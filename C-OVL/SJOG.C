#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

// OK P1
int FUN_0000_0000(void)
{
    int i = 0x20;

    while (--i >= 0)
    {
        if (D_5c5a[i]._0_tile == 0)
            return i;
    }

    return 0;
}

// OK P1
void FUN_0000_012a(int param_1)
{
    switch (param_1)
    {
    case 1:
        FUN_1000_1850_print_string("a chest!\n");
        break;
    case 2:
        FUN_1000_1850_print_string("a sack of gold!\n");
        break;
    case 3:
        FUN_1000_1850_print_string("a potion!\n");
        break;
    case 4:
        FUN_1000_1850_print_string("a scroll!\n");
        break;
    case 5:
        FUN_1000_1850_print_string("a weapon!\n");
        break;
    case 6:
        FUN_1000_1850_print_string("a shield!\n");
        break;
    case 7:
        FUN_1000_1850_print_string("a ring of keys!\n");
        break;
    case 8:
        FUN_1000_1850_print_string("a gem!\n");
        break;
    case 9:
        FUN_1000_1850_print_string("a helm!\n");
        break;
    case 10:
        FUN_1000_1850_print_string("a ring!\n");
        break;
    case 0xb:
        FUN_1000_1850_print_string("some armour!\n");
        break;
    case 0xc:
        FUN_1000_1850_print_string("an amulet!\n");
        break;
    case 0xd:
        FUN_1000_1850_print_string("some torches!\n");
        break;
    case 0xf:
        FUN_1000_1850_print_string("some food!\n");
        break;
    case 0x19:
        FUN_1000_1850_print_string("a strange rock!\n");
        break;
    case 0x1e:
        FUN_1000_1850_print_string("a rotting body!\n");
        break;
    case 0x1f:
        FUN_1000_1850_print_string("a moldy corpse!\n");
        break;
    default:
        FUN_1000_1850_print_string("Nothing of note.\n");
        break;
    }
}

F_SJOG_095c_search_cmd() {}

F_SJOG_0d4a_jimmy_cmd() {}

// TODO: MATCH
void FUN_0000_0f88(int param_7, int param_6, undefined2 param_5, undefined2 param_4, undefined2 param_3, int param_2, int* param_1)
{
    int iVar1;

    if (param_7 == 3 || param_7 == 4)
    {
        param_6--;
    }

    if (param_7 != 1)
    {
        if (param_7 != 2)
            goto LAB_0000_0fc9;
        param_2 = param_2 * 3;
    }

    param_6 = FUN_1000_2092_random_range(1, param_2);
LAB_0000_0fc9:
    iVar1 = FUN_0000_0000();
    if (iVar1 != 0)
    {
        FUN_1000_3a74(param_7, param_7, param_5, param_4, param_3, param_6, iVar1);
        if (D_5893_map_id < 0x80)
        {
            D_5c5a[iVar1]._7 = 0;
            D_5c5a[iVar1]._4_z = (undefined1)param_3;
        }
        else
        {
            D_5c5a[iVar1]._7 = 0x20;
        }
        D_24e6 = D_24e6 | 2;
        FUN_1000_5910_update_map();
        if (*param_1 == 0)
        {
            FUN_1000_1850_print_string("Found:\n");
            *param_1 = 1;
        }
        FUN_0000_012a(param_7);
    }
}

// TODO: MATCH
void FUN_0000_1040(uint param_5, undefined2 param_4, undefined2 param_3, undefined2 param_2, undefined2 param_1)
{
    uint uVar1;
    int iVar2;
    undefined2 uVar4;
    int iVar3;

    iVar2 = 8;
    while (iVar3 = iVar2, iVar2 = iVar3 - 1, 0 <= iVar2)
    {
        if (*(iVar3 - 1 + D_412c) <= param_5)
        {
            uVar1 = FUN_1000_2092_random_range(1, 0x1e);
            if (*(iVar3 - 1 + D_412c) <= uVar1)
            {
                if (*(iVar3 - 1 + D_4134) == 1)
                {
                    uVar4 = 1;
                }
                else
                {
                    uVar4 = FUN_1000_2092_random_range(1, *(iVar3 - 1 + D_4134));
                }
                FUN_0000_0f88(*(iVar3 - 1 + D_4124), uVar4, param_4, param_3, param_2, param_5, param_1);
            }
        }
    }
}

// TODO: MATCH
void FUN_0000_10b8(uint param_5, undefined2 param_4, undefined2 param_3, undefined2 param_2, undefined2 param_1)
{
    int iVar1;
    int iVar2;
    uint uVar3;
    undefined2 uStack_4;

    uStack_4 = (int)param_5 / 2;
    while (iVar1 = uStack_4 - 1, 0 <= uStack_4)
    {
        iVar2 = FUN_1000_2092_random_range(0, 0x2f);
        uStack_4 = iVar1;
        if (D_416c[iVar2] <= param_5)
        {
            uVar3 = FUN_1000_2092_random_range(1, 0x1e);
            if (D_416c[iVar2] <= uVar3)
            {
                FUN_0000_0f88(D_413c[iVar2], iVar2, param_4, param_3, param_2, param_5, param_1);
            }
        }
    }
}

// TODO: MATCH
// Open sub
void FUN_0000_112c(uint param_3, uint param_2, uint param_1)
{
    uint uVar4;
    int local_a;
    byte bStack_8;
    int iStack_6;

    local_a = 0;
    iStack_6 = 1;
    do
    {
        if (D_5c5a[iStack_6]._2_x == param_3 && D_5c5a[iStack_6]._3_y == param_2 &&
            (0x7f < D_5893_map_id || (D_5893_map_id < 0x80 && D_5c5a[iStack_6]._4_z == param_1)))
        {
            if (D_5c5a[iStack_6]._0_tile == '\x01')
                break;
            if (D_5c5a[iStack_6]._0_tile == '\x0e')
            {
                FUN_1000_1850_print_string("Can't!\n");
                return;
            }
        }
    } while (++iStack_6 < 0x20);

    if (iStack_6 == 0x20)
    {
        FUN_1000_1850_print_string("Nothing to open!\n");
    }
    else
    {
        uVar4 = FUN_1000_4988();
        if (uVar4 == -1)
        {
            return;
        }
        bStack_8 = D_5c5a[iStack_6]._5;
        FUN_1000_3a74(0, 0, 0, 0, 0, 0, iStack_6);
        D_24e6 = D_24e6 | 2;
        if ((D_5893_map_id != '\0') && (D_5893_map_id < 0x21))
        {
            if (D_5888 < 3)
            {
                D_5888 = 0;
            }
            else
            {
                D_5888 -= 2;
            }
        }

        if (0x7f < bStack_8)
        {
            bStack_8 = bStack_8 & 0x7f;
            FUN_1000_1850_print_string("Trapped!\n");
            FUN_1000_2fd0(uVar4);
            if ((0x7f < D_5893_map_id) && (D_55a8_party[uVar4]._b == 'D'))
            {
                iStack_6 = 0;
                do
                {
                    if (((D_ba14[iStack_6]._2 & 0x80) != 0) && D_ba14[iStack_6]._3 == uVar4)
                    {
                        D_ba14[iStack_6]._2 |= 0x20;

                        D_5c5a[D_ba14[iStack_6]._4]._1 = 0x1e;
                        D_5c5a[D_ba14[iStack_6]._4]._0_tile = 0x1e;
                        break;
                    }
                } while (++iStack_6 < 32);

                if (uVar4 == D_587b)
                {
                    D_587b = 0xff;
                }
                FUN_1000_5910_update_map();
            }
        }
        FUN_0000_1040(bStack_8, param_3, param_2, param_1, &local_a);
        FUN_0000_10b8(bStack_8, param_3, param_2, param_1, &local_a);
        if (local_a != 0)
        {
            return;
        }
        FUN_1000_1850_print_string("Chest empty!\n");
    }
}

// TODO: MATCH
void FUN_0000_12d4(void)
{
    byte bVar1;
    int iVar2;

    bVar1 = D_595a[((uint)D_5895_map_level * 0x40) + (D_5897_map_y & 7) * 8 + (D_5896_map_x & 7)];
    if ((bVar1 & 0xf0) == 0x40)
    {
        iVar2 = FUN_1000_4988();
        if (iVar2 == -1)
        {
            return;
        }
        if ((bVar1 & 7) != 0)
        {
            FUN_1000_2fd0(iVar2);
        }
        D_595a[((uint)D_5895_map_level * 0x40) + (D_5897_map_y & 7) * 8 + (D_5896_map_x & 7)] = (bVar1 & 8) + 0x70;
        FUN_1000_1850_print_string("\nChest opened\n");
    }
    else if ((bVar1 & 0xf0) == 0x70)
    {
        FUN_1000_1850_print_string("Already Open!\n");
    }
    else
    {
        FUN_1000_1850_print_string("What?\n");
    }
}

int FUN_1000_35ec_select_direction();

// TODO: MATCH
void F_SJOG_1374_open_cmd(void)
{
    byte bVar1;
    int iVar2;
    int iVar3;

    if ((0x20 < D_5893_map_id) && (D_5893_map_id < 0x29))
    {
        FUN_0000_12d4();
        return;
    }
    FUN_1000_39cc(D_594f, D_5950, D_5951);
    iVar2 = FUN_1000_35ec_select_direction();
    if (iVar2 == 0) {
        return;
    }
    iVar2 = (uint)D_5896_map_x + D_5876;
    iVar3 = (uint)D_5897_map_y + D_5878;
    bVar1 = *(byte*)FUN_1000_4402_get_address_of_tile_id(iVar2, iVar3);

    // TODO: switch?
    if (bVar1 == 0xaf) {
        FUN_1000_1850_print_string("It's open!\n");
        return;
    }
    if (bVar1 < 0xb0) {
        if (bVar1 < 0x97) {
        LAB_0000_1444:
            FUN_0000_112c(iVar2, iVar3, D_5895_map_level);
            return;
        }
        if (0x98 < bVar1) {
            if (bVar1 == 0x99) {
                FUN_1000_1850_print_string("Too heavy!\n");
                return;
            }
            goto LAB_0000_1444;
        }
    }
    else {
        if (bVar1 == 0xb8) {
        LAB_0000_1400:
            D_594f = bVar1;
            D_5952 = 4;
            D_5950 = (undefined1)iVar2;
            D_5951 = (undefined1)iVar3;
            *FUN_1000_4402_get_address_of_tile_id(iVar2, iVar3) = 0x44;
            D_24e6 = 1;
            FUN_1000_1850_print_string("Opened!\n");
            return;
        }
        if (bVar1 != 0xb9) {
            if (bVar1 == 0xba) goto LAB_0000_1400;
            if (bVar1 != 0xbb) goto LAB_0000_1444;
        }
    }
    FUN_1000_1850_print_string("Locked!\n");
}

F_SJOG_18ce_get_cmd() {}
