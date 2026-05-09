#include "common/common.h"
#include "vars.h"
#include "funcs.h"

void TOWN_11f0_Entry(int param_1);

int CAST2_05e0(int a, int b);
void CAST2_08ea(int a);

// OK P1
void BLCKTHRN_0000(int param_1)
{
    int local_4;

    for (local_4 = 0; local_4 < param_1; local_4++)
    {
        ULTIMA_433e_AudioWalkStep();
        ULTIMA_3ae6(2);
    }
}

// OK P1
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
    case 2:
        D_5878++;
        break;
    case 1:
        D_5876++;
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
    int local_4;
    bool di;
    bool local_a;
    int local_e;
    int local_18;
    int local_14;
    int local_10;
    int local_6;
    int local_12;
    int local_16;
    int local_8;

    di = 1;
    while (1)
    {
        local_6 = 1; // a4c9
        local_a = 0; // a4ce

        while (1)
        {
            // a4d3 (default)
            local_4 = *param_1++;
            if (local_4 == 0)
            {
                // -> a4fc
                return;
            }

            if (local_4 >= 0x10)
            {
                // -> a41c
                break;
            }

            // a4ec
            switch (local_4)
            {
            case 1:
                local_a = 1;
                break;

            case 2:
                local_6 = (uint)*param_1;
                param_1 += 2;
                break;

            case 3:
                di = 1;
                break;

            case 4:
                di = 0;
                break;

            case 5:
                ULTIMA_3ae6(*param_1);
                param_1 += 2;
                break;

            case 6:
                D_ad14[param_1[2] + param_1[3] * 0x20] = *param_1;
                param_1 += 4;
                break;

            case 7:
                ULTIMA_5910_UpdateFrame();
                break;

            case 8:
                BLCKTHRN_0000(local_6);
                local_6 = 1;
                break;

            case 9:
                local_4 = *param_1;
                D_5c5a[local_4]._1 = 0;
                D_5c5a[local_4]._0_tile = 0;
                param_1 += 2;
                break;
            }
        }

        // a41c
        local_e = BLCKTHRN_002e(local_4);
        local_12 = D_5876;
        local_16 = D_5878;
        if (local_a)
        {
            local_10 = BLCKTHRN_002e(*param_1);
            local_14 = D_5876;
            local_18 = D_5878;
            param_1 += 2;
        }

        // a454 ->
        local_8 = 0;
        for (; local_6 > 0; local_6--)
        {
            // a495
            D_5c5a[local_e]._2_x += local_12;
            D_5c5a[local_e]._3_y += local_16;
            if (local_a)
            {
                D_5c5a[local_10]._2_x += local_14;
                D_5c5a[local_10]._3_y += local_18;
            }

            if (di)
            {
                BLCKTHRN_0000(1);
            }
        }
    }
}

// OK P1
void BLCKTHRN_0278(int param_1, int param_2)
{
    switch (param_1)
    {
    case 0:
        ULTIMA_1850_PrintString((char*)&D_b21e[0x0]);
        ULTIMA_1850_PrintString(D_1f4e[param_2]);
        ULTIMA_1850_PrintString(/*0x6f6e*/ "?\"");
        break;
    case 1:
        ULTIMA_1850_PrintString((char*)&D_b21e[0x2d]);
        ULTIMA_1850_PrintString(D_1f4e[param_2]);
        ULTIMA_1850_PrintString(/*0x6f72*/ "?\"");
        break;
    case 2:
        ULTIMA_1850_PrintString((char*)&D_b21e[0x52]);
        ULTIMA_1850_PrintString(D_1f4e[param_2]);
        ULTIMA_1850_PrintString(/*0x6f76*/ "?\"");
        break;
    case 3:
        ULTIMA_1850_PrintString((char*)&D_b21e[0xac]);
        break;
    }
}

// OK P1
int BLCKTHRN_02ea(int param_1)
{
    int local_1c;
    int local_1a;
    int local_18;
    int local_16;
    char local_14[18];

    ULTIMA_1850_PrintString(/*0x6f7a*/ "\n\nYour response?\n:");
    ULTIMA_3b1c_GetString(local_14, 0xe);
    ULTIMA_1850_PrintString(/*0x6f8e*/ "\n\n");
    local_1c = ULTIMA_216c_strlen(D_1f5e[param_1]);
    local_16 = 0;

    for (local_18 = 0; local_18 <= ULTIMA_216c_strlen(local_14) - local_1c; local_18++)
    {
        local_16 = 1;

        for (local_1a = 0; local_1a < local_1c; local_1a++)
        {
            if (ULTIMA_2032_ToUpper((byte)local_14[local_18 + local_1a]) != ULTIMA_2032_ToUpper((byte)D_1f5e[param_1][local_1a]))
            {
                local_16 = 0;
                break;
            }
        }

        if (local_16 != 0)
        {
            break;
        }
    }

    return local_16;
}

// CHECKED
void BLCKTHRN_03ae(int param_1)
{
    int local_24;
    int local_26;
    int local_28;
    S_55a8 local_22;

    if (param_1 != 0)
    {
        ULTIMA_1850_PrintString((char*)&D_b21e[0xf1]);
    }
    else
    {
        ULTIMA_1850_PrintString((char*)&D_b21e[0x12d]);
    }

    ULTIMA_3ae6(10);

    for (local_24 = 2000; local_24 < 25000; local_24 += 0x32)
    {
        ULTIMA_2192_AudioPulse(0xa50, 1, 200, local_24, 0);
    }

    for (local_24 = 25000; 2000 < local_24; local_24 -= 0x32)
    {
        ULTIMA_2192_AudioPulse(0xa50, 1, 200, local_24, 0);
    }

    ULTIMA_3522(D_5c5a[1]._2_x, D_5c5a[1]._3_y);

    D_5c5a[1]._0_tile = D_5c5a[1]._1 = 0;
    D_ad14[0xe5] = 0x80;

    local_26 = 0;
    for (local_28 = 0; local_28 < D_585b; local_28++)
    {
        if (D_55a8_party[local_28]._b != 'D')
        {
            local_26++;
        }
        if (local_26 == 2)
            break;
    }

    // a6fc
    local_22 = D_55a8_party[local_28];

    // NOT MATCHING
    local_24 = local_28;
    for (; local_28 < 0xf; local_28++)
    {
        // a73b
        D_55a8_party[local_28] = D_55a8_party[local_28 + 1];
    }

    // a752
    D_55a8_party[0xf] = local_22;
    D_55a8_party[0xf]._1f = 0x7f;

    D_585b--;
    ULTIMA_2900_UpdateVitalsDisplay();
    if (param_1 != 0)
    {
        ULTIMA_1850_PrintString(/*0x6f92*/ "\n\n");
        ULTIMA_1850_PrintString(D_55a8_party[0xf]._0);
        ULTIMA_1850_PrintString(/*0x6f96*/ " is sliced in half! ");
        ULTIMA_266c_GetChar();
        ULTIMA_1850_PrintString((char*)&D_b21e[0x1a0]);
    }

    ULTIMA_16ba_PrintChar(10);
}

// OK P1
void BLCKTHRN_0510(void)
{
    ULTIMA_266c_GetChar();
    BLCKTHRN_00be(D_369e);
}

// OK P1
void BLCKTHRN_051c(void)
{
    ULTIMA_1850_PrintString((char*)&D_b21e[0x229]);
    BLCKTHRN_00be(D_36da);
    ULTIMA_1850_PrintString((char*)&D_b21e[0x25f]);
    ULTIMA_1850_PrintString(D_55a8_party[1]._0);
    ULTIMA_1850_PrintString(/*0x6fac*/ " die!\" ");
    ULTIMA_266c_GetChar();
    ULTIMA_1850_PrintString(/*0x6fb4*/ "\n\n");
}

// OK P1
void BLCKTHRN_054a(int param_1, int param_2)
{
    bool local_6;
    int local_4;

    local_6 = 0;
    ULTIMA_1850_PrintString(/*0x6fb8*/ "\n\n");

    for (local_4 = 0; local_4 < 4; local_4++)
    {
        BLCKTHRN_0278(local_4, param_1);
        if (BLCKTHRN_02ea(param_1) != 0)
        {
            *(D_58d8 + param_1) = 0xff;
            ULTIMA_3f36(&D_5888, 5);
            if (param_2 > 1)
            {
                BLCKTHRN_03ae(0);
                BLCKTHRN_0510();
            }
            else
            {
                ULTIMA_1850_PrintString((char*)&D_b21e[0x29c]);
                BLCKTHRN_0510();
            }
            break;
        }

        if (param_2 < 2)
        {
            ULTIMA_1850_PrintString((char*)&D_b21e[0x2dc]);
            BLCKTHRN_0510();
            break;
        }

        if (local_6)
        {
            ULTIMA_4f7c(2);
            ULTIMA_2900_UpdateVitalsDisplay();

            switch (local_4)
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
            local_6 = 1;
            BLCKTHRN_051c();
        }
    }
}

// OK P1
void BLCKTHRN_060e_Capture(void)
{
    int local_8;
    int local_e;
    int local_c;
    int local_a;
    int local_6;

    int local_10;
    ActorFmt* local_4;

    local_a = 0;
    for (local_8 = 0; local_8 < D_585b; local_8++)
    {
        if (D_55a8_party[local_8]._b != 'D')
        {
            local_a = local_a + 1;
        }
    }

    D_587c = 0x1c;
    ULTIMA_5910_UpdateFrame();
    ULTIMA_1850_PrintString(/*0x6fbc*/ "\nThou art subdued and blindfolded!");

    for (local_c = 0; local_c < 8; local_c++)
    {
        if (D_58d8[local_c] == 0)
            break;
    }

    if (local_c < 8)
    {
        local_10 = 0;

        ULTIMA_3ae6(2);
        ULTIMA_0a70_GRAP_2d_SetPenColor(0);
        ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);
        D_5895_map_level = 0xff;
        ULTIMA_4a84();
        ULTIMA_2e96_SetWindDirection(-1);

        for (local_8 = 0; local_8 < 5; local_8++)
        {
            ULTIMA_20fa_WaitTicks(5);
            ULTIMA_433e_AudioWalkStep();
        }

        ULTIMA_1850_PrintString(/*0x6fe0*/ "\n\nStrong guards drag thee away!");

        for (local_8 = 0; local_8 < (D_a9ce != 0 ? 0x12 : 3); local_8++)
        {
            ULTIMA_20fa_WaitTicks(5);
            ULTIMA_433e_AudioWalkStep();
        }

        for (local_8 = 0; local_8 < 0x20; local_8++)
        {
            ULTIMA_3a74(0, 0, 0, 0, 0, 0, local_8);
        }

        D_5893_map_id = 0xff;
        D_589e = 0xff;

        ULTIMA_256e_ReadFileFromDisk(/*0x7000*/ "MISCMAPS.DAT", D_ac64, 0xb0, 0);
        ULTIMA_256e_ReadFileFromDisk(/*0x700e*/ "MISCMSG.DAT", D_b21e, 1000, 0);

        for (local_8 = 0; local_8 < 0xb; local_8++)
        {
            for (local_e = 0; local_e < 0xb; local_e++)
            {
                D_ad14[local_8 * 0x20 + local_e] = D_ac64[local_8 * 0x10 + local_e];
            }
        }

        // a9ef
        for (local_8 = 0; local_8 < local_a; local_8++)
        {
            local_4 = &D_5c5a[local_8];
            local_4->_2_x = D_1f42[D_1f12[(local_a - 1) * 8 + local_8]];
            local_4->_3_y = D_1f48[D_1f12[(local_a - 1) * 8 + local_8]];

            local_6 = ULTIMA_4d76(/*0x701a*/ "AMBFDTPRS", D_55a8_party[local_8]._a);
            local_4->_0_tile = local_4->_1 = D_1ade[local_6];
        }

        // aa61
        ULTIMA_3ae6(0x10);
        ULTIMA_1850_PrintString(/*0x7024*/ "\n\nThou hast been chained and manacled!");
        ULTIMA_3ae6(0x32);
        ULTIMA_1850_PrintString(/*0x704c*/ "\n\nFootsteps!");
        BLCKTHRN_0000(8);
        ULTIMA_3a74(0x70, 0x70, 4, 10, 0, 0, 6);
        ULTIMA_3a74(0x70, 0x70, 6, 10, 0, 0, 7);
        BLCKTHRN_00be(D_3702);
        ULTIMA_2192_AudioPulse(0xaf0, 1, 13000, 100, 5);
        ULTIMA_3a74(0x16, 0x16, 5, 5, 0, 0, 8);
        ULTIMA_1068(0x178, 5, 5);
        ULTIMA_3a74(0x78, 0x78, 5, 5, 0, 0, 8);
        ULTIMA_3ae6(8);
        ULTIMA_1850_PrintString(/*0x705a*/ "\n\nBlackthorn says:\n\n\"Ah, ");
        ULTIMA_1850_PrintString(D_55a8_party[0]._0);
        ULTIMA_1850_PrintString(/*0x7074*/ "!\n'Tis indeed an honour to meet thee at last! ");
        ULTIMA_266c_GetChar();
        ULTIMA_1850_PrintString(/*0x70a4*/ "\n\nGUARD! Release this good");
        if (D_55a8_party[0]._9 == 12)
        {
            ULTIMA_1850_PrintString(/*0x70c0*/ " lady ");
        }
        else if (D_55a8_party[0]._9 == 11)
        {
            ULTIMA_1850_PrintString(/*0x70c8*/ "man ");
        }
        ULTIMA_1850_PrintString(/*0x70ce*/ "at once!\"");
        BLCKTHRN_00be(D_370e);
        ULTIMA_1850_PrintString((char*)&D_b21e[0x32c]);
        ULTIMA_266c_GetChar();
        BLCKTHRN_054a(local_c, local_a);
        if (D_5c5a[8]._0_tile != 0)
        {
            BLCKTHRN_00be(D_3716);
        }
    }

    D_5895_map_level = 0xff;
    ULTIMA_4a84();
    ULTIMA_2e96_SetWindDirection(-1);
    D_5896_map_x = 10;
    D_5897_map_y = 7;
    D_57ac = 0;
    D_5893_map_id = 0x12;
}

// CHECKED
void BLCKTHRN_0910_Death(void)
{
    int local_c;
    int local_6;
    uint local_8;
    int local_a;
    int local_4;

    ULTIMA_251e_SwitchDisks(1);

    while (ULTIMA_1674_TestOpenFile("BRIT.DAT") == 0) {}

    CAST2_08ea(D_58a6);
    D_587c = 0x1e;

    if (D_5893_map_id < 0x21)
    {
        ULTIMA_5910_UpdateFrame();
    }

    ULTIMA_20fa_WaitTicks(10);
    local_c = D_5893_map_id;
    D_5893_map_id = 0xff;
    D_589e = 0xff;
    ULTIMA_1850_PrintString("\nAn unending darkness engulfs thee...");
    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    ULTIMA_0f46_GRAP_66_Reveal(8, 8, 0xb7, 0xb7);

    for (local_8 = 0; local_8 < 0xb; local_8++)
    {
        for (local_a = 0; local_a < 0xb; local_a++)
        {
            D_ad14[local_8 * 0x20 + local_a] = 0xff;
        }
    }

    for (local_8 = 0; local_8 < 0x20; local_8++)
    {
        ULTIMA_3a74(0, 0, 0, 0, 0, 0, local_8);
    }

    ULTIMA_5910_UpdateFrame();

    ULTIMA_1850_PrintString("\n\nThou hast found refuge.");
    ULTIMA_20fa_WaitTicks(0xe);
    ULTIMA_1850_PrintString("\n\nNo evil lives here, only peace and darkness.");
    ULTIMA_20fa_WaitTicks(0x1c);
    ULTIMA_1850_PrintString("\n\nBut thy slumber is disturbed!");

    D_ad14[0xa5] = 0; // 0xadb9

    D_5c5a[0]._0_tile = D_5c5a[0]._1 = 0x1c;
    D_5c5a[0]._2_x = D_5c5a[0]._3_y = 5;

    ULTIMA_5910_UpdateFrame();

    // ac9d: NOT MATCHING
    for (local_8 = 0; local_8 < 6; local_8++)
    {
        ULTIMA_2192_AudioPulse(D_3720[local_8], 1, D_372c[local_8], D_3738[local_8], D_3744[local_8]);
    }

    ULTIMA_1850_PrintString("\n\nSomeone shouts\n\n\"FORTIS FORTUNA\nAVENTARI\"");
    ULTIMA_20fa_WaitTicks(6);

    D_5c5a[1]._0_tile = D_5c5a[1]._1 = 0x16;
    D_5c5a[1]._2_x = 2;
    D_5c5a[1]._3_y = 7;
    D_ad14[0xe2] = 0;
    ULTIMA_1068(0x5e, 2, 7);
    D_ad14[0xe2] = 0x5e;
    D_5c5a[1]._0_tile = 0;
    ULTIMA_5910_UpdateFrame();

    ULTIMA_20fa_WaitTicks(4);
    D_5c5a[1]._0_tile = 0x16;
    D_5c5a[1]._2_x = 8;
    D_ad14[0xe8] = 0;
    ULTIMA_1068(0x5f, 8, 7);
    D_ad14[0xe8] = 0x5f;
    D_5c5a[1]._0_tile = 0;
    ULTIMA_5910_UpdateFrame();

    ULTIMA_20fa_WaitTicks(4);
    ULTIMA_1850_PrintString("\n\nThere is a peal of thunder!\n");
    ULTIMA_3072();
    ULTIMA_3072();
    D_ad14[0x45] = 0;
    D_5c5a[1]._0_tile = D_5c5a[1]._1 = 0x16;
    D_5c5a[1]._2_x = 5;
    D_5c5a[1]._3_y = 2;
    ULTIMA_1068(0x174, 5, 2);
    D_5c5a[1]._0_tile = D_5c5a[1]._1 = 0x74;
    ULTIMA_5910_UpdateFrame();

    // ad93
    local_4 = D_5888 / 0x14;
    ULTIMA_1850_PrintString("\n\"");
    ULTIMA_256e_ReadFileFromDisk("KARMA.DAT", D_b21e, 2000, D_1a74[local_4]);
    ULTIMA_1850_PrintString((char*)D_b21e);
    ULTIMA_16ba_PrintChar(0x22);
    ULTIMA_266c_GetChar();
    ULTIMA_1850_PrintString("\n\nStrange words are intoned.");
    ULTIMA_20fa_WaitTicks(4);

    for (local_8 = 0; local_8 < D_585b; local_8++)
    {
        local_6 = (u32)36400 / (local_8 + 7);
        ULTIMA_2192_AudioPulse(local_6, 1, 30000, 2000, 2);
        CAST2_05e0(local_8, 0xff);
        D_55a8_party[local_8]._10 = D_55a8_party[local_8]._12;
        ULTIMA_2900_UpdateVitalsDisplay();
    }

    ULTIMA_1850_PrintString("\n\nVertigo...\n");
    ULTIMA_20fa_WaitTicks(4);
    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);
    ULTIMA_10e0_GRAP_51_PutTile(0x11c, 5, 5);
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    ULTIMA_0f46_GRAP_66_Reveal(8, 8, 0xb7, 0xb7);

    if (D_5888 < 0x4b)
    {
        D_5888 = 0x4b;
    }

    D_5893_map_id = 0x11;
    D_5895_map_level = 1;
    D_587c = 0x1c;

    D_5896_map_x = D_5897_map_y = 10;
    D_587a = D_588e = 0;

    while (D_587f != 0x6)
    {
        ULTIMA_4f7c(9);
    }

    D_58a7 = D_58a6 = 0;

    if (D_57a8 == 0)
    {
        D_57a8 = 0x3f;
    }

    if (local_c != 0 && local_c < 0x21)
    {
        TOWN_11f0_Entry(1);
    }
}
