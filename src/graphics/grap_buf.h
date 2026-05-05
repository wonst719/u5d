#ifndef _GRAPHICS_GRAP_BUF_H
#define _GRAPHICS_GRAP_BUF_H

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

extern void GRAP_BUF_InitializeDriver(pfGrapPresent* pfPresent);
extern void GRAP_BUF_CleanupDriver(void);

extern void GRAP_BUF_SetPenColor(byte color);
extern void GRAP_BUF_SetPage(int page);
extern void GRAP_BUF_PrintChar(byte* ptr, int offset, byte fgColor, byte bgColor, int penX, int penY);
extern void GRAP_BUF_ScrollWindow(int ax, int bx, int cx, int dx, int si);
extern void GRAP_BUF_Line(int x1, int y1, int x2, int y2);
extern void GRAP_BUF_Pset(int x, int y);
extern void GRAP_BUF_FillWindow(int x1, int y1, int x2, int y2, int xorMode);
extern void GRAP_BUF_Temp_PutTile(int x1, int y1, uint tileIdx, byte* tile);
extern void GRAP_BUF_PutBitmap(byte* buf, int x, int y, int w, int h);
extern void GRAP_BUF_PutBitmap_Flip(byte* buf, int x, int y, int w, int h, int flags);
extern void GRAP_BUF_PutBitImage(byte* buf, int x, int y, int w, int h);
extern void GRAP_BUF_TransferPage(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);
extern void GRAP_BUF_TransferPage_Reveal(int srcPage, int dstPage, int x1, int y1, int x2, int y2, int dstX, int dstY);

#endif
