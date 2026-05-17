#include "common/common.h"
#include "funcs.h"
#include "vars.h"

#include "zstats.h"

// OK P1
static int ZSTATS_0000(int param_1)
{
    int local_4;

    local_4 = -1;

    if (D_5893_map_id > 0x80 && (D_ba14[D_589e]._2 & 0x80) != 0)
    {
        local_4 = D_ba14[D_589e]._3;
    }
    else
    {
        // 202e
        ULTIMA_1850_PrintString(/*0x96b4*/ "Player: ");
        local_4 = ULTIMA_2d7a(param_1); // Select player
        if (local_4 >= 0)
        {
            ULTIMA_1850_PrintString(D_55a8_party[local_4]._0);
            if (ULTIMA_1f12_GetCurrentTextX() != 0)
            {
                ULTIMA_16ba_PrintChar(10);
            }
        }
    }

    // 205b
    if (local_4 == -1)
    {
        ULTIMA_1850_PrintString(/*0x96be*/ "None!\n");
    }
    // 206a
    else if (local_4 == -2)
    {
        ULTIMA_16ba_PrintChar(10);
    }

    // 2077
    return local_4;
}

// OK P1
static void ZSTATS_0082(int param_1)
{
    int local_6;
    int local_8;
    int local_a;
    S_55a8* local_4;

    ULTIMA_4daa();

    local_4 = &D_55a8_party[param_1];

    ULTIMA_4e50(local_4->_0);
    ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x26, 9);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x27, 9);

    local_6 = ULTIMA_4d76(/*0x96c6*/ "AMBFDTPRS", local_4->_a);
    local_a = ULTIMA_4d76(/*0x96d0*/ "GPDSC", local_4->_b);

    for (local_8 = 0; local_8 < D_1a58[local_6]; local_8++)
    {
        ULTIMA_16ba_PrintChar(0x20);
    }

    ULTIMA_16ba_PrintChar(local_4->_9);
    ULTIMA_1850_PrintString(/*0x96d6*/ " Lv-");
    ULTIMA_1a3e_PrintNumber(local_4->_16, 1, 0x20);
    ULTIMA_16ba_PrintChar(0x20);
    ULTIMA_1850_PrintString(D_1a44[local_6]);
    ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x26, 9);
    ULTIMA_1bf2_SetTextPosition(0, 1);
    ULTIMA_16ba_PrintChar(0xfc);
    ULTIMA_1850_PrintString(D_1a6a[local_a]);
    ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x27, 9);
    ULTIMA_1bf2_SetTextPosition(0, 3);
    ULTIMA_16ba_PrintChar(0xfb);
    ULTIMA_1850_PrintString(/*0x96dc*/ "Str=");
    ULTIMA_1a3e_PrintNumber(local_4->_c, 2, 0x30);
    ULTIMA_1850_PrintString(/*0x96e2*/ "  HP:");
    ULTIMA_1a3e_PrintNumber(local_4->_10, 4, 0x20);
    ULTIMA_1850_PrintString(/*0x96e8*/ "\nInt=");
    ULTIMA_1a3e_PrintNumber(local_4->_e, 2, 0x30);
    ULTIMA_1850_PrintString(/*0x96ee*/ "  HM:");
    ULTIMA_1a3e_PrintNumber(local_4->_12, 4, 0x20);
    ULTIMA_1850_PrintString(/*0x96f4*/ "\nDex=");
    ULTIMA_1a3e_PrintNumber(local_4->_d, 2, 0x30);
    ULTIMA_1850_PrintString(/*0x96fa*/ "  Ex:");
    ULTIMA_1a3e_PrintNumber(local_4->_14, 4, 0x20);
    ULTIMA_1850_PrintString(/*0x9700*/ "\n\n    Magic:");
    ULTIMA_1a3e_PrintNumber(local_4->_f, 2, 0x20);
}

// OK P1
static bool ZSTATS_0278(int param_1)
{
    if (param_1 == 0xff)
    {
        return 0;
    }
    else
    {
        ULTIMA_16ba_PrintChar(0x20);
        ULTIMA_1850_PrintString(D_1962[param_1]);
        ULTIMA_16ba_PrintChar(10);
        return 1;
    }
}

// OK P1
static void ZSTATS_02a8(int param_1)
{
    int local_4;
    S_55a8* local_6;

    ULTIMA_4daa();

    local_6 = &D_55a8_party[param_1];
    ULTIMA_4e50(local_6->_0);
    ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x26, 9);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_16ba_PrintChar(0xfc);
    ULTIMA_16ba_PrintChar(0xfe);
    ULTIMA_1850_PrintString(/*0x970e*/ "Arms\n\n");
    ULTIMA_16ba_PrintChar(0xfb);
    ULTIMA_16ba_PrintChar(0xfe);

    local_4 = ZSTATS_0278(local_6->_19);
    local_4 += ZSTATS_0278(local_6->_1a);
    local_4 += ZSTATS_0278(local_6->_1b);
    local_4 += ZSTATS_0278(local_6->_1c);
    local_4 += ZSTATS_0278(local_6->_1d);
    local_4 += ZSTATS_0278(local_6->_1e);

    if (local_4 == 0)
    {
        ULTIMA_1bf2_SetTextPosition(0, 4);
        ULTIMA_16ba_PrintChar(0xfc);
        ULTIMA_1850_PrintString(/*0x9716*/ "(None ready)");
        ULTIMA_16ba_PrintChar(0xfb);
    }

    ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x27, 9);
}

// OK P1
static void ZSTATS_039c(void)
{
    ULTIMA_4daa();
    ULTIMA_4e50(/*0x9724*/ "Equipment");
    ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x26, 9);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x27, 9);
    ULTIMA_1850_PrintString(/*0x972e*/ "\n Food: ");
    ULTIMA_1a3e_PrintNumber(D_57a8, 4, 0x20); // Food
    ULTIMA_1850_PrintString(/*0x9738*/ "\n Gold: ");
    ULTIMA_1a3e_PrintNumber(D_57aa, 4, 0x20); // Gold
    ULTIMA_1850_PrintString(/*0x9742*/ "\n\n Keys.......");
    ULTIMA_1a3e_PrintNumber(D_57ac, 2, 0x20); // Keys
    ULTIMA_1850_PrintString(/*0x9752*/ "\n Gems.......");
    ULTIMA_1a3e_PrintNumber(D_57ad, 2, 0x20); // Gems
    ULTIMA_1850_PrintString(/*0x9760*/ "\n Torches....");
    ULTIMA_1a3e_PrintNumber(D_57ae, 2, 0x20); // Torches
    if (D_57af != 0)
    {
        // Grapple
        ULTIMA_1850_PrintString(/*0x976e*/ "\n Grapple");
    }
}

// OK P1
void ZSTATS_045e(int param_1)
{
    int local_4;

    ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x26, param_1 + 1);
    ULTIMA_16ba_PrintChar(0xff);
    ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x27, 9);
    ULTIMA_16ba_PrintChar(0x10);

    for (local_4 = 0; local_4 < 0xd; local_4++)
    {
        ULTIMA_16ba_PrintChar(0x11);
    }

    ULTIMA_16ba_PrintChar(0x13);

    for (local_4 = 1; local_4 != param_1; local_4++)
    {
        ULTIMA_1bf2_SetTextPosition(0, local_4);
        ULTIMA_16ba_PrintChar(0x17);
        ULTIMA_1bf2_SetTextPosition(0xe, local_4);
        ULTIMA_16ba_PrintChar(0x17);
    }

    ULTIMA_16ba_PrintChar(10);
    ULTIMA_16ba_PrintChar(0x14);

    for (local_4 = 0; local_4 < 0xd; local_4++)
    {
        ULTIMA_16ba_PrintChar(0x15);
    }

    ULTIMA_16ba_PrintChar(0x16);
}

// OK P1
static int ZSTATS_0518(int param_1, uint param_2)
{
    S_55a8* local_4 = &D_55a8_party[param_1];

    return local_4->_19 == param_2 || local_4->_1a == param_2 || local_4->_1b == param_2 || local_4->_1c == param_2 ||
           local_4->_1d == param_2 || local_4->_1e == param_2;
}

// OK P1
int ZSTATS_056c(int param_1, int notused, byte* param_3, int param_4)
{
    while (1)
    {
        if (--param_1 >= 0)
        {
            if (param_3[param_1] == 0)
            {
                if (param_4 == 0xff)
                    continue;

                if (ZSTATS_0518(param_4, param_1) == 0)
                    continue;
            }

            return param_1;
        }

        break;
    }

    return -1;
}

// OK P1
int ZSTATS_05a4(int param_1, int param_2, byte* param_3, int param_4)
{
    while (1)
    {
        if (++param_1 < param_2)
        {
            if (param_3[param_1] == 0)
            {
                if (param_4 == 0xff)
                    continue;
                if (ZSTATS_0518(param_4, param_1) == 0)
                    continue;
            }

            return param_1;
        }

        break;
    }

    return -1;
}

// OK P1
// show inven count
void ZSTATS_05e2(int param_1, byte* param_2, char** param_3, uint param_4)
{
    char local_6;
    int local_4;

    local_6 = (char)param_2[param_1];
    if (local_6 != -1)
    {
        if (local_6 != 0)
        {
            ULTIMA_1a3e_PrintNumber((byte)local_6, 2, 0x20);
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x9778*/ "--");
        }

        if (param_4 < 0x20)
        {
            ULTIMA_1c9e_SelectCharset(1);
        }

        ULTIMA_16ba_PrintChar(param_4);
        ULTIMA_1c9e_SelectCharset(0);
    }

    if (param_3[param_1][0] == '*')
    {
        ULTIMA_1c9e_SelectCharset(1);
        ULTIMA_1850_PrintString(/*0x977c*/ "\x1c + ");
        ULTIMA_1850_PrintString(&param_3[param_1][1]);
        ULTIMA_1c9e_SelectCharset(0);
    }
    else if (param_3[param_1][0] == '!')
    {
        ULTIMA_1c9e_SelectCharset(1);
        ULTIMA_1850_PrintString(/*0x9782*/ "\x1d + ");
        ULTIMA_1c9e_SelectCharset(0);
        ULTIMA_1850_PrintString(D_1962[40 + param_1]); // NOT MATCHING?
    }
    else if (param_3[param_1][0] == '(')
    {
        ULTIMA_1850_PrintString(/*0x9788*/ "Moonstone ");
        ULTIMA_1c9e_SelectCharset(1);
        ULTIMA_16ba_PrintChar((byte)param_3[param_1][1]);
        ULTIMA_1c9e_SelectCharset(0);
    }
    else
    {
        ULTIMA_1850_PrintString(param_3[param_1]);
    }

    local_4 = ULTIMA_1f12_GetCurrentTextX();
    if (local_4 < 0xe)
    {
        register int si = 0xe - local_4;
        local_4 += si;

        do
        {
            ULTIMA_16ba_PrintChar(0x20);
            si--;
        } while (si != 0);
    }
    ULTIMA_16ba_PrintChar(10);
}

// NOT MATCHING
static int ZSTATS_06e8(char* param_1, int param_2, byte* param_3, char** param_4)
{
    int local_10;
    int local_e;
    int local_c;
    int local_a;
    bool local_8;
    int local_6;
    int local_4;

    ULTIMA_4e50(param_1);
    ZSTATS_045e(8);
    local_8 = false;
    local_6 = ZSTATS_05a4(-1, param_2, param_3, 0xff);
    if (local_6 == -1)
    {
        ZSTATS_045e(8);
        ULTIMA_1bf2_SetTextPosition(1, 4);
        ULTIMA_1850_PrintString(/*0x9794*/ "(None owned!)");
        ULTIMA_4daa();
        ULTIMA_1b94_SelectTextWindow(2);
        return ULTIMA_266c_GetChar();
    }

    // 092d
    while (!local_8)
    {
        ULTIMA_1b94_SelectTextWindow(1);
        ULTIMA_1bf2_SetTextPosition(1, 1);

        // -> 0756
        for (local_c = local_6; local_c != -1;
             // 0746
             local_c = ZSTATS_05a4(local_c, param_2, param_3, 0xff))
        {
            ZSTATS_05e2(local_c, param_3, param_4, 0x2d);

            ULTIMA_1bf2_SetTextPosition(1, ULTIMA_1cee_GetCurrentTextY());
            if (ULTIMA_1cee_GetCurrentTextY() == 8)
                break;
        }

        // 077f
        local_10 = 0;
        if (ZSTATS_056c(local_6, param_2, param_3, 0xff) != -1)
        {
            local_10 = 2;
        }

        // 079c
        if (local_c != -1 && ZSTATS_05a4(local_c, param_2, param_3, 0xff) != -1)
        {
            local_10++;
        }

        // 07b8
        switch (local_10)
        {
        case 0:
            // 07d0
            ULTIMA_4daa();
            break;
        case 1:
            // 0806
            ULTIMA_4dea(0x19);
            break;
        case 2:
            // 0810
            ULTIMA_4dea(0x18);
            break;
        case 3:
            // 0816
            ULTIMA_4dea(0x12);
            break;
        }

        // ^ ok

        // 07d3
        ULTIMA_1b94_SelectTextWindow(2);
        local_e = ULTIMA_266c_GetChar();
        switch (local_e)
        {
        case 3:
        case 0xd5:
            // 081c
            if (local_e == 0xd5)
            {
                local_4 = 7;
            }
            else
            {
                local_4 = 1;
            }

            for (local_a = 0; local_a < local_4; local_a++)
            {
                if (ZSTATS_056c(local_6, param_2, param_3, 0xff) != -1)
                {
                    local_6 = ZSTATS_056c(local_6, param_2, param_3, 0xff);
                }
            }
            break;

        case 4:
        case 0xd6:
            // 086c
            if (local_e == 0xd6)
            {
                local_4 = 7;
            }
            else
            {
                local_4 = 1;
            }

            for (local_a = 0; local_a < local_4; local_a++)
            {
                if (local_c != -1 && ZSTATS_05a4(local_c, param_2, param_3, 0xff) != -1)
                {
                    local_6 = ZSTATS_05a4(local_6, param_2, param_3, 0xff);
                    local_c = ZSTATS_05a4(local_c, param_2, param_3, 0xff);
                }
            }
            break; // -> 092d

        case 0xd3:
            // 08d6
            local_6 = ZSTATS_05a4(-1, param_2, param_3, 0xff);
            break; // -> 092d

        case 0xd4:
            // 08ec
            local_6 = ZSTATS_056c(param_2, param_2, param_3, 0xff);
            local_a = 0;
            // 090f
            while (local_a < 6 && ZSTATS_056c(local_6, param_2, param_3, 0xff) != -1)
            {
                local_6 = local_c;
                local_a++;
            }
            break; // -> 092d

        case 0:
            break; // -> 092d

        case 0x20:
        case 1:
        case 2:
        case 0x1b:
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
            // 0948
            local_8 = 1;
            break;
        }
    }

    return local_e;
}

// OK P1
// 099A
void ZSTATS_099a(void)
{
    int local_4;

    local_4 = 0;
    do
    {
        D_b9ee[local_4] = D_5820[local_4];
        D_b9f6[local_4] = D_5828[local_4];
        D_ba03[local_4] = D_5840[local_4] == 0xff ? 0xff : 0;
    } while (++local_4 < 8);

    D_b9fe = D_57b0;
    D_b9ff = D_57b1;
    D_ba00 = D_57b3;
    D_ba01 = D_57b4;
    D_ba02 = D_57b5;

    for (local_4 = 0; local_4 < 3; local_4++)
    {
        D_ba0b[local_4] = D_57b6[local_4];
    }

    D_ba0e = D_57ba;
    D_ba0f = D_57bb != 0 ? 0xff : 0;
    D_ba10 = D_57bc;
    D_ba11 = D_57bd;
    D_ba12 = D_57be;
    D_ba13 = D_57bf;
}

// NOT MATCHING
void ZSTATS_0a3a_ZstatsCmd(void)
{
    int local_8;
    byte local_6;
    uint local_4;

    local_8 = ZSTATS_0000(1);
    if (local_8 == -2)
    {
        local_8 = 6;
    }
    else if (local_8 < 0)
    {
        return;
    }
    // ec3f
    ULTIMA_1850_PrintString(/*0x97a2*/ "\nStatus: ");
    ZSTATS_099a();
    ULTIMA_4efc();
    local_4 = local_8 << 1;
    local_6 = 0;
    // ^OK
    // ec58
    do
    {
        do
        {
            if (local_6 != 0x20 && local_6 != 0x1b)
            {
                if ((unsigned int)local_6 == 3 || local_6 == 1)
                {
                    if (local_4 == 0xc)
                    {
                        local_4 = (uint)D_585b * 2 - 1;
                    }
                    else if ((int)local_4 < 1)
                    {
                        local_4 = 0x10;
                    }
                    else
                    {
                        local_4 = local_4 - 1;
                    }
                }
                else
                {
                    if (local_6 == 2 || local_6 == 4)
                    {
                        if ((uint)D_585b * 2 - 1 != local_4)
                        {
                            if ((int)local_4 < 0x10)
                            {
                                local_4 = local_4 + 1;
                            }
                            else
                            {
                                local_4 = 0;
                            }
                            break;
                        }
                    }
                    else if (local_6 > 4)
                    {
                        if (local_6 != 0x30)
                        {
                            if (((0x30 < local_6) && (local_6 < 0x37)) && (local_6 - 0x31 < (uint) * (byte*)0x585b))
                            {
                                local_4 = (uint)local_6 * 2 - 0x62;
                            }
                            break;
                        }
                    }
                    local_4 = 0xc;
                }
            }
            else
            {
                ULTIMA_4daa();
                ULTIMA_4e20();
                ULTIMA_4f3c();
                ULTIMA_2900_UpdateVitalsDisplay();
                ULTIMA_1850_PrintString(/*0x97ce*/ "Done\n");
                return;
            }
        } while (false);

        // ecab
        ULTIMA_1b94_SelectTextWindow(1);
        if ((int)local_4 < 0xc)
        {
            if ((local_4 & 1) == 0)
            {
                ZSTATS_0082((int)local_4 >> 1);
            }
            else
            {
                ZSTATS_02a8((int)local_4 >> 1);
            }

            // ed3f
            ULTIMA_1b94_SelectTextWindow(2);
            local_6 = ULTIMA_266c_GetChar();
            continue;
        }
        if (local_4 == 0xc)
        {
            ZSTATS_039c();

            // ed3f
            ULTIMA_1b94_SelectTextWindow(2);
            local_6 = ULTIMA_266c_GetChar();
            continue;
        }
        if (local_4 == 0xd)
        {
            // ed6a
            local_6 = ZSTATS_06e8(/*0x97ac*/ "Reagents", 8, D_5850, D_19d2);
        }
        else if (local_4 == 0xe)
        {
            local_6 = ZSTATS_06e8(/*0x97b6*/ "Spells", 0x30, &D_58ee[2], D_19e2);
        }
        else if (local_4 == 0xf)
        {
            local_6 = ZSTATS_06e8(/*0x97be*/ "Items", 0x26, D_b9ee, D_1916);
        }
        else if (local_4 == 0x10)
        {
            local_6 = ZSTATS_06e8(/*0x97c4*/ "Armaments", 0x30, D_57c0, D_1962);
        }
    } while (true);
}

// OK P1
static void ZSTATS_0bee(char* param_1)
{
    ULTIMA_1850_PrintString(/*0x97d4*/ "\n\n");
    ULTIMA_1850_PrintString(param_1);
    ULTIMA_1850_PrintString(/*0x97d8*/ "\n\nItem: ");
}

// OK P1
static int ZSTATS_0c0a(int param_1)
{
    S_55a8* s = &D_55a8_party[param_1];

    if ((s->_1b == 0xff) && (s->_1c == 0xff))
    {
        return 2;
    }
    else if (s->_1b == 0xff)
    {
        return 0;
    }
    else if ((s->_1c == 0xff) && (D_1a7e[s->_1b] != '0'))
    {
        return 1;
    }
    else
    {
        return 0xff;
    }
}

// NOT MATCHING
// param_2: whom?
// param_1: item_id?
static int ZSTATS_0c5c(int param_2, int param_1)
{
    byte* local_10;
    int local_e;
    int local_c;
    int local_a;
    int local_8;
    ActorFmt* local_6;
    int local_4;

#if !defined(TARGET_DOS16)
    local_6 = 0;
#endif

    // OK P1
    if (0x7f < D_5893_map_id)
    {
        local_6 = &D_5c5a[D_ba14[D_589e]._4];
    }

    // ee62
    // OK P1
    if (param_1 == 0x1b || param_1 == 0x1d)
    {
        return 0;
    }
    // ee74
    if (9 <= param_1 && param_1 <= 0xf && 0x7f < D_5893_map_id && D_58a3 == 0)
    { // OK P1
        // NOT MATCHING
        ZSTATS_0bee(/*0x97e2*/ "Thou canst not change armour in heated battle!");
        return 0;
    }
    // ee94
    // OK P1 (NOT MATCHING 55a8)
    if (ZSTATS_0518(param_2, param_1) != 0)
    {
        ULTIMA_6e60(param_2, param_1);
        if (D_57c0[param_1] < 99)
        {
            D_57c0[param_1]++;
        }
        // eeb8
        if (D_5893_map_id <= 0x7f)
        {
            return 0;
        }
        if (param_1 != 0x2a)
        {
            return 0;
        }
        local_8 = ULTIMA_4d76(/*0x9812*/ "AMBFDTPRS", D_55a8_party[param_2]._a);
        // ..eee8
        local_6->_0_tile = local_6->_1 = D_1ade[local_8];
        return 0;
    }
    if ((((param_1 == 0x1a) || (param_1 == 0x24)) && (D_57db == '\0')) || ((param_1 == 0x1c && (D_57dd == '\0'))))
    { // OK P1
        // NOT MATCHING
        ZSTATS_0bee(/*0x981c*/ "Thou hast no ammunition for that weapon!");
        return 0;
    }

    // ef16
    // OK P1 (NOT MATCHING 55a8)
    local_4 = 0;
    local_10 = &D_55a8_party[param_2]._19;
    local_a = 6;

    // ef30
    // OK P1 (NOT MATCHING 55a8)
    for (local_a = 0; local_a < 6; local_a++)
    {
        if (*local_10 != 0xff)
        {
            local_4 += D_1aae[*local_10];
        }
        // ef41
        local_10++;
    }

    // OK P1 (NOT MATCHING 55a8)
    local_e = D_1aae[param_1] + local_4 <= D_55a8_party[param_2]._c /*strength*/;

    // ef6e
    switch ((uint)D_1a7e[param_1])
    {
    case 2:
        // f0be
        if (D_55a8_party[param_2]._1d != -1)
        {
            ZSTATS_0bee(/*0x9916*/ "Only one magic ring may be worn at a time!");
            return 0;
        }
        // f0d2..efc6
        local_10 = &D_55a8_party[param_2]._1d;
        break;
    case 4:
        // f09c
        if (D_55a8_party[param_2]._1e != -1)
        {
            ZSTATS_0bee(/*0x98f0*/ "Thou must remove thine other amulet!");
            return 0;
        }
        // f0b0..efc6
        local_10 = &D_55a8_party[param_2]._1e;
        break;
    case 0x20:
        // f04e
        local_c = ZSTATS_0c0a(param_2);
        if (local_c == 0xff)
        {
            ZSTATS_0bee(/*0x9892*/ "Thou must free one of thy hands first!");
            return 0;
        }
        // f062
        if (local_c == 2)
        {
            local_c = 0;
        }
        // f06d..f077..efc6
        local_10 = &D_55a8_party[param_2]._1b + local_c;
        break;
    case 0x30:
        // f07e
        local_c = ZSTATS_0c0a(param_2);
        if (local_c != 2)
        {
            ZSTATS_0bee(/*0x98ba*/ "Both hands must be free before thou canst wield that!");
            return 0;
        }
        // f092..f077..efc6
        local_10 = &D_55a8_party[param_2]._1b;
        break;
    case 0x40:
        // f02c
        if (D_55a8_party[param_2]._1a != 0xff)
        {
            ZSTATS_0bee(/*0x9866*/ "Thou must first remove thine other armour!");
            return 0;
        }
        // f040..efc6
        local_10 = &D_55a8_party[param_2]._1a;
        break;
    case 0x80:
        // efa7
        if (D_55a8_party[param_2]._19 != 0xff)
        {
            ZSTATS_0bee(/*0x9846*/ "Remove first thy present helm!");
            return 0;
        }
        // efbc
        local_10 = &D_55a8_party[param_2]._19;
        break;
    }

    // efc9
    if (local_e == 0)
    {
        // f0e0
        ZSTATS_0bee(/*0x9942*/ "Thou art not strong enough!");
        return 0;
    }
    else
    {
        // efd2
        *local_10 = param_1;
        --D_57c0[param_1];
        if ((D_57c0[param_1] == 0x2a || D_57c0[param_1] == 0x2c) && (ULTIMA_2092_RandomRange(0, 0xf) == 0))
        {
            // efff
            ULTIMA_1850_PrintString(/*0x995e*/ "\n\nRing vanishes!\n");
            D_55a8_party[param_2]._1d = 0xff;
            ULTIMA_43ae_AudioSweepTone(0x4b0, 2000, 1, 0x28);
            return 1;
        }
        else
        {
            // f0e6
            if (param_1 != 0x2a)
            {
                // ee6e
                return 0;
            }
            // f0ef
            if (D_5893_map_id <= 0x7f)
            {
                // ee6e
                return 0;
            }
            // f0f9
            local_6->_1 = 0x1d;

            // eee8
            local_6->_1 = 0x1d;

            // ee6e
            return 0;
        }
    }
}

// NOT MATCHING
int ZSTATS_0f2e(int param_3, int param_2, int param_1)
{
    int local_1e;
    int local_1c;
    int local_1a;
    int local_18;
    int local_16;
    byte* local_14; // equipments
    int local_12;
    int local_10;
    int local_e;
    int local_c;
    int local_a;
    int local_8;
    int local_6;
    int local_4;

#if !defined(TARGET_DOS16)
    local_1a = 0;
#endif

    // f10e
    local_8 = 0;
    local_10 = 1;
    if (param_1 == 0x52)
    {
        local_14 = D_57c0;
        local_a = 0x30;
    }
    else
    {
        local_14 = D_b9ee;
        local_a = 0x26;
    }

    // f462
    if (local_8 != 0)
        return local_1a;

    // f142
    do
    {
        ULTIMA_1b94_SelectTextWindow(1);
        ULTIMA_1bf2_SetTextPosition(1, 1);
        local_4 = 0;
        local_12 = param_3;

        // f20b
        do
        {
            if (local_12 == -1)
            {
                // f1a4
                local_18 = 0;
                if (ZSTATS_056c(param_3, local_a, local_14, param_2) + 1 != 0)
                {
                    local_18 = 2;
                }
                // f1c0
                if (local_12 != -1)
                {
                    if (ZSTATS_05a4(local_12, local_a, local_14, param_2) + 1 != 0)
                    {
                        local_18++;
                    }
                }
                // ->f1db
                break;
            }
            else
            {
                // f213
                local_4++;
                if (ULTIMA_1cee_GetCurrentTextY() == local_10)
                {
                    ULTIMA_16ba_PrintChar(0xfd);
                    local_1a = local_12;
                }

                // f22b
                if (param_1 != 0x52)
                {
                    // f170..f17e
                    // Scrolls
                    ZSTATS_05e2(local_12, local_14, D_1916, 0x20);
                }
                else
                {
                    // f234
                    if (ZSTATS_0518(param_2, local_12) != 0)
                    {
                        // f244
                        local_c = D_1ae8[local_12];
                    }
                    else
                    {
                        // f15c
                        local_c = 0x20;
                    }
                    // f161..f17e
                    // Equipments
                    ZSTATS_05e2(local_12, local_14, D_1962, local_c);
                }

                // f181
                // OK P1
                ULTIMA_1bf2_SetTextPosition(1, ULTIMA_1cee_GetCurrentTextY());

                if (ULTIMA_1cee_GetCurrentTextY() - 1 == local_10)
                {
                    ULTIMA_16ba_PrintChar(0xfd);
                }

                // f19c
                if (ULTIMA_1cee_GetCurrentTextY() == 0x8)
                {
                    // f1a4
                    local_18 = 0;
                    if (ZSTATS_056c(param_3, local_a, local_14, param_2) != -1)
                    {
                        local_18 = 2;
                    }
                    // f1c0
                    if (local_12 != -1)
                    {
                        if (ZSTATS_05a4(local_12, local_a, local_14, param_2) != -1)
                        {
                            local_18++;
                        }
                    }
                    // -> f1db
                    break;
                }
                else
                {
                    // f1fc
                    local_12 = ZSTATS_05a4(local_12, local_a, local_14, param_2);
                    // -> f20b
                    continue;
                }
            }
        } while (true);

        // f1db
        if (local_18 != 0)
        {
            if (local_18 == 1)
            {
                // f28a..f28d
                ULTIMA_4dea(0x19);
            }
            else if (local_18 == 2)
            {
                // f294..f28d
                ULTIMA_4dea(0x18);
            }
            else if (local_18 == 3)
            {
                // f29a..f28d
                ULTIMA_4dea(0x12);
            }
        }
        else
        {
            // f254
            ULTIMA_4daa();
        }

        // L_1077
        // f257
        ULTIMA_1b94_SelectTextWindow(2);
        local_16 = ULTIMA_266c_GetChar();

        switch (local_16)
        {
            // OK P1
        case 1:
        case 3:
        case 0xd5:
            // 10c0
            if (local_16 == 0xd5)
                local_6 = 7;
            else
                local_6 = 1;
            local_e = 0;
            if (local_6 > 0)
            {
                register int si;
                register int di;
                // 10e1
                local_1c = local_6;
                local_e += local_6;
                di = param_3;
                si = local_10;

                // 10f0
                do
                {
                    if (si == 4 || si == 1)
                    {
                        // 10fa
                        if (ZSTATS_056c(di, local_a, local_14, param_2) != -1)
                        {
                            di = ZSTATS_056c(di, local_a, local_14, param_2);
                        }
                        else
                        {
                            // 111c
                            if (si == 4)
                            {
                                // 1121
                                si--;
                            }
                        }
                    }
                    else
                    {
                        // 1121
                        si--;
                    }
                    // 1122
                } while (--local_1c != 0);

                param_3 = di;

                // 112a
                local_10 = si;
            }
            break;

            // OK P1
        case 2:
        case 4:
        case 0xd6:
            // 1130
            if (local_16 == 0xd6)
                local_6 = 7;
            else
                local_6 = 1;
            local_e = 0;
            if (local_6 > 0)
            {
                register int si;
                register int di;
                // 1151
                local_1e = local_6;
                local_e += local_6;
                di = local_12;
                si = local_10;

                // 1160
                do
                {
                    if (si == 4 || si == 7 || si > local_4)
                    {
                        // 116f
                        if (di != -1 && ZSTATS_05a4(di, local_a, local_14, param_2) != -1)
                        {
                            param_3 = ZSTATS_05a4(param_3, local_a, local_14, param_2);
                            di = ZSTATS_05a4(di, local_a, local_14, param_2);
                        }
                        else
                        {
                            // 11a8
                            if (si == 4 && local_4 == 4)
                            {
                                si++;
                            }
                        }
                    }
                    else
                    {
                        // 11b3
                        si++;
                    }
                    // 11b4
                } while (--local_1e != 0);

                local_12 = di;

                // 112a
                local_10 = si;
            }
            break;

        case 0xd:
        case 0x20:
            // -> 121c;
            // f3fc
            if (param_1 == 0x52)
            {
                local_8 = ZSTATS_0c5c(param_2, local_1a);
            }
            else
            {
                // f410
                local_8 = 1;
            }
            // -> f462
            break;
        case 0x1b:
            // 1238
            // OK P1
            ULTIMA_1850_PrintString(param_1 == 0x52 ? /*0x9970*/ "Thou art empty-\nhanded!\n" : /*0x9976*/ "Item: ");
            local_8 = 1;
            local_1a = -1;

            // -> f462
            break;
        case 0xd3:
            // 11C0
            // OK P1
            // f3a0
            param_3 = ZSTATS_05a4(-1, local_a, local_14, param_2);
            local_10 = 1;
            // -> f462
            break;
        case 0xd4:
        {
            // OK P1
            // f3bc
            // L_11dc
            param_3 = ZSTATS_056c(local_a, local_a, local_14, param_2);

            local_10 = 1;
            do
            {
                // f3d1
                // L_11f1
                local_1a = ZSTATS_056c(param_3, local_a, local_14, param_2);
                if (local_1a == -1)
                {
                    // L_1207
                    break;
                }
                // f3e7
                // L_1210
                param_3 = local_1a;
                local_10++;
            } while (local_10 < 7);
            // -> f462
        }
        break;
        }
        // f462
    } while (local_8 == 0); // -> f142

    return local_1a;
}

// OK P1
void ZSTATS_1296_ReadyCmd(void)
{
    int local_6;
    int local_4;

    local_6 = ZSTATS_0000(0);

    if (local_6 < 0)
        return;

    local_4 = ZSTATS_05a4(-1, 0x30, D_57c0, local_6);
    if (local_4 == -1)
    {
        ULTIMA_1850_PrintString(/*0x997e*/ "Thou art empty-\nhanded!\n");
        return;
    }

    ULTIMA_1850_PrintString(/*0x9998*/ "Item: ");
    ULTIMA_4efc();
    ULTIMA_1b94_SelectTextWindow(1);

    ULTIMA_4e50(D_55a8_party[local_6]._0);

    ZSTATS_045e(0x08);

    ZSTATS_0f2e(local_4, local_6, 0x52);

    ULTIMA_4daa();
    ULTIMA_4e20();
    ULTIMA_4f3c();
    ULTIMA_2900_UpdateVitalsDisplay();
}
