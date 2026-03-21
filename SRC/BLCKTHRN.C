#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <memory.h>

void TOWN_11f0_Entry(int param_1);

int CAST2_05e0(int a, int b);
void CAST2_08ea(int a);

void BLCKTHRN_060e_capture(void) { debug("BLCKTHRN_060e_capture"); }

// NOT MATCHING
void BLCKTHRN_0000(int param_1)
{
    for (; param_1 >= 0; param_1--)
    {
        ULTIMA_433e_audio_some_noise();
        ULTIMA_3ae6(2);
    }
}

// NOT MATCHING
int BLCKTHRN_002e(int param_1)
{
    int local_4;

    SET_UNINITIALIZED_16(local_4);

    switch (param_1 & 0xfc)
    {
    case 0x10:
        local_4 = 6;
        break;
    case 0x14:
        local_4 = 7;
        break;
    case 0x18:
        local_4 = 8;
        break;
    case 0x1c:
        local_4 = 0;
        break;
    case 0x20:
        local_4 = 1;
        break;
    }

    D_5878 = 0;
    D_5876 = 0;

    switch (param_1 & 3)
    {
    case 0:
        D_5878--;
        break;
    case 1:
        D_5876++;
        break;
    case 2:
        D_5878++;
        break;
    case 3:
        D_5876--;
        break;
    }

    CHECK_UNINITIALIZED_16(local_4);

    return local_4;
}

// NOT MATCHING
void BLCKTHRN_00be(byte* param_1)
{
    byte* pbVar1;
    int uVar2;
    int uVar3;
    byte bVar4;
    bool bVar5;
    bool bVar6;
    int iVar7;
    int local_18;
    int local_14;
    int local_10;
    int local_6;

    bVar5 = 1;
    while (1)
    {
        local_6 = 1;
        bVar6 = 0;
        pbVar1 = param_1;

        while (1)
        {
            param_1 = pbVar1;
            pbVar1 = param_1 + 1;
            bVar4 = *param_1;
            if (bVar4 == 0)
            {
                return;
            }

            if (bVar4 > 0xf)
                break;

            switch (bVar4)
            {
            case 1:
                bVar6 = 1;
                break;
            case 2:
                local_6 = (uint)*pbVar1;
                pbVar1 = param_1 + 2;
                break;
            case 3:
                bVar5 = 1;
                break;
            case 4:
                bVar5 = 0;
                break;
            case 5:
                ULTIMA_3ae6(*pbVar1);
                pbVar1 = param_1 + 2;
                break;
            case 6:
                D_ad14[param_1[2] + param_1[3] * 0x20] = *pbVar1;
                pbVar1 = param_1 + 4;
                break;
            case 7:
                ULTIMA_5910_update_map();
                break;
            case 8:
                BLCKTHRN_0000(local_6);
                local_6 = 1;
                break;
            case 9:
                bVar4 = *pbVar1;
                D_5c5a[bVar4]._1 = 0;
                D_5c5a[bVar4]._0_tile = 0;
                pbVar1 = param_1 + 2;
            }
        }

        iVar7 = BLCKTHRN_002e(bVar4);
        uVar2 = D_5876;
        uVar3 = D_5878;
        if (bVar6)
        {
            local_10 = BLCKTHRN_002e(*pbVar1);
            local_14 = D_5876;
            local_18 = D_5878;
            pbVar1 = param_1 + 2;
        }

        param_1 = pbVar1;

        for (; local_6 >= 0; local_6--)
        {
            D_5c5a[iVar7]._2_x += uVar2;
            D_5c5a[iVar7]._3_y += uVar3;
            if (bVar6)
            {
                D_5c5a[local_10]._2_x += local_14;
                D_5c5a[local_10]._3_y += local_18;
            }
            if (bVar5)
            {
                BLCKTHRN_0000(1);
            }
        }
    }
}

// NOT MATCHING
void BLCKTHRN_0278(int param_1, int param_2)
{
    switch (param_1)
    {
    case 0:
        ULTIMA_1850_print_string((char*)&D_b21e[0x0]);
        ULTIMA_1850_print_string(D_1f4e[param_2]);
        ULTIMA_1850_print_string(/*0x6f6e*/ "?\"");
        break;
    case 1:
        ULTIMA_1850_print_string((char*)&D_b21e[0x2d]);
        ULTIMA_1850_print_string(D_1f4e[param_2]);
        ULTIMA_1850_print_string(/*0x6f72*/ "?\"");
        break;
    case 2:
        ULTIMA_1850_print_string((char*)&D_b21e[0x52]);
        ULTIMA_1850_print_string(D_1f4e[param_2]);
        ULTIMA_1850_print_string(/*0x6f76*/ "?\"");
        break;
    case 3:
        ULTIMA_1850_print_string((char*)&D_b21e[0xac]);
        break;
    }
}

// NOT MATCHING
int BLCKTHRN_02ea(int param_1)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int local_18;
    int local_16;
    char local_14[18];

    ULTIMA_1850_print_string(/*0x6f7a*/ "\n\nYour response?\n:");
    ULTIMA_3b1c_get_string(local_14, 0xe);
    ULTIMA_1850_print_string(/*0x6f8e*/ "\n\n");
    iVar1 = ULTIMA_216c_strlen(D_1f5e[param_1]);
    local_16 = 0;

    for (local_18 = 0; local_18 <= ULTIMA_216c_strlen(local_14) - iVar1; local_18++)
    {
        local_16 = 1;

        for (iVar2 = 0; iVar2 < iVar1; iVar2++)
        {
            iVar3 = ULTIMA_2032_to_upper((D_1f5e)[param_1][iVar2]);
            iVar4 = ULTIMA_2032_to_upper(local_14[local_18 + iVar2]);
            if (iVar4 != iVar3)
            {
                local_16 = 0;
                break;
            }
        }

        if (local_16 != 0)
        {
            return local_16;
        }
    }

    return local_16;
}

// NOT MATCHING
void BLCKTHRN_03ae(int param_1)
{
    int iVar6;
    uint local_28;
    S_55a8 local_22;

    if (param_1 == 0)
    {
        ULTIMA_1850_print_string((char*)&D_b21e[0x12d]);
    }
    else
    {
        ULTIMA_1850_print_string((char*)&D_b21e[0xf1]);
    }

    ULTIMA_3ae6(10);

    for (iVar6 = 2000; iVar6 < 25000; iVar6 += 0x32)
    {
        ULTIMA_2192_audio_some_noise(0xa50, 1, 200, iVar6, 0);
    }

    for (iVar6 = 25000; 2000 < iVar6; iVar6 -= 0x32)
    {
        ULTIMA_2192_audio_some_noise(0xa50, 1, 200, iVar6, 0);
    }

    ULTIMA_3522(D_5c5a[1]._2_x, D_5c5a[1]._3_y);
    D_5c5a[1]._1 = 0;
    D_5c5a[1]._0_tile = 0;
    D_ad14[0xe5] = 0x80;

    for (local_28 = 0; local_28 < D_585b; local_28++)
    {
        if (D_55a8_party[local_28]._b != 'D')
        {
            iVar6 = iVar6 + 1;
        }
        if (iVar6 == 2)
            break;
    }

    local_22 = D_55a8_party[local_28];

    for (; local_28 < 0xf; local_28++)
    {
        D_55a8_party[local_28 + 1] = D_55a8_party[local_28];
    }

    D_55a8_party[0xf] = local_22;
    D_55a8_party[0xf]._1f = 0x7f;

    D_585b--;
    ULTIMA_2900_update_vitals();
    if (param_1 != 0)
    {
        ULTIMA_1850_print_string(/*0x6f92*/ "\n\n");
        ULTIMA_1850_print_string(D_55a8_party[0xf]._0);
        ULTIMA_1850_print_string(/*0x6f96*/ " is sliced in half! ");
        ULTIMA_266c_get_ch();
        ULTIMA_1850_print_string((char*)&D_b21e[0x1a0]);
    }

    ULTIMA_16ba_print_char(10);
}

// NOT MATCHING
void BLCKTHRN_0510(void)
{
    ULTIMA_266c_get_ch();
    BLCKTHRN_00be(D_369e);
}

// NOT MATCHING
void BLCKTHRN_051c(void)

{
    ULTIMA_1850_print_string((char*)&D_b21e[0x229]);
    BLCKTHRN_00be(D_36da);
    ULTIMA_1850_print_string((char*)&D_b21e[0x25f]);
    ULTIMA_1850_print_string(D_55a8_party[1]._0);
    ULTIMA_1850_print_string(/*0x6fac*/ " die!\" ");
    ULTIMA_266c_get_ch();
    ULTIMA_1850_print_string(/*0x6fb4*/ "\n\n");
}

// NOT MATCHING
void BLCKTHRN_054a(int param_1, int param_2)
{
    bool bVar1;
    int iVar4;

    bVar1 = 0;
    ULTIMA_1850_print_string(/*0x6fb8*/ "\n\n");

    for (iVar4 = 0; iVar4 < 4; iVar4++)
    {
        BLCKTHRN_0278(iVar4, param_1);
        if (BLCKTHRN_02ea(param_1) != 0)
        {
            *(D_58d8 + param_1) = 0xff;
            ULTIMA_3f36(&D_5888, 5);
            if (param_2 > 1)
            {
                BLCKTHRN_03ae(0);
                BLCKTHRN_0510();
                return;
            }

            ULTIMA_1850_print_string((char*)&D_b21e[0x29c]);
            BLCKTHRN_0510();
            return;
        }

        if (param_2 < 2)
        {
            ULTIMA_1850_print_string((char*)&D_b21e[0x2dc]);
            BLCKTHRN_0510();
            return;
        }

        if (bVar1)
        {
            ULTIMA_4f7c(2);
            ULTIMA_2900_update_vitals();

            switch (iVar4)
            {
            case 0:
                D_ad14[0x125] = 0xea;
                break;
            case 1:
                D_ad14[0x125] = 0xeb;
                break;
            case 2:
                D_ad14[0x125] = 0xe8;
                break;
            case 3:
                BLCKTHRN_03ae(1);
                break;
            }
        }
        else
        {
            bVar1 = 1;
            BLCKTHRN_051c();
        }
    }
}

void BLCKTHRN_060e(void)
{
    undefined1 uVar3;
    int iVar4;
    uint uVar6;
    int iVar7;
    int iVar9;
    int iVar10;
    undefined* local_14;
    undefined1* local_12;
    int local_a;

    local_a = 0;
    for (uVar6 = 0; uVar6 < D_585b; uVar6++)
    {
        if (D_55a8_party[uVar6]._b != 'D')
        {
            local_a = local_a + 1;
        }
    }

    D_587c = 0x1c;
    ULTIMA_5910_update_map();
    ULTIMA_1850_print_string(/*0x6fbc*/ "\nThou art subdued and blindfolded!");

    for (iVar9 = 0; iVar9 < 8; iVar9++)
    {
        if (D_58d8[iVar9] == 0)
            break;
    }

    if (iVar9 <= 7)
    {
        ULTIMA_3ae6(2);
        ULTIMA_0a70_GRAP_2d_set_pen_color(0);
        ULTIMA_0aa6_GRAP_3f_fill_rectangle(8, 8, 0xb7, 0xb7);
        D_5895_map_level = 0xff;
        ULTIMA_4a84();
        ULTIMA_2e96_set_wind_direction(-1);

        for (iVar10 = 0; iVar10 < 5; iVar10++)
        {
            ULTIMA_20fa_wait_ticks(5);
            ULTIMA_433e_audio_some_noise();
        }

        ULTIMA_1850_print_string(/*0x6fe0*/ "\n\nStrong guards drag thee away!");

        iVar10 = 0;
        while (1)
        {
            if (D_a9ce == 0)
            {
                iVar4 = 3;
            }
            else
            {
                iVar4 = 0x12;
            }

            if (iVar4 <= iVar10)
                break;

            ULTIMA_20fa_wait_ticks(5);
            ULTIMA_433e_audio_some_noise();
            iVar10 = iVar10 + 1;
        }

        for (iVar10 = 0; iVar10 < 0x20; iVar10++)
        {
            ULTIMA_3a74(0, 0, 0, 0, 0, 0, iVar10);
        }

        D_5893_map_id = 0xff;
        D_589e = 0xff;

        ULTIMA_256e_read_file_from_disk(/*0x7000*/ "MISCMAPS.DAT", D_ac64, 0xb0, 0);
        ULTIMA_256e_read_file_from_disk(/*0x700e*/ "MISCMSG.DAT", D_b21e, 1000, 0);

        for (iVar4 = 0; iVar4 < 0xb; iVar4 = iVar4 + 1)
        {
            for (iVar7 = 0; iVar7 < 0xb; iVar7 = iVar7 + 1)
            {
                D_ad14[iVar4 * 0x20 + iVar7] = D_ac64[iVar4 * 0x10 + iVar7];
            }
        }

        if (local_a > 0)
        {
            for (iVar10 = 0; iVar10 < local_a; iVar10++)
            {
                uVar6 = D_1f12[(local_a - 1) * 8 + iVar10];
                D_5c5a[iVar10]._2_x = D_1f42[uVar6];
                D_5c5a[iVar10]._3_y = D_1f48[uVar6];
                iVar4 = ULTIMA_4d76(/*0x701a*/ "AMBFDTPRS", D_55a8_party[iVar10]._a);
                uVar3 = D_1ade[iVar4];
                D_5c5a[iVar10]._1 = uVar3;
                D_5c5a[iVar10]._0_tile = uVar3;
            }
        }

        ULTIMA_3ae6(0x10);
        ULTIMA_1850_print_string(/*0x7024*/ "\n\nThou hast been chained and manacled!");
        ULTIMA_3ae6(0x32);
        ULTIMA_1850_print_string(/*0x704c*/ "\n\nFootsteps!");
        BLCKTHRN_0000(8);
        ULTIMA_3a74(0x70, 0x70, 4, 10, 0, 0, 6);
        ULTIMA_3a74(0x70, 0x70, 6, 10, 0, 0, 7);
        BLCKTHRN_00be(D_3702);
        ULTIMA_2192_audio_some_noise(0xaf0, 1, 13000, 100, 5);
        ULTIMA_3a74(0x16, 0x16, 5, 5, 0, 0, 8);
        ULTIMA_1068(0x178, 5, 5);
        ULTIMA_3a74(0x78, 0x78, 5, 5, 0, 0, 8);
        ULTIMA_3ae6(8);
        ULTIMA_1850_print_string(/*0x705a*/ "\n\nBlackthorn says:\n\n\"Ah, ");
        ULTIMA_1850_print_string(D_55a8_party[0]._0);
        ULTIMA_1850_print_string(/*0x7074*/ "!\n'Tis indeed an honour to meet thee at last! ");
        ULTIMA_266c_get_ch();
        ULTIMA_1850_print_string(/*0x70a4*/ "\n\nGUARD! Release this good");
        if (D_55a8_party[0]._9 == 12)
        {
            ULTIMA_1850_print_string(/*0x70c0*/ " lady ");
        }
        else if (D_55a8_party[0]._9 == 11)
        {
            ULTIMA_1850_print_string(/*0x70c8*/ "man ");
        }
        ULTIMA_1850_print_string(/*0x70ce*/ "at once!\"");
        BLCKTHRN_00be(D_370e);
        ULTIMA_1850_print_string((char*)&D_b21e[0x32c]);
        ULTIMA_266c_get_ch();
        BLCKTHRN_054a(iVar9, local_a);
        if (D_5c5a[8]._0_tile != 0)
        {
            BLCKTHRN_00be(D_3716);
        }
    }

    D_5895_map_level = 0xff;
    ULTIMA_4a84();
    ULTIMA_2e96_set_wind_direction(-1);
    D_5896_map_x = 10;
    D_5897_map_y = 7;
    D_57ac = 0;
    D_5893_map_id = 0x12;
}

// TODO: MATCH
void BLCKTHRN_0910_death(void)
{
    int local_c;
    int local_6;
    uint local_8;

    ULTIMA_251e_switch_disks(1);

    while (ULTIMA_1674_test_open_file("BRIT.DAT") == 0) {}

    CAST2_08ea(D_58a6);
    D_587c = 0x1e;

    if (D_5893_map_id < 0x21)
    {
        ULTIMA_5910_update_map();
    }

    ULTIMA_20fa_wait_ticks(10);
    local_c = D_5893_map_id;
    D_5893_map_id = 0xff;
    D_589e = 0xff;
    ULTIMA_1850_print_string("\nAn unending darkness engulfs thee...");
    ULTIMA_0c22_GRAP_0f_select_page(1);
    ULTIMA_0a70_GRAP_2d_set_pen_color(0);
    ULTIMA_0aa6_GRAP_3f_fill_rectangle(8, 8, 0xb7, 0xb7);
    ULTIMA_0c22_GRAP_0f_select_page(0);
    ULTIMA_0f46_GRAP_66(8, 8, 0xb7, 0xb7);

    for (local_8 = 0; local_8 < 0xb; local_8++)
    {
        memset(&D_ad14[local_8 * 0x20], 0xff, 0xb);
    }

    for (local_8 = 0; local_8 < 0x20; local_8++)
    {
        ULTIMA_3a74(0, 0, 0, 0, 0, 0, local_8);
    }

    ULTIMA_5910_update_map();

    ULTIMA_1850_print_string("\n\nThou hast found refuge.");
    ULTIMA_20fa_wait_ticks(0xe);
    ULTIMA_1850_print_string("\n\nNo evil lives here, only peace and darkness.");
    ULTIMA_20fa_wait_ticks(0x1c);
    ULTIMA_1850_print_string("\n\nBut thy slumber is disturbed!");

    D_ad14[0xa5] = 0; // 0xadb9
    D_5c5a[0]._1 = 0x1c;
    D_5c5a[0]._0_tile = 0x1c;
    D_5c5a[0]._3_y = 5;
    D_5c5a[0]._2_x = 5;
    ULTIMA_5910_update_map();

    // TODO: match variable
    for (local_8 = 0; local_8 < 6; local_8++)
    {
        ULTIMA_2192_audio_some_noise(D_3720[local_8], 1, D_372c[local_8], D_3738[local_8], D_3744[local_8]);
    }

    ULTIMA_1850_print_string("\n\nSomeone shouts\n\n\"FORTIS FORTUNA\nAVENTARI\"");
    ULTIMA_20fa_wait_ticks(6);
    D_5c5a[1]._1 = 0x16;
    D_5c5a[1]._0_tile = 0x16;
    D_5c5a[1]._2_x = 2;
    D_5c5a[1]._3_y = 7;
    D_ad14[0xe2] = 0;
    ULTIMA_1068(0x5e, 2, 7);
    D_ad14[0xe2] = 0x5e;
    D_5c5a[1]._0_tile = 0;
    ULTIMA_5910_update_map();

    ULTIMA_20fa_wait_ticks(4);
    D_5c5a[1]._0_tile = 0x16;
    D_5c5a[1]._2_x = 8;
    D_ad14[0xe8] = 0;
    ULTIMA_1068(0x5f, 8, 7);
    D_ad14[0xe8] = 0x5f;
    D_5c5a[1]._0_tile = 0;
    ULTIMA_5910_update_map();

    ULTIMA_20fa_wait_ticks(4);
    ULTIMA_1850_print_string("\n\nThere is a peal of thunder!\n");
    ULTIMA_3072();
    ULTIMA_3072();
    D_ad14[0x45] = 0;
    D_5c5a[1]._1 = 0x16;
    D_5c5a[1]._0_tile = 0x16;
    D_5c5a[1]._2_x = 5;
    D_5c5a[1]._3_y = 2;
    ULTIMA_1068(0x174, 5, 2);
    D_5c5a[1]._1 = 0x74;
    D_5c5a[1]._0_tile = 0x74;
    ULTIMA_5910_update_map();

    ULTIMA_1850_print_string("\n\"");
    ULTIMA_256e_read_file_from_disk("KARMA.DAT", D_b21e, 2000, D_1a74[D_5888 / 0x14]);
    ULTIMA_1850_print_string((char*)D_b21e);
    ULTIMA_16ba_print_char(0x22);
    ULTIMA_266c_get_ch();
    ULTIMA_1850_print_string("\n\nStrange words are intoned.");
    ULTIMA_20fa_wait_ticks(4);

    if (D_585b != 0)
    {
        for (local_8 = 0; local_8 < D_585b; local_8++)
        {
            // 32bit div?
            // TODO: MATCH
            //uVar5 = ULTIMA_03a0(0, uVar6 + 7, 0, 0x8e30);
            ULTIMA_2192_audio_some_noise(0x8e30 / (local_8 + 7), 1, 30000, 2000, 2);
            CAST2_05e0(local_8, 0xff);
            D_55a8_party[local_8]._10 = D_55a8_party[local_8]._12;
            ULTIMA_2900_update_vitals();
        }
    }

    ULTIMA_1850_print_string("\n\nVertigo...\n");
    ULTIMA_20fa_wait_ticks(4);
    ULTIMA_0c22_GRAP_0f_select_page(1);
    ULTIMA_0a70_GRAP_2d_set_pen_color(0);
    ULTIMA_0aa6_GRAP_3f_fill_rectangle(8, 8, 0xb7, 0xb7);
    ULTIMA_10e0_GRAP_51_draw_tile(0x11c, 5, 5);
    ULTIMA_0c22_GRAP_0f_select_page(0);
    ULTIMA_0f46_GRAP_66(8, 8, 0xb7, 0xb7);
    if (D_5888 < 0x4b)
    {
        D_5888 = 0x4b;
    }
    D_5893_map_id = 0x11;
    D_5895_map_level = 1;
    D_587c = 0x1c;
    D_5897_map_y = 10;
    D_5896_map_x = 10;
    D_588e = 0;
    D_587a = 0;
    while (D_587f != 0x6)
    {
        ULTIMA_4f7c(9);
    }
    D_58a6 = 0;
    D_58a7 = 0;
    if (D_57a8 == 0)
    {
        D_57a8 = 0x3f;
    }
    if (local_c != 0 && local_c < 0x21)
    {
        TOWN_11f0_Entry(1);
    }
}
