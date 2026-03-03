#ifndef _GRAP_DRV_H
#define _GRAP_DRV_H

// 0x00: get screen height

// 0x03: initialize video

// 0x06: alloc data buffer

// 0x0c: free data buffer

// 0x0f: ?
extern void DRV_0f(int ax);

// 0x18: text data transfer
extern void DRV_18(int ax, int bx, int cx, int dx, int si, int di, int carry);

// 0x1b: image data transfer
extern void DRV_1b(int ax, int bx);

// 0x27: scroll text window
extern void DRV_27(int ax, int bx, int cx, int dx, int si);

// 0x2d: set pen color
extern void DRV_2d(byte al);

// 0x30: pset
extern void DRV_30(int ax, int bx);

// 0x33: line
extern void DRV_33(int ax, int bx, int cx, int dx);

// 0x39: hline
extern void DRV_39(int ax, int bx, int cx);

// 0x3c: vline
extern void DRV_3c(int ax, int bx, int dx);

// 0x3f: fill rectangle
extern void DRV_3f(int ax, int bx, int cx, int dx, int carry);

// 0x48: load tileset

// TODO: params
// 0x4b: put image
extern void DRV_4b(byte* imageData, int x, int y, int width, int height);

// 0x4e: copy image into page
// ax, bx, si, di
extern void DRV_4e(byte* img, int idx, int x, int y);

// 0x51: draw tile
extern void DRV_51(byte al, byte ah, int bx, int cx, int dx, int si, int di);

// 0x5a: free tileset

// 0x60
void DRV_60(int ax, byte bl, int cx, int dx, int si, int di, int carry);

// 0x69
extern void DRV_69(int carry);

// 0x6c: some text. ax: ?, bl: hour, bh: minute
extern void DRV_6c(int ax, byte bl, byte bh);

// 0x6f: ?
extern int DRV_6f(int ax);

#endif
