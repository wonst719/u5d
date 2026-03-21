#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdlib.h>

void F_FONT_0000(byte* param_1, char* param_2);

// NOT MATCHING
void F_ENDGAME_0000(void)
{
    byte* pbVar1;
    byte* pbVar2;
    byte* pbVar3;
    uint local_a;
    int local_8;

    ULTIMA_251e_switch_disks(2);

    do
    {
        pbVar1 = ULTIMA_0fae_load_file(D_25ea[0]); // PROPORT.PCS
    } while (pbVar1 == 0);

    do
    {
        pbVar2 = ULTIMA_0bae_load_image_file(D_25ea[0x11]); // TEXT.16
    } while (pbVar2 == 0);

    do
    {
        pbVar3 = ULTIMA_0bae_load_image_file(D_25ea[0x18]); // END1.16
    } while (pbVar3 == 0);

    ULTIMA_0f46_GRAP_66(0, 0, 0x13f, 199);
    ULTIMA_1b94_select_text_window(0);

    local_a = 0x31;
    for (local_8 = 0; local_8 < 6; local_8++)
    {
        if (D_3df4[local_8] != local_a)
        {
            ULTIMA_0be4_free_memory(pbVar3);
            local_a = (uint)D_3df4[local_8];
            do
            {
                pbVar3 = ULTIMA_0bae_load_image_file(D_25ea[0x18 + local_a]);
            } while (pbVar3 == 0);
        }

        ULTIMA_0c22_GRAP_0f_select_page(1);

        D_a9be = 2;
        ULTIMA_16ba_print_char(0xff);

        if (D_3e06[local_8] == 1)
        {
            if (local_8 == 0)
            {
                ULTIMA_0d4c_GRAP_4b_put_image(pbVar2, 0, 0xd8, 0, 0);
                ULTIMA_0d4c_GRAP_4b_put_image(pbVar2, 4, 0x98, 0x1c, 0);
            }
            else if (local_8 == 3)
            {
                ULTIMA_0d4c_GRAP_4b_put_image(pbVar2, 5, 0xe0, 0, 0);
                ULTIMA_0d4c_GRAP_4b_put_image(pbVar2, 0, 0xb0, 0, 0);
            }
        }

        ULTIMA_0d4c_GRAP_4b_put_image(pbVar3, D_3dee[local_8], D_3dfa[local_8], D_3e00[local_8], 0);

        D_5146[0] = D_3da6[local_8]._0;
        D_5146[1] = D_3da6[local_8]._1;
        D_514c[0] = D_3db2[local_8]._0;
        D_514c[1] = D_3db2[local_8]._2;
        D_5150 = D_3dd6[local_8];
        D_5152 = D_3ddc[local_8];
        D_5156 = D_3de2[local_8];
        D_5158 = D_3de8[local_8];

        ULTIMA_256e_read_file_from_disk(/*0x81fe*/ "END.DAT", D_b21e, 2000, D_3dca[local_8]);
        F_FONT_0000(pbVar1, D_b21e); // 7ce6 -> 1778:0566

        if (local_8 != 0)
        {
            while (ULTIMA_1d5e_peek_keystroke() == 0)
                ;
        }

        ULTIMA_0f6e_GRAP_1b_transfer_fullscreen(1, 0);
    }

    ULTIMA_0be4_free_memory(pbVar3);
    ULTIMA_0be4_free_memory(pbVar2);
    ULTIMA_0fdc_free_memory(pbVar1);

    while (ULTIMA_1d5e_peek_keystroke() == 0)
        ;

    ULTIMA_0c22_GRAP_0f_select_page(1);
    ULTIMA_16ba_print_char(0xff);

    do
    {
        pbVar1 = ULTIMA_0bae_load_image_file(D_25ea[0x1c]); // ENDSC.16
    } while (pbVar1 == 0);

    ULTIMA_0d4c_GRAP_4b_put_image(pbVar1, 0, 0x28, 0, 0);
    ULTIMA_0be4_free_memory(pbVar1);
    ULTIMA_0f6e_GRAP_1b_transfer_fullscreen(1, 0);
    ULTIMA_0c22_GRAP_0f_select_page(0);
    D_a9be = 0;
}

// NOT MATCHING
void F_ENDGAME_023a(char* param_1)
{
    byte bVar1;

    for (bVar1 = D_bcda; *param_1 != '\0' && bVar1 < 39; bVar1++)
    {
        D_bcb2[bVar1] = *param_1++;
    }

    D_bcda = bVar1;
    D_bcb2[bVar1] = 0;

    if (D_bcb2[bVar1 - 1] == '\n')
    {
        ULTIMA_1850_print_string(D_bcb2);
        D_bcda = 0;
    }
}

// NOT MATCHING
void F_ENDGAME_028c(int param_1)
{
    int iVar1;

    if (param_1 > 0x14)
    {
        F_ENDGAME_023a(D_3e32[param_1 / 10 - 2]);

        iVar1 = param_1 / 10;
        param_1 %= 10;
        if (param_1 == 0)
        {
            return;
        }

        F_ENDGAME_023a(/*0x82c6*/ "-");
    }

    F_ENDGAME_023a(D_3e0a[param_1]);
}

// NOT MATCHING
void F_ENDGAME_02d6(int param_1)
{
    if (param_1 < 13)
    {
        F_ENDGAME_023a(D_3e42[param_1 - 1]);
    }
    else if (param_1 < 20)
    {
        F_ENDGAME_028c(param_1);
        F_ENDGAME_023a(/*0x831e*/ "th");
    }
    else
    {
        F_ENDGAME_023a(/*0x8322*/ "Twent");
        if (param_1 == 20)
        {
            F_ENDGAME_023a(/*0x8328*/ "ieth");
        }
        else
        {
            F_ENDGAME_023a(/*0x832e*/ "y-");
            F_ENDGAME_023a(D_3e42[param_1 - 15]);
        }
    }
}

// NOT MATCHING
void F_ENDGAME_0326(void)
{
    char local_10[8];
    int local_8;
    int local_6;
    int local_4;

    ULTIMA_1bf2_set_text_cursor_position(0, 1);
    ULTIMA_16ba_print_char(0xfd);
    ULTIMA_16ba_print_char(0xfc);
    ULTIMA_1850_print_string(/*0x8332*/ "Be it known that on\n");
    D_bcda = 0;
    F_ENDGAME_023a(/*0x8348*/ "the ");
    F_ENDGAME_02d6(D_587e);
    F_ENDGAME_023a(/*0x834e*/ " Day of\n");
    F_ENDGAME_023a(/*0x8358*/ "the ");
    F_ENDGAME_02d6(D_587d);
    F_ENDGAME_023a(/*0x835e*/ " Month\n");
    ULTIMA_1850_print_string(/*0x8366*/ "of the Year\n");
    F_ENDGAME_028c(D_5874 / 100);
    F_ENDGAME_023a(/*0x8374*/ " Hundred\n");
    F_ENDGAME_028c(D_5874 % 100);
    F_ENDGAME_023a(/*0x837e*/ "\n\n");
    F_ENDGAME_023a(D_55a8_party[0]._0);
    F_ENDGAME_023a(/*0x8382*/ " the Avatar\n\n");
    ULTIMA_1850_print_string(/*0x8390*/ "saved the life\n");
    ULTIMA_1850_print_string(/*0x83a0*/ "of our sovereign\n");
    ULTIMA_1850_print_string(/*0x83b2*/ "Lord British, thereby\n");
    ULTIMA_1850_print_string(/*0x83ca*/ "saving our people\n");
    ULTIMA_1850_print_string(/*0x83de*/ "and our land.\n\n");
    ULTIMA_1c9e_set_charset(1);
    ULTIMA_1850_print_string(/*0x83ee*/ "[E@QUE_@OF@[E@AVATAR\n");
    ULTIMA_1850_print_string(/*0x8404*/ "IS@FOREVER\n\n\n\n");
    ULTIMA_1c9e_set_charset(0);
    ULTIMA_16ba_print_char(0xfd);
    ULTIMA_1850_print_string(/*0x8414*/ "Report now, thy Quest compleat in\n");

    local_6 = D_5874 + 0x75;
    local_8 = D_587d - 4;
    local_4 = D_587e - 5;
    if (local_4 < 0)
    {
        local_4 = D_587e + 0x17;
        local_8 = D_587d - 5;
    }

    if (local_8 < 0)
    {
        local_8 += 0xd;
        local_6 = D_5874 + 0x74;
    }

    if (local_6 != 0)
    {
        F_ENDGAME_023a(ULTIMA_0426_itoa(local_6, local_10, 10));
        F_ENDGAME_023a(/*0x8438*/ " year");
        if (local_6 > 1)
        {
            F_ENDGAME_023a(/*0x843e*/ "s");
        }

        if (local_8 != 0 || local_4 != 0)
        {
            F_ENDGAME_023a(/*0x8440*/ ", ");
        }
    }

    if (local_8 != 0)
    {
        F_ENDGAME_023a(ULTIMA_0426_itoa(local_8, local_10, 10));
        F_ENDGAME_023a(/*0x8444*/ " month");
        if (local_8 > 1)
        {
            F_ENDGAME_023a(/*0x844c*/ "s");
        }

        if (local_4 != 0)
        {
            F_ENDGAME_023a(/*0x844e*/ ", ");
        }
    }

    if (local_4 != 0)
    {
        F_ENDGAME_023a(ULTIMA_0426_itoa(local_4, local_10, 10));
        F_ENDGAME_023a(/*0x8452*/ " day");
        if (local_4 > 1)
        {
            F_ENDGAME_023a(/*0x8458*/ "s");
        }
    }

    F_ENDGAME_023a(/*0x845a*/ "\n");
    ULTIMA_1850_print_string(/*0x845c*/ "to Lord British at Origin Systems!");

    do
    {
        // infinite loop
    } while (1);
}

// NOT MATCHING
void F_ENDGAME_04fe(void)
{
    ULTIMA_3ae6(2);
    ULTIMA_433e_audio_some_noise();
    ULTIMA_3ae6(3);
}

// NOT MATCHING
// actor_idx, x, y
int F_ENDGAME_0510(int param_1, int param_2, int param_3)
{
    int ret;

    ret = 1;

    if (D_5c5a[param_1]._0_tile == 0 || (D_5c5a[param_1]._2_x == param_2 && D_5c5a[param_1]._3_y == param_3))
    {
        ret = 0;
    }
    else
    {
        if (abs(D_5c5a[param_1]._2_x - param_2) < abs(D_5c5a[param_1]._3_y - param_3))
        {
            if (param_3 < D_5c5a[param_1]._3_y)
            {
                D_5c5a[param_1]._3_y--;
            }
            else
            {
                D_5c5a[param_1]._3_y++;
            }
        }
        else if (param_2 < D_5c5a[param_1]._2_x)
        {
            D_5c5a[param_1]._2_x--;
        }
        else
        {
            D_5c5a[param_1]._2_x++;
        }

        F_ENDGAME_04fe();
    }

    return ret;
}

// NOT MATCHING
void F_ENDGAME_05a2(int param_1)
{
    uint uVar2;
    uint uVar3;
    int iStack_a;

    if (D_5c5a[param_1]._0_tile != 0 && ULTIMA_2092_random_range(0, 1) != 0)
    {
        for (iStack_a = 0; iStack_a < 8; iStack_a++)
        {
            uVar3 = D_5c5a[param_1]._2_x;
            uVar2 = D_5c5a[param_1]._3_y;

            switch (ULTIMA_2092_random_range(0, 3))
            {
            case 0:
                uVar3++;
                break;
            case 1:
                uVar3--;
                break;
            case 2:
                uVar2++;
                break;
            case 3:
                uVar2--;
                break;
            }

            if (D_ab02[uVar2 * 0x20 + uVar3] == 'D')
            {
                D_5c5a[param_1]._2_x = uVar3;
                D_5c5a[param_1]._3_y = uVar2;
                break;
            }
        }
    }

    ULTIMA_3ae6(1);
}

// NOT MATCHING
void F_ENDGAME_0648_endgame_main(void)
{
    byte uVar4;
    byte uVar5;
    int iVar7;
    int iVar8;
    int iVar11;
    int iVar12;
    int iStack_c;
    int iStack_4;

    D_589e = 0xff;
    ULTIMA_2900_update_vitals();
    ULTIMA_6f9e(1);
    ULTIMA_256e_read_file_from_disk(/*0x8480*/ "MISCMAPS.DAT", D_ac64, 0xb0, 0x210);
    ULTIMA_256e_read_file_from_disk(/*0x848e*/ "ENDMSG.DAT", D_b21e, 1000, 0);

    for (iVar12 = 0; iVar12 < 0xb; iVar12++)
    {
        for (iVar7 = 0; iVar7 < 0xb; iVar7++)
        {
            D_ad14[iVar12 * 0x20 + iVar7] = D_ac64[iVar12 * 0x10 + iVar7];
        }
    }

    for (iVar8 = 0; iVar8 < 0x20; iVar8++)
    {
        D_5c5a[iVar8]._0_tile = D_5c5a[iVar8]._1 = 0;
    }

    D_5c5a[31]._1 = 0x7c;
    D_5c5a[31]._0_tile = 0x7c;
    D_5c5a[31]._2_x = 5;
    D_5c5a[31]._3_y = 8;
    D_5c5a[31]._6 = 0;
    ULTIMA_3ae6(0x28);

    while (F_ENDGAME_0510(0x1f, 5, 3) != 0)
        ;

    for (iStack_c = 0; iStack_c < D_585b; iStack_c++)
    {
        if (D_55a8_party[iStack_c]._b == 'D')
        {
            ULTIMA_16ba_print_char(10);
            ULTIMA_1850_print_string(D_55a8_party[iStack_c]._0);
            ULTIMA_1850_print_string(/*0x849a*/ " lives!\n");
            D_55a8_party[iStack_c]._b = 'G';
            D_55a8_party[iStack_c]._10 = D_55a8_party[iStack_c]._12;
            ULTIMA_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
            ULTIMA_0b86(8, 8, 0xb7, 0xb7);
            ULTIMA_2192_audio_some_noise(0x2260, 1, 40000, 5000, 1);
            ULTIMA_2900_update_vitals();
        }

        iVar8 = ULTIMA_4d76(/*0x84a4*/ "AMBFDTPRS", D_55a8_party[iStack_c]._a);

        uVar4 = D_1ade[iVar8];

        D_5c5a[iStack_c]._1 = uVar4;
        D_5c5a[iStack_c]._0_tile = uVar4;
        D_5c5a[iStack_c]._2_x = 5;
        D_5c5a[iStack_c]._3_y = 9;
        D_5c5a[iStack_c]._6 = 0;

        ULTIMA_3ae6(1);

        if (F_ENDGAME_0510(iStack_c, D_3e5a[iStack_c], D_3e60[iStack_c]) != 0)
        {
            uVar4 = D_3e60[iStack_c];
            uVar5 = D_3e5a[iStack_c];

            while (F_ENDGAME_0510(iStack_c, uVar5, uVar4) != 0)
                ;
        }
    }

    ULTIMA_3ae6(0x28);
    ULTIMA_1850_print_string((char*)D_b21e);
    ULTIMA_1850_print_string(D_55a8_party[0]._0);
    ULTIMA_1850_print_string(/*0x84ae*/ "!\"\n\n");
    ULTIMA_266c_get_ch();
    ULTIMA_1850_print_string((char*)&D_b21e[0x21]);

    do
    {
        iStack_4 = ULTIMA_266c_get_ch();
        if (iStack_4 == 0x4e)
        {
            ULTIMA_1850_print_string(/*0x84ba*/ "No\n\n");
        }
        else if (iStack_4 == 0x59)
        {
            ULTIMA_1850_print_string(/*0x84b4*/ "Yes\n\n");
        }
    } while (iStack_4 != 0x59 && iStack_4 != 0x4e);

    if (iStack_4 == 0x4e)
    {
        ULTIMA_1850_print_string((char*)&D_b21e[0x49]);

        do
        {
            iStack_4 = ULTIMA_266c_get_ch();
            if (iStack_4 == 0x4e)
            {
                ULTIMA_1850_print_string(/*0x84c6*/ "No\n\n");
            }
            else if (iStack_4 == 0x59)
            {
                ULTIMA_1850_print_string(/*0x84c0*/ "Yes\n\n");
            }
        } while (iStack_4 != 0x59 && iStack_4 != 0x4e);
    }

    if (iStack_4 == 0x59 && D_57bf != 0)
    {
        ULTIMA_3ae6(8);

        while (F_ENDGAME_0510(0, 5, 4) != 0)
            ;

        while (F_ENDGAME_0510(0, 5, 5) != 0)
            ;

        ULTIMA_3ae6(4);

        D_5c5a[6]._1 = 0xe;
        D_5c5a[6]._0_tile = 0xe;
        D_5c5a[6]._2_x = 5;
        D_5c5a[6]._3_y = 4;
        D_5c5a[6]._6 = 0;

        ULTIMA_1850_print_string((char*)&D_b21e[0xab]);
        ULTIMA_3ae6(0x28);
        ULTIMA_1850_print_string(/*0x84cc*/ "\n\nHe says:\n\n");
        ULTIMA_266c_get_ch();
        ULTIMA_1850_print_string((char*)&D_b21e[0xd3]);
        ULTIMA_266c_get_ch();
        ULTIMA_1850_print_string((char*)&D_b21e[0x128]);
        ULTIMA_266c_get_ch();
        ULTIMA_1850_print_string((char*)&D_b21e[0x167]);
        ULTIMA_266c_get_ch();
        ULTIMA_1850_print_string((char*)&D_b21e[0x1c9]);
        ULTIMA_266c_get_ch();
        ULTIMA_1850_print_string((char*)&D_b21e[0x211]);
        ULTIMA_266c_get_ch();
        ULTIMA_1850_print_string((char*)&D_b21e[0x24b]);

        D_5c5a[6]._0_tile = 8;
        D_5c5a[6]._1 = 8;

        ULTIMA_266c_get_ch();
        ULTIMA_2192_audio_some_noise(0x1450, 1, 50000, 10000, 1);

        D_5c5a[6]._0_tile = 0;
        D_5c5a[6]._1 = 0;
        D_ad14[0x85] = 0xdc;

        for (D_5887 = 1; D_5887 < 0x10; D_5887++)
        {
            ULTIMA_3ae6(1);
        }

        ULTIMA_3ae6(4);

        while (F_ENDGAME_0510(0x1f, 5, 4) != 0)
            ;

        D_5c5a[31]._1 = 0;
        D_5c5a[31]._0_tile = 0;
        ULTIMA_3ae6(1);

        for (iVar11 = 0; iVar11 < D_585b; iVar11++)
        {
            while (F_ENDGAME_0510(iVar11, 5, 4) != 0)
                ;

            D_5c5a[iVar11]._1 = 0;
            D_5c5a[iVar11]._0_tile = 0;
            ULTIMA_3ae6(1);
        }

        for (D_5887 = 0xf; D_5887 > 0; D_5887--)
        {
            ULTIMA_3ae6(1);
        }

        ULTIMA_10e0_GRAP_51_draw_tile(0x44, 5, 4);
        ULTIMA_0c22_GRAP_0f_select_page(1);
        ULTIMA_0a70_GRAP_2d_set_pen_color(0);
        ULTIMA_102e_unload_tileset();
        ULTIMA_0aa6_GRAP_3f_fill_rectangle(0, 0, 0x13f, 199);
        ULTIMA_0c22_GRAP_0f_select_page(0);
        F_ENDGAME_0000();
        F_ENDGAME_0326();
        return;
    }

    // bad endgame
    ULTIMA_1850_print_string(/*0x84da*/ "\"I see...\n");
    ULTIMA_3ae6(0x28);
    ULTIMA_1850_print_string((char*)&D_b21e[0x2d5]);
    D_5c5a[0]._3_y--;
    F_ENDGAME_04fe();

    do
    {
        iVar8 = F_ENDGAME_0510(2, 8, 6);
        iVar12 = F_ENDGAME_0510(0x1f, 4, 1);
        iVar7 = F_ENDGAME_0510(0, 8, 4);
    } while (iVar8 + iVar12 + iVar7 != 0);

    do
    {
        F_ENDGAME_05a2(1);
        F_ENDGAME_05a2(3);
        F_ENDGAME_05a2(4);
        F_ENDGAME_05a2(5);
    } while (1);
}
