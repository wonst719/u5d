#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>

void F_CAST2_0000(int);
int F_CAST2_009e(void);
int F_CAST2_00de(void);
int F_CAST2_0306(void);
int F_CAST2_03c2(int);
void F_CAST2_040a(int, int);
void F_CAST2_046c(void);
int F_CAST2_04c2(int);
int F_CAST2_05e0(int, int);
void F_CAST2_06ec(void);
int F_CAST2_0768(void);
int F_CAST2_07bc(int);
void F_CAST2_08ea(int);
void F_CAST2_08f8(int, int, int);

void F_LOOKOBJ_10fc_view_cmd(int, int);
void F_DNGLOOK_06a8_view_cmd(void);

int F_DUNGEON_1c6a(int, int);
void F_DUNGEON_1d08(void);

int F_COMBAT_0000(int, int, int);
int F_COMBAT_120e(void);
void F_COMBAT_18ba(int, int);

void F_MAINOUT_0000(void);

int F_COMBAT_13e2(int, int);
int F_COMBAT_1574(int param_1, int param_2);

int F_COMSUBS_0000(int, int, int);
void F_COMSUBS_0094(int a);
void F_COMSUBS_0312(int a, int b);
int F_COMSUBS_0504(int a, int b);
int F_COMSUBS_0748(int a, int b);
void F_COMSUBS_0c52(int param_1, int param_2);
void F_COMBAT_1236(int a);

int F_TOWN_011e(int);
void F_TOWN_00b0(int);

void F_ZSTATS_045e(int param_1);
int F_ZSTATS_05a4(int param_4, int param_3, byte* param_2, int param_1);
void F_ZSTATS_099a(void);
int F_ZSTATS_0f2e(int param_3, undefined2 param_2, int param_1);

void F_CAST_04a4(void);

void F_LOOKOBJ_0366(void);

// NOT MATCHING
int F_CAST_0000(int param_1)
{
    byte cVar1;
    int uVar2;

    cVar1 = D_ba14[param_1]._3;
    if (cVar1 == 47 || cVar1 == 0xe || cVar1 == 0xf)
    {
        uVar2 = 1;
    }
    else
    {
        uVar2 = 0;
    }

    return uVar2;
}

// NOT MATCHING
void F_CAST_0032(int param_1)
{
    D_589d = param_1;
    F_COMSUBS_0c52(D_589e, param_1);
}

// NOT MATCHING
int F_CAST_004c(int param_1)
{
    byte bVar1;
    int uVar2;
    uint uVar3;
    uint uVar4;

    if (D_5893_map_id < 0x80)
    {
        if (param_1 == 3)
        {
            uVar2 = 4;
        }
        else
        {
            uVar2 = 3;
        }

        F_CAST2_0000(uVar2);
        uVar3 = (D_24d6[D_6603] + D_5896_map_x) & 7;
        uVar4 = (D_24de[D_6603] + D_5897_map_y) & 7;

        bVar1 = D_595a[D_5895_map_level * 0x40 + uVar4 * 8 + uVar3];
        if ((bVar1 & 0xf7) != 0)
        {
            return 0;
        }

        D_595a[D_5895_map_level * 0x40 + uVar4 * 8 + uVar3] = (bVar1 & 8) | D_4596[param_1];
    }
    else
    {
        D_589d = D_4592[param_1];
        F_COMSUBS_0c52(D_589e, D_589d);
    }

    return -1;
}

// NOT MATCHING
int F_CAST_0114(void)
{
    int uVar1;
    int iVar2;
    int local_4;

    uVar1 = F_CAST2_009e();
    if (uVar1 < 0)
    {
        local_4 = -1;
    }
    else if (D_55a8_party[uVar1]._b == 0x53)
    {
        D_55a8_party[uVar1]._b = 0x47;
        if (D_5893_map_id > 0x7f)
        {
            for (iVar2 = 0; iVar2 < 0x20; iVar2++)
            {
                if ((D_ba14[iVar2]._2 & 0xe8) == 0x88 && D_ba14[iVar2]._3 == uVar1)
                {
                    FUN_1000_6800(iVar2);
                    break;
                }
            }
        }
        F_CAST2_0000(1);
        local_4 = -1;
        D_a9fa = 1;
    }
    else
    {
        local_4 = 0;
    }

    return local_4;
}

// NOT MATCHING
int F_CAST_01ae(void)
{
    int local_4;

    if (F_CAST2_009e() < 0)
    {
        local_4 = -1;
    }
    else
    {
        if (D_55a8_party[0]._b == 'P')
        {
            D_55a8_party[0]._b = 'G';
            F_CAST2_0000(1);
            D_a9fa = 1;
            local_4 = 1;
        }
        else
        {
            local_4 = 0;
        }
    }

    return local_4;
}

// NOT MATCHING
int F_CAST_01fa(void)
{
    int iVar1;
    int local_4;

    iVar1 = F_CAST2_009e();
    if (iVar1 < 0)
    {
        local_4 = -1;
    }
    else
    {
        local_4 = F_CAST2_03c2(iVar1);
    }

    if (local_4 != 0)
    {
        F_CAST2_0000(1);
    }

    return local_4;
}

// NOT MATCHING
int F_CAST_0230(void)
{
    byte* pbVar2;

    if (F_CAST2_0306() != 0)
    {
        F_CAST2_0000(1);
        pbVar2 = FUN_1000_4402_get_address_of_tile_id(D_5876, D_5878);
        switch (*pbVar2)
        {
        case 0x5b:
        case 0x90:
        case 0x91:
        case 0x92:
        case 0x93:
        case 0x9d:
        case 0xa5:
        case 0xa6:
        case 0xa8:
        case 0xa9:
        case 0xad:
        case 0xae:
        case 0xaf:
            *pbVar2 = 0x44;
            FUN_1000_1850_print_string(/*0x459a*/ "POOF!\n");
            D_24e6 |= 2;
            FUN_1000_5910_update_map();
            FUN_1000_43ae(0x4b0, 2000, 1, 0x28);
            break;

        default:
            return 0;
        }
    }

    return -1;
}

// NOT MATCHING
int F_CAST_02d2(void)
{
    int iVar1;
    byte* pcVar2;
    int local_a;
    int local_8;
    byte* local_4;

    if (D_5893_map_id < 0x21 || D_5893_map_id > 0x7f)
    {
        iVar1 = F_CAST2_0306();
        if (iVar1 == 0)
        {
            local_8 = -1;
        }
        else
        {
            local_8 = 0;
            pcVar2 = FUN_1000_4402_get_address_of_tile_id(D_5876, D_5878);
            if (*pcVar2 == 0xb9 || *pcVar2 == 0xbb)
            {
                *pcVar2 = *pcVar2 - 1;
                D_24e6 |= 2;
                F_CAST2_0000(2);
                local_8 = 1;
            }
            else
            {
                for (local_a = 0; local_a < 0x20; local_a++)
                {
                    if (D_5c5a[local_a]._0_tile == 1 && D_5c5a[local_a]._2_x == D_5876 &&
                        D_5c5a[local_a]._3_y == D_5878 &&
                        (D_5893_map_id > 0x7f || D_5c5a[local_a]._4_z == D_5895_map_level))
                    {
                        D_5c5a[local_a]._5 &= 0x7f;
                        F_CAST2_0000(2);
                        return 1;
                    }
                }
            }
        }
    }
    else
    {
        F_CAST2_0000(2);

        local_4 = &D_595a[D_5895_map_level * 0x40 + D_5897_map_y * 8 + D_5896_map_x];
        if ((*local_4 & 0xf0) != 0x40)
        {
            local_4 = &D_595a[(D_24de[D_6603] + D_5897_map_y & 7) * 8 + (D_24d6[D_6603] + D_5896_map_x & 7) +
                              D_5895_map_level * 0x40];
        }

        if ((*local_4 & 0xf0) == 0x40)
        {
            if ((*local_4 & 1) != 0)
            {
                FUN_1000_1850_print_string(/*0x45a1*/ "Disarmed!\n");
            }

            *local_4 = (*local_4 & 8) | 0x70;
            FUN_1000_1850_print_string(/*0x45ac*/ "Chest opened!\n");

            local_8 = -1;
        }
        else
        {
            local_8 = 0;
        }
    }

    return local_8;
}

// NOT MATCHING
void F_CAST_043e(void)
{
    int iVar2;

    F_CAST2_0000(2);

    for (iVar2 = 0; iVar2 < 0x20; iVar2++)
    {
        if (F_CAST_0000(iVar2) == 0 && (D_ba14[iVar2]._2 & 0xc0) == 0x40 &&
            ((byte)D_153c[D_ba14[iVar2]._3] & 0x20) != 0)
        {
            if (F_COMSUBS_0000(D_589e, iVar2, 0) == 0)
            {
                D_ba14[iVar2]._0 = 1;
                D_ba14[iVar2]._2 |= 2;
            }
        }
    }
}

// OK P1
void F_CAST_04a4(void)
{
    F_CAST2_0000(2);
    F_CAST2_06ec();
}

// NOT MATCHING
int F_CAST_04b0(void)
{
    byte cVar2;
    int iVar3;
    int local_c;
    int local_4;

    F_CAST2_0000(2);

    iVar3 = FUN_1000_2092_random_range(0, 0xf);
    if (iVar3 < 6)
    {
        local_4 = 0x14;
    }
    else if (iVar3 < 0xb)
    {
        local_4 = 0x16;
    }
    else if (iVar3 < 0xe)
    {
        local_4 = 0x15;
    }
    else
    {
        local_4 = 0x22;
    }

    local_c = 0;
    while (F_COMBAT_120e() == 0 || F_COMBAT_0000(0x90, D_5876, D_5878) == 0)
    {
        local_c++;
        if (local_c > 7)
        {
            return 0;
        }
    }

    iVar3 = FUN_1000_6506(local_4, 0, D_5876, D_5878, D_5895_map_level);
    if (iVar3 < 0)
    {
        return 0;
    }

    D_5c5a[D_ba14[iVar3]._4]._0_tile = 0x16;
    D_5c5a[D_ba14[iVar3]._4]._1 = 0x16;
    FUN_1000_1068(local_4 * 4 + 0x140, D_5876, D_5878);
    cVar2 = local_4 * 4 + 64;
    D_5c5a[D_ba14[iVar3]._4]._0_tile = cVar2;
    D_5c5a[D_ba14[iVar3]._4]._1 = cVar2;
    D_ba14[iVar3]._2 |= 1;

    return 1;
}

// OK P1
int F_CAST_05b4(void)
{
    F_CAST2_0000(2);
    FUN_1000_3f14(&D_57a8, FUN_1000_2092_random_range(1, 3), 9999);
    D_a9fa = 1;
    return 1;
}

// NOT MATCHING
int F_CAST_05dc(void)
{
    byte uVar1;
    byte bVar2;
    byte bVar3;
    int iVar4;
    int iVar5;
    int uVar7;
    int iVar8;
    int uVar9;
    int local_10;
    int local_e;
    int local_c;

    local_c = 0;
    if (D_5893_map_id < 0x80)
    {
        iVar5 = F_CAST2_0306();
        if (iVar5 == 0)
        {
            local_c = -1;
        }
        else
        {
            F_CAST2_0000(3);

            iVar5 = D_5876;
            bVar2 = D_5896_map_x;
            iVar8 = D_5878;
            bVar3 = D_5897_map_y;

            local_e = D_589b + 0x20;
            if (local_e > 0x100)
            {
                local_e = 0x100;
            }

            local_10 = D_589c + 0x20;
            if (local_10 > 0x100)
            {
                local_10 = 0x100;
            }

            local_c = 0;
            uVar7 = D_5876;
            for (uVar9 = D_5878; D_589b <= uVar7 && uVar7 < local_e && D_589c <= uVar9 && uVar9 < local_10;
                 uVar9 += iVar8 - bVar3)
            {
                if (*FUN_1000_4402_get_address_of_tile_id(uVar7, uVar9) == 5)
                {
                    local_c = -1;
                    D_5896_map_x = uVar7;
                    D_5897_map_y = uVar9;
                    D_24e6 = 1;
                }
                uVar7 += iVar5 - bVar2;
            }

            if (local_c != 0)
            {
                F_MAINOUT_0000();
            }
        }
    }
    else
    {
        if ((D_58a1 & 2) == 0)
        {
            F_CAST2_0000(3);
            uVar1 = D_5c5a[D_ba14[D_589e]._4]._0_tile;
            for (iVar8 = 0; iVar8 < 7; iVar8++)
            {
                iVar4 = F_COMBAT_120e();
                if (iVar4 != 0 && F_COMBAT_0000(uVar1, D_5876, D_5878) != 0)
                {
                    uVar1 = D_5876;
                    D_ba14[D_589e]._6 = uVar1;
                    D_5c5a[D_ba14[D_589e]._4]._2_x = uVar1;

                    uVar1 = D_5878;
                    D_ba14[D_589e]._7 = uVar1;
                    D_5c5a[D_ba14[D_589e]._4]._3_y = uVar1;
                    return 1;
                }
            }
        }
        else
        {
            local_c = 0;
        }
    }
    return local_c;
}

// NOT MATCHING
void F_CAST_074c(void)
{
    int local_c;

    F_CAST2_0000(4);

    for (local_c = 0; local_c < 0x20; local_c++)
    {
        if (D_ba14[local_c]._2 != 0 && (D_ba14[local_c]._2 & 0x80) == 0 && (D_ba14[local_c]._2 & 0x10) != 0)
        {
            D_ba14[local_c]._2 &= 0xef;
            D_5c5a[D_ba14[local_c]._4]._1 = D_5c5a[D_ba14[local_c]._4]._0_tile;

            FUN_1000_5394();
            FUN_1000_56ac_draw_map();
        }
    }
}

// NOT MATCHING
int F_CAST_07b4(void)
{
    int iVar2;
    int iVar3;
    int local_6;

    F_CAST2_0000(5);
    local_6 = 0;
    iVar3 = 0;
    while (F_COMBAT_120e() == 0 || F_COMBAT_0000(0xbc, D_5876, D_5878) == 0)
    {
        iVar3++;
        if (iVar3 > 7)
        {
        LAB_0000_07ed:
            if (local_6 != 0)
            {
                local_6 = 0;

                for (iVar3 = 0; iVar3 < 4; iVar3++)
                {
                    iVar2 = FUN_1000_6506(0x1f, 0, D_5876, D_5878, D_5895_map_level);
                    if (iVar2 < 0)
                    {
                        return local_6;
                    }

                    D_ba14[iVar2]._2 |= 1;
                    local_6 = 1;
                }
            }

            return local_6;
        }
    }

    local_6 = 1;
    goto LAB_0000_07ed;
}

// NOT MATCHING
int F_CAST_0846(void)
{
    int uVar2;
    byte* pbVar3;

    if (F_CAST2_0306() == 0)
    {
        uVar2 = -1;
    }
    else
    {
        F_CAST2_0000(5);
        pbVar3 = FUN_1000_4402_get_address_of_tile_id(D_5876, D_5878);
        uVar2 = 0;
        switch (*pbVar3)
        {
        case 0xb8:
        case 0xb9:
            *pbVar3 = 0x97;
            break;

        case 0xba:
        case 0xbb:
            *pbVar3 = 0x98;
            break;

        default:
            return uVar2;
        }

        uVar2 = 1;
        D_24e6 |= 2;
    }

    return uVar2;
}

// NOT MATCHING
int F_CAST_08ac(void)
{
    int iVar1;
    int local_4;

    iVar1 = F_CAST2_009e();
    if (iVar1 < 0)
    {
        local_4 = -1;
    }
    else if (D_55a8_party[iVar1]._b == 'D' || (0x7f < D_5893_map_id && D_58a3 == 0) ||
             (0x7f < D_5893_map_id && D_58a3 == 0)) // sic
    {
        local_4 = 0;
    }
    else
    {
        D_55a8_party[iVar1]._10 = D_55a8_party[iVar1]._12;
        F_CAST2_0000(5);
        D_a9fa = 1;
        local_4 = 1;
    }

    return local_4;
}

// NOT MATCHING
void F_CAST_091e(int param_1)
{
    int uVar3;
    int iVar4;

    F_CAST2_0000(6);
    FUN_1000_3072();
    for (iVar4 = 0; iVar4 < 0x20; iVar4++)
    {
        if (D_ba14[iVar4]._2 != 0)
        {
            if (FUN_1000_5646(iVar4) != 0)
            {
                if (F_COMBAT_13e2(iVar4, -2) <= FUN_1000_3abe())
                {
                    FUN_1000_3564(iVar4);
                    uVar3 = FUN_1000_2092_random_range(1, 0x14);
                    uVar3 = F_COMBAT_1574(iVar4, uVar3);
                    FUN_1000_3f14(&D_55a8_party[param_1]._14, uVar3, 9999); // FMT: &local_8 ??
                    F_COMSUBS_0312(iVar4, D_589e);
                }
            }
        }
    }
}

// NOT MATCHING
int F_CAST_09a0(void)
{
    int iVar1;

    FUN_1000_1850_print_string(/*0x45bb*/ "Creature: ");
    if (F_COMSUBS_0504(D_589e, 0xf) == 0)
    {
        return -1;
    }

    F_CAST2_0000(6);
    if ((*FUN_1000_4402_get_address_of_tile_id(D_5899, D_589a) & 0xfe) != 0x84)
    {
        iVar1 = F_COMSUBS_0748(D_5899, D_589a);
        if (iVar1 > -1)
        {
            if (F_CAST_0000(iVar1) == 0)
            {
                if (FUN_1000_5646(iVar1) != 0)
                {
                    if (F_COMSUBS_0000(D_589e, iVar1, 0) == 0)
                    {
                        D_ba14[iVar1]._2 ^= 1;
                        if ((D_ba14[iVar1]._2 & 0x80) != 0)
                        {
                            D_55a8_party[D_ba14[iVar1]._3]._b = 0x47;
                            FUN_1000_2900_update_vitals();
                        }

                        F_COMSUBS_0094(iVar1);
                        FUN_1000_1850_print_string(/*0x45c6*/ " charmed!\n");

                        return -1;
                    }
                }
            }
        }
    }

    return 0;
}

// NOT MATCHING
int F_CAST_0a5c(void)
{
    undefined1 uVar1;
    undefined1 uVar2;
    int iVar3;

    FUN_1000_1850_print_string(/*0x45d1*/ "Creature: ");
    if (F_COMSUBS_0504(D_589e, 0xf) == 0)
    {
        return -1;
    }

    F_CAST2_0000(6);
    iVar3 = F_COMSUBS_0748(D_5899, D_589a);
    if (iVar3 > -1 && F_CAST_0000(iVar3) == 0 && F_COMSUBS_0000(D_589e, iVar3, 0) == 0)
    {
        uVar1 = D_ba14[iVar3]._6;
        uVar2 = D_ba14[iVar3]._7;
        F_COMBAT_1236(-1 - iVar3);
        FUN_1000_6506(0x14, 0, uVar1, uVar2, D_5895_map_level);
        return 1;
    }

    return 0;
}

// NOT MATCHING
int F_CAST_0afe(void)
{
    D_5c5a[D_ba14[D_589e]._4]._1 = 0x1d;
    D_ba14[D_589e]._2 |= 0x10;
    F_CAST2_0000(7);
    return 1;
}

// NOT MATCHING
int F_CAST_0b28(void)
{
    undefined1 uVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int local_8;

    FUN_1000_1850_print_string(/*0x45dc*/ "Creature: ");
    iVar2 = F_COMSUBS_0504(D_589e, 0xf);
    if (iVar2 == 0)
    {
        local_8 = -1;
    }
    else
    {
        F_CAST2_0000(7);
        iVar2 = F_COMSUBS_0748(D_5899, D_589a);
        if (iVar2 < 0)
        {
            local_8 = 0;
        }
        else
        {
            iVar4 = 0xff;
            for (iVar5 = 0; iVar5 < 0x20; iVar5++)
            {
                if (D_5c5a[iVar5]._0_tile == 0)
                {
                    iVar4 = iVar5;
                    break;
                }
            }

            if (iVar4 != 0xff)
            {
                iVar3 = 0xff;
                for (iVar5 = 0; iVar5 < 0x20; iVar5++)
                {
                    if (D_ba14[iVar5]._2 == 0)
                    {
                        iVar3 = iVar5;
                        break;
                    }
                }

                if (iVar3 != 0xff)
                {
                    D_ba14[iVar3]._0 = D_ba14[iVar2]._0;
                    D_ba14[iVar3]._2 = D_ba14[iVar2]._2;
                    D_ba14[iVar3]._4 = D_ba14[iVar2]._4;
                    D_ba14[iVar3]._6 = D_ba14[iVar2]._6;

                    D_ba14[iVar3]._4 = iVar4;

                    D_5c5a[iVar4]._0_tile = D_5c5a[D_ba14[iVar2]._4]._0_tile;
                    D_5c5a[iVar4]._2_x = D_5c5a[D_ba14[iVar2]._4]._2_x;
                    D_5c5a[iVar4]._4_z = D_5c5a[D_ba14[iVar2]._4]._4_z;
                    D_5c5a[iVar4]._6 = D_5c5a[D_ba14[iVar2]._4]._6;

                    do
                    {
                        iVar2 = F_COMBAT_120e();
                        if (iVar2 == 0 || F_COMBAT_0000(0x1c, D_5876, D_5878) == 0)
                        {
                            local_8 = 0;
                        }
                        else
                        {
                            uVar1 = D_5876;
                            D_ba14[iVar3]._6 = uVar1;
                            D_5c5a[iVar4]._2_x = uVar1;
                            uVar1 = D_5878;
                            D_ba14[iVar3]._7 = uVar1;
                            D_5c5a[iVar4]._3_y = uVar1;
                            local_8 = 1;
                        }
                    } while (local_8 == 0);
                }
            }
        }
    }

    return local_8;
}

// NOT MATCHING
void F_CAST_0c98(void)
{
    int iVar2;

    F_CAST2_0000(7);

    for (iVar2 = 0; iVar2 < 0x20; iVar2++)
    {
        if ((D_ba14[iVar2]._2 & 0xc0) == 0x40)
        {
            if (F_CAST_0000(iVar2) == 0)
            {
                if (F_COMSUBS_0000(D_589e, iVar2, 0) == 0)
                {
                    D_ba14[iVar2]._0 = 1;
                    D_ba14[iVar2]._2 |= 2;
                }
            }
        }
    }
}

// NOT MATCHING
int F_CAST_0cf0(void)
{
    byte bVar1;

    if ((D_587c & 0xf0) != 0x20)
    {
        FUN_1000_1850_print_string(/*0x45e7*/ "To phase: ");
        bVar1 = FUN_1000_266c_get_ch();
        if (bVar1 > 0x1f)
        {
            FUN_1000_16ba_print_char(bVar1);
        }

        FUN_1000_16ba_print_char(10);

        if (bVar1 > 0x30 && bVar1 < 0x39)
        {
            F_CAST2_0000(8);
            if (FUN_1000_47f4((byte)(bVar1 - 0x31)) != 0)
            {
                return -1;
            }
        }
    }

    return 0;
}

// NOT MATCHING
int F_CAST_0d4c(void)
{
    int iVar2;
    int local_6;

    F_CAST2_0000(8);
    local_6 = -1;

    for (iVar2 = 0; iVar2 < 0x20; iVar2++)
    {
        if (D_5c5a[iVar2]._0_tile == 0xfc)
        {
            FUN_1000_1850_print_string(/*0x45f2*/ "Magic absorbed!\n");
            FUN_1000_2192_audio_some_noise(0x2648, 1, 28000, 1000, 2);
            local_6 = 0;
            break;
        }
    }

    if (local_6 != 0)
    {
        D_587a = 0x54;
        D_588e = 10;
        FUN_1000_2900_update_vitals();
    }

    return local_6;
}

void F_CAST_1f60(int param_1, int param_2, int param_3);

// NOT MATCHING
int F_CAST_0dba_cast_spell_cmd(void)
{
    int iVar1;
    int iVar2;
    uint uVar3;
    bool bVar4;
    int iVar7;
    undefined2 uVar10;

    uVar10 = 1;
    D_588f = 1;
    D_5890 = 1;
    iVar7 = 1;
    iVar1 = FUN_1000_4988();
    if (iVar1 < 0)
    {
        return iVar1;
    }

    FUN_1000_1850_print_string(/*0x4603*/ "Spell name:\n:");
    iVar2 = F_CAST2_00de();
    if (iVar2 == -1)
    {
        FUN_1000_1850_print_string(/*0x4611*/ "None!\n");
        return; // sic
    }

    if (iVar2 == -2)
    {
        FUN_1000_1850_print_string(/*0x4618*/ "No effect!\n");
        return; // sic
    }

    uVar3 = iVar2 / 6 + 1;
    D_588f = (char)uVar3;
    if (D_5893_map_id == 0)
    {
        bVar4 = (*(iVar2 + D_1c90) & 8) == 0;
    }
    else if (D_5893_map_id < 0x80)
    {
        if (((D_5893_map_id == 0x12) && (D_57b4 == 0)) || (D_5893_map_id == 0x1d))
        {
            FUN_1000_1850_print_string(/*0x4624*/ "Absorbed!\n");
            FUN_1000_2192_audio_some_noise(0x2648, 1, 28000, 1000, 2);
            return; // sic
        }

        if (D_5893_map_id < 0x21)
        {
            bVar4 = (*(iVar2 + D_1c90) & 4) == 0;
        }
        else
        {
            bVar4 = (*(iVar2 + D_1c90) & 2) == 0;
        }
    }
    else
    {
        bVar4 = (*(iVar2 + D_1c90) & 1) == 0;
    }

    if (bVar4)
    {
        iVar7 = 0;
    }

    if (iVar7 == 0)
    {
        FUN_1000_1850_print_string(/*0x462f*/ "Not here!\n");
        return FUN_1000_43ae(800, 2000, 1, 0x32);
    }

    if (D_57f0[iVar2] == 0)
    {
        FUN_1000_1850_print_string(/*0x463a*/ "None mixed!\n");
        return; // sic
    }

    D_57f0[iVar2]--;
    if (D_55a8_party[iVar1]._f < uVar3)
    {
        FUN_1000_1850_print_string(/*0x4647*/ "M.P. too low!\n");
        iVar7 = 0;
        goto switchD_ce9a_default;
    }

    D_55a8_party[iVar1]._f -= uVar3;
    iVar7 = -1;
    if (D_55a8_party[iVar1]._16 < uVar3)
    {
        iVar7 = 0;
        goto switchD_ce9a_default;
    }

    switch (iVar2)
    {
    case 0:
        F_CAST2_08ea(100);
        F_CAST2_0000(1);
        break;
    case 1:
        F_CAST_0032(0x30);
        break;
    case 2:
        iVar7 = F_CAST_0114();
        break;
    case 3:
        iVar7 = F_CAST_01ae();
        break;
    case 4:
        iVar7 = F_CAST_01fa();
        break;
    case 5:
        iVar7 = F_CAST_0230();
        break;
    case 6:
        iVar7 = F_CAST_02d2();
        break;
    case 7:
        F_CAST_043e();
        break;
    case 8:
        F_CAST2_040a(F_CAST2_0306(), 0);
        break;
    case 9:
        F_CAST_04a4();
        break;
    case 10:
        iVar7 = F_CAST_04b0();
        break;
    case 0xb:
        iVar7 = F_CAST_05b4();
        break;
    case 0xc:
        F_CAST2_08ea(0xff);
        F_CAST2_0000(3);
        break;
    case 0xd:
        F_CAST_0032(0x31);
        break;
    case 0xe:
        iVar7 = F_CAST_004c(0);
        break;
    case 0xf:
        iVar7 = F_CAST_004c(1);
        break;
    case 0x10:
        iVar7 = F_CAST_004c(2);
        break;
    case 0x11:
        iVar7 = F_CAST_05dc();
        break;
    case 0x12:
        iVar7 = F_CAST2_07bc(1);
        break;
    case 0x13:
        F_CAST2_08f8(0x50, 0x14, 4);
        break;
    case 0x14:
        iVar7 = F_CAST_004c(3);
        break;
    case 0x15:
        if (D_5893_map_id == 40)
        {
            iVar7 = 0;
            break;
        }

        F_CAST2_0000(4);
        if (F_DUNGEON_1c6a(-1, 1) != 0)
        {
            F_DUNGEON_1d08();
        }
        break;
    case 0x16:
        if (D_5893_map_id == 40)
        {
            iVar7 = 0;
            break;
        }

        F_CAST2_0000(4);
        if (F_DUNGEON_1c6a(1, 1) != 0)
        {
            F_DUNGEON_1d08();
        }
        break;
    case 0x17:
        F_CAST_074c();
        break;
    case 0x18:
        iVar7 = F_CAST_07b4();
        break;
    case 0x19:
        iVar7 = F_CAST_0846();
        break;
    case 0x1a:
        iVar7 = F_CAST2_0768();
        if (iVar7 == -1)
            break;
        F_CAST2_0000(5);
        break;
    case 0x1b:
        iVar7 = F_CAST_08ac();
        break;
    case 0x1c:
        F_CAST_1f60(D_589e, 1, D_13b6);
        break;
    case 0x1d:
        F_CAST2_08f8(0x51, 0x1e, 5);
        break;
    case 0x1e:
        F_CAST_091e(iVar1);
        break;
    case 0x1f:
        F_CAST2_08f8(0x43, 0x14, 6);
        break;
    case 0x20:
        F_CAST2_08f8(0x4e, 10, 6);
        break;
    case 0x21:
        F_CAST2_0000(6);
        F_CAST2_046c();
        break;
    case 0x22:
        iVar7 = F_CAST_09a0();
        break;
    case 0x23:
        iVar7 = F_CAST_0a5c();
        break;
    case 0x24:
        iVar7 = F_CAST_0b28();
        break;
    case 0x25:
        F_CAST_0032(0x32);
        break;
    case 0x26:
        iVar7 = F_CAST_0b28();
        break;
    case 0x27: // view?
        F_CAST2_0000(7);
        if (D_5893_map_id < 0x21)
        {
            F_LOOKOBJ_10fc_view_cmd(D_5896_map_x, D_5897_map_y);
        }
        else
        {
            F_DNGLOOK_06a8_view_cmd();
        }
        break;
    case 0x28:
        F_CAST_1f60(D_589e, 2, D_13b4);
        break;
    case 0x29:
        F_CAST_0c98();
        break;
    case 0x2a:
        F_CAST2_05e0(F_CAST2_009e(), 0);
        FUN_1000_2900_update_vitals();
        break;
    case 0x2b:
        iVar7 = F_CAST2_04c2(0);
        break;
    case 0x2c:
        F_CAST_1f60(D_589e, 4, D_13b2_frame_color);
        break;
    case 0x2d:
        F_CAST_1f60(D_589e, 3, D_13ae);
        break;
    case 0x2e:
        iVar7 = F_CAST_0cf0();
        if (iVar7 != 0)
        {
            uVar10 = 0;
        }
        break;
    case 0x2f:
        iVar7 = F_CAST_0d4c();
        break;
    }

switchD_ce9a_default:
    if (iVar7 == 1)
    {
        FUN_1000_1850_print_string(/*0x4656*/ "Success!\n");
    }
    else if (iVar7 == 0)
    {
        FUN_1000_1850_print_string(/*0x4660*/ "Failed!\n");
        FUN_1000_43ae(800, 2000, 1, 0x32);
    }

    return uVar10;
}

// NOT MATCHING
int F_CAST_11de(int param_1)
{
    int uVar1;

    D_5820[param_1]--;
    FUN_1000_1850_print_string(/*0x466a*/ "Scroll\n\n");
    switch (param_1)
    {
    case 0:
        F_CAST2_08ea(0xf0);
        FUN_1000_1850_print_string(/*0x4673*/ "Light!\n");
        F_CAST2_0000(0);
        return 1;

    case 1:
        FUN_1000_1850_print_string(/*0x467b*/ "Wind change!\n");
        uVar1 = F_CAST2_0306();
        if (D_5893_map_id < 0x21)
        {
            F_CAST2_040a(uVar1, 1);
            return 1;
        }
        return 0;

    case 2:
        FUN_1000_1850_print_string(/*0x4689*/ "Protection!\n");
        F_CAST2_08f8(0x50, 100, 2);
        break;

    case 3:
        FUN_1000_1850_print_string(/*0x4696*/ "Negate magic!\n");
        F_CAST2_08f8(0x4e, 0x14, 3);
        break;

    case 4:
        FUN_1000_1850_print_string(/*0x46a5*/ "View!\n");
        if (D_5893_map_id < 0x80)
        {
            F_CAST2_0000(4);
            if (D_5893_map_id < 0x21)
            {
                F_LOOKOBJ_10fc_view_cmd(D_5896_map_x, D_5897_map_y);
                return 1;
            }
            F_DNGLOOK_06a8_view_cmd();
            return 1;
        }
        FUN_1000_1850_print_string(/*0x46ac*/ "Not here!\n");
        return 1;

    case 5:
        FUN_1000_1850_print_string(/*0x46b7*/ "Summon Daemon!\n");
        if (0x7f < D_5893_map_id)
        {
            uVar1 = F_CAST2_04c2(1);
            return uVar1;
        }
        FUN_1000_1850_print_string(/*0x46c7*/ "Not here!\n");
        return 1;

    case 6:
        FUN_1000_1850_print_string(/*0x46d2*/ "Resurrection!\n");
        if (D_5893_map_id < 0x80)
        {
            uVar1 = F_CAST2_05e0(F_CAST2_009e(), 1);
            FUN_1000_2900_update_vitals();
            return uVar1;
        }
        FUN_1000_1850_print_string(/*0x46e1*/ "Not here!\n");
        return 1;

    case 7:
        if ((D_5893_map_id == 0x1d) || (D_5893_map_id == 0x28))
        {
            FUN_1000_1850_print_string(/*0x46ec*/ "No effect!\n");
            FUN_1000_43ae(800, 2000, 1, 0x32);
            return 1;
        }
        FUN_1000_1850_print_string(/*0x46f8*/ "Negate time!\n");
        F_CAST2_08f8(0x54, 0x14, 7);
        break;
    }

    return 1;
}

// NOT MATCHING
int F_CAST_135a(int param_1)
{
    byte bVar2;
    int iVar4;
    int uVar5;
    int local_a;
    int local_8;

    local_8 = 1;
    (D_5828)[param_1]--;
    FUN_1000_1850_print_string(/*0x4706*/ "Potion\n");
    if (D_5893_map_id < 0x80)
    {
        local_a = F_CAST2_009e();
    }
    else
    {
        local_a = D_ba14[D_589e]._3;
    }

    if (local_a < 0)
    {
        return local_a;
    }

    F_CAST2_0000(param_1);
    iVar4 = FUN_1000_2092_random_range(0, 0xf);
    if (iVar4 == 0)
    {
        param_1 = 4;
    }
    else if (iVar4 == 1)
    {
        param_1 = FUN_1000_2092_random_range(0, 7);
    }

    switch (param_1)
    {
    case 0:
        if (D_55a8_party[local_a]._b != 'S')
        {
            return 0;
        }
        D_55a8_party[local_a]._b = 'G';

        if (D_5893_map_id < 0x80)
        {
            FUN_1000_2900_update_vitals();
            return local_8;
        }

        uVar5 = (uint)D_589e;
        if (local_a != D_ba14[uVar5]._3)
        {
            return 0;
        }

        if ((D_ba14[uVar5]._2 & 0xe8) != 0x88)
        {
            return 0;
        }

        FUN_1000_6800(uVar5);
        return 1;

    case 1:
        iVar4 = F_CAST2_03c2(local_a);
        if (iVar4 == 0)
        {
            return 0;
        }

        FUN_1000_1850_print_string(/*0x470e*/ "Healed!\n");
        FUN_1000_2900_update_vitals();
        break;

    case 2:
        if (D_55a8_party[local_a]._b != 'P')
        {
            return 0;
        }
        D_55a8_party[local_a]._b = 'G';

        FUN_1000_1850_print_string(/*0x4717*/ "Poison cured!\n");
        FUN_1000_2900_update_vitals();
        break;

    case 3:
        if (D_55a8_party[local_a]._b != 'G')
        {
            return 0;
        }
        D_55a8_party[local_a]._b = 'P';

        FUN_1000_1850_print_string(/*0x4726*/ "POISONED!\n");
        FUN_1000_2900_update_vitals();
        break;

    case 4:
        if (D_55a8_party[local_a]._b != 'G')
        {
            return 0;
        }

        if (D_5893_map_id < 0x80)
        {
            D_55a8_party[local_a]._b = 'S';
        }
        else
        {
            FUN_1000_68ae(local_a);
        }

        FUN_1000_1850_print_string(/*0x4731*/ "Slept!\n");
        FUN_1000_2900_update_vitals();
        break;

    case 5:
        if (0x7f < D_5893_map_id)
        {
            FUN_1000_1850_print_string(/*0x4739*/ "Poof!\n");
            bVar2 = D_ba14[(uint)D_589e]._4;
            D_5c5a[bVar2]._0_tile = D_5c5a[bVar2]._1 = 0x90;
            return 1;
        }

        FUN_1000_1850_print_string(/*0x474c*/ "\nNo noticeable effect now!\n");
        break;

    case 6:
        if (0x7f < D_5893_map_id)
        {
            local_a = (uint)D_589e;
            D_ba14[local_a]._2 |= 0x10;
            bVar2 = D_ba14[local_a]._4;
            FUN_1000_1850_print_string(/*0x4740*/ "Invisible!\n");
            D_5c5a[bVar2]._0_tile = D_5c5a[bVar2]._1 = 0x1d;
            return 1;
        }

        FUN_1000_1850_print_string(/*0x474c*/ "\nNo noticeable effect now!\n");
        break;

    case 7:
        if (D_5893_map_id < 0x21)
        {
            F_CAST2_046c();
            return 1;
        }

        FUN_1000_1850_print_string(/*0x474c*/ "\nNo noticeable effect now!\n");
        break;
    }

    return local_8;
}

// NOT MATCHING
void F_CAST_153c(int param_1)
{
    byte bVar1;

    bVar1 = *FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y);
    FUN_1000_1850_print_string(/*0x4768*/ "Moonstone ");
    if (D_5893_map_id < 0x21 && (bVar1 == 0x2c || bVar1 == 0x2d || (3 < bVar1 && bVar1 < 0xb)))
    {
        FUN_1000_1850_print_string(/*0x4773*/ "buried!\n");
        D_5830[param_1] = D_5896_map_x;
        D_5838[param_1] = D_5897_map_y;
        D_5840[param_1] = D_5893_map_id;
        D_5848[param_1] = D_5895_map_level;
    }
    else
    {
        FUN_1000_1850_print_string(/*0x477c*/ "cannot be buried here!\n");
    }
}

// NOT MATCHING
void F_CAST_15b4(int param_1)
{
    int iVar1;

    FUN_1000_1850_print_string(/*0x4794*/ "Gem Shard\n\nThou dost hold above thee the evil Shard of ");
    if (param_1 == 0)
    {
        FUN_1000_1850_print_string(/*0x47cc*/ "Falsehood...");
    }
    else if (param_1 == 1)
    {
        FUN_1000_1850_print_string(/*0x47d9*/ "Hatred...");
    }
    else if (param_1 == 2)
    {
        FUN_1000_1850_print_string(/*0x47e3*/ "Cowardice...");
    }

    for (iVar1 = 2000; iVar1 < 25000; iVar1 += 0x32)
    {
        FUN_1000_2192_audio_some_noise(0xa50, 1, 200, iVar1, 0);
    }

    for (iVar1 = 25000; iVar1 > 2000; iVar1 -= 0x32)
    {
        FUN_1000_2192_audio_some_noise(0xa50, 1, 200, iVar1, 0);
    }

    if (D_4882[param_1] != D_5896_map_x || D_4886[param_1] != D_5897_map_y || D_488a[param_1] != D_5893_map_id ||
        D_488e[param_1] != D_5895_map_level)
    {
        FUN_1000_1850_print_string(/*0x47f0*/ "\n\nNo effect!\n");
        FUN_1000_43ae(800, 2000, 1, 0x32);
        return;
    }

    FUN_1000_3ae6(7);
    FUN_1000_1850_print_string(/*0x47fe*/ "\n\n...and cast it into the Flame of ");
    if (param_1 == 0)
    {
        FUN_1000_1850_print_string(/*0x4822*/ "Truth!\n");
    }
    else if (param_1 == 1)
    {
        FUN_1000_1850_print_string(/*0x482a*/ "Love!\n");
    }
    else if (param_1 == 2)
    {
        FUN_1000_1850_print_string(/*0x4831*/ "Courage!\n");
    }

    FUN_1000_3072();
    FUN_1000_3072();
    FUN_1000_3072();
    FUN_1000_3ae6(3);

    if (FUN_1000_368e(D_5896_map_x, D_5897_map_y - 1, D_5895_map_level) != 0xfc)
    {
        return;
    }

    if (param_1 != D_58cb)
    {
        return;
    }

    F_TOWN_00b0(F_TOWN_011e(D_5876));

    for (iVar1 = 0; iVar1 < 7; iVar1++)
    {
        FUN_1000_3522(D_5896_map_x, D_5897_map_y - 1);
    }

    D_58c8[param_1] = 0xff;
    D_57b6[param_1] = 0;

    D_5b5a[0x70] |= D_4892[param_1];

    FUN_1000_1850_print_string(/*0x483b*/ "\nThe doom of the Shadowlord ");
    if (param_1 == 0)
    {
        FUN_1000_1850_print_string(/*0x4858*/ "Faulinei");
    }
    else if (param_1 == 1)
    {
        FUN_1000_1850_print_string(/*0x4861*/ "Astaroth");
    }
    else if (param_1 == 2)
    {
        FUN_1000_1850_print_string(/*0x486a*/ "Nosfentor");
    }

    FUN_1000_1850_print_string(/*0x4874*/ " is wrought!\n");
    FUN_1000_4368();
}

// NOT MATCHING
bool F_CAST_1764(int param_1)
{
    if (param_1 == D_587a)
    {
        FUN_1000_1850_print_string(/*0x4895*/ "Removed!\n");
        D_588e = 0;
        D_587a = 0;
        D_a9fa = 1;
    }

    return param_1 != D_587a;
}

// NOT MATCHING
void F_CAST_1792_use_cmd(void)
{
    int iVar1;
    byte* pbVar2;
    int iVar3;
    int local_18;
    int local_14;
    int local_8;

    local_14 = 1;
    F_ZSTATS_099a();

    iVar1 = F_ZSTATS_05a4(-1, 0x26, D_b9ee, -1);
    if (iVar1 == -1)
    {
        FUN_1000_1850_print_string(/*0x489f*/ "No usable items!\n");
        return;
    }

    FUN_1000_1850_print_string(/*0x48b1*/ "Item: ");
    FUN_1000_4efc();
    FUN_1000_1b94_select_text_window(1);
    FUN_1000_4e50(/*0x48b8*/ "Items:");
    F_ZSTATS_045e(8);

    iVar1 = F_ZSTATS_0f2e(iVar1, 0xff, 0x55);
    FUN_1000_4daa();
    FUN_1000_4e20();
    FUN_1000_4f3c();
    FUN_1000_2900_update_vitals();
    if (iVar1 < 0)
    {
        return;
    }

    if (iVar1 < 8)
    {
        local_14 = F_CAST_11de(iVar1);
    }
    else if (iVar1 < 0x10)
    {
        local_14 = F_CAST_135a(iVar1 - 8);
    }
    else if (iVar1 > 0x14 && iVar1 < 0x1d)
    {
        F_CAST_153c(iVar1 - 0x15);
    }
    else
    {
        switch (iVar1)
        {
        case 0x10:
            FUN_1000_1850_print_string(/*0x48bf*/ "Carpet\n\n");
            if (D_5893_map_id < 0x21 &&
                *FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y) != 0xc)
            {
                if (D_587c == 0x1c)
                {
                    FUN_1000_1850_print_string(/*0x48c8*/ "Boarded!\n");
                    D_587c = FUN_1000_2092_random_range(0, 1) + 0x14;
                    D_57b0--;
                    break;
                }

                if ((D_587c & 0xf8) == 0x20)
                {
                    FUN_1000_1850_print_string(/*0x48d2*/ "X-it ship first!\n");
                }
                else
                {
                    FUN_1000_1850_print_string(/*0x48e4*/ "Only on foot!\n");
                }
            }
            else
            {
                FUN_1000_1850_print_string(/*0x48f3*/ "Not here!\n");
            }
            break;

        case 0x11:
            D_57b1--;
            FUN_1000_1850_print_string(/*0x48fe*/ "Skull Key\n");
            if (D_5893_map_id < 0x21 || 0x7f < D_5893_map_id)
            {
                local_14 = F_CAST2_0768();
                if (local_14 != 0 && D_5893_map_id < 0x80)
                {
                    FUN_1000_3522(D_5876, D_5878);
                }
                break;
            }

            FUN_1000_1850_print_string(/*0x4909*/ "Not here!\n");
            break;

        case 0x12:
            FUN_1000_1850_print_string(/*0x4914*/ "Amulet\n\n");
            if (F_CAST_1764(0xe) == 0)
                break;

            FUN_1000_1850_print_string(/*0x491d*/ "Wearing the Amulet");
            FUN_1000_1850_print_string(/*0x4a84*/ " of Lord British...\n");
            F_CAST2_08f8(0xe, 0xff, 9);
            break;

        case 0x13:
            FUN_1000_1850_print_string(/*0x4930*/ "Crown\n\n");
            if (F_CAST_1764(0x1c) == 0)
                break;

            FUN_1000_1850_print_string(/*0x4938*/ "Thou dost don the Crown");
            FUN_1000_1850_print_string(/*0x4a84*/ " of Lord British...\n");
            F_CAST2_08f8(0x1c, 0xff, 9);
            break;

        case 0x14:
            FUN_1000_1850_print_string(/*0x4950*/ "Sceptre\n\n");
            FUN_1000_1850_print_string(/*0x495a*/ "Wielding the Sceptre");
            FUN_1000_1850_print_string(/*0x4a84*/ " of Lord British...\n");
            FUN_1000_2192_audio_some_noise(0x1450, 1, 50000, 5000, 1);

            local_8 = 0;
            if (D_5893_map_id < 0x21 || D_5893_map_id > 0x28)
            {
                for (iVar1 = -1; iVar1 < 2; iVar1++)
                {
                    for (iVar3 = -1; iVar3 < 2; iVar3++)
                    {
                        pbVar2 = FUN_1000_4402_get_address_of_tile_id(iVar1 + D_5896_map_x,
                                                                      iVar3 + D_5897_map_y);
                        if ((*pbVar2 & 0xf0) == 0x70)
                        {
                            *pbVar2 = 5;
                            FUN_1000_5910_update_map();
                            FUN_1000_223c_audio_white_noise(10, 3000, 2000);
                            local_8++;
                        }
                    }
                }
            }

            if (local_8 != 0)
                break;

            iVar1 = F_CAST2_07bc(0);
            if (iVar1 == 1)
            {
                FUN_1000_1850_print_string(/*0x496f*/ "Field dissolved!\n");
            }
            else if (iVar1 == 0)
            {
                FUN_1000_1850_print_string(/*0x4981*/ "No effect!\n");
            }
            break;

        case 0x1d:
        case 0x1e:
        case 0x1f:
            F_CAST_15b4(iVar1 - 0x1d);
            break;

        case 0x20:
            FUN_1000_1850_print_string(/*0x498d*/ "Spyglass\n\n");
            if (D_5893_map_id < 0x21 && D_5895_map_level < 0x80)
            {
                if (D_587f < 6 || 0x12 < D_587f)
                {
                    FUN_1000_1850_print_string(/*0x4998*/ "Looking...\n");
                    F_LOOKOBJ_0366();
                    break;
                }

                FUN_1000_1850_print_string(/*0x49a4*/ "No stars!\n");
            }
            else
            {
                FUN_1000_1850_print_string(/*0x49af*/ "Not here!\n");
            }
            break;

        case 0x21:
            FUN_1000_1850_print_string(/*0x49ba*/ "Plans\n\n");
            if ((D_587c & 0xf8) == 0x20)
            {
                D_57bb |= 0x80;
                FUN_1000_1850_print_string(/*0x49c2*/ "Ship rigged for double speed!\n");
            }
            else
            {
                FUN_1000_1850_print_string(/*0x49e1*/ "Only usable on shipboard!\n");
            }
            break;

        case 0x22:
            FUN_1000_1850_print_string(/*0x49fc*/ "Sextant\n\n");
            if (D_5895_map_level < 0x80 && D_5893_map_id == 0)
            {
                if (D_587f < 6 || D_587f > 0x12)
                {
                    FUN_1000_1850_print_string(/*0x4a26*/ "Position:");
                    F_CAST2_06ec();
                    break;
                }

                FUN_1000_1850_print_string(/*0x4a16*/ "Only at night!\n");
            }
            else
            {
                FUN_1000_1850_print_string(/*0x4a06*/ "Only outdoors!\n");
            }
            break;

        case 0x23:
            FUN_1000_1850_print_string(/*0x4a30*/ "Watch\n\nThe pocket watch reads ");
            local_18 = (uint)D_587f % 0xc;
            if (local_18 == 0)
            {
                local_18 = 0xc;
            }

            FUN_1000_1a3e_print_number(local_18, 1, 0x20);
            FUN_1000_16ba_print_char(0x3a);
            FUN_1000_1a3e_print_number(D_5881, 2, 0x30);
            if (D_587f < 0xc)
            {
                FUN_1000_1850_print_string(/*0x4a55*/ " AM.\n");
            }
            else
            {
                FUN_1000_1850_print_string(/*0x4a4f*/ " PM.\n");
            }
            break;

        case 0x24:
            FUN_1000_1850_print_string(/*0x4a5b*/ "Badge\n\n");
            if (F_CAST_1764(0x1d) != 0)
            {
                FUN_1000_1850_print_string(/*0x4a63*/ "Badge worn!\n");
                D_587a = 0x1d;
                D_588e = 0xff;
                D_a9fa = 1;
            }
            break;

        case 0x25:
            FUN_1000_1850_print_string(/*0x4a70*/ "Box\n\nHow?\n");
            break;
        }
    }

    if (local_14 == 0)
    {
        FUN_1000_1850_print_string(/*0x4a7b*/ "Failed!\n");
        FUN_1000_43ae(800, 2000, 1, 0x32);
    }
}

// NOT MATCHING
int F_CAST_1bb0(int param_3, int param_2, int param_1)
{
    int uVar1;

    if (param_3 < 8 || 0xb6 < param_3 || param_2 < 8 || 0xb6 < param_2)
    {
        D_5878 = -1;
        D_5876 = -1;
    }
    else
    {
        FUN_1000_0a70_GRAP_2d_set_pen_color(param_1);
        FUN_1000_0c64_GRAP_30_pset(param_3, param_2);
        FUN_1000_0c64_GRAP_30_pset(param_3 + 1, param_2);
        uVar1 = FUN_1000_2092_random_range(100, 10000);
        FUN_1000_22e2_pcspk_start_tone(uVar1);
        if ((param_2 & 1) == 0)
        {
            return 1;
        }
        FUN_1000_3fb4(param_3, param_2);
        if (-1 < D_5876 && -1 < D_5878)
        {
            uVar1 = FUN_1000_3f6e(D_5876, D_5878);
            return uVar1;
        }
    }
    return 0;
}

// NOT MATCHING
int F_CAST_1c36(s16* param_1, s16* param_2, int param_3, int param_4, int param_5)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int local_114;
    int local_110;
    int aiStack_10c[21];
    int aiStack_b8[21];
    int aiStack_64[21];
    int local_10;
    int local_c;
    int local_8;

    iVar3 = D_ba14[param_4]._6 * 0x10;
    local_110 = iVar3 + 8;
    iVar1 = D_ba14[param_4]._7 * 0x10;
    local_114 = iVar1 + 8;

    switch (param_5)
    {
    case 2:
        local_110 = iVar3 + 0x18;
    case 1:
        local_114 = iVar1 + 0x10;
        break;
    case 3:
        local_110 = iVar3 + 0x10;
        break;
    case 4:
        local_110 = iVar3 + 0x10;
        local_114 = iVar1 + 0x18;
    }

    for (iVar1 = 0; iVar1 < 0x15; iVar1++)
    {
        aiStack_64[iVar1] = local_110;
        aiStack_b8[iVar1] = local_114;

        aiStack_10c[iVar1] = 0;
        D_a9d0[iVar1] = D_1cf0[iVar1];
    }

    local_8 = 0;
    iVar1 = 0;
    while (1)
    {
        if (0x14 < local_8)
        {
            FUN_1000_230e_pcspk_off();
            return iVar1;
        }

        local_8 = 0;
        for (iVar3 = 0; iVar3 < 0x15; iVar3++)
        {
            if (aiStack_10c[iVar3] == 0)
            {
                local_10 = FUN_1000_3aae(0xf);
                for (local_c = 0; local_c < local_10; local_c++)
                {
                    if (F_CAST_1bb0(aiStack_64[iVar3], aiStack_b8[iVar3], param_3 + 8) == 0)
                    {
                        aiStack_10c[iVar3] = 1;
                    }
                    else if (iVar1 < 0x3f && -1 < D_5876 && -1 < D_5878 && D_5876 < 0xb && D_5878 < 0xb &&
                             D_ab02[D_5878 * 0x20 + D_5876] == 0)
                    {
                        iVar1++;
                        param_1[iVar1] = D_5876;
                        param_2[iVar1] = D_5878;
                        D_ab02[D_5876 + D_5878 * 0x20] = 0xff;
                    }

                    if (aiStack_10c[iVar3] == 0)
                    {
                        D_a9d0[iVar3] -= 10;

                        switch (param_5)
                        {
                        case 1:
                            aiStack_64[iVar3]--;
                            break;
                        case 2:
                            aiStack_64[iVar3]++;
                            break;
                        case 3:
                            aiStack_b8[iVar3]--;
                            break;
                        case 4:
                            aiStack_b8[iVar3]++;
                        }

                        if (D_a9d0[iVar3] < 1)
                        {
                            if (iVar3 < 10)
                            {
                                iVar2 = -1;
                            }
                            else
                            {
                                iVar2 = 1;
                            }

                            switch (param_5)
                            {
                            case 1:
                                aiStack_b8[iVar3] -= iVar2;
                                break;
                            case 2:
                                aiStack_b8[iVar3] += iVar2;
                                break;
                            case 3:
                                aiStack_64[iVar3] += iVar2;
                                break;
                            case 4:
                                aiStack_64[iVar3] -= iVar2;
                            }

                            D_a9d0[iVar3] += D_1cf0[iVar3];
                        }
                    }

                    if (aiStack_10c[iVar3] != 0)
                        break;
                }
            }
            else
            {
                local_8++;
            }
        }
    }
}

// NOT MATCHING
void F_CAST_1f60(int param_1, int param_2, int param_3)
{
    byte bVar1;
    int uVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    s16 local_214;
    int local_210;
    int local_20c;
    s16 local_208[64];
    s16 local_108[64];
    int local_8;

    local_20c = 1;
    uVar2 = D_ba14[param_1]._3;
#if !defined(TARGET_DOS16)
    local_8 = F_CAST2_0306();
#else
    local_8 = F_CAST2_0306(param_1); // NOTE: original code error?
#endif
    if (local_8 != 0)
    {
        if (param_2 == 1)
        {
            local_210 = 16000;
        }
        else if (param_2 == 2)
        {
            local_210 = 0x4b00;
        }
        else
        {
            local_210 = 0x5140;
        }

        FUN_1000_223c_audio_white_noise(800, local_210, 700);

        iVar3 = F_CAST_1c36(local_108, local_208, param_3, param_1, local_8);
        local_8 = iVar3 + 1;

        for (local_20c = 1; local_20c < local_8; local_20c++)
        {
            for (iVar3 = 0x1f; -1 < iVar3; iVar3 = iVar3 + -1)
            {
                iVar5 = iVar3 * 8;
                if (D_ba14[iVar5]._6 == local_108[local_20c] &&
                    D_ba14[iVar5]._7 == local_208[local_20c] &&
                    (D_ba14[iVar5]._5 & 0x80) == 0 && (bVar1 = D_ba14[iVar5]._2, (bVar1 & 0x20) == 0 && bVar1 != 0))
                {
                    D_ba14[iVar5]._5 |= 0x80;
                    switch (param_2)
                    {
                    case 1:
                        iVar5 = F_COMSUBS_0000(param_1, iVar3, 0);
                        if (iVar5 == 0 && (iVar5 = F_CAST_0000(iVar3), iVar5 == 0))
                        {
                            FUN_1000_3564(iVar3);
                            FUN_1000_68ae(iVar3);
                            F_COMSUBS_0312(iVar3, param_1);
                        }
                        break;

                    case 2:
                        iVar5 = FUN_1000_3abe();
                        iVar4 = F_COMBAT_13e2(iVar3, -2);
                        if (iVar4 <= iVar5)
                        {
                            FUN_1000_3564(iVar3);
                            F_COMBAT_18ba(iVar3, param_1);
                            F_COMSUBS_0312(iVar3, param_1);
                        }
                        break;

                    case 3:
                        FUN_1000_3564(iVar3);
                        local_214 = D_55a8_party[uVar2]._14;

                        iVar5 = F_COMBAT_1574(iVar3, FUN_1000_3aae(0x1e));
                        FUN_1000_3f14(&local_214, iVar5, 9999);
                        D_55a8_party[uVar2]._14 = local_214;
                        F_COMSUBS_0312(iVar3, param_1);
                        break;

                    case 4:
                        iVar5 = F_COMSUBS_0000(param_1, iVar3, 0);
                        if (iVar5 != 0 || (iVar5 = F_CAST_0000(iVar3), iVar5 != 0))
                            break;

                        FUN_1000_3564(iVar3);
                        local_214 = D_55a8_party[uVar2]._14;

                        iVar5 = F_COMBAT_1574(iVar3, 99);
                        FUN_1000_3f14(&local_214, iVar5, 9999);
                        D_55a8_party[uVar2]._14 = local_214;
                        F_COMSUBS_0312(iVar3, param_1);
                        break;
                    }
                }
            }
        }

        for (iVar3 = 0x1f; iVar3 >= 0; iVar3--)
        {
            D_ba14[iVar3]._5 &= 0x7f;
        }
    }
}
