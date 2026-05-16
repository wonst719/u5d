#include "common/common.h"
#include "funcs.h"
#include "vars.h"

#include <string.h>

#include "town.h"

int NPC_12e0(int a, char b);

int TALK_0f32(byte param_1);
void TALK_127e(int a);

void SHOPPES_04a2(int param_1);
void SHOPPES_075e(int param_1);
void SHOPPES_07be(int param_1);
void SHOPPES_12b2(int param_1);
void SHOPPES_14f8(int param_1);
void SHOPPES2_066c(int param_1);
void SHOPPES2_0abc(int param_1);
void SHOPPES3_08b4(int param_1);

// NOT MATCHING: nop
int TALK_0000(char* param_1, char* param_2)
{
    while (1)
    {
        if (ULTIMA_2032_ToUpper(((int)*param_1++) & 0x7f) != ULTIMA_2032_ToUpper(((int)*param_2++) & 0x7f))
        {
            return 0;
        }

        if ((*param_1 == 0) && (*param_2 == 0))
        {
            return 1;
        }
    }
}

// OK P1
int TALK_0054(int param_1, int param_2)
{
    switch (*ULTIMA_4402_GetTileAddr(param_1, param_2))
    {
    case 0x29:
    case 0x94:
    case 0x95:
    case 0x96:
    case 0x97:
    case 0x98:
    case 0x99:
    case 0x9a:
    case 0x9b:
    case 0x9c:
    case 0xa5:
    case 0xae:
    case 0xba:
    case 0xbb:
    case 0xbe:
    case 0xca:
    case 0xcb:
        return 1;
    }

    return 0;
}

// OK P1
// ask pay
int TALK_00ac(void)
{
    char ch;

    ULTIMA_1850_PrintString("\n\nDost thou pay?\n\n:");

    do
    {
        ch = ULTIMA_2032_ToUpper(ULTIMA_266c_GetChar());
        if (ch == 'Y')
        {
            ULTIMA_1850_PrintString("Yes\n");
            return 0;
        }
    } while (ch != 'N');

    ULTIMA_1850_PrintString("No!\n");
    return 1;
}

// NOT MATCHING
void TALK_00e6(int param_1)
{
    int iVar1;
    int iVar2;

    if (((D_587c & 0xfe) == 0x12) && (param_1 != 0x83))
    {
        ULTIMA_1850_PrintString(/*0x9072*/ "A merchant says:\n\"GET THAT HORSE OUT OF HERE!\"\n");
    }
    else
    {
        if (D_587b == 0xff)
        {
            ULTIMA_39fc_GetFirstActivePartyMember();
            iVar1 = D_5876;
        }
        else
        {
            iVar1 = D_587b;
        }

        D_b116 = param_1 - 0x81;
        D_b114 = 0;

        while (D_23ca[D_b116 * 0x10 + D_b114] != D_5893_map_id)
        {
            if (D_b114 >= 0x10)
                break;

            D_b114++;
        }

        D_aafc = D_21ca[D_b116 * 0x10 + D_b114];
        D_aafe = D_22ca[D_b116 * 0x10 + D_b114];

        switch (D_b116)
        {
        case 0:
            SHOPPES_12b2(iVar1);
            break;
        case 1:
            SHOPPES2_066c(iVar1);
            break;
        case 2:
            SHOPPES_07be(iVar1);
            break;
        case 3:
            SHOPPES2_0abc(iVar1);
            break;
        case 4:
            SHOPPES_075e(iVar1);
            break;
        case 5:
            SHOPPES_04a2(iVar1);
            break;
        case 6:
            SHOPPES_14f8(iVar1);
            break;
        case 7:
            SHOPPES3_08b4(iVar1);
        }
    }
}

// NOT MATCHING
int TALK_01e2(void)
{
    int iVar1;
    int local_16;
    char local_12[4];
    byte local_e; // unused

    if (D_5893_map_id != 0x12)
    {
        if (D_5893_map_id == 5)
        {
            ULTIMA_16ba_PrintChar(0x22);
            ULTIMA_1850_PrintString(/*0x90a2*/ "Thou wilt give\nhalf thy gold to\ncharity!");
            ULTIMA_16ba_PrintChar(0x22);

            if (TALK_00ac() != 0)
            {
                return 1;
            }

            D_57aa /= 2;
        }
        else
        {
            local_16 = 0;
            for (iVar1 = 0; iVar1 < D_585b; iVar1++)
            {
                if (D_55a8_party[local_16]._b != 'D')
                {
                    local_16 += 10;
                }
            }

            ULTIMA_1850_PrintString(/*0x90cc*/ "A guard demands\na ");
            ULTIMA_1a3e_PrintNumber(local_16, 2, 0x20);
            ULTIMA_1850_PrintString(/*0x90e0*/ " gp tribute\nto Blackthorn!");

            if (TALK_00ac() != 0)
            {
                return 1;
            }

            if (D_57aa < local_16)
            {
                return 1;
            }

            D_57aa -= local_16;
        }

        ULTIMA_2900_UpdateVitalsDisplay();
        return 0;
    }

    if (D_587a == 0x1d)
    {
        ULTIMA_16ba_PrintChar(0x22);
        ULTIMA_1850_PrintString(/*0x90fc*/ "Give now the\npassword, bearer\nof the Badge!");
        ULTIMA_16ba_PrintChar(0x22);
        ULTIMA_1850_PrintString(/*0x9128*/ "\n\nYour response?\n");
        ULTIMA_3b1c_GetString(local_12, 0xe);
        ULTIMA_16ba_PrintChar(10);
        local_e = 0;

        if (TALK_0000(/*0x4a9a*/ "IMPE", local_12) != 0) // TODO: D_4a9a = "IMPE"?
        {
            ULTIMA_16ba_PrintChar(10);
            ULTIMA_16ba_PrintChar(0x22);
            ULTIMA_1850_PrintString(/*0x913a*/ "Pass, friend!");
            ULTIMA_16ba_PrintChar(0x22);
            ULTIMA_16ba_PrintChar(10);
            return 0;
        }
    }

    return 1;
}

// CHECKED
int TALK_031e(int param_1)
{
    int local_4;
    NpcFmt* local_6;
    NpcScheduleFmt* local_8;

    ULTIMA_16ba_PrintChar(10);

    D_bcdc = param_1;
    local_6 = &D_5f5e[param_1];
    local_8 = &D_5d5e[param_1];

    if (local_8->_0[local_6->_e] == 4)
    {
        local_8->_0[local_6->_e] = 1;
    }
    // c2ea NOT MATCHING
    else if (D_5c5a[local_6->_c]._0_tile == 112 && ((local_6->_e & 1) == 0 || (local_6->_a) == 0))
    {
        ULTIMA_1850_PrintString(/*0x9148*/ "The guard offers\nno response!\n");
        return 0;
    }

    local_4 = local_6->_a;
    if (local_4 == 0)
    {
        ULTIMA_1850_PrintString(/*0x9168*/ "No response!\n");
        return 0;
    }
    else
    {
        // c316
        if (local_4 < 0x80)
        {
            TALK_127e(local_4);
            return 0;
        }

        if (local_4 == 0xfd)
        {
            ULTIMA_16ba_PrintChar(0x22);
            ULTIMA_1850_PrintString(/*0x9176*/ "Don't hurt me!\nPlease go away!");
            ULTIMA_16ba_PrintChar(0x22);
            ULTIMA_16ba_PrintChar(10);
            return 0;
        }

        // c34c
        if (local_4 == 0xfe)
        {
#if !defined(TARGET_DOS16)
            TOWN_10da(param_1); // TODO: validate param (reference apple?)
#else
            TOWN_10da(); // BUG: TOWN_10da(unaff_SI)
#endif
            return 0;
        }

        if (local_4 == 0xff)
        {
            return TALK_01e2();
        }

        if ((local_6->_e & 1) != 0 && (NPC_12e0(D_bcdc, D_587f) & 1) != 0)
        {
            TALK_00e6(local_4);
            return 0;
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x9196*/ "A merchant says:\n\"Come see me at\nmy shoppe, ");
            ULTIMA_1850_PrintString(/*0x91c4*/ "when\nit's open!\"\n");
            return 0;
        }
    }
}

// OK P1
int TALK_041c_TalkCmd(void)
{
    int local_a;
    int local_8;
    int local_c;
    int local_4;
    int local_6;

    if (ULTIMA_35ec_SelectDirection() == 0)
    {
        return 0;
    }

    local_8 = D_5876;
    local_c = D_5878;
    local_6 = local_8 + D_5896_map_x;
    local_a = local_c + D_5897_map_y;

    if (ULTIMA_368e_FindNpcTileAtPos(local_6, local_a, D_5895_map_level) == 0 && TALK_0054(local_6, local_a) != 0)
    {
        local_6 += local_8;
        local_a += local_c;
    }

    if (ULTIMA_368e_FindNpcTileAtPos(local_6, local_a, D_5895_map_level) == 0)
    {
        ULTIMA_1850_PrintString(/*0x91d6*/ "\nNobody's here!\n");
    }
    else
    {
        local_4 = TOWN_011e(D_5876);
        switch (*ULTIMA_4402_GetTileAddr(local_6, local_a))
        {
        case 0xab:
            ULTIMA_1850_PrintString(/*0x91e8*/ "\n\"Zzzzzz...\"\n");
            break;
        case 0x9d:
            ULTIMA_1850_PrintString(/*0x91f6*/ "\nNo response!\n");
            break;
        default:
            return TALK_031e(local_4);
        }
    }

    return 0;
}

// OK P1
void TALK_04d2(void) { TALK_0f32(0x8d); }

// OK P1
void TALK_04da(void) { TALK_0f32(0xa2); }

// CHECKED
void TALK_04e2(void)
{
    byte local_6;
    int local_4;

    local_4 = 0;

    // c469
    if (D_4af1 != 0)
    {
        while (local_4 < D_4af1) // c4c9
        {
            // c4d5 -> c47c
            ULTIMA_1c9e_SelectCharset((D_bce4[local_4] & 0x80) == 0);
            local_6 = D_bce4[local_4] & 0x7f;
            local_4++;

            if (ULTIMA_1f12_GetCurrentTextX() != 0 || local_6 != 0x20)
            {
                // c49a
                if (D_4af3 < 0xf || local_6 != 10)
                {
                    // c4a7
                    if (local_6 != 10)
                    {
                        D_4af3 = ULTIMA_1f12_GetCurrentTextX();
                    }

                    // c4b3
                    ULTIMA_16ba_PrintChar(local_6);
                }
                else if (local_6 == 10) // c4be
                {
                    D_4af3 = 0;
                }
            }
        }

        // c4e0
        D_4af1 = 0;
        ULTIMA_1c9e_SelectCharset(0);
    }
}

// OK P1
void TALK_0574(byte param_1)
{
    if (D_4af1 != 0x10)
    {
        D_bce4[D_4af1++] = param_1;

        if (param_1 != 0x8a && param_1 != 0xa0)
        {
            return;
        }

        if (ULTIMA_1f12_GetCurrentTextX() + (uint)D_4af1 >= 0x12)
        {
            ULTIMA_16ba_PrintChar(10);
        }
    }

    TALK_04e2();
}

int TALK_0b04(void);

// OK P1
int TALK_05b6(void)
{
    int local_4;

    local_4 = (D_bce0[0] & 0x7f) * 100 + (D_bce0[1] & 0x7f) * 10 + (D_bce0[2] & 0x7f) - 0x14d0; // 0x14d0 == 5328
    if (D_57aa >= local_4)
    {
        D_57aa -= local_4;
        ULTIMA_2900_UpdateVitalsDisplay();
        if ((D_5c5a[D_5f5e[D_bcdc]._c]._0_tile & 0xfc) == 0x6c && D_588b >= 100)
        {
            D_588b = 0;
            ULTIMA_3ef0(&D_5888, 1, 99);
            if (D_57aa == 0)
            {
                ULTIMA_3ef0(&D_5888, 2, 99);
            }
        }

        return 0;
    }
    else
    {
        D_4af1 = 0;
        ULTIMA_16ba_PrintChar(0x22);
        ULTIMA_1850_PrintString(/*0x9328*/ "Thou hast not enough gold!");
        ULTIMA_16ba_PrintChar(0x22);
        ULTIMA_1850_PrintString(/*0x9344*/ "\n\n");

        D_4aef = D_4aee = 0;

        return TALK_0b04();
    }
}

// OK P1
void TALK_0682(byte param_1)
{
    if (param_1 < 0x40)
    {
        ULTIMA_3ef0(&D_57c0[param_1], 1, 99);
        return;
    }

    switch (param_1)
    {
    case 0x41:
        ULTIMA_3f14(&D_57a8, 1, 9999);
        ULTIMA_2900_UpdateVitalsDisplay();
        break;
    case 0x42:
        ULTIMA_3f14(&D_57aa, 1, 9999);
        ULTIMA_2900_UpdateVitalsDisplay();
        break;
    case 0x43:
        ULTIMA_3ef0(&D_57ac, 1, 99);
        break;
    case 0x44:
        ULTIMA_3ef0(&D_57ad, 1, 99);
        break;
    case 0x45:
        ULTIMA_3ef0(&D_57ae, 1, 99);
        break;
    case 0x46:
        ULTIMA_3ef0(&D_57af, 1, 99);
        break;
    case 0x47:
        ULTIMA_3ef0(&D_57b0, 1, 99);
        break;
    case 0x48:
        D_57bc = 0xff;
        break;
    case 0x49:
        D_57ba = 0xff;
        break;
    case 0x4a:
        D_57be = 0xff;
        break;
    case 0x4b:
        ULTIMA_3ef0(&D_57b1, 1, 99);
        break;
    }
}

// OK P1
int TALK_0728(byte param_1, byte param_2)
{
    byte local_4;

    do
    {
        local_4 = *D_bcde++;
        if (local_4 == param_1)
        {
            return 1;
        }

        if (local_4 == param_2)
        {
            return 0;
        }
    } while (1);
}

// CHECKED
void TALK_075a(int param_1)
{
    D_bcde = D_b21e;

    if (param_1 != 0)
    {
        for (; param_1 != 0; param_1--)
        {
            TALK_0728(0, 0x90);
        }
    }
}

int TALK_0f32(byte param_1);

// OK P1
int TALK_0788(void)
{
    while (*D_bcde != 0)
    {
        if (TALK_0f32(*D_bcde++) != 0)
        {
            return 1;
        }
    }

    return 0;
}

// OK P1
int TALK_07aa(int param_1)
{
    TALK_075a(param_1);
    return TALK_0788();
}

// OK P1
int TALK_07be(void)
{
    D_bcde++;

    while (*D_bcde == 0)
    {
        D_bcde++;
    }

    while (*D_bcde++ != 0)
    {
        // empty
    }

    return TALK_0788();
}

// OK P1
// put avatar name
void TALK_07e4(void)
{
    byte* local_4;
    local_4 = D_55a8_party[0]._0;

    while (*local_4 != 0)
    {
        TALK_0f32(*local_4++ | 0x80);
    }
}

// NOT MATCHING
// join
int TALK_080a(void)
{
    // int local_30; // 30..2f
    byte* local_2e;   // 2e..2d
    char local_2c[4]; // 2c..29
    S_55a8 local_28;  // 28..09 (size: 0x20)
    char local_8[4];  // 08..05
    int local_4;      // 04..03

    local_2e = D_bcde;
    local_4 = 0xf;

    if (D_585b == 6)
    {
        ULTIMA_266c_GetChar();
        ULTIMA_1850_PrintString(/*0x9348*/ "\"Thou hast no room for me in thy party! ");
        ULTIMA_1850_PrintString(/*0x9372*/ "Seek me again if one of thy members doth leave\nthee.");

        return 0;
    }

    TALK_075a(0);

    // local_30 = 0;

    // 3 bytes
    memcpy(local_8, D_bcde, 3);
    // local_30 += 3;
    D_bcde += 3;

    local_8[3] = 0;
    local_2c[3] = 0;
    do
    {
        // 3 bytes
        memcpy(local_2c, D_55a8_party[local_4]._0, 3);

        if (TALK_0000(local_8, local_2c) != 0)
        {
            // local_30 = DI;
            D_55a8_party[local_4]._1f = 0;

            ASSERT(sizeof(S_55a8) == 0x20);
            memcpy(&local_28, &D_55a8_party[local_4], sizeof(S_55a8));
            memcpy(&D_55a8_party[local_4], &D_55a8_party[D_585b], sizeof(S_55a8));
            memcpy(&D_55a8_party[D_585b]._0, &local_28, sizeof(S_55a8));

            D_585b++;

            TOWN_0052(D_bcdc);
            TOWN_00b0(D_bcdc);

            ULTIMA_2900_UpdateVitalsDisplay();
            TALK_04e2();

            D_bcde = local_2e;

            return 1;
        }
    } while (--local_4 != 0);

    TALK_0574(0x22);
    TALK_0574(10);
    ULTIMA_1850_PrintString(/*0x93a8*/ "\nSystem Error -\nNo Match!");
    D_bcde = local_2e;
    // local_30 = DI;

    return 1;
}

// OK P1
int TALK_093a(void)
{
    D_bcde = D_b21e;
    while (*D_bcde != D_bcf4)
    {
        TALK_0728(0x90, 0x9f);
    }
    D_bcde++;
    return TALK_0788();
}

// OK P1
int TALK_0960(void)
{
    TALK_0728(0, 0x90);
    return TALK_0788();
}

// OK P1
int TALK_096e(void)
{
    D_bcde = D_b21e;
    while (*D_bcde != D_bcf4)
    {
        TALK_0728(0x90, 0x9f);
    }
    TALK_0728(0, 0x9f);
    return TALK_0788();
}

// OK P1
int TALK_099a(int param_1)
{
    D_bcde = D_b21e;
    param_1 = param_1 * 2 + 5;

    while (param_1 != 0)
    {
        if (TALK_0728(0, 0x90) == 0)
            return 0;

        param_1--;
    }

    return 1;
}

// OK P1
int TALK_09d8(void)
{
    int local_4;

    D_bcf6 = 0;
    while (1)
    {
        if (TALK_099a(D_bcf6) == 0)
        {
            return 0;
        }

        local_4 = ULTIMA_6f1e(D_bcde, D_bcf8);
        if (local_4 != -1 && (local_4 == 0 || D_bcf8[local_4 - 1] == ' '))
        {
            return 1;
        }

        D_bcde++;
        D_bcf6++;
    }

    return 1;
}

// OK P1
void TALK_0a2c(void)
{
    TALK_04e2();
    ULTIMA_3b1c_GetString(D_bcf8, 0xf);
}

// OK P1
int TALK_0a3c(void)
{
    TALK_04da();
    if (TALK_07aa(4) == 0)
    {
        TALK_04da();
        TALK_04d2();
    }
    return 1;
}

// NOT MATCHING
int TALK_0a54(byte param_1)
{
    int local_4;

    switch (param_1)
    {
    case 0:
        // ca1c
        if (D_4af2 != 0)
        {
            return 2;
        }
        ULTIMA_1850_PrintString("\"My name is ");
        if (TALK_07aa(0) != 0)
        {
            return 1;
        }
        break;

    case 1:
    case 2:
        // ca3e
        if (D_4af2 != 0)
        {
            return 2;
        }
        TALK_04da();
        if (TALK_07aa(3) != 0)
        {
            return 1;
        }

        break;

    case 3:
    case 4:
        // ca60
        if (D_4af2 != 0)
        {
            return 2;
        }
        return TALK_0a3c();

    default:
        // c9f8
        ULTIMA_1850_PrintString("\"With language like that, how did you become an Avatar?");
        TALK_04da();
        TALK_04d2();
        TALK_04d2();

        for (local_4 = 0; local_4 < 0x1c; local_4++)
        {
            ULTIMA_5910_UpdateFrame();
            if (ULTIMA_1d5e_PollKey() != 0)
                break;
            ULTIMA_20fa_WaitTicks(1);
        }
        ULTIMA_1b16_ClearKbdBuffer();
        return 0;
    }

    TALK_04da();
    TALK_04d2();
    TALK_04d2();
    return 0;
}

// OK P1
int TALK_0b04(void)
{
    int local_8;
    int local_6;
    byte local_4;

    while (1)
    {
        D_4af2 = 0;
        ULTIMA_1850_PrintString("Your interest?\n:");
        TALK_0a2c();
        if (D_bcf8[0] == 0)
        {
            ULTIMA_1850_PrintString("BYE\n\n");
            return TALK_0a3c();
        }
        TALK_04d2();
        TALK_04d2();
        for (local_4 = 0, local_6 = -1; local_4 < 0x22; local_4++)
        {
            local_8 = ULTIMA_6f1e((byte*)D_4aa8[local_4], D_bcf8);
            if (local_8 != -1 && (local_8 == 0 || D_bcf8[local_8 - 1] == ' '))
            {
                local_6 = TALK_0a54(local_4);
                if (local_6 == 0)
                {
                    break;
                }

                if (local_6 == 1)
                {
                    return 1;
                }
            }
        }

        if (local_6 != 0)
        {
            if (TALK_09d8() == 0)
            {
                ULTIMA_1850_PrintString("\"I cannot help thee with that.");
                TALK_04da();
                TALK_04d2();
                TALK_04d2();
            }
            else
            {
                TALK_04da();
                if (TALK_07aa(D_bcf6 * 2 + 6) != 0)
                {
                    return 1;
                }
                TALK_04da();
                TALK_04d2();
                TALK_04d2();
            }
        }
    }
}

// OK P1
int TALK_0bd4(void)
{
    int local_4;

    D_bcde = D_b21e;
    while (*D_bcde != D_bcf4)
    {
        TALK_0728(0x90, 0x9f);
    }

    TALK_0728(0, 0x9f);
    TALK_0728(0, 0x9f);

    while (1)
    {
        local_4 = ULTIMA_6f1e(D_bcde, D_bcf8);
        if (local_4 != -1 && (local_4 == 0 || D_bcf8[local_4 - 1] == ' '))
        {
            return 1;
        }

        if (TALK_0728(0, 0x90) == 0)
        {
            return 0;
        }

        if (TALK_0728(0, 0x90) == 0)
        {
            return 0;
        }
    }
}

// NOT MATCHING
// process label?
int TALK_0c5c(void)
{
    int iVar1;
    int local_8;
    byte local_4;

    do
    {
        TALK_04da();
        if (TALK_093a() != 0)
        {
            return 1;
        }

        TALK_04da();

        do
        {
            TALK_04d2();
            TALK_04d2();
            D_4af2 = 0xff;
            ULTIMA_1850_PrintString(/*0x9440*/ "You respond-\n:");
            TALK_0a2c();
            if (D_bcf8[0] == 0)
            {
                ULTIMA_1850_PrintString(/*0x9450*/ "\n\n\"What didst thou say?");
            }
        } while (D_bcf8[0] == 0);

        TALK_04d2();
        TALK_04d2();
        for (local_4 = 0, iVar1 = -1; local_4 < 0x22; local_4++)
        {
            local_8 = ULTIMA_6f1e(D_4aa8[local_4], D_bcf8);
            if (local_8 != -1 && (local_8 == 0 || *(local_8 + D_bcf8 - 1) == ' '))
            {
                iVar1 = TALK_0a54(local_4);
                if (iVar1 == 0)
                    break;
                if (iVar1 == 1)
                {
                    return 1;
                }
            }
        }
    } while (iVar1 == 0);

    if (TALK_0bd4() == 0)
    {
        TALK_04da();
        iVar1 = TALK_096e();
    }
    else
    {
        TALK_04da();
        iVar1 = TALK_0960();
    }

    if (iVar1 == 0)
    {
        TALK_04da();
        TALK_04d2();
        TALK_04d2();
        return TALK_0b04();
    }
    else
    {
        return 1;
    }
}

// NOT MATCHING (u32 operation)
// set npc killed flag
int TALK_0d42(int param_1) { *(u32*)&D_5b5a[(D_5893_map_id - 1) * 4] |= (u32)1 << (byte)param_1; }

// NOT MATCHING (u32 operation)
// check npc killed flag
int TALK_0d7a(int param_1)
{
    return (*(u32*)&D_5b5a[(D_5893_map_id - 1) * 4] & ((u32)1 << (byte)param_1)) != 0;
}

// NOT MATCHING
int TALK_0dbe(byte param_1)
{
    switch (D_4aee)
    {
    default:
        // 0dda
        D_4aef = D_4aee = 0;
        // 0dfc ->
        // 0e74
        return 0;

    case 0x85:
        // 0de4
        D_bce0[D_4aef++] = param_1;
        if (D_4aef != 3)
        {
            // 0dfc
            return 0;
        }

        // 0e02
        if (TALK_05b6() != 0)
        {
            // -> 0e74
            return 1;
        }

        // 0dda
        D_4aef = D_4aee = 0;
        return 0;

    case 0x86:
        // 0e0e
        TALK_0682(param_1 & 0x7f);

        // 0dda
        D_4aef = D_4aee = 0;
        return 0;

    case 0x8c:
        // 0e1c
        D_4aef = D_4aee = 0;

        if (TALK_0d7a(D_bcdc) == 0)
        {
            // 0dfc
            return 0;
        }

        if (param_1 == 0xff)
        {
            return TALK_0b04();
        }

        // 0e3a
        D_bcf4 = param_1;

        // 0e3d
        return TALK_0c5c();

    case 0xfe:
        // 0e46
        D_bce0[D_4aef++] = param_1;
        if (D_4aef != 2)
        {
            // 0dfc
            return 0;
        }

        D_4aef = D_4aee = 0;

        if (D_5888 < D_bce0[0])
        {
            // 0dfc
            return 0;
        }

        D_bcf4 = D_bce0[1];

        // 0e3d
        return TALK_0c5c();
    }
}

// CHECKED
void TALK_0e78(void)
{
    int local_e;
    int local_c;
    int local_a;
    char local_8[4];
    int local_4;

    local_a = 0;
    TALK_04da();
    TALK_04e2();
    ULTIMA_1850_PrintString(/*0x9468*/ "What is thy name?\"\n");
    ULTIMA_1850_PrintString(/*0x947c*/ "\nYou respond-\n:");
    TALK_0a2c();

    D_4aee = D_4aef = 0;

    if (D_bcf8[0] == 0)
    {
        ULTIMA_1850_PrintString(/*0x948c*/ "\n\n\"If you say so...");
    }
    else
    {
        for (; local_a < D_585b; local_a++)
        {
            local_c = 0;
            memcpy(local_8, D_55a8_party[local_a]._0, 4);
            local_c = 4;
            local_4 = 0;

            local_e = ULTIMA_6f1e(local_8, D_bcf8);
            if (local_e != -1 && (local_e == 0 || (D_bcf8[local_e - 1] == ' ')))
            {
                TALK_0d42(D_bcdc);
                ULTIMA_1850_PrintString(/*0x94a0*/ "\n\n\"A pleasure!");
                return;
            }
        }

        ULTIMA_1850_PrintString(/*0x94b0*/ "\n\n\"If you say so...");
    }
}

// OK P1
int TALK_0f32(byte param_1)
{
    byte* local_4;
    int local_6;
    char* pbVar5;

    if (D_4aee != 0)
    {
        return TALK_0dbe(param_1);
    }

    // 0f4c
    D_4aef = 0;
    if ((param_1 == 0xa2) && (D_4af4 == 0xa2))
    {
        // 0f5e
        return 0;
    }

    // 0f64
    switch (param_1)
    {
    case 0x81: // avatar
        // 0f86
        TALK_07e4();
        break;
    case 0x82: // end conversation
        // 0f8c
        return 1;
    case 0x83: // pause
        // 0f92
        for (local_6 = 0; local_6 < 0x1c; local_6++)
        {
            ULTIMA_5910_UpdateFrame();
            if (ULTIMA_1d5e_PollKey() != 0)
                break;
            ULTIMA_20fa_WaitTicks(1);
        }
        ULTIMA_1b16_ClearKbdBuffer();
        return 0; // -> 0f5e
    case 0x84:    // join
        // 0fb6
        return TALK_080a(); // -> 1114
    case 0x87:                // key_or
        // 0fbc
        local_4 = D_bcde;
        if (TALK_07be() != 0)
        {
            return 1;
        }
        D_bcde = local_4;
        return 0; // -> 0f5e
    case 0x88:    // ask name
        // 0fd2
        TALK_0e78();
        return 0; // -> 0f5e
    case 0x89:    // karma +1
        // 0fd8
        ULTIMA_3ef0(&D_5888, 1, 99);
        return 0; // -> 0f5e
    case 0x8a:    // karma -1
        // 0fea
        ULTIMA_3f36(&D_5888, 1);
        return 0; // -> 0f5e
    case 0x8b:    // call guards
        // 0ff8
        TOWN_0958();
        return 0; // -> 0f5e
    case 0x8e:    // rune
        // 0ffe
        D_4af0 ^= 0x80;
        return 0; // -> 0f5e
    case 0xff:    // no selection
        // 1006
        TALK_04e2();
        return TALK_0b04(); // -> 1114
    case 0x8f:                // wait
        // 1010
        ULTIMA_266c_GetChar();
        return 0; // -> 0f5e
    case 0xfe:
    case 0x85: // gold-
    case 0x86: // change item 65
    case 0x8c: // if else name
        // 1016
        D_4aee = param_1;
        return 0;
    case 0x91: // label_0
    case 0x92: // label_1
    case 0x93:
    case 0x94:
    case 0x95:
    case 0x96:
    case 0x97:
    case 0x98:
    case 0x99:
    case 0x9a:
    case 0x9b: // label_10
    case 0x9c: // label?
    case 0x9d: // label?
    case 0x9e: // label?
    case 0x9f: // label?
        // 1020
        D_bcf4 = param_1;
        return TALK_0c5c(); // -> 1114
        // ----------
    default:
        // 10ce
        if (param_1 < 0x81)
        {
            TALK_0574(0xa0);

            pbVar5 = D_24ea[param_1 - 1];
            while (*pbVar5 != 0)
            {
                TALK_0574((byte)*pbVar5++ | 0x80);
            }

            if (*D_24ea[param_1 - 1] == 0)
            {
                TALK_0574(param_1);
                return 0; // -> 0f5e
            }

            D_4af5 = 1;
        }
        else
        {
            // 1062
            param_1 |= 0x80;
            if (param_1 == 0x8d) // 0x0d / 0x8d: newline
            {
                param_1 = 0x8a;
            }

            D_4af4 = param_1 &= D_4af0;

            if (D_4af5 != 0)
            {
                TALK_0574(0xa0);
            }

            TALK_0574(param_1);
            D_4af5 = 0;
        }
        break;
    }

    return 0;
}

// OK P1
int TALK_111c(void)
{
    ULTIMA_1850_PrintString("You see ");

    if (TALK_07aa(1) != 0)
    {
        return 1;
    }
    else
    {
        TALK_04d2();
        TALK_04d2();
        if (TALK_0d7a(D_bcdc) == 0)
        {
            ULTIMA_207e_srand(ULTIMA_2056_GetTime());
            if (ULTIMA_2092_RandomRange(0, 1) != 0)
            {
                ULTIMA_1850_PrintString("\"I am called ");
                if (TALK_07aa(0) == 0)
                {
                    TALK_04da();
                    TALK_04d2();
                    TALK_04d2();
                }
                else
                {
                    return 1;
                }
            }
        }
        else
        {
            TALK_04da();
            if (TALK_07aa(2) == 0)
            {
                TALK_04da();
                TALK_04d2();
                TALK_04d2();
            }
            else
            {
                return 1;
            }
        }

        return 0;
    }
}

// OK P1
void TALK_1180(void)
{
    int local_4;

    if (D_5958 == 0)
    {
        ULTIMA_1850_PrintString("\nSomething was stolen!\n");
        ULTIMA_43ae_AudioSweepTone(800, 2000, 1, 0x32);
        ULTIMA_207e_srand(ULTIMA_2056_GetTime());

        if ((D_57ac | D_57ad | D_57ae) != 0)
        {
            do
            {
                while (1)
                {
                    switch (ULTIMA_2092_RandomRange(0, 2))
                    {
                    case 0:
                        if (D_57ac != 0)
                        {
                            ULTIMA_3f36(&D_57ac, 1);
                            return;
                        }
                        break;

                    case 1:
                        if (D_57ad != 0)
                        {
                            ULTIMA_3f36(&D_57ad, 1);
                            return;
                        }
                        break;

                    case 2:
                        if (D_57ae != 0)
                        {
                            ULTIMA_3f36(&D_57ae, 1);
                            return;
                        }
                        break;
                    default:
                        return;
                    }
                }
            } while (D_57ad == 0);

            ULTIMA_3f36(&D_57ad, 1);
        }
        else
        {
            for (local_4 = 0x2f; local_4 >= 0; local_4--)
            {
                if (D_57c0[local_4] != 0)
                {
                    ULTIMA_3f36(&D_57c0[local_4], 1);
                    return;
                }
            }

            for (local_4 = 7; local_4 >= 0; local_4--)
            {
                if (D_5828[local_4] != 0)
                {
                    ULTIMA_3f36(&D_5828[local_4], 1);
                    return;
                }
            }

            for (local_4 = 7; local_4 >= 0; local_4--)
            {
                if (D_5820[local_4] != 0)
                {
                    ULTIMA_3f36(&D_5820[local_4], 1);
                    return;
                }
            }

            ULTIMA_3f54(&D_57aa, ULTIMA_2092_RandomRange(1, 0xf));
            ULTIMA_2900_UpdateVitalsDisplay();
        }
    }
}

// OK P1
void TALK_127e(int param_1)
{
    uint local_4;
    s16* local_6;
    s16 local_8;
    s16 local_a;
    s16 local_c;

    local_4 = (D_5893_map_id - 1) >> 3;
    ULTIMA_256e_ReadFileFromDisk(D_4aa0[local_4], D_b21e, 0x200, 0);

    // 12a9
    local_6 = (s16*)D_b21e;
    local_c = *local_6++;

    // 12ad
    for (local_a = 1; *local_6++ != param_1 && local_a <= local_c; local_6++, local_a++)
    {
    }

    // 12d6
    local_8 = *local_6;
    ULTIMA_256e_ReadFileFromDisk(D_4aa0[local_4], D_b21e, 0x400, local_8);

    if (TALK_111c() == 0)
    {
        if (TALK_0b04() == 0)
        {
            TALK_0a3c();
        }
    }

    TALK_1180();
}
