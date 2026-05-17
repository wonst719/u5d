#ifndef _ULTIMA_2000_H
#define _ULTIMA_2000_H

// Utils

extern u16 ULTIMA_2032_ToUpper(u8 x);
extern uint ULTIMA_2056_GetTime(void);
extern void ULTIMA_207e_srand(uint a);
extern int ULTIMA_2092_RandomRange(int a, int b);
extern void ULTIMA_20c8_SomeDelay(int param_1, int param_2);
extern void ULTIMA_20fa_WaitTicks(int a);
extern int ULTIMA_216c_strlen(char* param_1);

// Audio

extern void ULTIMA_2192_AudioPulse(int param_1, int param_2, int param_3, int param_4, int param_5);
extern void ULTIMA_223c_AudioWhiteNoise(uint rate, uint dur, uint limit);
extern void ULTIMA_22c0_AudioTone(uint freq, uint dur);
extern void ULTIMA_22e2_PcspkOn(uint freq);
extern void ULTIMA_230e_PcspkOff(void);

// File cont.

extern void FAR ULTIMA_2320_NoDiskSwapMessage(void);
extern void FAR ULTIMA_2322_DiskSwapMessage(void);

extern void ULTIMA_251e_SwitchDisks(int a);
extern void ULTIMA_256e_ReadFileFromDisk(char* fileName, void* addr, u16 size, u16 offset);
extern void ULTIMA_25d8_WriteFileToDisk(char* fileName, void* addr, u16 size);

// Input cont.

extern int ULTIMA_266c_GetChar(void);

// Game display

extern void ULTIMA_2884_UpdateGoldDisplay(void);
extern void ULTIMA_2900_UpdateVitalsDisplay(void);
extern void ULTIMA_2a28(int param_1);
extern void ULTIMA_2a52(int param_1, uint param_2);
extern void ULTIMA_2aa8(void);
extern void ULTIMA_2ae8(void);
extern int ULTIMA_2c4c(int param_1, int param_2);
extern int ULTIMA_2d7a(int a);
extern int ULTIMA_2e8e(void);
extern void ULTIMA_2e96_SetWindDirection(int a);
extern void ULTIMA_2f62_UpdateWindDirectionRandomly(void);
extern void ULTIMA_2fd0(int param_1);

#endif
