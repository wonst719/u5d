#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <string.h>
#include <memory.h>

void F_NPC_0db4(int param_1);

void F_TOWN_0170(void);

void F_TOWN_1694(void);

void F_DNGLOOK_117e(int a, int b);

int F_COMBAT_0000(int param_1, int param_2, int param_3);

void F_OUTSUBS_0658(void);

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
        if (bVar2 == 0x1b || (bVar2 &= 0xfc, bVar2 == 0x1c) || bVar2 == 0x24 ||
            bVar2 == 0x10 || bVar2 == 0x28)
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

void F_CMDS_0aea_fire_cmd(void) { puts("F_CMDS_0aea_fire_cmd"); }

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

void F_CMDS_0ddc_new_order_cmd(void) { puts("F_CMDS_0ddc_new_order_cmd"); }

void F_CMDS_0eb4_xit_cmd(void) { puts("F_CMDS_0eb4_xit_cmd"); }

int F_CMDS_1418_yell_cmd(void) { puts("F_CMDS_1418_yell_cmd"); }

void F_CMDS_161a_push_cmd(void) { puts("F_CMDS_161a_push_cmd"); }

int F_CMDS_17ec(void) { puts("F_CMDS_17ec"); }

void F_CMDS_1ad8_mix_cmd(void) { puts("F_CMDS_1ad8_mix_cmd"); }

void F_CMDS_1c20_klimb_cmd(void) { puts("F_CMDS_1c20_klimb_cmd"); }
