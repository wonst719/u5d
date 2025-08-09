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

Uint32 egaPalette[16] =
{
	0xff000000,
	0xff0000aa,
	0xff00aa00,
	0xff00aaaa,
	0xffaa0000,
	0xffaa00aa,
	0xffaa5500,
	0xffaaaaaa,

	0xff555555,
	0xff5555ff,
	0xff55ff55,
	0xff55ffff,
	0xffff5555,
	0xffff55ff,
	0xffffff55,
	0xffffffff,
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

void GRAP_WIN_CleanupVideoDriver()
{
	SDL_Quit();
}

inline void GrPutOverlayPixel(int y, int x, int egaColor)
{
	pLinearOverlayBuffer[y * hiresWidth + x] = egaColor;
}

inline void GrPutPixel(int y, int x, int egaColor)
{
	pLinearEgaBuffer[y * loresWidth + x] = egaColor;
}

inline void GrPutByte(int y, int x, byte egaByte)
{
	pLinearEgaBuffer[y * loresWidth + x] = egaByte >> 4;
	pLinearEgaBuffer[y * loresWidth + x + 1] = egaByte & 0xf;
}

inline void GrPutOverlayMonoByte(int y, int x, byte b, int egaColor)
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
			pixels[y * pitch + x] |= egaPalette[pLinearOverlayBuffer[y * hiresWidth + x] & 0xf];
		}
	}
}

void Present()
{
	LinearToRGB();

	SDL_UpdateTexture(pSdlTexture, &pSdlSurface->clip_rect, pSdlSurface->pixels, pSdlSurface->pitch);

	SDL_Rect srcRect = { 0, 0, hiresWidth, hiresHeight };
	SDL_Rect dstRect = { 0, 0, windowWidth, windowHeight };
	SDL_RenderCopy(pSdlRenderer, pSdlTexture, &srcRect, &dstRect);
	SDL_RenderPresent(pSdlRenderer);
}

void GRAP_WIN_PrintChar(int penX, int penY, uint ch)
{
	static u8 mask[8] = { 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80 };

	char* p = font8x8_basic[ch];
	for (int y = 0; y < 8; y++)
	{
		byte b = p[y];
		for (int x = 0; x < 8; x++)
		{
			GrPutPixel(penY * 8 + y, penX * 8 + x, b & mask[x] ? 15 : 0);
		}
	}

	Present();
}

// 0x27
void GRAP_WIN_ScrollWindow(TextWindow* window, int amount)
{
	int l = (int)window->left << 3;
	int t = (int)window->top << 3;
	int r = ((int)window->right << 3) + 7;
	int b = ((int)window->bottom << 3) + 7;

	if (amount < 0)
	{
		amount = -amount;
		for (int y = t + amount; y < b; y++)
		{
			memcpy(&pLinearEgaBuffer[y * loresWidth + l], &pLinearEgaBuffer[(y + amount) * loresWidth + l], r - l);
		}
	}
	else
	{
		// Unsupported
		printf("GRAP_WIN_ScrollWindow(%d): Unsupported amount", amount);
	}

	Present();
}
