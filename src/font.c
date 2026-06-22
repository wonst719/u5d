#include "common/common.h"
#include "savegame.h"
#include "funcs.h"
#include "vars.h"
#include "macros.h"

#include <string.h>

#include "audio/audio.h"

#include "font.h"
#include "intro.h"
#include "tiles.h"

// CHECKED
// param_1: image, param_2: text
void FONT_0000(byte* param_1, char* param_2)
{
    int local_12;
    int local_10;
    int local_e;
    int local_c;
    int local_a;
    int local_8;
    int local_4;
    int local_6;

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    local_12 = ((int)D_5158 > (int)D_5150 && (int)D_5158 < (int)D_5152) ? 1 : 0; // TODO: D_5158, D_5150, D_5152 -> int?

    local_c = D_514c[local_12] - D_5146[local_12];

    local_e = local_6 = 0;
    local_4 = D_5156 - D_5146[local_12];

    while (param_2[local_e] != '\0')
    {
        local_a = 0;
        local_10 = local_e;
        while (param_2[local_10] != '\0' && local_4 < local_c && param_2[local_10] != '\n')
        {
            if (param_2[local_10] <= 0x20)
            {
                local_4 += D_5154;
                local_a += 1;
            }
            else if (param_2[local_10] == '{')
            {
                local_4 += 0xf;
            }
            else if (param_2[local_10] != '_')
            {
                local_4 += D_50eb[param_2[local_10] - 0x21] + 1;
            }

            local_10++;
        }

        while (1)
        {
            if ((param_2[local_10] == '\0' && local_4 < local_c))
                break;
            if (param_2[local_10] == '\n')
                break;
            if (--local_10 <= local_e)
                break;

            if (param_2[local_10] == ' ')
            {
                local_4 -= D_5154;
                local_a--;
                break;
            }

            if (param_2[local_10] == '_')
            {
                if (local_4 + D_50f7 + 1 < local_c)
                {
                    local_4 += D_50f7 + 1;
                    break;
                }
            }

            if (param_2[local_10] != '_' && param_2[local_10] != '{')
            {
                local_4 -= D_50eb[param_2[local_10] - 0x21] + 1;
            }
        }

        local_8 = local_c - local_4;
        local_6 = local_10;
        local_10 = local_e;

        for (; local_10 < local_6; local_10++)
        {
            if (param_2[local_10] <= 0x20)
            {
                D_5156 += D_5154;
                if (local_a != 0 && param_2[local_6] != '\0' && param_2[local_6] != '\n')
                {
                    D_5156 += local_8 / local_a;
                    local_8 -= local_8 / local_a;
                    local_a--;
                }
            }
            else if (param_2[local_10] == '{')
            {
                D_5156 += 0xf;
            }
            else if (param_2[local_10] != '_')
            {
                if (D_5158 < 0xc0)
                {
                    // NOTE: "or" mix
                    ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(param_1, param_2[local_10] - 0x20, D_5156, D_5158);
                }
                D_5156 += D_50eb[param_2[local_10] - 0x21] + 1;
            }
        }

        local_e = local_6;
        if (param_2[local_e] != '\0')
        {
            if (param_2[local_e] == '_' && D_5158 < 0xc0)
            {
                ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(param_1, 0xd, D_5156, D_5158);
            }

            local_4 = 0;
            D_5158 += 9;
            local_12 = ((int)D_5158 > (int)D_5150 && (int)D_5158 < (int)D_5152) ? 1 : 0;

            D_5156 = D_5146[local_12];
            local_c = D_514c[local_12] - D_5156;
            local_e++;
        }
    }

    ULTIMA_0c22_GRAP_0f_SelectPage(0);
}

// OK P1
static void FONT_02a2(int param_1, int param_2)
{
    byte local_4;

    local_4 = GetMap(param_1, param_2);
    if (local_4 != 0)
    {
        ULTIMA_10e0_GRAP_51_PutTile(D_b11e[local_4], param_1, param_2 + 7);
        return;
    }
    else
    {
        local_4 = D_6608[param_1 + param_2 * 0x20 + 0x80];
        if (local_4 == 0x16)
        {
            return;
        }

        ULTIMA_10e0_GRAP_51_PutTile(0x100 + local_4, param_1, param_2 + 7);
    }
}

// CHECKED
int FONT_02fc(int param_1)
{
    int local_c;
    int local_8;
    int local_6;
    ActorFmt* local_4;

    do
    {
        ULTIMA_4552_AnimateActors();
        INTRO_2090_AnimateWD();

        // NOT MATCHING (loop)
        for (local_6 = 0; local_6 < 32; local_6++)
        {
            local_4 = &D_5c5a[local_6];

            if (local_4->_0_tile != 0)
            {
                local_c = local_4->_2_x + local_4->_3_y * 0x20;
                D_6608[local_c] = 0;
                D_6608[local_c + 0x80] = local_4->_1_animTile;
            }
        }

        // NOT MATCHING (loop)
        for (local_6 = D_bd26; local_6 <= D_bd27; local_6++)
        {
            for (local_8 = 0; local_8 < 4; local_8++)
            {
                if (GetMap(local_6, local_8) != 0xfe)
                {
                    FONT_02a2(local_6, local_8);
                }
            }
        }

        if (D_bd26 != 0 && D_bd28 != 0)
        {
            D_bd26 -= 1;
            D_bd27 += 1;
        }

        D_bd28 = !D_bd28;

        if (ULTIMA_1d5e_PollKey() != 0)
        {
            return 1;
        }

        if (param_1 != 0)
        {
            ULTIMA_20fa_WaitTicks(1);
        }

        if (D_bd29 == 2)
        {
            ULTIMA_223c_AudioWhiteNoise(0x14, 0x3c, 10000);
        }
        else if (D_bd29 == 3)
        {
            D_515a++;
            if ((int)D_515a > 7)
            {
                D_515a = 0;
            }

            if (D_515a == 0)
            {
                ULTIMA_22c0_AudioTone(3000, 3);
            }
            else if (D_515a == 4)
            {
                ULTIMA_22c0_AudioTone(2000, 3);
            }
        }
    } while (--param_1 != 0);

    return 0;
}

// CHECKED
static void FONT_0418(int param_1)
{
    int local_6;
    int local_4;

    ASSERT(param_1 < 4);

    INTRO_043e(D_515c[param_1]);

    for (local_4 = 0; local_4 < 0x13; local_4++)
    {
        for (local_6 = 0; local_6 < 4; local_6++)
        {
            GetCopiedMap(local_4, local_6) = GetMap(local_4, local_6) = D_b21e[param_1 * 0x80 + local_4 + local_6 * 0x20];
        }
    }

    D_bd26 = D_bd27 = 9;
    D_bd28 = 0;
    D_bd29 = param_1;
}

static void FONT_0e52(void);
static void FONT_0e7b(void);

// CHECKED
// "view"
void FONT_04a4(void)
{
    int bVar1;
    int local_18;
    int uVar3;
    int iVar4;
    int local_16;
    int local_14;
    int local_12;
    int local_10;
    int local_e;
    ActorFmt* local_c;
    int local_8;
    int local_6;
    int local_4;

    int i;

    D_52ba_vdp._52be_tileYOffset = 0x10;
    D_bd26 = D_bd27 = 9;
    D_bd28 = 0;

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
    ULTIMA_0aa6_GRAP_3f_FillRect(0x78, 0x78, 199, 0x7e);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(0x78, 0x7f, 199, 0x7f);

    if (D_5893_map_id != 0x42)
    {
        ULTIMA_256e_ReadFileFromDisk(/*0xa044*/ "MISCMAPS.DAT", D_b21e, 2000, 0x2c0);
        if (D_5893_map_id == 0x40)
        {
            FONT_0e52();
            while (ULTIMA_0ff4_LoadTileset(*D_25f0) == 0) {}
            FONT_0e7b();
        }
    }

    D_5893_map_id = 0x42;

    for (local_e = 0x200; local_e < 2000; local_e++)
    {
        switch (D_b21e[local_e])
        {
        case 0:
            local_c = &D_5c5a[D_b21e[++local_e]];
            local_c->_0_tile = local_c->_1_animTile = D_b21e[++local_e];
            local_c->_2_x = D_b21e[++local_e];
            local_c->_3_y = D_b21e[++local_e];
            local_c->_6 = 0;
            break;

        case 1:
            local_c = &D_5c5a[D_b21e[++local_e]];
            local_c->_0_tile = local_c->_1_animTile = local_c->_6 = 0;

            GetMap(local_c->_2_x, local_c->_3_y) = GetCopiedMap(local_c->_2_x, local_c->_3_y);
            break;

        case 2:
            local_c = &D_5c5a[D_b21e[++local_e]];
            local_18 = D_b21e[++local_e];
            GetMap(local_c->_2_x, local_c->_3_y) = GetCopiedMap(local_c->_2_x, local_c->_3_y);
            local_c->_2_x += D_24d6[local_18];
            local_c->_3_y += D_24de[local_18];
            break;

        case 3:
            if (FONT_02fc(D_b21e[++local_e]) != 0)
            {
                return;
            }
            break;

        case 4:
            local_6 = D_b21e[++local_e];
            local_8 = D_b21e[++local_e];
            GetMap(local_6, local_8) = GetCopiedMap(local_6, local_8) = TILE_MAP_FE;

            for (iVar4 = 1; iVar4 < 0x10; iVar4++)
            {
                ULTIMA_1112_GRAP_60(iVar4, local_6, local_8 + 7);
                if (FONT_02fc(1) != 0)
                {
                    return;
                }
            }

            GetMap(local_6, local_8) = GetCopiedMap(local_6, local_8) = TILE_MAP_MOONGATE;
            if (FONT_02fc(2) != 0)
            {
                return;
            }
            break;

        case 5:
            GetMap(local_6, local_8) = GetCopiedMap(local_6, local_8) = TILE_MAP_FE;

            iVar4 = 0xf;
            do
            {
                ULTIMA_1112_GRAP_60(iVar4, local_6, local_8 + 7);
                if (FONT_02fc(1) != 0)
                {
                    return;
                }
                iVar4--;
            } while (iVar4 > 0);

            GetMap(local_6, local_8) = GetCopiedMap(local_6, local_8) = TILE_MAP_GRASS;
            if (FONT_02fc(2) != 0)
            {
                return;
            }
            break;

        case 6:
            FONT_0418(D_b21e[++local_e]);
            break;

        case 7:
            local_c = &D_5c5a[D_b21e[++local_e]];
            uVar3 = local_c->_0_tile;

            local_c->_0_tile = local_c->_1_animTile = TILE_ACTOR_CIRCLE;

            if (ULTIMA_1068(0x100 + uVar3, local_c->_2_x, local_c->_3_y + 7) != 0)
            {
                return;
            }
            local_c->_0_tile = local_c->_1_animTile = uVar3;
            break;

        case 8:
            local_c = &D_5c5a[D_b21e[++local_e]];
            local_18 = local_c->_2_x;
            bVar1 = local_c->_3_y;
            uVar3 = local_c->_0_tile;

            local_c->_0_tile = local_c->_1_animTile = TILE_ACTOR_CIRCLE;

            if (ULTIMA_1068(GetCopiedMap(local_18, bVar1), local_18, bVar1 + 7) != 0)
            {
                return;
            }

            local_c->_0_tile = local_c->_1_animTile = uVar3;
            break;

        case 9:
            local_e = 0x1ff;
            break;

        case 10:
            uVar3 = D_b21e[++local_e];
            local_14 = D_b21e[++local_e];
            iVar4 = D_b21e[++local_e];
            GetCopiedMap(local_14, iVar4) = uVar3;
            GetMap(local_14, iVar4) = uVar3;
            break;

        case 0xb:
            // ...
            local_12 = local_14 = 0;
            for (local_10 = 0; local_10 < 5; local_10++)
            {
                if (FONT_02fc(1) != 0)
                {
                    return;
                }
                local_12 = local_10 * 9;
                local_14 = local_10 * 3;
                ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
                ULTIMA_0b10_GRAP_Line(local_12 + 0x80, local_14 + 0x98, local_12 + 0x89, local_14 + 0x9b);
                ULTIMA_0b10_GRAP_Line(local_12 + 0x80, local_14 + 0x99, local_12 + 0x89, local_14 + 0x9c);
            }

            local_e++;
            local_e++;
            local_c = &D_5c5a[D_b21e[local_e]];
            ULTIMA_10e0_GRAP_51_PutTile(0, local_c->_2_x, local_c->_3_y + 7);
            ULTIMA_223c_AudioWhiteNoise(1, 0x4b0, 4000);
            if (FONT_02fc(3) != 0)
            {
                return;
            }
            break;

        case 0xc:
            for (i = 0; i < 0x20; i++)
            {
                D_5c5a[i]._1_animTile = D_5c5a[i]._0_tile = D_5c5a[i]._6 = 0;
            }
            break;

        case 0xd:
            local_c = &D_5c5a[D_b21e[++local_e]];
            local_18 = D_b21e[++local_e];
            GetMap(local_c->_2_x, local_c->_3_y) = GetCopiedMap(local_c->_2_x, local_c->_3_y);
            local_c->_2_x += D_24d6[local_18];
            local_c->_3_y += D_24de[local_18];
            if (FONT_02fc(7) != 0)
            {
                return;
            }
            break;

        case 0xe:
            local_16 = D_b21e[++local_e];
            local_4 = local_e;
            break;

        case 0xf:
            local_16--;
            if (local_16 != 0)
            {
                local_e = local_4;
            }
            break;
        }

        if (ULTIMA_1d5e_PollKey() != 0)
        {
            return;
        }
    }
}

// 0998 ~ 0b0a: character creation

// OK P1
static int FONT_0998(void)
{
    int local_4;

    do
    {
        local_4 = ULTIMA_2092_RandomRange(0, 7);
    } while (D_bd2a[local_4] != 0 || D_bd32[local_4] != 0);

    D_bd2a[local_4] = 1;

    return local_4;
}

// OK P1
static void FONT_09c8(byte* param_1, byte* param_2)
{
    int local_10;
    int local_e;
    int local_a;
    byte local_c;
    int local_8;
    int local_6;
    byte local_4;

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_16ba_PrintChar(CTRL_CHAR_CLEAR_WINDOW);
    ULTIMA_0d4c_GRAP_4b_PutImage(param_2, 1, 0x10, 0, 0);
    ULTIMA_0d4c_GRAP_4b_PutImage(param_2, 1, 200, 0, 0);

    D_5156 = 0;
    D_5158 = 0x98;

    local_6 = FONT_0998();
    local_8 = FONT_0998();
    if (local_6 > local_8)
    {
        local_e = local_8;
        local_10 = local_6;
        local_c = 'B';
    }
    else
    {
        local_e = local_6;
        local_10 = local_8;
        local_c = 'A';
    }

    ULTIMA_0d4c_GRAP_4b_PutImage(param_2, local_e + 2, D_51fc[local_e], D_5204[local_e], 0);
    ULTIMA_0d4c_GRAP_4b_PutImage(param_2, local_10 + 2, D_51fc[local_10] + 0xb8, D_5204[local_10], 0);
    ULTIMA_256e_ReadFileFromDisk(/*0xa052*/ "QUESTION.DAT", D_b21e, 2000, D_517c[local_6][local_8]);
    FONT_0000(param_1, (char*)D_b21e);
    ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);

    do
    {
        local_4 = ULTIMA_2032_ToUpper(ULTIMA_1d5e_PollKey());
        if (local_4 == 'A')
            break;
    } while (local_4 != 'B');

    if (local_4 != local_c)
    {
        local_a = local_6;
        local_6 = local_8;
        local_8 = local_a;
    }

    D_bd3c += D_5164[local_6];
    D_bd3d += D_516c[local_6];
    D_bd3e += D_5174[local_6];
    D_bd32[local_8] = 1;
}

// CHECKED
void FONT_0b0a(void)
{
    byte local_4;
    byte* local_a;
    byte* local_6;
    byte local_8;

    if (D_5893_map_id != 64)
    {
        ULTIMA_102e_UnloadTileset();
    }

    D_a9cb = 0xff;

    do
    {
        local_a = ULTIMA_0fae_LoadResourceFile(D_25ea[0]);
    } while (local_a == 0);

    do
    {
        local_6 = ULTIMA_0bae_LoadImageFile(D_25ea[0x10]);
    } while (local_6 == 0);

#if !defined(TARGET_DOS16)
    FILE_ReadSavegameFile(/*0xa060*/ "INIT.GAM");
#else
    ULTIMA_256e_ReadFileFromDisk(/*0xa060*/ "INIT.GAM", &D_55a6, (int)&D_6606 - (int)&D_55a6, 0);
#endif
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
    ULTIMA_0aa6_GRAP_3f_FillRect(0x78, 0x78, 200, 0x7e);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(0x78, 0x7f, 200, 0x7f);
    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    ULTIMA_0aa6_GRAP_3f_FillRect(8, 0x80, 0x137, 0xbf);
    ULTIMA_1bf2_SetTextPosition(3, 0x11);

    ULTIMA_1850_PrintString(_TEXT(0xa06a, "By what name shalt thou be known?"));
    ULTIMA_1bf2_SetTextPosition(0xe, 0x13);
    ULTIMA_16ba_PrintChar(0x3a);
    ULTIMA_1e38_IntroGetString(D_55a8_party[0].name, 8);

    if (D_55a8_party[0].name[0] != 0)
    {
        ULTIMA_1bf2_SetTextPosition(8, 0x15);
        ULTIMA_1850_PrintString(_TEXT(0xa08c, "Art thou Male or Female? "));

        do
        {
            local_4 = ULTIMA_2032_ToUpper(ULTIMA_1dda_WaitForKeystroke(0));
            if (local_4 == 'M')
                break;
        } while (local_4 != 'F');

        ULTIMA_16ba_PrintChar(local_4);
        if (local_4 == 'M')
        {
            D_55a8_party[0].gender = 0xb;
        }
        else
        {
            D_55a8_party[0].gender = 0xc;
        }

        D_5156 = 0;
        D_5158 = 9;
        D_5146[0] = 0;
        D_514c[0] = 0x140;
        D_5146[1] = 0xaf;
        D_514c[1] = 0x140;
        D_5150 = 0x59;
        D_5152 = 200;

#if defined(ENABLE_BGM)
        AUDIO_StopBgm();
#endif

        ULTIMA_256e_ReadFileFromDisk(/*0xa0a6*/ "QUESTION.DAT", D_b21e, 2000, 0);

        ULTIMA_0c22_GRAP_0f_SelectPage(1);
        D_a9bd[1] = 2;
        ULTIMA_16ba_PrintChar(CTRL_CHAR_CLEAR_WINDOW);
        ULTIMA_0d4c_GRAP_4b_PutImage(local_6, 0, 0, 0x60, 0);
        FONT_0000(local_a, D_b21e);
        ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);

        D_5150 = 200;

        while (ULTIMA_1d5e_PollKey() == 0) {}

        D_bd3c = D_55a8_party[0].intel;
        D_bd3d = D_55a8_party[0].dex;
        D_bd3e = D_55a8_party[0].str;

        for (local_8 = 0; local_8 < 8; local_8++)
        {
            D_bd2a[local_8] = D_bd32[local_8] = 0;
        }

        for (local_8 = 0; local_8 < 4; local_8++)
        {
            FONT_09c8(local_a, local_6);
        }

        for (local_8 = 0; local_8 < 8; local_8++)
        {
            D_bd2a[local_8] = 0;
        }

        for (local_8 = 0; local_8 < 2; local_8++)
        {
            FONT_09c8(local_a, local_6);
        }

        for (local_8 = 0; local_8 < 8; local_8++)
        {
            D_bd2a[local_8] = 0;
        }

        FONT_09c8(local_a, local_6);

        D_5156 = D_5158 = 0;
        D_5150 = 0x5a;
        D_5146[1] = 0;
        D_514c[1] = 0xa6;
        D_5154 = 4;

        ULTIMA_256e_ReadFileFromDisk(/*0xa0b4*/ "QUESTION.DAT", D_b21e, 2000, 0x322);
        ULTIMA_0c22_GRAP_0f_SelectPage(1);
        ULTIMA_16ba_PrintChar(CTRL_CHAR_CLEAR_WINDOW);
        ULTIMA_0d4c_GRAP_4b_PutImage(local_6, 10, 0xa8, 100, 0);

        FONT_0000(local_a, D_b21e);
        D_5154 = 5;
        ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);

        while (ULTIMA_1d5e_PollKey() == 0)
        {}

        ULTIMA_0be4_FreeImage(local_6);
        ULTIMA_0fdc_FreeBitImage(local_a);

        ULTIMA_0c22_GRAP_0f_SelectPage(1);
        ULTIMA_16ba_PrintChar(CTRL_CHAR_CLEAR_WINDOW);
        ULTIMA_0c22_GRAP_0f_SelectPage(0);

        D_a9bd[1] = 0;
        
        D_55a8_party[0].mag = D_55a8_party[0].intel = D_bd3c;
        D_55a8_party[0].dex = D_bd3d;
        //D_55a8_party[0]._c = (D_bd3e - 0x14 & ~-(D_bd3e < 0x14)) + 0x14;
        D_55a8_party[0].str = D_bd3e <= 0x14 ? 0x14 : D_bd3e;
        ULTIMA_256e_ReadFileFromDisk(/*0xa0c2*/ "INIT.OOL", D_b31e, 0x100, 0);
        ULTIMA_16ba_PrintChar(CTRL_CHAR_CLEAR_WINDOW);
        ULTIMA_1bf2_SetTextPosition(0, 10);
        ULTIMA_251e_SwitchDisks(3);

        // NOT MATCHING: sub al, al vs sub ax, ax
        memset(D_b21e, 0, 0x100);

        ULTIMA_25d8_WriteFileToDisk(/*0xa0cc*/ "SAVED.OOL", D_b21e, 0x200);
#if !defined(TARGET_DOS16)
        FILE_WriteSavegameFile(/*0xa0d6*/ "SAVED.GAM");
#else
        ULTIMA_25d8_WriteFileToDisk(/*0xa0d6*/ "SAVED.GAM", &D_55a6, (int)&D_6606 - (int)&D_55a6);
#endif
    }

    ULTIMA_251e_SwitchDisks(0);
    D_5893_map_id = 0x40;
}

// STUB (burning up some cpu cycles -> FLAMES. FMT: nop)
static void FONT_0e52(void) {}

// STUB (burning up some cpu cycles. FMT: nop)
static void FONT_0e7b(void) {}
