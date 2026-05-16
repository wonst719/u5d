#ifndef _ULTIMA_4000_H
#define _ULTIMA_4000_H

void ULTIMA_400c();
int ULTIMA_4080(int a);

// Audio cont.

void ULTIMA_4102_AudioPlayAmbientSfx(void);
void ULTIMA_433e_AudioWalkStep(void);
void ULTIMA_4368_AudioSomething(void);
void ULTIMA_43ae_AudioSweepTone(int a, int b, int c, int d);

// Game cont.

byte* ULTIMA_4402_GetTileAddr(int x, int y);
void ULTIMA_4552_AnimateActors(void);
void ULTIMA_475a(void);
int ULTIMA_47f4(int param_1);
int ULTIMA_48a8(void);
int ULTIMA_4988(void);
void ULTIMA_4a84(void);
void ULTIMA_4be8(void);

void ULTIMA_4c2a(void);
void ULTIMA_4cce(void);
int ULTIMA_4d76(byte* a, int b);
void ULTIMA_4daa(void);
void ULTIMA_4dea(int a);
void ULTIMA_4e20(void);
void ULTIMA_4e50(char* a);
void ULTIMA_4efc(void);

void ULTIMA_4f3c(void);
void ULTIMA_4f7c(int a);

#endif
