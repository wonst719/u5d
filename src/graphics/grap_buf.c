#include "common/common.h"

#include "vars.h"

#include "grap_buf.h"

#if defined(ENABLE_GRAP_OVERLAY_DEBUG)
#include "common/dbg_font_data.h"
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g_enableDebugOverlay = 0;

// 64k
u8* g_linearEgaBuffer0;

// 64k
u8* g_linearEgaBuffer1;

#if defined(ENABLE_GRAP_OVERLAY)
// 256k
u8* g_linearOverlayBuffer;
#endif

byte g_grapPenColor = 0;

extern VideoDriverParams D_52ba_vdp;

static u8 s_bitMask[8] = {0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1};

static u8 s_colorTable[16] = {0, 1, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15}; // ?

static pfGrapPresent* s_pfPresent;

static u32 s_lastPresentTick = 0;
static bool s_dirty = FALSE;

void GRAP_BUF_InitializeDriver(pfGrapPresent* pfPresent)
{
    g_linearEgaBuffer0 = malloc(loresWidth * loresHeight);
    memset(g_linearEgaBuffer0, 0, loresWidth * loresHeight);

    g_linearEgaBuffer1 = malloc(loresWidth * loresHeight);
    memset(g_linearEgaBuffer1, 0, loresWidth * loresHeight);

#if defined(ENABLE_GRAP_OVERLAY)
    g_linearOverlayBuffer = malloc(hiresWidth * hiresHeight);
    memset(g_linearOverlayBuffer, 0, hiresWidth * hiresHeight);
#endif

    s_pfPresent = pfPresent;
}

void GRAP_BUF_CleanupDriver(void)
{
    free(g_linearEgaBuffer0);
    free(g_linearEgaBuffer1);
#if defined(ENABLE_GRAP_OVERLAY)
    free(g_linearOverlayBuffer);
#endif
}

void GRAP_BUF_SetPenColor(byte color)
{
    g_grapPenColor = color;
}

void GRAP_BUF_SetPage(int page)
{
    D_52ba_vdp._52d8_page = page;
}

byte* GetPage(int page)
{
    if (page == 0)
        return g_linearEgaBuffer0;
    else if (page == 1)
        return g_linearEgaBuffer1;
    return 0;
}

#if defined(ENABLE_GRAP_OVERLAY)
void GrPutOverlayPixel(int x, int y, int egaColor) { g_linearOverlayBuffer[y * hiresWidth + x] = egaColor; }
#endif

void GrPutPixel(int page, int x, int y, int egaColor)
{
    byte* target = GetPage(page);
    target[y * loresWidth + x] = egaColor;
}

void GrPutByte(int page, int x, int y, byte egaByte)
{
    byte* target = GetPage(page);
    target[y * loresWidth + x] = egaByte >> 4;
    target[y * loresWidth + x + 1] = egaByte & 0xf;
}

#if defined(ENABLE_GRAP_OVERLAY)
void GrPutOverlayMonoByte(int x, int y, byte b, int egaColor)
{
    g_linearOverlayBuffer[y * hiresWidth + x + 0] = ((b >> 7) & 1) ? egaColor : 0;
    g_linearOverlayBuffer[y * hiresWidth + x + 1] = ((b >> 6) & 1) ? egaColor : 0;
    g_linearOverlayBuffer[y * hiresWidth + x + 2] = ((b >> 5) & 1) ? egaColor : 0;
    g_linearOverlayBuffer[y * hiresWidth + x + 3] = ((b >> 4) & 1) ? egaColor : 0;
    g_linearOverlayBuffer[y * hiresWidth + x + 4] = ((b >> 3) & 1) ? egaColor : 0;
    g_linearOverlayBuffer[y * hiresWidth + x + 5] = ((b >> 2) & 1) ? egaColor : 0;
    g_linearOverlayBuffer[y * hiresWidth + x + 6] = ((b >> 1) & 1) ? egaColor : 0;
    g_linearOverlayBuffer[y * hiresWidth + x + 7] = ((b >> 0) & 1) ? egaColor : 0;
}
#endif

#if defined(ENABLE_GRAP_OVERLAY_DEBUG)
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

    if (vsprintf(debugBuffer, str, args) < 0)
    {
        debugBuffer[0] = 0;
    }

    va_end(args);

    PrintDebugOverlayString(debugBuffer);
}

void DisplayDebugMessages(void)
{
    if (!g_enableDebugOverlay)
        return;

    memset(g_linearOverlayBuffer, 0, hiresWidth * hiresHeight);

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
#endif

static void Present()
{
#if defined(ENABLE_GRAP_OVERLAY_DEBUG)
    DisplayDebugMessages();
#endif

    (*s_pfPresent)();

    s_dirty = FALSE;
}

extern u32 TIME_CurrentFrame(void);

void GRAP_FlushPrevPresentReq(void)
{
    if (!s_dirty)
        return;

    u32 tick = TIME_CurrentFrame();
    if (s_lastPresentTick != tick)
    {
        s_lastPresentTick = tick;

        Present();
    }
}

void GRAP_BUF_PrintChar(byte* ptr, int offset, byte fgColor, byte bgColor, int penX, int penY)
{
    GRAP_FlushPrevPresentReq();

    byte* p = &ptr[offset];
    for (int y = 0; y < 8; y++)
    {
        byte b = p[y];
        for (int x = 0; x < 8; x++)
        {
            byte col = b & s_bitMask[x] ? s_colorTable[fgColor] : s_colorTable[bgColor];

            GrPutPixel(D_52ba_vdp._52d8_page, penX * 8 + x, penY * 8 + y, col);
        }
    }

    s_dirty = TRUE;
}

// 0x27
void GRAP_BUF_ScrollWindow(int ax, int bx, int cx, int dx, int si)
{
    GRAP_FlushPrevPresentReq();

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
            memcpy(&g_linearEgaBuffer0[y * loresWidth + l], &g_linearEgaBuffer0[(y + amount) * loresWidth + l],
                   r - l + 1);
        }
    }
    else
    {
        // Unsupported
        debug("GRAP_BUF_ScrollWindow(%d): Unsupported amount", amount);
    }

    s_dirty = TRUE;
}

extern byte g_grapPenColor;

// 0x3f
void GRAP_BUF_FillWindow(int x1, int y1, int x2, int y2, int xorMode)
{
    if (y1 > y2)
        return;
    if (x1 > x2)
        return;

    GRAP_FlushPrevPresentReq();

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
        s_dirty = TRUE;
    }
}

void GRAP_BUF_Temp_PutTile(int x1, int y1, uint tileIdx, byte* tile)
{
    GRAP_FlushPrevPresentReq();

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

    s_dirty = TRUE;
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
void GRAP_BUF_Line(int x1, int y1, int x2, int y2)
{
    GRAP_FlushPrevPresentReq();

    // ULTIMA_08e6_constraint_imagewindow(&x1, &y1, &x2, &y2);

    PlotLine(x1, y1, x2, y2);

    if (D_52ba_vdp._52d8_page == 0)
    {
        s_dirty = TRUE;
    }
}

void GRAP_BUF_LineRectangle(int x1, int y1, int x2, int y2, byte color)
{
    GRAP_FlushPrevPresentReq();

    byte x = g_grapPenColor;
    g_grapPenColor = color;

    PlotLine(x1, y1, x2, y1);
    PlotLine(x1, y2, x2, y2);
    PlotLine(x1, y1, x1, y2);
    PlotLine(x2, y1, x2, y2);

    PlotLine(x1, y1, x2, y2);
    PlotLine(x2, y1, x1, y2);

    g_grapPenColor = x;

    s_dirty = TRUE;
}

void GRAP_BUF_Pset(int x, int y)
{
    // ULTIMA_08e6_constraint_imagewindow(&x1, &y1, &x2, &y2);

    GRAP_FlushPrevPresentReq();

    GrPutPixel(D_52ba_vdp._52d8_page, x, y, g_grapPenColor);

    if (D_52ba_vdp._52d8_page == 0)
    {
        s_dirty = TRUE;
    }
}

void GRAP_BUF_PutBitmap(byte* buf, int x, int y, int w, int h)
{
    GRAP_FlushPrevPresentReq();

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

    if (D_52ba_vdp._52d8_page == 0)
    {
        s_dirty = TRUE;
    }
}

void GRAP_BUF_PutBitmap_Flip(byte* buf, int x, int y, int w, int h, int flags)
{
    GRAP_FlushPrevPresentReq();

    if (flags == 0)
    {
        GRAP_BUF_PutBitmap(buf, x, y, w, h);
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

    if (D_52ba_vdp._52d8_page == 0)
    {
        s_dirty = TRUE;
    }
}

void GRAP_BUF_PutBitImage(byte* buf, int x, int y, int w, int h)
{
    // TODO: drawing mode?

    GRAP_FlushPrevPresentReq();

    int stride = (w + 7) / 8;
    for (int yy = 0; yy < h; yy++)
    {
        byte* linePtr = &buf[yy * stride];
        for (int xx = 0; xx < w; xx++)
        {
            byte col = linePtr[xx / 8] & s_bitMask[xx % 8] ? 15 : 0;
            GrPutPixel(D_52ba_vdp._52d8_page, xx + x, yy + y, col);
        }
    }

    // GRAP_BUF_LineRectangle(x, y, x + w, y + h, 14);

    if (D_52ba_vdp._52d8_page == 0)
    {
        s_dirty = TRUE;
    }
}

void GRAP_BUF_TransferPage(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY)
{
    GRAP_FlushPrevPresentReq();

    byte* srcPagePtr = GetPage(srcPage);
    byte* dstPagePtr = GetPage(dstPage);

    // TODO: check bounds
    for (int y = 0; y <= y2 - y1; y++)
    {
        memcpy(&dstPagePtr[(y + dstY) * loresWidth + dstX], &srcPagePtr[(y + y1) * loresWidth + x1], x2 - x1 + 1);
    }

    if (dstPage == 0)
    {
        s_dirty = TRUE;
    }
}

extern int u5_peekch();
extern void TIME_sleep(int ms);

typedef struct RevealState
{
    u16 state;
    u16 maxState;
    u16 mask;

    int total;
    int produced;
} RevealState;

static u16 lfsrMasks[] = {3,     6,     0xc,   0x14,   0x30,   0x60,   0xb8,  0x110,
                          0x240, 0x500, 0xca0, 0x1b00, 0x3500, 0x6000, 0xb400};

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

extern void TIME_Sleep(int ms);

void GRAP_BUF_TransferPage_Reveal(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY)
{
    GRAP_FlushPrevPresentReq();

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
                GRAP_BUF_TransferPage(srcPage, dstPage, x1, y1, x2, y2, dstX, dstY);
                return;
            }

            TIME_Sleep(1 * 55);
        }
    }

    Present();
}
