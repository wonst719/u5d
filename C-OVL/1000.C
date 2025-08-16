#include "COMMON.H"

#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>
#include <stdlib.h>

void FUN_1000_10e0(uint tile, int x, int y)
{
    /*printf("FUN_1000_10e0(%d,%d,%d)\n");*/
    // al = x
    // ah = y
    // bx = tile
    // cx = 52bc, dx = 52be, si = 52c0, di = 52c2
    // 0x51
#ifdef _WIN32
    void GRAP_WIN_Temp_PlotTile(int x, int y, int color);
    GRAP_WIN_Temp_PlotTile(x, y, tile % 16);
#endif
}

// OK P1 (NOT MATCHING: optimization)
// print_integer(val, min_len, filler)
void FUN_1000_1a3e_print_number(int param_1, int param_2, int param_3)
{
    int l_2a = 1; // required_length
    int l_2c;     // space
    int l_2e = 0; // is_negative
    int l_30;
    char local_28[40];

    register s16 *si;

    if (param_2 > 39)
    {
        param_2 = 39;
    }

    // 1a5b
    if (param_1 < 0) // is negative?
    {
        l_2e++; // is_negative = true
        param_1 = -param_1;
    }

    // 1a6c
    l_30 = 5;

    si = &D_5402[1];
    do
    {
        // 1a7a
        if (*si <= param_1) // cmp order?
        {
            l_2a++;
        }
        si++;
    } while (si < &D_5402[5]); // 1a7f

    if (l_2e)
    {
        l_2a++;
    }

    // 1a94
    l_2c = param_2 - l_2a;
    if (l_2c <= 0)
    {
        l_2c = 0;
    }
    else
    {
        // 1aa8: NOT MATCHING (loop optimization)
        for (l_30 = 0; l_30 != l_2c; l_30++)
        {
            local_28[l_30] = param_3;
        }
    }

    // 1ac0
    if (l_2e)
    {
        local_28[l_2c++] = '-';
        l_2a--;
    }

    // 1ad3: NOT MATCHING
    do
    {
        l_30 = D_5402[l_2a - 1];
        l_2e = param_1 / l_30;
        local_28[l_2c++] = (char)l_2e + '0';

        param_1 -= l_30 * l_2e;
    } while (--l_2a != 0);

    // 1afb
    local_28[l_2c] = '\0';

    FUN_1000_1850_print_string(local_28);
}

u16 FUN_1000_1b38_keystroke_cursor(void)
{
    int local_2;
    int local_4;

    //puts("FUN_1000_1b38_keystroke_cursor");
    //return u5_getch();

    local_2 = D_538e;
    D_538e = 0;
    FUN_1000_16ba_print_char(D_540c++);
    local_4 = FUN_1000_1d5e_peek_keystroke();
    if (D_5392 <= D_540c) {
        D_540c = 0;
    }
    if (local_4 != 0) {
        FUN_1000_16ba_print_char(0x20);
    }
    else {
        FUN_1000_20fa_wait_ticks(1);
    }
    D_538e = local_2;
    return local_4;
}

u8 FUN_1000_1d5e_peek_keystroke(void)
{
    return u5_peekch();
}
