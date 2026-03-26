#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <memory.h>
#include <stdio.h>
#include <string.h>

void ULTIMA_0c64_GRAP_30_Pset(int param_1, int param_2);
int ULTIMA_2e8e();
void ULTIMA_56ac_DrawMap(void);

void LOOKOBJ_10fc_ViewCmd(int param_1, int param_2);

// NOT MATCHING
void LOOKOBJ_0000(int param_1)
{
    char local_84[0x80];
    u16 local_4;

    local_4 = 0;
    ULTIMA_256e_ReadFile("LOOK2.DAT", &local_4, 2, param_1 << 1);
    ULTIMA_256e_ReadFile("LOOK2.DAT", local_84, 0x80, local_4);
    ULTIMA_1850_PrintString(local_84);
}

// NOT MATCHING
void LOOKOBJ_0042(int param_1, int param_2, int param_3)
{
    char cVar1;
    char local_10[14];

    ULTIMA_1850_PrintString("a well.\n\nDrop a coin?");
    do
    {
        cVar1 = ULTIMA_266c_GetChar();
        if (cVar1 == 'Y')
            break;
    } while (cVar1 != 'N');
    if (cVar1 == 'N')
    {
        ULTIMA_1850_PrintString("No\n");
    }
    else
    {
        ULTIMA_1850_PrintString("Yes\n");
        if (D_57aa == 0)
        {
            return;
        }
        ULTIMA_1850_PrintString("\nThy wish?\n");
        D_57aa--;
        ULTIMA_3b1c_GetString(local_10, 0xc);
        if (local_10[0] == '\0')
        {
            ULTIMA_1850_PrintString("Nothing\n");
        }
        else
        {
            if (ULTIMA_6f1e("Corvette", local_10) >= 0 || ULTIMA_6f1e("Ferrari", local_10) >= 0 ||
                ULTIMA_6f1e("Lamborghini", local_10) >= 0 || ULTIMA_6f1e("Lotus", local_10) >= 0 ||
                ULTIMA_6f1e("Porsche", local_10) >= 0 || ULTIMA_6f1e("Horse", local_10) >= 0)
            {
                if ((D_5893_map_id == 0x16) || (D_5893_map_id == 0x1f))
                {
                    ULTIMA_1850_PrintString("\nPoof!\n");
                    ULTIMA_223c_AudioNoise(10, 3000, 2000);
                    ULTIMA_3a74(0x10, 0x10, param_1 + 1, param_2, param_3, 0, ULTIMA_38e4());
                    return;
                }
                ULTIMA_1850_PrintString("\nNo effect...\n");
            }
            else
            {
                ULTIMA_1850_PrintString("\nNo effect...\n");
            }
        }
    }
}

// NOT MATCHING
void LOOKOBJ_0162(void)
{
    char cVar1;
    int iVar2;

    ULTIMA_1850_PrintString("a gurgling fountain!\n\n");
    ULTIMA_1850_PrintString("Who will drink?\n");

    iVar2 = ULTIMA_2e8e();
    if (iVar2 == -1)
    {
        ULTIMA_1850_PrintString("None!\n");
    }
    else
    {
        cVar1 = D_55a8_party[iVar2]._b;
        if (cVar1 == 'D' || cVar1 == 'S')
        {
            ULTIMA_1850_PrintString("Incapacitated!\n\n");
        }
        else
        {
            ULTIMA_1850_PrintString("Refreshing...\n");
        }
    }
}

// NOT MATCHING
void LOOKOBJ_01ac(int param_2, int param_1)
{
    int iVar1;
    int iVar2;
    undefined2 local_4;

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    iVar1 = param_2 * 8;
    ULTIMA_0c64_GRAP_30_Pset(iVar1 + 6, param_1 * 8 + 8);

    for (local_4 = 0; local_4 < 3; local_4++)
    {
        for (iVar2 = 0; iVar2 < 3; iVar2++)
        {
            if (iVar1 + iVar2 < 0xb1)
            {
                ULTIMA_0c64_GRAP_30_Pset(iVar1 + iVar2 + 7, param_1 * 8 + local_4 + 7);
            }
        }
    }

    if (param_2 * 8 < 0xae)
    {
        ULTIMA_0c64_GRAP_30_Pset(param_2 * 8 + 10, param_1 * 8 + 8);
    }
}

// NOT MATCHING
void LOOKOBJ_024c(int param_2, int param_1)
{
    param_2 = param_2 * 8;
    param_1 = param_1 << 3;
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13ae);
    if (2 < param_2)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(param_2 + 5, param_1 + 10, param_1 + 0xc);
        ULTIMA_0cf2_GRAP_3c_VertLine(param_2 + 6, param_1 + 10, param_1 + 0xc);
        ULTIMA_0cf2_GRAP_3c_VertLine(param_2 + 7, param_1 + 8, param_1 + 0xc);
    }
    if (param_2 < 0xb0)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(param_2 + 8, param_1 + 8, param_1 + 0xc);
    }
    if (param_2 < 0xaf)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(param_2 + 9, param_1 + 6, param_1 + 10);
    }
    if (param_2 < 0xae)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(param_2 + 10, param_1 + 6, param_1 + 10);
    }
    if (param_2 < 0xad)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(param_2 + 0xb, param_1 + 5, param_1 + 8);
    }
    if (param_2 < 0xac)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(param_2 + 0xc, param_1 + 5, param_1 + 7);
    }
}

// NOT MATCHING
void LOOKOBJ_0366(void)
{
    undefined1 uVar2;
    int iVar4;
    int iVar6;
    uint uVar7;
    int local_18;
    uint local_16;
    int local_12;
    int local_4;

    if ((D_587f < 6) || (0x11 < D_587f))
    {
        D_24e6 = 1;
        for (iVar4 = 0; iVar4 < 0xb; iVar4++)
        {
            // memset?
            for (iVar6 = 0; iVar6 < 0xb; iVar6++)
            {
                D_ab02[iVar4 * 0x20 + iVar6] = 0xff;
            }
        }

        D_ab02[0x145] = 0x59;
        ULTIMA_56ac_DrawMap();
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color + 8);

        for (iVar4 = 0; iVar4 < 0x50; iVar4++)
        {
            ULTIMA_0c64_GRAP_30_Pset(ULTIMA_2092_RandomRange(9, 0xb6), ULTIMA_2092_RandomRange(9, 0xac));
        }

        for (local_12 = 0; local_12 < 8; local_12++)
        {
            local_18 = local_12 * 0x16;
            iVar4 = D_5874 % 100;
            uVar7 = (uint)D_587d;
            local_16 = (uint)D_587e;
            local_4 = D_3750[local_12];
            while (((0x27 < iVar4 || ((iVar4 == 0x27 && (4 < (int)uVar7)))) ||
                    ((iVar4 == 0x27 && ((uVar7 == 4 && (5 < (int)local_16)))))))
            {
                local_16--;
                if (local_16 == 0)
                {
                    local_16 = 0x1c;
                    uVar7--;
                }
                if (uVar7 == 0)
                {
                    uVar7 = 0xd;
                    iVar4--;
                }
                do
                {
                    local_4--;
                    if (local_4 < 0)
                    {
                        local_4 = 0x15;
                    }
                } while (D_3760[local_12 * 0x16 + local_4] == 0);
            }
            uVar2 = D_3758[local_12];
            LOOKOBJ_01ac(local_4 + 1, uVar2);
            for (iVar4 = 0; iVar4 < 3; iVar4++)
            {
                if (D_58c8[iVar4] == local_12 + 1U)
                {
                    LOOKOBJ_024c(local_4, uVar2);
                }
            }
        }

        ULTIMA_1850_PrintString("the night sky! ");

        do
        {
        } while (ULTIMA_1b38_KeystrokeCursor() == '\0');
    }
    else
    {
        ULTIMA_1850_PrintString("the sun!\n");
        if (D_587b == 0xff && ULTIMA_39fc_GetFirstActivePartyMember() == 0)
        {
            D_587b = D_5876;
        }
        ULTIMA_2a52(D_587b, 1);
        ULTIMA_2900_UpdateVitalsDisplay();
    }
    return;
}

// NOT MATCHING
void LOOKOBJ_0502(uint param_3, int param_2, int param_1)
{
    char cVar1;
    byte bVar5;
    int iVar4;

    while (((param_3 == 0xe0 || (param_3 == 0xe1)) || (param_3 == 0xe2)))
    {
        if (param_3 == 0xe0)
        {
            param_1 = param_1 - 1;
        }
        else if (param_3 == 0xe1)
        {
            param_2 = param_2 + 1;
        }
        else if (param_3 == 0xe2)
        {
            param_2 = param_2 - 1;
        }
        param_3 = (uint)*ULTIMA_4402_GetTileAddr(param_2, param_1);
    }

    if (param_3 == 0x59)
    {
        LOOKOBJ_0366();
    }
    else if (param_3 == 0xa1)
    {
        LOOKOBJ_0042(D_5896_map_x, D_5897_map_y, D_5895_map_level);
    }
    else if (((byte)param_3 & 0xfc) == 0xd8)
    {
        LOOKOBJ_0162();
    }
    else
    {
        LOOKOBJ_0000(param_3);
        if (((byte)param_3 & 0xfe) == 0xfa)
        {
            bVar5 = D_587f % 0xc;
            if (bVar5 == 0)
            {
                bVar5 = 0xc;
            }
            ULTIMA_1a3e_PrintNumber(bVar5, 1, 0x20);
            ULTIMA_16ba_PrintChar(0x3a);
            ULTIMA_1a3e_PrintNumber(D_5881, 2, 0x30);
            if (D_587f < 0xc)
            {
                ULTIMA_1850_PrintString(" AM.\n");
            }
            else
            {
                ULTIMA_1850_PrintString(" PM.\n");
            }
        }
        else if (param_3 == 0xde)
        {
            cVar1 = D_5893_map_id;
            if (cVar1 == '\x1e')
            {
                ULTIMA_1850_PrintString("Truth\n");
            }
            else if (cVar1 == '\x1f')
            {
                ULTIMA_1850_PrintString("Love\n");
            }
            else
            {
                if (cVar1 != ' ')
                {
                    return;
                }
                ULTIMA_1850_PrintString("Courage\n");
            }
        }
        else
        {
            if (param_3 != 0xdf)
            {
                iVar4 = ULTIMA_1f12_GetCurrentTextX();
                if (iVar4 == 0)
                {
                    return;
                }
                ULTIMA_16ba_PrintChar(10);
                return;
            }
            if (param_2 == 0x7e)
            {
                ULTIMA_1850_PrintString("Wrong\n");
            }
            else if (param_2 < 0x7f)
            {
                if (param_2 == 0x3a)
                {
                    ULTIMA_1850_PrintString("Shame\n");
                }
                else if (param_2 == 0x48)
                {
                    ULTIMA_1850_PrintString("Destard\n");
                }
                else
                {
                    if (param_2 != 0x5b)
                    {
                        return;
                    }
                    ULTIMA_1850_PrintString("Despise\n");
                }
            }
            else if (param_2 == 0x80)
            {
                ULTIMA_1850_PrintString("Doom\n");
            }
            else if (param_2 == 0x9c)
            {
                ULTIMA_1850_PrintString("Covetous\n");
            }
            else if (param_2 == 0xef)
            {
                ULTIMA_1850_PrintString("Hythloth\n");
            }
            else
            {
                if (param_2 != 0xf0)
                {
                    return;
                }
                ULTIMA_1850_PrintString("Deceit\n");
            }
        }
    }
}

// NOT MATCHING
void LOOKOBJ_06a4(int param_1)
{
    char local_84[128];
    u16 local_4;

    local_4 = 0;

    // NOTE: FMT does some other things here

    ULTIMA_256e_ReadFile("LOOK2.DAT", &local_4, 2, param_1 * 2 + 0x200);
    ULTIMA_256e_ReadFile("LOOK2.DAT", local_84, 0x80, local_4);

    ULTIMA_1850_PrintString(local_84);

    if (ULTIMA_1f12_GetCurrentTextX() != 0)
    {
        ULTIMA_16ba_PrintChar(10);
    }
}

// NOT MATCHING
void LOOKOBJ_06f8(int param_1)
{
    byte bVar1;
    char* pcVar3;

    if (param_1 == -1)
    {
        ULTIMA_1c9e_SelectCharset(1);
        ULTIMA_1850_PrintString("abbbbbbbbbbbbbbc\ng              g\ng  LIVE@BY@[E  g\n");
        ULTIMA_1850_PrintString("g  EIGHT@LAWS  g\ng              g\ndeeeeeeeeeeeeeef\n");
        ULTIMA_1c9e_SelectCharset(0);
    }
    else
    {
        for (param_1 = param_1 + 4; (char)D_b21e[param_1] == '\n'; param_1 = param_1 + 6)
        {
        }

        do
        {
            bVar1 = D_b21e[param_1];
            ULTIMA_1c9e_SelectCharset((bVar1 & 0x80) == 0);
            if ((bVar1 == 0x26) || (bVar1 == 0x27))
            {
                bVar1 = 0x6c;
            LAB_0000_07b6:
                ULTIMA_16ba_PrintChar(bVar1);
            }
            else if ((bVar1 < 0x29) || (0x31 < bVar1))
            {
                if (bVar1 != 0xd)
                {
                    bVar1 = bVar1 & 0x7f;
                    goto LAB_0000_07b6;
                }
                ULTIMA_1c9e_SelectCharset(0);
                ULTIMA_266c_GetChar();
            }
            else
            {
                ULTIMA_1c9e_SelectCharset(1);
                // need separate buffer?
                for (pcVar3 = *(char**)(D_3760 + 0x5e + (uint)bVar1 * sizeof(char*)); *pcVar3 != '\0'; pcVar3++)
                {
                    ULTIMA_16ba_PrintChar(*pcVar3);
                }
            }
            pcVar3 = (char*)(param_1 + D_b21e + 1);
            param_1 = param_1 + 1;
        } while (*pcVar3 != '\0');

        ULTIMA_1c9e_SelectCharset(0);

        if (ULTIMA_1f12_GetCurrentTextX() != 0)
        {
            ULTIMA_16ba_PrintChar(10);
        }
    }
}

// NOT MATCHING
void LOOKOBJ_07e4(char param_3, char param_2, char param_1)
{
    int iVar3;
    int iVar4;
    uint uVar6;
    s16 local_48[33];
    uint local_6;
    int local_4;

    local_4 = 0;
    if (D_5893_map_id == 0x4 && param_3 == 0 && param_2 == 0x11 && param_1 == 0x15)
    {
        ULTIMA_1c9e_SelectCharset(1);
        ULTIMA_1850_PrintString("abbbbbbbbbbbbbc\ng   ");
        ULTIMA_1c9e_SelectCharset(0);
        ULTIMA_1850_PrintString("Wanted:   ");
        ULTIMA_1c9e_SelectCharset(1);
        ULTIMA_1850_PrintString("g\ng");
        ULTIMA_1bf2_SetTextPosition(0xe, ULTIMA_1cee_GetCurrentTextY());
        ULTIMA_1850_PrintString("g\ng");
        for (local_6 = 0; local_6 < 3; local_6++)
        {
            if (local_6 < D_585b)
            {
                ULTIMA_1c9e_SelectCharset(0);
                iVar3 = ULTIMA_216c_strlen(D_55a8_party[local_6]._0);
                ULTIMA_1bf2_SetTextPosition(7 - (iVar3 / 2), ULTIMA_1cee_GetCurrentTextY());
                ULTIMA_1850_PrintString(D_55a8_party[local_6]._0);
                ULTIMA_1c9e_SelectCharset(1);
            }
            ULTIMA_1bf2_SetTextPosition(0xe, ULTIMA_1cee_GetCurrentTextY());
            ULTIMA_1850_PrintString("g\ng");
        }
        ULTIMA_1bf2_SetTextPosition(0xe, ULTIMA_1cee_GetCurrentTextY());
        ULTIMA_1850_PrintString("g\ng");
        ULTIMA_1c9e_SelectCharset(0);
        ULTIMA_1850_PrintString("Dead or Alive");
        ULTIMA_1c9e_SelectCharset(1);
        ULTIMA_1850_PrintString("g\ndeeeeeeeeeeeeef\n");
        ULTIMA_1c9e_SelectCharset(0);
    }
    else
    {
        ULTIMA_256e_ReadFile("signs.dat", local_48, 0x42, 0);
        local_6 = local_48[D_5893_map_id];
        memset(D_b21e, 0xff, 2000);

        if (local_6 == 0)
        {
            LOOKOBJ_06f8(-1);
        }
        else
        {
            ULTIMA_256e_ReadFile("signs.dat", D_b21e, 2000, local_6);
            local_6 = 0;
            iVar4 = 0;
            iVar3 = local_4;
            do
            {
                if (D_b21e[iVar4 + 1] == param_3 && D_b21e[iVar4 + 2] == param_2 && D_b21e[iVar4 + 3] == param_1)
                {
                    LOOKOBJ_06f8(iVar4);
                    uVar6 = iVar3 + 1;
                }
                else
                {
                    iVar4 = iVar4 + 4;
                    do
                    {
                        iVar3 = iVar4;
                        iVar4 = iVar3 + 1;
                    } while (D_b21e[iVar3] != 0);

                    uVar6 = (D_b21e[iVar3 + 1] == 0xff);
                    if (uVar6)
                    {
                        LOOKOBJ_06f8(-1);
                    }
                }
                iVar3 = 0;
            } while (uVar6 == 0);
        }
    }
}

// NOT MATCHING
void LOOKOBJ_099c_LookCmd(void)
{
    byte bVar1;
    int iVar2;
    int iVar3;
    int iVar5;

    if (ULTIMA_35ec_SelectDirection() == 0)
    {
        return;
    }

    iVar2 = (uint)D_5896_map_x + D_5876;
    iVar3 = (uint)D_5897_map_y + D_5878;
    bVar1 = *ULTIMA_4402_GetTileAddr(iVar2, iVar3);
    iVar5 = ULTIMA_368e(iVar2, iVar3, D_5895_map_level);
    if (bVar1 == 0x29)
    {
        iVar2 = ULTIMA_4988();
        if (iVar2 == -1)
        {
            return;
        }

        if (D_55a8_party[iVar2]._e <= ULTIMA_2092_RandomRange(1, 0x1e))
        {
            ULTIMA_1850_PrintString("Death vision!\n");
            ULTIMA_2a52(iVar2, 1);
            ULTIMA_2900_UpdateVitalsDisplay();
            return;
        }
        ULTIMA_1850_PrintString("Strange vision!\n");
        LOOKOBJ_10fc_ViewCmd(D_5896_map_x, D_5897_map_y);
        return;
    }

    ULTIMA_1850_PrintString("\nThou dost see\n");
    if (iVar5 != 0)
    {
        LOOKOBJ_06a4(iVar5);
        return;
    }

    // switch?
    if (bVar1 != 0xa0)
    {
        if (bVar1 < 0xa1)
        {
            if ((bVar1 < 0x89) || (0x8a < bVar1))
            {
                LOOKOBJ_0502(bVar1, iVar2, iVar3);
                return;
            }
        }
        else if ((bVar1 != 0xa4) && (bVar1 != 0xf8))
        {
            LOOKOBJ_0502(bVar1, iVar2, iVar3);
            return;
        }
    }

    ULTIMA_1850_PrintString("\n");
    LOOKOBJ_07e4(D_5895_map_level, iVar2, iVar3);
}

// OK P1
void LOOKOBJ_0a9c(int param_2, int param_1)
{
    D_5876 = param_2 * 4 + 0x20;
    D_5878 = param_1 * 4 + 0x20;
}

// OK P1
void LOOKOBJ_0abe(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b4 + 8);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 1, D_5878);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 1, D_5878 + 2);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 3, D_5878 + 1);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 3, D_5878 + 3);
}

// OK P1
void LOOKOBJ_0b04(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b4 + 8);
    ULTIMA_0aa6_GRAP_3f_FillRect(D_5876, D_5878, D_5876 + 3, D_5878 + 3);
}

// OK P1
void LOOKOBJ_0b28(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878, D_5876, D_5878 + 3);
    ULTIMA_0b10_GRAP_Line(D_5876 + 2, D_5878, D_5876 + 2, D_5878 + 3);
}

// OK P1
void LOOKOBJ_0b60(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878, D_5876 + 3, D_5878);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878 + 3, D_5876 + 3, D_5878 + 3);
}

// OK P1
void LOOKOBJ_0b98(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(D_5876 + 1, D_5878 + 1, D_5876 + 2, D_5878 + 1);
    ULTIMA_0b10_GRAP_Line(D_5876 + 1, D_5878 + 2, D_5876 + 2, D_5878 + 2);
}

// OK P1
void LOOKOBJ_0bd0(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878, D_5876 + 3, D_5878);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878 + 3, D_5876 + 3, D_5878 + 3);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878 + 1, D_5876, D_5878 + 2);
    ULTIMA_0b10_GRAP_Line(D_5876 + 3, D_5878 + 1, D_5876 + 3, D_5878 + 2);
}

// OK P1
void LOOKOBJ_0c36(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b8);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878, D_5876 + 1, D_5878);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878 + 1, D_5876 + 1, D_5878 + 1);
    ULTIMA_0b10_GRAP_Line(D_5876 + 2, D_5878 + 2, D_5876 + 3, D_5878 + 2);
    ULTIMA_0b10_GRAP_Line(D_5876 + 2, D_5878 + 3, D_5876 + 3, D_5878 + 3);
}

// OK P1
void LOOKOBJ_0c9c(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b4 + 8);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878, D_5876 + 3, D_5878);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878 + 2, D_5876 + 3, D_5878 + 2);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 2, D_5878 + 1);
    ULTIMA_0c64_GRAP_30_Pset(D_5876, D_5878 + 3);
}

// NOT MATCHING
void LOOKOBJ_0cf4(byte param_1)
{
    byte bVar3;
    int uVar5;

    int i;
    int local_a[4];

    uVar5 = 8;

    for (i = 0; i < 4; i++)
    {
        if ((param_1 & 0xf0) == 0x60 && (D_3822[param_1 & 0xf] & uVar5) == 0)
        {
            local_a[i] = D_13b4 + 8;
        }
        else if ((D_52c8 == 0) || (D_52c8 == 3))
        {
            local_a[i] = D_13b6;
        }
        else
        {
            local_a[i] = D_13b2_frame_color + 8;
        }

        uVar5 >>= 1;
    }

    ULTIMA_0a70_GRAP_2d_SetPenColor(local_a[0]);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 1, D_5878);
    ULTIMA_0a70_GRAP_2d_SetPenColor(local_a[1]);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 3, D_5878 + 1);
    ULTIMA_0a70_GRAP_2d_SetPenColor(local_a[2]);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 1, D_5878 + 2);
    ULTIMA_0a70_GRAP_2d_SetPenColor(local_a[3]);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 3, D_5878 + 3);
}

// OK P1
void LOOKOBJ_0dda(void)
{
    if (D_52c8 == 0 || D_52c8 == 3)
    {
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b6);
    }
    else
    {
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color + 8);
    }

    ULTIMA_0c64_GRAP_30_Pset(D_5876, D_5878);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 2, D_5878 + 2);
}

// OK P1
void LOOKOBJ_0e16(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b4 + 8);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 1, D_5878);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 3, D_5878 + 1);

    if ((D_52c8 == 0) || (D_52c8 == 3))
    {
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b6);
    }
    else
    {
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color + 8);
    }

    ULTIMA_0c64_GRAP_30_Pset(D_5876, D_5878 + 2);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 2, D_5878 + 3);
}

// OK P1
void LOOKOBJ_0e7a(int param_1)
{
    int local_4;

    LOOKOBJ_0abe();
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13ae);
    ULTIMA_0aa6_GRAP_3f_FillRect(D_5876 + 1, D_5878 + 1, D_5876 + 2, D_5878 + 2);

    local_4 = D_3812[param_1];
    if ((local_4 & 8) != 0)
    {
        ULTIMA_0b10_GRAP_Line(D_5876 + 1, D_5878, D_5876 + 2, D_5878);
    }
    if ((local_4 & 4) != 0)
    {
        ULTIMA_0b10_GRAP_Line(D_5876 + 3, D_5878 + 1, D_5876 + 3, D_5878 + 2);
    }
    if ((local_4 & 2) != 0)
    {
        ULTIMA_0b10_GRAP_Line(D_5876 + 1, D_5878 + 3, D_5876 + 2, D_5878 + 3);
    }
    if ((local_4 & 1) != 0)
    {
        ULTIMA_0b10_GRAP_Line(D_5876, D_5878 + 1, D_5876, D_5878 + 2);
    }

    ULTIMA_0a70_GRAP_2d_SetPenColor(0);

    switch (param_1)
    {
    case 0x22:
        ULTIMA_0c64_GRAP_30_Pset(D_5876 + 1, D_5878 + 2);
        break;
    case 0x23:
        ULTIMA_0c64_GRAP_30_Pset(D_5876 + 1, D_5878 + 1);
        break;

    case 0x24:
        ULTIMA_0c64_GRAP_30_Pset(D_5876 + 2, D_5878 + 1);
        break;

    case 0x25:
        ULTIMA_0c64_GRAP_30_Pset(D_5876 + 2, D_5878 + 2);
        break;
    }
}

// OK P1
void LOOKOBJ_0f7e(int param_1, int param_2, int param_3)
{
    int local_4;

    local_4 = D_1e19[param_1 + 1];
    LOOKOBJ_0a9c(param_2, param_3);

    switch (local_4)
    {
    case 0:
        break;
    case 1: // 0fba
        LOOKOBJ_0abe();
        break;
    case 2: // 0fc0
        LOOKOBJ_0b04();
        break;
    case 3: // 0fc6
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13ae);
        ULTIMA_0aa6_GRAP_3f_FillRect(D_5876, D_5878, D_5876 + 3, D_5878 + 3);
        break;
    case 4: // 0fea
        LOOKOBJ_0b60();
        break;
    case 5: // 0ff0
        LOOKOBJ_0b98();
        break;
    case 6: // 0ff6
        LOOKOBJ_0bd0();
        break;
    case 7: // 0ffc -> 0fca
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
        ULTIMA_0aa6_GRAP_3f_FillRect(D_5876, D_5878, D_5876 + 3, D_5878 + 3);
        break;
    case 8: // 1002
        LOOKOBJ_0c36();
        break;
    case 9: // 1008
        LOOKOBJ_0c9c();
        break;
    case 10: // 1011
        LOOKOBJ_0cf4(param_1);
        break;
    case 11: // 1018
        LOOKOBJ_0dda();
        break;
    case 12: // 101e
        if ((D_52c8 == 0) || (D_52c8 == 3))
        {
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b6);
        }
        else
        {
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color + 8);
        }
        ULTIMA_0c64_GRAP_30_Pset(D_5876 + 2, D_5878 + 2);
        break;
    case 13: // 1050
        LOOKOBJ_0e16();
        break;
    case 14: // 1056
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
        ULTIMA_0b10_GRAP_Line(D_5876 + 1, D_5878, D_5876 + 1, D_5878 + 3);
        ULTIMA_0b10_GRAP_Line(D_5876 + 2, D_5878, D_5876 + 2, D_5878 + 3);
        break;
    case 15: // 108c
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color + 8);
        ULTIMA_0aa6_GRAP_3f_FillRect(D_5876, D_5878, D_5876 + 3, D_5878 + 3);
        break;
    case 16: // 1096
        LOOKOBJ_0e7a(param_1);
        break;
    case 90: // 0ffc
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
        ULTIMA_0aa6_GRAP_3f_FillRect(D_5876, D_5878, D_5876 + 3, D_5878 + 3);
        break;
    }
}

// OK P1
void LOOKOBJ_10fc_ViewCmd(int param_1, int param_2)
{
    int local_4;
    int local_6;

    param_1 -= D_589b;
    param_2 -= D_589c;
    param_1 &= 0xff;
    param_2 &= 0xff;

    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        for (local_6 = 0; local_6 < 0x20; local_6++)
        {
            LOOKOBJ_0f7e(*ULTIMA_4402_GetTileAddr((uint)D_589b + local_6, (uint)D_589c + local_4),
                           local_6, local_4);
        }
    }

    ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 8, 8, 0xb7, 0xb7);
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    LOOKOBJ_0a9c(param_1, param_2);

    local_4 = 0;
    while (ULTIMA_1b38_KeystrokeCursor() == 0)
    {
        local_4++;
        if (local_4 == 4)
        {
            local_4 = 0;
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
            ULTIMA_0b86_GRAP_XorFillRect(D_5876, D_5878, D_5876 + 3, D_5878 + 3);
        }
    }

    ULTIMA_5910_UpdateFrame();
}
