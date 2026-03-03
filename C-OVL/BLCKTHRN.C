#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <memory.h>

void F_TOWN_11f0_Entry(int param_1);

int F_CAST2_05e0(int a, int b);
void F_CAST2_08ea(int a);

void F_BLCKTHRN_060e_capture(void) { puts("F_BLCKTHRN_060e_capture"); }

// TODO: MATCH
void F_BLCKTHRN_0910_death(void)
{
    int local_c;
    int local_6;
    uint local_8;

    FUN_1000_251e_switch_disks(1);

    while (FUN_1000_1674_test_open_file("BRIT.DAT") == 0) {}

    F_CAST2_08ea(D_58a6);
    D_587c = 0x1e;

    if (D_5893_map_id < 0x21)
    {
        FUN_1000_5910_update_map();
    }

    FUN_1000_20fa_wait_ticks(10);
    local_c = D_5893_map_id;
    D_5893_map_id = 0xff;
    D_589e = 0xff;
    FUN_1000_1850_print_string("\nAn unending darkness engulfs thee...");
    FUN_1000_0c22_GRAP_0f_select_page(1);
    FUN_1000_0a70_GRAP_2d_set_pen_color(0);
    FUN_1000_0aa6_GRAP_3f_fill_rectangle(8, 8, 0xb7, 0xb7);
    FUN_1000_0c22_GRAP_0f_select_page(0);
    FUN_1000_0f46_GRAP_66(8, 8, 0xb7, 0xb7);

    for (local_8 = 0; local_8 < 0xb; local_8++)
    {
        memset(&D_ad14[local_8 * 0x20], 0xff, 0xb);
    }

    for (local_8 = 0; local_8 < 0x20; local_8++)
    {
        FUN_1000_3a74(0, 0, 0, 0, 0, 0, local_8);
    }

    FUN_1000_5910_update_map();

    FUN_1000_1850_print_string("\n\nThou hast found refuge.");
    FUN_1000_20fa_wait_ticks(0xe);
    FUN_1000_1850_print_string("\n\nNo evil lives here, only peace and darkness.");
    FUN_1000_20fa_wait_ticks(0x1c);
    FUN_1000_1850_print_string("\n\nBut thy slumber is disturbed!");

    D_ad14[0xa5] = 0; // 0xadb9
    D_5c5a[0]._1 = 0x1c;
    D_5c5a[0]._0_tile = 0x1c;
    D_5c5a[0]._3_y = 5;
    D_5c5a[0]._2_x = 5;
    FUN_1000_5910_update_map();

    // TODO: match variable
    for (local_8 = 0; local_8 < 6; local_8++)
    {
        FUN_1000_2192_audio_some_noise(D_3720[local_8], 1, D_372c[local_8], D_3738[local_8], D_3744[local_8]);
    }

    FUN_1000_1850_print_string("\n\nSomeone shouts\n\n\"FORTIS FORTUNA\nAVENTARI\"");
    FUN_1000_20fa_wait_ticks(6);
    D_5c5a[1]._1 = 0x16;
    D_5c5a[1]._0_tile = 0x16;
    D_5c5a[1]._2_x = 2;
    D_5c5a[1]._3_y = 7;
    D_ad14[0xe2] = 0;
    FUN_1000_1068(0x5e, 2, 7);
    D_ad14[0xe2] = 0x5e;
    D_5c5a[1]._0_tile = 0;
    FUN_1000_5910_update_map();

    FUN_1000_20fa_wait_ticks(4);
    D_5c5a[1]._0_tile = 0x16;
    D_5c5a[1]._2_x = 8;
    D_ad14[0xe8] = 0;
    FUN_1000_1068(0x5f, 8, 7);
    D_ad14[0xe8] = 0x5f;
    D_5c5a[1]._0_tile = 0;
    FUN_1000_5910_update_map();

    FUN_1000_20fa_wait_ticks(4);
    FUN_1000_1850_print_string("\n\nThere is a peal of thunder!\n");
    FUN_1000_3072();
    FUN_1000_3072();
    D_ad14[0x45] = 0;
    D_5c5a[1]._1 = 0x16;
    D_5c5a[1]._0_tile = 0x16;
    D_5c5a[1]._2_x = 5;
    D_5c5a[1]._3_y = 2;
    FUN_1000_1068(0x174, 5, 2);
    D_5c5a[1]._1 = 0x74;
    D_5c5a[1]._0_tile = 0x74;
    FUN_1000_5910_update_map();

    FUN_1000_1850_print_string("\n\"");
    FUN_1000_256e_read_file_from_disk("KARMA.DAT", D_b21e, 2000, D_1a74[D_5888 / 0x14]);
    FUN_1000_1850_print_string((char*)D_b21e);
    FUN_1000_16ba_print_char(0x22);
    FUN_1000_266c_get_ch();
    FUN_1000_1850_print_string("\n\nStrange words are intoned.");
    FUN_1000_20fa_wait_ticks(4);

    if (D_585b != 0)
    {
        for (local_8 = 0; local_8 < D_585b; local_8++)
        {
            // 32bit div?
            // TODO: MATCH
            //uVar5 = FUN_1000_03a0(0, uVar6 + 7, 0, 0x8e30);
            FUN_1000_2192_audio_some_noise(0x8e30 / (local_8 + 7), 1, 30000, 2000, 2);
            F_CAST2_05e0(local_8, 0xff);
            D_55a8_party[local_8]._10 = D_55a8_party[local_8]._12;
            FUN_1000_2900_update_vitals();
        }
    }

    FUN_1000_1850_print_string("\n\nVertigo...\n");
    FUN_1000_20fa_wait_ticks(4);
    FUN_1000_0c22_GRAP_0f_select_page(1);
    FUN_1000_0a70_GRAP_2d_set_pen_color(0);
    FUN_1000_0aa6_GRAP_3f_fill_rectangle(8, 8, 0xb7, 0xb7);
    FUN_1000_10e0_draw_tile(0x11c, 5, 5);
    FUN_1000_0c22_GRAP_0f_select_page(0);
    FUN_1000_0f46_GRAP_66(8, 8, 0xb7, 0xb7);
    if (D_5888 < 0x4b)
    {
        D_5888 = 0x4b;
    }
    D_5893_map_id = 0x11;
    D_5895_map_level = 1;
    D_587c = 0x1c;
    D_5897_map_y = 10;
    D_5896_map_x = 10;
    D_588e = 0;
    D_587a = 0;
    while (D_587f != 0x6)
    {
        FUN_1000_4f7c(9);
    }
    D_58a6 = 0;
    D_58a7 = 0;
    if (D_57a8 == 0)
    {
        D_57a8 = 0x3f;
    }
    if (local_c != 0 && local_c < 0x21)
    {
        F_TOWN_11f0_Entry(1);
    }
}
