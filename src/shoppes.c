#include "common/common.h"
#include "funcs.h"
#include "vars.h"
#include "macros.h"
#include "tiles.h"

#include <stdlib.h>
#include <string.h>

#include "cast2.h"
#include "shoppes.h"
#include "zstats.h"

STUB u16 D_3a82[0x30]; // TODO: int (FMT)

STUB u8 D_3ae2[9][8]; // ~3b2a)

STUB u16 D_3b2a[8][4]; // int (FMT: 4byte)
STUB u16 D_3b6a[8][4]; // ~3baa)
STUB u16 D_3baa[8][4]; // ~3bea)

STUB u16 D_3bea[4][4];
STUB u16 D_3c0a[3];
STUB u16 D_3c10[8];    // string offset table. type: int (FMT: 4bytes)

STUB char* D_3c20[8];

STUB u16 D_3c30[4];
STUB s16 D_3c38[4]; // 3c38..3c40)
STUB s16 D_3c40[4]; // 3c40..3c48)
STUB s16 D_3c48[0x2f]; // 3c40..3ca6)? shop item description TODO: size

STUB char* D_3ca6[4];
STUB char* D_3cae[4];
STUB char* D_3cb6[4];

STUB u16 D_3cbe[8]; // string offset table. type: int (FMT: 4bytes)

STUB char* D_3cce[0x30];

STUB char* D_3d2e[4];

STUB char* D_3d36[4];
STUB char* D_3d3e[4];
STUB char* D_3d46[2];
STUB char* D_3d4a[4];
STUB char* D_3d52[4];

STUB char* D_3d5a; // "\n\n\"Thou hast no need of this art!\"\nsays $."

STUB u8 D_3d86[8];
STUB u8 D_3d8e[8];
STUB u16 D_3d96[8];

u16 D_3a82[0x30] =
{
    0x000f, 0x0032, 0x0078, 0x0096, 0x0028, 0x0046, 0x0078, 0x07d0,
    0x0000, 0x0014, 0x0032, 0x0064, 0x0096, 0x012c, 0x02bc, 0x0000,
    0x0001, 0x000a, 0x0005, 0x0005, 0x000f, 0x0007, 0x0003, 0x0028,
    0x0032, 0x003c, 0x004b, 0x000a, 0x0096, 0x000f, 0x0046, 0x0055,
    0x0096, 0x00c8, 0x00fa, 0x0000, 0x0320, 0x00fa, 0x03e8, 0x0000,
    0x0000, 0x0000, 0x01c2, 0x01f4, 0x00c8, 0x0384, 0x00f0, 0x0000
};

u8 D_3ae2[9][8] =
{
    0x10, 0x11, 0x1a, 0x1b, 0x1c, 0x1d, 0x24, 0xff,
    0x13, 0x18, 0x2e, 0x16, 0x03, 0x06, 0x19, 0xff,
    0x00, 0x09, 0x0a, 0x12, 0x15, 0x25, 0x26, 0xff,
    0x02, 0x04, 0x0b, 0x17, 0x1e, 0x18, 0x1f, 0xff,
    0x20, 0x21, 0x22, 0x02, 0x05, 0x0c, 0x0e, 0xff,
    0x01, 0x07, 0x0d, 0x0e, 0x1e, 0x25, 0x2b, 0xff,
    0x00, 0x0a, 0x10, 0x14, 0x17, 0x13, 0x2a, 0xff,
    0x07, 0x20, 0x24, 0x1b, 0x1f, 0x2c, 0x2d, 0xff,
    0x01, 0x0d, 0x1c, 0x1d, 0x22, 0x16, 0x19, 0xff
};

u16 D_3b2a[8][4] =
{
    0x0000, 0x0000, 0x0000, 0x0000, 0x0d6c, 0x0da6, 0x0dd9, 0x0e14,
    0x1491, 0x14e1, 0x1513, 0x1557, 0x1697, 0x16d8, 0x1710, 0x174d,
    0x1a67, 0x1aaa, 0x1ae5, 0x1b25, 0x1f62, 0x1f92, 0x1fd1, 0x2026,
    0x223c, 0x2273, 0x22ab, 0x22df, 0x23e4, 0x241a, 0x245c, 0x2495
};

u16 D_3b6a[8][4] =
{
    0x0000, 0x0011, 0x0038, 0x0043, 0x0e44, 0x0e69, 0x0e85, 0x0ea1,
    0x159a, 0x15b4, 0x15be, 0x15c9, 0x1788, 0x179b, 0x17c7, 0x17d2,
    0x1b61, 0x1b73, 0x1b90, 0x1ba8, 0x205f, 0x2078, 0x2086, 0x209b,
    0x231e, 0x233c, 0x235e, 0x2381, 0x24f2, 0x250c, 0x2520, 0x2539
};

u16 D_3baa[8][4] =
{
    0x0057, 0x0064, 0x0076, 0x0083, 0x0ebc, 0x0ece, 0x0ee3, 0x0ef4,
    0x15ea, 0x160b, 0x161b, 0x1637, 0x17e6, 0x1807, 0x181d, 0x1832,
    0x1bbf, 0x1bda, 0x1bf5, 0x1c0f, 0x20bb, 0x20da, 0x20ee, 0x210e,
    0x231e, 0x233c, 0x235e, 0x2381, 0x2569, 0x2584, 0x25a2, 0x25be
};

u16 D_3bea[4][4] =
{
    0x00be, 0x00ff, 0x000c, 0x0118, 0x00a0, 0x00c8, 0x000b, 0x00af,
    0x00b9, 0x00e1, 0x0019, 0x0109, 0x00aa, 0x0096, 0x0014, 0x012c
};

u16 D_3c0a[3] = { 0x212d, 0x216c, 0x21b9 };

u16 D_3c10[8] = { 0x1c1c, 0x1c7c, 0x1cda, 0x1d3b, 0x1d8d, 0x1dee, 0x1e4e, 0x1ebd };

char* D_3c20[8] =
{
    /*0x79b4*/ "Sulfur Ash",
    /*0x79c0*/ "Ginseng",
    /*0x79c8*/ "Garlic",
    /*0x79d0*/ "Spider Silk",
    /*0x79dc*/ "Blood Moss",
    /*0x79e8*/ "Black Pearl",
    /*0x79f4*/ "Nightshade",
    /*0x7a00*/ "Mandrake"
};

u16 D_3c30[4] = { 0x0064, 0x0082, 0x00a0, 0x00be };
s16 D_3c38[4] = { 0x0000, 0x0000, 0x0001, 0xffff };
s16 D_3c40[4] = { 0x0001, 0xffff, 0x0000, 0x0000 };

s16 D_3c48[0x2f] =
{
    0x0095, 0x00d0, 0x011f, 0x0152, 0x0192, 0x01cb, 0x0209, 0x024d,
    0x0000, 0x02b2, 0x030a, 0x0342, 0x0376, 0x03c6, 0x0410, 0x0000,
    0x0465, 0x04a1, 0x04de, 0x0521, 0x0560, 0x05ab, 0x05f6, 0x0638,
    0x066e, 0x06b0, 0x06ee, 0x0721, 0x0742, 0x077c, 0x07a4, 0x07e7,
    0x082f, 0x0872, 0x08bb, 0x0000, 0x090e, 0x0959, 0x09a0, 0x0000,
    0x0000, 0x0000, 0x09f7, 0x0a60, 0x0ac2, 0x0b19, 0x0b78
};

char* D_3ca6[4] =
{
    /*0x7ab6*/ "Wouldst thou buy one?",
    /*0x7acc*/ "Wilt thou take it?",
    /*0x7ae0*/ "Wish ye it?",
    /*0x7aec*/ "May I get one for thee?"
};

char* D_3cae[4] =
{
    /*0x7b04*/ "Can't pay?! Out with ye, orc-face!",
    /*0x7b28*/ "What be ye trying to pull? OUT!",
    /*0x7b48*/ "OUT, SLIME!",
    /*0x7b54*/ "BEAT IT!",
};

char* D_3cb6[4] =
{
    /*0x7be2*/ "What may I show thee?",
    /*0x7bf8*/ "Which wouldst thou like to see?",
    /*0x7c18*/ "What is thine interest?",
    /*0x7c30*/ "Which would ye see?",
};

u16 D_3cbe[8] = { 0x0bc0, 0x0bff, 0x0c2e, 0x0c55, 0x0ca1, 0x0ce8, 0x0d12, 0x0d3d };

char* D_3cce[0x30] =
{
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    /*0x7c5e*/ "Cloth suit",
    /*0x7c6a*/ "Leather suit",
    /*0x7c78*/ "Ring Mail suit",
    /*0x7c88*/ "Scale suit",
    /*0x7c94*/ "Chain suit",
    /*0x7ca0*/ "Plate suit",
    /*0x7cac*/ "Mystic suits",
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    /*0x7cba*/ "Two-Handed Hammer",
    /*0x7ccc*/ "Two-Handed Axe",
    /*0x7cdc*/ "Two-Handed Sword",
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    /*0x7cee*/ "Invisibility Ring",
    /*0x7d00*/ "Protection Ring",
    /*0x7d10*/ "Regeneration Ring",
    /*0x7d22*/ "Turning Amulet",
    0,
    0
};

char* D_3d2e[4] =
{
    /*0x7db4*/ "Which item wouldst thou like to sell?",
    /*0x7dda*/ "What dost thou wish to sell?",
    /*0x7df8*/ "Show me what ye got...",
    /*0x7e10*/ "What dost thou have for me to buy?"
};
char* D_3d36[4] =
{
    /*0x7e34*/ "Good-bye...",
    /*0x7e40*/ "Mayhap another time...",
    /*0x7e58*/ "Godspeed...",
    /*0x7e64*/ "Fare thee well..."
};

char* D_3d3e[4] =
{
    /*0x7e76*/ "What else can ye offer me?",
    /*0x7e92*/ "What else hath ye to sell?",
    /*0x7eae*/ "What else doth thou wish to sell?",
    /*0x7ed0*/ "What other arms wilt thou sell?"
};

char* D_3d46[2] =
{
    /*0x7f48*/ "Hail, friend! Wouldst thou Buy or Sell?",
    /*0x7f70*/ "Greetings, traveller! Wish ye to Buy, or hast thou wares to Sell?",
};
char* D_3d4a[4] =
{
    /*0x7fb2*/ "Very good!\n",
    /*0x7fbe*/ "Excellent!\n",
    /*0x7fca*/ "Fine, fine!\n",
    /*0x7fd8*/ "But of course!\n"
};

char* D_3d52[4] =
{
    /*0x7fe8*/ "We have:",
    /*0x7ff2*/ "We stock:",
    /*0x7ffc*/ "Thou canst buy:",
    /*0x800c*/ "We've got:"
};

char* D_3d5a = "\n\n\"Thou hast no need of this art!\"\nsays $.";

u8 D_3d86[8] = { 0x23, 0x28, 0x2d, 0x32, 0x37, 0x3c, 0x41, 0x46 };
u8 D_3d8e[8] = { 0x14, 0x19, 0x1e, 0x23, 0x28, 0x0f, 0x0a, 0x01 };
u16 D_3d96[8] = { 0x00c8, 0x00d7, 0x00e1, 0x00ed, 0x00f7, 0x00f9, 0x0106, 0x010e };

// OK P1
static char* SHOPPES_0000(char* param_1, char* param_2)
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
    ULTIMA_256e_ReadFileFromDisk(/*0x7840*/ "SHOPPE.DAT", D_b21e, 1500, param_1);
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
        ULTIMA_3f54_DecreaseInt(&D_57aa, ULTIMA_2092_RandomRange(1, 0x40));
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
static int SHOPPES_02ba(int param_1, int param_2, int param_3)
{
    char local_4;

    ASSERT(param_2 < 3); // ?
    ASSERT(D_b114 < 4); // ?

    D_b118 = D_3bea[D_b114][param_2];
    D_b118 += (D_b118 * -((s32)(D_55a8_party[param_1].intel * 3) - 100) / (u32)100);

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
                    ULTIMA_3ef0_IncreaseByte(&D_57ac, 3, 99);
                    break;
                case 1:
                    ULTIMA_3ef0_IncreaseByte(&D_57ad, 4, 99);
                    break;
                case 2:
                    ULTIMA_3ef0_IncreaseByte(&D_57ae, 5, 99);
                    break;
                }

                param_3 = 1;
                SHOPPES_0026(/*0x78a0*/ "\n\"Sold!\"\nsays $.\n\n\"What else, \n");
                if (D_55a8_party[param_1].gender == 12)
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
static int SHOPPES_03f6(int param_1)
{
    bool local_6;
    int local_8;
    byte local_4;

    local_8 = local_6 = 0;

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

            case U5_KEY_ESC:
            case U5_KEY_SPACE:
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

        case U5_KEY_SPACE:
        case 0x4e:
            ULTIMA_1850_PrintString(/*0x7928*/ "No");
            local_6 = 1;
            break;
        }
    } while (!local_6);

    SHOPPES_0202(local_8);
}

STUB u8 D_3a32[5][8];
STUB u8 D_3a5a[5][8];

// CHECKED
static int SHOPPES_0502(int param_1, int param_2, int param_3)
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
        D_b118 += D_b118 * -((s32)(D_55a8_party[param_1].intel * 3) - 100) / (u32)100;
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
                    ULTIMA_3ef0_IncreaseByte(&D_5850[local_8], D_b11a, 99);
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
static int SHOPPES_0666(int param_1)
{
    bool local_6;
    int local_a;
    int local_e;
    byte local_c;
    int local_8;
    byte local_4;

    local_e = local_6 = 0;

    ULTIMA_256e_ReadFileFromDisk(/*0x7a0a*/ "SHOPPE.DAT", D_b21e, 1500, 6759); //offset: 0x1a67

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

            case U5_KEY_ENTER:
            case U5_KEY_ESC:
            case U5_KEY_SPACE:
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

        case U5_KEY_SPACE:
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

        if (ULTIMA_368e_FindActorTileAtPos(local_a, local_e, D_5895_map_level) == 0)
        {
            if (local_14 == TILE_MAP_44 || local_14 == TILE_MAP_45 || local_14 == TILE_MAP_GRASS)
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
        D_b118 += (D_b118 * -((s32)(D_55a8_party[param_1].intel * 3) - 100) / (u32)100);

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
                        local_18->_0_tile = local_18->_1_animTile = TILE_ACTOR_HORSE;
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

            case U5_KEY_SPACE:
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
static int SHOPPES_09ac(int param_1, int param_2, int param_3)
{
    byte local_4;

    D_b118 = D_3a82[param_2];
    D_b118 += (D_b118 * -((s32)(D_55a8_party[param_1].intel * 3) - 100) / (u32)100);

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
                    ULTIMA_3ef0_IncreaseByte(param_2 + D_57c0, 1, 99);
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
            if (D_55a8_party[param_1].gender == 12)
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
static int SHOPPES_0b30(int param_1)
{
    bool local_6;
    int local_c;
    int local_8;
    int local_a;
    byte local_4;

    local_a = local_6 = 0;

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
                if (local_4 == U5_KEY_ESC || local_4 == U5_KEY_SPACE)
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
static int SHOPPES_0c58(void)
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
static int SHOPPES_0c80(int* param_1, int* param_2)
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
static int SHOPPES_0e76(int param_1, int param_2)
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
            D_b118 = (D_55a8_party[param_1].intel * D_3a82[param_2] * (u32)3) / (u32)100 + 1;

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
                ULTIMA_3f14_IncreaseInt(&D_57aa, D_b118, 9999);
                ULTIMA_3f36_DecreaseByte(&D_57c0[param_2], 1);
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
static void SHOPPES_0f64(int param_1)
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

        ULTIMA_256e_ReadFileFromDisk(/*0x7efa*/ "SHOPPE.DAT", D_b21e, 1500, 3008); // offset: 0xbc0

        // b317
        while (local_a == 0)
        {
            // b320
            local_8 = ULTIMA_266c_GetChar();

            switch (local_8)
            {
            case U5_KEY_LEFT:
            case U5_KEY_UP:
            case U5_KEY_PGUP:
                // b34c
                if (local_8 == U5_KEY_PGUP)
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

            case U5_KEY_RIGHT:
            case U5_KEY_DOWN:
            case U5_KEY_PGDN:
                // b3b4
                if (local_8 == U5_KEY_PGDN)
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

            case U5_KEY_HOME:
                // b41a
                local_10 = local_6 = ZSTATS_05a4(-1, 0x30, D_57c0, 0xff);
                local_c = SHOPPES_0c80(&local_6, &local_10);
                break;

            case U5_KEY_END:
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

            case U5_KEY_ENTER:
            case U5_KEY_SPACE:
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

            case U5_KEY_ESC:
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
        case U5_KEY_SPACE:
            ULTIMA_1850_PrintString(/*0x8056*/ "No");
            break;
        }
    } while (local_4 != 'B' && local_4 != 'S' && local_4 != U5_KEY_SPACE);

    SHOPPES_0202(local_6);
}

// OK P1
static int SHOPPES_137c(void)
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
static void SHOPPES_13b0(void)
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
static int SHOPPES_146a(void)
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
void SHOPPES_14f8(int unused)
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
        } while (local_4 != 'C' && local_4 != 'H' && local_4 != 'R' &&
                 local_4 != U5_KEY_SPACE && local_4 != U5_KEY_ENTER);

        switch (local_4)
        {
        case 0x43:
            // b826
            ULTIMA_1850_PrintString(/*0x8106*/ "Curing");
            local_8 = SHOPPES_137c();
            if (local_8 != -1)
            {
                // b856
                if (D_55a8_party[local_8].status != STATUS_POISONED)
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
                        D_55a8_party[local_8].status = STATUS_GOOD;
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
                            D_55a8_party[local_8].status = STATUS_GOOD;
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
                if (D_55a8_party[local_8].status != STATUS_DEAD && D_55a8_party[local_8].hp != D_55a8_party[local_8].maxHp)
                {
                    ULTIMA_1850_PrintString(/*0x8150*/ "\n\n\"");
                    if (D_5893_map_id == 5)
                    {
                        ULTIMA_1850_PrintString(/*0x8154*/ "Receive now the Light!\"");
                        // -> b914
                        SHOPPES_13b0();
                        D_55a8_party[local_8].hp = D_55a8_party[local_8].maxHp;
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
                            D_55a8_party[local_8].hp = D_55a8_party[local_8].maxHp;
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
                if (D_55a8_party[local_8].status == STATUS_DEAD)
                {
                    ULTIMA_1850_PrintString(/*0x8188*/ "\n\n\"");
                    ULTIMA_1850_PrintString(/*0x818c*/ "I can raise this unfortunate person from ");
                    ULTIMA_1850_PrintString(/*0x81b6*/ "the dead ");

                    D_b118 = D_3d96[D_b114];

                    if (SHOPPES_146a() == 0)
                    {
                        SHOPPES_13b0();
                        CAST2_05e0_Resurrect(local_8, 0xff);
                        D_55a8_party[local_8].hp = D_55a8_party[local_8].maxHp;
                        ULTIMA_2900_UpdateVitalsDisplay();
                    }
                }
                else
                {
                    SHOPPES_0026(D_3d5a);
                }
            }
            break;
        case U5_KEY_ENTER:
        case U5_KEY_SPACE:
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
