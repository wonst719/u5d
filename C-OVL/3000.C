#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>

int F_TOWN_09e6_attack_cmd();
int F_TOWN_0b82_klimb_cmd(void);

int F_MAINOUT_06ec_attack_cmd(void);
int F_MAINOUT_08de_enter_cmd(void);

int F_DUNGEON_1d4a_attack_cmd();
F_DUNGEON_1e10_klimb_cmd();

F_DNGLOOK_0000_look_cmd_in_dungeon();
F_LOOKOBJ_099c_look_cmd();
F_LOOKOBJ_10fc_view_cmd(int x, int y);

F_DNGLOOK_06a8_view_cmd();

F_SJOG_095c_search_cmd();
F_SJOG_0d4a_jimmy_cmd();
void F_SJOG_1374_open_cmd(void);
F_SJOG_18ce_get_cmd();

F_CMDS_0552_hole_up_cmd();
int F_CMDS_07f6_board_cmd();
F_CMDS_0aea_fire_cmd();
F_CMDS_0d98_ignite_torch_cmd();
F_CMDS_0ddc_new_order_cmd();
F_CMDS_0eb4_xit_cmd();
F_CMDS_1418_yell_cmd();
F_CMDS_161a_push_cmd();
F_CMDS_1ad8_mix_cmd();
F_CMDS_1c20_klimb_cmd();

int F_CAST_0dba_cast_spell_cmd();
F_CAST_1792_use_cmd();

int F_TALK_041c_talk_cmd(void);

F_CAST2_10fe_save_game();

void F_ZSTATS_0a3a_zstats_cmd();
void F_ZSTATS_1296_ready_cmd(void);

// OK P1 (not matching: stack variable order)
int FUN_1000_3178_process_command(int param_1)
{
    int ret;
    int local_6;

#ifdef _WIN32
    printf("FUN_1000_3178_process_command(%d)\n", param_1);
#endif

    ret = 1;
    switch (param_1)
    {
    case 0xfc:
        FUN_1000_1850_print_string("Buffer O");
        D_538c = !D_538c;
        if (D_538c != 0) 
        {
            FUN_1000_1850_print_string("ff\n");
        }
        else
        {
            FUN_1000_1850_print_string("n\n");
        }

        ret = 0;
        break;
    case 0x20:
        /* ' ' Pass */
        if ((D_5893_map_id == 0) && (D_5955 != 0))
        {
            FUN_1000_1850_print_string("Sheets in irons!\n");
            D_5955 = 0;
        }
        else
        {
            FUN_1000_1850_print_string("Pass\n");
        }
        break;
    case 0x41:
        /* 'A' */
        // 3216
        ret = (D_5893_map_id == 0) ?
            F_MAINOUT_06ec_attack_cmd() :
                (D_5893_map_id < 0x21) ?
            F_TOWN_09e6_attack_cmd() :
            F_DUNGEON_1d4a_attack_cmd();
        break;
    case 0x42:
        /* 'B' Board */
        FUN_1000_1850_print_string("Board ");
        ret = F_CMDS_07f6_board_cmd();
        break;
    case 0x43:
        /* 'C' Cast */
        FUN_1000_1850_print_string("Cast...\n");
        ret = F_CAST_0dba_cast_spell_cmd();
        break;
    case 0x44:
        /* 'D' What? */
        FUN_1000_1850_print_string("D-What?\n");
        ret = 0;
        break;
    case 0x45:
        /* 'E' Enter */
        if (D_5893_map_id == 0)
        {
            ret = F_MAINOUT_08de_enter_cmd();
            break;
        }
        FUN_1000_1850_print_string("Enter what?\n");
        break;
    case 0x46:
        /* 'F' Fire */
        FUN_1000_1850_print_string("Fire-");
        F_CMDS_0aea_fire_cmd();
        break;
    case 0x47:
        /* 'G' Get */
        if (D_5893_map_id < 0x21)
        {
            FUN_1000_1850_print_string("Get-");
        }
        F_SJOG_18ce_get_cmd();
        break;
    case 0x48:
        /* 'H' Hole up */
        if ((D_5893_map_id == 0) || (0x20 < D_5893_map_id))
        {
            FUN_1000_3c9a_hole_up();
            //FUN_0002b8cc_outmap_hole_up_cmd();
            break;
        }
        // FUN_1000_4402_get_address_of_tile_id == FUN_0000db10_LOOKOBJ_UNK?
        //local_6 = *FUN_0000db10_LOOKOBJ_UNK(D_5896_map_x, D_5897_map_y);
        local_6 = *FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y);
        FUN_1000_1850_print_string("Hole up- ");
        if (local_6 != 0xab)
        {
            FUN_1000_1850_print_string("Only in bed!\n");
        }
        else
        {
            F_CMDS_0552_hole_up_cmd();
        }
        break;
    case 0x49:
        /* 'I' Ignite torch */
        FUN_1000_1850_print_string("Ignite torch!\n");
        F_CMDS_0d98_ignite_torch_cmd();
        break;
    case 0x4a:
        /* 'J' Jimmy */
        FUN_1000_1850_print_string("Jimmy-");
        F_SJOG_0d4a_jimmy_cmd();
        break;
    case 0x4b:
        /* 'K' Klimb */
        if (D_5893_map_id == 0)
        {
            FUN_1000_1850_print_string("Klimb-");
            F_CMDS_1c20_klimb_cmd();
        }
        else if (D_5893_map_id < 0x21)
        {
            ret = F_TOWN_0b82_klimb_cmd();
        }
        else
        {
            ret = F_DUNGEON_1e10_klimb_cmd();
        }
        break;
    case 0x4c:
        /* 'L' Look */
        FUN_1000_1850_print_string("Look");
        if (D_5893_map_id > 0x20 && 0x29 > D_5893_map_id)
        {
            /* 0x21..0x28 (Dungeon) */
            FUN_1000_1850_print_string("...\n");
            F_DNGLOOK_0000_look_cmd_in_dungeon();
        }
        else
        {
            FUN_1000_16ba_print_char(0x2d);
            F_LOOKOBJ_099c_look_cmd();
        }
        break;
    case 0x4d:
        /* 'M' Mix */
        FUN_1000_1850_print_string("Mix Reagents\n\n");
        F_CMDS_1ad8_mix_cmd();
        break;
    case 0x4e:
        /* 'N' New order */
        FUN_1000_1850_print_string("New Order");
        F_CMDS_0ddc_new_order_cmd();
        break;
    case 0x4f:
        /* 'O' Open */
        FUN_1000_1850_print_string("Open-");
        F_SJOG_1374_open_cmd();
        break;
    case 0x50:
        /* 'P' Push */
        if (D_5893_map_id > 0x20 && 0x29 > D_5893_map_id)
        {
            /* Cannot push in dungeons */
            FUN_1000_1850_print_string("Push\nNot here!\n");
            ret = 0;
        }
        else
        {
            FUN_1000_1850_print_string("Push-");
            F_CMDS_161a_push_cmd();
        }
        break;
    case 0x51:
        /* 'Q' Quit */
        FUN_1000_1850_print_string("Quit:");
        F_CAST2_10fe_save_game();
        ret = 0;
        break;
    case 0x52:
        /* 'R' Ready */
        FUN_1000_1850_print_string("Ready...\n\n");
        F_ZSTATS_1296_ready_cmd();
        break;
    case 0x53:
        /* 'S' Search */
        if (D_5893_map_id < 0x21)
        {
            FUN_1000_1850_print_string("Search-");
        }
        else
        {
            FUN_1000_1850_print_string("Search...\n");
        }
        F_SJOG_095c_search_cmd();
        break;
    case 0x54:
        /* 'T' Talk */
        if (D_5893_map_id == 0)
        {
            FUN_1000_1850_print_string("Talk-");
            if (FUN_1000_35ec_select_direction() == 0)
                break;
            FUN_1000_1850_print_string("Funny, no response!\n");
        }
        else
        {
            if (D_5893_map_id > 0x20)
            {
                FUN_1000_1850_print_string("Talk-Funny, no response!\n");
            }
            else
            {
                FUN_1000_1850_print_string("Talk-");
                if (F_TALK_041c_talk_cmd() != 0)
                {
                    ret = 2;
                }
            }
        }
        break;
    case 0x55:
        /* 'U' Use item */
        FUN_1000_1850_print_string("Use item\n\n");
        F_CAST_1792_use_cmd();
        break;
    case 0x56:
        /* 'V' View a gem */
        FUN_1000_1850_print_string("View a gem!\n");
        if (D_57ad != 0)
        {
            D_57ad--;
            if (D_5893_map_id < 0x21)
            {
                F_LOOKOBJ_10fc_view_cmd(D_5896_map_x, D_5897_map_y);
            }
            else
            {
                F_DNGLOOK_06a8_view_cmd();
            }
            break;
        }
        FUN_1000_1850_print_string("You have none!\n");
        break;
    case 0x57:
        /* 'W' What? */
        FUN_1000_1850_print_string("W-What?\n");
        ret = 0;
        break;
    case 0x58:
        /* 'X' X-it */
        FUN_1000_1850_print_string("X-it ");
        F_CMDS_0eb4_xit_cmd();
        break;
    case 0x59:
        /* 'Y' Yell */
        FUN_1000_1850_print_string("Yell ");
        ret = F_CMDS_1418_yell_cmd();
        break;
    case 0x5a:
        /* 'Z' Z-stats */
        FUN_1000_1850_print_string("Z-stats...\n");
        F_ZSTATS_0a3a_zstats_cmd();
        break;
    default:
        /* default What? */
        FUN_1000_1850_print_string("What?\n");
        ret = 0;
        break;
    }
    return ret;
}

// NOT MATCHING: LOOP
int FUN_1000_35ec_select_direction()
{
    u8 cVar1;

    D_5876 = 0;
    D_5878 = 0;

    // NOT MATCHING
    while (cVar1 = FUN_1000_266c_get_ch(), (cVar1 != ' ' && cVar1 != 3 && cVar1 != 4 && cVar1 != 1 && cVar1 != 2))
    {
    }

    switch (cVar1)
    {
    case 0x1b:
    case ' ':
        FUN_1000_1850_print_string("Pass\n");
        return 0;
    case 3:
        FUN_1000_1850_print_string("North\n");
        D_5878--;
        return 1;
    case 4:
        FUN_1000_1850_print_string("South\n");
        D_5878++;
        return 1;
    case 1:
        FUN_1000_1850_print_string("West\n");
        D_5876--;
        return 1;
    case 2:
        FUN_1000_1850_print_string("East\n");
        D_5876++;
        return 1;
    }

#ifdef _WIN32
    return cVar1;
#endif
}

// NOT MATCHING
// FindNpcTileAtPos(x,y,level)
int FUN_1000_368e(int param_1, int param_2, int param_3)
{
    for (D_5876 = 1; D_5876 < 32; D_5876++)
    {
        if (D_5c5a[D_5876]._2_x == param_1 && D_5c5a[D_5876]._3_y == param_2 &&
            (D_5893_map_id > 0x7f || (D_5893_map_id < 0x80 && D_5c5a[D_5876]._4_z == param_3)))
        {
            return D_5c5a[D_5876]._0_tile;
        }
    }

    return 0;
}

// OK P1
void FUN_1000_39cc_set_new_tile_id(int new_tile_id, byte x, byte y)
{
    if (D_5893_map_id != 0 && D_5893_map_id < 0x21 && new_tile_id != 0)
    {
        *FUN_1000_4402_get_address_of_tile_id(x, y) = new_tile_id;
    }
}

int FUN_1000_3702(int param_1, int param_2, int param_3)
{
    printf("FUN_1000_3702(%d,%d,%d)\n", param_1, param_2, param_3);
}

// TODO: MATCH
int FUN_1000_3868(uint param_3, uint param_2, int param_1)
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
int FUN_1000_38e4(void)
{
    int ret;

    ret = FUN_1000_3868(0, 0, 0);
    if (ret == 0)
        ret = FUN_1000_3868(1, 0xf, 1);
    if (ret == 0)
        ret = FUN_1000_3868(0x80, 0xff, 1);
    if (ret == 0)
        ret = FUN_1000_3868(0x10, 0x11, 1);
    if (ret == 0)
        ret = FUN_1000_3868(0x30, 0x7f, 1);
    if (ret == 0)
        ret = FUN_1000_3868(1, 0xf, 0);
    if (ret == 0)
        ret = FUN_1000_3868(0x80, 0xff, 0);
    if (ret == 0)
        ret = FUN_1000_3868(0x10, 0x11, 0);
    if (ret == 0)
        ret = FUN_1000_3868(0x30, 0x7f, 0);
    if (ret == 0)
        ret = FUN_1000_3868(0, 0xff, 0);

    return ret;
}

// NOT MATCHING
int FUN_1000_39fc_get_first_active_party_member()
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
void FUN_1000_3a74(byte a, byte b, byte c, byte d, byte e, byte f, int g)
{
    D_5c5a[g]._0_tile = a;
    D_5c5a[g]._1 = b;
    D_5c5a[g]._2_x = c;
    D_5c5a[g]._3_y = d;
    D_5c5a[g]._4_z = e;
    D_5c5a[g]._5 = f;
}

// OK P1
int FUN_1000_3aae(int param_1)
{
    return FUN_1000_2092_random_range(0, param_1);
}

// OK P1
int FUN_1000_3abe(void)
{
    int local_4 = 0;

    local_4 = FUN_1000_3aae(0x3c) / 2;
    if (local_4 == 0)
    {
        local_4++;
    }
    return local_4;
}

// sleep_ticks
// OK P1
void FUN_1000_3ae6(int param_1)
{
    int local_4;

    if (D_58a4 == 0)
        return;

    for (local_4 = 0; local_4 < param_1; local_4++)
    {
        FUN_1000_5910_update_map();
        FUN_1000_20fa_wait_ticks(1);
    }
}

// gets
void FUN_1000_3b1c_get_string(char* param_1, int param_2)
{
    undefined2 uVar1;
    int iVar2;
    int iVar3;

    iVar3 = 0; // di
    uVar1 = D_538c;
    D_538c = 0;
    do
    {
        iVar2 = FUN_1000_266c_get_ch();
        if ((iVar2 == 8 || iVar2 == 1) && iVar3 != 0)
        {
            // 3b43
            FUN_1000_1fa0_backspace(1);
            iVar3--;
        }
        else if ((iVar2 == 0x1b) && (iVar3 != 0))
        {
            FUN_1000_1fa0_backspace(iVar3);
            iVar3 = 0;
        }
        else if (0x1f < iVar2 && iVar2 < 0x80 && iVar3 < param_2)
        {
            param_1[iVar3++] = (char)iVar2;
            FUN_1000_16ba_print_char(iVar2);
        }
    } while (iVar2 != 0xd);
    param_1[iVar3] = 0;
    D_538c = uVar1;
}

// OK P1
void FUN_1000_3ef0(byte* param_1, int param_2, int param_3)
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
void FUN_1000_3f14(s16* param_1, int param_2, int param_3)
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
void FUN_1000_3f36(byte* param_1, int param_2)
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
void FUN_1000_3f54(s16* param_1, int param_2)
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
