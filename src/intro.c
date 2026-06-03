#include "audio/audio.h"
#include "common/common.h"
#include "funcs.h"
#include "grap_drv.h"
#include "savegame.h"
#include "vars.h"
#include "macros.h"

#include <stdlib.h>

#include "font.h"
#include "intro.h"

#include <string.h>

#include "time/time.h"

// NOTE: Addresses are shifted by 0x10 (there appears to be a header)

static void INTRO_132a_TransferFromU4(void);
static void INTRO_1e22(int param_1);
static void INTRO_2024(void);
static void INTRO_20ae_ShowWD(byte* ptr);

// OK P1
static void INTRO_0010(void)
{
    int local_4;

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_16ba_PrintChar(0xff);

    for (local_4 = 0; local_4 < 4; local_4++)
    {
        ULTIMA_0d4c_GRAP_4b_PutImage(D_bb1a, local_4 + 1, 0x10, local_4 * 0x32, 0);
    }
}

#if !defined(TARGET_DOS16)
byte* g_british;
#endif

// OK P1
// lord british animation
static int INTRO_0050(int param_1, int param_2)
{
    int local_4;
    int local_a_xMove;
    int local_8;
    int local_e;
    int local_c_yMove;
    byte* local_6;

#if !defined(TARGET_DOS16)
    local_6 = g_british;
#define MEM_SIZE 3000
#else
    // DOS: uses savegame area
    local_6 = &D_55a6;
#define MEM_SIZE ((byte*)&D_6606 - (byte*)&D_55a6) /*0x1060*/
#endif

    local_e = D_13b0_white_color;

    ULTIMA_0a70_GRAP_2d_SetPenColor(local_e);

    local_4 = D_5356;
    D_5356 = 0x113;

    for (local_8 = D_bb18; local_8 < MEM_SIZE; local_8++)
    {
        if (local_e != 0)
        {
            ULTIMA_0c64_GRAP_30_Pset(param_1, param_2);
        }

        local_e = D_13b0_white_color;

        local_c_yMove = local_6[local_8] & 7;
        if (local_c_yMove > 2)
        {
            local_e = 0;
        }

        if ((local_6[local_8] & 8) != 0)
        {
            local_c_yMove = -local_c_yMove;
        }

        local_a_xMove = (local_6[local_8] >> 4) & 0x7;
        if (local_a_xMove > 2)
        {
            local_e = 0;
        }

        if ((local_6[local_8] & 0x80) != 0)
        {
            local_a_xMove = -local_a_xMove;
        }

        param_1 += local_a_xMove;
        param_2 += local_c_yMove;

        if (ULTIMA_1d5e_PollKey() != 0)
        {
            D_5356 = local_4;
            return 0;
        }

        if ((local_8 & 0x1f) == 0)
        {
            ULTIMA_20fa_WaitTicks(1);
        }

        if (local_6[local_8] == 0)
            break;
    }

    D_bb18 = local_8 + 1;
    D_5356 = local_4;

    return D_bb18;
#undef MEM_SIZE
}

// CHECKED
// introduction
static void INTRO_014e_Introduction(void)
{
    int local_e; // unused
    byte* local_c;
    byte* local_4;
    int local_a;
    int local_8;
    byte* local_6;

    if (D_5893_map_id != 64)
    {
        ULTIMA_102e_UnloadTileset();
    }

    D_5893_map_id = 0x40;
    do
    {
        local_c = ULTIMA_0fae_LoadResourceFile(D_25ea[0]);
    } while (local_c == 0);

    FONT_0000(local_c, /*0x2f30*/ "");
    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1bf2_SetTextPosition(0, 10);

    do
    {
        local_4 = ULTIMA_0bae_LoadImageFile(D_25ea[0x11]);
    } while (local_4 == 0);

    // 01b2
    do
    {
        local_6 = ULTIMA_0bae_LoadImageFile(D_25ea[0x12]);
    } while (local_6 == 0);

    local_8 = 0;
    for (local_a = 0; local_a < 0x15; local_a++) // 0384
    {
        // 038a
        if (local_8 != D_30ae[local_a])
        {
            ULTIMA_0be4_FreeImage(local_6);
            local_8 = D_30ae[local_a];
            do
            {
                local_6 = ULTIMA_0bae_LoadImageFile(D_25ea[0x12 + local_8]);
            } while (local_6 == 0);
        }

        D_a9bd[1] = 2;
        ULTIMA_0c22_GRAP_0f_SelectPage(1);
        ULTIMA_16ba_PrintChar(0xff);
        if (D_30f0[local_a] == 1)
        {
            switch (local_a)
            {
            case 0:
                ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 0, 0xe0, 0x1e, 0);
                ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 1, 0xa8, 0x3a, 0);
                break;
            case 7:
                ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 0, 0xe8, 0x1a, 0);
                ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 2, 200, 0x36, 0);
                break;
            case 0xe:
                ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 0, 0xb8, 0, 0);
                ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 3, 0xf8, 0, 0);
                break;
            }
        }

        ULTIMA_0d4c_GRAP_4b_PutImage(local_6, D_3098[local_a], D_30c4[local_a], D_30da[local_a], 0);
        if (D_30f0[local_a] >= 4)
        {
            ULTIMA_0d4c_GRAP_4b_PutImage(local_6, D_30f0[local_a] * 2 - 5, D_30c4[local_a], D_30da[local_a] + 0x37, 0);
        }

        D_5146[0] = D_2f98[local_a].x;
        D_5146[1] = D_2f98[local_a].y;

        D_514c[0] = D_2fc2[local_a].x;
        D_514c[1] = D_2fc2[local_a].y;

        D_5150 = D_3040[local_a];
        D_5152 = D_3056[local_a];
        D_5156 = D_306c[local_a];
        D_5158 = D_3082[local_a];

        if (D_30f0[local_a] == 3)
        {
            ULTIMA_0d4c_GRAP_4b_PutImage(local_6, 3, 0x60, 0x27, 0);
            FONT_0000(local_c, /*0x2f31*/ "Instantly, a shimmering blue door springs up!");
            D_5156 = D_306c[local_a];
            D_5158 = 0xb4;
            FONT_0000(local_c, /*0x2f5f*/ "With heart beating rapidly, you step into it.");
        }
        else
        {
            ULTIMA_256e_ReadFileFromDisk(/*0x2f8d*/ "STORY.DAT", D_b21e, 2000, D_3016[local_a]);
            FONT_0000(local_c, D_b21e);
        }

        if (local_a != 0)
        {
            ULTIMA_1b16_ClearKbdBuffer();
            while (ULTIMA_1d5e_PollKey() == 0)
                ;
        }

        ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);

        if (D_30f0[local_a] == 2)
        {
            ULTIMA_0c22_GRAP_0f_SelectPage(1);
            ULTIMA_0d4c_GRAP_4b_PutImage(local_6, 2, 0x28, 0x56, 0);
            ULTIMA_0f46_GRAP_66_Reveal(0x28, 0x56, 0x4b, 0x78);
        }
    }

    ULTIMA_0be4_FreeImage(local_6);
    ULTIMA_0be4_FreeImage(local_4);
    ULTIMA_0fdc_FreeBitImage(local_c);

    ULTIMA_1b16_ClearKbdBuffer();
    while (ULTIMA_1d5e_PollKey() == 0)
        ;

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    D_a9bd[1] = 0;
    ULTIMA_251e_SwitchDisks(0);
}

// OK P1
void INTRO_043e(char* param_1)
{
    int local_4;
    int local_6;

    local_4 = -(ULTIMA_216c_strlen(param_1) / 2 - 0x12);
    local_6 = local_4 + ULTIMA_216c_strlen(param_1) + 2;
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
    ULTIMA_0aa6_GRAP_3f_FillRect(8, 0xc1, local_4 * 8, 199);
    ULTIMA_0aa6_GRAP_3f_FillRect(local_6 * 8, 0xc1, 0x137, 199);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(8, 0xc0, local_4 * 8, 0xc0);
    ULTIMA_0b10_GRAP_Line(local_6 * 8, 0xc0, 0x137, 0xc0);
    ULTIMA_1bf2_SetTextPosition(local_4, 0x18);
    ULTIMA_4c2a();
    ULTIMA_1850_PrintString(param_1);
    ULTIMA_4cce();
}

// OK P1
static void INTRO_04e0_DrawMenuBorders(void)
{
    int local_4;

    ULTIMA_1cca_SetTextForegroundColor(D_13b2_frame_color);
    ULTIMA_1bf2_SetTextPosition(0, 0xf);
    ULTIMA_16ba_PrintChar(0x7b);

    for (local_4 = 0; local_4 < 0x26; local_4++)
    {
        ULTIMA_16ba_PrintChar(0x7f);
    }

    ULTIMA_16ba_PrintChar(0x7c);

    for (local_4 = 0; local_4 < 8; local_4++)
    {
        ULTIMA_16ba_PrintChar(0x7f);
        ULTIMA_1bf2_SetTextPosition(0x27, ULTIMA_1cee_GetCurrentTextY());
        ULTIMA_16ba_PrintChar(0x7f);
    }

    ULTIMA_16ba_PrintChar(0x7d);

    for (local_4 = 0; local_4 < 0x26; local_4++)
    {
        ULTIMA_16ba_PrintChar(0x7f);
    }

    D_538e = 0;
    ULTIMA_16ba_PrintChar(0x7e);
    D_538e = 1;
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(7, 127, 312, 127);
    ULTIMA_0f90_GRAP_Pen(312, 192);
    ULTIMA_0f90_GRAP_Pen(7, 192);
    ULTIMA_0f90_GRAP_Pen(7, 127);
    ULTIMA_1cca_SetTextForegroundColor(D_13b0_white_color);
}

// OK P1
static void INTRO_05b0_DisplayTitle(int param_1) // (0 for fast display)
{
    byte* local_4;
    int local_6; // unused

    D_a9bd[1] = 2;
    if (D_5893_map_id != 0x40)
    {
        ULTIMA_102e_UnloadTileset();
        D_5893_map_id = 0x40;
    }
    do
    {
        D_bb1a = ULTIMA_0bae_LoadImageFile(D_25f0[23]); // "ULTIMA.16"
    } while (D_bb1a == 0);
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_0d4c_GRAP_4b_PutImage(D_bb1a, 0, 0, 0, 0);
    if (param_1 != 0)
    {
        // "ULTIMA" with sound
        ULTIMA_0f46_GRAP_66_Reveal(0, 0, 319, 100);
        param_1 = ULTIMA_1d5e_PollKey() == 0;
    }
    if (param_1 == 0)
    {
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0, 0, 319, 100);
    }
    INTRO_0010();
    ULTIMA_0be4_FreeImage(D_bb1a);
    if (param_1 != 0)
    {
        do
        {
            local_4 = ULTIMA_0fae_LoadResourceFile("WD.BIT");
        } while (local_4 == 0);
        // "warriors of destiny" with sound
        INTRO_20ae_ShowWD(local_4);
        ULTIMA_0fdc_FreeBitImage(local_4);
    }
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    INTRO_2090_AnimateWD();
    D_a9bd[1] = 0;
    INTRO_04e0_DrawMenuBorders();
}

// OK P1
static void INTRO_0676_WriteMenuOption(int param_4, int param_3, int param_2, char* param_1)
{
    if (param_3 == param_4)
    {
        ULTIMA_16ba_PrintChar(0xfd);
    }

    ULTIMA_1bf2_SetTextPosition(param_2, param_3 + 0x11);
    ULTIMA_16ba_PrintChar(0x20);
    ULTIMA_1850_PrintString(param_1);
    ULTIMA_16ba_PrintChar(0x20);

    if (param_3 == param_4)
    {
        ULTIMA_16ba_PrintChar(0xfd);
    }
}

// OK P1
static void INTRO_06bc_BuildMainMenu(int param_1)
{
    INTRO_0676_WriteMenuOption(param_1, 0, 0xc, /*0x310c*/ "Journey Onward");
    INTRO_0676_WriteMenuOption(param_1, 1, 9, /*0x311b*/ "Create New Character");
    INTRO_0676_WriteMenuOption(param_1, 2, 8, /*0x3130*/ "Transfer from Ultima IV");
    INTRO_0676_WriteMenuOption(param_1, 3, 9, /*0x3148*/ "Ultima V Introduction");
    INTRO_0676_WriteMenuOption(param_1, 4, 0xb, /*0x315e*/ "Acknowledgements");
    INTRO_0676_WriteMenuOption(param_1, 5, 10, /*0x316f*/ "Return to the View");
}

// OK P1
static void INTRO_072e_Acknowledgements(void)
{
    void* local_4;
    int local_6;

    do
    {
        local_4 = ULTIMA_0bae_LoadImageFile(D_25ea[27]); // "STARTSC.16"
    } while (local_4 == 0);

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 1, 0x10, 0x3f, 0);
    ULTIMA_0c22_GRAP_0f_SelectPage(0);

    for (local_6 = 199; local_6 >= 0x3f; local_6--)
    {
        ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 0, 0x90, local_6, 0); // (image_buffer, image_idx, x, y, ?)
        ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 2, 0xa0, local_6, 0);

#if !defined(TARGET_DOS16)
        TIME_SleepMs((199 - local_6) / 16);
#endif
    }

    for (local_6 = 0; local_6 < 0x90; local_6 += 8)
    {
        ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 0, 0x88 - local_6, 0x3f, 0);
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0x98 - local_6, 0x3f, 0x9f - local_6, 199);
        ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 2, local_6 + 0xa8, 0x3f, 0);
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, local_6 + 0xa0, 0x3f, local_6 + 0xa7, 199);
        ULTIMA_20fa_WaitTicks(1);
    }

    do
    {
        D_bb1a = ULTIMA_0bae_LoadImageFile(D_25ea[26]); // "ULTIMA.16"
    } while (D_bb1a == 0);

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_0d4c_GRAP_4b_PutImage(D_bb1a, 1, 0x10, 0x41, 0);
    ULTIMA_0be4_FreeImage(D_bb1a);
    INTRO_04e0_DrawMenuBorders();
    INTRO_06bc_BuildMainMenu(4);

    while (ULTIMA_1d5e_PollKey() == 0)
    {
    }

    ULTIMA_0c22_GRAP_0f_SelectPage(0);

    for (local_6 = 0x88; local_6 >= 0; local_6 -= 8)
    {
        ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 0, 0x90 - local_6, 0x3f, 0);
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0x88 - local_6, 0x3f, 0x8f - local_6, 199);
        ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 2, local_6 + 0xa0, 0x3f, 0);
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, local_6 + 0xb0, 0x3f, local_6 + 0xb7, 199);
        ULTIMA_20fa_WaitTicks(1);
    }

    ULTIMA_0be4_FreeImage(local_4);

    for (local_6 = 0x3f; local_6 < 199; local_6++)
    {
        ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 0, 0x90, local_6 + 1, 0);
        ULTIMA_0d4c_GRAP_4b_PutImage(local_4, 2, 0xa0, local_6 + 1, 0);
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0x90, local_6, 0xaf, local_6);

#if !defined(TARGET_DOS16)
        TIME_SleepMs((199 - local_6) / 16);
#endif
    }

    ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0x90, 199, 0xaf, 199);
    INTRO_0010();
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    ULTIMA_1b16_ClearKbdBuffer();
}

// OK P1
// pause(wait time) (8b0e)
static int INTRO_094e_Pause(int param_1)
{
    int local_4;
    int local_6;

    local_4 = 0;

    for (local_6 = 0; local_6 < param_1; local_6++)
    {
        if ((local_4 = ULTIMA_1d5e_PollKey()) != 0)
            break;

        ULTIMA_20fa_WaitTicks(1);
    }

    return local_4;
}

// CHECKED
void INTRO_0986_Main(void) // intro_main (initialize video) (8b46)
{
    int local_4;
    char* local_6;
    int local_8;
    int local_a;
    int local_c;
    int local_e;
    byte local_10;
    byte* local_12;
    byte* local_14;

    // 098e
    D_a9ce = 1;
    local_e = 0;

    // 0995
    for (local_e = 0; local_e < 0x100; local_e++)
    {
        D_b11e[local_e] = (char)local_e;
    }

    ULTIMA_0de0_DetectVideo();
    ULTIMA_1158_InitTimer();
    local_8 = D_5356;

    // force cga if low memory
    if (D_52ba_vdp._52c8_videoDriverSelection == 2 && D_5358 < 0x170)
    {
        D_52f1_forceTandy = 0;
        D_52ba_vdp._52ba_forceCga = 1;
        D_52ba_vdp._52c8_videoDriverSelection = 0;
    }

    // 09d2
    while (ULTIMA_0e94_LoadVideoDriver() == 0)
    {
    }

    ULTIMA_0892_InitializeVideoDriver(1);

    if (D_52ba_vdp._52c8_videoDriverSelection != 0 && D_52ba_vdp._52c8_videoDriverSelection != 3)
    {
        D_13b2_frame_color = 1;
        D_13ae = 4;
        D_13b0_white_color = 0xf;
        D_13b6 = 5;
        D_13b4 = 2;
        D_13b8 = 0xe;
        D_13ba = 7;
    }
    else
    {
        // 0a1a
        local_e = 0;

        // cga / herc: *.16 -> *.4
        while (*(local_6 = D_25ea[local_e++]) != 0) // 0a35
        {
            // 0a22
            while (*local_6++ != '.')
            {
            }

            if (*local_6 == '1')
            {
                *local_6++ = '4';
                *local_6 = '\0';
            }
        }
    }

    // 0a49
    if (ULTIMA_0f2a_GRAP_06_AllocPageBuffer() == 0)
    {
        ULTIMA_0878_RestoreVideoMode();
        exit(1);
    }
    if (D_52ba_vdp._52c8_videoDriverSelection == 3)
    {
        // 0a64
        while (ULTIMA_1d02_LoadCharset(/*0x3182*/ "ibm.hcs", 0) == 0)
        {
        }
        while (ULTIMA_1d02_LoadCharset(/*0x318a*/ "runes.hcs", 1) == 0)
        {
        }
    }
    else
    {
        // 0a84
        while (ULTIMA_1d02_LoadCharset(/*0x3194*/ "ibm.ch", 0) == 0)
        {
        }
        while (ULTIMA_1d02_LoadCharset(/*0x319b*/ "runes.ch", 1) == 0)
        {
        }
    }

    // 0aa1
    ULTIMA_1c9e_SelectCharset(0);
    ULTIMA_1c22_SetTextWindowSize(0, 0, 0, 0x27, 0x18);
    ULTIMA_1b94_SelectTextWindow(0);
    local_a = ULTIMA_2032_ToUpper(ULTIMA_1d5e_PollKey());
    if (local_a == 0x4a) // 'J'
    {
        ULTIMA_16ba_PrintChar(0xff);
        ULTIMA_16ba_PrintChar(0xfc);
        ULTIMA_1bf2_SetTextPosition(0, 0xb);
        ULTIMA_1850_PrintString(/*0x31a4*/ "Journey Onward\n\n");
        ULTIMA_16ba_PrintChar(0xfb);
        // 0af2
        while (ULTIMA_0ff4_LoadTileset(D_25f0[0]) == 0)
        {
        }
        D_5893_map_id = 0x41;
        // -> 0cc9
    }
    else
    {
        // 0b06
        local_a = 1;

        do
        {
            local_12 = ULTIMA_0fae_LoadResourceFile(D_25ea[2]); // "TITLE.BIT"
        } while (local_12 == 0);

        do
        {
            local_14 = ULTIMA_0fae_LoadResourceFile(D_25ea[1]); // "BRITISH.BIT"
        } while (local_14 == 0);

#if !defined(TARGET_DOS16)
        // TODO
        g_british = malloc(3000);
        ULTIMA_256e_ReadFileFromDisk(/*0x31b5*/ "BRITISH.PTH", g_british, 3000, 0);
#else
        ULTIMA_256e_ReadFileFromDisk(/*0x31b5*/ "BRITISH.PTH", &D_55a6, ((int)&D_6606 - (int)&D_55a6) /*0x1060*/, 0);
#endif
        // "origin systems inc."
        if (local_a != 0)
            local_a = ULTIMA_0d72_AnimateOriginLogo(local_12) == 0;

        // 0b56
        // "presents"
        ULTIMA_0c22_GRAP_0f_SelectPage(1);
        ULTIMA_0aa6_GRAP_3f_FillRect(0, 0x8c, 0x13f, 199);
        ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(local_12, 7, 0x6c, 0x8c);
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0, 0x8c, 0x13f, 199);
        if (local_a != 0)
        {
            ULTIMA_20fa_WaitTicks(0x12);
            local_a = INTRO_094e_Pause(0x14) == 0;
        }
        // 0bb6
        if (local_a != 0)
        {
            // 0bbf
            ULTIMA_16ba_PrintChar(0xff);
            // "a"
            ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(local_12, 0x8, 0x98, 0);
            ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);
            local_a = INTRO_094e_Pause(0x14) == 0;
            if (local_a != 0)
            {
                ULTIMA_0c22_GRAP_0f_SelectPage(0);
                D_bb18 = 0;
                local_a = 0;
                // "lord british" animation
                if ((INTRO_0050(0x2c, 0x44) != 0) && (INTRO_0050(0x40, 0x5e) != 0) && (INTRO_0050(0x8f, 0x4e) != 0))
                {
                    local_a = INTRO_0050(0xa7, 0x69);
                }
                // 0c42
                ULTIMA_0c22_GRAP_0f_SelectPage(1);
            }
            // 0c49
            // "lord british"
            ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(local_14, 0, 0x18, 0x42);
            ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);
            // "production"
            ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(local_12, 9, 0x68, 0xa0);
            ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);
            if (local_a != 0)
            {
                local_a = INTRO_094e_Pause(0x14) == 0;
            }
        }

#if !defined(TARGET_DOS16)
        free(g_british);
        g_british = 0;
#endif

        // 0c97
        ULTIMA_0fdc_FreeBitImage(local_14);
        ULTIMA_0fdc_FreeBitImage(local_12);

        D_5893_map_id = 0x40;
        ULTIMA_16ba_PrintChar(0xff);
        ULTIMA_0c22_GRAP_0f_SelectPage(0);
        INTRO_05b0_DisplayTitle(local_a);
        if (local_a != 0)
        {
#if !defined(TARGET_DOS16)
            AUDIO_PlayBgm(BGM_ID_1);
#endif

            FONT_04a4();
        }
        // 0cc4
        local_a = 1;
    }

    ULTIMA_207e_srand(ULTIMA_2056_GetTime());

    // 0cd0
    do
    {
#if !defined(TARGET_DOS16)
        AUDIO_PlayBgm(BGM_ID_1);
#endif

        ULTIMA_1c22_SetTextWindowSize(0, 1, 0x10, 0x26, 0x17);
        ULTIMA_1b94_SelectTextWindow(0);
        ULTIMA_16ba_PrintChar(0xff);
        ULTIMA_1c22_SetTextWindowSize(0, 0, 0, 0x27, 0x18);
        ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x27, 9);
        ULTIMA_1c22_SetTextWindowSize(2, 0x18, 0xb, 0x27, 0x17);
        if (local_a == 0x4a) // 'J'
        {
            local_10 = 0x4a; // 'J'
        }
        else
        {
            // OK P1
            // 0d3e
            local_c = 0;
            INTRO_043e(/*0x31c1*/ "Copyright 1988 Lord British");
            INTRO_06bc_BuildMainMenu(0);
            do
            {
                // 0d4d
                ULTIMA_1bf2_SetTextPosition(0xf, 0xf);
                ULTIMA_4c2a();
                ULTIMA_1850_PrintString(/*0x31dd*/ "Select: ");
                ULTIMA_4cce();
                ULTIMA_1bf2_SetTextPosition(0x17, 0xf);
                D_5356 = 0x113;
                local_4 = 0;
                do
                {
                    // 0d75
                    local_10 = ULTIMA_2032_ToUpper(ULTIMA_1b38_PollKeyWithCursor());
                    if (local_10 == 0)
                    {
                        INTRO_2090_AnimateWD();
                    }
                    // 0d86
                    local_4++;
                } while (local_4 < 200 && local_10 == 0);
                D_5356 = local_8;
                // OK P1!
                switch (local_10)
                {
                case 1: // up?
                case 3: // left?
                    local_c--;
                    if (local_c < 0)
                    {
                        local_c = 5;
                    }
                    INTRO_06bc_BuildMainMenu(local_c);
                    break;
                case 2: // down?
                case 4: // right?
                    local_c++;
                    if (5 < local_c)
                    {
                        local_c = 0;
                    }
                    INTRO_06bc_BuildMainMenu(local_c);
                    break;
                case 0xd:  // CR
                case 0x20: // ' '
                    // 0de2
                    local_10 = /*0x3270*/ "JCTUAR"[local_c];
                    break;
                case 0:
                    local_10 = 0x52;
                    break;
                case 0x4a: // 'J'
                    INTRO_06bc_BuildMainMenu(0);
                    break;
                case 0x43: // 'C'
                    INTRO_06bc_BuildMainMenu(1);
                    break;
                case 0x54: // 'T'
                    INTRO_06bc_BuildMainMenu(2);
                    break;
                case 0x55: // 'U'
                    INTRO_06bc_BuildMainMenu(3);
                    break;
                case 0x41: // 'A'
                    INTRO_06bc_BuildMainMenu(4);
                    break;
                case 0x52: // 'R'
                    INTRO_06bc_BuildMainMenu(5);
                    break;
                default:
                    local_10 = 0;
                    break;
                }
            } while (local_10 <= 0x20);
        }

        // 0e47
        switch ((int)local_10)
        {
        case 0x4a: // 'J'
#if !defined(TARGET_DOS16)
            AUDIO_StopBgm();
#endif

            // 0e7c
            ULTIMA_637e_DrawFrame();
            ULTIMA_2e96_SetWindDirection(0);
            ULTIMA_1b94_SelectTextWindow(2);
            ULTIMA_1bf2_SetTextPosition(0, 0xc);
            if (D_5893_map_id == 0x40)
            {
                while (ULTIMA_0ff4_LoadTileset(D_25f0[0]) == 0)
                {
                }
                D_5893_map_id = 0x41;
            }
            // 0ead
            ULTIMA_251e_SwitchDisks(3);
#if !defined(TARGET_DOS16)
            FILE_ReadSavegameFile(/*0x31e6*/ "SAVED.GAM");
#else
            ULTIMA_256e_ReadFileFromDisk(/*0x31e6*/ "SAVED.GAM", &D_55a6, ((int)&D_6606 - (int)&D_55a6) /*0x1060*/, 0);
#endif
            if (D_55a8_party[0].name[0] == '\0')
            {
                ULTIMA_1850_PrintString(/*0x31f0*/ "\n\nNo active game. ");
                ULTIMA_1850_PrintString(/*0x3203*/ "Please create a character ");
                ULTIMA_1850_PrintString(/*0x321e*/ "or transfer one from Ultima IV. ");
                ULTIMA_1dda_WaitForKeystroke(0);
                D_a9cb = 0xff;
                ULTIMA_251e_SwitchDisks(0);
                ULTIMA_1b94_SelectTextWindow(0);
                ULTIMA_16ba_PrintChar(0xff);
                ULTIMA_0c22_GRAP_0f_SelectPage(1);
                ULTIMA_16ba_PrintChar(0xff);
                ULTIMA_0c22_GRAP_0f_SelectPage(0);
                INTRO_05b0_DisplayTitle(0);
                local_a = 0;
            }
            else
            {
                // 0f26
                ULTIMA_256e_ReadFileFromDisk(/*0x323f*/ "SAVED.OOL", D_b21e, 0x200, 0);
                ULTIMA_251e_SwitchDisks(1);
                ULTIMA_25d8_WriteFileToDisk(/*0x3249*/ "BRIT.OOL", D_b21e, 0x100);
                ULTIMA_25d8_WriteFileToDisk(/*0x3252*/ "UNDER.OOL", D_b31e, 0x100);
                if ((D_5893_map_id == 0) && (D_5895_map_level != 0))
                {
                    ULTIMA_251e_SwitchDisks(5);
                    while (ULTIMA_1674_TestOpenFile(/*0x325c*/ "UNDER.DAT") == 0)
                    {
                    }
                    ULTIMA_25d8_WriteFileToDisk(/*0x3266*/ "UNDER.OOL", D_b31e, 0x100);
                }
                ULTIMA_2e96_SetWindDirection(-1);
                D_52ba_vdp._52be = 8;
                return;
            }
            break;

        case 0x54: // 'T'
#if !defined(TARGET_DOS16)
            AUDIO_StopBgm();
#endif

            ULTIMA_16ba_PrintChar(0xff);
            INTRO_132a_TransferFromU4();
            goto L_0fab; // TODO: get rid of goto
            // break;

        case 0x43: // 'C'
#if !defined(TARGET_DOS16)
            AUDIO_StopBgm();
#endif

            // 0fa8
            FONT_0b0a();
        L_0fab:
            ULTIMA_1c22_SetTextWindowSize(0, 0, 0, 0x27, 0x18);
            ULTIMA_1b94_SelectTextWindow(0);
            ULTIMA_16ba_PrintChar(0xff);
            ULTIMA_0c22_GRAP_0f_SelectPage(1);
            ULTIMA_16ba_PrintChar(0xff);
            INTRO_05b0_DisplayTitle(0);
            INTRO_0010();
            ULTIMA_0c22_GRAP_0f_SelectPage(0);
            break;

        case 0x55: // 'U'
#if !defined(TARGET_DOS16)
            AUDIO_StopBgm();
#endif

            INTRO_014e_Introduction();
            INTRO_05b0_DisplayTitle(0);
            break;

        case 0x41: // 'A'
#if !defined(TARGET_DOS16)
            AUDIO_StopBgm();
#endif

            // 0ff4
            if (D_5893_map_id != 0x40)
            {
                ULTIMA_102e_UnloadTileset();
                D_5893_map_id = 0x40;
            }
            INTRO_072e_Acknowledgements();
            break;

        case 0x52:       // 'R'
            FONT_04a4(); // thunk
            break;
        }
    } while (1);
}

// CHECKED
static int INTRO_1016_ConvertU4Savegame(void)
{
    bool local_4;
    int local_e;
    int local_a;
    S_bc88_U4Party* local_8;
    S_55a8* local_6;
    S_bb1c* local_c;
    int local_10;

    local_4 = 0;
    local_8 = &D_bc88;
    local_a = 0;
    local_10 = 8;

    D_a9bd[1] = 1;
    D_a9bd[0] = 4;

    D_a9cc = ULTIMA_16a6_GetDefaultDrive(); // NOT MATCHING

    ULTIMA_256e_ReadFileFromDisk(/*0x3278*/ "party.sav", &D_bc88, 0x28, local_10);

    if (D_bc88.str > 0x46 || D_bc88.dex > 0x46 || D_bc88.intel > 0x46 || D_bc88.exp > 9999 || D_bc88.hp > 9999 ||
        D_bc88.maxHp > 9999 || D_bc88.cls > 7)
    {
        local_4 = 1;
    }

    for (local_e = 0; local_e < 8; local_e++)
    {
        if (local_8->name[local_e] != 0 && local_8->name[local_e] < 0x20)
        {
            local_4 = 1;
            break;
        }

        // 92b6
        if (local_8->name == 0) // bug?
        {
            break;
        }
    }

    if (local_4)
    {
        ULTIMA_16ba_PrintChar(0xff);
        ULTIMA_16ba_PrintChar(0xfc);
        ULTIMA_1bf2_SetTextPosition(0, 5);
        ULTIMA_1850_PrintString(/*0x3282*/ "Error:  Your Ultima IV game\n\ncontains bad data.\n\n");
        ULTIMA_1850_PrintString(/*0x32b4*/ "Unable to continue transfer.\n\n\n");
        ULTIMA_1850_PrintString(/*0x32d4*/ "Press any key to return to the menu.");
        ULTIMA_16ba_PrintChar(0xfb);
        ULTIMA_1dda_WaitForKeystroke(0);
        return 1;
    }

    local_6 = &D_55a8_party[local_a];

    for (local_e = 0; local_e < 8; local_e++)
    {
        if (local_8->name[local_e] != 0)
        {
            local_6->name[local_e] = local_8->name[local_e];
        }
        else
        {
            break;
        }
    }

    local_6->name[local_e] = 0;

    if (local_8->gender == 11)
    {
        local_6->gender = 0xb;
    }
    else
    {
        local_6->gender = 0xc;
    }

    switch (local_8->cls)
    {
    case 0:
        local_6->profession = 0x4d;
        break;
    case 1:
        local_6->profession = 0x42;
        break;
    case 2:
        local_6->profession = 0x46;
        break;
    case 3:
        local_6->profession = 0x44;
        break;
    case 4:
        local_6->profession = 0x54;
        break;
    case 5:
        local_6->profession = 0x50;
        break;
    case 6:
        local_6->profession = 0x52;
        break;
    case 7:
        local_6->profession = 0x53;
    }

    local_6->status = STATUS_GOOD;
    local_6->str = local_8->str;
    local_6->dex = local_8->dex;
    local_6->intel = local_8->intel;
    local_6->mag = local_8->mag;
    local_6->hp = local_8->hp;
    local_6->maxHp = local_8->maxHp;
    local_6->exp = local_8->exp;

    local_6->level = local_8->maxHp / 100;

    local_10 = 0x140;
    local_c = &D_bb1c;

    ULTIMA_256e_ReadFileFromDisk(/*0x32f9*/ "party.sav", &D_bb1c, 0xb6, 0x140);

    if (D_bb1c._6 == 0 && D_bb1c._8 == 0 && D_bb1c._a == 0 && D_bb1c._c == 0 && D_bb1c._e == 0 && D_bb1c._10 == 0 &&
        D_bb1c._12 == 0 && D_bb1c._14 == 0)
    {
        D_3304 = 1;
    }

    return 0;
}

// OK P1
static void INTRO_1278_PrintU4Class(void)
{
    switch (D_55a8_party[0].profession)
    {
    case 0x4d:
        ULTIMA_1850_PrintString(/*0x3306*/ "Mage\n");
        break;
    case 0x42:
        ULTIMA_1850_PrintString(/*0x330c*/ "Bard\n");
        break;
    case 0x46:
        ULTIMA_1850_PrintString(/*0x3312*/ "Fighter\n");
        break;
    case 0x44:
        ULTIMA_1850_PrintString(/*0x331b*/ "Druid\n");
        break;
    case 0x54:
        ULTIMA_1850_PrintString(/*0x3322*/ "Tinker\n");
        break;
    case 0x50:
        ULTIMA_1850_PrintString(/*0x332a*/ "Paladin\n");
        break;
    case 0x52:
        ULTIMA_1850_PrintString(/*0x3333*/ "Ranger\n");
        break;
    case 0x53:
        ULTIMA_1850_PrintString(/*0x333b*/ "Shepherd\n");
        break;
    }
}

// OK P1
static int INTRO_12ea(int param_1)
{
    if (param_1 < 10)
    {
        return param_1;
    }

    if (param_1 >= 30)
    {
        return (param_1 - 30) / 4 + 20;
    }
    else
    {
        return (param_1 - 9) / 2 + 10;
    }
}

// CHECKED
static void INTRO_132a_TransferFromU4(void)
{
    int local_14;
    int local_e;
    byte cVar4;
    byte bVar5;
    byte uVar6;
    int iVar7;
    int uVar8;
    byte local_12;

#if defined(GOG_BUILD)
    // GOG patched (1332..134c)
    local_e = D_5893_map_id == 66 ? 65 : D_5893_map_id;
    D_a9cc = D_a9cb = D_a9c8[0];
#else
    // MATCHING (1.16)
    if (D_5893_map_id == 66)
    {
        D_5893_map_id = 65;
    }

    local_e = D_5893_map_id;

    D_a9cb = D_a9cc = 0xff;
#endif

#if !defined(TARGET_DOS16)
    FILE_ReadSavegameFile(/*0x3345*/ "INIT.GAM");
#else
    ULTIMA_256e_ReadFileFromDisk(/*0x3345*/ "INIT.GAM", &D_55a6, ((byte*)&D_6606 - (byte*)&D_55a6), 0);
#endif
    ULTIMA_256e_ReadFileFromDisk(/*0x334e*/ "INIT.OOL", D_b31e, 0x100, 0);
    ULTIMA_1c22_SetTextWindowSize(0, 0, 0, 0x27, 0x18);

    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_16ba_PrintChar(0xff);

#if defined(GOG_BUILD)
    // GOG patched (1392..1399)
    local_12 = D_a9c8[0];
    goto L_GOG_1402;
#endif

    ULTIMA_1bf2_SetTextPosition(4, 0xc);
    ULTIMA_1850_PrintString(/*0x3357*/ "Transfer Character from Ultima IV");
    ULTIMA_1bf2_SetTextPosition(0, 0xf);
    ULTIMA_1850_PrintString(/*0x3379*/ "Please insert the Ultima IV Player Disk");
    ULTIMA_1bf2_SetTextPosition(8, 0x10);
    ULTIMA_1850_PrintString(/*0x33a1*/ "and press drive letter");
    ULTIMA_1bf2_SetTextPosition(3, 0x12);
    ULTIMA_1850_PrintString(/*0x33b8*/ "or press <Esc> to abort transfer");

    D_5394_fn = ULTIMA_2320_NoDiskSwapMessage;

    do
    {
        local_12 = ULTIMA_2032_ToUpper(ULTIMA_1dda_WaitForKeystroke(0));
        if (local_12 == 0x1b)
        {
            D_5893_map_id = local_e;
            return;
        }
#if defined(GOG_BUILD)
L_GOG_1402:
        ;
#endif
    } while (ULTIMA_1eac_SetDefaultDrive(local_12) == 0);

    D_5394_fn = ULTIMA_2322_DiskSwapMessage;

    if (INTRO_1016_ConvertU4Savegame() != 0)
    {
        D_5893_map_id = local_e;
        return;
    }

    if (D_3304 != 0)
    {
        D_55a8_party[0].profession = 0x41;
    }

    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1bf2_SetTextPosition(0, 0xb);
    ULTIMA_16ba_PrintChar(0xfc);
    ULTIMA_1850_PrintString(/*0x33d9*/ "Found:\n");
    ULTIMA_1bf2_SetTextPosition(0, 0xc);
    ULTIMA_1850_PrintString(D_55a8_party[0].name);
    ULTIMA_16ba_PrintChar(0xfb);
    ULTIMA_1bf2_SetTextPosition(0xc, 0xd);
    ULTIMA_1850_PrintString(/*0x33e1*/ "a level ");
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].level, 1, 0x20);

    if (D_55a8_party[0].gender == 11)
    {
        ULTIMA_1850_PrintString(/*0x33ea*/ " Male ");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x33f1*/ " Female ");
    }

    INTRO_1278_PrintU4Class();
    ULTIMA_1bf2_SetTextPosition(0x11, 0xf);
    ULTIMA_1850_PrintString(/*0x33fa*/ "STR:  ");
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].str, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(0x11, 0x10);
    ULTIMA_1850_PrintString(/*0x3401*/ "DEX:  ");
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].dex, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(0x11, 0x11);
    ULTIMA_1850_PrintString(/*0x3408*/ "INT:  ");
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].intel, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(10, 0x14);

    ULTIMA_1850_PrintString(D_55a8_party[0].name);
    ULTIMA_1850_PrintString(/*0x340f*/ " is ");
    if (D_3304 != 0)
    {
        ULTIMA_1850_PrintString(/*0x3414*/ "an Avatar.");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x341f*/ "not an Avatar");
    }

    ULTIMA_1dda_WaitForKeystroke(0);
    ULTIMA_16ba_PrintChar(0xff);

    INTRO_2024();

    for (iVar7 = 0; iVar7 < 8; iVar7++)
    {
        INTRO_1e22(iVar7);
    }

    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(0, 3);
    ULTIMA_16ba_PrintChar(0xfc);
    ULTIMA_1850_PrintString(D_55a8_party[0].name);
    ULTIMA_16ba_PrintChar(0xfb);
    ULTIMA_1bf2_SetTextPosition(10, 5);

    if (D_55a8_party[0].gender == 11)
    {
        ULTIMA_1850_PrintString(/*0x342d*/ "Male");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x3432*/ "Female");
    }

    ULTIMA_1bf2_SetTextPosition(10, 6);

    if (D_3304 != 0)
    {
        ULTIMA_1850_PrintString(/*0x3439*/ "Avatar");
    }
    else
    {
        INTRO_1278_PrintU4Class();
    }

    ULTIMA_1bf2_SetTextPosition(10, 8);
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].exp, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(10, 9);
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].level, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(10, 0xb);
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].str, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(10, 0xc);
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].dex, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(10, 0xd);
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].intel, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(0, 0xf);
    ULTIMA_16ba_PrintChar(0xfc);

    if (D_3304 != 0)
    {
        ULTIMA_1850_PrintString(/*0x3440*/ "Avatar");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x3447*/ "Non-Avatar");
    }

    ULTIMA_16ba_PrintChar(0xfb);
    ULTIMA_1bf2_SetTextPosition(7, 2);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x3452*/ "Name:");

    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(7, 2);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x3458*/ "Name:");
    ULTIMA_16ba_PrintChar(0xfd);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1bf2_SetTextPosition(10, 0);
    ULTIMA_1850_PrintString(/*0x345e*/ "Keep this name?");

    do // NOT MATCHING
    {
        cVar4 = ULTIMA_2032_ToUpper(ULTIMA_1dda_WaitForKeystroke(0));
        if (cVar4 == 'Y')
            break;
    } while (cVar4 != 'N');

    ULTIMA_16ba_PrintChar(0xff);

    if (cVar4 == 'N')
    {
        do
        {
            ULTIMA_1bf2_SetTextPosition(1, 0);
            ULTIMA_1850_PrintString(/*0x346e*/ "Enter new name: ");
            ULTIMA_1e38_IntroGetString(D_55a8_party[0].name, 8);
        } while (D_55a8_party[0].name[0] == 0);
    }

    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(0, 3);
    ULTIMA_16ba_PrintChar(0xfc);
    ULTIMA_1850_PrintString(D_55a8_party[0].name);
    ULTIMA_16ba_PrintChar(0xfb);
    ULTIMA_1bf2_SetTextPosition(7, 2);
    ULTIMA_1850_PrintString(/*0x347f*/ "Name:");
    ULTIMA_1bf2_SetTextPosition(5, 5);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x3485*/ "Sex:");
    ULTIMA_16ba_PrintChar(0xfd);

    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(7, 2);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x348a*/ "Name:");
    ULTIMA_1bf2_SetTextPosition(5, 5);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x3490*/ "Sex:");
    ULTIMA_16ba_PrintChar(0xfd);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_16ba_PrintChar(0xfc);
    ULTIMA_1850_PrintString(/*0x3495*/ "Keep same sex?");
    ULTIMA_16ba_PrintChar(0xfb);

    do // NOT MATCHING
    {
        cVar4 = ULTIMA_2032_ToUpper(ULTIMA_1dda_WaitForKeystroke(0));
        if (cVar4 == 'Y')
            break;
    } while (cVar4 != 'N');

    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(10, 5);

    if ((cVar4 == 'Y' && D_55a8_party[0].gender == 11) || (cVar4 == 'N' && D_55a8_party[0].gender == 12))
    {
        ULTIMA_1850_PrintString(/*0x34a4*/ "Male");
        D_55a8_party[0].gender = 0xb;
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x34a9*/ "Female");
        D_55a8_party[0].gender = 0xc;
    }

    ULTIMA_1bf2_SetTextPosition(5, 5);
    ULTIMA_1850_PrintString(/*0x34b0*/ "Sex:");
    ULTIMA_1bf2_SetTextPosition(3, 6);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x34b5*/ "Class:");
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1bf2_SetTextPosition(10, 6);
    if (D_3304 != 0)
    {
        ULTIMA_1850_PrintString(/*0x34bc*/ "Avatar");
    }
    else
    {
        INTRO_1278_PrintU4Class();
    }

    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(5, 5);
    ULTIMA_1850_PrintString(/*0x34c3*/ "Sex:");
    ULTIMA_1bf2_SetTextPosition(3, 6);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x34c8*/ "Class:");
    ULTIMA_16ba_PrintChar(0xfd);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1bf2_SetTextPosition(2, 0);
    if (D_3304 != 0)
    {
        ULTIMA_1850_PrintString(/*0x34cf*/ "Thou art now an Avatar:");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x34e7*/ "Class remains intact");
    }
    ULTIMA_1dda_WaitForKeystroke(0);

    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(3, 6);
    ULTIMA_1850_PrintString(/*0x34fc*/ "Class:");
    ULTIMA_1bf2_SetTextPosition(5, 8);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x3503*/ "Exp:");
    ULTIMA_16ba_PrintChar(0xfd);

    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(3, 6);
    ULTIMA_1850_PrintString(/*0x3508*/ "Class:");
    ULTIMA_1bf2_SetTextPosition(5, 8);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x350f*/ "Exp:");
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1bf2_SetTextPosition(10, 8);
    D_55a8_party[0].exp /= 10;
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].exp, 1, 0x20);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_16ba_PrintChar(0xfc);
    ULTIMA_1850_PrintString(/*0x3514*/ "Experience has been converted");
    ULTIMA_16ba_PrintChar(0xfb);
    ULTIMA_1dda_WaitForKeystroke(0);

    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(5, 8);
    ULTIMA_1850_PrintString(/*0x3532*/ "Exp:");
    ULTIMA_1bf2_SetTextPosition(3, 9);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x3537*/ "Level:");
    ULTIMA_16ba_PrintChar(0xfd);

    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(5, 8);
    ULTIMA_1850_PrintString(/*0x353e*/ "Exp:");
    ULTIMA_1bf2_SetTextPosition(3, 9);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x3543*/ "Level:");
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1bf2_SetTextPosition(10, 9);
    D_55a8_party[0].level = 1;
    for (iVar7 = D_55a8_party[0].exp / 100; iVar7 > 0; iVar7 >>= 1)
    {
        D_55a8_party[0].level++;
    }

    D_55a8_party[0].hp = D_55a8_party[0].maxHp = D_55a8_party[0].level * 0x1e;
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].level, 1, 0x20);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_16ba_PrintChar(0xfc);
    ULTIMA_1850_PrintString(/*0x354a*/ "Level has been converted");
    ULTIMA_16ba_PrintChar(0xfb);
    ULTIMA_1dda_WaitForKeystroke(0);

    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(3, 9);
    ULTIMA_1850_PrintString(/*0x3563*/ "Level:");
    ULTIMA_1bf2_SetTextPosition(5, 0xb);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x356a*/ "STR:");
    ULTIMA_16ba_PrintChar(0xfd);

    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(3, 9);
    ULTIMA_1850_PrintString(/*0x356f*/ "Level:");
    ULTIMA_1bf2_SetTextPosition(5, 0xb);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x3576*/ "STR:");
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1bf2_SetTextPosition(10, 0xb);
    local_14 = D_55a8_party[0].str;
    D_55a8_party[0].str = INTRO_12ea(local_14);
    if (D_55a8_party[0].str < 0x14)
    {
        D_55a8_party[0].str = 0x14;
    }
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].str, 1, 0x20);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1bf2_SetTextPosition(1, 0);
    ULTIMA_1850_PrintString(/*0x357b*/ "Strength: was ");
    ULTIMA_1a3e_PrintNumber(local_14, 1, 0x20);
    ULTIMA_1850_PrintString(/*0x358a*/ "(50), now ");
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].str, 1, 0x20);
    ULTIMA_1850_PrintString(/*0x3595*/ "(30)");
    ULTIMA_1dda_WaitForKeystroke(0);

    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(5, 0xb);
    ULTIMA_1850_PrintString(/*0x359a*/ "STR:");
    ULTIMA_1bf2_SetTextPosition(5, 0xc);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x359f*/ "DEX:");
    ULTIMA_16ba_PrintChar(0xfd);

    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(5, 0xb);
    ULTIMA_1850_PrintString(/*0x35a4*/ "STR:");
    ULTIMA_1bf2_SetTextPosition(5, 0xc);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x35a9*/ "DEX:");
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1bf2_SetTextPosition(10, 0xc);
    local_14 = D_55a8_party[0].dex;
    D_55a8_party[0].dex = INTRO_12ea(local_14);
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].dex, 1, 0x20);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1bf2_SetTextPosition(1, 0);
    ULTIMA_1850_PrintString(/*0x35ae*/ "Dexterity: was ");
    ULTIMA_1a3e_PrintNumber(local_14, 1, 0x20);
    ULTIMA_1850_PrintString(/*0x35be*/ "(50), now ");
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].dex, 1, 0x20);
    ULTIMA_1850_PrintString(/*0x35c9*/ "(30)");
    ULTIMA_1dda_WaitForKeystroke(0);

    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(5, 0xc);
    ULTIMA_1850_PrintString(/*0x35ce*/ "DEX:");
    ULTIMA_1bf2_SetTextPosition(5, 0xd);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x35d3*/ "INT:");
    ULTIMA_16ba_PrintChar(0xfd);

    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(5, 0xc);
    ULTIMA_1850_PrintString(/*0x35d8*/ "DEX:");
    ULTIMA_1bf2_SetTextPosition(5, 0xd);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x35dd*/ "INT:");
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1bf2_SetTextPosition(10, 0xd);

    local_14 = D_55a8_party[0].intel;
    D_55a8_party[0].mag = D_55a8_party[0].intel = INTRO_12ea(local_14);
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].mag, 1, 0x20);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1bf2_SetTextPosition(1, 0);
    ULTIMA_1850_PrintString(/*0x35e2*/ "Intellect: was ");
    ULTIMA_1a3e_PrintNumber(local_14, 1, 0x20);
    ULTIMA_1850_PrintString(/*0x35f2*/ "(50), now ");
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0].intel, 1, 0x20);
    ULTIMA_1850_PrintString(/*0x35fd*/ "(30)");
    ULTIMA_1dda_WaitForKeystroke(0);

    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(5, 0xd);
    ULTIMA_1850_PrintString(/*0x3602*/ "INT:");

    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(5, 0xd);
    ULTIMA_1850_PrintString(/*0x3607*/ "INT:");
    ULTIMA_1bf2_SetTextPosition(0, 0xf);
    ULTIMA_16ba_PrintChar(0xfc);
    if (D_3304 != 0)
    {
        ULTIMA_1850_PrintString(/*0x360c*/ "Avatar");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x3613*/ "Non-Avatar");
    }
    ULTIMA_16ba_PrintChar(0xfb);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_1c22_SetTextWindowSize(2, 2, 0x15, 0x25, 0x16);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_251e_SwitchDisks(3);
    ULTIMA_1850_PrintString(/*0x361e*/ "\n\n Conversion complete, saving...\n");

    memset(D_b21e, 0, 0x100);

    ULTIMA_25d8_WriteFileToDisk(/*0x3641*/ "SAVED.OOL", D_b21e, 0x200);
#if !defined(TARGET_DOS16)
    FILE_WriteSavegameFile(/*0x364b*/ "SAVED.GAM");
#else
    ULTIMA_25d8_WriteFileToDisk(/*0x364b*/ "SAVED.GAM", &D_55a6, ((byte*)&D_6606 - (byte*)&D_55a6));
#endif
    ULTIMA_251e_SwitchDisks(0);

    D_5893_map_id = local_e;
    D_a9bd[1] = 0;
}

// OK P1
static void INTRO_1e22(int param_1)
{
    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(3, D_3656[param_1]);
    ULTIMA_1850_PrintString(D_3666[param_1]);
    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(3, D_3656[param_1]);
    ULTIMA_1850_PrintString(D_3666[param_1]);
}

// OK P1
static void INTRO_1e62(void)
{
    int local_4;

    ULTIMA_1cca_SetTextForegroundColor(D_13b2_frame_color);

    ULTIMA_1bf2_SetTextPosition(0, 0x13);
    ULTIMA_16ba_PrintChar(0x7b);
    for (local_4 = 0; local_4 < 0x26; local_4++)
    {
        ULTIMA_16ba_PrintChar(0x7f);
    }
    ULTIMA_16ba_PrintChar(0x7c);
    for (local_4 = 0; local_4 < 3; local_4++)
    {
        ULTIMA_16ba_PrintChar(0x7f);
        ULTIMA_1bf2_SetTextPosition(0x27, ULTIMA_1cee_GetCurrentTextY());
        ULTIMA_16ba_PrintChar(0x7f);
    }
    ULTIMA_16ba_PrintChar(0x7d);
    for (local_4 = 0; local_4 < 0x26; local_4++)
    {
        ULTIMA_16ba_PrintChar(0x7f);
    }
    ULTIMA_16ba_PrintChar(0x7e);

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(7, 0x9f, 0x138, 0x9f);
    ULTIMA_0f90_GRAP_Pen(0x138, 0xb8);
    ULTIMA_0f90_GRAP_Pen(7, 0xb8);
    ULTIMA_0f90_GRAP_Pen(7, 0x9f);
    ULTIMA_1cca_SetTextForegroundColor(D_13b0_white_color);
}

// OK P1
static void INTRO_1f26(int param_1)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
    ULTIMA_0aa6_GRAP_3f_FillRect(param_1, 0, param_1 + 6, 0x8f);
    ULTIMA_0aa6_GRAP_3f_FillRect(param_1 + 0x8f, 0, param_1 + 0x97, 0x89);
    ULTIMA_0aa6_GRAP_3f_FillRect(param_1 + 7, 0x89, param_1 + 0x96, 0x8f);
    ULTIMA_1cca_SetTextForegroundColor(D_13b2_frame_color);
    ULTIMA_1bf2_SetTextPosition(0, 0);
    ULTIMA_1850_PrintString(/*0x3676*/ "\x7b\x7f\x7f");
    ULTIMA_4c2a();
    ULTIMA_1cca_SetTextForegroundColor(D_13b0_white_color);
    ULTIMA_1850_PrintString(/*0x6d3a*/ " Ultima IV ");
    ULTIMA_1cca_SetTextForegroundColor(D_13b2_frame_color);
    ULTIMA_4cce();
    ULTIMA_1850_PrintString(/*0x367a*/ "\x7f\x7f");
    ULTIMA_16ba_PrintChar(0x7c);
    ULTIMA_1bf2_SetTextPosition(0, 0x11);
    ULTIMA_16ba_PrintChar(0x7d);
    ULTIMA_1bf2_SetTextPosition(0x12, 0x11);
    ULTIMA_16ba_PrintChar(0x7e);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(param_1 + 0x18, 7, param_1 + 7, 7);
    ULTIMA_0f90_GRAP_Pen(param_1 + 7, 0x88);
    ULTIMA_0f90_GRAP_Pen(param_1 + 0x8f, 0x88);
    ULTIMA_0f90_GRAP_Pen(param_1 + 0x8f, 7);
    ULTIMA_0f90_GRAP_Pen(param_1 + 0x80, 7);
    ULTIMA_1cca_SetTextForegroundColor(D_13b0_white_color);
}

// OK P1
static void INTRO_2024(void)
{
    INTRO_1e62();
    ULTIMA_1c22_SetTextWindowSize(0, 0, 0, 0x13, 0x12);
    ULTIMA_1c22_SetTextWindowSize(1, 0x15, 0, 0x27, 0x12);
    ULTIMA_1c22_SetTextWindowSize(2, 3, 0x15, 0x25, 0x15);
    ULTIMA_1b94_SelectTextWindow(0);
    INTRO_1f26(0);
    ULTIMA_1b94_SelectTextWindow(1);
    INTRO_1f26(0xa8);
    ULTIMA_1bf2_SetTextPosition(0xc, 0);
    ULTIMA_16ba_PrintChar(0x20);
}

// NOT MATCHING (asm)
// animate "warriors of destiny"
void INTRO_2090_AnimateWD(void)
{
    ULTIMA_20fa_WaitTicks(1);
    DRV_69(0, 0); // ax: undefined, cf: 0
}

// NOT MATCHING (asm)
// show "warriors of destiny" (a26e)
static void INTRO_20ae_ShowWD(byte* ptr)
{
    DRV_69(ptr, 1); // ax: a, cf: 1
}
