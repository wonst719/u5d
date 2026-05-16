#ifndef _ULTIMA_0000_H
#define _ULTIMA_0000_H

// Grap

extern void ULTIMA_0878_RestoreVideoMode(void);
extern void ULTIMA_0892_InitializeVideoDriver(int a);
extern int ULTIMA_08e6_ClipRectCoord(int* x1, int* y1, int* x2, int* y2);
extern void ULTIMA_0a70_GRAP_2d_SetPenColor(int a);
extern void ULTIMA_0aa6_GRAP_3f_FillRect(int x1, int y1, int x2, int y2);
extern void ULTIMA_0ace_GRAP_18_TransferArea(int a, int b, int c, int d, int e, int f);
extern void ULTIMA_0b10_GRAP_Line(int x1, int y1, int x2, int y2);
extern void ULTIMA_0b86_GRAP_XorFillRect(int x1, int y1, int x2, int y2);
extern void* ULTIMA_0bae_LoadImageFile(char* file_name);
extern void ULTIMA_0be4_FreeImage(void* ptr);
extern void ULTIMA_0bfc_GRAP_63(byte* param_1, int param_2, int param_3, int param_4, int param_5);
extern void ULTIMA_0c22_GRAP_0f_SelectPage(int a);
extern void ULTIMA_0c3c(int a, int b, int c, int d);
extern void ULTIMA_0c64_GRAP_30_Pset(int param_1, int param_2);
extern void ULTIMA_0c9c_GRAP_39_HorizLine(int x1, int y, int x2);
extern void ULTIMA_0cf2_GRAP_3c_VertLine(int a, int b, int c);
extern void ULTIMA_0d4c_GRAP_4b_PutImage(void* a, int b, int c, int d, int e);
extern int ULTIMA_0d72_AnimateOriginLogo(byte* a);
extern void ULTIMA_0de0_DetectVideo(void);
extern int ULTIMA_0e94_LoadVideoDriver(void);
extern int ULTIMA_0f2a_GRAP_06_AllocPageBuffer(void);
extern void ULTIMA_0f46_GRAP_66_Reveal(int x1, int y1, int x2, int y2);
extern void ULTIMA_0f6e_GRAP_1b_TransferFullscreen(int from, int to);
extern void ULTIMA_0f90_GRAP_Pen(int a, int b);

extern byte* ULTIMA_0fae_LoadResourceFile(char* file_name);

extern void ULTIMA_0fdc_FreeBitImage(void* ptr);
extern int ULTIMA_0ff4_LoadTileset(char* a);

#endif
