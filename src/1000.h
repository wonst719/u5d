#ifndef _ULTIMA_1000_H
#define _ULTIMA_1000_H

// Grap cont.

extern void ULTIMA_102e_UnloadTileset(void);
extern void ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(byte* a, int b, int c, int d);
extern int ULTIMA_1068(int a, int b, int c);
extern void ULTIMA_10e0_GRAP_51_PutTile(uint a, int b, int c);
extern void ULTIMA_1112_GRAP_60(int a, int b, int c);
extern int ULTIMA_1140_GRAP_6f(void);

// Timer

extern void ULTIMA_1158_InitTimer(void);

// File

extern int ULTIMA_1674_TestOpenFile(char* file_name);
extern int ULTIMA_16a6_GetDefaultDrive(void);

// Text

extern void ULTIMA_16ba_PrintChar(uint a);
extern void ULTIMA_1850_PrintString(char* a);
extern void ULTIMA_1a3e_PrintNumber(int a, int b, int c);

// Keyboard

extern void ULTIMA_1b16_ClearKbdBuffer(void);
extern u16 ULTIMA_1b38_PollKeyWithCursor(void);

// Text cont.

extern void ULTIMA_1b94_SelectTextWindow(int a);
extern void ULTIMA_1bf2_SetTextPosition(int a, int b);
extern void ULTIMA_1c22_SetTextWindowSize(int a, int b, int c, int d, int e);
extern void ULTIMA_1c9e_SelectCharset(int a);
extern void ULTIMA_1cca_SetTextForegroundColor(int a);
extern int ULTIMA_1cee_GetCurrentTextY(void);
extern int ULTIMA_1d02_LoadCharset(char* a, int b);

// Keyboard cont.

extern int ULTIMA_1d5e_PollKey(void);
extern int ULTIMA_1dda_WaitForKeystroke(int a);

// Input

extern void ULTIMA_1e38_IntroGetString(char* param_1, int param_2);

// File cont.

extern int ULTIMA_1eac_SetDefaultDrive(int param_1);

// Text

extern int ULTIMA_1f12_GetCurrentTextX(void);
extern void ULTIMA_1f26_SetTextBackgroundColor(int a);

// Input cont.

extern void ULTIMA_1fa0_Backspace(int x);

#endif
