#include "COMMON.H"
#include "FILE.H"
#include "FUNCS.H"
#include "GRAP_DRV.H"
#include "VARS.H"

#include <stdio.h>
#include <stdlib.h>

// NOTE: 헤더 같은 게 있어서 주소가 0x10 밀려 있음.

void cdecl FUN_1000_02f4_exit_to_dos(int a);

extern void F_FONT_0000(byte* a, char* b);
extern void F_FONT_0b0a(void);
extern void F_FONT_04a4(void);

void FUN_1000_2322_disk_swap_message(void);

void F_INTRO_132a_transfer_character(void);
void F_INTRO_1e22(int param_1);
void F_INTRO_2024(void);
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

#ifdef _WIN32
byte* g_british;
#endif

// NOT MATCHING
// lord british animation
int F_INTRO_0050(int param_1, int param_2)
{
#ifdef _WIN32
#define MEM_SIZE 3000
#define MEM_ACCESS(x) g_british[x]
#else // DOS: use savegame area
#define MEM_SIZE 0x1060
#define MEM_ACCESS(x) *(byte*)(x + &D_55a6)
#endif

    int uVar1;
    int xMove;
    int uVar4;
    int iStack_e;
    int yMove;

    iStack_e = D_13b0_white_color;

    FUN_1000_0a70_GRAP_2d_set_pen_color(iStack_e);

    uVar1 = D_5356;
    D_5356 = 0x113;

    for (uVar4 = D_bb18; uVar4 < MEM_SIZE; uVar4++)
    {
        if (iStack_e != 0)
        {
            FUN_1000_0c64_GRAP_30_pset(param_1, param_2);
        }

        iStack_e = D_13b0_white_color;

        yMove = MEM_ACCESS(uVar4) & 7;
        if (yMove > 2)
        {
            iStack_e = 0;
        }

        if ((MEM_ACCESS(uVar4) & 8) != 0)
        {
            yMove = -yMove;
        }

        xMove = (MEM_ACCESS(uVar4) & 0x70) >> 4;
        if (xMove > 2)
        {
            iStack_e = 0;
        }

        if ((MEM_ACCESS(uVar4) & 0x80) != 0)
        {
            xMove = -xMove;
        }

        param_1 += xMove;
        param_2 += yMove;

        if (FUN_1000_1d5e_peek_keystroke() != 0)
        {
            D_5356 = uVar1;
            return 0;
        }

        if ((uVar4 & 0x1f) == 0)
        {
            FUN_1000_20fa_wait_ticks(1);
        }

        if (MEM_ACCESS(uVar4) == 0)
            break;
    }

    D_bb18 = uVar4 + 1;
    D_5356 = uVar1;

    return D_bb18;
#undef MEM_SIZE
#undef MEM_ACCESS
}

// NOT MATCHING
// introduction
void F_INTRO_014e_introduction(void)
{
    byte bVar1;
    int uVar2;
    byte* puVar3;
    byte* iVar4;
    int iVar6;
    int local_a;
    int local_8;
    byte* local_6;

    if (D_5893_map_id != 64)
    {
        FUN_1000_102e_unload_tileset();
    }

    D_5893_map_id = 0x40;
    do
    {
        puVar3 = FUN_1000_0fae_load_file(D_25ea[0]);
    } while (puVar3 == 0);

    F_FONT_0000(puVar3, /*0x2f30*/ "");
    FUN_1000_0c22_GRAP_0f_select_page(1);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_0c22_GRAP_0f_select_page(0);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_1bf2_set_text_cursor_position(0, 10);

    do
    {
        iVar4 = FUN_1000_0bae_load_image_file(D_25ea[0x11]);
    } while (iVar4 == 0);

    do
    {
        local_6 = FUN_1000_0bae_load_image_file(D_25ea[0x12]);
    } while (local_6 == 0);

    local_8 = 0;
    for (local_a = 0; local_a < 0x15; local_a++)
    {
        if (local_8 != D_30ae[local_a])
        {
            FUN_1000_0be4_free_memory(local_6);
            local_8 = (uint)D_30ae[local_a];
            do
            {
                local_6 = FUN_1000_0bae_load_image_file(D_25ea[0x12 + local_8]);
            } while (local_6 == 0);
        }

        D_a9be = 2;
        FUN_1000_0c22_GRAP_0f_select_page(1);
        FUN_1000_16ba_print_char(0xff);
        if (D_30f0[local_a] == 1)
        {
            if (local_a == 0)
            {
                FUN_1000_0d4c_GRAP_4b_put_image(iVar4, 0, 0xe0, 0x1e, 0);
                FUN_1000_0d4c_GRAP_4b_put_image(iVar4, 1, 0xa8, 0x3a, 0);
            }
            else if (local_a == 7)
            {
                FUN_1000_0d4c_GRAP_4b_put_image(iVar4, 0, 0xe8, 0x1a, 0);
                FUN_1000_0d4c_GRAP_4b_put_image(iVar4, 2, 200, 0x36, 0);
            }
            else if (local_a == 0xe)
            {
                FUN_1000_0d4c_GRAP_4b_put_image(iVar4, 0, 0xb8, 0, 0);
                FUN_1000_0d4c_GRAP_4b_put_image(iVar4, 3, 0xf8, 0, 0);
            }
        }

        bVar1 = D_30da[local_a];
        uVar2 = D_30c4[local_a];
        FUN_1000_0d4c_GRAP_4b_put_image(local_6, D_3098[local_a], uVar2, bVar1, 0);
        if (D_30f0[local_a] > 3)
        {
            FUN_1000_0d4c_GRAP_4b_put_image(local_6, (uint)D_30f0[local_a] * 2 - 5, uVar2, bVar1 + 0x37, 0);
        }

        D_5146[0] = D_2f98[local_a]._0;
        D_5146[1] = D_2f98[local_a]._1;

        D_514c[0] = D_2fc2[local_a]._0;
        D_514c[1] = D_2fc2[local_a]._2;

        D_5150 = D_3040[local_a];
        D_5152 = D_3056[local_a];
        bVar1 = D_306c[local_a];
        D_5156 = (uint)bVar1;
        D_5158 = D_3082[local_a];

        if (D_30f0[local_a] == 3)
        {
            FUN_1000_0d4c_GRAP_4b_put_image(local_6, 3, 0x60, 0x27, 0);
            F_FONT_0000(puVar3, /*0x2f31*/ "Instantly, a shimmering blue door springs up!");
            D_5156 = (uint)bVar1;
            D_5158 = 0xb4;
            F_FONT_0000(puVar3, /*0x2f5f*/ "With heart beating rapidly, you step into it.");
        }
        else
        {
            FUN_1000_256e_read_file_from_disk(/*0x2f8d*/ "STORY.DAT", D_b21e, 2000, D_3016[local_a]);
            F_FONT_0000(puVar3, D_b21e);
        }

        if (local_a != 0)
        {
            FUN_1000_1b16_clear_keyboard_buffer();
            do
            {
                iVar6 = FUN_1000_1d5e_peek_keystroke();
            } while (iVar6 == 0);
        }

        FUN_1000_0f6e_GRAP_1b_transfer_fullscreen(1, 0);

        if (D_30f0[local_a] == 2)
        {
            FUN_1000_0c22_GRAP_0f_select_page(1);
            FUN_1000_0d4c_GRAP_4b_put_image(local_6, 2, 0x28, 0x56, 0);
            FUN_1000_0f46_GRAP_66(0x28, 0x56, 0x4b, 0x78);
        }
    }

    FUN_1000_0be4_free_memory(local_6);
    FUN_1000_0be4_free_memory(iVar4);
    FUN_1000_0fdc_free_memory(puVar3);

    FUN_1000_1b16_clear_keyboard_buffer();
    while (FUN_1000_1d5e_peek_keystroke() == 0)
        ;

    FUN_1000_0c22_GRAP_0f_select_page(1);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_0c22_GRAP_0f_select_page(0);
    D_a9be = 0;
    FUN_1000_251e_switch_disks(0);
}

// NOT MATCHING
void F_INTRO_043e(char* param_1)
{
    int iVar1;
    int iVar2;
    int iVar3;

    iVar1 = FUN_1000_216c_strlen(param_1) / 2 - 0x12;
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
    FUN_1000_0be4_free_memory(D_bb1a);
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

    FUN_1000_0be4_free_memory(pVar1);

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
        while (FUN_1000_1d02_load_charset(/*0x3182*/ "ibm.hcs", 0) == 0)
        {
        }
        while (FUN_1000_1d02_load_charset(/*0x318a*/ "runes.hcs", 1) == 0)
        {
        }
    }
    else
    {
        // 0a84
        while (FUN_1000_1d02_load_charset(/*0x3194*/ "ibm.ch", 0) == 0)
        {
        }
        while (FUN_1000_1d02_load_charset(/*0x319b*/ "runes.ch", 1) == 0)
        {
        }
    }

    // 0aa1
    FUN_1000_1c9e_set_charset(0);
    FUN_1000_1c22_set_text_window_size(0, 0, 0, 0x27, 0x18);
    FUN_1000_1b94_select_text_window(0);
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
        // TODO
        g_british = malloc(3000);
        FUN_1000_256e_read_file_from_disk(/*0x31b5*/ "BRITISH.PTH", g_british, 3000, 0);
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

#ifdef _WIN32
        free(g_british);
        g_british = 0;
#endif

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
        FUN_1000_1b94_select_text_window(0);
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
                FUN_1000_2e96_set_wind_direction(0);
                FUN_1000_1b94_select_text_window(2);
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
                    FUN_1000_1b94_select_text_window(0);
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
                    FUN_1000_2e96_set_wind_direction(-1);
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
                FUN_1000_1b94_select_text_window(0);
                FUN_1000_16ba_print_char(0xff);
                FUN_1000_0c22_GRAP_0f_select_page(1);
                FUN_1000_16ba_print_char(0xff);
                F_INTRO_05b0_display_title(0);
                F_INTRO_0010();
                FUN_1000_0c22_GRAP_0f_select_page(0);
                break;

            case 0x55: // 'U'
                F_INTRO_014e_introduction();
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

// NOT MATCHING
int F_INTRO_1016_transfer_u4_data(void)
{
    bool bVar1;
    int uVar3;
    int iVar4;

    bVar1 = 0;

    D_a9be = 1;
    D_a9bd = 4;

    D_a9cc = FUN_1000_16a6_get_default_drive();

    FUN_1000_256e_read_file_from_disk(/*0x3278*/ "party.sav", &D_bc88, 0x28, 8);

    if (D_bc88._6 > 0x46 || D_bc88._8 > 0x46 || D_bc88._a > 0x46 || D_bc88._4 > 9999 || D_bc88._0 > 9999 ||
        D_bc88._2 > 9999 || D_bc88._25 > 7)
    {
        bVar1 = 1;
    }

    for (iVar4 = 0; iVar4 < 8; iVar4++)
    {
        if (D_bc88._14[iVar4] != 0 && D_bc88._14[iVar4] < 0x20)
        {
            bVar1 = 1;
            break;
        }
    }

    if (bVar1)
    {
        FUN_1000_16ba_print_char(0xff);
        FUN_1000_16ba_print_char(0xfc);
        FUN_1000_1bf2_set_text_cursor_position(0, 5);
        FUN_1000_1850_print_string(/*0x3282*/ "Error:  Your Ultima IV game\n\ncontains bad data.\n\n");
        FUN_1000_1850_print_string(/*0x32b4*/ "Unable to continue transfer.\n\n\n");
        FUN_1000_1850_print_string(/*0x32d4*/ "Press any key to return to the menu.");
        FUN_1000_16ba_print_char(0xfb);
        FUN_1000_1dda_wait_for_keystroke(0);
        uVar3 = 1;
    }
    else
    {
        for (iVar4 = 0; iVar4 < 8; iVar4++)
        {
            if (D_bc88._14[iVar4] == 0)
                break;

            D_55a8_party[0]._0[iVar4] = D_bc88._14[iVar4];
        }

        D_55a8_party[0]._0[iVar4] = 0;

        if (D_bc88._24 == 11)
        {
            D_55a8_party[0]._9 = 0xb;
        }
        else
        {
            D_55a8_party[0]._9 = 0xc;
        }

        switch (D_bc88._25)
        {
        case 0:
            D_55a8_party[0]._a = 0x4d;
            break;
        case 1:
            D_55a8_party[0]._a = 0x42;
            break;
        case 2:
            D_55a8_party[0]._a = 0x46;
            break;
        case 3:
            D_55a8_party[0]._a = 0x44;
            break;
        case 4:
            D_55a8_party[0]._a = 0x54;
            break;
        case 5:
            D_55a8_party[0]._a = 0x50;
            break;
        case 6:
            D_55a8_party[0]._a = 0x52;
            break;
        case 7:
            D_55a8_party[0]._a = 0x53;
        }

        D_55a8_party[0]._b = 0x47;
        D_55a8_party[0]._c = D_bc88._6;
        D_55a8_party[0]._d = D_bc88._8;
        D_55a8_party[0]._e = D_bc88._a;
        D_55a8_party[0]._f = D_bc88._c;
        D_55a8_party[0]._10 = D_bc88._0;
        D_55a8_party[0]._12 = D_bc88._2;
        D_55a8_party[0]._14 = D_bc88._4;

        D_55a8_party[0]._16 = D_bc88._2 / 100;

        FUN_1000_256e_read_file_from_disk(/*0x32f9*/ "party.sav", &D_bb1c, 0xb6, 0x140);

        if (D_bb1c._6 == 0 && D_bb1c._8 == 0 && D_bb1c._a == 0 && D_bb1c._c == 0 && D_bb1c._e == 0 && D_bb1c._10 == 0 &&
            D_bb1c._12 == 0 && D_bb1c._14 == 0)
        {
            D_3304 = 1;
        }

        uVar3 = 0;
    }

    return uVar3;
}

// NOT MATCHING
void F_INTRO_1278_print_u4_class(void)
{
    switch (D_55a8_party[0]._a)
    {
    case 0x4d:
        FUN_1000_1850_print_string(/*0x3306*/ "Mage\n");
        break;
    case 0x42:
        FUN_1000_1850_print_string(/*0x330c*/ "Bard\n");
        break;
    case 0x46:
        FUN_1000_1850_print_string(/*0x3312*/ "Fighter\n");
        break;
    case 0x44:
        FUN_1000_1850_print_string(/*0x331b*/ "Druid\n");
        break;
    case 0x54:
        FUN_1000_1850_print_string(/*0x3322*/ "Tinker\n");
        break;
    case 0x50:
        FUN_1000_1850_print_string(/*0x332a*/ "Paladin\n");
        break;
    case 0x52:
        FUN_1000_1850_print_string(/*0x3333*/ "Ranger\n");
        break;
    case 0x53:
        FUN_1000_1850_print_string(/*0x333b*/ "Shepherd\n");
        break;
    }
}

// NOT MATCHING
int F_INTRO_12ea(int param_1)
{
    if (param_1 > 9)
    {
        if (param_1 < 30)
        {
            param_1 = (param_1 - 9) / 2 + 10;
        }
        else
        {
            param_1 = (param_1 - 30) / 4 + 20;
        }
    }

    return param_1;
}

void F_INTRO_132a_transfer_character(void)
{
    byte uVar1;
    char cVar3;
    char cVar4;
    byte bVar5;
    byte uVar6;
    int iVar7;
    int uVar8;
    char local_12;

    if (D_5893_map_id == 66)
        D_5893_map_id = 65;
    cVar3 = D_5893_map_id;

    uVar1 = D_a9c8;
    D_a9cb = uVar1;
    D_a9cc = uVar1;

    FILE_ReadSavegameFile(/*0x3345*/ "INIT.GAM");
    //FUN_1000_256e_read_file_from_disk(/*0x3345*/ "INIT.GAM", &D_55a6, 0x1060, 0);
    FUN_1000_256e_read_file_from_disk(/*0x334e*/ "INIT.OOL", D_b31e, 0x100, 0);
    FUN_1000_1c22_set_text_window_size(0, 0, 0, 0x27, 0x18);

    FUN_1000_1b94_select_text_window(0);
    FUN_1000_16ba_print_char(0xff);

    local_12 = D_a9c8;
    while (FUN_1000_1eac_set_default_drive(local_12) == 0)
    {
        local_12 = FUN_1000_2032_to_upper(FUN_1000_1dda_wait_for_keystroke(0));
        if (local_12 == 0x1b)
        {
            D_5893_map_id = cVar3;
            return;
        }
    }

    D_5394_fn = &FUN_1000_2322_disk_swap_message;

    if (F_INTRO_1016_transfer_u4_data() != 0)
    {
        D_5893_map_id = cVar3;
        return;
    }

    if (D_3304 != 0)
    {
        D_55a8_party[0]._a = 0x41;
    }

    FUN_1000_16ba_print_char(0xff);
    FUN_1000_1bf2_set_text_cursor_position(0, 0xb);
    FUN_1000_16ba_print_char(0xfc);
    FUN_1000_1850_print_string(/*0x33d9*/ "Found:\n");
    FUN_1000_1bf2_set_text_cursor_position(0, 0xc);
    FUN_1000_1850_print_string(D_55a8_party[0]._0);
    FUN_1000_16ba_print_char(0xfb);
    FUN_1000_1bf2_set_text_cursor_position(0xc, 0xd);
    FUN_1000_1850_print_string(/*0x33e1*/ "a level ");
    FUN_1000_1a3e_print_number(D_55a8_party[0]._16, 1, 0x20);

    if (D_55a8_party[0]._9 == 11)
    {
        FUN_1000_1850_print_string(/*0x33ea*/ " Male ");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x33f1*/ " Female ");
    }

    F_INTRO_1278_print_u4_class();
    FUN_1000_1bf2_set_text_cursor_position(0x11, 0xf);
    FUN_1000_1850_print_string(/*0x33fa*/ "STR:  ");
    FUN_1000_1a3e_print_number(D_55a8_party[0]._c, 1, 0x20);
    FUN_1000_1bf2_set_text_cursor_position(0x11, 0x10);
    FUN_1000_1850_print_string(/*0x3401*/ "DEX:  ");
    FUN_1000_1a3e_print_number(D_55a8_party[0]._d, 1, 0x20);
    FUN_1000_1bf2_set_text_cursor_position(0x11, 0x11);
    FUN_1000_1850_print_string(/*0x3408*/ "INT:  ");
    FUN_1000_1a3e_print_number(D_55a8_party[0]._e, 1, 0x20);
    FUN_1000_1bf2_set_text_cursor_position(10, 0x14);

    FUN_1000_1850_print_string(D_55a8_party[0]._0);
    FUN_1000_1850_print_string(/*0x340f*/ " is ");
    if (D_3304 == 0)
    {
        FUN_1000_1850_print_string(/*0x341f*/ "not an Avatar");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x3414*/ "an Avatar.");
    }

    FUN_1000_1dda_wait_for_keystroke(0);
    FUN_1000_16ba_print_char(0xff);

    F_INTRO_2024();

    for (iVar7 = 0; iVar7 < 8; iVar7++)
    {
        F_INTRO_1e22(iVar7);
    }

    FUN_1000_1b94_select_text_window(0);
    FUN_1000_1bf2_set_text_cursor_position(0, 3);
    FUN_1000_16ba_print_char(0xfc);
    FUN_1000_1850_print_string(D_55a8_party[0]._0);
    FUN_1000_16ba_print_char(0xfb);
    FUN_1000_1bf2_set_text_cursor_position(10, 5);

    if (D_55a8_party[0]._9 == 11)
    {
        FUN_1000_1850_print_string(/*0x342d*/ "Male");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x3432*/ "Female");
    }

    FUN_1000_1bf2_set_text_cursor_position(10, 6);

    if (D_3304 == 0)
    {
        F_INTRO_1278_print_u4_class();
    }
    else
    {
        FUN_1000_1850_print_string(/*0x3439*/ "Avatar");
    }

    FUN_1000_1bf2_set_text_cursor_position(10, 8);
    FUN_1000_1a3e_print_number(D_55a8_party[0]._14, 1, 0x20);
    FUN_1000_1bf2_set_text_cursor_position(10, 9);
    FUN_1000_1a3e_print_number(D_55a8_party[0]._16, 1, 0x20);
    FUN_1000_1bf2_set_text_cursor_position(10, 0xb);
    FUN_1000_1a3e_print_number(D_55a8_party[0]._c, 1, 0x20);
    FUN_1000_1bf2_set_text_cursor_position(10, 0xc);
    FUN_1000_1a3e_print_number(D_55a8_party[0]._d, 1, 0x20);
    FUN_1000_1bf2_set_text_cursor_position(10, 0xd);
    FUN_1000_1a3e_print_number(D_55a8_party[0]._e, 1, 0x20);
    FUN_1000_1bf2_set_text_cursor_position(0, 0xf);
    FUN_1000_16ba_print_char(0xfc);

    if (D_3304 == 0)
    {
        FUN_1000_1850_print_string(/*0x3447*/ "Non-Avatar");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x3440*/ "Avatar");
    }

    FUN_1000_16ba_print_char(0xfb);
    FUN_1000_1bf2_set_text_cursor_position(7, 2);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x3452*/ "Name:");

    FUN_1000_1b94_select_text_window(1);
    FUN_1000_1bf2_set_text_cursor_position(7, 2);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x3458*/ "Name:");
    FUN_1000_16ba_print_char(0xfd);

    FUN_1000_1b94_select_text_window(2);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_1bf2_set_text_cursor_position(10, 0);
    FUN_1000_1850_print_string(/*0x345e*/ "Keep this name?");
    do
    {
        uVar8 = FUN_1000_1dda_wait_for_keystroke(0);
        cVar4 = FUN_1000_2032_to_upper(uVar8);
        if (cVar4 == 'Y')
            break;
    } while (cVar4 != 'N');
    FUN_1000_16ba_print_char(0xff);
    if (cVar4 == 'N')
    {
        do
        {
            FUN_1000_1bf2_set_text_cursor_position(1, 0);
            FUN_1000_1850_print_string(/*0x346e*/ "Enter new name: ");
            FUN_1000_1e38_intro_enter_string(D_55a8_party[0]._0, 8);
        } while (D_55a8_party[0]._0[0] == 0);
    }

    FUN_1000_1b94_select_text_window(1);
    FUN_1000_1bf2_set_text_cursor_position(0, 3);
    FUN_1000_16ba_print_char(0xfc);
    FUN_1000_1850_print_string(D_55a8_party[0]._0);
    FUN_1000_16ba_print_char(0xfb);
    FUN_1000_1bf2_set_text_cursor_position(7, 2);
    FUN_1000_1850_print_string(/*0x347f*/ "Name:");
    FUN_1000_1bf2_set_text_cursor_position(5, 5);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x3485*/ "Sex:");
    FUN_1000_16ba_print_char(0xfd);

    FUN_1000_1b94_select_text_window(0);
    FUN_1000_1bf2_set_text_cursor_position(7, 2);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x348a*/ "Name:");
    FUN_1000_1bf2_set_text_cursor_position(5, 5);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x3490*/ "Sex:");
    FUN_1000_16ba_print_char(0xfd);

    FUN_1000_1b94_select_text_window(2);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_16ba_print_char(0xfc);
    FUN_1000_1850_print_string(/*0x3495*/ "Keep same sex?");
    FUN_1000_16ba_print_char(0xfb);

    do
    {
        cVar4 = FUN_1000_2032_to_upper(FUN_1000_1dda_wait_for_keystroke(0));
        if (cVar4 == 'Y')
            break;
    } while (cVar4 != 'N');

    FUN_1000_1b94_select_text_window(1);
    FUN_1000_1bf2_set_text_cursor_position(10, 5);
    if ((cVar4 == 'Y' && D_55a8_party[0]._9 == 11) || (cVar4 == 'N' && D_55a8_party[0]._9 == 12))
    {
        FUN_1000_1850_print_string(/*0x34a4*/ "Male");
        D_55a8_party[0]._9 = 0xb;
    }
    else
    {
        FUN_1000_1850_print_string(/*0x34a9*/ "Female");
        D_55a8_party[0]._9 = 0xc;
    }
    FUN_1000_1bf2_set_text_cursor_position(5, 5);
    FUN_1000_1850_print_string(/*0x34b0*/ "Sex:");
    FUN_1000_1bf2_set_text_cursor_position(3, 6);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x34b5*/ "Class:");
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1bf2_set_text_cursor_position(10, 6);
    if (D_3304 == 0)
    {
        F_INTRO_1278_print_u4_class();
    }
    else
    {
        FUN_1000_1850_print_string(/*0x34bc*/ "Avatar");
    }

    FUN_1000_1b94_select_text_window(0);
    FUN_1000_1bf2_set_text_cursor_position(5, 5);
    FUN_1000_1850_print_string(/*0x34c3*/ "Sex:");
    FUN_1000_1bf2_set_text_cursor_position(3, 6);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x34c8*/ "Class:");
    FUN_1000_16ba_print_char(0xfd);

    FUN_1000_1b94_select_text_window(2);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_1bf2_set_text_cursor_position(2, 0);
    if (D_3304 == 0)
    {
        FUN_1000_1850_print_string(/*0x34e7*/ "Class remains intact");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x34cf*/ "Thou art now an Avatar:");
    }
    FUN_1000_1dda_wait_for_keystroke(0);

    FUN_1000_1b94_select_text_window(0);
    FUN_1000_1bf2_set_text_cursor_position(3, 6);
    FUN_1000_1850_print_string(/*0x34fc*/ "Class:");
    FUN_1000_1bf2_set_text_cursor_position(5, 8);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x3503*/ "Exp:");
    FUN_1000_16ba_print_char(0xfd);

    FUN_1000_1b94_select_text_window(1);
    FUN_1000_1bf2_set_text_cursor_position(3, 6);
    FUN_1000_1850_print_string(/*0x3508*/ "Class:");
    FUN_1000_1bf2_set_text_cursor_position(5, 8);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x350f*/ "Exp:");
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1bf2_set_text_cursor_position(10, 8);
    D_55a8_party[0]._14 /= 10;
    FUN_1000_1a3e_print_number(iVar7, 1, 0x20);

    FUN_1000_1b94_select_text_window(2);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_16ba_print_char(0xfc);
    FUN_1000_1850_print_string(/*0x3514*/ "Experience has been converted");
    FUN_1000_16ba_print_char(0xfb);
    FUN_1000_1dda_wait_for_keystroke(0);

    FUN_1000_1b94_select_text_window(0);
    FUN_1000_1bf2_set_text_cursor_position(5, 8);
    FUN_1000_1850_print_string(/*0x3532*/ "Exp:");
    FUN_1000_1bf2_set_text_cursor_position(3, 9);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x3537*/ "Level:");
    FUN_1000_16ba_print_char(0xfd);

    FUN_1000_1b94_select_text_window(1);
    FUN_1000_1bf2_set_text_cursor_position(5, 8);
    FUN_1000_1850_print_string(/*0x353e*/ "Exp:");
    FUN_1000_1bf2_set_text_cursor_position(3, 9);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x3543*/ "Level:");
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1bf2_set_text_cursor_position(10, 9);
    D_55a8_party[0]._16 = 1;
    for (iVar7 = D_55a8_party[0]._14 / 100; iVar7 > 0; iVar7 >>= 1)
    {
        D_55a8_party[0]._16++;
    }
    iVar7 = (uint)D_55a8_party[0]._16 * 0x1e;
    D_55a8_party[0]._12 = iVar7;
    D_55a8_party[0]._10 = iVar7;
    FUN_1000_1a3e_print_number(D_55a8_party[0]._16, 1, 0x20);

    FUN_1000_1b94_select_text_window(2);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_16ba_print_char(0xfc);
    FUN_1000_1850_print_string(/*0x354a*/ "Level has been converted");
    FUN_1000_16ba_print_char(0xfb);
    FUN_1000_1dda_wait_for_keystroke(0);

    FUN_1000_1b94_select_text_window(0);
    FUN_1000_1bf2_set_text_cursor_position(3, 9);
    FUN_1000_1850_print_string(/*0x3563*/ "Level:");
    FUN_1000_1bf2_set_text_cursor_position(5, 0xb);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x356a*/ "STR:");
    FUN_1000_16ba_print_char(0xfd);

    FUN_1000_1b94_select_text_window(1);
    FUN_1000_1bf2_set_text_cursor_position(3, 9);
    FUN_1000_1850_print_string(/*0x356f*/ "Level:");
    FUN_1000_1bf2_set_text_cursor_position(5, 0xb);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x3576*/ "STR:");
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1bf2_set_text_cursor_position(10, 0xb);
    uVar1 = D_55a8_party[0]._c;
    bVar5 = F_INTRO_12ea(uVar1);
    D_55a8_party[0]._c = bVar5;
    if (bVar5 < 0x14)
    {
        D_55a8_party[0]._c = 0x14;
    }
    FUN_1000_1a3e_print_number(D_55a8_party[0]._c, 1, 0x20);

    FUN_1000_1b94_select_text_window(2);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_1bf2_set_text_cursor_position(1, 0);
    FUN_1000_1850_print_string(/*0x357b*/ "Strength: was ");
    FUN_1000_1a3e_print_number(uVar1, 1, 0x20);
    FUN_1000_1850_print_string(/*0x358a*/ "(50), now ");
    FUN_1000_1a3e_print_number(D_55a8_party[0]._c, 1, 0x20);
    FUN_1000_1850_print_string(/*0x3595*/ "(30)");
    FUN_1000_1dda_wait_for_keystroke(0);

    FUN_1000_1b94_select_text_window(0);
    FUN_1000_1bf2_set_text_cursor_position(5, 0xb);
    FUN_1000_1850_print_string(/*0x359a*/ "STR:");
    FUN_1000_1bf2_set_text_cursor_position(5, 0xc);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x359f*/ "DEX:");
    FUN_1000_16ba_print_char(0xfd);

    FUN_1000_1b94_select_text_window(1);
    FUN_1000_1bf2_set_text_cursor_position(5, 0xb);
    FUN_1000_1850_print_string(/*0x35a4*/ "STR:");
    FUN_1000_1bf2_set_text_cursor_position(5, 0xc);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x35a9*/ "DEX:");
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1bf2_set_text_cursor_position(10, 0xc);
    uVar1 = D_55a8_party[0]._d;
    uVar6 = F_INTRO_12ea(uVar1);
    D_55a8_party[0]._d = uVar6;
    FUN_1000_1a3e_print_number(uVar6, 1, 0x20);

    FUN_1000_1b94_select_text_window(2);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_1bf2_set_text_cursor_position(1, 0);
    FUN_1000_1850_print_string(/*0x35ae*/ "Dexterity: was ");
    FUN_1000_1a3e_print_number(uVar1, 1, 0x20);
    FUN_1000_1850_print_string(/*0x35be*/ "(50), now ");
    FUN_1000_1a3e_print_number(D_55a8_party[0]._d, 1, 0x20);
    FUN_1000_1850_print_string(/*0x35c9*/ "(30)");
    FUN_1000_1dda_wait_for_keystroke(0);

    FUN_1000_1b94_select_text_window(0);
    FUN_1000_1bf2_set_text_cursor_position(5, 0xc);
    FUN_1000_1850_print_string(/*0x35ce*/ "DEX:");
    FUN_1000_1bf2_set_text_cursor_position(5, 0xd);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x35d3*/ "INT:");
    FUN_1000_16ba_print_char(0xfd);

    FUN_1000_1b94_select_text_window(1);
    FUN_1000_1bf2_set_text_cursor_position(5, 0xc);
    FUN_1000_1850_print_string(/*0x35d8*/ "DEX:");
    FUN_1000_1bf2_set_text_cursor_position(5, 0xd);
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1850_print_string(/*0x35dd*/ "INT:");
    FUN_1000_16ba_print_char(0xfd);
    FUN_1000_1bf2_set_text_cursor_position(10, 0xd);
    uVar1 = D_55a8_party[0]._e;
    uVar6 = F_INTRO_12ea(uVar1);
    D_55a8_party[0]._e = uVar6;
    D_55a8_party[0]._f = uVar6;
    FUN_1000_1a3e_print_number(uVar6, 1, 0x20);

    FUN_1000_1b94_select_text_window(2);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_1bf2_set_text_cursor_position(1, 0);
    FUN_1000_1850_print_string(/*0x35e2*/ "Intellect: was ");
    FUN_1000_1a3e_print_number(uVar1, 1, 0x20);
    FUN_1000_1850_print_string(/*0x35f2*/ "(50), now ");
    FUN_1000_1a3e_print_number(D_55a8_party[0]._e, 1, 0x20);
    FUN_1000_1850_print_string(/*0x35fd*/ "(30)");
    FUN_1000_1dda_wait_for_keystroke(0);

    FUN_1000_1b94_select_text_window(0);
    FUN_1000_1bf2_set_text_cursor_position(5, 0xd);
    FUN_1000_1850_print_string(/*0x3602*/ "INT:");

    FUN_1000_1b94_select_text_window(1);
    FUN_1000_1bf2_set_text_cursor_position(5, 0xd);
    FUN_1000_1850_print_string(/*0x3607*/ "INT:");
    FUN_1000_1bf2_set_text_cursor_position(0, 0xf);
    FUN_1000_16ba_print_char(0xfc);
    if (D_3304 == 0)
    {
        FUN_1000_1850_print_string(/*0x3613*/ "Non-Avatar");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x360c*/ "Avatar");
    }
    FUN_1000_16ba_print_char(0xfb);

    FUN_1000_1b94_select_text_window(2);
    FUN_1000_1c22_set_text_window_size(2, 2, 0x15, 0x25, 0x16);
    FUN_1000_16ba_print_char(0xff);
    FUN_1000_251e_switch_disks(3);
    FUN_1000_1850_print_string(/*0x361e*/ "\n\n Conversion complete, saving...\n");

    for (iVar7 = 0; iVar7 < 0x100; iVar7++)
    {
        D_b21e[iVar7] = 0;
    }

    FUN_1000_25d8_write_file_to_disk(/*0x3641*/ "SAVED.OOL", D_b21e, 0x200);
    FILE_WriteSavegameFile(/*0x364b*/ "SAVED.GAM");
    //FUN_1000_25d8_write_file_to_disk(/*0x364b*/ "SAVED.GAM", &D_55a6, 0x1060);
    FUN_1000_251e_switch_disks(0);

    D_5893_map_id = cVar3;
    D_a9be = 0;
}

// NOT MATCHING
void F_INTRO_1e22(int param_1)
{
    FUN_1000_1b94_select_text_window(0);
    FUN_1000_1bf2_set_text_cursor_position(3, D_3656[param_1]);
    FUN_1000_1850_print_string(D_3666[param_1]);
    FUN_1000_1b94_select_text_window(1);
    FUN_1000_1bf2_set_text_cursor_position(3, D_3656[param_1]);
    FUN_1000_1850_print_string(D_3666[param_1]);
}

// NOT MATCHING
void F_INTRO_1e62(void)
{
    int iVar2;

    FUN_1000_1cca_set_text_foreground_color(D_13b2_frame_color);

    FUN_1000_1bf2_set_text_cursor_position(0, 0x13);
    FUN_1000_16ba_print_char(0x7b);
    for (iVar2 = 0; iVar2 < 0x26; iVar2++)
    {
        FUN_1000_16ba_print_char(0x7f);
    }
    FUN_1000_16ba_print_char(0x7c);
    for (iVar2 = 0; iVar2 < 3; iVar2++)
    {
        FUN_1000_16ba_print_char(0x7f);
        FUN_1000_1bf2_set_text_cursor_position(0x27, FUN_1000_1cee_get_current_text_row());
        FUN_1000_16ba_print_char(0x7f);
    }
    FUN_1000_16ba_print_char(0x7d);
    for (iVar2 = 0; iVar2 < 0x26; iVar2++)
    {
        FUN_1000_16ba_print_char(0x7f);
    }
    FUN_1000_16ba_print_char(0x7e);

    FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
    FUN_1000_0b10_GRAP_line(7, 0x9f, 0x138, 0x9f);
    FUN_1000_0f90_GRAP_pen(0x138, 0xb8);
    FUN_1000_0f90_GRAP_pen(7, 0xb8);
    FUN_1000_0f90_GRAP_pen(7, 0x9f);
    FUN_1000_1cca_set_text_foreground_color(D_13b0_white_color);
}

// NOT MATCHING
void F_INTRO_1f26(int param_1)
{
    int iVar1;
    int iVar2;

    FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b2_frame_color);
    FUN_1000_0aa6_GRAP_3f_fill_rectangle(param_1, 0, param_1 + 6, 0x8f);
    iVar1 = param_1 + 0x8f;
    FUN_1000_0aa6_GRAP_3f_fill_rectangle(iVar1, 0, param_1 + 0x97, 0x89);
    iVar2 = param_1 + 7;
    FUN_1000_0aa6_GRAP_3f_fill_rectangle(iVar2, 0x89, param_1 + 0x96, 0x8f);
    FUN_1000_1cca_set_text_foreground_color(D_13b2_frame_color);
    FUN_1000_1bf2_set_text_cursor_position(0, 0);
    FUN_1000_1850_print_string(/*0x3676*/ "\x7b\x7f\x7f");
    FUN_1000_4c2a();
    FUN_1000_1cca_set_text_foreground_color(D_13b0_white_color);
    FUN_1000_1850_print_string(/*0x6d3a*/ " Ultima IV ");
    FUN_1000_1cca_set_text_foreground_color(D_13b2_frame_color);
    FUN_1000_4cce();
    FUN_1000_1850_print_string(/*0x367a*/ "\x7f\x7f");
    FUN_1000_16ba_print_char(0x7c);
    FUN_1000_1bf2_set_text_cursor_position(0, 0x11);
    FUN_1000_16ba_print_char(0x7d);
    FUN_1000_1bf2_set_text_cursor_position(0x12, 0x11);
    FUN_1000_16ba_print_char(0x7e);
    FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
    FUN_1000_0b10_GRAP_line(param_1 + 0x18, 7, iVar2, 7);
    FUN_1000_0f90_GRAP_pen(iVar2, 0x88);
    FUN_1000_0f90_GRAP_pen(iVar1, 0x88);
    FUN_1000_0f90_GRAP_pen(iVar1, 7);
    FUN_1000_0f90_GRAP_pen(param_1 + 0x80, 7);
    FUN_1000_1cca_set_text_foreground_color(D_13b0_white_color);
}

// NOT MATCHING
void F_INTRO_2024(void)
{
    F_INTRO_1e62();
    FUN_1000_1c22_set_text_window_size(0, 0, 0, 0x13, 0x12);
    FUN_1000_1c22_set_text_window_size(1, 0x15, 0, 0x27, 0x12);
    FUN_1000_1c22_set_text_window_size(2, 3, 0x15, 0x25, 0x15);
    FUN_1000_1b94_select_text_window(0);
    F_INTRO_1f26(0);
    FUN_1000_1b94_select_text_window(1);
    F_INTRO_1f26(0xa8);
    FUN_1000_1bf2_set_text_cursor_position(0xc, 0);
    FUN_1000_16ba_print_char(0x20);
}

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
