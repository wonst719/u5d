#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <memory.h>
#include <stdio.h>
#include <string.h>

void F_OUTSUBS_0658(void);

void F_TOWN_0052(int param_1);
void F_TOWN_00b0(int param_1);
void F_TOWN_0170(void);
void F_TOWN_0958(void);
void F_TOWN_1694(void);

void F_NPC_0db4(int param_1);

void F_DNGLOOK_117e(int a, int b);

int F_COMBAT_0000(int param_1, int param_2, int param_3);

int F_COMSUBS_12de(int param_1, int param_2, int param_3, int param_4, int param_5);

int F_MAINOUT_105c(int param_1);

// NOT MATCHING
// hole up (impl)
int F_CMDS_0000(int param_1, int param_2, int param_3)
{
    char cVar1;
    undefined1 uVar2;
    undefined1 uVar5;
    undefined1 uVar6;
    int iVar9;
    uint uVar10;
    S_ba14* pVar11;
    int iVar13;
    uint local_2a;
    int local_24;
    uint local_22;
    int local_1e;
    undefined1 local_18;
    int local_16[8];
    int local_6;
    ActorFmt* local_4; // not read

#ifdef _WIN32
    pVar11 = 0;
#endif

    cVar1 = D_587f;
    local_6 = -1;
    local_1e = -1;
    D_588e = 0;
    D_587a = 0;
    uVar2 = D_587b;
    D_587b = 0xff;
    if ((param_1 & 2) == 0)
    {
        FUN_1000_6936();
    }
    else
    {
        F_DNGLOOK_117e(D_595a[(uint)D_5896_map_x + (D_5895_map_level & 0xff) * 0x40 + (uint)D_5897_map_y * 8], 0);
    }

    // (fmt: BGM(4))

    D_589e = 0xff;
    local_2a = param_3 + (uint)D_587f;
    if (0x17 < (int)local_2a)
    {
        local_2a -= 0x18;
    }

    if (5 < param_2 || param_2 < -1)
    {
        param_2 = -1;
    }

    for (iVar9 = 0; iVar9 < 8; iVar9++)
    {
        local_16[iVar9] = 0;
    }

    for (local_22 = 0; local_22 < D_585b; local_22++)
    {
        for (iVar13 = 0; iVar13 < 0x20; iVar13++)
        {
            if (local_22 == D_ba14[iVar13]._3)
            {
                pVar11 = &D_ba14[iVar13];
                break;
            }
        }

        switch (D_55a8_party[local_22]._b)
        {
        case 'P':
            local_16[local_22]++;
            // fallthrough
        case 'G':
        case 'S':
            if (local_22 != param_2)
            {
                FUN_1000_6880(iVar13);
            }
            if (D_55a8_party[local_22]._a == 'B' && local_22 == param_2 && D_a9ce != '\0')
            {
                local_6 = iVar13;
            }
            break;
        }
    }

    FUN_1000_5910_update_map();

    if (local_6 != -1)
    {
        uVar5 = D_5c5a[D_ba14[local_6]._4]._0_tile;
        uVar6 = D_5c5a[D_ba14[local_6]._4]._1;
        D_5c5a[D_ba14[local_6]._4]._1 = 0x5f;
        D_5c5a[D_ba14[local_6]._4]._0_tile = 0x5f;
        D_6a08 = 1;
        local_4 = &D_5c5a[D_ba14[local_6]._4];
        FUN_1000_3ae6(0x34);
        D_5c5a[D_ba14[local_6]._4]._0_tile = uVar5;
        D_5c5a[D_ba14[local_6]._4]._1 = uVar6;
        if (D_ba14[local_6]._3 != param_2)
        {
            FUN_1000_6880(local_6);
        }
        FUN_1000_5910_update_map();
    }

    FUN_1000_1850_print_string(/*0x41d4*/ "Zzzzzz...\n\n");

    if (param_2 != -1)
    {
        for (iVar13 = 0; iVar13 < 0x20; iVar13++)
        {
            if (D_ba14[iVar13]._3 == param_2)
            {
                pVar11 = &D_ba14[iVar13];
                break;
            }
        }

        local_18 = D_5c5a[pVar11->_4]._0_tile;
    }

    while (1)
    {
        if (local_2a == D_587f)
            goto LAB_0000_c27d;

        if (0x17 < D_587f)
        {
            D_587f = D_587f + 0xe8;
        }
        FUN_1000_5910_update_map();
        FUN_1000_400c();
        FUN_1000_2900_update_vitals();
        if (cVar1 != D_587f)
        {
            if (FUN_1000_2092_random_range(0, 0x3f) == 0)
            {
                FUN_1000_207e_srand(FUN_1000_2056_get_time());
                local_1e = (uint)D_1734[FUN_1000_2092_random_range(0, 7)];
                FUN_1000_1850_print_string(/*0x41e0*/ "Ambushed!\n\n");

                if (param_2 > -1)
                {
                    for (local_24 = 0; local_24 < 6; local_24++)
                    {
                        uVar10 = D_ba14[local_24]._3;
                        if (uVar10 < D_585b)
                        {
                            FUN_1000_6800(local_24);
                            if (local_16[uVar10] == 0)
                            {
                                D_55a8_party[uVar10]._b = 0x47;
                            }
                            else
                            {
                                D_55a8_party[uVar10]._b = 0x50;
                            }
                        }
                    }
                }

                FUN_1000_2900_update_vitals();
                if ((param_1 & 2) == 0)
                {
                    FUN_1000_6bc2(param_1, local_1e);
                }
                else
                {
                    F_DNGLOOK_117e(
                        D_595a[(uint)D_5896_map_x + (D_5895_map_level & 0xff) * 0x40 + (uint)D_5897_map_y * 8], 1);
                }

            LAB_0000_c27d:
                if (local_1e >= 0)
                {
                    return 1;
                }

                if (D_588c == 0 && param_3 >= 6)
                {
                    FUN_1000_1850_print_string(/*0x41ec*/ "Party rested!\n");

                    for (uVar10 = 0; uVar10 < D_585b; uVar10++)
                    {
                        if (local_16[uVar10] == 0 && D_588c == 0 && 5 < param_3 && D_55a8_party[uVar10]._b != 'D' &&
                            uVar10 != param_2)
                        {
                            iVar9 = FUN_1000_2092_random_range(1, 0x3f);
                            D_55a8_party[uVar10]._10 += iVar9;
                            if (D_55a8_party[uVar10]._10 > D_55a8_party[uVar10]._12)
                            {
                                D_55a8_party[uVar10]._10 = D_55a8_party[uVar10]._12;
                            }

                            if (uVar10 != param_2)
                            {
                                switch (D_55a8_party[uVar10]._a)
                                {
                                case 'A':
                                case 'M':
                                    D_55a8_party[uVar10]._f = D_55a8_party[uVar10]._e;
                                    break;
                                case 'B':
                                    D_55a8_party[uVar10]._f = D_55a8_party[uVar10]._e >> 1;
                                    break;
                                }
                            }
                        }
                    }

                    if ((param_1 & 0x82) == 0 && FUN_1000_2092_random_range(0, 99) < 0x19)
                    {
                        D_588d = D_587d;
                        F_OUTSUBS_0658();
                    }

                    D_588c = 0xe;
                }
                else
                {
                    FUN_1000_1850_print_string(/*0x41fb*/ "No effect...\n");
                }

                for (uVar10 = 0; uVar10 < D_585b; uVar10++)
                {
                    if (D_55a8_party[0]._b == 'S')
                    {
                        D_55a8_party[0]._b = 'G';
                    }
                }

                D_587b = uVar2;
                FUN_1000_2900_update_vitals();
                return 0;
            }
        }

        cVar1 = D_587f;
        FUN_1000_4f7c(5);
        FUN_1000_20fa_wait_ticks(1);
        if (D_5894 < 0x21)
        {
            D_5893_map_id = D_5894;
            FUN_1000_4a84();
            D_5893_map_id = 0xff;
        }

        if (param_2 != -1 && (iVar9 = FUN_1000_2092_random_range(0, 3), iVar9 == 2))
        {
            D_5876 = (uint)pVar11->_6;
            D_5878 = (uint)pVar11->_7;

            switch (FUN_1000_2092_random_range(0, 3))
            {
            case 0:
                D_5878--;
                break;
            case 1:
                D_5878++;
                break;
            case 2:
                D_5876++;
                break;
            case 3:
                D_5876--;
                break;
            }

            if (FUN_1000_6d82(D_5876, D_5878) != 0 && F_COMBAT_0000(local_18, D_5876, D_5878) != 0)
            {
                pVar11->_6 = D_5c5a[pVar11->_4]._2_x = D_5876;
                pVar11->_7 = D_5c5a[pVar11->_4]._3_y = D_5878;
                FUN_1000_5910_update_map();
            }
        }
    }
}

// NOT MATCHING
void F_CMDS_0552_hole_up_cmd(void)
{
    byte local_4;
    byte local_c;
    byte local_6;
    int local_a;
    int local_8;

    FUN_1000_1850_print_string(/*0x4209*/ "For how many hours? ");

    do
    {
        local_6 = FUN_1000_266c_get_ch();
    } while (local_6 != 0x20 && (local_6 < 0x30 || 0x39 < local_6));

    if (local_6 != 0x20 && local_6 != 0x30)
    {
        FUN_1000_16ba_print_char(local_6);
        FUN_1000_16ba_print_char(10);

        local_8 = (int)D_587f + (int)local_6 - 0x30;
        if (local_8 > 0x17)
        {
            local_8 -= 0x17;
        }

        for (local_a = 0; local_a < 0x10; local_a++)
        {
            F_NPC_0db4(D_587f);
            FUN_1000_5910_update_map();
            if (D_65be == 'a')
            {
                return;
            }
        }

        local_4 = D_587b;

        for (local_a = 0; local_a < D_585b; local_a++)
        {
            if (D_55a8_party[local_a]._b == 'G')
            {
                D_55a8_party[local_a]._b = 'S';
            }
        }

        FUN_1000_2900_update_vitals();
        FUN_1000_1850_print_string(/*0x421e*/ "Zzzzzzz...\n");

        FUN_1000_0a70_set_pen_color(0);
        FUN_1000_0aa6_fill_rectangle(8, 8, 0xb7, 0xb7);

        local_c = D_587f;
        while (local_8 != D_587f)
        {
            FUN_1000_4f7c(10);
            if (local_c != D_587f && (D_587f == 0x14 || D_587f == 0x05))
            {
                F_TOWN_0170();
            }
            local_c = D_587f;
            FUN_1000_4a84();
            FUN_1000_2ae8();
            FUN_1000_2900_update_vitals();
            F_TOWN_1694();

            if (FUN_1000_368e(D_5896_map_x, D_5897_map_y, D_5895_map_level) != 0)
            {
                local_8 = -1;
                break;
            }
            FUN_1000_20fa_wait_ticks(1);
        }

        if (local_8 == -1)
        {
            FUN_1000_1850_print_string(/*0x422a*/ "Thrown out of bed!\n");
        }

        for (local_a = 0; local_a < D_585b; local_a++)
        {
            if (D_55a8_party[local_a]._b == 'S')
            {
                D_55a8_party[local_a]._b = 'G';
            }
        }

        D_587b = local_4;
        D_5896_map_x++;
        D_24e6 = 1;
        D_5c5a[0]._2_x++;

        FUN_1000_2900_update_vitals();
        FUN_1000_5910_update_map();
    }
}

// NOT MATCHING
int F_CMDS_06ee(void)
{
    int uVar1;

    if (D_587c == 0x1c || D_587c == 0x1d)
    {
        return 1;
    }
    else
    {
        FUN_1000_1850_print_string(/*0x423e*/ "\nOn foot\n");
        return 0;
    }
}

// NOT MATCHING
int F_CMDS_070c(void)
{
    int local_4;

    switch (D_587c)
    {
    case 0x14:
    case 0x15:
    case 0x1c:
    case 0x1d:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
        return 1;

    default:
        FUN_1000_1850_print_string(/*0x4248*/ "\nOn foot\n");
        return 0;
    }
}

int F_CMDS_0788(int param_1, int param_2);

// NOT MATCHING
int F_CMDS_073e(void)
{
    if (F_CMDS_0788(4, 5) != 1)
    {
        if (F_CMDS_0788(6, 5) != 1)
        {
            if (F_CMDS_0788(5, 6) != 1)
            {
                if (F_CMDS_0788(5, 4) != 1)
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

// NOT MATCHING
int F_CMDS_0788(int param_1, int param_2)
{
    char cVar1;
    byte bVar2;
    undefined2 uVar3;

    cVar1 = D_ab02[param_2 + param_1 * 0x20];
    if (cVar1 == 0)
    {
        bVar2 = D_ac64[param_2 + param_1 * 0x10];
        if (bVar2 == 0x1b || (bVar2 &= 0xfc, bVar2 == 0x1c) || bVar2 == 0x24 || bVar2 == 0x10 || bVar2 == 0x28)
        {
            uVar3 = 1;
        }
        else
        {
            uVar3 = 0;
        }
    }
    else
    {
        uVar3 = FUN_1000_2c4c(0x1c, cVar1);
    }
    return uVar3;
}

int F_TOWN_011e(int param_1);

// NOT MATCHING
int F_CMDS_07f6_board_cmd(void)
{
    byte local_c;
    byte local_a;
    int local_4;
    int local_8;
    int local_6;

    if (D_5893_map_id >= 0x21 && 0x28 >= D_5893_map_id)
    {
        FUN_1000_1850_print_string(/*0x4252*/ "\nNot here!\n");
    }
    else
    {
        local_c = FUN_1000_368e(D_5896_map_x, D_5897_map_y, D_5895_map_level);
        local_6 = D_5876;
        if ((local_c & 0xfe) == 0x10)
        {
            if (D_5893_map_id != 0)
            {
                local_4 = F_TOWN_011e(local_6);
                if (local_4 != -1 && D_5f5e[local_4]._a != 0)
                {
                    FUN_1000_1850_print_string(/*0x425e*/ "\"Nay!\"\n");
                    return 1;
                }
            }

            if (F_CMDS_06ee() == 0)
            {
                return 1;
            }

            FUN_1000_1850_print_string(/*0x4266*/ "horse\n");

            local_c += 2;
            D_587c = local_c;
        }
        else if (local_c == 0x1b)
        {
            if (F_CMDS_06ee() == 0)
            {
                return 1;
            }

            FUN_1000_1850_print_string(/*0x426d*/ "carpet\n");

            D_587c = 0x14;
        }
        else if ((local_c & 0xfc) == 0x28)
        {
            if (F_CMDS_06ee() == 0)
            {
                return 1;
            }

            FUN_1000_1850_print_string(/*0x4275*/ "skiff\n");

            D_587c = local_c;
        }
        else if ((local_c & 0xfc) == 0x24)
        {
            if (F_CMDS_070c() == 0)
            {
                return 1;
            }

            FUN_1000_1850_print_string(/*0x427c*/ "Ship\n");

            local_a = D_5c5a[local_6]._5;
            if (local_a < 10)
            {
                FUN_1000_1850_print_string(/*0x4282*/ "\nDANGER: SHIP BADLY DAMAGED!\n");
            }

            D_5c5a[0]._5 = local_a;
            local_8 = D_5c5a[local_6]._7;

            if ((D_587c & 0xfe) == 0x14)
            {
                D_57b0++;
            }

            if ((D_587c & 0xfc) == 0x28)
            {
                local_8++;
            }

            if (local_8 == 0)
            {
                FUN_1000_1850_print_string(/*0x42a0*/ "\nWARNING: NO SKIFFS ON BOARD!\n");
            }

            D_587c = local_c;
            D_5c5a[0]._7 = local_8;
            D_a9fa = 1;
        }
        else
        {
            FUN_1000_1850_print_string(/*0x42bf*/ "What?\n");
            return 0;
        }

        FUN_1000_3a74(0, 0, 0, 0, 0, 0, local_6);
        D_24e6 |= 2;
    }

    return 1;
}

// NOT MATCHING
void F_CMDS_0962(void)
{
    undefined2 uVar3;
    int iVar4;
    int iVar6;
    uint uVar8;
    uint local_16;
    int local_e;
    byte local_c;

    if (D_587c < 0x20 || 0x27 < D_587c)
    {
        FUN_1000_1850_print_string(/*0x42c6*/ "What?\n");
    }
    else
    {
        if (FUN_1000_35ec_select_direction() == 0)
        {
            return;
        }

        iVar4 = D_5876;
        iVar6 = D_5878;

        if (iVar4 == 0 && (D_587c & 1) == 0 || iVar4 != 0 && (D_587c & 1) != 0)
        {
            FUN_1000_1850_print_string(/*0x42cd*/ "Fire broadsides only!\n");
        }
        else
        {
            uVar8 = D_5896_map_x;
            local_16 = D_5897_map_y;
            FUN_1000_43ae(1000, 200, 5, 300);
            local_e = 0;
            while (1)
            {
                uVar8 += iVar4;
                local_16 += iVar6;

                uVar3 = FUN_1000_368e(uVar8, local_16, D_5895_map_level);
                if (F_MAINOUT_105c(uVar3) != 0)
                {
                    local_c = (byte)uVar3;
                    if ((local_c & 0xfc) != 0xec)
                    {
                        break;
                    }
                }

                local_e++;

                if (2 < local_e)
                {
                    F_COMSUBS_12de(5, 5, iVar4 * 3 + 5, iVar6 * 3 + 5, 1);
                    return;
                }
            }

            iVar4 = D_5876;

            if (F_COMSUBS_12de(5, 5, (uint)D_5c5a[iVar4]._2_x - (uint)D_5896_map_x + 5,
                               (uint)D_5c5a[iVar4]._3_y - (uint)D_5897_map_y + 5, 1) == 0)
            {
                return;
            }

            FUN_1000_5910_update_map();
            FUN_1000_3522(uVar8, local_16);

            D_5c5a[iVar4]._5 -= FUN_1000_2092_random_range(1, 0x14);
            if (D_5c5a[iVar4]._5 < 0x80)
            {
                return;
            }

            FUN_1000_3a74(0, 0, 0, 0, 0, 0, iVar4);
            D_24e6 |= 2;
        }
    }
}

// NOT MATCHING
void F_CMDS_0aea_fire_cmd(void)
{
    bool bVar1;
    bool bVar2;
    int local_1c;
    int local_8;
    int local_c;
    undefined1* puVar10;
    byte local_20;
    int local_1e;
    int local_18;
    int local_16;
    int local_14;
    int local_12;
    byte local_10;
    int local_e;
    int local_a;

    SET_UNINITIALIZED_16(local_a);

    if (0x20 < D_5893_map_id && D_5893_map_id < 0x29)
    {
        FUN_1000_1850_print_string(/*0x42e4*/ "What?\n");
        return;
    }

    if (D_5893_map_id == 0)
    {
        F_CMDS_0962();
        return;
    }

    FUN_1000_39cc_set_new_tile_id(D_594f, D_5950, D_5951);

    local_20 = D_ab02[0x85];
    if ((local_20 & 0xfc) == 0xb4)
    {
        local_16 = 0;
        local_1e = -1;
    }
    else
    {
        local_20 = D_ab02[0xa6];
        if ((local_20 & 0xfc) == 0xb4)
        {
            local_16 = 1;
            local_1e = 0;
        }
        else
        {
            local_20 = D_ab02[0xc5];
            if ((local_20 & 0xfc) == 0xb4)
            {
                local_16 = 0;
                local_1e = 1;
            }
            else
            {
                local_20 = D_ab02[0xa4];
                if ((local_20 & 0xfc) == 0xb4)
                {
                    local_16 = -1;
                    local_1e = 0;
                }
                else
                {
                    FUN_1000_1850_print_string(/*0x42eb*/ "What?\n");
                    return;
                }
            }
        }
    }

    local_14 = local_16 + (uint)D_5896_map_x;
    local_1c = local_1e + (uint)D_5897_map_y;

    local_8 = local_e = local_16 + 5;
    local_c = local_12 = local_1e + 5;

    switch (local_20 & 3)
    {
    case 0:
        local_16 = 0;
        local_1e = -1;
        break;
    case 1:
        local_16 = 1;
        local_1e = 0;
        break;
    case 2:
        local_16 = 0;
        local_1e = 1;
        break;
    case 3:
        local_16 = -1;
        local_1e = 0;
        break;
    }

    FUN_1000_1850_print_string(/*0x42f2*/ "BOOOM!\n");
    FUN_1000_43ae(1000, 200, 5, 300);
    F_TOWN_0958();

    bVar1 = 0;
    bVar2 = 0;
    local_18 = 5;

    while (!bVar1 && !bVar2 && 0 < --local_18)
    {
        local_14 += local_16;
        local_1c += local_1e;
        local_e += local_16;
        local_12 += local_1e;

        local_10 = FUN_1000_3702(local_14, local_1c, D_5895_map_level);
        if (local_10 == 0)
        {
            local_20 = *FUN_1000_4402_get_address_of_tile_id(local_14, local_1c);
            if (0x96 < local_20 && (local_20 < 0x9a || (0xb7 < local_20 && local_20 < 0xbc))) // TODO: switch?
            {
                bVar1 = 1;
            }
        }
        else if ((0x1b < local_10 && ((byte)local_10 & 0xf8) != 0x78 && ((byte)local_10 & 0xfc) != 0x2f) // TODO: BUG?
                 || local_10 == 0x10 || local_10 == 0x11)
        {
            bVar2 = 1;
            local_a = D_5876;
        }
    }

    F_COMSUBS_12de(local_8, local_c, local_e, local_12, 1);
    if (bVar1 || bVar2)
    {
        FUN_1000_3522(local_14, local_1c);
    }

    if (bVar1)
    {
        FUN_1000_1850_print_string(/*0x42fa*/ "Door destroyed!\n");
        puVar10 = FUN_1000_4402_get_address_of_tile_id(local_14, local_1c);
        *puVar10 = 0x44;
        D_24e6 = 1;
        D_594f = 0;
    }

    CHECK_UNINITIALIZED_16(local_a);

    if (bVar2 && local_a != 0)
    {
        FUN_1000_3a74(0, 0, 0, 0, 0, 0, local_a);

        D_24e6 |= 2;
        if (D_5888 < 6)
        {
            D_5888 = 0;
        }
        else
        {
            D_5888 -= 5;
        }

        local_1e = F_TOWN_011e(local_a);
        if (local_1e == -1)
        {
            return;
        }

        F_TOWN_0052(local_1e);
        F_TOWN_00b0(local_1e);
    }

    if (bVar2 && local_a == 0)
    {
        FUN_1000_2aa8();
    }
}

// NOT MATCHING
void F_CMDS_0d98_ignite_torch_cmd(void)
{
    if (D_57ae == 0)
    {
        FUN_1000_1850_print_string(/*0x430b*/ "None owned!\n");
    }
    else
    {
        D_57ae--;
        if (D_5893_map_id <= 0x20 || D_5893_map_id >= 0x29)
        {
            D_58a7 = 0xf0;
        }
        else
        {
            FUN_1000_3ef0(&D_58a7, FUN_1000_2092_random_range(0, 0xf) + 0x70, 0xff);
        }
    }
}

// NOT MATCHING
void F_CMDS_0ddc_new_order_cmd(void)
{
    int local_24;
    int local_26;
    S_55a8 local_22;

    FUN_1000_1850_print_string(/*0x4318*/ "\n\nSwap ");
    local_24 = FUN_1000_2e8e();
    if (local_24 == -1)
    {
        FUN_1000_1850_print_string(/*0x4320*/ "nobody!\n");
        return;
    }

    FUN_1000_1850_print_string(D_55a8_party[local_24]._0);
    if (local_24 == 0)
    {
        FUN_1000_1850_print_string(/*0x4329*/ "\n\n");
        FUN_1000_1850_print_string(D_55a8_party[0]._0);
        FUN_1000_1850_print_string(/*0x432c*/ " must lead!\n");
        return;
    }

    FUN_1000_1850_print_string(/*0x4339*/ "\nwith ");
    local_26 = FUN_1000_2e8e();
    if (local_26 == -1)
    {
        FUN_1000_1850_print_string(/*0x4340*/ "nobody!\n");
        return;
    }

    FUN_1000_1850_print_string(D_55a8_party[local_26]._0);
    if (local_26 == 0)
    {
        FUN_1000_1850_print_string(/*0x4349*/ "\n\n");
        FUN_1000_1850_print_string(D_55a8_party[0]._0);
        FUN_1000_1850_print_string(/*0x434c*/ " must lead!\n");
        return;
    }

    FUN_1000_1850_print_string(/*0x4359*/ "!\n");

    memcpy(&local_22, &D_55a8_party[local_24], sizeof(S_55a8));
    memcpy(&D_55a8_party[local_24], &D_55a8_party[local_26], sizeof(S_55a8));
    memcpy(&D_55a8_party[local_26], &local_22, sizeof(S_55a8));

    D_a9fa = 1;
}

// NOT MATCHING
void F_CMDS_0eb4_xit_cmd(void)
{
    byte local_a;
    byte local_8;
    int local_6;
    byte local_4;

    if (D_5893_map_id < 0x20 && D_5893_map_id > 0x29) // TODO: sic; BUG
    {
        FUN_1000_1850_print_string(/*0x435c*/ "\nNot here!\n");
        return;
    }

    local_8 = *FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y);

    switch (D_587c & 0xfc)
    {
    case 0x1c:
        FUN_1000_1850_print_string(/*0x4368*/ "what?\n");
        return;

    case 0x20:
        FUN_1000_1850_print_string(/*0x436f*/ "\nUnder sail!\n");
        return;

    case 0x14:
        if (F_CMDS_073e() != 0 || FUN_1000_2c4c(0x1c, local_8) != 0)
        {
            FUN_1000_1850_print_string(/*0x437d*/ "carpet!\n");
            local_4 = 0x1b;
            D_587c = 0x1c;
            break;
        }

        if (F_CMDS_073e() == 0)
        {
            FUN_1000_1850_print_string(/*0x4386*/ "\nNo land nearby!\n");
        }
        else
        {
            FUN_1000_1850_print_string(/*0x4398*/ "\nNot here!\n");
        }

        return;

    case 0x10:
        FUN_1000_1850_print_string(/*0x43a4*/ "horse!\n");
        local_4 = D_587c - 2;
        D_587c = 0x1c;
        break;

    case 0x28:
        if (F_CMDS_073e() == 0)
        {
            FUN_1000_1850_print_string(/*0x43ac*/ "\nNo land nearby!\n");
        }
        else
        {
            if ((local_8 & 0xfe) != 0x6a)
            {
                FUN_1000_1850_print_string(/*0x43ca*/ "skiff!\n");
                local_4 = D_587c;
                D_587c = 0x1c;
                break;
            }

            FUN_1000_1850_print_string(/*0x43be*/ "\nNot here!\n");
        }
        return;

    case 0x24:
        FUN_1000_1850_print_string(/*0x43d2*/ "ship!\n");
        if (F_CMDS_073e() == 0)
        {
            if (D_5c5a[0]._7 != '\0')
            {
                local_4 = D_587c;
                D_587c += 4;
                local_a = D_5c5a[0]._7 - 1;
                break;
            }

            if (D_57b0 == '\0')
            {
                FUN_1000_1850_print_string(/*0x43d9*/ "\nNo skiffs on board!\n");
                return;
            }

            D_57b0--;
            local_4 = D_587c;
            D_587c = 0x14;
        }
        else
        {
            local_4 = D_587c;
            D_587c = 0x1c;
        }

        local_a = D_5c5a[0]._7;
        break;
    }

    local_6 = FUN_1000_38e4();
    FUN_1000_3a74(local_4, local_4, D_5896_map_x, D_5897_map_y, D_5895_map_level, D_5c5a[0]._5, local_6);
    D_5c5a[local_6]._7 = local_a; // TODO: BUG; NOT INITIALIZED when (D_587c & 0xfc) != 0x24
    FUN_1000_2900_update_vitals();
}

// NOT MATCHING
int F_CMDS_1030(char* param_1)
{
    int local_c;
    int local_a;
    int local_6;
    int local_4;

    local_6 = 1;

    if (D_5893_map_id == 0x1e || D_5893_map_id == 0x1f || D_5893_map_id == 0x20)
    {
        for (local_a = 0; local_a < 3; local_a++)
        {
            if (-1 < FUN_1000_6f1e((byte*)D_444a[local_a], param_1))
                break;
        }

        if (local_a == 3 || 1 >= D_5897_map_y || D_58c8[local_a] == 0xff)
        {
            FUN_1000_1850_print_string(/*0x440b*/ "\nNo effect!\n");
        }
        else
        {
            for (local_c = 0; local_c < 0x20; local_c++)
            {
                if (D_5c5a[local_c]._0_tile == 0xfc)
                {
                    FUN_1000_1850_print_string(/*0x4418*/ "\nNo effect!\n");

                    return local_6;
                }
            }

            D_58cb = local_a;
            local_c = FUN_1000_38e4();
            FUN_1000_3a74(0xfc, 0xfc, D_5896_map_x, D_5897_map_y - 2, D_5895_map_level, 0, local_c);

            for (local_4 = 0x1f; local_4 >= 0; local_4--)
            {
                if (D_659e[local_4] == 0)
                {
                    break;
                }
            }

            D_5f5e[local_4]._0 = 1;
            D_5f5e[local_4]._c = local_c;
            D_5f5e[local_4]._2 = D_5896_map_x;
            D_5f5e[local_4]._4 = D_5897_map_y - 2;
            D_5f5e[local_4]._6 = D_5895_map_level;

            for (local_a = 0; local_a < 4; local_a++)
            {
                D_5d5e[local_4]._c[local_a] = 0;
            }

            for (local_a = 0; local_a < 3; local_a++)
            {
                D_5d5e[local_4]._0[local_a] = 6;
                D_5d5e[local_4]._3[local_a] = D_5896_map_x;
                D_5d5e[local_4]._6[local_a] = D_5897_map_y - 2;
                D_5d5e[local_4]._9[local_a] = D_5895_map_level;
            }

            D_659e[local_4] = 0xfc;

            FUN_1000_1850_print_string(/*0x4425*/ "\nA shadowlord appears\n");
            FUN_1000_2192_audio_some_noise(0x28a0, 1, 30000, 2000, 2);

            D_5c5a[local_c]._0_tile = D_5c5a[local_c]._1 = 0x16;
            FUN_1000_1068(0x1fc, 5, 3);
            D_5c5a[local_c]._0_tile = D_5c5a[local_c]._1 = 0xfc;

            /* FMT
                if (DAT_0003e08a_587a != 0x54) { // Icon != 0x54
                    return 0;
                }
                DAT_0003e08a_587a = 0; // Icon = 0
                FUN_00029d64_ULTIMA_5910_update_map();
                DAT_0003e08a_587a = 0x54; // Icon = 0x54
                return 0;
             */

            local_6 = 0;
        }
    }
    else
    {
        FUN_1000_1850_print_string(/*0x443c*/ "\nNo effect!\n");
    }

    return local_6;
}

// NOT MATCHING
// meditate
void F_CMDS_1202(int param_1, int param_2, int param_3)
{
    int local_14;
    bool local_16;
    char local_12[16];

    FUN_1000_1850_print_string(/*0x4450*/ "\nUpon what virtue\ndost thou\nmeditate?\n\n:");
    FUN_1000_3b1c_get_string(local_12, 0xf);

    local_16 = FUN_1000_6f1e((byte*)D_1f4e[param_1], local_12) != -1;

    for (local_14 = 0; local_14 < 3; local_14++)
    {
        FUN_1000_1850_print_string(/*0x4479*/ "\nMantra:");
        FUN_1000_3b1c_get_string(local_12, 0xf);

        if (FUN_1000_6f1e((byte*)D_1f5e[param_1], local_12) == -1)
        {
            local_16 = 0;
        }
    }

    if (local_16 && D_1f6e[param_1] == param_2 && D_1f76[param_1] == param_3)
    {
        D_58d8[param_1] &= 0x7f;
        FUN_1000_1850_print_string(/*0x4482*/ "\n\nThe Shrine is\nrestored!\n");
        FUN_1000_3072();
        *FUN_1000_4402_get_address_of_tile_id(param_2, param_3) = 0x19;
        D_24e6 |= 2;
    }
    else
    {
        FUN_1000_16ba_print_char(10);
    }
}

// NOT MATCHING
void F_CMDS_12c8(char* param_1)
{
    bool local_8;
    int local_4;
    int local_a;
    byte local_c;
    int local_6;

    local_8 = 0;

    for (local_4 = 0; local_4 < 4; local_4++)
    {
        if (FUN_1000_6f1e((byte*)D_4502[local_4], param_1) > -1)
        {
            FUN_1000_1850_print_string(/*0x44d7*/ "\nA word of power is uttered\n");
            FUN_1000_3072();

            local_c = D_ab02[0xa4];
            if (D_4512[local_4] == local_c || local_c == 0xdf || local_c == 0x1a)
            {
                local_6 = -1;
                local_a = 0;
            }
            else
            {
                local_c = D_ab02[0xc5];
                if (D_4512[local_4] == local_c || local_c == 0xdf || local_c == 0x1a)
                {
                    local_6 = 0;
                    local_a = 1;
                }
                else
                {
                    local_c = D_ab02[0xa6];
                    if (D_4512[local_4] == local_c || local_c == 0xdf || local_c == 0x1a)
                    {
                        local_6 = 1;
                        local_a = 0;
                    }
                    else
                    {
                        local_c = D_ab02[0x85];
                        if (D_4512[local_4] == local_c || local_c == 0xdf || local_c == 0x1a)
                        {
                            local_6 = 0;
                            local_a = -1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }

            if (local_c == 0x1a)
            {
                F_CMDS_1202(local_4, local_6 + (uint)D_5896_map_x, local_a + (uint)D_5897_map_y);
                return;
            }

            if (local_6 + (uint)D_5896_map_x == (uint)D_1e8a[local_4 + 0x20] &&
                local_a + (uint)D_5897_map_y == (uint)D_1eb2[local_4 + 0x20])
            {
                D_58d0[local_4] ^= 0x80;
                *FUN_1000_4402_get_address_of_tile_id(local_6 + D_5896_map_x, local_a + D_5897_map_y) ^=
                    D_4512[local_4] ^ 0xdf;
                D_24e6 |= 2;
            }
            local_8 = 1;
            break;
        }
    }

    if (!local_8)
    {
        FUN_1000_1850_print_string(/*0x44f4*/ "\nNo effect!\n");
    }
}

// NOT MATCHING
int F_CMDS_1418_yell_cmd(void)
{
    int local_24;
    char local_22[32];

    local_24 = 1;

    if ((D_587c & 0xf8) == 0x20 && D_5893_map_id < 0x80)
    {
        if ((D_587c & 0xfc) == 0x20)
        {
            FUN_1000_1850_print_string(/*0x451a*/ "FURL!\n");
            D_587c += 4;
        }
        else
        {
            FUN_1000_1850_print_string(/*0x4521*/ "HOIST!\n");
            D_587c -= 4;
        }
    }
    else
    {
        FUN_1000_1850_print_string(/*0x4529*/ "what?\n:");
        FUN_1000_3b1c_get_string(local_22, 0x1e);
        if (local_22[0] == 0)
        {
            FUN_1000_1850_print_string(/*0x4531*/ "Nothing\n");
        }
        else
        {
            FUN_1000_16ba_print_char(10);
            if (D_5893_map_id == 0 || 0x20 < D_5893_map_id)
            {
                if (D_5893_map_id == 0)
                {
                    F_CMDS_12c8(local_22);
                }
                else
                {
                    FUN_1000_1850_print_string(/*0x453a*/ "\nNo effect!\n");
                }
            }
            else
            {
                local_24 = F_CMDS_1030(local_22);
            }
        }
    }

    return local_24;
}

void F_CMDS_161a_push_cmd(void) { puts("F_CMDS_161a_push_cmd"); }

int F_CMDS_17ec(void) { puts("F_CMDS_17ec"); }

void F_CMDS_1ad8_mix_cmd(void) { puts("F_CMDS_1ad8_mix_cmd"); }

void F_CMDS_1c20_klimb_cmd(void) { puts("F_CMDS_1c20_klimb_cmd"); }
