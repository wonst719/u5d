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

// STUB
// (asm) some busy-wait delay?
void FUN_1000_20c8_some_delay(int param_1, int param_2)
{
    // FMT: empty
#ifdef _WIN32
    return;
#else
    register uint ax, cx;

    ax = D_5356; // timer calibration
    cx = D_5426[param_1];

    if (cx != 0)
    {
        // shr ax, cl
        ax >>= (byte)cx & 0x1f;
    }

    // 20dc
    D_5424 = param_2;

    do
    {
        // 20e3
        D_5422 = ax;

        do
        {
            // 20e6
        } while (--D_5422 != 0);
    } while (--D_5424 != 0);
#endif
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

// audio: white noise (rate, dur, limit)
void FUN_1000_223c_audio_white_noise(uint rate, uint dur, uint limit)
{
    // Ref: FUN_0002c598
}

void FUN_1000_22c0_pcspk_play_tone(uint freq, uint dur)
{
    if (D_a9ce != 0)
    {
        FUN_1000_22e2_pcspk_start_tone(freq);
    }

    FUN_1000_20c8_some_delay(1, dur);
    FUN_1000_230e_pcspk_off();
}

void FUN_1000_22e2_pcspk_start_tone(uint freq)
{
    if (D_a9ce != 0)
    {
        // start tone
        // NOTE / REF: https://fragglet.github.io/dos-help-files/alang.hlp/x_at_L848b.html
    }
}

void FUN_1000_230e_pcspk_off(void)
{
    // speaker off
    // NOTE / REF: https://fragglet.github.io/dos-help-files/alang.hlp/x_at_L848b.html
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
        local_4 = FUN_1000_2032_to_upper((u8)FUN_1000_1b38_keystroke_cursor());
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

// OK P1
void FUN_1000_2a28(int param_1)
{
    FUN_1000_0a70_set_pen_color(D_13b0_white_color);
    FUN_1000_0b86(0xc0, param_1 * 8 + 8, 0x137, param_1 * 8 + 0xf);
}

// OK P1
void FUN_1000_2a52(int param_1, uint param_2)
{
    FUN_1000_2a28(param_1);
    FUN_1000_223c_audio_white_noise(10, 0x640, 2000);
    FUN_1000_2a28(param_1);

    D_55a8_party[param_1]._10 -= param_2;
    if (D_55a8_party[param_1]._10 <= 0)
    {
        D_55a8_party[param_1]._10 = 0;
        D_55a8_party[param_1]._b = 0x44;
        if (param_1 == D_587b)
        {
            D_587b = 0xff;
        }
    }

    FUN_1000_2900_update_vitals();
}

// OK P1
void FUN_1000_2aa8(void)
{
    int i = 0;
    do
    {
        if ((i < D_585b) && (D_55a8_party[i]._b != 'D'))
        {
            FUN_1000_2a52(i, FUN_1000_2092(1, 8));
        }
        i++;
    } while (i < 6);
}

void FUN_1000_3ef0(byte* param_1, int param_2, int param_3);

// OK P1 (NOT MATCHING: register)
void FUN_1000_2ae8(void)
{
    int local_8;
    int local_6;
    int local_4;

    local_4 = 0;
    local_6 = 0;

    if ((int)D_585b != 0)
    {
        do
        {
            local_8 = D_55a8_party[local_6]._b;
            if ((local_8 == 'D') && (local_6 == D_587b))
            {
                D_587b = 0xff;
            }
            // NOT MATCHING: register (mov ax, si ...)
            if ((local_8 != 'D') && (local_8 != 'S'))
            {
                if (local_8 == 'P')
                {
                    FUN_1000_2a52(local_6, 1);
                }
                local_4++;
            }
            local_6++;
        } while (local_6 < D_585b);
    }
    if (D_587f != D_5880)
    {
        if (D_57a8 == 0)
        {
            FUN_1000_1850_print_string("Starving!\n"/*54c8*/);
            FUN_1000_2aa8();
        }
        else if (((D_587f == '\x06') || (D_587f == '\f')) || (D_587f == '\x12'))
        {
            FUN_1000_3f54(&D_57a8, local_4);
        }
        D_5880 = D_587f;
    }
    FUN_1000_3ef0(&D_588b, 1, 0xff);
    if ((D_588e != '\0') && (D_588e != 0xff))
    {
        D_588e--;
        if (D_588e == '\0')
        {
            D_587a = 0;
            FUN_1000_2900_update_vitals();
        }
    }
    FUN_1000_400c();
}

// OK P1
bool FUN_1000_2bd4(byte param_1, int param_2)
{
    bool local_4;

    if ((D_54d4[param_2 >> 3] & (0x80 >> (param_2 & 7))) != 0)
        local_4 = 0;
    else
        local_4 = 1;

    if ((((param_1 & 0xfe) != 0x1c) && ((param_1 & 0xf0) != 0x40)) && (((byte)param_2 & 0xfc) == 0x90))
    {
        local_4 = 0;
    }

    return local_4;
}

// OK P1
int FUN_1000_2c2e(int param_1)
{
    return param_1 < 4 || ((byte)param_1 & 0xf0) == 0x60;
}

// NOT MATCHING (case order)
uint FUN_1000_2c4c(int param_2, int param_1)
{
    switch (D_54f4[param_2 >> 2])
    {
    case 0:
        return FUN_1000_2bd4(param_2, param_1);
    case 1:
        return FUN_1000_2c2e(param_1);
    case 2:
        if (((byte)param_1 & 0xf0) == 0x60 || FUN_1000_2c2e(param_1) != 0 || FUN_1000_2bd4(param_2, param_1) != 0)
        {
            return 1;
        }
        return 0;
    case 3:
        if (FUN_1000_2bd4(param_2, param_1) == 0 || param_1 == 0x8f || param_1 == 4)
        {
            return 0;
        }
        return 1;
    case 4:
        return (uint)(FUN_1000_2c2e(param_1) == 0);
    case 5:
        if (((byte)param_1 & 0xfc) == 0x34)
        {
            return (uint)((8 >> (param_2 & 3) & (uint)D_5510[param_1]) != 0);
        }
        if (FUN_1000_2c2e(param_1) == 0)
        {
            return 0;
        }
        if (param_1 < 0x60)
        {
            return 1;
        }
        return (uint)D_54d4[param_1] & (8 >> (param_2 & 3));
    case 6:
        if (2 < param_1)
        {
            return 0;
        }
        return 1;
    case 7:
        return param_1 == 4;
    case 8:
        return param_1 == 5;
    case 9:
        return param_1 == 1;
    case 10:
        return param_1 == 7;
    default:
        return 0;
    }
}

FUN_1000_3f14(void* a, int b, int c) {}

// select player (zstats, ...)
// TODO: MATCH
int FUN_1000_2d7a(int param_1)
{
    bool bVar1;
    uint uVar2;
    int iVar3;
    int local_4;

    local_4 = 0;
    bVar1 = 0;
    if ((0x7f < D_5893_map_id) && ((D_ba16[D_589e]._0 & 0x80) != 0))
    {
        FUN_1000_2a28(D_ba16[D_589e]._1);
    }
    FUN_1000_4e50("Select:");
    iVar3 = -1;
    do
    {
        if (iVar3 != local_4)
        {
            FUN_1000_2a28(local_4);
            iVar3 = local_4;
        }
        do
        {
            uVar2 = FUN_1000_266c_get_ch();
        } while (0x37 < uVar2);

        // TODO: switch
        if (((uVar2 < 0x31) || (0x36 < uVar2)) || ((uint)D_585b <= uVar2 - 0x31))
        {
            // case 2: 4:
            if (uVar2 == 4)
            {
            LAB_1000_2e2a:
                FUN_1000_3f14(&local_4, 1, D_585b - 1);
            }
            else if ((int)uVar2 < 5)
            {
                if (uVar2 != 1)
                {
                    if (uVar2 == 2) goto LAB_1000_2e2a;
                    if (uVar2 != 3) goto LAB_1000_2e19;
                }
                // case 1: 3:
                FUN_1000_3f54(&local_4, 1);
            }
            else
            {
                if (uVar2 != 0xd)
                {
                    if (uVar2 == 0x1b)
                    {
                        local_4 = -1;
                    }
                    else if (uVar2 != 0x20)
                    {
                        if ((uVar2 != 0x30) || (param_1 == 0)) goto LAB_1000_2e19;
                        local_4 = -2;
                    }
                }
                bVar1 = 1;
            }
        }
        else
        {
            local_4 = uVar2 - 0x31;
        }
    LAB_1000_2e19:
        if (iVar3 != local_4)
        {
            FUN_1000_2a28(iVar3);
        }
        if (bVar1)
        {
            if (-1 < local_4)
            {
                FUN_1000_2a28(local_4);
            }
            FUN_1000_4e20();
            return local_4;
        }
    } while (1);
}

void FUN_1000_2e8e(void)
{
    FUN_1000_2d7a(0);
    return;
}
