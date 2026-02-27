#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <string.h>
#include <memory.h>

int F_CAST2_00de(void) { puts("F_CAST2_00de"); }

// resurrect
void F_CAST2_05e0(int a, int b)
{
    printf("F_CAST2_05e0(%d,%d)\n", a, b);

    // STUB
    D_55a8_party[a]._b = 'G';
    D_55a8_party[a]._10 = 1;
}

void F_CAST2_08ea(int a) { printf("F_CAST2_08ea(%d)\n", a); }

F_CAST2_0e76() { puts("F_CAST2_0e76"); }

void F_CAST2_10fe_save_game(void) { puts("F_CAST2_10fe_save_game"); }
