#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

// OK P1
u16 FUN_1000_2032_to_upper(u8 x)
{
    if (x >= 0x61 && 0x7a >= x)
    {
        return x - 0x20;
    }

    return x;
}

FUN_1000_20fa_wait_ticks(int a)
{
    /*puts("FUN_1000_20FA_wait_ticks");*/

#ifdef _WIN32
    void u5_sleep(int ms);
    u5_sleep(a * 55); // 18.2 ticks per second
#endif
}

int FUN_1000_216c_strlen(char* param_1)
{
    int iVar1;

    iVar1 = 0;
    while (*param_1 != '\0') {
        iVar1 = iVar1 + 1;
        param_1 = param_1 + 1;
    }
    return iVar1;
}

// OK P1
u8 FUN_1000_266c_get_ch_impl(void)
{
    int local_4;

    if (D_52c8 == 2)
    {
        D_5891 = 0xff;
    }

    do
    {
        local_4 = FUN_1000_2032_to_upper(FUN_1000_1b38_keystroke_cursor());
        if ((local_4 == 0) && (D_5893_map_id < 0x21 || 0x7f < D_5893_map_id))
        {
            FUN_1000_5910_update_map();
        }
    } while (local_4 == 0);

    if (D_538a != 0)
    {
        // numpad
        switch (local_4)
        {
        case 0x31:
            local_4 = 0xd4;
            break;
        case 0x32:
            local_4 = 4;
            break;
        case 0x33:
            local_4 = 0xd6;
            break;
        case 0x34:
            local_4 = 1;
            break;
        case 0x36:
            local_4 = 2;
            break;
        case 0x37:
            local_4 = 0xd3;
            break;
        case 0x38:
            local_4 = 3;
            break;
        case 0x39:
            local_4 = 0xd5;
        }
    }
    else
    {
        if (local_4 < 5)
            local_4 += 0xfa;
    }

    return local_4;
}

void FUN_1000_2726(int a) {}

// OK P1 (completed)
void FUN_1000_2884_update_gold(void)
{
    undefined2 local_2;

    local_2 = D_5386_currentCharset;
    FUN_1000_1b94_select_charset(1);
    FUN_1000_1bf2_set_text_cursor_position(8, 7);
    if (D_57aa < 1000)
    {
        FUN_1000_16ba_print_char(' ');
    }
    if (D_57aa < 100)
    {
        FUN_1000_16ba_print_char(' ');
    }
    if (D_57aa < 10)
    {
        FUN_1000_16ba_print_char(' ');
    }
    FUN_1000_1850_print_string(" G:");
    FUN_1000_1a3e_print_number(D_57aa, 1, ' ');
    while (0xf > FUN_1000_1f12_get_current_text_column())
    {
        FUN_1000_16ba_print_char(' ');
    }

    FUN_1000_1b94_select_charset(local_2);
}

// OK P1
void FUN_1000_2900_update_vitals(void)
{
    int local_2;

    FUN_1000_1b94_select_charset(1);

    local_2 = 0;
    do
    {
        FUN_1000_2726(local_2);
        local_2++;
    } while (local_2 < 6);

    FUN_1000_1bf2_set_text_cursor_position(0, 7);

    // food
    FUN_1000_1850_print_string("F:");
    FUN_1000_1a3e_print_number(D_57a8, 1, ' ');

    while (FUN_1000_1f12_get_current_text_column() < 8)
    {
        FUN_1000_16ba_print_char(' ');
    }

    if ((D_5893_map_id < 0x80) && ((D_587c & 0xf8) == 0x20))
    {
        // ship
        FUN_1000_1850_print_string("Ship:");
        FUN_1000_1a3e_print_number(D_5c5a[0]._5, 1, ' ');
        if (D_5c5a[0]._5 < 10)
        {
            FUN_1000_16ba_print_char(' ');
        }
    }
    else
    {
        FUN_1000_2884_update_gold();
    }

    FUN_1000_1850_print_string("\n   ");

    if ((D_587d < 10) && (D_587e < 10))
    {
        FUN_1000_16ba_print_char(' ');
    }

    // date (m/d/y)
    FUN_1000_1a3e_print_number(D_587d, 1, ' ');
    FUN_1000_16ba_print_char(' ');
    FUN_1000_1a3e_print_number(D_587e, 1, ' ');
    FUN_1000_16ba_print_char(' ');
    FUN_1000_1a3e_print_number(D_5874, 3, ' ');

    while (FUN_1000_1f12_get_current_text_column() < 0xf)
    {
        FUN_1000_16ba_print_char(' ');
    }

    FUN_1000_1bf2_set_text_cursor_position(6, 6);

    // icon?
    if (D_587a != 0)
    {
        FUN_1000_4c2a();
        FUN_1000_16ba_print_char(D_587a);
        FUN_1000_4cce();
    }
    else
    {
        FUN_1000_4f3c();
    }

    FUN_1000_1b94_select_charset(2);
}
