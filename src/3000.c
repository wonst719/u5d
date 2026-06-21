#include "common/common.h"
#include "time/time.h"

#include "vars.h"
#include "funcs.h"
#include "macros.h"
#include "tiles.h"

#include "cast.h"
#include "cast2.h"
#include "cmds.h"
#include "dnglook.h"
#include "dungeon.h"
#include "lookobj.h"
#include "sjog.h"
#include "talk.h"
#include "town.h"
#include "zstats.h"

int MAINOUT_06ec_AttackCmd(void);
int MAINOUT_08de_EnterCmd(void);

// OK P1
// shake screen
void ULTIMA_3072_ShakeScreen(void)
{
    int i;
    int local_8;

    ULTIMA_0f6e_GRAP_1b_TransferFullscreen(0, 1);
    ULTIMA_0c22_GRAP_0f_SelectPage(1);

#if defined(TARGET_SDL)
    ULTIMA_223c_AudioWhiteNoise(0x13, 16000, 0x96);
#endif

    for (local_8 = 0; local_8 < 8; local_8++)
    {
        for (i = 8; i <= 0xb3; i += 3)
        {
            ULTIMA_71ca_DRV_27_ScrollTextWindow1(8, i, 0xb7, i + 4, 2);
#if defined(MATCHING_BUILD)
            ULTIMA_22e2_PcspkOn(ULTIMA_2092_RandomRange(0x13, 0x96));
#endif
        }

#if defined(TARGET_DOS32)
        ULTIMA_223c_AudioWhiteNoise(0x13, 700, 0x96);
#elif defined(ENABLE_SPEED_FIX)
        TIME_SleepMs(70);
#endif

        for (i = 8; i <= 0xb3; i += 3)
        {
            ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 8, i, 0xb7, i + 4);
#if defined(MATCHING_BUILD)
            ULTIMA_22e2_PcspkOn(ULTIMA_2092_RandomRange(0x13, 0x96));
#endif
        }

#if defined(TARGET_DOS32)
        ULTIMA_223c_AudioWhiteNoise(0x13, 300, 0x96);
#elif defined(ENABLE_SPEED_FIX)
        TIME_SleepMs(30);
#endif

        for (i = 0xb3; i >= 8; i -= 3)
        {
            ULTIMA_7200_DRV_27_ScrollTextWindow2(8, i, 0xb7, i + 4, 2);
#if defined(MATCHING_BUILD)
            ULTIMA_22e2_PcspkOn(ULTIMA_2092_RandomRange(0x13, 0x96));
#endif
        }

#if defined(TARGET_DOS32)
        ULTIMA_223c_AudioWhiteNoise(0x13, 700, 0x96);
#elif defined(ENABLE_SPEED_FIX)
        TIME_SleepMs(70);
#endif

        for (i = 0xb3; i >= 8; i -= 3)
        {
            ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 8, i, 0xb7, i + 4);
#if defined(MATCHING_BUILD)
            ULTIMA_22e2_PcspkOn(ULTIMA_2092_RandomRange(0x13, 0x96));
#endif
        }

#if defined(TARGET_DOS32)
        ULTIMA_223c_AudioWhiteNoise(0x13, 300, 0x96);
#elif defined(ENABLE_SPEED_FIX)
        TIME_SleepMs(30);
#endif
    }

    ULTIMA_0c22_GRAP_0f_SelectPage(0);
#if defined(MATCHING_BUILD)
    ULTIMA_230e_PcspkOff();
#endif
}

static void ULTIMA_3c9a_HoleUpCmd(void);

// OK P1
int ULTIMA_3178_ProcessCommand(int param_1)
{
    int ret;
    int local_6;

    ret = 1;
    switch (param_1)
    {
    case U5_KEY_CTRL_B:
        ULTIMA_1850_PrintString(_TEXT(0xa110, "Buffer O"));
        D_538c = !D_538c;
        if (D_538c != 0) 
        {
            ULTIMA_1850_PrintString(_TEXT(0xa11a, "ff\n"));
        }
        else
        {
            ULTIMA_1850_PrintString(_TEXT(0xa11e, "n\n"));
        }

        ret = 0;
        break;
    case U5_KEY_SPACE:
        /* ' ' Pass */
        if (D_5893_map_id == 0 && D_5955 != 0)
        {
            ULTIMA_1850_PrintString(_TEXT(0xa122, "Sheets in irons!\n"));
            D_5955 = 0;
        }
        else
        {
            ULTIMA_1850_PrintString(_TEXT(0xa134, "Pass\n"));
        }
        break;
    case 0x41:
        /* 'A' */
        // 3216
        ret = D_5893_map_id == 0 ?
            MAINOUT_06ec_AttackCmd() :
                D_5893_map_id < 0x21 ?
            TOWN_09e6_AttackCmd() :
            DUNGEON_1d4a_AttackCmd();
        break;
    case 0x42:
        /* 'B' Board */
        ULTIMA_1850_PrintString(_TEXT(0xa13a, "Board "));
        ret = CMDS_07f6_BoardCmd();
        break;
    case 0x43:
        /* 'C' Cast */
        ULTIMA_1850_PrintString(_TEXT(0xa142, "Cast...\n"));
        ret = CAST_0dba_CastSpellCmd();
        break;
    case 0x44:
        /* 'D' What? */
        ULTIMA_1850_PrintString(_TEXT(0xa14c, "D-What?\n"));
        ret = 0;
        break;
    case 0x45:
        /* 'E' Enter */
        if (D_5893_map_id == 0)
        {
            ret = MAINOUT_08de_EnterCmd();
            break;
        }
        ULTIMA_1850_PrintString(_TEXT(0xa156, "Enter what?\n"));
        break;
    case 0x46:
        /* 'F' Fire */
        ULTIMA_1850_PrintString(_TEXT(0xa164, "Fire-"));
        CMDS_0aea_FireCmd();
        break;
    case 0x47:
        /* 'G' Get */
        if (D_5893_map_id < 0x21)
        {
            ULTIMA_1850_PrintString(_TEXT(0xa16a, "Get-"));
        }
        SJOG_18ce_GetCmd();
        break;
    case 0x48:
        /* 'H' Hole up */
        if (D_5893_map_id == 0 || D_5893_map_id > 0x20)
        {
            // outmap_hole_up_cmd
            ULTIMA_3c9a_HoleUpCmd();
            break;
        }
        local_6 = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
        ULTIMA_1850_PrintString(_TEXT(0xa170, "Hole up- "));
        if (local_6 != TILE_MAP_BED)
        {
            ULTIMA_1850_PrintString(_TEXT(0xa17a, "Only in bed!\n"));
        }
        else
        {
            CMDS_0552_HoleUpCmd();
        }
        break;
    case 0x49:
        /* 'I' Ignite torch */
        ULTIMA_1850_PrintString(_TEXT(0xa188, "Ignite torch!\n"));
        CMDS_0d98_IgniteTorchCmd();
        break;
    case 0x4a:
        /* 'J' Jimmy */
        ULTIMA_1850_PrintString(_TEXT(0xa198, "Jimmy-"));
        SJOG_0d4a_JimmyCmd();
        break;
    case 0x4b:
        /* 'K' Klimb */
        if (D_5893_map_id == 0)
        {
            ULTIMA_1850_PrintString(_TEXT(0xa1a0, "Klimb-"));
            CMDS_1c20_KlimbCmd();
        }
        else if (D_5893_map_id < 0x21)
        {
            ret = TOWN_0b82_KlimbCmd();
        }
        else
        {
            ret = DUNGEON_1e10_KlimbCmd();
        }
        break;
    case 0x4c:
        /* 'L' Look */
        ULTIMA_1850_PrintString(_TEXT(0xa1a8, "Look"));
        if (D_5893_map_id > 0x20 && D_5893_map_id < 0x29)
        {
            /* 0x21..0x28 (Dungeon) */
            ULTIMA_1850_PrintString(_TEXT(0xa1ae, "...\n"));
            DNGLOOK_0000_LookCmdInDungeon();
        }
        else
        {
            ULTIMA_16ba_PrintChar(0x2d);
            LOOKOBJ_099c_LookCmd();
        }
        break;
    case 0x4d:
        /* 'M' Mix */
        ULTIMA_1850_PrintString(_TEXT(0xa1b4, "Mix Reagents\n\n"));
        CMDS_1ad8_MixCmd();
        break;
    case 0x4e:
        /* 'N' New order */
        ULTIMA_1850_PrintString(_TEXT(0xa1c4, "New Order"));
        CMDS_0ddc_NewOrderCmd();
        break;
    case 0x4f:
        /* 'O' Open */
        ULTIMA_1850_PrintString(_TEXT(0xa1ce, "Open-"));
        SJOG_1374_OpenCmd();
        break;
    case 0x50:
        /* 'P' Push */
        if (D_5893_map_id > 0x20 && D_5893_map_id < 0x29)
        {
            /* Cannot push in dungeons */
            ULTIMA_1850_PrintString(_TEXT(0xa1d4, "Push\nNot here!\n"));
            ret = 0;
        }
        else
        {
            ULTIMA_1850_PrintString(_TEXT(0xa1e4, "Push-"));
            CMDS_161a_PushCmd();
        }
        break;
    case 0x51:
        /* 'Q' Quit */
        ULTIMA_1850_PrintString(_TEXT(0xa1ea, "Quit:"));
        CAST2_10fe_SaveGame();
        ret = 0;
        break;
    case 0x52:
        /* 'R' Ready */
        ULTIMA_1850_PrintString(_TEXT(0xa1f0, "Ready...\n\n"));
        ZSTATS_1296_ReadyCmd();
        break;
    case 0x53:
        /* 'S' Search */
        if (D_5893_map_id < 0x21)
        {
            ULTIMA_1850_PrintString(_TEXT(0xa1fc, "Search-"));
        }
        else
        {
            ULTIMA_1850_PrintString(_TEXT(0xa204, "Search...\n"));
        }
        SJOG_095c_SearchCmd();
        break;
    case 0x54:
        /* 'T' Talk */
        if (D_5893_map_id == 0)
        {
            ULTIMA_1850_PrintString(_TEXT(0xa210, "Talk-"));
            if (ULTIMA_35ec_SelectDirection() == 0)
                break;
            ULTIMA_1850_PrintString(_TEXT(0xa216, "Funny, no response!\n"));
        }
        else
        {
            if (D_5893_map_id > 0x20)
            {
                ULTIMA_1850_PrintString(_TEXT(0xa22c, "Talk-Funny, no response!\n"));
            }
            else
            {
                ULTIMA_1850_PrintString(_TEXT(0xa246, "Talk-"));
                if (TALK_041c_TalkCmd() != 0)
                {
                    ret = 2;
                }
            }
        }
        break;
    case 0x55:
        /* 'U' Use item */
        ULTIMA_1850_PrintString(_TEXT(0xa24c, "Use item\n\n"));
        CAST_1792_UseCmd();
        break;
    case 0x56:
        /* 'V' View a gem */
        ULTIMA_1850_PrintString(_TEXT(0xa258, "View a gem!\n"));
        if (D_57ad != 0)
        {
            D_57ad--;
            if (D_5893_map_id < 0x21)
            {
                LOOKOBJ_10fc_ViewCmd(D_5896_map_x, D_5897_map_y);
            }
            else
            {
                DNGLOOK_06a8_ViewCmd();
            }
            break;
        }
        ULTIMA_1850_PrintString(_TEXT(0xa266, "You have none!\n"));
        break;
    case 0x57:
        /* 'W' What? */
        ULTIMA_1850_PrintString(_TEXT(0xa276, "W-What?\n"));
        ret = 0;
        break;
    case 0x58:
        /* 'X' X-it */
        ULTIMA_1850_PrintString(_TEXT(0xa280, "X-it "));
        CMDS_0eb4_XitCmd();
        break;
    case 0x59:
        /* 'Y' Yell */
        ULTIMA_1850_PrintString(_TEXT(0xa286, "Yell "));
        ret = CMDS_1418_YellCmd();
        break;
    case 0x5a:
        /* 'Z' Z-stats */
        ULTIMA_1850_PrintString(_TEXT(0xa28c, "Z-stats...\n"));
        ZSTATS_0a3a_ZstatsCmd();
        break;
    default:
        /* default What? */
        ULTIMA_1850_PrintString(_TEXT(0xa298, "What?\n"));
        ret = 0;
        break;
    }
    return ret;
}

// OK P1
// "explosion effect"
void ULTIMA_3522(int param_1, int param_2)
{
    if (D_5893_map_id < 0x80)
    {
        param_1 -= D_5896_map_x - 5;
        param_2 -= D_5897_map_y - 5;
    }

    ULTIMA_10e0_GRAP_51_PutTile(0, param_1, param_2);
    ULTIMA_223c_AudioWhiteNoise(10, 3000, 2000);
    ULTIMA_5910_UpdateFrame();
}

// OK P1
void ULTIMA_3564(int param_1)
{
    CombatEntity* local_4;

#if !defined(MATCHING_BUILD)
    local_4 = 0;
    ASSERT(D_5893_map_id > 0x7f);
#endif

    if (D_5893_map_id > 0x7f)
    {
        local_4 = &D_ba14[param_1];
        param_1 = local_4->actorIdx;
    }

    ULTIMA_10e0_GRAP_51_PutTile(0, D_5c5a[param_1]._2_x, D_5c5a[param_1]._3_y);

    if (D_5893_map_id > 0x7f && (local_4->flags & COMBAT_FLAGS_PLAYER) != 0)
    {
        ULTIMA_2a28(local_4->entityIdx);
        ULTIMA_223c_AudioWhiteNoise(0x28, 3000, 500);
        ULTIMA_2a28(local_4->entityIdx);
    }
    else
    {
        ULTIMA_223c_AudioWhiteNoise(10, 3000, 2000);
    }

    ULTIMA_5910_UpdateFrame();
}

// OK P1
int ULTIMA_35ec_SelectDirection(void)
{
    u8 local_4;

    D_5876 = 0;
    D_5878 = 0;

    while ((local_4 = ULTIMA_266c_GetChar()) != U5_KEY_SPACE &&
           local_4 != U5_KEY_UP && local_4 != U5_KEY_DOWN &&
           local_4 != U5_KEY_LEFT && local_4 != U5_KEY_RIGHT)
    {
    }

    switch (local_4)
    {
    case U5_KEY_ESC:
    case U5_KEY_SPACE:
        ULTIMA_1850_PrintString(_TEXT(0xa2a0, "Pass\n"));
        return 0;
    case U5_KEY_UP:
        ULTIMA_1850_PrintString(_TEXT(0xa2a6, "North\n"));
        D_5878--;
        return 1;
    case U5_KEY_DOWN:
        ULTIMA_1850_PrintString(_TEXT(0xa2ae, "South\n"));
        D_5878++;
        return 1;
    case U5_KEY_LEFT:
        ULTIMA_1850_PrintString(_TEXT(0xa2b6, "West\n"));
        D_5876--;
        return 1;
    case U5_KEY_RIGHT:
        ULTIMA_1850_PrintString(_TEXT(0xa2bc, "East\n"));
        D_5876++;
        return 1;
    }

#if !defined(MATCHING_BUILD)
    return local_4;
#endif
}

// CHECKED
int ULTIMA_368e_FindActorTileAtPos(int param_1_x, int param_2_y, int param_3_level)
{
    for (D_5876 = 1; D_5876 < 32; D_5876++)
    {
        if (D_5c5a[D_5876]._2_x == param_1_x && D_5c5a[D_5876]._3_y == param_2_y &&
            (D_5893_map_id > 0x7f || (D_5893_map_id < 0x80 && D_5c5a[D_5876]._4_z == param_3_level)))
        {
            return D_5c5a[D_5876]._0_tile;
        }
    }

    return 0;
}

// CHECKED
int ULTIMA_3702(int param_1, int param_2, int param_3)
{
    for (D_5876 = 31; D_5876 >= 0; D_5876--)
    {
        if (D_5c5a[D_5876]._2_x == param_1 && D_5c5a[D_5876]._3_y == param_2 &&
            (D_5893_map_id > 0x7f || (D_5893_map_id < 0x80 && D_5c5a[D_5876]._4_z == param_3)))
        {
            return D_5c5a[D_5876]._0_tile;
        }
    }

    return 0;
}

// CHECKED
// NOTE: UNUSED
static int ULTIMA_3776(byte param_1)
{
    int local_6;
    int local_8;
    int local_4;

    for (local_8 = 0x1f; local_8 >= 0; local_8--)
    {
        if (D_5c5a[local_8]._0_tile == 0)
        {
            return local_8;
        }

        if (D_5c5a[local_8]._0_tile == param_1)
        {
            if (D_5896_map_x >= D_5c5a[local_8]._2_x)
            {
                local_4 = D_5896_map_x - D_5c5a[local_8]._2_x;
            }
            else
            {
                local_4 = ~(D_5896_map_x - D_5c5a[local_8]._2_x) + 1;
            }

            if (D_5897_map_y >= D_5c5a[local_8]._3_y)
            {
                local_6 = D_5897_map_y - D_5c5a[local_8]._3_y;
            }
            else
            {
                local_6 = ~(D_5897_map_y - D_5c5a[local_8]._3_y) + 1;
            }

            if (D_5c5a[local_8]._4_z != D_5895_map_level)
            {
                return local_8;
            }

            // NOT MATCHING
            if (local_4 >= 6 && local_6 >= 6)
            {
                return local_8;
            }
        }
    }

    return -1;
}

// CHECKED
static int ULTIMA_3868(int param_1, int param_2, int param_3)
{
    byte local_4;
    byte local_6;
    int local_8;

    for (local_8 = 1; local_8 < 0x18; local_8++)
    {
        local_6 = D_5c5a[local_8]._0_tile;
        if (local_6 >= param_1 && local_6 <= param_2 && local_6 != TILE_ACTOR_CROWN)
        {
            if (param_3 != 0)
            {
                local_4 = D_5c5a[local_8]._2_x - D_5896_map_x + 5;
                local_6 = D_5c5a[local_8]._3_y - D_5897_map_y + 5;
                if (local_4 > 10 || local_6 > 10)
                {
                    return local_8;
                }
            }
            else
            {
                return local_8;
            }
        }
    }

    return 0;
}

// OK P1
int ULTIMA_38e4(void)
{
    int ret;

    ret = ULTIMA_3868(0, 0, 0);
    if (ret == 0)
        ret = ULTIMA_3868(1, 0xf, 1);
    if (ret == 0)
        ret = ULTIMA_3868(0x80, 0xff, 1);
    if (ret == 0)
        ret = ULTIMA_3868(0x10, 0x11, 1);
    if (ret == 0)
        ret = ULTIMA_3868(0x30, 0x7f, 1);
    if (ret == 0)
        ret = ULTIMA_3868(1, 0xf, 0);
    if (ret == 0)
        ret = ULTIMA_3868(0x80, 0xff, 0);
    if (ret == 0)
        ret = ULTIMA_3868(0x10, 0x11, 0);
    if (ret == 0)
        ret = ULTIMA_3868(0x30, 0x7f, 0);
    if (ret == 0)
        ret = ULTIMA_3868(0, 0xff, 0);

    return ret;
}

// OK P1
void ULTIMA_39cc_SetTile(byte new_tile_id, byte x, byte y)
{
    if (D_5893_map_id != 0 && D_5893_map_id < 0x21 && new_tile_id != 0)
    {
        *ULTIMA_4402_GetTileAddr(x, y) = new_tile_id;
    }
}

// CHECKED
int ULTIMA_39fc_GetFirstActivePartyMember(void)
{
    byte local_6;
    int local_4;
    int local_8;

    local_8 = 0;

    for (local_4 = 0; local_4 < D_585b; local_4++)
    {
        local_6 = D_55a8_party[local_4].status;
        if (local_6 == STATUS_GOOD || local_6 == STATUS_POISONED)
        {
            D_5876 = local_4;
            return 0;
        }
        else if (local_6 == STATUS_SLEEP)
        {
            local_8++;
        }
    }

    if (local_8 != 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// OK P1
void ULTIMA_3a74(byte a, byte b, byte c, byte d, byte e, byte f, int g)
{
    D_5c5a[g]._0_tile = a;
    D_5c5a[g]._1_animTile = b;
    D_5c5a[g]._2_x = c;
    D_5c5a[g]._3_y = d;
    D_5c5a[g]._4_z = e;
    D_5c5a[g]._5 = f;
}

// OK P1
int ULTIMA_3aae_Random(int param_1)
{
    return ULTIMA_2092_RandomRange(0, param_1);
}

// OK P1
int ULTIMA_3abe(void)
{
    int local_4 = 0;

    local_4 = ULTIMA_3aae_Random(0x3c) / 2;
    if (local_4 == 0)
    {
        local_4++;
    }
    return local_4;
}

// OK P1
// sleep_ticks
void ULTIMA_3ae6(int param_1)
{
    int local_4;

    if (D_58a4 == 0)
        return;

    for (local_4 = 0; local_4 < param_1; local_4++)
    {
        ULTIMA_5910_UpdateFrame();
        ULTIMA_20fa_WaitTicks(1);
    }
}

// OK P1
// gets
void ULTIMA_3b1c_GetString(char* param_1, int param_2)
{
    int local_8;
    int local_6;
    int local_4;

    local_4 = 0; // di
    local_8 = D_538c;
    D_538c = 0;
    do
    {
        local_6 = ULTIMA_266c_GetChar();
        if ((local_6 == U5_KEY_BACKSPACE || local_6 == U5_KEY_LEFT) && local_4 != 0)
        {
            // 3b43
            ULTIMA_1fa0_Backspace(1);
            local_4--;
        }
        else if ((local_6 == U5_KEY_ESC) && (local_4 != 0))
        {
            ULTIMA_1fa0_Backspace(local_4);
            local_4 = 0;
        }
        else if (0x1f < local_6 && local_6 < 0x80 && local_4 < param_2)
        {
            param_1[local_4++] = (char)local_6;
            ULTIMA_16ba_PrintChar(local_6);
        }
    } while (local_6 != U5_KEY_ENTER);
    param_1[local_4] = 0;
    D_538c = local_8;
}

// OK P1
int ULTIMA_3b9e(int param_1)
{
    uint local_e;
    int local_c;
    int local_10;
    int local_a;
    byte local_8[6];

    local_c = 0;
    local_10 = 0;
    local_a = 0;
    if (param_1 > 5)
    {
        param_1 = 5;
    }

    do
    {
        local_e = ULTIMA_266c_GetChar();
        if (local_e >= 0x30 && local_e <= 0x39)
        {
            if (local_c < param_1)
            {
                local_8[local_c] = local_e;
                local_c++;
                ULTIMA_16ba_PrintChar(local_e);
            }
        }
        else
        {
            if (((int)local_e == U5_KEY_MINUS || (int)local_e == U5_KEY_PLUS) && local_c == 0)
            {
                local_8[local_c] = local_e;
                local_c++;
                ULTIMA_16ba_PrintChar(local_e);
            }
            else if ((local_e == U5_KEY_BACKSPACE || local_e == U5_KEY_LEFT) && local_c != 0)
            {
                local_c--;
                ULTIMA_1fa0_Backspace(1);
            }
            else if (local_e == U5_KEY_ESC && local_c != 0)
            {
                ULTIMA_1fa0_Backspace(local_c);
                local_c = 0;
            }
        }
    } while (local_e != U5_KEY_ENTER);

    while (--local_c > 0)
    {
        local_10 += (local_8[local_c] - 0x30) * D_6a0a[local_a];
        local_a++;
    }

    if (local_8[0] == U5_KEY_MINUS)
    {
        local_10 = -local_10;
    }
    else if (local_8[0] >= 0x30)
    {
        local_10 += D_6a0a[local_a] * (local_8[0] - 0x30);
    }

    return local_10;
}

void DNGLOOK_109e(void); // NOTE: SIC
void MAINOUT_007a(void);
int MAINOUT_1a60(void);

// OK P1
// hole up from outside
static void ULTIMA_3c9a_HoleUpCmd(void)
{
    int local_10;
    byte local_e;
    int local_c;
    ActorFmt* local_a;
    int local_8;
    int local_6;
    byte local_4;

    local_a = &D_5c5a[0];
    local_e = D_5c5a[0]._1_animTile;

    ULTIMA_1850_PrintString(_TEXT(0xa2c2, "Hole up & "));

    if ((local_e & 0xf8) == TILE_ACTOR_FRIGATE_20)
    {
        ULTIMA_1850_PrintString(_TEXT(0xa2ce, "\nrepair...\n\n"));

        if (D_5c5a[0]._1_animTile < TILE_ACTOR_FRIGATE_24)
        {
            ULTIMA_1850_PrintString(_TEXT(0xa2dc, "Sails must be\n"));
            ULTIMA_1850_PrintString(_TEXT(0xa2ec, "lowered!\n\n"));
        }
        else
        {
            for (local_c = 0; local_c < 5; local_c++)
            {
                MAINOUT_007a();
                MAINOUT_1a60();
                if ((D_587c_partyTile & 0xfc) != TILE_ACTOR_FRIGATE_24)
                {
                    return;
                }
                ULTIMA_4f7c(5);
            }

            do
            {
                local_a->_5 += ULTIMA_2092_RandomRange(1, 3);
                if (local_a->_5 > 99)
                {
                    local_a->_5 = 99;
                }
            } while (local_a->_5 < 10);

            ULTIMA_1850_PrintString(_TEXT(0xa2f8, "Hull now "));
            ULTIMA_1a3e_PrintNumber(local_a->_5, 2, 0x20);
            ULTIMA_1850_PrintString(_TEXT(0xa302, "!\n\n"));
            D_a9fa = 1;
        }
    }
    else
    {
        ULTIMA_1850_PrintString(_TEXT(0xa306, "camp!\n\n"));

        if (D_5893_map_id < 0x21)
        {
            local_e = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
        }

        if (D_5893_map_id < 0x21 && local_e != 0 && local_e < 4)
        {
            ULTIMA_1850_PrintString(_TEXT(0xa30e, "On land or ship!\n\n"));
        }
        else
        {
            if (D_5893_map_id < 0x21 && local_a->_1_animTile != TILE_ACTOR_AVATAR)
            {
                ULTIMA_1850_PrintString(_TEXT(0xa322, "On foot!\n"));
            }
            else
            {
                ULTIMA_1850_PrintString(_TEXT(0xa32c, "For how many hours? (1-9) "));

                while ((local_4 = ULTIMA_266c_GetChar()) != U5_KEY_SPACE && (local_4 < 0x30 || local_4 > 0x39))
                {
                }

                ULTIMA_16ba_PrintChar(local_4);
                ULTIMA_16ba_PrintChar(10);

                if (local_4 == U5_KEY_SPACE || local_4 == 0x30)
                {
                    return;
                }

                local_10 = local_4 - 0x30;

                local_6 = 0;
                for (local_c = 0; local_c != D_585b; local_c++)
                {
                    if (D_55a8_party[local_c].status == STATUS_GOOD || D_55a8_party[local_c].status == STATUS_POISONED)
                    {
                        local_6++;
                    }
                }

                if (local_6 > 1)
                {
                    ULTIMA_1850_PrintString(_TEXT(0xa348, "\nWilt thou set a watch? "));

                    while ((local_4 = ULTIMA_266c_GetChar()) != 'Y' && local_4 != 'N')
                    {
                    }

                    if (local_4 == 'N')
                    {
                        ULTIMA_1850_PrintString(_TEXT(0xa362, "No\n\n"));
                        local_8 = -1;
                    }
                    else
                    {
                        ULTIMA_1850_PrintString(_TEXT(0xa368, "Yes\n\n"));
                        ULTIMA_1850_PrintString(_TEXT(0xa36e, "Who will stand guard? "));
                        local_8 = ULTIMA_2e8e();
                        ULTIMA_16ba_PrintChar(10);
                        if (local_8 == -1 || D_55a8_party[local_8].status != STATUS_GOOD)
                        {
                            local_8 = -1;
                            ULTIMA_1850_PrintString(_TEXT(0xa386, "None posted!\n\n"));
                        }
                    }
                }
                else
                {
                    local_8 = -1;
                }

                if (D_5893_map_id > 0x20)
                {
                    D_58a1 = 6;
                    DNGLOOK_1130();
                    DNGLOOK_0d3e();
                    ULTIMA_5f86_SpecialMapHandler(D_58a1, local_8, local_10);
                    ULTIMA_251e_SwitchDisks(2);
                    DNGLOOK_109e(); // NOTE: sic (bug?)

                    D_5c5a[1] = D_a9fc[1];

                    DUNGEON_0134(0);
                }
                else
                {
                    ULTIMA_6360_Camping(local_8, local_10);
                }
            }
        }
    }

    D_24e6 = 1;
}

// OK P1
// TODO: int? byte?
void ULTIMA_3ef0_IncreaseByte(byte* param_1, int param_2, int param_3)
{
    if (*param_1 + param_2 < param_3)
    {
        *param_1 += param_2;
    }
    else
    {
        *param_1 = param_3;
    }
}

// OK P1
// TODO: u16? s16? int? (FMT)
void ULTIMA_3f14_IncreaseInt(s16* param_1, int param_2, int param_3)
{
    if (*param_1 + param_2 < param_3)
    {
        *param_1 += param_2;
    }
    else
    {
        *param_1 = param_3;
    }
}

// OK P1
void ULTIMA_3f36_DecreaseByte(byte* param_1, int param_2)
{
    if (*param_1 > param_2)
    {
        *param_1 = *param_1 - param_2;
    }
    else
    {
        *param_1 = 0;
    }
}

// OK P1
void ULTIMA_3f54_DecreaseInt(s16* param_1, int param_2)
{
    if (*param_1 > param_2)
    {
        *param_1 = *param_1 - param_2;
    }
    else
    {
        *param_1 = 0;
    }
}

// OK P1
bool ULTIMA_3f6e(int param_1, int param_2)
{
    int local_4 = GetMapViewport(param_1, param_2);
    return (0x80 >> (local_4 & 7) & D_6a14[local_4 >> 3]) != 0;
}

// OK P1
void ULTIMA_3fb4(int param_1, int param_2)
{
    if (param_1 < 8 || param_1 > 0xb7 || param_2 < 8 || param_2 > 0xb7)
    {
        D_5876 = D_5878 = -1;
    }
    else
    {
        D_5876 = (param_1 - 8) / 0x10;
        D_5878 = (param_2 - 8) / 0x10;
    }
}
