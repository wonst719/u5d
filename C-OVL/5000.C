#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <memory.h>

FUN_1000_1112(int a, int b, int c) {}
FUN_1000_0cf2(int a, int b, int c) {}

// OK P1
int FUN_1000_51a0(void)
{
    if (D_587a == 'T')
    {
        return 0;
    }
    else
    {
        return FUN_1000_2092_random_range(0, 3);
    }
}

// NOT MATCHING
void FUN_1000_51b8(int param_1, undefined2 param_2, int param_3, int param_4, int param_5)
{
    int local_4;

    if ((param_5 != 0x1c) &&
        ((((param_5 < 0x12 || (0x16 <= param_5)) && (param_5 < 0x40)) &&
            ((param_5 < 0x28 || (0x2c <= param_5)))))) goto LAB_1000_5370;

    // 51e9
    local_4 = *FUN_1000_4402_get_address_of_tile_id(param_3, param_4);
    if (local_4 == 0xec || local_4 == 0x10)
        return;

    // 520b?
    if (local_4 == 0x57) // 87
    {
        // 520b
        D_ab02[param_1 + param_2 * 0x20] = 0x38;
        return;
    }

    if (local_4 == 0x6a || local_4 == 0x6b) // 106, 107
    {
        // 522e
        if (((byte)param_5 & 0xf0) == 0x80)
        {
            return;
        }
        if (((byte)param_5 & 0xfc) == 0x28)
        {
            return;
        }

        goto LAB_1000_5370;
    }

    // 524a
    if (0x80 <= param_5)
        goto LAB_1000_5370;

    // 5254
    switch (local_4)
    {
    case 0x84: // 132
        // 5276
        param_5 = FUN_1000_51a0() + 0x60; // -> 5300
        break;

    case 0x85: // 133
        // 5280
        param_5 = FUN_1000_51a0() + 0x64; // -> 5300
        break;

    case 0xc8: // 200
        // 528a
        param_5 = 0x17;
        break;

    case 0xc9: // 201
        // 5292
        param_5 = 0x18;
        break;

    case 0xab: // 171
        // 529a
        param_5 = 0x1a;
        break;

        // 93..9e
    case 0x9d: // 157
    case 0x9e: // 158 (531a)
        // 52a2
        param_5 = FUN_1000_51a0() + 0x3c;
        break;

    case 0x92: // 146
        // 52aa
        if ((*FUN_1000_4402_get_address_of_tile_id(param_3, param_4 + 1) == 0x9a) ||
            (*FUN_1000_4402_get_address_of_tile_id(param_3, param_4 + 1) == 0x9c))
        {
            param_5 = FUN_1000_51a0() + 0x34;
        }
        else
        {
            param_5 = 0x32;
        }
        break;

    case 0x90: // 144
        // 52da
        if ((*FUN_1000_4402_get_address_of_tile_id(param_3, param_4 - 1) == 0x9b) ||
            (*FUN_1000_4402_get_address_of_tile_id(param_3, param_4 - 1) == 0x9c))
        {
            param_5 = FUN_1000_51a0() + 0x38;
        }
        else
        {
            param_5 = 0x30;
        }
        break;

    case 0x91: // 145, 532a
    case 0x93: // 147
        // -> 530e -> 5300
        param_5 = (local_4 & 3) + 0x30;
        break;

    default:
        // 532c
        if ((*FUN_1000_4402_get_address_of_tile_id(param_3, param_4 - 1) == 0x9d) && (param_2 != 0))
        {
            D_ab02[param_1 + (param_2 - 1) * 0x20] = 0x9e;
        }
        break;
    }

LAB_1000_5370:
    D_ac64[param_1 + param_2 * 0x10] = (byte)param_5;
    D_ab02[param_1 + param_2 * 0x20] = 0;

    // 538d
    return;
}

// NOT MATCHING (TODO: 6ff0 리턴형 검증)
void FUN_1000_5394(void)
{
    int local_c;
    int local_e;
    byte local_a;
    byte local_8;

    byte local_6;
    byte local_4;

    if (D_5893_map_id < 0x80)
    {
        D_5c5a[0]._2_x = D_5896_map_x;
        D_5c5a[0]._3_y = D_5897_map_y;
        D_5c5a[0]._4_z = D_5895_map_level;
        D_5c5a[0]._1 = D_5c5a[0]._0_tile = D_587c;
        
        for (local_e = 0; local_e < 0xb; local_e++)
        {
            for (local_c = 0; local_c < 0xb; local_c++)
            {
                if ((D_ab02[local_e * 0x20 + local_c] == 0xdd) &&
                    (5 < FUN_1000_6ff0(local_c, local_e)))
                {
                    D_ab02[local_e * 0x20 + local_c] = 0x1c;
                }
                else if ((D_ab02[local_e * 0x20 + local_c] == 0x1c) &&
                    (FUN_1000_6ff0(local_c, local_e) <= 5))
                {
                    D_ab02[local_e * 0x20 + local_c] = 0xdd;
                }
            }
        }
    }

    // 542a
    local_c = 31;
    do
    {
        if (D_5c5a[local_c]._0_tile != 0)
        {
            local_8 = local_4 = D_5c5a[local_c]._2_x;
            local_a = local_6 = D_5c5a[local_c]._3_y;

            if (D_5893_map_id < 0x80)
            {
                local_8 -= (D_5896_map_x - 5);
                local_a -= (D_5897_map_y - 5);
                if (((D_5c5a[local_c]._4_z != D_5895_map_level) || (10 < local_8)) || (10 < local_a))
                    continue;
            }
            if (((D_5c5a[local_c]._1 != 0) &&
                (D_ab02[(uint)local_a * 0x20 + (uint)local_8] != 0xff)) &&
                (D_ab02[(uint)local_a * 0x20 + (uint)local_8] != 0x87))
            {
                if ((((D_5c5a[local_c]._0_tile & 0xfc) == 0xe8) || (D_5c5a[local_c]._0_tile == 0x1e)) || (D_5c5a[local_c]._0_tile == 0x1f))
                {
                    // 5503
                    if (D_ab02[(uint)local_a * 0x20 + (uint)local_8] != 0)
                    {
                        D_ac64[(uint)local_a * 0x10 + (uint)local_8] = D_5c5a[local_c]._1;
                        D_ab02[(uint)local_a * 0x20 + (uint)local_8] = 0;
                    }
                }
                else if ((D_5c5a[local_c]._1 == 0x1d) || (D_5c5a[local_c]._1 == 0x1e))
                {
                    D_ac64[(uint)local_a * 0x10 + (uint)local_8] = D_5c5a[local_c]._1;
                    D_ab02[(uint)local_a * 0x20 + (uint)local_8] = 0;
                }
                else
                {
                    if (D_5c5a[local_c]._0_tile == 0x5c)
                    {
                        if (D_ab02[(uint)local_a * 0x20 + (uint)local_8] == 0x92)
                        {
                            D_ac64[(uint)local_a * 0x10 + (uint)local_8] = D_5c5a[local_c]._1;
                            D_ab02[(uint)local_a * 0x20 + (uint)local_8] = 0;
                        }
                        else
                        {
                            FUN_1000_51b8(local_8, local_a, D_5c5a[local_c]._2_x, D_5c5a[local_c]._3_y, D_5c5a[local_c]._1 - 8);
                        }
                    }
                    else
                    {
                        FUN_1000_51b8(local_8, local_a, D_5c5a[local_c]._2_x, D_5c5a[local_c]._3_y, D_5c5a[local_c]._1);
                    }
                }
            }
        }
    } while (--local_c >= 0);
}

// OK P1 (complete)
int FUN_1000_5646(int param_1)
{
    int local1_6;
    int local2_4;

    local1_6 = D_ba14[param_1]._2;
    local2_4 = D_ba14[param_1]._3;

    if ((local1_6 & 0x20) != 0)
    {
        return 0;
    }

    // 566e
    if ((local1_6 & 0x80) != 0)
    {
        if (local2_4 != 0 && D_55a8_party[local2_4]._0[4] == 'j')
        {
            return 1;
        }
        else
        {
            // 568e
            return (local1_6 & 1);
        }
    }
    else
    {
        // 5696
        return !(local1_6 & 1);
    }

    // 56a4
}

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
        local_2 = (uint)D_ba14[D_589e]._6 * 0x10 + 8;
        local_4 = (uint)D_ba14[D_589e]._7 * 0x10 + 8;

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

// NOT MATCHING: di, control flow, ...
void FUN_1000_5a28(int param_1, int param_2_y, int param_3_x, int param_4, int param_5, uint param_6, byte* param_7_map)
{
    register byte* ptr;
    int local_218; // -0x216
    byte local_216;
    int local_214_y; // -0x212; x or y? (y?)
    int local_212_x; // -0x210; x or y? (x?)
    int local_210; // -0x20e
    int local_20e; // -0x20c
    int local_20c; // -0x20a
    int local_20a_y; // -0x208
    int local_208_x; // -0x206
    int _local_206[257]; // -0x204
    int z_local_4z;

    local_20e = 0;
    z_local_4z = 0;
    local_218 = 7;
    local_20c = 1;
    local_210 = 0;

    if (param_1 > 0)
    {
        // 5a57
        if (param_4 == -0x6f)
        {
            param_4 = 0;
            local_210++;
        }

        // 5a66 (OK P1: si vs di)
        param_1++;
        _local_206[z_local_4z] = 5;
        _local_206[++z_local_4z] = 5;
        ++z_local_4z;
        param_7_map[param_4 * 0x20 + param_5 + 0xa5] =
            *FUN_1000_4402_get_address_of_tile_id(param_3_x + (uint)D_589b + 5, param_2_y + (uint)D_589c + 5);

        while (local_20e != z_local_4z)
        {
            // 5abc
            local_20a_y = local_214_y = _local_206[local_20e];
            local_208_x = local_212_x = _local_206[++local_20e];
            ++local_20e;

            while (local_218 > -1) // 5ce5
            {
                // 5aec
                switch (local_218)
                {
                case 0:
                case 1:
                case 7:
                    local_212_x--;
                    break;
                case 4:
                case 5:
                    local_212_x++;
                    break;
                case 2:
                case 3:
                    local_214_y--;
                    break;
                case 6:
                    local_214_y++;
                    break;
                }

                if (local_212_x < 0 || 10 < local_212_x || local_214_y < 0 || 10 < local_214_y)
                {
                    // 5b42
                    local_20c = 0;
                }

                // 5b48
                ptr = &param_7_map[(param_4 + local_214_y) * 0x20 + param_5 + local_212_x];

                // 5b5f
                if (local_210 == 0)
                {
                    // 5b66
                    if ((D_ab02[local_214_y * 0x20 + local_212_x] != 0) && (0x1f >= param_4 + local_214_y))
                    {
                        // 5b83
                        D_ab02[local_214_y * 0x20 + local_212_x] = 0;

                        // -> 5b9b
                    }
                    else
                    {
                        // 5b95
                        local_20c = 0;
                    }
                }
                else
                {
                    // 5b90
                    if (*ptr != 0xff)
                    {
                        // 5b95
                        local_20c = 0;
                    }
                }

                // 5b9b
                if (local_20c != 0)
                {
                    // 5ba5
                    local_216 = *FUN_1000_4402_get_address_of_tile_id(param_3_x + local_212_x + (uint)D_589b, param_2_y + local_214_y + (uint)D_589c);
                    if (FUN_1000_6ff0(local_212_x, local_214_y) >= param_1)
                    {
                        // TODO: control flow position
                        if (local_210) // 5be1 : ??
                        {
                            // 5beb
                            if (FUN_1000_5dfe(local_216, FUN_1000_6ff0(local_212_x, local_214_y)) == 0)
                            {
                                // 5c05
                                if (param_7_map[local_20a_y * 0x20 + local_208_x] == 0 ||
                                    D_ad14[(param_2_y + local_20a_y) * 0x20 + param_3_x + local_208_x] == 0 ||
                                    D_ad14[(param_2_y + local_214_y) * 0x20 + param_3_x + local_212_x] == 0)
                                {
                                    // 5c47
                                    local_216 = *ptr = 0xff;
                                }
                                else
                                {
                                    // 5c93
                                    *ptr = local_216;
                                }
                            }
                            else
                            {
                                // 5c52
                                if (param_2_y + local_214_y < 0 || param_3_x + local_212_x < 0 ||
                                    param_3_x + local_212_x > 0x20 || param_2_y + local_214_y > 0x20)
                                {
                                    // 5c74
                                    *ptr = 0;
                                }
                                else
                                {
                                    // 5c7a
                                    if (D_ad14[(param_2_y + local_214_y) * 0x20 + param_3_x + local_212_x] != 0)
                                    {
                                        // 5c93
                                        *ptr = local_216;
                                    }
                                    else
                                    {
                                        // 5c74
                                        *ptr = 0;
                                    }
                                }
                            }
                        }
                        else
                        {
                            // 5c9c
                            local_216 = 0xff;
                        }
                    }
                    else
                    {
                        // 5c93
                        *ptr = local_216;
                    }

                    // 5ca1
                    if (FUN_1000_5dfe(local_216, FUN_1000_6ff0(local_212_x, local_214_y)) != 0)
                    {
                        _local_206[z_local_4z] = local_214_y;
                        z_local_4z++;
                        _local_206[z_local_4z] = local_212_x;
                        z_local_4z++;
                    }
                }

                // 5cdb
                local_218--;
                local_20c = 1;
            }

            // 5cef
            local_218 = 7;
        }
    }

    // 5d01
}

// OK P1 (complete)
void FUN_1000_5d0a(int param_1, int param_2_x, int param_3_y, int param_4)
{
    int local5_4;
    int local4_6;
    byte* local3_8;
    int local2_a;
    int local1_c;

    for (local2_a = 0; local2_a < 0xb; local2_a++)
    {
        memset(&D_ab02[local2_a * 0x20], 0xff, 0xb);
    }

    local2_a = param_2_x - 5;
    local1_c = param_3_y - 5;

    if (0 < param_1)
    {
        FUN_1000_5a28(param_1, local1_c, local2_a, -111, 0, 0x20, D_ab02);
        local3_8 = D_ab02;

        for (local1_c = 0; local1_c < 0xb; local1_c++)
        {
            for (local2_a = 0; local2_a < 0xb; local2_a++)
            {
                if (*local3_8 == 0)
                {
                    *local3_8 = *local3_8 - 1;
                }

                local3_8++;
            }

            local3_8 = local3_8 + 0x16;
        }
    }

    if (param_1 < 0)
    {
        local5_4 = param_2_x - 5;
        local4_6 = param_3_y - 5;

        for (local1_c = 0; local1_c < 0xb; local1_c++)
        {
            for (local2_a = 0; local2_a < 0xb; local2_a++)
            {
                D_ab02[local2_a + local1_c * 0x20] = *FUN_1000_4402_get_address_of_tile_id(
                    local5_4 + local2_a + (uint)D_589b,
                    local4_6 + local1_c + (uint)D_589c);
            }
        }
    }
}

// OK P1 (optimization)
bool FUN_1000_5dfe(byte param_1, int param_2)
{
    if (param_1 == 'K' || param_1 == 'J' || param_1 == 0xba || param_1 == 0xbb || param_1 == 0x98)
    {
        return param_2 == 1;
    }
    else
    {
        return FUN_1000_0402_memchr(D_6a86, param_1, 0x13) == 0;
    }
}

// OK P1 (stack)
void FUN_1000_5e4a(void)
{
    byte local_92;
    int local_90;
    int local_8e[64];
    int local_e;
    int local_c;
    undefined2 local_a;
    int local_8;
    int local_6;
    u8* local_4;

    local_90 = 0;
    local_4 = D_ad14;

    memset(D_ad14, 0xff, 0x400);

    // 5e72
    for (local_8 = 0; local_8 < 0x20; local_8++)
    {
        for (local_6 = 0; local_6 < 0x20; local_6++)
        {
            // 5e78
            local_92 = *FUN_1000_4402_get_address_of_tile_id(D_589b + local_6, D_589c + local_8);
            if (FUN_1000_0402_memchr(D_6a9a, local_92, 10) != 0)
            {
                // 5eb0
                local_8e[local_90++] = local_8;
                local_8e[local_90++] = local_6;
                *local_4 = local_92;
            }

            // 5ed2
            local_4++;
        }
    }

    local_6 = local_90;
    local_8 = 0;

    // 5ef5
    if (local_90 > 0)
    {
        do
        {
            // 5efe
            local_e = local_8e[local_8++] - 5;
            local_c = local_8e[local_8] - 5;

            // 5f23
            for (local_a = 0; local_a < 0xb; local_a++)
            {
                // 5f29
                memset(&D_ab02[local_a * 0x20], 0xff, 0xb);
            }

            // 5f3f
            FUN_1000_5a28(10, local_e, local_c, local_e, local_c, 0x20, D_ad14);
            local_8++;
        } while (local_8 < local_6);
    }

    // 5f65
    local_4 = D_ad14;

    for (local_6 = 0; local_6 < 0x400; local_6++)
    {
        if (*local_4 == 0xff)
        {
            (*local_4)++;
        }
        local_4++;
    }
}
