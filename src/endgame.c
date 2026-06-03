#include "common/common.h"
#include "funcs.h"
#include "vars.h"
#include "macros.h"

#include <stdlib.h>

#include "endgame.h"
#include "font.h"

// CHECKED (nop)
static void ENDGAME_0000(void)
{
    byte* local_c;
    byte* local_4;
    byte* local_6;
    uint local_a;
    int local_8;

    ULTIMA_251e_SwitchDisks(2);

    do
    {
        local_c = ULTIMA_0fae_LoadResourceFile(D_25ea[0]); // PROPORT.PCS
    } while (local_c == 0);

    do
    {
        local_4 = ULTIMA_0bae_LoadImageFile(D_25ea[0x11]); // TEXT.16
    } while (local_4 == 0);

    do
    {
        local_6 = ULTIMA_0bae_LoadImageFile(D_25ea[0x18]); // END1.16
    } while (local_6 == 0);

    ULTIMA_0f46_GRAP_66_Reveal(0, 0, 0x13f, 199);
    ULTIMA_1b94_SelectTextWindow(0);

    local_a = 0x31;
    for (local_8 = 0; local_8 < 6; local_8++)
    {
        if (D_3df4[local_8] != local_a)
        {
            ULTIMA_0be4_FreeImage(local_6);
            local_a = (uint)D_3df4[local_8];
            do
            {
                local_6 = ULTIMA_0bae_LoadImageFile(D_25ea[0x18 + local_a]);
            } while (local_6 == 0);
        }

        // a32d
        ULTIMA_0c22_GRAP_0f_SelectPage(1);

        D_a9bd[1] = 2;
        ULTIMA_16ba_PrintChar(0xff);

        if (D_3e06[local_8] == 1)
        {
            switch (local_8)
            {
            case 0:
                // a366
                ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 0, 0xd8, 0, 0);
                ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 4, 0x98, 0x1c, 0); // a385
                break;

            case 3:
                // a454
                ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 5, 0xe0, 0, 0);
                ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 0, 0xb0, 0, 0);
                // -> a385
                break;

            default:
                // a363: NOT MATCHING nop
                ;
            }
        }

        // a38c
        ULTIMA_0d4c_GRAP_4b_PutImage(local_6, D_3dee[local_8], D_3dfa[local_8], D_3e00[local_8], 0);

        D_5146[0] = D_3da6[local_8].x;
        D_5146[1] = D_3da6[local_8].y;
        D_514c[0] = D_3db2[local_8].x;
        D_514c[1] = D_3db2[local_8].y;
        D_5150 = D_3dd6[local_8];
        D_5152 = D_3ddc[local_8];
        D_5156 = D_3de2[local_8];
        D_5158 = D_3de8[local_8];

        ULTIMA_256e_ReadFileFromDisk(/*0x81fe*/ "END.DAT", D_b21e, 2000, D_3dca[local_8]);
        FONT_0000(local_c, D_b21e); // 7ce6 -> 1778:0566

        if (local_8 != 0)
        {
            // a40e
            while (ULTIMA_1d5e_PollKey() == 0)
                ;
        }

        // a415
        ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);
    }

    // a43f
    ULTIMA_0be4_FreeImage(local_6);
    ULTIMA_0be4_FreeImage(local_4);
    ULTIMA_0fdc_FreeBitImage(local_c);

    // a476
    while (ULTIMA_1d5e_PollKey() == 0)
        ;

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_16ba_PrintChar(0xff);

    // a48b
    do
    {
        local_6 = ULTIMA_0bae_LoadImageFile(D_25ea[0x1c]); // ENDSC.16
    } while (local_6 == 0);

    ULTIMA_0d4c_GRAP_4b_PutImage(local_6, 0, 0x28, 0, 0);
    ULTIMA_0be4_FreeImage(local_6);
    ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    D_a9bd[1] = 0;
}

// OK P1
static void ENDGAME_023a(char* param_1)
{
    int notused;

    for (; *param_1 != '\0' && D_bcda < 39; D_bcda++)
    {
        D_bcb2[D_bcda] = *param_1++;
    }

    D_bcb2[D_bcda] = 0;

    if (D_bcb2[D_bcda - 1] == '\n')
    {
        ULTIMA_1850_PrintString(D_bcb2);
        D_bcda = 0;
    }
}

// OK P1
static void ENDGAME_028c(int param_1)
{
    if (param_1 < 0x15)
    {
        ENDGAME_023a(D_3e0c[param_1 - 1]);
    }
    else
    {
        ENDGAME_023a(D_3e32[param_1 / 10 - 2]);

        if (param_1 % 10)
        {
            ENDGAME_023a(/*0x82c6*/ "-");
            ENDGAME_023a(D_3e0c[(param_1 % 10) - 1]);
        }
    }
}

// OK P1
static void ENDGAME_02d6(int param_1)
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
            ENDGAME_023a(D_3e42[param_1 - 0x15]);
        }
    }
}

// OK P1
static void ENDGAME_0326(void)
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
    ENDGAME_028c((s16)D_5874 / 100);
    ENDGAME_023a(/*0x8374*/ " Hundred\n");
    ENDGAME_028c((s16)D_5874 % 100);
    ENDGAME_023a(/*0x837e*/ "\n\n");
    ENDGAME_023a(D_55a8_party[0].name);
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

    // a697
    local_6 = D_5874 - 0x8b;
    local_8 = D_587d - 4;
    local_4 = D_587e - 5;
    if (local_4 < 0)
    {
        // a6ba
        local_4 += 0x1c;
        local_8--;
    }

    // a6c1
    if (local_8 < 0)
    {
        local_8 += 0xd;
        local_6--;
    }

    // a6ce
    if (local_6 != 0)
    {
        ENDGAME_023a(u5_itoa(local_6, local_10, 10));
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
        ENDGAME_023a(u5_itoa(local_8, local_10, 10));
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
        ENDGAME_023a(u5_itoa(local_4, local_10, 10));
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
        local_4++;
    } while (1);
}

// OK P1
static void ENDGAME_04fe(void)
{
    ULTIMA_3ae6(2);
    ULTIMA_433e_AudioWalkStep();
    ULTIMA_3ae6(3);
}

// CHECKED (optimization)
// actor_idx, x, y
static int ENDGAME_0510(int param_1, int param_2, int param_3)
{
    ActorFmt* local_4;
    int local_6;
    int local_8;
    int local_a;

    local_8 = 1;
    local_4 = &D_5c5a[param_1];

    if (local_4->_0_tile == 0)
    {
        // a7c0
        local_8 = 0;
    }
    else if (local_4->_2_x == param_2 && local_4->_3_y == param_3) // a7c8
    {
        local_8 = 0;
    }
    else
    {
        // a7da
        local_6 = abs(local_4->_2_x - param_2);
        local_a = abs(local_4->_3_y - param_3);
        if (local_6 < local_a)
        {
            if (local_4->_3_y > param_3)
            {
                local_4->_3_y--;
            }
            else
            {
                // a80c
                local_4->_3_y++;
            }
        }
        else if (local_4->_2_x > param_2) // a812
        {
            local_4->_2_x--;
        }
        else
        {
            // a822
            local_4->_2_x++;
        }

        ENDGAME_04fe();

    }

    return local_8;
}

// OK P1
static void ENDGAME_05a2(int param_1)
{
    ActorFmt* local_4;
    int local_8;
    int local_6;
    int local_a;
    local_4 = &D_5c5a[param_1];

    if (local_4->_0_tile != 0 && ULTIMA_2092_RandomRange(0, 1) != 0)
    {
        for (local_a = 0; local_a < 8; local_a++)
        {
            local_6 = local_4->_2_x;
            local_8 = local_4->_3_y;

            switch (ULTIMA_2092_RandomRange(0, 3))
            {
            case 0:
                local_6++;
                break;
            case 1:
                local_6--;
                break;
            case 2:
                local_8++;
                break;
            case 3:
                local_8--;
                break;
            }

            if (GetMapViewport(local_6, local_8) == 68)
            {
                local_4->_2_x = local_6;
                local_4->_3_y = local_8;
                break;
            }
        }
    }

    ULTIMA_3ae6(1);
}

// CHECKED
void ENDGAME_0648_EndgameMain(void)
{
    int local_e;
    int local_c;
    int local_a;
    int local_8;
    int local_4;
    ActorFmt* local_6;

    D_589e = 0xff;
    ULTIMA_2900_UpdateVitalsDisplay();
    ULTIMA_6f9e(1);
    ULTIMA_256e_ReadFileFromDisk(/*0x8480*/ "MISCMAPS.DAT", D_ac64, 0xb0, 0x210);
    ULTIMA_256e_ReadFileFromDisk(/*0x848e*/ "ENDMSG.DAT", D_b21e, 1000, 0);

    for (local_c = 0; local_c < 0xb; local_c++)
    {
        for (local_e = 0; local_e < 0xb; local_e++)
        {
            GetCombatMap(local_e, local_c) = D_ac64[local_c * 0x10 + local_e];
        }
    }

    // a949 (NOT MATCHING)
    for (local_c = 0; local_c < 0x20; local_c++)
    {
        D_5c5a[local_c]._0_tile = D_5c5a[local_c]._1_animTile = 0;
    }

    // a966
    local_6 = &D_5c5a[31];
    local_6->_0_tile = local_6->_1_animTile = 0x7c;
    local_6->_2_x = 5;
    local_6->_3_y = 8;
    local_6->_6 = 0;
    ULTIMA_3ae6(0x28);

    while (ENDGAME_0510(0x1f, 5, 3) != 0)
        ;

    // a9ad
    // NOT MATCHING
    for (local_c = 0; local_c < D_585b; local_c++)
    {
        if (D_55a8_party[local_c].status == STATUS_DEAD)
        {
            ULTIMA_16ba_PrintChar(10);
            ULTIMA_1850_PrintString(D_55a8_party[local_c].name);
            ULTIMA_1850_PrintString(/*0x849a*/ " lives!\n");
            D_55a8_party[local_c].status = STATUS_GOOD;
            D_55a8_party[local_c].hp = D_55a8_party[local_c].maxHp;
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
            ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);
            ULTIMA_2192_AudioPulse(0x2260, 1, 40000, 5000, 1);
            ULTIMA_2900_UpdateVitalsDisplay();
        }

        // aa25
        local_8 = ULTIMA_4d76_FindIndex(/*0x84a4*/ PROFESSION_LIST, D_55a8_party[local_c].profession);

        // aa37; NOT MATCHING
        local_6 = &D_5c5a[local_c];
        
        local_6->_0_tile = local_6->_1_animTile = D_1ade[local_8];
        local_6->_2_x = 5;
        local_6->_3_y = 9;
        local_6->_6 = 0;

        // aa57
        ULTIMA_3ae6(1);

        // aa5e; NOT MATCHING
        if (ENDGAME_0510(local_c, D_3e5a[local_c], D_3e60[local_c]) != 0)
        {
            while (ENDGAME_0510(local_c, D_3e5a[local_c], D_3e60[local_c]) != 0)
                ;
        }
    }

    // aabc
    ULTIMA_3ae6(0x28);
    ULTIMA_1850_PrintString((char*)D_b21e);
    ULTIMA_1850_PrintString(D_55a8_party[0].name);
    ULTIMA_1850_PrintString(/*0x84ae*/ "!\"\n\n");
    ULTIMA_266c_GetChar();
    ULTIMA_1850_PrintString((char*)&D_b21e[0x21]);

    do
    {
        local_4 = ULTIMA_266c_GetChar();
        switch (local_4)
        {
        case 0x59:
            ULTIMA_1850_PrintString(/*0x84b4*/ "Yes\n\n");
            break;
        case 0x4e:
            ULTIMA_1850_PrintString(/*0x84ba*/ "No\n\n");
            break;
        }
    } while (local_4 != 0x59 && local_4 != 0x4e); // aaf8; NOT MATCHING

    // ab0c
    if (local_4 == 0x4e)
    {
        ULTIMA_1850_PrintString((char*)&D_b21e[0x49]);

        do
        {
            local_4 = ULTIMA_266c_GetChar();
            switch (local_4)
            {
            case 0x59:
                ULTIMA_1850_PrintString(/*0x84c0*/ "Yes\n\n");
                break;
            case 0x4e:
                ULTIMA_1850_PrintString(/*0x84c6*/ "No\n\n");
                break;
            }
        } while (local_4 != 0x59 && local_4 != 0x4e); // NOT MATCHING
    }

    // ab49
    if (local_4 == 0x59 && D_57bf != 0)
    {
        ULTIMA_3ae6(8);

        while (ENDGAME_0510(0, 5, 4) != 0)
            ;

        while (ENDGAME_0510(0, 5, 5) != 0)
            ;

        ULTIMA_3ae6(4);

        local_6 = &D_5c5a[6];
        
        local_6->_0_tile = local_6->_1_animTile = 0xe;
        local_6->_2_x = 5;
        local_6->_3_y = 4;
        local_6->_6 = 0;

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

        D_5c5a[6]._1_animTile = D_5c5a[6]._0_tile = 8;

        ULTIMA_266c_GetChar();
        ULTIMA_2192_AudioPulse(0x1450, 1, 50000, 10000, 1);

        D_5c5a[6]._1_animTile = D_5c5a[6]._0_tile = 0;
        GetCombatMap(5, 4) = 0xdc;

        for (D_5887 = 1; D_5887 < 0x10; D_5887++)
        {
            ULTIMA_3ae6(1);
        }

        ULTIMA_3ae6(4);

        while (ENDGAME_0510(0x1f, 5, 4) != 0)
            ;

        D_5c5a[31]._0_tile = D_5c5a[31]._1_animTile = 0;

        // ac64
        ULTIMA_3ae6(1);

        for (local_c = 0; local_c < D_585b; local_c++)
        {
            while (ENDGAME_0510(local_c, 5, 4) != 0)
                ;

            D_5c5a[local_c]._0_tile = D_5c5a[local_c]._1_animTile = 0;
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
        local_a = ENDGAME_0510(2, 8, 6);
        local_a += ENDGAME_0510(0x1f, 4, 1);
        local_a += ENDGAME_0510(0, 8, 4);
    } while (local_a != 0);

    do
    {
        ENDGAME_05a2(1);
        ENDGAME_05a2(3);
        ENDGAME_05a2(4);
        ENDGAME_05a2(5);
    } while (1);
}
