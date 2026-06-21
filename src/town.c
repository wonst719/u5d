#include "common/common.h"
#include "vars.h"
#include "funcs.h"
#include "macros.h"
#include "tiles.h"

#include <memory.h>

#include "audio/aud_mus.h"

#include "blckthrn.h"
#include "cast2.h"
#include "npc.h"
#include "talk.h"
#include "town.h"

// OK P1
// check npc killed flag
int TOWN_0000_CheckNpcKilled(int param_1)
{
    if (D_659e[param_1] == TILE_ACTOR_SANDALWOOD_BOX || D_659e[param_1] >= TILE_ACTOR_WIZARD)
    {
        return ((*(u32*)&D_5b5a[(D_5893_map_id - 1) * 4]) & ((u32)1 << (byte)param_1)) != 0;
    }

    return 0;
}

// OK P1
// 0052: set killed
void TOWN_0052_SetNpcKilled(int param_1)
{
    int local_4;

    if (param_1 < 0 || param_1 > 0x1f)
        return;

    local_4 = D_659e[param_1] & 0xfc;

    if ((local_4 != TILE_ACTOR_GUARD && local_4 < TILE_ACTOR_80) || local_4 == TILE_ACTOR_SHARD)
    {
        // 0084
        (*(u32*)&D_5b5a[(D_5893_map_id - 1) * 4]) |= ((u32)1 << (byte)param_1);
    }
}

// OK P1
// despawn npc
void TOWN_00b0_DespawnNpc(int param_1)
{
    ActorFmt* actor = &D_5c5a[D_5f5e[param_1]._c];

    actor->_0_tile = actor->_1_animTile = actor->_2_x = actor->_3_y = actor->_4_z = actor->_6 = actor->_7 = D_5f5e[param_1]._0 =
        D_5f5e[param_1]._2_x = D_5f5e[param_1]._4_y = D_5f5e[param_1]._6_z = D_5f5e[param_1]._a = 0;
    D_5d5e[param_1].type[0] = D_5d5e[param_1].type[1] = D_5d5e[param_1].type[2] = 0;
    D_659e[param_1] = 0;
    D_24e6 |= 2;
}

// OK P1
int TOWN_011e(int param_1)
{
    int local_4;
    int local_2 = -1;

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        if (D_5f5e[local_4]._c == param_1 && D_659e[local_4] != 0 && D_5f5e[local_4]._0 != 0)
        {
            local_2 = local_4;
            break;
        }
    }

    return local_2;
}

// OK P1
void TOWN_0170(void)
{
    int local_4;
    int local_6;

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        for (local_6 = 0; local_6 < 0x20; local_6++)
        {
            if (*ULTIMA_4402_GetTileAddr(local_4, local_6) == TILE_MAP_87)
            {
                *ULTIMA_4402_GetTileAddr(local_4, local_6 + 1) ^= TILE_MAP_DD;
            }
        }
    }

    if ((*ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y) & 0xfe) != TILE_MAP_48)
    {
        for (local_4 = 0; local_4 < D_594e; local_4++)
        {
            if (D_587f == 5)
            {
                *ULTIMA_4402_GetTileAddr(D_58ee[local_4], D_590e[local_4]) = D_592e[local_4];
            }
            else
            {
                *ULTIMA_4402_GetTileAddr(D_58ee[local_4], D_590e[local_4]) = TILE_MAP_WATER_3;
            }
        }
    }

    D_24e6 |= 2;
}

// OK P1
static void TOWN_0212(void)
{
    int local_4;
    int local_6;

    if (D_5958 != 0xff)
    {
        ULTIMA_207e_srand(D_587e);

        for (local_6 = 0; local_6 < 0x20; local_6++)
        {
            for (local_4 = 0; local_4 < 0x20; local_4++)
            {
                switch (GetMap(local_4, local_6))
                {
                case TILE_MAP_TREE:
                    if (ULTIMA_2092_RandomRange(0, 7) != 0)
                    {
                        GetMap(local_4, local_6) = TILE_MAP_STUMP;
                    }
                    break;
                case TILE_MAP_CROPS:
                    if (ULTIMA_2092_RandomRange(0, 7) != 0)
                    {
                        GetMap(local_4, local_6) = TILE_MAP_CROPS_PICKED;
                    }
                    break;
                }
            }
        }

        D_24e6 |= 2;

        ULTIMA_207e_srand(ULTIMA_2056_GetTime());
    }
}

// OK P1
// setup shadowlord
static void TOWN_02ae(void)
{
    int local_a;
    int local_4;
    int local_8;
    ActorFmt* local_6;

    D_5958 = 0xff;
    if (D_5897_map_y != 4)
    {
        for (local_8 = 0; local_8 < 3; local_8++)
        {
            if (D_58c8[local_8] == D_5893_map_id)
            {
                D_5958 = local_8;
                break;
            }
        }
    }

    if (D_5958 != 0xff)
    {
        // Setup shadow lord
        TOWN_0212();
        for (local_8 = 0; local_8 < 0x20; local_8++)
        {
            if (D_5c5a[local_8]._0_tile == TILE_ACTOR_SHADOWLORD)
            {
                return;
            }
        }

        local_a = ULTIMA_38e4();

        local_6 = &D_5c5a[local_a];

        local_4 = 0x1f;
        for (local_8 = 0x1f; local_8 >= 0; local_8--)
        {
            if (D_659e[local_8] == 0)
            {
                local_4 = local_8;
                break;
            }
        }

        ASSERT(D_5893_map_id > 0 && D_5893_map_id <= 8);

        D_5f5e[local_4]._0 = 1;
        D_5f5e[local_4]._c = local_a;
        
        D_5f5e[local_4]._2_x = local_6->_2_x = 0xf;
        D_5f5e[local_4]._4_y = local_6->_3_y = D_13a6[D_5893_map_id - 1];
        D_5f5e[local_4]._6_z = local_6->_6 = local_6->_5 = local_6->_4_z = local_6->_7 = 0;
        local_6->_0_tile = local_6->_1_animTile = TILE_ACTOR_SHADOWLORD;

        for (local_8 = 0; local_8 < 4; local_8++)
        {
            // npc time
            D_5d5e[local_4].time[local_8] = 0;
        }

        for (local_8 = 0; local_8 < 3; local_8++)
        {
            // setup npc schedules
            D_5d5e[local_4].type[local_8] = 6;
            D_5d5e[local_4].x[local_8] = 0xf;
            D_5d5e[local_4].y[local_8] = local_6->_3_y;
            D_5d5e[local_4].z[local_8] = 0;
        }

        D_659e[local_4] = 0xfc;
    }
}

// OK P1
static void TOWN_0408(int param_1)
{
    char* local_2;
    int local_8;
    int local_4;
    undefined2 local_6;

    ULTIMA_4be8();
    ULTIMA_4a84();
    ULTIMA_2e96_SetWindDirection(-1);

    D_594f = 0;
    D_589b = D_589c = 0;

    local_2 = D_2652[(D_5893_map_id - 1) >> 3];
    local_6 = (uint)D_1e19[D_5893_map_id] + (uint)D_5895_map_level;
    if (D_5895_map_level > 0x7f)
    {
        local_6 -= 0x100;
    }

    ULTIMA_256e_ReadFileFromDisk(local_2, D_6608, 0x400, local_6 << 10);

    D_594e = 0;
    D_217e = D_2180 = D_2182 = D_2184 = -1;

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        for (local_8 = 0; local_8 < 0x20; local_8++)
        {
            if ((*ULTIMA_4402_GetTileAddr(local_4, local_8) & 0xfe) == TILE_MAP_48)
            {
                D_58ee[D_594e] = (char)local_4;
                D_590e[D_594e] = (char)local_8;
                D_592e[D_594e] = *ULTIMA_4402_GetTileAddr(local_4, local_8);
                D_594e++;
            }
            if (*ULTIMA_4402_GetTileAddr(local_4, local_8) == TILE_MAP_2A)
            {
                if (D_217e == -1)
                {
                    D_217e = local_4;
                    D_2180 = local_8;
                }
                else
                {
                    D_2182 = local_4;
                    D_2184 = local_8;
                }
            }
        }
    }

    if (D_587f < 5 || D_587f > 0x13)
    {
        TOWN_0170();
    }

    ULTIMA_5e4a();
    ULTIMA_4f7c(0);
    TOWN_0212();

    if (param_1 != 0)
    {
        TOWN_1694();
    }

    D_24e6 = 1;
}

// OK P1 (complete)
static void TOWN_052e(int param_1, int param_2)
{
    if ((param_2 & 0xfc) == TILE_MAP_STAIR)
    {
        ULTIMA_5910_UpdateFrame();
        if (param_2 - TILE_MAP_STAIR == param_1)
        {
            D_5895_map_level++;
            ULTIMA_1850_PrintString(_TEXT(0x265a, "Up!\n"));
        }
        else if (param_2 - TILE_MAP_STAIR == (param_1 ^ 2))
        {
            D_5895_map_level--;
            ULTIMA_1850_PrintString(_TEXT(0x265f, "Down!\n"));
        }
        else
        {
            return;
        }

        TOWN_0408(1);
    }
}

// OK P1 (complete)
// select party icon
// 0: up, 1: right, 2: down, 3: left
static void TOWN_057c(int param_1)
{
    switch (D_587c_partyTile & 0xfc)
    {
    case TILE_ACTOR_HORSE:
        ULTIMA_1850_PrintString(_TEXT(0x2666, "Ride "));
        if (param_1 == 1)
        {
            D_587c_partyTile = TILE_ACTOR_RIDING_HORSE;
        }
        else if (param_1 == 3)
        {
            D_587c_partyTile = TILE_ACTOR_RIDING_HORSE + 1;
        }
        break;

    case TILE_ACTOR_FLYING_CARPET:
        ULTIMA_1850_PrintString(_TEXT(0x266c, "Fly "));
        if (param_1 == 1)
        {
            D_587c_partyTile = TILE_ACTOR_FLYING_CARPET;
        }
        else if (param_1 == 3)
        {
            D_587c_partyTile = TILE_ACTOR_FLYING_CARPET + 1;
        }
        break;

    case TILE_ACTOR_SKIFF:
        ULTIMA_1850_PrintString(_TEXT(0x2671, "Row "));
        // fall-through

    case TILE_ACTOR_FRIGATE_20:
    case TILE_ACTOR_FRIGATE_24:
        D_587c_partyTile = (char)param_1 + (D_587c_partyTile & 0xfc);
        break;
    }
}

// CHECKED
// move
// return: exit from the map?
static bool TOWN_0600(int param_1)
{
    int local_4;
    bool local_6;
    bool local_8; // reached the end of the map?
    int local_a;
    int local_c;
    int local_e;
    undefined2 local_10;

    if (D_587c_partyTile == TILE_ACTOR_AVATAR || (D_587c_partyTile & 0xfe) == TILE_ACTOR_RIDING_HORSE)
    {
        ULTIMA_433e_AudioFootstep();
    }

    local_c = local_e = local_8 = 0;

    switch (param_1)
    {
    case DIR_UP:
        // 0648
        local_e--;
        if (D_5897_map_y < 1)
            local_8 = 1;
        // 0657
        param_1 = 0;
        TOWN_057c(0);
        ULTIMA_1850_PrintString(_TEXT(0x2676, "North\n"));
        break;

    case DIR_DOWN:
        // 06f8
        local_e++;
        if (D_5897_map_y > 0x1e)
            local_8 = 1;
        param_1 = 2;
        TOWN_057c(2);
        ULTIMA_1850_PrintString(_TEXT(0x267d, "South\n"));
        break;

    case DIR_RIGHT:
        // 071a
        local_c++;
        if (0x1e < D_5896_map_x)
            local_8 = 1;
        param_1 = 1;
        TOWN_057c(1);
        ULTIMA_1850_PrintString(_TEXT(0x2684, "East\n"));
        break;

    case DIR_LEFT:
        // 073c
        local_c--;
        if (D_5896_map_x < 1)
            local_8 = 1;
        param_1 = 3;
        TOWN_057c(3);
        ULTIMA_1850_PrintString(_TEXT(0x268a, "West\n"));
        break;
    }

    // 0669
    local_6 = 1;
    local_10 = GetMapViewport(local_c + 5, local_e + 5); // 0xaba7
    local_a = ULTIMA_368e_FindActorTileAtPos(local_c + (uint)D_5896_map_x, local_e + (uint)D_5897_map_y, D_5895_map_level);
    if (local_a != 0)
    {
        // 06a9
        local_6 = 0;
        if (D_587c_partyTile >= TILE_ACTOR_30 || D_587c_partyTile < TILE_ACTOR_FRIGATE_20)
        {
            // 06bf
            if (local_a >= TILE_ACTOR_FRIGATE_24 && local_a < TILE_ACTOR_PIRATE || local_a == TILE_ACTOR_CARPET || ((byte)local_a & 0xfe) == TILE_ACTOR_HORSE ||
                local_a == TILE_ACTOR_SLEEP || local_a == TILE_ACTOR_DEAD)
            {
                // -> 0771
                local_6 = 1;
            }
        }
        else
        {
            // 075e
            if (D_587c_partyTile >= TILE_ACTOR_SKIFF && local_a >= TILE_ACTOR_FRIGATE_24 && local_a < TILE_ACTOR_SKIFF)
            {
                // -> 0771
                local_6 = 1;
            }
        }
    }

    // 0776
    if (local_6 && ULTIMA_2c4c(D_587c_partyTile, local_10) != 0)
    {
        // 0792
        if (local_8 != 0)
        {
            ULTIMA_1850_PrintString(_TEXT(0x2690, "\nDost thou wish to leave? "));

            // 079f NOT MATCHING
            while ((local_4 = ULTIMA_266c_GetChar()) != 'Y' && local_4 != 'N' && local_4 != U5_KEY_ESC)
            {
            }

            // 07b6
            if (local_4 == 'Y')
            {
                ULTIMA_1850_PrintString(_TEXT(0x26ab, "Yes\n\nExit to\n"));
                if (D_5893_map_id == 0x19)
                {
                    ULTIMA_1850_PrintString(_TEXT(0x26b9, "Underworld!\n"));
                    D_5895_map_level = 0xff;
                }
                else
                {
                    // 07da
                    ULTIMA_1850_PrintString(_TEXT(0x26c6, "Britannia!\n"));
                    D_5895_map_level = 0;
                }

                // 07e6
                D_594f = 0;
                D_5896_map_x = D_1e8a[D_5893_map_id - 1];
                D_5897_map_y = D_1eb2[D_5893_map_id - 1];
                D_5893_map_id = 0;
            }
            else
            {
                // 0806
                ULTIMA_1850_PrintString(_TEXT(0x26d2, "No\n"));
                local_8 = 0;
            }
        }
        else
        {
            // 0810
            D_5896_map_x += local_c;
            D_5897_map_y += local_e;
            D_24e6 = 1;
            if ((D_587c_partyTile & 0xfe) == TILE_ACTOR_RIDING_HORSE)
            {
                ULTIMA_433e_AudioFootstep();
            }

            TOWN_052e(param_1, local_10);
        }
    }
    else
    {
        // 083a
        ULTIMA_1850_PrintString(_TEXT(0x26d6, "Blocked!\n"));
        ULTIMA_22c0_AudioTone(0xa5, 200);
        ULTIMA_1b16_ClearKbdBuffer();
        local_8 = 0;
    }

    // 0854
    return local_8;
}

// OK P1
static void TOWN_085e(int param_1)
{
    int local_4;
    int i;

    if (D_659e[param_1] >= 0x2f)
    {
        local_4 = 7;
    }
    else
    {
        local_4 = 6;
    }

    for (i = 0; i < 4; i++)
    {
        D_5d5e[param_1].time[i] = 0;
    }

    for (i = 0; i < 3; i++)
    {
        D_5d5e[param_1].type[i] = local_4;
    }
}

// OK P1
static void TOWN_08d4(int param_1)
{
    int local_6;
    int local_8;
    int local_c; // unused

    local_6 = 0;

    for (local_8 = 0; local_8 < 4; local_8++)
    {
        if (D_5d5e[param_1].time[local_8] != 0)
        {
            local_6 = 1;
        }
    }

    if (D_659e[param_1] < 0x74 && D_659e[param_1] >= 0x40 && (D_5f5e[param_1]._a == 0xfe || local_6))
    {
        D_5f5e[param_1]._a = 0xfd;

        for (local_8 = 0; local_8 < 3; local_8++)
        {
            D_5d5e[param_1].type[local_8] = 3;
        }
    }
}

// OK P1
// call guards?
void TOWN_0958(void)
{
    int local_6;
    int local_4;

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        if (D_5f5e[local_4]._0 != 0)
        {
            local_6 = D_659e[local_4];
            if (local_6 == TILE_ACTOR_SHADOWLORD || local_6 == TILE_ACTOR_D8 || local_6 == TILE_ACTOR_GUARD)
            {
                TOWN_085e(local_4);
            }
            else
            {
                if (ULTIMA_2092_RandomRange(0, 0xff) < 0x80)
                {
                    TOWN_08d4(local_4);
                }
            }
        }
    }
}

// OK P1
static void TOWN_09bc(int param_1)
{
    TOWN_0052_SetNpcKilled(param_1);
    ULTIMA_6150_Combat(D_5f5e[param_1]._c);
    TOWN_00b0_DespawnNpc(param_1);
    TOWN_0408(0);
    TOWN_02ae();
}

// OK P1
int TOWN_09e6_AttackCmd(void)
{
    bool local_8;
    int local_a;
    int local_c;
    int local_e;
    int local_10;
    int local_12;
    int local_4;
    int local_6 = 1;

    ULTIMA_1850_PrintString(_TEXT(0x26e0, "Attack-"));

    if (*ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y) < TILE_MAP_POISON && D_587c_partyTile != TILE_ACTOR_AVATAR)
    {
        ULTIMA_1850_PrintString(_TEXT(0x26e8, "On foot!\n"));
        local_6 = 0;
    }
    else if (ULTIMA_35ec_SelectDirection() != 0)
    {
        local_a = (uint)D_5896_map_x + D_5876;
        local_c = (uint)D_5897_map_y + D_5878;
        if (*ULTIMA_4402_GetTileAddr(local_a, local_c) == TILE_MAP_MIRROR)
        {
            *ULTIMA_4402_GetTileAddr(local_a, local_c) = TILE_MAP_MIRROR_BROKEN;
            ULTIMA_1850_PrintString(_TEXT(0x26f2, "Broken!\n"));

            for (local_e = 2000; local_e < 20000; local_e += 1000)
            {
                ULTIMA_223c_AudioWhiteNoise(0x28, 0x78, local_e);
            }

            D_24e6 |= 2;
        }
        else
        {
            local_12 = ULTIMA_368e_FindActorTileAtPos(local_a, local_c, D_5895_map_level);
            local_8 = 1;
            if (local_12 != 0)
            {
                local_10 = D_5876;
                local_4 = TOWN_011e(local_10);
                if (local_12 >= TILE_ACTOR_WIZARD && (local_12 < TILE_ACTOR_E8 || local_12 >= TILE_ACTOR_F0) && (local_12 & 0xfc) != TILE_ACTOR_SHARD)
                {
                    local_8 = 0;
                }
            }

            // 0ad8
            if (local_8)
            {
                // 0ae1
                ULTIMA_1850_PrintString(_TEXT(0x26fb, "Nothing to attack!\n"));
            }
            else
            {
                if (local_12 < 0x80)
                {
                    ULTIMA_3f36_DecreaseByte(&D_5888, 5);
                    TOWN_0958();
                }
                else if ((local_12 & 0xfc) == TILE_ACTOR_D8)
                {
                    TOWN_0958();
                }

                switch (*ULTIMA_4402_GetTileAddr(local_a, local_c))
                {
                case TILE_MAP_84:
                case TILE_MAP_85:
                case TILE_MAP_MIRROR_BROKEN:
                case TILE_MAP_BED:
                    if (local_12 == TILE_ACTOR_BLACKTHORN)
                    {
                        ULTIMA_1850_PrintString(_TEXT(0x270f, "Missed!\n"));
                    }
                    else
                    {
                        ULTIMA_1850_PrintString(_TEXT(0x2718, "Murdered!\n"));
                        ULTIMA_3f36_DecreaseByte(&D_5888, 5);
                        ULTIMA_3522(local_a, local_c);

                        if (local_4 >= 0)
                        {
                            TOWN_0052_SetNpcKilled(local_4);
                            TOWN_00b0_DespawnNpc(local_4);
                        }
                    }
                    break;

                default:
                    if (local_4 >= 0)
                    {
                        TOWN_0052_SetNpcKilled(local_4);
                        TOWN_09bc(local_4);
                    }
                    break;
                }

            }
        }
    }

    return local_6;
}

// CHECKED
int TOWN_0b82_KlimbCmd(void)
{
    int local_6;
    int local_4;

    local_4 = 0;
    ULTIMA_1850_PrintString(_TEXT(0x2723, "Klimb-"));

    if ((D_587c_partyTile & 0xfe) == TILE_ACTOR_RIDING_HORSE)
    {
        // 0ba0..
        ULTIMA_1850_PrintString(_TEXT(0x272a, "-On foot!\n"));
    }
    else
    {
        // 0ba8
        switch (*ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y))
        {
        case TILE_MAP_LADDER_UP:
            // 0bce..0bd0
            TOWN_052e(0, TILE_MAP_STAIR);
            local_4 = 1;
            break;

        case TILE_MAP_86:
        case TILE_MAP_LADDER_DOWN:
            // 0c32..0bd0
            TOWN_052e(2, TILE_MAP_STAIR);
            local_4 = 1;
            break;
        }

        // 0bdd
        if (local_4 == 0)
        {
            if (ULTIMA_35ec_SelectDirection() != 0)
            {
                switch (local_6 = *ULTIMA_4402_GetTileAddr(D_5896_map_x + D_5876, D_5897_map_y + D_5878))
                {
                case TILE_MAP_4C:
                case TILE_MAP_CA:
                case TILE_MAP_CB:
                    // 0c19
                    D_5896_map_x += D_5876;
                    D_5897_map_y += D_5878;
                    D_24e6 = 1;
                    ULTIMA_5910_UpdateFrame();
                    // 0c3e
                    local_4 = 1;
                    break;

                default:
                    // 0c38..0ba0
                    ULTIMA_1850_PrintString(_TEXT(0x2735, "What?\n"));
                    break;
                }
            }
        }
    }

    return local_4;
}

// OK P1
static int TOWN_0c4a(int param_1, int param_2)
{
    if (*ULTIMA_4402_GetTileAddr(param_1, param_2) == TILE_MAP_A2 ||
        *ULTIMA_4402_GetTileAddr(param_1, param_2) == TILE_MAP_43)
    {
        return 1;
    }

    return 0;
}

// CHECKED (loop, stack)
static void TOWN_0c78(void)
{
    ActorFmt* local_4;
    int local_6; // x
    int local_8; // y
    int local_a; // i
    int local_c;
    int local_e;

    for (local_a = 0; local_a < 0x20; local_a++)
    {
        local_4 = &D_5c5a[local_a];

        local_e = local_4->_0_tile;
        if (((byte)local_e & 0xfe) == TILE_ACTOR_HORSE && local_4->_4_z == D_5895_map_level &&
            ULTIMA_2092_RandomRange(0, 1) == 0)
        {
            local_6 = local_4->_2_x;
            local_8 = local_4->_3_y;

            if (TOWN_0c4a(local_6, local_8 + 1) == 0 &&
                TOWN_0c4a(local_6 + 1, local_8) == 0 &&
                TOWN_0c4a(local_6, local_8 - 1) == 0 &&
                TOWN_0c4a(local_6 - 1, local_8) == 0)
            {
                // 0d12
                if (ULTIMA_2092_RandomRange(0, 1) != 0)
                {
                    local_c = ULTIMA_2092_RandomRange(0, 1) * 2 - 1;
                    local_6 += local_c;
                    if (local_c > 0)
                    {
                        local_e = TILE_ACTOR_HORSE;
                        // nop
                    }
                    else
                    {
                        local_e = TILE_ACTOR_HORSE + 1;
                    }
                }
                else
                {
                    local_8 += ULTIMA_2092_RandomRange(0, 1) * 2 - 1;
                }

                if (local_6 <= 0x1f && local_8 <= 0x1f && 0 <= local_6 && 0 <= local_8)
                {
                    if ((ULTIMA_2c4c(TILE_ACTOR_HORSE, *ULTIMA_4402_GetTileAddr(local_6, local_8)) != 0) &&
                        (ULTIMA_3702(local_6, local_8, D_5895_map_level) == 0))
                    {
                        local_4->_0_tile = local_4->_1_animTile = local_e;
                        local_4->_2_x = (byte)local_6;
                        local_4->_3_y = (byte)local_8;
                        D_24e6 |= 2;
                    }
                }
            }
        }
    }
}

// OK P1
static uint TOWN_0dc4(int param_1)
{
    uint local_4;

    if (param_1 != 0)
    {
        ULTIMA_5910_UpdateFrame(); // update_map?
        if (D_a9fa != 0)
        {
            ULTIMA_2900_UpdateVitalsDisplay();
            D_a9fa = 0;
        }
        ULTIMA_16ba_PrintChar(10);
        ULTIMA_4c2a();
    }

    local_4 = ULTIMA_266c_GetChar();

    if (D_5957 != 0)
    {
        if (ULTIMA_2092_RandomRange(0, 1) != 0)
        {
            TOWN_0958();
            D_5957--;
            ULTIMA_1850_PrintString(_TEXT(0x273c, "Hic!\n"));
            local_4 = D_2742[ULTIMA_2092_RandomRange(0, 3)];
        }
    }

    return local_4;
}

// OK P1
static int TOWN_0e34(int param_1)
{
    int local_4;

    local_4 = 3;
    if (GetMapViewport(5, 6) == 0x8d) // abc7
    {
        param_1 -= 0x30;
        if (D_a9ce != 0)
        {
            ULTIMA_2192_AudioPulse(D_2746[param_1], 1, 4000, 20000, -4);
        }
        if (D_275a[D_2767] == param_1)
        {
            D_2767++;
            if (D_2767 == 0xd)
            {
                D_2767 = 0;
                if (D_5893_map_id == 0x11 && D_5895_map_level == 0x02)
                {
                    GetMap(0x11, 0xd) ^= 0xb; // 67b9
                    ULTIMA_3072_ShakeScreen();
                    D_24e6 = 1;
                }
            }
        }
        else if (D_2767 == 0xa && param_1 == 8)
        {
            D_2767 = 3;
        }
        else if (D_2767 == 0xb && param_1 == 7)
        {
            D_2767 = 2;
        }
        else if (param_1 == D_275a[0])
        {
            D_2767 = 1;
        }
        else
        {
            D_2767 = 0;
        }
    }
    else
    {
        local_4 = ULTIMA_4080(param_1);
    }

    return local_4;
}

// CHECKED (loop)
static void TOWN_0f02(void)
{
    int local_8;
    int local_a;
    int local_4;
    int local_6;

    for (local_6 = 0; local_6 < D_585b; local_6++)
    {
        if (D_55a8_party[local_6].status == STATUS_SLEEP && ULTIMA_2092_RandomRange(0, 0xf) == 0xf)
        {
            D_55a8_party[local_6].status = STATUS_GOOD;
        }
    }

    do
    {
        local_4 = 0;
        local_a = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
        if (local_a == TILE_MAP_TRAPDOOR && (D_587c_partyTile & 0xfe) != TILE_ACTOR_FLYING_CARPET)
        {
            ULTIMA_1850_PrintString(_TEXT(0x2768, "A TRAPDOOR!\n"));
            local_8 = D_587c_partyTile;
            D_587c_partyTile = 0;
            ULTIMA_5910_UpdateFrame();
            ULTIMA_2aa8();
            D_587c_partyTile = local_8;
            if (D_5893_map_id == 0x1d)
            {
                ULTIMA_0a70_GRAP_2d_SetPenColor(0);
                ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);
#if defined(MATCHING_BUILD)
                for (local_6 = 1000; local_6 > 0xfa; local_6--)
                {
                    ULTIMA_22e2_PcspkOn(local_6);
                    ULTIMA_20c8_SomeDelay(1, 0x28);
                }
                ULTIMA_230e_PcspkOff();
#else
                ULTIMA_43ae_AudioSweepTone(1000, 250, 0x28, 30000);
#endif

                memset(D_6608, TILE_MAP_LAVA, 0x400);

                D_24e6 = 1;

                memset(D_5c5a, 0, 0x100);

                for (local_6 = 0; (local_6 < D_585b); local_6++)
                {
                    D_55a8_party[local_6].hp = 0;
                    D_55a8_party[local_6].status = STATUS_DEAD;
                    ULTIMA_223c_AudioWhiteNoise(0x28, 3000, 500);
                    ULTIMA_2900_UpdateVitalsDisplay();
                }
            }
            else
            {
                D_5895_map_level--;
                TOWN_0408(1);
                local_4 = 1;
            }
        }
        else if (local_a == TILE_MAP_POISON && D_587c_partyTile == TILE_ACTOR_AVATAR)
        {
            // NOT MATCHING
            // for (105d; 1067; 1064)
            for (local_6 = 0; local_6 < D_585b; local_6++)
            {
                // 1071
                if (D_55a8_party[local_6].status != STATUS_DEAD &&
                    D_55a8_party[local_6].status != STATUS_POISONED &&
                    D_55a8_party[local_6].dex < ULTIMA_2092_RandomRange(0, 0x1d))
                {
                    ULTIMA_1850_PrintString(_TEXT(0x2775, "Poisoned!\n"));
                    D_55a8_party[local_6].status = STATUS_POISONED;
                    ULTIMA_2900_UpdateVitalsDisplay();
                }
            }
        }
        // 10ac
        else if (local_a == TILE_MAP_FIREPLACE || local_a == TILE_MAP_LAVA)
        {
            // 10ba
            ULTIMA_5910_UpdateFrame();
            ULTIMA_1850_PrintString(_TEXT(0x2780, "Burning!\n"));
            ULTIMA_2aa8();
        }
        // 10c7
    } while (local_4);

    // 10d0
    ULTIMA_2ae8();
}

// OK P1
void TOWN_10da(int param_1)
{
    ULTIMA_1850_PrintString(_TEXT(0x278a, "\"Begone,\nvermin!\"\n"));
    ULTIMA_2aa8();
    TOWN_08d4(param_1);
}

// OK P1
static int TOWN_10f2(int param_1)
{
    int local_8;
    int local_6;
    int local_4;

    local_4 = 0;
    for (local_6 = 0; local_6 < 4; local_6++)
    {
        if (D_5d5e[param_1].time[local_6] != 0)
        {
            local_4 = 1;
        }
    }

    local_8 = D_659e[local_6];
    if (local_8 < TILE_ACTOR_WIZARD || local_8 >= TILE_ACTOR_74)
    {
        local_4 = 0;
    }

    if (ULTIMA_2092_RandomRange(0, 1) != 0)
    {
        local_4 = 0;
    }

    return local_4;
}

// OK P1
static void TOWN_1156(void)
{
    int local_4;

    switch (D_5958)
    {
    case 1:
        for (local_4 = 0; local_4 < 0x20; local_4++)
        {
            if (TOWN_10f2(local_4) != 0)
            {
                TOWN_085e(local_4);
                D_5f5e[local_4]._a = 0xfe;
            }
        }
        break;

    case 2:
        for (local_4 = 0; local_4 < 0x20; local_4++)
        {
            if (TOWN_10f2(local_4) != 0)
            {
                TOWN_08d4(local_4);
                D_5f5e[local_4]._a = 0xfd;
            }
        }
        break;
    }
}

// OK P1
static void TOWN_11b8(int param_1)
{
    ULTIMA_1850_PrintString(_TEXT(0x27b8, "\nAn air of\n"));
    ULTIMA_1850_PrintString(D_27dc[param_1]);
    ULTIMA_1850_PrintString(_TEXT(0x27c4, " doth surround thee...\n"));
    ULTIMA_2192_AudioPulse(0x19c8, 1, 60000, 2000, 1);
}

// OK P1 (complete)
void TOWN_11f0_Entry(int param_1)
{
    int local_4;

#if defined(ENABLE_BGM)
    AUDIO_StopBgm();
#endif

    D_a9bc = D_24e6 = 1;
    if (param_1 != 0)
    {
        for (local_4 = 1; local_4 < 0x20; local_4++)
        {
            D_5c5a[local_4]._0_tile = 0;
        }
        D_5957 = 0;
        D_58a4 = 1;
        NPC_0000_LoadNpcFile();
        NPC_00d6(D_587f);
    }
    D_5958 = 0xff;
    TOWN_0408(param_1);
    TOWN_02ae();

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        if (TOWN_0000_CheckNpcKilled(local_4) != 0)
            TOWN_00b0_DespawnNpc(local_4);
    }

    if ((D_5893_map_id == 29) && (D_57b5 != 0))
        TOWN_00b0_DespawnNpc(9);

    ULTIMA_2900_UpdateVitalsDisplay();

    if (ULTIMA_39fc_GetFirstActivePartyMember() >= 0)
    {
        ULTIMA_5910_UpdateFrame();
        if (D_5893_map_id == 29)
        {
            for (local_4 = 2; local_4 >= 0; local_4--)
            {
                if (D_58c8[local_4] < 0x80)
                {
                    TOWN_11b8(local_4);
                }
            }
        }
        else if (D_5958 != (byte)-1)
        {
            TOWN_11b8(D_5958);
            TOWN_1156();
        }
    }

#if defined(ENABLE_BGM)
    AUDIO_PlayBgmPerMap();
#endif
}

// OK P1
static int TOWN_12ae(void)
{
    int local_6;
    char local_4;

    local_6 = 0;
    if (D_5893_map_id == 0x12)
    {
        if (ULTIMA_39fc_GetFirstActivePartyMember() >= 0)
        {
            BLCKTHRN_060e_Capture();
            TOWN_11f0_Entry(1);
        }
    }
    else
    {
        ULTIMA_1850_PrintString(_TEXT(0x27e2, "\n\"Thou art under arrest!\"\n\n"));
        ULTIMA_1850_PrintString(_TEXT(0x27fe, "\"Wilt thou come quietly?\"\n\n:"));

        do
        {
            local_4 = ULTIMA_266c_GetChar();
        } while (local_4 != 'N' && local_4 != 'Y');

        if (local_4 == 'Y')
        {
            ULTIMA_1850_PrintString(_TEXT(0x281b, "Yes\n\nThe guard strikes thee unconscious!\n"));
            ULTIMA_0a70_GRAP_2d_SetPenColor(0);
            ULTIMA_1850_PrintString(_TEXT(0x2845, "\nThou dost awaken to...\n"));
            D_5893_map_id = 4;
            D_5896_map_x = 0x19;
            D_5897_map_y = 4;
            D_24e6 = 1;

            while (D_587f != 8)
            {
                ULTIMA_4f7c(0x14);
            }

            D_5895_map_level = D_57ac = 0;

            TOWN_11f0_Entry(1);
        }
        else
        {
            ULTIMA_1850_PrintString(_TEXT(0x285e, "No\n\n\"Then defend thyself, rogue!\"\n"));
            TOWN_0958();
            local_6 = 1;
        }
    }

    return local_6;
}

// OK P1
static void TOWN_1352(int param_1)
{
    ActorFmt* local_6;
    int local_4;

    local_4 = 0;
    local_6 = &D_5c5a[D_5f5e[D_65bf]._c];

    ULTIMA_5910_UpdateFrame();

    if (D_65be == 0x61)
    {
        if (D_5f5e[D_65bf]._a == 0xfe)
        {
            ULTIMA_16ba_PrintChar(10);
            TOWN_10da(D_65bf);
        }
        else if (local_6->_0_tile != TILE_ACTOR_GUARD)
        {
            local_4 = 1;
        }
        else
        {
            local_4 = TOWN_12ae();
        }
    }
    else if (param_1 == 0)
    {
        if (D_5f5e[D_65bf]._a != 0 && TALK_031e(D_65bf) != 0)
        {
            local_4 = TOWN_12ae();
        }
    }
    else
    {
        local_4 = TOWN_12ae();
    }

    if (local_4 != 0)
    {
        if (D_5c5a[D_5f5e[D_65bf]._c]._0_tile >= TILE_ACTOR_WIZARD)
        {
            ULTIMA_1850_PrintString(_TEXT(0x2881, "\nAttacked!\n"));
            TOWN_09bc(D_65bf);
        }
        else
        {
            TOWN_00b0_DespawnNpc(D_65bf);
        }
    }
}

// OK P1
void TOWN_141e_MainLoop(void)
{
    int local_4;
    int local_6;
    uint local_8;
    int local_a;
    uint local_c;
    int local_e;
    int local_10;
    int local_12;
    int local_14; // unused

    local_6 = local_10 = 0;

    do
    {
        local_e = 0;
        local_c = 1;
        local_a = ULTIMA_39fc_GetFirstActivePartyMember();
        // 1456
        if (local_a == 1)
        {
            ULTIMA_16ba_PrintChar(10);
            ULTIMA_4c2a();
            ULTIMA_1850_PrintString(_TEXT(0x288d, "Zzzzzz...\n"));
        }
        else if (local_a == -1)
        {
            BLCKTHRN_0910_Death();
            local_c = 0;
        }
        else
        {
            if (D_a9bc != 0)
            {
                D_a9bc = 0;
            }
            else
            {
                if (ULTIMA_48a8() != 0) // FMT: LOOKOBJ_UNK();
                {
                    CAST2_0e76_Shrine(); // thunk f89a
                }
            }
            if (D_5893_map_id == 0)
            {
                return;
            }

            local_4 = 1;

            do {
                // 148f
                local_8 = TOWN_0dc4(local_4);
                local_4 = 0;

                if (local_8 < 0x20)
                {
                    // 14a5
                    switch (local_8)
                    {
                    case U5_KEY_CTRL_K: // 14b8 (9688)
                        ULTIMA_1a3e_PrintNumber(D_5888, 1, 0x20);
                        // 14ff
                        ULTIMA_16ba_PrintChar(10);   // 94ea
                        // 154b
                        local_c = 0;
                        break;

                    case U5_KEY_CTRL_E: // 14cc (969c)
                        ULTIMA_1850_PrintString(_TEXT(0x2898, "Exit to DOS? "));
                        local_8 = ULTIMA_266c_GetChar();
                        if (local_8 == 0x59)
                        {
                            ULTIMA_0878_RestoreVideoMode();
                            exit(0); // cdecl
                        }
                        else
                        {
                            ULTIMA_1850_PrintString(_TEXT(0x28a6, "N\n"));
                        }
                        break;

                    case U5_KEY_CTRL_V: // 14f8 (96c8)
                        ULTIMA_1850_PrintString(_TEXT(0x28a9, "1.16"));
                        ULTIMA_16ba_PrintChar(10);
                        local_c = 0;
                        break;

                    case U5_KEY_CTRL_S: // 1508 (96d8)
                        ULTIMA_1850_PrintString(_TEXT(0x28ae, "Sound "));
                        if (D_a9ce != 0)
                        {
                            ULTIMA_1850_PrintString(_TEXT(0x28b5, "Off\n"));
                        }
                        else
                        {
                            ULTIMA_1850_PrintString(_TEXT(0x28ba, "On\n"));
                        }

                        D_a9ce = !D_a9ce;
                        // 154b
                        local_c = 0;
                        break;

                    case U5_KEY_LEFT:
                    case U5_KEY_RIGHT:
                    case U5_KEY_UP:
                    case U5_KEY_DOWN: // 1532 (9702)
                        local_e = TOWN_0600(local_8); // bp-06
                        local_c = (uint)(local_e == 0); // -> 159a
                        break;

                    default: // 1544 (9714)
                        ULTIMA_1850_PrintString(_TEXT(0x28be, "What?\n"));
                        local_c = 0;
                        break;
                    }
                }
                else if ((local_8 < 0x30) || (local_8 > 0x39))
                {
                    local_c = ULTIMA_3178_ProcessCommand(local_8);
                }
                else
                {
                    local_c = TOWN_0e34(local_8);
                }
                // 159d
            } while (local_c == 3);
        }
        // 15a6
        if (D_5893_map_id == 0)
        {
            local_e = 1;
        }
        else if (local_c != 0 && ULTIMA_39fc_GetFirstActivePartyMember() != -1)
        {
            local_12 = D_587f;
            ULTIMA_4f7c(1);
            if ((D_587f != local_12) && (D_587f == 20 || D_587f == 5))
            {
                TOWN_0170();
            }
            // 15ec
            TOWN_0f02();
            if ((D_594f != 0) && (D_5952--, D_5952 == 0))
            {
                ULTIMA_39cc_SetTile(D_594f, D_5950, D_5951);
            }
            // 160d
            D_5c5a[0]._2_x = D_5896_map_x;
            D_5c5a[0]._3_y = D_5897_map_y;
            D_5c5a[0]._4_z = D_5895_map_level;
            if ((D_587c_partyTile < TILE_ACTOR_RIDING_HORSE || D_587c_partyTile >= TILE_ACTOR_CIRCLE || local_8 == 0x20 ||
                (local_6 = !local_6, !local_6)) &&
                D_587a != 'T' && (D_587a != 'Q' || (local_10 = !local_10, !local_10)))
            {
                // 165f
                TOWN_0c78();
                if ((int)local_c < 2)
                {
                    NPC_0db4(D_587f);
                }
                // 1671
                if (D_65bf != 0 || local_c == 2)
                {
                    // 167e
                    TOWN_1352(local_c - 1);
                }
            }
        }
        // 1686
    } while (local_e == 0);

    // 168f
}

// OK P1
void TOWN_1694(void)
{
    int local_4;
    int local_6;

    for (local_4 = 1; local_4 < 0x20; local_4++)
    {
        ULTIMA_3a74(0, 0, 0, 0, 0, 0, local_4);
        D_5f5e[local_4]._c = 0;
    }

    for (local_4 = 1; local_4 < 0x20; local_4++)
    {
        if (D_659e[local_4] != 0)
        {
            local_6 = NPC_12e0(local_4, D_587f);
            TOWN_1726(local_4, D_5d5e[local_4].x[local_6], D_5d5e[local_4].y[local_6], D_5d5e[local_4].z[local_6]);
            D_5f5e[local_4]._0 = 1;
            D_5f5e[local_4]._e = local_6;
            D_655e[local_4] = -1;
        }
    }
}

// OK P1
void TOWN_1726(int param_1, int param_2, int param_3, int param_4)
{
    int local_6;
    int local_8;
    NpcFmt* local_4;

    if (D_659e[param_1] == 0)
        return;

    local_4 = &D_5f5e[param_1];

    if (param_4 != D_5895_map_level && local_4->_c != 0)
    {
        D_5c5a[local_4->_c]._0_tile = 0;
        local_4->_c = 0;
    }

    if (param_4 == D_5895_map_level && local_4->_c == 0)
    {
        local_6 = ULTIMA_38e4();

        if (D_659e[param_1] == 1)
        {
            local_8 = 0x1e;
        }
        else if ((D_28c6[D_5893_map_id - 1] & ((u32)1 << param_1)) != 0)
        {
            local_8 = 0xff;
        }
        else
        {
            local_8 = 0;
        }

        ULTIMA_3a74(D_659e[param_1], D_659e[param_1], param_2, param_3, param_4, local_8, local_6);

        D_5c5a[local_6]._6 = 0;
        local_4->_c = local_6;
    }

    if (param_4 == D_5895_map_level && local_4->_c != 0)
    {
        local_6 = local_4->_c;
        D_5c5a[local_6]._2_x = param_2;
        D_5c5a[local_6]._3_y = param_3;
        D_5c5a[local_6]._4_z = param_4;
    }

    local_4->_2_x = param_2;
    local_4->_4_y = param_3;
    local_4->_6_z = param_4;
    local_4->_0 = 1;
}
