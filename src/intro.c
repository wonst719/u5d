#include "common/common.h"
#include "savegame.h"
#include "funcs.h"
#include "grap_drv.h"
#include "audio/audio.h"
#include "vars.h"

#include <stdlib.h>

#include "font.h"
#include "intro.h"

// NOTE: Addresses are shifted by 0x10 (there appears to be a header)

void ULTIMA_2322_DiskSwapMessage(void);

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

// NOT MATCHING
// lord british animation
static int INTRO_0050(int param_1, int param_2)
{
#if !defined(TARGET_DOS16)
#define MEM_SIZE 3000
#define MEM_ACCESS(x) g_british[x]
#else // DOS: use savegame area
#define MEM_SIZE 0x1060
#define MEM_ACCESS(x) *(byte*)(x + &D_55a6)
#endif

    int uVar1;
    int xMove;
    int uVar4;
    int iStack_e;
    int yMove;

    iStack_e = D_13b0_white_color;

    ULTIMA_0a70_GRAP_2d_SetPenColor(iStack_e);

    uVar1 = D_5356;
    D_5356 = 0x113;

    for (uVar4 = D_bb18; uVar4 < MEM_SIZE; uVar4++)
    {
        if (iStack_e != 0)
        {
            ULTIMA_0c64_GRAP_30_Pset(param_1, param_2);
        }

        iStack_e = D_13b0_white_color;

        yMove = MEM_ACCESS(uVar4) & 7;
        if (yMove > 2)
        {
            iStack_e = 0;
        }

        if ((MEM_ACCESS(uVar4) & 8) != 0)
        {
            yMove = -yMove;
        }

        xMove = (MEM_ACCESS(uVar4) & 0x70) >> 4;
        if (xMove > 2)
        {
            iStack_e = 0;
        }

        if ((MEM_ACCESS(uVar4) & 0x80) != 0)
        {
            xMove = -xMove;
        }

        param_1 += xMove;
        param_2 += yMove;

        if (ULTIMA_1d5e_PollKey() != 0)
        {
            D_5356 = uVar1;
            return 0;
        }

        if ((uVar4 & 0x1f) == 0)
        {
            ULTIMA_20fa_WaitTicks(1);
        }

        if (MEM_ACCESS(uVar4) == 0)
            break;
    }

    D_bb18 = uVar4 + 1;
    D_5356 = uVar1;

    return D_bb18;
#undef MEM_SIZE
#undef MEM_ACCESS
}

// NOT MATCHING
// introduction
static void INTRO_014e_Introduction(void)
{
    byte bVar1;
    int uVar2;
    byte* puVar3;
    byte* iVar4;
    int iVar6;
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
        puVar3 = ULTIMA_0fae_LoadResourceFile(D_25ea[0]);
    } while (puVar3 == 0);

    FONT_0000(puVar3, /*0x2f30*/ "");
    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1bf2_SetTextPosition(0, 10);

    do
    {
        iVar4 = ULTIMA_0bae_LoadImageFile(D_25ea[0x11]);
    } while (iVar4 == 0);

    do
    {
        local_6 = ULTIMA_0bae_LoadImageFile(D_25ea[0x12]);
    } while (local_6 == 0);

    local_8 = 0;
    for (local_a = 0; local_a < 0x15; local_a++)
    {
        if (local_8 != D_30ae[local_a])
        {
            ULTIMA_0be4_FreeImage(local_6);
            local_8 = (uint)D_30ae[local_a];
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
            if (local_a == 0)
            {
                ULTIMA_0d4c_GRAP_4b_PutImage(iVar4, 0, 0xe0, 0x1e, 0);
                ULTIMA_0d4c_GRAP_4b_PutImage(iVar4, 1, 0xa8, 0x3a, 0);
            }
            else if (local_a == 7)
            {
                ULTIMA_0d4c_GRAP_4b_PutImage(iVar4, 0, 0xe8, 0x1a, 0);
                ULTIMA_0d4c_GRAP_4b_PutImage(iVar4, 2, 200, 0x36, 0);
            }
            else if (local_a == 0xe)
            {
                ULTIMA_0d4c_GRAP_4b_PutImage(iVar4, 0, 0xb8, 0, 0);
                ULTIMA_0d4c_GRAP_4b_PutImage(iVar4, 3, 0xf8, 0, 0);
            }
        }

        bVar1 = D_30da[local_a];
        uVar2 = D_30c4[local_a];
        ULTIMA_0d4c_GRAP_4b_PutImage(local_6, D_3098[local_a], uVar2, bVar1, 0);
        if (D_30f0[local_a] > 3)
        {
            ULTIMA_0d4c_GRAP_4b_PutImage(local_6, (uint)D_30f0[local_a] * 2 - 5, uVar2, bVar1 + 0x37, 0);
        }

        D_5146[0] = D_2f98[local_a]._0;
        D_5146[1] = D_2f98[local_a]._1;

        D_514c[0] = D_2fc2[local_a]._0;
        D_514c[1] = D_2fc2[local_a]._2;

        D_5150 = D_3040[local_a];
        D_5152 = D_3056[local_a];
        bVar1 = D_306c[local_a];
        D_5156 = (uint)bVar1;
        D_5158 = D_3082[local_a];

        if (D_30f0[local_a] == 3)
        {
            ULTIMA_0d4c_GRAP_4b_PutImage(local_6, 3, 0x60, 0x27, 0);
            FONT_0000(puVar3, /*0x2f31*/ "Instantly, a shimmering blue door springs up!");
            D_5156 = (uint)bVar1;
            D_5158 = 0xb4;
            FONT_0000(puVar3, /*0x2f5f*/ "With heart beating rapidly, you step into it.");
        }
        else
        {
            ULTIMA_256e_ReadFileFromDisk(/*0x2f8d*/ "STORY.DAT", D_b21e, 2000, D_3016[local_a]);
            FONT_0000(puVar3, D_b21e);
        }

        if (local_a != 0)
        {
            ULTIMA_1b16_ClearKbdBuffer();
            do
            {
                iVar6 = ULTIMA_1d5e_PollKey();
            } while (iVar6 == 0);
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
    ULTIMA_0be4_FreeImage(iVar4);
    ULTIMA_0fdc_FreeBitImage(puVar3);

    ULTIMA_1b16_ClearKbdBuffer();
    while (ULTIMA_1d5e_PollKey() == 0)
        ;

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    D_a9bd[1] = 0;
    ULTIMA_251e_SwitchDisks(0);
}

// NOT MATCHING
void INTRO_043e(char* param_1)
{
    int iVar1;
    int iVar2;
    int iVar3;

    iVar1 = ULTIMA_216c_strlen(param_1) / 2 - 0x12;
    iVar2 = -iVar1;
    iVar3 = ULTIMA_216c_strlen(param_1);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
    iVar1 *= -8;
    ULTIMA_0aa6_GRAP_3f_FillRect(8, 0xc1, iVar1, 199);
    iVar3 = (iVar3 + iVar2 + 2) * 8;
    ULTIMA_0aa6_GRAP_3f_FillRect(iVar3, 0xc1, 0x137, 199);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(8, 0xc0, iVar1, 0xc0);
    ULTIMA_0b10_GRAP_Line(iVar3, 0xc0, 0x137, 0xc0);
    ULTIMA_1bf2_SetTextPosition(iVar2, 0x18);
    ULTIMA_4c2a();
    ULTIMA_1850_PrintString(param_1);
    ULTIMA_4cce();
}

// OK P1: not matching: si
static void INTRO_04e0_DrawMenuBorders(void)
{
    int local_4;

    ULTIMA_1cca_SetTextForegroundColor(D_13b2_frame_color);
    ULTIMA_1bf2_SetTextPosition(0, 0xf);
    ULTIMA_16ba_PrintChar(0x7b);
    local_4 = 0x26;
    do {
        ULTIMA_16ba_PrintChar(0x7f);
    } while (--local_4 != 0);
    ULTIMA_16ba_PrintChar(0x7c);
    local_4 = 8;
    do {
        ULTIMA_16ba_PrintChar(0x7f);
        ULTIMA_1bf2_SetTextPosition(0x27, ULTIMA_1cee_GetCurrentTextY());
        ULTIMA_16ba_PrintChar(0x7f);
    } while (--local_4 != 0);
    ULTIMA_16ba_PrintChar(0x7d);
    local_4 = 0x26;
    do {
        ULTIMA_16ba_PrintChar(0x7f);
    } while (--local_4 != 0);
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
static void INTRO_05b0_DisplayTitle(uint param_1) // (0 for fast display)
{
    byte* local_4;

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
        param_1 = (u8)ULTIMA_1d5e_PollKey() == 0;
    }
    if (param_1 == 0)
    {
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0, 0, 319, 100);
    }
    INTRO_0010();
    ULTIMA_0be4_FreeImage(D_bb1a);
    if (param_1 != 0)
    {
        do {
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

// NOT MATCHING
static void INTRO_072e_Acknowledgements(void)
{
    void* pVar1;
    int iVar2;

    while ((pVar1 = ULTIMA_0bae_LoadImageFile(D_25ea[28])) == 0) // "STARTSC.16"
        ;

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_0d4c_GRAP_4b_PutImage(pVar1, 1, 0x10, 0x3f, 0);
    ULTIMA_0c22_GRAP_0f_SelectPage(0);

    for (iVar2 = 199; iVar2 > 0x3e; iVar2--)
    {
        ULTIMA_0d4c_GRAP_4b_PutImage(pVar1, 0, 0x90, iVar2, 0); // (image_buffer, image_idx, x, y, ?)
        ULTIMA_0d4c_GRAP_4b_PutImage(pVar1, 2, 0xa0, iVar2, 0);
    }

    for (iVar2 = 0; iVar2 < 0x90; iVar2 += 8)
    {
        ULTIMA_0d4c_GRAP_4b_PutImage(pVar1, 0, 0x88 - iVar2, 0x3f, 0);
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0x98 - iVar2, 0x3f, 0x9f - iVar2, 199);
        ULTIMA_0d4c_GRAP_4b_PutImage(pVar1, 2, iVar2 + 0xa8, 0x3f, 0);
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, iVar2 + 0xa0, 0x3f, iVar2 + 0xa7, 199);
        ULTIMA_20fa_WaitTicks(1);
    }

    while ((D_bb1a = ULTIMA_0bae_LoadImageFile(D_25ea[27])) == 0) // "ULTIMA.16"
        ;

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_0d4c_GRAP_4b_PutImage(D_bb1a, 1, 0x10, 0x41, 0);
    ULTIMA_0be4_FreeImage(D_bb1a);
    INTRO_04e0_DrawMenuBorders();
    INTRO_06bc_BuildMainMenu(4);

    while (ULTIMA_1d5e_PollKey() == 0)
        ;

    ULTIMA_0c22_GRAP_0f_SelectPage(0);

    for (iVar2 = 0x88; iVar2 >= 0; iVar2 -= 8)
    {
        ULTIMA_0d4c_GRAP_4b_PutImage(pVar1, 0, 0x90 - iVar2, 0x3f, 0);
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0x88 - iVar2, 0x3f, 0x8f - iVar2, 199);
        ULTIMA_0d4c_GRAP_4b_PutImage(pVar1, 2, iVar2 + 0xa0, 0x3f, 0);
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, iVar2 + 0xb0, 0x3f, iVar2 + 0xb7, 199);
        ULTIMA_20fa_WaitTicks(1);
    }

    ULTIMA_0be4_FreeImage(pVar1);

    for (iVar2 = 0x3f; iVar2 < 199; iVar2++)
    {
        ULTIMA_0d4c_GRAP_4b_PutImage(pVar1, 0, 0x90, iVar2 + 1, 0);
        ULTIMA_0d4c_GRAP_4b_PutImage(pVar1, 2, 0xa0, iVar2 + 1, 0);
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0x90, iVar2, 0xaf, iVar2);
    }


    ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0x90, 199, 0xaf, 199);
    INTRO_0010();
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    ULTIMA_1b16_ClearKbdBuffer();
}

// NOT MATCHING
// pause(wait time) (8b0e)
static int INTRO_094e_Pause(int param_1)
{
    int iVar1;
    int iVar2;

    iVar2 = 0;

    while (1)
    {
        if (param_1 <= iVar2)
        {
            return 0;
        }

        iVar1 = ULTIMA_1d5e_PollKey();
        if (iVar1 != 0)
            break;

        ULTIMA_20fa_WaitTicks(1);
        iVar2++;
    }

    return iVar1;
}

// OK P1 (NOT MATCHING: local variable order)
void INTRO_0986_Main(void) // intro_main (initialize video) (8b46)
{
    int local_4;
    char *local_6;
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
    for (local_e = 0; local_e < 0x100; local_e++) {
        D_b11e[local_e] = (char)local_e;
    }

    ULTIMA_0de0_DetectVideo();
    ULTIMA_1158_InitTimer();
    local_8 = D_5356;

    // force cga if low memory
    if ((D_52ba_vdp._52c8_videoDriverSelection == 2) && (D_5358 < 0x170)) {
        D_52f1_forceTandy = 0;
        D_52ba_vdp._52ba_forceCga = 1;
        D_52ba_vdp._52c8_videoDriverSelection = 0;
    }

    // 09d2
    while (ULTIMA_0e94_LoadVideoDriver() == 0) {}

    ULTIMA_0892_InitializeVideoDriver(1);

    if ((D_52ba_vdp._52c8_videoDriverSelection != 0) && (D_52ba_vdp._52c8_videoDriverSelection != 3))
    {
        D_13b2_frame_color = 1;
        D_13ae = 4;
        D_13b0_white_color = 0xf;
        D_13b6 = 5;
        D_13b4 = 2;
        D_13b8 = 0xe;
        D_13ba = 7;
    } else {
        // 0a1a
        local_e = 0;

        // cga / herc: *.16 -> *.4
        while (*(local_6 = D_25ea[local_e++]) != 0) // 0a35
        {
            // 0a22
            while (*local_6++ != '.') {}

            if (*local_6 == '1') {
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
        // 	ADD        SP,2h <- cdecl
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
    local_a = ULTIMA_2032_ToUpper((u8)ULTIMA_1d5e_PollKey());
    if (local_a == 0x4a) // 'J'
    {
        ULTIMA_16ba_PrintChar(0xff);
        ULTIMA_16ba_PrintChar(0xfc);
        ULTIMA_1bf2_SetTextPosition(0, 0xb);
        ULTIMA_1850_PrintString(/*0x31a4*/ "Journey Onward\n\n");
        ULTIMA_16ba_PrintChar(0xfb);
        // 0af2
        while (ULTIMA_0ff4_LoadTileset(D_25f0[0]) == 0) {}
        D_5893_map_id = 0x41;
        // -> 0cc9
    }
    else
    {
        // 0b06
        local_a = 1;

        do {
            local_12 = ULTIMA_0fae_LoadResourceFile(D_25ea[2]); // "TITLE.BIT"
        } while (local_12 == 0);

        do {
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
                if ((INTRO_0050(0x2c, 0x44) != 0) &&
                    (INTRO_0050(0x40, 0x5e) != 0) &&
                    (INTRO_0050(0x8f, 0x4e) != 0))
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
            AUDIO_PlayBgm(BGM_ID_1);

            FONT_04a4();
        }
        // 0cc4
        local_a = 1;
    }

    ULTIMA_207e_srand(ULTIMA_2056_GetTime());

    // 0cd0
    do
    {
        AUDIO_PlayBgm(BGM_ID_1);

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
            do {
                // 0d4d
                ULTIMA_1bf2_SetTextPosition(0xf, 0xf);
                ULTIMA_4c2a();
                ULTIMA_1850_PrintString(/*0x31dd*/ "Select: ");
                ULTIMA_4cce();
                ULTIMA_1bf2_SetTextPosition(0x17, 0xf);
                D_5356 = 0x113;
                local_4 = 0;
                do {
                    // 0d75
                    local_10 = ULTIMA_2032_ToUpper(ULTIMA_1b38_PollKeyWithCursor());
                    if (local_10 == 0) {
                        INTRO_2090_AnimateWD();
                    }
                    // 0d86
                    local_4++;
                } while ((local_4 < 200) && (local_10 == 0));
                D_5356 = local_8;
                // OK P1!
                switch ((int)local_10)
                {
                    case 1: // up?
                    case 3: // left?
                        local_c--;
                        if (local_c < 0) {
                            local_c = 5;
                        }
                        INTRO_06bc_BuildMainMenu(local_c);
                        break;
                    case 2: // down?
                    case 4: // right?
                        local_c++;
                        if (5 < local_c) {
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
                AUDIO_StopBgm();

                // 0e7c
                ULTIMA_637e_DrawFrame();
                ULTIMA_2e96_SetWindDirection(0);
                ULTIMA_1b94_SelectTextWindow(2);
                ULTIMA_1bf2_SetTextPosition(0, 0xc);
                if (D_5893_map_id == 0x40) {
                    while (ULTIMA_0ff4_LoadTileset(D_25f0[0]) == 0) {}
                    D_5893_map_id = 0x41;
                }
                // 0ead
                ULTIMA_251e_SwitchDisks(3);
#if !defined(TARGET_DOS16)
                FILE_ReadSavegameFile(/*0x31e6*/ "SAVED.GAM");
#else
                ULTIMA_256e_ReadFileFromDisk(/*0x31e6*/ "SAVED.GAM", &D_55a6, ((int)&D_6606 - (int)&D_55a6) /*0x1060*/, 0);
#endif
                if (D_55a8_party[0]._0[0] == '\0')
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
                    if ((D_5893_map_id == 0) && (D_5895_map_level != 0)) {
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
                AUDIO_StopBgm();

                ULTIMA_16ba_PrintChar(0xff);
                INTRO_132a_TransferFromU4();
                goto L_0fab; // TODO: get rid of goto
                //break;

            case 0x43: // 'C'
                AUDIO_StopBgm();

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
                AUDIO_StopBgm();

                INTRO_014e_Introduction();
                INTRO_05b0_DisplayTitle(0);
                break;
                
            case 0x41: // 'A'
                AUDIO_StopBgm();

                // 0ff4
                if (D_5893_map_id != '@') {
                    ULTIMA_102e_UnloadTileset();
                    D_5893_map_id = 0x40;
                }
                INTRO_072e_Acknowledgements();
                break;

            case 0x52: // 'R'
                FONT_04a4(); // thunk
                break;
        }
    } while (1);
}

// NOT MATCHING
static int INTRO_1016_ConvertU4Savegame(void)
{
    bool bVar1;
    int uVar3;
    int iVar4;

    bVar1 = 0;

    D_a9bd[1] = 1;
    D_a9bd[0] = 4;

    D_a9cc = ULTIMA_16a6_GetDefaultDrive();

    ULTIMA_256e_ReadFileFromDisk(/*0x3278*/ "party.sav", &D_bc88, 0x28, 8);

    if (D_bc88._6 > 0x46 || D_bc88._8 > 0x46 || D_bc88._a > 0x46 || D_bc88._4 > 9999 || D_bc88._0 > 9999 ||
        D_bc88._2 > 9999 || D_bc88._25 > 7)
    {
        bVar1 = 1;
    }

    for (iVar4 = 0; iVar4 < 8; iVar4++)
    {
        if (D_bc88._14[iVar4] != 0 && D_bc88._14[iVar4] < 0x20)
        {
            bVar1 = 1;
            break;
        }
    }

    if (bVar1)
    {
        ULTIMA_16ba_PrintChar(0xff);
        ULTIMA_16ba_PrintChar(0xfc);
        ULTIMA_1bf2_SetTextPosition(0, 5);
        ULTIMA_1850_PrintString(/*0x3282*/ "Error:  Your Ultima IV game\n\ncontains bad data.\n\n");
        ULTIMA_1850_PrintString(/*0x32b4*/ "Unable to continue transfer.\n\n\n");
        ULTIMA_1850_PrintString(/*0x32d4*/ "Press any key to return to the menu.");
        ULTIMA_16ba_PrintChar(0xfb);
        ULTIMA_1dda_WaitForKeystroke(0);
        uVar3 = 1;
    }
    else
    {
        for (iVar4 = 0; iVar4 < 8; iVar4++)
        {
            if (D_bc88._14[iVar4] == 0)
                break;

            D_55a8_party[0]._0[iVar4] = D_bc88._14[iVar4];
        }

        D_55a8_party[0]._0[iVar4] = 0;

        if (D_bc88._24 == 11)
        {
            D_55a8_party[0]._9 = 0xb;
        }
        else
        {
            D_55a8_party[0]._9 = 0xc;
        }

        switch (D_bc88._25)
        {
        case 0:
            D_55a8_party[0]._a = 0x4d;
            break;
        case 1:
            D_55a8_party[0]._a = 0x42;
            break;
        case 2:
            D_55a8_party[0]._a = 0x46;
            break;
        case 3:
            D_55a8_party[0]._a = 0x44;
            break;
        case 4:
            D_55a8_party[0]._a = 0x54;
            break;
        case 5:
            D_55a8_party[0]._a = 0x50;
            break;
        case 6:
            D_55a8_party[0]._a = 0x52;
            break;
        case 7:
            D_55a8_party[0]._a = 0x53;
        }

        D_55a8_party[0]._b = 0x47;
        D_55a8_party[0]._c = D_bc88._6;
        D_55a8_party[0]._d = D_bc88._8;
        D_55a8_party[0]._e = D_bc88._a;
        D_55a8_party[0]._f = D_bc88._c;
        D_55a8_party[0]._10 = D_bc88._0;
        D_55a8_party[0]._12 = D_bc88._2;
        D_55a8_party[0]._14 = D_bc88._4;

        D_55a8_party[0]._16 = D_bc88._2 / 100;

        ULTIMA_256e_ReadFileFromDisk(/*0x32f9*/ "party.sav", &D_bb1c, 0xb6, 0x140);

        if (D_bb1c._6 == 0 && D_bb1c._8 == 0 && D_bb1c._a == 0 && D_bb1c._c == 0 && D_bb1c._e == 0 && D_bb1c._10 == 0 &&
            D_bb1c._12 == 0 && D_bb1c._14 == 0)
        {
            D_3304 = 1;
        }

        uVar3 = 0;
    }

    return uVar3;
}

// NOT MATCHING
static void INTRO_1278_PrintU4Class(void)
{
    switch (D_55a8_party[0]._a)
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

// NOT MATCHING
static int INTRO_12ea(int param_1)
{
    if (param_1 > 9)
    {
        if (param_1 < 30)
        {
            param_1 = (param_1 - 9) / 2 + 10;
        }
        else
        {
            param_1 = (param_1 - 30) / 4 + 20;
        }
    }

    return param_1;
}

// NOT MATCHING
static void INTRO_132a_TransferFromU4(void)
{
    byte uVar1;
    char cVar3;
    char cVar4;
    byte bVar5;
    byte uVar6;
    int iVar7;
    int uVar8;
    char local_12;

    if (D_5893_map_id == 66)
        D_5893_map_id = 65;
    cVar3 = D_5893_map_id;

    uVar1 = D_a9c8[0];
    D_a9cb = uVar1;
    D_a9cc = uVar1;

#if !defined(TARGET_DOS16)
    FILE_ReadSavegameFile(/*0x3345*/ "INIT.GAM");
#else
    ULTIMA_256e_ReadFileFromDisk(/*0x3345*/ "INIT.GAM", &D_55a6, 0x1060, 0);
#endif
    ULTIMA_256e_ReadFileFromDisk(/*0x334e*/ "INIT.OOL", D_b31e, 0x100, 0);
    ULTIMA_1c22_SetTextWindowSize(0, 0, 0, 0x27, 0x18);

    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_16ba_PrintChar(0xff);

    local_12 = D_a9c8[0];
    while (ULTIMA_1eac_SetDefaultDrive(local_12) == 0)
    {
        local_12 = ULTIMA_2032_ToUpper(ULTIMA_1dda_WaitForKeystroke(0));
        if (local_12 == 0x1b)
        {
            D_5893_map_id = cVar3;
            return;
        }
    }

    D_5394_fn = ULTIMA_2322_DiskSwapMessage;

    if (INTRO_1016_ConvertU4Savegame() != 0)
    {
        D_5893_map_id = cVar3;
        return;
    }

    if (D_3304 != 0)
    {
        D_55a8_party[0]._a = 0x41;
    }

    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1bf2_SetTextPosition(0, 0xb);
    ULTIMA_16ba_PrintChar(0xfc);
    ULTIMA_1850_PrintString(/*0x33d9*/ "Found:\n");
    ULTIMA_1bf2_SetTextPosition(0, 0xc);
    ULTIMA_1850_PrintString(D_55a8_party[0]._0);
    ULTIMA_16ba_PrintChar(0xfb);
    ULTIMA_1bf2_SetTextPosition(0xc, 0xd);
    ULTIMA_1850_PrintString(/*0x33e1*/ "a level ");
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._16, 1, 0x20);

    if (D_55a8_party[0]._9 == 11)
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
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._c, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(0x11, 0x10);
    ULTIMA_1850_PrintString(/*0x3401*/ "DEX:  ");
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._d, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(0x11, 0x11);
    ULTIMA_1850_PrintString(/*0x3408*/ "INT:  ");
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._e, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(10, 0x14);

    ULTIMA_1850_PrintString(D_55a8_party[0]._0);
    ULTIMA_1850_PrintString(/*0x340f*/ " is ");
    if (D_3304 == 0)
    {
        ULTIMA_1850_PrintString(/*0x341f*/ "not an Avatar");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x3414*/ "an Avatar.");
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
    ULTIMA_1850_PrintString(D_55a8_party[0]._0);
    ULTIMA_16ba_PrintChar(0xfb);
    ULTIMA_1bf2_SetTextPosition(10, 5);

    if (D_55a8_party[0]._9 == 11)
    {
        ULTIMA_1850_PrintString(/*0x342d*/ "Male");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x3432*/ "Female");
    }

    ULTIMA_1bf2_SetTextPosition(10, 6);

    if (D_3304 == 0)
    {
        INTRO_1278_PrintU4Class();
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x3439*/ "Avatar");
    }

    ULTIMA_1bf2_SetTextPosition(10, 8);
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._14, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(10, 9);
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._16, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(10, 0xb);
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._c, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(10, 0xc);
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._d, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(10, 0xd);
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._e, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(0, 0xf);
    ULTIMA_16ba_PrintChar(0xfc);

    if (D_3304 == 0)
    {
        ULTIMA_1850_PrintString(/*0x3447*/ "Non-Avatar");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x3440*/ "Avatar");
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
    do
    {
        uVar8 = ULTIMA_1dda_WaitForKeystroke(0);
        cVar4 = ULTIMA_2032_ToUpper(uVar8);
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
            ULTIMA_1e38_IntroGetString(D_55a8_party[0]._0, 8);
        } while (D_55a8_party[0]._0[0] == 0);
    }

    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(0, 3);
    ULTIMA_16ba_PrintChar(0xfc);
    ULTIMA_1850_PrintString(D_55a8_party[0]._0);
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

    do
    {
        cVar4 = ULTIMA_2032_ToUpper(ULTIMA_1dda_WaitForKeystroke(0));
        if (cVar4 == 'Y')
            break;
    } while (cVar4 != 'N');

    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(10, 5);
    if ((cVar4 == 'Y' && D_55a8_party[0]._9 == 11) || (cVar4 == 'N' && D_55a8_party[0]._9 == 12))
    {
        ULTIMA_1850_PrintString(/*0x34a4*/ "Male");
        D_55a8_party[0]._9 = 0xb;
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x34a9*/ "Female");
        D_55a8_party[0]._9 = 0xc;
    }
    ULTIMA_1bf2_SetTextPosition(5, 5);
    ULTIMA_1850_PrintString(/*0x34b0*/ "Sex:");
    ULTIMA_1bf2_SetTextPosition(3, 6);
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1850_PrintString(/*0x34b5*/ "Class:");
    ULTIMA_16ba_PrintChar(0xfd);
    ULTIMA_1bf2_SetTextPosition(10, 6);
    if (D_3304 == 0)
    {
        INTRO_1278_PrintU4Class();
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x34bc*/ "Avatar");
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
    if (D_3304 == 0)
    {
        ULTIMA_1850_PrintString(/*0x34e7*/ "Class remains intact");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x34cf*/ "Thou art now an Avatar:");
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
    D_55a8_party[0]._14 /= 10;
    ULTIMA_1a3e_PrintNumber(iVar7, 1, 0x20);

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
    D_55a8_party[0]._16 = 1;
    for (iVar7 = D_55a8_party[0]._14 / 100; iVar7 > 0; iVar7 >>= 1)
    {
        D_55a8_party[0]._16++;
    }
    iVar7 = (uint)D_55a8_party[0]._16 * 0x1e;
    D_55a8_party[0]._12 = iVar7;
    D_55a8_party[0]._10 = iVar7;
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._16, 1, 0x20);

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
    uVar1 = D_55a8_party[0]._c;
    bVar5 = INTRO_12ea(uVar1);
    D_55a8_party[0]._c = bVar5;
    if (bVar5 < 0x14)
    {
        D_55a8_party[0]._c = 0x14;
    }
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._c, 1, 0x20);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1bf2_SetTextPosition(1, 0);
    ULTIMA_1850_PrintString(/*0x357b*/ "Strength: was ");
    ULTIMA_1a3e_PrintNumber(uVar1, 1, 0x20);
    ULTIMA_1850_PrintString(/*0x358a*/ "(50), now ");
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._c, 1, 0x20);
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
    uVar1 = D_55a8_party[0]._d;
    uVar6 = INTRO_12ea(uVar1);
    D_55a8_party[0]._d = uVar6;
    ULTIMA_1a3e_PrintNumber(uVar6, 1, 0x20);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1bf2_SetTextPosition(1, 0);
    ULTIMA_1850_PrintString(/*0x35ae*/ "Dexterity: was ");
    ULTIMA_1a3e_PrintNumber(uVar1, 1, 0x20);
    ULTIMA_1850_PrintString(/*0x35be*/ "(50), now ");
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._d, 1, 0x20);
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
    uVar1 = D_55a8_party[0]._e;
    uVar6 = INTRO_12ea(uVar1);
    D_55a8_party[0]._e = uVar6;
    D_55a8_party[0]._f = uVar6;
    ULTIMA_1a3e_PrintNumber(uVar6, 1, 0x20);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1bf2_SetTextPosition(1, 0);
    ULTIMA_1850_PrintString(/*0x35e2*/ "Intellect: was ");
    ULTIMA_1a3e_PrintNumber(uVar1, 1, 0x20);
    ULTIMA_1850_PrintString(/*0x35f2*/ "(50), now ");
    ULTIMA_1a3e_PrintNumber(D_55a8_party[0]._e, 1, 0x20);
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
    if (D_3304 == 0)
    {
        ULTIMA_1850_PrintString(/*0x3613*/ "Non-Avatar");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x360c*/ "Avatar");
    }
    ULTIMA_16ba_PrintChar(0xfb);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_1c22_SetTextWindowSize(2, 2, 0x15, 0x25, 0x16);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_251e_SwitchDisks(3);
    ULTIMA_1850_PrintString(/*0x361e*/ "\n\n Conversion complete, saving...\n");

    for (iVar7 = 0; iVar7 < 0x100; iVar7++)
    {
        D_b21e[iVar7] = 0;
    }

    ULTIMA_25d8_WriteFileToDisk(/*0x3641*/ "SAVED.OOL", D_b21e, 0x200);
#if !defined(TARGET_DOS16)
    FILE_WriteSavegameFile(/*0x364b*/ "SAVED.GAM");
#else
    ULTIMA_25d8_WriteFileToDisk(/*0x364b*/ "SAVED.GAM", &D_55a6, 0x1060);
#endif
    ULTIMA_251e_SwitchDisks(0);

    D_5893_map_id = cVar3;
    D_a9bd[1] = 0;
}

// NOT MATCHING
static void INTRO_1e22(int param_1)
{
    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(3, D_3656[param_1]);
    ULTIMA_1850_PrintString(D_3666[param_1]);
    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(3, D_3656[param_1]);
    ULTIMA_1850_PrintString(D_3666[param_1]);
}

// NOT MATCHING
static void INTRO_1e62(void)
{
    int iVar2;

    ULTIMA_1cca_SetTextForegroundColor(D_13b2_frame_color);

    ULTIMA_1bf2_SetTextPosition(0, 0x13);
    ULTIMA_16ba_PrintChar(0x7b);
    for (iVar2 = 0; iVar2 < 0x26; iVar2++)
    {
        ULTIMA_16ba_PrintChar(0x7f);
    }
    ULTIMA_16ba_PrintChar(0x7c);
    for (iVar2 = 0; iVar2 < 3; iVar2++)
    {
        ULTIMA_16ba_PrintChar(0x7f);
        ULTIMA_1bf2_SetTextPosition(0x27, ULTIMA_1cee_GetCurrentTextY());
        ULTIMA_16ba_PrintChar(0x7f);
    }
    ULTIMA_16ba_PrintChar(0x7d);
    for (iVar2 = 0; iVar2 < 0x26; iVar2++)
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

// NOT MATCHING
static void INTRO_1f26(int param_1)
{
    int iVar1;
    int iVar2;

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
    ULTIMA_0aa6_GRAP_3f_FillRect(param_1, 0, param_1 + 6, 0x8f);
    iVar1 = param_1 + 0x8f;
    ULTIMA_0aa6_GRAP_3f_FillRect(iVar1, 0, param_1 + 0x97, 0x89);
    iVar2 = param_1 + 7;
    ULTIMA_0aa6_GRAP_3f_FillRect(iVar2, 0x89, param_1 + 0x96, 0x8f);
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
    ULTIMA_0b10_GRAP_Line(param_1 + 0x18, 7, iVar2, 7);
    ULTIMA_0f90_GRAP_Pen(iVar2, 0x88);
    ULTIMA_0f90_GRAP_Pen(iVar1, 0x88);
    ULTIMA_0f90_GRAP_Pen(iVar1, 7);
    ULTIMA_0f90_GRAP_Pen(param_1 + 0x80, 7);
    ULTIMA_1cca_SetTextForegroundColor(D_13b0_white_color);
}

// NOT MATCHING
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
