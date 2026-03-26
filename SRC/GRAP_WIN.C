#include "COMMON.H"

#include "FUNCS.H"
#include "VARS.H"

#include <SDL2/SDL.h>

#include "FONT_DATA_WIN.H"

#if defined(TARGET_WINDOWS)
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#pragma comment(lib, "imm32.lib")
#endif

int g_enableDebugOverlay = 0;

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

Uint8* pLinearEgaBuffer0;

Uint8* pLinearEgaBuffer1;

Uint8* pLinearOverlayBuffer;

Uint32 egaPalette[16] = {
    0xff000000, 0xff0000aa, 0xff00aa00, 0xff00aaaa, 0xffaa0000, 0xffaa00aa, 0xffaa5500, 0xffaaaaaa,

    0xff555555, 0xff5555ff, 0xff55ff55, 0xff55ffff, 0xffff5555, 0xffff55ff, 0xffffff55, 0xffffffff,
};

static u8 bitMask[8] = {0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1};

static u8 colorTable[16] = {0, 1, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15}; // ?

extern VideoDriverParams D_52ba_vdp;

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

    pLinearEgaBuffer0 = malloc(loresWidth * loresHeight);
    memset(pLinearEgaBuffer0, 0, loresWidth * loresHeight);

    pLinearEgaBuffer1 = malloc(loresWidth * loresHeight);
    memset(pLinearEgaBuffer1, 0, loresWidth * loresHeight);

    pLinearOverlayBuffer = malloc(hiresWidth * hiresHeight);
    memset(pLinearOverlayBuffer, 0, hiresWidth * hiresHeight);
}

void GRAP_WIN_CleanupVideoDriver() { SDL_Quit(); }

inline byte* GetPage(int page)
{
    if (page == 0)
        return pLinearEgaBuffer0;
    else if (page == 1)
        return pLinearEgaBuffer1;
    return 0;
}

inline void GrPutOverlayPixel(int x, int y, int egaColor) { pLinearOverlayBuffer[y * hiresWidth + x] = egaColor; }

inline void GrPutPixel(int page, int x, int y, int egaColor)
{
    byte* target = GetPage(page);
    target[y * loresWidth + x] = egaColor;
}

inline void GrPutByte(int page, int x, int y, byte egaByte)
{
    byte* target = GetPage(page);
    target[y * loresWidth + x] = egaByte >> 4;
    target[y * loresWidth + x + 1] = egaByte & 0xf;
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
    if (!g_enableDebugOverlay)
        return;

    memset(pLinearOverlayBuffer, 0, hiresWidth * hiresHeight);

    _debugPenX = 0;
    _debugPenY = 0;

    PrintDebugOverlayStringFmt("P: X%d Y%d", D_5c5a[0]._2_x, D_5c5a[0]._3_y);
    PrintDebugOverlayStringFmt("Map: %d", D_5893_map_id);
    PrintDebugOverlayStringFmt("Time: %02d-%02d %02d:%02d", D_587d, D_587e, D_587f, D_5881);

    return;

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

void GRAP_WIN_PrintChar(byte* ptr, int offset, byte fgColor, byte bgColor, int penX, int penY)
{
    byte* p = &ptr[offset];
    for (int y = 0; y < 8; y++)
    {
        byte b = p[y];
        for (int x = 0; x < 8; x++)
        {
            byte col = b & bitMask[x] ? colorTable[fgColor] : colorTable[bgColor];

            GrPutPixel(D_52ba_vdp._52d8_page, penX * 8 + x, penY * 8 + y, col);
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
            memcpy(&pLinearEgaBuffer0[y * loresWidth + l], &pLinearEgaBuffer0[(y + amount) * loresWidth + l], r - l + 1);
        }
    }
    else
    {
        // Unsupported
        debug("GRAP_WIN_ScrollWindow(%d): Unsupported amount", amount);
    }

    Present();
}

extern byte g_grapPenColor;

// 0x3f
void GRAP_WIN_FillWindow(int x1, int y1, int x2, int y2, int xorMode)
{
    if (y1 > y2)
        return;
    if (x1 > x2)
        return;

    byte* target = GetPage(D_52ba_vdp._52d8_page);

    for (int y = y1; y <= y2; y++)
    {
        if (!xorMode)
        {
            memset(&target[y * loresWidth + x1], g_grapPenColor, x2 - x1 + 1);
        }
        else
        {
            for (int x = x1; x <= x2; x++)
            {
                target[y * loresWidth + x] ^= g_grapPenColor;
                target[y * loresWidth + x] &= 0xf;
            }
        }
    }

    if (D_52ba_vdp._52d8_page == 0)
    {
        Present();
    }
}

void GRAP_WIN_Temp_PutTile(int x1, int y1, uint tileIdx, byte* tile)
{
    int width = 16;
    int height = 16;
    x1 *= width;
    y1 *= height;
    x1 += D_52ba_vdp._52bc;
    y1 += D_52ba_vdp._52be;
    for (int y = y1; y < y1 + height; y++)
    {
        for (int x = x1; x < x1 + width; x += 2)
        {
            GrPutByte(D_52ba_vdp._52d8_page, x, y, *tile++);
        }
    }

    // Present();
}

int ULTIMA_08e6_ClipRectCoord(int* x1, int* y1, int* x2, int* y2);

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
        GrPutPixel(D_52ba_vdp._52d8_page, x1, y1, g_grapPenColor);
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
    // ULTIMA_08e6_constraint_imagewindow(&x1, &y1, &x2, &y2);

    PlotLine(x1, y1, x2, y2);

    if (D_52ba_vdp._52d8_page == 0)
    {
        Present();
    }
}

void GRAP_WIN_LineRectangle(int x1, int y1, int x2, int y2, byte color)
{
    byte x = g_grapPenColor;
    g_grapPenColor = color;

    PlotLine(x1, y1, x2, y1);
    PlotLine(x1, y2, x2, y2);
    PlotLine(x1, y1, x1, y2);
    PlotLine(x2, y1, x2, y2);

    PlotLine(x1, y1, x2, y2);
    PlotLine(x2, y1, x1, y2);

    g_grapPenColor = x;

    Present();
}

void GRAP_WIN_Pset(int x, int y)
{
    // ULTIMA_08e6_constraint_imagewindow(&x1, &y1, &x2, &y2);

    GrPutPixel(D_52ba_vdp._52d8_page, x, y, g_grapPenColor);

    if (D_52ba_vdp._52d8_page == 0)
    {
        Present();
    }
}

void GRAP_WIN_PutBitmap(byte* buf, int x, int y, int w, int h)
{
    int stride = ((w + 7) / 8) * 4;

    if (x + w >= 320)
    {
        w = 320 - x;
    }

    if (y + h >= 200)
    {
        h = 200 - y;
    }

    if (w <= 0 || h <= 0)
        return;

    for (int yy = 0; yy < h; yy++)
    {
        byte* linePtr = &buf[yy * stride];
        int xx;
        for (xx = 0; xx < w - 1; xx += 2)
        {
            GrPutByte(D_52ba_vdp._52d8_page, xx + x, yy + y, linePtr[xx / 2]);
        }

        if (xx < w)
        {
            GrPutPixel(D_52ba_vdp._52d8_page, xx + x, yy + y, linePtr[xx / 2] >> 4);
        }
    }

    Present();
}

void GRAP_WIN_PutBitmap_Flip(byte* buf, int x, int y, int w, int h, int flags)
{
    if (flags == 0)
    {
        GRAP_WIN_PutBitmap(buf, x, y, w, h);
        return;
    }

    // flags & 1: vflip
    // flags & 2: hflip

    int stride = ((w + 7) / 8) * 4;

    if (x + w >= 320)
    {
        w = 320 - x;
    }

    if (y + h >= 200)
    {
        h = 200 - y;
    }

    if (w <= 0 || h <= 0)
        return;

    int vflip = (flags & 1) != 0;
    int hflip = (flags & 2) != 0;

    for (int yy = 0; yy < h; yy++)
    {
        byte* linePtr;
        if (vflip)
        {
            linePtr = &buf[(h - yy - 1) * stride];
        }
        else
        {
            linePtr = &buf[yy * stride];
        }

        if (hflip)
        {
            if (w & 1)
            {
                // TODO: handle odd width
                for (int xx = 0; xx < w; xx += 2)
                {
                    byte flip = linePtr[(w - xx - 1) / 2];
                    flip = (flip << 4) | (flip >> 4);
                    GrPutByte(D_52ba_vdp._52d8_page, xx + x, yy + y, flip);
                }
            }
            else
            {
                for (int xx = 0; xx < w; xx += 2)
                {
                    byte flip = linePtr[(w - xx - 1) / 2];
                    flip = (flip << 4) | (flip >> 4);
                    GrPutByte(D_52ba_vdp._52d8_page, xx + x, yy + y, flip);
                }
            }
        }
        else
        {
            int xx;
            for (xx = 0; xx < w - 1; xx += 2)
            {
                GrPutByte(D_52ba_vdp._52d8_page, xx + x, yy + y, linePtr[xx / 2]);
            }

            if (xx < w)
            {
                GrPutPixel(D_52ba_vdp._52d8_page, xx + x, yy + y, linePtr[xx / 2] >> 4);
            }
        }
    }

    Present();
}

void GRAP_WIN_PutBitImage(byte* buf, int x, int y, int w, int h)
{
    // TODO: drawing mode?

    int stride = (w + 7) / 8;
    for (int yy = 0; yy < h; yy++)
    {
        byte* linePtr = &buf[yy * stride];
        for (int xx = 0; xx < w; xx++)
        {
            byte col = linePtr[xx / 8] & bitMask[xx % 8] ? 15 : 0;
            GrPutPixel(D_52ba_vdp._52d8_page, xx + x, yy + y, col);
        }
    }

    //GRAP_WIN_LineRectangle(x, y, x + w, y + h, 14);

    //Present();
}

void GRAP_WIN_TransferPage(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY)
{
    byte* srcPagePtr = GetPage(srcPage);
    byte* dstPagePtr = GetPage(dstPage);

    // TODO: check bounds
    for (int y = 0; y <= y2 - y1; y++)
    {
        memcpy(&dstPagePtr[(y + dstY) * loresWidth + dstX], &srcPagePtr[(y + y1) * loresWidth + x1],
               x2 - x1 + 1);
    }

    if (dstPage == 0)
    {
        Present();
    }
}

extern int u5_peekch();
extern void u5_sleep(int ms);

typedef struct RevealState
{
    u16 state;
    u16 maxState;
    u16 mask;

    int total;
    int produced;
} RevealState;

static u16 lfsrMasks[] = {3, 6, 0xc, 0x14, 0x30, 0x60, 0xb8, 0x110, 0x240, 0x500, 0xca0, 0x1b00, 0x3500, 0x6000, 0xb400};

static u16 GetRevealLfsrMask(int bits)
{
    ASSERT(bits >= 2 && bits <= 16);

    return lfsrMasks[bits - 2];
}

void RevealInit(RevealState* state, int width, int height, u16 seed)
{
    ASSERT(state);
    ASSERT(width > 0 && height > 0);
    ASSERT(seed);

    u16 total;

    u8 bits = 2;
    u16 maxState = 3;

    total = width * height;

    while (maxState < total)
    {
        bits++;
        maxState = (1 << bits) - 1;
    }

    state->maxState = maxState;
    state->mask = GetRevealLfsrMask(bits);
    ASSERT(state->mask);

    seed %= maxState;
    ASSERT(seed);

    state->state = seed;

    state->total = total;
    state->produced = 0;
}

static u16 RevealStep(u16 state, u16 mask)
{
    int lsb = state & 1;
    state >>= 1;
    if (lsb)
        state ^= mask;
    return state;
}

bool RevealNextIndex(RevealState* state, int* outIndex)
{
    int guard;
    int idx;

    ASSERT(state);
    ASSERT(outIndex);

    if (state->produced >= state->total)
        return 0;

    guard = 0;

    for (;;)
    {
        idx = state->state - 1;
        state->state = RevealStep(state->state, state->mask);

        if (idx < state->total)
        {
            *outIndex = idx;
            state->produced++;
            return 1;
        }

        if (++guard > state->maxState)
            return 0;
    }
}

void GRAP_WIN_TransferPage_Reveal(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY)
{
    RevealState state;

    byte* srcPagePtr = GetPage(srcPage);
    byte* dstPagePtr = GetPage(dstPage);

    int w = x2 - x1 + 1;
    int h = y2 - y1 + 1;

    RevealInit(&state, w, h, 1);

    int nextIdx;
    while (RevealNextIndex(&state, &nextIdx))
    {
        int nx = nextIdx % w;
        int ny = nextIdx / w;
        dstPagePtr[(ny + dstY) * loresWidth + nx + dstX] = srcPagePtr[(ny + y1) * loresWidth + nx + x1];

        if (state.produced % 512 == 511)
        {
            Present();

            if (u5_peekch())
            {
                GRAP_WIN_TransferPage(srcPage, dstPage, x1, y1, x2, y2, dstX, dstY);
                return;
            }

            u5_sleep(1 * 55);
        }
    }

    Present();
}
