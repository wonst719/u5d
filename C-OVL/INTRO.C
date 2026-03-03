#include "COMMON.H"
#include "FILE.H"
#include "FUNCS.H"
#include "GRAP_DRV.H"
#include "VARS.H"

#include <stdio.h>

// NOTE: 헤더 같은 게 있어서 주소가 0x10 밀려 있음.

void cdecl FUN_1000_02f4_exit_to_dos(int a);

extern void F_FONT_0b0a(void);
extern void F_FONT_04a4(void);

F_INTRO_132a_transfer_character();
void F_INTRO_2090_animate_wd(void);
void F_INTRO_20ae_show_wd(byte* ptr);

// OK P1
void F_INTRO_0010(void)
{
    int local_4;

    FUN_1000_0c22_GRAP_0f_select_page(1);
    FUN_1000_16ba_print_char(0xff);
    
    for (local_4 = 0; local_4 < 4; local_4++)
    {
        FUN_1000_0d4c_GRAP_4b_put_image(D_bb1a, local_4 + 1, 0x10, local_4 * 0x32, 0);
    }
}

F_INTRO_0050(int a, int b) { printf("F_INTRO_0050(%d,%d)\n", a, b); }

F_INTRO_014e_play_story() { puts("F_INTRO_014e"); }

void F_INTRO_043e(char* param_1)
{
    int iVar1;
    int iVar2;
    int iVar3;

    iVar1 = FUN_1000_216c_strlen(param_1) / 2 + 238;
    iVar2 = -iVar1;
    iVar3 = FUN_1000_216c_strlen(param_1);
    FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b2_frame_color);
    iVar1 *= -8;
    FUN_1000_0aa6_GRAP_3f_fill_rectangle(8, 0xc1, iVar1, 199);
    iVar3 = (iVar3 + iVar2 + 2) * 8;
    FUN_1000_0aa6_GRAP_3f_fill_rectangle(iVar3, 0xc1, 0x137, 199);
    FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
    FUN_1000_0b10_GRAP_line(8, 0xc0, iVar1, 0xc0);
    FUN_1000_0b10_GRAP_line(iVar3, 0xc0, 0x137, 0xc0);
    FUN_1000_1bf2_set_text_cursor_position(iVar2, 0x18);
    FUN_1000_4c2a();
    FUN_1000_1850_print_string(param_1);
    FUN_1000_4cce();
}

// OK P1: not matching: si
void F_INTRO_04e0_draw_menu_borders(void)
{
    int local_4;

    FUN_1000_1cca_set_text_foreground_color(D_13b2_frame_color);
    FUN_1000_1bf2_set_text_cursor_position(0, 0xf);
    FUN_1000_16ba_print_char(0x7b);
    local_4 = 0x26;
    do {
        FUN_1000_16ba_print_char(0x7f);
    } while (--local_4 != 0);
    FUN_1000_16ba_print_char(0x7c);
    local_4 = 8;
    do {
        FUN_1000_16ba_print_char(0x7f);
        FUN_1000_1bf2_set_text_cursor_position(0x27, FUN_1000_1cee_get_current_text_row());
        FUN_1000_16ba_print_char(0x7f);
    } while (--local_4 != 0);
    FUN_1000_16ba_print_char(0x7d);
    local_4 = 0x26;
    do {
        FUN_1000_16ba_print_char(0x7f);
    } while (--local_4 != 0);
    D_538e = 0;
    FUN_1000_16ba_print_char(0x7e);
    D_538e = 1;
    FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
    FUN_1000_0b10_GRAP_line(7, 127, 312, 127);
    FUN_1000_0f90_GRAP_pen(312, 192);
    FUN_1000_0f90_GRAP_pen(7, 192);
    FUN_1000_0f90_GRAP_pen(7, 127);
    FUN_1000_1cca_set_text_foreground_color(D_13b0_white_color);
}

// OK P1
void F_INTRO_05b0_display_title(uint param_1) // (0 for fast display)
{
    byte* local_4;

    D_a9be = 2;
    if (D_5893_map_id != 0x40)
    {
        FUN_1000_102e_unload_tileset();
        D_5893_map_id = 0x40;
    }
    do
    {
        D_bb1a = FUN_1000_0bae_load_image_file(D_25f0[23]); // "ULTIMA.16"
    } while (D_bb1a == 0);
    FUN_1000_0c22_GRAP_0f_select_page(0);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_0c22_GRAP_0f_select_page(1);
    FUN_1000_0d4c_GRAP_4b_put_image(D_bb1a, 0, 0, 0, 0);
    if (param_1 != 0)
    {
        // "ULTIMA" with sound
        FUN_1000_0f46_GRAP_66(0, 0, 319, 100);
        param_1 = (u8)FUN_1000_1d5e_peek_keystroke() == 0;
    }
    if (param_1 == 0)
    {
        FUN_1000_0ace_GRAP_18_transfer_area(1, 0, 0, 0, 319, 100);
    }
    F_INTRO_0010();
    FUN_1000_0be4_free_memory(D_bb1a);
    if (param_1 != 0)
    {
        do {
            local_4 = FUN_1000_0fae_load_file("WD.BIT");
        } while (local_4 == 0);
        // "warriors of destiny" with sound
        F_INTRO_20ae_show_wd(local_4);
        FUN_1000_0fdc_free_memory(local_4);
    }
    FUN_1000_0c22_GRAP_0f_select_page(0);
    F_INTRO_2090_animate_wd();
    D_a9be = 0;
    F_INTRO_04e0_draw_menu_borders();
}

// OK P1
void F_INTRO_0676_write_menu_option(int param_4, int param_3, int param_2, char* param_1)
{
    if (param_3 == param_4)
    {
        FUN_1000_16ba_print_char(0xfd);
    }

    FUN_1000_1bf2_set_text_cursor_position(param_2, param_3 + 0x11);
    FUN_1000_16ba_print_char(0x20);
    FUN_1000_1850_print_string(param_1);
    FUN_1000_16ba_print_char(0x20);

    if (param_3 == param_4)
    {
        FUN_1000_16ba_print_char(0xfd);
    }
}

// OK P1
void F_INTRO_06bc_build_main_menu(int param_1)
{
    F_INTRO_0676_write_menu_option(param_1, 0, 0xc, /*0x310c*/ "Journey Onward");
    F_INTRO_0676_write_menu_option(param_1, 1, 9, /*0x311b*/ "Create New Character");
    F_INTRO_0676_write_menu_option(param_1, 2, 8, /*0x3130*/ "Transfer from Ultima IV");
    F_INTRO_0676_write_menu_option(param_1, 3, 9, /*0x3148*/ "Ultima V Introduction");
    F_INTRO_0676_write_menu_option(param_1, 4, 0xb, /*0x315e*/ "Acknowledgements");
    F_INTRO_0676_write_menu_option(param_1, 5, 10, /*0x316f*/ "Return to the View");
}

// NOT MATCHING
void F_INTRO_072e_acknowledgements(void)
{
    void* pVar1;
    int iVar2;

    while ((pVar1 = FUN_1000_0bae_load_image_file(D_25ea[28])) == 0) // "STARTSC.16"
        ;

    FUN_1000_0c22_GRAP_0f_select_page(1);
    FUN_1000_0d4c_GRAP_4b_put_image(pVar1, 1, 0x10, 0x3f, 0);
    FUN_1000_0c22_GRAP_0f_select_page(0);

    for (iVar2 = 199; iVar2 > 0x3e; iVar2--)
    {
        FUN_1000_0d4c_GRAP_4b_put_image(pVar1, 0, 0x90, iVar2, 0); // (image_buffer, image_idx, x, y, ?)
        FUN_1000_0d4c_GRAP_4b_put_image(pVar1, 2, 0xa0, iVar2, 0);
    }

    for (iVar2 = 0; iVar2 < 0x90; iVar2 += 8)
    {
        FUN_1000_0d4c_GRAP_4b_put_image(pVar1, 0, 0x88 - iVar2, 0x3f, 0);
        FUN_1000_0ace_GRAP_18_transfer_area(1, 0, 0x98 - iVar2, 0x3f, 0x9f - iVar2, 199);
        FUN_1000_0d4c_GRAP_4b_put_image(pVar1, 2, iVar2 + 0xa8, 0x3f, 0);
        FUN_1000_0ace_GRAP_18_transfer_area(1, 0, iVar2 + 0xa0, 0x3f, iVar2 + 0xa7, 199);
        FUN_1000_20fa_wait_ticks(1);
    }

    while ((D_bb1a = FUN_1000_0bae_load_image_file(D_25ea[27])) == 0) // "ULTIMA.16"
        ;

    FUN_1000_0c22_GRAP_0f_select_page(1);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_0d4c_GRAP_4b_put_image(D_bb1a, 1, 0x10, 0x41, 0);
#ifndef _WIN32
    FUN_1000_0be4_free_memory(D_bb1a);
#endif
    F_INTRO_04e0_draw_menu_borders();
    F_INTRO_06bc_build_main_menu(4);

    while (FUN_1000_1d5e_peek_keystroke() == 0)
        ;

    FUN_1000_0c22_GRAP_0f_select_page(0);

    for (iVar2 = 0x88; iVar2 >= 0; iVar2 -= 8)
    {
        FUN_1000_0d4c_GRAP_4b_put_image(pVar1, 0, 0x90 - iVar2, 0x3f, 0);
        FUN_1000_0ace_GRAP_18_transfer_area(1, 0, 0x88 - iVar2, 0x3f, 0x8f - iVar2, 199);
        FUN_1000_0d4c_GRAP_4b_put_image(pVar1, 2, iVar2 + 0xa0, 0x3f, 0);
        FUN_1000_0ace_GRAP_18_transfer_area(1, 0, iVar2 + 0xb0, 0x3f, iVar2 + 0xb7, 199);
        FUN_1000_20fa_wait_ticks(1);
    }

#ifndef _WIN32
    FUN_1000_0be4_free_memory(pVar1);
#endif

    for (iVar2 = 0x3f; iVar2 < 199; iVar2++)
    {
        FUN_1000_0d4c_GRAP_4b_put_image(pVar1, 0, 0x90, iVar2 + 1, 0);
        FUN_1000_0d4c_GRAP_4b_put_image(pVar1, 2, 0xa0, iVar2 + 1, 0);
        FUN_1000_0ace_GRAP_18_transfer_area(1, 0, 0x90, iVar2, 0xaf, iVar2);
    }


    FUN_1000_0ace_GRAP_18_transfer_area(1, 0, 0x90, 199, 0xaf, 199);
    F_INTRO_0010();
    FUN_1000_0c22_GRAP_0f_select_page(0);
    FUN_1000_1b16_clear_keyboard_buffer();

#ifdef _WIN32
    // ?
    FUN_1000_0be4_free_memory(pVar1);
    FUN_1000_0be4_free_memory(D_bb1a);
#endif
}

// NOT MATCHING
// pause(wait time) (8b0e)
int F_INTRO_094e_pause(int param_1)
{
    int iVar1;
    int iVar2;

    iVar2 = 0;

    while (1)
    {
        if (param_1 <= iVar2)
        {
            return 0;
        }

        iVar1 = FUN_1000_1d5e_peek_keystroke();
        if (iVar1 != 0)
            break;

        FUN_1000_20fa_wait_ticks(1);
        iVar2++;
    }

    return iVar1;
}

// OK P1 (NOT MATCHING: local variable order)
void F_INTRO_0986_main(void) // intro_main (initialize video) (8b46)
{
    int local_4;
    char *local_6;
    int local_8;
    int local_a;
    int local_c;
    int local_e;
    byte local_10;
    byte* local_12;
    byte* local_14;

    // 098e
    D_a9ce = 1;
    local_e = 0;

    // 0995
    for (local_e = 0; local_e < 0x100; local_e++) {
        D_b11e[local_e] = (char)local_e;
    }

    FUN_1000_0de0_detect_video();
    FUN_1000_1158_init_timer();
    local_8 = D_5356;

    // force cga if low memory
    if ((D_52ba_vdp._52c8_videoDriverSelection == 2) && (D_5358 < 0x170)) {
        D_52f1_forceTandy = 0;
        D_52ba_vdp._52ba_forceCga = 1;
        D_52ba_vdp._52c8_videoDriverSelection = 0;
    }

    // 09d2
    while (FUN_1000_0e94_load_video_driver() == 0) {}

    FUN_1000_0892_initialize_video_driver(1);

    if ((D_52ba_vdp._52c8_videoDriverSelection != 0) && (D_52ba_vdp._52c8_videoDriverSelection != 3))
    {
        D_13b2_frame_color = 1;
        D_13ae = 4;
        D_13b0_white_color = 0xf;
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
    if (FUN_1000_0f2a_GRAP_06_alloc_page_buffer() == 0)
    {
        FUN_1000_0878_set_old_video_mode();
        FUN_1000_02f4_exit_to_dos(1);
        // 	ADD        SP,2h <- cdecl
    }
    if (D_52ba_vdp._52c8_videoDriverSelection == 3)
    {
        // 0a64
        while (FUN_1000_1d02_load_character_set(/*0x3182*/ "ibm.hcs", 0) == 0)
        {
        }
        while (FUN_1000_1d02_load_character_set(/*0x318a*/ "runes.hcs", 1) == 0)
        {
        }
    }
    else
    {
        // 0a84
        while (FUN_1000_1d02_load_character_set(/*0x3194*/ "ibm.ch", 0) == 0)
        {
        }
        while (FUN_1000_1d02_load_character_set(/*0x319b*/ "runes.ch", 1) == 0)
        {
        }
    }

    // 0aa1
    FUN_1000_1c9e_set_charset(0);
    FUN_1000_1c22_set_text_window_size(0, 0, 0, 0x27, 0x18);
    FUN_1000_1b94_select_charset(0);
    local_a = FUN_1000_2032_to_upper((u8)FUN_1000_1d5e_peek_keystroke());
    if (local_a == 0x4a) // 'J'
    {
        FUN_1000_16ba_print_char(0xff);
        FUN_1000_16ba_print_char(0xfc);
        FUN_1000_1bf2_set_text_cursor_position(0, 0xb);
        FUN_1000_1850_print_string(/*0x31a4*/ "Journey Onward\n\n");
        FUN_1000_16ba_print_char(0xfb);
        // 0af2
        while (FUN_1000_0ff4_load_compressed_tileset(D_25f0[0]) == 0) {}
        D_5893_map_id = 0x41;
        // -> 0cc9
    }
    else
    {
        // 0b06
        local_a = 1;

        do {
            local_12 = FUN_1000_0fae_load_file(D_25ea[2]); // "TITLE.BIT"
        } while (local_12 == 0);

        do {
            local_14 = FUN_1000_0fae_load_file(D_25ea[1]); // "BRITISH.BIT"
        } while (local_14 == 0);

#ifdef _WIN32
        extern void FILE_ReadSavegameFile(char* fileName);
        FILE_ReadSavegameFile(/*0x31b5*/ "BRITISH.PTH");
#else
        FUN_1000_256e_read_file_from_disk(/*0x31b5*/ "BRITISH.PTH", &D_55a6, ((int)&D_6606 - (int)&D_55a6) /*0x1060*/, 0);
#endif
        // "origin systems inc."
        if (local_a != 0)
            local_a = FUN_1000_0d72_origin_animation(local_12) == 0;

        // 0b56
        // "presents"
        FUN_1000_0c22_GRAP_0f_select_page(1);
        FUN_1000_0aa6_GRAP_3f_fill_rectangle(0, 0x8c, 0x13f, 199);
        FUN_1000_1044_GRAP_4e_copy_bit_image_into_page(local_12, 7, 0x6c, 0x8c);
        FUN_1000_0ace_GRAP_18_transfer_area(1, 0, 0, 0x8c, 0x13f, 199);
        if (local_a != 0)
        {
            FUN_1000_20fa_wait_ticks(0x12);
            local_a = F_INTRO_094e_pause(0x14) == 0;
        }
        // 0bb6
        if (local_a != 0)
        {
            // 0bbf
            FUN_1000_16ba_print_char(0xff);
            // "a"
            FUN_1000_1044_GRAP_4e_copy_bit_image_into_page(local_12, 0x8, 0x98, 0);
            FUN_1000_0f6e_GRAP_1b_transfer_fullscreen(1, 0);
            local_a = F_INTRO_094e_pause(0x14) == 0;
            if (local_a != 0)
            {
                FUN_1000_0c22_GRAP_0f_select_page(0);
                D_bb18 = 0;
                local_a = 0;
                // "lord british" animation
                if ((F_INTRO_0050(0x2c, 0x44) != 0) &&
                    (F_INTRO_0050(0x40, 0x5e) != 0) &&
                    (F_INTRO_0050(0x8f, 0x4e) != 0))
                {
                    local_a = F_INTRO_0050(0xa7, 0x69);
                }
                // 0c42
                FUN_1000_0c22_GRAP_0f_select_page(1);
            }
            // 0c49
            // "lord british"
            FUN_1000_1044_GRAP_4e_copy_bit_image_into_page(local_14, 0, 0x18, 0x42);
            FUN_1000_0f6e_GRAP_1b_transfer_fullscreen(1, 0);
            // "production"
            FUN_1000_1044_GRAP_4e_copy_bit_image_into_page(local_12, 9, 0x68, 0xa0);
            FUN_1000_0f6e_GRAP_1b_transfer_fullscreen(1, 0);
            if (local_a != 0) {
                local_a = F_INTRO_094e_pause(0x14) == 0;
            }
        }
        // 0c97
        FUN_1000_0fdc_free_memory(local_14);
        FUN_1000_0fdc_free_memory(local_12);

        D_5893_map_id = 0x40;
        FUN_1000_16ba_print_char(0xff);
        FUN_1000_0c22_GRAP_0f_select_page(0);
        F_INTRO_05b0_display_title(local_a);
        if (local_a != 0) {
            F_FONT_04a4();
        }
        // 0cc4
        local_a = 1;
    }
    FUN_1000_207e_srand(FUN_1000_2056_get_time());

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
            F_INTRO_043e(/*0x31c1*/ "Copyright 1988 Lord British");
            F_INTRO_06bc_build_main_menu(0);
            do {
                // 0d4d
                FUN_1000_1bf2_set_text_cursor_position(0xf, 0xf);
                FUN_1000_4c2a();
                FUN_1000_1850_print_string(/*0x31dd*/ "Select: ");
                FUN_1000_4cce();
                FUN_1000_1bf2_set_text_cursor_position(0x17, 0xf);
                D_5356 = 0x113;
                local_4 = 0;
                do {
                    // 0d75
                    local_10 = FUN_1000_2032_to_upper(FUN_1000_1b38_keystroke_cursor());
                    if (local_10 == 0) {
                        F_INTRO_2090_animate_wd();
                    }
                    // 0d86
                    local_4++;
                } while ((local_4 < 200) && (local_10 == 0));
                D_5356 = local_8;
                // OK P1!
                switch ((int)local_10)
                {
                    case 1: // up?
                    case 3: // left?
                        local_c--;
                        if (local_c < 0) {
                            local_c = 5;
                        }
                        F_INTRO_06bc_build_main_menu(local_c);
                        break;
                    case 2: // down?
                    case 4: // right?
                        local_c++;
                        if (5 < local_c) {
                            local_c = 0;
                        }
                        F_INTRO_06bc_build_main_menu(local_c);
                        break;
                    case 0xd:  // CR
                    case 0x20: // ' '
                        // 0de2
                        local_10 = /*0x3270*/ "JCTUAR"[local_c];
                        break;
                    case 0:
                        local_10 = 0x52;
                        break;
                    case 0x4a: // 'J'
                        F_INTRO_06bc_build_main_menu(0);
                        break;
                    case 0x43: // 'C'
                        F_INTRO_06bc_build_main_menu(1);
                        break;
                    case 0x54: // 'T'
                        F_INTRO_06bc_build_main_menu(2);
                        break;
                    case 0x55: // 'U'
                        F_INTRO_06bc_build_main_menu(3);
                        break;
                    case 0x41: // 'A'
                        F_INTRO_06bc_build_main_menu(4);
                        break;
                    case 0x52: // 'R'
                        F_INTRO_06bc_build_main_menu(5);
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
                FUN_1000_637e_draw_frame();
                FUN_1000_2e96_print_direction(0);
                FUN_1000_1b94_select_charset(2);
                FUN_1000_1bf2_set_text_cursor_position(0, 0xc);
                if (D_5893_map_id == 0x40) {
                    while (FUN_1000_0ff4_load_compressed_tileset(D_25f0[0]) == 0) {}
                    D_5893_map_id = 0x41;
                }
                // 0ead
                FUN_1000_251e_switch_disks(3);
#ifdef _WIN32
                FILE_ReadSavegameFile(/*0x31e6*/ "SAVED.GAM");
#else
                FUN_1000_256e_read_file_from_disk(/*0x31e6*/ "SAVED.GAM", &D_55a6, ((int)&D_6606 - (int)&D_55a6) /*0x1060*/, 0);
#endif
                if (D_55a8_party[0]._0[0] == '\0')
                {
                    FUN_1000_1850_print_string(/*0x31f0*/ "\n\nNo active game. ");
                    FUN_1000_1850_print_string(/*0x3203*/ "Please create a character ");
                    FUN_1000_1850_print_string(/*0x321e*/ "or transfer one from Ultima IV. ");
                    FUN_1000_1dda_wait_for_keystroke(0);
                    D_a9cb = 0xff;
                    FUN_1000_251e_switch_disks(0);
                    FUN_1000_1b94_select_charset(0);
                    FUN_1000_16ba_print_char(0xff);
                    FUN_1000_0c22_GRAP_0f_select_page(1);
                    FUN_1000_16ba_print_char(0xff);
                    FUN_1000_0c22_GRAP_0f_select_page(0);
                    F_INTRO_05b0_display_title(0);
                    local_a = 0;
                }
                else
                {
                    // 0f26
                    FUN_1000_256e_read_file_from_disk(/*0x323f*/ "SAVED.OOL", D_b21e, 0x200, 0);
                    FUN_1000_251e_switch_disks(1);
                    FUN_1000_25d8_write_file_to_disk(/*0x3249*/ "BRIT.OOL", D_b21e, 0x100);
                    FUN_1000_25d8_write_file_to_disk(/*0x3252*/ "UNDER.OOL", D_b31e, 0x100);
                    if ((D_5893_map_id == 0) && (D_5895_map_level != 0)) {
                        FUN_1000_251e_switch_disks(5);
                        while (FUN_1000_1674_test_open_file(/*0x325c*/ "UNDER.DAT") == 0)
                        {
                        }
                        FUN_1000_25d8_write_file_to_disk(/*0x3266*/ "UNDER.OOL", D_b31e, 0x100);
                    }
                    FUN_1000_2e96_print_direction(-1);
                    D_52ba_vdp._52be = 8;
                    return;
                }
                break;

            case 0x54: // 'T'
                FUN_1000_16ba_print_char(0xff);
                F_INTRO_132a_transfer_character();
                goto L_0fab; // TODO: get rid of goto
                //break;

            case 0x43: // 'C'
                // 0fa8
                F_FONT_0b0a();
L_0fab:
                FUN_1000_1c22_set_text_window_size(0, 0, 0, 0x27, 0x18);
                FUN_1000_1b94_select_charset(0);
                FUN_1000_16ba_print_char(0xff);
                FUN_1000_0c22_GRAP_0f_select_page(1);
                FUN_1000_16ba_print_char(0xff);
                F_INTRO_05b0_display_title(0);
                F_INTRO_0010();
                FUN_1000_0c22_GRAP_0f_select_page(0);
                break;

            case 0x55: // 'U'
                F_INTRO_014e_play_story();
                F_INTRO_05b0_display_title(0);
                break;
                
            case 0x41: // 'A'
                // 0ff4
                if (D_5893_map_id != '@') {
                    FUN_1000_102e_unload_tileset();
                    D_5893_map_id = 0x40;
                }
                F_INTRO_072e_acknowledgements();
                break;

            case 0x52: // 'R'
                F_FONT_04a4(); // thunk
                break;
        }
    } while (1);
}

F_INTRO_1016_transfer_u4_data() { puts("F_INTRO_1016"); } // (91d6)

F_INTRO_1278_print_u4_class() { puts("F_INTRO_1278"); } // (9438)

F_INTRO_12ea(int a) { printf("F_INTRO_12ea(%d)\n", a); }

F_INTRO_132a_transfer_character() { puts("F_INTRO_132a"); } // (94ea)

F_INTRO_1e22(int a) { printf("F_INTRO_1e22(%d)\n", a); } // (9fe2)

F_INTRO_1e62() { puts("F_INTRO_1e22"); } // (a022)

F_INTRO_1f26(int a) { printf("F_INTRO_1f26(%d)\n", a); } // (a0e6)

F_INTRO_2024() { puts("F_INTRO_2024"); }

// NOT MATCHING (asm)
// animate "warriors of destiny"
void F_INTRO_2090_animate_wd(void)
{
    FUN_1000_20fa_wait_ticks(1);
    DRV_69(0, 0); // ax: undefined, cf: 0
}

// NOT MATCHING (asm)
// show "warriors of destiny" (a26e)
void F_INTRO_20ae_show_wd(byte* ptr)
{
    DRV_69(ptr, 1); // ax: a, cf: 1
}
