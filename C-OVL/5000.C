#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <memory.h>

FUN_1000_1112(int a, int b, int c) {}
FUN_1000_0cf2(int a, int b, int c) {}

FUN_1000_6ff0() {}
FUN_1000_51b8() {}

void FUN_1000_5394(void)
{
    undefined1 uVar1;
    byte bVar2;
    byte bVar3;
    uint uVar5;
    int iVar6;
    int iStack_e;
    byte bStack_a;
    byte bStack_8;

    int idx;

    if (D_5893_map_id < 0x80)
    {
        D_5c5a[0]._2_x = D_5896_map_x;
        D_5c5a[0]._3_y = D_5897_map_y;
        D_5c5a[0]._4_z = D_5895_map_level;
        uVar1 = D_587c;
        D_5c5a[0]._0_tile = uVar1;
        D_5c5a[0]._1 = uVar1;
        
        for (iStack_e = 0; iStack_e < 0xb; iStack_e++)
        {
            for (iVar6 = 0; iVar6 < 0xb; iVar6++)
            {
                if ((D_ab02[iStack_e * 0x20 + iVar6] == -0x23) &&
                    (5 < FUN_1000_6ff0(iVar6, iStack_e)))
                {
                    D_ab02[iStack_e * 0x20 + iVar6] = 0x1c;
                }
                else if ((D_ab02[iStack_e * 0x20 + iVar6] == '\x1c') &&
                    (FUN_1000_6ff0(iVar6, iStack_e) < 6))
                {
                    D_ab02[iStack_e * 0x20 + iVar6] = 0xdd;
                }
            }
        }
    }

    idx = 0x1f;
    do
    {
        if (D_5c5a[idx]._0_tile != '\0')
        {
            bVar2 = D_5c5a[idx]._2_x;
            bVar3 = D_5c5a[idx]._3_y;
            bStack_a = bVar3;
            bStack_8 = bVar2;
            if (D_5893_map_id < 0x80)
            {
                bStack_8 = bVar2 - (D_5896_map_x + -5);
                bStack_a = bVar3 - (D_5897_map_y + -5);
                if (((D_5c5a[idx]._4_z != D_5895_map_level) || (10 < bStack_8)) || (10 < bStack_a))
                    goto LAB_1000_5601;
            }
            if (((D_5c5a[idx]._1 != '\0') &&
                (D_ab02[(uint)bStack_a * 0x20 + (uint)bStack_8] != -1)) &&
                (D_ab02[(uint)bStack_a * 0x20 + (uint)bStack_8] != -0x79))
            {
                if ((((D_5c5a[idx]._0_tile & 0xfc) == 0xe8) || (D_5c5a[idx]._0_tile == 0x1e)) || (D_5c5a[idx]._0_tile == 0x1f))
                {
                    uVar5 = (uint)bStack_8;
                    if (D_ab02[(uint)bStack_a * 0x20 + uVar5] != '\0')
                    {
                        D_ac64[(uint)bStack_a * 0x10 + uVar5] = D_5c5a[idx]._1;
                        iVar6 = (uint)bStack_a * 0x20 + uVar5;
                        goto LAB_1000_5542;
                    }
                }
                else if ((D_5c5a[idx]._1 == '\x1d') || (D_5c5a[idx]._1 == '\x1e'))
                {
                    D_ac64[(uint)bStack_a * 0x10 + (uint)bStack_8] = D_5c5a[idx]._1;
                    iVar6 = (uint)bStack_a * 0x20 + (uint)bStack_8;
                LAB_1000_5542:
                    D_ab02[iVar6] = 0;
                }
                else
                {
                    if (D_5c5a[idx]._0_tile == '\\')
                    {
                        uVar5 = (uint)bStack_8;
                        if (D_ab02[(uint)bStack_a * 0x20 + uVar5] == 0x92)
                        {
                            D_ac64[(uint)bStack_a * 0x10 + uVar5] = D_5c5a[idx]._1;
                            iVar6 = (uint)bStack_a * 0x20 + uVar5;
                            goto LAB_1000_5542;
                        }
                        uVar5 = D_5c5a[idx]._1 - 8;
                    }
                    else
                    {
                        uVar5 = (uint)D_5c5a[idx]._1;
                    }
                    FUN_1000_51b8(bStack_8, bStack_a, bVar2, bVar3, uVar5);
                }
            }
        }
    LAB_1000_5601:
        idx--;
    }
    while (idx >= 1);
}

FUN_1000_5646(int a) {}

// OK P1
void FUN_1000_56ac_draw_map(void)
{
    int local_2;
    int local_4;
    int local_6;
    int local_8;

    for (local_8 = 0; local_8 < 11; local_8++)
    {
        for (local_6 = 0; local_6 < 0xb; local_6++)
        {
            // D_ab02: map data for rendering?
            if (D_ab02[local_8 * 0x20 + local_6] == 0)
            {
                // D_ac64: character map?
                if (D_ac64[local_8 * 0x10 + local_6] != 0x16)
                {
                    // draw character?
                    FUN_1000_10e0_draw_tile(0x100 + D_ac64[local_8 * 0x10 + local_6], local_6, local_8);
                }
            }
            else
            {
                if (D_ab02[local_8 * 0x20 + local_6] == 0xdc && D_5887 != 0 && D_5887 < 0x10)
                {
                    // moongate?
                    FUN_1000_1112(D_5887, local_6, local_8);
                }
                else
                {
                    // draw map tile
                    FUN_1000_10e0_draw_tile(D_b11e[D_ab02[local_8 * 0x20 + local_6]], local_6, local_8);
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
void FUN_1000_5910_update_map(void)
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

        FUN_1000_5394();
        FUN_1000_56ac_draw_map();
        if (D_5891 != 0)
        {
            // animate?
            FUN_1000_4102();
        }
    }

    D_5891 = 1;
}
