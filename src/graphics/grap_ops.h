#ifndef _GRAPHICS_GRAP_OPS_H
#define _GRAPHICS_GRAP_OPS_H

#include "image.h"

typedef struct GraphicsDriverOps
{
    void (*Initialize)(void);
    void (*Cleanup)(void);
    void (*Present)(void);
    void (*SetPenColor)(byte color);
    void (*SetPage)(int page);
    void (*PrintChar)(byte* ptr, int offset, byte fgColor, byte bgColor, int penX, int penY);
    void (*ScrollWindow)(int left, int top, int right, int bottom, int amount);
    void (*Line)(int x1, int y1, int x2, int y2);
    void (*Pset)(int x, int y);
    void (*FillWindow)(int x1, int y1, int x2, int y2, int xorMode);
    void (*LoadTileset)(byte* tileset);
    void (*UnloadTileset)(void);
    void (*AnimateTileset)(void);
    void (*UpdateTimeTileset)(int mode, byte hour, byte minute);
    void (*ShowNextWDFrame)(void);
    void (*AnimateWD)(BitImageView* mask);
    void (*PutAnimatedMoongateTile)(int tileX, int tileY, int visibleRows, byte floorType, int xOffset, int yOffset);
    void (*PutTileRevealStep)(int tileX, int tileY, int tileIdx, int progress, int xOffset, int yOffset);
    void (*PutTile)(int tileX, int tileY, int tileIdx, int xOffset, int yOffset);
    void (*PutImage)(ImageView* view, int x, int y, int flags);
    void (*PutBitImage)(BitImageView* view, int x, int y);
    void (*TransferPage)(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);
    void (*TransferPage_Reveal)(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);
} GraphicsDriverOps;

#endif
