#include "common/common.h"
#include "vars.h"
#include "funcs.h"

#include <string.h>

#include "cast.h"
#include "cmds.h"
#include "combat.h"
#include "comsubs.h"
#include "sjog.h"
#include "zstats.h"

static void COMBAT_063e(void);
static int COMBAT_0d30(int a);
static int COMBAT_0ee4(int param_1);
static void COMBAT_1b1e(int param_1);
static void COMBAT_1c66(int param_1);

// NOT MATCHING
int COMBAT_0000(int param_1, int param_2, int param_3)
{
    byte bVar1;
    int local_8;

    if (param_2 > 0xa || param_3 > 0xa || param_2 < 0 || param_3 < 0)
    {
        // 0020
        return 1;
    }

    // 0026
    if (ULTIMA_2c4c(param_1, *ULTIMA_4402_GetTileAddr(param_2, param_3)) != 0 &&
        *ULTIMA_4402_GetTileAddr(param_2, param_3) != 0xff)
    {
        // 0043
        for (local_8 = 0; local_8 < 0x20; local_8++)
        {
            if (D_5c5a[local_8]._2_x == param_2 && D_5c5a[local_8]._3_y == param_3)
            {
                bVar1 = D_5c5a[local_8]._0_tile;
                if (bVar1 == 0xeb)
                {
                    return 0;
                }
                if ((bVar1 & 0xfc) != 0xe8 && bVar1 != 0x1e && bVar1 != 0x1f && bVar1 != 0)
                {
                    bVar1 = D_5c5a[local_8]._1;
                    if (bVar1 != 0)
                    {
                        return 0;
                    }
                }
            }
            else if (D_5c5a[local_8]._6 == param_2 && D_5c5a[local_8]._7 == param_3)
            {
                bVar1 = D_5c5a[local_8]._2_x;
                if ((bVar1 & 0x24) == 0)
                {
                    if (bVar1 != 0)
                    {
                        return 0;
                    }
                }
            }
        }
    }

    // -> 0020
    return 1;
}

// OK P1
static int COMBAT_014e(int param_1, int param_2, int param_3)
{
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    local_a = D_ba14[param_1]._3;
    local_4 = D_15cc[local_a];
    if (local_a != 0x1a && (int)ULTIMA_2092_RandomRange(0, 0xff) >= 0x80 || (D_153c[local_a] & 0x8000) != 0 && (D_587a == 'N' ||
        D_587a == 0x1c))
    {
        return 0;
    }
    else
    {
        ULTIMA_43ae_AudioSweepTone(0x2ee, 400, 5, 0x96); // S.E.?
        if (param_3 != 0)
        {
            local_6 = 0;
        }
        else
        {
            local_6 = COMBAT_14d6(param_2, param_1, -(int)D_588f, 0);
        }

        local_8 = COMSUBS_0822(param_1, D_ba14[param_2]._6, D_ba14[param_2]._7, local_6, local_4);
        if (local_8 >= 0)
        {
            ULTIMA_3564(local_8);
            ULTIMA_16ba_PrintChar(10);
            COMBAT_194a(local_8, param_1);
            COMSUBS_0312(local_8, param_1);
        }

        return 1;
    }
}

// OK P1
static int COMBAT_0226(int param_1)
{
    int local_c;
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    local_c = 0;
    local_a = D_ba14[param_1]._3;
    local_8 = D_ba14[param_1]._4;
    local_4 = COMBAT_0d30(param_1);
    if (local_4 < 0)
    {
        // 0256
        return 0;
    }

    // 025c
    local_6 = D_ba14[local_4]._3;

    if ((D_ba14[param_1]._2 & 1) != 0)
    {
        // 0278
        if (COMSUBS_04d4(param_1, local_4) == 1)
        {
            // 0286
            D_589d = 0x21;
            COMSUBS_0bf8(param_1, local_4, 0x21);
            // -> 035f
        }
        else
        {
            return 0;
        }
    }
    else
    {
        // 029c
        if ((D_ba14[local_4]._2 & 0x80) != 0 &&
            D_55a8_party[local_6]._1e == '-' &&
            (D_153c[local_a] & 0x8000) != 0)
        {
            local_c = ULTIMA_2092_RandomRange(0, 0xff) < 0x80;
        }

        // 02df
        if (COMSUBS_04d4(param_1, local_4) <= D_159c[local_a])
        {
            if (local_a == 0x1a)
            {
                D_5c5a[local_8]._6 = 0x20;
            }

            if (COMSUBS_04d4(param_1, local_4) == 1)
            {
                if (local_a == 0x2d)
                {
                    D_5c5a[local_8]._6 = 0x20;
                }

                ULTIMA_43ae_AudioSweepTone(0x2ee, 400, 5, 0x96);
                D_58a8[local_4] = param_1;
                if (COMBAT_14d6(local_4, param_1, -(uint)D_588f, 0) == 0)
                {
                    return 1;
                }

                if ((D_153c[local_a] & 2) != 0 && ULTIMA_2092_RandomRange(0, 3) != 0 && D_57a8 != 0)
                {
                    ULTIMA_1850_PrintString("\nA ");
                    COMSUBS_0094(param_1);
                    ULTIMA_1850_PrintString(" stole some food!\n");
                    ULTIMA_3f54(&D_57a8, 5);
                    ULTIMA_43ae_AudioSweepTone(800, 2000, 1, 0x32);
                    ULTIMA_2900_UpdateVitalsDisplay();
                    return 1;
                }

                ULTIMA_3564(local_4);
                ULTIMA_16ba_PrintChar(10);
                COMBAT_194a(local_4, param_1);
                COMSUBS_0312(local_4, param_1);
                return 1;
            }

            return COMBAT_014e(param_1, local_4, local_c);
        }
        else
        {
            return 0;
        }
    }

    return 1;
}

// OK P1
static void COMBAT_03f4(void)
{
    S_ba14* local_4;
    int local_6;

    local_4 = &D_ba14[D_589e];
    D_589d = 0;
    local_6 = local_4->_4;

    if (D_587a != 'T' &&
        (D_587a != 'Q' || ULTIMA_2092_RandomRange(0, 1) != 0) &&
        (local_4->_2 & 4) == 0)
    {
        // 0446
        if ((local_4->_2 & 8) != 0)
        {
            if (ULTIMA_2092_RandomRange(0, 0x10) == 0x10)
            {
                ULTIMA_6800(D_589e);
            }
        }
        else
        {
            if ((local_4->_3) == '-')
            {
                D_5c5a[local_6]._6 = 0;
            }

            // 047f
            if ((local_4->_2 & 2) != 0)
            {
                if ((local_4->_2 & 0x80) == 0 && ULTIMA_2092_RandomRange(0, 3) == 3)
                {
                    local_4->_0++;
                }

                COMBAT_1a5c(D_589e);
            }
            else
            {
                if (COMSUBS_00f4(D_589e) != 0)
                {
                    return;
                }

                if (COMBAT_0226(D_589e) != 0)
                {
                    return;
                }
            }

            // 04cb
            if (COMBAT_0ee4(D_589e) != 0)
            {
                if ((D_58a2 & 0x10) != 0)
                {
                    ULTIMA_16ba_PrintChar(10);
                    ULTIMA_43ae_AudioSweepTone(0x4b0, 2000, 1, 0x28);
                    COMSUBS_0094(D_589e);
                    ULTIMA_1850_PrintString(" escapes!\n");
                    COMBAT_1236(-(uint)D_589e - 1);

                    if ((local_4->_2 & 0x80) == 0 && local_4->_3 == '/')
                    {
                        SJOG_21ce();
                    }
                }
                ULTIMA_5910_UpdateFrame();
            }
            else
            {
                if ((local_4->_2 & 2) != 0)
                {
                    COMBAT_0226(D_589e);
                }
            }
        }
    }
}

// OK P1
static int COMBAT_0544(char* param_1, int param_2)
{
    ULTIMA_1850_PrintString(param_1);

    if ((D_ba14[D_589e]._2 & 0x80) != 0)
    {
        switch (param_2)
        {
        case 0:
            SJOG_18ce_GetCmd();
            break;
        case 1:
            SJOG_0d4a_JimmyCmd();
            break;
        case 2:
            SJOG_1374_OpenCmd();
            break;
        case 3:
            ZSTATS_1296_ReadyCmd();
            break;
        case 4:
            SJOG_095c_SearchCmd();
            break;
        case 5:
            CAST_1792_UseCmd();
        }
    }
    else
    {
        ULTIMA_1850_PrintString("Can't!\n");
        return 1;
    }

    return 0;
}

// NOT MATCHING
static int COMBAT_05b6(int param_1, int param_2)
{
    if (param_1 != 0xff && D_15fc[param_1] != 0)
    {
        if (param_2 != 0)
        {
            // OK
            strcat(D_b21e, ", ");
        }

        // 05fb: NOT MATCHING (register)
        strcat(D_b21e, D_17f6[param_1]);

        return 1;
    }
    else
    {
        return 0;
    }
}

// OK P1
// process combat command
static void COMBAT_063e(void)
{
    int local_c;
    int local_a;
    byte local_8;
    int local_6;
    int local_4;

#if !defined(TARGET_DOS16)
    local_8 = 0xff;
#endif

    D_5896_map_x = D_ba14[D_589e]._6;
    D_5897_map_y = D_ba14[D_589e]._7;
    local_a = D_ba14[D_589e]._3;

    if (D_587b != 0xff && ((D_ba14[D_589e]._2 & 0x80) == 0 || D_587b != local_a))
    {
        SJOG_2012();
    }
    else
    {
        if ((D_ba14[D_589e]._2 & 0x80) != 0 && (D_55a8_party[local_a]._1b == 0x23 || D_55a8_party[local_a]._1c == 0x23))
        {
            // a938
            D_ba14[D_589e]._2 |= 1;
            D_587b = 0xff;
            D_a9fa = 1;
            COMBAT_03f4();
            // -> ae09
        }
        else
        {
            // a958
            if ((D_ba14[D_589e]._2 & 0x80) != 0)
            {
                ULTIMA_2a28(D_ba14[D_589e]._3);
            }

            // a972
            if (D_a9fa != 0)
            {
                ULTIMA_2900_UpdateVitalsDisplay();
                D_a9fa = 0;
            }

            // a981
            do
            {
                ULTIMA_16ba_PrintChar(10);
                COMSUBS_0094(D_589e);
                D_b21e[0] = 0;
                if ((D_ba14[D_589e]._2 & 0x80) != 0)
                {
                    ULTIMA_1850_PrintString(", armed with ");
                    local_c = COMBAT_05b6(D_55a8_party[local_a]._19, 0);
                    local_c += COMBAT_05b6(D_55a8_party[local_a]._1b, local_c);
                    local_c += COMBAT_05b6(D_55a8_party[local_a]._1c, local_c);
                    if (local_c == 0)
                    {
                        strcat(D_b21e, "bare hands");
                    }
                }

                strcat(D_b21e, ":");
                ULTIMA_1850_PrintString(D_b21e);

                local_6 = local_4 = 0;

                // aa4a
                while (!local_6)
                {
                    ULTIMA_16ba_PrintChar(10);
                    ULTIMA_4c2a();
                    if ((D_ba14[D_589e]._2 & 4) != 0)
                    {
                        ULTIMA_1850_PrintString("ARGH!\n");
                        ULTIMA_223c_AudioWhiteNoise(0x28, 3000, 500);
                        COMBAT_1c66(D_589e);
                        local_6 = 1;
                    }
                    else if ((D_ba14[D_589e]._2 & 8) != 0)
                    {
                        // TODO: random_range returns signed int?
                        if ((signed)ULTIMA_2092_RandomRange(0, 0xff) < 0x10)
                        {
                            ULTIMA_6800(D_589e);
                        }
                        ULTIMA_1850_PrintString("Zzzzz...\n");
                        local_6 = 1;
                    }
                    else
                    {
                        local_8 = ULTIMA_266c_GetChar();
                        local_6 = 1;
                        local_4 = 0;

                        switch (local_8)
                        {
                        case 0xfc: // ok
                            // Buffer on/off
                            // ab1a
                            ULTIMA_1850_PrintString("Buffer O");
                            D_538c = !D_538c;
                            if (D_538c != 0)
                            {
                                ULTIMA_1850_PrintString("ff\n");
                            }
                            else
                            {
                                ULTIMA_1850_PrintString("n\n");
                            }
                            // ab3d
                            local_6 = 0;
                            break;

                        case 0x13: // ok
                            // ab46
                            ULTIMA_1850_PrintString("Sound ");
                            if (D_a9ce != 0)
                            {
                                ULTIMA_1850_PrintString("Off\n");
                            }
                            else
                            {
                                ULTIMA_1850_PrintString("On\n");
                            }
                            D_a9ce = !D_a9ce;
                            // -> ab3d
                            local_6 = 0;
                            break;

                        case 0x41:
                            /* 'A' Attack */
                            // ab70
                            COMSUBS_0d96(D_589e, local_c);
                            break;

                        case 0x43: // ok
                            /* 'C' Cast */
                            // ab80 / 08f0
                            ULTIMA_1850_PrintString("Cast...\n");
                            local_4 = 1;
                            if ((D_ba14[D_589e]._2 & 0x80) != 0)
                            {
                                if (COMSUBS_09fc(D_589e) == 0)
                                {
                                    // abab / 091b
                                    D_588f = D_5890 = 1;
                                    local_4 = 0;
                                    if (D_587a == 'N' || (D_57b4 == 0 && D_5894 == 0x12))
                                    {
                                        ULTIMA_1850_PrintString("Absorbed!\n");
                                        ULTIMA_2192_AudioPulse(0x2648, 1, 28000, 1000, 2);
                                    }
                                    else
                                    {
                                        CAST_0dba_CastSpellCmd();
                                    }
                                }
                            }
                            else
                            {
                                // abf4
                                ULTIMA_1850_PrintString("Can't!\n");
                            }
                            break;

                        case 0x47:
                            /* 'G' Get */
                            // abfa
                            local_4 = COMBAT_0544("Get-", 0);
                            break;

                        case 0x4a: // ok
                            /* 'J' Jimmy */
                            // ac0a
                            local_4 = COMBAT_0544("Jimmy-", 1);
                            break;

                        case 0x4b:
                            /* 'K' Klimb */
                            // ac14
                            if (SJOG_1d6a_Klimb() == 0)
                            {
                                // -> ab3d
                                local_6 = 0;
                            }
                            break;

                        case 0x4f:
                            /* 'O' Open */
                            // ac1a
                            local_4 = COMBAT_0544("Open-", 2);
                            break;

                        case 0x50:
                            /* 'P' Push */
                            // ac24
                            ULTIMA_1850_PrintString("Push-");
                            CMDS_161a_PushCmd();
                            break;

                        case 0x52:
                            /* 'R' Ready */
                            // ac32
                            local_4 = COMBAT_0544("Ready...\n\n", 3);
                            break;

                        case 0x53: // ok
                            /* 'S' Search */
                            // ac3c
                            local_4 = COMBAT_0544("Search-", 4);
                            break;

                        case 0x55: // ok
                            // ac46
                            local_4 = COMBAT_0544("Use item\n\n", 5);
                            break;

                        case 0x59: // ok
                            /* 'Y' Yell */
                            // ac50
                            ULTIMA_1850_PrintString("Yell ");
                            CMDS_1418_YellCmd();
                            break;

                        case 0x5a: // ok
                            /* 'Z' Z-stats */
                            // ac5e
                            ULTIMA_1850_PrintString("Z-stats...\n");
                            ZSTATS_0a3a_ZstatsCmd();
                            break;

                        case 0x1b:
                            // ac6c
                            local_4 = CMDS_17ec_Escape();
                            break;

                        case 0x20: // ok
                            // ac72
                            ULTIMA_1850_PrintString("Pass\n");
                            break;
                        case 0x30: // ok
                            /* '0' */
                            // ac7c
                            D_587b = 0xff;
                            ULTIMA_1850_PrintString("Set active plr:\nNone!\n");
                            ULTIMA_2900_UpdateVitalsDisplay();
                            break;

                        case 0x31:
                        case 0x32:
                        case 0x33:
                        case 0x34:
                        case 0x35:
                        case 0x36:
                            /* '1' .. '6' */
                            // ac8e
                            if (SJOG_1f7a(local_8 - 0x31) == 0)
                            {
                                // -> acd1
                                local_4 = 1;
                            }
                            break;

                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            // aca4
                            if (SJOG_1c56(D_589e, local_8) == 0)
                            {
                                local_6 = 0;
                            }
                            break;

                        case 0x42:
                            /* 'B' Board */
                            // acbc
                            local_4 = SJOG_1f26("Board", 1);
                            break;

                        case 0x44:
                            /* 'D' What? */
                            // acca
                            ULTIMA_1850_PrintString("D-What?\n");
                            local_4 = 1;
                            break;

                        case 0x45: // ok
                            /* 'E' Enter */
                            // acda / 0a4a
                            local_4 = SJOG_1f26("Enter", 2);
                            break;

                        case 0x46: // ok
                            /* 'F' Fire */
                            // ace4 / 0a54
                            local_4 = SJOG_1f26("Fire", 2);
                            break;

                        case 0x48: // ok
                            /* 'H' Hole up */
                            // acea / 0a5a
                            local_4 = SJOG_1f26("Hole up", 2);
                            break;

                        case 0x49: // ok
                            /* 'I' Ignite torch */
                            // acf0 / 0a60
                            local_4 = SJOG_1f26("Ignite torch", 2);
                            break;

                        case 0x4c: // ok
                            /* 'L' Look */
                            // acf6 /  0a66
                            local_4 = SJOG_1f26("Look", 2);
                            break;

                        case 0x4d: // ok
                            /* 'M' Mix */
                            // acfc / 0a6c
                            local_4 = SJOG_1f26("Mix", 2);
                            break;

                        case 0x4e: // ok
                            /* 'N' New order */
                            // ad02 / 0a72
                            local_4 = SJOG_1f26("New order", 2);
                            break;

                        case 0x51: // ok
                            /* 'Q' Quit */
                            // ad08 / 0a78
                            local_4 = SJOG_1f26("Quit", 2);
                            break;

                        case 0x54: // ok
                            /* 'T' Talk */
                            // ad0e
                            local_4 = SJOG_1f26("Talk", 3);
                            break;

                        case 0x56: // ok
                            /* 'V' View */
                            // ad18
                            local_4 = SJOG_1f26("View", 2);
                            break;

                        case 0x57: // ok
                            /* 'W' What */
                            // ad1e
                            ULTIMA_1850_PrintString("W-What?\n");
                            local_4 = 1;
                            break;

                        case 0x58: // ok
                            /* 'X' X-it */
                            // ad24
                            local_4 = SJOG_1f26("X-it", 1);
                            break;

                        default:
                            // ad47
                            // -> ab39
                            ULTIMA_1850_PrintString("What?\n");
                            local_6 = 0;
                            break;
                        }
                    }
                }
                // ade6
            } while (local_4 != 0); // -> a981

            // adef
            if ((D_ba14[D_589e]._2 & 0x80) != 0)
            {
                ULTIMA_2a28(D_ba14[D_589e]._3);
            }
        }

        // ae09
        if (local_8 < 0x30 || local_8 > 0x36)
        {
            SJOG_2012();
            ULTIMA_5910_UpdateFrame();
            SJOG_1ea4();
        }
    }
}

// NOT MATCHING
int COMBAT_0b94(void)
{
    byte bVar2;
    byte bVar3;
    uint local_a;
    undefined2 local_4;

    local_4 = 1;
    D_58a0 = 0;

    ULTIMA_5910_UpdateFrame();
    ULTIMA_2900_UpdateVitalsDisplay();
    ULTIMA_1b16_ClearKbdBuffer();
    SJOG_1b6c();

    if (D_5876 == 0)
    {
        D_58a3 = 1;
    }
    else
    {
        D_58a3 = 0;
    }

    local_a = 0;
    do
    {
        for (D_589e = 0; D_589e < 0x20; D_589e++)
        {
            D_594f = 0;
            bVar3 = D_ba14[D_589e]._2;

            if ((bVar3 & 0xc0) != 0 && (bVar3 & 0x20) == 0)
            {
                if ((bVar3 & 0x80) == 0 || D_55a8_party[D_ba14[D_589e]._3]._b != 'D')
                {
                    if ((D_ad14[D_ba14[D_589e]._7 * 0x20 + D_ba14[D_589e]._6] & 0xfe) != 0x84)
                    {
                        if (--D_ba14[D_589e]._5 == 0)
                        {
                            D_ba14[D_589e]._5 = 36 - D_ba14[D_589e]._1;
                            D_5898 = 0;
                            D_58a2 = 0;
                            D_588f = 0;
                            D_5890 = 0;
                            D_589d = 0;
                            D_5882++;
                            if (D_5882 == 10)
                            {
                                D_5882 = 0;
                                ULTIMA_4f7c(1);
                            }
                            D_589f = 1;
                            if (ULTIMA_5646(D_589e) == 0) {
                                COMBAT_063e();
                            }
                            else {
                                COMBAT_03f4();
                            }
                            bVar2 = D_589e;
                            D_58a8[bVar2] = 0xff;
                            COMBAT_1b1e((uint)bVar2);
                            SJOG_1b6c();
                            if (D_5878 == 0)
                            {
                                if (D_5876 == 0)
                                {
                                    local_4 = 0;
                                }
                                else
                                {
                                    if (SJOG_21ce() != -1)
                                    {
                                        D_589e++;
                                        continue;
                                    }
                                    ULTIMA_5910_UpdateFrame();
                                    if (D_58a3 == 0)
                                    {
                                        ULTIMA_1850_PrintString("\nBATTLE IS LOST!");
                                        local_4 = 1;
                                    }
                                }
                                local_a = 1;
                                break;
                            }
                            if (D_5876 == 0 && D_58a3 == 0)
                            {
                                ULTIMA_1850_PrintString("\nVICTORY!\n");
                                D_58a3 = 1;
                                ULTIMA_4368_AudioSomething();
                                ULTIMA_1b16_ClearKbdBuffer();
                            }
                        }
                    }
                }
                else
                {
                    D_ba14[D_589e]._2 |= 0x20;
                    ULTIMA_3564(D_589e);
                    local_a = (uint)D_589e;
                    COMBAT_1574(local_a, 99);
                }
            }
        }

        if (local_a != 0)
        {
            ULTIMA_1b16_ClearKbdBuffer();
            D_2186 = 0xff;
            return local_4;
        }
    } while (1);
}

// NOT MATCHING
static int COMBAT_0d30(int param_1)
{
    int iVar4;
    int iVar5;
    int local_16;
    uint local_12;
    int local_10;
    uint local_e;
    int local_8;
    int local_4;

    local_10 = -1;
    local_16 = -1;
    local_4 = 99;

    local_8 = ULTIMA_5646(param_1);
    if (D_587a == 67)
    {
        iVar4 = COMBAT_13e2(param_1, -1);
        if (iVar4 < ULTIMA_3abe())
        {
            local_8 = 0;
        }
    }

    for (iVar4 = 0x1f; iVar4 >= 0; iVar4--)
    {
        if (iVar4 != param_1 && D_ba14[iVar4]._2 != '\0' && (D_ba14[iVar4]._2 & 0x20) == 0 && local_8 != ULTIMA_5646(iVar4) &&
            ((D_5894 == '(' || D_ba14[param_1]._3 == '/' || (D_ba14[iVar4]._2 & 0x10) == 0) && (D_ba14[iVar4]._2 & 4) == 0))
        {
            if (iVar4 < 5)
            {
                local_10 = local_10 + 1;
            }

            iVar5 = COMSUBS_048a(D_ba14[iVar4]._7, D_ba14[iVar4]._6, D_ba14[param_1]._7, D_ba14[param_1]._6);
            if (iVar5 < local_4)
            {
                local_e = D_ba14[iVar4]._6;
                local_12 = D_ba14[iVar4]._7;
                local_16 = iVar4;
                local_4 = iVar5;
            }
        }
    }

    if (local_10 == -1 && local_16 == -1)
    {
        local_16 = SJOG_21ce();
    }

    if (local_16 == -1)
    {
        for (iVar4 = 0x1f; iVar4 > 5; iVar4--)
        {
            if ((D_ba14[iVar4]._2 & 0x40) != 0)
            {
                D_ba14[iVar4]._0 = 1;
                D_ba14[iVar4]._2 |= 2;
            }
        }

        local_e = 5;
        local_12 = 5;
    }

    D_5878 = 0;
    D_5876 = 0;

    if (local_e < D_ba14[param_1]._6)
    {
        D_5876 = -1;
    }
    if (D_ba14[param_1]._6 < local_e)
    {
        D_5876 = 1;
    }
    if (local_12 < D_ba14[param_1]._7)
    {
        D_5878 = -1;
    }
    if (D_ba14[param_1]._7 < local_12)
    {
        D_5878 = 1;
    }
    if ((D_ba14[param_1]._2 & 2) != 0)
    {
        D_5876 = -D_5876;
        D_5878 = -D_5878;
    }
    if (local_16 == param_1)
    {
        local_16 = -1;
    }
    return local_16;
}

// NOT MATCHING
static int COMBAT_0ee4(int param_1)
{
    int local_a;
    int local_8;
    int local_6;
    S_ba14* local_4;

    local_8 = 0;
    local_6 = 0;
    local_4 = &D_ba14[param_1];

    if (local_4->_3 != 0x1b && local_4->_3 != 0x1a)
    {
        // 0f17
        if ((local_4->_2 & 0x80) == 0 && (D_153c[local_4->_3] & 0x2000) != 0 && D_587a != 0x4e && D_587a != 0x1c &&
            (SJOG_2148(param_1) != 0 || ULTIMA_3aae_Random(3) != 3) && COMBAT_120e() != 0)
        {
            if (COMBAT_0000(D_5c5a[local_4->_4]._0_tile, D_5876, D_5878) != 0)
            {
                D_5c5a[local_4->_4]._2_x = local_4->_6 = D_5876;
                D_5c5a[local_4->_4]._3_y = local_4->_7 = D_5878;

                ULTIMA_1850_PrintString(D_1856[local_4->_3]);
                ULTIMA_1850_PrintString(" teleports!\n");
                local_8++;
            }
        }

        // 0fab
        if (local_8 == 0 && SJOG_2148(param_1) == 0)
        {
            // 0fc1
            local_a = COMBAT_0d30(param_1);
            if (ULTIMA_3aae_Random(0xff) > 0x7f && SJOG_20d8(local_4->_6 + D_5876, local_4->_7, param_1) == 0)
            {
                D_5878 = 0;
                local_6 = 999;
            }
            else
            {
                if (SJOG_20d8(local_4->_6, local_4->_7 + D_5878, param_1) == 0)
                {
                    D_5876 = 0;
                    local_6 = 998;
                }
            }

            if (local_6 < 990)
            {
                // 1030
                local_6 = 0;
                for (local_8 = 4; local_8 > 0; local_8--)
                {
                    local_6 = ULTIMA_3aae_Random(3);
                    switch (local_6)
                    {
                    case 0:
                        D_5878 = 1;
                        D_5876 = 0;
                        break;
                    case 1:
                        D_5876 = 1;
                        D_5878 = 0;
                        break;
                    case 2:
                        D_5878 = -1;
                        D_5876 = 0;
                        break;
                    case 3:
                        D_5876 = -1;
                        D_5878 = 0;
                        break;
                    }

                    // 1070
                    if (SJOG_20d8(local_4->_6 + D_5876, local_4->_7 + D_5878, param_1) == 0)
                    {
                        local_6 = 991;
                    }

                    if (local_6 > 990)
                        break;

                    
                    D_5876 = D_5878 = 0;
                }
            }

            // 10c7 (??)
            if (local_6 != 0)
            {
                // si = D_5c5a[local_4->_4];

                local_4->_6 += D_5876;
                D_5c5a[local_4->_4]._2_x = local_4->_6;

                local_4->_7 += D_5878;
                D_5c5a[local_4->_4]._3_y = local_4->_7;

                local_8 = 1;

                if (ULTIMA_6d82(local_4->_6, local_4->_7) == 0)
                {
                    D_58a2 = 0x10;
                }
            }
        }
    }

    return local_8;
}

// NOT MATCHING
int COMBAT_111a(uint param_1, uint param_2)
{
    int iVar1;
    byte* pbVar2;
    byte* pbVar3;
    undefined1* local_12;
    int local_10;
    byte* local_c;
    byte* local_a;
    byte* local_8;
    byte* local_6;

    local_10 = 0;

    if ((D_58a1 & 0x80) != 0 || (D_58a1 & 2) != 0)
    {
        pbVar2 = D_ad14 + 0x10b;
        pbVar3 = D_ad14 + 0x113;
        local_12 = D_ad14 + 0xb;
        local_6 = D_ad14 + 0x12b;
        local_a = D_ad14 + 0x133;
        local_8 = D_ad14 + 0x14b;
        local_c = D_ad14 + 0x153;

        for (iVar1 = 8; (iVar1 != 0); iVar1--)
        {
            if (*pbVar2 == param_1 && *pbVar3 == param_2)
            {
                *pbVar3 = 0xff;
                *pbVar2 = 0xff;

                if (*local_6 < 0xb && *local_a < 0xb)
                {
                    D_ad14[(uint)*local_a * 0x20 + (uint)*local_6] = *local_12;
                }

                if (*local_8 < 0xb && *local_c < 0xb)
                {
                    D_ad14[(uint)*local_c * 0x20 + (uint)*local_8] = *local_12;
                }
                local_10 = 1;
            }

            pbVar2++;
            pbVar3++;
            local_12++;
            local_6++;
            local_a++;
            local_8++;
            local_c++;
        }

        if (local_10 != 0)
        {
            ULTIMA_5910_UpdateFrame();
        }
    }

    return local_10;
}

// OK P1
int COMBAT_120e(void)
{
    D_5876 = ULTIMA_3aae_Random(0xf);
    D_5878 = ULTIMA_3aae_Random(0xf);

    if (D_5876 > 0xa || D_5878 > 0xa)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// OK P1
void COMBAT_1236(int param_1)
{
    S_ba14* local_4;
    int local_6;

    if (param_1 < 0)
    {
        param_1 *= -1;
        param_1--;
        local_4 = &D_ba14[param_1]; // [-param_1 - 1]
        local_6 = local_4->_4;

        local_4->_0 = local_4->_1 = local_4->_4 = 0;
        local_4->_2 = local_4->_5 = local_4->_6 = local_4->_7 = 0;
    }
    else
    {
        local_6 = param_1 - 1;
    }

    D_5c5a[local_6]._3_y =
        D_5c5a[local_6]._4_z =
        D_5c5a[local_6]._5 =
        D_5c5a[local_6]._0_tile =
        D_5c5a[local_6]._1 =
        D_5c5a[local_6]._2_x = 0;
}

// NOT MATCHING
static uint COMBAT_12b0(int param_1, int param_2)
{
    char cVar1;
    uint uVar2;
    int iVar3;
    uint local_8;
    uint local_6;

    if ((D_ba14[param_1]._2 & 0x40) == 0)
    {
        uVar2 = (uint)D_589d;
        if (uVar2 == 0x27)
        {
            ULTIMA_1850_PrintString("Thy sword hath shattered!\n");
            ULTIMA_6e60(param_1, 0x27);
            local_8 = 99;
        }
        else if (uVar2 == 0x28)
        {
            local_8 = 0;
        }
        else if (uVar2 == 0xff)
        {
            local_8 = 1;
        }
        else
        {
            local_8 = D_15fc[uVar2];
            if (1 < D_15fc[uVar2] && local_8 != 99)
            {
                local_8 = ULTIMA_2092_RandomRange(1, local_8);
            }
        }
    }
    else
    {
        local_8 = D_13bc[D_ba14[param_1]._3]._4;
    }

    if (local_8 == 99)
    {
        local_6 = 99;
    }
    else
    {
        if ((D_ba14[param_2]._2 & 0x40) == 0)
        {
            cVar1 = D_55a8_party[D_ba14[param_2]._3]._18;
        }
        else
        {
            cVar1 = D_13bc[D_ba14[param_2]._3]._3;
        }

        local_6 = local_8;
        if (cVar1 != 0)
        {
            iVar3 = ULTIMA_2092_RandomRange(1, cVar1);
            local_6 = local_8 - iVar3;
        }
    }

    return local_6;
}

// OK P1
static int COMBAT_139a(int param_1)
{
    if (D_587a == 'T' && (D_ba14[param_1]._2 & 0x40) != 0)
    {
        return 1;
    }

    if (D_ba14[param_1]._3 == 0x1a)
    {
        return 1;
    }

    if ((D_ba14[param_1]._2 & 8) != 0)
    {
        return 1;
    }

    return D_ba14[param_1]._1;
}

// OK P1
int COMBAT_13e2(int param_1, int param_2)
{
    S_ba14* local_4 = &D_ba14[param_1];
    int local_6;

    if ((local_4->_2 & 0x40) != 0)
    {
        if (param_2 == 0)
        {
            if ((D_153c[local_4->_3] & 0x80) != 0)
            {
                // 1411
                param_2 = -3;
            }
            else
            {
                // -> 1428
                param_2 = -2;
            }
        }
    }
    else
    {
        // 1418
        if (param_2 > 0)
        {
            if (D_169c[param_2] == 8) // TODO: offset? (+1?)
            {
                // -> 1411
                param_2 = -3;
            }
            else
            {
                // 1428
                param_2 = -2;
            }
        }
    }

    // 142d
    switch (param_2)
    {
    case -1:
        // 1444
        if ((local_4->_2 & 0x40) != 0)
        {
            local_6 = D_13bc[local_4->_3]._2;
        }
        else
        {
            // 145e
            local_6 = D_55a8_party[local_4->_3]._e;
        }

        return local_6;

    case -2:
        // 1478
        local_6 = COMBAT_139a(param_1);

        return local_6;

    case -3:
        // 1480
        if ((local_4->_2 & 0x40) != 0)
        {
            local_6 = D_13bc[local_4->_3]._0;
        }
        else
        {
            local_6 = D_55a8_party[local_4->_3]._c;
        }

        return local_6;

    case -4:
        // 14aa
        if ((local_4->_2 & 0x40) != 0)
        {
            local_6 = D_13bc[local_4->_3]._3;
        }
        else
        {
            local_6 = ULTIMA_6da8((local_4->_3));
        }

        return local_6;
    }

    // sic
}

// OK P1
int COMBAT_14d6(int param_1, int param_2, int param_3, int param_4)
{
    int local_a;
    int local_8;
    int local_6;
    int local_4;
    SET_UNINITIALIZED_16(local_8);

    local_a = -1;
    local_6 = 0;

    if (D_588f != 0)
    {
        if (param_4 > 0x29 && param_4 < 0x32 || param_4 == 0x33)
        {
            local_6 = 1;
        }
        else
        {
            local_8 = local_a = -1;
        }
    }
    else
    {
        // 1512
        if (param_4 == 0x27 || param_4 == 0x23 || param_4 == 0x28)
        {
            local_6 = 1;
        }
        else
        {
            local_8 = -2;
            local_a = param_4;
        }
    }

    // 152f
    if (local_6 == 0)
    {
        CHECK_UNINITIALIZED_16(local_8);
        local_8 = COMBAT_13e2(param_1, local_8);
        local_a = COMBAT_13e2(param_2, local_a);
        local_4 = ((local_8 - local_a) + 0x1e) / 2;
        if (local_4 <= ULTIMA_3abe())
        {
            local_6 = 1;
        }
    }

    return local_6;
}

// NOT MATCHING
int COMBAT_1574(int param_1, int param_2)
{
    byte bVar5;
    byte bVar6;
    char cVar7;
    uint uVar10;
    uint uVar11;
    int iVar14;
    int local_c;

    cVar7 = 0;

    if (param_2 < 1)
    {
        D_58a2 = 0x20;
        param_2 = 0;
    }

    if ((D_ba14[param_1]._2 & 0x80) == 0)
    {
        if ((((byte)D_153c[D_ba14[param_1]._3]) & 0x20) != 0 && D_5890 == 0)
        {
            param_2 /= 2;
        }

        if ((((byte)D_153c[D_ba14[param_1]._3]) & 8) != 0)
        {
            param_2 = 0;
        }

        if (D_ba14[param_1]._0 < param_2)
        {
            D_ba14[param_1]._0 = 0;
        }
        else
        {
            D_ba14[param_1]._0 -= (char)param_2;
        }

        if (D_ba14[param_1]._0 == 0 || param_2 == 99)
        {
            cVar7 = (D_13bc[D_ba14[param_1]._3]._5 >> 2) + 1;
            bVar5 = D_13bc[D_ba14[param_1]._3]._7;

            D_ba14[param_1]._2 = 0x20;

            D_ba14[param_1]._0 = 0;
            uVar10 = D_ba14[param_1]._6;
            uVar11 = D_ba14[param_1]._7;
            bVar6 = D_ad14[uVar11 * 0x20 + uVar10];

            if ((D_153c[D_ba14[param_1]._3] & 0x1001) == 0)
            {
                if (D_ba14[param_1]._3 == '\x1c')
                {
                    D_5c5a[D_ba14[param_1]._4]._1 = 0x1f;
                    D_5c5a[D_ba14[param_1]._4]._0_tile = 0x1f;
                    ULTIMA_6506(0x1f, 0, uVar10, uVar11, D_5895_map_level);
                    ULTIMA_5910_UpdateFrame();
                    return cVar7;
                }
                if (D_ba14[param_1]._3 == '\x1e')
                {
                    *ULTIMA_4402_GetTileAddr(uVar10, uVar11) = 0x4c;
                }
                else if (bVar6 != 0x87 && 3 < bVar6)
                {
                    if ((int)(uint)bVar5 < ULTIMA_3abe())
                    {
                        D_5c5a[D_ba14[param_1]._4]._1 = 0x1f;
                        D_5c5a[D_ba14[param_1]._4]._0_tile = 0x1f;
                        return cVar7;
                    }

                    D_5c5a[D_ba14[param_1]._4]._1 = 1;
                    D_5c5a[D_ba14[param_1]._4]._0_tile = 1;
                    D_5c5a[D_ba14[param_1]._4]._5 = bVar5;

                    if ((int)(uint)bVar5 <= ULTIMA_3abe())
                    {
                        return cVar7;
                    }

                    D_5c5a[D_ba14[param_1]._4]._5 |= 0x80;

                    return cVar7;
                }
                param_1 = -(param_1 + 1);
            }
            else
            {
                if ((D_153c[D_ba14[param_1]._3] & 0x1000) != 0)
                {
                    ULTIMA_1850_PrintString(D_1856[D_ba14[param_1]._3]);
                    ULTIMA_1850_PrintString(" vanishes!");
                    D_58a2 = 2;
                    D_5c5a[D_ba14[param_1]._4]._1 = 0x16;
                    D_5c5a[D_ba14[param_1]._4]._0_tile = 0x16;
                    ULTIMA_1068(D_ad14[D_ba14[param_1]._7 * 0x20 + D_ba14[param_1]._6], D_ba14[param_1]._6, D_ba14[param_1]._7);
                    COMBAT_1236(-(param_1 + 1));
                    SJOG_21ce();
                    return cVar7;
                }
                param_1 = -(param_1 + 1);
            }

            COMBAT_1236(param_1);
        }
        else if ((D_153c[D_ba14[param_1]._3] & 0x10) != 0)
        {
            for (local_c = 0; local_c < 8; local_c++)
            {
                COMSUBS_07d4(D_ba14[param_1]._6, D_ba14[param_1]._7);

                if (COMBAT_0000(D_5c5a[D_ba14[param_1]._4]._0_tile, D_5876, D_5878) != 0)
                {
                    iVar14 = ULTIMA_6506((D_5c5a[D_ba14[param_1]._4]._0_tile - 0x40) >> 2, 0, D_5876, D_5878, D_5895_map_level);
                    if (iVar14 >= 0)
                    {
                        D_ba14[iVar14]._0 = D_ba14[param_1]._0;
                        ULTIMA_1850_PrintString(D_1856[D_ba14[param_1]._3]);
                        ULTIMA_1850_PrintString(" divides!\n");
                        return 0;
                    }
                }
            }
        }
    }
    else
    {
        D_55a8_party[D_ba14[param_1]._3]._10 -= param_2;
        if (D_55a8_party[D_ba14[param_1]._3]._10 < 1 || param_2 == 99)
        {
            D_55a8_party[D_ba14[param_1]._3]._10 = 0;
            D_ba14[param_1]._2 |= 0x20;
            D_55a8_party[D_ba14[param_1]._3]._b = 0x44;

            D_5c5a[D_ba14[param_1]._4]._1 = 0x1e;
            D_5c5a[D_ba14[param_1]._4]._0_tile = 0x1e;
            if (D_ba14[param_1]._3 == D_587b)
            {
                D_587b = 0xff;
            }
        }

        ULTIMA_2900_UpdateVitalsDisplay();
    }

    return cVar7;
}

// OK P1
void COMBAT_18ba(int param_1, int param_2)
{
    int local_4;

    if ((D_ba14[param_1]._2 & 0x80) != 0 && D_55a8_party[D_ba14[param_1]._3]._b == 'G')
    {
        D_55a8_party[D_ba14[param_1]._3]._b = 0x50;
        ULTIMA_1850_PrintString(D_55a8_party[D_ba14[param_1]._3]._0);
        ULTIMA_1850_PrintString(" is poisoned!\n");
        D_58a2 = 8;
        D_a9fa = 1;
    }
    else
    {
        local_4 = COMBAT_1574(param_1, ULTIMA_3aae_Random(0x14));
        if (param_2 > -1 && (D_ba14[param_2]._2 & 0x80) != 0)
        {
            ULTIMA_3f14(&D_55a8_party[D_ba14[param_2]._3]._14, local_4, 9999);
        }
    }
}

// OK P1
void COMBAT_194a(int param_1, int param_2)
{
    int local_4;
    int local_8;
    int local_6;

    local_6 = 0;
    if ((D_ba14[param_2]._2 & 0x80) == 0)
    {
        local_6 = 1;
    }

    // 1969
    if (local_6 && (D_153c[D_ba14[param_2]._3] & 0x204) != 0 && ULTIMA_2092_RandomRange(0, 3) != 0)
    {
        COMBAT_18ba(param_1, param_2);
    }
    else
    {
        // 19a0
        local_4 = 0;
        if (local_6 && D_ba14[param_2]._3 == 0x1c && (D_ba14[param_1]._2 & 8) == 0)
        {
            ULTIMA_68ae(param_1);
            local_4 = 1;
        }

        // 19d0
        if (local_4)
        {
            // -> 1a54
            return;
        }

        if (D_5890 != 0 && D_589d == 52)
        {
            ULTIMA_68ae(param_1);
            // -> 1a54
            return;
        }

        // 19ee
        if (D_5890 == 0 || D_589d != 51)
        {
            // 19fc
            local_8 = COMBAT_12b0(param_2, param_1);
            if (local_8 < 0 && (D_ba14[param_1]._2 & 0x80) != 0)
            {
                D_58a2 = 0x20;
                return; // -> 1a54
            }

            // 1a22
            local_8 = COMBAT_1574(param_1, local_8);
            if ((D_ba14[param_2]._2 & 0x80) != 0)
            {
                // 1a3c
                ULTIMA_3f14(&D_55a8_party[D_ba14[param_2]._3]._14, local_8, 9999);
            }
        }
    }
}

// NOT MATCHING
int COMBAT_1a5c(int param_1)
{
    int local_a;
    int local_8;
    int local_6;
    S_ba14* local_4;

    local_8 = 0;
    local_6 = 0;
    local_4 = &D_ba14[param_1];

    if ((local_4->_2 & 0x80) != 0)
    {
        // 1a81
        return; // sic (IBM: returns &D_ba14[param_1], FMT: returns D_ba14[param_1]._2)
    }
    else
    {
        // 1a84
        local_a = D_13bc[local_4->_3]._5 / 4;
        if (local_4->_0 < local_a)
        {
            local_6 = 1;
            // 1aa9
            local_8 = 1;
        }
        else
        {
            // 1ab0 (NOT MATCHING)
            local_a *= 2;
            if (local_4->_0 < local_a)
            {
                local_6 = 2;
                local_a = ULTIMA_3aae_Random(0x100);
                if (local_a > 0xfb)
                {
                    local_8 = 1;
                }
            }
            else
            {
                // 1ad2 (NOT MATCHING)
                local_a = (local_a / 2) * 3;
                if (local_4->_0 < local_a)
                {
                    local_6 = 3;
                }
                else
                {
                    local_6 = 4;
                }
            }
        }

        if (local_8)
        {
            local_4->_2 |= 2;
        }
        else
        {
            local_4->_2 &= 0xfd;
        }

        return local_6;
    }
}

// OK P1
static void COMBAT_1b1e(int param_1)
{
    int local_4;
    int local_8;
    int local_a;
    S_ba14* local_6;

    local_a = 0;
    local_6 = &D_ba14[param_1];
    local_4 = D_ad14[local_6->_6 + local_6->_7 * 0x20];
    if (local_4 == 0x8f || local_4 == 0xbc)
    {
        local_a = 100;
    }

    if (local_4 == 4)
    {
        local_a = 50;
    }

    // 1b6f
    if (local_a == 0)
    {
        for (local_8 = 0; local_8 < 0x20; local_8++)
        {
            if (local_8 != local_6->_4 &&
                local_6->_6 == D_5c5a[local_8]._2_x &&
                local_6->_7 == D_5c5a[local_8]._3_y)
            {
                if (D_5c5a[local_8]._0_tile == 0xea)
                {
                    local_a = 100;
                }

                if (D_5c5a[local_8]._0_tile == 0xe8)
                {
                    local_a = 50;
                }

                if (D_5c5a[local_8]._0_tile == 0xe9)
                {
                    local_a = 150;
                }

                if (local_a != 0)
                    break;
            }
        }
    }

    // 1bdd
    switch (local_a)
    {
    case 150:
        // 1c0c
        ULTIMA_68ae(param_1);
        break;

    case 100:
        // 1c14
        ULTIMA_3564(param_1);
        COMBAT_1574(param_1, ULTIMA_3aae_Random(10));
        COMSUBS_0312(param_1, 0xff);
        D_a9fa = 1;
        break;

    case 50:
        // 1c3a
        if (D_5c5a[local_6->_4]._0_tile < 0x80)
        {
            COMBAT_18ba(param_1, -1);
            ULTIMA_3564(param_1);
        }
        break;
    }
}

// OK P1
static void COMBAT_1c66(int param_1)
{
    if (ULTIMA_3abe() < D_ba14[param_1]._1)
    {
        if ((D_ba14[param_1]._2 & 0x80) != 0)
        {
            ULTIMA_1850_PrintString(D_55a8_party[D_ba14[param_1]._3]._0);
        }
        else
        {
            ULTIMA_1850_PrintString(D_1856[D_ba14[param_1]._3]);
        }

        ULTIMA_1850_PrintString(" regurgitated!\n");
        ULTIMA_223c_AudioWhiteNoise(1, 7000, 600);

        D_ba14[param_1]._2 &= 0xfb;

        D_5c5a[D_ba14[param_1]._4]._1 = D_5c5a[D_ba14[param_1]._4]._0_tile;
    }
}
