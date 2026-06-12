#include "common/common.h"
#include "funcs.h"
#include "vars.h"
#include "macros.h"
#include "tiles.h"

#include <string.h>

#include "lookobj.h"

void ULTIMA_0c64_GRAP_30_Pset(int param_1, int param_2);
int ULTIMA_2e8e();
void ULTIMA_56ac_DrawMap(void);

// OK P1
static void LOOKOBJ_0000(int param_1)
{
    char local_84[0x80];
    u16 local_4;

    local_4 = 0;
    ULTIMA_256e_ReadFileFromDisk(/*0x71f8*/ "LOOK2.DAT", &local_4, 2, param_1 << 1);
    ULTIMA_256e_ReadFileFromDisk(/*0x7202*/ "LOOK2.DAT", local_84, 0x80, local_4);
    ULTIMA_1850_PrintString(local_84);
}

// OK P1
static void LOOKOBJ_0042(byte param_1, byte param_2, byte param_3)
{
    char local_14;
    char local_10[14];
    int local_12;

    ULTIMA_1850_PrintString(/*0x720c*/ "a well.\n\nDrop a coin?");

    while ((local_14 = ULTIMA_266c_GetChar()) != 'Y' && local_14 != 'N')
    {
    }

    if (local_14 == 'N')
    {
        ULTIMA_1850_PrintString(/*0x7222*/ "No\n");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x7226*/ "Yes\n");
        if (D_57aa == 0)
        {
            return;
        }

        ULTIMA_1850_PrintString(/*0x722c*/ "\nThy wish?\n");
        D_57aa--;
        ULTIMA_3b1c_GetString(local_10, 0xc);
        if (local_10[0] == 0)
        {
            ULTIMA_1850_PrintString(/*0x7238*/ "Nothing\n");
            return;
        }

        if (ULTIMA_6f1e(/*0x7242*/ "Corvette", local_10) > -1 || ULTIMA_6f1e(/*0x724c*/ "Ferrari", local_10) > -1 ||
            ULTIMA_6f1e(/*0x7254*/ "Lamborghini", local_10) > -1 || ULTIMA_6f1e(/*0x7260*/ "Lotus", local_10) > -1 ||
            ULTIMA_6f1e(/*0x7266*/ "Porsche", local_10) > -1 || ULTIMA_6f1e(/*0x726e*/ "Horse", local_10) > -1)
        {
            if (D_5893_map_id != 0x16 && D_5893_map_id != 0x1f)
            {
                ULTIMA_1850_PrintString(/*0x7274*/ "\nNo effect...\n");
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x7284*/ "\nPoof!\n");
                ULTIMA_223c_AudioWhiteNoise(10, 3000, 2000);
                local_12 = ULTIMA_38e4();
                ULTIMA_3a74(TILE_ACTOR_HORSE, TILE_ACTOR_HORSE, param_1 + 1, param_2, param_3, 0, local_12);
            }
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x728c*/ "\nNo effect...\n");
        }
    }
}

// OK P1
static void LOOKOBJ_0162(void)
{
    byte local_6;
    int local_4;

    ULTIMA_1850_PrintString(/*0x729c*/ "a gurgling fountain!\n\n");
    ULTIMA_1850_PrintString(/*0x72b4*/ "Who will drink?\n");

    if ((local_4 = ULTIMA_2e8e()) == -1)
    {
        ULTIMA_1850_PrintString(/*0x72c6*/ "None!\n");
    }
    else
    {
        local_6 = D_55a8_party[local_4].status;
        if (local_6 == STATUS_DEAD || local_6 == STATUS_SLEEP)
        {
            ULTIMA_1850_PrintString(/*0x72ce*/ "Incapacitated!\n\n");
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x72e0*/ "Refreshing...\n");
        }
    }
}

// OK P1
static void LOOKOBJ_01ac(int param_1, int param_2)
{
    int local_6;
    int local_4;

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0c64_GRAP_30_Pset(param_1 * 8 + 6, param_2 * 8 + 8);

    for (local_4 = 0; local_4 < 3; local_4++)
    {
        for (local_6 = 0; local_6 < 3; local_6++)
        {
            if (param_1 * 8 + local_6 <= 0xb0)
            {
                ULTIMA_0c64_GRAP_30_Pset(param_1 * 8 + local_6 + 7, param_2 * 8 + local_4 + 7);
            }
        }
    }

    if (param_1 * 8 <= 0xad)
    {
        ULTIMA_0c64_GRAP_30_Pset(param_1 * 8 + 10, param_2 * 8 + 8);
    }
}

// OK P1
static void LOOKOBJ_024c(int param_1, int param_2)
{
    int local_4 = param_1 * 8;
    int local_6 = param_2 * 8;

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13ae);

    if (local_4 > 2)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(local_4 + 5, local_6 + 10, local_6 + 0xc);
    }

    if (local_4 > 2)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(local_4 + 6, local_6 + 10, local_6 + 0xc);
    }

    if (local_4 > 2)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(local_4 + 7, local_6 + 8, local_6 + 0xc);
    }

    if (local_4 <= 0xaf)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(local_4 + 8, local_6 + 8, local_6 + 0xc);
    }

    if (local_4 <= 0xae)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(local_4 + 9, local_6 + 6, local_6 + 10);
    }

    if (local_4 <= 0xad)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(local_4 + 10, local_6 + 6, local_6 + 10);
    }

    if (local_4 <= 0xac)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(local_4 + 0xb, local_6 + 5, local_6 + 8);
    }

    if (local_4 <= 0xab)
    {
        ULTIMA_0cf2_GRAP_3c_VertLine(local_4 + 0xc, local_6 + 5, local_6 + 7);
    }
}

// CHECKED
void LOOKOBJ_0366(void)
{
    int local_6;
    int local_a;
    int local_14;
    int local_16;
    int local_12;
    int local_10;
    int local_4;
    byte local_c;
    int local_e;
    int local_8;

    if (D_587f >= 6 && D_587f < 0x12)
    {
        ULTIMA_1850_PrintString(/*0x72f0*/ "the sun!\n");
        if (D_587b == 0xff && ULTIMA_39fc_GetFirstActivePartyMember() == 0)
        {
            D_587b = D_5876;
        }

        ULTIMA_2a52(D_587b, 1);
        ULTIMA_2900_UpdateVitalsDisplay();
    }
    else
    {
        D_24e6 = 1;
        for (local_6 = 0; local_6 < 0xb; local_6++)
        {
            // memset?
            for (local_a = 0; local_a < 0xb; local_a++)
            {
                GetMapViewport(local_a, local_6) = 0xff;
            }
        }

        GetMapViewport(5, 10) = 0x59;
        ULTIMA_56ac_DrawMap();
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color + 8);

        for (local_6 = 0; local_6 < 0x50; local_6++)
        {
            ULTIMA_0c64_GRAP_30_Pset(ULTIMA_2092_RandomRange(9, 0xb6), ULTIMA_2092_RandomRange(9, 0xac));
        }

        for (local_12 = 0; local_12 < 8; local_12++)
        {
            local_10 = (int)D_5874 % 100;
            local_14 = D_587d;
            local_16 = D_587e;
            local_4 = D_3750[local_12];
            // NOT MATCHING
            while (local_10 > 0x27 || (local_10 == 0x27 && local_14 > 4) || (local_10 == 0x27 && local_14 == 4 && local_16 > 5))
            {
                local_16--;
                if (local_16 == 0)
                {
                    local_16 = 0x1c;
                    local_14--;
                }

                if (local_14 == 0)
                {
                    local_14 = 0xd;
                    local_10--;
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

            local_8 = local_4 + 1;
            local_e = D_3758[local_12];
            LOOKOBJ_01ac(local_8, local_e);
            local_8--;
            for (local_a = 0; local_a < 3; local_a++)
            {
                if (D_58c8[local_a] == local_12 + 1)
                {
                    LOOKOBJ_024c(local_8, local_e);
                }
            }
        }

        ULTIMA_1850_PrintString(/*0x72fa*/ "the night sky! ");

        do
        {
        } while ((local_c = ULTIMA_1b38_PollKeyWithCursor()) == 0);
    }
}

// OK P1
static void LOOKOBJ_0502(int param_1, int param_2, int param_3)
{
    int local_4;

    while (param_1 == TILE_MAP_E0 || param_1 == TILE_MAP_E1 || param_1 == TILE_MAP_E2)
    {
        switch (param_1)
        {
        case TILE_MAP_E0:
            param_3--;
            break;

        case TILE_MAP_E1:
            param_2++;
            break;

        case TILE_MAP_E2:
            param_2--;
            break;
        }

        param_1 = *ULTIMA_4402_GetTileAddr(param_2, param_3);
    }

    if (param_1 == TILE_MAP_59)
    {
        LOOKOBJ_0366();
    }
    else if (param_1 == TILE_MAP_WELL)
    {
        LOOKOBJ_0042(D_5896_map_x, D_5897_map_y, D_5895_map_level);
    }
    else if ((param_1 & 0xfc) == TILE_MAP_FOUNTAIN)
    {
        LOOKOBJ_0162();
    }
    else
    {
        LOOKOBJ_0000(param_1);
        if ((param_1 & 0xfe) == TILE_MAP_CLOCK)
        {
            local_4 = D_587f % 0xc;
            if (local_4 == 0)
            {
                local_4 = 0xc;
            }

            ULTIMA_1a3e_PrintNumber(local_4, 1, 0x20);
            ULTIMA_16ba_PrintChar(0x3a);
            ULTIMA_1a3e_PrintNumber(D_5881, 2, 0x30);

            if (D_587f > 0xb)
            {
                ULTIMA_1850_PrintString(/*0x730a*/ " PM.\n");
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x7310*/ " AM.\n");
            }
        }
        else if (param_1 == TILE_MAP_DE)
        {
            switch (D_5893_map_id)
            {
            case 0x1e:
                ULTIMA_1850_PrintString(/*0x7316*/ "Truth\n");
                break;

            case 0x1f:
                ULTIMA_1850_PrintString(/*0x731e*/ "Love\n");
                break;

            case 0x20:
                ULTIMA_1850_PrintString(/*0x7324*/ "Courage\n");
                break;
            }
        }
        else if (param_1 == TILE_MAP_DF)
        {
            switch (param_2)
            {
            case 0xf0:
                ULTIMA_1850_PrintString(/*0x732e*/ "Deceit\n");
                break;

            case 0x5b:
                ULTIMA_1850_PrintString(/*0x7336*/ "Despise\n");
                break;

            case 0x48:
                ULTIMA_1850_PrintString(/*0x7340*/ "Destard\n");
                break;

            case 0x7e:
                ULTIMA_1850_PrintString(/*0x734a*/ "Wrong\n");
                break;

            case 0x9c:
                ULTIMA_1850_PrintString(/*0x7352*/ "Covetous\n");
                break;

            case 0x3a:
                ULTIMA_1850_PrintString(/*0x735c*/ "Shame\n");
                break;

            case 0xef:
                ULTIMA_1850_PrintString(/*0x7364*/ "Hythloth\n");
                break;

            case 0x80:
                ULTIMA_1850_PrintString(/*0x736e*/ "Doom\n");
                break;
            }
        }
        else
        {
            if (ULTIMA_1f12_GetCurrentTextX() != 0)
            {
                ULTIMA_16ba_PrintChar(10);
            }
        }
    }
}

// OK P1
static void LOOKOBJ_06a4(int param_1)
{
    char local_84[128];
    u16 local_4;

    local_4 = 0;

    // NOTE: FMT does some other things here

    ULTIMA_256e_ReadFileFromDisk(/*0x7374*/ "LOOK2.DAT", &local_4, 2, param_1 * 2 + 0x200);
    ULTIMA_256e_ReadFileFromDisk(/*0x737e*/ "LOOK2.DAT", local_84, 0x80, local_4);

    ULTIMA_1850_PrintString(local_84);

    if (ULTIMA_1f12_GetCurrentTextX() != 0)
    {
        ULTIMA_16ba_PrintChar(10);
    }
}

// OK P1
static void LOOKOBJ_06f8(int param_1)
{
    byte local_6;
    char* local_4;

    if (param_1 == -1)
    {
        ULTIMA_1c9e_SelectCharset(1);
        ULTIMA_1850_PrintString(/*0x742a*/ "abbbbbbbbbbbbbbc\ng              g\ng  LIVE@BY@[E  g\n");
        ULTIMA_1850_PrintString(/*0x745e*/ "g  EIGHT@LAWS  g\ng              g\ndeeeeeeeeeeeeeef\n");
        ULTIMA_1c9e_SelectCharset(0);
    }
    else
    {
        for (param_1 = param_1 + 4; D_b21e[param_1] == '\n'; param_1 += 6)
        {
        }

        do
        {
            local_6 = D_b21e[param_1];
            if (local_6 & 0x80)
            {
                ULTIMA_1c9e_SelectCharset(0);
            }
            else
            {
                ULTIMA_1c9e_SelectCharset(1);
            }

            if (local_6 == 0x26 || local_6 == 0x27)
            {
                ULTIMA_16ba_PrintChar(0x6c);
            }
            else if (local_6 >= 0x29 && local_6 <= 0x31)
            {
                ULTIMA_1c9e_SelectCharset(1);
                for (local_4 = D_3810[local_6 - 0x29]; *local_4 != '\0';)
                {
                    ULTIMA_16ba_PrintChar((byte)*local_4++);
                }
            }
            else if (local_6 == 0xd)
            {
                ULTIMA_1c9e_SelectCharset(0);
                local_6 = ULTIMA_266c_GetChar();
            }
            else
            {
                ULTIMA_16ba_PrintChar(local_6 & 0x7f);
            }
        } while (D_b21e[++param_1] != 0);

        ULTIMA_1c9e_SelectCharset(0);

        if (ULTIMA_1f12_GetCurrentTextX() != 0)
        {
            ULTIMA_16ba_PrintChar(10);
        }
    }
}

// OK P1
static void LOOKOBJ_07e4(byte param_1, byte param_2, byte param_3)
{
    s16 local_48[33];
    int local_6;
    int local_4;

    local_4 = 0;
    if (D_5893_map_id == 0x4 && param_1 == 0 && param_2 == 0x11 && param_3 == 0x15)
    {
        ULTIMA_1c9e_SelectCharset(1);
        ULTIMA_1850_PrintString(/*0x7492*/ "abbbbbbbbbbbbbc\ng   ");
        ULTIMA_1c9e_SelectCharset(0);
        ULTIMA_1850_PrintString(/*0x74a8*/ "Wanted:   ");
        ULTIMA_1c9e_SelectCharset(1);
        ULTIMA_1850_PrintString(/*0x74b4*/ "g\ng");
        ULTIMA_1bf2_SetTextPosition(0xe, ULTIMA_1cee_GetCurrentTextY());
        ULTIMA_1850_PrintString(/*0x74b8*/ "g\ng");
        for (local_6 = 0; local_6 < 3; local_6++)
        {
            if (local_6 < D_585b)
            {
                ULTIMA_1c9e_SelectCharset(0);
                ULTIMA_1bf2_SetTextPosition(7 - (ULTIMA_216c_strlen(D_55a8_party[local_6].name) / 2),
                    ULTIMA_1cee_GetCurrentTextY());
                ULTIMA_1850_PrintString(D_55a8_party[local_6].name);
                ULTIMA_1c9e_SelectCharset(1);
            }

            ULTIMA_1bf2_SetTextPosition(0xe, ULTIMA_1cee_GetCurrentTextY());
            ULTIMA_1850_PrintString(/*0x74bc*/ "g\ng");
        }

        ULTIMA_1bf2_SetTextPosition(0xe, ULTIMA_1cee_GetCurrentTextY());
        ULTIMA_1850_PrintString(/*0x74c0*/ "g\ng");
        ULTIMA_1c9e_SelectCharset(0);
        ULTIMA_1850_PrintString(/*0x74c4*/ "Dead or Alive");
        ULTIMA_1c9e_SelectCharset(1);
        ULTIMA_1850_PrintString(/*0x74d2*/ "g\ndeeeeeeeeeeeeef\n");
        ULTIMA_1c9e_SelectCharset(0);
    }
    else
    {
        ULTIMA_256e_ReadFileFromDisk(/*0x74e6*/ "signs.dat", local_48, 0x42, 0);
        local_6 = local_48[D_5893_map_id];
        memset(D_b21e, 0xff, 2000);

        if (local_6 == 0)
        {
            LOOKOBJ_06f8(-1);
        }
        else
        {
            ULTIMA_256e_ReadFileFromDisk(/*0x74f0*/ "signs.dat", D_b21e, 2000, local_6);
            local_6 = 0;
            // di = local_4
            // si = local_6
            do
            {
                if (D_b21e[local_6 + 1] == param_1 && D_b21e[local_6 + 2] == param_2 && D_b21e[local_6 + 3] == param_3)
                {
                    LOOKOBJ_06f8(local_6);
                    local_4++;
                }
                else
                {
                    local_6 += 4;
                    while (D_b21e[local_6++] != 0)
                    {
                    }

                    local_4 = D_b21e[local_6] == 0xff ? 1 : 0;

                    if (local_4)
                    {
                        LOOKOBJ_06f8(-1);
                    }
                }
            } while (local_4 == 0);
        }
    }
}

// OK P1
void LOOKOBJ_099c_LookCmd(void)
{
    int local_4;
    int local_8;
    int local_a;
    int local_6;
    int local_c;

    if (ULTIMA_35ec_SelectDirection() == 0)
    {
        return;
    }

    local_8 = D_5896_map_x + D_5876;
    local_a = D_5897_map_y + D_5878;
    local_4 = *ULTIMA_4402_GetTileAddr(local_8, local_a);
    local_6 = ULTIMA_368e_FindActorTileAtPos(local_8, local_a, D_5895_map_level);
    if (local_4 == TILE_MAP_29)
    {
        if ((local_c = ULTIMA_4988()) == -1)
        {
            return;
        }

        if (D_55a8_party[local_c].intel <= ULTIMA_2092_RandomRange(1, 0x1e))
        {
            ULTIMA_1850_PrintString(/*0x74fa*/ "Death vision!\n");
            ULTIMA_2a52(local_c, 1);
            ULTIMA_2900_UpdateVitalsDisplay();
            return;
        }
        ULTIMA_1850_PrintString(/*0x750a*/ "Strange vision!\n");
        LOOKOBJ_10fc_ViewCmd(D_5896_map_x, D_5897_map_y);
        return;
    }

    ULTIMA_1850_PrintString(/*0x751c*/ "\nThou dost see\n");
    if (local_6 != 0)
    {
        LOOKOBJ_06a4(local_6);
        return;
    }

    switch (local_4)
    {
    case TILE_MAP_89:
    case TILE_MAP_8A:
    case TILE_MAP_A0:
    case TILE_MAP_A4:
    case TILE_MAP_SIGN_F8:
        ULTIMA_1850_PrintString(/*0x752c*/ "\n");
        LOOKOBJ_07e4(D_5895_map_level, local_8, local_a);
        break;

    default:
        LOOKOBJ_0502(local_4, local_8, local_a);
        break;
    }
}

// OK P1
static void LOOKOBJ_0a9c(int param_1, int param_2)
{
    D_5876 = param_1 * 4 + 0x20;
    D_5878 = param_2 * 4 + 0x20;
}

// OK P1
static void LOOKOBJ_0abe(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b4 + 8);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 1, D_5878);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 1, D_5878 + 2);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 3, D_5878 + 1);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 3, D_5878 + 3);
}

// OK P1
static void LOOKOBJ_0b04(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b4 + 8);
    ULTIMA_0aa6_GRAP_3f_FillRect(D_5876, D_5878, D_5876 + 3, D_5878 + 3);
}

// OK P1
static void LOOKOBJ_0b28(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878, D_5876, D_5878 + 3);
    ULTIMA_0b10_GRAP_Line(D_5876 + 2, D_5878, D_5876 + 2, D_5878 + 3);
}

// OK P1
static void LOOKOBJ_0b60(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878, D_5876 + 3, D_5878);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878 + 3, D_5876 + 3, D_5878 + 3);
}

// OK P1
static void LOOKOBJ_0b98(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(D_5876 + 1, D_5878 + 1, D_5876 + 2, D_5878 + 1);
    ULTIMA_0b10_GRAP_Line(D_5876 + 1, D_5878 + 2, D_5876 + 2, D_5878 + 2);
}

// OK P1
static void LOOKOBJ_0bd0(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878, D_5876 + 3, D_5878);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878 + 3, D_5876 + 3, D_5878 + 3);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878 + 1, D_5876, D_5878 + 2);
    ULTIMA_0b10_GRAP_Line(D_5876 + 3, D_5878 + 1, D_5876 + 3, D_5878 + 2);
}

// OK P1
static void LOOKOBJ_0c36(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b8);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878, D_5876 + 1, D_5878);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878 + 1, D_5876 + 1, D_5878 + 1);
    ULTIMA_0b10_GRAP_Line(D_5876 + 2, D_5878 + 2, D_5876 + 3, D_5878 + 2);
    ULTIMA_0b10_GRAP_Line(D_5876 + 2, D_5878 + 3, D_5876 + 3, D_5878 + 3);
}

// OK P1
static void LOOKOBJ_0c9c(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b4 + 8);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878, D_5876 + 3, D_5878);
    ULTIMA_0b10_GRAP_Line(D_5876, D_5878 + 2, D_5876 + 3, D_5878 + 2);
    ULTIMA_0c64_GRAP_30_Pset(D_5876 + 2, D_5878 + 1);
    ULTIMA_0c64_GRAP_30_Pset(D_5876, D_5878 + 3);
}

// CHECKED
static void LOOKOBJ_0cf4(int param_1)
{
    int local_e;

    int local_c;
    int local_a[4];

    local_e = 8;

    for (local_c = 0; local_c < 4; local_c++)
    {
        if ((param_1 & 0xf0) == 0x60 && (D_3822[param_1 & 0xf] & local_e) == 0)
        {
            local_a[local_c] = D_13b4 + 8;
        }
        else if (D_52c8 == 0 || D_52c8 == 3)
        {
            local_a[local_c] = D_13b6;
        }
        else
        {
            local_a[local_c] = D_13b2_frame_color + 8;
        }

        local_e >>= 1;
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
static void LOOKOBJ_0dda(void)
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
static void LOOKOBJ_0e16(void)
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
static void LOOKOBJ_0e7a(int param_1)
{
    int local_4;

    LOOKOBJ_0abe();
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13ae);
    ULTIMA_0aa6_GRAP_3f_FillRect(D_5876 + 1, D_5878 + 1, D_5876 + 2, D_5878 + 2);

    // param_1: 0x20 ~ 0x26 (LOOKOBJ_0f7e -> D_1d1a -> val == 0x10)
    local_4 = D_3832[param_1 - 0x20];
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
static void LOOKOBJ_0f7e(int param_1, int param_2, int param_3)
{
    int local_4;

    local_4 = D_1d1a[param_1];
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
    while (ULTIMA_1b38_PollKeyWithCursor() == 0)
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
