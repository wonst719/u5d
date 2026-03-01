#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <string.h>
#include <memory.h>

void F_CAST2_0000(int a) { printf("F_CAST2_0000(%d)\n", a); }

int F_CAST2_009e(void) { puts("F_CAST2_009e"); }

int F_CAST2_00de(void) { puts("F_CAST2_00de"); }

int F_CAST2_0306(void) { puts("F_CAST2_0306"); }

int F_CAST2_03c2(int a) { printf("F_CAST2_03c2(%d)\n", a); }

void F_CAST2_040a(int a, int b) { printf("F_CAST2_040a(%d,%d)\n", a, b); }

void F_CAST2_046c(void) { puts("F_CAST2_046c"); }

int F_CAST2_04c2(int a) { printf("F_CAST2_04c2(%d)\n", a); }

// STUB
// resurrect
int F_CAST2_05e0(int a, int b)
{
    printf("F_CAST2_05e0(%d,%d)\n", a, b);

    D_55a8_party[a]._b = 'G';
    D_55a8_party[a]._10 = 1;
}

void F_CAST2_06ec(void) { puts("F_CAST2_06ec"); }

int F_CAST2_0768(void) { puts("F_CAST2_0768"); }

int F_CAST2_07bc(int a) { printf("F_CAST2_07bc(%d)\n", a); }

void F_CAST2_08ea(int a) { printf("F_CAST2_08ea(%d)\n", a); }

void F_CAST2_08f8(int a, int b, int c) { printf("F_CAST2_08f8(%d,%d,%d)\n", a, b, c); }

void F_CAST2_0e76(void) { puts("F_CAST2_0e76"); }

void F_CAST2_10fe_save_game(void) { puts("F_CAST2_10fe_save_game"); }
