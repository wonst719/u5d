#include "common/common.h"

#include "grap.h"
#include "grap_ops.h"

static GraphicsDriverOps* g_ops;

void GRAP_Initialize(void)
{
#if defined(TARGET_WINDOWS)
    extern GraphicsDriverOps* GRAP_SDL_GetOps(void);
    g_ops = GRAP_SDL_GetOps();
#elif defined(TARGET_DOS32)
    extern GraphicsDriverOps* GRAP_VGA_GetOps(void);
    g_ops = GRAP_VGA_GetOps();
#endif

    if (!g_ops)
        return;

    g_ops->Initialize();
}

void GRAP_Cleanup(void)
{
    if (!g_ops)
        return;

    g_ops->Cleanup();
}

void GRAP_Present(void)
{
    if (!g_ops)
        return;

    g_ops->Present();
}

void GRAP_SetPenColor(byte color)
{
    if (!g_ops)
        return;

    g_ops->SetPenColor(color);
}

void GRAP_SetPage(int page)
{
    if (!g_ops)
        return;

    g_ops->SetPage(page);
}

void GRAP_PrintChar(byte* ptr, int offset, byte fgColor, byte bgColor, int penX, int penY)
{
    if (!g_ops)
        return;

    g_ops->PrintChar(ptr, offset, fgColor, bgColor, penX, penY);
}

void GRAP_ScrollWindow(int ax, int bx, int cx, int dx, int si)
{
    if (!g_ops)
        return;

    g_ops->ScrollWindow(ax, bx, cx, dx, si);
}

void GRAP_Line(int x1, int y1, int x2, int y2)
{
    if (!g_ops)
        return;

    g_ops->Line(x1, y1, x2, y2);
}

void GRAP_Pset(int x, int y)
{
    if (!g_ops)
        return;

    g_ops->Pset(x, y);
}

void GRAP_FillWindow(int x1, int y1, int x2, int y2, int xorMode)
{
    if (!g_ops)
        return;

    g_ops->FillWindow(x1, y1, x2, y2, xorMode);
}

void GRAP_LoadTileset(byte* charset)
{
    if (!g_ops)
        return;

    g_ops->LoadTileset(charset);
}

void GRAP_UnloadTileset(void)
{
    if (!g_ops)
        return;

    g_ops->UnloadTileset();
}

void GRAP_AnimateTileset(void)
{
    if (!g_ops)
        return;

    g_ops->AnimateTileset();
}

void GRAP_PutTile(int x1, int y1, int tileIdx)
{
    if (!g_ops)
        return;

    g_ops->PutTile(x1, y1, tileIdx);
}

void GRAP_PutImage(ImageView* view, int x, int y, int flags)
{
    if (!g_ops)
        return;

    g_ops->PutImage(view, x, y, flags);
}

void GRAP_PutBitImage(BitImageView* view, int x, int y)
{
    if (!g_ops)
        return;

    g_ops->PutBitImage(view, x, y);
}

void GRAP_TransferPage(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY)
{
    if (!g_ops)
        return;

    g_ops->TransferPage(srcPage, dstPage, x1, y1, x2, y2, dstX, dstY);
}

void GRAP_TransferPage_Reveal(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY)
{
    if (!g_ops)
        return;

    g_ops->TransferPage_Reveal(srcPage, dstPage, x1, y1, x2, y2, dstX, dstY);
}
