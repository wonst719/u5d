#include "common/common.h"
#include "vars.h"
#include "funcs.h"
#include "macros.h"

#include <string.h>

#include "cast.h"
#include "cmds.h"
#include "combat.h"
#include "comsubs.h"
#include "sjog.h"
#include "zstats.h"

static void COMBAT_063e_ProcessCommand(void);
static int COMBAT_0d30(int a);
static int COMBAT_0ee4(int param_1);
static void COMBAT_1b1e(int param_1);
static void COMBAT_1c66(int param_1);

// CHECKED
// walkable?
// param_1: party icon, param_2: x, param_3: y
int COMBAT_0000(int param_1, int param_2, int param_3)
{
    int local_4;
    int local_6;
    int local_8;

    if (param_2 > 0xa || param_3 > 0xa || param_2 < 0 || param_3 < 0)
    {
        // -> a2b0
        return 1;
    }

    // 0026
    if (ULTIMA_2c4c(param_1, *ULTIMA_4402_GetTileAddr(param_2, param_3)) != 0 &&
        *ULTIMA_4402_GetTileAddr(param_2, param_3) != 0xff)
    {
        // 0043
        for (local_8 = 0; local_8 < 0x20; local_8++)
        {
            if (D_5c5a[local_8]._2_x == param_2 && D_5c5a[local_8]._3_y == param_3) // a317
            {
                local_4 = D_5c5a[local_8]._0_tile;
                if (local_4 == 0xeb)
                {
                    return 0; // a33a
                }

                if ((local_4 & 0xfc) == 0xe8 || local_4 == 0x1e || local_4 == 0x1f) // a346
                {
                    continue;
                }

                if (local_4 != 0) // a38a
                {
                    if (D_5c5a[local_8]._1_animTile != 0)
                    {
                        return 0;
                    }
                }
            }
            else if (D_ba14[local_8].x == param_2 && D_ba14[local_8].y == param_3) // a398
            {
                local_6 = D_ba14[local_8].flags; // a3b3
                if ((local_6 & 0x24) == 0)
                {
                    if (local_6 == 0)
                    {
                        return 0;
                    }
                }

                if (D_5c5a[local_8]._1_animTile != 0)
                {
                    if (local_6 == 8)
                    {
                        return 0;
                    }
                }
            }
        }

        // -> a2b0
        return 1;
    }

    // a3d4
    return 0;
}

// OK P1
static int COMBAT_014e(int param_1, int param_2, int param_3)
{
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    local_a = D_ba14[param_1].entityIdx;
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

        local_8 = COMSUBS_0822(param_1, D_ba14[param_2].x, D_ba14[param_2].y, local_6, local_4);
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
    local_a = D_ba14[param_1].entityIdx;
    local_8 = D_ba14[param_1].actorIdx;
    local_4 = COMBAT_0d30(param_1);
    if (local_4 < 0)
    {
        // 0256
        return 0;
    }

    // 025c
    local_6 = D_ba14[local_4].entityIdx;

    if ((D_ba14[param_1].flags & 1) != 0)
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
        if ((D_ba14[local_4].flags & 0x80) != 0 &&
            D_55a8_party[local_6].equips[5] == 0x2d &&
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
    CombatEntity* local_4;
    int local_6;

    local_4 = &D_ba14[D_589e];
    D_589d = 0;
    local_6 = local_4->actorIdx;

    if (D_587a != 'T' &&
        (D_587a != 'Q' || ULTIMA_2092_RandomRange(0, 1) != 0) &&
        (local_4->flags & 4) == 0)
    {
        // 0446
        if ((local_4->flags & 8) != 0)
        {
            if (ULTIMA_2092_RandomRange(0, 0x10) == 0x10)
            {
                ULTIMA_6800(D_589e);
            }
        }
        else
        {
            if ((local_4->entityIdx) == 0x2d)
            {
                D_5c5a[local_6]._6 = 0;
            }

            // 047f
            if ((local_4->flags & 2) != 0)
            {
                if ((local_4->flags & 0x80) == 0 && ULTIMA_2092_RandomRange(0, 3) == 3)
                {
                    local_4->hp++;
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

                    if ((local_4->flags & 0x80) == 0 && local_4->entityIdx == 0x2f)
                    {
                        SJOG_21ce();
                    }
                }
                ULTIMA_5910_UpdateFrame();
            }
            else
            {
                if ((local_4->flags & 2) != 0)
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

    if ((D_ba14[D_589e].flags & 0x80) != 0)
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

// CHECKED
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
static void COMBAT_063e_ProcessCommand(void)
{
    int local_c;
    int local_a;
    byte local_8;
    int local_6;
    int local_4;

#if !defined(TARGET_DOS16)
    local_8 = 0xff;
#endif

    D_5896_map_x = D_ba14[D_589e].x;
    D_5897_map_y = D_ba14[D_589e].y;
    local_a = D_ba14[D_589e].entityIdx;

    if (D_587b != 0xff && ((D_ba14[D_589e].flags & 0x80) == 0 || D_587b != local_a))
    {
        SJOG_2012();
    }
    else
    {
        if ((D_ba14[D_589e].flags & 0x80) != 0 && (D_55a8_party[local_a].equips[2] == 0x23 || D_55a8_party[local_a].equips[3] == 0x23))
        {
            // a938
            D_ba14[D_589e].flags |= 1;
            D_587b = 0xff;
            D_a9fa = 1;
            COMBAT_03f4();
            // -> ae09
        }
        else
        {
            // a958
            if ((D_ba14[D_589e].flags & 0x80) != 0)
            {
                ULTIMA_2a28(D_ba14[D_589e].entityIdx);
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
                if ((D_ba14[D_589e].flags & 0x80) != 0)
                {
                    ULTIMA_1850_PrintString(", armed with ");
                    local_c = COMBAT_05b6(D_55a8_party[local_a].equips[0], 0);
                    local_c += COMBAT_05b6(D_55a8_party[local_a].equips[2], local_c);
                    local_c += COMBAT_05b6(D_55a8_party[local_a].equips[3], local_c);
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
                    if ((D_ba14[D_589e].flags & 4) != 0)
                    {
                        ULTIMA_1850_PrintString("ARGH!\n");
                        ULTIMA_223c_AudioWhiteNoise(0x28, 3000, 500);
                        COMBAT_1c66(D_589e);
                        local_6 = 1;
                    }
                    else if ((D_ba14[D_589e].flags & 8) != 0)
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
                            if ((D_ba14[D_589e].flags & 0x80) != 0)
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
                            if (SJOG_1d6a_CombatKlimb() == 0)
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
                            if (SJOG_1f7a_CombatSetActivePlayer(local_8 - 0x31) == 0)
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
                            if (SJOG_1c56_CombatMovePlayer(D_589e, local_8) == 0)
                            {
                                local_6 = 0;
                            }
                            break;

                        case 0x42:
                            /* 'B' Board */
                            // acbc
                            local_4 = SJOG_1f26_CombatMiscCmd("Board", 1);
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
                            local_4 = SJOG_1f26_CombatMiscCmd("Enter", 2);
                            break;

                        case 0x46: // ok
                            /* 'F' Fire */
                            // ace4 / 0a54
                            local_4 = SJOG_1f26_CombatMiscCmd("Fire", 2);
                            break;

                        case 0x48: // ok
                            /* 'H' Hole up */
                            // acea / 0a5a
                            local_4 = SJOG_1f26_CombatMiscCmd("Hole up", 2);
                            break;

                        case 0x49: // ok
                            /* 'I' Ignite torch */
                            // acf0 / 0a60
                            local_4 = SJOG_1f26_CombatMiscCmd("Ignite torch", 2);
                            break;

                        case 0x4c: // ok
                            /* 'L' Look */
                            // acf6 /  0a66
                            local_4 = SJOG_1f26_CombatMiscCmd("Look", 2);
                            break;

                        case 0x4d: // ok
                            /* 'M' Mix */
                            // acfc / 0a6c
                            local_4 = SJOG_1f26_CombatMiscCmd("Mix", 2);
                            break;

                        case 0x4e: // ok
                            /* 'N' New order */
                            // ad02 / 0a72
                            local_4 = SJOG_1f26_CombatMiscCmd("New order", 2);
                            break;

                        case 0x51: // ok
                            /* 'Q' Quit */
                            // ad08 / 0a78
                            local_4 = SJOG_1f26_CombatMiscCmd("Quit", 2);
                            break;

                        case 0x54: // ok
                            /* 'T' Talk */
                            // ad0e
                            local_4 = SJOG_1f26_CombatMiscCmd("Talk", 3);
                            break;

                        case 0x56: // ok
                            /* 'V' View */
                            // ad18
                            local_4 = SJOG_1f26_CombatMiscCmd("View", 2);
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
                            local_4 = SJOG_1f26_CombatMiscCmd("X-it", 1);
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
            if ((D_ba14[D_589e].flags & 0x80) != 0)
            {
                ULTIMA_2a28(D_ba14[D_589e].entityIdx);
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

// CHECKED
// perform combat (main loop)
int COMBAT_0b94_MainLoop(void)
{
    int local_a;
    int local_4;
    register CombatEntity* local_8;
    register int local_6;

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
        // ae5a
        //for (D_589e = 0; D_589e < 0x20; D_589e++)
        D_589e = 0;
        do
        {
            // ae5f
            D_594f = 0;
            local_8 = &D_ba14[D_589e];
            local_6 = local_8->flags;

            if (((byte)local_6 & 0xc0) != 0 && ((byte)local_6 & 0x20) == 0)
            {
                // ae86
                if (((byte)local_6 & 0x80) != 0 && D_55a8_party[local_8->entityIdx].status == STATUS_DEAD) // monster / non-dead player
                {
                    local_8->flags |= 0x20;
                    ULTIMA_3564(D_589e);
                    COMBAT_1574(D_589e, 99);
                }
                else
                {
                    // aeb6
                    if ((GetCombatMap(local_8->x, local_8->y) & 0xfe) != 0x84)
                    {
                        // aed3
                        if (--local_8->turnTimer == 0) // decrease turn timer
                        {
                            // aedb
                            local_8->turnTimer = 36 - local_8->dex; // reset timer
                            D_589d = D_5890 = D_588f = D_58a2 = D_5898 = 0;
                            D_5882++;
                            if (D_5882 == 10)
                            {
                                D_5882 = 0;
                                ULTIMA_4f7c(1);
                            }

                            // af09
                            D_589f = 1;
                            if (ULTIMA_5646(D_589e) != 0)
                            {
                                COMBAT_03f4();
                            }
                            else
                            {
                                COMBAT_063e_ProcessCommand();
                            }

                            // af23
                            D_58a8[D_589e] = 0xff;
                            COMBAT_1b1e(D_589e);
                            SJOG_1b6c();

                            // af39
                            if (D_5878 == 0)
                            {
                                if (D_5876 == 0)
                                {
                                    // af47
                                    local_4 = 0;

                                    // af4c
                                    local_a = 1;
                                    break; // -> afa6
                                }

                                // af5a
                                if (SJOG_21ce() == -1)
                                {
                                    ULTIMA_5910_UpdateFrame();
                                    if (D_58a3 == 0)
                                    {
                                        ULTIMA_1850_PrintString(/*0x6eee*/ "\nBATTLE IS LOST!");
                                        local_4 = 1;
                                    }

                                    // -> af4c
                                    local_a = 1;
                                    break;
                                }

                                continue;
                            }

                            // af78
                            if (D_5876 == 0 && D_58a3 == 0)
                            {
                                ULTIMA_1850_PrintString(/*0x6f00*/ "\nVICTORY!\n");
                                D_58a3 = 1;
                                ULTIMA_4368_AudioSomething();
                                ULTIMA_1b16_ClearKbdBuffer();
                            }
                        }
                    }
                }
            }
        } while (++D_589e < 0x20); // af98
    } while (local_a == 0); // afa6

    // afaf
    ULTIMA_1b16_ClearKbdBuffer();
    D_2186 = 0xff;
    return local_4;
}

// CHECKED
static int COMBAT_0d30(int param_1)
{
    int local_18;
    int local_16;
    int local_12;
    int local_10;
    int local_e;
    int local_8;
    int local_4;
    int local_a;
    int local_14;

    CombatEntity* local_6;
    CombatEntity* local_c;

    local_10 = -1;
    local_16 = -1;
    local_4 = 99;
    local_6 = &D_ba14[param_1];

    local_8 = ULTIMA_5646(param_1);
    if (D_587a == 67)
    {
        local_18 = COMBAT_13e2(param_1, -1);
        if (local_18 < ULTIMA_3abe())
        {
            local_8 = 0;
        }
    }

    for (local_14 = 0x1f; local_14 > -1; local_14--)
    {
        local_c = &D_ba14[local_14];
        if (local_14 != param_1 && local_c->flags != 0 && (local_c->flags & 0x20) == 0)
        {
            local_a = ULTIMA_5646(local_14);
            if (local_8 != local_a)
            {
                if (((D_5894 == 40 || local_6->entityIdx == 47 || (local_c->flags & 0x10) == 0) && (local_c->flags & 4) == 0))
                {
                    if (local_14 < 5)
                    {
                        local_10 = local_10 + 1;
                    }

                    // b06b
                    local_18 = COMSUBS_048a(local_6->x, local_6->y, local_c->x, local_c->y);
                    if (local_18 < local_4)
                    {
                        local_4 = local_18;
                        local_16 = local_14;
                        local_e = local_c->x;
                        local_12 = local_c->y;
                    }
                }
            }
        }
    }

    if (local_10 == -1 && local_16 == -1)
    {
        local_16 = SJOG_21ce();
    }

    if (local_16 == -1)
    {
        // NOT MATCHING (loop)
        for (local_14 = 0x1f; local_14 > 5; local_14--)
        {
            if ((D_ba14[local_14].flags & 0x40) != 0)
            {
                D_ba14[local_14].hp = 1;
                D_ba14[local_14].flags |= 2;
            }
        }

        local_e = 5;
        local_12 = 5;
    }

    D_5876 = D_5878 = 0;

    if (local_6->x > local_e)
    {
        D_5876 = -1;
    }

    if (local_6->x < local_e)
    {
        D_5876 = 1;
    }

    if (local_6->y > local_12)
    {
        D_5878 = -1;
    }

    if (local_6->y < local_12)
    {
        D_5878 = 1;
    }

    if ((local_6->flags & 2) != 0)
    {
        D_5876 *= -1;
        D_5878 *= -1;
    }

    if (local_16 == param_1)
    {
        local_16 = -1;
    }

    return local_16;
}

// CHECKED
static int COMBAT_0ee4(int param_1)
{
    int local_a;
    int local_8;
    int local_6;
    CombatEntity* local_4;

    local_8 = 0;
    local_6 = 0;
    local_4 = &D_ba14[param_1];

    if (local_4->entityIdx != 0x1b && local_4->entityIdx != 0x1a)
    {
        // 0f17
        if ((local_4->flags & 0x80) == 0 && (D_153c[local_4->entityIdx] & 0x2000) != 0 && D_587a != 0x4e && D_587a != 0x1c &&
            (SJOG_2148(param_1) != 0 || ULTIMA_3aae_Random(3) != 3) && COMBAT_120e() != 0)
        {
            if (COMBAT_0000(D_5c5a[local_4->actorIdx]._0_tile, D_5876, D_5878) != 0)
            {
                D_5c5a[local_4->actorIdx]._2_x = local_4->x = D_5876;
                D_5c5a[local_4->actorIdx]._3_y = local_4->y = D_5878;

                ULTIMA_1850_PrintString(D_1856[local_4->entityIdx]);
                ULTIMA_1850_PrintString(" teleports!\n");
                local_8++;
            }
        }

        // 0fab
        if (local_8 == 0 && SJOG_2148(param_1) == 0)
        {
            // 0fc1
            local_a = COMBAT_0d30(param_1);
            if (ULTIMA_3aae_Random(0xff) > 0x7f && SJOG_20d8(local_4->x + D_5876, local_4->y, param_1) == 0)
            {
                D_5878 = 0;
                local_6 = 999;
            }
            else
            {
                if (SJOG_20d8(local_4->x, local_4->y + D_5878, param_1) == 0)
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
                    if (SJOG_20d8(local_4->x + D_5876, local_4->y + D_5878, param_1) == 0)
                    {
                        local_6 = 991;
                    }

                    if (local_6 > 990)
                        break;

                    
                    D_5876 = D_5878 = 0;
                }
            }

            // 10c7
            if (local_6 != 0)
            {
                // NOT MATCHING (code order)
                local_4->x += D_5876;
                D_5c5a[local_4->actorIdx]._2_x = local_4->x;

                local_4->y += D_5878;
                D_5c5a[local_4->actorIdx]._3_y = local_4->y;

                local_8 = 1;

                if (ULTIMA_6d82(local_4->x, local_4->y) == 0)
                {
                    D_58a2 = 0x10;
                }
            }
        }
    }

    return local_8;
}

// OK P1
int COMBAT_111a(int param_1, int param_2)
{
    int local_e;
    byte* local_14;
    byte* local_4;
    byte* local_12;
    int local_10;
    byte* local_c;
    byte* local_a;
    byte* local_8;
    byte* local_6;

    local_10 = 0;

    if ((D_58a1 & 0x80) != 0 || (D_58a1 & 2) != 0)
    {
        local_14 = &GetCombatMapTriggerX(0);
        local_4 = &GetCombatMapTriggerY(0);
        local_12 = &GetCombatMapNewTileId(0);
        local_6 = &GetCombatMapNewTile1X(0);
        local_a = &GetCombatMapNewTile1Y(0);
        local_8 = &GetCombatMapNewTile2X(0);
        local_c = &GetCombatMapNewTile2Y(0);

        for (local_e = 0; local_e < 8; local_e++)
        {
            if (*local_14 == param_1 && *local_4 == param_2)
            {
                *local_14 = *local_4 = 0xff;

                if (*local_6 < 0xb && *local_a < 0xb)
                {
                    GetCombatMap((uint)*local_6, (uint)*local_a) = *local_12;
                }

                if (*local_8 < 0xb && *local_c < 0xb)
                {
                    GetCombatMap((uint)*local_8, (uint)*local_c) = *local_12;
                }
                local_10 = 1;
            }

            local_14++;
            local_4++;
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
    CombatEntity* local_4;
    int local_6;

    if (param_1 < 0)
    {
        param_1 *= -1;
        param_1--;
        local_4 = &D_ba14[param_1]; // [-param_1 - 1]
        local_6 = local_4->actorIdx;

        local_4->hp = local_4->dex = local_4->actorIdx = 0;
        local_4->flags = local_4->turnTimer = local_4->x = local_4->y = 0;
    }
    else
    {
        local_6 = param_1 - 1;
    }

    D_5c5a[local_6]._3_y =
        D_5c5a[local_6]._4_z =
        D_5c5a[local_6]._5 =
        D_5c5a[local_6]._0_tile =
        D_5c5a[local_6]._1_animTile =
        D_5c5a[local_6]._2_x = 0;
}

// OK P1
static int COMBAT_12b0(int param_1, int param_2)
{
    int local_4;
    int local_8;
    int local_6;

    if ((D_ba14[param_1].flags & 0x40) != 0)
    {
        local_8 = D_13bc[D_ba14[param_1].entityIdx]._4;
    }
    else
    {
        local_8 = D_589d;
        switch (local_8)
        {
        case 0x27:
            ULTIMA_1850_PrintString("Thy sword hath shattered!\n");
            ULTIMA_6e60(param_1, local_8);
            local_8 = 99;
            break;

        case 0xff:
            local_8 = 1;
            break;

        case 0x28:
            local_8 = 0;
            break;

        default:
            local_8 = D_15fc[local_8];
            if (local_8 > 1 && local_8 != 99)
            {
                local_8 = ULTIMA_2092_RandomRange(1, local_8);
            }
            break;
        }
    }

    if (local_8 == 99)
    {
        local_6 = 99;
    }
    else
    {
        if ((D_ba14[param_2].flags & 0x40) != 0)
        {
            local_4 = D_13bc[D_ba14[param_2].entityIdx]._3;
        }
        else
        {
            local_4 = D_55a8_party[D_ba14[param_2].entityIdx]._18;
        }

        local_6 = local_8;
        if (local_4 != 0)
        {
            local_6 -= ULTIMA_2092_RandomRange(1, local_4);
        }
    }

    return local_6;
}

// OK P1
static int COMBAT_139a(int param_1)
{
    if (D_587a == 'T' && (D_ba14[param_1].flags & 0x40) != 0)
    {
        return 1;
    }

    if (D_ba14[param_1].entityIdx == 0x1a)
    {
        return 1;
    }

    if ((D_ba14[param_1].flags & 8) != 0)
    {
        return 1;
    }

    return D_ba14[param_1].dex;
}

// OK P1
int COMBAT_13e2(int param_1, int param_2)
{
    CombatEntity* local_4 = &D_ba14[param_1];
    int local_6;

    if ((local_4->flags & 0x40) != 0)
    {
        if (param_2 == 0)
        {
            if ((D_153c[local_4->entityIdx] & 0x80) != 0)
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
        if ((local_4->flags & 0x40) != 0)
        {
            local_6 = D_13bc[local_4->entityIdx]._2;
        }
        else
        {
            // 145e
            local_6 = D_55a8_party[local_4->entityIdx].intel;
        }

        return local_6;

    case -2:
        // 1478
        local_6 = COMBAT_139a(param_1);

        return local_6;

    case -3:
        // 1480
        if ((local_4->flags & 0x40) != 0)
        {
            local_6 = D_13bc[local_4->entityIdx]._0;
        }
        else
        {
            local_6 = D_55a8_party[local_4->entityIdx].str;
        }

        return local_6;

    case -4:
        // 14aa
        if ((local_4->flags & 0x40) != 0)
        {
            local_6 = D_13bc[local_4->entityIdx]._3;
        }
        else
        {
            local_6 = ULTIMA_6da8((local_4->entityIdx));
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

// OK P1
int COMBAT_1574(int param_1, int param_2)
{
    int local_e;
    int local_8;
    int local_10;
    int local_12;
    int local_4;
    int local_c;
    int local_6;

    CombatEntity* local_a;

    local_8 = 0;
    local_6 = 0;
    local_4 = -1;
    local_a = &D_ba14[param_1];

    if (param_2 < 1)
    {
        D_58a2 = 0x20;
        param_2 = 0;
    }

    if ((local_a->flags & 0x80) != 0)
    {
        D_55a8_party[local_a->entityIdx].hp -= param_2;
        if (D_55a8_party[local_a->entityIdx].hp < 1 || param_2 == 99)
        {
            D_55a8_party[local_a->entityIdx].hp = 0;
            local_a->flags |= 0x20;
            D_55a8_party[local_a->entityIdx].status = STATUS_DEAD;

            D_5c5a[local_a->actorIdx]._0_tile = D_5c5a[local_a->actorIdx]._1_animTile = 0x1e;
            if (local_a->entityIdx == D_587b)
            {
                D_587b = 0xff;
            }
        }

        ULTIMA_2900_UpdateVitalsDisplay();
    }
    else
    {
        if ((((byte)D_153c[local_a->entityIdx]) & 0x20) != 0 && D_5890 == 0)
        {
            param_2 /= 2;
        }

        if ((((byte)D_153c[local_a->entityIdx]) & 8) != 0)
        {
            param_2 = 0;
        }

        if (local_a->hp < param_2)
        {
            local_a->hp = 0;
        }
        else
        {
            local_a->hp -= param_2;
        }

        if (local_a->hp == 0 || param_2 == 99)
        {
            local_8 = (D_13bc[local_a->entityIdx]._5_maxHp >> 2) + 1;
            local_6 = D_13bc[local_a->entityIdx]._7;

            local_a->flags = 0x20;

            local_a->hp = 0;
            local_10 = local_a->x;
            local_12 = local_a->y;
            local_e = GetCombatMap(local_10, local_12);

            if ((D_153c[local_a->entityIdx] & 0x1001) == 0)
            {
                if (local_a->entityIdx == 0x1c)
                {
                    D_5c5a[local_a->actorIdx]._0_tile = D_5c5a[local_a->actorIdx]._1_animTile = 0x1f;
                    ULTIMA_6506(0x1f, 0, local_10, local_12, D_5895_map_level);
                    ULTIMA_5910_UpdateFrame();
                }
                else if (local_a->entityIdx == 0x1e)
                {
                    *ULTIMA_4402_GetTileAddr(local_10, local_12) = 0x4c;
                    COMBAT_1236(-param_1 - 1);
                }
                else if (local_e == 0x87 || local_e < 4)
                {
                    COMBAT_1236(-param_1 - 1);
                }
                else if (local_6 >= ULTIMA_3abe())
                {
                    D_5c5a[local_a->actorIdx]._0_tile = D_5c5a[local_a->actorIdx]._1_animTile = 1;
                    D_5c5a[local_a->actorIdx]._5 = local_6;

                    if (local_6 > ULTIMA_3abe())
                    {
                        D_5c5a[local_a->actorIdx]._5 |= 0x80;
                    }
                }
                else
                {
                    D_5c5a[local_a->actorIdx]._0_tile = D_5c5a[local_a->actorIdx]._1_animTile = 0x1f;
                }
            }
            else if ((D_153c[local_a->entityIdx] & 0x1000) != 0)
            {
                ULTIMA_1850_PrintString(D_1856[local_a->entityIdx]);
                ULTIMA_1850_PrintString(" vanishes!");
                D_58a2 = 2;
                D_5c5a[local_a->actorIdx]._0_tile = D_5c5a[local_a->actorIdx]._1_animTile = 0x16;
                ULTIMA_1068(GetCombatMap(local_a->x, local_a->y), local_a->x, local_a->y);
                COMBAT_1236(-(param_1 + 1));
                SJOG_21ce();
            }
            else
            {
                COMBAT_1236(-(param_1 + 1));
            }

        }
        else if ((D_153c[local_a->entityIdx] & 0x10) != 0)
        {
            for (local_c = 0; local_c < 8; local_c++)
            {
                COMSUBS_07d4(local_a->x, local_a->y);

                local_10 = D_5876;
                local_12 = D_5878;
                if (COMBAT_0000(D_5c5a[local_a->actorIdx]._0_tile, local_10, local_12) != 0)
                {
                    local_4 = ULTIMA_6506((D_5c5a[local_a->actorIdx]._0_tile - 0x40) >> 2, 0, local_10, local_12, D_5895_map_level);
                    if (local_4 > -1)
                    {
                        D_ba14[local_4].hp = local_a->hp;
                        ULTIMA_1850_PrintString(D_1856[local_a->entityIdx]);
                        ULTIMA_1850_PrintString(" divides!\n");
                        break;
                    }
                }
            }
        }
    }

    return local_8;
}

// OK P1
void COMBAT_18ba(int param_1, int param_2)
{
    int local_4;

    if ((D_ba14[param_1].flags & 0x80) != 0 && D_55a8_party[D_ba14[param_1].entityIdx].status == STATUS_GOOD)
    {
        D_55a8_party[D_ba14[param_1].entityIdx].status = STATUS_POISONED;
        ULTIMA_1850_PrintString(D_55a8_party[D_ba14[param_1].entityIdx].name);
        ULTIMA_1850_PrintString(" is poisoned!\n");
        D_58a2 = 8;
        D_a9fa = 1;
    }
    else
    {
        local_4 = COMBAT_1574(param_1, ULTIMA_3aae_Random(0x14));
        if (param_2 > -1 && (D_ba14[param_2].flags & 0x80) != 0)
        {
            ULTIMA_3f14(&D_55a8_party[D_ba14[param_2].entityIdx].exp, local_4, 9999);
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
    if ((D_ba14[param_2].flags & 0x80) == 0)
    {
        local_6 = 1;
    }

    // 1969
    if (local_6 && (D_153c[D_ba14[param_2].entityIdx] & 0x204) != 0 && ULTIMA_2092_RandomRange(0, 3) != 0)
    {
        COMBAT_18ba(param_1, param_2);
    }
    else
    {
        // 19a0
        local_4 = 0;
        if (local_6 && D_ba14[param_2].entityIdx == 0x1c && (D_ba14[param_1].flags & 8) == 0)
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
            if (local_8 < 0 && (D_ba14[param_1].flags & 0x80) != 0)
            {
                D_58a2 = 0x20;
                return; // -> 1a54
            }

            // 1a22
            local_8 = COMBAT_1574(param_1, local_8);
            if ((D_ba14[param_2].flags & 0x80) != 0)
            {
                // 1a3c
                ULTIMA_3f14(&D_55a8_party[D_ba14[param_2].entityIdx].exp, local_8, 9999);
            }
        }
        else
        {
            COMBAT_18ba(param_1, param_2);
            return;
        }
    }
}

// CHECKED
int COMBAT_1a5c(int param_1)
{
    int local_a;
    int local_8;
    int local_6;
    CombatEntity* local_4;

    local_8 = 0;
    local_6 = 0;
    local_4 = &D_ba14[param_1];

    if ((local_4->flags & 0x80) != 0)
    {
        // 1a81
        return; // sic (IBM: returns &D_ba14[param_1], FMT: returns D_ba14[param_1]._2)
    }
    else
    {
        // 1a84
        local_a = D_13bc[local_4->entityIdx]._5_maxHp / 4; // max hp / 4 (25%)
        if (local_4->hp < local_a)
        {
            local_6 = 1;
            // 1aa9
            local_8 = 1;
        }
        else
        {
            // 1ab0 (NOT MATCHING)
            local_a *= 2;
            if (local_4->hp < local_a) // max hp / 2 (50%)
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
                local_a = (local_a / 2) * 3; // max hp / 4 * 3 (75%)
                if (local_4->hp < local_a)
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
            local_4->flags |= 2;
        }
        else
        {
            local_4->flags &= 0xfd;
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
    CombatEntity* local_6;

    local_a = 0;
    local_6 = &D_ba14[param_1];
    local_4 = GetCombatMap(local_6->x, local_6->y);
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
            if (local_8 != local_6->actorIdx &&
                local_6->x == D_5c5a[local_8]._2_x &&
                local_6->y == D_5c5a[local_8]._3_y)
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
        if (D_5c5a[local_6->actorIdx]._0_tile < 0x80)
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
    if (ULTIMA_3abe() < D_ba14[param_1].dex)
    {
        if ((D_ba14[param_1].flags & 0x80) != 0)
        {
            ULTIMA_1850_PrintString(D_55a8_party[D_ba14[param_1].entityIdx].name);
        }
        else
        {
            ULTIMA_1850_PrintString(D_1856[D_ba14[param_1].entityIdx]);
        }

        ULTIMA_1850_PrintString(" regurgitated!\n");
        ULTIMA_223c_AudioWhiteNoise(1, 7000, 600);

        D_ba14[param_1].flags &= 0xfb;

        D_5c5a[D_ba14[param_1].actorIdx]._1_animTile = D_5c5a[D_ba14[param_1].actorIdx]._0_tile;
    }
}
