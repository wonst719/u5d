#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>

void F_DNGLOOK_0000_look_cmd_in_dungeon(void) { puts("F_DNGLOOK_0000_look_cmd_in_dungeon"); }

void F_DNGLOOK_06a8_view_cmd(void) { puts("F_DNGLOOK_06a8_view_cmd"); }

void F_DNGLOOK_0844(int a) { printf("F_DNGLOOK_0844(%d)\n", a); }

// NOT MATCHING: TEST
uint F_DNGLOOK_08d4(int param_1)
{
    uint local_6;
    uint local_c;
    uint local_a;
    u8 local_8;
    u8 local_4;

    local_6 = (int)D_5893_map_id - 0x21;
    if (1 <= local_6) {
        local_6--;
    }

    // 08ed
    local_c = local_6 * 0x10 + param_1;
    local_a = param_1 / 8;
    local_4 = D_58e0[local_a];
    local_8 = 1 << (local_c & 7);

    return (local_8 & local_4) != 0;
}

// NOT MATCHING
void F_DNGLOOK_093a(void)
{
    byte* ptr = D_595a;
    int size = 0x200;

    do
    {
        if ((*ptr & 0xf0) == 0xf0)
        {
            int iVar1 = F_DNGLOOK_08d4(*ptr & 0xf);
            if (iVar1 != 0)
            {
                *ptr &= 0xaf;
            }
        }
        ptr++;
        size--;
    } while (size != 0);
    return;
}

void F_DNGLOOK_0c6c(void) { puts("F_DNGLOOK_0c6c"); }

void F_DNGLOOK_0d3e(void) { puts("F_DNGLOOK_0d3e"); }

void F_DNGLOOK_0fda(void) { puts("F_DNGLOOK_0fda"); }

void F_DNGLOOK_109e(int param_1)
{
    if (D_5893_map_id != 0)
    {
        if ((D_bb17 & 2) != 0)
        {
            FUN_1000_102e_unload_tileset();
        }

        if ((D_bb17 & 1) == 0)
        {
            do
            {
                D_a9c0 = FUN_1000_0bae_load_image_file(D_25ea[4 + D_6604]); // DNGn.16
            } while (D_a9c0 == 0);

            do
            {
                D_a9c4 = FUN_1000_0bae_load_image_file(D_25ea[4]); // ITEMS.16
            } while (D_a9c4 == 0);
        }

        D_bb17 = 1;
        if (param_1 != 0)
        {
            D_5c5a[1]._1 = 0;
            D_5c5a[1]._0_tile = 0;
            D_5c5a[1]._3_y = 0xff;
            D_5c5a[1]._2_x = 0xff;
            D_5c5a[1]._5 = 0xff;
        }

        FUN_1000_0a70_GRAP_2d_set_pen_color(0);
        FUN_1000_0aa6_GRAP_3f_fill_rectangle(8, 8, 0xb7, 0xb7);
        FUN_1000_0c22_GRAP_0f_select_page(1);
        FUN_1000_0aa6_GRAP_3f_fill_rectangle(8, 8, 0xb7, 0xb7);
        FUN_1000_0c22_GRAP_0f_select_page(0);
    }
}

void F_DNGLOOK_1130(void)
{
    int iVar1;

    if ((D_bb17 & 1) != 0)
    {
        if (D_5c5a[1]._5 != 0xff)
        {
            FUN_1000_0be4_free_memory(D_a9c6);
        }
        D_a9c6 = 0;
        FUN_1000_0be4_free_memory(D_a9c4);
        FUN_1000_0be4_free_memory(D_a9c0);
    }

    if ((D_bb17 & 2) == 0)
    {
        do
        {
            iVar1 = FUN_1000_0ff4_load_compressed_tileset(*D_25f0); // TILES.16
        } while (iVar1 == 0);
    }

    if ((D_bb17 & 4) == 0)
    {
        FUN_1000_6f9e(0);
    }

    D_bb17 = 6;
}

void F_DNGLOOK_117e(int a, int b) { printf("F_DNGLOOK_117e(%d,%d)\n", a, b); }
