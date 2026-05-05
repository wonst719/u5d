#include "common.h"
#include "vars.h"
#include "funcs.h"

#include <string.h>

int TOWN_09e6_attack_cmd(void);
int TOWN_0b82_klimb_cmd(void);

int MAINOUT_06ec_AttackCmd(void);
int MAINOUT_08de_EnterCmd(void);

int DUNGEON_1d4a_AttackCmd(void);
int DUNGEON_1e10_KlimbCmd(void);

void DNGLOOK_0000_LookCmdInDungeon(void);
void LOOKOBJ_099c_LookCmd(void);
void LOOKOBJ_10fc_ViewCmd(int x, int y);

void DNGLOOK_06a8_ViewCmd(void);

void SJOG_095c_SearchCmd(void);
void SJOG_0d4a_JimmyCmd(void);
void SJOG_1374_OpenCmd(void);
void SJOG_18ce_GetCmd(void);

void CMDS_0552_HoleUpCmd(void);
int CMDS_07f6_BoardCmd(void);
void CMDS_0aea_FireCmd(void);
void CMDS_0d98_IgniteTorchCmd(void);
void CMDS_0ddc_NewOrderCmd(void);
void CMDS_0eb4_XitCmd(void);
int CMDS_1418_YellCmd(void);
void CMDS_161a_PushCmd(void);
void CMDS_1ad8_MixCmd(void);
void CMDS_1c20_KlimbCmd(void);

int CAST_0dba_CastSpellCmd(void);
void CAST_1792_UseCmd(void);

int TALK_041c_TalkCmd(void);

void CAST2_10fe_SaveGame(void);

void ZSTATS_0a3a_ZstatsCmd(void);
void ZSTATS_1296_ReadyCmd(void);

// NOT MATCHING
void ULTIMA_3072(void)
{
    int i;
    int local_8;

    ULTIMA_0f6e_GRAP_1b_TransferFullscreen(0, 1);
    ULTIMA_0c22_GRAP_0f_SelectPage(1);

    for (local_8 = 0; local_8 < 8; local_8++)
    {
        for (i = 8; i <= 0xb3; i += 3)
        {
            ULTIMA_71ca_DRV_27_ScrollTextWindow1(8, i, 0xb7, i + 4, 2);
            ULTIMA_22e2_PcspkOn(ULTIMA_2092_RandomRange(0x13, 0x96));
        }

        for (i = 8; i <= 0xb3; i += 3)
        {
            ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 8, i, 0xb7, i + 4);
            ULTIMA_22e2_PcspkOn(ULTIMA_2092_RandomRange(0x13, 0x96));
        }

        for (i = 0xb3; i >= 8; i -= 3)
        {
            ULTIMA_7200_DRV_27_ScrollTextWindow2(8, i, 0xb7, i + 4, 2);
            ULTIMA_22e2_PcspkOn(ULTIMA_2092_RandomRange(0x13, 0x96));
        }

        for (i = 0xb3; i >= 8; i -= 3)
        {
            ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 8, i, 0xb7, i + 4);
            ULTIMA_22e2_PcspkOn(ULTIMA_2092_RandomRange(0x13, 0x96));
        }
    }

    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    ULTIMA_230e_PcspkOff();
}

// OK P1 (not matching: stack variable order)
int ULTIMA_3178_ProcessCommand(int param_1)
{
    int ret;
    int local_6;

#if !defined(TARGET_DOS16)
    debug("ULTIMA_3178_ProcessCommand(%d)", param_1);
#endif

    ret = 1;
    switch (param_1)
    {
    case 0xfc:
        ULTIMA_1850_PrintString("Buffer O");
        D_538c = !D_538c;
        if (D_538c != 0) 
        {
            ULTIMA_1850_PrintString("ff\n");
        }
        else
        {
            ULTIMA_1850_PrintString("n\n");
        }

        ret = 0;
        break;
    case 0x20:
        /* ' ' Pass */
        if (D_5893_map_id == 0 && D_5955 != 0)
        {
            ULTIMA_1850_PrintString("Sheets in irons!\n");
            D_5955 = 0;
        }
        else
        {
            ULTIMA_1850_PrintString("Pass\n");
        }
        break;
    case 0x41:
        /* 'A' */
        // 3216
        ret = D_5893_map_id == 0 ?
            MAINOUT_06ec_AttackCmd() :
                D_5893_map_id < 0x21 ?
            TOWN_09e6_attack_cmd() :
            DUNGEON_1d4a_AttackCmd();
        break;
    case 0x42:
        /* 'B' Board */
        ULTIMA_1850_PrintString("Board ");
        ret = CMDS_07f6_BoardCmd();
        break;
    case 0x43:
        /* 'C' Cast */
        ULTIMA_1850_PrintString("Cast...\n");
        ret = CAST_0dba_CastSpellCmd();
        break;
    case 0x44:
        /* 'D' What? */
        ULTIMA_1850_PrintString("D-What?\n");
        ret = 0;
        break;
    case 0x45:
        /* 'E' Enter */
        if (D_5893_map_id == 0)
        {
            ret = MAINOUT_08de_EnterCmd();
            break;
        }
        ULTIMA_1850_PrintString("Enter what?\n");
        break;
    case 0x46:
        /* 'F' Fire */
        ULTIMA_1850_PrintString("Fire-");
        CMDS_0aea_FireCmd();
        break;
    case 0x47:
        /* 'G' Get */
        if (D_5893_map_id < 0x21)
        {
            ULTIMA_1850_PrintString("Get-");
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
        ULTIMA_1850_PrintString("Hole up- ");
        if (local_6 != 0xab)
        {
            ULTIMA_1850_PrintString("Only in bed!\n");
        }
        else
        {
            CMDS_0552_HoleUpCmd();
        }
        break;
    case 0x49:
        /* 'I' Ignite torch */
        ULTIMA_1850_PrintString("Ignite torch!\n");
        CMDS_0d98_IgniteTorchCmd();
        break;
    case 0x4a:
        /* 'J' Jimmy */
        ULTIMA_1850_PrintString("Jimmy-");
        SJOG_0d4a_JimmyCmd();
        break;
    case 0x4b:
        /* 'K' Klimb */
        if (D_5893_map_id == 0)
        {
            ULTIMA_1850_PrintString("Klimb-");
            CMDS_1c20_KlimbCmd();
        }
        else if (D_5893_map_id < 0x21)
        {
            ret = TOWN_0b82_klimb_cmd();
        }
        else
        {
            ret = DUNGEON_1e10_KlimbCmd();
        }
        break;
    case 0x4c:
        /* 'L' Look */
        ULTIMA_1850_PrintString("Look");
        if (D_5893_map_id > 0x20 && D_5893_map_id < 0x29)
        {
            /* 0x21..0x28 (Dungeon) */
            ULTIMA_1850_PrintString("...\n");
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
        ULTIMA_1850_PrintString("Mix Reagents\n\n");
        CMDS_1ad8_MixCmd();
        break;
    case 0x4e:
        /* 'N' New order */
        ULTIMA_1850_PrintString("New Order");
        CMDS_0ddc_NewOrderCmd();
        break;
    case 0x4f:
        /* 'O' Open */
        ULTIMA_1850_PrintString("Open-");
        SJOG_1374_OpenCmd();
        break;
    case 0x50:
        /* 'P' Push */
        if (D_5893_map_id > 0x20 && D_5893_map_id < 0x29)
        {
            /* Cannot push in dungeons */
            ULTIMA_1850_PrintString("Push\nNot here!\n");
            ret = 0;
        }
        else
        {
            ULTIMA_1850_PrintString("Push-");
            CMDS_161a_PushCmd();
        }
        break;
    case 0x51:
        /* 'Q' Quit */
        ULTIMA_1850_PrintString("Quit:");
        CAST2_10fe_SaveGame();
        ret = 0;
        break;
    case 0x52:
        /* 'R' Ready */
        ULTIMA_1850_PrintString("Ready...\n\n");
        ZSTATS_1296_ReadyCmd();
        break;
    case 0x53:
        /* 'S' Search */
        if (D_5893_map_id < 0x21)
        {
            ULTIMA_1850_PrintString("Search-");
        }
        else
        {
            ULTIMA_1850_PrintString("Search...\n");
        }
        SJOG_095c_SearchCmd();
        break;
    case 0x54:
        /* 'T' Talk */
        if (D_5893_map_id == 0)
        {
            ULTIMA_1850_PrintString("Talk-");
            if (ULTIMA_35ec_SelectDirection() == 0)
                break;
            ULTIMA_1850_PrintString("Funny, no response!\n");
        }
        else
        {
            if (D_5893_map_id > 0x20)
            {
                ULTIMA_1850_PrintString("Talk-Funny, no response!\n");
            }
            else
            {
                ULTIMA_1850_PrintString("Talk-");
                if (TALK_041c_TalkCmd() != 0)
                {
                    ret = 2;
                }
            }
        }
        break;
    case 0x55:
        /* 'U' Use item */
        ULTIMA_1850_PrintString("Use item\n\n");
        CAST_1792_UseCmd();
        break;
    case 0x56:
        /* 'V' View a gem */
        ULTIMA_1850_PrintString("View a gem!\n");
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
        ULTIMA_1850_PrintString("You have none!\n");
        break;
    case 0x57:
        /* 'W' What? */
        ULTIMA_1850_PrintString("W-What?\n");
        ret = 0;
        break;
    case 0x58:
        /* 'X' X-it */
        ULTIMA_1850_PrintString("X-it ");
        CMDS_0eb4_XitCmd();
        break;
    case 0x59:
        /* 'Y' Yell */
        ULTIMA_1850_PrintString("Yell ");
        ret = CMDS_1418_YellCmd();
        break;
    case 0x5a:
        /* 'Z' Z-stats */
        ULTIMA_1850_PrintString("Z-stats...\n");
        ZSTATS_0a3a_ZstatsCmd();
        break;
    default:
        /* default What? */
        ULTIMA_1850_PrintString("What?\n");
        ret = 0;
        break;
    }
    return ret;
}

// NOT MATCHING
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

// NOT MATCHING
void ULTIMA_3564(int param_1)
{
    S_ba14* local_4;

#if !defined(TARGET_DOS16)
    local_4 = 0;
    ASSERT(D_5893_map_id > 0x7f);
#endif

    if (D_5893_map_id > 0x7f)
    {
        local_4 = &D_ba14[param_1];
        param_1 = D_ba14[param_1]._4;
    }

    ULTIMA_10e0_GRAP_51_PutTile(0, D_5c5a[param_1]._2_x, D_5c5a[param_1]._3_y);

    if (D_5893_map_id < 0x80 || (local_4->_2 & 0x80) == 0)
    {
        ULTIMA_223c_AudioWhiteNoise(10, 3000, 2000);
    }
    else
    {
        ULTIMA_2a28(local_4->_3);
        ULTIMA_223c_AudioWhiteNoise(0x28, 3000, 500);
        ULTIMA_2a28(local_4->_3);
    }

    ULTIMA_5910_UpdateFrame();
}

// NOT MATCHING: LOOP
int ULTIMA_35ec_SelectDirection()
{
    u8 cVar1;

    D_5876 = 0;
    D_5878 = 0;

    // NOT MATCHING
    while (cVar1 = ULTIMA_266c_GetChar(), (cVar1 != ' ' && cVar1 != 3 && cVar1 != 4 && cVar1 != 1 && cVar1 != 2))
    {
    }

    switch (cVar1)
    {
    case 0x1b:
    case ' ':
        ULTIMA_1850_PrintString("Pass\n");
        return 0;
    case 3:
        ULTIMA_1850_PrintString("North\n");
        D_5878--;
        return 1;
    case 4:
        ULTIMA_1850_PrintString("South\n");
        D_5878++;
        return 1;
    case 1:
        ULTIMA_1850_PrintString("West\n");
        D_5876--;
        return 1;
    case 2:
        ULTIMA_1850_PrintString("East\n");
        D_5876++;
        return 1;
    }

#if !defined(TARGET_DOS16)
    return cVar1;
#endif
}

// NOT MATCHING
// FindNpcTileAtPos(x,y,level)
int ULTIMA_368e_FindNpcTileAtPos(int param_1_x, int param_2_y, int param_3_level)
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

// NOT MATCHING
int ULTIMA_3702(int param_1, int param_2, int param_3)
{
    D_5876 = 31;

    while (1)
    {
        if (D_5c5a[D_5876]._2_x == param_1 && D_5c5a[D_5876]._3_y == param_2 &&
            (D_5893_map_id > 0x7f || (D_5893_map_id < 0x80 && D_5c5a[D_5876]._4_z == param_3)))
        {
            break;
        }

        if (--D_5876 < 0)
        {
            return 0;
        }
    }

    return D_5c5a[D_5876]._0_tile;
}

// TODO: MATCH
int ULTIMA_3868(uint param_3, uint param_2, int param_1)
{
    byte bVar1;
    int iVar2;
    byte* pbVar3;
    char* pcVar4;
    char* pcStack_e;

    iVar2 = 1;
    do {
        pbVar3 = (byte*)&D_5c5a[iVar2]._0_tile;
        pcVar4 = (char*)&D_5c5a[iVar2]._2_x;
        pcStack_e = (char*)&D_5c5a[iVar2]._3_y;

        bVar1 = *pbVar3;
        if (((param_3 <= bVar1) && (bVar1 <= param_2)) && (bVar1 != 0xb5)) {
            if (param_1 == 0) {
                return iVar2;
            }
            if (10 < (byte)((*pcVar4 - D_5896_map_x) + 5U)) {
                return iVar2;
            }
            if (10 < (byte)((*pcStack_e - D_5897_map_y) + 5U)) {
                return iVar2;
            }
        }

        iVar2 = iVar2 + 1;
        if (0x17 < iVar2) {
            return 0;
        }
    } while (1);
}

// TODO: MATCH
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
void ULTIMA_39cc_SetTile(int new_tile_id, byte x, byte y)
{
    if (D_5893_map_id != 0 && D_5893_map_id < 0x21 && new_tile_id != 0)
    {
        *ULTIMA_4402_GetTileAddr(x, y) = new_tile_id;
    }
}

// NOT MATCHING
int ULTIMA_39fc_GetFirstActivePartyMember(void)
{
    char local_6;
    uint local_4;
    int local_8;

    local_8 = 0;

    for (local_4 = 0; local_4 < D_585b; local_4++)
    {
        local_6 = D_55a8_party[local_4]._b;
        if ((local_6 == 'G') || (local_6 == 'P'))
        {
            D_5876 = local_4;
            return 0;
        }
        if (local_6 == 'S')
        {
            local_8++;
        }
    }

    if (local_8 == 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

// TODO: MATCH
void ULTIMA_3a74(byte a, byte b, byte c, byte d, byte e, byte f, int g)
{
    D_5c5a[g]._0_tile = a;
    D_5c5a[g]._1 = b;
    D_5c5a[g]._2_x = c;
    D_5c5a[g]._3_y = d;
    D_5c5a[g]._4_z = e;
    D_5c5a[g]._5 = f;
}

// OK P1
int ULTIMA_3aae(int param_1)
{
    return ULTIMA_2092_RandomRange(0, param_1);
}

// OK P1
int ULTIMA_3abe(void)
{
    int local_4 = 0;

    local_4 = ULTIMA_3aae(0x3c) / 2;
    if (local_4 == 0)
    {
        local_4++;
    }
    return local_4;
}

// sleep_ticks
// OK P1
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

// gets
void ULTIMA_3b1c_GetString(char* param_1, int param_2)
{
    undefined2 uVar1;
    int iVar2;
    int iVar3;

    iVar3 = 0; // di
    uVar1 = D_538c;
    D_538c = 0;
    do
    {
        iVar2 = ULTIMA_266c_GetChar();
        if ((iVar2 == 8 || iVar2 == 1) && iVar3 != 0)
        {
            // 3b43
            ULTIMA_1fa0_Backspace(1);
            iVar3--;
        }
        else if ((iVar2 == 0x1b) && (iVar3 != 0))
        {
            ULTIMA_1fa0_Backspace(iVar3);
            iVar3 = 0;
        }
        else if (0x1f < iVar2 && iVar2 < 0x80 && iVar3 < param_2)
        {
            param_1[iVar3++] = (char)iVar2;
            ULTIMA_16ba_PrintChar(iVar2);
        }
    } while (iVar2 != 0xd);
    param_1[iVar3] = 0;
    D_538c = uVar1;
}

// NOT MATCHING
int ULTIMA_3b9e(int param_1)
{
    int iVar1;
    int iVar3;
    int local_10;
    int local_a;
    byte local_8[6];

    local_10 = 0;
    local_a = 0;
    if (param_1 > 5)
    {
        param_1 = 5;
    }

    iVar3 = 0;
    while (1)
    {
        iVar1 = ULTIMA_266c_GetChar();
        if (iVar1 < 0x30 || iVar1 > 0x39)
        {
            if ((iVar1 == 0x2d || iVar1 == 0x2b) && iVar3 == 0)
            {
                local_8[iVar3] = iVar1;
                iVar3++;
                ULTIMA_16ba_PrintChar(iVar1);
            }
            else if ((iVar1 == 8 || iVar1 == 1) && iVar3 != 0)
            {
                iVar3--;
                ULTIMA_1fa0_Backspace(1);
            }
            else if (iVar1 == 0x1b && iVar3 != 0)
            {
                ULTIMA_1fa0_Backspace(iVar3);
                iVar3 = 0;
            }
        }
        else if (iVar3 < param_1)
        {
            local_8[iVar3] = iVar1;
            iVar3++;
            ULTIMA_16ba_PrintChar(iVar1);
        }

        if (iVar1 == 0xd)
        {
            while (--iVar3 > 0)
            {
                local_10 += (local_8[iVar3] - 0x30) * D_6a0a[local_a];
                local_a++;
            }

            if (local_8[0] == 0x2d)
            {
                local_10 = -local_10;
            }
            else if (0x2f < local_8[0])
            {
                local_10 += D_6a0a[local_a] * (local_8[0] - 0x30);
            }

            return local_10;
        }
    }
}

void DNGLOOK_0d3e(void);
void DNGLOOK_109e(void); // NOTE: SIC
void DNGLOOK_1130(void);
DUNGEON_0134(int param_1);

void MAINOUT_007a(void);
int MAINOUT_1a60(void);

// NOT MATCHING (get_ch)
// hole up from outside
void ULTIMA_3c9a_HoleUpCmd(void)
{
    int local_10;
    byte local_e;
    int local_c;
    ActorFmt* local_a;
    int local_8;
    int local_6;
    byte local_4;

    local_a = &D_5c5a[0];
    local_e = D_5c5a[0]._1;

    ULTIMA_1850_PrintString(/*0xa2c2*/ "Hole up & ");

    if ((local_e & 0xf8) == 0x20)
    {
        ULTIMA_1850_PrintString(/*0xa2ce*/ "\nrepair...\n\n");

        if (D_5c5a[0]._1 < 0x24)
        {
            ULTIMA_1850_PrintString(/*0xa2dc*/ "Sails must be\n");
            ULTIMA_1850_PrintString(/*0xa2ec*/ "lowered!\n\n");
        }
        else
        {
            for (local_c = 0; local_c < 5; local_c++)
            {
                MAINOUT_007a();
                MAINOUT_1a60();
                if ((D_587c & 0xfc) != 0x24)
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

            ULTIMA_1850_PrintString(/*0xa2f8*/ "Hull now ");
            ULTIMA_1a3e_PrintNumber(local_a->_5, 2, 0x20);
            ULTIMA_1850_PrintString(/*0xa302*/ "!\n\n");
            D_a9fa = 1;
        }
    }
    else
    {
        ULTIMA_1850_PrintString(/*0xa306*/ "camp!\n\n");

        if (D_5893_map_id < 0x21)
        {
            local_e = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
        }

        if (D_5893_map_id < 0x21 && local_e != 0 && local_e < 4)
        {
            ULTIMA_1850_PrintString(/*0xa30e*/ "On land or ship!\n\n");
        }
        else
        {
            if (D_5893_map_id < 0x21 && local_a->_1 != 0x1c)
            {
                ULTIMA_1850_PrintString(/*0xa322*/ "On foot!\n");
            }
            else
            {
                ULTIMA_1850_PrintString(/*0xa32c*/ "For how many hours? (1-9) ");

                // NOT MATCHING
                do
                {
                    local_4 = ULTIMA_266c_GetChar();
                } while (local_4 != 0x20 && (local_4 < 0x30 || 0x39 < local_4));

                ULTIMA_16ba_PrintChar(local_4);
                ULTIMA_16ba_PrintChar(10);

                if (local_4 == 0x20 || local_4 == 0x30)
                {
                    return;
                }

                local_10 = local_4 - 0x30;

                local_6 = 0;
                for (local_c = 0; local_c != D_585b; local_c++)
                {
                    if (D_55a8_party[local_c]._b == 'G' || D_55a8_party[local_c]._b == 'P')
                    {
                        local_6++;
                    }
                }

                if (local_6 > 1)
                {
                    ULTIMA_1850_PrintString(/*0xa348*/ "\nWilt thou set a watch? ");

                    // NOT MATCHING
                    do
                    {
                        local_4 = ULTIMA_266c_GetChar();
                    } while (local_4 != 'Y' && local_4 != 'N');

                    if (local_4 == 'N')
                    {
                        ULTIMA_1850_PrintString(/*0xa362*/ "No\n\n");
                        local_8 = -1;
                    }
                    else
                    {
                        ULTIMA_1850_PrintString(/*0xa368*/ "Yes\n\n");
                        ULTIMA_1850_PrintString(/*0xa36e*/ "Who will stand guard? ");
                        local_8 = ULTIMA_2e8e();
                        ULTIMA_16ba_PrintChar(10);
                        if (local_8 == -1 || D_55a8_party[local_8]._b != 'G')
                        {
                            local_8 = -1;
                            ULTIMA_1850_PrintString(/*0xa386*/ "None posted!\n\n");
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

                    // NOT MATCHING
                    memcpy(&D_5c5a[1], &D_a9fc[1], sizeof(ActorFmt));

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
void ULTIMA_3ef0(byte* param_1, int param_2, int param_3)
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
void ULTIMA_3f14(s16* param_1, int param_2, int param_3)
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
void ULTIMA_3f36(byte* param_1, int param_2)
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
void ULTIMA_3f54(s16* param_1, int param_2)
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

// NOT MATCHING
bool ULTIMA_3f6e(int param_1, int param_2)
{
    byte local_4 = D_ab02[param_2 * 0x20 + param_1];
    return (0x80 >> (local_4 & 7) & D_6a14[local_4 >> 3]) != 0;
}

// NOT MATCHING
void ULTIMA_3fb4(int param_1, int param_2)
{
    if (param_1 < 8 || param_1 > 0xb7 || param_2 < 8 || param_2 > 0xb7)
    {
        D_5878 = -1;
        D_5876 = -1;
    }
    else
    {
        D_5876 = (param_1 - 8) / 0x10;
        D_5878 = (param_2 - 8) / 0x10;
    }
}
