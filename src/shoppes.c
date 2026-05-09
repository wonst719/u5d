#include "common/common.h"
#include "funcs.h"
#include "vars.h"

#include <stdlib.h>
#include <string.h>

int CAST2_05e0(int a, int b);

int ZSTATS_056c(int param_1, int notused, byte* param_3, int param_4);

int ZSTATS_05a4(int param_1, int param_2, byte* param_3, int param_4);

void ZSTATS_05e2(int param_1, byte* param_2, char** param_3, uint param_4);

// OK P1
char* SHOPPES_0000(char* param_1, char* param_2)
{
    while (*param_1 = *param_2++)
    {
        param_1++;
    }

    return param_1;
}

// OK P1
void SHOPPES_0026(char* param_1)
{
    byte local_e;
    char local_c[6];
    char* local_6;
    char* local_4;

#if !defined(TARGET_DOS16)
    // prevents direct modification of protected memory
    char buf[256];
    //strcpy_s(buf, sizeof(buf), param_1);
    strcpy(buf, param_1);
    param_1 = buf;
#endif

    local_6 = param_1;
    local_4 = D_b7fa;

    while (*local_6 != 0)
    {
        // 0068
        local_e = *local_6;
        if (local_e == 0x23 || local_e == 0x24 || local_e == 0x40 || local_e == 0x25 || local_e == 0x5e ||
            local_e == 0x26 || local_e == 0x2a || local_e >= 0x80)
        {
            // 008d
            *local_6 = 0;
            local_4 = SHOPPES_0000(local_4, param_1);
            *local_6 = local_e;
            param_1 = local_6 + 1;
        }

        // 00a4
        local_6++;

        if (local_e >= 0x80)
        {
            // 00ab
            *local_4++ = 0x20;
            local_4 = SHOPPES_0000(local_4, D_24ea[local_e - 0x80]);
            if (*local_6 != 0 && (byte)*local_6 < 0x80)
            {
                *local_4++ = 0x20;
            }
        }
        else
        {
            // 0036
            switch (local_e)
            {
            case 0x23: // '#'
                // 0056
                local_4 = SHOPPES_0000(local_4, D_aafc); // 3ef24
                break;

            case 0x24: // '$'
                // 00d0
                local_4 = SHOPPES_0000(local_4, D_aafe); // 3ef28
                continue;

            case 0x40: // '('
                // 00d8
                if (D_587f < 0xc)
                {
                    local_4 = SHOPPES_0000(local_4, /*0x7826*/ "morning");
                }
                else if (D_587f < 0x12)
                {
                    local_4 = SHOPPES_0000(local_4, /*0x782e*/ "afternoon");
                }
                else
                {
                    local_4 = SHOPPES_0000(local_4, /*0x7838*/ "evening");
                }
                break;

            case 0x25: // '%'
                // 00fc
                u5_itoa(D_b118, local_c, 10);
                local_4 = SHOPPES_0000(local_4, local_c);
                break;

            case 0x5e: // '^'
                // 0114
                u5_itoa(D_b11a, local_c, 10);
                local_4 = SHOPPES_0000(local_4, local_c);
                break;

            case 0x26: // '&'
                // 0122
                local_4 = SHOPPES_0000(local_4, D_ab00);
                break;

            case 0x2a: // '*'
                // 012a
                local_4 = SHOPPES_0000(local_4, D_ac62);
                break;
            }
        }
    }

    // 014a
    strcpy(local_4, param_1);

    ULTIMA_1850_PrintString(D_b7fa);
}

// OK P1
void SHOPPES_017a(int param_1)
{
    ULTIMA_256e_ReadFile(/*0x7840*/ "SHOPPE.DAT", D_b21e, 1500, param_1);
    SHOPPES_0026(D_b21e);
}

// OK P1
void SHOPPES_019a(void)
{
    if (D_5958 == 0)
    {
        // FMT: int local_8 = D_57aa;
        // 3f54(&local_8)
        // D_57aa = local_8
        ULTIMA_3f54(&D_57aa, ULTIMA_2092_RandomRange(1, 0x40));
    }
}

// OK P1
void SHOPPES_01b6(void)
{
    ULTIMA_16ba_PrintChar(0x22);
    SHOPPES_017a(D_3b2a[D_b116][ULTIMA_2092_RandomRange(0, 3)]);

    if (ULTIMA_1f12_GetCurrentTextX() > 0xb)
    {
        ULTIMA_1850_PrintString(/*0x784c*/ "\n\n:");
    }
    else if (ULTIMA_1f12_GetCurrentTextX() == 0)
    {
        ULTIMA_1850_PrintString(/*0x7850*/ "\n:");
    }
    else
    {
        ULTIMA_16ba_PrintChar(0x20);
    }
}

// OK P1
void SHOPPES_0202(int param_1)
{
    if (param_1 == 0)
    {
        ULTIMA_1850_PrintString(/*0x7854*/ "\n\n\"");
        SHOPPES_017a(D_3b6a[D_b116][ULTIMA_2092_RandomRange(0, 3)]);
    }
    else if (param_1 == 1)
    {
        ULTIMA_1850_PrintString(/*0x7858*/ "\n\n\"");
        SHOPPES_017a(D_3baa[D_b116][ULTIMA_2092_RandomRange(0, 3)]);
    }

    if (param_1 == 0 || param_1 == 1)
    {
        if (ULTIMA_1f12_GetCurrentTextX() != 0)
        {
            ULTIMA_16ba_PrintChar(10);
        }

        SHOPPES_0026(/*0x785c*/ "says $.\n");
    }
}

// CHECKED
int SHOPPES_0280(void)
{
    int local_4;

    do
    {
        local_4 = ULTIMA_266c_GetChar();
        if (local_4 == 0x4e)
        {
            ULTIMA_1850_PrintString(/*0x7866*/ "No");
        }
        else if (local_4 == 0x59)
        {
            ULTIMA_1850_PrintString(/*0x786a*/ "Yes");
        }
    } while (local_4 != 0x4e && local_4 != 0x59);

    return local_4;
}

// OK P1
int SHOPPES_02ba(int param_1, int param_2, int param_3)
{
    char local_4;

    ASSERT(param_2 < 3); // ?
    ASSERT(D_b114 < 4); // ?

    D_b118 = D_3bea[D_b114][param_2];
    D_b118 += (D_b118 * -((s32)(D_55a8_party[param_1]._e * 3) - 100) / (u32)100);

    ULTIMA_1850_PrintString(/*0x786e*/ "\n\n\"");
    SHOPPES_017a(D_3c0a[param_2]);
    ULTIMA_1850_PrintString(/*0x7872*/ "\n\nInterested?\" ");

    do
    {
        local_4 = ULTIMA_266c_GetChar();
        if (local_4 == 'N')
        {
            ULTIMA_1850_PrintString(/*0x7882*/ "No\n\n\"What else, then?\n\n");
        }
        else if (local_4 == 'Y')
        {
            ULTIMA_1850_PrintString(/*0x789a*/ "Yes\n");
            if (D_57aa < D_b118)
            {
                SHOPPES_017a(0x21e6);
                param_3 = -1;
            }
            else
            {
                D_57aa -= D_b118;
                SHOPPES_019a();
                ULTIMA_2900_UpdateVitalsDisplay();
                switch (param_2)
                {
                case 0:
                    ULTIMA_3ef0(&D_57ac, 3, 99);
                    break;
                case 1:
                    ULTIMA_3ef0(&D_57ad, 4, 99);
                    break;
                case 2:
                    ULTIMA_3ef0(&D_57ae, 5, 99);
                    break;
                }

                param_3 = 1;
                SHOPPES_0026(/*0x78a0*/ "\n\"Sold!\"\nsays $.\n\n\"What else, \n");
                if (D_55a8_party[param_1]._9 == 12)
                {
                    ULTIMA_1850_PrintString(/*0x78c0*/ "m'lady");
                }
                else
                {
                    ULTIMA_1850_PrintString(/*0x78c8*/ "m'lord");
                }

                ULTIMA_1850_PrintString(/*0x78d0*/ "?\n\n");
            }
        }
    } while (local_4 != 'N' && local_4 != 'Y');

    return param_3;
}

// OK P1
int SHOPPES_03f6(int param_1)
{
    bool local_6;
    int local_8;
    byte local_4;

    local_6 = 0;
    local_8 = 0;

    while (!local_6)
    {
        ULTIMA_1850_PrintString(/*0x78d4*/ "a.........Keys\n");
        ULTIMA_1850_PrintString(/*0x78e4*/ "b.........Gems\n");
        ULTIMA_1850_PrintString(/*0x78f4*/ "c......Torches\n\n");
        ULTIMA_1850_PrintString(/*0x7906*/ "Thy concern?\" ");

        do
        {
            local_4 = ULTIMA_266c_GetChar();
            switch (local_4)
            {
            case 0x41:
            case 0x42:
            case 0x43:
                ULTIMA_16ba_PrintChar(local_4 | 0x20);
                local_8 = SHOPPES_02ba(param_1, local_4 - 0x41, local_8);
                if (local_8 == -1)
                    local_6 = 1;
                break;

            case 0x1b:
            case 0x20:
                local_6 = 1;
                break;

            case 0x44:
                SHOPPES_017a(8725); // offset: 0x2215
                break;

            default:
                local_4 = 0;
                break;
            }
        } while (local_4 == 0 && !local_6);
    }

    return local_8;
}

// OK P1
void SHOPPES_04a2(int param_1)
{
    int local_6;
    byte local_4;
    int local_8;

    local_8 = local_6 = 0;

    SHOPPES_01b6();

    do
    {
        local_4 = ULTIMA_266c_GetChar();
        switch (local_4)
        {
        case 0x59:
            ULTIMA_1850_PrintString(/*0x7916*/ "Yes\n\n\"We sell:\n\n");
            local_8 = SHOPPES_03f6(param_1);
            local_6 = 1;
            break;

        case 0x20:
        case 0x4e:
            ULTIMA_1850_PrintString(/*0x7928*/ "No");
            local_6 = 1;
            break;
        }
    } while (!local_6);

    SHOPPES_0202(local_8);
}

// CHECKED
int SHOPPES_0502(int param_1, int param_2, int param_3)
{
    char local_4;
    int local_8;
    int local_6;

    local_6 = 0;
    for (local_8 = 0; local_8 < 8; local_8++)
    {
        if (D_3a32[D_b114][local_8] != 0) // NOT MATCHING
        {
            if (local_6 == param_2)
                break;

            local_6++;
        }
    }

    if (local_8 == 8)
    {
        return -2;
    }

    if (D_5850[local_8] == 99)
    {
        ULTIMA_1850_PrintString(/*0x792c*/ "\n\n\"Thou canst not carry any more!\"\n\n");
        ULTIMA_266c_GetChar();
    }
    else
    {
        D_b118 = D_3a32[D_b114][local_8];
        D_b118 += D_b118 * -((s32)(D_55a8_party[param_1]._e * 3) - 100) / (u32)100;
        D_b11a = D_3a5a[D_b114][local_8];

        ULTIMA_1850_PrintString(/*0x7952*/ "\n\n\"");
        //SHOPPES_0026(D_3c10[iVar4] + 0x97b7);
        SHOPPES_0026((char*)&D_b21e[((D_3c10[local_8] + 0x97b7) - 0xb21e)]); // 0x97b7 + 0x1c1c - b21e = 0x1b5
        ULTIMA_1850_PrintString(/*0x7956*/ " Is this thy need?\" ");
        if (ULTIMA_1f12_GetCurrentTextX() > 0xc)
        {
            ULTIMA_1850_PrintString(/*0x796c*/ "\n:");
        }

        do
        {
            local_4 = ULTIMA_266c_GetChar();
            if (local_4 == 'N')
            {
                ULTIMA_1850_PrintString(/*0x7970*/ "No\n\n\"What else?\n\n");
            }
            else if (local_4 == 'Y')
            {
                ULTIMA_1850_PrintString(/*0x7982*/ "Yes\n");
                if (D_57aa < D_b118)
                {
                    SHOPPES_0026(/*0xb6e2*/ "");
                    param_3 = -1;
                }
                else
                {
                    D_57aa -= D_b118;
                    SHOPPES_019a();
                    ULTIMA_2900_UpdateVitalsDisplay();
                    ULTIMA_3ef0(&D_5850[local_8], D_b11a, 99);
                    param_3 = 1;
                    SHOPPES_0026(/*0x7988*/ "\n\"I thank thee!\"\nsays $.\n");
                    ULTIMA_1850_PrintString(/*0x79a2*/ "\"Anything else?\n\n");
                }
            }
        } while (local_4 != 'N' && local_4 != 'Y');
    }

    // a8e7 NOT MATCHING
    return param_3;
}

// OK P1
int SHOPPES_0666(int param_1)
{
    bool local_6;
    int local_a;
    int local_e;
    byte local_c;
    int local_8;
    byte local_4;

    local_e = local_6 = 0;

    ULTIMA_256e_ReadFile(/*0x7a0a*/ "SHOPPE.DAT", D_b21e, 1500, 6759); //offset: 0x1a67

    while (!local_6)
    {
        local_c = 'A';
        local_8 = 0;
        do
        {
            if (D_3a32[D_b114][local_8] != 0) // size = max_b114 * 8 + 8
            {
                ULTIMA_16ba_PrintChar(local_c++);
                ULTIMA_1850_PrintString(/*0x7a16*/ "...");
                ULTIMA_1850_PrintString(D_3c20[local_8]);
                ULTIMA_16ba_PrintChar(10);
            }
            local_8++;
        } while (local_8 < 8);

        ULTIMA_1850_PrintString(/*0x7a1a*/ "\nThy interest?\" ");

        do
        {
            local_4 = ULTIMA_266c_GetChar();

            switch (local_4)
            {
            case 0x41:
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
                local_a = SHOPPES_0502(param_1, local_4 - 0x41, local_e);
                if (local_a == -1)
                {
                    local_e = -1;
                    local_6 = 1;
                }
                else if (local_a == -2)
                {
                    local_4 = 0;
                }
                else
                {
                    local_e = local_a;
                }
                break;

            case 0xd:
            case 0x1b:
            case 0x20:
                local_6 = 1;
                break;

            default:
                local_4 = 0;
                break;
            }

        } while (local_4 == 0 && local_6 == 0);
    }

    return local_e;
}

// OK P1
void SHOPPES_075e(int param_1)
{
    int local_6;
    byte local_4;
    int local_8;
    
    local_8 = local_6 = 0;

    SHOPPES_01b6();

    do
    {
        local_4 = ULTIMA_266c_GetChar();
        switch (local_4)
        {
        case 0x59:
            ULTIMA_1850_PrintString(/*0x7a2c*/ "Yes\n\n\"Fine! We sell:\n\n");
            local_8 = SHOPPES_0666(param_1);
            local_6 = 1;
            break;

        case 0x20:
        case 0x4e:
            ULTIMA_1850_PrintString(/*0x7a44*/ "No");
            local_6 = 1;
            break;
        }
    } while (!local_6);

    SHOPPES_0202(local_8);
}

// CHECKED (loop)
void SHOPPES_07be(int param_1)
{
    bool local_8;
    int local_14;
    int local_a;
    int local_e;
    int local_10;
    int local_12;
    int local_c;
    byte local_4;
    ActorFmt* local_18;

    for (local_10 = 0; local_10 < 32; local_10++)
    {
        if (D_5c5a[local_10]._0_tile == 0)
            break;
    }

    for (local_c = 0; local_c < 4; local_c++)
    {
        local_a = D_3c38[local_c] + D_5896_map_x;
        local_e = D_3c40[local_c] + D_5897_map_y;
        local_14 = *ULTIMA_4402_GetTileAddr(local_a, local_e);

        if (ULTIMA_368e_FindNpcTileAtPos(local_a, local_e, D_5895_map_level) == 0)
        {
            if (local_14 == 0x44 || local_14 == 0x45 || local_14 == 5)
                break;
        }
    }

    // aabf
    if (local_c == 4 || local_10 == 0x20)
    {
        ULTIMA_1850_PrintString(/*0x7a48*/ "The stables are closed.\n");
    }
    else
    {
        local_8 = 0;
        local_12 = 0;

        D_b118 = D_3c30[D_b114];
        D_b118 += (D_b118 * -((s32)(D_55a8_party[param_1]._e * 3) - 100) / (u32)100);

        SHOPPES_01b6();
        do
        {
            local_4 = ULTIMA_266c_GetChar();
            switch (local_4)
            {
            case 0x59:
                ULTIMA_1850_PrintString(/*0x7a62*/ "Yes\n\n\"");
                SHOPPES_017a(5699); // 0x1643
                ULTIMA_1850_PrintString(/*0x7a6a*/ "\n\nDeal?\" ");

                do
                {
                    local_4 = ULTIMA_266c_GetChar();
                    if (local_4 == 'Y')
                        break;
                } while (local_4 != 'N');

                if (local_4 == 'N')
                {
                    ULTIMA_1850_PrintString(/*0x7a74*/ "No");
                    local_8 = 1;
                }
                else
                {
                    ULTIMA_1850_PrintString(/*0x7a78*/ "Yes!");
                    if (D_57aa < D_b118)
                    {
                        ULTIMA_1850_PrintString(/*0x7a7e*/ "\n\n\"Thou couldst not afford to ");
                        SHOPPES_0026(/*0x7a9e*/ "feed it!\"\nyells $.\n");
                        local_12 = -1;
                    }
                    else
                    {
                        // abda
                        D_57aa -= D_b118;
                        SHOPPES_019a();

                        local_18 = &D_5c5a[local_10];
                        local_18->_6 = local_18->_7 = local_18->_5 = 0;
                        local_18->_0_tile = local_18->_1 = 0x10;
                        local_18->_2_x = local_a;
                        local_18->_3_y = local_e;
                        local_18->_4_z = D_5895_map_level;

                        ULTIMA_5910_UpdateFrame();
                        ULTIMA_2900_UpdateVitalsDisplay();
                        local_12 = 1;
                    }

                    local_8 = 1;
                }
                break;

            case 0x20:
            case 0x4e:
                ULTIMA_1850_PrintString(/*0x7ab2*/ "No");
                local_8 = 1;
                break;
            }
        } while (!local_8);

        SHOPPES_0202(local_12);
    }
}

// OK P1
int SHOPPES_09ac(int param_1, int param_2, int param_3)
{
    byte local_4;

    D_b118 = D_3a82[param_2];
    D_b118 += (D_b118 * -((s32)(D_55a8_party[param_1]._e * 3) - 100) / (u32)100);

    ULTIMA_1850_PrintString(/*0x7b5e*/ "\n\n\"");
    SHOPPES_017a(D_3c48[param_2]);
    ULTIMA_1850_PrintString(/*0x7b62*/ "\n\n");
    ULTIMA_1850_PrintString(D_3ca6[ULTIMA_2092_RandomRange(0, 3)]);
    ULTIMA_1850_PrintString(/*0x7b66*/ "\" ");

    do
    {
        local_4 = ULTIMA_266c_GetChar();
        if (local_4 == 'N')
        {
            ULTIMA_1850_PrintString(/*0x7b6a*/ "No\n\n");
        }
        else if (local_4 == 'Y')
        {
            ULTIMA_1850_PrintString(/*0x7b70*/ "Yes\n");
            if (D_57c0[param_2] == 99)
            {
                ULTIMA_1850_PrintString(/*0x7b76*/ "\n\"Thou canst not carry any more!\"\n");
                SHOPPES_0026(/*0x7b9a*/ "says $.\n\n");
                ULTIMA_266c_GetChar();
            }
            else if (D_57aa < D_b118)
            {
                ULTIMA_1850_PrintString(/*0x7ba4*/ "\n\"");
                ULTIMA_1850_PrintString(D_3cae[ULTIMA_2092_RandomRange(0, 3)]);
                SHOPPES_0026(/*0x7ba8*/ "\"\nyells $.\n");
                param_3 = -1;
            }
            else
            {
                D_57aa -= D_b118;
                SHOPPES_019a();
                ULTIMA_2900_UpdateVitalsDisplay();
                if (param_2 == 0x1b || param_2 == 0x1d)
                {
                    D_57c0[param_2] = 99;
                }
                else
                {
                    ULTIMA_3ef0(param_2 + D_57c0, 1, 99);
                }

                SHOPPES_0026(/*0x7bb4*/ "\nSold!\n");
                param_3 = 1;
            }
        }
    } while (local_4 != 'N' && local_4 != 'Y');

    if (param_3 != -1)
    {
        ULTIMA_1850_PrintString(/*0x7bbc*/ "\"Anything else,\n");
        if (param_3 != 0)
        {
            if (D_55a8_party[param_1]._9 == 12)
            {
                ULTIMA_1850_PrintString(/*0x7bce*/ "milady?");
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x7bd6*/ "sir?");
            }
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x7bdc*/ "then?");
        }
    }

    return param_3;
}

// CHECKED
int SHOPPES_0b30(int param_1)
{
    bool local_6;
    int local_c;
    int local_8;
    int local_a;
    byte local_4;

    local_6 = 0;
    local_a = 0;
    do
    {
        ULTIMA_1850_PrintString(/*0x7c44*/ "\n\n");

        for (local_8 = 0; local_8 < 8; local_8++)
        {
            local_c = D_3ae2[D_b114][local_8];
            if (local_c == 0xff)
                break;

            // ae5c
            ULTIMA_16ba_PrintChar(local_8 + 0x61); // + 'a' NOT MATCHING
            ULTIMA_1850_PrintString(/*0x7c48*/ "...");

            if (ULTIMA_216c_strlen(D_17f6[local_c]) < 0xd)
            {
                ULTIMA_1850_PrintString(D_17f6[local_c]);
            }
            else
            {
                ULTIMA_1850_PrintString(D_1962[local_c]);
            }

            if (ULTIMA_1f12_GetCurrentTextX() != 0)
            {
                ULTIMA_16ba_PrintChar(10);
            }
        }

        ULTIMA_16ba_PrintChar(10);
        ULTIMA_1850_PrintString(D_3cb6[ULTIMA_2092_RandomRange(0, 3)]);
        ULTIMA_1850_PrintString(/*0x7c4c*/ "\" ");

        do
        {
            // ae1b
            local_4 = ULTIMA_266c_GetChar();
            local_c = local_4 - 0x41; // - 'A'
            if (local_c < local_8 && local_c >= 0)
            {
                ULTIMA_16ba_PrintChar(local_c + 0x61); // + 'a' NOT MATCHING
                local_a = SHOPPES_09ac(param_1, D_3ae2[D_b114][local_c], local_a);
                if (local_a == -1)
                {
                    local_6 = 1;
                }
            }
            else
            {
                if (local_4 == 0x1b || local_4 == 0x20)
                {
                    local_6 = 1;
                }
                else
                {
                    local_4 = 0;
                }
            }
        } while (local_4 == 0 && !local_6);
    } while (!local_6);

    return local_a;
}

// OK P1
int SHOPPES_0c58(void)
{
    int local_4;

    for (local_4 = 0; local_4 < 0x30; local_4++)
    {
        if (D_57c0[local_4] != 0)
        {
            return 1;
        }
    }

    return 0;
}

// OK P1
int SHOPPES_0c80(int* param_1, int* param_2)
{
    int local_6;
    int local_a;
    int local_8;
    int local_4;

    if (D_57c0[*param_2] == 0)
    {
        if (*param_1 == *param_2)
        {
            *param_2 = ZSTATS_056c(*param_2, 0x30, D_57c0, 0xff);
            if (*param_2 == -1)
            {
                *param_2 = ZSTATS_05a4(-1, 0x30, D_57c0, 0xff);
            }

            *param_1 = *param_2;
        }
        else
        {
            *param_2 = ZSTATS_05a4(*param_2, 0x30, D_57c0, 0xff);
            if (*param_2 == -1)
            {
                *param_2 = ZSTATS_056c(0x30, 0x30, D_57c0, 0xff);
                if (ZSTATS_056c(*param_1, 0x30, D_57c0, 0xff) > -1)
                {
                    *param_1 = ZSTATS_056c(*param_1, 0x30, D_57c0, 0xff);
                }
            }
        }
    }

    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_1bf2_SetTextPosition(1, 1);

    local_8 = *param_1;
    while (local_8 != -1)
    {
        if (*param_2 == local_8)
        {
            ULTIMA_16ba_PrintChar(0xfd);
            local_4 = ULTIMA_1cee_GetCurrentTextY();
        }

        ZSTATS_05e2(local_8, D_57c0, D_1962, 0x2d);

        if (*param_2 == local_8)
        {
            ULTIMA_16ba_PrintChar(0xfd);
        }

        ULTIMA_1bf2_SetTextPosition(1, ULTIMA_1cee_GetCurrentTextY());
        if (ULTIMA_1cee_GetCurrentTextY() == 5)
            break;
        
        local_8 = ZSTATS_05a4(local_8, 0x30, D_57c0, 0xff);
    }

    for (local_6 = ULTIMA_1cee_GetCurrentTextY(); local_6 != 5; local_6 = local_6 + 1)
    {
        ULTIMA_1bf2_SetTextPosition(1, local_6);
        ULTIMA_1850_PrintString(/*0x7c50*/ "             ");
    }

    local_a = 0;
    if (ZSTATS_056c(*param_1, 0x30, D_57c0, 0xff) != -1)
    {
        local_a = 2;
    }

    if (local_8 != -1 && ZSTATS_05a4(local_8, 0x30, D_57c0, 0xff) != -1)
    {
        local_a++;
    }

    if (local_a != 0)
    {
        ULTIMA_1bf2_SetTextPosition(6, 6);
        ULTIMA_4c2a();
    }

    switch (local_a)
    {
    case 0:
        ULTIMA_4f3c();
        break;
    case 1:
        ULTIMA_16ba_PrintChar(0x19);
        ULTIMA_4cce();
        break;
    case 2:
        ULTIMA_16ba_PrintChar(0x18);
        ULTIMA_4cce();
        break;
    case 3:
        ULTIMA_16ba_PrintChar(0x12);
        ULTIMA_4cce();
        break;
    }

    ULTIMA_1b94_SelectTextWindow(2);

    return local_4;
}

// OK P1
int SHOPPES_0e76(int param_1, int param_2)
{
    byte local_4;

    if (param_2 == 0x1b || param_2 == 0x1d)
    {
        SHOPPES_0026(/*0x7d32*/ "\n\n\"We don't deal in used ammunition!\"\ngrowls $.\n");
        return 1;
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x7d64*/ "\n\n\"");
        if (D_3a82[param_2] != 0)
        {
            D_b118 = (D_55a8_party[param_1]._e * D_3a82[param_2] * (u32)3) / (u32)100 + 1;

            D_ab00 = D_3cce[param_2];
            if (D_3cce[param_2] == 0)
            {
                D_ab00 = D_17f6[param_2];
            }

            //SHOPPES_0026(D_3cbe[iVar5] + 0xa65e);
            SHOPPES_0026((char*)&D_b21e[D_3cbe[ULTIMA_2092_RandomRange(0, 7)] + 0xa65e - 0xb21e]);
            ULTIMA_1850_PrintString(/*0x7d68*/ "\n\nDeal?\" ");
            do
            {
                local_4 = ULTIMA_266c_GetChar();
            } while (local_4 != 'N' && local_4 != 'Y');

            if (local_4 == 'N')
            {
                ULTIMA_1850_PrintString(/*0x7d72*/ "No");
            }
            else
            {
                SHOPPES_0026(/*0x7d76*/ "Yes\n\n\"Done!\"\nsays $.");
                ULTIMA_3f14(&D_57aa, D_b118, 9999);
                ULTIMA_3f36(&D_57c0[param_2], 1);
            }
            ULTIMA_2884_UpdateGoldDisplay();
        }
        else
        {
            SHOPPES_0026(/*0x7d8c*/ "That, I cannot buy from thee.\"\nsays $.");
        }

        return 0;
    }
}

// CHECKED (di)
void SHOPPES_0f64(int param_1)
{
    int local_14;
    int local_16;
    int local_12;
    int local_10;
    int local_e;
    int local_c;
    int local_a;
    byte local_8;
    int local_6;
    int local_4;

    if (SHOPPES_0c58() != 0)
    {
        ULTIMA_1850_PrintString(D_3d2e[ULTIMA_2092_RandomRange(0, 3)]);
        ULTIMA_1850_PrintString(/*0x7ef0*/ "\" ");
        ULTIMA_4e50(/*0x7ef4*/ "Arms");
        ULTIMA_1b94_SelectTextWindow(1);
        ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x26, 6);
        ULTIMA_16ba_PrintChar(0xff);
        ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x27, 9);
        ULTIMA_16ba_PrintChar(0x10);

        for (local_e = 0; local_e < 0xd; local_e++)
        {
            ULTIMA_16ba_PrintChar(0x11);
        }

        ULTIMA_16ba_PrintChar(0x13);

        for (local_e = 1; local_e < 5; local_e++)
        {
            ULTIMA_1bf2_SetTextPosition(0, local_e);
            ULTIMA_16ba_PrintChar(0x17);
            ULTIMA_1bf2_SetTextPosition(0xe, local_e);
            ULTIMA_16ba_PrintChar(0x17);
        }

        ULTIMA_16ba_PrintChar(10);
        ULTIMA_16ba_PrintChar(0x14);

        for (local_e = 0; local_e < 0xd; local_e++)
        {
            ULTIMA_16ba_PrintChar(0x15);
        }

        ULTIMA_16ba_PrintChar(0x16);

        local_10 = local_6 = ZSTATS_05a4(-1, 0x30, D_57c0, 0xff);
        local_c = SHOPPES_0c80(&local_6, &local_10);
        local_a = local_12 = 0;

        ULTIMA_256e_ReadFile(/*0x7efa*/ "SHOPPE.DAT", D_b21e, 1500, 3008); // offset: 0xbc0

        // b317
        while (local_a == 0)
        {
            // b320
            local_8 = ULTIMA_266c_GetChar();

            switch (local_8)
            {
            case 1:
            case 3:
            case 0xd5:
                // b34c
                if (local_8 == 0xd5)
                {
                    local_4 = 4;
                }
                else
                {
                    local_4 = 1;
                }

                local_e = 0;
                if (local_4 > 0)
                {
                    local_16 = local_4;
                    local_e += local_4;

                    do
                    {
                        // b376
                        local_14 = ZSTATS_056c(local_10, 0x30, D_57c0, 0xff);

                        if (local_10 == local_6)
                        {
                            if (local_14 > -1)
                            {
                                local_6 = local_14;
                                // b395
                                local_10 = local_14; // di = si
                            }
                        }
                        else
                        {
                            // b395
                            local_10 = local_14;
                        }

                        local_16--;
                    } while (local_16 != 0);

                    // b39f
                    //local_14 = si;
                }

                // b3a2
                local_c = SHOPPES_0c80(&local_6, &local_10);
                break;

            case 2:
            case 4:
            case 0xd6:
                // b3b4
                if (local_8 == 0xd6)
                {
                    local_4 = 4;
                }
                else
                {
                    local_4 = 1;
                }

                local_e = 0;
                if (local_4 > 0)
                {
                    // di = local_4
                    local_16 = local_4;
                    local_e += local_4;

                    do
                    {
                        // b3da
                        local_14 = ZSTATS_05a4(local_10, 0x30, D_57c0, 0xff);
                        if (local_14 > -1)
                        {
                            local_10 = local_14;
                            if (++local_c > 4)
                            {
                                local_6 = ZSTATS_05a4(local_6, 0x30, D_57c0, 0xff);
                            }
                        }
                        // b414
                        local_16--;
                    } while (local_16 != 0); // NOT MATCHING (di?)

                    // -> b39f
                }
                // else -> b3a2

                local_c = SHOPPES_0c80(&local_6, &local_10);
                break;

            case 0xd3:
                // b41a
                local_10 = local_6 = ZSTATS_05a4(-1, 0x30, D_57c0, 0xff);
                local_c = SHOPPES_0c80(&local_6, &local_10);
                break;

            case 0xd4:
                // b436
                local_10 = local_6 = ZSTATS_056c(0x30, 0x30, D_57c0, 0xff);
                for (local_e = 1; local_e < 4; local_e++)
                {
                    local_14 = ZSTATS_056c(local_6, 0x30, D_57c0, 0xff);
                    if (local_14 == -1)
                        break;

                    local_6 = local_14;
                }

                local_c = SHOPPES_0c80(&local_6, &local_10);
                break;

            case 0xd:
            case 0x20:
                // b47a
                local_12 = SHOPPES_0e76(param_1, local_10);
                if (local_12 == 0 && SHOPPES_0c58() != 0)
                {
                    local_c = SHOPPES_0c80(&local_6, &local_10);
                    ULTIMA_1850_PrintString(/*0x7f06*/ "\n\n\"");
                    ULTIMA_1850_PrintString(D_3d3e[ULTIMA_2092_RandomRange(0, 3)]);
                    ULTIMA_1850_PrintString(/*0x7f0a*/ "\" ");
                }
                else
                {
                    local_a = 1;
                }
                break;

            case 0x1b:
                // b4c6
                local_a = 1;
                break;
            }
        }

        // b4f6 (OK)
        ULTIMA_2900_UpdateVitalsDisplay();
        ULTIMA_4e20();

        if (local_12 != 0)
        {
            return;
        }

        ULTIMA_1850_PrintString(/*0x7f0e*/ "\n\n\"");
        ULTIMA_1850_PrintString(D_3d36[ULTIMA_2092_RandomRange(0, 3)]);
        ULTIMA_1850_PrintString(/*0x7f12*/ "\"\n");

        if (SHOPPES_0c58() == 0)
        {
            return;
        }

        SHOPPES_0026(/*0x7f16*/ "says $.\n");
    }
    else
    {
        SHOPPES_0026(/*0x7f20*/ "Thou hast nothing to sell!\"\ngrowls $.\n");
    }
}

// OK P1
void SHOPPES_12b2(int param_1)
{
    byte local_4;
    int local_6;

    local_6 = 0;

    SHOPPES_0026(/*0x8018*/ "\"Good @, and welcome to #!\"\n");
    ULTIMA_266c_GetChar();
    SHOPPES_0026(/*0x8036*/ "\n$ says,\n\"");

    ULTIMA_1850_PrintString(D_3d46[ULTIMA_2092_RandomRange(0, 1)]);
    ULTIMA_1850_PrintString(/*0x8042*/ "\" ");

    do
    {
        local_4 = ULTIMA_266c_GetChar();
        switch (local_4)
        {
        case 0x42:
            ULTIMA_1850_PrintString(/*0x8046*/ "Buy\n\n\"");
            ULTIMA_1850_PrintString(D_3d4a[ULTIMA_2092_RandomRange(0, 3)]);
            ULTIMA_1850_PrintString(D_3d52[ULTIMA_2092_RandomRange(0, 3)]);
            local_6 = SHOPPES_0b30(param_1);
            break;
        case 0x53:
            ULTIMA_1850_PrintString(/*0x804e*/ "Sell\n\n\"");
            SHOPPES_0f64(param_1);
            local_6 = -1;
            break;
        case 0x20:
            ULTIMA_1850_PrintString(/*0x8056*/ "No");
            break;
        }
    } while (local_4 != 'B' && local_4 != 'S' && local_4 != ' ');

    SHOPPES_0202(local_6);
}

// OK P1
int SHOPPES_137c(void)
{
    int local_4;

    if (D_585b == 1)
    {
        local_4 = 0;
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x805a*/ "\n\n\"Who needs my aid?\" ");
        local_4 = ULTIMA_2e8e();
        if (local_4 == -1)
        {
            ULTIMA_1850_PrintString(/*0x8072*/ "No one");
        }
    }

    return local_4;
}

// OK P1
void SHOPPES_13b0(void)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13ae);
    ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);
    ULTIMA_2192_AudioPulse(0x100e, 1, 0x57e4, 5000, 1);
    ULTIMA_2192_AudioPulse(0x100e, 1, 0x57e4, 0x6b6c, -1);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);
    ULTIMA_2192_AudioPulse(0x11b2, 1, 40000, 1, 1);
    ULTIMA_2192_AudioPulse(0x11b2, 1, 40000, 40000, -1);
    ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);
    ULTIMA_2192_AudioPulse(0x8fc, 1, 18000, 1, 2);
    ULTIMA_2192_AudioPulse(0x8fc, 1, 18000, 36000, -2);
}

// CHECKED (si)
int SHOPPES_146a(void)
{
    int local_4;
    bool local_6;

    SHOPPES_0026(/*0x807a*/ "for % gold.\n\nWilt thou\npay?\" ");
    do
    {
        // b708
        local_4 = ULTIMA_266c_GetChar();
        if (local_4 == 'Y') // NOT MATCHING
        {
            ULTIMA_1850_PrintString(/*0x8098*/ "Yes");
        }
        else if (local_4 == 'N')
        {
            ULTIMA_1850_PrintString(/*0x809c*/ "No");
        }

        // b726
    } while (local_4 != 'Y' && local_4 != 'N');

    // b732
    local_6 = local_4 == 'N';

    // b742
    if (local_6 == 0 && D_57aa < D_b118 && (D_b118 > 100 || D_5893_map_id != 7))
    {
        // b75e
        SHOPPES_017a(9131); // 0x23ab
        local_6 = 1;
    }

    // b76a
    if (local_6 == 0 && D_57aa >= D_b118)
    {
        D_57aa -= D_b118;
        SHOPPES_019a();
    }

    // b780
    return local_6;
}

// CHECKED
void SHOPPES_14f8(void)
{
    int local_6;
    byte local_4;
    int local_8;

    SHOPPES_01b6();

    local_6 = 0;
    while (!local_6)
    {
        do
        {
            local_4 = ULTIMA_266c_GetChar();
            if (local_4 == 'N')
            {
                ULTIMA_1850_PrintString(/*0x80a0*/ "No");
            }
            else if (local_4 == 'Y')
            {
                ULTIMA_1850_PrintString(/*0x80a4*/ "Yes\n\n");
            }
        } while (local_4 != 'N' && local_4 != 'Y');

        if (local_4 == 'N')
            break;

        ULTIMA_1850_PrintString(/*0x80aa*/ "\"We have powers to Cure, Heal, or Resurrect.\"\n");
        SHOPPES_0026(/*0x80da*/ "says $.\n\n\"What is the nature of thy need?\" ");

        do
        {
            local_4 = ULTIMA_266c_GetChar();
        } while (local_4 != 'C' && local_4 != 'H' && local_4 != 'R' && local_4 != ' ' && local_4 != '\r');

        switch (local_4)
        {
        case 0x43:
            // b826
            ULTIMA_1850_PrintString(/*0x8106*/ "Curing");
            local_8 = SHOPPES_137c();
            if (local_8 != -1)
            {
                // b856
                if (D_55a8_party[local_8]._b != 'P')
                {
                    // b864
                    SHOPPES_0026(D_3d5a);
                }
                else
                {
                    // b86e
                    ULTIMA_1850_PrintString(/*0x810e*/ "\n\n\"");
                    if (D_5893_map_id == 5)
                    {
                        ULTIMA_1850_PrintString(/*0x8112*/ "Receive now the Light!\"");
                        // -> b8a1
                        SHOPPES_13b0();
                        D_55a8_party[local_8]._b = 0x47;
                    }
                    else
                    {
                        // b886
                        ULTIMA_1850_PrintString(/*0x812a*/ "I can cure thy poisoned body ");
                        D_b118 = D_3d8e[D_b114];
                        if (SHOPPES_146a() == 0)
                        {
                            // b8a1
                            SHOPPES_13b0();
                            D_55a8_party[local_8]._b = 0x47;
                        }
                    }
                }
            }
            break;
        case 0x48:
            // b8b2
            ULTIMA_1850_PrintString(/*0x8148*/ "Healing");
            local_8 = SHOPPES_137c();
            if (local_8 != -1)
            {
                // b8c7
                if (D_55a8_party[local_8]._b != 'D' && D_55a8_party[local_8]._10 != D_55a8_party[local_8]._12)
                {
                    ULTIMA_1850_PrintString(/*0x8150*/ "\n\n\"");
                    if (D_5893_map_id == 5)
                    {
                        ULTIMA_1850_PrintString(/*0x8154*/ "Receive now the Light!\"");
                        // -> b914
                        SHOPPES_13b0();
                        D_55a8_party[local_8]._10 = D_55a8_party[local_8]._12;
                    }
                    else
                    {
                        // b8f6
                        ULTIMA_1850_PrintString(/*0x816c*/ "I can heal thee ");
                        D_b118 = D_3d86[D_b114];
                        if (SHOPPES_146a() == 0)
                        {
                            // b914
                            SHOPPES_13b0();
                            D_55a8_party[local_8]._10 = D_55a8_party[local_8]._12;
                        }
                    }
                }
                else
                {
                    // -> b864
                    SHOPPES_0026(D_3d5a);
                }
            }
            break;
        case 0x52:
            // b92a
            ULTIMA_1850_PrintString(/*0x817e*/ "Resurrect");
            local_8 = SHOPPES_137c();
            if (local_8 != -1)
            {
                if (D_55a8_party[local_8]._b == 'D')
                {
                    ULTIMA_1850_PrintString(/*0x8188*/ "\n\n\"");
                    ULTIMA_1850_PrintString(/*0x818c*/ "I can raise this unfortunate person from ");
                    ULTIMA_1850_PrintString(/*0x81b6*/ "the dead ");

                    D_b118 = D_3d96[D_b114];

                    if (SHOPPES_146a() == 0)
                    {
                        SHOPPES_13b0();
                        CAST2_05e0(local_8, 0xff);
                        D_55a8_party[local_8]._10 = D_55a8_party[local_8]._12;
                        ULTIMA_2900_UpdateVitalsDisplay();
                    }
                }
                else
                {
                    SHOPPES_0026(D_3d5a);
                }
            }
            break;
        case 0xd:
        case 0x20:
            // b99e
            ULTIMA_1850_PrintString(/*0x81c0*/ "Nothing");
            local_6 = 1;
            break;
        }

        // b838
        if (!local_6)
        {
            ULTIMA_2900_UpdateVitalsDisplay();
            ULTIMA_1850_PrintString(/*0x81c8*/ "\n\n\"Is there any other way in which I may\n");
            ULTIMA_1850_PrintString(/*0x81f2*/ "aid thee?\" ");
        }
    }

    SHOPPES_0202(1);
}
