#include "COMMON.H"

#include "GRAP.H"
#include "GRAP_OPS.H"

static GraphicsDriverOps* g_ops;

void GRAP_InitializeVideoDriver(void)
{
#if defined(TARGET_WINDOWS)
    extern GraphicsDriverOps* GRAP_WIN_GetOps(void);
    g_ops = GRAP_WIN_GetOps();
#elif defined(TARGET_DOS32)
    extern GraphicsDriverOps* GRAP_VGA_GetOps(void);
    g_ops = GRAP_VGA_GetOps();
#endif

    if (!g_ops)
        return;

    g_ops->InitializeVideoDriver();
}

void GRAP_CleanupVideoDriver(void)
{
    if (!g_ops)
        return;

    g_ops->CleanupVideoDriver();
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

void GRAP_Temp_PutTile(int x1, int y1, uint tileIdx, byte* tile)
{
    if (!g_ops)
        return;

    g_ops->Temp_PutTile(x1, y1, tileIdx, tile);
}

void GRAP_PutBitmap(byte* buf, int x, int y, int w, int h)
{
    if (!g_ops)
        return;

    g_ops->PutBitmap(buf, x, y, w, h);
}

void GRAP_PutBitmap_Flip(byte* buf, int x, int y, int w, int h, int flags)
{
    if (!g_ops)
        return;

    g_ops->PutBitmap_Flip(buf, x, y, w, h, flags);
}

void GRAP_PutBitImage(byte* buf, int x, int y, int w, int h)
{
    if (!g_ops)
        return;

    g_ops->PutBitImage(buf, x, y, w, h);
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
