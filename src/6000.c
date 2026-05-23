#include "common/common.h"
#include "funcs.h"
#include "vars.h"

#include "grap_drv.h"
#include "sjog.h"

#include <string.h>

// OK P1 (NOTE: combine arrays?)
static void ULTIMA_60ec_LoadSpecialMap(int param_1)
{
    int local_4;

    ULTIMA_256e_ReadFileFromDisk("BRIT.CBT", D_ad14, 0x160, param_1 * 0x160);

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

// OK P1
void ULTIMA_6150_Attack(int param_1)
{
    int local_6;
    bool local_8;
    int local_a;
    int local_4;

    local_a = D_5c5a[param_1]._0_tile & 0xfc;

    ULTIMA_16ba_PrintChar(10);
    ULTIMA_16ba_PrintChar(0xfc);
    if (local_a < 0x40)
    {
        ULTIMA_1850_PrintString(/*0xa3fa*/ "PIRATES");
    }
    else
    {
        ULTIMA_1850_PrintString(D_18b6[(local_a - 0x40) / 4]);
    }

    ULTIMA_16ba_PrintChar(0xfb);
    ULTIMA_1850_PrintString(/*0xa402*/ "\n\n");

    local_6 = *ULTIMA_4402_GetTileAddr(D_5c5a[param_1]._2_x, D_5c5a[param_1]._3_y);
    if (local_6 < 4 || (local_6 & 0xfe) != 0x6a && ((local_6 & 0xf0) == 0x60))
    {
        local_8 = true;
    }
    else
    {
        local_8 = false;
    }

    if (local_a == 0xfc) // 61f3
    {
        local_4 = 10;
        if (D_57b5 != 0)
        {
            ULTIMA_1850_PrintString(/*0xa406*/ "The Sceptre is reclaimed!\n");
            ULTIMA_2192_AudioPulse(0xfd2, 1, 65000, 1, 1);
            D_57b5 = 0;
        }
    }
    else
    {
        if (((byte)local_a & 0xf0) == 0x80) // 622c
        {
            local_8 = 1;
        }

        if ((D_587c & 0xf8) == 0x20) // 623a
        {
            if (local_a == 0x2c)
            {
                local_4 = 0xe;
            }
            else if (local_8)
            {
                local_4 = 0xb;
            }
            else
            {
                local_4 = 0xd;
            }
        }
        else if (local_a == 0x2c)
        {
            local_4 = 0xc;
        }
        else if (local_8)
        {
            local_4 = 0xf;
        }
        else
        {
            switch (local_6)
            {
            case 1:
            case 2:
            case 3:
                local_4 = 0xf;
                break;
            case 4:
                local_4 = 1;
                break;
            case 5:
                local_4 = 2;
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
            default:
                if (D_5893_map_id != 0)
                {
                    local_4 = 8;
                }
                else
                {
                    local_4 = 2;
                }
                break;
            }
        }
    }

    ULTIMA_60ec_LoadSpecialMap(local_4);
    ULTIMA_5f86_SpecialMapHandler(0, param_1, 0);
    SJOG_203e(param_1);
    ULTIMA_5e4a();
    ULTIMA_4f7c(0);
}

// OK P1
void ULTIMA_6360_Camping(int param_1, int param_2)
{
    ULTIMA_60ec_LoadSpecialMap(0);
    ULTIMA_5f86_SpecialMapHandler(4, param_1, param_2);
    ULTIMA_5e4a();
}

// OK P1
// draw frame
void ULTIMA_637e_DrawFrame(void)
{
    int local_4; // unused
 
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

// CHECKED
// place actor on combat map
// param_2: player / monster?
// return: placed actor idx
int ULTIMA_6506(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    int local_a;
    int local_8;
    int local_6;
    CombatEntity* local_4;

#if !defined(TARGET_DOS16)
    local_4 = NULL;
#endif

    local_a = 0;
    local_6 = 0;
    local_8 = -1;

    if (param_2 != 2)
    {
        if (param_2 == 0)
        {
            local_a = 6;
        }

        // 6531
        for (local_6 = local_a; local_6 < 0x20; local_6++)
        {
            // 653f
            // 6577
            if (D_ba14[local_6]._2 == 0) // combat actor slot not occupied?
            {
                local_4 = &D_ba14[local_6];
                local_8 = local_6;

                // 6587
                if (param_2 == 1 && D_55a8_party[param_1]._b != 'D') // player?
                {
                    // 65a0
                    local_4->_1 = D_55a8_party[param_1]._d;
                    local_4->_5 = 36 - local_4->_1;
                    local_4->_2 = 0x80;
                    // 65b4
                    if (D_55a8_party[param_1]._b != 'G' && D_55a8_party[param_1]._b != 'P')
                    {
                        local_4->_2 |= 8;
                    }
                }

                // 65c5
                if (param_2 == 0) // monster?
                {
                    local_4->_0 = D_13bc[param_1]._5;
                    local_4->_1 = ULTIMA_3aae_Random(7) - 4 + D_13bc[param_1]._1;
                    if (local_4->_1 > 0x1e)
                    {
                        local_4->_1 = D_13bc[param_1]._1;
                    }

                    local_4->_5 = 36 - local_4->_1;
                    local_4->_2 = 0x40;
                    if (param_1 == 8 || param_1 == 9)
                    {
                        // 6609
                        local_4->_2 = 0x20;
                    }
                }

                // 660d
                local_4->_3 = param_1;
                local_4->_6 = param_3;
                local_4->_7 = param_4;
                break;
            }
        }
    }

    // 6625
    if (local_8 > -1 || param_2 == 2)
    {
        // 6634
        for (local_6 = 0; local_6 < 0x20; local_6++)
        {
            if (D_5c5a[local_6]._0_tile == 0)
            {
                // 6685
                if (param_2 == 0)
                {
                    local_4->_4 = local_6;
                    
                    D_5c5a[local_6]._1 = D_5c5a[local_6]._0_tile = param_1 * 4 + 64; // local_14
                }

                // 669a
                if (param_2 == 1)
                {
                    local_4->_4 = local_6;
                }

                // 66a6
                if (param_2 == 2)
                {
                    D_5c5a[local_6]._1 = D_5c5a[local_6]._0_tile = param_1;
                    local_8 = local_6;
                }

                // 66bb
                D_5c5a[local_6]._2_x = param_3;
                D_5c5a[local_6]._3_y = param_4;
                D_5c5a[local_6]._4_z = param_5;
                D_5c5a[local_6]._7 = 0xff;
                if (param_2 == 0)
                {
                    D_5c5a[local_6]._5 = local_4->_0;
                }
                else
                {
                    D_5c5a[local_6]._5 = param_1;
                }

                // 66f8
                if (param_2 != 2)
                {
                    local_4->_4 = local_6;
                }

                break;
            }
        }

        // 6706
        if (param_2 != 2 && local_6 == 0x20 && local_8 > -1)
        {
            local_8 = -1;
        }
    }
    else
    {
        local_8 = -1;
    }

    // 6751
    if (local_8 >= 0)
    {
        for (local_6 = 0; local_6 < 0x20; local_6++)
        {
            if (D_5c5a[D_ba14[local_6]._4]._7 == local_8)
            {
                D_5c5a[D_ba14[local_6]._4]._7 = 0xff;
            }
        }
    }

    return local_8;
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

// OK P1
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
// initialize combat entities
void ULTIMA_6936(void)
{
    byte bVar1;
    int iVar2;
    byte local_10;
    int local_6;
    int local_a;

    local_10 = 0;

    // clear
    for (local_6 = 0; local_6 < 0x20; local_6++)
    {
        D_5c5a[local_6]._3_y = D_5c5a[local_6]._4_z = D_5c5a[local_6]._5 = D_5c5a[local_6]._0_tile = D_5c5a[local_6]._1 = D_5c5a[local_6]._2_x = D_5c5a[local_6]._6 = 0;

        D_ba14[local_6]._0 = D_ba14[local_6]._1 = D_ba14[local_6]._2 = D_ba14[local_6]._3 = 0;

        D_ba14[local_6]._4 = D_ba14[local_6]._5 = D_ba14[local_6]._6 = D_ba14[local_6]._7 = 0;
    }

    // place player party
    for (local_6 = 0; local_6 < D_585b; local_6++)
    {
        if (D_55a8_party[local_6]._b != 'D')
        {
            if (D_55a8_party[local_6]._1d == '*')
            {
                local_10 = '*';
            }
            if (D_55a8_party[local_6]._1d == ',')
            {
                local_10 = ',';
            }
            if (local_10 != 0)
            {
                local_a = ULTIMA_2092_RandomRange(0, 0xf);
                if (local_a == 0xb)
                {
                    ULTIMA_1850_PrintString("A ring has vanished!\n");
                    ULTIMA_43ae_AudioSweepTone(0x4b0, 2000, 1, 0x28);
                    ULTIMA_6e60(local_6, local_10);
                }
                local_10 = 0;
            }

            iVar2 = ULTIMA_6506(local_6, 1, D_1724[local_6], D_172c[local_6], D_5895_map_level);

            D_5c5a[D_ba14[iVar2]._4]._7 = 0xff;

            // setup tile (according to class)
            switch (D_55a8_party[local_6]._a)
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

            if (D_55a8_party[local_6]._b == 'S')
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
// prepare combat
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
        if (uVar6 < uStack_6 / 4 + 1 && ULTIMA_3aae_Random(8) == 0)
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

// OK P1
int ULTIMA_6da8(int param_1)
{
    int local_6;
    S_55a8* local_4;

    local_6 = 0;
    local_4 = &D_55a8_party[param_1];

    if (D_5894 == 40 && local_4->_1a != 0x0f)
    {
        return 0;
    }
    else
    {
        // BUG (portability?)
#if defined(TARGET_DOS16)
#define CMP(a) ((a) > -1)
#else
#define CMP(a) (((s8)(a)) > -1)
#endif
        if (CMP(local_4->_19))
        {
            // 6dd6
            local_6 += D_1634[local_4->_19];
        }

        if (CMP(local_4->_1a))
        {
            // 6dec
            local_6 += D_1634[local_4->_1a];
        }

        if (CMP(local_4->_1b))
        {
            // 6dff
            local_6 += D_1634[local_4->_1b];
        }

        if (CMP(local_4->_1c))
        {
            // 6e12
            local_6 += D_1634[local_4->_1c];
        }

        if (CMP(local_4->_1d))
        {
            // 6e25
            local_6 += D_1634[local_4->_1d];
        }

        if (CMP(local_4->_1e))
        {
            // 6e38
            local_6 += D_1634[local_4->_1e];
        }

        // 6e4b
        if (D_587a == 80)
        {
            local_6 += 3;
        }
    }

    return local_6;
}

// OK P1
int ULTIMA_6e60(int param_1, int param_2)
{
    int local_4;

    local_4 = 1;

    if (param_2 == D_55a8_party[param_1]._19)
    {
        D_55a8_party[param_1]._19 = 0xff;
    }
    else if (param_2 == D_55a8_party[param_1]._1a)
    {
        D_55a8_party[param_1]._1a = 0xff;
    }
    else if (param_2 == D_55a8_party[param_1]._1b)
    {
        D_55a8_party[param_1]._1b = 0xff;
    }
    else if (param_2 == D_55a8_party[param_1]._1c)
    {
        D_55a8_party[param_1]._1c = 0xff;
    }
    else if (param_2 == D_55a8_party[param_1]._1d)
    {
        D_55a8_party[param_1]._1d = 0xff;

        if (param_2 == 0x2a && D_5893_map_id > 0x7f && D_589e < 0x20)
        {
            D_ba14[D_589e]._2 &= 0xef;
        }
    }
    else if (param_2 == D_55a8_party[param_1]._1e)
    {
        D_55a8_party[param_1]._1e = 0xff;
    }
    else
    {
        local_4 = 0;
    }

    ULTIMA_6da8(param_1);
    return local_4;
}

// from FMT
u8 DAT_000738d8[] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x28, 0x28, 0x28, 0x28, 0x28, 0x20, 0x20,
                     0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
                     0x88, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
                     0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
                     0x10, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
                     0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x10, 0x10, 0x10, 0x10, 0x10,
                     0x10, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
                     0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x10, 0x10, 0x10, 0x10, 0x20};

// STUB (asm)
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

// STUB (asm)
static int ULTIMA_6f90(char* di)
{
    // repne scasb
    return strlen(di);
}

// STUB (asm)
void ULTIMA_6f9e(int param_1)
{
    // bx: not initialized
    byte bl = 0;
    byte bh = 0;
    int ax = param_1 + 3;
    DRV_6c(ax, bl, bh);
}

// STUB (asm)
void ULTIMA_6fbc(int param_1)
{
    // bx: not initialized
    byte bl = 0;
    byte bh = 0;
    DRV_6c(param_1, bl, bh);
}

void DRV_60_CF0(void* ax);

// STUB (asm)
void ULTIMA_6fd6_GRAP_AnimateTiles(void)
{
    // CLC
    // ax: D_539c
    DRV_60_CF0(D_539c);
    //debug("ULTIMA_6fd6");
}

// NOT MATCHING (asm)
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
