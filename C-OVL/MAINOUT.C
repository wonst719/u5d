#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>

F_CAST2_0e76();

void F_OUTSUBS_01b4(int param_1, int param_2);
F_OUTSUBS_0458();
void F_OUTSUBS_0566(void);
F_OUTSUBS_05ee();
F_OUTSUBS_05fc();

// OK P1
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

// OK P1
int F_MAINOUT_00da(int param_1)
{
    int local1_6;
    int local2_4 = 0;

    switch (D_587c & 0xfc)
    {
    case 0x10:
        // 010a
        FUN_1000_1850_print_string("Ride "); // 2946
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
        // 0130
        FUN_1000_1850_print_string("Fly ");
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
        // 0152
        FUN_1000_1850_print_string("Row ");
        D_587c = (char)param_1 + (D_587c & 0xfc);
        break;

    case 0x20:
    case 0x24:
        // 016a
        local1_6 = D_587c;
        D_587c = (char)param_1 + (D_587c & 0xfc);
        if (local1_6 != D_587c)
        {
            FUN_1000_1850_print_string("Head ");

            switch (param_1)
            {
            case 0:
                FUN_1000_1850_print_string("North\n");
                break;
            case 2:
                FUN_1000_1850_print_string("South\n");
                break;
            case 1:
                FUN_1000_1850_print_string("East\n");
                break;
            case 3:
                FUN_1000_1850_print_string("West\n");
                break;
            }

            // 01ad
            D_5956 = local2_4 = 1;
            if (D_5c5a[0]._5 < 0x32)
            {
                FUN_1000_1850_print_string("Hull weak!\n");
            }
        }
        // 01dc
        else if (D_587c < 0x24 && D_5892_wind_dir == 0)
        {
            local2_4 = 1;
        }

        break;
    }

    // 0129
    return local2_4;
}


int F_MAINOUT_01fe(int a, int b) {}

void F_MAINOUT_0354(int a, int b) {}
void F_MAINOUT_03e0() {}

// OK P1
int F_MAINOUT_0490(int param_1, int param_2)
{
    int local_8;
    int local_6;
    int local_4;

    if ((D_587c & 0xfc) == 0x20)
    {
        if (param_1 != D_5955)
        {
            D_5955 = param_1;
            D_5883 = 0;
        }
        D_5956 = 0;
    }

    // 04b8
    if ((D_587c == 0x1c) || ((D_587c & 0xfe) == 0x12))
    {
        FUN_1000_433e_audio_some_noise();
    }

    // 04cb
    local_6 = local_8 = 0;

    switch (param_1)
    {
    case 3:
        // 04f0
        local_8--;
#if _WIN32
        local_4 = F_MAINOUT_00da(0);
        if (local_4 != 0)
        {
            return local_4;
        }
#else
        if (F_MAINOUT_00da(0))
        {
            return;
        }
#endif

        // 0500
        if (D_5955 == 0)
        {
            FUN_1000_1850_print_string("North\n"); // 29db
        }
        break;

    case 4:
        // 054e
        local_8++;
#if _WIN32
        local_4 = F_MAINOUT_00da(2);
        if (local_4 != 0)
        {
            return local_4;
        }
#else
        if (F_MAINOUT_00da(2))
        {
            return;
        }
#endif
        if (D_5955 == 0)
        {
            FUN_1000_1850_print_string("South\n");
        }
        break;

    case 2:
        // 055c
        local_6++;
#if _WIN32
        local_4 = F_MAINOUT_00da(1);
        if (local_4 != 0)
        {
            return local_4;
        }
#else
        if (F_MAINOUT_00da(1))
        {
            return;
        }
#endif
        if (D_5955 == 0)
        {
            FUN_1000_1850_print_string("East\n");
        }
        break;

    case 1:
        // 0576
        local_6--;
#if _WIN32
        local_4 = F_MAINOUT_00da(3);
        if (local_4 != 0)
        {
            return local_4;
        }
#else
        if (F_MAINOUT_00da(3))
        {
            return;
        }
#endif
        if (D_5955 == 0)
        {
            FUN_1000_1850_print_string("West\n");
        }
        break;
    }

    // 050e
    local_4 = F_MAINOUT_01fe(local_6, local_8);
    if (param_2 == 0 && local_4 != 0)
    {
        if ((D_587c & 0xfe) == 0x12)
        {
            FUN_1000_433e_audio_some_noise();
        }
        // 0530
        F_MAINOUT_0354(local_6, local_8);
        F_MAINOUT_03e0();
    }
    return local_4;
}

F_MAINOUT_1a60();

// OK P1
int F_MAINOUT_0598(void)
{
    int local1_a;
    int local2_8;
    int local3_6;
    int local4_4;

    FUN_1000_5910_update_map();
    if (D_a9fa != 0)
    {
        FUN_1000_2900_update_vitals();
        D_a9fa = 0;
    }

    // 05b2
    if ((D_ab02[0xc5] & 0xfc) == 0xd4)
    {
        F_OUTSUBS_0458();
        local3_6 = 0;
    }
    else
    {
        // 05c6
        if (D_5956 != 0)
        {
            FUN_1000_16ba_print_char(10);
            FUN_1000_4c2a();
        }

        // 05d7
        D_5956 = 1;
        while (D_5955 != 0)
        {
            local3_6 = FUN_1000_2032_to_upper(FUN_1000_1b38_keystroke_cursor());
            if (local3_6 != 0 && local3_6 != D_5955)
                break;

            // 05e6
            local3_6 = (uint)D_5955;
            if (D_5892_wind_dir != 0)
            {
                local2_8 = local1_a = 0;

                switch (local3_6)
                {
                case 3:
                    // 0614
                    local1_a = -1;
                    break;
                case 4:
                    // 0658
                    local1_a = 1;
                    break;
                case 2:
                    // 0660
                    local2_8 = 1;
                    break;
                case 1:
                    // 0668
                    local2_8 = -1;
                    break;
                }

                // 0619
                local4_4 = 1;
                if (D_29f5[D_5892_wind_dir] != local2_8)
                {
                    local4_4++;
                }
                // 062e
                if (D_29f9[D_5892_wind_dir] != local1_a)
                {
                    local4_4++;
                }
                // 0640
                if (local4_4 % 3 <= (uint)D_5883)
                {
                    D_5883 = 0;
                    break;
                }
            }

            // 0670
            if (D_57bb > 0x7f)
            {
                D_a524 = (uint)(D_a524 == 0);
                FUN_1000_4f7c(1);
            }
            else
            {
                FUN_1000_4f7c(2);
            }

            if (D_a524 == 0 || D_57bb < 0x80)
            {
                F_MAINOUT_1a60();
            }

            FUN_1000_3ae6(1);
            D_5883 = D_5883 + 1;
        }

        if (D_5955 == 0)
        {
            local3_6 = FUN_1000_266c_get_ch();
        }
    }

    return local3_6;
}

// OK P1
int F_MAINOUT_0a1a(int param_1)
{
    if (*FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y) == 0xff && D_587a != 0xe)
    {
        D_58a5 = 0;
        if (param_1 == 0)
        {
            FUN_1000_5910_update_map();
            param_1 = 1;
        }
    }
    else
    {
        param_1 = 0;
        FUN_1000_4f7c(0);
    }

    return param_1;
}

F_MAINOUT_0a60() {}

F_MAINOUT_109e();
F_MAINOUT_1be8();

char* F_OUTSUBS_0368_GetWorldSavefile();
void F_BLCKTHRN_0910_death();

// OK P1 (stack)
void F_MAINOUT_0a84_main_loop()
{
    int local_4 = 0;
    byte local_6;
    int local_8;
    int local_a;
    bool local_c;
    int local_e; // not used
    int local_10; // not used
    int local_12;
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
            FUN_1000_1850_print_string("Zzzzzz...\n");
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
                    FUN_1000_1850_print_string("Exit to DOS? ");
                    local_6 = FUN_1000_266c_get_ch();
                    if (local_6 == 'Y')
                    {
                        FUN_1000_0878_set_old_video_mode();
                        FUN_1000_02f4_exit_to_dos(0);
                    }
                    else
                    {
                        FUN_1000_1850_print_string("N\n");
                    }
                    break;

                case 0x16: // 0b6e
                    FUN_1000_1850_print_string("1.16");
                    // 0b75
                    FUN_1000_16ba_print_char(10);
                    local_a = 0;
                    break;

                case 0x13: // 0b80
                    FUN_1000_1850_print_string("Sound ");
                    if (D_a9ce != 0)
                    {
                        FUN_1000_1850_print_string("Off\n");
                    }
                    else
                    {
                        FUN_1000_1850_print_string("On\n");
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
                    FUN_1000_1850_print_string("What?\n");
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
        if (D_5893_map_id != 0)
        {
            local_c = 1;
        }
        else
        {
            if (local_a != 0)
            {
                // 0c39
                FUN_1000_4f7c(2);
                local_12 = *FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y);
                if ((local_12 & 0xfe) == 0x6a)
                {
                    F_MAINOUT_1be8();
                }
                // 0c64
                else if ((local_12 == 4) && (D_587c == 0x1c))
                {
                    F_OUTSUBS_05fc();
                    FUN_1000_3ae6(1);
                }
                else if (local_12 == 0x8f)
                {
                    F_OUTSUBS_05ee();
                }
                else if (D_5896_map_x == 0xe9 && D_5897_map_y == 0xeb && D_5895_map_level == 0 && D_5893_map_id == 0)
                {
                    FUN_1000_1850_print_string("\n\"");
                    if (D_58cc != 0)
                    {
                        FUN_1000_1850_print_string("Pass, Seeker!\"\n");
                    }
                    else
                    {
                        FUN_1000_1850_print_string("Thou art not upon a Sacred Quest!\n");
                        FUN_1000_1850_print_string("Passage denied!\"\n");
                        D_5897_map_y++;
                    }
                }

                // 0cd0
                F_MAINOUT_0a60();
                FUN_1000_2ae8();
                if (local_12 == 1 && ((D_587c & 0xfc) == 0x28 || (D_587c & 0xfe) == 0x14))
                {
                    FUN_1000_1850_print_string("Rough seas!\n");
                    FUN_1000_3522(D_5896_map_x, D_5897_map_y);
                    F_MAINOUT_109e();
                }
                if ((local_12 & 0xfc) == 0xd4)
                {
                    F_OUTSUBS_0458();
                }
                F_MAINOUT_1a60();
            }
        }
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

F_MAINOUT_109e() {}
F_MAINOUT_1a60() {}
F_MAINOUT_1be8() {}
