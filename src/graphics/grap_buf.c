#include "common/common.h"
#include "key/key.h"
#include "time/time.h"

#include "vars.h"

#include "grap_buf.h"
#include "animate.h"
#include "reveal.h"

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

static byte* s_tileset;

static pfGrapFlushFrame* s_pfFlushFrame;

static u32 s_lastPresentTick = 0;
static bool s_dirty = false;

// T1K:19d9
static u16 s_tileRevealSeed = 0;

void GRAP_BUF_Initialize(pfGrapFlushFrame* pfFlushFrame)
{
    g_linearEgaBuffer0 = malloc(loresWidth * loresHeight);
    memset(g_linearEgaBuffer0, 0, loresWidth * loresHeight);

    g_linearEgaBuffer1 = malloc(loresWidth * loresHeight);
    memset(g_linearEgaBuffer1, 0, loresWidth * loresHeight);

#if defined(ENABLE_GRAP_OVERLAY)
    g_linearOverlayBuffer = malloc(hiresWidth * hiresHeight);
    memset(g_linearOverlayBuffer, 0, hiresWidth * hiresHeight);
#endif

    s_pfFlushFrame = pfFlushFrame;
}

void GRAP_BUF_Cleanup(void)
{
    if (s_tileset != NULL)
    {
        free(s_tileset);
        s_tileset = NULL;
    }

    free(g_linearEgaBuffer0);
    free(g_linearEgaBuffer1);

    g_linearEgaBuffer0 = NULL;
    g_linearEgaBuffer1 = NULL;

#if defined(ENABLE_GRAP_OVERLAY)
    free(g_linearOverlayBuffer);
    g_linearOverlayBuffer = NULL;
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

inline byte* GetPage(int page)
{
    if (page == 0)
        return g_linearEgaBuffer0;
    else if (page == 1)
        return g_linearEgaBuffer1;
    return 0;
}

#if defined(ENABLE_GRAP_OVERLAY)
inline void GrPutOverlayPixel(int x, int y, int egaColor) { g_linearOverlayBuffer[y * hiresWidth + x] = egaColor; }
#endif

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

// safe but slow
inline void GrPutClippedPixel(int page, int x, int y, int egaColor)
{
    if (x >= 0 && x < loresWidth && y >= 0 && y < loresHeight)
    {
        GrPutPixel(page, x, y, egaColor);
    }
}

#if defined(ENABLE_GRAP_OVERLAY)
inline void GrPutOverlayMonoByte(int x, int y, byte b, int egaColor)
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

static void PrintDebugOverlayChar(int penX, int penY, uint ch)
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

static void PrintDebugOverlayString(char* str)
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

static void PrintDebugOverlayStringFmt(char* str, ...)
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

static void DisplayDebugMessages(void)
{
#if _DEBUG
    if (!g_enableDebugOverlay)
        return;

    memset(g_linearOverlayBuffer, 0, hiresWidth * hiresHeight);

    _debugPenX = 0;
    _debugPenY = 0;

    PrintDebugOverlayStringFmt("P: X%d Y%d", D_5c5a[0]._2_x, D_5c5a[0]._3_y);
    PrintDebugOverlayStringFmt("Map: %d", D_5893_map_id);
    PrintDebugOverlayStringFmt("Time: %02d-%02d %02d:%02d", D_587d, D_587e, D_587f, D_5881);
#endif
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

            PrintDebugOverlayStringFmt("%2x: %d X%d Y%d %d %d %d %d %d", i, D_5f5e[i]._0, D_5f5e[i]._2_x, D_5f5e[i]._4_y,
                                       D_5f5e[i]._6_z, D_5f5e[i]._8, D_5f5e[i]._a, D_5f5e[i]._c, D_5f5e[i]._e);
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
            PrintDebugOverlayStringFmt("%2x: T%02x A%02x X%d Y%d Z%d %d %d %d", i, D_5c5a[i]._0_tile, D_5c5a[i]._1_animTile,
                                       D_5c5a[i]._2_x, D_5c5a[i]._3_y, D_5c5a[i]._4_z, D_5c5a[i]._5, D_5c5a[i]._6,
                                       D_5c5a[i]._7);
        }
    }
}
#endif

void GRAP_BUF_Present(void)
{
#if defined(ENABLE_GRAP_OVERLAY_DEBUG)
    DisplayDebugMessages();
#endif

    (*s_pfFlushFrame)();

    s_dirty = false;
}

extern u32 TIME_CurrentFrame(void);

void GRAP_BUF_FlushPendingPresent(void)
{
    if (!s_dirty)
        return;

    u32 tick = TIME_CurrentFrame();
    if (s_lastPresentTick != tick)
    {
        s_lastPresentTick = tick;

        GRAP_BUF_Present();
    }
}

void GRAP_BUF_MarkDirty(void)
{
    s_dirty = true;
}

void GRAP_BUF_PrintChar(byte* ptr, int offset, byte fgColor, byte bgColor, int penX, int penY)
{
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

    s_dirty = true;
}

// 0x27
void GRAP_BUF_ScrollWindow(int left, int top, int right, int bottom, int amount)
{
    if (amount < 0)
    {
        amount = -amount;
        for (int y = top; y <= bottom - amount; y++)
        {
            memcpy(&g_linearEgaBuffer0[y * loresWidth + left], &g_linearEgaBuffer0[(y + amount) * loresWidth + left], right - left + 1);
        }

        for (int y = bottom - amount + 1; y <= bottom; y++)
        {
            memset(&g_linearEgaBuffer0[y * loresWidth + left], 0, right - left + 1);
        }
    }
    else
    {
        for (int y = bottom; y >= top + amount; y--)
        {
            memcpy(&g_linearEgaBuffer0[y * loresWidth + left], &g_linearEgaBuffer0[(y - amount) * loresWidth + left], right - left + 1);
        }

        for (int y = top; y < top + amount; y++)
        {
            memset(&g_linearEgaBuffer0[y * loresWidth + left], 0, right - left + 1);
        }
    }

    s_dirty = true;
}

// 0x3f
void GRAP_BUF_FillWindow(int x1, int y1, int x2, int y2, int xorMode)
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
        s_dirty = true;
    }
}

void GRAP_BUF_LoadTileset(byte* tileset)
{
    s_tileset = tileset;
}

void GRAP_BUF_UnloadTileset(void)
{
    if (s_tileset != NULL)
    {
        free(s_tileset);
        s_tileset = NULL;
    }
}

void GRAP_BUF_AnimateTileset(void)
{
    AnimateTileset(s_tileset);
}

void GRAP_BUF_UpdateTimeTileset(int mode, byte hour, byte minute)
{
    AnimateTimeTileset(s_tileset, mode, hour, minute);
}

void GRAP_BUF_PutTile(int tileX, int tileY, int tileIdx, int xOffset, int yOffset)
{
    byte* tile = &s_tileset[0x80 * tileIdx];

    int width = 16;
    int height = 16;
    int dstX = tileX * width + xOffset;
    int dstY = tileY * height + yOffset;

    for (int y = dstY; y < dstY + height; y++)
    {
        for (int x = dstX; x < dstX + width; x += 2)
        {
            GrPutByte(D_52ba_vdp._52d8_page, x, y, *tile++);
        }
    }

    s_dirty = true;
}

void GRAP_BUF_PutAnimatedMoongateTile(int tileX, int tileY, int visibleRows, byte floorType, int xOffset, int yOffset)
{
    byte backup[0x80];

    AnimateTile_BuildMoongateTile(s_tileset, visibleRows, floorType, backup);
    GRAP_BUF_PutTile(tileX & 0xff, tileY & 0xff, 0x116, xOffset, yOffset); // magic circle tile is used as scratch tile
    AnimateTile_RestoreMoongateTile(s_tileset, backup);
}

static u16 StepLfsrSeed(u16 seed, u16 mask)
{
    int carry = seed & 1;

    seed >>= 1;
    if (carry)
    {
        seed ^= mask;
    }

    return seed;
}

static void PutTileRevealPixel(int tileX, int tileY, int tileIdx, int relX, int relY, int xOffset, int yOffset)
{
    byte packed;
    int dstX;
    int dstY;

    packed = s_tileset[0x80 * tileIdx + relY * 8 + (relX >> 1)];
    dstX = tileX * 16 + xOffset + relX;
    dstY = tileY * 16 + yOffset + relY;

    if ((relX & 1) == 0)
    {
        GrPutPixel(D_52ba_vdp._52d8_page, dstX, dstY, packed >> 4);
    }
    else
    {
        GrPutPixel(D_52ba_vdp._52d8_page, dstX, dstY, packed & 0x0f);
    }

    s_dirty = true;
}

// T1K:1b27
void GRAP_BUF_PutTileRevealStep(int tileX, int tileY, int tileIdx, int progress, int xOffset, int yOffset)
{
    u16 seed;

    if (progress == 0)
    {
        PutTileRevealPixel(tileX, tileY, tileIdx, 0, 0, xOffset, yOffset);
        return;
    }

    seed = s_tileRevealSeed;
    if (progress == 1 || seed == 0)
    {
        seed = 1;
    }

    PutTileRevealPixel(tileX, tileY, tileIdx, seed >> 4, seed & 0x0f, xOffset, yOffset);

    // 1b7f
    s_tileRevealSeed = StepLfsrSeed(seed, 0xb8);
}

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

//int ULTIMA_08e6_ClipRectCoord(int* x1, int* y1, int* x2, int* y2);

// 0x27
void GRAP_BUF_Line(int x1, int y1, int x2, int y2)
{
    // ULTIMA_08e6_ClipRectCoord(&x1, &y1, &x2, &y2);

    PlotLine(x1, y1, x2, y2);

    if (D_52ba_vdp._52d8_page == 0)
    {
        s_dirty = true;
    }
}

void GRAP_BUF_LineRectangle(int x1, int y1, int x2, int y2, byte color)
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

    s_dirty = true;
}

void GRAP_BUF_Pset(int x, int y)
{
    // ULTIMA_08e6_ClipRectCoord(&x1, &y1, &x2, &y2);

    GrPutClippedPixel(D_52ba_vdp._52d8_page, x, y, g_grapPenColor);

    if (D_52ba_vdp._52d8_page == 0)
    {
        s_dirty = true;
    }
}

inline byte GetImagePixel(byte packed, int relX)
{
    if ((relX & 1) == 0)
        return packed >> 4;

    return packed & 0x0f;
}

inline bool MaskHasPixel(byte* maskPtr, int relX)
{
    if (maskPtr == NULL)
        return true;

    return (maskPtr[relX / 8] & (0x80 >> (relX & 7))) == 0;
}

void GRAP_BUF_PutImage(ImageView* view, int x, int y, int flags)
{
    int width = view->width;
    int height = view->height;
    int byteWidth = view->byteWidth;
    int page = D_52ba_vdp._52d8_page;

    if (width <= 0 || height <= 0)
        return;

    bool vflip = (flags & 1) != 0;
    bool hflip = (flags & 2) != 0;

    for (int yy = 0; yy < height; yy++)
    {
        int srcY;
        int dstY;

        if (vflip)
        {
            srcY = height - yy - 1;
            dstY = y + yy + 1;
        }
        else
        {
            srcY = yy;
            dstY = y + yy;
        }

        byte* linePtr = &view->pixels[srcY * view->stride];
        byte* maskPtr = view->hasMask ? &view->maskBits[srcY * view->maskStride] : NULL;
        for (int byteX = 0; byteX < byteWidth; byteX++)
        {
            byte packed = linePtr[byteX];
            int leftRelX = byteX * 2;

            if (hflip)
            {
                int dstX = x + width - 2 - leftRelX;

                if (MaskHasPixel(maskPtr, leftRelX))
                {
                    GrPutClippedPixel(page, dstX, dstY, GetImagePixel(packed, leftRelX));
                }

                leftRelX++;
                if (leftRelX < width && MaskHasPixel(maskPtr, leftRelX))
                {
                    GrPutClippedPixel(page, dstX - 1, dstY, GetImagePixel(packed, leftRelX));
                }
            }
            else
            {
                int dstX = x + leftRelX;

                if (MaskHasPixel(maskPtr, leftRelX))
                {
                    GrPutClippedPixel(page, dstX, dstY, GetImagePixel(packed, leftRelX));
                }

                leftRelX++;
                if (leftRelX < width && MaskHasPixel(maskPtr, leftRelX))
                {
                    GrPutClippedPixel(page, dstX + 1, dstY, GetImagePixel(packed, leftRelX));
                }
            }
        }
    }

    if (page == 0)
    {
        s_dirty = true;
    }
}

void GRAP_BUF_PutBitImage(BitImageView* view, int x, int y)
{
    // TODO: drawing mode?
    int w = view->width;
    int h = view->height;
    byte* buf = view->bits;
    int stride = view->stride;

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
        s_dirty = true;
    }
}

void GRAP_BUF_TransferPage(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY)
{
    byte* srcPagePtr = GetPage(srcPage);
    byte* dstPagePtr = GetPage(dstPage);

    // TODO: check bounds
    for (int y = 0; y <= y2 - y1; y++)
    {
        memcpy(&dstPagePtr[(y + dstY) * loresWidth + dstX], &srcPagePtr[(y + y1) * loresWidth + x1], x2 - x1 + 1);
    }

    if (dstPage == 0)
    {
        s_dirty = true;
    }
}

void GRAP_BUF_TransferPage_Reveal(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY)
{
    GRAP_BUF_FlushPendingPresent();

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
            GRAP_BUF_Present();

            if (KEY_PollKey())
            {
                GRAP_BUF_TransferPage(srcPage, dstPage, x1, y1, x2, y2, dstX, dstY);
                return;
            }

            TIME_SleepMs(1 * 55);
        }
    }

    GRAP_BUF_Present();
}
