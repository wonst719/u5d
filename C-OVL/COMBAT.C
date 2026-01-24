#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <string.h>
#include <memory.h>

void F_COMSUBS_0094(int a);
int F_COMSUBS_00f4(int a);
void F_COMSUBS_0312(int a, int b);
int F_COMSUBS_048a(int a, int b, int c, int d);
int F_COMSUBS_04d4(int a, int b);
void F_COMSUBS_07d4(int a, int b);
int F_COMSUBS_0822(int a, int b, int c, int d, int e);
int F_COMSUBS_09fc(int a);
void F_COMSUBS_0bf8(int a, int b, int c);
void F_COMSUBS_0d96(int a, int b);

F_SJOG_095c_search_cmd();
F_SJOG_0d4a_jimmy_cmd();
void F_SJOG_1374_open_cmd(void);
F_SJOG_18ce_get_cmd();
void F_SJOG_1b6c();
int F_SJOG_1c56(int a, int b);
int F_SJOG_1d6a_klimb();
void F_SJOG_1ea4();
int F_SJOG_1f7a(int a);
int F_SJOG_1f26(char* a, int b);
void F_SJOG_2012();
int F_SJOG_20d8(int a, int b, int c);
int F_SJOG_2148(int a);
int F_SJOG_21ce();

void F_ZSTATS_1296_ready_cmd(void);
int F_CAST_0dba_cast_spell_cmd();
F_CAST_1792_use_cmd();

F_CMDS_1418_yell_cmd();
F_CMDS_161a_push_cmd();
int F_CMDS_17ec();

void F_ZSTATS_0a3a_zstats_cmd();

void F_COMBAT_063e(void);
int F_COMBAT_0d30(int a);
int F_COMBAT_0ee4(int param_1);
void F_COMBAT_1236(int param_1);
int F_COMBAT_120e(void);
uint F_COMBAT_13e2(int param_1, int param_2);
int F_COMBAT_14d6(undefined2 param_1, undefined2 param_2, undefined2 param_3, int param_4);
int F_COMBAT_1574(int param_1, int param_2);
void F_COMBAT_194a(int param_1, int param_2);
int F_COMBAT_1a5c(int param_1);
void F_COMBAT_1b1e(int param_1);
void F_COMBAT_1c66(int param_1);

// NOT MATCHING
int F_COMBAT_0000(int param_1, int param_2, int param_3)
{
    byte bVar1;
    int iVar3;

    if (param_2 < 0xb && param_3 < 0xb && 0 <= param_2 && 0 <= param_3)
    {
        if (FUN_1000_2c4c(param_1, *FUN_1000_4402_get_address_of_tile_id(param_2, param_3)) == 0 ||
            *FUN_1000_4402_get_address_of_tile_id(param_2, param_3) == 0xff)
        {
            return 0;
        }

        for (iVar3 = 0; iVar3 < 0x20; iVar3++)
        {
            if (D_5c5a[iVar3]._2_x == param_2 && D_5c5a[iVar3]._3_y == param_3)
            {
                bVar1 = D_5c5a[iVar3]._0_tile;
                if (bVar1 == 0xeb)
                {
                    return 0;
                }
                if ((bVar1 & 0xfc) != 0xe8 && bVar1 != 0x1e && bVar1 != 0x1f && bVar1 != 0)
                {
                    bVar1 = D_5c5a[iVar3]._1;
                    if (bVar1 != 0)
                    {
                        return 0;
                    }
                }
            }
            else if (D_5c5a[iVar3]._6 == param_2 && D_5c5a[iVar3]._7 == param_3 &&
                    (bVar1 = D_5c5a[iVar3]._2_x, (bVar1 & 0x24) == 0))
            {
                if (bVar1 != 0)
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

// NOT MATCHING
int F_COMBAT_014e(int param_1, int param_2, int param_3)
{
    uint uVar2;
    int iVar3;
    undefined2 local_6;

    uVar2 = D_ba14[param_1]._3;
    if ((uVar2 == 0x1a || FUN_1000_2092_random_range(0, 0xff) < 0x80) &&
        ((D_153c[uVar2] & 0x8000) == 0 || (D_587a != 'N' && D_587a != 0x1c)))
    {
        FUN_1000_43ae(0x2ee, 400, 5, 0x96); // S.E.?
        if (param_3 == 0)
        {
            local_6 = F_COMBAT_14d6(param_2, param_1, -(uint)D_588f, 0);
        }
        else
        {
            local_6 = 0;
        }

        iVar3 = F_COMSUBS_0822(param_1, D_ba14[param_2]._6, D_ba14[param_2]._7, local_6, D_15cc[uVar2]);
        if (0 <= iVar3)
        {
            FUN_1000_3564(iVar3);
            FUN_1000_16ba_print_char(10);
            F_COMBAT_194a(iVar3, param_1);
            F_COMSUBS_0312(iVar3, param_1);
        }
        return 1;
    }

    return 0;
}

// NOT MATCHING
int F_COMBAT_0226(int param_1)
{
    bool bVar1;
    uint uVar2;
    uint uVar3;
    int iVar4;

    bVar1 = 0;
    uVar2 = D_ba14[param_1]._3;
    uVar3 = D_ba14[param_1]._4;
    iVar4 = F_COMBAT_0d30(param_1);
    if (0 <= iVar4)
    {
        if ((D_ba14[param_1]._2 & 1) == 0)
        {
            if ((D_ba14[iVar4]._2 & 0x80) != 0 &&
                D_55a8_party[D_ba14[iVar4]._3]._1e == '-' &&
                (D_153c[uVar2] & 0x8000) != 0)
            {
                bVar1 = FUN_1000_2092_random_range(0, 0xff) < 0x80;
            }

            if (F_COMSUBS_04d4(param_1, iVar4) <= D_159c[uVar2])
            {
                if (uVar2 == 0x1a)
                {
                    D_5c5a[uVar3]._6 = 0x20;
                }

                if (F_COMSUBS_04d4(param_1, iVar4) == 1)
                {
                    if (uVar2 == 0x2d)
                    {
                        D_5c5a[uVar3]._6 = 0x20;
                    }

                    FUN_1000_43ae(0x2ee, 400, 5, 0x96);
                    D_58a8[iVar4] = param_1;
                    if (F_COMBAT_14d6(iVar4, param_1, -(uint)D_588f, 0) == 0)
                    {
                        return 1;
                    }

                    if ((D_153c[uVar2] & 2) != 0 && FUN_1000_2092_random_range(0, 3) != 0 && D_57a8 != 0)
                    {
                        FUN_1000_1850_print_string("\nA ");
                        F_COMSUBS_0094(param_1);
                        FUN_1000_1850_print_string(" stole some food!\n");
                        FUN_1000_3f54(&D_57a8, 5);
                        FUN_1000_43ae(800, 2000, 1, 0x32);
                        FUN_1000_2900_update_vitals();
                        return 1;
                    }

                    FUN_1000_3564(iVar4);
                    FUN_1000_16ba_print_char(10);
                    F_COMBAT_194a(iVar4, param_1);
                    F_COMSUBS_0312(iVar4, param_1);
                    return 1;
                }

                return F_COMBAT_014e(param_1, iVar4, bVar1);
            }
        }
        else
        {
            if (F_COMSUBS_04d4(param_1, iVar4) == 1)
            {
                D_589d = 0x21;
                F_COMSUBS_0bf8(param_1, iVar4, 0x21);
                return 1;
            }
        }
    }

    return 0;
}

// NOT MATCHING
void F_COMBAT_03f4(void)
{
    D_589d = 0;

    if (D_587a != 'T' &&
        (D_587a != 'Q' || FUN_1000_2092_random_range(0, 1) != 0) &&
        (D_ba14[D_589e]._2 & 4) == 0)
    {
        if (((D_ba14[D_589e]._2) & 8) == 0)
        {
            if ((D_ba14[D_589e]._3) == '-')
            {
                D_5c5a[D_ba14[D_589e]._4]._6 = 0;
            }

            if ((D_ba14[D_589e]._2 & 2) == 0)
            {
                if (F_COMSUBS_00f4(D_589e) != 0)
                {
                    return;
                }

                if (F_COMBAT_0226(D_589e) != 0)
                {
                    return;
                }
            }
            else
            {
                if ((D_ba14[D_589e]._2 & 0x80) == 0 && FUN_1000_2092_random_range(0, 3) == 3)
                {
                    D_ba14[D_589e]._0++;
                }

                F_COMBAT_1a5c(D_589e);
            }

            if (F_COMBAT_0ee4(D_589e) == 0)
            {
                if ((D_ba14[D_589e]._2 & 2) != 0)
                {
                    F_COMBAT_0226(D_589e);
                }
            }
            else
            {
                if ((D_58a2 & 0x10) != 0)
                {
                    FUN_1000_16ba_print_char(10);
                    FUN_1000_43ae(0x4b0, 2000, 1, 0x28);
                    F_COMSUBS_0094(D_589e);
                    FUN_1000_1850_print_string(" escapes!\n");
                    F_COMBAT_1236(-1 - (uint)D_589e);

                    if ((D_ba14[D_589e]._2 & 0x80) == 0 && D_ba14[D_589e]._3 == '/')
                    {
                        F_SJOG_21ce();
                    }
                }
                FUN_1000_5910_update_map();
            }
        }
        else
        {
            if (FUN_1000_2092_random_range(0, 0x10) == 0x10)
            {
                FUN_1000_6800(D_589e);
            }
        }
    }
}

// NOT MATCHING
int F_COMBAT_0544(char* param_1, int param_2)
{
    FUN_1000_1850_print_string(param_1);

    if ((D_ba14[D_589e]._2 & 0x80) == 0)
    {
        FUN_1000_1850_print_string("Can't!\n");
        return 1;
    }
    else
    {
        switch (param_2)
        {
        case 0:
            F_SJOG_18ce_get_cmd();
            break;
        case 1:
            F_SJOG_0d4a_jimmy_cmd();
            break;
        case 2:
            F_SJOG_1374_open_cmd();
            break;
        case 3:
            F_ZSTATS_1296_ready_cmd();
            break;
        case 4:
            F_SJOG_095c_search_cmd();
            break;
        case 5:
            F_CAST_1792_use_cmd();
        }
        return 0;
    }
}

// NOT MATCHING
// from FMT
int F_COMBAT_05b6(int param_1, int param_2)
{
    if (param_1 == 0xff || D_15fc[param_1] == 0)
    {
        return 0;
    }
    else
    {
        if (param_2 != 0)
        {
            strcat(D_b21e, ", ");
        }

        strcat(D_b21e, D_17f6[param_1]);

        return 1;
    }
}

// NOT MATCHING
// based on FMT
void F_COMBAT_063e(void)
{
    bool bVar2;
    uint uVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    uint uVar7;
    int unaff_EDI;
    byte local_9;

    uVar3 = (uint)D_589e;
    D_5896_map_x = D_ba14[D_589e]._6;
    D_5897_map_y = D_ba14[D_589e]._7;
    uVar7 = D_ba14[D_589e]._3;
    if ((D_587b == 0xff) ||(((D_ba14[D_589e]._2 & 0x80) != 0 && (D_587b == uVar7))))
    {
        if ((D_ba14[D_589e]._2 & 0x80) == 0 ||
            (D_55a8_party[uVar7]._1b != '#' && *(char*)(uVar7 * 0x20 + 0x55c4) != '#'))
        {
            if ((D_ba14[D_589e]._2 & 0x80) != 0)
            {
                FUN_1000_2a28(D_ba14[D_589e]._3);
            }

            if (D_a9fa != 0)
            {
                FUN_1000_2900_update_vitals();
                D_a9fa = 0;
            }

            do
            {
                FUN_1000_16ba_print_char(10);
                F_COMSUBS_0094(D_589e);
                D_b21e[0] = 0;
                if ((D_ba14[D_589e]._2 & 0x80) != 0)
                {
                    FUN_1000_1850_print_string(", armed with ");
                    iVar4 = uVar7 * 0x20;
                    iVar5 = F_COMBAT_05b6(D_55a8_party[uVar7]._19, 0);
                    iVar6 = F_COMBAT_05b6(D_55a8_party[uVar7]._1b, iVar5);
                    iVar4 = F_COMBAT_05b6(D_55a8_party[uVar7]._1c, iVar5 + iVar6);
                    unaff_EDI = iVar5 + iVar6 + iVar4;
                    if (unaff_EDI == 0)
                    {
                        strcat(D_b21e, "bare hands");
                    }
                }

                strcat(D_b21e, ":");
                FUN_1000_1850_print_string(D_b21e);

                iVar4 = 0;
                bVar2 = 0;
                while (!bVar2)
                {
                    FUN_1000_16ba_print_char(10);
                    FUN_1000_4c2a();
                    if ((D_ba14[D_589e]._2 & 4) == 0)
                    {
                        if ((D_ba14[D_589e]._2 & 8) == 0)
                        {
                            local_9 = FUN_1000_266c_get_ch();
                            bVar2 = 1;
                            iVar4 = 0;

                            switch (local_9)
                            {
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                                if (F_SJOG_1c56(D_589e, local_9) == 0)
                                {
                                    bVar2 = 0;
                                }
                                break;
                            default:
                                FUN_1000_1850_print_string("What?\n");
                                bVar2 = 0;
                                break;

                            case 0x13: // ok
                                FUN_1000_1850_print_string("Sound ");
                                if (D_a9ce == 0)
                                {
                                    FUN_1000_1850_print_string("On\n");
                                }
                                else
                                {
                                    FUN_1000_1850_print_string("Off\n");
                                }
                                D_a9ce = D_a9ce == 0;
                                break;

                            case 0x1b:
                                iVar4 = F_CMDS_17ec();
                                break;
                            case 0x20: // ok
                                FUN_1000_1850_print_string("Pass\n");
                                break;
                            case 0x30: // ok
                                /* '0' */
                                D_587b = 0xff;
                                FUN_1000_1850_print_string("Set active plr:\nNone!\n");
                                FUN_1000_2900_update_vitals();
                                break;
                            case 0x31:
                            case 0x32:
                            case 0x33:
                            case 0x34:
                            case 0x35:
                            case 0x36:
                                /* '1' .. '6' */
                                iVar5 = F_SJOG_1f7a(local_9 - 0x31);
                                if (iVar5 == 0) {
                                    iVar4 = 1;
                                }
                                break;
                            case 0x41:
                                /* 'A' Attack */
                                F_COMSUBS_0d96(D_589e, unaff_EDI);
                                break;
                            case 0x42:
                                /* 'B' Board */
                                iVar4 = F_SJOG_1f26("Board", 1);
                                break;
                            case 0x43: // ok
                                /* 'C' Cast */
                                // 08f0
                                FUN_1000_1850_print_string("Cast...\n");
                                iVar4 = 1;
                                if ((D_ba14[D_589e]._2 & 0x80) == 0)
                                {
                                    FUN_1000_1850_print_string("Can't!\n");
                                    break;
                                }
                                iVar5 = F_COMSUBS_09fc((uint)D_589e);
                                if (iVar5 == 0)
                                {
                                    // 091b
                                    D_5890 = 1;
                                    D_588f = 1;
                                    iVar4 = 0;
                                    if (D_587a == 'N' || (D_57b4 == 0 && D_5894 == 0x12))
                                    {
                                        FUN_1000_1850_print_string("Absorbed!\n");
                                        FUN_1000_2192_audio_some_noise(0x2648, 1, 28000, 1000, 2);
                                    }
                                    else
                                    {
                                        F_CAST_0dba_cast_spell_cmd();
                                    }
                                }
                                break;
                            case 0x44:
                                /* 'D' What? */
                                FUN_1000_1850_print_string("D-What?\n");
                                break;
                            case 0x45: // ok
                                /* 'E' Enter */
                                // 0a4a
                                iVar4 = F_SJOG_1f26("Enter", 2);
                                break;
                            case 0x46: // ok
                                /* 'F' Fire */
                                // 0a54
                                iVar4 = F_SJOG_1f26("Fire", 2);
                                break;
                            case 0x47:
                                /* 'G' Get */
                                iVar4 = F_COMBAT_0544("Get-", 0);
                                break;
                            case 0x48: // ok
                                /* 'H' Hole up */
                                // 0a5a
                                iVar4 = F_SJOG_1f26("Hole up", 2);
                                break;
                            case 0x49: // ok
                                /* 'I' Ignite torch */
                                // 0a60
                                iVar4 = F_SJOG_1f26("Ignite torch", 2);
                                break;
                            case 0x4a: // ok
                                /* 'J' Jimmy */
                                iVar4 = F_COMBAT_0544("Jimmy-", 1);
                                break;
                            case 0x4b:
                                /* 'K' Klimb */
                                iVar5 = F_SJOG_1d6a_klimb();
                                if (iVar5 == 0)
                                {
                                    bVar2 = 0;
                                }
                                break;
                            case 0x4c: // ok
                                /* 'L' Look */
                                // 0a66
                                iVar4 = F_SJOG_1f26("Look", 2);
                                break;
                            case 0x4d: // ok
                                /* 'M' Mix */
                                // 0a6c
                                iVar4 = F_SJOG_1f26("Mix", 2);
                                break;
                            case 0x4e: // ok
                                /* 'N' New order */
                                // 0a72
                                iVar4 = F_SJOG_1f26("New order", 2);
                                break;
                            case 0x4f:
                                /* 'O' Open */
                                iVar4 = F_COMBAT_0544("Open-", 2);
                                break;
                            case 0x50:
                                /* 'P' Push */
                                FUN_1000_1850_print_string("Push-");
                                F_CMDS_161a_push_cmd();
                                break;
                            case 0x51: // ok
                                /* 'Q' Quit */
                                // 0a78
                                iVar4 = F_SJOG_1f26("Quit", 2);
                                break;
                            case 0x52:
                                /* 'R' Ready */
                                iVar4 = F_COMBAT_0544("Ready...\n\n", 3);
                                break;
                            case 0x53: // ok
                                /* 'S' Search */
                                iVar4 = F_COMBAT_0544("Search-", 4);
                                break;
                            case 0x54: // ok
                                /* 'T' Talk */
                                iVar4 = F_SJOG_1f26("Talk", 3);
                                break;
                            case 0x55: // ok
                                iVar4 = F_COMBAT_0544("Use item\n\n", 5);
                                break;
                            case 0x56: // ok
                                /* 'V' View */
                                iVar4 = F_SJOG_1f26("View", 2);
                                break;
                            case 0x57: // ok
                                /* 'W' What */
                                FUN_1000_1850_print_string("W-What?\n");
                                iVar4 = 1;
                                break;
                            case 0x58: // ok
                                /* 'X' X-it */
                                iVar4 = F_SJOG_1f26("X-it", 1);
                                break;
                            case 0x59: // ok
                                /* 'Y' Yell */
                                FUN_1000_1850_print_string("Yell ");
                                F_CMDS_1418_yell_cmd();
                                break;
                            case 0x5a: // ok
                                /* 'Z' Z-stats */
                                FUN_1000_1850_print_string("Z-stats...\n");
                                F_ZSTATS_0a3a_zstats_cmd();
                                break;
                            case 0xfc: // ok
                                // Buffer on/off
                                FUN_1000_1850_print_string("Buffer O");
                                D_538c = D_538c == 0;
                                if (D_538c == 0)
                                {
                                    FUN_1000_1850_print_string("n\n");
                                }
                                else
                                {
                                    FUN_1000_1850_print_string("ff\n");
                                }
                            }
                        }
                        else
                        {
                            iVar5 = FUN_1000_2092_random_range(0, 0xff);
                            if (iVar5 < 0x10)
                            {
                                FUN_1000_6800(D_589e);
                            }
                            FUN_1000_1850_print_string("Zzzzz...\n");
                            bVar2 = 1;
                        }
                    }
                    else
                    {
                        FUN_1000_1850_print_string("ARGH!\n");
                        FUN_1000_223c_audio_white_noise(0x28, 3000, 500);
                        F_COMBAT_1c66(D_589e);
                        bVar2 = 1;
                    }
                }
            } while (iVar4 != 0);

            if ((D_ba14[D_589e]._2 & 0x80) != 0)
            {
                FUN_1000_2a28(D_ba14[D_589e]._3);
            }
        }
        else
        {
            D_ba14[D_589e]._2 |= 1;
            D_587b = 0xff;
            D_a9fa = 1;
            F_COMBAT_03f4();
        }

        if ((local_9 < 0x30) || (0x36 < local_9))
        {
            F_SJOG_2012();
            FUN_1000_5910_update_map();
            F_SJOG_1ea4();
        }
    }
    else
    {
        F_SJOG_2012();
    }
}

// NOT MATCHING
int F_COMBAT_0b94(void)
{
    byte bVar2;
    byte bVar3;
    uint uVar6;
    undefined2 local_4;

    local_4 = 1;
    D_58a0 = 0;

    FUN_1000_5910_update_map();
    FUN_1000_2900_update_vitals();
    FUN_1000_1b16_clear_keyboard_buffer();
    F_SJOG_1b6c();

    if (D_5876 == 0)
    {
        D_58a3 = 1;
    }
    else
    {
        D_58a3 = 0;
    }

    uVar6 = 0;
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
                            D_ba14[D_589e]._5 = '$' - D_ba14[D_589e]._1;
                            D_5898 = 0;
                            D_58a2 = 0;
                            D_588f = 0;
                            D_5890 = 0;
                            D_589d = 0;
                            D_5882++;
                            if (D_5882 == 10)
                            {
                                D_5882 = 0;
                                FUN_1000_4f7c(1);
                            }
                            D_589f = 1;
                            if (FUN_1000_5646(D_589e) == 0) {
                                F_COMBAT_063e();
                            }
                            else {
                                F_COMBAT_03f4();
                            }
                            bVar2 = D_589e;
                            D_58a8[bVar2] = 0xff;
                            F_COMBAT_1b1e((uint)bVar2);
                            uVar6 = 0xca9;
                            F_SJOG_1b6c();
                            if (D_5878 == 0)
                            {
                                if (D_5876 == 0)
                                {
                                    local_4 = 0;
                                }
                                else
                                {
                                    uVar6 = 0xccd;
                                    if (F_SJOG_21ce() != -1)
                                    {
                                        D_589e++;
                                        continue;
                                    }
                                    FUN_1000_5910_update_map();
                                    if (D_58a3 == 0)
                                    {
                                        FUN_1000_1850_print_string("\nBATTLE IS LOST!");
                                        local_4 = 1;
                                    }
                                }
                                uVar6 = 1;
                                break;
                            }
                            if (D_5876 == 0 && D_58a3 == 0)
                            {
                                FUN_1000_1850_print_string("\nVICTORY!\n");
                                D_58a3 = 1;
                                uVar6 = 0xd05;
                                FUN_1000_4368();
                                FUN_1000_1b16_clear_keyboard_buffer();
                            }
                        }
                    }
                }
                else
                {
                    D_ba14[D_589e]._2 |= 0x20;
                    FUN_1000_3564(D_589e);
                    uVar6 = (uint)D_589e;
                    F_COMBAT_1574(uVar6, 99);
                }
            }
        }

        if (uVar6 != 0)
        {
            FUN_1000_1b16_clear_keyboard_buffer();
            D_2186 = 0xff;
            return local_4;
        }
    } while (1);
}

// NOT MATCHING
int F_COMBAT_0d30(int param_1)
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

    local_8 = FUN_1000_5646(param_1);
    if (D_587a == 'C')
    {
        iVar4 = F_COMBAT_13e2(0xffff, param_1);
        if (iVar4 < FUN_1000_3abe())
        {
            local_8 = 0;
        }
    }

    for (iVar4 = 0x1f; iVar4 >= 0; iVar4--)
    {
        if (iVar4 != param_1 && D_ba14[iVar4]._2 != '\0' && (D_ba14[iVar4]._2 & 0x20) == 0 && local_8 != FUN_1000_5646(iVar4) &&
            ((D_5894 == '(' || D_ba14[param_1]._3 == '/' || (D_ba14[iVar4]._2 & 0x10) == 0) && (D_ba14[iVar4]._2 & 4) == 0))
        {
            if (iVar4 < 5)
            {
                local_10 = local_10 + 1;
            }

            iVar5 = F_COMSUBS_048a(D_ba14[iVar4]._7, D_ba14[iVar4]._6, D_ba14[param_1]._7, D_ba14[param_1]._6);
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
        local_16 = F_SJOG_21ce();
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
int F_COMBAT_0ee4(int param_1)
{
    int local_8;
    int local_6;

    local_8 = 0;
    local_6 = 0;

    if ((D_ba14[param_1]._3 != '\x1b') && (D_ba14[param_1]._3 != '\x1a'))
    {
        if ((D_ba14[param_1]._2 & 0x80) == 0 && (D_153c[D_ba14[param_1]._3] & 0x2000) != 0 && D_587a != 'N' && D_587a != 0x1c &&
            (F_SJOG_2148(param_1) != 0 || FUN_1000_3aae(3) != 3) && F_COMBAT_120e() != 0)
        {
            if (F_COMBAT_0000(D_5c5a[D_ba14[param_1]._4]._0_tile, D_5876, D_5878) != 0)
            {
                D_5c5a[D_ba14[param_1]._4]._2_x = D_ba14[param_1]._6 = D_5876;
                D_5c5a[D_ba14[param_1]._4]._3_y = D_ba14[param_1]._7 = D_5878;

                FUN_1000_1850_print_string(D_1856[D_ba14[param_1]._3]);
                FUN_1000_1850_print_string(" teleports!\n");
                local_8 = 1;
            }
        }
        if (local_8 == 0 && F_SJOG_2148(param_1) == 0)
        {
            F_COMBAT_0d30(param_1);
            if (FUN_1000_3aae(0xff) < 0x80 || F_SJOG_20d8(D_ba14[param_1]._6 + D_5876, D_ba14[param_1]._7, param_1) != 0)
            {
                if (F_SJOG_20d8(D_ba14[param_1]._6, D_ba14[param_1]._7 + D_5878, param_1) == 0)
                {
                    D_5876 = 0;
                    local_6 = 0x3e6;
                }
            }
            else
            {
                D_5878 = 0;
                local_6 = 999;
            }

            if (local_6 < 0x3de)
            {
                for (local_8 = 4; 0 < local_8; local_8--)
                {
                    local_6 = FUN_1000_3aae(3);
                    if (local_6 == 0)
                    {
                        D_5878 = 1;
                        D_5876 = 0;
                    }
                    else if (local_6 == 1)
                    {
                        D_5876 = 1;
                        D_5878 = 0;
                    }
                    else if (local_6 == 2)
                    {
                        D_5878 = -1;
                        D_5876 = 0;
                    }
                    else if (local_6 == 3)
                    {
                        D_5876 = -1;
                        D_5878 = 0;
                    }

                    if (F_SJOG_20d8(D_ba14[param_1]._6 + D_5876, D_ba14[param_1]._7 + D_5878, param_1) == 0)
                    {
                        local_6 = 0x3df;
                    }

                    if (0x3de < (int)local_6)
                        break;

                    D_5878 = 0;
                    D_5876 = 0;
                }
            }

            if (local_6 != 0)
            {
                D_ba14[param_1]._6 += D_5876;
                D_5c5a[D_ba14[param_1]._4]._2_x = D_ba14[param_1]._6;

                D_ba14[param_1]._7 += D_5878;
                D_5c5a[D_ba14[param_1]._4]._3_y = D_ba14[param_1]._7;

                local_8 = 1;

                if (FUN_1000_6d82(D_ba14[param_1]._6, D_ba14[param_1]._7) == 0)
                {
                    D_58a2 = 0x10;
                }
            }
        }
    }

    return local_8;
}

// NOT MATCHING
int F_COMBAT_111a(uint param_1, uint param_2)
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
            FUN_1000_5910_update_map();
        }
    }

    return local_10;
}

// NOT MATCHING
int F_COMBAT_120e(void)
{
    int iVar2;

    D_5876 = FUN_1000_3aae(0xf);
    iVar2 = FUN_1000_3aae(0xf);
    D_5878 = iVar2;

    if (D_5876 < 0xb && iVar2 < 0xb)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// NOT MATCHING
void F_COMBAT_1236(int param_1)
{
    int iVar1;
    undefined2 local_6;

    if (param_1 < 0)
    {
        local_6 = D_ba14[-param_1 - 1]._4;
        D_ba14[-param_1 - 1]._4 = 0;
        D_ba14[-param_1 - 1]._1 = 0;
        D_ba14[-param_1 - 1]._0 = 0;
        D_ba14[-param_1 - 1]._7 = 0;
        D_ba14[-param_1 - 1]._6 = 0;
        D_ba14[-param_1 - 1]._5 = 0;
        D_ba14[-param_1 - 1]._2 = 0;
    }
    else
    {
        local_6 = param_1 - 1;
    }

    D_5c5a[local_6]._2_x = 0;
    D_5c5a[local_6]._1 = 0;
    D_5c5a[local_6]._0_tile = 0;
    D_5c5a[local_6]._5 = 0;
    D_5c5a[local_6]._4_z = 0;
    D_5c5a[local_6]._3_y = 0;
}

// NOT MATCHING
uint F_COMBAT_12b0(int param_1, int param_2)
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
            FUN_1000_1850_print_string("Thy sword hath shattered!\n");
            FUN_1000_6e60(param_1, 0x27);
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
                local_8 = FUN_1000_2092_random_range(1, local_8);
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
            iVar3 = FUN_1000_2092_random_range(1, cVar1);
            local_6 = local_8 - iVar3;
        }
    }

    return local_6;
}

// NOT MATCHING
int F_COMBAT_139a(int param_1)
{
    if (((D_587a == 'T' && (D_ba14[param_1]._2 & 0x40) != 0) || D_ba14[param_1]._3 == 0x1a) || (D_ba14[param_1]._2 & 8) != 0)
    {
        return  1;
    }
    else
    {
        return  D_ba14[param_1]._1;
    }
}

// NOT MATCHING
uint F_COMBAT_13e2(int param_1, int param_2)
{
    if ((D_ba14[param_1]._2 & 0x40) == 0)
    {
        if (param_2 <= 0)
            goto LAB_0000_142d;

        if (D_169c[param_2] != 8) // TODO: offset? (+1?)
            goto LAB_0000_1428; // param_2 = -2
    }
    else
    {
        if (param_2 != 0)
            goto LAB_0000_142d;

        if ((D_153c[D_ba14[param_1]._3] & 0x80) == 0)
        {
        LAB_0000_1428:
            param_2 = -2;
            goto LAB_0000_142d;
        }
    }
    param_2 = -3;

LAB_0000_142d:
    switch (param_2)
    {
        case -4:
            if ((D_ba14[param_1]._2 & 0x40) == 0)
            {
                return FUN_1000_6da8((D_ba14[param_1]._3));
            }
            else
            {
                return D_13bc[D_ba14[param_1]._3]._3;
            }

        case -3:
            if ((D_ba14[param_1]._2 & 0x40) == 0)
            {
                return D_55a8_party[D_ba14[param_1]._3]._c;
            }
            else
            {
                return D_13bc[D_ba14[param_1]._3]._0;
            }

        case -2:
            return F_COMBAT_139a(param_1);

        case -1:
            if ((D_ba14[param_1]._2 & 0x40) == 0)
            {
                return D_55a8_party[D_ba14[param_1]._3]._e;
            }
            else
            {
                return D_13bc[D_ba14[param_1]._3]._2;
            }
    }

    // sic
}

// NOT MATCHING
int F_COMBAT_14d6(undefined2 param_1, undefined2 param_2, undefined2 param_3, int param_4)
{
    int iVar1;
    int iVar2;
    undefined2 local_a;
    undefined2 local_8;
    undefined2 local_6;

    local_a = -1;
    local_6 = 0;

    if (D_588f == 0)
    {
        if (param_4 != 0x27 && param_4 != 0x23 && param_4 != 0x28)
        {
            local_8 = -2;
            local_a = param_4;
            goto LAB_0000_152f;
        }
    }
    else if ((param_4 < 0x2a || 0x31 < param_4) && param_4 != 0x33)
    {
        local_a = -1;
        local_8 = -1;
        goto LAB_0000_152f;
    }
    local_6 = 1;

LAB_0000_152f:
    if (local_6 == 0)
    {
        iVar1 = F_COMBAT_13e2(param_1, local_8);
        iVar2 = F_COMBAT_13e2(param_2, local_a);
        if (((iVar1 - iVar2) + 0x1e) / 2 <= FUN_1000_3abe())
        {
            local_6 = 1;
        }
    }

    return local_6;
}

// NOT MATCHING
int F_COMBAT_1574(int param_1, int param_2)
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
                    FUN_1000_6506(0x1f, 0, uVar10, uVar11, D_5895_map_level);
                    FUN_1000_5910_update_map();
                    return cVar7;
                }
                if (D_ba14[param_1]._3 == '\x1e')
                {
                    *FUN_1000_4402_get_address_of_tile_id(uVar10, uVar11) = 0x4c;
                }
                else if (bVar6 != 0x87 && 3 < bVar6)
                {
                    if ((int)(uint)bVar5 < FUN_1000_3abe())
                    {
                        D_5c5a[D_ba14[param_1]._4]._1 = 0x1f;
                        D_5c5a[D_ba14[param_1]._4]._0_tile = 0x1f;
                        return cVar7;
                    }

                    D_5c5a[D_ba14[param_1]._4]._1 = 1;
                    D_5c5a[D_ba14[param_1]._4]._0_tile = 1;
                    D_5c5a[D_ba14[param_1]._4]._5 = bVar5;

                    if ((int)(uint)bVar5 <= FUN_1000_3abe())
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
                    FUN_1000_1850_print_string(D_1856[D_ba14[param_1]._3]);
                    FUN_1000_1850_print_string(" vanishes!");
                    D_58a2 = 2;
                    D_5c5a[D_ba14[param_1]._4]._1 = 0x16;
                    D_5c5a[D_ba14[param_1]._4]._0_tile = 0x16;
                    FUN_1000_1068(D_ad14[D_ba14[param_1]._7 * 0x20 + D_ba14[param_1]._6], D_ba14[param_1]._6, D_ba14[param_1]._7);
                    F_COMBAT_1236(-(param_1 + 1));
                    F_SJOG_21ce();
                    return cVar7;
                }
                param_1 = -(param_1 + 1);
            }

            F_COMBAT_1236(param_1);
        }
        else if ((D_153c[D_ba14[param_1]._3] & 0x10) != 0)
        {
            for (local_c = 0; local_c < 8; local_c++)
            {
                F_COMSUBS_07d4(D_ba14[param_1]._6, D_ba14[param_1]._7);

                if (F_COMBAT_0000(D_5c5a[D_ba14[param_1]._4]._0_tile, D_5876, D_5878) != 0 &&
                    (iVar14 = FUN_1000_6506((D_5c5a[D_ba14[param_1]._4]._0_tile - 0x40) >> 2, 0, D_5876, D_5878, D_5895_map_level)) >= 0)
                {
                    D_ba14[iVar14]._0 = D_ba14[param_1]._0;
                    FUN_1000_1850_print_string(D_1856[D_ba14[param_1]._3]);
                    FUN_1000_1850_print_string(" divides!\n");
                    return 0;
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

        FUN_1000_2900_update_vitals();
    }

    return cVar7;
}

// NOT MATCHING
void F_COMBAT_18ba(int param_1, int param_2)
{
    undefined2 uVar1;

    if ((D_ba14[param_1]._2 & 0x80) == 0 || D_55a8_party[D_ba14[param_1]._3]._b != 'G')
    {
        uVar1 = F_COMBAT_1574(param_1, FUN_1000_3aae(0x14));
        if (0 <= param_2 && (D_ba14[param_2]._2 & 0x80) != 0)
        {
            FUN_1000_3f14(&D_55a8_party[D_ba14[param_2]._3]._14, uVar1, 9999);
        }
    }
    else
    {
        D_55a8_party[D_ba14[param_1]._3]._b = 0x50;
        FUN_1000_1850_print_string(D_55a8_party[D_ba14[param_1]._3]._0);
        FUN_1000_1850_print_string(" is poisoned!\n");
        D_58a2 = 8;
        D_a9fa = 1;
    }
}

// NOT MATCHING
void F_COMBAT_194a(int param_1, int param_2)
{
    bool bVar1;
    int iVar2;
    undefined2 uVar3;
    bool bVar4;

    bVar4 = (D_ba14[param_2]._2 & 0x80) == 0;
    if (!bVar4 || (D_153c[D_ba14[param_2]._3] & 0x204) == 0 || FUN_1000_2092_random_range(0, 3) == 0)
    {
        bVar1 = 0;
        if (bVar4 && D_ba14[param_2]._3 == 0x1c && (D_ba14[param_1]._2 & 8) == 0)
        {
            FUN_1000_68ae(param_1);
            bVar1 = 1;
        }

        if (bVar1)
        {
            return;
        }

        if (D_5890 != 0 && D_589d == '4')
        {
            FUN_1000_68ae(param_1);
            return;
        }

        if (D_5890 == 0 || D_589d != '3')
        {
            iVar2 = F_COMBAT_12b0(param_2, param_1);
            if (iVar2 < 0 && (D_ba14[param_1]._2 & 0x80) != 0)
            {
                D_58a2 = 0x20;
                return;
            }

            uVar3 = F_COMBAT_1574(param_1, iVar2);
            if ((D_ba14[param_2]._2 & 0x80) == 0)
            {
                return;
            }

            FUN_1000_3f14(&D_55a8_party[D_ba14[param_2]._3]._14, uVar3, 9999);
            return;
        }
    }

    F_COMBAT_18ba(param_1, param_2);
    return;
}

// NOT MATCHING
int F_COMBAT_1a5c(int param_1)
{
    uint uVar3;
    int bVar4;
    byte bVar5;

    bVar4 = 0;
    bVar5 = D_ba14[param_1]._2;

    if ((bVar5 & 0x80) == 0)
    {
        if ((uint)D_ba14[param_1]._0 < (uint)(D_13bc[D_ba14[param_1]._3]._5 >> 2))
        {
            bVar5 = 1;
            bVar4 = 1;
        }
        else
        {
            uVar3 = (uint)(D_13bc[D_ba14[param_1]._3]._5 >> 2) * 2;
            if (D_ba14[param_1]._0 < uVar3)
            {
                bVar5 = 2;
                if (0xfb < FUN_1000_3aae(0x100))
                {
                    bVar4 = 1;
                }
            }
            else if ((uint)D_ba14[param_1]._0 < (uVar3 / 2) * 3)
            {
                bVar5 = 3;
            }
            else
            {
                bVar5 = 4;
            }
        }

        if (bVar4)
        {
            D_ba14[param_1]._2 |= 2;
        }
        else
        {
            D_ba14[param_1]._2 &= 0xfd;
        }
    }

    return bVar5;
}

// NOT MATCHING
void F_COMBAT_1b1e(int param_1)
{
    char cVar1;
    int iVar4;
    int local_a;

    local_a = 0;
    cVar1 = D_ad14[D_ba14[param_1]._6 + D_ba14[param_1]._7 * 0x20];
    if (cVar1 == 0x8f || cVar1 == 0xbc)
    {
        local_a = 100;
    }
    if (cVar1 == 4)
    {
        local_a = 0x32;
    }
    if (local_a == 0)
    {
        for (iVar4 = 0; iVar4 < 0x20; iVar4++)
        {
            if (iVar4 != D_ba14[param_1]._4 && D_ba14[param_1]._6 == D_5c5a[iVar4]._2_x && D_ba14[param_1]._7 == D_5c5a[iVar4]._3_y)
            {
                if (D_5c5a[iVar4]._0_tile == 0xea)
                {
                    local_a = 100;
                }
                if (D_5c5a[iVar4]._0_tile == 0xe8)
                {
                    local_a = 0x32;
                }
                if (D_5c5a[iVar4]._0_tile == 0xe9)
                {
                    local_a = 0x96;
                }

                if (local_a != 0)
                    break;
            }
        }
    }

    if (local_a == 0x32)
    {
        if (D_5c5a[D_ba14[param_1]._4]._0_tile < 0x80)
        {
            F_COMBAT_18ba(param_1, -1);
            FUN_1000_3564(param_1);
        }
    }
    else if (local_a == 100)
    {
        FUN_1000_3564(param_1);
        F_COMBAT_1574(param_1, FUN_1000_3aae(10));
        F_COMSUBS_0312(param_1, -1);
        D_a9fa = 1;
    }
    else if (local_a == 0x96)
    {
        FUN_1000_68ae(param_1);
    }
}

// NOT MATCHING
void F_COMBAT_1c66(int param_1)
{
    if (FUN_1000_3abe() < D_ba14[param_1]._1)
    {
        if ((D_ba14[param_1]._2 & 0x80) == 0)
        {
            FUN_1000_1850_print_string(D_1856[D_ba14[param_1]._3]);
        }
        else
        {
            FUN_1000_1850_print_string(D_55a8_party[D_ba14[param_1]._3]._0);
        }

        FUN_1000_1850_print_string(" regurgitated!\n");
        FUN_1000_223c_audio_white_noise(1, 7000, 600);

        D_ba14[param_1]._2 &= 0xfb;

        D_5c5a[D_ba14[param_1]._4]._1 = D_5c5a[D_ba14[param_1]._4]._0_tile;
    }
}
