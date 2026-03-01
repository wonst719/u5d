#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <memory.h>

void F_NPC_0db4(int param_1);
int F_NPC_12e0(int param_1, char param_2);

void F_BLCKTHRN_060e_capture(void);
void F_BLCKTHRN_0910_death(void);
void F_CAST2_0e76(void);

int F_TALK_031e(int param_1);

void F_TOWN_1694(void);
void F_TOWN_1726(int param_1, byte param_2, byte param_3, byte param_4);

// NOT MATCHING (u32 operation)
// check npc killed flag
int F_TOWN_0000(int param_1)
{
    if ((D_659e[param_1] == 0xe) || (0x40 <= D_659e[param_1]))
    {
        return ((*(u32*)&D_5b5a[(D_5893_map_id - 1) * 4]) & (((u32)1) << ((byte)param_1 & 0x1f))) != 0;
    }

    return 0;
}

// NOT MATCHING (u32 operation)
// 0052: set killed
void F_TOWN_0052(int param_1)
{
    int b;

    if (param_1 < 0 || param_1 > 0x1f)
        return;

    b = D_659e[param_1] & 0xfc;

    if ((b != 0x70 && b < 0x80) || b == 0xb4)
    {
        // 0084
        (*(u32*)&D_5b5a[(D_5893_map_id - 1) * 4]) |= ((u32)1) << ((byte)param_1 & 0x1f);
    }
}

// OK P1
void F_TOWN_00b0(int param_1)
{
    ActorFmt* actor = &D_5c5a[D_5f5e[param_1]._c];

    actor->_0_tile = actor->_1 = actor->_2_x = actor->_3_y = actor->_4_z = actor->_6 = actor->_7 = D_5f5e[param_1]._0 =
        D_5f5e[param_1]._2 = D_5f5e[param_1]._4 = D_5f5e[param_1]._6 = D_5f5e[param_1]._a = 0;
    D_5d5e[param_1]._0[0] = D_5d5e[param_1]._0[1] = D_5d5e[param_1]._0[2] = 0;
    D_659e[param_1] = 0;
    D_24e6 |= 2;
}

// OK P1
int F_TOWN_011e(int param_1)
{
    int local_4;
    int local_2 = -1;

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        if (D_5f5e[local_4]._c == param_1 && D_659e[local_4] != 0 && D_5f5e[local_4]._0 != 0)
        {
            local_2 = local_4;
            break;
        }
    }

    return local_2;
}

// OK P1
void F_TOWN_0170(void)
{
    int local_4;
    int local_6;

    for (local_6 = 0; local_6 < 0x20; local_6++)
    {
        for (local_4 = 0; local_4 < 0x20; local_4++)
        {
            if (*FUN_1000_4402_get_address_of_tile_id(local_6, local_4) == 0x87)
            {
                *FUN_1000_4402_get_address_of_tile_id(local_6, local_4 + 1) ^= 0xdd;
            }
        }
    }

    if ((*FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y) & 0xfe) != 0x48)
    {
        for (local_4 = 0; local_4 < D_594e; local_4++)
        {
            if (D_587f == 5)
            {
                *FUN_1000_4402_get_address_of_tile_id(D_58ee[local_4], D_590e[local_4]) = D_592e[local_4];
            }
            else
            {
                *FUN_1000_4402_get_address_of_tile_id(D_58ee[local_4], D_590e[local_4]) = 3;
            }
        }
    }

    D_24e6 |= 2;
}

// TODO: MATCH
// randomize field?
void F_TOWN_0212(void)
{
    char cVar1;
    int iVar2;
    undefined2 uVar3;
    int iVar4;
    int iStack_e;

    if (D_5958 != -1) {
        FUN_1000_207e_srand(D_587e);
        iStack_e = 0;
        do {
            iVar4 = 0;
            do {
                cVar1 = *(iStack_e + iVar4 + D_6608);
                if (cVar1 == '-') {
                    iVar2 = FUN_1000_2092_random_range(0, 7);
                    if (iVar2 != 0) {
                        *(iStack_e + iVar4 + D_6608) = 0x2c;
                    }
                }
                else if ((cVar1 == '.') && (iVar2 = FUN_1000_2092_random_range(0, 7), iVar2 != 0)) {
                    *(iStack_e + iVar4 + D_6608) = 0x2b;
                }
                iVar4 = iVar4 + 1;
            } while (iVar4 < 0x20);
            iStack_e = iStack_e + 0x20;
        } while (iStack_e < 0x400);
        D_24e6 = D_24e6 | 2;
        uVar3 = FUN_1000_2056_get_time();
        FUN_1000_207e_srand(uVar3);
    }
}

// TODO: MATCH
// setup npcs?
void F_TOWN_02ae(void)
{
    byte bVar2;
    int iVar4;
    int iVar6;
    int i;

    D_5958 = 0xff;
    if (D_5897_map_y != 4)
    {
        for (i = 0; i < 3; i++)
        {
            if (D_58c8[i] == D_5893_map_id)
            {
                D_5958 = (undefined1)i;
                break;
            }
        }
    }

    if (D_5958 != 0xff)
    {
        // Setup shadow lord
        F_TOWN_0212();
        for (i = 0; i < 0x20; i++)
        {
            if (D_5c5a[i]._0_tile == 0xfc)
            {
                return;
            }
        }

        iVar4 = FUN_1000_38e4();

        i = 0x1f;
        do {
            iVar6 = i;
            if (D_659e[iVar6] == 0)
                break;
            i = iVar6 - 1;
            iVar6 = 0x1f; // ??
        } while (0 <= i);

        ASSERT(D_5893_map_id > 0 && D_5893_map_id <= 8);

        D_5f5e[iVar6]._0 = 1;
        D_5f5e[iVar6]._c = iVar4;
        D_5c5a[iVar4]._2_x = 0xf;
        D_5f5e[iVar6]._2 = 0xf;
        bVar2 = D_13a6[D_5893_map_id - 1];
        D_5c5a[iVar4]._3_y = bVar2;
        D_5f5e[iVar6]._4 = (uint)bVar2;
        D_5c5a[iVar4]._7 = 0;
        D_5c5a[iVar4]._4_z = 0;
        D_5c5a[iVar4]._5 = 0;
        D_5c5a[iVar4]._6 = 0;
        D_5f5e[iVar6]._6 = 0;
        D_5c5a[iVar4]._1 = 0xfc;
        D_5c5a[iVar4]._0_tile = 0xfc;

        for (i = 0; i < 4; i++)
        {
            // npc time
            D_5d5e[iVar6]._c[i] = 0;
        }

        for (i = 0; i < 3; i++)
        {
            // setup npc schedules
            D_5d5e[iVar6]._0[i] = 6;
            D_5d5e[iVar6]._3[i] = 0xf;
            D_5d5e[iVar6]._6[i] = D_5c5a[iVar4]._3_y;
            D_5d5e[iVar6]._9[i] = 0;
        }

        D_659e[iVar6] = 0xfc;
    }
}

// OK P1
void F_TOWN_0408(int param_1)
{
    char* local_2;
    int local_8;
    int local_4;
    undefined2 local_6;

    FUN_1000_4be8();
    FUN_1000_4a84();
    FUN_1000_2e96_print_direction(-1);

    D_594f = 0;
    D_589b = D_589c = 0;

    local_2 = D_2652[(D_5893_map_id - 1) >> 3];
    local_6 = (uint)D_1e19[D_5893_map_id] + (uint)D_5895_map_level;
    if (D_5895_map_level > 0x7f)
    {
        local_6 -= 0x100;
    }

    FUN_1000_256e_read_file_from_disk(local_2, D_6608, 0x400, local_6 << 10);

    D_594e = 0;
    D_217e = D_2180 = D_2182 = D_2184 = -1;

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        for (local_8 = 0; local_8 < 0x20; local_8++)
        {
            if ((*FUN_1000_4402_get_address_of_tile_id(local_4, local_8) & 0xfe) == 0x48)
            {
                D_58ee[D_594e] = (char)local_4;
                D_590e[D_594e] = (char)local_8;
                D_592e[D_594e] = *FUN_1000_4402_get_address_of_tile_id(local_4, local_8);
                D_594e++;
            }
            if (*FUN_1000_4402_get_address_of_tile_id(local_4, local_8) == '*')
            {
                if (D_217e == -1)
                {
                    D_217e = local_4;
                    D_2180 = local_8;
                }
                else
                {
                    D_2182 = local_4;
                    D_2184 = local_8;
                }
            }
        }
    }

    if (D_587f < 5 || D_587f > 0x13)
    {
        F_TOWN_0170();
    }

    FUN_1000_5e4a();
    FUN_1000_4f7c(0);
    F_TOWN_0212();

    if (param_1 != 0)
    {
        F_TOWN_1694();
    }

    D_24e6 = 1;
}

// OK P1 (complete)
void F_TOWN_052e(int param_1, int param_2)
{
    if ((param_2 & 0xfc) == 0xc4)
    {
        FUN_1000_5910_update_map();
        if (param_2 - 0xc4 == param_1)
        {
            D_5895_map_level++;
            FUN_1000_1850_print_string("Up!\n"); // 265a
        }
        else if (param_2 - 0xc4 == (param_1 ^ 2))
        {
            D_5895_map_level--;
            FUN_1000_1850_print_string("Down!\n"); // 265f
        }
        else
        {
            return;
        }

        F_TOWN_0408(1);
    }
}

// OK P1 (complete)
// select party icon
// 0: up, 1: right, 2: down, 3: left
void F_TOWN_057c(int param_1)
{
    switch (D_587c & 0xfc)
    {
    case 0x10:
        FUN_1000_1850_print_string("Ride "); // 2666
        if (param_1 == 1)
        {
            D_587c = 0x12;
        }
        else if (param_1 == 3)
        {
            D_587c = 0x13;
        }
        break;

    case 0x14:
        FUN_1000_1850_print_string("Fly "); // 266c
        if (param_1 == 1)
        {
            D_587c = 0x14;
        }
        else if (param_1 == 3)
        {
            D_587c = 0x15;
        }
        break;

    case 0x28:
        FUN_1000_1850_print_string("Row "); // 2671
        // fall-through

    case 0x20:
    case 0x24:
        D_587c = (char)param_1 + (D_587c & 0xfc);
        break;
    }
}

// NOT MATCHING
// move
// return: exit from the map?
bool F_TOWN_0600(int param_1)
{
    int local_4;
    bool local_6;
    bool local_8; // reached the end of the map?
    int local_a;
    int local_c;
    int local_e;
    undefined2 local_10;

    if ((D_587c == 0x1c) || ((D_587c & 0xfe) == 0x12))
    {
        FUN_1000_433e_audio_some_noise();
    }

    local_c = local_e = local_8 = 0;

    switch (param_1)
    {
    case 3: // up
        // 0648 (OK P1)
        local_e--;
        if (D_5897_map_y < 1)
            local_8 = 1;
        // 0657
        param_1 = 0;
        F_TOWN_057c(0);
        FUN_1000_1850_print_string("North\n");
        break;

    case 4: // down
        // 06f8
        local_e++;
        if (D_5897_map_y > 0x1e)
            local_8 = 1;
        param_1 = 2;
        F_TOWN_057c(2);
        FUN_1000_1850_print_string("South\n");
        break;

    case 2: // right
        // 071a
        local_c++;
        if (0x1e < D_5896_map_x)
            local_8 = 1;
        param_1 = 1;
        F_TOWN_057c(1);
        FUN_1000_1850_print_string("East\n");
        break;

    case 1: // left
        // 073c
        local_c--;
        if (D_5896_map_x == 0)
            local_8 = 1;
        param_1 = 3;
        F_TOWN_057c(3);
        FUN_1000_1850_print_string("West\n");
        break;
    }

    // 0669 (OK P1)
    local_6 = 1;
    local_10 = *(local_c + local_e * 0x20 + D_ab02 + 0xa5); // 0xaba7
    local_a = FUN_1000_368e(local_c + (uint)D_5896_map_x, local_e + (uint)D_5897_map_y, D_5895_map_level);
    if (local_a != 0)
    {
        // 06a9
        local_6 = 0;
        if (D_587c >= 0x30 || D_587c < 0x20)
        {
            // 06bf
            // NOT MATCHING
            if ((local_a < 0x24 || local_a >= 0x2c) &&
                // 06ce
                local_a != 0x1b && ((byte)local_a & 0xfe) != 0x10 && local_a != 0x1e && local_a != 0x1f)
            {
                // -> 0776
            }
            else
            {
                // -> 0771
                local_6 = 1;
            }
        }
        else
        {
            // 075e (OK P1)
            if (((D_587c < 0x28) || (local_a < 0x24)) || (local_a >= 0x28))
            {
                // -> 0776
            }
            else
            {
                // -> 0771
                local_6 = 1;
            }
        }
    }

    // 0776
    if (local_6 && FUN_1000_2c4c(D_587c, local_10) != 0)
    {
        // 0792
        if (local_8 != 0)
        {
            FUN_1000_1850_print_string("\nDost thou wish to leave? ");

            // NOT MATCHING
            do
            {
                // 07ac
                if ((local_4 = FUN_1000_266c_get_ch()) == 0x59)
                    break;

            } while (local_4 != 0x4e && local_4 != 0x1b);

            // 07b6 (OK P1)
            if (local_4 == 0x59)
            {
                FUN_1000_1850_print_string("Yes\n\nExit to\n");
                if (D_5893_map_id == 0x19)
                {
                    FUN_1000_1850_print_string("Underworld!\n");
                    D_5895_map_level = 0xff;
                }
                else
                {
                    // 07da
                    FUN_1000_1850_print_string("Britannia!\n");
                    D_5895_map_level = 0;
                }

                // 07e6
                D_594f = 0;
                D_5896_map_x = D_1e8a[D_5893_map_id - 1];
                D_5897_map_y = D_1eb2[D_5893_map_id - 1];
                D_5893_map_id = 0;
            }
            else
            {
                // 0806
                FUN_1000_1850_print_string("No\n");
                local_8 = 0;
            }
        }
        else
        {
            // 0810
            D_5896_map_x = D_5896_map_x + (char)local_c;
            D_5897_map_y = D_5897_map_y + (char)local_e;
            D_24e6 = 1;
            if ((D_587c & 0xfe) == 0x12)
            {
                FUN_1000_433e_audio_some_noise();
            }
            F_TOWN_052e(param_1, local_10);
        }
    }
    else
    {
        // 083a
        FUN_1000_1850_print_string("Blocked!\n");
        FUN_1000_22c0_pcspk_play_tone(0xa5, 200);
        FUN_1000_1b16_clear_keyboard_buffer();
        local_8 = 0;
    }

    // 0854
    return local_8;
}

// OK P1
void F_TOWN_085e(int param_1)
{
    int local_4;
    int i;

    if (D_659e[param_1] >= 0x2f)
    {
        local_4 = 7;
    }
    else
    {
        local_4 = 6;
    }

    for (i = 0; i < 4; i++)
    {
        D_5d5e[param_1]._c[i] = 0;
    }

    for (i = 0; i < 3; i++)
    {
        D_5d5e[param_1]._0[i] = local_4;
    }
}

// OK P1
void F_TOWN_08d4(int param_1)
{
    int local_6;
    int local_8;
    int local_c; // unused

    local_6 = 0;

    for (local_8 = 0; local_8 < 4; local_8++)
    {
        if (D_5d5e[param_1]._c[local_8] != 0)
        {
            local_6 = 1;
        }
    }

    if (D_659e[param_1] < 0x74 && D_659e[param_1] >= 0x40 && (D_5f5e[param_1]._a == 0xfe || local_6))
    {
        D_5f5e[param_1]._a = 0xfd;

        for (local_8 = 0; local_8 < 3; local_8++)
        {
            D_5d5e[param_1]._0[local_8] = 3;
        }
    }
}

// OK P1
// call guards?
void F_TOWN_0958(void)
{
    int local_6;
    int local_4;

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        if (D_5f5e[local_4]._0 != 0)
        {
            local_6 = D_659e[local_4];
            if (local_6 == 0xfc || local_6 == 0xd8 || local_6 == 0x70)
            {
                F_TOWN_085e(local_4);
            }
            else
            {
                if (FUN_1000_2092_random_range(0, 0xff) < 0x80)
                {
                    F_TOWN_08d4(local_4);
                }
            }
        }
    }
}

// OK P1
void F_TOWN_09bc(int param_1)
{
    F_TOWN_0052(param_1);
    FUN_1000_6150_attack_monster(D_5f5e[param_1]._c);
    F_TOWN_00b0(param_1);
    F_TOWN_0408(0);
    F_TOWN_02ae();
}

// NOT MATCHING
int F_TOWN_09e6_attack_cmd(void)
{
    bool local_8;
    int local_a;
    int local_c;
    int local_e;
    byte local_12;
    int local_4;
    int local_6 = 1;

    FUN_1000_1850_print_string(/*0x26e0*/ "Attack-");

    if (*FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y) < 4 && D_587c != 0x1c)
    {
        FUN_1000_1850_print_string(/*0x26e8*/ "On foot!\n");
        local_6 = 0;
        return local_6;
    }

    if (FUN_1000_35ec_select_direction() == 0)
    {
        return local_6;
    }

    local_a = (uint)D_5896_map_x + D_5876;
    local_c = (uint)D_5897_map_y + D_5878;
    if (*FUN_1000_4402_get_address_of_tile_id(local_a, local_c) == 0x9d)
    {
        *FUN_1000_4402_get_address_of_tile_id(local_a, local_c) = 0x9f;
        FUN_1000_1850_print_string(/*0x26f2*/ "Broken!\n");

        for (local_e = 2000; local_e < 20000; local_e += 1000)
        {
            FUN_1000_223c_audio_white_noise(0x28, 0x78, local_e);
        }

        D_24e6 |= 2;
        return local_6;
    }

    local_12 = FUN_1000_368e(local_a, local_c, D_5895_map_level);
    local_8 = 1;
    if (local_12 != 0)
    {
        local_4 = F_TOWN_011e(D_5876);
        if (local_12 >= 0x40 && (local_12 < 0xe8 || local_12 >= 0xf0) && (local_12 & 0xfc) != 0xb4)
        {
            local_8 = 0;
        }
    }

    // 0ad8
    if (local_8)
    {
        // 0ae1
        FUN_1000_1850_print_string(/*0x26fb*/ "Nothing to attack!\n");
        return local_6;
    }

    if (local_12 < 0x80)
    {
        FUN_1000_3f36(&D_5888, 5);
        F_TOWN_0958();
    }
    else if ((local_12 & 0xfc) == 0xd8)
    {
        F_TOWN_0958();
    }

    switch (*FUN_1000_4402_get_address_of_tile_id(local_a, local_c))
    {
    case 0x84:
    case 0x85:
    case 0x9f:
    case 0xab:
        if (local_12 == 0x78)
        {
            FUN_1000_1850_print_string(/*0x270f*/ "Missed!\n");
            return local_6;
        }

        FUN_1000_1850_print_string(/*0x2718*/ "Murdered!\n");
        FUN_1000_3f36(&D_5888, 5);
        FUN_1000_3522(local_a, local_c);

        if (local_4 < 0)
        {
            return local_6;
        }

        F_TOWN_0052(local_4);
        F_TOWN_00b0(local_4);
        return local_6;
    }

    if (local_4 < 0)
    {
        return local_6;
    }

    F_TOWN_0052(local_4);
    F_TOWN_09bc(local_4);
    return local_6;
}

// NOT MATCHING
int F_TOWN_0b82_klimb_cmd(void)
{
    int local_6;
    int local_4;

    local_4 = 0;
    FUN_1000_1850_print_string("Klimb-"); // 2723

    if ((D_587c & 0xfe) == 0x12)
    {
        // 0ba0..
        FUN_1000_1850_print_string("-On foot!\n"); // 272a
    }
    else
    {
        // 0ba8
        switch (*FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y))
        {
        case 0xc8:
            // 0bce..0bd0
            F_TOWN_052e(0, 0xc4);
            local_4 = 1;
            break;

        case 0x86:
        case 0xc9:
            // 0c32..0bd0
            F_TOWN_052e(2, 0xc4);
            local_4 = 1;
            break;
        }

        // 0bdd
        if (local_4 == 0)
        {
            if (FUN_1000_35ec_select_direction() != 0)
            {
                switch (local_6 = *FUN_1000_4402_get_address_of_tile_id((uint)D_5896_map_x + D_5876, (uint)D_5897_map_y + D_5878))
                {
                case 0x4c:
                case 0xca:
                    // 0c19
                    D_5896_map_x += D_5876;
                    D_5897_map_y += D_5878;
                    D_24e6 = 1;
                    FUN_1000_5910_update_map();
                    // 0c3e
                    local_4 = 1;
                    break;
                case 0xcb:
                    // 0c38..0ba0
                    FUN_1000_1850_print_string("What?\n"); // 2735
                    break;
                }
            }
        }
    }

    return local_4;
}

// OK P1
int F_TOWN_0c4a(int param_1, int param_2)
{
    if (*FUN_1000_4402_get_address_of_tile_id(param_1, param_2) == 0xa2 ||
        *FUN_1000_4402_get_address_of_tile_id(param_1, param_2) == 0x43)
    {
        return 1;
    }

    return 0;
}

// NOT MATCHING (loop, stack)
void F_TOWN_0c78(void)
{
    ActorFmt* local_4;
    int local_6; // x
    int local_8; // y
    int local_a; // i
    int local_c;
    int local_e;

    for (local_a = 0; local_a < 0x20; local_a++)
    {
        local_4 = &D_5c5a[local_a];

        local_e = local_4->_0_tile;
        if (((byte)local_e & 0xfe) == 0x10 && local_4->_4_z == D_5895_map_level &&
            FUN_1000_2092_random_range(0, 1) == 0)
        {
            local_6 = local_4->_2_x;
            local_8 = local_4->_3_y;

            if (F_TOWN_0c4a(local_6, local_8 + 1) == 0 &&
                F_TOWN_0c4a(local_6 + 1, local_8) == 0 &&
                F_TOWN_0c4a(local_6, local_8 - 1) == 0 &&
                F_TOWN_0c4a(local_6 - 1, local_8) == 0)
            {
                // 0d12
                if (FUN_1000_2092_random_range(0, 1) == 0)
                {
                    local_c = FUN_1000_2092_random_range(0, 1) * 2 - 1;
                    local_6 += local_c;
                    if (local_c > 0)
                    {
                        local_e = 0x10;
                    }
                    else
                    {
                        local_e = 0x11;
                    }
                }
                else
                {
                    local_8 += FUN_1000_2092_random_range(0, 1) * 2 - 1;
                }

                if (local_6 <= 0x1f && local_8 <= 0x1f && 0 <= local_6 && 0 <= local_8)
                {
                    if ((FUN_1000_2c4c(0x10, *FUN_1000_4402_get_address_of_tile_id(local_6, local_8)) != 0) &&
                        (FUN_1000_3702(local_6, local_8, D_5895_map_level) == 0))
                    {
                        local_4->_0_tile = local_4->_1 = local_e;
                        local_4->_2_x = (byte)local_6;
                        local_4->_3_y = (byte)local_8;
                        D_24e6 |= 2;
                    }
                }
            }
        }
    }
}

// OK P1
uint F_TOWN_0dc4(int param_1)
{
    uint local_4;

    if (param_1 != 0)
    {
        FUN_1000_5910_update_map(); // update_map?
        if (D_a9fa != 0)
        {
            FUN_1000_2900_update_vitals();
            D_a9fa = 0;
        }
        FUN_1000_16ba_print_char(10);
        FUN_1000_4c2a();
    }

    local_4 = FUN_1000_266c_get_ch();

    if (D_5957 != 0)
    {
        if (FUN_1000_2092_random_range(0, 1) != 0)
        {
            F_TOWN_0958();
            D_5957--;
            FUN_1000_1850_print_string("Hic!\n");
            local_4 = D_2742[FUN_1000_2092_random_range(0, 3)];
        }
    }

    return local_4;
}

// NOT MATCHING
int F_TOWN_0e34(int param_1)
{
    int local_4;

    local_4 = 3;
    if (D_ab02[0xc5] == 0x8d) // abc7
    {
        param_1 -= 0x30;
        if (D_a9ce != 0)
        {
            FUN_1000_2192_audio_some_noise(D_2746[param_1], 1, 4000, 20000, 0xfffc);
        }
        if (D_275a[D_2767] == param_1)
        {
            D_2767++;
            if (D_2767 == 0xd)
            {
                D_2767 = 0;
                if (D_5893_map_id == 0x11 && D_5895_map_level == 0x02)
                {
                    D_6608[0x1b1] ^= 0xb; // 67b9
                    FUN_1000_3072();
                    D_24e6 = 1;
                }
            }
        }
        else if (D_2767 == 0xa && param_1 == 8)
        {
            D_2767 = 3;
        }
        else if (D_2767 == 0xb && param_1 == 7)
        {
            D_2767 = 2;
        }
        else if (param_1 == D_275a[0])
        {
            D_2767 = 1;
        }
        else
        {
            D_2767 = 0;
        }
    }
    else
    {
        local_4 = FUN_1000_4080(param_1);
    }

    return local_4;
}

// TODO: MATCH
void F_TOWN_0f02(void)
{
    int local_8;
    int local_a;
    int local_4;
    int local_6;

    for (local_6 = 0; local_6 < D_585b; local_6++)
    {
        if ((D_55a8_party[local_6]._b == 'S') && FUN_1000_2092_random_range(0, 0xf) == 0xf)
        {
            D_55a8_party[local_6]._b = 'G';
        }
    }

    do
    {
        local_4 = 0;
        local_a = *FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y);
        if (local_a == 0x8c && (D_587c & 0xfe) != 0x14)
        {
            FUN_1000_1850_print_string("A TRAPDOOR!\n"); // 2768
            local_8 = D_587c;
            D_587c = 0;
            FUN_1000_5910_update_map();
            FUN_1000_2aa8();
            D_587c = local_8;
            if (D_5893_map_id == 0x1d)
            {
                FUN_1000_0a70_set_pen_color(0);
                FUN_1000_0aa6_fill_rectangle(8, 8, 0xb7, 0xb7);
                for (local_6 = 1000; local_6 > 0xfa; local_6--)
                {
                    FUN_1000_22e2_pcspk_start_tone(local_6);
                    FUN_1000_20c8_some_delay(1, 0x28);
                }
                FUN_1000_230e_pcspk_off();

                memset(D_6608, 0x8f, 0x400);

                D_24e6 = 1;

                memset(D_5c5a, 0, 0x100);

                for (local_6 = 0; (local_6 < D_585b); local_6++)
                {
                    D_55a8_party[local_6]._10 = 0;
                    D_55a8_party[local_6]._b = 0x44;
                    FUN_1000_223c_audio_white_noise(0x28, 3000, 500);
                    FUN_1000_2900_update_vitals();
                }
            }
            else
            {
                D_5895_map_level--;
                F_TOWN_0408(1);
                local_4 = 1;
            }
        }
        else if (local_a == 0x04 && D_587c == 0x1c)
        {
            // 105d; 1067; 1064
            for (local_6 = 0; local_6 < D_585b; local_6++)
            {
                // 1071
                if (D_55a8_party[local_6]._b != 'D' &&
                    D_55a8_party[local_6]._b != 'P' &&
                    D_55a8_party[local_6]._d < FUN_1000_2092_random_range(0, 0x1d))
                {
                    FUN_1000_1850_print_string("Poisoned!\n"); // 2775
                    D_55a8_party[local_6]._b = 0x50;
                    FUN_1000_2900_update_vitals();
                }
            }
        }
        // 10ac
        else if (local_a == 0xbc || local_a == 0x8f)
        {
            // 10ba
            FUN_1000_5910_update_map();
            FUN_1000_1850_print_string("Burning!\n"); // 2780
            FUN_1000_2aa8();
        }
        // 10c7
    } while (local_4);

    // 10d0
    FUN_1000_2ae8();
}

// OK P1
void F_TOWN_10da(int param_1)
{
    FUN_1000_1850_print_string(/*0x278a*/ "\"Begone,\nvermin!\"\n");
    FUN_1000_2aa8();
    F_TOWN_08d4(param_1);
}

// OK P1
int F_TOWN_10f2(int param_1)
{
    int local_8;
    int local_6;
    int local_4;

    local_4 = 0;
    for (local_6 = 0; local_6 < 4; local_6++)
    {
        if (D_5d5e[param_1]._c[local_6] != 0)
        {
            local_4 = 1;
        }
    }

    local_8 = D_659e[local_6];
    if (local_8 < 0x40 || local_8 >= 0x74)
    {
        local_4 = 0;
    }

    if (FUN_1000_2092_random_range(0, 1) != 0)
    {
        local_4 = 0;
    }

    return local_4;
}

// OK P1
void F_TOWN_1156(void)
{
    int local_4;

    switch (D_5958)
    {
    case 1:
        for (local_4 = 0; local_4 < 0x20; local_4++)
        {
            if (F_TOWN_10f2(local_4) != 0)
            {
                F_TOWN_085e(local_4);
                D_5f5e[local_4]._a = 0xfe;
            }
        }
        break;

    case 2:
        for (local_4 = 0; local_4 < 0x20; local_4++)
        {
            if (F_TOWN_10f2(local_4) != 0)
            {
                F_TOWN_08d4(local_4);
                D_5f5e[local_4]._a = 0xfd;
            }
        }
        break;
    }
}

// OK P1
void F_TOWN_11b8(int param_1)
{
    FUN_1000_1850_print_string(/*0x27b8*/ "\nAn air of\n");
    FUN_1000_1850_print_string(D_27dc[param_1]);
    FUN_1000_1850_print_string(/*0x27c4*/ " doth surround thee...\n");
    FUN_1000_2192_audio_some_noise(0x19c8, 1, 60000, 2000, 1);
}

// OK P1 (complete)
void F_TOWN_11f0_Entry(int param_1)
{
    int local_4;

    D_a9bc = D_24e6 = 1;
    if (param_1 != 0)
    {
        for (local_4 = 1; local_4 < 0x20; local_4++)
        {
            D_5c5a[local_4]._0_tile = 0;
        }
        D_5957 = 0;
        D_58a4 = 1;
        F_NPC_0000();
        F_NPC_00d6(D_587f);
    }
    D_5958 = 0xff;
    F_TOWN_0408(param_1);
    F_TOWN_02ae();

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        if (F_TOWN_0000(local_4) != 0)
            F_TOWN_00b0(local_4);
    }

    if ((D_5893_map_id == 29) && (D_57b5 != 0))
        F_TOWN_00b0(9);

    FUN_1000_2900_update_vitals();

    if (0 <= FUN_1000_39fc_get_first_active_party_member())
    {
        FUN_1000_5910_update_map();
        if (D_5893_map_id == 29)
        {
            for (local_4 = 2; local_4 >= 0; local_4--)
            {
                if (D_58c8[local_4] < 0x80)
                {
                    F_TOWN_11b8(local_4);
                }
            }
        }
        else if (D_5958 != (byte)-1)
        {
            F_TOWN_11b8(D_5958);
            F_TOWN_1156();
        }
    }
}

// OK P1
int F_TOWN_12ae(void)
{
    int local_6;
    char local_4;

    local_6 = 0;
    if (D_5893_map_id == 0x12)
    {
        if (FUN_1000_39fc_get_first_active_party_member() < 0)
        {
            return local_6;
        }

        F_BLCKTHRN_060e_capture();
        F_TOWN_11f0_Entry(1);
    }
    else
    {
        FUN_1000_1850_print_string(/*0x27e2*/ "\n\"Thou art under arrest!\"\n\n");
        FUN_1000_1850_print_string(/*0x27fe*/ "\"Wilt thou come quietly?\"\n\n:");

        do
        {
            local_4 = FUN_1000_266c_get_ch();
        } while (local_4 != 'N' && local_4 != 'Y');

        if (local_4 == 'Y')
        {
            FUN_1000_1850_print_string(/*0x281b*/ "Yes\n\nThe guard strikes thee unconscious!\n");
            FUN_1000_0a70_set_pen_color(0);
            FUN_1000_1850_print_string(/*0x2845*/ "\nThou dost awaken to...\n");
            D_5893_map_id = 4;
            D_5896_map_x = 0x19;
            D_5897_map_y = 4;
            D_24e6 = 1;

            while (D_587f != 8)
            {
                FUN_1000_4f7c(0x14);
            }

            D_5895_map_level = D_57ac = 0;

            F_TOWN_11f0_Entry(1);
        }
        else
        {
            FUN_1000_1850_print_string(/*0x285e*/ "No\n\n\"Then defend thyself, rogue!\"\n");
            F_TOWN_0958();
            local_6 = 1;
        }
    }

    return local_6;
}

// OK P1
void F_TOWN_1352(int param_1)
{
    ActorFmt* local_6;
    int local_4;

    local_4 = 0;
    local_6 = &D_5c5a[D_5f5e[D_65bf]._c];

    FUN_1000_5910_update_map();

    if (D_65be == 0x61)
    {
        if (D_5f5e[D_65bf]._a == 0xfe)
        {
            FUN_1000_16ba_print_char(10);
            F_TOWN_10da(D_65bf);
        }
        else if (local_6->_0_tile != 0x70)
        {
            local_4 = 1;
        }
        else
        {
            local_4 = F_TOWN_12ae();
        }
    }
    else if (param_1 == 0)
    {
        if (D_5f5e[D_65bf]._a != 0 && F_TALK_031e(D_65bf) != 0)
        {
            local_4 = F_TOWN_12ae();
        }
    }

    if (local_4 != 0)
    {
        if (D_5c5a[D_5f5e[D_65bf]._c]._0_tile >= 0x40)
        {
            FUN_1000_1850_print_string(/*0x2881*/ "\nAttacked!\n");
            F_TOWN_09bc(D_65bf);
        }
        else
        {
            F_TOWN_00b0(D_65bf);
        }
    }
}

// OK P1
void F_TOWN_141e_MainLoop(void)
{
    int local_4;
    int local_6;
    uint local_8;
    int local_a;
    uint local_c;
    int local_e;
    int local_10;
    int local_12;

    local_10 = 0;
    local_6 = 0;
    do
    {
        local_e = 0;
        local_c = 1;
        local_a = FUN_1000_39fc_get_first_active_party_member();
        // 1456
        if (local_a == 1)
        {
            FUN_1000_16ba_print_char(10);
            FUN_1000_4c2a();
            FUN_1000_1850_print_string("Zzzzzz...\n");
        }
        else if (local_a == -1)
        {
            F_BLCKTHRN_0910_death();
            local_c = 0;
        }
        else
        {
            if (D_a9bc != 0)
            {
                D_a9bc = 0;
            }
            else
            {
                if (FUN_1000_48a8() != 0) // FMT: F_LOOKOBJ_UNK();
                {
                    F_CAST2_0e76(); // thunk f89a
                }
            }
            if (D_5893_map_id == 0)
            {
                return;
            }

            local_4 = 1;

            do {
                // 148f
                local_8 = F_TOWN_0dc4(local_4);
                local_4 = 0;

                if (local_8 < 0x20)
                {
                    // 14a5
                    switch (local_8)
                    {
                    case 0xb: // 14b8 (9688)
                        FUN_1000_1a3e_print_number(D_5888, 1, 0x20);
                        // 14ff
                        FUN_1000_16ba_print_char(10);   // 94ea
                        // 154b
                        local_c = 0;
                        break;

                    case 5: // 14cc (969c)
                        FUN_1000_1850_print_string("Exit to DOS? ");
                        local_8 = FUN_1000_266c_get_ch();
                        if (local_8 == 0x59)
                        {
                            FUN_1000_0878_set_old_video_mode();
                            FUN_1000_02f4_exit_to_dos(0); // cdecl
                        }
                        else
                        {
                            FUN_1000_1850_print_string("N\n");
                        }
                        break;

                    case 0x16: // 14f8 (96c8)
                        FUN_1000_1850_print_string("1.16");
                        FUN_1000_16ba_print_char(10);
                        local_c = 0;
                        break;

                    case 0x13: // 1508 (96d8)
                        FUN_1000_1850_print_string("Sound "); // TODO                            
                        if (D_a9ce != 0)
                        {
                            FUN_1000_1850_print_string("Off\n");
                        }
                        else
                        {
                            FUN_1000_1850_print_string("On\n");
                        }

                        D_a9ce = !D_a9ce;
                        // 154b
                        local_c = 0;
                        break;

                    case 1:
                    case 2:
                    case 3:
                    case 4: // 1532 (9702)
                        local_e = F_TOWN_0600(local_8); // bp-06
                        local_c = (uint)(local_e == 0); // -> 159a
                        break;

                    default: // 1544 (9714)
                        FUN_1000_1850_print_string("What?\n");
                        local_c = 0;
                        break;
                    }
                }
                else if ((local_8 < 0x30) || (0x39 < local_8))
                {
                    local_c = FUN_1000_3178_process_command(local_8);
                }
                else
                {
                    local_c = F_TOWN_0e34(local_8);
                }
                // 159d
            } while (local_c == 3);
        }
        // 15a6
        if (D_5893_map_id == 0)
        {
            local_e = 1;
        }
        else if ((local_c != 0) && (FUN_1000_39fc_get_first_active_party_member() != -1))
        {
            local_12 = D_587f;
            FUN_1000_4f7c(1);
            if ((D_587f != local_12) && (D_587f == 20 || D_587f == 5))
            {
                F_TOWN_0170();
            }
            // 15ec
            F_TOWN_0f02();
            if ((D_594f != 0) && (D_5952--, D_5952 == 0))
            {
                FUN_1000_39cc_set_new_tile_id(D_594f, D_5950, D_5951);
            }
            // 160d
            D_5c5a[0]._2_x = D_5896_map_x;
            D_5c5a[0]._3_y = D_5897_map_y;
            D_5c5a[0]._4_z = D_5895_map_level;
            if (((((D_587c < 0x12) || (0x16 <= D_587c)) || (local_8 == 0x20)) ||
                (local_6 = !local_6, !local_6)) &&
                ((D_587a != 'T' && ((D_587a != 'Q' || (local_10 = !local_10, !local_10))))))
            {
                // 165f
                F_TOWN_0c78();
                if ((int)local_c < 2)
                {
                    F_NPC_0db4(D_587f);
                }
                // 1671
                if ((D_65bf != 0) || (local_c == 2))
                {
                    // 167e
                    F_TOWN_1352(local_c - 1);
                }
            }
        }
        // 1686
    } while (local_e == 0);

    // 168f
}

// OK P1
void F_TOWN_1694(void)
{
    int local_4;
    int local_6;

    for (local_4 = 1; local_4 < 0x20; local_4++)
    {
        FUN_1000_3a74(0, 0, 0, 0, 0, 0, local_4);
        D_5f5e[local_4]._c = 0;
    }

    for (local_4 = 1; local_4 < 0x20; local_4++)
    {
        if (D_659e[local_4] != 0)
        {
            local_6 = F_NPC_12e0(local_4, D_587f);
            F_TOWN_1726(local_4, D_5d5e[local_4]._3[local_6], D_5d5e[local_4]._6[local_6], D_5d5e[local_4]._9[local_6]);
            D_5f5e[local_4]._0 = 1;
            D_5f5e[local_4]._e = local_6;
            D_655e[local_4] = 0xffff;
        }
    }
}

// TODO: MATCH
void F_TOWN_1726(int param_1, byte param_2, byte param_3, byte param_4)
{
    int iVar5;
    byte uStack_8;

    if (D_659e[param_1] == 0)
        return;

    if (param_4 != D_5895_map_level && D_5f5e[param_1]._c != 0)
    {
        D_5c5a[D_5f5e[param_1]._c]._0_tile = 0;
        D_5f5e[param_1]._c = 0;
    }

    if (param_4 == D_5895_map_level && D_5f5e[param_1]._c == 0)
    {
        iVar5 = FUN_1000_38e4();

        if (D_659e[param_1] == 1)
        {
            uStack_8 = 0x1e;
        }
        else if ((D_28c6[D_5893_map_id - 1] & (1 << ((byte)param_1 & 0x1f))) == 0)
        {
            uStack_8 = 0;
        }
        else
        {
            uStack_8 = 0xff;
        }

        FUN_1000_3a74(D_659e[param_1], D_659e[param_1], param_2, param_3, param_4, uStack_8, iVar5);

        D_5c5a[iVar5]._6 = 0;
        D_5f5e[param_1]._c = iVar5;
    }

    if (param_4 == D_5895_map_level && D_5f5e[param_1]._c != 0)
    {
        iVar5 = D_5f5e[param_1]._c;
        D_5c5a[iVar5]._2_x = param_2;
        D_5c5a[iVar5]._3_y = param_3;
        D_5c5a[iVar5]._4_z = param_4;
    }

    D_5f5e[param_1]._2 = param_2;
    D_5f5e[param_1]._4 = param_3;
    D_5f5e[param_1]._6 = param_4;
    D_5f5e[param_1]._0 = 1;
}
