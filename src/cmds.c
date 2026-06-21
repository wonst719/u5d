#include "common/common.h"
#include "funcs.h"
#include "vars.h"
#include "macros.h"
#include "tiles.h"

#include "audio/aud_mus.h"

#include "cast2.h"
#include "cmds.h"
#include "combat.h"
#include "comsubs.h"
#include "dnglook.h"
#include "npc.h"
#include "outsubs.h"
#include "town.h"

void MAINOUT_0354(int param_1, int param_2);
int MAINOUT_105c(int param_1);

// CHECKED
// hole up (impl)
int CMDS_0000(int param_1, int param_2, int param_3)
{
    int local_20;
    byte local_1c;
    byte local_28;
    byte local_2c;
    int local_22;
    CombatEntity* local_1a;
    int local_26;
    int local_2a;
    int local_24;
    int local_1e;
    byte local_18;
    int local_16[8];
    int local_6;
    ActorFmt* local_4; // not read

#if !defined(MATCHING_BUILD)
    local_1a = 0;
#endif

    local_20 = D_587f;
    local_6 = -1;
    local_1e = -1;
    D_587a = D_588e = 0;
    local_1c = D_587b;
    D_587b = 0xff;
    if ((param_1 & 2) != 0)
    {
        DNGLOOK_117e(GetDungeonMap((uint)D_5896_map_x, (uint)D_5897_map_y, D_5895_map_level & 0xff), 0);
    }
    else
    {
        ULTIMA_6936();
    }

#if defined(ENABLE_BGM)
    AUDIO_PlayBgmForHoleUp();
#endif

    D_589e = 0xff;
    local_2a = param_3 + (uint)D_587f;
    if (local_2a > 0x17)
    {
        local_2a -= 0x18;
    }

    if (5 < param_2 || param_2 < -1)
    {
        param_2 = -1;
    }

    for (local_22 = 0; local_22 < 8; local_22++)
    {
        local_16[local_22] = 0;
    }

    for (local_22 = 0; local_22 < D_585b; local_22++)
    {
        for (local_26 = 0; local_26 < 0x20; local_26++)
        {
            if (local_22 == D_ba14[local_26].entityIdx)
            {
                local_1a = &D_ba14[local_26];
                break;
            }
        }

        switch (D_55a8_party[local_22].status)
        {
        case STATUS_POISONED:
            local_16[local_22]++;
            // fallthrough
        case STATUS_GOOD:
        case STATUS_SLEEP:
            if (local_22 != param_2)
            {
                ULTIMA_6880(local_26);
            }

            if (D_55a8_party[local_22].cls == CLASS_BARD && local_22 == param_2 && D_a9ce != 0)
            {
                local_6 = local_26;
            }
            break;
        }
    }

    ULTIMA_5910_UpdateFrame();

    if (local_6 != -1)
    {
        local_4 = &D_5c5a[D_ba14[local_6].actorIdx];
        local_28 = local_4->_0_tile;
        local_2c = local_4->_1_animTile;
        
        local_4->_0_tile = local_4->_1_animTile = TILE_ACTOR_5F;
        D_6a08 = 1;
        ULTIMA_3ae6(0x34);
        local_4->_0_tile = local_28;
        local_4->_1_animTile = local_2c;
        if (D_ba14[local_6].entityIdx != param_2)
        {
            ULTIMA_6880(local_6);
        }

        ULTIMA_5910_UpdateFrame();
    }

    ULTIMA_1850_PrintString(_TEXT(0x41d4, "Zzzzzz...\n\n"));

    if (param_2 != -1)
    {
        for (local_26 = 0; local_26 < 0x20; local_26++)
        {
            if (D_ba14[local_26].entityIdx == param_2)
            {
                local_1a = &D_ba14[local_26];
                break;
            }
        }

        local_18 = D_5c5a[local_1a->actorIdx]._0_tile;
    }

    while (local_2a != D_587f)
    {
        if (D_587f >= 0x18)
        {
            D_587f -= 0x18;
        }

        ULTIMA_5910_UpdateFrame();
        ULTIMA_400c();
        ULTIMA_2900_UpdateVitalsDisplay();
        if (local_20 != D_587f)
        {
            if (ULTIMA_2092_RandomRange(0, 0x3f) == 0)
            {
                ULTIMA_207e_srand(ULTIMA_2056_GetTime());
                local_1e = (uint)D_1734[ULTIMA_2092_RandomRange(0, 7)];
                ULTIMA_1850_PrintString(_TEXT(0x41e0, "Ambushed!\n\n"));

                if (param_2 > -1)
                {
                    // 0254..026e..027a..027d
                    for (local_24 = 0; local_24 < 6; local_24++)
                    {
                        // 0283
                        local_22 = D_ba14[local_24].entityIdx;
                        // NOT MATCHING: if (local_22 >= 0)
                        if (local_22 < D_585b)
                        {
                            ULTIMA_6800(local_24);
                            if (local_16[local_22] != 0)
                            {
                                D_55a8_party[local_22].status = STATUS_POISONED;
                            }
                            else
                            {
                                D_55a8_party[local_22].status = STATUS_GOOD;
                            }
                        }
                    }
                }

                ULTIMA_2900_UpdateVitalsDisplay();
                if ((param_1 & 2) != 0)
                {
                    DNGLOOK_117e(GetDungeonMap((uint)D_5896_map_x, (uint)D_5897_map_y, D_5895_map_level & 0xff), 1);
                }
                else
                {
                    ULTIMA_6bc2(param_1, local_1e);
                }

                break;
            }
        }

        local_20 = D_587f;
        ULTIMA_4f7c(5);
        ULTIMA_20fa_WaitTicks(1);
        if (D_5894 < 0x21)
        {
            D_5893_map_id = D_5894;
            ULTIMA_4a84();
            D_5893_map_id = 0xff;
        }

        if (param_2 != -1 && ULTIMA_2092_RandomRange(0, 3) == 2)
        {
            D_5876 = (uint)local_1a->x;
            D_5878 = (uint)local_1a->y;

            switch (ULTIMA_2092_RandomRange(0, 3))
            {
            case 0:
                D_5878--;
                break;
            case 1:
                D_5878++;
                break;
            case 2:
                D_5876++;
                break;
            case 3:
                D_5876--;
                break;
            }

            if (ULTIMA_6d82(D_5876, D_5878) != 0 && COMBAT_0000(local_18, D_5876, D_5878) != 0)
            {
                local_1a->x = D_5c5a[local_1a->actorIdx]._2_x = D_5876;
                local_1a->y = D_5c5a[local_1a->actorIdx]._3_y = D_5878;
                ULTIMA_5910_UpdateFrame();
            }
        }
    }

    // c27d
    if (local_1e > -1)
    {
        // conflict
#if defined(ENABLE_BGM)
        AUDIO_StopBgm();
#endif

        return 1;
    }

    if (D_588c < 1 && param_3 > 5)
    {
        ULTIMA_1850_PrintString(_TEXT(0x41ec, "Party rested!\n"));

        for (local_22 = 0; local_22 < D_585b; local_22++)
        {
            if (local_16[local_22] == 0 && D_588c < 1 && param_3 > 5 && D_55a8_party[local_22].status != STATUS_DEAD && local_22 != param_2)
            {
                D_55a8_party[local_22].hp += ULTIMA_2092_RandomRange(1, 0x3f);
                if (D_55a8_party[local_22].hp > D_55a8_party[local_22].maxHp)
                {
                    D_55a8_party[local_22].hp = D_55a8_party[local_22].maxHp;
                }

                if (local_22 != param_2)
                {
                    switch (D_55a8_party[local_22].cls)
                    {
                    case CLASS_AVATAR:
                    case CLASS_MAGE:
                        D_55a8_party[local_22].mag = D_55a8_party[local_22].intel;
                        break;
                    case CLASS_BARD:
                        D_55a8_party[local_22].mag = D_55a8_party[local_22].intel >> 1;
                        break;
                    }
                }
            }
        }

        if ((param_1 & 0x82) == 0 && ULTIMA_2092_RandomRange(0, 99) < 0x19)
        {
            D_588d = D_587d;
            OUTSUBS_0658();
        }

        D_588c = 0xe;
    }
    else
    {
        ULTIMA_1850_PrintString(_TEXT(0x41fb, "No effect...\n"));
    }

    for (local_22 = 0; local_22 < D_585b; local_22++)
    {
        if (D_55a8_party[local_22].status == STATUS_SLEEP)
        {
            D_55a8_party[local_22].status = STATUS_GOOD;
        }
    }

    D_587b = local_1c;
    ULTIMA_2900_UpdateVitalsDisplay();

#if defined(ENABLE_BGM)
    AUDIO_PlayBgmPerMap();
#endif

    return 0;
}

// OK P1
void CMDS_0552_HoleUpCmd(void)
{
    int local_4;
    int local_c;
    byte local_6;
    int local_a;
    int local_8;

    ULTIMA_1850_PrintString(_TEXT(0x4209, "For how many hours? "));

    while ((local_6 = ULTIMA_266c_GetChar()) != U5_KEY_SPACE && (local_6 < 0x30 || local_6 > 0x39))
    {
    }

    if (local_6 != U5_KEY_SPACE && local_6 != 0x30)
    {
        ULTIMA_16ba_PrintChar(local_6);
        ULTIMA_16ba_PrintChar(10);

        local_8 = (int)D_587f + (int)local_6 - 0x30;
        if (local_8 > 0x17)
        {
            local_8 -= 0x17;
        }

        for (local_a = 0; local_a < 0x10; local_a++)
        {
            NPC_0db4(D_587f);
            ULTIMA_5910_UpdateFrame();
            if (D_65be == 0x61)
            {
                return;
            }
        }

        local_4 = D_587b;

        for (local_a = 0; local_a < D_585b; local_a++)
        {
            if (D_55a8_party[local_a].status == STATUS_GOOD)
            {
                D_55a8_party[local_a].status = STATUS_SLEEP;
            }
        }

        ULTIMA_2900_UpdateVitalsDisplay();
        ULTIMA_1850_PrintString(_TEXT(0x421e, "Zzzzzzz...\n"));

        ULTIMA_0a70_GRAP_2d_SetPenColor(0);
        ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);

        local_c = D_587f;
        while (local_8 != D_587f)
        {
            ULTIMA_4f7c(10);
            if (local_c != D_587f && (D_587f == 0x14 || D_587f == 0x05))
            {
                TOWN_0170();
            }

            local_c = D_587f;
            ULTIMA_4a84();
            ULTIMA_2ae8();
            ULTIMA_2900_UpdateVitalsDisplay();
            TOWN_1694();

            if (ULTIMA_368e_FindActorTileAtPos(D_5896_map_x, D_5897_map_y, D_5895_map_level) != 0)
            {
                local_8 = -1;
                break;
            }
            ULTIMA_20fa_WaitTicks(1);
        }

        if (local_8 == -1)
        {
            ULTIMA_1850_PrintString(_TEXT(0x422a, "Thrown out of bed!\n"));
        }

        for (local_a = 0; local_a < D_585b; local_a++)
        {
            if (D_55a8_party[local_a].status == STATUS_SLEEP)
            {
                D_55a8_party[local_a].status = STATUS_GOOD;
            }
        }

        D_587b = local_4;
        D_5896_map_x++;
        D_24e6 = 1;
        D_5c5a[0]._2_x++;

        ULTIMA_2900_UpdateVitalsDisplay();
        ULTIMA_5910_UpdateFrame();
    }
}

// OK P1
static int CMDS_06ee(void)
{
    if (D_587c_partyTile != TILE_ACTOR_AVATAR && D_587c_partyTile != TILE_ACTOR_1D)
    {
        ULTIMA_1850_PrintString(_TEXT(0x423e, "\nOn foot\n"));
        return 0;
    }
    else
    {
        return 1;
    }
}

// OK P1
static int CMDS_070c(void)
{
    switch (D_587c_partyTile)
    {
    case TILE_ACTOR_FLYING_CARPET:
    case TILE_ACTOR_FLYING_CARPET + 1:
    case TILE_ACTOR_AVATAR:
    case TILE_ACTOR_1D:
    case TILE_ACTOR_SKIFF:
    case TILE_ACTOR_SKIFF + 1:
    case TILE_ACTOR_SKIFF + 2:
    case TILE_ACTOR_SKIFF + 3:
        return 1;

    default:
        ULTIMA_1850_PrintString(_TEXT(0x4248, "\nOn foot\n"));
        return 0;
    }
}

static int CMDS_0788(int param_1, int param_2);

// OK P1
static int CMDS_073e(void)
{
    if (CMDS_0788(4, 5) == 1 || CMDS_0788(6, 5) == 1 || CMDS_0788(5, 6) == 1 || CMDS_0788(5, 4) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// OK P1
static int CMDS_0788(int param_1, int param_2)
{
    int local_4;

    local_4 = GetMapViewport(param_2, param_1);
    if (local_4 != 0)
    {
        return ULTIMA_2c4c(0x1c, local_4);
    }

    local_4 = GetActorMap(param_2, param_1);
    if (local_4 == 0x1b)
    {
        return 1;
    }

    local_4 &= 0xfc;
    if (local_4 == 0x1c || local_4 == 0x24 || local_4 == 0x10 || local_4 == 0x28)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// OK P1
int CMDS_07f6_BoardCmd(void)
{
    byte local_c;
    int local_a;
    int local_4;
    int local_8;
    int local_6;

    if (D_5893_map_id > 0x20 && D_5893_map_id < 0x29)
    {
        ULTIMA_1850_PrintString(_TEXT(0x4252, "\nNot here!\n"));

        return 1;
    }

    local_c = ULTIMA_368e_FindActorTileAtPos(D_5896_map_x, D_5897_map_y, D_5895_map_level);
    local_6 = D_5876;
    if ((local_c & 0xfe) == TILE_ACTOR_HORSE)
    {
        if (D_5893_map_id != 0)
        {
            local_4 = TOWN_011e(local_6);
            if (local_4 != -1 && D_5f5e[local_4]._a != 0)
            {
                ULTIMA_1850_PrintString(_TEXT(0x425e, "\"Nay!\"\n"));
                return 1;
            }
        }

        if (CMDS_06ee() == 0)
        {
            return 1;
        }

        ULTIMA_1850_PrintString(_TEXT(0x4266, "horse\n"));

        D_587c_partyTile = local_c + 2;
    }
    else if (local_c == TILE_ACTOR_CARPET)
    {
        if (CMDS_06ee() == 0)
        {
            return 1;
        }

        ULTIMA_1850_PrintString(_TEXT(0x426d, "carpet\n"));

        D_587c_partyTile = TILE_ACTOR_FLYING_CARPET;
    }
    else if ((local_c & 0xfc) == TILE_ACTOR_SKIFF)
    {
        if (CMDS_06ee() == 0)
        {
            return 1;
        }

        ULTIMA_1850_PrintString(_TEXT(0x4275, "skiff\n"));

        D_587c_partyTile = local_c;
    }
    else if ((local_c & 0xfc) == TILE_ACTOR_FRIGATE_24)
    {
        if (CMDS_070c() == 0)
        {
            return 1;
        }

        ULTIMA_1850_PrintString(_TEXT(0x427c, "Ship\n"));

        local_a = D_5c5a[local_6]._5;
        if (local_a < 10)
        {
            ULTIMA_1850_PrintString(_TEXT(0x4282, "\nDANGER: SHIP BADLY DAMAGED!\n"));
        }

        D_5c5a[0]._5 = local_a;
        local_8 = D_5c5a[local_6]._7;

        if ((D_587c_partyTile & 0xfe) == TILE_ACTOR_FLYING_CARPET)
        {
            D_57b0++;
        }

        if ((D_587c_partyTile & 0xfc) == TILE_ACTOR_SKIFF)
        {
            local_8++;
        }

        if (local_8 == 0)
        {
            ULTIMA_1850_PrintString(_TEXT(0x42a0, "\nWARNING: NO SKIFFS ON BOARD!\n"));
        }

        D_587c_partyTile = local_c;
        D_5c5a[0]._7 = local_8;
        D_a9fa = 1;
    }
    else
    {
        ULTIMA_1850_PrintString(_TEXT(0x42bf, "What?\n"));
        return 0;
    }

    ULTIMA_3a74(0, 0, 0, 0, 0, 0, local_6);
    D_24e6 |= 2;

#if defined(ENABLE_BGM)
    AUDIO_PlayBgmPerMap();
#endif

    return 1;
}

// OK P1
static void CMDS_0962(void)
{
    int local_10;
    int local_14;
    int local_12;
    int local_16;
    int local_e;
    int local_c;
    int local_8;
    int local_a;
    int local_6;
    int local_4;

    if (D_587c_partyTile < TILE_ACTOR_FRIGATE_20 || D_587c_partyTile > TILE_ACTOR_FRIGATE_20_END)
    {
        ULTIMA_1850_PrintString(_TEXT(0x42c6, "What?\n"));
    }
    else
    {
        if (ULTIMA_35ec_SelectDirection() == 0)
        {
            return;
        }

        local_10 = D_5876;
        local_14 = D_5878;

        if (local_10 == 0 && (D_587c_partyTile & 1) == 0 || local_10 != 0 && (D_587c_partyTile & 1) != 0)
        {
            // 09b2
            ULTIMA_1850_PrintString(_TEXT(0x42cd, "Fire broadsides only!\n"));
        }
        else
        {
            // 09b8
            local_12 = D_5896_map_x;
            local_16 = D_5897_map_y;
            ULTIMA_43ae_AudioSweepTone(1000, 200, 5, 300);

            // 09d8
            for (local_e = 0; local_e < 3; local_e++)
            {
                local_12 += local_10;
                local_16 += local_14;

                local_c = ULTIMA_368e_FindActorTileAtPos(local_12, local_16, D_5895_map_level);

                if (MAINOUT_105c(local_c) != 0 && (local_c & 0xfc) != 0xec)
                {
                    // 0a10
                    local_6 = D_5876;

                    local_8 = D_5c5a[local_6]._2_x - D_5896_map_x + 5;
                    local_a = D_5c5a[local_6]._3_y - D_5897_map_y + 5;
                    local_4 = COMSUBS_12de(5, 5, local_8, local_a, 1);
                    if (local_4 != 0)
                    {
                        ULTIMA_5910_UpdateFrame();
                        ULTIMA_3522(local_12, local_16);

                        D_5c5a[local_6]._5 -= ULTIMA_2092_RandomRange(1, 0x14);
                        if (D_5c5a[local_6]._5 > 0x7f)
                        {
                            ULTIMA_3a74(0, 0, 0, 0, 0, 0, local_6);
                            D_24e6 |= 2;
                        }
                    }

                    return;
                }
            }

            local_8 = local_10 * 3 + 5;
            local_a = local_14 * 3 + 5;
            COMSUBS_12de(5, 5, local_8, local_a, 1);
        }
    }
}

// OK P1
void CMDS_0aea_FireCmd(void)
{
    int local_4;
    int local_1a;
    int local_1c;
    int local_8;
    int local_c;
    uint local_20;
    int local_1e;
    int local_18;
    int local_16;
    int local_14;
    int local_12;
    int local_10;
    int local_e;
    int local_a;
    int local_6;

    if (0x20 < D_5893_map_id && D_5893_map_id < 0x29)
    {
        ULTIMA_1850_PrintString(_TEXT(0x42e4, "What?\n"));
        return;
    }

    if (D_5893_map_id == 0)
    {
        CMDS_0962();
        return;
    }

    ULTIMA_39cc_SetTile(D_594f, D_5950, D_5951);

    if (((local_20 = GetMapViewport(5, 4)) & 0xfc) == 0xb4)
    {
        local_16 = 0;
        local_1e = -1;
    }
    else if (((local_20 = GetMapViewport(6, 5)) & 0xfc) == 0xb4)
    {
        local_16 = 1;
        local_1e = 0;
    }
    else if (((local_20 = GetMapViewport(5, 6)) & 0xfc) == 0xb4)
    {
        local_16 = 0;
        local_1e = 1;
    }
    else if (((local_20 = GetMapViewport(4, 5)) & 0xfc) == 0xb4)
    {
        local_16 = -1;
        local_1e = 0;
    }
    else
    {
        ULTIMA_1850_PrintString(_TEXT(0x42eb, "What?\n"));
        return;
    }

    local_14 = local_16 + (uint)D_5896_map_x;
    local_1c = local_1e + (uint)D_5897_map_y;

    local_8 = local_e = local_16 + 5;
    local_c = local_12 = local_1e + 5;

    switch (local_20 & 3)
    {
    case 0:
        local_16 = 0;
        local_1e = -1;
        break;
    case 1:
        local_16 = 1;
        local_1e = 0;
        break;
    case 2:
        local_16 = 0;
        local_1e = 1;
        break;
    case 3:
        local_16 = -1;
        local_1e = 0;
        break;
    }

    ULTIMA_1850_PrintString(_TEXT(0x42f2, "BOOOM!\n"));
    ULTIMA_43ae_AudioSweepTone(1000, 200, 5, 300);
    TOWN_0958();

    local_4 = 0;
    local_1a = 0;
    local_18 = 5;

    // 0c1a
    while (!local_4 && !local_1a && --local_18 > 0)
    {
        local_14 += local_16;
        local_1c += local_1e;

        local_e += local_16;
        local_12 += local_1e;

        local_10 = ULTIMA_3702(local_14, local_1c, D_5895_map_level);
        if (local_10 == 0)
        {
            switch (*ULTIMA_4402_GetTileAddr(local_14, local_1c))
            {
            case TILE_MAP_97:
            case TILE_MAP_98:
            case TILE_MAP_99:
            case TILE_MAP_DOOR_B8:
            case TILE_MAP_DOOR_B9:
            case TILE_MAP_DOOR_BA:
            case TILE_MAP_DOOR_BB:
                local_4 = 1;
                break;
            }
        }
        // 0cb8
        else if ((local_10 >= 0x1c && (local_10 & 0xf8) != 0x78 && (local_10 & 0xfc) != 0x2f) // BUG: expression is always true
                 || local_10 == 0x10 || local_10 == 0x11)
        {
            local_1a = 1;
            local_a = D_5876;
        }
    }

    COMSUBS_12de(local_8, local_c, local_e, local_12, 1);
    if (local_4 || local_1a)
    {
        ULTIMA_3522(local_14, local_1c);
    }

    if (local_4)
    {
        ULTIMA_1850_PrintString(_TEXT(0x42fa, "Door destroyed!\n"));
        *ULTIMA_4402_GetTileAddr(local_14, local_1c) = TILE_MAP_44;
        D_24e6 = 1;
        D_594f = 0;
    }

    if (local_1a && local_a != 0)
    {
        ULTIMA_3a74(0, 0, 0, 0, 0, 0, local_a);

        D_24e6 |= 2;
        if (D_5888 > 5)
        {
            D_5888 -= 5;
        }
        else
        {
            D_5888 = 0;
        }

        if ((local_6 = TOWN_011e(local_a)) == -1)
        {
            return;
        }

        TOWN_0052_SetNpcKilled(local_6);
        TOWN_00b0_DespawnNpc(local_6);
    }

    if (local_1a && local_a == 0)
    {
        ULTIMA_2aa8();
    }
}

// OK P1
void CMDS_0d98_IgniteTorchCmd(void)
{
    if (D_57ae == 0)
    {
        ULTIMA_1850_PrintString(_TEXT(0x430b, "None owned!\n"));
    }
    else
    {
        D_57ae--;
        if (D_5893_map_id > 0x20 && D_5893_map_id < 0x29)
        {
            ULTIMA_3ef0_IncreaseByte(&D_58a7, ULTIMA_2092_RandomRange(0, 0xf) + 0x70, 0xff);
        }
        else
        {
            D_58a7 = 0xf0;
        }
    }
}

// OK P1
void CMDS_0ddc_NewOrderCmd(void)
{
    int local_24;
    int local_26;
    S_55a8 local_22;

    ULTIMA_1850_PrintString(_TEXT(0x4318, "\n\nSwap "));
    if ((local_24 = ULTIMA_2e8e()) == -1)
    {
        ULTIMA_1850_PrintString(_TEXT(0x4320, "nobody!\n"));
        return;
    }

    ULTIMA_1850_PrintString(D_55a8_party[local_24].name);
    if (local_24 == 0)
    {
        ULTIMA_1850_PrintString(_TEXT(0x4329, "\n\n"));
        ULTIMA_1850_PrintString(D_55a8_party[0].name);
        ULTIMA_1850_PrintString(_TEXT(0x432c, " must lead!\n"));
        return;
    }

    ULTIMA_1850_PrintString(_TEXT(0x4339, "\nwith "));

    if ((local_26 = ULTIMA_2e8e()) == -1)
    {
        ULTIMA_1850_PrintString(_TEXT(0x4340, "nobody!\n"));
        return;
    }

    ULTIMA_1850_PrintString(D_55a8_party[local_26].name);
    if (local_26 == 0)
    {
        ULTIMA_1850_PrintString(_TEXT(0x4349, "\n\n"));
        ULTIMA_1850_PrintString(D_55a8_party[0].name);
        ULTIMA_1850_PrintString(_TEXT(0x434c, " must lead!\n"));
        return;
    }

    ULTIMA_1850_PrintString(_TEXT(0x4359, "!\n"));

    local_22 = D_55a8_party[local_24];
    D_55a8_party[local_24] = D_55a8_party[local_26];
    D_55a8_party[local_26] = local_22;

    D_a9fa = 1;
}

// CHECKED
void CMDS_0eb4_XitCmd(void)
{
    byte local_a;
    byte local_8;
    int local_6;
    byte local_4;

#if !defined(MATCHING_BUILD)
    local_a = 0;
#endif

    if (D_5893_map_id < 0x20 && D_5893_map_id > 0x29) // TODO: sic; BUG
    {
        // ce4c
        ULTIMA_1850_PrintString(_TEXT(0x435c, "\nNot here!\n"));
        return; // -> cfaa
    }

    local_8 = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);

    switch (D_587c_partyTile & 0xfc)
    {
    case TILE_ACTOR_AVATAR:
        ULTIMA_1850_PrintString(_TEXT(0x4368, "what?\n"));
        return;

    case TILE_ACTOR_FRIGATE_20:
        ULTIMA_1850_PrintString(_TEXT(0x436f, "\nUnder sail!\n"));
        return;

    case TILE_ACTOR_FLYING_CARPET:
        if (CMDS_073e() != 0 || ULTIMA_2c4c(0x1c, local_8) != 0)
        {
            ULTIMA_1850_PrintString(_TEXT(0x437d, "carpet!\n"));
            local_4 = 0x1b;
            D_587c_partyTile = TILE_ACTOR_AVATAR;
            break;
        }

        if (CMDS_073e() == 0)
        {
            ULTIMA_1850_PrintString(_TEXT(0x4386, "\nNo land nearby!\n"));
        }
        else
        {
            ULTIMA_1850_PrintString(_TEXT(0x4398, "\nNot here!\n"));
            // -> ce4c
        }

        return;

    case TILE_ACTOR_HORSE:
        ULTIMA_1850_PrintString(_TEXT(0x43a4, "horse!\n"));
        local_4 = D_587c_partyTile - 2;
        D_587c_partyTile = TILE_ACTOR_AVATAR;
        break;

    case TILE_ACTOR_SKIFF:
        // cef2
        if (CMDS_073e() == 0)
        {
            ULTIMA_1850_PrintString(_TEXT(0x43ac, "\nNo land nearby!\n"));
        }
        else if ((local_8 & 0xfe) == TILE_MAP_6A)
        {
            ULTIMA_1850_PrintString(_TEXT(0x43be, "\nNot here!\n"));
            // -> ce4c
        }
        else
        {
            ULTIMA_1850_PrintString(_TEXT(0x43ca, "skiff!\n"));
            local_4 = D_587c_partyTile;
            D_587c_partyTile = TILE_ACTOR_AVATAR;
            break;
        }
        return;

    case TILE_ACTOR_FRIGATE_24:
        // cf1c
        ULTIMA_1850_PrintString(_TEXT(0x43d2, "ship!\n"));
        if (CMDS_073e() != 0)
        {
            local_4 = D_587c_partyTile;
            D_587c_partyTile = TILE_ACTOR_AVATAR;

            local_a = D_5c5a[0]._7;
        }
        else if (D_5c5a[0]._7 != 0)
        {
            local_4 = D_587c_partyTile;
            D_587c_partyTile += 4;
            local_a = D_5c5a[0]._7 - 1;
        }
        else if (D_57b0 != 0)
        {
            D_57b0--;
            local_4 = D_587c_partyTile;
            D_587c_partyTile = TILE_ACTOR_FLYING_CARPET;

            local_a = D_5c5a[0]._7;
        }
        else
        {
            ULTIMA_1850_PrintString(_TEXT(0x43d9, "\nNo skiffs on board!\n"));
            return;
        }

        break;
    }

    local_6 = ULTIMA_38e4();
    ULTIMA_3a74(local_4, local_4, D_5896_map_x, D_5897_map_y, D_5895_map_level, D_5c5a[0]._5, local_6);
    D_5c5a[local_6]._7 = local_a; // BUG: local_a NOT INITIALIZED when (D_587c & 0xfc) != 0x24
    ULTIMA_2900_UpdateVitalsDisplay();

#if defined(ENABLE_BGM)
    AUDIO_PlayBgmPerMap();
#endif
}

// CHECKED
static int CMDS_1030(char* param_1)
{
    int local_c;
    int local_a;
    int local_6;
    int local_4;

    local_6 = 1;

    if (D_5893_map_id == 0x1e || D_5893_map_id == 0x1f || D_5893_map_id == 0x20)
    {
        for (local_a = 0; local_a < 3; local_a++)
        {
            if (ULTIMA_6f1e((byte*)D_444a[local_a], param_1) > -1)
                break;
        }

        if (local_a == 3 || D_5897_map_y < 2 || D_58c8[local_a] == 0xff)
        {
            // d002
            ULTIMA_1850_PrintString(_TEXT(0x440b, "\nNo effect!\n"));
            //
        }
        else
        {
            for (local_c = 0; local_c < 0x20; local_c++)
            {
                if (D_5c5a[local_c]._0_tile == TILE_ACTOR_SHADOWLORD)
                {
                    ULTIMA_1850_PrintString(_TEXT(0x4418, "\nNo effect!\n"));

                    goto END;
                }
            }

            D_58cb = local_a;
            local_c = ULTIMA_38e4();
            ULTIMA_3a74(TILE_ACTOR_SHADOWLORD, TILE_ACTOR_SHADOWLORD, D_5896_map_x, D_5897_map_y - 2, D_5895_map_level, 0, local_c);

            for (local_4 = 0x1f; local_4 >= 0; local_4--)
            {
                if (D_659e[local_4] == 0)
                {
                    break;
                }
            }

            D_5f5e[local_4]._0 = 1;
            D_5f5e[local_4]._c = local_c;
            D_5f5e[local_4]._2_x = D_5896_map_x;
            D_5f5e[local_4]._4_y = D_5897_map_y - 2;
            D_5f5e[local_4]._6_z = D_5895_map_level;

            for (local_a = 0; local_a < 4; local_a++)
            {
                D_5d5e[local_4].time[local_a] = 0;
            }

            for (local_a = 0; local_a < 3; local_a++)
            {
                D_5d5e[local_4].type[local_a] = 6;
                D_5d5e[local_4].x[local_a] = D_5896_map_x;
                D_5d5e[local_4].y[local_a] = D_5897_map_y - 2;
                D_5d5e[local_4].z[local_a] = D_5895_map_level;
            }

            D_659e[local_4] = 0xfc;

            ULTIMA_1850_PrintString(_TEXT(0x4425, "\nA shadowlord appears\n"));
            ULTIMA_2192_AudioPulse(0x28a0, 1, 30000, 2000, 2);

            D_5c5a[local_c]._0_tile = D_5c5a[local_c]._1_animTile = TILE_ACTOR_CIRCLE;
            ULTIMA_1068(0x1fc, 5, 3);
            D_5c5a[local_c]._0_tile = D_5c5a[local_c]._1_animTile = TILE_ACTOR_SHADOWLORD;

            /* FMT
                if (DAT_0003e08a_587a != 0x54) { // Icon != 0x54
                    return 0;
                }
                DAT_0003e08a_587a = 0; // Icon = 0
                FUN_00029d64_ULTIMA_5910_update_map();
                DAT_0003e08a_587a = 0x54; // Icon = 0x54
                return 0;
             */

            local_6 = 0;
        }
    }
    else
    {
        ULTIMA_1850_PrintString(_TEXT(0x443c, "\nNo effect!\n"));
    }

END:
    return local_6;
}

// OK P1
// meditate
static void CMDS_1202(int param_1, int param_2, int param_3)
{
    int local_14;
    bool local_16;
    char local_12[16];

    local_16 = 1;

    ULTIMA_1850_PrintString(_TEXT(0x4450, "\nUpon what virtue\ndost thou\nmeditate?\n\n:"));
    ULTIMA_3b1c_GetString(local_12, 0xf);

    if (ULTIMA_6f1e((byte*)D_1f4e[param_1], local_12) == -1)
    {
        local_16 = 0;
    }

    for (local_14 = 0; local_14 < 3; local_14++)
    {
        ULTIMA_1850_PrintString(_TEXT(0x4479, "\nMantra:"));
        ULTIMA_3b1c_GetString(local_12, 0xf);

        if (ULTIMA_6f1e((byte*)D_1f5e[param_1], local_12) == -1)
        {
            local_16 = 0;
        }
    }

    if (local_16 && D_1f6e[param_1] == param_2 && D_1f76[param_1] == param_3)
    {
        D_58d8[param_1] &= 0x7f;
        ULTIMA_1850_PrintString(_TEXT(0x4482, "\n\nThe Shrine is\nrestored!\n"));
        ULTIMA_3072_ShakeScreen();
        *ULTIMA_4402_GetTileAddr(param_2, param_3) = TILE_MAP_SHRINE;
        D_24e6 |= 2;
    }
    else
    {
        ULTIMA_16ba_PrintChar(10);
    }
}

// CHECKED
static void CMDS_12c8(char* param_1)
{
    bool local_8;
    register int local_4; // <- si
    register int local_a; // <- di
    byte local_c;
    int local_6;
    char** local_e;

    local_8 = 0;
    local_4 = 0;
    local_e = D_4502;

    do
    {
        if (ULTIMA_6f1e((byte*)*local_e, param_1) > -1)
        {
            ULTIMA_1850_PrintString(_TEXT(0x44d7, "\nA word of power is uttered\n"));
            ULTIMA_3072_ShakeScreen();

            local_c = GetMapViewport(4, 5);
            if (D_4512[local_4] == local_c || local_c == TILE_MAP_DF || local_c == TILE_MAP_RUINS)
            {
                local_6 = -1;
                local_a = 0;
            }
            else
            {
                local_c = GetMapViewport(5, 6);
                if (D_4512[local_4] == local_c || local_c == TILE_MAP_DF || local_c == TILE_MAP_RUINS)
                {
                    local_6 = 0;
                    local_a = 1;
                }
                else
                {
                    local_c = GetMapViewport(6, 5);
                    if (D_4512[local_4] == local_c || local_c == TILE_MAP_DF || local_c == TILE_MAP_RUINS)
                    {
                        local_6 = 1;
                        local_a = 0;
                    }
                    else
                    {
                        local_c = GetMapViewport(5, 4);
                        if (D_4512[local_4] == local_c || local_c == TILE_MAP_DF || local_c == TILE_MAP_RUINS)
                        {
                            local_6 = 0;
                            local_a = -1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }

            if (local_c == TILE_MAP_RUINS)
            {
                CMDS_1202(local_4, local_6 + D_5896_map_x, local_a + D_5897_map_y);
                return;
            }

            if (local_6 + D_5896_map_x == D_1e8a[local_4 + 0x20] &&
                local_a + D_5897_map_y == D_1eb2[local_4 + 0x20])
            {
                D_58d0[local_4] ^= 0x80;
                *ULTIMA_4402_GetTileAddr(local_6 + D_5896_map_x, local_a + D_5897_map_y) ^= D_4512[local_4] ^ TILE_MAP_DF;
                D_24e6 |= 2;
            }

            local_8 = 1;
            break;
        }
        local_e++;
        local_4++;
    } while (local_4 < 8);

    if (!local_8)
    {
        ULTIMA_1850_PrintString(_TEXT(0x44f4, "\nNo effect!\n"));
    }
}

// OK P1
int CMDS_1418_YellCmd(void)
{
    int local_24;
    char local_22[32];

    local_24 = 1;

    if ((D_587c_partyTile & 0xf8) == TILE_ACTOR_FRIGATE_20 && D_5893_map_id < 0x80)
    {
        if ((D_587c_partyTile & 0xfc) == TILE_ACTOR_FRIGATE_20)
        {
            ULTIMA_1850_PrintString(_TEXT(0x451a, "FURL!\n"));
            D_587c_partyTile += 4;
            return; // sic
        }
        else
        {
            ULTIMA_1850_PrintString(_TEXT(0x4521, "HOIST!\n"));
            D_587c_partyTile -= 4;
            return; // sic
        }
    }
    else
    {
        ULTIMA_1850_PrintString(_TEXT(0x4529, "what?\n:"));
        ULTIMA_3b1c_GetString(local_22, 0x1e);
        if (local_22[0] == 0)
        {
            ULTIMA_1850_PrintString(_TEXT(0x4531, "Nothing\n"));
            return; // sic
        }
        else
        {
            ULTIMA_16ba_PrintChar(10);
            if (D_5893_map_id >= 1 && D_5893_map_id <= 0x20)
            {
                local_24 = CMDS_1030(local_22);
            }
            else if (D_5893_map_id == 0)
            {
                CMDS_12c8(local_22);
            }
            else
            {
                ULTIMA_1850_PrintString(_TEXT(0x453a, "\nNo effect!\n"));
            }
        }
    }

    return local_24;
}

// OK P1
static int CMDS_14ba_Pushable(byte param_1)
{
    switch (param_1)
    {
    case TILE_MAP_5B:
    case TILE_MAP_CHAIR_90:
    case TILE_MAP_CHAIR_91:
    case TILE_MAP_CHAIR_92:
    case TILE_MAP_CHAIR_93:
    case TILE_MAP_DESK:
    case TILE_MAP_BARREL:
    case TILE_MAP_VANITY:
    case TILE_MAP_A9:
    case TILE_MAP_DRESSER:
    case TILE_MAP_AE:
    case TILE_MAP_TRUNK:
    case TILE_MAP_CANNON_B4:
    case TILE_MAP_CANNON_B5:
    case TILE_MAP_CANNON_B6:
    case TILE_MAP_CANNON_B7:
        return 1;
    }

    return 0;
}

// OK P1
static int CMDS_1504(int param_1, int param_2, int param_3, int param_4)
{
    if (param_1 == 1 && param_2 == 0)
    {
        param_3++;
    }
    if (param_1 == 0 && param_2 == 1)
    {
        param_3 += 2;
    }
    if (param_1 == -1 && param_2 == 0)
    {
        param_3 += 3;
    }
    if (param_4 != 0)
    {
        param_3 ^= 2;
    }

    return param_3;
}

// OK P1
static void CMDS_1548_Pushed(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7,
                 int param_8)
{
    ULTIMA_1850_PrintString(_TEXT(0x4547, "Pushed!\n"));
    *ULTIMA_4402_GetTileAddr(param_5, param_6) = param_1;
    *ULTIMA_4402_GetTileAddr(param_3, param_4) = param_2;
    param_1 &= 0xfc;
    if (param_1 == TILE_MAP_CHAIR_90 || param_1 == TILE_MAP_CANNON_B4)
    {
        *ULTIMA_4402_GetTileAddr(param_5, param_6) = CMDS_1504(param_7, param_8, param_1, 0);
    }
}

// OK P1
static void CMDS_15b0_Pulled(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7,
                 int param_8)
{
    ULTIMA_1850_PrintString(_TEXT(0x4550, "Pulled!\n"));
    *ULTIMA_4402_GetTileAddr(param_3, param_4) = param_2;
    *ULTIMA_4402_GetTileAddr(param_5, param_6) = param_1;
    param_2 &= 0xfc;
    if (param_2 == TILE_MAP_CHAIR_90 || param_2 == TILE_MAP_CANNON_B4)
    {
        *ULTIMA_4402_GetTileAddr(param_3, param_4) = CMDS_1504(param_7, param_8, param_2, 1);
    }
}

// OK P1
void CMDS_161a_PushCmd(void)
{
    int local_4;
    int local_18;
    int local_6;
    int local_1c;
    int local_a;
    int local_12;
    int local_10;
    int local_16;
    int local_14;
    int local_1a;
    int local_e;
    int local_c;
    int local_8;

    ULTIMA_39cc_SetTile(D_594f, D_5950, D_5951);
    if (ULTIMA_35ec_SelectDirection() == 0)
    {
        return;
    }

    local_12 = D_5876;
    local_18 = D_5878;

    if (D_5893_map_id > 0x7f)
    {
        local_c = D_5896_map_x;
        local_e = D_5897_map_y;
        D_5896_map_x = D_ba14[D_589e].x;
        D_5897_map_y = D_ba14[D_589e].y;
    }

    local_10 = local_12 + (uint)D_5896_map_x;
    local_16 = local_18 + (uint)D_5897_map_y;

    if (D_5893_map_id > 0x7f && COMBAT_111a(local_10, local_16) != 0)
    {
        return;
    }

    local_4 = *ULTIMA_4402_GetTileAddr(local_10, local_16);
    if (ULTIMA_368e_FindActorTileAtPos(local_10, local_16, D_5895_map_level) != 0 || CMDS_14ba_Pushable(local_4) == 0)
    {
        ULTIMA_1850_PrintString(_TEXT(0x4559, "Won't budge!\n"));
    }
    else
    {
        local_a = (local_4 & 0xfc) == TILE_MAP_CANNON_B4 ? TILE_MAP_45 : TILE_MAP_44;
        local_14 = local_10 + local_12;
        local_1a = local_16 + local_18;
        local_6 = *ULTIMA_4402_GetTileAddr(local_14, local_1a);
        local_1c = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
        if (ULTIMA_368e_FindActorTileAtPos(local_14, local_1a, D_5895_map_level) == 0 && local_6 == local_a)
        {
            CMDS_1548_Pushed(local_4, local_6, local_10, local_16, local_14, local_1a, local_12, local_18);
        }
        else
        {
            if (local_1c == local_a)
            {
                CMDS_15b0_Pulled(local_1c, local_4, D_5896_map_x, D_5897_map_y, local_10, local_16, local_12, local_18);
            }
            else
            {
                ULTIMA_1850_PrintString(_TEXT(0x4567, "Won't budge\n"));
                return;
            }
        }

        D_5896_map_x += local_12;
        D_5897_map_y += local_18;
        D_24e6 = 1;

        if (D_5893_map_id > 0x7f)
        {
            local_8 = D_ba14[D_589e].entityIdx;

            D_ba14[D_589e].x += local_12;
            D_ba14[D_589e].y += local_18;

            D_5c5a[local_8]._2_x += local_12;
            D_5c5a[local_8]._3_y += local_18;

            D_5896_map_x = local_c;
            D_5897_map_y = local_e;

            ULTIMA_5910_UpdateFrame();
        }
    }
}

// OK P1
// escape
int CMDS_17ec_Escape(void)
{
    bool local_4;
    int local_8;
    int local_6;

    ULTIMA_1850_PrintString(_TEXT(0x4574, "Escape"));

    local_4 = local_6 = 0;
    for (local_8 = 0; local_8 < 0x20; local_8++)
    {
        if ((D_ba14[local_8].flags & (COMBAT_FLAGS_PLAYER | COMBAT_FLAGS_DEAD)) == COMBAT_FLAGS_PLAYER)
        {
            local_4 = 1;
            break;
        }
    }

    if (local_4)
    {
        if ((D_58a1 & 0x80) != 0)
        {
            ULTIMA_1850_PrintString(_TEXT(0x457b, "-Not here!\n"));
            local_6 = 1;
        }
        else if (D_58a3 == 0)
        {
            ULTIMA_1850_PrintString(_TEXT(0x4587, "-Not yet!\n"));
            local_6 = 1;
        }
    }

    if (local_6 == 0)
    {
        ULTIMA_16ba_PrintChar(0x21);

        for (local_8 = 0; local_8 < 0x20; local_8++)
        {
            if (D_ba14[local_8].flags != 0)
            {
                COMBAT_1236(-local_8 - 1);
                ULTIMA_5910_UpdateFrame();
            }
        }

        for (local_8 = 0; local_8 < 0x20; local_8++)
        {
            if (D_5c5a[local_8]._0_tile != 0)
            {
                COMBAT_1236(local_8 + 1);
                ULTIMA_5910_UpdateFrame();
            }
        }

        ULTIMA_43ae_AudioSweepTone(0x4b0, 2000, 1, 0x28);
    }

    D_a9fa = 1;
    return local_6;
}

// CMDS_MIX.C?

// OK P1
// select reagents
static int CMDS_18be(void)
{
    int local_14;
    int local_16;
    int local_6;
    int local_18;
    byte local_12[8];
    int local_a;
    int local_8;
    int local_4;

    local_16 = 0;
    for (local_8 = 0; local_8 < 8; local_8++)
    {
        if (D_5850[local_8] != 0)
        {
            local_12[local_16] = local_8;
            local_16++;
        }
    }

    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x26, 9);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x27, 9);
    ULTIMA_4efc();
    ULTIMA_4e50(_TEXT(0x8f64, "Reagents:"));

    for (local_8 = 0; local_8 != local_16; local_8++)
    {
        ULTIMA_16ba_PrintChar(10);
        ULTIMA_16ba_PrintChar(0x20);
        ULTIMA_1a3e_PrintNumber(D_5850[local_12[local_8]], 2, 0x30);
        ULTIMA_16ba_PrintChar(0x20);
        ULTIMA_1850_PrintString(D_19d2[local_12[local_8]]);
    }

    // d8f2
    local_6 = local_18 = 0;

    ULTIMA_2a28(1);
    local_4 = 0;
    do
    {
        ULTIMA_1b94_SelectTextWindow(2);
        local_a = ULTIMA_266c_GetChar();
        switch (local_a)
        {
        case U5_KEY_LEFT:
        case U5_KEY_UP:
            // 19b2
            if (local_6 > 0)
            {
                ULTIMA_2a28(local_6 + 1);
                local_6--;
                ULTIMA_2a28(local_6 + 1);
            }
            break;

        case U5_KEY_RIGHT:
        case U5_KEY_DOWN:
            // 19d0
            if (local_6 < local_16 + -1)
            {
                ULTIMA_2a28(local_6 + 1);
                local_6++;
                ULTIMA_2a28(local_6 + 1);
            }
            break;

        case 0x4d:
            // 19e0
            local_4 = 1;
            ULTIMA_1850_PrintString(_TEXT(0x8f6e, "\n\n"));
            break;

        case U5_KEY_ENTER:
        case U5_KEY_SPACE:
            // 19ee
            local_14 = 0x80 >> local_12[local_6];
            local_18 ^= local_14;
            ULTIMA_1b94_SelectTextWindow(1);
            ULTIMA_1bf2_SetTextPosition(3, local_6 + 1);
            ULTIMA_16ba_PrintChar(0xfd);
            if ((local_14 & local_18) != 0)
            {
                ULTIMA_16ba_PrintChar(0xf);
            }
            else
            {
                ULTIMA_16ba_PrintChar(0x20);
            }

            ULTIMA_16ba_PrintChar(0xfd);
            break;

        case U5_KEY_ESC:
            // 1a2e
            local_18 = -1;
            local_4 = 1;

            ULTIMA_16ba_PrintChar(10);
            break;
        }
    } while (local_4 == 0);

    //local_6 = iVar6;
    ULTIMA_2a28(local_6 + 1);
    ULTIMA_1b94_SelectTextWindow(2);
    return local_18;
}

// OK P1
// select mix amount
static int CMDS_1a70(int param_1)
{
    bool local_6;
    int local_4;
    int local_8;
    int local_a;

    do
    {
        local_6 = 1;
        ULTIMA_1850_PrintString(_TEXT(0x8f72, "How much? "));
        local_4 = ULTIMA_3b9e(2);
        if (local_4 != 0)
        {
            local_a = 0x80;
            for (local_8 = 0; local_8 < 8; local_8++)
            {
                if ((param_1 & local_a) != 0 && D_5850[local_8] < local_4)
                {
                    ULTIMA_1850_PrintString(_TEXT(0x8f7e, "Insufficient reagents!\n\n"));
                    local_6 = 0;
                    break;
                }
                local_a >>= 1;
            }
        }
    } while (!local_6);

    return local_4;
}

// OK P1
void CMDS_1ad8_MixCmd(void)
{
    int local_4;
    int local_8;
    int local_c;
    int local_a;
    int local_6;

    local_8 = 0;
    for (local_a = 0; local_a < 8; local_a++)
    {
        local_8 += D_5850[local_a];
    }

    if (local_8 == 0)
    {
        ULTIMA_1850_PrintString(_TEXT(0x8f98, "No reagents owned!\n"));
        return;
    }

    ULTIMA_1850_PrintString(_TEXT(0x8fac, "For what spell?\n:"));
    local_6 = CAST2_00de_SelectSpell();
    if (local_6 == -1)
    {
        ULTIMA_1850_PrintString(_TEXT(0x8fbe, "\nNone!\n"));
    }
    else
    {
        ULTIMA_16ba_PrintChar(10);
        ULTIMA_16ba_PrintChar(0x1b);
        ULTIMA_16ba_PrintChar(0x2c); // ','
        ULTIMA_16ba_PrintChar(0x1a);
        ULTIMA_16ba_PrintChar(0x2c); // ','
        ULTIMA_16ba_PrintChar(0x18);
        ULTIMA_16ba_PrintChar(0x2c); // ','
        ULTIMA_16ba_PrintChar(0x19);
        ULTIMA_1850_PrintString(_TEXT(0x8fc6, " to move,\nRETURN selects.\nType M to mix:"));

        local_4 = CMDS_18be();
        if (local_4 >= 0)
        {
            local_8 = CMDS_1a70(local_4);
            if (local_8 > 0)
            {
                if (local_4 != 0)
                {
                    ULTIMA_1850_PrintString(_TEXT(0x8ff0, "Mixing...\n"));
                    if (D_5893_map_id > 0x20)
                    {
                        ULTIMA_20fa_WaitTicks(10);
                    }
                    else
                    {
                        ULTIMA_3ae6(10);
                    }

                    local_c = 0x80;
                    for (local_a = 0; local_a < 8; local_a++)
                    {
                        if ((local_4 & local_c) != 0)
                        {
                            D_5850[local_a] -= local_8;
                        }
                        local_c >>= 1;
                    }

                    if (local_6 >= 0 && D_1cc0[local_6] == local_4)
                    {
                        ULTIMA_1850_PrintString(_TEXT(0x8ffc, "\nDone!\n"));
                        D_57f0[local_6] += local_8;
                        if (D_57f0[local_6] > 99)
                        {
                            D_57f0[local_6] = 99;
                        }
                    }
                    else
                    {
                        ULTIMA_16ba_PrintChar(10);
                        ULTIMA_39fc_GetFirstActivePartyMember();
                        ULTIMA_2fd0(D_5876);
                    }
                }
                else
                {
                    ULTIMA_1850_PrintString(_TEXT(0x9004, "\nNothing to mix!\n"));
                }
            }
        }
    }

    ULTIMA_4e20();
    ULTIMA_4f3c();
    ULTIMA_2900_UpdateVitalsDisplay();
}

// OK P1
void CMDS_1c20_KlimbCmd(void)
{
    int local_a;
    int local_6;
    int local_4;
    int local_8;
    int local_c;
    int local_e;

    if (D_57af == 0)
    {
        ULTIMA_1850_PrintString(_TEXT(0x9016, "With what?\n"));
        return;
    }

    if (D_587c_partyTile != TILE_ACTOR_AVATAR)
    {
        ULTIMA_1850_PrintString(_TEXT(0x9022, "On foot!\n"));
        return;
    }

    if (ULTIMA_35ec_SelectDirection() == 0)
    {
        return;
    }

    local_6 = D_5876;
    local_a = D_5878;

    local_8 = D_5896_map_x + D_5876;
    local_c = D_5897_map_y + D_5878;

    local_e = *ULTIMA_4402_GetTileAddr(local_8, local_c);
    if (local_e == 13)
    {
        ULTIMA_1850_PrintString(_TEXT(0x902c, "Impassable!\n"));
    }
    else if (local_e != 12)
    {
        ULTIMA_1850_PrintString(_TEXT(0x903a, "Not climbable!\n"));
    }
    else
    {
        for (local_4 = 0; local_4 < D_585b; local_4++)
        {
            if (D_55a8_party[local_4].status != STATUS_DEAD && D_55a8_party[local_4].dex < ULTIMA_2092_RandomRange(1, 0x1e))
            {
                ULTIMA_1850_PrintString(_TEXT(0x904a, "Fell!\n"));
                ULTIMA_2a52(local_4, ULTIMA_2092_RandomRange(1, 5));
            }
        }

        MAINOUT_0354(local_6, local_a);
    }
}
