#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <string.h>
#include <memory.h>

void F_COMSUBS_0094(int param_1)
{
    if ((D_ba14[param_1]._2 & 0x80) == 0)
    {
        FUN_1000_1850_print_string(D_1856[D_ba14[param_1]._3]);
    }
    else
    {
        FUN_1000_1850_print_string(D_55a8_party[D_ba14[param_1]._3]._0);
    }
}

int F_COMSUBS_00f4(int a) { printf("F_COMSUBS_00f4(%d)\n", a); }

void F_COMSUBS_0312(int a, int b) { printf("F_COMSUBS_0312(%d,%d)\n", a, b); }

int F_COMSUBS_048a(int a, int b, int c, int d) { printf("F_COMSUBS_048a(%d,%d,%d,%d)\n", a, b, c, d); }

int F_COMSUBS_04d4(int a, int b) { printf("F_COMSUBS_04d4(%d,%d)\n", a, b); }

void F_COMSUBS_07d4(int a, int b) { printf("F_COMSUBS_07d4(%d,%d)\n", a, b); }

int F_COMSUBS_0822(int a, int b, int c, int d, int e) { printf("F_COMSUBS_0822(%d,%d,%d,%d,%d)\n", a, b, c, d, e); }

int F_COMSUBS_09fc(int a) { printf("F_COMSUBS_09fc(%d)\n", a); }

void F_COMSUBS_0bf8(int a, int b, int c) { printf("F_COMSUBS_0bf8(%d,%d,%d)\n", a, b, c); }

void F_COMSUBS_0d96(int a, int b) { printf("F_COMSUBS_0d96(%d,%d)\n", a, b); } // attack

int F_COMSUBS_12de(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    printf("F_COMSUBS_12de(%d,%d,%d,%d,%d)\n", param_1, param_2, param_3, param_4, param_5);
}
