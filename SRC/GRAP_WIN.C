#include "COMMON.H"

#include "VARS.H"

#include "GRAP_BUF.H"
#include "GRAP_OPS.H"

#include <SDL2/SDL.h>

SDL_Window* pSdlWindow;
SDL_Renderer* pSdlRenderer;
SDL_Surface* pSdlSurface;
SDL_Texture* pSdlTexture;

const int windowWidth = 1280;
const int windowHeight = 960;

Uint32 egaPalette[16] = {
    0xff000000, 0xff0000aa, 0xff00aa00, 0xff00aaaa, 0xffaa0000, 0xffaa00aa, 0xffaa5500, 0xffaaaaaa,

    0xff555555, 0xff5555ff, 0xff55ff55, 0xff55ffff, 0xffff5555, 0xffff55ff, 0xffffff55, 0xffffffff,
};

void GRAP_WIN_Present(void);

void GRAP_WIN_InitializeVideoDriver(void)
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    SDL_CreateWindowAndRenderer(windowWidth, windowHeight, 0, &pSdlWindow, &pSdlRenderer);
    SDL_SetWindowTitle(pSdlWindow, "Ultima V: Warriors of Destiny");
    SDL_StopTextInput();

    pSdlSurface = SDL_CreateRGBSurface(0, hiresWidth, hiresHeight, 32, 0xff0000, 0xff00, 0xff, 0xff000000);

    pSdlTexture = SDL_CreateTextureFromSurface(pSdlRenderer, pSdlSurface);
    SDL_SetTextureScaleMode(pSdlTexture, SDL_ScaleModeLinear);

    if (SDL_MUSTLOCK(pSdlSurface))
    {
        exit(0);
    }

    if (pSdlSurface->pitch != hiresWidth * 4)
    {
        exit(0);
    }

    GRAP_BUF_InitializeDriver(GRAP_WIN_Present);
}

void GRAP_WIN_CleanupVideoDriver(void) { SDL_Quit(); }

void LinearToRGB(void)
{
    Uint32* pixels = pSdlSurface->pixels;
    int pitch = pSdlSurface->pitch / 4;

    for (int y = 0; y < loresHeight; y++)
    {
        for (int x = 0; x < loresWidth; x++)
        {
            Uint32 color = egaPalette[pLinearEgaBuffer0[y * loresWidth + x] & 0xf];
            pixels[(y * 2) * pitch + (x * 2)] = color;
            pixels[(y * 2) * pitch + (x * 2 + 1)] = color;
            pixels[(y * 2 + 1) * pitch + (x * 2)] = color;
            pixels[(y * 2 + 1) * pitch + (x * 2 + 1)] = color;
        }
    }

    for (int y = 0; y < hiresHeight; y++)
    {
        for (int x = 0; x < hiresWidth; x++)
        {
            byte pixel = pLinearOverlayBuffer[y * hiresWidth + x] & 0xf;
            if (pixel != 0)
            {
                pixels[y * pitch + x] = egaPalette[pixel];
            }
            // pixels[y * pitch + x] |= egaPalette[pLinearOverlayBuffer[y * hiresWidth + x] & 0xf];
        }
    }
}

extern void DisplayDebugMessages(void);

void GRAP_WIN_Present(void)
{
    LinearToRGB();

    SDL_UpdateTexture(pSdlTexture, &pSdlSurface->clip_rect, pSdlSurface->pixels, pSdlSurface->pitch);

    SDL_Rect srcRect = {0, 0, hiresWidth, hiresHeight};
    SDL_Rect dstRect = {0, 0, windowWidth, windowHeight};
    SDL_RenderCopy(pSdlRenderer, pSdlTexture, &srcRect, &dstRect);
    SDL_RenderPresent(pSdlRenderer);
}

static DriverOps s_winOps =
{
    .InitializeVideoDriver = GRAP_WIN_InitializeVideoDriver,
    .CleanupVideoDriver = GRAP_WIN_CleanupVideoDriver,
    .SetPenColor = GRAP_BUF_SetPenColor,
    .SetPage = GRAP_BUF_SetPage,
    .PrintChar = GRAP_BUF_PrintChar,
    .ScrollWindow = GRAP_BUF_ScrollWindow,
    .Line = GRAP_BUF_Line,
    .Pset = GRAP_BUF_Pset,
    .FillWindow = GRAP_BUF_FillWindow,
    .Temp_PutTile = GRAP_BUF_Temp_PutTile,
    .PutBitmap = GRAP_BUF_PutBitmap,
    .PutBitmap_Flip = GRAP_BUF_PutBitmap_Flip,
    .PutBitImage = GRAP_BUF_PutBitImage,
    .TransferPage = GRAP_BUF_TransferPage,
    .TransferPage_Reveal = GRAP_BUF_TransferPage_Reveal
};

DriverOps* GRAP_WIN_GetOps(void)
{
    return &s_winOps;
}
