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

int FUN_1000_4988() {}
void FUN_1000_2fd0(undefined2 param_1);

void FUN_0000_0f88(int param_7, int param_6, undefined2 param_5, undefined2 param_4, undefined2 param_3, int param_2, int* param_1)
{
    int iVar1;

    if ((param_7 == 3) || (param_7 == 4)) {
        param_6 = param_6 + -1;
    }
    if (param_7 != 1) {
        if (param_7 != 2) goto LAB_0000_0fc9;
        param_2 = param_2 * 3;
    }
    param_6 = FUN_1000_2092_random_range(1, param_2);
LAB_0000_0fc9:
    iVar1 = FUN_0000_0000();
    if (iVar1 != 0) {
        FUN_1000_3a74(param_7, param_7, param_5, param_4, param_3, param_6, iVar1);
        if (D_5893_map_id < 0x80) {
            *(undefined1*)(iVar1 * 8 + 0x5c61) = 0;
            *(undefined1*)(iVar1 * 8 + 0x5c5e) = (undefined1)param_3;
        }
        else {
            *(undefined1*)(iVar1 * 8 + 0x5c61) = 0x20;
        }
        D_24e6 = D_24e6 | 2;
        FUN_1000_5910_update_map();
        if (*param_1 == 0) {
            FUN_1000_1850_print_string(0x8b5c);
            *param_1 = 1;
        }
        FUN_0000_012a(param_7);
    }
}

void FUN_0000_1040(uint param_5, undefined2 param_4, undefined2 param_3, undefined2 param_2, undefined2 param_1)
{
    uint uVar1;
    int iVar2;
    undefined2 uVar4;
    int iVar3;

    iVar2 = 8;
    while (iVar3 = iVar2, iVar2 = iVar3 + -1, -1 < iVar2) {
        if (*(byte*)(iVar3 + 0x412b) <= param_5) {
            uVar1 = FUN_1000_2092_random_range(1, 0x1e);
            if (*(byte*)(iVar3 + 0x412b) <= uVar1) {
                if (*(char*)(iVar3 + 0x4133) == '\x01') {
                    uVar4 = 1;
                }
                else {
                    uVar4 = FUN_1000_2092_random_range(1, *(undefined1*)(iVar3 + 0x4133));
                }
                FUN_0000_0f88(*(undefined1*)(iVar3 + 0x4123), uVar4, param_4, param_3, param_2, param_5, param_1);
            }
        }
    }
}

void FUN_0000_10b8(uint param_5, undefined2 param_4, undefined2 param_3, undefined2 param_2, undefined2 param_1)
{
    int iVar1;
    int iVar2;
    uint uVar3;
    undefined2 uStack_4;

    uStack_4 = (int)param_5 / 2;
    while (iVar1 = uStack_4 + -1, -1 < uStack_4) {
        iVar2 = FUN_1000_2092_random_range(0, 0x2f);
        uStack_4 = iVar1;
        if (*(byte*)(iVar2 + 0x416c) <= param_5) {
            uVar3 = FUN_1000_2092_random_range(1, 0x1e);
            if (*(byte*)(iVar2 + 0x416c) <= uVar3) {
                FUN_0000_0f88(*(undefined1*)(iVar2 + 0x413c), iVar2, param_4, param_3, param_2, param_5, param_1);
            }
        }
    }
}

void FUN_0000_112c(uint param_3, uint param_2, uint param_1)
{
    byte bVar1;
    uint uVar2;
    undefined2 uVar3;
    uint uVar4;
    char* pcVar5;
    byte* pbVar6;
    int iVar7;
    char* pcStack_14;
    byte* pbStack_12;
    byte* pbStack_10;
    int local_a;
    byte bStack_8;
    int iStack_6;
    uint uStack_4;

    local_a = 0;
    iStack_6 = 1;
    pbVar6 = (byte*)0x5c64;
    pbStack_10 = (byte*)0x5c65;
    pbStack_12 = (byte*)0x5c66;
    pcStack_14 = (char*)0x5c62;
    pcVar5 = (char*)0x5c62;
    do {
        if (((*pbVar6 == param_3) && (*pbStack_10 == param_2)) &&
            ((0x7f < D_5893_map_id || ((D_5893_map_id < 0x80 && (*pbStack_12 == param_1)))))) {
            if (*pcStack_14 == '\x01') break;
            if (*pcVar5 == '\x0e') {
                uVar3 = 0x8b64;
                goto LAB_0000_12c8;
            }
        }
        pbVar6 = pbVar6 + 8;
        pbStack_10 = pbStack_10 + 8;
        pbStack_12 = pbStack_12 + 8;
        pcStack_14 = pcStack_14 + 8;
        pcVar5 = pcVar5 + 8;
        iStack_6 = iStack_6 + 1;
    } while (pcVar5 < (char*)0x5d5a);
    if (iStack_6 == 0x20) {
        uVar3 = 0x8b6c;
    }
    else {
        uVar4 = FUN_1000_4988();
        if (uVar4 == 0xffff) {
            return;
        }
        bStack_8 = *(byte*)(iStack_6 * 8 + 0x5c5f);
        FUN_1000_3a74(0, 0, 0, 0, 0, 0, iStack_6);
        D_24e6 = D_24e6 | 2;
        if ((D_5893_map_id != '\0') && (D_5893_map_id < 0x21)) {
            if (D_5888 < 3) {
                D_5888 = 0;
            }
            else {
                D_5888 = D_5888 + -2;
            }
        }
        if (0x7f < bStack_8) {
            bStack_8 = bStack_8 & 0x7f;
            FUN_1000_1850_print_string(0x8b7e);
            FUN_1000_2fd0(uVar4);
            if ((0x7f < D_5893_map_id) && (*(char*)(uVar4 * 0x20 + D_55a8_party[0]._b) == 'D')) {
                iStack_6 = 0;
                uVar2 = 0xba14;
                do {
                    uStack_4 = uVar2;
                    if (((*(byte*)(uStack_4 + 2) & 0x80) != 0) &&
                        (*(byte*)(uStack_4 + 3) == uVar4)) {
                        *(byte*)(uStack_4 + 2) = *(byte*)(uStack_4 + 2) | 0x20;
                        iVar7 = (uint) * (byte*)(uStack_4 + 4) * 8;
                        *(undefined1*)(iVar7 + 0x5c5b) = 0x1e;
                        *(undefined1*)(iVar7 + 0x5c5a) = 0x1e;
                        break;
                    }
                    iStack_6 = iStack_6 + 1;
                    uVar2 = uStack_4 + 8;
                } while (uStack_4 + 8 < 0xbb14);
                if (uVar4 == D_587b) {
                    D_587b = 0xff;
                }
                FUN_1000_5910_update_map();
            }
        }
        bVar1 = bStack_8;
        FUN_0000_1040(bStack_8, param_3, param_2, param_1, &local_a);
        FUN_0000_10b8(bVar1, param_3, param_2, param_1, &local_a);
        if (local_a != 0) {
            return;
        }
        uVar3 = 0x8b88;
    }
LAB_0000_12c8:
    FUN_1000_1850_print_string(uVar3);
    return;
}

void FUN_0000_12d4(void)
{
    byte bVar1;
    int iVar2;
    undefined2 uVar3;

    bVar1 = *(byte*)((uint)D_5895_map_level * 0x40 +
        (*(uint*)0x5897 & 7) * 8 + (D_5896_map_x & 7) + 0x595a);
    if ((bVar1 & 0xf0) == 0x40) {
        iVar2 = FUN_1000_4988();
        if (iVar2 == -1) {
            return;
        }
        if ((bVar1 & 7) != 0) {
            FUN_1000_2fd0(iVar2);
        }
        *(char*)((uint)D_5895_map_level * 0x40 + (*(uint*)0x5897 & 7) * 8 + (D_5896_map_x & 7) +
            0x595a) = (bVar1 & 8) + 0x70;
        uVar3 = 0x8b96;
    }
    else if ((bVar1 & 0xf0) == 0x70) {
        uVar3 = 0x8ba6;
    }
    else {
        uVar3 = 0x8bb6;
    }
    FUN_1000_1850_print_string(uVar3);
    return;
}

void F_SJOG_1374_open_cmd(void)
{
    byte bVar1;
    int iVar2;
    int iVar3;
    byte* pbVar4;
    undefined2 uVar5;
    undefined1* puVar6;
    undefined1 uStack_8;
    undefined1 uStack_6;

    if ((0x20 < D_5893_map_id) && (D_5893_map_id < 0x29)) {
        FUN_0000_12d4();
        return;
    }
    FUN_1000_39cc(D_5951, D_5950, D_594f);
    iVar2 = FUN_1000_35ec_select_direction();
    if (iVar2 == 0) {
        return;
    }
    iVar2 = (uint)D_5896_map_x + D_5876;
    iVar3 = (uint)D_5897_map_y + D_5878;
    pbVar4 = (byte*)FUN_1000_4402_get_address_of_tile_id(iVar2, iVar3);
    bVar1 = *pbVar4;
    if (bVar1 == 0xaf) {
        uVar5 = 0x8bbe;
        goto LAB_0000_13ed;
    }
    if (bVar1 < 0xb0) {
        if (bVar1 < 0x97) {
        LAB_0000_1444:
            FUN_0000_112c(iVar2, iVar3, D_5895_map_level);
            return;
        }
        if (0x98 < bVar1) {
            if (bVar1 == 0x99) {
                uVar5 = 0x8bca;
                goto LAB_0000_13ed;
            }
            goto LAB_0000_1444;
        }
    }
    else {
        if (bVar1 == 0xb8) {
        LAB_0000_1400:
            D_594f = bVar1;
            D_5952 = 4;
            uStack_6 = (undefined1)iVar2;
            D_5950 = uStack_6;
            uStack_8 = (undefined1)iVar3;
            D_5951 = uStack_8;
            puVar6 = (undefined1*)FUN_1000_4402_get_address_of_tile_id(iVar2, iVar3);
            *puVar6 = 0x44;
            D_24e6 = 1;
            uVar5 = 0x8be0;
            goto LAB_0000_13ed;
        }
        if (bVar1 != 0xb9) {
            if (bVar1 == 0xba) goto LAB_0000_1400;
            if (bVar1 != 0xbb) goto LAB_0000_1444;
        }
    }
    uVar5 = 0x8bd6;
LAB_0000_13ed:
    FUN_1000_1850_print_string(uVar5);
    return;
}

F_SJOG_18ce_get_cmd() {}
