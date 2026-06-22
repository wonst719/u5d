#include "common/common.h"
#include "funcs.h"
#include "vars.h"
#include "macros.h"
#include "tiles.h"

#include "grap_drv.h"
#include "sjog.h"

#include <string.h>

// OK P1 (NOTE: combine arrays?)
static void ULTIMA_60ec_LoadSpecialMap(int param_1)
{
    int local_4;

    ULTIMA_256e_ReadFileFromDisk(/*0xa3f0*/ "BRIT.CBT", D_ad14, 0x160, param_1 * 0x160);

    for (local_4 = 0; local_4 < 6; local_4++)
    {
        D_1724[local_4] = GetCombatMapPartyX(COMBAT_MAP_SPECIAL_PARTY_SOUTH, local_4);
        D_172c[local_4] = GetCombatMapPartyY(COMBAT_MAP_SPECIAL_PARTY_SOUTH, local_4);
    }

    for (local_4 = 0; local_4 < 0x10; local_4++)
    {
        D_1704[local_4] = GetCombatMapMonsterX(local_4);
        D_1714[local_4] = GetCombatMapMonsterY(local_4);
    }
}

void ULTIMA_5f86_SpecialMapHandler(int a, int b, int c);

// OK P1
void ULTIMA_6150_Combat(int param_1)
{
    int local_6;
    bool local_8;
    int local_a;
    int local_4;

    local_a = D_5c5a[param_1]._0_tile & 0xfc;

    ULTIMA_16ba_PrintChar(10);
    ULTIMA_16ba_PrintChar(CTRL_CHAR_CENTER_TEXT);
    if (local_a < 0x40) // TILE_ACTOR_40
    {
        ULTIMA_1850_PrintString(_TEXT(0xa3fa, "PIRATES"));
    }
    else
    {
        ULTIMA_1850_PrintString(D_18b6[(local_a - 0x40) / 4]); // TILE_ACTOR_40
    }

    ULTIMA_16ba_PrintChar(CTRL_CHAR_UNCENTER_TEXT);
    ULTIMA_1850_PrintString(_TEXT(0xa402, "\n\n"));

    local_6 = *ULTIMA_4402_GetTileAddr(D_5c5a[param_1]._2_x, D_5c5a[param_1]._3_y);
    if (local_6 < TILE_MAP_POISON || (local_6 & 0xfe) != TILE_MAP_6A && ((local_6 & 0xf0) == TILE_MAP_60))
    {
        local_8 = true;
    }
    else
    {
        local_8 = false;
    }

    if (local_a == 0xfc) // 61f3
    {
        local_4 = 10;
        if (D_57b5 != 0)
        {
            ULTIMA_1850_PrintString(_TEXT(0xa406, "The Sceptre is reclaimed!\n"));
            ULTIMA_2192_AudioPulse(0xfd2, 1, 65000, 1, 1);
            D_57b5 = 0;
        }
    }
    else
    {
        if (((byte)local_a & 0xf0) == 0x80) // 622c
        {
            local_8 = 1;
        }

        if ((D_587c_partyTile & 0xf8) == TILE_ACTOR_FRIGATE_20) // 623a
        {
            if (local_a == TILE_ACTOR_PIRATE)
            {
                local_4 = 0xe;
            }
            else if (local_8)
            {
                local_4 = 0xb;
            }
            else
            {
                local_4 = 0xd;
            }
        }
        else if (local_a == TILE_ACTOR_PIRATE)
        {
            local_4 = 0xc;
        }
        else if (local_8)
        {
            local_4 = 0xf;
        }
        else
        {
            switch (local_6)
            {
            case TILE_MAP_WATER_1:
            case TILE_MAP_WATER_2:
            case TILE_MAP_WATER_3:
                local_4 = 0xf;
                break;
            case TILE_MAP_POISON:
                local_4 = 1;
                break;
            case TILE_MAP_GRASS:
                local_4 = 2;
                break;
            case TILE_MAP_6:
            case TILE_MAP_8:
                local_4 = 3;
                break;
            case TILE_MAP_7:
            case TILE_MAP_1E:
            case TILE_MAP_1F:
                local_4 = 4;
                break;
            case TILE_MAP_9:
            case TILE_MAP_A:
                local_4 = 5;
                break;
            case TILE_MAP_B:
            case TILE_MAP_C:
            case TILE_MAP_D:
            case TILE_MAP_E:
            case TILE_MAP_F:
                local_4 = 6;
                break;
            case TILE_MAP_1D:
            case TILE_MAP_48:
            case TILE_MAP_49:
            case TILE_MAP_6A:
            case TILE_MAP_6B:
                local_4 = 7;
                break;
            case TILE_MAP_44:
                local_4 = 8;
                break;
            default:
                if (D_5893_map_id != 0)
                {
                    local_4 = 8;
                }
                else
                {
                    local_4 = 2;
                }
                break;
            }
        }
    }

    ULTIMA_60ec_LoadSpecialMap(local_4);
    ULTIMA_5f86_SpecialMapHandler(0, param_1, 0);

    SJOG_203e(param_1);
    ULTIMA_5e4a();
    ULTIMA_4f7c(0);
}

// OK P1
void ULTIMA_6360_Camping(int param_1, int param_2)
{
    ULTIMA_60ec_LoadSpecialMap(0);
    ULTIMA_5f86_SpecialMapHandler(4, param_1, param_2);
    ULTIMA_5e4a();
}

// OK P1
// draw frame
void ULTIMA_637e_DrawFrame(void)
{
    int local_4; // unused
 
    // black
    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    ULTIMA_0aa6_GRAP_3f_FillRect(0, 0, 319, 199);

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
    ULTIMA_0aa6_GRAP_3f_FillRect(0, 0, 319, 6);
    ULTIMA_0aa6_GRAP_3f_FillRect(0, 185, 191, 191);
    ULTIMA_0aa6_GRAP_3f_FillRect(0, 0, 6, 191);
    ULTIMA_0aa6_GRAP_3f_FillRect(185, 0, 191, 191);
    ULTIMA_0aa6_GRAP_3f_FillRect(313, 0, 319, 87);
    ULTIMA_0aa6_GRAP_3f_FillRect(192, 80, 312, 87);
    ULTIMA_0aa6_GRAP_3f_FillRect(192, 0x39, 312, 63);

    ULTIMA_1cca_SetTextForegroundColor(D_13b2_frame_color);
    ULTIMA_1bf2_SetTextPosition(0, 0);
    ULTIMA_16ba_PrintChar(0x7b);
    ULTIMA_1bf2_SetTextPosition(39, 0);
    ULTIMA_16ba_PrintChar(0x7c);
    ULTIMA_1bf2_SetTextPosition(0, 23);
    ULTIMA_16ba_PrintChar(0x7d);

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(7, 7, 7, 184);
    ULTIMA_0f90_GRAP_Pen(184, 184);
    ULTIMA_0f90_GRAP_Pen(184, 7);
    ULTIMA_0f90_GRAP_Pen(7, 7);
    ULTIMA_0b10_GRAP_Line(191, 191, 191, 87);
    ULTIMA_0f90_GRAP_Pen(319, 87);
    ULTIMA_0b10_GRAP_Line(191, 7, 312, 7);
    ULTIMA_0f90_GRAP_Pen(312, 56);
    ULTIMA_0f90_GRAP_Pen(191, 56);
    ULTIMA_0f90_GRAP_Pen(191, 7);
    ULTIMA_0b10_GRAP_Line(191, 63, 312, 63);
    ULTIMA_0f90_GRAP_Pen(312, 80);
    ULTIMA_0f90_GRAP_Pen(191, 80);
    ULTIMA_0f90_GRAP_Pen(191, 63);

    ULTIMA_1cca_SetTextForegroundColor(D_13b0_white_color);
}

// CHECKED
// place actor on combat map
// param_2: player / monster?
// return: placed actor idx
int ULTIMA_6506(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    int local_a;
    int local_8;
    int local_6;
    CombatEntity* local_4;

#if !defined(MATCHING_BUILD)
    local_4 = NULL;
#endif

    local_a = 0;
    local_6 = 0;
    local_8 = -1;

    if (param_2 != 2)
    {
        if (param_2 == 0)
        {
            local_a = 6;
        }

        // 6531
        for (local_6 = local_a; local_6 < 0x20; local_6++)
        {
            // 653f
            // 6577
            if (D_ba14[local_6].flags == 0) // combat actor slot not occupied?
            {
                local_4 = &D_ba14[local_6];
                local_8 = local_6;

                // 6587
                if (param_2 == 1 && D_55a8_party[param_1].status != STATUS_DEAD) // player?
                {
                    // 65a0
                    local_4->dex = D_55a8_party[param_1].dex;
                    local_4->turnTimer = 36 - local_4->dex;
                    local_4->flags = COMBAT_FLAGS_PLAYER;
                    // 65b4
                    if (D_55a8_party[param_1].status != STATUS_GOOD && D_55a8_party[param_1].status != STATUS_POISONED)
                    {
                        local_4->flags |= COMBAT_FLAGS_ASLEEP;
                    }
                }

                // 65c5
                if (param_2 == 0) // monster?
                {
                    local_4->hp = D_13bc[param_1]._5_maxHp;
                    local_4->dex = ULTIMA_3aae_Random(7) - 4 + D_13bc[param_1]._1;
                    if (local_4->dex > 0x1e)
                    {
                        local_4->dex = D_13bc[param_1]._1;
                    }

                    local_4->turnTimer = 36 - local_4->dex;
                    local_4->flags = COMBAT_FLAGS_MONSTER;
                    if (param_1 == 8 || param_1 == 9)
                    {
                        // 6609
                        local_4->flags = COMBAT_FLAGS_DEAD;
                    }
                }

                // 660d
                local_4->entityIdx = param_1;
                local_4->x = param_3;
                local_4->y = param_4;
                break;
            }
        }
    }

    // 6625
    if (local_8 > -1 || param_2 == 2)
    {
        // 6634
        for (local_6 = 0; local_6 < 0x20; local_6++)
        {
            if (D_5c5a[local_6]._0_tile == 0)
            {
                // 6685
                if (param_2 == 0)
                {
                    local_4->actorIdx = local_6;
                    
                    D_5c5a[local_6]._1_animTile = D_5c5a[local_6]._0_tile = param_1 * 4 + TILE_ACTOR_WIZARD; // local_14
                }

                // 669a
                if (param_2 == 1)
                {
                    local_4->actorIdx = local_6;
                }

                // 66a6
                if (param_2 == 2)
                {
                    D_5c5a[local_6]._1_animTile = D_5c5a[local_6]._0_tile = param_1;
                    local_8 = local_6;
                }

                // 66bb
                D_5c5a[local_6]._2_x = param_3;
                D_5c5a[local_6]._3_y = param_4;
                D_5c5a[local_6]._4_z = param_5;
                D_5c5a[local_6]._7 = 0xff;
                if (param_2 == 0)
                {
                    D_5c5a[local_6]._5 = local_4->hp;
                }
                else
                {
                    D_5c5a[local_6]._5 = param_1;
                }

                // 66f8
                if (param_2 != 2)
                {
                    local_4->actorIdx = local_6;
                }

                break;
            }
        }

        // 6706
        if (param_2 != 2 && local_6 == 0x20 && local_8 > -1)
        {
            local_8 = -1;
        }
    }
    else
    {
        local_8 = -1;
    }

    // 6751
    if (local_8 >= 0)
    {
        for (local_6 = 0; local_6 < 0x20; local_6++)
        {
            if (D_5c5a[D_ba14[local_6].actorIdx]._7 == local_8)
            {
                D_5c5a[D_ba14[local_6].actorIdx]._7 = 0xff;
            }
        }
    }

    return local_8;
}

// OK P1
void ULTIMA_6794(int param_1)
{
    CombatEntity* local_4 = &D_ba14[param_1];
    if ((local_4->flags & COMBAT_FLAGS_PLAYER) != 0 && (local_4->flags & (COMBAT_FLAGS_DEAD | COMBAT_FLAGS_ASLEEP)) == 0)
    {
        if (D_55a8_party[local_4->entityIdx].equips[4] == 42)
        {
            D_5c5a[local_4->actorIdx]._1_animTile = TILE_ACTOR_1D;
            local_4->flags |= COMBAT_FLAGS_INVISIBLE;
        }
        else if (D_55a8_party[local_4->entityIdx].equips[4] == 44)
        {
            ULTIMA_400c(local_4->entityIdx); // sic
        }
    }
}

// OK P1
void ULTIMA_6800(int param_1)
{
    CombatEntity* local_4 = &D_ba14[param_1];
    if ((local_4->flags & COMBAT_FLAGS_ASLEEP) != 0)
    {
        if ((local_4->flags & COMBAT_FLAGS_PLAYER) != 0)
        {
            D_55a8_party[local_4->entityIdx].status = STATUS_GOOD;
            if ((local_4->flags & COMBAT_FLAGS_INVISIBLE) != 0)
            {
                D_5c5a[local_4->actorIdx]._1_animTile = TILE_ACTOR_1D;
            }
            else
            {
                D_5c5a[local_4->actorIdx]._1_animTile = D_5c5a[local_4->actorIdx]._0_tile;
            }
        }
        else
        {
            D_5c5a[local_4->actorIdx]._6 = 0;
        }
        local_4->flags &= ~COMBAT_FLAGS_ASLEEP;
    }

    ULTIMA_2900_UpdateVitalsDisplay();
}

// OK P1
void ULTIMA_6880(int param_1)
{
    if ((D_ba14[param_1].flags & COMBAT_FLAGS_PLAYER) == 0 || D_55a8_party[D_ba14[param_1].entityIdx].status != STATUS_POISONED)
    {
        ULTIMA_68ae(param_1);
    }
}

// OK P1
void ULTIMA_68ae(int param_1)
{
    CombatEntity* local_4 = &D_ba14[param_1];
    if ((local_4->flags & COMBAT_FLAGS_PLAYER) != 0)
    {
        if (D_55a8_party[local_4->entityIdx].status != STATUS_DEAD)
        {
            D_55a8_party[local_4->entityIdx].status = STATUS_SLEEP;
            local_4->flags |= COMBAT_FLAGS_ASLEEP;
            D_5c5a[local_4->actorIdx]._1_animTile = TILE_ACTOR_SLEEP;

            if (param_1 == D_587b)
            {
                D_587b = 0xff;
            }

            D_58a2 = 4;

            ULTIMA_2900_UpdateVitalsDisplay();

            if ((D_58a1 & 4) == 0)
            {
                ULTIMA_5910_UpdateFrame();
            }
        }
    }
    else
    {
        local_4->flags |= COMBAT_FLAGS_ASLEEP;
        D_58a2 = 4;
        D_5c5a[local_4->actorIdx]._6 = 0xff;

        ULTIMA_5910_UpdateFrame();
    }
}

// CHECKED
// initialize combat entities
void ULTIMA_6936(void)
{
    byte local_c;
    int local_a;
    byte local_10;
    int local_6;
    byte local_8;
    byte local_e;
    CombatEntity* local_4;

    local_10 = 0;

    // clear
    for (local_6 = 0; local_6 < 0x20; local_6++)
    {
        local_4 = &D_ba14[local_6];

        D_5c5a[local_6]._3_y = D_5c5a[local_6]._4_z = D_5c5a[local_6]._5 = D_5c5a[local_6]._0_tile = D_5c5a[local_6]._1_animTile = D_5c5a[local_6]._2_x = D_5c5a[local_6]._6 = 0;

        local_4->hp = local_4->dex = local_4->flags = local_4->entityIdx = 0;

        local_4->actorIdx = local_4->turnTimer = local_4->x = local_4->y = 0;
    }

    // place player party
    for (local_6 = 0; local_6 < D_585b; local_6++)
    {
        if (D_55a8_party[local_6].status != STATUS_DEAD)
        {
            if (D_55a8_party[local_6].equips[4] == 42)
            {
                local_10 = 42;
            }

            if (D_55a8_party[local_6].equips[4] == 44)
            {
                local_10 = 44;
            }

            if (local_10 != 0)
            {
                local_a = ULTIMA_2092_RandomRange(0, 0xf);
                if (local_a == 0xb)
                {
                    ULTIMA_1850_PrintString(_TEXT(0xa422, "A ring has vanished!\n"));
                    ULTIMA_43ae_AudioSweepTone(0x4b0, 2000, 1, 0x28);
                    ULTIMA_6e60(local_6, local_10);
                }
                local_10 = 0;
            }

            local_8 = D_1724[local_6];
            local_e = D_172c[local_6];
            local_a = ULTIMA_6506(local_6, 1, local_8, local_e, D_5895_map_level);

            D_5c5a[D_ba14[local_a].actorIdx]._7 = 0xff;

            // setup tile (according to class)
            switch (D_55a8_party[local_6].cls)
            {
            case CLASS_AVATAR:
                D_5c5a[D_ba14[local_a].actorIdx]._0_tile = TILE_ACTOR_4C;
                break;
            case CLASS_FIGHTER:
            case CLASS_PALADIN:
            case CLASS_RANGER:
                D_5c5a[D_ba14[local_a].actorIdx]._0_tile = TILE_ACTOR_FIGHTER;
                break;
            case CLASS_DRUID:
            case CLASS_MAGE:
                D_5c5a[D_ba14[local_a].actorIdx]._0_tile = TILE_ACTOR_WIZARD;
                break;
            case CLASS_BARD:
            case CLASS_SHEPHERD:
            case CLASS_TINKER:
                D_5c5a[D_ba14[local_a].actorIdx]._0_tile = TILE_ACTOR_BARD_44;
                break;
            }

            D_5c5a[D_ba14[local_a].actorIdx]._1_animTile = D_5c5a[D_ba14[local_a].actorIdx]._0_tile;

            if (D_55a8_party[local_6].status == STATUS_SLEEP)
            {
                ULTIMA_68ae(local_a);
            }
            else
            {
                ULTIMA_6794(local_a);
            }
        }
    }

    if (GetCombatMap(5, 5) == 0xdc)
    {
        local_c = ULTIMA_6506(1, 2, 5, 5, D_5895_map_level);
        D_5c5a[local_c]._5 = D_5895_map_level * 3 + 7;
        GetCombatMap(5, 5) = D_bb15;
    }
}

// CHECKED
// prepare combat
void ULTIMA_6bc2(int param_1, int param_2)
{
    int local_2e;
    byte local_2c;
    byte local_30;
    int local_2a;
    int local_28[16];
    int local_8;
    int local_6;
    int local_4;

    if (param_2 >= 0x100)
    {
        param_2 -= 0x100;
        local_8 = 0;
    }
    else
    {
        local_8 = 1;
    }

    D_58a0 = 0;
    if ((param_1 & 4) == 0)
    {
        ULTIMA_6936();
    }

    for (local_2e = 0; local_2e < 0x10; local_2e++)
    {
        local_28[local_2e] = local_2e;
    }

    if ((param_1 & 4) != 0)
    {
        // shuffle
        for (local_2a = 0; local_2a < 0xf; local_2a++)
        {
            local_2e = ULTIMA_2092_RandomRange(0, 0xf);
            // swap
            local_6 = local_28[local_2a];
            local_28[local_2a] = local_28[local_2e];
            local_28[local_2e] = local_6;
        }
    }

    if (param_1 != 0x80 || param_1 != 0x4) // BUG: expression always true
    {
        ULTIMA_1850_PrintString(_TEXT(0xa438, "*** CONFLICT ***\n"));
    }

    if (D_5894 != 0 && D_5894 < 0x21 && param_2 != 0xc && local_8 != 0)
    {
        local_6 = 1;
    }
    else
    {
        local_6 = D_13bc[param_2]._6;
    }

    if (local_6 != 8 && local_6 != 0x10 && local_6 != 1)
    {
        local_6 = ULTIMA_2092_RandomRange(1, local_6);
        if (D_5959 != 0)
        {
            local_6 = ULTIMA_2092_RandomRange(1, local_6);
        }
        ULTIMA_5910_UpdateFrame();
        if (local_6 > 0x1f - 6)
        {
            local_6 = 0x1a;
        }
    }

    local_2c = D_1704[local_28[0]];
    local_30 = D_1714[local_28[0]];
    ULTIMA_6506(param_2, 0, local_2c, local_30, D_5895_map_level);

    local_2e = local_6 / 4 + 1;
    for (local_2a = 1; local_2a < local_6; local_2a++)
    {
        local_4 = param_2;
        if (local_2a < local_2e && ULTIMA_3aae_Random(8) == 0)
        {
            local_4 = D_16d4[param_2];
        }
        local_2c = D_1704[local_28[local_2a]];
        local_30 = D_1714[local_28[local_2a]];
        ULTIMA_6506(local_4, 0, local_2c, local_30, D_5895_map_level);
    }
}

// OK P1
int ULTIMA_6d82(int param_1, int param_2)
{
    if (param_1 > -1 && param_1 < 11 && param_2 > -1 && param_2 < 11)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// OK P1
// calc player def
int ULTIMA_6da8(int param_1)
{
    int local_6;
    S_55a8* local_4;

    local_6 = 0;
    local_4 = &D_55a8_party[param_1];

    if (D_5894 == 40 && local_4->equips[1] != 0x0f)
    {
        return 0;
    }
    else
    {
#if defined(MATCHING_BUILD)
        // BUG: the comparison is always false on DOS16, and always true on FMT
#define CMP(a) ((a) > -1)
#else
#define CMP(a) (((s8)(a)) > -1)
#endif
        if (CMP(local_4->equips[0]))
        {
            // 6dd6
            local_6 += D_1634[local_4->equips[0]];
        }

        if (CMP(local_4->equips[1]))
        {
            // 6dec
            local_6 += D_1634[local_4->equips[1]];
        }

        if (CMP(local_4->equips[2]))
        {
            // 6dff
            local_6 += D_1634[local_4->equips[2]];
        }

        if (CMP(local_4->equips[3]))
        {
            // 6e12
            local_6 += D_1634[local_4->equips[3]];
        }

        if (CMP(local_4->equips[4]))
        {
            // 6e25
            local_6 += D_1634[local_4->equips[4]];
        }

        if (CMP(local_4->equips[5]))
        {
            // 6e38
            local_6 += D_1634[local_4->equips[5]];
        }

        // 6e4b
        if (D_587a == 80)
        {
            local_6 += 3;
        }
    }

    return local_6;
}

// OK P1
// unequip
int ULTIMA_6e60(int param_1, int param_2)
{
    int local_4;

    local_4 = 1;

    if (param_2 == D_55a8_party[param_1].equips[0])
    {
        D_55a8_party[param_1].equips[0] = 0xff;
    }
    else if (param_2 == D_55a8_party[param_1].equips[1])
    {
        D_55a8_party[param_1].equips[1] = 0xff;
    }
    else if (param_2 == D_55a8_party[param_1].equips[2])
    {
        D_55a8_party[param_1].equips[2] = 0xff;
    }
    else if (param_2 == D_55a8_party[param_1].equips[3])
    {
        D_55a8_party[param_1].equips[3] = 0xff;
    }
    else if (param_2 == D_55a8_party[param_1].equips[4])
    {
        D_55a8_party[param_1].equips[4] = 0xff;

        if (param_2 == 0x2a && D_5893_map_id > 0x7f && D_589e < 0x20)
        {
            D_ba14[D_589e].flags &= ~COMBAT_FLAGS_INVISIBLE;
        }
    }
    else if (param_2 == D_55a8_party[param_1].equips[5])
    {
        D_55a8_party[param_1].equips[5] = 0xff;
    }
    else
    {
        local_4 = 0;
    }

    // BUG: equip def is recalculated but discarded.
    ULTIMA_6da8(param_1);

    return local_4;
}

// from FMT
u8 DAT_000738d8[] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x28, 0x28, 0x28, 0x28, 0x28, 0x20, 0x20,
                     0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
                     0x88, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
                     0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
                     0x10, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
                     0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x10, 0x10, 0x10, 0x10, 0x10,
                     0x10, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
                     0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x10, 0x10, 0x10, 0x10, 0x20};

// STUB (asm)
// from FMT (27c98)
int ULTIMA_6f1e(byte* param_1, char* param_2)
{
    byte bVar1;
    int iVar2;
    int iVar3;
    int local_18;
    char local_14[10];

    local_18 = -1;
    memset(local_14, 0, 10);

    for (iVar2 = 0; iVar2 < 9 && (iVar3 = iVar2, param_1[iVar2] != 0); iVar2++)
    {
        bVar1 = param_1[iVar2] & 0x7f;
        if ((DAT_000738d8[bVar1] & 2) != 0)
        {
            bVar1 = (param_1[iVar2] & 0x7fU) - 0x20;
        }
        local_14[iVar2] = (char)bVar1;
    }

    iVar2 = strncmp(local_14, param_2, iVar3);
    if (iVar2 == 0)
    {
        local_18 = 0;
    }

    return local_18;
}

// STUB (asm)
static int ULTIMA_6f90(char* di)
{
    // repne scasb
    return strlen(di);
}

// STUB (asm)
void ULTIMA_6f9e(int param_1)
{
    // bx: not initialized
    byte bl = 0;
    byte bh = 0;
    int ax = param_1 + 3;
    DRV_6c(ax, bl, bh);
}

// STUB (asm)
void ULTIMA_6fbc(int param_1)
{
    // bx: not initialized
    byte bl = 0;
    byte bh = 0;
    DRV_6c(param_1, bl, bh);
}

void DRV_60_CF0(void* ax);

// STUB (asm)
void ULTIMA_6fd6_GRAP_AnimateTiles(void)
{
    // CLC
    // ax: D_539c
    DRV_60_CF0(D_539c);
    //debug("ULTIMA_6fd6");
}

// NOT MATCHING (asm)
int ULTIMA_6ff0(register int param_1, register int param_2)
{
    if ((param_1 < 0xb) && (param_2 < 0xb))
    {
        if ((param_1 > 5) || (param_2 > 5))
        {
            if (param_1 > 5)
            {
                param_1 = 10 - param_1;
            }
            if (param_2 > 5)
            {
                param_2 = 10 - param_2;
            }
        }

        return D_6aa8[param_1 + param_2 * 6];
    }

    return 0;
}
