#include "COMMON.H"
#include "FILE.H"
#include "FUNCS.H"
#include "VARS.H"

#include <string.h>

// NOT MATCHING
// param_1: image, param_2: text
void FONT_0000(byte* param_1, char* param_2)
{
    char cVar1;
    int iVar2;
    int iVar3;
    int local_e;
    int local_c;
    int local_a;
    int local_8;
    int local_4;

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    if (D_5150 < D_5158 && D_5158 < D_5152)
    {
        iVar2 = 1;
    }
    else
    {
        iVar2 = 0;
    }

    local_c = D_514c[iVar2] - D_5146[iVar2];
    local_e = 0;
    local_4 = D_5156 - D_5146[iVar2];
    while (1)
    {
        if (param_2[local_e] == '\0')
        {
            ULTIMA_0c22_GRAP_0f_SelectPage(0);
            return;
        }

        local_a = 0;
        for (iVar2 = local_e; param_2[iVar2] != '\0' && local_4 < local_c && param_2[iVar2] != '\n'; iVar2++)
        {
            if (param_2[iVar2] < 0x21)
            {
                local_4 += D_5154;
                local_a += 1;
            }
            else if (param_2[iVar2] == '{')
            {
                local_4 += 0xf;
            }
            else if (param_2[iVar2] != '_')
            {
                local_4 += D_50eb[param_2[iVar2] - 0x21] + 1;
            }
        }

        while (1)
        {
            if ((param_2[iVar2] == '\0' && local_4 < local_c) || param_2[iVar2] == '\n' || --iVar2 <= local_e)
                break;

            if (param_2[iVar2] == ' ')
            {
                local_4 -= D_5154;
                local_a--;
                break;
            }

            if (param_2[iVar2] == '_' && (uint)D_50f7 + local_4 + 1 < local_c)
            {
                local_4 += D_50f7 + 1;
                break;
            }

            if (param_2[iVar2] != '_' && param_2[iVar2] != '{')
            {
                local_4 -= D_50eb[param_2[iVar2] - 0x21] + 1;
            }
        }

        local_8 = local_c - local_4;
        for (; local_e < iVar2; local_e++)
        {
            cVar1 = param_2[iVar2];
            if (param_2[local_e] < 0x21)
            {
                D_5156 += D_5154;
                if (local_a != 0 && cVar1 != '\0' && cVar1 != '\n')
                {
                    D_5156 += local_8 / local_a;
                    local_8 -= local_8 / local_a;
                    local_a--;
                }
            }
            else if (param_2[local_e] == '{')
            {
                D_5156 += 0xf;
            }
            else if (param_2[local_e] != '_')
            {
                if (D_5158 < 0xc0)
                {
                    // NOTE: "or" mix
                    ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(param_1, param_2[local_e] - 0x20, D_5156, D_5158);
                }
                D_5156 += D_50eb[param_2[local_e] - 0x21] + 1;
            }
        }

        local_e = iVar2;
        if (param_2[iVar2] != '\0')
        {
            if (param_2[iVar2] == '_' && D_5158 < 0xc0)
            {
                ULTIMA_1044_GRAP_4e_CopyBitImageIntoPage(param_1, 0xd, D_5156, D_5158);
            }

            local_4 = 0;
            D_5158 += 9;
            if (D_5150 < D_5158 && D_5158 < D_5152)
            {
                iVar3 = 1;
            }
            else
            {
                iVar3 = 0;
            }

            D_5156 = D_5146[iVar3];
            local_c = D_514c[iVar3] - D_5156;
            local_e = iVar2 + 1;
        }
    }
}

// NOT MATCHING
void FONT_02a2(int param_1, int param_2)
{
    byte bVar1;
    byte cVar2;

    bVar1 = D_6608[param_1 + param_2 * 0x20];
    if (bVar1 != 0)
    {
        ULTIMA_10e0_GRAP_51_PutTile(D_b11e[bVar1], param_1, param_2 + 7);
    }
    else
    {
        cVar2 = D_6608[param_1 + param_2 * 0x20 + 0x80];
        if (cVar2 == 0x16)
        {
            return;
        }

        ULTIMA_10e0_GRAP_51_PutTile(0x100 + cVar2, param_1, param_2 + 7);
    }
}

void INTRO_2090_AnimateWD(void);

// NOT MATCHING
int FONT_02fc(int param_1)
{
    int iVar1;
    int iVar3;
    uint uStack_6;

    do
    {
        ULTIMA_4552_AnimateActors();
        INTRO_2090_AnimateWD();

        for (iVar3 = 0; iVar3 < 0x20; iVar3++)
        {
            if (D_5c5a[iVar3]._0_tile != 0)
            {
                iVar1 = D_5c5a[iVar3]._3_y * 0x20 + D_5c5a[iVar3]._2_x;
                D_6608[iVar1] = 0;
                D_6608[iVar1 + 0x80] = D_5c5a[iVar3]._1;
            }
        }

        for (uStack_6 = D_bd26; uStack_6 <= D_bd27; uStack_6++)
        {
            for (iVar1 = 0; iVar1 < 4; iVar1++)
            {
                if (D_6608[uStack_6 + iVar1 * 0x20] != 0xfe)
                {
                    FONT_02a2(uStack_6, iVar1);
                }
            }
        }

        if (D_bd26 != 0 && D_bd28 != 0)
        {
            D_bd26 -= 1;
            D_bd27 += 1;
        }

        D_bd28 = !D_bd28;

        if (ULTIMA_1d5e_PeekKeystroke() != 0)
        {
            return 1;
        }

        if (param_1 != 0)
        {
            ULTIMA_20fa_WaitTicks(1);
        }

        if (D_bd29 == 2)
        {
            ULTIMA_223c_AudioNoise(0x14, 0x3c, 10000);
        }
        else if (D_bd29 == 3)
        {
            D_515a++;
            if (D_515a > 7)
            {
                D_515a = 0;
            }

            if (D_515a == 0)
            {
                ULTIMA_22c0_AudioPlayTone(3000, 3);
            }
            else if (D_515a == 4)
            {
                ULTIMA_22c0_AudioPlayTone(2000, 3);
            }
        }

        param_1--;
        if (param_1 == 0)
        {
            return 0;
        }
    } while (1);
}

void INTRO_043e(char* param_1);

// NOT MATCHING
void FONT_0418(int param_1)
{
    int local_6;
    int local_4;

    ASSERT(param_1 < 4);

    INTRO_043e(D_515c[param_1]);

    for (local_4 = 0; local_4 < 0x13; local_4++)
    {
        for (local_6 = 0; local_6 < 4; local_6++)
        {
            D_6708[local_4 + local_6 * 0x20] =
                D_6608[local_4 + local_6 * 0x20] =
                D_b21e[param_1 * 0x80 + local_4 + local_6 * 0x20];
        }
    }

    D_bd27 = 9;
    D_bd26 = 9;
    D_bd28 = 0;
    D_bd29 = param_1;
}

void FONT_0e52(void);
void FONT_0e7b(void);

// NOT MATCHING
// "view"
void FONT_04a4(void)
{
    byte bVar1;
    byte bVar2;
    byte uVar3;
    int iVar4;
    int uVar5;
    int local_16;
    int local_10;
    int local_e;
    int local_8;
    int local_6;
    int local_4;

    int local_14;

    int i;

    D_52ba_vdp._52be = 0x10;
    D_bd27 = 9;
    D_bd26 = 9;
    D_bd28 = 0;

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
    ULTIMA_0aa6_GRAP_3f_FillRect(0x78, 0x78, 199, 0x7e);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(0x78, 0x7f, 199, 0x7f);

    if (D_5893_map_id != 0x42)
    {
        ULTIMA_256e_ReadFile(/*0xa044*/ "MISCMAPS.DAT", D_b21e, 2000, 0x2c0);
        if (D_5893_map_id == 0x40)
        {
            FONT_0e52();
            do
            {
                iVar4 = ULTIMA_0ff4_LoadTileset(*D_25f0);
            } while (iVar4 == 0);
            FONT_0e7b();
        }
    }

    D_5893_map_id = 0x42;

    for (local_e = 0x200; local_e < 2000; local_e++)
    {
        switch (D_b21e[local_e])
        {
        case 0:
            uVar5 = D_b21e[++local_e];
            D_5c5a[uVar5]._0_tile = D_5c5a[uVar5]._1 = D_b21e[++local_e];
            D_5c5a[uVar5]._2_x = D_b21e[++local_e];
            D_5c5a[uVar5]._3_y = D_b21e[++local_e];
            D_5c5a[uVar5]._6 = 0;
            break;

        case 1:
            uVar5 = D_b21e[++local_e];
            D_5c5a[uVar5]._6 = 0;
            D_5c5a[uVar5]._1 = 0;
            D_5c5a[uVar5]._0_tile = 0;

            D_6608[D_5c5a[uVar5]._3_y * 0x20 + D_5c5a[uVar5]._2_x] =
                D_6708[D_5c5a[uVar5]._3_y * 0x20 + D_5c5a[uVar5]._2_x];
            break;

        case 2:
            uVar5 = D_b21e[++local_e];
            D_6608[D_5c5a[uVar5]._3_y * 0x20 + D_5c5a[uVar5]._2_x] =
                D_6708[D_5c5a[uVar5]._3_y * 0x20 + D_5c5a[uVar5]._2_x];
            bVar2 = D_b21e[++local_e];
            D_5c5a[uVar5]._2_x += D_24d6[bVar2];
            D_5c5a[uVar5]._3_y += D_24de[bVar2];
            break;

        case 3:
            uVar3 = D_b21e[++local_e];
            iVar4 = FONT_02fc(uVar3);
            if (iVar4 != 0)
            {
                return;
            }
            break;

        case 4:
            local_6 = D_b21e[++local_e];
            local_8 = D_b21e[++local_e];
            D_6708[local_8 * 0x20 + local_6] = 0xfe;
            D_6608[local_8 * 0x20 + local_6] = 0xfe;

            for (iVar4 = 1; iVar4 < 0x10; iVar4++)
            {
                ULTIMA_1112_GRAP_60(iVar4, local_6, local_8 + 7);
                if (FONT_02fc(1) != 0)
                {
                    return;
                }
            }

            D_6608[local_8 * 0x20 + local_6] = D_6708[local_8 * 0x20 + local_6] = 0xdc;
            if (FONT_02fc(2) != 0)
            {
                return;
            }
            break;

        case 5:
            D_6608[local_8 * 0x20 + local_6] = D_6708[local_8 * 0x20 + local_6] = 0xfe;

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

            D_6608[local_8 * 0x20 + local_6] = D_6708[local_8 * 0x20 + local_6] = 5;
            if (FONT_02fc(2) != 0)
            {
                return;
            }
            break;

        case 6:
            FONT_0418(D_b21e[++local_e]);
            break;

        case 7:
            bVar2 = D_b21e[++local_e];
            uVar3 = D_5c5a[bVar2]._0_tile;
            D_5c5a[bVar2]._1 = 0x16;
            D_5c5a[bVar2]._0_tile = 0x16;

            if (ULTIMA_1068(0x100 + uVar3, D_5c5a[bVar2]._2_x, D_5c5a[bVar2]._3_y + 7) != 0)
            {
                return;
            }
            D_5c5a[bVar2]._0_tile = D_5c5a[bVar2]._1 = uVar3;
            break;

        case 8:
            iVar4 = D_b21e[++local_e];
            bVar2 = D_5c5a[iVar4]._2_x;
            bVar1 = D_5c5a[iVar4]._3_y;
            uVar3 = D_5c5a[iVar4]._0_tile;
            D_5c5a[iVar4]._1 = 0x16;
            D_5c5a[iVar4]._0_tile = 0x16;

            if (ULTIMA_1068(D_6708[bVar2 + bVar1 * 0x20], bVar2, bVar1 + 7) != 0)
            {
                return;
            }

            D_5c5a[iVar4]._0_tile = D_5c5a[iVar4]._1 = uVar3;
            break;

        case 9:
            local_e = 0x1ff;
            break;

        case 10:
            uVar3 = D_b21e[++local_e];
            local_14 = D_b21e[++local_e];
            iVar4 = local_14 + D_b21e[++local_e] * 0x20;
            D_6708[iVar4] = uVar3;
            D_6608[iVar4] = uVar3;
            break;

        case 0xb:
            for (local_10 = 0; local_10 < 5; local_10++)
            {
                if (FONT_02fc(1) != 0)
                {
                    return;
                }
                ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
                ULTIMA_0b10_GRAP_Line(local_10 * 9 + 0x80, local_10 * 3 + 0x98, local_10 * 9 + 0x89,
                                        local_10 * 3 + 0x9b);
                ULTIMA_0b10_GRAP_Line(local_10 * 9 + 0x80, local_10 * 3 + 0x99, local_10 * 9 + 0x89,
                                        local_10 * 3 + 0x9c);
            }

            ULTIMA_10e0_GRAP_51_PutTile(0, D_5c5a[D_b21e[local_e + 2]]._2_x, D_5c5a[D_b21e[local_e + 2]]._3_y + 7);
            ULTIMA_223c_AudioNoise(1, 0x4b0, 4000);
            uVar3 = 3;
            local_e += 2;
            if (FONT_02fc(uVar3) != 0)
            {
                return;
            }
            break;

        case 0xc:
            for (i = 0; i < 0x20; i++)
            {
                D_5c5a[i]._1 = D_5c5a[i]._0_tile = D_5c5a[i]._6 = 0;
            }
            break;

        case 0xd:
            uVar5 = D_b21e[++local_e];
            bVar2 = D_b21e[++local_e];
            iVar4 = D_5c5a[uVar5]._3_y * 0x20 + D_5c5a[uVar5]._2_x;
            D_6608[iVar4] = D_6708[iVar4];
            D_5c5a[uVar5]._2_x += D_24d6[bVar2];
            D_5c5a[uVar5]._3_y += D_24de[bVar2];
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

        if (ULTIMA_1d5e_PeekKeystroke() != 0)
        {
            return;
        }
    }
}

// 0998 ~ 0b0a: character creation

// NOT MATCHING
int FONT_0998(void)
{
    int iVar1;

    do
    {
        do
        {
            iVar1 = ULTIMA_2092_RandomRange(0, 7);
        } while (D_bd2a[iVar1] != 0);
    } while (D_bd32[iVar1] != 0);

    D_bd2a[iVar1] = 1;

    return iVar1;
}

// NOT MATCHING
void FONT_09c8(byte* param_1, byte* param_2)
{
    int local_10;
    int local_e;
    int local_a;
    byte local_c;
    int local_8;
    int local_6;
    byte local_4;

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_0d4c_GRAP_4b_PutImage(param_2, 1, 0x10, 0, 0);
    ULTIMA_0d4c_GRAP_4b_PutImage(param_2, 1, 200, 0, 0);

    D_5156 = 0;
    D_5158 = 0x98;

    local_6 = FONT_0998();
    local_8 = FONT_0998();
    if (local_8 < local_6)
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
    ULTIMA_256e_ReadFile(/*0xa052*/ "QUESTION.DAT", D_b21e, 2000, D_517c[local_8 + local_6 * 8]);
    FONT_0000(param_1, (char*)D_b21e);
    ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);

    do
    {
        local_4 = ULTIMA_2032_ToUpper(ULTIMA_1d5e_PeekKeystroke());
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

// NOT MATCHING
void FONT_0b0a(void)
{
    char cVar4;
    byte* pVar5;
    byte* pVar6;
    int iVar8;
    byte bVar9;
    int i;

    if (D_5893_map_id != 64)
    {
        ULTIMA_102e_UnloadTileset();
    }

    D_a9cb = 0xff;

    do
    {
        pVar5 = ULTIMA_0fae_LoadFile(D_25ea[0]);
    } while (pVar5 == 0);

    do
    {
        pVar6 = ULTIMA_0bae_LoadImageFile(D_25ea[0x10]);
    } while (pVar6 == 0);

    FILE_ReadSavegameFile(/*0xa060*/ "INIT.GAM");
    //ULTIMA_256e_read_file_from_disk(/*0xa060*/ "INIT.GAM", D_55a6, 0x1060, 0);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
    ULTIMA_0aa6_GRAP_3f_FillRect(0x78, 0x78, 200, 0x7e);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(0x78, 0x7f, 200, 0x7f);
    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    ULTIMA_0aa6_GRAP_3f_FillRect(8, 0x80, 0x137, 0xbf);
    ULTIMA_1bf2_SetTextPosition(3, 0x11);

    ULTIMA_1850_PrintString(/*0xa06a*/ "By what name shalt thou be known?");
    ULTIMA_1bf2_SetTextPosition(0xe, 0x13);
    ULTIMA_16ba_PrintChar(0x3a);
    ULTIMA_1e38_IntroGetString(D_55a8_party[0]._0, 8);

    if (D_55a8_party[0]._0[0] != 0)
    {
        ULTIMA_1bf2_SetTextPosition(8, 0x15);
        ULTIMA_1850_PrintString(/*0xa08c*/ "Art thou Male or Female? ");

        do
        {
            cVar4 = ULTIMA_2032_ToUpper(ULTIMA_1dda_WaitForKeystroke(0));
            if (cVar4 == 'M')
                break;
        } while (cVar4 != 'F');

        ULTIMA_16ba_PrintChar(cVar4);
        if (cVar4 == 'M')
        {
            D_55a8_party[0]._9 = 0xb;
        }
        else
        {
            D_55a8_party[0]._9 = 0xc;
        }

        D_5156 = 0;
        D_5158 = 9;
        D_5146[0] = 0;
        D_514c[0] = 0x140;
        D_5146[1] = 0xaf;
        D_514c[1] = 0x140;
        D_5150 = 0x59;
        D_5152 = 200;

        ULTIMA_256e_ReadFile(/*0xa0a6*/ "QUESTION.DAT", D_b21e, 2000, 0);

        ULTIMA_0c22_GRAP_0f_SelectPage(1);
        D_a9be = 2;
        ULTIMA_16ba_PrintChar(0xff);
        ULTIMA_0d4c_GRAP_4b_PutImage(pVar6, 0, 0, 0x60, 0);
        FONT_0000(pVar5, (char*)D_b21e);
        ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);

        D_5150 = 200;

        do
        {
            iVar8 = ULTIMA_1d5e_PeekKeystroke();
        } while (iVar8 == 0);

        D_bd3c = D_55a8_party[0]._e;
        D_bd3d = D_55a8_party[0]._d;
        D_bd3e = D_55a8_party[0]._c;

        for (bVar9 = 0; bVar9 < 8; bVar9++)
        {
            D_bd32[bVar9] = 0;
            D_bd2a[bVar9] = 0;
        }

        for (iVar8 = 0; iVar8 < 4; iVar8++)
        {
            FONT_09c8(pVar5, pVar6);
        }

        memset(D_bd2a, 0, 8);

        for (iVar8 = 0; iVar8 < 2; iVar8++)
        {
            FONT_09c8(pVar5, pVar6);
        }

        memset(D_bd2a, 0, 8);

        FONT_09c8(pVar5, pVar6);

        D_5158 = 0;
        D_5156 = 0;
        D_5150 = 0x5a;
        D_5146[1] = 0;
        D_514c[1] = 0xa6;
        D_5154 = 4;

        ULTIMA_256e_ReadFile(/*0xa0b4*/ "QUESTION.DAT", D_b21e, 2000, 0x322);
        ULTIMA_0c22_GRAP_0f_SelectPage(1);
        ULTIMA_16ba_PrintChar(0xff);
        ULTIMA_0d4c_GRAP_4b_PutImage(pVar6, 10, 0xa8, 100, 0);

        FONT_0000(pVar5, (char*)D_b21e);
        D_5154 = 5;
        ULTIMA_0f6e_GRAP_1b_TransferFullscreen(1, 0);

        while (ULTIMA_1d5e_PeekKeystroke() == 0)
            ;

        ULTIMA_0be4_FreeImage(pVar6);
        ULTIMA_0fdc_FreeBitImage(pVar5);

        ULTIMA_0c22_GRAP_0f_SelectPage(1);
        ULTIMA_16ba_PrintChar(0xff);
        ULTIMA_0c22_GRAP_0f_SelectPage(0);

        D_a9be = 0;
        
        D_55a8_party[0]._f = D_55a8_party[0]._e = D_bd3c;
        D_55a8_party[0]._d = D_bd3d;
        //D_55a8_party[0]._c = (D_bd3e - 0x14 & ~-(D_bd3e < 0x14)) + 0x14;
        D_55a8_party[0]._c = D_bd3e <= 0x14 ? 0x14 : D_bd3e;
        ULTIMA_256e_ReadFile(/*0xa0c2*/ "INIT.OOL", D_b31e, 0x100, 0);
        ULTIMA_16ba_PrintChar(0xff);
        ULTIMA_1bf2_SetTextPosition(0, 10);
        ULTIMA_251e_SwitchDisks(3);

        for (i = 0; i < 0x100; i++)
        {
            D_b21e[i] = 0;
        }

        ULTIMA_25d8_WriteFile(/*0xa0cc*/ "SAVED.OOL", D_b21e, 0x200);
        FILE_WriteSavegameFile(/*0xa0d6*/ "SAVED.GAM");
        //ULTIMA_25d8_write_file_to_disk(/*0xa0d6*/ "SAVED.GAM", D_55a6, 0x1060);
    }

    ULTIMA_251e_SwitchDisks(0);
    D_5893_map_id = 0x40;
}

// STUB (burning up some cpu cycles. FMT: nop)
void FONT_0e52(void) {}

// STUB (burning up some cpu cycles. FMT: nop)
void FONT_0e7b(void) {}
