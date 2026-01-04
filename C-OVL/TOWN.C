#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>

F_TOWN_0000() { puts("F_TOWN_0000"); }
F_TOWN_00b0() { puts("F_TOWN_00b0"); }
F_TOWN_0170() { puts("F_TOWN_0170"); }
F_TOWN_0212() { puts("F_TOWN_0212"); }
F_TOWN_02ae() { puts("F_TOWN_02ae"); }

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
                D_5896_map_x = *(D_5893_map_id + D_1e89);
                D_5897_map_y = *(D_5893_map_id + D_1eb1);
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

F_TOWN_0958() { puts("F_TOWN_0958"); }

F_TOWN_0c4a(int a, int b) { printf("F_TOWN_0c4a(%d,%d)\n", a, b); }

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

F_TOWN_0e34() { puts("F_TOWN_0e34"); }
F_TOWN_0f02() { puts("F_TOWN_0f02"); }
F_TOWN_1156() { puts("F_TOWN_1156"); }
F_TOWN_11b8() { puts("F_TOWN_11b8"); }

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

F_TOWN_1352() { puts("F_TOWN_1352"); }

extern F_NPC_0db4();

// OK P1
void F_TOWN_141e_MainLoop()
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

F_TOWN_1694() { puts("F_TOWN_1694"); }
