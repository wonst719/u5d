#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdlib.h>

void FONT_0000(byte* param_1, char* param_2);

// NOT MATCHING
void ENDGAME_0000(void)
{
    byte* pbVar1;
    byte* pbVar2;
    byte* pbVar3;
    uint local_a;
    int local_8;

    ULTIMA_251e_SwitchDisks(2);

    do
    {
        pbVar1 = ULTIMA_0fae_LoadFile(D_25ea[0]); // PROPORT.PCS
    } while (pbVar1 == 0);

    do
    {
        pbVar2 = ULTIMA_0bae_LoadImageFile(D_25ea[0x11]); // TEXT.16
    } while (pbVar2 == 0);

    do
    {
        pbVar3 = ULTIMA_0bae_LoadImageFile(D_25ea[0x18]); // END1.16
    } while (pbVar3 == 0);

    ULTIMA_0f46_GRAP_66_Reveal(0, 0, 0x13f, 199);
    ULTIMA_1b94_SelectTextWindow(0);

    local_a = 0x31;
    for (local_8 = 0; local_8 < 6; local_8++)
    {
        if (D_3df4[local_8] != local_a)
        {
            ULTIMA_0be4_FreeImage(pbVar3);
            local_a = (uint)D_3df4[local_8];
            do
            {
                pbVar3 = ULTIMA_0bae_LoadImageFile(D_25ea[0x18 + local_a]);
            } while (pbVar3 == 0);
        }

        ULTIMA_0c22_GRAP_0f_SelectPage(1);

        D_a9be = 2;
        ULTIMA_16ba_PrintChar(0xff);

        if (D_3e06[local_8] == 1)
        {
            if (local_8 == 0)
            {
                ULTIMA_0d4c_GRAP_4b_PutImage(pbVar2, 0, 0xd8, 0, 0);
                ULTIMA_0d4c_GRAP_4b_PutImage(pbVar2, 4, 0x98, 0x1c, 0);
            }
            else if (local_8 == 3)
            {
                ULTIMA_0d4c_GRAP_4b_PutImage(pbVar2, 5, 0xe0, 0, 0);
                ULTIMA_0d4c_GRAP_4b_PutImage(pbVar2, 0, 0xb0, 0, 0);
            }
        }

        ULTIMA_0d4c_GRAP_4b_PutImage(pbVar3, D_3dee[local_8], D_3dfa[local_8], D_3e00[local_8], 0);

        D_5146[0] = D_3da6[local_8]._0;
        D_5146[1] = D_3da6[local_8]._1;
        D_514c[0] = D_3db2[local_8]._0;
        D_514c[1] = D_3db2[local_8]._2;
        D_5150 = D_3dd6[local_8];
        D_5152 = D_3ddc[local_8];
        D_5156 = D_3de2[local_8];
        D_5158 = D_3de8[local_8];

        ULTIMA_256e_ReadFile(/*0x81fe*/ "END.DAT", D_b21e, 2000, D_3dca[local_8]);
        FONT_0000(pbVar1, D_b21e); // 7ce6 -> 1778:0566

        if (local_8 != 0)
        {
            while (ULTIMA_1d5e_PeekKeystroke() == 0)
                ;
        }

        ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);
    }

    ULTIMA_0be4_FreeImage(pbVar3);
    ULTIMA_0be4_FreeImage(pbVar2);
    ULTIMA_0fdc_FreeBitImage(pbVar1);

    while (ULTIMA_1d5e_PeekKeystroke() == 0)
        ;

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_16ba_PrintChar(0xff);

    do
    {
        pbVar1 = ULTIMA_0bae_LoadImageFile(D_25ea[0x1c]); // ENDSC.16
    } while (pbVar1 == 0);

    ULTIMA_0d4c_GRAP_4b_PutImage(pbVar1, 0, 0x28, 0, 0);
    ULTIMA_0be4_FreeImage(pbVar1);
    ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    D_a9be = 0;
}

// NOT MATCHING
void ENDGAME_023a(char* param_1)
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
        ULTIMA_1850_PrintString(D_bcb2);
        D_bcda = 0;
    }
}

// NOT MATCHING
void ENDGAME_028c(int param_1)
{
    int iVar1;

    if (param_1 > 0x14)
    {
        ENDGAME_023a(D_3e32[param_1 / 10 - 2]);

        iVar1 = param_1 / 10;
        param_1 %= 10;
        if (param_1 == 0)
        {
            return;
        }

        ENDGAME_023a(/*0x82c6*/ "-");
    }

    ENDGAME_023a(D_3e0c[param_1 - 1]);
}

// NOT MATCHING
void ENDGAME_02d6(int param_1)
{
    if (param_1 < 13)
    {
        ENDGAME_023a(D_3e42[param_1 - 1]);
    }
    else if (param_1 < 20)
    {
        ENDGAME_028c(param_1);
        ENDGAME_023a(/*0x831e*/ "th");
    }
    else
    {
        ENDGAME_023a(/*0x8322*/ "Twent");
        if (param_1 == 20)
        {
            ENDGAME_023a(/*0x8328*/ "ieth");
        }
        else
        {
            ENDGAME_023a(/*0x832e*/ "y-");
            ENDGAME_023a(D_3e42[param_1 - 15]);
        }
    }
}

// NOT MATCHING
void ENDGAME_0326(void)
{
    char local_10[8];
    int local_8;
    int local_6;
    int local_4;

    ULTIMA_1bf2_SetTextPosition(0, 1);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_16ba_PrintChar(0xfc);
    ULTIMA_1850_PrintString(/*0x8332*/ "Be it known that on\n");
    D_bcda = 0;
    ENDGAME_023a(/*0x8348*/ "the ");
    ENDGAME_02d6(D_587e);
    ENDGAME_023a(/*0x834e*/ " Day of\n");
    ENDGAME_023a(/*0x8358*/ "the ");
    ENDGAME_02d6(D_587d);
    ENDGAME_023a(/*0x835e*/ " Month\n");
    ULTIMA_1850_PrintString(/*0x8366*/ "of the Year\n");
    ENDGAME_028c(D_5874 / 100);
    ENDGAME_023a(/*0x8374*/ " Hundred\n");
    ENDGAME_028c(D_5874 % 100);
    ENDGAME_023a(/*0x837e*/ "\n\n");
    ENDGAME_023a(D_55a8_party[0]._0);
    ENDGAME_023a(/*0x8382*/ " the Avatar\n\n");
    ULTIMA_1850_PrintString(/*0x8390*/ "saved the life\n");
    ULTIMA_1850_PrintString(/*0x83a0*/ "of our sovereign\n");
    ULTIMA_1850_PrintString(/*0x83b2*/ "Lord British, thereby\n");
    ULTIMA_1850_PrintString(/*0x83ca*/ "saving our people\n");
    ULTIMA_1850_PrintString(/*0x83de*/ "and our land.\n\n");
    ULTIMA_1c9e_SelectCharset(1);
    ULTIMA_1850_PrintString(/*0x83ee*/ "[E@QUE_@OF@[E@AVATAR\n");
    ULTIMA_1850_PrintString(/*0x8404*/ "IS@FOREVER\n\n\n\n");
    ULTIMA_1c9e_SelectCharset(0);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x8414*/ "Report now, thy Quest compleat in\n");

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
        ENDGAME_023a(ULTIMA_0426_itoa(local_6, local_10, 10));
        ENDGAME_023a(/*0x8438*/ " year");
        if (local_6 > 1)
        {
            ENDGAME_023a(/*0x843e*/ "s");
        }

        if (local_8 != 0 || local_4 != 0)
        {
            ENDGAME_023a(/*0x8440*/ ", ");
        }
    }

    if (local_8 != 0)
    {
        ENDGAME_023a(ULTIMA_0426_itoa(local_8, local_10, 10));
        ENDGAME_023a(/*0x8444*/ " month");
        if (local_8 > 1)
        {
            ENDGAME_023a(/*0x844c*/ "s");
        }

        if (local_4 != 0)
        {
            ENDGAME_023a(/*0x844e*/ ", ");
        }
    }

    if (local_4 != 0)
    {
        ENDGAME_023a(ULTIMA_0426_itoa(local_4, local_10, 10));
        ENDGAME_023a(/*0x8452*/ " day");
        if (local_4 > 1)
        {
            ENDGAME_023a(/*0x8458*/ "s");
        }
    }

    ENDGAME_023a(/*0x845a*/ "\n");
    ULTIMA_1850_PrintString(/*0x845c*/ "to Lord British at Origin Systems!");

    do
    {
        // infinite loop
#if !defined(TARGET_DOS16)
        ULTIMA_20fa_WaitTicks(1);
#endif
    } while (1);
}

// NOT MATCHING
void ENDGAME_04fe(void)
{
    ULTIMA_3ae6(2);
    ULTIMA_433e_AudioSomeNoise();
    ULTIMA_3ae6(3);
}

// NOT MATCHING
// actor_idx, x, y
int ENDGAME_0510(int param_1, int param_2, int param_3)
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

        ENDGAME_04fe();
    }

    return ret;
}

// NOT MATCHING
void ENDGAME_05a2(int param_1)
{
    uint uVar2;
    uint uVar3;
    int iStack_a;

    if (D_5c5a[param_1]._0_tile != 0 && ULTIMA_2092_RandomRange(0, 1) != 0)
    {
        for (iStack_a = 0; iStack_a < 8; iStack_a++)
        {
            uVar3 = D_5c5a[param_1]._2_x;
            uVar2 = D_5c5a[param_1]._3_y;

            switch (ULTIMA_2092_RandomRange(0, 3))
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
void ENDGAME_0648_EndgameMain(void)
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
    ULTIMA_2900_UpdateVitalsDisplay();
    ULTIMA_6f9e(1);
    ULTIMA_256e_ReadFile(/*0x8480*/ "MISCMAPS.DAT", D_ac64, 0xb0, 0x210);
    ULTIMA_256e_ReadFile(/*0x848e*/ "ENDMSG.DAT", D_b21e, 1000, 0);

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

    while (ENDGAME_0510(0x1f, 5, 3) != 0)
        ;

    for (iStack_c = 0; iStack_c < D_585b; iStack_c++)
    {
        if (D_55a8_party[iStack_c]._b == 'D')
        {
            ULTIMA_16ba_PrintChar(10);
            ULTIMA_1850_PrintString(D_55a8_party[iStack_c]._0);
            ULTIMA_1850_PrintString(/*0x849a*/ " lives!\n");
            D_55a8_party[iStack_c]._b = 'G';
            D_55a8_party[iStack_c]._10 = D_55a8_party[iStack_c]._12;
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
            ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);
            ULTIMA_2192_AudioSomeNoise(0x2260, 1, 40000, 5000, 1);
            ULTIMA_2900_UpdateVitalsDisplay();
        }

        iVar8 = ULTIMA_4d76(/*0x84a4*/ "AMBFDTPRS", D_55a8_party[iStack_c]._a);

        uVar4 = D_1ade[iVar8];

        D_5c5a[iStack_c]._1 = uVar4;
        D_5c5a[iStack_c]._0_tile = uVar4;
        D_5c5a[iStack_c]._2_x = 5;
        D_5c5a[iStack_c]._3_y = 9;
        D_5c5a[iStack_c]._6 = 0;

        ULTIMA_3ae6(1);

        if (ENDGAME_0510(iStack_c, D_3e5a[iStack_c], D_3e60[iStack_c]) != 0)
        {
            uVar4 = D_3e60[iStack_c];
            uVar5 = D_3e5a[iStack_c];

            while (ENDGAME_0510(iStack_c, uVar5, uVar4) != 0)
                ;
        }
    }

    ULTIMA_3ae6(0x28);
    ULTIMA_1850_PrintString((char*)D_b21e);
    ULTIMA_1850_PrintString(D_55a8_party[0]._0);
    ULTIMA_1850_PrintString(/*0x84ae*/ "!\"\n\n");
    ULTIMA_266c_GetChar();
    ULTIMA_1850_PrintString((char*)&D_b21e[0x21]);

    do
    {
        iStack_4 = ULTIMA_266c_GetChar();
        if (iStack_4 == 0x4e)
        {
            ULTIMA_1850_PrintString(/*0x84ba*/ "No\n\n");
        }
        else if (iStack_4 == 0x59)
        {
            ULTIMA_1850_PrintString(/*0x84b4*/ "Yes\n\n");
        }
    } while (iStack_4 != 0x59 && iStack_4 != 0x4e);

    if (iStack_4 == 0x4e)
    {
        ULTIMA_1850_PrintString((char*)&D_b21e[0x49]);

        do
        {
            iStack_4 = ULTIMA_266c_GetChar();
            if (iStack_4 == 0x4e)
            {
                ULTIMA_1850_PrintString(/*0x84c6*/ "No\n\n");
            }
            else if (iStack_4 == 0x59)
            {
                ULTIMA_1850_PrintString(/*0x84c0*/ "Yes\n\n");
            }
        } while (iStack_4 != 0x59 && iStack_4 != 0x4e);
    }

    if (iStack_4 == 0x59 && D_57bf != 0)
    {
        ULTIMA_3ae6(8);

        while (ENDGAME_0510(0, 5, 4) != 0)
            ;

        while (ENDGAME_0510(0, 5, 5) != 0)
            ;

        ULTIMA_3ae6(4);

        D_5c5a[6]._1 = 0xe;
        D_5c5a[6]._0_tile = 0xe;
        D_5c5a[6]._2_x = 5;
        D_5c5a[6]._3_y = 4;
        D_5c5a[6]._6 = 0;

        ULTIMA_1850_PrintString((char*)&D_b21e[0xab]);
        ULTIMA_3ae6(0x28);
        ULTIMA_1850_PrintString(/*0x84cc*/ "\n\nHe says:\n\n");
        ULTIMA_266c_GetChar();
        ULTIMA_1850_PrintString((char*)&D_b21e[0xd3]);
        ULTIMA_266c_GetChar();
        ULTIMA_1850_PrintString((char*)&D_b21e[0x128]);
        ULTIMA_266c_GetChar();
        ULTIMA_1850_PrintString((char*)&D_b21e[0x167]);
        ULTIMA_266c_GetChar();
        ULTIMA_1850_PrintString((char*)&D_b21e[0x1c9]);
        ULTIMA_266c_GetChar();
        ULTIMA_1850_PrintString((char*)&D_b21e[0x211]);
        ULTIMA_266c_GetChar();
        ULTIMA_1850_PrintString((char*)&D_b21e[0x24b]);

        D_5c5a[6]._0_tile = 8;
        D_5c5a[6]._1 = 8;

        ULTIMA_266c_GetChar();
        ULTIMA_2192_AudioSomeNoise(0x1450, 1, 50000, 10000, 1);

        D_5c5a[6]._0_tile = 0;
        D_5c5a[6]._1 = 0;
        D_ad14[0x85] = 0xdc;

        for (D_5887 = 1; D_5887 < 0x10; D_5887++)
        {
            ULTIMA_3ae6(1);
        }

        ULTIMA_3ae6(4);

        while (ENDGAME_0510(0x1f, 5, 4) != 0)
            ;

        D_5c5a[31]._1 = 0;
        D_5c5a[31]._0_tile = 0;
        ULTIMA_3ae6(1);

        for (iVar11 = 0; iVar11 < D_585b; iVar11++)
        {
            while (ENDGAME_0510(iVar11, 5, 4) != 0)
                ;

            D_5c5a[iVar11]._1 = 0;
            D_5c5a[iVar11]._0_tile = 0;
            ULTIMA_3ae6(1);
        }

        for (D_5887 = 0xf; D_5887 > 0; D_5887--)
        {
            ULTIMA_3ae6(1);
        }

        ULTIMA_10e0_GRAP_51_PutTile(0x44, 5, 4);
        ULTIMA_0c22_GRAP_0f_SelectPage(1);
        ULTIMA_0a70_GRAP_2d_SetPenColor(0);
        ULTIMA_102e_UnloadTileset();
        ULTIMA_0aa6_GRAP_3f_FillRect(0, 0, 0x13f, 199);
        ULTIMA_0c22_GRAP_0f_SelectPage(0);
        ENDGAME_0000();
        ENDGAME_0326();
        return;
    }

    // bad endgame
    ULTIMA_1850_PrintString(/*0x84da*/ "\"I see...\n");
    ULTIMA_3ae6(0x28);
    ULTIMA_1850_PrintString((char*)&D_b21e[0x2d5]);
    D_5c5a[0]._3_y--;
    ENDGAME_04fe();

    do
    {
        iVar8 = ENDGAME_0510(2, 8, 6);
        iVar12 = ENDGAME_0510(0x1f, 4, 1);
        iVar7 = ENDGAME_0510(0, 8, 4);
    } while (iVar8 + iVar12 + iVar7 != 0);

    do
    {
        ENDGAME_05a2(1);
        ENDGAME_05a2(3);
        ENDGAME_05a2(4);
        ENDGAME_05a2(5);
    } while (1);
}
