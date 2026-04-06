#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include "GRAP_DRV.H"

#include <stdio.h>
#include <string.h>

void SJOG_203e(int a);

// OK P1 (NOTE: combine arrays?)
void ULTIMA_60ec_LoadSpecialMap(int param_1)
{
    int local_4;

    ULTIMA_256e_ReadFile("BRIT.CBT", D_ad14, 0x160, param_1 * 0x160);

    for (local_4 = 0; local_4 < 6; local_4++)
    {
        D_1724[local_4] = D_ad14[0x6b + local_4];
        D_172c[local_4] = D_ad14[0x71 + local_4];
    }

    for (local_4 = 0; local_4 < 0x10; local_4++)
    {
        D_1704[local_4] = D_ad14[0xcb + local_4];
        D_1714[local_4] = D_ad14[0xeb + local_4];
    }
}

void ULTIMA_5f86_SpecialMapHandler(int a, int b, int c);

void ULTIMA_6150_Attack(int param_1)
{
    byte bVar1;
    bool bVar2;
    uint uVar3;
    undefined2 local_4;

    uVar3 = D_5c5a[param_1]._0_tile & 0xfc;

    ULTIMA_16ba_PrintChar(10);
    ULTIMA_16ba_PrintChar(0xfc);
    if (uVar3 < 0x40)
    {
        ULTIMA_1850_PrintString("PIRATES");
    }
    else
    {
        ULTIMA_1850_PrintString(D_18b6[(uVar3 - 0x40) / 4]);
    }
    ULTIMA_16ba_PrintChar(0xfb);
    ULTIMA_1850_PrintString("\n\n");

    bVar1 = *ULTIMA_4402_GetTileAddr(D_5c5a[param_1]._2_x, D_5c5a[param_1]._3_y);
    if (bVar1 < 4 || (bVar1 & 0xfe) != 0x6a && ((bVar1 & 0xf0) == 0x60))
    {
        bVar2 = 1;
    }
    else
    {
        bVar2 = 0;
    }

    if (uVar3 == 0xfc)
    {
        local_4 = 10;
        if (D_57b5 != 0)
        {
            ULTIMA_1850_PrintString("The Sceptre is reclaimed!\n");
            ULTIMA_2192_AudioSomeNoise(0xfd2, 1, 65000, 1, 1);
            D_57b5 = 0;
        }
    }
    else if (((byte)uVar3 & 0xf0) == 0x80)
    {
        bVar2 = 1;
    }

    if ((D_587c & 0xf8) == 0x20)
    {
        if (uVar3 == 0x2c)
        {
            local_4 = 0xe;
        }
        else if (bVar2)
        {
            local_4 = 0xb;
        }
        else
        {
            local_4 = 0xd;
        }
    }
    else if (uVar3 == 0x2c)
    {
        local_4 = 0xc;
    }
    else if (bVar2)
    {
        local_4 = 0xf;
    }
    else
    {
        switch (bVar1)
        {
        case 1:
        case 2:
        case 3:
            local_4 = 0xf;
            break;
        case 4:
            local_4 = 1;
            break;
        case 6:
        case 8:
            local_4 = 3;
            break;
        case 7:
        case 0x1e:
        case 0x1f:
            local_4 = 4;
            break;
        case 9:
        case 10:
            local_4 = 5;
            break;
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xe:
        case 0xf:
            local_4 = 6;
            break;
        default:
            if (D_5893_map_id != '\0')
                local_4 = 8;
            // fall-through
        case 5:
            local_4 = 2;
            break;
        case 0x1d:
        case 0x48:
        case 0x49:
        case 0x6a:
        case 0x6b:
            local_4 = 7;
            break;
        case 0x44:
            local_4 = 8;
            break;
        }
    }

    ULTIMA_60ec_LoadSpecialMap(local_4);
    ULTIMA_5f86_SpecialMapHandler(0, param_1, 0);
    SJOG_203e(param_1);
    ULTIMA_5e4a();
    ULTIMA_4f7c(0);
}

void ULTIMA_6360_Camping(int param_1, int param_2)
{
    ULTIMA_60ec_LoadSpecialMap(0);
    ULTIMA_5f86_SpecialMapHandler(4, param_1, param_2);
    ULTIMA_5e4a();
}

// draw_frame
// FMT: 26840
void ULTIMA_637e_DrawFrame(void)
{
    // black
    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    ULTIMA_0aa6_GRAP_3f_FillRect(0, 0, 319, 199);

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
    ULTIMA_0aa6_GRAP_3f_FillRect(0, 0, 319, 6);
    ULTIMA_0aa6_GRAP_3f_FillRect(0, 185, 191, 191);
    ULTIMA_0aa6_GRAP_3f_FillRect(0, 0, 6, 191);
    ULTIMA_0aa6_GRAP_3f_FillRect(185, 0, 191, 191);
    ULTIMA_0aa6_GRAP_3f_FillRect(313, 0, 319, 87);
    ULTIMA_0aa6_GRAP_3f_FillRect(192, 80, 312, 87);
    ULTIMA_0aa6_GRAP_3f_FillRect(192, 0x39, 312, 63);

    ULTIMA_1cca_SetTextForegroundColor(D_13b2_frame_color);
    ULTIMA_1bf2_SetTextPosition(0, 0);
    ULTIMA_16ba_PrintChar(0x7b);
    ULTIMA_1bf2_SetTextPosition(39, 0);
    ULTIMA_16ba_PrintChar(0x7c);
    ULTIMA_1bf2_SetTextPosition(0, 23);
    ULTIMA_16ba_PrintChar(0x7d);

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(7, 7, 7, 184);
    ULTIMA_0f90_GRAP_Pen(184, 184);
    ULTIMA_0f90_GRAP_Pen(184, 7);
    ULTIMA_0f90_GRAP_Pen(7, 7);
    ULTIMA_0b10_GRAP_Line(191, 191, 191, 87);
    ULTIMA_0f90_GRAP_Pen(319, 87);
    ULTIMA_0b10_GRAP_Line(191, 7, 312, 7);
    ULTIMA_0f90_GRAP_Pen(312, 56);
    ULTIMA_0f90_GRAP_Pen(191, 56);
    ULTIMA_0f90_GRAP_Pen(191, 7);
    ULTIMA_0b10_GRAP_Line(191, 63, 312, 63);
    ULTIMA_0f90_GRAP_Pen(312, 80);
    ULTIMA_0f90_GRAP_Pen(191, 80);
    ULTIMA_0f90_GRAP_Pen(191, 63);

    ULTIMA_1cca_SetTextForegroundColor(D_13b0_white_color);
}

// NOT MATCHING
int ULTIMA_6506(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    byte bVar2;
    uint uVar7;
    uint uStack_a;
    int uStack_8;

    uStack_a = 0;
    uStack_8 = -1;
    if (param_2 != 2)
    {
        if (param_2 == 0)
        {
            uStack_a = 6;
        }
        if (uStack_a < 0x20)
        {
            for (; uStack_a < 0x20; uStack_a++)
            {
                if (D_ba14[uStack_a]._2 == 0)
                {
                    if ((param_2 == 1) && (D_55a8_party[param_1]._b != 'D'))
                    {
                        D_ba14[uStack_a]._1 = D_55a8_party[param_1]._d;
                        D_ba14[uStack_a]._5 = 36 - D_ba14[uStack_a]._1;
                        D_ba14[uStack_a]._2 = 0x80;
                        if (D_55a8_party[param_1]._b != 'G' && D_55a8_party[param_1]._b != 'P')
                        {
                            D_ba14[uStack_a]._2 |= 8;
                        }
                    }
                    if (param_2 == 0)
                    {
                        D_ba14[uStack_a]._0 = D_13bc[param_1]._5;
                        bVar2 = ULTIMA_3aae(7) - 4 + D_13bc[param_1]._1;
                        D_ba14[uStack_a]._1 = bVar2;
                        if (0x1e < bVar2)
                        {
                            D_ba14[uStack_a]._1 = D_13bc[param_1]._1;
                        }
                        D_ba14[uStack_a]._5 = 36 - D_ba14[uStack_a]._1;
                        D_ba14[uStack_a]._2 = 0x40;
                        if (param_1 == 8 || param_1 == 9)
                        {
                            D_ba14[uStack_a]._2 = 0x20;
                        }
                    }
                    D_ba14[uStack_a]._3 = (char)param_1;
                    D_ba14[uStack_a]._6 = param_3;
                    D_ba14[uStack_a]._7 = param_4;
                    uStack_8 = uStack_a;
                    break;
                }
            }
        }
    }

    if (uStack_8 > -1 || (param_2 == 2))
    {
        for (uVar7 = 0; uVar7 < 0x20; uVar7++)
        {
            if (D_5c5a[uVar7]._0_tile == 0)
            {
                if (param_2 == 0)
                {
                    D_ba14[uStack_a]._4 = uVar7;
                    D_5c5a[uVar7]._0_tile = param_1 * 4 + 64;
                    D_5c5a[uVar7]._1 = param_1 * 4 + 64;
                }
                if (param_2 == 1)
                {
                    D_ba14[uStack_a]._4 = uVar7;
                }
                if (param_2 == 2)
                {
                    D_5c5a[uVar7]._0_tile = (char)param_1;
                    D_5c5a[uVar7]._1 = (char)param_1;
                    uStack_8 = uVar7;
                }
                D_5c5a[uVar7]._2_x = param_3;
                D_5c5a[uVar7]._3_y = param_4;
                D_5c5a[uVar7]._4_z = param_5;
                D_5c5a[uVar7]._7 = 0xff;
                if (param_2 == 0)
                {
                    D_5c5a[uVar7]._5 = D_ba14[uStack_a]._0;
                }
                else
                {
                    D_5c5a[uVar7]._5 = (char)param_1;
                }
                if (param_2 != 2)
                {
                    D_ba14[uStack_a]._4 = uVar7;
                }
                break;
            }
        }

        if (((param_2 == 2) || (uVar7 != 0x20)) || ((int)uStack_8 < 0))
            goto LAB_1000_6751;
    }
    uStack_8 = -1;

LAB_1000_6751:
    if (0 <= uStack_8)
    {
        for (uVar7 = 0; uVar7 < 0x20; uVar7++)
        {
            if (D_5c5a[D_ba14[uVar7]._4]._7 == uStack_8)
            {
                D_5c5a[D_ba14[uVar7]._4]._7 = 0xff;
            }
        }
    }

    return uStack_8;
}

// NOT MATCHING
void ULTIMA_6794(int param_1)
{
    if ((D_ba14[param_1]._2 & 0x80) != 0 && (D_ba14[param_1]._2 & 0x28) == 0)
    {
        if (D_55a8_party[D_ba14[param_1]._3]._1d == '*')
        {
            D_5c5a[D_ba14[param_1]._4]._1 = 0x1d;
            D_ba14[param_1]._2 |= 0x10;
        }
        else if (D_55a8_party[D_ba14[param_1]._3]._1d == ',')
        {
            ULTIMA_400c(D_ba14[param_1]._3); // sic
        }
    }
}

// NOT MATCHING
void ULTIMA_6800(int param_1)
{
    if ((D_ba14[param_1]._2 & 8) != 0)
    {
        if ((D_ba14[param_1]._2 & 0x80) == 0)
        {
            D_5c5a[D_ba14[param_1]._4]._6 = 0;
        }
        else
        {
            D_55a8_party[D_ba14[param_1]._3]._b = 0x47;
            if ((D_ba14[param_1]._2 & 0x10) == 0)
            {
                D_5c5a[D_ba14[param_1]._4]._1 = D_5c5a[D_ba14[param_1]._4]._0_tile;
            }
            else
            {
                D_5c5a[D_ba14[param_1]._4]._1 = 0x1d;
            }
        }
        D_ba14[param_1]._2 &= 0xf7;
    }

    ULTIMA_2900_UpdateVitalsDisplay();
}

// NOT MATCHING
void ULTIMA_6880(int param_1)
{
    if ((D_ba14[param_1]._2 & 0x80) == 0 || D_55a8_party[D_ba14[param_1]._3]._b != 'P')
    {
        ULTIMA_68ae(param_1);
    }
}

// NOT MATCHING
void ULTIMA_68ae(int param_1)
{
    if ((D_ba14[param_1]._2 & 0x80) == 0)
    {
        D_ba14[param_1]._2 |= 8;
        D_58a2 = 4;
        D_5c5a[D_ba14[param_1]._4]._6 = 0xff;
    }
    else
    {
        if (D_55a8_party[D_ba14[param_1]._3]._b == 'D')
        {
            return;
        }

        D_55a8_party[D_ba14[param_1]._3]._b = 'S';
        D_ba14[param_1]._2 |= 8;
        D_5c5a[D_ba14[param_1]._4]._1 = 0x1e;

        if (param_1 == D_587b)
        {
            D_587b = 0xff;
        }

        D_58a2 = 4;

        ULTIMA_2900_UpdateVitalsDisplay();

        if ((D_58a1 & 4) != 0)
        {
            return;
        }
    }

    ULTIMA_5910_UpdateFrame();
}

// NOT MATCHING
void ULTIMA_6936(void)
{
    byte bVar1;
    int iVar2;
    char cStack_10;
    uint uStack_6;

    cStack_10 = 0;
    for (uStack_6 = 0; uStack_6 < 0x20; uStack_6++)
    {
        D_5c5a[uStack_6]._6 = 0;
        D_5c5a[uStack_6]._2_x = 0;
        D_5c5a[uStack_6]._1 = 0;
        D_5c5a[uStack_6]._0_tile = 0;
        D_5c5a[uStack_6]._5 = 0;
        D_5c5a[uStack_6]._4_z = 0;
        D_5c5a[uStack_6]._3_y = 0;

        D_ba14[uStack_6]._3 = 0;
        D_ba14[uStack_6]._2 = 0;
        D_ba14[uStack_6]._1 = 0;
        D_ba14[uStack_6]._0 = 0;

        D_ba14[uStack_6]._7 = 0;
        D_ba14[uStack_6]._6 = 0;
        D_ba14[uStack_6]._5 = 0;
        D_ba14[uStack_6]._4 = 0;
    }

    for (uStack_6 = 0; uStack_6 < D_585b; uStack_6 = uStack_6 + 1)
    {
        if (D_55a8_party[uStack_6]._b != 'D')
        {
            if (D_55a8_party[uStack_6]._1d == '*')
            {
                cStack_10 = '*';
            }
            if (D_55a8_party[uStack_6]._1d == ',')
            {
                cStack_10 = ',';
            }
            if (cStack_10 != 0)
            {
                if (ULTIMA_2092_RandomRange(0, 0xf) == 0xb)
                {
                    ULTIMA_1850_PrintString("A ring has vanished!\n");
                    ULTIMA_43ae(0x4b0, 2000, 1, 0x28);
                    ULTIMA_6e60(uStack_6, cStack_10);
                }
                cStack_10 = 0;
            }

            iVar2 = ULTIMA_6506(uStack_6, 1, D_1724[uStack_6], D_172c[uStack_6], D_5895_map_level);

            D_5c5a[D_ba14[iVar2]._4]._7 = 0xff;

            switch (D_55a8_party[uStack_6]._a)
            {
            case 0x41:
                D_5c5a[D_ba14[iVar2]._4]._0_tile = 0x4c;
                break;
            case 0x42:
            case 0x53:
            case 0x54:
                D_5c5a[D_ba14[iVar2]._4]._0_tile = 0x44;
                break;
            case 0x44:
            case 0x4d:
                D_5c5a[D_ba14[iVar2]._4]._0_tile = 0x40;
                break;
            case 0x46:
            case 0x50:
            case 0x52:
                D_5c5a[D_ba14[iVar2]._4]._0_tile = 0x48;
            }

            D_5c5a[D_ba14[iVar2]._4]._1 = D_5c5a[D_ba14[iVar2]._4]._0_tile;

            if (D_55a8_party[uStack_6]._b == 'S')
            {
                ULTIMA_68ae(iVar2);
            }
            else
            {
                ULTIMA_6794(iVar2);
            }
        }
    }

    if (D_ad14[0xa5] == 0xdc)
    {
        bVar1 = ULTIMA_6506(1, 2, 5, 5, D_5895_map_level);
        D_5c5a[bVar1]._5 = D_5895_map_level * 3 + 7;
        D_ad14[0xa5] = D_bb15;
    }
}

// NOT MATCHING
void ULTIMA_6bc2(int param_1, int param_2)
{
    bool bVar1;
    int iVar4;
    int iVar5;
    uint uVar6;
    int aiStack_28[16];
    uint uStack_8;
    uint uStack_6;
    uint uStack_4;

    bVar1 = param_2 < 0x100;
    if (!bVar1)
    {
        param_2 -= 0x100;
    }
    uStack_8 = (uint)bVar1;
    D_58a0 = 0;
    if ((param_1 & 4) == 0)
    {
        ULTIMA_6936();
    }

    for (iVar4 = 0; iVar4 < 0x10; iVar4++)
    {
        aiStack_28[iVar4] = iVar4;
    }

    if ((param_1 & 4) != 0)
    {
        for (iVar5 = 0; iVar5 < 0xf; iVar5++)
        {
            iVar4 = ULTIMA_2092_RandomRange(0, 0xf);
            // swap
            uStack_6 = aiStack_28[iVar5];
            aiStack_28[iVar5] = aiStack_28[iVar4];
            aiStack_28[iVar4] = uStack_6;
        }
    }

    ULTIMA_1850_PrintString("*** CONFLICT ***\n");
    if (D_5894 == 0 || 0x20 < D_5894 || param_2 == 0xc || uStack_8 == 0)
    {
        uStack_6 = (uint)D_13bc[param_2]._6;
    }
    else
    {
        uStack_6 = 1;
    }

    if (uStack_6 != 8 && uStack_6 != 0x10 && uStack_6 != 1)
    {
        uStack_6 = ULTIMA_2092_RandomRange(1, uStack_6);
        if (D_5959 != 0)
        {
            uStack_6 = ULTIMA_2092_RandomRange(1, uStack_6);
        }
        ULTIMA_5910_UpdateFrame();
        if (0x1f < (int)uStack_6 + 6) // (0x19 < (int)uStack_6)
        {
            uStack_6 = 0x1a;
        }
    }

    ULTIMA_6506(param_2, 0, D_1704[aiStack_28[0]], D_1714[aiStack_28[0]], D_5895_map_level);

    for (uVar6 = 1; uVar6 < uStack_6; uVar6++)
    {
        uStack_4 = param_2;
        if (uVar6 < uStack_6 / 4 + 1 && ULTIMA_3aae(8) == 0)
        {
            uStack_4 = D_16d4[param_2];
        }
        ULTIMA_6506(uStack_4, 0, D_1704[aiStack_28[uVar6]], D_1714[aiStack_28[uVar6]], D_5895_map_level);
    }
}

// OK P1
int ULTIMA_6d82(int param_1, int param_2)
{
    if (param_1 > -1 && param_1 < 11 && param_2 > -1 && param_2 < 11)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int ULTIMA_6da8(int a) { debug("ULTIMA_6da8(%d)", a); }

int ULTIMA_6e60(int param_2, int param_1) { debug("ULTIMA_6e60(%d,%d)", param_2, param_1); }

// from FMT
u8 DAT_000738d8[] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x28, 0x28, 0x28, 0x28, 0x28, 0x20, 0x20,
                     0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
                     0x88, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
                     0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
                     0x10, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
                     0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x10, 0x10, 0x10, 0x10, 0x10,
                     0x10, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
                     0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x10, 0x10, 0x10, 0x10, 0x20};

// from FMT (27c98)
int ULTIMA_6f1e(byte* param_1, char* param_2)
{
    byte bVar1;
    int iVar2;
    int iVar3;
    int local_18;
    char local_14[10];

    local_18 = -1;
    memset(local_14, 0, 10);

    for (iVar2 = 0; iVar2 < 9 && (iVar3 = iVar2, param_1[iVar2] != 0); iVar2++)
    {
        bVar1 = param_1[iVar2] & 0x7f;
        if ((DAT_000738d8[bVar1] & 2) != 0)
        {
            bVar1 = (param_1[iVar2] & 0x7fU) - 0x20;
        }
        local_14[iVar2] = (char)bVar1;
    }

    iVar2 = strncmp(local_14, param_2, iVar3);
    if (iVar2 == 0)
    {
        local_18 = 0;
    }

    return local_18;
}

// assembly (uses al, bx, cx, di)
int ULTIMA_6f90(char* di)
{
    // repne scasb
    return strlen(di);
}

void ULTIMA_6f9e(int param_1)
{
    // bx: not initialized
    byte bl = 0;
    byte bh = 0;
    int ax = param_1 + 3;
    DRV_6c(ax, bl, bh);
}

void ULTIMA_6fbc(int param_1)
{
    // bx: not initialized
    byte bl = 0;
    byte bh = 0;
    DRV_6c(param_1, bl, bh);
}

// DUMMY
void ULTIMA_6fd6(void)
{
    // CLC
    // ax: D_539c
    // DRV_60(D_539c);
}

// NOT MATCHING (asm?)
int ULTIMA_6ff0(register int param_1, register int param_2)
{
    if ((param_1 < 0xb) && (param_2 < 0xb))
    {
        if ((param_1 > 5) || (param_2 > 5))
        {
            if (param_1 > 5)
            {
                param_1 = 10 - param_1;
            }
            if (param_2 > 5)
            {
                param_2 = 10 - param_2;
            }
        }

        return D_6aa8[param_1 + param_2 * 6];
    }

    return 0;
}
