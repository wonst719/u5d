#ifndef _GRAPHICS_GRAP_H
#define _GRAPHICS_GRAP_H

#include "common/common.h"
#include "image.h"

extern void GRAP_Initialize(void);
extern void GRAP_Cleanup(void);
extern void GRAP_Present(void);
extern void GRAP_SetPenColor(byte color);
extern void GRAP_SetPage(int page);
extern void GRAP_PrintChar(byte* ptr, int offset, byte fgColor, byte bgColor, int penX, int penY);
extern void GRAP_ScrollWindow(int left, int top, int right, int bottom, int amount);
extern void GRAP_Line(int x1, int y1, int x2, int y2);
extern void GRAP_Pset(int x, int y);
extern void GRAP_FillWindow(int x1, int y1, int x2, int y2, int xorMode);
extern void GRAP_LoadTileset(byte* charset);
extern void GRAP_UnloadTileset(void);
extern void GRAP_AnimateTileset(void);
extern void GRAP_PutAnimatedMoongateTile(int tileX, int tileY, int visibleRows, byte floorType, int xAdjust, int yAdjust);
extern void GRAP_PutTile(int tileX, int tileY, int tileIdx, int xAdjust, int yAdjust);
extern void GRAP_PutImage(ImageView* view, int x, int y, int flags);
extern void GRAP_PutBitImage(BitImageView* view, int x, int y);
extern void GRAP_TransferPage(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);
extern void GRAP_TransferPage_Reveal(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);

#endif
