#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <memory.h>
#include <stdio.h>
#include <string.h>

int F_COMBAT_0000(int param_1, int param_2, int param_3);
int F_COMBAT_120e(void);
void F_COMBAT_1236(int param_1);
uint F_COMBAT_13e2(int param_1, int param_2);

int F_COMSUBS_0000(int param_1, int param_2, int param_3)
{
    int iVar1;
    int iVar2;
    int iVar3;

    if (param_3 != 0x30 && param_3 != 0x31 && param_3 < 0x33)
    {
        iVar1 = F_COMBAT_13e2(param_1, -1);
        iVar2 = F_COMBAT_13e2(param_2, -1);
        iVar3 = FUN_1000_3abe();
        if (iVar3 < ((iVar2 + 0x1e) - iVar1) / 2)
        {
            return 1;
        }
    }

    return 0;
}

// NOT MATCHING
void F_COMSUBS_0056(void)
{
    int iVar2;

    for (iVar2 = 0; iVar2 < 0x20; iVar2++)
    {
        if ((D_5c5a[iVar2]._0_tile & 0xfc) == 0xe8)
        {
            if (FUN_1000_2092_random_range(0, 0xff) < 0x10)
            {
                F_COMBAT_1236(iVar2 + 1);
            }
        }
    }
}

void F_COMSUBS_0094(int param_1)
{
    if ((D_ba14[param_1]._2 & 0x80) == 0)
    {
        FUN_1000_1850_print_string(D_1856[D_ba14[param_1]._3]);
    }
    else
    {
        FUN_1000_1850_print_string(D_55a8_party[D_ba14[param_1]._3]._0);
    }
}

// NOT MATCHING
int F_COMSUBS_00f4(int param_1)
{
    byte bVar2;
    uint uVar3;
    int iVar6;

    uVar3 = D_ba14[param_1]._3;
    bVar2 = D_ba14[param_1]._4;
    if (D_587a == 0x1c || D_587a == 'N' || (D_ba14[param_1]._2 & 0x80) != 0)
    {
        return 0;
    }
    else
    {
        if (((byte)D_153c[uVar3] & 0x40) != 0)
        {
            iVar6 = FUN_1000_2092_random_range(0, 0x1f);

            if ((D_ba14[iVar6]._2 & 0x80) != 0 && (D_ba14[iVar6]._2 & 0x3d) == 0)
            {
                if (F_COMSUBS_0000(param_1, iVar6, 0) == 0)
                {
                    FUN_1000_16ba_print_char(10);

                    D_ba14[iVar6]._2 |= 1;
                    if (D_ba14[iVar6]._3 == D_587b)
                    {
                        D_587b = 0xff;
                    }

                    FUN_1000_2900_update_vitals();
                    F_COMSUBS_0094(iVar6);
                    FUN_1000_1850_print_string(" possessed!\n");
                    FUN_1000_2192_audio_some_noise(0xc1c, 1, 30000, 1000, 2);
                    if (uVar3 == 0x26)
                    {
                        F_COMBAT_1236(-param_1 - 1);
                    }
                }

                return 1;
            }
        }

        if ((D_153c[uVar3] & 0x800) == 0 || (iVar6 = FUN_1000_2092_random_range(0, 0xff), 0x1f < iVar6))
        {
            if (((D_153c[uVar3] & 0x400) == 0 || (iVar6 = FUN_1000_2092_random_range(0, 0xff), 0x1f < iVar6)) ||
                (iVar6 = F_COMBAT_120e(), iVar6 == 0) ||
                (iVar6 = F_COMBAT_0000(0xd8, D_5876, D_5878), iVar6 == 0) ||
                (iVar6 = FUN_1000_6506(0x26, 0, D_5876, D_5878, D_5895_map_level), iVar6 == -1))
            {
                return 0;
            }

            FUN_1000_16ba_print_char(10);
            F_COMSUBS_0094(param_1);
            FUN_1000_1850_print_string(" gates in a daemon!\n");
            FUN_1000_2192_audio_some_noise(0xac8, 1, 5000, 1000, 0xf);
            D_5c5a[D_ba14[iVar6]._4]._1 = 0x16;
            D_5c5a[D_ba14[iVar6]._4]._0_tile = 0x16;
            FUN_1000_1068(D_5878, D_5876, 0x1d8);
            D_5c5a[D_ba14[iVar6]._4]._1 = 0xd8;
            D_5c5a[D_ba14[iVar6]._4]._0_tile = 0xd8;
        }
        else
        {
            FUN_1000_16ba_print_char(10);
            F_COMSUBS_0094(param_1);
            if (D_5c5a[bVar2]._1 == 0)
            {
                FUN_1000_1850_print_string(" reappears!");
                D_ba14[param_1]._2 &= 0xef;
                D_5c5a[bVar2]._1 = D_5c5a[bVar2]._0_tile;
            }
            else
            {
                FUN_1000_1850_print_string(" disappears!");
                D_ba14[param_1]._2 |= 0x10;
                D_5c5a[bVar2]._1 = 0;
            }
        }
        return 1;
    }
}

void F_COMSUBS_0312(int a, int b) { printf("F_COMSUBS_0312(%d,%d)\n", a, b); }

int F_COMSUBS_048a(int a, int b, int c, int d) { printf("F_COMSUBS_048a(%d,%d,%d,%d)\n", a, b, c, d); }

int F_COMSUBS_04d4(int a, int b) { printf("F_COMSUBS_04d4(%d,%d)\n", a, b); }

void F_COMSUBS_07d4(int a, int b) { printf("F_COMSUBS_07d4(%d,%d)\n", a, b); }

int F_COMSUBS_0822(int a, int b, int c, int d, int e) { printf("F_COMSUBS_0822(%d,%d,%d,%d,%d)\n", a, b, c, d, e); }

int F_COMSUBS_09fc(int a) { printf("F_COMSUBS_09fc(%d)\n", a); }

void F_COMSUBS_0bf8(int a, int b, int c) { printf("F_COMSUBS_0bf8(%d,%d,%d)\n", a, b, c); }

void F_COMSUBS_0d96(int a, int b) { printf("F_COMSUBS_0d96(%d,%d)\n", a, b); } // attack

int F_COMSUBS_12de(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    printf("F_COMSUBS_12de(%d,%d,%d,%d,%d)\n", param_1, param_2, param_3, param_4, param_5);
}
