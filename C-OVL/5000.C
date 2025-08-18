#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <memory.h>

FUN_1000_1112(int a, int b, int c) {}
FUN_1000_0cf2(int a, int b, int c) {}

FUN_1000_6ff0() {}
FUN_1000_51b8() {}

void FUN_1000_5394_a(void);

void FUN_1000_5394(void)
{
    undefined1 uVar1;
    byte bVar2;
    byte bVar3;
    int iVar4;
    uint uVar5;
    int iVar6;
    register byte* pbVar7;
    register char* pcVar8;
    undefined2 unaff_DS;
    byte* pbStack_28;
    byte* pbStack_26;
    undefined1* puStack_24;
    char* pcStack_22;
    undefined1* puStack_20;
    undefined1* puStack_1c;
    char* pcStack_18;
    char* pcStack_16;
    char* pcStack_14;
    byte* pbStack_12;
    byte* pbStack_10;
    int iStack_e;
    byte bStack_a;
    byte bStack_8;

    byte l_6;
    byte l_4;

    int idx;

    if (D_5893_map_id < 0x80)
    {
        D_5c5a[0]._2_x = D_5896_map_x;
        D_5c5a[0]._3_y = D_5897_map_y;
        D_5c5a[0]._4_z = D_5895_map_level;
        D_5c5a[0]._1 = D_5c5a[0]._0_tile = D_587c;
        
        for (iStack_e = 0; iStack_e < 0xb; iStack_e++)
        {
            for (iVar6 = 0; iVar6 < 0xb; iVar6++)
            {
                if ((D_ab02[iStack_e * 0x20 + iVar6] == 0xdd) &&
                    (5 < FUN_1000_6ff0(iVar6, iStack_e)))
                {
                    D_ab02[iStack_e * 0x20 + iVar6] = 0x1c;
                }
                else if ((D_ab02[iStack_e * 0x20 + iVar6] == 0x1c) &&
                    (FUN_1000_6ff0(iVar6, iStack_e) <= 5))
                {
                    D_ab02[iStack_e * 0x20 + iVar6] = 0xdd;
                }
            }
        }
    }

    // 542a
    // f8
    idx = 0x1f;
    pcStack_14 = (char*)&D_5c5a[idx]._0_tile;
    pbStack_12 = (byte*)&D_5c5a[idx]._2_x;
    pbStack_10 = (byte*)&D_5c5a[idx]._3_y;
    pcStack_16 = (char*)&D_5c5a[idx]._4_z;
    pcStack_18 = (char*)&D_5c5a[idx]._1;
    pbVar7 = (byte*)&D_5c5a[idx]._0_tile;
    puStack_1c = (undefined1*)&D_5c5a[idx]._1;
    pcVar8 = (char*)&D_5c5a[idx]._1;
    puStack_20 = (undefined1*)&D_5c5a[idx]._1;
    pcStack_22 = (char*)&D_5c5a[idx]._0_tile;
    puStack_24 = (undefined1*)&D_5c5a[idx]._1;
    pbStack_26 = (byte*)&D_5c5a[idx]._1;
    pbStack_28 = (byte*)&D_5c5a[idx]._1;
    do
    {
        if (*pcStack_14 != 0)
        {
            bStack_8 = l_4 = *pbStack_12;
            bStack_a = l_6 = *pbStack_10;
            //bVar2 = *pbStack_12;
            //bVar3 = *pbStack_10;
            //bStack_a = bVar3;
            //bStack_8 = bVar2;
            if (D_5893_map_id < 0x80)
            {
                l_4 -= (D_5896_map_x - 5);
                l_6 -= (D_5897_map_y - 5);
                if (((*pcStack_16 != D_5895_map_level) || (10 < bStack_8)) || (10 < bStack_a))
                    goto LAB_1000_5601;
            }
            if (((*pcStack_18 != 0) &&
                (D_ab02[(uint)bStack_a * 0x20 + (uint)bStack_8] != 0xff)) &&
                (D_ab02[(uint)bStack_a * 0x20 + (uint)bStack_8] != 0x87))
            {
                if ((((*pbVar7 & 0xfc) == 0xe8) || (*pbVar7 == 0x1e)) || (*pbVar7 == 0x1f))
                {
                    // 5503
                    if (D_ab02[(uint)bStack_a * 0x20 + (uint)bStack_8] != 0)
                    {
                        D_ac64[(uint)bStack_a * 0x10 + (uint)bStack_8] = *puStack_1c;
                        D_ab02[(uint)bStack_a * 0x20 + (uint)bStack_8] = 0;
                    }
                }
                else if ((*pcVar8 == 0x1d) || (*pcVar8 == 0x1e))
                {
                    D_ac64[(uint)bStack_a * 0x10 + (uint)bStack_8] = *puStack_20;
                    D_ab02[(uint)bStack_a * 0x20 + (uint)bStack_8] = 0;
                }
                else
                {
                    if (*pcStack_22 == 0x5c)
                    {
                        if (D_ab02[(uint)bStack_a * 0x20 + (uint)bStack_8] == 0x92)
                        {
                            D_ac64[(uint)bStack_a * 0x10 + (uint)bStack_8] = *puStack_24;
                            D_ab02[(uint)bStack_a * 0x20 + (uint)bStack_8] = 0;
                            goto LAB_1000_5601;
                        }
                        //uVar5 = *pbStack_26 - 8;
                        FUN_1000_51b8(bStack_8, bStack_a, *pbStack_12, *pbStack_10, *pbStack_26 - 8);
                    }
                    else
                    {
                        //uVar5 = (uint)*pbStack_28;
                        FUN_1000_51b8(bStack_8, bStack_a, *pbStack_12, *pbStack_10, *pbStack_28);
                    }
                    //FUN_1000_51b8(bStack_8, bStack_a, bVar2, bVar3, uVar5);
                }
            }
        }
    LAB_1000_5601:
        pcStack_14 -= 8;
        pbStack_12 -= 8;
        pbStack_10 -= 8;
        pcStack_16 -= 8;
        pcStack_18 -= 8;
        pbVar7 -= 8;
        puStack_1c -= 8;
        pcVar8 -= 8;
        puStack_20 -= 8;
        pcStack_22 -= 8;
        puStack_24 -= 8;
        pbStack_26 -= 8;
        pbStack_28 -= 8;
        idx--;
    }
    while (pbStack_28 >= (byte*)&D_5c5a[0]._1);
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
