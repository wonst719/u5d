#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#ifdef _WIN32
extern void GRAP_WIN_ScrollWindow(int ax, int bx, int cx, int dx, int si);
extern void GRAP_WIN_Line(int x1, int y1, int x2, int y2);
extern void GRAP_WIN_FillWindow(int x1, int y1, int x2, int y2);
extern void GRAP_WIN_Temp_PlotTile2(int x1, int y1, uint tileIdx, byte* tile);
#endif

byte g_grapPenColor = 0;

void DRV_27(int ax, int bx, int cx, int dx, int si)
{
#ifdef _WIN32
    GRAP_WIN_ScrollWindow(ax, bx, cx, dx, si);
#endif
}

// set pen color
void DRV_2d(byte al)
{
    g_grapPenColor = al;
}

// pset
void DRV_30(int ax, int bx)
{
}

// line
void DRV_33(int ax, int bx, int cx, int dx)
{
#ifdef _WIN32
    int x1 = ax;
    int y1 = bx;
    int x2 = cx;
    int y2 = dx;
    GRAP_WIN_Line(x1, y1, x2, y2);
#endif
}

// hline
void DRV_39(int ax, int bx, int cx)
{
#ifdef _WIN32
    int x1 = ax;
    int y = bx;
    int x2 = cx;

    GRAP_WIN_Line(x1, y, x2, y);
#endif
}

// vline
void DRV_3c(int ax, int bx, int dx)
{
#ifdef _WIN32
    int x = ax;
    int y1 = bx;
    int y2 = dx;

    GRAP_WIN_Line(x, y1, x, y2);
#endif
}

// fill rectangle
void DRV_3f(int ax, int bx, int cx, int dx)
{
#ifdef _WIN32
    int x1 = ax;
    int y1 = bx;
    int x2 = cx;
    int y2 = dx;
	GRAP_WIN_FillWindow(x1, y1, x2, y2);
#endif
}

#ifdef _WIN32
extern byte* g_tileset_mem;
#endif

void DRV_51(byte al, byte ah, int bx, int cx, int dx, int si, int di)
{
#ifdef _WIN32
    int x = al;
    int y = ah;
    int tile = bx;

    GRAP_WIN_Temp_PlotTile2(x, y, tile, &g_tileset_mem[128 * tile]);
#endif
}
