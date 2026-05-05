#ifndef _GRAPHICS_GRAP_H
#define _GRAPHICS_GRAP_H

#include "common/common.h"

extern void GRAP_InitializeVideoDriver(void);
extern void GRAP_SetPenColor(byte color);
extern void GRAP_SetPage(int page);
extern void GRAP_PrintChar(byte* ptr, int offset, byte fgColor, byte bgColor, int penX, int penY);
extern void GRAP_ScrollWindow(int ax, int bx, int cx, int dx, int si);
extern void GRAP_Line(int x1, int y1, int x2, int y2);
extern void GRAP_Pset(int x, int y);
extern void GRAP_FillWindow(int x1, int y1, int x2, int y2, int xorMode);
extern void GRAP_Temp_PutTile(int x1, int y1, uint tileIdx, byte* tile);
extern void GRAP_PutBitmap(byte* buf, int x, int y, int w, int h);
extern void GRAP_PutBitmap_Flip(byte* buf, int x, int y, int w, int h, int flags);
extern void GRAP_PutBitImage(byte* buf, int x, int y, int w, int h);
extern void GRAP_TransferPage(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);
extern void GRAP_TransferPage_Reveal(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);

#endif
