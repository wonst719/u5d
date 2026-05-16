#ifndef _ULTIMA_7000_H
#define _ULTIMA_7000_H

// Game cont.

void ULTIMA_70a6(void);

// Grap cont.

void ULTIMA_71aa(void);
void ULTIMA_71ca_DRV_27_ScrollTextWindow1(int param_1, int param_2, int param_3, int param_4, int param_5);
void ULTIMA_7200_DRV_27_ScrollTextWindow2(int param_1, int param_2, int param_3, int param_4, int param_5);

// File

int ULTIMA_7234_ReadFile(char* fileName, void* addr, u16 size, u16 offset);
int ULTIMA_7296_WriteFile(char* fileName, void* addr, u16 size);

#endif
