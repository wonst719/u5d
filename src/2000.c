#include "common/common.h"
#include "vars.h"
#include "funcs.h"
#include "macros.h"
#include "tiles.h"

#include "audio/aud_sfx.h"
#include "time/time.h"

#include <stdlib.h>
#include <time.h>

// OK P1
u16 ULTIMA_2032_ToUpper(u8 x)
{
    if (x >= 0x61 && x <= 0x7a)
    {
        return x - 0x20;
    }

    return x;
}

// STUB (asm)
uint ULTIMA_2056_GetTime(void)
{
    return time(NULL) & 0xffff;
}

// OK P1 (asm)
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

// STUB (asm)
// some busy-wait delay?
void ULTIMA_20c8_SomeDelay(int param_1, int param_2)
{
    // FMT: empty
#if !defined(TARGET_DOS16)
    if (param_2 == 0x14)
    {
        TIME_SleepMs(16);
    }
    // dummy values / approximation
    if (param_2 > 0x14)
    {
        TIME_SleepMs(param_2);
    }
    return;
#else
    register uint ax, cx;

    ax = D_5356; // timer calibration
    cx = D_5426[param_1];

    if (cx != 0)
    {
        // shr ax, cl
        ax >>= cx;
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

// STUB (asm)
void ULTIMA_20fa_WaitTicks(int a)
{
    //debug("ULTIMA_20fa_WaitTicks");

#if !defined(TARGET_DOS16)
    TIME_SleepMs(a * 55); // 18.2 ticks per second
#endif
}

// OK P1
int ULTIMA_216c_strlen(char* param_1)
{
    int local_4;

    local_4 = 0;
    while (*param_1++ != '\0')
    {
        local_4++;
    }
    return local_4;
}

// STUB (asm)
// audio: pulse (pwm)
// FMT debug msg: pulse_(Freq, Delay, Dura, P_Wid, P_Inc)
void ULTIMA_2192_AudioPulse(int freq, int delay, int dur, int pulseWidth, int pulseInc)
{
#if !defined(TARGET_DOS16)
    AUDIO_DispatchPulse(freq, delay, dur, pulseWidth, pulseInc);
    return;
#endif
}

// STUB (asm)
// audio: white noise
// FMT debug msg: white_noise(Rate, Dura, Limit)
void ULTIMA_223c_AudioWhiteNoise(uint rate, uint dur, uint limit)
{
#if !defined(TARGET_DOS16)
    AUDIO_DispatchWhiteNoise(rate, dur, limit);
    return;
#endif
}

// STUB (asm?)
// audio: tone
// FMT debug msg: tone(freq, dur)
void ULTIMA_22c0_AudioTone(uint freq, uint dur)
{
#if !defined(TARGET_DOS16)
    AUDIO_DispatchTone(freq, dur);
    return;
#endif

    if (D_a9ce != 0)
    {
        ULTIMA_22e2_PcspkOn(freq);
    }

    ULTIMA_20c8_SomeDelay(1, dur);
    ULTIMA_230e_PcspkOff();
}

// STUB (asm)
// FMT: dummy
void ULTIMA_22e2_PcspkOn(uint freq)
{
    if (D_a9ce != 0)
    {
        // start tone
        // NOTE / REF: https://fragglet.github.io/dos-help-files/alang.hlp/x_at_L848b.html
    }
}

// STUB (asm)
// FMT: dummy
void ULTIMA_230e_PcspkOff(void)
{
    // speaker off
    // NOTE / REF: https://fragglet.github.io/dos-help-files/alang.hlp/x_at_L848b.html
}

// OK P1
void FAR ULTIMA_2320_NoDiskSwapMessage(void)
{
    // nop
}

// CHECKED
// GOG patched: skip drive selection
void FAR ULTIMA_2322_DiskSwapMessage(void)
{
    byte local_4;
    byte local_6;

    D_5394_fn = ULTIMA_2320_NoDiskSwapMessage;

    local_6 = D_a9c8[D_a9bd[0]];
    if (local_6 != 0xff && D_545e != D_a9bd[0] && ULTIMA_16a6_GetDefaultDrive() != local_6)
    {
        // 235a
        ULTIMA_1eac_SetDefaultDrive(D_a9c8[D_a9bd[0]]);
        // 236d
        D_545e = D_a9bd[0];
    }
    else
    {
        // 2374
        if (D_a9c8[D_a9bd[0]] < 0x43 && D_a9c2 > 1)
        {
            D_a9c8[D_a9bd[0]] ^= 3;
            ULTIMA_1eac_SetDefaultDrive(D_a9c8[D_a9bd[0]]);
            // 2394
            if (D_545e != D_a9bd[0])
            {
                // -> 236d
                D_545e = D_a9bd[0];
                goto L_250c; // TODO: remove goto
            }
        }

        // 239d
        if (D_a9c8[D_a9bd[0]] >= 'C' && D_a9c8[D_a9bd[0]] != 0xff)
        {
            D_a9c8[D_a9bd[0]] = 'A';
            ULTIMA_1eac_SetDefaultDrive('A');
            D_545e = 0xff;
        }
        else
        {
            if (D_a9bd[1] == 2)
            {
                ULTIMA_0c22_GRAP_0f_SelectPage(0);
                ULTIMA_1c22_SetTextWindowSize(0, 6, 0xc, 0x21, 0xd);
                ULTIMA_0a70_GRAP_2d_SetPenColor(0);
                ULTIMA_0aa6_GRAP_3f_FillRect(0x28, 0x58, 0x117, 0x77);
            }

            // 2400
            D_545e = 0xff;

#if defined(GOG_BUILD)
            // 2405 GOG: PATCHED (different instructions)
            local_4 = ULTIMA_16a6_GetDefaultDrive();
            goto L_GOG_247d;
#endif

            // 2405
            ULTIMA_1850_PrintString(/*0x545f*/ "\nPlease insert the Ultima ");
            if (D_a9bd[0] == 4)
            {
                ULTIMA_16ba_PrintChar(0x49);
            }

            ULTIMA_1850_PrintString(/*0x547a*/ "V ");

            // 360k: 0=Program 1,3=Britannia 4=Player 2=Dungeon 5=Underworld
            // 720k: 0=Program 1,3=Britannia 4=Player (2, 5 => 1)
            switch (D_a9bd[0])
            {
            case 0:
                ULTIMA_1850_PrintString(/*0x547d*/ "Program");
                break;
            case 1:
            case 3:
                ULTIMA_1850_PrintString(/*0x5485*/ "Britannia");
                break;

            case 4:
                ULTIMA_1850_PrintString(/*0x548f*/ "Player");
                break;
            }

            ULTIMA_1850_PrintString(/*0x5496*/ " Disk");

            if (D_a9c8[D_a9bd[0]] == 0xff)
            {
                ULTIMA_1850_PrintString(/*0x549c*/ " and press drive letter: ");
            }
            else
            {
                ULTIMA_16ba_PrintChar(0x2e);
            }

            do
            {
                // 2473
                local_4 = ULTIMA_2032_ToUpper(ULTIMA_1dda_WaitForKeystroke(0));

#if defined(GOG_BUILD)
L_GOG_247d:
#endif
                // 247d
                if (D_a9c8[D_a9bd[0]] != 0xff)
                    break;

            } while (ULTIMA_1eac_SetDefaultDrive(local_4) == 0);

            // 2497
            if (D_a9c8[D_a9bd[0]] == 0xff)
            {
                // 24aa
#if !defined(GOG_BUILD)
                // GOG: PATCHED (3 nops)
                ULTIMA_16ba_PrintChar(local_4);
#endif

                if (local_4 == 'B')
                {
                    D_a9c2 = 2;
                }

                D_a9c8[D_a9bd[0]] = local_4;
                if (D_a9bd[0] == 3 && D_a9c9 == 0xff)
                {
                    D_a9c9 = local_4;
                }
            }

            if (D_a9bd[1] == 0)
            {
                ULTIMA_16ba_PrintChar(10);
            }
            else if (D_a9bd[1] == 2)
            {
                ULTIMA_0c22_GRAP_0f_SelectPage(1);
                ULTIMA_1c22_SetTextWindowSize(0, 0, 0, 0x27, 0x18);
                ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);
            }
        }
    }

L_250c:
    D_5394_fn = ULTIMA_2322_DiskSwapMessage;
}

// OK P1
void ULTIMA_251e_SwitchDisks(int param_1)
{
    D_5394_fn = ULTIMA_2320_NoDiskSwapMessage;

    if (param_1 == 2 || param_1 == 5)
    {
        param_1 = 1;
    }

    D_a9bd[0] = param_1;

    if (D_a9c8[param_1] != 0xff)
    {
        ULTIMA_1eac_SetDefaultDrive(D_a9c8[param_1]);
        D_545e = 0xff;
    }

    D_5394_fn = ULTIMA_2322_DiskSwapMessage;
}

// CHECKED
void ULTIMA_256e_ReadFileFromDisk(char* fileName, void* addr, u16 size, u16 offset)
{
#if !defined(TARGET_DOS16)
    ULTIMA_7234_ReadFile(fileName, addr, size, offset);
    return;
#endif

    int local_4 = 0;

    if (D_a9bd[0] == 3 && D_a9c8[D_a9bd[0]] == 0xff)
    {
        // NOT MATCHING: callf
        ULTIMA_2322_DiskSwapMessage();
    }

    ULTIMA_1eac_SetDefaultDrive(D_a9c8[D_a9bd[0]]);

    while (local_4 == 0)
    {
        local_4 = ULTIMA_7234_ReadFile(fileName, addr, size, offset);
    }
}

// OK P1
static void FAR ULTIMA_25ca_WriteError(void)
{
    ULTIMA_1850_PrintString(/*0xa0e0*/ "\nYour disk may be write-protected. Try again.\n");
    ULTIMA_1dda_WaitForKeystroke(0);
}

// CHECKED
void ULTIMA_25d8_WriteFileToDisk(char* fileName, void* addr, u16 size)
{
#if !defined(TARGET_DOS16)
    ULTIMA_7296_WriteFile(fileName, addr, size);
    return;
#endif

    int local_6;
    int local_4;

    local_4 = 0;

    local_6 = D_a9bd[0]; // NOT MATCHING: si
    if (local_6 == 3 && D_a9cb == 0xff)
    {
        // NOT MATCHING: callf
        ULTIMA_2322_DiskSwapMessage();
    }

    ULTIMA_1eac_SetDefaultDrive(D_a9c8[D_a9bd[0]]);

    while (local_4 == 0)
    {
        while (ULTIMA_1674_TestOpenFile(fileName) == 0) {}

        D_5394_fn = ULTIMA_25ca_WriteError;

        local_4 = ULTIMA_7296_WriteFile(fileName, addr, size);

        D_5394_fn = ULTIMA_2322_DiskSwapMessage;
    }

    D_a9bd[0] = local_6;
    ULTIMA_1eac_SetDefaultDrive(D_a9c8[D_a9bd[0]]);
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
        local_4 = ULTIMA_2032_ToUpper(ULTIMA_1b38_PollKeyWithCursor());
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
            local_4 = U5_KEY_END;
            break;
        case 0x32:
            local_4 = U5_KEY_DOWN;
            break;
        case 0x33:
            local_4 = U5_KEY_PGDN;
            break;
        case 0x34:
            local_4 = U5_KEY_LEFT;
            break;
        case 0x36:
            local_4 = U5_KEY_RIGHT;
            break;
        case 0x37:
            local_4 = U5_KEY_HOME;
            break;
        case 0x38:
            local_4 = U5_KEY_UP;
            break;
        case 0x39:
            local_4 = U5_KEY_PGUP;
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
static void ULTIMA_2726(int param_1)
{
    int     local1_6;
    CombatEntity* local2_4;

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
    if (D_5893_map_id > 0x7f && D_589e != 0xff && (local2_4->flags & COMBAT_FLAGS_PLAYER) != 0 && local2_4->entityIdx == param_1)
    {
        ULTIMA_16ba_PrintChar(0xfd);
    }

    // 278e
    ULTIMA_1850_PrintString(D_55a8_party[param_1].name);
    for (local1_6 = ULTIMA_216c_strlen(D_55a8_party[param_1].name); local1_6 < 9; local1_6++)
    {
        // 27b8
        ULTIMA_16ba_PrintChar(0x20);
    }

    // 27c2
    if (param_1 == D_587b)
    {
        if (D_55a8_party[param_1].status != STATUS_DEAD && D_55a8_party[param_1].status != STATUS_SLEEP)
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
    ULTIMA_1a3e_PrintNumber(D_55a8_party[param_1].hp, 4, 0x20);

    if (D_5893_map_id > 0x7f)
    {
        if ((D_ba14[param_1].flags & (COMBAT_FLAGS_PLAYER | COMBAT_FLAGS_MONSTER | COMBAT_FLAGS_DEAD | COMBAT_FLAGS_CHARMED)) ==
            (COMBAT_FLAGS_PLAYER | COMBAT_FLAGS_CHARMED) &&
            D_ba14[param_1].entityIdx == param_1)
        {
            // -> 2849
            ULTIMA_16ba_PrintChar(0x43);
        }
        else
        {
            // 283c -> 2849
            ULTIMA_16ba_PrintChar(D_55a8_party[param_1].status);
        }

        if (D_589e != 0xff && (local2_4->flags & COMBAT_FLAGS_PLAYER) != 0)
        {
            if (local2_4->entityIdx == param_1)
            {
                ULTIMA_16ba_PrintChar(0xfd);
            }
        }

        // 287d
        return;
    }

    // 286c
    ULTIMA_16ba_PrintChar(D_55a8_party[param_1].status);
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
    ULTIMA_1850_PrintString(/*0x54b6*/ " G:");
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
    ULTIMA_1850_PrintString(/*0x54ba*/ "F:");
    ULTIMA_1a3e_PrintNumber(D_57a8, 1, ' ');

    while (ULTIMA_1f12_GetCurrentTextX() < 8)
    {
        ULTIMA_16ba_PrintChar(' ');
    }

    if ((D_5893_map_id < 0x80) && ((D_587c_partyTile & 0xf8) == TILE_ACTOR_FRIGATE_20))
    {
        // ship
        ULTIMA_1850_PrintString(/*0x54bd*/ "Ship:");
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

    ULTIMA_1850_PrintString(/*0x54c3*/ "\n   ");

    if ((D_587d < 10) && (D_587e < 10))
    {
        ULTIMA_16ba_PrintChar(' ');
    }

    // date (m/d/y)
    ULTIMA_1a3e_PrintNumber(D_587d, 1, ' ');
    ULTIMA_16ba_PrintChar('-');
    ULTIMA_1a3e_PrintNumber(D_587e, 1, ' ');
    ULTIMA_16ba_PrintChar('-');
    ULTIMA_1a3e_PrintNumber(D_5874, 3, '0');

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
    ULTIMA_223c_AudioWhiteNoise(10, 0x640, 2000);
    ULTIMA_2a28(param_1);

    D_55a8_party[param_1].hp -= param_2;
    if (D_55a8_party[param_1].hp <= 0)
    {
        D_55a8_party[param_1].hp = 0;
        D_55a8_party[param_1].status = STATUS_DEAD;
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
    int i;
    for (i = 0; i < 6; i++)
    {
        if (i < D_585b && D_55a8_party[i].status != STATUS_DEAD)
        {
            ULTIMA_2a52(i, ULTIMA_2092_RandomRange(1, 8));
        }
    }
}

void ULTIMA_3ef0_IncreaseByte(byte* param_1, int param_2, int param_3);

// CHECKED
void ULTIMA_2ae8(void)
{
    int local_8;
    int local_6;
    int local_4;

    local_4 = 0;

    for (local_6 = 0; local_6 < D_585b; local_6++)
    {
        local_8 = D_55a8_party[local_6].status;
        if (local_8 == STATUS_DEAD && local_6 == D_587b)
        {
            D_587b = 0xff;
        }

        // NOT MATCHING: register (mov ax, si ...)
        if (local_8 != STATUS_DEAD && local_8 != STATUS_SLEEP)
        {
            if (local_8 == STATUS_POISONED)
            {
                ULTIMA_2a52(local_6, 1);
            }

            local_4++;
        }
    }

    if (D_587f != D_5880)
    {
        if (D_57a8 == 0)
        {
            ULTIMA_1850_PrintString(/*0x54c8*/ "Starving!\n");
            ULTIMA_2aa8();
        }
        else if (D_587f == 6 || D_587f == 12 || D_587f == 18)
        {
            ULTIMA_3f54_DecreaseInt(&D_57a8, local_4);
        }
        D_5880 = D_587f;
    }

    ULTIMA_3ef0_IncreaseByte(&D_588b, 1, 0xff);
    if (D_588e != 0 && D_588e != 0xff)
    {
        D_588e--;
        if (D_588e == 0)
        {
            D_587a = 0;
            ULTIMA_2900_UpdateVitalsDisplay();
        }
    }

    ULTIMA_400c();
}

// OK P1
static bool ULTIMA_2bd4(byte param_1, int param_2)
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
static int ULTIMA_2c2e(int param_1)
{
    return param_1 < 4 || ((byte)param_1 & 0xf0) == 0x60;
}

// CHECKED
// walkable?
// param_1: party tile
// param_2: tile
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

// CHECKED
// select player (zstats, ...)
int ULTIMA_2d7a(int param_1)
{
    bool local_6;
    uint local_8;
    int local_a;
    s16 local_4;

    local_4 = 0;
    local_a = -1;
    local_6 = 0;
    if (D_5893_map_id > 0x7f && (D_ba14[D_589e].flags & COMBAT_FLAGS_PLAYER) != 0)
    {
        ULTIMA_2a28(D_ba14[D_589e].entityIdx);
    }

    // 2db2
    ULTIMA_4e50(/*0x5554*/ "Select:");
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
        } while (local_8 > '7');

        if (local_8 > '0' && local_8 < '7' && local_8 - '1' < D_585b)
        {
            local_4 = local_8 - '1';
        }
        else
        {
            switch ((int)local_8)
            {
            case U5_KEY_LEFT:
            case U5_KEY_UP:
                ULTIMA_3f54_DecreaseInt(&local_4, 1);
                break;

            case U5_KEY_RIGHT:
            case U5_KEY_DOWN:
                ULTIMA_3f14_IncreaseInt(&local_4, 1, D_585b - 1);
                break;

            case 0x30:
                if (param_1 == 0)
                    break;

                local_4 = -2;
                local_6 = 1;
                break;

            case U5_KEY_ESC:
                local_4 = -1;
                local_6 = 1;
                break;

            case U5_KEY_ENTER:
            case U5_KEY_SPACE:
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
            ULTIMA_1850_PrintString(/*0x555c*/ "Calm ");
            break;
        case 1:
            ULTIMA_1850_PrintString(/*0x5562*/ "North");
            break;
        case 2:
            ULTIMA_1850_PrintString(/*0x5568*/ "South");
            break;
        case 3:
            ULTIMA_1850_PrintString(/*0x556e*/ "East ");
            break;
        case 4:
            ULTIMA_1850_PrintString(/*0x5574*/ "West ");
            break;
        }

        ULTIMA_1850_PrintString(/*0x557a*/ " Winds");
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

// CHECKED
void ULTIMA_2f62_UpdateWindDirectionRandomly(void)
{
    int local_4;
    if (ULTIMA_2092_RandomRange(0, 0x3f) == 0)
    {
        while ((local_4 = ULTIMA_2092_RandomRange(0, 4)) == 0 && ULTIMA_2092_RandomRange(0, 0xff) < 0xc0)
        {
        }

        ULTIMA_2e96_SetWindDirection(local_4);
    }
}

// OK P1
static void ULTIMA_2fa6(int param_1)
{
    if (param_1 < D_585b && D_55a8_party[param_1].status != STATUS_DEAD)
    {
        D_55a8_party[param_1].status = STATUS_POISONED;
        ULTIMA_2900_UpdateVitalsDisplay();
    }
}

// OK P1
void ULTIMA_2fd0(int param_1)
{
    int local_4b;
    int local_6a;

    ULTIMA_223c_AudioWhiteNoise(0x28, 3000, 500);

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
        ULTIMA_1850_PrintString(/*0x5581*/ "ACID!\n");
        ULTIMA_2a52(param_1, ULTIMA_3abe());
        break;
    case 1:
        ULTIMA_1850_PrintString(/*0x5588*/ "POISON!\n");
        ULTIMA_2fa6(param_1);
        break;
    case 2:
        ULTIMA_1850_PrintString(/*0x5591*/ "BOMB!\n");
        ULTIMA_2aa8();
        break;
    case 3:
        ULTIMA_1850_PrintString(/*0x5598*/ "GAS!\n");
        local_6a = 0;
        do
        {
            ULTIMA_2fa6(local_6a);
        } while (++local_6a < 6);
        break;
    }
}
