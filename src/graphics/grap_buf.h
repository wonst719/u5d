#ifndef _GRAPHICS_GRAP_BUF_H
#define _GRAPHICS_GRAP_BUF_H

#include "image.h"

#define hiresWidth 640
#define hiresHeight 400

#define loresWidth 320
#define loresHeight 200

#define hiresPackedStride 80

#define loresToHiresRatio 2

extern u8* g_linearEgaBuffer0;
extern u8* s_linearEgaBuffer1;
extern u8* g_linearOverlayBuffer;

typedef void pfGrapPresent(void);

extern void GRAP_BUF_Initialize(pfGrapPresent* pfPresent);
extern void GRAP_BUF_Cleanup(void);

extern void GRAP_BUF_SetPenColor(byte color);
extern void GRAP_BUF_SetPage(int page);
extern void GRAP_BUF_PrintChar(byte* ptr, int offset, byte fgColor, byte bgColor, int penX, int penY);
extern void GRAP_BUF_ScrollWindow(int left, int top, int right, int bottom, int amount);
extern void GRAP_BUF_Line(int x1, int y1, int x2, int y2);
extern void GRAP_BUF_Pset(int x, int y);
extern void GRAP_BUF_FillWindow(int x1, int y1, int x2, int y2, int xorMode);
extern void GRAP_BUF_LoadTileset(byte* tileset);
extern void GRAP_BUF_UnloadTileset(void);
extern void GRAP_BUF_AnimateTileset(void);
extern void GRAP_BUF_PutAnimatedMoongateTile(int tileX, int tileY, int visibleRows, byte floorType, int xOffset, int yOffset);
extern void GRAP_BUF_PutTile(int tileX, int tileY, int tileIdx, int xOffset, int yOffset);
extern void GRAP_BUF_PutImage(ImageView* view, int x, int y, int flags);
extern void GRAP_BUF_PutBitImage(BitImageView* view, int x, int y);
extern void GRAP_BUF_TransferPage(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);
extern void GRAP_BUF_TransferPage_Reveal(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);

#endif
