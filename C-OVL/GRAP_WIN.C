#include "COMMON.H"

#include "FUNCS.H"
#include "VARS.H"

#include <SDL2/SDL.h>

#include "FONT_DATA_WIN.H"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#pragma comment(lib, "imm32.lib")
#endif

SDL_Window* pSdlWindow;
SDL_Renderer* pSdlRenderer;
SDL_Surface* pSdlSurface;
SDL_Texture* pSdlTexture;

const int windowWidth = 1280;
const int windowHeight = 960;

const int hiresWidth = 640;
const int hiresHeight = 400;

const int loresWidth = 320;
const int loresHeight = 200;

const int hiresPackedStride = 80;

const int loresToHiresRatio = 2;

Uint8* pLinearEgaBuffer;

Uint8* pLinearOverlayBuffer;

Uint32 egaPalette[16] = {
    0xff000000, 0xff0000aa, 0xff00aa00, 0xff00aaaa, 0xffaa0000, 0xffaa00aa, 0xffaa5500, 0xffaaaaaa,

    0xff555555, 0xff5555ff, 0xff55ff55, 0xff55ffff, 0xffff5555, 0xffff55ff, 0xffffff55, 0xffffffff,
};

void GRAP_WIN_InitializeVideoDriver()
{
    ImmDisableIME(0);
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO | SDL_INIT_TIMER);

    SDL_CreateWindowAndRenderer(windowWidth, windowHeight, 0, &pSdlWindow, &pSdlRenderer);

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

    pLinearEgaBuffer = malloc(loresWidth * loresHeight);
    memset(pLinearEgaBuffer, 0, loresWidth * loresHeight);

    pLinearOverlayBuffer = malloc(hiresWidth * hiresHeight);
    memset(pLinearOverlayBuffer, 0, hiresWidth * hiresHeight);
}

void GRAP_WIN_CleanupVideoDriver() { SDL_Quit(); }

inline void GrPutOverlayPixel(int x, int y, int egaColor) { pLinearOverlayBuffer[y * hiresWidth + x] = egaColor; }

inline void GrPutPixel(int x, int y, int egaColor) { pLinearEgaBuffer[y * loresWidth + x] = egaColor; }

inline void GrPutByte(int x, int y, byte egaByte)
{
    pLinearEgaBuffer[y * loresWidth + x] = egaByte >> 4;
    pLinearEgaBuffer[y * loresWidth + x + 1] = egaByte & 0xf;
}

inline void GrPutOverlayMonoByte(int x, int y, byte b, int egaColor)
{
    pLinearOverlayBuffer[y * hiresWidth + x + 0] = ((b >> 7) & 1) ? egaColor : 0;
    pLinearOverlayBuffer[y * hiresWidth + x + 1] = ((b >> 6) & 1) ? egaColor : 0;
    pLinearOverlayBuffer[y * hiresWidth + x + 2] = ((b >> 5) & 1) ? egaColor : 0;
    pLinearOverlayBuffer[y * hiresWidth + x + 3] = ((b >> 4) & 1) ? egaColor : 0;
    pLinearOverlayBuffer[y * hiresWidth + x + 4] = ((b >> 3) & 1) ? egaColor : 0;
    pLinearOverlayBuffer[y * hiresWidth + x + 5] = ((b >> 2) & 1) ? egaColor : 0;
    pLinearOverlayBuffer[y * hiresWidth + x + 6] = ((b >> 1) & 1) ? egaColor : 0;
    pLinearOverlayBuffer[y * hiresWidth + x + 7] = ((b >> 0) & 1) ? egaColor : 0;
}

void LinearToRGB()
{
    Uint32* pixels = pSdlSurface->pixels;
    int pitch = pSdlSurface->pitch / 4;

    for (int y = 0; y < loresHeight; y++)
    {
        for (int x = 0; x < loresWidth; x++)
        {
            Uint32 color = egaPalette[pLinearEgaBuffer[y * loresWidth + x] & 0xf];
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

static int _debugPenX;
static int _debugPenY;

void PrintDebugOverlayChar(int penX, int penY, uint ch)
{
    static u8 mask[8] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};

    char* p = font8x8_basic[ch];
    for (int y = 0; y < 8; y++)
    {
        byte b = p[y];
        for (int x = 0; x < 8; x++)
        {
            byte col = b & mask[x] ? 15 : 1;

            GrPutOverlayPixel(penX * 8 + x, penY * 8 + y, col);
        }
    }
}

void PrintDebugOverlayString(char* str)
{
    if (_debugPenY >= 50)
        return;

    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        PrintDebugOverlayChar(_debugPenX, _debugPenY, str[i]);
        _debugPenX++;
        if (_debugPenX >= 80)
        {
            _debugPenX = 0;
            _debugPenY++;
        }
    }

    _debugPenX = 0;
    _debugPenY++;
}

void PrintDebugOverlayStringFmt(char* str, ...)
{
    char debugBuffer[256];

    va_list args;
    va_start(args, str);

    if (vsprintf_s(debugBuffer, sizeof(debugBuffer), str, args) < 0)
    {
        debugBuffer[0] = 0;
    }

    va_end(args);

    PrintDebugOverlayString(debugBuffer);
}

void DisplayDebugMessages()
{
    memset(pLinearOverlayBuffer, 0, hiresWidth * hiresHeight);

    _debugPenX = 0;
    _debugPenY = 0;

    PrintDebugOverlayStringFmt("P: X%d Y%d", D_5c5a[0]._2_x, D_5c5a[0]._3_y);
    PrintDebugOverlayStringFmt("Map: %d", D_5893_map_id);
    PrintDebugOverlayStringFmt("Time: %02d-%02d %02d:%02d", D_587d, D_587e, D_587f, D_5881);

    if (D_5893_map_id > 0)
    {
        PrintDebugOverlayString("NPC:");

        for (int i = 0; i < 32; i++)
        {
            if (i >= 8)
            {
                PrintDebugOverlayString("...");
                break;
            }

            PrintDebugOverlayStringFmt("%2x: %d X%d Y%d %d %d %d %d %d", i, D_5f5e[i]._0, D_5f5e[i]._2, D_5f5e[i]._4,
                                       D_5f5e[i]._6, D_5f5e[i]._8, D_5f5e[i]._a, D_5f5e[i]._c, D_5f5e[i]._e);
        }
    }
    else
    {
        PrintDebugOverlayString("Actor:");

        for (int i = 0; i < 32; i++)
        {
            if (i >= 8)
            {
                PrintDebugOverlayString("...");
                break;
            }
            PrintDebugOverlayStringFmt("%2x: T%02x A%02x X%d Y%d Z%d %d %d %d", i, D_5c5a[i]._0_tile, D_5c5a[i]._1,
                                       D_5c5a[i]._2_x, D_5c5a[i]._3_y, D_5c5a[i]._4_z, D_5c5a[i]._5, D_5c5a[i]._6,
                                       D_5c5a[i]._7);
        }
    }
}

void Present()
{
    DisplayDebugMessages();
    LinearToRGB();

    SDL_UpdateTexture(pSdlTexture, &pSdlSurface->clip_rect, pSdlSurface->pixels, pSdlSurface->pitch);

    SDL_Rect srcRect = {0, 0, hiresWidth, hiresHeight};
    SDL_Rect dstRect = {0, 0, windowWidth, windowHeight};
    SDL_RenderCopy(pSdlRenderer, pSdlTexture, &srcRect, &dstRect);
    SDL_RenderPresent(pSdlRenderer);
}

void GRAP_WIN_PrintChar(int penX, int penY, uint ch)
{
    static u8 mask[8] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};

    char* p = font8x8_basic[ch];
    for (int y = 0; y < 8; y++)
    {
        byte b = p[y];
        for (int x = 0; x < 8; x++)
        {
            byte col;

            if (D_53a8_inverse)
            {
                col = b & mask[x] ? 0 : 15;
            }
            else
            {
                col = b & mask[x] ? 15 : 0;
            }

            GrPutPixel(penX * 8 + x, penY * 8 + y, col);
        }
    }

    Present();
}

// 0x27
void GRAP_WIN_ScrollWindow(int ax, int bx, int cx, int dx, int si)
{
    int l = ax;
    int t = bx;
    int r = cx;
    int b = dx;
    int amount = si;

    if (amount < 0)
    {
        amount = -amount;
        for (int y = t + amount; y <= b; y++)
        {
            memcpy(&pLinearEgaBuffer[y * loresWidth + l], &pLinearEgaBuffer[(y + amount) * loresWidth + l], r - l + 1);
        }
    }
    else
    {
        // Unsupported
        printf("GRAP_WIN_ScrollWindow(%d): Unsupported amount", amount);
    }

    Present();
}

extern byte g_grapPenColor;

// 0x3f
void GRAP_WIN_FillWindow(int x1, int y1, int x2, int y2)
{
    if (y1 > y2)
        return;
    if (x1 > x2)
        return;

    for (int y = y1; y <= y2; y++)
    {
        memset(&pLinearEgaBuffer[y * loresWidth + x1], g_grapPenColor, x2 - x1 + 1);
    }

    Present();
}

void GRAP_WIN_Temp_PlotTile(int x1, int y1, int color)
{
    int width = 16;
    int height = 16;
    x1 *= width;
    y1 *= height;
    x1 += 8;
    y1 += 8;
    for (int y = y1; y < y1 + height; y++)
    {
        memset(&pLinearEgaBuffer[y * loresWidth + x1], color, width);
    }

    // Present();
}

void GRAP_WIN_Temp_PlotTile2(int x1, int y1, uint tileIdx, byte* tile)
{
    static char* s_hex_tbl = "0123456789ABCDEF";

    int width = 16;
    int height = 16;
    x1 *= width;
    y1 *= height;
    x1 += 8;
    y1 += 8;
    for (int y = y1; y < y1 + height; y++)
    {
        for (int x = x1; x < x1 + width; x += 2)
        {
            GrPutByte(x, y, *tile++);
        }
    }

    // GRAP_WIN_PrintChar(x1 / 8, y1 / 8, s_hex_tbl[(tileIdx >> 4) & 0xf]);
    // GRAP_WIN_PrintChar(x1 / 8 + 1, y1 / 8, s_hex_tbl[tileIdx & 0xf]);

    // Present();
}

int FUN_1000_08e6_constraint_imagewindow(int* x1, int* y1, int* x2, int* y2);

// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm#All_cases
void PlotLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int error = dx + dy;
    int e2;

    while (1)
    {
        GrPutPixel(x1, y1, g_grapPenColor);
        e2 = 2 * error;

        if (e2 >= dy)
        {
            if (x1 == x2)
                break;

            error += dy;
            x1 += sx;
        }
        if (e2 <= dx)
        {
            if (y1 == y2)
                break;

            error += dx;
            y1 += sy;
        }
    }
}

// 0x27
void GRAP_WIN_Line(int x1, int y1, int x2, int y2)
{
    // FUN_1000_08e6_constraint_imagewindow(&x1, &y1, &x2, &y2);

    PlotLine(x1, y1, x2, y2);

    Present();
}
