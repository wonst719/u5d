#ifndef _GRAP_DRV_H
#define _GRAP_DRV_H

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
extern void DRV_3f(int ax, int bx, int cx, int dx);

// 0x51: draw tile
extern void DRV_51(byte al, byte ah, int bx, int cx, int dx, int si, int di);

#endif
