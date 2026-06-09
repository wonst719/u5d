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

static pfGrapPresent* s_pfPresent;

static u32 s_lastPresentTick = 0;
static bool s_dirty = false;

// T1K:19d9
static u16 s_tileRevealSeed = 0;

// T1K:12ba
static int s_wdFrame = 0;

void GRAP_BUF_Initialize(pfGrapPresent* pfPresent)
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

static byte* GetPage(int page)
{
    if (page == 0)
        return g_linearEgaBuffer0;
    else if (page == 1)
        return g_linearEgaBuffer1;
    return 0;
}

#if defined(ENABLE_GRAP_OVERLAY)
static void GrPutOverlayPixel(int x, int y, int egaColor) { g_linearOverlayBuffer[y * hiresWidth + x] = egaColor; }
#endif

static void GrPutPixel(int page, int x, int y, int egaColor)
{
    byte* target = GetPage(page);
    target[y * loresWidth + x] = egaColor;
}

static void GrPutByte(int page, int x, int y, byte egaByte)
{
    byte* target = GetPage(page);
    target[y * loresWidth + x] = egaByte >> 4;
    target[y * loresWidth + x + 1] = egaByte & 0xf;
}

#if defined(ENABLE_GRAP_OVERLAY)
static void GrPutOverlayMonoByte(int x, int y, byte b, int egaColor)
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

    (*s_pfPresent)();

    s_dirty = false;
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

        GRAP_BUF_Present();
    }
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

    GrPutPixel(D_52ba_vdp._52d8_page, x, y, g_grapPenColor);

    if (D_52ba_vdp._52d8_page == 0)
    {
        s_dirty = true;
    }
}

static void GRAP_BUF_PutImageNormal(ImageView* view, int x, int y)
{
    int w = view->width;
    int h = view->height;
    byte* buf = view->pixels;
    int stride = view->stride;

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
        s_dirty = true;
    }
}

// TODO: process mask
void GRAP_BUF_PutImage(ImageView* view, int x, int y, int flags)
{
    if (flags == 0)
    {
        GRAP_BUF_PutImageNormal(view, x, y);
        return;
    }

    // flags & 1: vflip
    // flags & 2: hflip

    int w = view->width;
    int h = view->height;
    byte* buf = view->pixels;
    int stride = view->stride;

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

    // TODO: temporary
    if (hflip)
    {
        x--;
    }

    // TODO: temporary
    if (vflip)
    {
        y++;
    }

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

// TODO: refactor wd

#define WD_FRAME_X 0x10
#define WD_FRAME_WIDTH 0x120
#define WD_FRAME_HEIGHT 0x31
#define WD_FRAME_SPACING 0x32
#define WD_FRAME_COUNT 4
#define WD_SCREEN_Y 0x41

// T1K:12be
static void WdShowNextFrame(void)
{
    int srcY = s_wdFrame * WD_FRAME_SPACING;

    for (int row = 0; row < WD_FRAME_HEIGHT; row++)
    {
        memcpy(&g_linearEgaBuffer0[(WD_SCREEN_Y + row) * loresWidth], &g_linearEgaBuffer1[(srcY + row) * loresWidth], loresWidth);
    }

    s_wdFrame = (s_wdFrame + 1) & 3;
}

void GRAP_BUF_ShowNextWDFrame(void)
{
    WdShowNextFrame();
    s_dirty = true;
}

static u16 StepWdSeed(u16 seed)
{
    int carry = seed & 1;

    seed >>= 1;
    if (carry)
    {
        seed ^= 0x3500;
    }

    return seed;
}

static bool WdMaskMatches(BitImageView* mask, int x, int y, bool maskedPixels)
{
    if (x >= mask->width || y >= mask->height)
        return false;

    return ((mask->bits[y * mask->stride + x / 8] & (0x80 >> (x % 8))) != 0) == maskedPixels;
}

static void WdCopyFramePixelsFromBackup(byte* backup, int maskX, int maskY)
{
    int x = WD_FRAME_X + maskX;

    for (int frame = 0; frame < WD_FRAME_COUNT; frame++)
    {
        int y = frame * WD_FRAME_SPACING + maskY;
        g_linearEgaBuffer1[y * loresWidth + x] = backup[y * loresWidth + x];
    }
}

// T1K:139c
static bool AnimateWdPass(BitImageView* mask, byte* backup, bool maskedPixels)
{
    u16 seed;
    int frameCountdown;
    int generated;

    seed = 1;
    frameCountdown = 0x100;
    generated = 0;

    for (int i = 0; i < 0x8000; i++)
    {
        int relY = seed / WD_FRAME_WIDTH;
        int x = seed % WD_FRAME_WIDTH;

        if (relY < WD_FRAME_HEIGHT && WdMaskMatches(mask, x, relY, maskedPixels))
        {
            WdCopyFramePixelsFromBackup(backup, x, relY);

            if (generated % 64 == 63)
            {
                GRAP_BUF_Present();

                if (KEY_PollKey())
                    return true;

                if (maskedPixels)
                {
                    TIME_SleepMs(120);
                }
                else
                {
                    TIME_SleepMs(33);
                }
            }

            generated++;
        }

        frameCountdown--;
        if (frameCountdown == 0)
        {
            WdShowNextFrame();
            GRAP_BUF_Present();
            frameCountdown = 0x100;
        }

        seed = StepWdSeed(seed);
        if (seed == 1)
            break;
    }

    return false;
}

void GRAP_BUF_AnimateWD(BitImageView* mask)
{
    byte* backup;
    bool aborted;
    int pageSize;

    GRAP_FlushPrevPresentReq();

    pageSize = loresWidth * loresHeight;
    backup = malloc(pageSize); // TODO: temp
    if (backup == NULL)
        return;

    memcpy(backup, g_linearEgaBuffer1, pageSize);
    memset(g_linearEgaBuffer1, 0, pageSize);

    aborted = AnimateWdPass(mask, backup, false);
    if (!aborted)
    {
        aborted = AnimateWdPass(mask, backup, true);
    }

    if (aborted)
    {
        memcpy(g_linearEgaBuffer1, backup, pageSize);
        WdShowNextFrame();
        GRAP_BUF_Present();
        free(backup);
        return;
    }

    WdCopyFramePixelsFromBackup(backup, 0, 0);
    WdShowNextFrame();
    GRAP_BUF_Present();

    memcpy(g_linearEgaBuffer1, backup, pageSize);
    free(backup);
}

// 112c
static const byte s_originLogoAnimationTable[] =
{
    0x07,
    // 0
    0x00, 0x4b, 0x03, 0x0b, 0xff, 0xff, 0xff, 0x01,
    0xff, 0xff, 0xff, 0xff, 0x00, 0x02, 0xff,
    // 1
    0x03, 0x48, 0x07, 0x0f, 0xff, 0xff, 0x01, 0x05,
    0xff, 0xff, 0x02, 0x04, 0xff, 0xff, 0x03, 0xff,
    0x00, 0x06, 0xff,
    // 2
    0x0a, 0x47, 0x0b, 0x13, 0xff, 0xff, 0x02, 0x08,
    0xff, 0x03, 0x07, 0xff, 0x01, 0x09, 0xff, 0x04,
    0x06, 0xff, 0x05, 0xff, 0x00, 0x0a, 0xff,
    // 3
    0x15, 0x42, 0x14, 0x1c, 0xff, 0x04, 0x0f, 0xff,
    0x01, 0x07, 0x0c, 0x12, 0xff, 0x05, 0x0e, 0xff,
    0x02, 0x08, 0x0b, 0x11, 0xff, 0x03, 0x06, 0x0d,
    0x10, 0xff, 0x09, 0x0a, 0xff, 0x00, 0x13, 0xff,
    // 4
    0x29, 0x3c, 0x20, 0x28, 0xff, 0x07, 0x18, 0xff,
    0x02, 0x0c, 0x13, 0x1d, 0xff, 0x03, 0x08, 0x0d,
    0x12, 0x17, 0x1c, 0xff, 0x01, 0x06, 0x0b, 0x14,
    0x19, 0x1e, 0xff, 0x04, 0x09, 0x0e, 0x11, 0x16,
    0x1b, 0xff, 0x05, 0x0a, 0x0f, 0x10, 0x15, 0x1a,
    0xff, 0x00, 0x1f, 0xff,
    // 5
    0x49, 0x35, 0x2d, 0x35, 0xff, 0x04, 0x0b, 0x12,
    0x1a, 0x21, 0x28, 0xff, 0x01, 0x08, 0x0f, 0x13,
    0x24, 0x2b, 0xff, 0x06, 0x0d, 0x14, 0x18, 0x1f,
    0x26, 0xff, 0x03, 0x0a, 0x11, 0x16, 0x1b, 0x22,
    0x29, 0xff, 0x02, 0x05, 0x09, 0x0c, 0x10, 0x13,
    0x19, 0x1c, 0x20, 0x23, 0x27, 0x2a, 0xff, 0x07,
    0x0e, 0x15, 0x17, 0x1e, 0x25, 0xff, 0x00, 0x2c,
    0xff,
    // 6
    0x76, 0x2e, 0x3d, 0x45, 0xff, 0x1c, 0x17, 0x12,
    0x0d, 0x08, 0x03, 0x20, 0x25, 0x2a, 0x2f, 0x34,
    0x39, 0xff, 0x1a, 0x15, 0x10, 0x0b, 0x06, 0x01,
    0x22, 0x27, 0x2c, 0x31, 0x36, 0x3b, 0xff, 0x1d,
    0x18, 0x13, 0x0e, 0x09, 0x04, 0x1f, 0x24, 0x29,
    0x2e, 0x33, 0x38, 0xff, 0x1b, 0x16, 0x11, 0x0c,
    0x07, 0x02, 0x21, 0x26, 0x2b, 0x30, 0x35, 0x3a,
    0xff, 0x19, 0x0f, 0x05, 0x23, 0x2d, 0x37, 0xff,
    0x1e, 0x28, 0x32, 0x14, 0x0a, 0xff, 0x00, 0x3c,
    0xff
};

static int s_originLogoListStart; // 0e53 (ptr)
static int s_originLogoTableCursor; // 0e55 (ptr)
static int s_originLogoListLenMinusOne; // 0e03
static int s_originLogoTargetBaseY; // 0e0b
static int s_originLogoSourceBaseY; // 0e0d
static int s_originLogoLineCount; // 0e0f
static byte s_originLogoLineVisible[128]; // 0e13

// 0ebe
static void OriginLogoClearLine(int y)
{
    if (y < loresHeight)
    {
        memset(&g_linearEgaBuffer0[y * loresWidth], 0, loresWidth);
    }
}

// 0ed7
static void OriginLogoCopyColoredLineFromBackBuffer(int srcY, int dstY)
{
    if (srcY < loresHeight && dstY < loresHeight)
    {
        byte* src = &g_linearEgaBuffer1[srcY * loresWidth];
        byte* dst = &g_linearEgaBuffer0[dstY * loresWidth];

        for (int x = 0; x < loresWidth; x++)
        {
            dst[x] = src[x] & 9; // blue
        }
    }
}

static byte OriginLogoReadByte(void)
{
    if (s_originLogoTableCursor >= ARRAYSIZE(s_originLogoAnimationTable))
        return 0;

    return s_originLogoAnimationTable[s_originLogoTableCursor++];
}

// 106f
static void OriginLogoReadHeader(void)
{
    s_originLogoSourceBaseY = OriginLogoReadByte();
    s_originLogoTargetBaseY = OriginLogoReadByte();
    s_originLogoLineCount = OriginLogoReadByte();
}

// 1085
static void OriginLogoReadList(void)
{
    byte listLen = OriginLogoReadByte();

    s_originLogoListLenMinusOne = listLen - 1;
    s_originLogoListStart = s_originLogoTableCursor;
    s_originLogoTableCursor += listLen;
}

// 10a8
static void OriginLogoPreparePass(void)
{
    OriginLogoReadHeader();
    OriginLogoReadList();
}

static byte OriginLogoListAt(int index)
{
    if (index < 0 || s_originLogoListStart + index >= ARRAYSIZE(s_originLogoAnimationTable))
        return 0xff;

    return s_originLogoAnimationTable[s_originLogoListStart + index];
}

// 0e7f
static void OriginLogoCountLineStates(int* hiddenCount, int* visibleCount)
{
    *hiddenCount = 0;
    *visibleCount = 0;

    for (int i = 0; i < s_originLogoLineCount; i++)
    {
        if (s_originLogoLineVisible[i] == 0)
        {
            (*hiddenCount)++;
        }
        else
        {
            (*visibleCount)++;
        }
    }
}

// 0f12
static int OriginLogoInitialY(int direction)
{
    if (direction == 0)
        return s_originLogoTargetBaseY;

    return s_originLogoTargetBaseY + s_originLogoLineCount;
}

// 0f2e
static u16 OriginLogoAdvanceY(int direction, u16 y)
{
    if (direction == 0)
        return y + 1;

    return y - 1;
}

// 0f62
static bool OriginLogoRenderStateStep(int direction)
{
    int hiddenCount; // 0e57
    int visibleCount;
    int y;
    int scan;

    y = OriginLogoInitialY(direction);
    scan = 0;

    OriginLogoCountLineStates(&hiddenCount, &visibleCount);

    for (int i = 0; i < hiddenCount / 2; i++)
    {
        OriginLogoClearLine(y);
        y = OriginLogoAdvanceY(direction, y);
    }

    for (int i = 0; i < visibleCount; i++)
    {
        // 0eab
        while (scan < s_originLogoLineCount && s_originLogoLineVisible[scan] == 0)
        {
            scan++;
        }

        if (scan >= s_originLogoLineCount)
            break;

        OriginLogoCopyColoredLineFromBackBuffer(s_originLogoSourceBaseY + scan, y);
        scan++;
        y = OriginLogoAdvanceY(direction, y);
    }

    hiddenCount++;

    for (int i = 0; i < hiddenCount / 2; i++)
    {
        OriginLogoClearLine(y);
        y = OriginLogoAdvanceY(direction, y);
    }

    GRAP_BUF_Present();

    if (KEY_PollKey())
    {
        return true;
    }

    TIME_SleepMs(2 * (s_originLogoLineCount / 3 + 15));

    return false;
}

// 0fe2
static bool OriginLogoApplyReverseSet(int direction)
{
    int pos; // 0e05
    int count; // 0e07

    memset(s_originLogoLineVisible, 0, s_originLogoLineCount);

    pos = s_originLogoListLenMinusOne - 1;
    count = 6;

    while (count >= 0)
    {
        byte value = OriginLogoListAt(pos--);

        if (value == 0xff)
        {
            bool aborted = OriginLogoRenderStateStep(direction);
            count--;

            if (aborted)
                return true;
        }
        else if (value < s_originLogoLineCount)
        {
            s_originLogoLineVisible[value] = 1;
        }
    }

    return false;
}

// 1023
static bool OriginLogoApplyForwardClear(int direction)
{
    int pos;
    int count;

    pos = 1;
    count = 6;

    while (count > 0)
    {
        byte value = OriginLogoListAt(pos++);

        if (value == 0xff)
        {
            bool aborted = OriginLogoRenderStateStep(direction);
            count--;

            if (aborted)
                return true;
        }
        else if (value < s_originLogoLineCount)
        {
            s_originLogoLineVisible[value] = 0;
        }
    }

    return false;
}

// 1107
static void OriginLogoCleanupAfterAbort(void)
{
    s_originLogoTableCursor = 0xbf;
    OriginLogoReadHeader();

    memset(s_originLogoLineVisible, 1, s_originLogoLineCount);
    OriginLogoRenderStateStep(0);
}

// 10b7
int GRAP_BUF_AnimateOriginLogo(int timerCalibration)
{
    int passCount;
    int direction;
    bool cleanup;

    GRAP_FlushPrevPresentReq();

    s_originLogoListStart = 0;
    s_originLogoListLenMinusOne = 0;
    s_originLogoSourceBaseY = 0;
    s_originLogoTargetBaseY = 0;
    s_originLogoLineCount = 0;
    memset(s_originLogoLineVisible, 0, sizeof(s_originLogoLineVisible));

    s_originLogoTableCursor = 0;
    cleanup = false;
    passCount = OriginLogoReadByte();
    direction = 1;

    while (passCount != 0)
    {
        OriginLogoPreparePass();
        direction ^= 1;

        if (OriginLogoApplyReverseSet(direction))
        {
            OriginLogoCleanupAfterAbort();
            cleanup = true;
            break;
        }

        passCount--;
        if (passCount == 0)
            break;

        if (OriginLogoApplyForwardClear(direction))
        {
            OriginLogoCleanupAfterAbort();
            cleanup = true;
            break;
        }
    }

    return cleanup ? 1 : 0;
}

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
