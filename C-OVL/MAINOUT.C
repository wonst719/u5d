#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>

F_OUTSUBS_01b4(int a, int b);
F_OUTSUBS_0566();

int FUN_1000_38e4();

void F_MAINOUT_0000()
{
    FUN_1000_4be8();
    FUN_1000_4f7c(0);

    D_58a4 = D_5956 = D_24e6 = 1;
    D_5955 = 0;
    D_589b = D_5896_map_x & 0xf0;
    if ((D_5896_map_x & 0xf) < 8)
    {
        D_589b = (D_589b - 0x10) & 0xf0;
    }

    // 0034
    D_589c = D_5897_map_y & 0xf0;
    if ((D_5897_map_y & 0xf) < 8)
    {
        D_589c = (D_589c - 0x10) & 0xf0;
    }

    // 004f
    F_OUTSUBS_01b4(0, 1);
    F_OUTSUBS_01b4(0, -1);
    FUN_1000_4f7c(0);
    FUN_1000_5e4a();
    FUN_1000_2e96_print_direction(-1);
    FUN_1000_4a84();
    F_OUTSUBS_0566();
}

F_MAINOUT_0598() {}
F_MAINOUT_0490(int a, int b) {}

int F_MAINOUT_0a1a(int a) {}

F_CAST2_0e76();

FUN_1000_3522(int x, int y) {}
FUN_1000_3ae6(int a) {}
FUN_1000_4080(int a) {}

F_OUTSUBS_05fc() {}
F_OUTSUBS_05ee() {}
F_OUTSUBS_0458() {}

F_MAINOUT_0a60() {}
F_MAINOUT_109e() {}
F_MAINOUT_1a60() {}
F_MAINOUT_1be8() {}

char* F_OUTSUBS_0368_GetWorldSavefile();
void F_BLCKTHRN_0910_death();

// TODO: text
void F_MAINOUT_0a84_main_loop()
{
    bool local_c;
    undefined2 local_4 = 0;
    int local_8;
    byte local_6;
    uint uVar5;
    byte* pbVar6;
    byte bVar7;
    int local_a;
    undefined2 local_10;
    do {
        // 0a8f
        local_c = 0;
        local_a = 1;
        local_4 = F_MAINOUT_0a1a(local_4);
        local_8 = FUN_1000_39fc_get_first_active_party_member();
        if (local_8 == 1)
        {
            FUN_1000_16ba_print_char(10);
            FUN_1000_4c2a();
            // 0aba
            FUN_1000_1850_print_string("Zzzzzz...");
        }
        else if (local_8 == -1) // 0ac2
        {
            if (D_a9bd != 1)
            {
                FUN_1000_251e_switch_disks(1);
                // 0ad6
                while (FUN_1000_1674_test_open_file("BRIT.DAT") == 0) {}
            }
            // 0ae1
            FUN_1000_25d8_write_file_to_disk(F_OUTSUBS_0368_GetWorldSavefile(), D_5c5a, 0x100);
            F_BLCKTHRN_0910_death();
            local_c = 1;
            local_a = 0;
        }
        else
        {
            // 0b00
            if (FUN_1000_48a8() != 0)
            {
                F_CAST2_0e76();
            }
            // 0b0a
            if (D_5893_map_id != 0)
            {
                return;
            }
            // 0b14
            local_6 = F_MAINOUT_0598();
            if (local_6 < 0x20)
            {
                switch (local_6 & 0xff)
                {
                case 0xb: // 0b34
                    FUN_1000_1a3e_print_number(D_5888, 1, 0x20);
                    // -> 0b75
                    FUN_1000_16ba_print_char(10);
                    // -> 0af8
                    local_a = 0;
                    break; // -> 0c12

                case 5: // 0b48
                    FUN_1000_1850_print_string("2b3e");
                    local_6 = FUN_1000_266c_get_ch();
                    if (local_6 == 'Y')
                    {
                        FUN_1000_0878_set_old_video_mode();
                        FUN_1000_02f4_exit_to_dos(0);
                    }
                    else
                    {
                        FUN_1000_1850_print_string("2b4c");
                    }
                    break;

                case 0x16: // 0b6e
                    FUN_1000_1850_print_string("2b4f");
                    // 0b75
                    FUN_1000_16ba_print_char(10);
                    local_a = 0;
                    break;

                case 0x13: // 0b80
                    FUN_1000_1850_print_string("2b54");
                    if (D_a9ce != 0)
                    {
                        FUN_1000_1850_print_string("2b5b");
                    }
                    else
                    {
                        FUN_1000_1850_print_string("2b60");
                    }
                    // ?
                    D_a9ce = !D_a9ce;
                    break;

                case 1: // 0baa
                case 2:
                case 3:
                case 4:
                    local_a = F_MAINOUT_0490(local_6, local_4);
                    break;

                case 0: // 0af8
                    local_a = 0;
                    break;

                default: // 0bb8
                    FUN_1000_1850_print_string("s_What ? _0004d954");
                    break;
                }
            }
            else
            {
                // 0bee
                if ((local_6 < 0x30) || (0x39 < local_6))
                {
                    // 0bfa
                    local_a = FUN_1000_3178_process_command(local_6 & 0xff);
                }
                else
                {
                    // 0c06
                    local_a = FUN_1000_4080(local_6);
                }
            }
        }
        // 0c12
        if ((D_587c & 0xfc) != 0x20)
        {
            D_5955 = 0;
        }
        // 0c20
        if (D_5893_map_id == 0)
        {
            if (local_a != 0)
            {
                // 0c39
                FUN_1000_4f7c(2);
                pbVar6 = (byte*)FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y);
                bVar7 = *pbVar6;
                if ((bVar7 & 0xfe) == 0x6a)
                {
                    F_MAINOUT_1be8();
                }
                // 0c64
                else if ((bVar7 == 4) && (D_587c == 0x1c))
                {
                    F_OUTSUBS_05fc();
                    FUN_1000_3ae6(1);
                }
                else if (bVar7 == 0x8f)
                {
                    F_OUTSUBS_05ee();
                }
                else if (D_5896_map_x == 0xe9 && D_5897_map_y == 0xeb && D_5895_map_level == 0 && D_5893_map_id == 0)
                {
                    FUN_1000_1850_print_string("2b6b");
                    if (D_58cc == 0)
                    {
                        FUN_1000_1850_print_string("s_Thou_art_not_upon_a_Sacred_Quest"); // 2b7e
                        FUN_1000_1850_print_string("s_Passage_denied!"); // 2ba1
                        D_5897_map_y++;
                    }
                    else
                    {
                        FUN_1000_1850_print_string("s_Pass, _Seeker!"); // 2b6e
                    }
                }

                // 0cd0
                F_MAINOUT_0a60();
                FUN_1000_2ae8();
                if (bVar7 == 1 && (D_587c & 0xfc) == 0x28 || (D_587c & 0xfe) == 0x14)
                {
                    FUN_1000_1850_print_string("s_Rough_seas!_0004d9a8");
                    FUN_1000_3522(D_5896_map_x, D_5897_map_y);
                    F_MAINOUT_109e();
                }
                if ((bVar7 & 0xfc) == 0xd4)
                {
                    F_OUTSUBS_0458();
                }
                F_MAINOUT_1a60();
            }
        }
        else
        {
            local_c = 1;
        }
        local_10 = local_4;
    } while (!local_c);
}

// load_mainout_ovl
// OK P1 (reg)
void F_MAINOUT_0d22()
{
    undefined1 local_8;
    int local_6;
    ActorFmt* local_4;

    F_MAINOUT_0000();

    if (D_6605 >= 0x40)
    {
        local_6 = FUN_1000_38e4();
        local_4 = &D_5c5a[local_6]; // get some actor
        local_4->_7 = D_6605 & 0x3f;
        local_4->_2_x = D_5953; // ship_x
        local_4->_3_y = D_5954; // ship_y
        local_4->_4_z = 0;

        if (D_6605 > 0x7f)
        {
            local_8 = 0x25;
        }
        else
        {
            local_8 = 0x29;
        }

        local_4->_0_tile = local_4->_1 = local_8;
        local_4->_5 = 99;
        D_6605 = 0;
    }

    F_MAINOUT_0a84_main_loop();
}
