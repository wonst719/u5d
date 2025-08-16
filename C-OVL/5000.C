#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <memory.h>

FUN_1000_1112(int a, int b, int c) {}
FUN_1000_0cf2(int a, int b, int c) {}

FUN_1000_5646(int a) {}

// OK P1
void FUN_1000_56ac(void)
{
    int local_2;
    int local_4;
    int local_6;
    int local_8;

    for (local_8 = 0; local_8 < 11; local_8++)
    {
        for (local_6 = 0; local_6 < 0xb; local_6++)
        {
            if (D_ab02[local_8 * 0x20 + local_6] == 0)
            {
                if (D_ac64[local_8 * 0x10 + local_6] != 0x16)
                {
                    FUN_1000_10e0(0x100 + D_ac64[local_8 * 0x10 + local_6], local_6, local_8);
                }
            }
            else
            {
                if (D_ab02[local_8 * 0x20 + local_6] == 0xdc && D_5887 != 0 && D_5887 < 0x10)
                {
                    FUN_1000_1112(D_5887, local_6, local_8);
                }
                else
                {
                    FUN_1000_10e0(D_b11e[D_ab02[local_8 * 0x20 + local_6]], local_6, local_8);
                }
            }
        }
    }

    if (0x7f < D_5893_map_id && (D_589f = !D_589f) != 0 && D_589e != 0xff && FUN_1000_5646(D_589e) == 0)
    {
        local_2 = (uint)D_ba1a[D_589e * 8] * 0x10 + 8;
        local_4 = (uint)D_ba1a[D_589e * 8 + 1] * 0x10 + 8;

        FUN_1000_0a70_set_pen_color(D_13b0_white_color);

        for (local_6 = 0; local_6 < 2; local_6++)
        {
            for (local_8 = 0; local_8 < 0xf; local_8 += 0xe)
            {
                FUN_1000_0c9c_grap_horiz_line(local_2, local_4 + local_6 + local_8, local_2 + 0xf);
                FUN_1000_0cf2(local_2 + local_6 + local_8, local_4, local_4 + 0xf);
            }
        }

        if (D_5898 != 0)
        {
            // 5813
            // draw crosshair / focus
            local_2 = (uint)D_5899 * 0x10 + 8; // cross hair x
            local_4 = (uint)D_589a * 0x10 + 8; // cross hair y

            // 586a
            for (local_6 = 0; local_6 < 2; local_6++)
            {
                for (local_8 = 0; local_8 < 2; local_8++)
                {
                    // 5887
                    FUN_1000_0a70_set_pen_color(D_13b0_white_color);
                    FUN_1000_0b10_line(local_8 * 0xb + local_2 + 2, local_6 * 3 + local_4 + 6, local_8 * 3 + local_2 + 6, local_6 * 3 + local_4 + 6);
                    FUN_1000_0f90_pen(local_8 * 3 + local_2 + 6, local_6 * 0xb + local_4 + 2);
                    FUN_1000_0a70_set_pen_color(0);
                    FUN_1000_0b10_line(local_8 * 0xb + local_2 + 2, local_6 * 5 + local_4 + 5, local_8 * 5 + local_2 + 5, local_6 * 5 + local_4 + 5);
                    FUN_1000_0f90_pen(local_8 * 5 + local_2 + 5, local_6 * 0xb + local_4 + 2);
                    FUN_1000_0b10_line(local_8 * 0xb + local_2 + 2, local_4 + local_6 + 7, local_8 * 3 + local_2 + 6, local_4 + local_6 + 7);

                    FUN_1000_0b10_line(local_2 + local_8 + 7, local_6 * 3 + local_4 + 6, local_2 + local_8 + 7, local_6 * 0xb + local_4 + 2);
                }
            }
        }
    }
}

// OK P1 (complete)
void FUN_1000_5910(void)
{
    int local_2;
    int local_4;

    D_545e = 0xff;
    if (D_587a == 'T')
    {
        D_5891 = 0;
    }
    if (D_58a4 != 0)
    {
        if (D_5891 != 0) // animate flag
        {
            if (D_5891 != (byte)-1)
            {
                FUN_1000_4552();
            }
            FUN_1000_2f62();
            if (D_5893_map_id < 0x80)
            {
                FUN_1000_475a();
                FUN_1000_70a6();
            }
        }
        if (D_5893_map_id < 0x80)
        {
            if (D_24e6 != 0)
            {
                FUN_1000_5d0a(D_58a5, (uint)D_5896_map_x - (uint)D_589b, (uint)D_5897_map_y - (uint)D_589c, 0xb);
                D_24e6 = 0;
            }
            else
            {
                for (local_4 = 0; local_4 < 11; local_4++)
                {
                    for (local_2 = 0; local_2 < 11; local_2++)
                    {
                        if (D_ab02[local_4 * 32 + local_2] == 0)
                        {
                            D_ab02[local_4 * 32 + local_2] =
                                *FUN_1000_4402_get_address_of_tile_id((byte)local_2 + (uint)D_5896_map_x - 5, (byte)local_4 + (uint)D_5897_map_y - 5);
                        }
                    }
                }
            }
        }
        else // map_id >= 0x80; combat?
        {
            // OK P1
            memcpy(D_ab02, D_ad14, 0x160);
        }

        FUN_1000_5394_disk_swap_message();
        FUN_1000_56ac();
        if (D_5891 != 0)
        {
            FUN_1000_4102();
        }
    }

    D_5891 = 1;
}
