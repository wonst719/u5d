#ifndef _FUNCS_H
#define _FUNCS_H

#include "structs.h"

extern void SWAP(int* a, int* b);

// 0000
extern void ULTIMA_0878_RestoreVideoMode(void);
extern void ULTIMA_0892_InitializeVideoDriver(int a);
extern int  ULTIMA_08e6_ClipRectCoord(int* x1, int* y1, int* x2, int* y2);
extern void ULTIMA_0a70_GRAP_2d_SetPenColor(int a);
extern void ULTIMA_0aa6_GRAP_3f_FillRect(int x1, int y1, int x2, int y2);
extern void ULTIMA_0ace_GRAP_18_TransferArea(int a, int b, int c, int d, int e, int f);
extern void ULTIMA_0b10_GRAP_Line(int x1, int y1, int x2, int y2);
extern void ULTIMA_0b2d_GRAP_Line(int ax, int bx, int cx, int dx, byte carry);
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
extern int  ULTIMA_0d72_AnimateOriginLogo(byte* a);
extern void ULTIMA_0de0_DetectVideo(void);
extern int  ULTIMA_0e94_LoadVideoDriver(void);
extern int  ULTIMA_0f2a_GRAP_06_AllocPageBuffer(void);
extern void ULTIMA_0f46_GRAP_66_Reveal(int x1, int y1, int x2, int y2);
extern void ULTIMA_0f6e_GRAP_1b_TransferFullscreen(int from, int to);
extern void ULTIMA_0f90_GRAP_Pen(int a, int b);

extern byte* ULTIMA_0fae_LoadResourceFile(char* file_name);

extern void ULTIMA_0fdc_FreeBitImage(void* ptr);
extern int  ULTIMA_0ff4_LoadTileset(char* a);

// 1000
extern void ULTIMA_102e_UnloadTileset(void);
extern void ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(byte* a, int b, int c, int d);
extern int ULTIMA_1068(int a, int b, int c);
extern void ULTIMA_10e0_GRAP_51_PutTile(uint a, int b, int c);
extern void ULTIMA_1112_GRAP_60(int a, int b, int c);
extern int ULTIMA_1140_GRAP_6f(void);
extern void ULTIMA_1158_InitTimer(void);
extern int ULTIMA_1588_is_filename_in_table(char* fileName);
extern int ULTIMA_1674_TestOpenFile(char* file_name);
extern int ULTIMA_16a6_GetDefaultDrive(void);
extern void ULTIMA_16ba_PrintChar(uint a);
extern void ULTIMA_1850_PrintString(char *a);
extern void ULTIMA_1a3e_PrintNumber(int a, int b, int c);
extern void ULTIMA_1b16_ClearKbdBuffer(void);
extern void ULTIMA_1b24_ClearKbdBufferImpl(void);
extern u16 ULTIMA_1b38_PollKeyWithCursor(void);
extern void ULTIMA_1b94_SelectTextWindow(int a);
extern void ULTIMA_1bf2_SetTextPosition(int a, int b);
extern void ULTIMA_1c22_SetTextWindowSize(int a, int b, int c, int d, int e);
extern void ULTIMA_1c9e_SelectCharset(int a);
extern void ULTIMA_1cca_SetTextForegroundColor(int a);
extern int ULTIMA_1cee_GetCurrentTextY(void);
extern int ULTIMA_1d02_LoadCharset(char* a, int b);
extern int ULTIMA_1d5e_PollKey(void);
extern int ULTIMA_1dda_WaitForKeystroke(int a);
extern void ULTIMA_1e38_IntroGetString(char* param_1, int param_2);
extern int ULTIMA_1eac_SetDefaultDrive(int param_1);
extern int ULTIMA_1f12_GetCurrentTextX(void);
extern void ULTIMA_1f26_SetTextBackgroundColor(int a);
struct TextWindow;
extern void ULTIMA_1f77_ConvertCharCoordToPixel(TextWindow* window, int* pAX, int* pBX, int* pCX, int* pDX);
extern void ULTIMA_1fa0_Backspace(int x);

// 2000
extern u16  ULTIMA_2032_ToUpper(u8 x);
extern uint ULTIMA_2056_GetTime(void);
extern void ULTIMA_207e_srand(uint a);
extern int  ULTIMA_2092_RandomRange(int a, int b);
extern void ULTIMA_20c8_SomeDelay(int param_1, int param_2);
extern void ULTIMA_20fa_WaitTicks(int a);
extern int  ULTIMA_216c_strlen(char* param_1);
extern void ULTIMA_2192_AudioPulse(int param_1, int param_2, int param_3, int param_4, int param_5);
extern void ULTIMA_223c_AudioWhiteNoise(uint rate, uint dur, uint limit);
extern void ULTIMA_22c0_AudioTone(uint freq, uint dur);
extern void ULTIMA_22e2_PcspkOn(uint freq);
extern void ULTIMA_230e_PcspkOff(void);
extern void ULTIMA_251e_SwitchDisks(int a);
extern void ULTIMA_256e_ReadFileFromDisk(char* fileName, void* addr, u16 size, u16 offset);
extern void ULTIMA_25d8_WriteFileToDisk(char* fileName, void* addr, u16 size);

extern int  ULTIMA_266c_GetChar(void);
extern void ULTIMA_2884_UpdateGoldDisplay(void);
extern void ULTIMA_2900_UpdateVitalsDisplay(void);
extern void ULTIMA_2a28(int param_1);
extern void ULTIMA_2a52(int param_1, uint param_2);
extern void ULTIMA_2aa8(void);
extern void ULTIMA_2ae8(void);
extern int  ULTIMA_2c4c(int param_1, int param_2);
extern int  ULTIMA_2d7a(int a);
extern int  ULTIMA_2e8e(void);
extern void ULTIMA_2e96_SetWindDirection(int a);
extern void ULTIMA_2f62_UpdateWindDirectionRandomly(void);
extern void ULTIMA_2fd0(undefined2 param_1);

// 3000
extern void ULTIMA_3072(void);
extern int  ULTIMA_3178_ProcessCommand(int param_1);
extern void ULTIMA_3522(int x, int y);
extern void ULTIMA_3564(int a);
extern int  ULTIMA_35ec_SelectDirection();
extern int  ULTIMA_368e_FindNpcTileAtPos(int x, int y, int z);
extern int  ULTIMA_3702(int param_1, int param_2, int param_3);
extern int ULTIMA_38e4(void);
extern void ULTIMA_39cc_SetTile(int new_tile_id, byte x, byte y);
extern int  ULTIMA_39fc_GetFirstActivePartyMember(void);
extern void ULTIMA_3a74(byte a, byte b, byte c, byte d, byte e, byte f, int g);
extern int  ULTIMA_3aae(int a);
extern int ULTIMA_3abe(void);
extern void ULTIMA_3ae6(int a);
extern void ULTIMA_3b1c_GetString(char* param_1, int param_2);
extern int  ULTIMA_3b9e(int param_1);
extern void ULTIMA_3c9a_HoleUpCmd(void);

extern void ULTIMA_3ef0(byte* param_1, int param_2, int param_3);
extern void ULTIMA_3f14(s16* a, int b, int c);
extern void ULTIMA_3f36(byte* param_1, int param_2);
extern void ULTIMA_3f54(s16* a, int b);
extern bool ULTIMA_3f6e(int param_1, int param_2);
extern void ULTIMA_3fb4(int param_1, int param_2);

// 4000
extern void ULTIMA_400c();
extern int  ULTIMA_4080(int a);
extern void ULTIMA_4102_AudioPlayAmbientSfx(void);
extern void ULTIMA_433e_AudioWalkStep(void);
extern void ULTIMA_4368_AudioSomething(void);
extern void ULTIMA_43ae_AudioSweepTone(int a, int b, int c, int d);
extern byte* ULTIMA_4402_GetTileAddr(int x, int y);
extern void ULTIMA_4552_AnimateActors(void);
extern void ULTIMA_475a(void);
extern int ULTIMA_47f4(int param_1);
extern int ULTIMA_48a8(void);
extern int ULTIMA_4988(void);
extern void ULTIMA_4a84(void);
extern void ULTIMA_4be8(void);

extern void ULTIMA_4c2a(void);
extern void ULTIMA_4cce(void);
extern int  ULTIMA_4d76(byte* a, int b);
extern void ULTIMA_4daa(void);
extern void ULTIMA_4dea(int a);
extern void ULTIMA_4e20(void);
extern void ULTIMA_4e50(char* a);
extern void ULTIMA_4efc(void);

extern void ULTIMA_4f3c(void);
extern void ULTIMA_4f7c(int a);

extern void ULTIMA_5394(void);
extern int ULTIMA_5646(int a);
extern void ULTIMA_56ac_DrawMap(void);
extern void ULTIMA_5910_UpdateFrame(void);

extern void ULTIMA_5d0a(int a, int x, int y, int d);
extern bool ULTIMA_5dfe(byte param_1, int param_2);
extern void ULTIMA_5e4a(void);
extern void ULTIMA_5f86_SpecialMapHandler(int param_1, int param_2, int param_3);

// 6000
extern void ULTIMA_6150_Attack(int a);
extern void ULTIMA_6360_Camping(int param_1, int param_2);
extern void ULTIMA_637e_DrawFrame(void);

extern int  ULTIMA_6506(int a, int b, int c, int d, int e);
extern void ULTIMA_6800(int a);
extern void ULTIMA_6880(int param_1);
extern void ULTIMA_68ae(int a);
extern void ULTIMA_6936(void);
extern int  ULTIMA_6d82(int a, int b);
extern int  ULTIMA_6da8(int a);
extern int  ULTIMA_6e60(int param_1, int param_2);
extern int  ULTIMA_6f1e(byte* param_1, char* param_2);
extern void ULTIMA_6bc2(int param_1, int param_2);
extern void ULTIMA_6f9e(int param_1);
extern void ULTIMA_6fbc(int param_1);
extern void ULTIMA_6fd6_GRAP_AnimateTiles(void);
extern int  ULTIMA_6ff0(register int param_1, register int param_2);

// 7000
extern void ULTIMA_70a6(void);
extern void ULTIMA_71aa(void);
extern void ULTIMA_71ca_DRV_27_ScrollTextWindow1(int param_1, int param_2, int param_3, int param_4, int param_5);
extern void ULTIMA_7200_DRV_27_ScrollTextWindow2(int param_1, int param_2, int param_3, int param_4, int param_5);

int ULTIMA_7234_ReadFile(char* fileName, void* addr, u16 size, u16 offset);
int ULTIMA_7296_WriteFile(char* fileName, void* addr, u16 size);

#endif
