#include "common/common.h"
#include "funcs.h"
#include "vars.h"
#include "macros.h"
#include "tiles.h"

#include "npc.h"
#include "town.h"

static int NPC_032c(int a, int b, int c, int d, int e, int f);
static int NPC_06a0(int param_1, int param_2, int param_3, int param_4);
static int NPC_0adc(int param_1, int param_2, int param_3, int param_4, int param_5);
static int NPC_0b9e(int param_1, int param_2, int param_3, int param_4);

// OK P1
void NPC_0000_LoadNpcFile(void)
{
    int local_4;
    char* local_6;
    byte local_26[32];
    int local_28;

#if !defined(TARGET_DOS16)
    local_6 = NULL;
#endif

    D_5893_map_id--;

    local_4 = (uint)D_5893_map_id >> 3;
    switch (local_4)
    {
    case 0:
        local_6 = /*0x6d46*/ "towne.npc";
        break;
    case 1:
        local_6 = /*0x6d50*/ "dwelling.npc";
        break;
    case 2:
        local_6 = /*0x6d5e*/ "castle.npc";
        break;
    case 3:
        local_6 = /*0x6d6a*/ "keep.npc";
        break;
    }

    local_28 = (uint)D_5893_map_id - (local_4 << 3);

    ULTIMA_256e_ReadFileFromDisk(local_6, D_5d5e, 0x200, local_28 * 0x240);
    ULTIMA_256e_ReadFileFromDisk(local_6, D_659e, 0x20, local_28 * 0x240 + 0x200);
    ULTIMA_256e_ReadFileFromDisk(local_6, local_26, 0x20, local_28 * 0x240 + 0x220);

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        D_5f5e[local_4]._a = (u16)local_26[local_4];
    }

    D_5893_map_id++;
}

// OK P1
void NPC_00d6(int param_1)
{
    int local_4;
    int local_6;

    for (local_4 = 1; local_4 < 0x20; local_4++)
    {
        if (D_659e[local_4] == 0)
        {
            D_5f5e[local_4]._0 = 0;
        }
        else
        {
            local_6 = NPC_12e0(local_4, param_1);
            D_5f5e[local_4]._0 = 1;

            D_5f5e[local_4]._2_x = D_5d5e[local_4].x[local_6];
            D_5f5e[local_4]._4_y = D_5d5e[local_4].y[local_6];
            D_5f5e[local_4]._6_z = D_5d5e[local_4].z[local_6];

            D_5f5e[local_4]._8 = D_659e[local_4];
            D_5f5e[local_4]._e = local_6;
            D_5f5e[local_4]._c = 0;

            D_655e[local_4] = -1;
            D_615e[local_4].data[0] = 0;
            D_65c2[local_4] = 0;
        }
    }
}

// OK P1
static int NPC_01a0(int param_1, int param_2, int param_3, int param_4)
{
    int local_4;

    if (param_3 != 0)
    {
        local_4 = -1;
    }
    else
    {
        local_4 = -2;
    }

    return NPC_032c(param_1, param_2, 0, 0, local_4, param_4);
}

// CHECKED (loop)
static void NPC_01d2(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
{
    int local_a;
    int local_8;
    int local_6;
    byte local_e;
    NpcFmt* local_4;
    ActorFmt* local_c;

    if (param_5 == -1)
    {
        local_e = 0xc8;
    }

    if (param_5 == -2)
    {
        local_e = 0xc9;
    }

    local_a = NPC_12e0(param_6, D_587f);
    for (local_6 = 0; local_6 < 0x20; local_6 = local_6 + 1)
    {
        for (local_8 = 0; local_8 < 0x20; local_8 = local_8 + 1)
        {
            if (NPC_0adc(local_8, local_6, D_5895_map_level, param_6, local_a) != 0)
            {
                D_b11c[local_8 + local_6 * 0x20] = 0;
            }
            else
            {
                D_b11c[local_8 + local_6 * 0x20] = 0x90;
            }

            if (param_5 < 0 && GetMap(local_8, local_6) == local_e)
            {
                D_b11c[local_8 + local_6 * 0x20] = 5;
            }
        }
    }

    // 0272
    local_4 = &D_5f5e[param_6];

    for (local_6 = 0x1f; local_6 > 0; local_6--) // NOT MATCHING
    {
        local_c = &D_5c5a[local_6];
        if (local_c->_0_tile > 0x3f)
        {
            if (NPC_06a0(local_c->_2_x, local_c->_3_y, local_4->_2_x, local_4->_4_y) < 4)
            {
                D_b11c[local_c->_3_y * 0x20 + local_c->_2_x] = 0x90;
            }
        }
    }

    local_c = &D_5c5a[0];
    if (NPC_06a0(local_c->_2_x, local_c->_3_y, local_4->_2_x, local_4->_4_y) < 4)
    {
        D_b11c[local_c->_3_y * 0x20 + local_c->_2_x] = 0x90;
    }

    if (param_5 > -1)
    {
        D_b11c[param_4 * 0x20 + param_3] = 5;
    }

    D_b11c[param_2 * 0x20 + param_1] = 0x46;
}

// CHECKED
static int NPC_032c(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
{
    byte local_50[32];
    byte local_2e[32];
    int local_30;
    int local_e;
    int local_c;
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    local_e = 0;
    local_c = 0;
    local_4 = 1;

    NPC_01d2(param_1, param_2, param_3, param_4, param_5, param_6);

    local_2e[0] = param_1;
    local_50[0] = param_2;

    //while (1)
    do
    {
        if (local_e != 0)
            break;

        local_a = local_2e[local_c];
        local_8 = local_50[local_c];
        local_30 = D_b11c[local_8 * 0x20 + local_a] >> 4;

        for (local_6 = 0; local_6 < 4; local_6++)
        {
            switch (local_30)
            {
            case 1:
                local_a--;
                if (local_a < 0)
                {
                    local_e = 2;
                }
                break;

            case 2:
                local_8++;
                if (local_8 > 0x20)
                {
                    local_e = 2;
                }
                break;

            case 3:
                local_a++;
                if (local_a > 0x20)
                {
                    local_e = 2;
                }
                break;

            case 4:
                local_8--;
                if (local_8 < 0)
                {
                    local_e = 2;
                }
                break;

            default:
                break;
            }

            if (local_e != 2)
            {
                if (D_b11c[local_8 * 0x20 + local_a] < 0x10)
                {
                    local_e = D_b11c[local_8 * 0x20 + local_a] & 0xf;
                    D_b11c[local_8 * 0x20 + local_a] = (byte)(local_30 << 4);
                    if (local_e == 5)
                    {
                        local_e = 1;
                        D_5876 = local_a;
                        D_5878 = local_8;
                        break;
                    }

                    if (local_4 != local_c)
                    {
                        local_2e[local_4] = local_a;
                        local_50[local_4] = local_8;
                        local_4++;
                    }

                    if (local_4 >= 0x20)
                    {
                        local_4 = 0;
                    }
                }
            }

            local_e = 0;
            local_30 = (local_30 & 3) + 1;
            local_a = local_2e[local_c];
            local_8 = local_50[local_c];
        }

        if (local_e == 1)
        {
            return 1;
        }

        local_c++;
        if (local_c == 0x20)
        {
            local_c = 0;
        }

        //if (local_c == local_4)
        //    break;
    } while (local_c != local_4);

    return local_e;
}

// CHECKED
static int NPC_04ac(int param_1, int param_2, int param_3, int param_4)
{
    int local_c;
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    local_6 = 0;
    local_a = 0;

    D_655e[param_1] = 0;

    local_8 = D_b11c[param_4 * 0x20 + param_3] & 0xf;
    local_4 = D_b11c[param_4 * 0x20 + param_3] >> 4;

    local_c = local_4;

    do
    {
        switch (local_4)
        {
        case 1:
            param_3++;
            break;
        case 2:
            param_4--;
            break;
        case 3:
            param_3--;
            break;
        case 4:
            param_4++;
            break;
        }

        if (local_c == local_4 && local_8 != 6)
        {
            local_6++;
        }

        if (local_c != local_4 || local_8 == 6)
        {
            D_615e[param_1].data[local_a] = local_6;
            local_a++;
            D_615e[param_1].data[local_a] = local_c;
            local_a++;

            if (local_8 == 6)
                break;

            local_c = local_4;
            local_6 = 1;
        }

        local_4 = D_b11c[param_4 * 0x20 + param_3] >> 4;
        local_8 = D_b11c[param_4 * 0x20 + param_3] & 0xf;
    } while (local_a < 0x20);

    local_8 = local_a - 2;

    if (local_8 >= 0)
    {
        local_6 = 0;
        do
        {
            // swap
            local_c = D_615e[param_1].data[local_6];
            D_615e[param_1].data[local_6] = D_615e[param_1].data[local_8];
            D_615e[param_1].data[local_8] = local_c;

            local_8++;
            local_6++;

            // swap*
            local_c = (D_615e[param_1].data[local_6] + 1 & 3) + 1;
            D_615e[param_1].data[local_6] = (D_615e[param_1].data[local_8] + 1 & 3) + 1;
            D_615e[param_1].data[local_8] = local_c;

            local_6++;
            local_8 -= 3;
        } while (local_8 >= local_6);
    }

    return local_a;
}

// OK P1
// set walk direction
static void NPC_0632(int param_1)
{
    switch (param_1)
    {
    case 1:
        D_5876++;
        if (D_5878 > 0x20)
        {
            D_5876 = 0x20;
        }
        break;

    case 2:
        D_5878--;
        if (D_5876 < 0)
        {
            D_5878 = 0;
        }
        break;

    case 3:
        D_5876--;
        if (D_5878 < 0)
        {
            D_5876 = 0;
        }
        break;

    case 4:
        D_5878++;
        if (D_5876 > 0x20)
        {
            D_5878 = 0x20;
        }
        break;
    }
}

// OK P1
// Calculate manhattan distance
static int NPC_06a0(int param_1, int param_2, int param_3, int param_4)
{
    int local_6;
    int local_4;

    local_4 = param_1 - param_3;
    local_6 = param_2 - param_4;

    if (local_4 < 0)
    {
        local_4 = -local_4;
    }

    if (local_6 < 0)
    {
        local_6 = -local_6;
    }

    local_4 += local_6;
    return local_4;
}

// CHECKED
static void NPC_06e4(int param_1, int param_2)
{
    int local_4;
    int local_6;
    NpcFmt* local_8;
    int local_10[4];
    int local_12;
    int local_14;
    int local_16;
    ActorFmt* local_18;
    int local_1a;
    int local_1c;

    CHECK_PARAM_RANGE(param_1, 0, 32);
    CHECK_PARAM_RANGE(param_2, 0, 3);

    local_18 = &D_5c5a[0];
    local_8 = &D_5f5e[param_1];
    local_4 = D_5d5e[param_1].type[param_2];
    local_6 = NPC_06a0(D_5c5a[0]._2_x, D_5c5a[0]._3_y, local_8->_2_x, local_8->_4_y);
    if (local_6 == 1 && local_4 > 3)
    {
        if (local_4 == 4 || local_4 == 5)
        {
            // a9cd
            if (local_8->_a != 0)
            {
                // a9d6
                D_65be = 0x74;
                // a9db
                D_65bf = param_1;
                local_4 = 1;
            }
        }
        else
        {
            // aa4e: ??
            D_65be = 0x61;
            // -> a9db
            D_65bf = param_1;
            local_4 = 1;
        }
    }
    else
    {
        // a9ea
        for (local_16 = 1; local_16 < 5; local_16++)
        {
            // aa09
            D_5876 = local_8->_2_x;
            D_5878 = local_8->_4_y;
            NPC_0632(local_16);
            local_12 = D_5876;
            local_14 = D_5878;
            if (NPC_0b9e(D_5876, D_5878, param_1, -1) != 0)
            {
                local_10[local_16 - 1] = NPC_06a0(local_18->_2_x, local_18->_3_y, local_12, local_14);
            }
            else
            {
                // aa56 (OK)
                local_10[local_16 - 1] = 99;
            }
        }

        // aa6a (OK)
        local_1a = -1; // di
        local_6 = NPC_06a0(local_18->_2_x, local_18->_3_y, local_8->_2_x, local_8->_4_y);
        // aa8c
        for (local_16 = 1; local_16 < 8; local_16++)
        {
            // aaa7
            if (local_16 < 5 && local_10[local_16 - 1] != 99)
            {
                if (local_4 == 3)
                {
                    if (local_6 < local_10[local_16 - 1])
                    {
                        if (local_1a == -1 || ULTIMA_2092_RandomRange(0, 1) != 0)
                        {
                            local_1a = local_16;
                        }

                        if (local_16 == 4)
                            break;
                    }
                }
                else
                {
                    // ab14
                    if (local_10[local_16 - 1] < local_6)
                    {
                        local_1a = local_16;
                        break;
                    }
                }
            }

#if defined(TARGET_DOS16)
            // aae4 (OK)
            if (local_16 > 4 && local_10[local_16 - 1] != 99) // BUG? (OOB, invalid index)
#else
            if (local_16 > 4 && local_10[local_16 - 5] != 99) // BUGFIX?
#endif
            {
                if (local_10[local_16 - 5] == local_6)
                {
                    local_1a = local_16;
                    break;
                }
            }
        }

        // ab22 (OK below)
        if ((local_4 == 5 || local_4 == 7) && ULTIMA_2092_RandomRange(0, 0x3f) < 0x10)
        {
            // ab3d
            local_1c = local_1a;
            for (local_16 = 1; local_16 < 5; local_16++)
            {
                // ab4b
                if (local_1a != local_16 && local_10[local_16 - 1] != 99 &&
                    (local_1c == local_1a || ULTIMA_2092_RandomRange(0, 0x3f) < 0x10))
                {
                    local_1c = local_16;
                }
            }
            local_1a = local_1c;
        }

        if (local_1a > -1)
        {
            D_5876 = local_8->_2_x;
            D_5878 = local_8->_4_y;
            NPC_0632(local_1a);

            D_5c5a[local_8->_c]._2_x = local_8->_2_x = D_5876;
            D_5c5a[local_8->_c]._3_y = local_8->_4_y = D_5878;
            D_24e6 |= 2;
        }
    }
}

// CHECKED
static int NPC_0938(int param_1, int param_2)
{
    NpcFmt* local_8;
    int local_a;
    int local_6;
    NpcScheduleFmt* local_4;

    local_a = -1;
    local_8 = &D_5f5e[param_1];
    local_4 = &D_5d5e[param_1];

    for (local_6 = 0; local_6 < 4; local_6++)
    {
        if (local_4->time[local_6] == param_2)
        {
            local_a = NPC_12e0(param_1, param_2);
            if (local_a == local_8->_e) // NOT MATCHING: di vs ax
            {
                local_8->_0 = 1;
                break;
            }

            if (local_8->_6_z != D_5895_map_level && local_4->z[local_a] != D_5895_map_level)
            {
                local_8->_0 = 8;
            }
            else
            {
                if (local_8->_6_z == D_5895_map_level)
                {
                    if (local_4->z[local_a] == D_5895_map_level)
                    {
                        local_8->_0 = 2;
                    }
                    else if ((char)D_5895_map_level < (char)local_4->z[local_a])
                    {
                        local_8->_0 = 6;
                    }
                    else
                    {
                        local_8->_0 = 7;
                    }
                }
                else if ((char)D_5895_map_level < (char)local_8->_6_z)
                {
                    local_8->_0 = 4;
                }
                else
                {
                    local_8->_0 = 5;
                }
            }
            break;
        }
    }

    // ac1b
    if (-1 < local_a && local_8->_2_x == (uint)local_4->x[local_a] &&
        local_8->_4_y == (uint)local_4->y[local_a] &&
        local_8->_6_z == (uint)local_4->z[local_a])
    {
        local_a = 0;
        local_8->_0 = 1;
    }

    if (local_a == -1)
    {
        local_a = 0;
    }
    else
    {
        local_a++;
    }

    return local_a;
}

// OK P1
static int NPC_0a4a(int param_1, int param_2)
{
    byte local_8;
    int local_6;
    NpcFmt* local_4;

    local_4 = &D_5f5e[param_1];

    // 0a4a
    local_8 = *ULTIMA_4402_GetTileAddr(D_5c5a[local_4->_c]._2_x, D_5c5a[local_4->_c]._3_y);
    if ((char)D_5d5e[param_1].z[param_2] < (char)D_5895_map_level)
    {
        if (local_8 != TILE_MAP_LADDER_DOWN)
        {
            // 0a92
            if ((local_8 & 0xf4) == TILE_MAP_STAIR)
            {
                local_6 = 1;
            }
            else
            {
                local_6 = 0;
            }
        }
        else
        {
            // 0a9b
            local_6 = 1;
        }
    }
    else
    {
        // 0aa2
        local_8 = *ULTIMA_4402_GetTileAddr(D_5c5a[local_4->_c]._2_x, D_5c5a[local_4->_c]._3_y);
        if (local_8 == TILE_MAP_LADDER_UP)
        {
            // -> 0a9b
            local_6 = 1;
        }
        else
        {
            if ((local_8 & 0xf4) == TILE_MAP_STAIR)
            {
                local_6 = 1;
            }
            else
            {
                local_6 = 0;
            }
        }
    }

    return local_6;
}

// OK P1
static int NPC_0adc(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    byte local_8;
    int local_6;
    NpcScheduleFmt* local_4;

    local_6 = 0;
    local_4 = &D_5d5e[param_4];

    if (param_5 > -1 && local_4->x[param_5] == param_1 && local_4->y[param_5] == param_2 && local_4->z[param_5] == param_3)
    {
        local_6 = 2;
    }
    else
    {
        if (param_1 < 0 || param_2 < 0 || 0x1f < param_1 || 0x1f < param_2)
        {
            local_8 = D_6a07;
        }
        else
        {
            local_8 = GetMap(param_1, param_2);
        }

        if (D_5f5e[param_4]._0 == 3 && (local_8 == TILE_MAP_LADDER_UP || local_8 == TILE_MAP_LADDER_DOWN))
        {
            local_6 = 1;
        }
        else
        {
            local_6 = ((uint)D_367e[local_8 >> 3] & 0x80 >> (local_8 & 7)) == 0;
        }
    }

    return local_6;
}

// OK P1
static int NPC_0b9e(int param_1, int param_2, int param_3, int param_4)
{
    int local_8;
    int local_6;
    int local_4;

    local_6 = 0;
    if (param_1 < 0 || param_1 > 0x1f || param_2 < 0 || param_2 > 0x1f)
    {
        return 0;
    }

    local_8 = *ULTIMA_4402_GetTileAddr(param_1, param_2) & 0xfc;
    if (D_659e[param_3] == 0xfc)
    {
        local_4 = 1;
    }
    else if (local_8 == TILE_MAP_30)
    {
        local_4 = 1;
    }
    else if (local_8 == TILE_MAP_CHAIR_90 && D_5f5e[param_3]._0 != 2)
    {
        local_4 = 0;
    }
    else
    {
        local_4 = NPC_0adc(param_1, param_2, D_5895_map_level, param_3, param_4);
    }

    local_6 = ULTIMA_3702(param_1, param_2, D_5895_map_level);
    if (local_4 == 0 || local_6 != 0)
    {
        local_4 = 0;
    }

    return local_4;
}

// OK P1
// move npc randomly
static void NPC_0c50(NpcFmt* param_1, int param_2, int param_3, int param_4, NpcScheduleFmt* param_5)
{
    int local_8;
    int local_6;
    int local_4;

    if ((ULTIMA_2092_RandomRange(0, 0xff) & 8) != 0)
    {
        local_4 = ULTIMA_3aae_Random(0x40);
        local_4 = (local_4 & 3) + 1;
        D_5876 = param_1->_2_x;
        D_5878 = param_1->_4_y;
        NPC_0632(local_4);
        local_6 = D_5876;
        local_8 = D_5878;

        if ((param_2 == 0 || NPC_06a0(param_5->x[param_3], param_5->y[param_3], D_5876, D_5878) <= param_2) &&
            NPC_0b9e(D_5876, D_5878, param_4, param_3) != 0)
        {
            D_5c5a[param_1->_c]._2_x = param_1->_2_x = local_6;
            D_5c5a[param_1->_c]._3_y = param_1->_4_y = local_8;

            D_24e6 |= 2;
        }
    }
}

// CHECKED (switch order)
static void NPC_0d00(int param_1, int param_2)
{
    NpcFmt* local_4;
    NpcScheduleFmt* local_6;

    local_4 = &D_5f5e[param_1];
    local_6 = &D_5d5e[param_1];

    switch (local_6->type[param_2])
    {
    case 0:
        break;

    case 2:
        NPC_0c50(local_4, 0, param_2, param_1, local_6);
        break;

    case 4:
        if (NPC_06a0(D_5896_map_x, D_5897_map_y, local_6->x[param_2], local_6->y[param_2]) < 4)
        {
            NPC_06e4(param_1, param_2);
        }

        break;

    case 1:
        NPC_0c50(local_4, 3, param_2, param_1, local_6);
        break;

    case 3:
    case 6:
        if (NPC_06a0(D_5896_map_x, D_5897_map_y, local_4->_2_x, local_4->_4_y) < 4)
        {
            NPC_06e4(param_1, param_2);
        }

        break;

    case 5:
    case 7:
        NPC_06e4(param_1, param_2);
        break;
    }
}

// NOT MATCHING (checked)
// move npc
void NPC_0db4(int param_1)
{
    byte local_12;
    int local_10;
    int local_e;
    int local_14;
    int local_c;
    int local_a;
    int local_6;
    int local_4;
    NpcFmt* local_8;

    local_14 = 0;
    D_65be = 0;
    D_65bf = 0;

    // 0dd9
    for (local_4 = 1; /*1267*/ local_4 < 0x20; /*1264*/ local_4++)
    {
        // 126d
        if (D_659e[local_4] == 0)
            continue;

        // 1277
        local_e = NPC_12e0(local_4, param_1);
        // 1281
        local_8 = &D_5f5e[local_4];

        // 128e
        if (local_8->_0 <= 1 && NPC_0938(local_4, param_1) == 0)
        {
            // 124e
            if (local_8->_6_z == D_5895_map_level)
            {
                // 1261
                NPC_0d00(local_4, local_e);
            }
        }
        // 12a2
        else if (local_8->_0 > 3)
        {
            if (local_8->_0 == 4 || local_8->_0 == 5)
            {
                // 12bc
                if (local_14 != 1)
                {
                    local_14 = 1;
                    if (local_8->_0 == 4)
                    {
                        // 12cf
                        local_6 = 3;
                        // -> 0dd9
                    }
                    else
                    {
                        // 0dd4
                        local_6 = 4;
                    }

                    // 0dd9 (ok)
                    local_10 =
                        NPC_01a0(D_5d5e[local_4].x[local_e], D_5d5e[local_4].y[local_e], local_6 == 3, local_4);
                    if (local_10 != 0)
                    {
                        local_a = D_5876;
                        local_c = D_5878;
                        local_10 = NPC_032c(local_a, local_c, D_5d5e[local_4].x[local_e],
                                            D_5d5e[local_4].y[local_e], local_6, local_4);
                    }

                    // 0e32 (ok)
                    if (local_10 != 0)
                    {
                        // 0e3b (ok)
                        NPC_04ac(local_4, local_6, D_5d5e[local_4].x[local_e], D_5d5e[local_4].y[local_e]);

                        // 0e5a (ok)
                        local_12 = GetMap(local_a, local_c);
                        if (/*0e6b*/ (local_6 == 3 && local_12 == TILE_MAP_LADDER_UP) ||
                            /*0e75*/ (local_6 == 4 && local_12 == TILE_MAP_LADDER_DOWN) ||
                            /*0e81*/ (local_12 & 0xfc) == TILE_MAP_STAIR)
                        {
                            // 0e8a (ok)
                            TOWN_1726(local_4, local_a, local_c, D_5895_map_level);
                        }

                        // 0e9c (ok)
                        local_8->_0 = 2;
                    }
                }
            }
            else if (local_8->_0 == 6 || local_8->_0 == 7)
            {
                // 0eb2
                if (NPC_0a4a(local_4, local_e) != 0)
                {
                    // 0ebf
                    TOWN_1726(local_4, D_5d5e[local_4].x[local_e], D_5d5e[local_4].y[local_e],
                              D_5d5e[local_4].z[local_e]);

                    local_8->_e = local_e;
                    D_655e[local_4] = -1;
                    local_8->_0 = 1;
                }
                else
                {
                    // 0efe
                    if (local_8->_0 != 2 && local_14 != 1)
                    {
                        local_14 = 1;
                        if (local_8->_0 == 6)
                        {
                            local_6 = 1;
                        }
                        else
                        {
                            local_6 = 2;
                        }
                        // 0f2b
                        local_10 = NPC_01a0(local_8->_2_x, local_8->_4_y, local_6 == 1, local_4);
                        if (local_10 != 0)
                        {
                            local_a = D_5876;
                            local_c = D_5878;
                            local_10 = NPC_032c(local_8->_2_x, local_8->_4_y, local_a, local_c, local_6, local_4);
                        }
                        // 0f71
                        if (local_10 != 0)
                        {
                            // 0f7a
                            NPC_04ac(local_4, local_6, local_a, local_c);
                            local_8->_0 = 3;
                        }
                    }
                }
            }
        }
        else
        {
            // 0f94
            if (D_655e[local_4] > -1 && D_615e[local_4].data[D_655e[local_4]] != 0)
            {
                // 0fb8
                D_5876 = local_8->_2_x;
                D_5878 = local_8->_4_y;
                NPC_0632(D_615e[local_4].data[D_655e[local_4] + 1]);
                local_a = D_5876;
                local_c = D_5878;
                local_10 = NPC_0b9e(D_5876, local_c, local_4, local_e);
                if (local_10 != 0)
                {
                    // 0ff9
                    D_5c5a[local_8->_c]._2_x = (u8)local_a;
                    local_8->_2_x = local_a & 0xff;
                    D_5c5a[local_8->_c]._3_y = (u8)local_c;
                    local_8->_4_y = local_c & 0xff;
                    D_24e6 |= 2;

                    D_615e[local_4].data[D_655e[local_4]]--;
                    D_65c2[local_4] = 0;
                    if (D_615e[local_4].data[D_655e[local_4]] == 0)
                    {
                        // 104a
                        D_655e[local_4]++;
                        D_615e[local_4].data[D_655e[local_4]++] = 0;
                        if (D_655e[local_4] >= 0x20 || D_615e[local_4].data[D_655e[local_4]] < 1)
                        {
                            D_655e[local_4] = -1;
                        }

                        if (local_10 == 2)
                        {
                            // 1083
                            local_8->_e = local_e;
                            local_8->_0 = 1;
                            D_655e[local_4] = -1;
                        }
                    }
                }
                else
                {
                    D_65c2[local_4]++;
                    NPC_0c50(&D_5f5e[local_4], 0, local_e, local_4, &D_5d5e[local_4]);
                    if (D_65c2[local_4] > 3)
                    {
                        // 10d0
                        D_655e[local_4] = -1;
                        // 10d6
                        D_65c2[local_4] = 0;
                    }
                }
            }
            else
            {
                // 10e0
                if (D_655e[local_4] == -1 && local_8->_0 == 3)
                {
                    local_e = NPC_12e0(local_4, param_1);
                    if (D_5895_map_level < D_5d5e[local_4].z[local_e])
                    {
                        local_8->_0 = 6;
                        return; // 12d8
                    }
                    local_8->_0 = 7;
                    return; // 12d8
                }

                // 1124
                if (local_14 < 1)
                {
                    // 112d
                    if (local_8->_0 != 1)
                    {
                        // 1138
                        if (D_65c2[local_4] < 200 && (D_65c2[local_4] == 0 || ULTIMA_2092_RandomRange(0, 2) == 1))
                        {
                            // 1160
                            if (D_655e[local_4] == -1)
                            {
                                local_14 = local_14 + 1;
                                if (NPC_032c(local_8->_2_x, local_8->_4_y, D_5d5e[local_4].x[local_e],
                                             D_5d5e[local_4].y[local_e], 0, local_4) != 0)
                                {
                                    NPC_04ac(local_4, 0, D_5d5e[local_4].x[local_e],
                                             D_5d5e[local_4].y[local_e]);

                                    D_65c2[local_4] = 0;
                                    continue;
                                }
                                // 11ba
                                D_65c2[local_4] = 200;
                            }

                            // 11c5
                            NPC_0c50(local_8, 0, local_e, local_4, &D_5d5e[local_4]);
                        }
                        else
                        {
                            // 11e8
                            if (D_65c2[local_4] >= 200)
                            {
                                D_65c2[local_4]++;
                            }

                            // 11f9
                            if (D_65c2[local_4] > 204)
                            {
                                D_65c2[local_4] = 0;
                            }
                        }
                    }
                }
                // 120e
                else if (local_8->_6_z == (uint)D_5895_map_level)
                {
                    // 1243 -> 1261
                    NPC_0d00(local_4, local_8->_e);
                }
                else if (local_e == 1 || local_e == 2)
                {
                    // 1227
                    local_10 = 0;
                    // -> 1243
                    NPC_0d00(local_4, local_8->_e);
                }
                else if (local_e == 0)
                {
                    local_10 = 2;
                    // -> 1243
                    NPC_0d00(local_4, local_8->_e);
                }
                else
                {
                    // 123c
                    local_10 = local_e - 1;
                    // 1243
                    NPC_0d00(local_4, local_8->_e);
                }
                // 1264
            }
        }
    }

    // 12d8
}

// CHECKED (asm)
// use literal conversion from FMT
int NPC_12e0(int param_1, char param_2)
{
    int i;
    int ret;
    byte local_8[4];

    for (i = 0; i < 4; i++)
    {
        local_8[i] = param_2 - D_5d5e[param_1].time[i];
    }

    ret = 0;
    if (local_8[1] < local_8[0])
    {
        local_8[0] = local_8[1];
        ret = 1;
    }

    if (local_8[2] < local_8[0])
    {
        local_8[0] = local_8[2];
        ret = 2;
    }

    if (local_8[3] < local_8[0])
    {
        ret = 1;
    }

    return ret;
}
