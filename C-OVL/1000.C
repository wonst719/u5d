#include "COMMON.H"

#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>

u16  FUN_1000_1b38_keystroke_cursor(void)
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
