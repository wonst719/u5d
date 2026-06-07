#include "common/common.h"
#include "vars.h"

#if !defined(TARGET_DOS16)
#include "graphics/grap.h"
#include "graphics/image.h"
#endif

// 00: get screen height
//int DRV_00(void) { return 200; }

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

#if !defined(TARGET_DOS16)
static void DRV_PutImage(byte* rsrc, int idx, int x, int y, int flags)
{
    // flags & 1: vflip
    // flags & 2: hflip

    ImageView view;

    if (!IMAGE_GetImageView(rsrc, idx, &view))
        return;

    if (view.hasMask)
    {
        debug(" - fmt2 w: %d, h: %d", view.width, view.height);
    }
    else
    {
        debug(" - fmt1 w: %d, h: %d", view.width, view.height);
    }

    GRAP_PutImage(&view, x, y, flags);
}
#endif

// 48: load tileset
void DRV_48_LoadTileset(byte* charset)
{
    GRAP_LoadTileset(charset);
}

// 4b: put image (ax=seg, bx=idx, cx=flags, si=x, di=y)
void DRV_4b(byte* rsrc, int idx, int x, int y, int flags)
{
#if !defined(TARGET_DOS16)
    DRV_PutImage(rsrc, idx, x, y, flags);
#endif
}

// 4e: copy "1-bit" image into page
void DRV_4e(byte* rsrc, int idx, int x, int y)
{
#if !defined(TARGET_DOS16)
    BitImageView view;

    if (!IMAGE_GetBitImageView(rsrc, idx, &view))
        return;

    //debug(" - w: %d, h: %d, dataLen: %d", view.width, view.height, view.stride * view.height);

    GRAP_PutBitImage(&view, x, y);
#endif
}

// 51: put tile
void DRV_51_PutTile(byte al, byte ah, int bx, int cx, int dx, int si, int di)
{
#if !defined(TARGET_DOS16)
    int x = al;
    int y = ah;
    int tile = bx;
    int xOffset = cx;
    int yOffset = dx;

    GRAP_PutTile(x, y, tile, xOffset, yOffset);
#endif
}

// 5a: free tileset
void DRV_5a_FreeTileset(void)
{
#if !defined(TARGET_DOS16)
    GRAP_UnloadTileset();
#endif
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
        // 1567~
        // animate tileset
        // ax: ignored?
#if !defined(TARGET_DOS16)
        GRAP_AnimateTileset();
#endif
    }
    else
    {
        // 196e~
#if !defined(TARGET_DOS16)
        GRAP_PutAnimatedMoongateTile(si, di, ax, bl, cx, dx);
#endif
    }
}

// animate tiles
void DRV_60_CF0(void* ax)
{
#if !defined(TARGET_DOS16)
    // ax: ignored?
    GRAP_AnimateTileset();
#endif
}

// 63: put image (forced hflip)
void DRV_63(byte* rsrc, int idx, int x, int y, int flags)
{
#if !defined(TARGET_DOS16)
    DRV_PutImage(rsrc, idx, x, y, flags | 2);
#endif
}

// 66: reveal image/tile gradually
void DRV_66(int ax, int bx, int cx, int dx, int si, int di, int cf)
{
    //debug("DRV_66(%d,%d,%d,%d,%d,%d,%d)", ax, bx, cx, dx, si, di, cf);

#if !defined(TARGET_DOS16)
    if (cf == 0)
    {
        int x1 = ax;
        int y1 = bx;
        int x2 = cx;
        int y2 = dx;

        GRAP_TransferPage_Reveal(1, 0, x1, y1, x2, y2, x1, y1);
    }
    else
    {
        int tileX = ax;
        int tileY = bx;
        int xOffset = cx;
        int yOffset = dx;
        int tileIdx = si;
        int progress = di;

        GRAP_PutTileRevealStep(tileX, tileY, tileIdx, progress, xOffset, yOffset);
    }
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
// DRV_6c(3,0,0): turn grass color to red?
void DRV_6c(int ax, byte bl, byte bh)
{ debug("DRV_6c(%d,%d,%d)", ax, bl, bh); }

// 6f: ?
int DRV_6f(int ax)
{
    debug("DRV_6f(%d)", ax);
    //return DAT_0000_0e60;
    return 0; // DUMMY
}
