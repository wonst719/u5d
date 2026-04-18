#include "COMMON.H"
#include "FILE.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// OK P1
u16 ULTIMA_2032_ToUpper(u8 x)
{
    if (x >= 0x61 && 0x7a >= x)
    {
        return x - 0x20;
    }

    return x;
}

// STUB
uint ULTIMA_2056_GetTime(void)
{
    return time(NULL) & 0xffff;
}

// OK P1
void ULTIMA_207e_srand(uint param_1)
{
#if !defined(TARGET_DOS16)
    srand(param_1);
#else
    D_5420 = param_1;
#endif
}

// NOT MATCHING: asm
// range: [min..max]
int ULTIMA_2092_RandomRange(int param_1, int param_2) // inclusive_min, inclusive_max
{
#if !defined(TARGET_DOS16)
    ASSERT(param_1 <= param_2);

    return rand() % ((param_2 - param_1) + 1) + param_1;
#else
    register uint ax;

    ax = D_5420 + 0x9248;
    ax = _rotr(ax, 3);
    ax ^= 0x9248;
    ax += 0x11;
    D_5420 = ax;

    return (ax & 0x7fff) % ((param_2 - param_1) + 1) + param_1;
#endif
}

// STUB
// (asm) some busy-wait delay?
void ULTIMA_20c8_SomeDelay(int param_1, int param_2)
{
    // FMT: empty
#if !defined(TARGET_DOS16)
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

void ULTIMA_20fa_WaitTicks(int a)
{
    //debug("ULTIMA_20fa_WaitTicks");

#if !defined(TARGET_DOS16)
    void TIME_Sleep(int ms);
    TIME_Sleep(a * 55); // 18.2 ticks per second
#endif
}

int ULTIMA_216c_strlen(char* param_1)
{
    int iVar1;

    iVar1 = 0;
    while (*param_1 != '\0') {
        iVar1 = iVar1 + 1;
        param_1 = param_1 + 1;
    }
    return iVar1;
}

// audio: some noise? audio and something?
// param_3, param_4: uint?
void ULTIMA_2192_AudioSomeNoise(int param_1, int param_2, int param_3, int param_4, int param_5)
{
}

// audio: white noise (rate, dur, limit)
void ULTIMA_223c_AudioNoise(uint rate, uint dur, uint limit)
{
    // Ref: FUN_0002c598
}

void ULTIMA_22c0_AudioPlayTone(uint freq, uint dur)
{
    if (D_a9ce != 0)
    {
        ULTIMA_22e2_PcspkOn(freq);
    }

    ULTIMA_20c8_SomeDelay(1, dur);
    ULTIMA_230e_PcspkOff();
}

void ULTIMA_22e2_PcspkOn(uint freq)
{
    if (D_a9ce != 0)
    {
        // start tone
        // NOTE / REF: https://fragglet.github.io/dos-help-files/alang.hlp/x_at_L848b.html
    }
}

void ULTIMA_230e_PcspkOff(void)
{
    // speaker off
    // NOTE / REF: https://fragglet.github.io/dos-help-files/alang.hlp/x_at_L848b.html
}

void ULTIMA_2322_DiskSwapMessage(void)
{
    // DUMMY
}

void ULTIMA_251e_SwitchDisks(int x) { debug("ULTIMA_251e_SwitchDisks(%d)", x); }

int ULTIMA_256e_ReadFile(char* file_name, void* addr, u16 size, u16 offset)
{
    debug("ULTIMA_256e_ReadFile(%s,ptr,%d,%d)", file_name, size, offset);
    return FILE_ReadFile(file_name, addr, size, offset);
}

int ULTIMA_25d8_WriteFile(char* file_name, void* addr, u16 size)
{
    debug("ULTIMA_25d8_WriteFile(%s,ptr,%d)", file_name, size);
    return FILE_WriteFile(file_name, addr, size, 0);
}

// OK P1
int ULTIMA_266c_GetChar(void)
{
    int local_4;

    if (D_52c8 == 2)
    {
        D_5891 = 0xff;
    }

    do
    {
        local_4 = ULTIMA_2032_ToUpper((u8)ULTIMA_1b38_KeystrokeCursor());
        if ((local_4 == 0) && (D_5893_map_id < 0x21 || 0x7f < D_5893_map_id))
        {
            ULTIMA_5910_UpdateFrame();
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

// OK P1 (complete)
void ULTIMA_2726(int param_1)
{
    int     local1_6;
    S_ba14* local2_4;

    ULTIMA_1bf2_SetTextPosition(0, param_1);

    if (D_585b <= param_1)
    {
        for (local1_6 = 0; local1_6 < 0xf; local1_6++)
        {
            // 2748
            ULTIMA_16ba_PrintChar(0x20);
        }

        return;
    }

    // 2758
    local2_4 = &D_ba14[D_589e];
    if (D_5893_map_id > 0x7f && D_589e != 0xff && (local2_4->_2 & 0x80) != 0 && local2_4->_3 == param_1)
    {
        ULTIMA_16ba_PrintChar(0xfd);
    }

    // 278e
    ULTIMA_1850_PrintString(D_55a8_party[param_1]._0);
    for (local1_6 = ULTIMA_216c_strlen(D_55a8_party[param_1]._0); local1_6 < 9; local1_6++)
    {
        // 27b8
        ULTIMA_16ba_PrintChar(0x20);
    }

    // 27c2
    if (param_1 == D_587b)
    {
        if (D_55a8_party[param_1]._b != 0x44 && D_55a8_party[param_1]._b != 0x53)
        {
            ULTIMA_16ba_PrintChar(0x1a);
        }
        else
        {
            ULTIMA_16ba_PrintChar(0x20);
            D_587b = 0xff;
        }
    }
    else
    {
        // 27f6
        ULTIMA_16ba_PrintChar(0x20);
    }

    // 27fd
    ULTIMA_1a3e_PrintNumber(D_55a8_party[param_1]._10, 4, 0x20);

    if (D_5893_map_id > 0x7f)
    {
        if ((D_ba14[param_1]._2 & 0xe1) == 0x81 && D_ba14[param_1]._3 == param_1)
        {
            // -> 2849
            ULTIMA_16ba_PrintChar(0x43);
        }
        else
        {
            // 283c -> 2849
            ULTIMA_16ba_PrintChar(D_55a8_party[param_1]._b);
        }

        if (D_589e != 0xff && (local2_4->_2 & 0x80) != 0)
        {
            if (local2_4->_3 == param_1)
            {
                ULTIMA_16ba_PrintChar(0xfd);
            }
        }

        // 287d
        return;
    }

    // 286c
    ULTIMA_16ba_PrintChar(D_55a8_party[param_1]._b);
}

// OK P1 (complete)
void ULTIMA_2884_UpdateGoldDisplay(void)
{
    undefined2 local_2;

    local_2 = D_5386_current_text_window_idx;
    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(8, 7);
    if (D_57aa < 1000)
    {
        ULTIMA_16ba_PrintChar(' ');
    }
    if (D_57aa < 100)
    {
        ULTIMA_16ba_PrintChar(' ');
    }
    if (D_57aa < 10)
    {
        ULTIMA_16ba_PrintChar(' ');
    }
    ULTIMA_1850_PrintString(" G:");
    ULTIMA_1a3e_PrintNumber(D_57aa, 1, ' ');
    while (0xf > ULTIMA_1f12_GetCurrentTextX())
    {
        ULTIMA_16ba_PrintChar(' ');
    }

    ULTIMA_1b94_SelectTextWindow(local_2);
}

// OK P1
void ULTIMA_2900_UpdateVitalsDisplay(void)
{
    int local_2;

    ULTIMA_1b94_SelectTextWindow(1);

    local_2 = 0;
    do
    {
        ULTIMA_2726(local_2);
        local_2++;
    } while (local_2 < 6);

    ULTIMA_1bf2_SetTextPosition(0, 7);

    // food
    ULTIMA_1850_PrintString("F:");
    ULTIMA_1a3e_PrintNumber(D_57a8, 1, ' ');

    while (ULTIMA_1f12_GetCurrentTextX() < 8)
    {
        ULTIMA_16ba_PrintChar(' ');
    }

    if ((D_5893_map_id < 0x80) && ((D_587c & 0xf8) == 0x20))
    {
        // ship
        ULTIMA_1850_PrintString("Ship:");
        ULTIMA_1a3e_PrintNumber(D_5c5a[0]._5, 1, ' ');
        if (D_5c5a[0]._5 < 10)
        {
            ULTIMA_16ba_PrintChar(' ');
        }
    }
    else
    {
        ULTIMA_2884_UpdateGoldDisplay();
    }

    ULTIMA_1850_PrintString("\n   ");

    if ((D_587d < 10) && (D_587e < 10))
    {
        ULTIMA_16ba_PrintChar(' ');
    }

    // date (m/d/y)
    ULTIMA_1a3e_PrintNumber(D_587d, 1, ' ');
    ULTIMA_16ba_PrintChar(' ');
    ULTIMA_1a3e_PrintNumber(D_587e, 1, ' ');
    ULTIMA_16ba_PrintChar(' ');
    ULTIMA_1a3e_PrintNumber(D_5874, 3, ' ');

    while (ULTIMA_1f12_GetCurrentTextX() < 0xf)
    {
        ULTIMA_16ba_PrintChar(' ');
    }

    ULTIMA_1bf2_SetTextPosition(6, 6);

    // icon?
    if (D_587a != 0)
    {
        ULTIMA_4c2a();
        ULTIMA_16ba_PrintChar(D_587a);
        ULTIMA_4cce();
    }
    else
    {
        ULTIMA_4f3c();
    }

    ULTIMA_1b94_SelectTextWindow(2);
}

// OK P1
void ULTIMA_2a28(int param_1)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b86_GRAP_XorFillRect(0xc0, param_1 * 8 + 8, 0x137, param_1 * 8 + 0xf);
}

// OK P1
// process damage (show fx, reduce hp)
void ULTIMA_2a52(int param_1, uint param_2)
{
    ULTIMA_2a28(param_1);
    ULTIMA_223c_AudioNoise(10, 0x640, 2000);
    ULTIMA_2a28(param_1);

    D_55a8_party[param_1]._10 -= param_2;
    if (D_55a8_party[param_1]._10 <= 0)
    {
        D_55a8_party[param_1]._10 = 0;
        D_55a8_party[param_1]._b = 0x44; // 'D'
        if (param_1 == D_587b)
        {
            D_587b = 0xff;
        }
    }

    ULTIMA_2900_UpdateVitalsDisplay();
}

// OK P1
// process party damage
void ULTIMA_2aa8(void)
{
    int i = 0;
    do
    {
        if ((i < D_585b) && (D_55a8_party[i]._b != 'D'))
        {
            ULTIMA_2a52(i, ULTIMA_2092_RandomRange(1, 8));
        }
        i++;
    } while (i < 6);
}

void ULTIMA_3ef0(byte* param_1, int param_2, int param_3);

// OK P1 (NOT MATCHING: register)
void ULTIMA_2ae8(void)
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
                    ULTIMA_2a52(local_6, 1);
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
            ULTIMA_1850_PrintString("Starving!\n"/*54c8*/);
            ULTIMA_2aa8();
        }
        else if (((D_587f == '\x06') || (D_587f == '\f')) || (D_587f == '\x12'))
        {
            ULTIMA_3f54((s16*)&D_57a8, local_4);
        }
        D_5880 = D_587f;
    }
    ULTIMA_3ef0(&D_588b, 1, 0xff);
    if ((D_588e != '\0') && (D_588e != 0xff))
    {
        D_588e--;
        if (D_588e == '\0')
        {
            D_587a = 0;
            ULTIMA_2900_UpdateVitalsDisplay();
        }
    }
    ULTIMA_400c();
}

// OK P1
bool ULTIMA_2bd4(byte param_1, int param_2)
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
int ULTIMA_2c2e(int param_1)
{
    return param_1 < 4 || ((byte)param_1 & 0xf0) == 0x60;
}

// NOT MATCHING (case order)
// walkable?
// a: party icon
// b: tile
int ULTIMA_2c4c(int param_1, int param_2)
{
    switch (D_54f4[param_1 >> 2])
    {
    case 0:
        return ULTIMA_2bd4(param_1, param_2);
    case 1:
        return ULTIMA_2c2e(param_2);
    case 2:
        if (((byte)param_2 & 0xf0) == 0x60 || ULTIMA_2c2e(param_2) != 0 || ULTIMA_2bd4(param_1, param_2) != 0)
        {
            return 1;
        }
        return 0;
    default:
        return 0;
    case 3:
        if (ULTIMA_2bd4(param_1, param_2) == 0 || param_2 == 0x8f || param_2 == 4)
        {
            return 0;
        }
        return 1;
    case 4:
        return ULTIMA_2c2e(param_2) == 0;
    case 5:
        if (((byte)param_2 & 0xfc) == 0x34)
        {
            return (8 >> (param_1 & 3) & (uint)D_5544[param_2 - 0x34]) != 0;
        }
        if (ULTIMA_2c2e(param_2) == 0)
        {
            return 0;
        }
        if (param_2 < 0x60)
        {
            return 1;
        }
        if (!((uint)D_54d4[param_2] & (8 >> (param_1 & 3))))
            return 0;
        else
            return 1;
    case 6:
        if (2 < param_2)
        {
            return 0;
        }
        return 1;
    case 7:
        return param_2 == 4;
    case 8:
        return param_2 == 5;
    case 9:
        return param_2 == 1;
    case 10:
        return param_2 == 7;
    }
}

// select player (zstats, ...)
// OK P1 (NOT MATCHING: register)
int ULTIMA_2d7a(int param_1)
{
    bool local_6;
    int local_8;
    int local_a;
    s16 local_4;

    local_4 = 0;
    local_a = -1; // (-1)
    local_6 = 0;
    if ((0x7f < D_5893_map_id) && ((D_ba14[D_589e]._2 & 0x80) != 0))
    {
        ULTIMA_2a28(D_ba14[D_589e]._3);
    }
    // 2db2
    ULTIMA_4e50("Select:");
    // ^OK
    do
    {
        // 2dbc
        if (local_a != local_4)
        {
            ULTIMA_2a28(local_4);
            local_a = local_4;
        }
        do
        {
            local_8 = ULTIMA_266c_GetChar();
        } while (0x37 < local_8);

        // sub vs lea
        if (((local_8 > 0x30) && (local_8 < 0x37)) && ((uint)D_585b > local_8 - 0x31))
        {
            local_4 = local_8 - 0x31;
        }
        else
        {
            switch (local_8)
            {
            case 1:
            case 3:
                ULTIMA_3f54(&local_4, 1);
                break;

            case 2:
            case 4:
                ULTIMA_3f14(&local_4, 1, D_585b - 1);
                break;

            case 0x30:
                if (param_1 == 0)
                    break;

                local_4 = -2;
                local_6 = 1;
                break;

            case 0x1b:
                local_4 = -1;
                local_6 = 1;
                break;

            case 0xd:
            case 0x20:
                local_6 = 1;
                break;
            }
        }

        if (local_a != local_4)
        {
            ULTIMA_2a28(local_a);
        }
    } while (!local_6);

    // 2e6e
    if (-1 < local_4)
    {
        ULTIMA_2a28(local_4);
    }
    ULTIMA_4e20();
    return local_4;
}

// OK P1
int ULTIMA_2e8e(void)
{
    return ULTIMA_2d7a(0);
}

// OK P1
void ULTIMA_2e96_SetWindDirection(int direction)
{
    if (direction != -1)
    {
        D_5892_wind_dir = (char)direction;
        D_5883 = 0;
    }

    if (D_5893_map_id >= 0x21 || D_5893_map_id == 0x19)
        return;

    if (D_5895_map_level < 0x80) // s8 level >= 0?
    {
        ULTIMA_1b94_SelectTextWindow(0);
        ULTIMA_1bf2_SetTextPosition(6, 0x17);
        ULTIMA_4c2a();

        switch (D_5892_wind_dir)
        {
        case 0:
            ULTIMA_1850_PrintString("Calm "); // 555c
            break;
        case 1:
            ULTIMA_1850_PrintString("North"); // 5562
            break;
        case 2:
            ULTIMA_1850_PrintString("South"); // 5568
            break;
        case 3:
            ULTIMA_1850_PrintString("East "); // 556e
            break;
        case 4:
            ULTIMA_1850_PrintString("West "); // 5574
            break;
        }

        ULTIMA_1850_PrintString(" Winds"); // 557a
        ULTIMA_4cce();
        ULTIMA_1b94_SelectTextWindow(2);
    }
    else
    {
        // level < 0
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
        ULTIMA_0b10_GRAP_Line(0x30, 0xb8, 0x98, 0xb8);
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
        ULTIMA_0aa6_GRAP_3f_FillRect(0x30, 0xb9, 0x98, 0xbf);
    }
}

// NOT MATCHING
void ULTIMA_2f62_UpdateWindDirectionRandomly(void)
{
    if (ULTIMA_2092_RandomRange(0, 0x3f) == 0)
    {
        register int iVar1;
        while ((iVar1 = ULTIMA_2092_RandomRange(0, 4)) == 0)
        {
            if (ULTIMA_2092_RandomRange(0, 0xff) >= 0xc0)
                break;
        }

        ULTIMA_2e96_SetWindDirection(iVar1);
    }
}

// OK P1
void ULTIMA_2fa6(uint param_1)
{
    if (param_1 < D_585b && D_55a8_party[param_1]._b != 'D')
    {
        D_55a8_party[param_1]._b = 'P';
        ULTIMA_2900_UpdateVitalsDisplay();
    }
}

// OK P1
void ULTIMA_2fd0(undefined2 param_1)
{
    int local_4b;
    int local_6a;

    ULTIMA_223c_AudioNoise(0x28, 3000, 500);

    if (D_5893_map_id > 0x7f)
    {
        local_4b = ULTIMA_2092_RandomRange(0, 1);
    }
    else
    {
        local_4b = (uint)D_559e[ULTIMA_2092_RandomRange(0, 7)];
    }

    switch (local_4b)
    {
    case 0:
        ULTIMA_1850_PrintString("ACID!\n"); // 5581
        ULTIMA_2a52(param_1, ULTIMA_3abe());
        break;
    case 1:
        ULTIMA_1850_PrintString("POISON!\n"); // 5588
        ULTIMA_2fa6(param_1);
        break;
    case 2:
        ULTIMA_1850_PrintString("BOMB!\n"); // 5591
        ULTIMA_2aa8();
        break;
    case 3:
        ULTIMA_1850_PrintString("GAS!\n"); // 5598
        local_6a = 0;
        do
        {
            ULTIMA_2fa6(local_6a);
        } while (++local_6a < 6);
        break;
    }
}
