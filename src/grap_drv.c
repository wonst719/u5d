#include "common/common.h"
#include "vars.h"

#include <stdlib.h>
#include <string.h>

#if !defined(TARGET_DOS16)
#include "graphics/grap.h"
#endif

// 00: get screen height
int DRV_00(void) { return 200; }

// 03: initialize video
//void DRV_03(void) { }

// 06: alloc page buffer
// byte* DRV_06() { ... return 202_buffer; }

// 0c: free page buffer
//void DRV_0c() { }

// 0f: set page
void DRV_0f(int ax)
{
    debug("DRV_0f(%d)", ax);

    //EGA_0650_0f(ax);
    D_52ba_vdp._52d8_page = ax;
}

// 18: transfer area
void DRV_18(int ax, int bx, int cx, int dx, int si, int di, int carry)
{
#if !defined(TARGET_DOS16)
    int x1 = ax;
    int y1 = bx;
    int x2 = cx;
    int y2 = dx;
    // TODO: si, di not used?

    debug("DRV_18(%d,%d,%d,%d,%d,%d,%d)", ax, bx, cx, dx, si, di, carry);

    if (carry)
    {
        // transfer 1 -> 0
        GRAP_TransferPage(1, 0, x1, y1, x2, y2, x1, y1);
    }
    else
    {
        // transfer 0 -> 1
        GRAP_TransferPage(0, 1, x1, y1, x2, y2, x1, y1);
    }
#endif
}

// 1b: transfer fullscreen
void DRV_1b(int ax, int bx)
{
    // ax: src page
    // bx: dst page
    if (ax == 0 && bx == 1)
    {
        GRAP_TransferPage(0, 1, 0, 0, 319, 199, 0, 0);
    }
    else
    {
        // transfer 0 -> 1
        GRAP_TransferPage(1, 0, 0, 0, 319, 199, 0, 0);
    }
}

// 1e: ?
//void DRV_1e() {}

// 24: ?
// int DRV_24() {}

// 27: scroll text window
void DRV_27(int ax, int bx, int cx, int dx, int si)
{
#if !defined(TARGET_DOS16)
    GRAP_ScrollWindow(ax, bx, cx, dx, si);
#endif
}

// 2d: set pen color
void DRV_2d(byte al)
{
#if !defined(TARGET_DOS16)
    GRAP_SetPenColor(al);
#endif
}

// 30: pset
void DRV_30(int ax, int bx)
{
#if !defined(TARGET_DOS16)
    GRAP_Pset(ax, bx);
#endif
}

// 33: line
void DRV_33(int ax, int bx, int cx, int dx)
{
#if !defined(TARGET_DOS16)
    int x1 = ax;
    int y1 = bx;
    int x2 = cx;
    int y2 = dx;
    GRAP_Line(x1, y1, x2, y2);
#endif
}

// 39: hline
void DRV_39(int ax, int bx, int cx)
{
#if !defined(TARGET_DOS16)
    int x1 = ax;
    int y = bx;
    int x2 = cx;

    GRAP_Line(x1, y, x2, y);
#endif
}

// 3c: vline
void DRV_3c(int ax, int bx, int dx)
{
#if !defined(TARGET_DOS16)
    int x = ax;
    int y1 = bx;
    int y2 = dx;

    GRAP_Line(x, y1, x, y2);
#endif
}

// TODO: carry (xor mode?)
// 3f: fill rectangle
void DRV_3f(int ax, int bx, int cx, int dx, int carry)
{
#if !defined(TARGET_DOS16)
    int x1 = ax;
    int y1 = bx;
    int x2 = cx;
    int y2 = dx;
    GRAP_FillWindow(x1, y1, x2, y2, carry);
#endif
}

// 42: shuffle image data (ega only)
//void DRV_42() {}

// put_image(rsrc, imageIdx, x, y, vflip?)
void GRAP_PutImage(void* rsrc, int idx, int x, int y, int flags)
{
    // flags & 1: vflip
    // flags & 2: hflip

#if !defined(TARGET_DOS16)
    // TODO: implement properly
    byte* rsrcBytes = rsrc;

    int imageCount = *(u16*)&rsrcBytes[0];
    if (idx >= imageCount)
        return;

    // TODO: how to differentiate?
    if (*(u16*)&rsrcBytes[4] != 0)
    {
        // format with image mask (ITEMS.16, MON*.16)
        // TODO: process image mask
        u16 imageOffset = *(u16*)&rsrcBytes[2 + idx * 2];

        byte* imageBuf = &rsrcBytes[imageOffset];
        u16 width = *(u16*)&imageBuf[0];
        u16 height = *(u16*)&imageBuf[2];
        byte* imageData = &imageBuf[4];

        debug(" - fmt2 offset: 0x%x, w: %d, h: %d", imageOffset, width, height);

        GRAP_PutBitmap_Flip(imageData, x, y, width, height, flags);
        return;
    }

    u32 imageOffset = *(u32*)&rsrcBytes[2 + idx * 4];

    byte* imageBuf = &rsrcBytes[imageOffset];
    u16 width = *(u16*)&imageBuf[0];
    u16 height = *(u16*)&imageBuf[2];
    byte* imageData = &imageBuf[4];

    debug(" - fmt1 offset: 0x%x, w: %d, h: %d", imageOffset, width, height);

    GRAP_PutBitmap_Flip(imageData, x, y, width, height, flags);
#endif
}

void* D_tileset;

// 48: load tileset
void DRV_48_LoadTileset(void* charset)
{
    D_tileset = charset;
}

// 4b: put image (ax=seg, bx=idx, cx=flags, si=x, di=y)
void DRV_4b(void* rsrc, int idx, int x, int y, int flags)
{
    GRAP_PutImage(rsrc, idx, x, y, flags);
}

// 4e: copy "1-bit" image into page
void DRV_4e(byte* img, int idx, int x, int y)
{
#if !defined(TARGET_DOS16)
    // TODO
    byte* rsrcBytes = img;

    int imageCount = *(u16*)&rsrcBytes[0];
    if (idx >= imageCount)
        return;

    u16 imageOffset = *(u16*)&rsrcBytes[2 + idx * 2];

    byte* imageBuf = &rsrcBytes[imageOffset];
    u16 width = *(u16*)&imageBuf[0];
    u16 height = *(u16*)&imageBuf[2];
    byte* imageData = &imageBuf[4];
    int dataLen = ((width + 7) / 8) * height;

    //debug(" - offset: 0x%x, w: %d, h: %d, dataLen: %d", imageOffset, width, height, dataLen);

    GRAP_PutBitImage(imageData, x, y, width, height);
#endif
}

#if !defined(TARGET_DOS16)
extern byte* g_tileset_mem;
#endif

// 51: put tile
void DRV_51_PutTile(byte al, byte ah, int bx, int cx, int dx, int si, int di)
{
#if !defined(TARGET_DOS16)
    int x = al;
    int y = ah;
    int tile = bx;

    GRAP_Temp_PutTile(x, y, tile, &g_tileset_mem[128 * tile]);
#endif
}

// 5a: free tileset
void DRV_5a_FreeTileset(void)
{
    if (D_tileset != 0)
    {
        free(D_tileset);
    }
}

// 5d: print char
void DRV_5d(byte* es, int di, byte dl, byte dh, byte al, byte bl)
{
#if !defined(TARGET_DOS16)
    // es = ptr_base
    // di = offset
    // dl = [text_fg_color]
    // dh = [text_bg_color]
    // al = [x]
    // bl = [y]

    GRAP_PrintChar(es, di, dl, dh, al, bl);
#endif
}

// 60: tile animation
void DRV_60(int ax, byte bl, int cx, int dx, int si, int di, int carry)
{
    debug("DRV_60(%d,%d,%d,%d,%d,%d,%d)", ax, bl, cx, dx, si, di, carry);

    // ULTIMA_1112: CF=1
    // ULTIMA_6fd6: CF=0

    if (!carry)
    {
        // ax: ?

        // 1567~
        // animate tileset
    }
    else
    {
        // 196e~
    }
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
void DRV_60_CF0(void* ax)
{
    // ax: ignored?

    // ...

    // animate water

    // 15ef, 1620, 1651, 1682
    // water 1, 2, 3, lava
    AnimateTile_ShiftDown(g_tileset_mem, 0x0080);
    AnimateTile_ShiftDown(g_tileset_mem, 0x0100);
    AnimateTile_ShiftDown(g_tileset_mem, 0x0180);
    AnimateTile_ShiftDown(g_tileset_mem, 0x4780);

    // 16b5: remove light blue from 3000..3500
    AnimateTile_MaskColor(g_tileset_mem, 0x3000, 0x6666, 0x280);

    // 16c4: fixup horiz bridge (3500)
    memset(g_tileset_mem + 0x3500, 0, 0x10);
    memset(g_tileset_mem + 0x3570, 0, 0x10);

    // 16d6: fixup vert bridge (3580 <- 3d80)
    AnimateTile_MaskTile(g_tileset_mem, 0x3580, 0x3d80, 0x40);

    // 16e9: remove light blue from 3600..3800
    AnimateTile_MaskColor(g_tileset_mem, 0x3600, 0x6666, 0x100);

    // 16f8: mix mask (3000: water, 3800: mask)
    AnimateTile_MixTilesUsingMask(g_tileset_mem, 0x3000, 0x3800, 0x0180, 16);

    // 8400: some light, 8000: flash?, f580: mask??
    // some effect(di: 0x8000, si: 0x8400, dx: 0xf580);

    // da00: some light, 8000: flash?, f480: mask??
    // some effect(di: 0x8000, si: 0xda00, dx: 0xf480);

    // 1807
    AnimateTile_MaskTile(g_tileset_mem, 0x1a00, 0x6800, 0x100);

    // 181a
    AnimateTile_MixTilesUsingMask(g_tileset_mem, 0x1a00, 0x6800, 0x0180, 4);

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

// 63: put image (forced hflip)
void DRV_63(void* rsrc, int idx, int x, int y, int flags)
{
    GRAP_PutImage(rsrc, idx, x, y, flags | 2);
}

// 66: put image gradually (cf==0: "ultima", cf==1: tile)
void DRV_66(int ax, int bx, int cx, int dx, int si, int di, int cf)
{
    debug("DRV_66(%d,%d,%d,%d,%d,%d,%d)", ax, bx, cx, dx, si, di, cf);

#if !defined(TARGET_DOS16)
    // cf == 0: with sound?
    // cf == 1: no sound?
    if (cf == 1)
    {
        // TODO: temporary
        // ax: tile x
        // bx: tile y
        // cx: offset x
        // dx: offset y
        // si: tile idx
        // di: progress (0..ff)
        DRV_51_PutTile(ax, bx, si, 0, 0, 0, 0);

        return;
    }

    // ax: x1
    // bx: y1
    // cx: x2
    // dx: y2
    GRAP_TransferPage_Reveal(1, 0, ax, bx, cx, dx, ax, bx);
#endif
}

int DRV_0000_12ba = 0; // t1k offset

// 69: show or animate "wd"
void DRV_69(byte* ax, int carry)
{
#if !defined(TARGET_DOS16)
    if (carry == 0)
    {
        // animate wd
        // hardcoded values in driver
        int x1 = 0;
        int x2 = 319;
        int y1 = DRV_0000_12ba * 50;
        int y2 = y1 + 49 - 1;
        int dstX = 0;
        int dstY = 65;
        GRAP_TransferPage(1, 0, x1, y1, x2, y2, dstX, dstY);

        DRV_0000_12ba = (DRV_0000_12ba + 1) & 3;
    }
    else
    {
        // show wd using "WD.BIT"
        // TODO: implement
        debug("DRV_69(%d)", carry);
    }
#endif
}

// 6c: ax: ?, bl: hour, bh: minute
void DRV_6c(int ax, byte bl, byte bh)
{ debug("DRV_6c(%d,%d,%d)", ax, bl, bh); }

// 6f: ?
int DRV_6f(int ax)
{
    debug("DRV_6f(%d)", ax);
    //return DAT_0000_0e60;
    return 0; // DUMMY
}
