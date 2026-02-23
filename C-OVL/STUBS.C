#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>

void SWAP(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int F_CAST_0dba_cast_spell_cmd(void) { puts("F_CAST_0dba_cast_spell_cmd"); }

void F_CAST_1792_use_cmd(void) { puts("F_CAST_1792_use_cmd"); }

void F_ENDGAME_0648_endgame_main(void) { puts("F_ENDGAME_0648_endgame_main"); }

void F_SHOPPES_04a2(int param_1) { printf("F_SHOPPES_04a2(%d)\n", param_1); }
void F_SHOPPES_075e(int param_1) { printf("F_SHOPPES_075e(%d)\n", param_1); }
void F_SHOPPES_07be(int param_1) { printf("F_SHOPPES_07be(%d)\n", param_1); }
void F_SHOPPES_12b2(int param_1) { printf("F_SHOPPES_12b2(%d)\n", param_1); }
void F_SHOPPES_14f8(int param_1) { printf("F_SHOPPES_14f8(%d)\n", param_1); }
void F_SHOPPES2_066c(int param_1) { printf("F_SHOPPES2_066c(%d)\n", param_1); }
void F_SHOPPES2_0abc(int param_1) { printf("F_SHOPPES2_0abc(%d)\n", param_1); }
void F_SHOPPES3_08b4(int param_1) { printf("F_SHOPPES3_08b4(%d)\n", param_1); }

void F_FONT_0b0a(void) { puts("F_FONT_0b0a"); }
void F_FONT_04a4(void) { puts("F_FONT_04a4"); }
