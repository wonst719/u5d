#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <string.h>

// OK P1 (complete)
int OUTSUBS_0000(uint param_1)
{
    int local2_4;
    int local1_6 = 1;

    param_1 = (byte)(param_1 >> 8);

    for (local2_4 = 0; local2_4 < 8; local2_4++)
    {
        if (D_3866[local2_4] == param_1)
        {
            local1_6 = D_58d0[local2_4] == 0;
            break;
        }
    }

    return local1_6;
}

// OK P1 (complete)
int OUTSUBS_004a(int param_1)
{
    int local2_4;
    int local1_6 = 0;

    param_1 >>= 8;

    for (local2_4 = 0; local2_4 < 8; local2_4++)
    {
        // 0063
        if (D_386e[local2_4] == param_1)
        {
            local1_6 = 0x7f < D_58d8[local2_4];
            break;
        }
    }

    return local1_6;
}

// OK P1
void OUTSUBS_0098(char* param_1/*file_name*/, int param_2/*layer?*/, uint param_3)
{
    int local_c;
    int local_a;
    uint local_8;
    uint local_6;
    uint local_4;

    if (*param_1 == 'B') // "BRIT.DAT"
    {
        local_4 = D_3876[(byte)(param_3 >> 8)];
        if (local_4 == 0xff)
        {
            memset(&D_6608[param_2 * 0x100], 1, 0x100);
            return; // -> 01ac
        }

        // 00d4
        local_4 <<= 8;
    }
    else
    {
        // 00dc
        local_4 = param_3;
    }

    // 00e2
    if (D_5895_map_level != 0)
    {
        ULTIMA_251e_switch_disks(5);
    }

    // 00f0
    ULTIMA_256e_read_file_from_disk(param_1, D_6608 + param_2 * 0x100, 0x100, local_4);
    local_6 = param_3 >> 4 & 0xf0;
    local_8 = param_3 >> 8 & 0xf0;

    for (local_c = 0; local_c < 0x10; local_c++)
    {
        // 0125
        for (local_a = 0; local_a < 0x10; local_a++)
        {
            switch (D_6608[local_a + param_2 * 0x100 + local_c * 0x10])
            {
            case 0x16:
            case 0x17:
            case 0x18:
                // 012c
                if (OUTSUBS_0000(param_3) != 0)
                {
                    *ULTIMA_4402_get_address_of_tile_id(local_a + local_6, local_c + local_8) = 0xdf;
                }
                break;
            case 0x19:
                // 017d
                if (OUTSUBS_004a(param_3) != 0)
                {
                    *ULTIMA_4402_get_address_of_tile_id(local_a + local_6, local_c + local_8) = 0x1a;
                }
                break;
            }
        }
    }
}

// OK P1
void OUTSUBS_01b4(int param_1, int param_2)
{
    uint local_c;
    int local_a;
    byte* local_8;
    int local_6;
    char* local_4;

    local_a = D_589b * 0x10 + D_589c * 0x100;

    if (D_589b == 0xf0)
    {
        local_6 = -0xf00; // 0xf100?
    }
    else
    {
        // 01dc
        local_6 = 0x100;
    }

    // 01e1
    if (D_5895_map_level > 0x7f)
    {
        local_4 = "UNDER.DAT"; // 3976
    }
    else
    {
        local_4 = "BRIT.DAT"; // 3980
    }

    // 01f5
    if (param_1 == -1 || param_2 == -1)
    {
        OUTSUBS_0098(local_4, 0, local_a);
    }
    // 020d
    if (param_1 == 1 || param_2 == -1)
    {
        OUTSUBS_0098(local_4, 1, local_a + local_6);
    }
    // 022a
    if (param_1 == -1 || param_2 == 1)
    {
        OUTSUBS_0098(local_4, 2, local_a + 0x1000);
    }
    // 0247
    if (param_1 == 1 || param_2 == 1)
    {
        OUTSUBS_0098(local_4, 3, (local_a + local_6) + 0x1000);
    }

    // 0267
    local_8 = ULTIMA_0402_memchr(D_6608, 0x1b, 0x400);
    if (local_8 == 0)
    {
        D_217e = D_2180 = -1;
    }
    else
    {
        // 028c
        local_c = (int)(local_8 - D_6608);
        D_217e = local_c & 0xf;
        D_2180 = ((byte)local_c & 0xf0) >> 4;
        if ((local_c & 0x100) != 0)
        {
            D_217e += 0x10;
        }
        if ((local_c & 0x200) != 0)
        {
            D_2180 += 0x10;
        }
    }
}

// TODO: MATCH
// Load chunk?
void OUTSUBS_02c8(int param_2, int param_1)
{
    undefined2* puVar1;
    undefined2* puVar2;
    int iVar3;
    int iVar4;
    undefined2* puVar5;
    int iVar6;
    undefined2* puVar7;
    undefined2 unaff_DS;

    if ((param_2 < 0) || (param_1 < 0)) {
        iVar3 = 3;
    }
    else {
        iVar3 = 0;
    }
    if ((param_2 < 0) || (0 < param_1)) {
        iVar4 = 2;
    }
    else {
        iVar4 = 1;
    }
    puVar5 = (undefined2*)(iVar4 * 0x100 + D_6608); // src
    puVar7 = (undefined2*)(iVar3 * 0x100 + D_6608); // dst
    memcpy(puVar7, puVar5, 0x100);

    puVar5 = (undefined2*)((iVar4 + param_1 + param_2 * 2) * 0x100 + D_6608); // src
    puVar7 = (undefined2*)((iVar3 + param_1 + param_2 * 2) * 0x100 + D_6608); // dst
    memcpy(puVar7, puVar5, 0x100);
}

// OK P1
char* OUTSUBS_0368_GetWorldSavefile()
{
	if (D_5895_map_level == 0)
		return "BRIT.OOL";
	else
		return "UNDER.OOL";
}

// TODO: MATCH
// enter town
int OUTSUBS_0388(char* param_1)
{
    int iVar1;
    undefined2 uVar2;
    int iVar3;
    char cStack_6;
    undefined2 uStack_4;

    uStack_4 = 1;
    ULTIMA_1850_print_string(param_1);
    iVar3 = 0;
    do {
        if ((*(char*)(iVar3 + D_1e8a) == D_5896_map_x) &&
            (*(char*)(iVar3 + D_1eb2) == D_5897_map_y)) break;
        iVar3 = iVar3 + 1;
    } while (iVar3 < 0x20);
    if (iVar3 < 0x20) {
        if ((iVar3 < 0xd) || (0x11 < iVar3)) {
            ULTIMA_1850_print_string("\n\n");
            ULTIMA_16ba_print_char(0xfc);
            ULTIMA_1850_print_string(D_1e3a[iVar3]);
            ULTIMA_16ba_print_char(0xfb);
        }
        ULTIMA_16ba_print_char(10);
        if (D_a9bd != '\x01') {
            ULTIMA_251e_switch_disks(1);
            do {
                iVar1 = ULTIMA_1674_test_open_file("BRIT.DAT");
            } while (iVar1 == 0);
        }
        ULTIMA_25d8_write_file_to_disk(OUTSUBS_0368_GetWorldSavefile(), D_5c5a, 0x100);
        cStack_6 = (char)iVar3;
        D_5893_map_id = cStack_6 + '\x01';
        D_5895_map_level = 0;
        D_5896_map_x = 0xf;
        D_5897_map_y = 0x1e;
        uStack_4 = 0;
    }
    else {
        ULTIMA_1850_print_string("\nWhat town?\n");
    }
    return uStack_4;
}

void MAINOUT_0000(void);
void MAINOUT_0354(int param_1, int param_2);

// TODO: MATCH
// f-a-l-l-s
void OUTSUBS_0458(void)
{
    undefined1 uVar1;
    uint uVar2;
    int iVar3;
    uint uVar4;
    char* pcVar5;
    undefined2 unaff_DS;
    byte* pbStack_a;

    ULTIMA_1850_print_string("F-A-L-L-S!!!\n");
    MAINOUT_0354(0, 1);
    ULTIMA_3ae6(1);
    MAINOUT_0354(0, 1); // THUNK 7bc6
    ULTIMA_43ae(0x9c4, 800, 1, 300);
    uVar1 = D_587c;
    D_587c = 0;
    ULTIMA_3ae6(1);
    if (D_585b != '\0') {
        uVar4 = 0;
        pcVar5 = (char*)&D_55a8_party[uVar4]._b;
        pbStack_a = (byte*)&D_55a8_party[uVar4]._d;
        do {
            if ((*pcVar5 != 'D') && (uVar2 = ULTIMA_3abe(), *pbStack_a <= uVar2)) {
                ULTIMA_2a52(uVar4, 1);
            }
            uVar4 = uVar4 + 1;
        } while (uVar4 < D_585b);
    }
    ULTIMA_3ae6(2);
    D_587c = uVar1;
    if ((D_5896_map_x == 0x36) && (D_5897_map_y == 0x8a)) {
        ULTIMA_1850_print_string("Falling into underworld!!\n");
        D_5895_map_level = 0xff;
        ULTIMA_25d8_write_file_to_disk("BRIT.OOL", D_5c5a, 0x100);
        ULTIMA_256e_read_file_from_disk("UNDER.OOL", D_5c5a, 0x100, 0);
        ULTIMA_251e_switch_disks(5);
        do {
            iVar3 = ULTIMA_1674_test_open_file("UNDER.DAT");
        } while (iVar3 == 0);
        ULTIMA_25d8_write_file_to_disk("UNDER.OOL", D_5c5a, 0x100);
        MAINOUT_0000(); // THUNK 7b7e
    }
}

// OK P1
void OUTSUBS_0566(void)
{
    int local1_6;
    ActorFmt* local2_4;

    if (D_5895_map_level != 0)
    {
        if (D_57b3 == 0)
        {
            // D_5c5a[28] == 5d3a
            local2_4 = &D_5c5a[28];
            local2_4->_0_tile = local2_4->_1 = 0xb7;
            local2_4->_2_x = 0x69;
            local2_4->_3_y = 0xe1;
            local2_4->_4_z = 0xff;
            local2_4->_5 = 0xf3;
        }

        // 059d
        for (local1_6 = 0; local1_6 < 3; local1_6++)
        {
            if (D_57b6[local1_6] == 0 && D_58c8[local1_6] < 0x80)
            {
                // D_5c5a[29] == 5d42
                local2_4 = &D_5c5a[local1_6 + 29];
                local2_4->_0_tile = local2_4->_1 = 0xb4;
                local2_4->_2_x = D_3a06[local1_6];
                local2_4->_3_y = D_3a0a[local1_6];
                local2_4->_4_z = 0xff;
                local2_4->_5 = D_3a0e[local1_6];
            }
        }
    }
}

// OK P1
// step_on_burning_tile
void OUTSUBS_05ee(void)
{
    ULTIMA_5910_update_map();
    ULTIMA_1850_print_string("Burning!\n");
    ULTIMA_2aa8();
}

// TODO: MATCH
// step_on_poison_tile
void OUTSUBS_05fc(void)
{
    uint uVar1;
    char* pcVar2;
    byte* pbVar3;
    undefined2 unaff_DS;
    uint uStack_4;

    uStack_4 = 0;
    if (D_585b != 0)
    {
        do
        {
            pcVar2 = (char*)&D_55a8_party[uStack_4]._b;
            pbVar3 = (byte*)&D_55a8_party[uStack_4]._d;
            if ((*pcVar2 != 'D') && (*pcVar2 != 'P'))
            {
                uVar1 = ULTIMA_2092_random_range(1, 0x1e);
                if (*pbVar3 < uVar1)
                {
                    *pcVar2 = 'P';
                    ULTIMA_1850_print_string("Poisoned!\n");
                }
            }
            uStack_4 = uStack_4 + 1;
        } while (uStack_4 < D_585b);
    }
    return;
}

void OUTSUBS_0658(void)
{
    char cVar1;
    undefined1 uVar2;
    byte bVar3;
    int iVar4;
    undefined2* puVar5;
    undefined2 uVar8;
    undefined2 uVar9;
    uint uStack_e;
    uint uStack_8;
    ActorFmt* puStack_4;

    int i;

    ULTIMA_1850_print_string("An apparition!\n");
    ULTIMA_2192_audio_some_noise(0x0a3c, 1, 10000, 0x9c4, 6);
    puVar5 = (undefined2*)0x3a26; // TODO
    for (i = 0; i < 0xc; i++)
    {
        ULTIMA_2192_audio_some_noise(D_3a26[i], 1, 5000, 200, 0xd);
    }
    puStack_4 = &D_5c5a[10];
    D_5c5a[10]._3_y = 5;
    D_5c5a[10]._2_x = 5;
    D_5c5a[10]._1 = 0x16;
    D_5c5a[10]._0_tile = 0x16;
    ULTIMA_1068(0x174, 5, 5);
    D_5c5a[10]._1 = 0x74;
    D_5c5a[10]._0_tile = 0x74;
    uStack_8 = 0;
    do {
        if (D_585b <= uStack_8) {
            ULTIMA_1850_print_string("\n\"");
            if (D_5888 / 0x14 < 4)
            {
                ULTIMA_256e_read_file_from_disk("KARMA.DAT", D_b21e, 2000, D_1a74[D_5888 / 0x14]);
            }
            else
            {
                ULTIMA_256e_read_file_from_disk("KARMA.DAT", D_b21e, 2000, 0x29f);
            }
            ULTIMA_1850_print_string(D_b21e);
            ULTIMA_16ba_print_char(0x22);
            ULTIMA_266c_get_ch();
            ULTIMA_1850_print_string("\n\nThe strangely familiar old man vanishes...\n");
            D_5c5a[10]._1 = 0x16;
            D_5c5a[10]._0_tile = 0x16;
            ULTIMA_1068(D_ad14[0xa5], 5, 5);
            D_5c5a[10]._1 = 0;
            D_5c5a[10]._0_tile = 0;
            ULTIMA_3ae6(1);
            ULTIMA_4f7c(0);
            return;
        }
        if (D_55a8_party[uStack_8]._b != 'D') {
            D_55a8_party[uStack_8]._10 = D_55a8_party[uStack_8]._12;
            D_55a8_party[uStack_8]._b = 0x47;
            for (i = 0; i < 32; i++)
            {
                if (D_ba14[i]._3 == uStack_8)
                {
                    puStack_4 = &D_5c5a[D_ba14[i]._4];
                    break;
                }
            }

            iVar4 = ULTIMA_4d76("AMBFDTPRS", D_55a8_party[uStack_8]._a);
            uVar2 = D_1ade[iVar4];
            puStack_4->_1 = uVar2;
            puStack_4->_0_tile = uVar2;
            D_5c5a[10]._6 = 0;
            ULTIMA_3ae6(1);
            ULTIMA_2192_audio_some_noise(0x157c, 1, 5000, 200, 0xd); // TODO
            ULTIMA_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
            ULTIMA_0b86(8, 8, 0xb7, 0xb7);
            ULTIMA_2192_audio_some_noise(0x157c, 1, 60000, 0x9c4, 1); // TODO
            iVar4 = 3;
            do {
                D_5c5a[10]._6 = 1;
                ULTIMA_3ae6(1);
                iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
            uStack_e = 1;
            for (iVar4 = D_55a8_party[uStack_8]._14 / 100; 0 < iVar4; iVar4 = iVar4 >> 1) {
                uStack_e = uStack_e + 1;
            }
            if (D_55a8_party[uStack_8]._16 != uStack_e) {
                D_55a8_party[uStack_8]._16 = (undefined1)uStack_e;
                D_55a8_party[uStack_8]._12 = uStack_e * 0x1e;
                D_55a8_party[uStack_8]._10 = uStack_e * 0x1e;
                ULTIMA_1850_print_string("\n\"Hail, ");
                ULTIMA_1850_print_string(D_55a8_party[uStack_8]._0);
                ULTIMA_1850_print_string("!\nFor thy valiant deeds, I shall reward thee!\n");
                ULTIMA_1850_print_string("Thou art now level ");
                ULTIMA_1a3e_print_number(uStack_e, 1, 0x20);
                ULTIMA_1850_print_string(", and\n");
                iVar4 = ULTIMA_2092_random_range(1, 3);
                if (iVar4 == 1) {
                    ULTIMA_1850_print_string("stronger!");
                    ULTIMA_3ef0(&D_55a8_party[uStack_8]._c, 1, 0x1e);
                }
                else {
                    if (iVar4 == 2) {
                        ULTIMA_1850_print_string("quicker!");
                        ULTIMA_3ef0(&D_55a8_party[uStack_8]._d, 1, 0x1e);
                    }
                    if (iVar4 == 3) {
                        ULTIMA_1850_print_string("wiser!");
                        ULTIMA_3ef0(&D_55a8_party[uStack_8]._e, 1, 0x1e);
                    }
                }
                ULTIMA_1850_print_string("\" ");
                ULTIMA_266c_get_ch();
                ULTIMA_16ba_print_char(10);
            }
        }
        cVar1 = D_55a8_party[uStack_8]._a;
        if (cVar1 == 'A') {
        LAB_0000_07e6:
            bVar3 = D_55a8_party[uStack_8]._e;
        LAB_0000_07f1:
            D_55a8_party[uStack_8]._f = bVar3;
        }
        else {
            if (cVar1 == 'B') {
                bVar3 = D_55a8_party[uStack_8]._e >> 1;
                goto LAB_0000_07f1;
            }
            if (cVar1 == 'M') goto LAB_0000_07e6;
        }
        ULTIMA_2900_update_vitals();
        uStack_8 = uStack_8 + 1;
    } while (1);
}
