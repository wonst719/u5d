#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>

// NOTE: 헤더 같은 게 있어서 주소가 0x10 밀려 있음.


F_INTRO_0010() {}
F_INTRO_0050(int a, int b) {}
F_INTRO_014e() {} // play_story
F_INTRO_043e(char* a) {}
F_INTRO_04e0() {} // draw_menu_borders
F_INTRO_05b0(int a) {} // display_title(0 for fast display)
F_INTRO_0676(int a, int b, int c, int d) {} // write_menu_option(string, x in window, y in window, highlighted option y)
F_INTRO_06bc(int a) {} // build_main_menu
F_INTRO_072e() {} // acknowledgements (88ee)
F_INTRO_094e(int a) {} // pause(wait time) (8b0e)

cdecl FUN_1000_02F4_exit_to_dos(int a);

// OK P1 (NOT MATCHING: local variable order)
void F_INTRO_0986() // intro_main (initialize video) (8b46)
{
    int local_4;
    char *local_6;
    int local_8;
    int local_a;
    int local_c;
    int local_e;
    byte local_10;
    int local_12;
    int local_14;

    // 098e
    D_a9ce = 1;
    local_e = 0;

    // 0995
    for (local_e = 0; local_e < 0x100; local_e++) {
        D_b11e[local_e] = (char)local_e;
    }

    FUN_1000_0DE0_detect_video();
    FUN_1000_1158_init_timer();
    local_8 = D_5356;

    // force cga if low memory
    if ((D_52ba_vdp._52c8_videoDriverSelection == 2) && (D_5358 < 0x170)) {
        D_52f1_forceTandy = 0;
        D_52ba_vdp._52ba_forceCga = 1;
        D_52ba_vdp._52c8_videoDriverSelection = 0;
    }

    // 09d2
    while (FUN_1000_0E94_load_video_driver() == 0) {}

    FUN_1000_0892_initialize_video_driver(1);

    if ((D_52ba_vdp._52c8_videoDriverSelection != 0) && (D_52ba_vdp._52c8_videoDriverSelection != 3))
    {
        D_13b2 = 1;
        D_13ae = 4;
        D_13b0 = 0xf;
        D_13b6 = 5;
        D_13b4 = 2;
        D_13b8 = 0xe;
        D_13ba = 7;
    } else {
        // 0a1a
        local_e = 0;

        // cga / herc: *.16 -> *.4
        while (*(local_6 = D_25ea[local_e++]) != 0) // 0a35
        {
            // 0a22
            while (*local_6++ != '.') {}

            if (*local_6 == '1') {
                *local_6++ = '4';
                *local_6 = '\0';
            }
        }
    }

    // 0a49
    if (FUN_1000_0F2A_init_data_buffer() == 0)
    {
        FUN_1000_0878_set_old_video_mode();
        FUN_1000_02F4_exit_to_dos(1);
        // 	ADD        SP,2h <- cdecl
    }
    if (D_52ba_vdp._52c8_videoDriverSelection == 3)
    {
        // 0a64
#define TEXT_3182 "ibm.hcs"
        while (FUN_1000_1D02_load_character_set(TEXT_3182, 0) == 0) {}
#define TEXT_318a "runes.hcs"
        while (FUN_1000_1D02_load_character_set(TEXT_318a, 1) == 0) {}
    }
    else
    {
        // 0a84
#define TEXT_3194 "ibm.ch"
        while (FUN_1000_1D02_load_character_set(TEXT_3194, 0) == 0) {}
#define TEXT_319b "runes.ch"
        while (FUN_1000_1D02_load_character_set(TEXT_319b, 1) == 0) {}
    }

    // 0aa1
    FUN_1000_1c9e_get_char_segment(0);
    FUN_1000_1c22_set_text_window_size(0, 0, 0, 0x27, 0x18);
    FUN_1000_1b94_select_charset(0);
    local_a = FUN_1000_2032_to_upper(FUN_1000_1D5E_peek_keystroke());
    if (local_a == 0x4a) // 'J'
    {
        FUN_1000_16ba_print_char(0xff);
        FUN_1000_16ba_print_char(0xfc);
        FUN_1000_1bf2_set_text_cursor_position(0, 0xb);
#define TEXT_31a4 "Journey Onward\n\n"
        FUN_1000_1850_print_string(TEXT_31a4);
        FUN_1000_16ba_print_char(0xfb);
        // 0af2
        while (FUN_1000_0FF4_load_compressed_tileset(D_25f0[0]) == 0) {}
        D_5893_map_id = 0x41;
        // -> 0cc9
    }
    else
    {
        // 0b06
        local_a = 1;

        do {
            local_12 = FUN_1000_0FAE_load_file(*D_25ee); // "TITLE.BIT"
        } while (local_12 == 0);

        do {
            local_14 = FUN_1000_0FAE_load_file(*D_25ec); // "BRITISH.BIT"
        } while (local_14 == 0);

#define TEXT_31b5 "BRITISH.PTH"
        FUN_1000_256e_read_file_from_disk(TEXT_31b5, &D_55a6, ((int)&D_6606 - (int)&D_55a6)/*0x1060*/, 0);
        if (local_a != 0)
            local_a = FUN_1000_0D72(local_12) == 0;

        // 0b56
        FUN_1000_0C22(1);
        FUN_1000_0AA6(0, 0x8c, 0x13f, 199);
        FUN_1000_1044_buffer_image(local_12, 7, 0x6c, 0x8c);
        FUN_1000_0ACE(1, 0, 0, 0x8c, 0x13f, 199);
        if (local_a != 0)
        {
            FUN_1000_20FA_wait_ticks(0x12);
            local_a = F_INTRO_094e(0x14) == 0;
        }
        // 0bb6
        if (local_a != 0)
        {
            // 0bbf
            FUN_1000_16ba_print_char(0xff);
            FUN_1000_1044_buffer_image(local_12, 0x8, 0x98, 0);
            FUN_1000_0F6E_image_data_transfer(1, 0);
            local_a = F_INTRO_094e(0x14) == 0;
            if (local_a != 0)
            {
                FUN_1000_0C22(0);
                D_bb18 = 0;
                local_a = 0;
                if ((F_INTRO_0050(0x2c, 0x44) != 0) &&
                    (F_INTRO_0050(0x40, 0x5e) != 0) &&
                    (F_INTRO_0050(0x8f, 0x4e) != 0))
                {
                    local_a = F_INTRO_0050(0xa7, 0x69);
                }
                // 0c42
                FUN_1000_0C22(1);
            }
            // 0c49
            FUN_1000_1044_buffer_image(local_14, 0, 0x18, 0x42);
            FUN_1000_0F6E_image_data_transfer(1, 0);
            FUN_1000_1044_buffer_image(local_e, 9, 0x68, 0xa0);
            FUN_1000_0F6E_image_data_transfer(1, 0);
            if (local_a != 0) {
                local_a = F_INTRO_094e(0x14) == 0;
            }
        }
        // 0c97
        FUN_1000_0FDC_free_memory(local_14);
        FUN_1000_0FDC_free_memory(local_12);
        D_5893_map_id = 0x40;
        FUN_1000_16ba_print_char(0xff);
        FUN_1000_0C22(0);
        F_INTRO_05b0(local_a);
        if (local_a != 0) {
            FUN_0000_7CDA(); // thunk
        }
        // 0cc4
        local_a = 1;
    }
    FUN_1000_207E(FUN_1000_2056_get_time());

    // 0cd0
    do {
        FUN_1000_1c22_set_text_window_size(0, 1, 0x10, 0x26, 0x17);
        FUN_1000_1b94_select_charset(0);
        FUN_1000_16ba_print_char(0xff);
        FUN_1000_1c22_set_text_window_size(0, 0, 0, 0x27, 0x18);
        FUN_1000_1c22_set_text_window_size(1, 0x18, 1, 0x27, 9);
        FUN_1000_1c22_set_text_window_size(2, 0x18, 0xb, 0x27, 0x17);
        if (local_a == 0x4a) // 'J'
        {
            local_10 = 0x4a; // 'J'
        }
        else
        {
            // OK P1
            // 0d3e
            local_c = 0;
#define TEXT_31c1 "Copyright 1988 Lord British"
            F_INTRO_043e(TEXT_31c1);
            F_INTRO_06bc(0);
            do {
                // 0d4d
                FUN_1000_1bf2_set_text_cursor_position(0xf, 0xf);
                FUN_1000_4C2A();
#define TEXT_31dd "Select: "
                FUN_1000_1850_print_string(TEXT_31dd);
                FUN_1000_4CCE();
                FUN_1000_1bf2_set_text_cursor_position(0x17, 0xf);
                D_5356 = 0x113;
                local_4 = 0;
                do {
                    // 0d75
                    local_10 = FUN_1000_2032_to_upper(FUN_1000_1B38_keystroke_cursor());
                    if (local_10 == 0) {
                        F_INTRO_2090();
                    }
                    // 0d86
                    local_4++;
                } while ((local_4 < 200) && (local_10 == 0));
                D_5356 = local_8;
                // OK P1!
                switch ((int)local_10)
                {
                    case 1:
                    case 3:
                        local_c--;
                        if (local_c < 0) {
                            local_c = 5;
                        }
                        F_INTRO_06bc(local_c);
                        break;
                    case 2:
                    case 4:
                        local_c++;
                        if (5 < local_c) {
                            local_c = 0;
                        }
                        F_INTRO_06bc(local_c);
                        break;
                    case 0xd:  // CR
                    case 0x20: // ' '
                        // 0de2
#define TEXT_3270 "JCTUAR"
                        local_10 = TEXT_3270[local_c];
                        break;
                    case 0:
                        local_10 = 0x52;
                        break;
                    case 0x4a: // 'J'
                        F_INTRO_06bc(0);
                        break;
                    case 0x43: // 'C'
                        F_INTRO_06bc(1);
                        break;
                    case 0x54: // 'T'
                        F_INTRO_06bc(2);
                        break;
                    case 0x55: // 'U'
                        F_INTRO_06bc(3);
                        break;
                    case 0x41: // 'A'
                        F_INTRO_06bc(4);
                        break;
                    case 0x52: // 'R'
                        F_INTRO_06bc(5);
                        break;
                    default:
                        local_10 = 0;
                        break;
                }
            } while (local_10 <= 0x20);
        }

        // 0e47
        switch ((int)local_10)
        {
            case 0x4a: // 'J'
                // 0e7c
                FUN_1000_637E();
                FUN_1000_2E96_print_direction(0);
                FUN_1000_1b94_select_charset(2);
                FUN_1000_1bf2_set_text_cursor_position(0, 0xc);
                if (D_5893_map_id == 0x40) {
                    while (FUN_1000_0FF4_load_compressed_tileset(D_25f0[0]) == 0) {}
                    D_5893_map_id = 0x41;
                }
                // 0ead
                FUN_1000_251e_switch_disks(3);
#define TEXT_31e6 "SAVED.GAM"
                FUN_1000_256e_read_file_from_disk(TEXT_31e6, &D_55a6, ((int)&D_6606 - (int)&D_55a6)/*0x1060*/, 0); // "SAVED.GAM"
                if (*(char*)D_55a8_party == '\0')
                {
#define TEXT_31f0 "\n\nNo active game."
                    FUN_1000_1850_print_string(TEXT_31f0);
#define TEXT_3203 "Please create a character "
                    FUN_1000_1850_print_string(TEXT_3203);
#define TEXT_321e "or transfer one from Ultima IV. "
                    FUN_1000_1850_print_string(TEXT_321e);
                    FUN_1000_1DDA_wait_for_keystroke(0);
                    D_a9cb = 0xff;
                    FUN_1000_251e_switch_disks(0);
                    FUN_1000_1b94_select_charset(0);
                    FUN_1000_16ba_print_char(0xff);
                    FUN_1000_0C22(1);
                    FUN_1000_16ba_print_char(0xff);
                    FUN_1000_0C22(0);
                    F_INTRO_05b0(0);
                    local_a = 0;
                }
                else
                {
                    // 0f26
#define TEXT_323f "SAVED.OOL"
                    FUN_1000_256e_read_file_from_disk(TEXT_323f, 0xb21e, 0x200, 0);
                    FUN_1000_251e_switch_disks(1);
#define TEXT_3249 "BRIT.OOL"
                    FUN_1000_25d8_write_file_to_disk(TEXT_3249, 0xb21e, 0x100);
#define TEXT_3252 "UNDER.OOL"
                    FUN_1000_25d8_write_file_to_disk(TEXT_3252, 0xb31e, 0x100);
                    if ((D_5893_map_id == 0) && (D_5895 != 0)) {
                        FUN_1000_251e_switch_disks(5);
#define TEXT_325c "UNDER.DAT"
                        while (FUN_1000_1674_test_open_file(TEXT_325c) == 0) {}
#define TEXT_3266 "UNDER.OOL"
                        FUN_1000_25d8_write_file_to_disk(TEXT_3266, 0xb31e, 0x100);
                    }
                    FUN_1000_2E96_print_direction(0xffff);
                    D_52ba_vdp._52be = 8;
                    return;
                }
                break;

            case 0x54: // 'T'
                FUN_1000_16ba_print_char(0xff);
                F_INTRO_132a();
                goto L_0fab; // TODO: get rid of goto
                //break;

            case 0x43: // 'C'
                // 0fa8
                FUN_0000_7CCE(); // thunk
L_0fab:
                FUN_1000_1c22_set_text_window_size(0, 0, 0, 0x27, 0x18);
                FUN_1000_1b94_select_charset(0);
                FUN_1000_16ba_print_char(0xff);
                FUN_1000_0C22(1);
                FUN_1000_16ba_print_char(0xff);
                F_INTRO_05b0(0);
                F_INTRO_0010();
                FUN_1000_0C22(0);
                break;

            case 0x55: // 'U'
                F_INTRO_014e();
                F_INTRO_05b0(0);
                break;
                
            case 0x41: // 'A'
                // 0ff4
                if (D_5893_map_id != '@') {
                    FUN_1000_102E_unload_tileset();
                    D_5893_map_id = 0x40;
                }
                F_INTRO_072e();
                break;

            case 0x52: // 'R'
                FUN_0000_7CDA(); // thunk
                break;
        }
    } while (1);
}

F_INTRO_1016() {} // transfer_u4_data (91d6)
F_INTRO_1278() {} // print_u4_class (9438)
F_INTRO_12ea(int a) {}
F_INTRO_132a() {} // transfer_character (94ea)
F_INTRO_1e22(int a) {} // (9fe2)
F_INTRO_1e62() {} // (a022)
F_INTRO_1f26(int a) {} // (a0e6)
F_INTRO_2024() {}
F_INTRO_2090() {}
F_INTRO_20ae() {} // update_demo (a26e)
