#ifndef _GRAPHICS_GRAP_OPS_H
#define _GRAPHICS_GRAP_OPS_H

typedef struct GraphicsDriverOps
{
    void (*Initialize)(void);
    void (*Cleanup)(void);
    void (*Present)(void);
    void (*SetPenColor)(byte color);
    void (*SetPage)(int page);
    void (*PrintChar)(byte* ptr, int offset, byte fgColor, byte bgColor, int penX, int penY);
    void (*ScrollWindow)(int ax, int bx, int cx, int dx, int si);
    void (*Line)(int x1, int y1, int x2, int y2);
    void (*Pset)(int x, int y);
    void (*FillWindow)(int x1, int y1, int x2, int y2, int xorMode);
    void (*LoadTileset)(byte* tileset);
    void (*UnloadTileset)(void);
    void (*AnimateTileset)(void);
    void (*PutTile)(int x1, int y1, int tileIdx);
    void (*PutBitmap)(byte* buf, int x, int y, int w, int h);
    void (*PutBitmap_Flip)(byte* buf, int x, int y, int w, int h, int flags);
    void (*PutBitImage)(byte* buf, int x, int y, int w, int h);
    void (*TransferPage)(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);
    void (*TransferPage_Reveal)(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);
} GraphicsDriverOps;

#endif
