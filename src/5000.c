#include "common/common.h"
#include "vars.h"
#include "funcs.h"

#include <string.h>

#include "cmds.h"
#include "combat.h"
#include "dnglook.h"

// OK P1
static int ULTIMA_51a0(void)
{
    if (D_587a == 'T')
    {
        return 0;
    }
    else
    {
        return ULTIMA_2092_RandomRange(0, 3);
    }
}

// NOT MATCHING
static void ULTIMA_51b8(int param_1, undefined2 param_2, int param_3, int param_4, int param_5)
{
    int local_4;

    ASSERT(param_1 >= 0 && param_1 < 32 && param_2 >= 0 && param_2 < 0xb);

    if ((param_5 != 0x1c) &&
        ((((param_5 < 0x12 || (0x16 <= param_5)) && (param_5 < 0x40)) &&
            ((param_5 < 0x28 || (0x2c <= param_5)))))) goto LAB_1000_5370;

    // 51e9
    local_4 = *ULTIMA_4402_GetTileAddr(param_3, param_4);
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
        param_5 = ULTIMA_51a0() + 0x60; // -> 5300
        break;

    case 0x85: // 133
        // 5280
        param_5 = ULTIMA_51a0() + 0x64; // -> 5300
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
        param_5 = ULTIMA_51a0() + 0x3c;
        break;

    case 0x92: // 146
        // 52aa
        if ((*ULTIMA_4402_GetTileAddr(param_3, param_4 + 1) == 0x9a) ||
            (*ULTIMA_4402_GetTileAddr(param_3, param_4 + 1) == 0x9c))
        {
            param_5 = ULTIMA_51a0() + 0x34;
        }
        else
        {
            param_5 = 0x32;
        }
        break;

    case 0x90: // 144
        // 52da
        if ((*ULTIMA_4402_GetTileAddr(param_3, param_4 - 1) == 0x9b) ||
            (*ULTIMA_4402_GetTileAddr(param_3, param_4 - 1) == 0x9c))
        {
            param_5 = ULTIMA_51a0() + 0x38;
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
        if ((*ULTIMA_4402_GetTileAddr(param_3, param_4 - 1) == 0x9d) && (param_2 != 0))
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
void ULTIMA_5394(void)
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
                if (D_ab02[local_e * 0x20 + local_c] == 0xdd &&
                    5 < ULTIMA_6ff0(local_c, local_e))
                {
                    D_ab02[local_e * 0x20 + local_c] = 0x1c;
                }
                else if (D_ab02[local_e * 0x20 + local_c] == 0x1c &&
                    ULTIMA_6ff0(local_c, local_e) <= 5)
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
                local_8 -= D_5896_map_x - 5;
                local_a -= D_5897_map_y - 5;
                if (D_5c5a[local_c]._4_z != D_5895_map_level || 10 < local_8 || 10 < local_a)
                    continue;
            }

            if (D_5c5a[local_c]._1 != 0 &&
                D_ab02[(uint)local_a * 0x20 + (uint)local_8] != 0xff &&
                D_ab02[(uint)local_a * 0x20 + (uint)local_8] != 0x87)
            {
                if ((D_5c5a[local_c]._0_tile & 0xfc) == 0xe8 || D_5c5a[local_c]._0_tile == 0x1e || D_5c5a[local_c]._0_tile == 0x1f)
                {
                    // 5503
                    if (D_ab02[(uint)local_a * 0x20 + (uint)local_8] != 0)
                    {
                        D_ac64[(uint)local_a * 0x10 + (uint)local_8] = D_5c5a[local_c]._1;
                        D_ab02[(uint)local_a * 0x20 + (uint)local_8] = 0;
                    }
                }
                else if (D_5c5a[local_c]._1 == 0x1d || D_5c5a[local_c]._1 == 0x1e)
                {
                    D_ac64[(uint)local_a * 0x10 + (uint)local_8] = D_5c5a[local_c]._1;
                    D_ab02[(uint)local_a * 0x20 + (uint)local_8] = 0;
                }
                else if (D_5c5a[local_c]._0_tile == 0x5c)
                {
                    if (D_ab02[(uint)local_a * 0x20 + (uint)local_8] == 0x92)
                    {
                        D_ac64[(uint)local_a * 0x10 + (uint)local_8] = D_5c5a[local_c]._1;
                        D_ab02[(uint)local_a * 0x20 + (uint)local_8] = 0;
                    }
                    else
                    {
                        ULTIMA_51b8(local_8, local_a, local_4, local_6, D_5c5a[local_c]._1 - 8);
                    }
                }
                else
                {
                    ULTIMA_51b8(local_8, local_a, local_4, local_6, D_5c5a[local_c]._1);
                }
            }
        }
    } while (--local_c >= 0);
}

// OK P1 (complete)
int ULTIMA_5646(int param_1)
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
void ULTIMA_56ac_DrawMap(void)
{
    int local_2;
    int local_4;
    int local_6;
    int local_8;

    for (local_8 = 0; local_8 < 11; local_8++)
    {
        for (local_6 = 0; local_6 < 0xb; local_6++)
        {
            // D_ab02: map data for rendering
            if (D_ab02[local_8 * 0x20 + local_6] == 0)
            {
                // D_ac64: actor map
                if (D_ac64[local_8 * 0x10 + local_6] != 0x16)
                {
                    // draw actor
                    ULTIMA_10e0_GRAP_51_PutTile(0x100 + D_ac64[local_8 * 0x10 + local_6], local_6, local_8);
                }
            }
            else
            {
                if (D_ab02[local_8 * 0x20 + local_6] == 0xdc && D_5887 != 0 && D_5887 < 0x10)
                {
                    // moongate?
                    ULTIMA_1112_GRAP_60(D_5887, local_6, local_8);
                }
                else
                {
                    // draw map tile
                    ULTIMA_10e0_GRAP_51_PutTile(D_b11e[D_ab02[local_8 * 0x20 + local_6]], local_6, local_8);
                }
            }
        }
    }

    if (0x7f < D_5893_map_id && (D_589f = !D_589f) != 0 && D_589e != 0xff && ULTIMA_5646(D_589e) == 0)
    {
        local_2 = (uint)D_ba14[D_589e]._6 * 0x10 + 8;
        local_4 = (uint)D_ba14[D_589e]._7 * 0x10 + 8;

        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);

        for (local_6 = 0; local_6 < 2; local_6++)
        {
            for (local_8 = 0; local_8 < 0xf; local_8 += 0xe)
            {
                ULTIMA_0c9c_GRAP_39_HorizLine(local_2, local_4 + local_6 + local_8, local_2 + 0xf);
                ULTIMA_0cf2_GRAP_3c_VertLine(local_2 + local_6 + local_8, local_4, local_4 + 0xf);
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
                    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
                    ULTIMA_0b10_GRAP_Line(local_8 * 0xb + local_2 + 2, local_6 * 3 + local_4 + 6, local_8 * 3 + local_2 + 6, local_6 * 3 + local_4 + 6);
                    ULTIMA_0f90_GRAP_Pen(local_8 * 3 + local_2 + 6, local_6 * 0xb + local_4 + 2);
                    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
                    ULTIMA_0b10_GRAP_Line(local_8 * 0xb + local_2 + 2, local_6 * 5 + local_4 + 5, local_8 * 5 + local_2 + 5, local_6 * 5 + local_4 + 5);
                    ULTIMA_0f90_GRAP_Pen(local_8 * 5 + local_2 + 5, local_6 * 0xb + local_4 + 2);
                    ULTIMA_0b10_GRAP_Line(local_8 * 0xb + local_2 + 2, local_4 + local_6 + 7, local_8 * 3 + local_2 + 6, local_4 + local_6 + 7);

                    ULTIMA_0b10_GRAP_Line(local_2 + local_8 + 7, local_6 * 3 + local_4 + 6, local_2 + local_8 + 7, local_6 * 0xb + local_4 + 2);
                }
            }
        }
    }
}

// OK P1 (complete)
// Animate / Update
void ULTIMA_5910_UpdateFrame(void)
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
            if (D_5891 != 0xff)
            {
                ULTIMA_4552_AnimateActors();
            }
            ULTIMA_2f62_UpdateWindDirectionRandomly();
            if (D_5893_map_id < 0x80)
            {
                ULTIMA_475a();
                ULTIMA_70a6();
            }
        }

        if (D_5893_map_id < 0x80)
        {
            if (D_24e6 != 0)
            {
                ULTIMA_5d0a(D_58a5, (uint)D_5896_map_x - (uint)D_589b, (uint)D_5897_map_y - (uint)D_589c, 0xb);
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
                                *ULTIMA_4402_GetTileAddr((byte)local_2 + (uint)D_5896_map_x - 5, (byte)local_4 + (uint)D_5897_map_y - 5);
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

        ULTIMA_5394();
        ULTIMA_56ac_DrawMap();
        if (D_5891 != 0)
        {
            ULTIMA_4102_AudioPlayAmbientSfx();
        }
    }

    D_5891 = 1;
}

static bool ULTIMA_5dfe(byte param_1, int param_2);

// NOT MATCHING: di, control flow, ...
static void ULTIMA_5a28(int param_1, int param_2_y, int param_3_x, int param_4, int param_5, uint param_6, byte* param_7_map)
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
            *ULTIMA_4402_GetTileAddr(param_3_x + (uint)D_589b + 5, param_2_y + (uint)D_589c + 5);

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
                    local_216 = *ULTIMA_4402_GetTileAddr(param_3_x + local_212_x + (uint)D_589b, param_2_y + local_214_y + (uint)D_589c);
                    if (ULTIMA_6ff0(local_212_x, local_214_y) >= param_1)
                    {
                        // TODO: control flow position
                        if (local_210) // 5be1 : ??
                        {
                            // 5beb
                            if (ULTIMA_5dfe(local_216, ULTIMA_6ff0(local_212_x, local_214_y)) == 0)
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
                    if (ULTIMA_5dfe(local_216, ULTIMA_6ff0(local_212_x, local_214_y)) != 0)
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
// update map data?
// param_1: light intensity
void ULTIMA_5d0a(int param_1_light, int param_2_x, int param_3_y, int param_4)
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

    if (param_1_light > 0)
    {
        ULTIMA_5a28(param_1_light, local1_c, local2_a, -111, 0, 0x20, D_ab02);
        local3_8 = D_ab02;

        for (local1_c = 0; local1_c < 0xb; local1_c++)
        {
            for (local2_a = 0; local2_a < 0xb; local2_a++)
            {
                if (*local3_8 == 0)
                {
                    (*local3_8)--;
                }

                local3_8++;
            }

            local3_8 += 0x15;
        }
    }

    if (param_1_light < 0)
    {
        local5_4 = param_2_x - 5;
        local4_6 = param_3_y - 5;

        for (local1_c = 0; local1_c < 0xb; local1_c++)
        {
            for (local2_a = 0; local2_a < 0xb; local2_a++)
            {
                D_ab02[local2_a + local1_c * 0x20] = *ULTIMA_4402_GetTileAddr(
                    local5_4 + local2_a + (uint)D_589b,
                    local4_6 + local1_c + (uint)D_589c);
            }
        }
    }
}

// OK P1 (optimization)
static bool ULTIMA_5dfe(byte param_1, int param_2)
{
    if (param_1 == 'K' || param_1 == 'J' || param_1 == 0xba || param_1 == 0xbb || param_1 == 0x98)
    {
        return param_2 == 1;
    }
    else
    {
        return memchr(D_6a86, param_1, 0x13) == 0;
    }
}

// OK P1 (stack)
void ULTIMA_5e4a(void)
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
            local_92 = *ULTIMA_4402_GetTileAddr(D_589b + local_6, D_589c + local_8);
            if (memchr(D_6a9a, local_92, 10) != 0)
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
            ULTIMA_5a28(10, local_e, local_c, local_e, local_c, 0x20, D_ad14);
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

void ULTIMA_6fbc(int param_1);

void ULTIMA_6bc2(int param_1, int param_2);

// NOT MATCHING
void ULTIMA_5f86_SpecialMapHandler(int param_1, int param_2, int param_3)
{
    byte uVar1;
    byte uVar2;
    byte uVar3;
    byte bVar4;
    char cVar5;
    int iVar6;
    int local_6;

    uVar1 = D_5896_map_x;
    uVar2 = D_5897_map_y;
    uVar3 = D_5895_map_level;
    bVar4 = D_587b;

    D_58a1 = param_1;
    D_5894 = D_5893_map_id;
    D_5893_map_id = 0xff;

    for (local_6 = 0; local_6 < 0x20; local_6++)
    {
        memcpy(&D_a9fc[local_6], &D_5c5a[local_6], sizeof(ActorFmt));
    }

    if (param_1 == 0)
    {
        if ((D_5c5a[param_2]._0_tile & 0xfc) == 0x2c)
        {
            local_6 = 0x1;
        }
        else
        {
            local_6 = ((D_5c5a[param_2]._0_tile - 0x40) >> 2);
        }
        if (0x7f < D_5c5a[param_2]._5)
        {
            local_6 += 0x100;
        }
        ULTIMA_6bc2(1, local_6); // ***CONFLICT***
    }
    else if ((param_1 & 4) == 0)
    {
        if ((param_1 & 2) != 0)
        {
            local_6 = 2;
            DNGLOOK_117e(0, 2);
        }
    }
    else
    {
        iVar6 = CMDS_0000(param_1, param_2, param_3);
        local_6 = param_2;
        if (iVar6 == 0)
            goto LAB_1000_606c;
    }

    D_587b = 0xff;
    D_589e = 0xff;
    D_58a3 = 0;
    COMBAT_0b94(); // COMBAT.0b94
LAB_1000_606c:
    if (D_bb16 != 0)
    {
        D_bb16 = 0;
        ULTIMA_6fbc(local_6);
    }

    D_5896_map_x = uVar1;
    D_5897_map_y = uVar2;
    D_5895_map_level = uVar3;
    D_5893_map_id = D_5894;
    D_24e6 = 1;

    ULTIMA_2900_UpdateVitalsDisplay();

    cVar5 = D_55a8_party[bVar4]._b;
    if (cVar5 == 'D' || cVar5 == 'S')
    {
        D_587b = 0xff;
    }
    else
    {
        D_587b = bVar4;
    }

    for (local_6 = 0; local_6 < 0x20; local_6++)
    {
        D_5c5a[local_6]._0_tile = D_a9fc[local_6]._0_tile;
        D_5c5a[local_6]._1 = D_a9fc[local_6]._1;
        D_5c5a[local_6]._2_x = D_a9fc[local_6]._2_x;
        D_5c5a[local_6]._3_y = D_a9fc[local_6]._3_y;
    }
}
