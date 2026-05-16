#include "common/common.h"
#include "vars.h"
#include "funcs.h"

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
        ULTIMA_251e_SwitchDisks(5);
    }

    // 00f0
    ULTIMA_256e_ReadFileFromDisk(param_1, D_6608 + param_2 * 0x100, 0x100, local_4);
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
                    *ULTIMA_4402_GetTileAddr(local_a + local_6, local_c + local_8) = 0xdf;
                }
                break;
            case 0x19:
                // 017d
                if (OUTSUBS_004a(param_3) != 0)
                {
                    *ULTIMA_4402_GetTileAddr(local_a + local_6, local_c + local_8) = 0x1a;
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
    local_8 = memchr(D_6608, 0x1b, 0x400);
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

// OK P1
// Load chunk?
void OUTSUBS_02c8(int param_1, int param_2)
{
    int local_4;
    int local_8;

    int local_6;
    int local_a;

    local_4 = param_1 < 0 || param_2 < 0 ? 3 : 0;
    local_8 = param_1 < 0 || param_2 > 0 ? 2 : 1;

    local_6 = local_4 + param_2 + param_1 * 2;
    local_a = local_8 + param_2 + param_1 * 2;

    memcpy(local_4 * 0x100 + D_6608, local_8 * 0x100 + D_6608, 0x100);
    memcpy(local_6 * 0x100 + D_6608, local_a * 0x100 + D_6608, 0x100);
}

// OK P1
char* OUTSUBS_0368_GetWorldSavefile(void)
{
	if (D_5895_map_level == 0)
		return "BRIT.OOL";
	else
		return "UNDER.OOL";
}

// OK P1
// enter town
int OUTSUBS_0388_EnterTown(char* param_1)
{
    int local_6;
    int local_4;

    local_4 = 1;
    ULTIMA_1850_PrintString(param_1);

    for (local_6 = 0; local_6 < 0x20; local_6++)
    {
        if (D_1e8a[local_6] == D_5896_map_x && (D_1eb2[local_6] == D_5897_map_y))
            break;
    }

    if (local_6 < 0x20)
    {
        if (local_6 < 0xd || local_6 > 0x11)
        {
            ULTIMA_1850_PrintString("\n\n");
            ULTIMA_16ba_PrintChar(0xfc);
            ULTIMA_1850_PrintString(D_1e3a[local_6]);
            ULTIMA_16ba_PrintChar(0xfb);
        }

        ULTIMA_16ba_PrintChar(10);
        if (D_a9bd[0] != 1)
        {
            ULTIMA_251e_SwitchDisks(1);

            while (ULTIMA_1674_TestOpenFile("BRIT.DAT") == 0)
                ;
        }

        ULTIMA_25d8_WriteFileToDisk(OUTSUBS_0368_GetWorldSavefile(), D_5c5a, 0x100);
        D_5893_map_id = local_6 + 1;
        D_5895_map_level = 0;
        D_5896_map_x = 0xf;
        D_5897_map_y = 0x1e;
        local_4 = 0;
    }
    else
    {
        ULTIMA_1850_PrintString("\nWhat town?\n");
    }

    return local_4;
}

void MAINOUT_0000(void);
void MAINOUT_0354(int param_1, int param_2);

// OK P1
// f-a-l-l-s
void OUTSUBS_0458(void)
{
    int local_6;
    int local_4;

    ULTIMA_1850_PrintString("F-A-L-L-S!!!\n");
    MAINOUT_0354(0, 1);
    ULTIMA_3ae6(1);
    MAINOUT_0354(0, 1);
    ULTIMA_43ae_AudioSweepTone(0x9c4, 800, 1, 300);

    local_6 = D_587c;
    D_587c = 0;

    ULTIMA_3ae6(1);

    for (local_4 = 0; local_4 < D_585b; local_4++)
    {
        if (D_55a8_party[local_4]._b != 'D' && D_55a8_party[local_4]._d <= ULTIMA_3abe())
        {
            ULTIMA_2a52(local_4, 1);
        }
    }

    ULTIMA_3ae6(2);
    D_587c = local_6;

    if (D_5896_map_x == 0x36 && D_5897_map_y == 0x8a)
    {
        ULTIMA_1850_PrintString("Falling into underworld!!\n");

        D_5895_map_level = 0xff;

        ULTIMA_25d8_WriteFileToDisk("BRIT.OOL", D_5c5a, 0x100);
        ULTIMA_256e_ReadFileFromDisk("UNDER.OOL", D_5c5a, 0x100, 0);
        ULTIMA_251e_SwitchDisks(5);

        while (ULTIMA_1674_TestOpenFile("UNDER.DAT") == 0)
            ;

        ULTIMA_25d8_WriteFileToDisk("UNDER.OOL", D_5c5a, 0x100);
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
    ULTIMA_5910_UpdateFrame();
    ULTIMA_1850_PrintString("Burning!\n");
    ULTIMA_2aa8();
}

// OK P1
// step_on_poison_tile
void OUTSUBS_05fc(void)
{
    int local_4;

    for (local_4 = 0; local_4 < D_585b; local_4++)
    {
        if (D_55a8_party[local_4]._b != 'D' && D_55a8_party[local_4]._b != 'P')
        {
            if (D_55a8_party[local_4]._d < ULTIMA_2092_RandomRange(1, 0x1e))
            {
                D_55a8_party[local_4]._b = 'P';
                ULTIMA_1850_PrintString("Poisoned!\n");
            }
        }
    }
}

// CHECKED
void OUTSUBS_0658(void)
{
    int local_a;
    int local_c;
    int local_e;
    int local_8;
    int local_6;
    ActorFmt* local_4;

    ULTIMA_1850_PrintString(/*0x7750*/ "An apparition!\n");
    ULTIMA_2192_AudioPulse(0x0a3c, 1, 10000, 0x9c4, 6);

    for (local_8 = 0; local_8 < 6; local_8++) // NOT MATCHING (di)
    {
        ULTIMA_2192_AudioPulse(D_3a26[local_8], 1, 5000, 200, 0xd);
    }

    local_4 = &D_5c5a[10];
    
    D_5c5a[10]._2_x = D_5c5a[10]._3_y = 5;
    D_5c5a[10]._0_tile = D_5c5a[10]._1 = 0x16;

    ULTIMA_1068(0x174, 5, 5);

    D_5c5a[10]._0_tile = D_5c5a[10]._1 = 0x74;

    for (local_8 = 0; local_8 < D_585b; local_8++) // NOT MATCHING (si)
    {
        if (D_55a8_party[local_8]._b != 'D')
        {
            D_55a8_party[local_8]._10 = D_55a8_party[local_8]._12;
            D_55a8_party[local_8]._b = 0x47;

            for (local_a = 0; local_a < 32; local_a++)
            {
                if (D_ba14[local_a]._3 == local_8)
                {
                    local_4 = &D_5c5a[D_ba14[local_a]._4];
                    break;
                }
            }

            local_6 = ULTIMA_4d76("AMBFDTPRS", D_55a8_party[local_8]._a);
            local_4->_0_tile = local_4->_1 = D_1ade[local_6];

            D_5c5a[10]._6 = 0;

            ULTIMA_3ae6(1);
            ULTIMA_2192_AudioPulse(5500, 1, 5000, 200, 13);
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
            ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);
            ULTIMA_2192_AudioPulse(5500, 1, 60000, 2500, 1);

            for (local_a = 0; local_a < 3; local_a++)
            {
                D_5c5a[10]._6 = 1;
                ULTIMA_3ae6(1);
            }

            local_e = 1;
            for (local_a = D_55a8_party[local_8]._14 / 100; local_a > 0; local_a >>= 1)
            {
                local_e++;
            }

            // 070b
            if (D_55a8_party[local_8]._16 != local_e)
            {
                D_55a8_party[local_8]._16 = local_e;
                D_55a8_party[local_8]._10 = D_55a8_party[local_8]._12 = local_e * 0x1e;

                ULTIMA_1850_PrintString(/*0x776a*/ "\n\"Hail, ");
                ULTIMA_1850_PrintString(D_55a8_party[local_8]._0);
                ULTIMA_1850_PrintString(/*0x7774*/ "!\nFor thy valiant deeds, I shall reward thee!\n");
                ULTIMA_1850_PrintString(/*0x77a4*/ "Thou art now level ");
                ULTIMA_1a3e_PrintNumber(local_e, 1, 0x20);
                ULTIMA_1850_PrintString(/*0x77b8*/ ", and\n");

                switch (ULTIMA_2092_RandomRange(1, 3))
                {
                case 1:
                    ULTIMA_1850_PrintString(/*0x77c0*/ "stronger!");
                    ULTIMA_3ef0(&D_55a8_party[local_8]._c, 1, 0x1e);
                    break;
                case 2:
                    ULTIMA_1850_PrintString(/*0x77ca*/ "quicker!");
                    ULTIMA_3ef0(&D_55a8_party[local_8]._d, 1, 0x1e);
                    break;
                case 3:
                    ULTIMA_1850_PrintString(/*0x77d4*/ "wiser!");
                    ULTIMA_3ef0(&D_55a8_party[local_8]._e, 1, 0x1e);
                    break;
                }

                ULTIMA_1850_PrintString(/*0x77dc*/ "\" ");
                ULTIMA_266c_GetChar();
                ULTIMA_16ba_PrintChar(10);
            }
        }
        
        switch (D_55a8_party[local_8]._a)
        {
        case 'A':
        case 'M':
            D_55a8_party[local_8]._f = D_55a8_party[local_8]._e;
            break;
        case 'B':
            D_55a8_party[local_8]._f = D_55a8_party[local_8]._e >> 1;
            break;
        }

        ULTIMA_2900_UpdateVitalsDisplay();
    }

    ULTIMA_1850_PrintString("\n\"");

    local_c = D_5888 / 20;
    if (local_c < 4)
    {
        ULTIMA_256e_ReadFileFromDisk("KARMA.DAT", D_b21e, 2000, D_1a74[local_c]);
    }
    else
    {
        ULTIMA_256e_ReadFileFromDisk("KARMA.DAT", D_b21e, 2000, 0x29f);
    }

    ULTIMA_1850_PrintString(D_b21e);
    ULTIMA_16ba_PrintChar(0x22);
    ULTIMA_266c_GetChar();
    ULTIMA_1850_PrintString("\n\nThe strangely familiar old man vanishes...\n");

    D_5c5a[10]._0_tile = D_5c5a[10]._1 = 0x16;

    ULTIMA_1068(D_ad14[0xa5], 5, 5);

    D_5c5a[10]._0_tile = D_5c5a[10]._1 = 0;

    ULTIMA_3ae6(1);
    ULTIMA_4f7c(0);
}
