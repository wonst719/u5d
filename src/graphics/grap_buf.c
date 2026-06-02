#include "common/common.h"

#include "vars.h"

#include "grap_buf.h"
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

static void Present(void)
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

        Present();
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
void GRAP_BUF_ScrollWindow(int l, int t, int r, int b, int amount)
{
    if (amount < 0)
    {
        amount = -amount;
        for (int y = t; y <= b - amount; y++)
        {
            memcpy(&g_linearEgaBuffer0[y * loresWidth + l], &g_linearEgaBuffer0[(y + amount) * loresWidth + l], r - l + 1);
        }

        for (int y = b - amount + 1; y <= b; y++)
        {
            memset(&g_linearEgaBuffer0[y * loresWidth + l], 0, r - l + 1);
        }
    }
    else
    {
        for (int y = b; y >= t + amount; y--)
        {
            memcpy(&g_linearEgaBuffer0[y * loresWidth + l], &g_linearEgaBuffer0[(y - amount) * loresWidth + l], r - l + 1);
        }

        for (int y = t; y < t + amount; y++)
        {
            memset(&g_linearEgaBuffer0[y * loresWidth + l], 0, r - l + 1);
        }
    }

    s_dirty = true;
}

extern byte g_grapPenColor;

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

void GRAP_BUF_PutTile(int x1, int y1, int tileIdx)
{
    byte* tile = &s_tileset[128 * tileIdx];

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

    s_dirty = true;
}

static u16 r16(u8* p)
{
    return (u16)p[0] | ((u16)p[1] << 8);
}

static void w16(u8* p, u16 v)
{
    p[0] = (u8)v;
    p[1] = (u8)(v >> 8);
}

static void AnimateTile_ShiftDown(byte* tiles, int base)
{
    byte tail[8];
    memcpy(tail, tiles + base + 0x78, sizeof(tail));
    memmove(tiles + base + 8, tiles + base, 0x78);
    memcpy(tiles + base, tail, sizeof(tail));
}

// d &= m
static void AnimateTile_MaskColor(u8* tiles, int off, int mask, int words)
{
    for (int i = 0; i < words; i++)
    {
        w16(tiles + off + i * 2, (u16)(r16(tiles + off + i * 2) & mask));
    }
}

// d &= ~s
static void AnimateTile_MaskTile(u8* tiles, int dst, int src, int words)
{
    for (int i = 0; i < words; i++)
    {
        int off = i * 2;
        w16(tiles + dst + off, (u16)(r16(tiles + dst + off) & (u16)~r16(tiles + src + off)));
    }
}

// d |= m & s
// di, si, bx, cx
static void AnimateTile_MixTilesUsingMask(u8* tiles, int dst, int mask, int src, int blocks)
{
    for (int block = 0; block < blocks; block++)
    {
        for (int off = 0; off < 0x80; off += 2)
        {
            int dstOff = dst + block * 0x80 + off;
            int maskOff = mask + block * 0x80 + off;
            int srcOff = src + off;

            u16 mixed = (u16)(r16(tiles + maskOff) & r16(tiles + srcOff));
            w16(tiles + dstOff, (u16)(r16(tiles + dstOff) | mixed));
        }
    }
}

// animate tiles
void GRAP_BUF_AnimateTileset(void)
{
    // ...

    // animate water

    // 15ef, 1620, 1651, 1682
    // water 1, 2, 3, lava
    AnimateTile_ShiftDown(s_tileset, 0x0080);
    AnimateTile_ShiftDown(s_tileset, 0x0100);
    AnimateTile_ShiftDown(s_tileset, 0x0180);
    AnimateTile_ShiftDown(s_tileset, 0x4780);

    // 16b5: remove light blue from 3000..3500
    AnimateTile_MaskColor(s_tileset, 0x3000, 0x6666, 0x280);

    // 16c4: fixup horiz bridge (3500)
    memset(s_tileset + 0x3500, 0, 0x10);
    memset(s_tileset + 0x3570, 0, 0x10);

    // 16d6: fixup vert bridge (3580 <- 3d80)
    AnimateTile_MaskTile(s_tileset, 0x3580, 0x3d80, 0x40);

    // 16e9: remove light blue from 3600..3800
    AnimateTile_MaskColor(s_tileset, 0x3600, 0x6666, 0x100);

    // 16f8: mix mask (3000: water, 3800: mask)
    AnimateTile_MixTilesUsingMask(s_tileset, 0x3000, 0x3800, 0x0180, 16);

    // 8400: some light, 8000: flash?, f580: mask??
    // some effect(di: 0x8000, si: 0x8400, dx: 0xf580);

    // da00: some light, 8000: flash?, f480: mask??
    // some effect(di: 0x8000, si: 0xda00, dx: 0xf480);

    // 1807
    AnimateTile_MaskTile(s_tileset, 0x1a00, 0x6800, 0x100);

    // 181a
    AnimateTile_MixTilesUsingMask(s_tileset, 0x1a00, 0x6800, 0x0180, 4);

    // 183b (7200: water, 6800: diagonal masks)
    // some effect(di: 0x7200, si: 0x6800, bx: 0x0180, cx: 4);

    // 1858
    // some effect(di: 0x6000, si: 0x5800, bx: 0xf500, cx: 4);

    // 1884
    // some effect(di: 0x6600, si: 0x5e00, bx: 0xf500, cx: 4);

    // 18b0
    // some effect(di: 0x6100, si: 0x6f00, bx: 0xf580);

    // flags, fireplaces?
    // 18d2 if ((DAT_0000_14de & 1) != 0) FUN_0000_1968(0x900)
    // 18e1 if ((DAT_0000_14de & 2) != 0) FUN_0000_194c(0xa10)
    // 18f0 if ((DAT_0000_14de & 4) != 0) FUN_0000_1968(0xa80)
    // 18ff if ((DAT_0000_14de & 8) != 0) FUN_0000_1968(0x1f00)
    // 190e if ((DAT_0000_14de & 0x10) != 0) FUN_0000_1963(0x9088)
    // 191d if ((DAT_0000_14de & 0x20) != 0) FUN_0000_194c(0x9188)
    // 192c if ((DAT_0000_14de & 0x40) != 0) FUN_0000_1963(0x9688)
    // 193b if ((DAT_0000_14de & 1) != 0) FUN_0000_194c(0x9788)
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
    // ULTIMA_08e6_constraint_imagewindow(&x1, &y1, &x2, &y2);

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

extern int KEY_PollKey(void);

extern void TIME_SleepMs(int ms);

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

            if (KEY_PollKey())
            {
                GRAP_BUF_TransferPage(srcPage, dstPage, x1, y1, x2, y2, dstX, dstY);
                return;
            }

            TIME_SleepMs(1 * 55);
        }
    }

    Present();
}
