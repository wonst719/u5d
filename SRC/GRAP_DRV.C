#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>
#include <stdlib.h>

#if defined(TARGET_WINDOWS)
extern void GRAP_WIN_ScrollWindow(int ax, int bx, int cx, int dx, int si);
extern void GRAP_WIN_Line(int x1, int y1, int x2, int y2);
extern void GRAP_WIN_Pset(int x, int y);
extern void GRAP_WIN_FillWindow(int x1, int y1, int x2, int y2);
extern void GRAP_WIN_Temp_PutTile(int x1, int y1, uint tileIdx, byte* tile);
extern void GRAP_WIN_PutBitmap(byte* buf, int x, int y, int w, int h);
extern void GRAP_WIN_PutBitmap_Flip(byte* buf, int x, int y, int w, int h, int flags);
extern void GRAP_WIN_PutBitImage(byte* buf, int x, int y, int w, int h);
extern void GRAP_WIN_TransferPage(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);
extern void GRAP_WIN_TransferPage_Reveal(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);
#endif

byte g_grapPenColor = 0;

#if 0
u8* DAT_0000_0202_buffer;

u16 DAT_0000_0204; //, 04f6
void* DAT_0000_0206_tileset;
u8 DAT_0000_0210; // xref: 045c, 04f6
u8 DAT_0000_0211; // xref: 045c
u8 DAT_0000_0214; // xref: 04f6
u16 DAT_0000_0216; // xref: 045c, 04f6
u16 DAT_0000_0222;

u16 DAT_0000_0226_y;
u16 DAT_0000_022a; // y2?

VideoDriverParams* DAT_0000_023c_drv_param = &D_52ba_vdp; // DUMMY

void FUN_0000_0582_03_init_video_mode_etc(void) {}

u8* F_EGA_0614_06_alloc_buffer(void)
{
    DAT_0000_0202_buffer = calloc(1, 0x400 * 16); // 0x400 paragraphs = 16 kb

    return DAT_0000_0202_buffer;
}

void F_EGA_0634_0c_free_buffer(void) { free(DAT_0000_0202_buffer); }

void F_EGA_0650_0f(int param_1)
{
    if (param_1 == 0 || (param_1 < 2 && DAT_0000_0202_buffer != 0))
    {
        DAT_0000_023c_drv_param->_52d8_page = param_1;
    }
}

void F_EGA_17a9_48_load_tileset(void* charset, int cx)
{
    DAT_0000_0206_tileset = charset;
    // si = 0;
    // ds = charset;
    int di = cx;
    if (di != -1)
        di++;

    // 17be_swizzle
}

void F_EGA_18f6_5a_free_tileset(void)
{
    if (DAT_0000_0206_tileset != 0)
    {
        free(DAT_0000_0206_tileset);
    }
}
#endif

extern VideoDriverParams D_52ba_vdp;

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
    printf("DRV_0f(%d)\n", ax);

    //F_EGA_0650_0f(ax);
    D_52ba_vdp._52d8_page = ax;
}

// 18: transfer area
void DRV_18(int ax, int bx, int cx, int dx, int si, int di, int carry)
{
#if defined(TARGET_WINDOWS)
    int x1 = ax;
    int y1 = bx;
    int x2 = cx;
    int y2 = dx;
    // TODO: si, di not used?

    printf("DRV_18(%d,%d,%d,%d,%d,%d,%d)\n", ax, bx, cx, dx, si, di, carry);

    if (carry)
    {
        // transfer 1 -> 0
        GRAP_WIN_TransferPage(1, 0, x1, y1, x2, y2, x1, y1);
    }
    else
    {
        // transfer 0 -> 1
        GRAP_WIN_TransferPage(0, 1, x1, y1, x2, y2, x1, y1);
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
        GRAP_WIN_TransferPage(0, 1, 0, 0, 319, 199, 0, 0);
    }
    else
    {
        // transfer 0 -> 1
        GRAP_WIN_TransferPage(1, 0, 0, 0, 319, 199, 0, 0);
    }
}

// 1e: ?
//void DRV_1e() {}

// 24: ?
// int DRV_24() {}

// 27: scroll text window
void DRV_27(int ax, int bx, int cx, int dx, int si)
{
#if defined(TARGET_WINDOWS)
    GRAP_WIN_ScrollWindow(ax, bx, cx, dx, si);
#endif
}

// 2d: set pen color
void DRV_2d(byte al)
{
    g_grapPenColor = al;
}

// 30: pset
void DRV_30(int ax, int bx)
{
#if defined(TARGET_WINDOWS)
    GRAP_WIN_Pset(ax, bx);
#endif
}

// 33: line
void DRV_33(int ax, int bx, int cx, int dx)
{
#if defined(TARGET_WINDOWS)
    int x1 = ax;
    int y1 = bx;
    int x2 = cx;
    int y2 = dx;
    GRAP_WIN_Line(x1, y1, x2, y2);
#endif
}

// 39: hline
void DRV_39(int ax, int bx, int cx)
{
#if defined(TARGET_WINDOWS)
    int x1 = ax;
    int y = bx;
    int x2 = cx;

    GRAP_WIN_Line(x1, y, x2, y);
#endif
}

// 3c: vline
void DRV_3c(int ax, int bx, int dx)
{
#if defined(TARGET_WINDOWS)
    int x = ax;
    int y1 = bx;
    int y2 = dx;

    GRAP_WIN_Line(x, y1, x, y2);
#endif
}

// TODO: carry (xor mode?)
// 3f: fill rectangle
void DRV_3f(int ax, int bx, int cx, int dx, int carry)
{
#if defined(TARGET_WINDOWS)
    int x1 = ax;
    int y1 = bx;
    int x2 = cx;
    int y2 = dx;
	GRAP_WIN_FillWindow(x1, y1, x2, y2);
#endif
}

// 42: shuffle image data (ega only)
//void DRV_42() {}

// 48: load tileset
//void DRV_48() {}

// put_image(rsrc, imageIdx, x, y, vflip?)
void GRAP_PutImage(void* rsrc, int idx, int x, int y, int flags)
{
    // flags & 1: vflip
    // flags & 2: hflip

#if defined(TARGET_WINDOWS)
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

        printf(" - fmt2 offset: 0x%x, w: %d, h: %d\n", imageOffset, width, height);

        GRAP_WIN_PutBitmap_Flip(imageData, x, y, width, height, flags);
        return;
    }

    u32 imageOffset = *(u32*)&rsrcBytes[2 + idx * 4];

    byte* imageBuf = &rsrcBytes[imageOffset];
    u16 width = *(u16*)&imageBuf[0];
    u16 height = *(u16*)&imageBuf[2];
    byte* imageData = &imageBuf[4];

    printf(" - fmt1 offset: 0x%x, w: %d, h: %d\n", imageOffset, width, height);

    GRAP_WIN_PutBitmap_Flip(imageData, x, y, width, height, flags);
#endif
}

// 4b: put image (ax=seg, bx=idx, cx=flags, si=x, di=y)
void DRV_4b(void* rsrc, int idx, int x, int y, int flags)
{
    GRAP_PutImage(rsrc, idx, x, y, flags);
}

// 4e: copy "1-bit" image into page
void DRV_4e(byte* img, int idx, int x, int y)
{
#if 1
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

    //printf(" - offset: 0x%x, w: %d, h: %d, dataLen: %d\n", imageOffset, width, height, dataLen);

#if defined(TARGET_WINDOWS)
    GRAP_WIN_PutBitImage(imageData, x, y, width, height);
#endif
#endif
}

#if defined(TARGET_WINDOWS)
extern byte* g_tileset_mem;
#endif

// 51: put tile
void DRV_51_put_tile(byte al, byte ah, int bx, int cx, int dx, int si, int di)
{
#if defined(TARGET_WINDOWS)
    int x = al;
    int y = ah;
    int tile = bx;

    GRAP_WIN_Temp_PutTile(x, y, tile, &g_tileset_mem[128 * tile]);
#endif
}

// 5a: free tileset
//void DRV_5a() {}

// 5d: print char
void DRV_5d(byte* es, int di, byte dl, byte dh, byte al, byte bl)
{
    // es = ptr_base
    // di = offset
    // dl = [text_fg_color]
    // dh = [text_bg_color]
    // al = [x]
    // bl = [y]

    extern void GRAP_WIN_PrintChar(byte* ptr, int offset, byte fgColor, byte bgColor, int penX, int penY);
    GRAP_WIN_PrintChar(es, di, dl, dh, al, bl);
}

// 60: ?
void DRV_60(int ax, byte bl, int cx, int dx, int si, int di, int carry)
{
    printf("DRV_60(%d,%d,%d,%d,%d,%d,%d)\n", ax, bl, cx, dx, si, di, carry);
}

// 63: put image (forced hflip)
void DRV_63(void* rsrc, int idx, int x, int y, int flags)
{
    GRAP_PutImage(rsrc, idx, x, y, flags | 2);
}

// 66: put image gradually (cf==0: "ultima", cf==1: tile)
void DRV_66(int ax, int bx, int cx, int dx, int si, int di, int cf)
{
    printf("DRV_66(%d,%d,%d,%d,%d,%d,%d)\n", ax, bx, cx, dx, si, di, cf);

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
        DRV_51_put_tile(ax, bx, si, 0, 0, 0, 0);

        return;
    }

    // ax: x1
    // bx: y1
    // cx: x2
    // dx: y2
    GRAP_WIN_TransferPage_Reveal(1, 0, ax, bx, cx, dx, ax, bx);
}

int DRV_0000_12ba = 0; // t1k offset

// 69: show or animate "wd"
void DRV_69(byte* ax, int carry)
{
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
        GRAP_WIN_TransferPage(1, 0, x1, y1, x2, y2, dstX, dstY);

        DRV_0000_12ba = (DRV_0000_12ba + 1) & 3;
    }
    else
    {
        // show wd using "WD.BIT"
        // TODO: implement
        printf("DRV_69(%d)\n", carry);
    }
}

// 6c: ax: ?, bl: hour, bh: minute
void DRV_6c(int ax, byte bl, byte bh)
{
    printf("DRV_6c(%d,%d,%d)\n", ax, bl, bh);
}

// 6f: ?
extern int DRV_6f(int ax)
{
    printf("DRV_6f(%d)\n", ax);
    //return DAT_0000_0e60;
    return 0; // DUMMY
}
