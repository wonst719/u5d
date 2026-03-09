#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>

void F_ENDGAME_0648_endgame_main(void);

int F_COMBAT_0b94(void);

void F_DNGLOOK_0844(int);
void F_DNGLOOK_0c6c(void);
void F_DNGLOOK_0d3e(void);
void F_DNGLOOK_0fda(void);
void F_DNGLOOK_109e(int param_1);
void F_DNGLOOK_117e(int a, int b);
void F_DNGLOOK_1130(void);

// NOT MATCHING
void F_DUNGEON_0000(byte param_1)
{
    byte uVar1;
    byte bVar2;
    byte bVar3;
    int uVar4;
    int uVar5;
    int uVar6;
    int uVar7;
    int uVar8;
    int uVar9;
    int uVar10;
    int uVar11;
    int iVar13;
    int local_1e;

    FUN_1000_1850_print_string(/*0x2c58*/ "Entering room...\n");
    D_6603 = D_2c76[D_6602];
    FUN_1000_1b16_clear_keyboard_buffer();
    uVar1 = D_587b;
    D_587b = 0xff;
    D_589e = 0xff;

    local_1e = D_5893_map_id - 0x21;
    if (local_1e > 0)
    {
        local_1e = D_5893_map_id - 0x22;
    }

    for (iVar13 = 0; iVar13 < 0x160; iVar13++)
    {
        D_ad14[iVar13] = 0;
    }

    FUN_1000_256e_read_file_from_disk(/*0x2c6a*/ "dungeon.cbt", D_ad14, 0x160,
                                      local_1e * 0x1600 + (param_1 & 0xf) * 0x160);
    D_5894 = D_5893_map_id;
    bVar2 = D_5896_map_x;
    bVar3 = D_5897_map_y;
    uVar4 = D_5c5a[1]._0_tile;
    uVar5 = D_5c5a[1]._2_x;
    uVar6 = D_5c5a[1]._4_z;
    uVar7 = D_5c5a[1]._6;
    uVar8 = D_5c5a[2]._0_tile;
    uVar9 = D_5c5a[2]._2_x;
    uVar10 = D_5c5a[2]._4_z;
    uVar11 = D_5c5a[2]._6;
    D_5893_map_id = 0xff;
    D_58a0 = 0;
    F_DNGLOOK_117e(param_1, 3);
    FUN_1000_5910_update_map();
    D_58a1 = 0x82;
    iVar13 = F_COMBAT_0b94();
    if (iVar13 == 0)
    {
        if (D_58a0 == 'M')
        {
            F_ENDGAME_0648_endgame_main();
        }
        D_5893_map_id = D_5894;
        F_DNGLOOK_0844(param_1 & 0xf);
        D_595a[(uint)D_5895_map_level * 0x40 + (uint)bVar3 * 8 + (uint)bVar2] &= 0xaf;
    }
    D_5897_map_y = bVar3;
    D_5896_map_x = bVar2;
    D_5893_map_id = D_5894;
    F_DNGLOOK_0fda();
    D_5c5a[1]._0_tile = uVar4;
    D_5c5a[1]._2_x = uVar5;
    D_5c5a[1]._4_z = uVar6;
    D_5c5a[1]._6 = uVar7;
    D_5c5a[2]._0_tile = uVar8;
    D_5c5a[2]._2_x = uVar9;
    D_5c5a[2]._4_z = uVar10;
    D_5c5a[2]._6 = uVar11;
    D_587b = uVar1;
}

int F_DUNGEON_0252(void);

// NOT MATCHING
void F_DUNGEON_0134(int param_1)
{
    char cVar1;
    int local_8;

    cVar1 = D_5c5a[1]._5;
    if (param_1 != 0)
    {
        local_8 = FUN_1000_2092_random_range(0, 7);
        D_5c5a[1]._1 = local_8;
        D_5c5a[1]._0_tile = local_8;
        D_5c5a[1]._7 = 0;
        D_5c5a[1]._6 = D_1744[local_8];
        D_5c5a[1]._5 = D_173c[local_8];
        D_5c5a[1]._4_z = D_5895_map_level;
        if (cVar1 != -1)
        {
            FUN_1000_0be4_free_memory(D_a9c6);
        }
        D_a9c6 = 0;
        if (F_DUNGEON_0252() == 0)
        {
            D_5c5a[1]._1 = 0;
            D_5c5a[1]._0_tile = 0;
            D_5c5a[1]._5 = 0xff;
        }
    }

    if (D_5c5a[1]._5 != 0xff)
    {
        do
        {
            D_a9c6 = FUN_1000_0bae_load_image_file(D_25ea[D_5c5a[1]._0_tile + 8]);
        } while (D_a9c6 == 0);
    }
}

// NOT MATCHING
void F_DUNGEON_01d2_print_walk_dir(void)
{
    int uVar2;

    uVar2 = D_5386_currentCharset;
    FUN_1000_1b94_select_charset(0);
    FUN_1000_1bf2_set_text_cursor_position(0xc, 0);
    FUN_1000_1a3e_print_number(D_5895_map_level + 1, 1, 0x20);
    FUN_1000_1bf2_set_text_cursor_position(0xc, 0x17);

    if (D_6603 == 0)
    {
        FUN_1000_1850_print_string(/*0x2c7c*/ "North");
    }
    else if (D_6603 == 1)
    {
        FUN_1000_1850_print_string(/*0x2c82*/ " East");
    }
    else if (D_6603 == 2)
    {
        FUN_1000_1850_print_string(/*0x2c88*/ "South");
    }
    else if (D_6603 == 3)
    {
        FUN_1000_1850_print_string(/*0x2c8e*/ " West");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x2c94*/ " ????");
    }

    FUN_1000_1b94_select_charset(uVar2);
}

// NOT MATCHING
int F_DUNGEON_0252(void)
{
    byte bVar1;
    int local_a;
    int local_8;

    for (local_8 = 0; local_8 < 8; local_8++)
    {
        local_a = FUN_1000_2092_random_range(0, 0x3f);
        bVar1 = D_595a[local_a + D_5895_map_level * 0x40] & 0xf0;
        if (bVar1 < 0x60 || bVar1 == 0x70)
        {
            if (local_a % 8 != D_5896_map_x && local_a / 8 != D_5897_map_y)
            {
                D_5c5a[1]._2_x = D_5c5a[2]._2_x = local_a % 8;
                D_5c5a[1]._3_y = D_5c5a[2]._3_y = local_a / 8;

                if ((D_5c5a[1]._5 == 0x16 || D_5c5a[1]._5 == 0x18) && FUN_1000_2092_random_range(0, 99) > 0x30)
                {
                    D_5c5a[1]._7 = 0xff;
                }

                local_a = 1;
                break;
            }
        }
    }

    if (local_8 == 8)
    {
        D_5c5a[2]._3_y = 0xff;
        D_5c5a[1]._3_y = 0xff;
        D_5c5a[2]._2_x = 0xff;
        D_5c5a[1]._2_x = 0xff;
        local_a = 0;
    }

    return local_a;
}

// NOT MATCHING
void F_DUNGEON_0332(void)
{
    int uVar1;

    uVar1 = D_5386_currentCharset;
    FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b2_frame_color);
    FUN_1000_0aa6_GRAP_3f_fill_rectangle(0x28, 0, 0x98, 7);
    FUN_1000_0aa6_GRAP_3f_fill_rectangle(0x30, 0xb9, 0x98, 0xbf);
    FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
    FUN_1000_0b10_GRAP_line(0x28, 7, 0x98, 7);
    FUN_1000_0b10_GRAP_line(0x30, 0xb8, 0x98, 0xb8);
    FUN_1000_1b94_select_charset(0);
    FUN_1000_1bf2_set_text_cursor_position(10, 0);
    FUN_1000_4c2a();
    FUN_1000_1850_print_string(/*0x2c9a*/ "L ");
    FUN_1000_4cce();
    FUN_1000_1bf2_set_text_cursor_position(6, 0x17);
    FUN_1000_4c2a();
    FUN_1000_1850_print_string(/*0x2c9d*/ "Dir:      ");
    FUN_1000_4cce();
    FUN_1000_1b94_select_charset(uVar1);
}

void F_DUNGEON_1020(void);

void F_DUNGEON_1a90(int param_1);

// NOT MATCHING
int F_DUNGEON_03d6(void)
{
    int iVar2;
    int iVar3;

    if (D_a9fa != 0)
    {
        FUN_1000_2900_update_vitals();
        D_a9fa = 0;
    }

    FUN_1000_16ba_print_char(10);
    FUN_1000_4c2a();

    iVar3 = 1;
    do
    {
        iVar2 = FUN_1000_2032_to_upper((u8)FUN_1000_1b38_keystroke_cursor());
        if (iVar2 != 0 && iVar2 < 5 && D_538a == 0)
        {
            iVar2 += 0xfa;
        }

        if (iVar2 == 0)
        {
            F_DUNGEON_1a90(iVar3);
            if (iVar3 == 0)
            {
                FUN_1000_0ace_GRAP_18_transfer_area(1, 0, 0x28, 0xe, 0x96, 0xb2);
            }
            else
            {
                FUN_1000_0ace_GRAP_18_transfer_area(1, 0, 0x10, 0xe, 0xaf, 0xb2);
            }

            if (D_6604 != 1)
            {
                iVar3 = 0;
            }

            F_DUNGEON_1020();
        }
    } while (iVar2 == 0);

    return iVar2;
}

void F_DUNGEON_1be0(void);

// NOT MATCHING
void F_DUNGEON_0470(int param_1)
{
    byte bVar1;

    F_DUNGEON_1be0();
    FUN_1000_1850_print_string(/*0x2ca8*/ "Ouch!\n");
    FUN_1000_1850_print_string(/*0x2caf*/ "Electric field!\n");
    FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
    FUN_1000_0b86(8, 8, 0xb7, 0xb7);
    FUN_1000_20fa_wait_ticks(1);
    FUN_1000_0b86(8, 8, 0xb7, 0xb7);
    FUN_1000_223c_audio_white_noise(1, 500, 20000);
    if (param_1 < 1)
    {
        bVar1 = D_6603;
        D_5896_map_x += D_24d6[(uint)bVar1];
        D_5897_map_y += D_24de[(uint)bVar1];
    }
    else
    {
        bVar1 = D_6603;
        D_5896_map_x -= D_24d6[(uint)bVar1];
        D_5897_map_y -= D_24de[(uint)bVar1];
    }
    FUN_1000_2aa8();
    F_DUNGEON_1be0();
}

// NOT MATCHING
int F_DUNGEON_0502(int param_1, byte param_2)
{
    byte bVar1;
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    local_6 = 0;
    local_4 = 0;

    switch (param_1)
    {
    case 3:
        FUN_1000_1850_print_string(/*0x2cc0*/ "Advance\n");
        local_6 = 1;
        break;

    case 2:
        if ((param_2 & 0xf0) != 0xe0)
        {
            FUN_1000_1850_print_string(/*0x2cda*/ "Turn right\n");
            D_6603 = (D_6603 + 1) & 3;
            break;
        }

        FUN_1000_1850_print_string(/*0x2cc9*/ "Not in doorway!\n");
        break;

    case 4:
        FUN_1000_1850_print_string(/*0x2ce6*/ "Back up\n");
        local_6 = -1;
        break;

    case 1:
        if ((param_2 & 0xf0) == 0xe0)
        {
            FUN_1000_1850_print_string(/*0x2cef*/ "Not in doorway!\n");
        }
        else
        {
            FUN_1000_1850_print_string(/*0x2d00*/ "Turn left\n");
            D_6603 = (D_6603 + 3) & 3;
        }
        break;

    default:
        FUN_1000_1850_print_string(/*0x2d0b*/ "Turn around.\n");
        D_6603 = (D_6603 + 2) & 3;
        break;
    }

    D_6602 = D_6603;

    if (local_6 != 0)
    {
        local_4 = 1;
        local_8 = D_24d6[D_6603] * local_6 + D_5896_map_x;
        if (local_8 < 0)
        {
            local_8 = 7;
        }

        if (local_8 > 7)
        {
            local_8 = 0;
        }

        local_a = D_24de[D_6603] * local_6 + D_5897_map_y;
        if (local_a < 0)
        {
            local_a = 7;
        }

        if (local_a > 7)
        {
            local_a = 0;
        }

        bVar1 = D_595a[D_5895_map_level * 0x40 + local_a * 8 + local_8];
        if (bVar1 == 0x83)
        {
            D_5896_map_x = local_8;
            D_5897_map_y = local_a;
            F_DUNGEON_0470(local_6);
            local_8 = D_5896_map_x;
            local_a = D_5897_map_y;
        }

        bVar1 &= 0xf0;
        if (bVar1 >= 0xa1 && bVar1 <= 0xdf || local_6 == -1 && (bVar1 == 0xa0 || bVar1 == 0xf0))
        {
            FUN_1000_1850_print_string(/*0x2d19*/ "Blocked!\n");
        }
        else
        {
            if (local_8 != D_5c5a[1]._2_x || local_a != D_5c5a[1]._3_y)
            {
                D_a9fb = 0xf;
                D_24e7 = 0;
                F_DUNGEON_1020();
                D_24e7 = 0;
                D_5896_map_x = (byte)local_8 & 7;
                D_5897_map_y = (byte)local_a & 7;
                F_DUNGEON_1be0();
                return local_4;
            }

            FUN_1000_1850_print_string(/*0x2d23*/ "Blocked!\n");
        }
    }

    F_DUNGEON_1be0();
    return local_4;
}

// NOT MATCHING
int F_DUNGEON_06c4_process_command(int param_1)
{
    int local_4;

    local_4 = 1;
    switch (param_1)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 0x2e:
        local_4 = F_DUNGEON_0502(param_1, D_595a[D_5896_map_x + D_5897_map_y * 8 + D_5895_map_level * 0x40]);
        break;

    case 5:
        FUN_1000_1850_print_string(/*0x2d2d*/ "Exit to DOS? ");
        if (FUN_1000_266c_get_ch() == 0x59)
        {
            FUN_1000_0878_set_old_video_mode();
            FUN_1000_02f4_exit_to_dos(0);
            break;
        }
        FUN_1000_1850_print_string(/*0x2d3b*/ "N\n");
        break;

    case 0xb:
        FUN_1000_1a3e_print_number(D_5888, 1, 0x20);
        FUN_1000_16ba_print_char(10);
        break;

    case 0x16:
        FUN_1000_1850_print_string(/*0x2d3e*/ "1.16");
        FUN_1000_16ba_print_char(10);
        break;

    case 0x13:
        FUN_1000_1850_print_string(/*0x2d43*/ "Sound ");
        if (D_a9ce != 0)
        {
            FUN_1000_1850_print_string(/*0x2d4a*/ "Off\n");
        }
        else
        {
            FUN_1000_1850_print_string(/*0x2d4f*/ "On\n");
        }
        D_a9ce = !D_a9ce;
        break;

    default:
        if (param_1 < 0x30 || param_1 > 0x39)
        {
            local_4 = FUN_1000_3178_process_command(param_1);
        }
        else
        {
            FUN_1000_4080(param_1);
            local_4 = 0;
        }
        break;
    }

    return local_4;
}

// NOT MATCHING
int F_DUNGEON_07e2(void)
{
    int iVar1;
    byte bVar2;
    int iVar8;
    int iVar7;
    int local_1c;
    int local_10;
    int local_c;

    local_10 = 0;
    local_1c = 999;
    if (D_5c5a[1]._5 != 0xff)
    {
        if (D_5c5a[1]._5 != 0x1b)
        {
            for (local_c = 0; local_c < 8; local_c++)
            {
                iVar1 = FUN_1000_2092_random_range(0, 3);
                iVar7 = D_24d6[iVar1] + (uint)D_5c5a[1]._2_x;
                if (iVar7 > 7)
                {
                    iVar7 = 0;
                }
                if (iVar7 < 0)
                {
                    iVar7 = 7;
                }

                iVar8 = D_24de[iVar1] + (uint)D_5c5a[1]._3_y;
                if (iVar8 > 7)
                {
                    iVar8 = 0;
                }
                if (iVar8 < 0)
                {
                    iVar8 = 7;
                }

                bVar2 = D_595a[iVar7 + iVar8 * 8 + D_5895_map_level * 0x40] & 0xf0;

                if (bVar2 != 0x60 && bVar2 != 0x80 && bVar2 < 0xa0)
                {
                    if (D_5c5a[2]._2_x != iVar7 || D_5c5a[2]._3_y != iVar8 || FUN_1000_2092_random_range(0, 7) == 1)
                    {
                        local_1c = 900;
                        break;
                    }
                }
            }

            if (local_1c == 900)
            {
                D_5c5a[2]._2_x = D_5c5a[1]._2_x;
                D_5c5a[2]._3_y = D_5c5a[1]._3_y;
                D_5c5a[1]._2_x = (byte)iVar7;
                D_5c5a[1]._3_y = (byte)iVar8;
            }
        }

        if (D_5c5a[2]._2_x == D_5896_map_x && D_5c5a[1]._3_y == D_5897_map_y)
        {
            local_10 = 1;
            D_5c5a[1]._2_x = D_5c5a[2]._2_x;
            D_5c5a[1]._3_y = D_5c5a[2]._3_y;
        }
    }
    return local_10;
}

// NOT MATCHING
// sleep spell
void F_DUNGEON_0948(void)
{
    int local_4;

    FUN_1000_1850_print_string(/*0x2d53*/ "Sleep spell!\n");

    for (local_4 = 0; local_4 < D_585b; local_4++)
    {
        if (D_55a8_party[local_4]._d <= FUN_1000_2092_random_range(1, 0x1e) && D_55a8_party[local_4]._b != 'D')
        {
            D_55a8_party[local_4]._b = 'S';
            FUN_1000_2a28(local_4);
            FUN_1000_223c_audio_white_noise(1, 0x32, 0xdac);
            D_a9fa = 1;
        }
    }

    D_595a[D_5896_map_x + D_5895_map_level * 0x40 + D_5897_map_y * 8] &= 8;
}

// NOT MATCHING
// poison
void F_DUNGEON_09e6(void)
{
    int local_4;

    FUN_1000_1850_print_string(/*0x2d61*/ "Poison!\n");

    for (local_4 = 0; local_4 < D_585b; local_4++)
    {
        if (D_55a8_party[local_4]._d <= FUN_1000_2092_random_range(1, 0x1e) && D_55a8_party[local_4]._b != 'D')
        {
            D_55a8_party[local_4]._b = 'P';
            FUN_1000_223c_audio_white_noise(1, 0x32, 0xdac);
        }
    }
}

// NOT MATCHING
void F_DUNGEON_0a4c(byte param_1)
{
    byte bVar1;
    byte bVar2;

    D_6602 = 5;
    while ((param_1 == 0x61 || param_1 == 0x69) && D_5895_map_level < 8)
    {
        FUN_1000_1850_print_string(/*0x2d6a*/ "Pit Trap!\n");
        FUN_1000_1850_print_string(/*0x2d75*/ "Falling...\n");

        bVar1 = D_5896_map_x;
        bVar2 = D_5897_map_y;

        D_595a[D_5895_map_level * 0x40 + bVar2 * 8 + bVar1] &= 0xf8;

        D_5895_map_level++;

        param_1 = D_595a[D_5895_map_level * 0x40 + bVar2 * 8 + bVar1];
        if (param_1 < 0x90)
        {
            param_1 = param_1 | 8;
            D_595a[D_5895_map_level * 0x40 + D_5897_map_y * 8 + D_5896_map_x] = param_1;
        }

        F_DUNGEON_1be0();
        FUN_1000_1850_print_string(/*0x2d81*/ "      ...splat!\n");
        FUN_1000_2aa8();
    }

    if (D_5895_map_level == 8)
    {
        D_5893_map_id = 0;
    }

    if (D_5893_map_id != 0)
    {
        bVar1 = D_595a[D_5896_map_x + D_5895_map_level * 0x40 + D_5897_map_y * 8] & 0xf0;
        if (bVar1 == 0xa0 || bVar1 == 0xf0)
        {
            F_DNGLOOK_1130();
            F_DUNGEON_0000(D_595a[D_5896_map_x + D_5895_map_level * 0x40 + D_5897_map_y * 8]);
            if (D_5893_map_id == 0)
            {
                return;
            }

            F_DNGLOOK_109e(1);
        }

        F_DUNGEON_0134(1);
    }
}

// NOT MATCHING
void F_DUNGEON_0b7e(void)
{
    FUN_1000_1850_print_string(/*0x2d92*/ "Attacked");

    if (((D_5c5a[2]._2_x - 1) & 7) == D_5896_map_x)
    {
        D_6602 = 1;
    }
    else if (((D_5c5a[2]._2_x + 1) & 7) == D_5896_map_x)
    {
        D_6602 = 3;
    }
    else if (((D_5c5a[2]._3_y - 1) & 7) == D_5897_map_y)
    {
        D_6602 = 2;
    }
    else
    {
        D_6602 = 0;
    }

    if (D_6602 != D_6603)
    {
        FUN_1000_1850_print_string(/*0x2d9b*/ " from the ");

        switch (D_6602)
        {
        case 0:
            FUN_1000_1850_print_string(/*0x2da6*/ "north");
            break;
        case 1:
            FUN_1000_1850_print_string(/*0x2dac*/ "east");
            break;
        case 2:
            FUN_1000_1850_print_string(/*0x2db1*/ "south");
            break;
        case 3:
            FUN_1000_1850_print_string(/*0x2db7*/ "west");
            break;
        }

        D_6603 = D_6602;
    }

    FUN_1000_1850_print_string(/*0x2dbc*/ "!\n");
    F_DUNGEON_1be0();
    FUN_1000_1b16_clear_keyboard_buffer();
    FUN_1000_20fa_wait_ticks(2);
    F_DNGLOOK_1130();
    D_58a0 = 0;
    D_58a1 = 2;
    F_DNGLOOK_0d3e();
    FUN_1000_5f86_special_handler(2, D_5c5a[1]._5, 0);
    F_DNGLOOK_0fda();
    F_DNGLOOK_109e(1);
    F_DUNGEON_0134(1);
    if (D_5893_map_id != 0)
    {
        F_DUNGEON_1be0();
    }
}

// NOT MATCHING
void F_DUNGEON_0c76(byte param_1, int param_2)
{
    int iVar2;
    int iVar3;
    char local_6;
    byte local_5;

    iVar2 = 0;
    local_6 = 0;
    for (iVar3 = 0; iVar3 < D_585b; iVar3++)
    {
        if (D_55a8_party[iVar3]._b == 'S' && FUN_1000_2092_random_range(0, 0x3f) < 4)
        {
            D_55a8_party[iVar3]._b = 'G';
            local_6++;
        }
    }

    if (local_6 != 0)
    {
        FUN_1000_2900_update_vitals();
    }

    if (param_2 != 0)
    {
        iVar2 = F_DUNGEON_07e2();
    }

    if (iVar2 != 0)
    {
        F_DUNGEON_0b7e();
        param_1 = D_595a[D_5896_map_x + D_5897_map_y * 8 + D_5895_map_level * 0x40];
    }

    local_5 = param_1 & 0xf0;
    if (local_5 == 0xf0 || local_5 == 0xa0)
    {
        F_DNGLOOK_1130();
        while ((local_5 == 0xf0 || local_5 == 0xa0) && FUN_1000_39fc_get_first_active_party_member() > -1 &&
               (F_DUNGEON_0000(param_1), D_5893_map_id != 0))
        {
            param_1 = D_595a[D_5896_map_x + D_5897_map_y * 8 + D_5895_map_level * 0x40];
            local_5 = param_1 & 0xf0;
        }

        F_DNGLOOK_109e(1);

        if (D_5893_map_id > 0x20)
        {
            F_DUNGEON_1be0();
        }
    }
    else
    {
        switch (param_1)
        {
        case 0x80:
        case 0x88:
            F_DUNGEON_0948();
            break;

        case 0x81:
        case 0x89:
            F_DUNGEON_09e6();
            break;

        case 0x82:
        case 0x8a:
            FUN_1000_1850_print_string(/*0x2dbf*/ "Fire!!\n");
            FUN_1000_2aa8();
            break;

        case 0x61:
        case 0x69:
            F_DUNGEON_0a4c(param_1);
            break;

        case 0x62:
        case 0x6a:
            FUN_1000_1850_print_string(/*0x2dc7*/ "Bomb Trap!\n");
            FUN_1000_1850_print_string(/*0x2dd3*/ "KABOOM!!\n");
            D_595a[D_5896_map_x + D_5897_map_y * 8 + D_5895_map_level * 0x40] &= 8;
            FUN_1000_2aa8();
            break;
        }

        FUN_1000_2900_update_vitals();
    }

    FUN_1000_2ae8();
}

void F_DNGLOOK_093a(void);
void F_DNGLOOK_1130();
void F_DNGLOOK_109e(int param_1);

void F_BLCKTHRN_0910_death(void);

// NOT MATCHING
void F_DUNGEON_0e2e_MainLoop(int param_1)
{
    register int si, di;
    int local_e;
    int local_c; // -> si
    int local_a;
    int local_8;
    u8 local_6; // -> di
    int local_4;
    u8 local_2;

#ifdef _WIN32
    local_a = 0;
#endif

    local_c = 1;
    local_e = 0;
    local_4 = 0;
    D_bb17 = 2;
    F_DNGLOOK_093a();
    local_6 = D_595a[D_5895_map_level * 0x40 + D_5897_map_y * 8 + D_5896_map_x];
    local_6 &= 0xf0;
    F_DUNGEON_0332();
    F_DUNGEON_01d2_print_walk_dir();
    local_8 = D_5893_map_id - 0x20;
    if (local_8 == 1 || local_8 == 4 || local_8 == 5)
    {
        // 0e95
        D_bb14 = 0x4f;
        D_bb15 = 0x45;
        D_6604 = 3;
    }
    else
    {
        // 0ea6
        D_bb14 = 0x4d;
        D_bb15 = 5;
        if (local_8 == 6 || local_8 == 7)
        {
            // 0ebc
            D_6604 = 2;
        }
        else
        {
            // 0ec4
            D_6604 = 1;
        }
    }

    // 0ec9
    if (local_6 == 0xa0 || local_6 == 0xf0)
    {
        // 0ed5
        F_DNGLOOK_1130();
        F_DUNGEON_0000(D_595a[(D_5895_map_level & 0xff) * 0x40 + D_5897_map_y * 8 + D_5896_map_x]);
    }

    if (D_5893_map_id > 0x20)
    {
        F_DNGLOOK_109e(param_1);
        F_DUNGEON_0134(param_1);
        F_DUNGEON_1be0();
    }

    // 0f15
    di = local_4;
    si = local_a;

    while (local_c != 0 && D_5893_map_id > 0x20) // 0f93
    {
        local_c = 1;
        si = 1;
        local_e = FUN_1000_39fc_get_first_active_party_member();
        if (local_e == si)
        {
            FUN_1000_16ba_print_char(10);
            FUN_1000_4c2a();
            FUN_1000_1850_print_string("Zzzzzz...\n");
        }

        // 0fc3
        if (local_e < 0)
        {
            local_c = 0;
            si = 0;
        }

        // 0fd0
        if (local_e != 0)
            continue;

        if (D_587a != 'T' && D_587a != 'Q')
        {
            // 0fea -> 0f2e
            di = 1;
            FUN_1000_4f7c(1);
        }
        else
        {
            if (D_587a == 'Q')
            {
                di ^= 1;
                if (di != 0)
                {
                    FUN_1000_4f7c(1);
                }
            }
            else
            {
                di = 0;
            }
        }

        // 0f36
        local_8 = F_DUNGEON_03d6();
        if (local_8 > -1)
        {
            si = F_DUNGEON_06c4_process_command(local_8);
        }

        if (D_5893_map_id < 0x21)
        {
            si = 0;
            local_c = si;
        }

        // 0f53
        local_2 = D_595a[(D_5895_map_level & 0xff) * 0x40 + D_5897_map_y * 8 + D_5896_map_x];
        local_6 = local_2 & 0xf0;
        if (si != 0)
        {
            F_DUNGEON_0c76(local_2, di);
        }

        if (D_5893_map_id >= 0x21)
        {
            continue;
        }

        si = 0;
        local_c = si;
    }

    // 0ff2
    local_4 = di;
    local_a = si;
    if ((D_bb17 & 2) != 0)
    {
        D_bb17 &= 0xfb;
    }
    else
    {
        D_bb17 |= 4;
    }
    // 100b
    F_DNGLOOK_1130();
    if (local_e < 0)
    {
        F_BLCKTHRN_0910_death();
    }
}

// NOT MATCHING
void F_DUNGEON_1020(void)
{
    D_24e7 ^= 1;
    if (D_24e7 != 0 && D_a9fb != 0)
    {
        FUN_1000_223c_audio_white_noise(1, D_a9fb, 20000);
        FUN_1000_3f36(&D_a9fb, 4);
    }
}

// NOT MATCHING
void F_DUNGEON_104c(int param_1)
{
    int iVar1;

    if (param_1 <= D_2df0[D_5893_map_id - 0x21])
    {
        iVar1 = D_2de8[D_5893_map_id - 0x21] + param_1;
        FUN_1000_1c22_set_text_window_size(0, D_2df8[iVar1 - 1], D_2e04[iVar1 - 1], 0x27, 0x18);
        FUN_1000_1b94_select_charset(0);
        FUN_1000_1c9e_set_charset(1);
        FUN_1000_1bf2_set_text_cursor_position(0, 0);
        FUN_1000_16ba_print_char(0xfd);
        FUN_1000_1850_print_string(D_2e10[iVar1 - 1]);
        FUN_1000_16ba_print_char(0xfd);
        FUN_1000_1c9e_set_charset(0);
        FUN_1000_1b94_select_charset(2);
        FUN_1000_1c22_set_text_window_size(0, 0, 0, 0x27, 0x18);
    }
}

// NOT MATCHING
byte F_DUNGEON_10dc(int param_1, int param_2)
{
    byte bVar1;

    bVar1 = D_595a[D_5895_map_level * 0x40 + (param_2 & 7) * 8 + (param_1 & 7)];
    if (bVar1 < 0x90)
    {
        bVar1 &= 0xf7;
    }

    return bVar1;
}

// NOT MATCHING
void F_DUNGEON_111e(int param_1)
{
    byte bVar1;
    int uVar2;
    int uVar3;
    int uVar4;
    int uVar5;
    int local_e;
    byte local_a;
    int local_8;
    int local_6;
    byte local_4;

    if (D_587a == 'T')
    {
        D_5c5a[1]._6 = D_1744[D_5c5a[1]._0_tile];
    }

    uVar3 = (uint)(D_5c5a[1]._7 == 0xff);
    bVar1 = D_5c5a[1]._6;
    uVar4 = (uint)bVar1;
    uVar5 = uVar4 & 0x60;
    local_8 = uVar4 & 0xf;

    if (D_587a == 'T')
    {
        local_e = 1;
        local_6 = 1;
    }
    else
    {
        local_6 = FUN_1000_2092_random_range(0, 100) < 0x32;
        local_e = FUN_1000_2092_random_range(0, 100) < 0x32;
        if (uVar5 == 0x20)
        {
            local_e = (bVar1 & 0xf) == 0;
            local_8 = local_e;
            local_6 = local_e;
        }
        else if (uVar5 != 0x40 && uVar5 == 0x60)
        {
            local_8--;
            if (local_8 < 0)
            {
                local_8 = 3;
            }
            local_6 = D_2e26[local_8] >> 1;
            local_e = D_2e26[local_8] & 1;
        }
    }

    if ((bVar1 & 0x90) != 0)
    {
        local_e = ((uVar4 & 0x90) == 0x90) ^ local_6;
    }

    if (D_a9c6 == 0)
    {
        // debug message?
        FUN_1000_1850_print_string(/*0x6c4e*/ "Hey!! What's going on here???");
    }
    else
    {
        uVar2 = D_2e32[uVar3 * 4 + param_1];
        FUN_1000_0d4c_GRAP_4b_put_image(D_a9c6, local_6 * 3 + param_1 - 1, D_2e2a[param_1], uVar2, uVar3);
        FUN_1000_0bfc_GRAP_63(D_a9c6, local_e * 3 + param_1 - 1, 0x60, uVar2, uVar3);
        local_4 = uVar5;
        local_a = uVar4 & 0x90;
        D_5c5a[1]._6 = local_4 + local_a + local_8;
    }
}

// NOT MATCHING
void F_DUNGEON_127e(int param_1, int param_2)
{
    int uVar1;
    int iVar2;
    int iVar3;
    int uVar4;
    int iVar5;
    int uVar6;
    int iVar7;

    uVar1 = D_52ba_vdp._52c4;
    D_52ba_vdp._52c4 = 0;

    if (param_2 == 0)
    {
        FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b6 + 8);
    }
    else if (param_2 == 1)
    {
        FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b4 + 8);
    }
    else if (param_2 == 2)
    {
        FUN_1000_0a70_GRAP_2d_set_pen_color(D_13ae + 8);
    }
    else if (param_2 == 3)
    {
        FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b2_frame_color + 8);
    }

    if (D_2e52[param_1] > 0)
    {
        iVar7 = D_2e52[param_1];
        iVar2 = D_2e5a[param_1];
        iVar3 = D_2e4a[param_1];
        uVar4 = D_2e42[param_1];

        for (; iVar7 >= 0; iVar7--)
        {
            iVar5 = FUN_1000_2092_random_range(uVar4, iVar3 - iVar2);
            uVar6 = FUN_1000_2092_random_range(uVar4, iVar3);
            FUN_1000_0c9c_GRAP_39_horiz_line(iVar5, uVar6, iVar2 + iVar5);
        }
    }

    D_52ba_vdp._52c4 = uVar1;
}

// NOT MATCHING
void F_DUNGEON_134a(int param_1, int param_2, int param_3)
{
    int uVar1;
    int uVar2;
    int local_8;

    if (param_1 < 0x1f)
    {
        local_8 = D_2e62[(param_1 & 3) + param_3 * 4];
        if (param_3 != 0 && (((byte)param_1 & 0xf8) == 8 || ((byte)param_1 & 0xfc) == 0x18))
        {
            local_8 = 0x60;
        }

        if (param_3 == 0)
        {
            FUN_1000_0d4c_GRAP_4b_put_image(D_a9c0, param_1, local_8, 0xe, 0);
        }
        else
        {
            FUN_1000_0bfc_GRAP_63(D_a9c0, param_1, local_8, 0xe, 0);
        }
    }
    else
    {
        uVar1 = param_1 + 1;
        param_1 = (uVar1 >> 1) - 0x10;
        uVar1 = (uVar1 & 6) >> 1;
        if (param_3 == 0)
        {
            local_8 = D_2e72[uVar1];
        }
        else
        {
            local_8 = 0x60;
        }

        if (param_1 < 8)
        {
            if (param_2 == 0)
            {
                uVar2 = 0x60;
            }
            else
            {
                uVar2 = D_2e82[uVar1];
            }
        }
        else
        {
            uVar2 = D_2e7a[uVar1 + param_2 * 4];
        }

        if (param_3 == 0)
        {
            // TODO: ITEMS.16, MON*.16 contain different format
            FUN_1000_0d4c_GRAP_4b_put_image(D_a9c4, param_1, local_8, uVar2, param_2);
        }
        else
        {
            // TODO: ITEMS.16, MON*.16 contain different format
            FUN_1000_0bfc_GRAP_63(D_a9c4, param_1, local_8, uVar2, param_2);
        }
    }
}

// NOT MATCHING
int F_DUNGEON_145c(int param_1, int param_2, int param_3, int param_4)
{
    if (param_3 == 5)
    {
        param_3 = 0;
        FUN_1000_43ae(0xc80, 0xdac, 1, -(param_4 * 8 + 0xec));
    }
    else
    {
        if (param_3 == 4)
        {
            if (D_52c8 == 0 || D_52c8 == 3)
            {
                FUN_1000_0a70_GRAP_2d_set_pen_color(3);
            }
            else
            {
                FUN_1000_0a70_GRAP_2d_set_pen_color(0xb);
            }
        }
        else
        {
            FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b2_frame_color);
        }

        FUN_1000_0c9c_GRAP_39_horiz_line(param_1 - 1, param_2, param_1 + 1);
        FUN_1000_0cf2_GRAP_3c_vert_line(param_1, param_2 - 1, param_2 + 1);

        if (param_3 < 4)
        {
            FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b2_frame_color + 8);
            FUN_1000_0c64_GRAP_30_pset(param_1, param_2);
        }

        if (param_3 != 0 || FUN_1000_2092_random_range(0, 0x40) < 4)
        {
            param_3++;
        }
    }

    return param_3;
}

// NOT MATCHING
int F_DUNGEON_150a(int param_1, int param_2, int param_3)
{
    byte cVar3;
    uint uVar4;
    byte local_6;
    int local_4;

    uVar4 = F_DUNGEON_10dc(param_1, param_2);
    if (uVar4 > 0x9f)
    {
        local_4 = (uint)D_2e8a[(uVar4 >> 4) - 0xa] + param_3;
        if (param_3 == 0)
        {
            local_4 = 0xc;
        }

        F_DUNGEON_134a(local_4, 0, 0);
        F_DUNGEON_134a(local_4, 0, 1);

        local_6 = (byte)uVar4;
        if ((param_3 == 1 || param_3 == 2) && D_6604 == 1 && (local_6 & 0xf0) == 0xc0)
        {
            cVar3 = F_DUNGEON_145c(0x5f, D_2e90[(uVar4 & 7) + (param_3 - 1) * 5] + 0xe, uVar4 & 7, param_3);
            D_595a[D_5895_map_level * 0x40 + (param_2 & 7) * 8 + (param_1 & 7)] &= 0xf8;
            D_595a[D_5895_map_level * 0x40 + (param_2 & 7) * 8 + (param_1 & 7)] += cVar3;
        }

        if (param_3 == 1)
        {
            if ((local_6 & 0xf0) == 0xb0 && (uVar4 & 0xf) != 0)
            {
                F_DUNGEON_104c(uVar4 & 0xf);
            }
            else if (D_6604 == 3 && (local_6 & 0xf0) == 0xc0 && FUN_1000_2092_random_range(0, 0x40) < 4)
            {
                FUN_1000_0a70_GRAP_2d_set_pen_color(D_13ae + 8);
                FUN_1000_0c9c_GRAP_39_horiz_line(0x5c, 0x57, 0x5d);
                FUN_1000_0c9c_GRAP_39_horiz_line(0x5b, 0x58, 0x5d);
                FUN_1000_0c9c_GRAP_39_horiz_line(0x61, 0x57, 0x62);
                FUN_1000_0c9c_GRAP_39_horiz_line(0x61, 0x58, 99);
            }
        }

        if ((local_6 & 0xf0) != 0xe0 || param_3 != 0)
        {
            return 0;
        }

        D_52ba_vdp._52c4 = 1;
    }

    return 1;
}

// NOT MATCHING
void F_DUNGEON_1682(int param_1, int param_2, int param_3, int param_4)
{
    byte bVar2;
    byte cVar3;
    int uVar4;
    int local_6;

    uVar4 = F_DUNGEON_10dc(param_1, param_2);
    if (uVar4 < 0xa0)
    {
        param_4 += 0x10;
        F_DUNGEON_134a(param_4, 0, param_3);
    }
    else
    {
        switch (uVar4 & 0xf0)
        {
        case 0xa0:
        case 0xe0:
        case 0xf0:
            param_4 += 4;
            F_DUNGEON_134a(param_4, 0, param_3);
            break;

        case 0xc0:
            F_DUNGEON_134a(param_4 + 0x14, 0, param_3);
            if (param_4 > 1)
            {
                break;
            }

            if (D_6604 != 1)
            {
                break;
            }

            if (param_4 == 0)
            {
                local_6 = 0x21;
            }
            else
            {
                local_6 = 0x43;
            }

            if (param_3 != 0)
            {
                local_6 = 0xbe - local_6;
            }

            cVar3 = F_DUNGEON_145c(local_6, D_2e9a[(uVar4 & 7) + param_4 * 5] + 0xe, uVar4 & 7, param_4);
            bVar2 = D_5895_map_level;

            D_595a[(uint)bVar2 * 0x40 + (param_2 & 7) * 8 + (param_1 & 7)] &= 0xf8;
            D_595a[(uint)bVar2 * 0x40 + (param_2 & 7) * 8 + (param_1 & 7)] += cVar3;
            break;
        }
    }
}

// NOT MATCHING
void F_DUNGEON_1786(int param_1, int param_2)
{
    byte uVar1;
    byte bVar2;
    byte bVar3;
    int uVar4;
    int iVar5;

    if (D_52c8 == 0 || D_52c8 == 3)
    {
        FUN_1000_0a70_GRAP_2d_set_pen_color(0);
    }
    else
    {
        FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b2_frame_color);
    }

    switch (param_1)
    {
    case 0:
        if (D_52c8 != 0 && D_52c8 != 3)
        {
            FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b2_frame_color + 8);
        }

        for (iVar5 = 0; iVar5 < 8; iVar5++)
        {
            uVar1 = D_2ea4[param_2 * 8 + iVar5]._1;
            bVar2 = D_2ea4[param_2 * 8 + iVar5]._0;

            FUN_1000_0c64_GRAP_30_pset(bVar2, uVar1);
            FUN_1000_0c64_GRAP_30_pset(0xbe - bVar2, uVar1);
        }

        uVar4 = D_2f10[param_2]._1;
        bVar2 = D_2f10[param_2]._0;
        FUN_1000_0c64_GRAP_30_pset(bVar2, uVar4);
        FUN_1000_0c64_GRAP_30_pset(0xbe - bVar2, uVar4);
        break;

    case 1:
        for (iVar5 = 0; iVar5 < 5; iVar5++)
        {
            bVar2 = D_2ed4[param_2 * 8 + iVar5]._1;
            bVar3 = D_2ed4[param_2 * 8 + iVar5]._0;
            FUN_1000_0c64_GRAP_30_pset(bVar3 + 0x48, bVar2 + 0x60);
            FUN_1000_0c64_GRAP_30_pset(0x76 - bVar3, bVar2 + 0x60);
        }
        break;

    case 2:
        for (iVar5 = 0; iVar5 < 4; iVar5++)
        {
            bVar2 = D_2ef2[param_2 * 4 + iVar5]._1;
            bVar3 = D_2ef2[param_2 * 4 + iVar5]._0;
            FUN_1000_0c64_GRAP_30_pset(bVar3 + 0x50, bVar2 + 0x60);
            FUN_1000_0c64_GRAP_30_pset(0x6e - bVar3, bVar2 + 0x60);
        }
        break;

    case 3:
        uVar4 = D_2f0a[param_2]._1 + 0x60;
        bVar2 = D_2f0a[param_2]._0;
        FUN_1000_0c64_GRAP_30_pset(bVar2 + 0x58, uVar4);
        FUN_1000_0c64_GRAP_30_pset(0x66 - bVar2, uVar4);
        break;
    }
}

// NOT MATCHING
void F_DUNGEON_1952(int param_1, int param_2, int param_3)
{
    int uVar1;
    int iVar2;
    int iVar3;

    uVar1 = F_DUNGEON_10dc(param_1, param_2);
    iVar2 = uVar1 >> 4;
    if (iVar2 >= 1 && iVar2 <= 7 && (iVar2 != 6 || (uVar1 & 7) == 0))
    {
        if (D_2f16[iVar2] != 0)
        {
            iVar3 = D_2f16[iVar2] + param_3 * 2;
            F_DUNGEON_134a(iVar3, 1, 0);
            F_DUNGEON_134a(iVar3, 1, 1);
        }

        if (D_2f1e[iVar2] != 0)
        {
            iVar3 = D_2f1e[iVar2] + param_3 * 2;
            F_DUNGEON_134a(iVar3, 0, 0);
            F_DUNGEON_134a(iVar3, 0, 1);
        }

        if (iVar2 == 5)
        {
            F_DUNGEON_1786(param_3, D_2f26);
        }
    }
    else if (iVar2 == 8)
    {
        F_DUNGEON_127e(param_3, uVar1 & 7);
    }

    if (iVar2 < 9 && (D_595a[D_5895_map_level * 0x40 + (param_2 & 7) * 8 + (param_1 & 7)] & 8) != 0)
    {
        iVar2 = param_3 * 2 + D_2f24;
        F_DUNGEON_134a(iVar2, 1, 0);
        F_DUNGEON_134a(iVar2, 1, 1);
    }

    if (param_3 != 0 && (param_1 & 7) == D_5c5a[1]._2_x && (param_2 & 7) == D_5c5a[1]._3_y)
    {
        F_DUNGEON_111e(param_3);
    }

    if (param_3 == 0 && ++D_2f26 > 2)
    {
        D_2f26 = 0;
    }
}

// NOT MATCHING
void F_DUNGEON_1a90(int param_1)
{
    int iVar1;
    int iVar2;
    int iVar4;
    uint uVar5;
    uint local_8;

    D_545e = 0xff;
    FUN_1000_0c22_GRAP_0f_select_page(1);
    FUN_1000_0a70_GRAP_2d_set_pen_color(0);
    FUN_1000_0aa6_GRAP_3f_fill_rectangle(0x60, 0xe, 0xaf, 0xb2);
    FUN_1000_0c3c(0x28, 0x2a, 0x98, 0xb7);
    D_52ba_vdp._52c4 = 0;

    if (D_58a6 == 0 && D_58a7 == 0)
    {
        FUN_1000_0aa6_GRAP_3f_fill_rectangle(8, 8, 0xb7, 0xb7);
    }
    else
    {
        uVar5 = (uint)D_5896_map_x;
        local_8 = (uint)D_5897_map_y;
        iVar1 = D_24d6[D_6603];
        iVar2 = D_24de[D_6603];

        for (iVar4 = 0; iVar4 < 4; iVar4++)
        {
            if (F_DUNGEON_150a(uVar5, local_8, iVar4) == 0)
                break;

            if (iVar4 != 0 || (F_DUNGEON_10dc(D_5896_map_x, D_5897_map_y) != 0xe0 && param_1 != 0))
            {
                F_DUNGEON_1682(D_2f28[D_6603] + uVar5, D_2f2c[D_6603] + local_8, 0, iVar4);
                F_DUNGEON_1682(uVar5 - D_2f28[D_6603], local_8 - D_2f2c[D_6603], 1, iVar4);
            }

            uVar5 += iVar1;
            local_8 += iVar2;
        }

        while (--iVar4 >= 0)
        {
            uVar5 -= iVar1;
            local_8 -= iVar2;
            F_DUNGEON_1952(uVar5, local_8, iVar4);
        }
    }

    FUN_1000_0c22_GRAP_0f_select_page(0);
    D_52ba_vdp._52c4 = 0;
}

// NOT MATCHING
void F_DUNGEON_1be0(void)
{
    FUN_1000_2900_update_vitals();
    F_DUNGEON_1a90(1);
    FUN_1000_0ace_GRAP_18_transfer_area(1, 0, 0x10, 0xe, 0xaf, 0xb2);
    F_DUNGEON_1020();
    F_DUNGEON_01d2_print_walk_dir();
}

// NOT MATCHING
int F_DUNGEON_1c0c(int param_1, int param_2)
{
    int local_6;
    int local_4;

    local_4 = 1;
    local_6 = D_595a[D_5896_map_x + param_2 * 0x40 + D_5897_map_y * 8] & 0xf0;
    if (param_1 != 0 &&
        (local_6 != 0 || local_6 == 0xe0 || local_6 == 0xd0 || local_6 == 0xc0 || local_6 == 0xb0)) // logic bug?
    {
        local_4 = 0;
    }

    return local_4;
}

// NOT MATCHING
int F_DUNGEON_1c6a(int param_1, int param_2)
{
    int local_4;

    local_4 = 0;

    if (param_1 >= 1)
    {
        FUN_1000_1850_print_string(/*0x6c6c*/ "Down!\n");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x6c74*/ "Up!\n");
    }

    if ((param_1 < 1 || D_5895_map_level != 7) && (param_1 >= 0 || D_5895_map_level != 0))
    {
        if (F_DUNGEON_1c0c(param_1 + (uint)D_5895_map_level, param_2) == 0)
        {
            FUN_1000_1850_print_string(/*0x6c7a*/ "Failed!\n");
            FUN_1000_43ae(800, 2000, 1, 0x32);
        }
        else
        {
            D_5895_map_level += param_1;
            if (param_1 < 1)
            {
                D_6602 = 4;
            }
            else
            {
                D_6602 = 5;
            }

            F_DUNGEON_0134(1);
            F_DUNGEON_1be0();
        }
    }
    else
    {
        local_4 = 1;
    }

    return local_4;
}

// NOT MATCHING
void F_DUNGEON_1d08(void)
{
    D_5896_map_x = D_1e8a[D_5893_map_id - 1];
    D_5897_map_y = D_1eb2[D_5893_map_id - 1];

    FUN_1000_1850_print_string(/*0x6c84*/ "\nExit to ");
    if (D_5895_map_level != 0)
    {
        D_5895_map_level = 0xff;
        FUN_1000_1850_print_string(/*0x6c8e*/ "Underworld!\n\n");
    }
    else
    {
        D_5895_map_level = 0;
        FUN_1000_1850_print_string(/*0x6c9c*/ "Britannia!\n\n");
    }

    D_5893_map_id = 0;
}

// NOT MATCHING
int F_DUNGEON_1d4a_attack_cmd(void)
{
    FUN_1000_1850_print_string(/*0x6caa*/ "Attack\n");
    if ((D_24d6[D_6603] + D_5896_map_x & 7) != D_5c5a[1]._2_x || (D_24de[D_6603] + D_5897_map_y & 7) != D_5c5a[1]._3_y)
    {
        FUN_1000_1850_print_string(/*0x6cb2*/ "What?\n");
        return 0;
    }

    D_58a1 = 2;
    F_DNGLOOK_1130();
    F_DNGLOOK_0c6c();
    F_DNGLOOK_0d3e();
    FUN_1000_5f86_special_handler(0, D_5c5a[1]._5, 2);

    if (D_58a0 == 5)
    {
        if (D_5895_map_level != 0)
        {
            D_5895_map_level--;
        }
        else
        {
            F_DUNGEON_1d08();
        }
    }
    else if (D_58a0 == 6)
    {
        if (D_5895_map_level < 7)
        {
            D_5895_map_level++;
        }
        else
        {
            F_DUNGEON_1d08();
        }
    }

    F_DNGLOOK_109e(1);

    if (D_5893_map_id != 0)
    {
        F_DUNGEON_0134(1);
        F_DUNGEON_1be0();
    }

    return 0;
}

// NOT MATCHING
int F_DUNGEON_1e10_klimb_cmd(void)
{
    int bVar1;
    int bVar2;
    int uVar3;

    bVar1 = 0;
    bVar2 = 0;
    uVar3 = F_DUNGEON_10dc(D_5896_map_x, D_5897_map_y);
    uVar3 = uVar3 & 0xf0;
    if (uVar3 == 0x10 || uVar3 == 0x30 ||
        ((D_595a[D_5896_map_x + D_5895_map_level * 0x40 + D_5897_map_y * 8] & 8) != 0 && D_57af != 0))
    {
        bVar1 = 1;
    }

    if (uVar3 == 0x20 || uVar3 == 0x30 || uVar3 == 0x60)
    {
        bVar2 = 1;
    }

    if (bVar1 && bVar2)
    {
        FUN_1000_1850_print_string(/*0x6cba*/ "Klimb-U/D-");
        while (bVar1 && bVar2)
        {
            switch (FUN_1000_266c_get_ch())
            {
            case 3:
            case 0x55:
                bVar2 = 0;
                break;

            case 4:
            case 0x44:
                bVar1 = 0;
                break;

            case 0x20:
                FUN_1000_1850_print_string(/*0x6cc6*/ "Pass\n\n");
                bVar2 = 0;
                bVar1 = 0;
                break;
            }
        }
    }
    else
    {
        if (!bVar1 && !bVar2)
        {
            if ((D_595a[D_5896_map_x + D_5895_map_level * 0x40 + D_5897_map_y * 8] & 8) != 0)
            {
                FUN_1000_1850_print_string(/*0x6cd6*/ "Klimb-\nWith What?\n");
            }
            else
            {
                FUN_1000_1850_print_string(/*0x6cea*/ "Klimb-what?\n");
            }

            return 0;
        }

        FUN_1000_1850_print_string(/*0x6cce*/ "Klimb-");
    }

    if ((bVar1 && F_DUNGEON_1c6a(-1, 0) != 0) || (bVar2 && F_DUNGEON_1c6a(1, 0) != 0))
    {
        F_DUNGEON_1d08();
    }

    return 1;
}
