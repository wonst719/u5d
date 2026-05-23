#include "common/common.h"
#include "vars.h"
#include "funcs.h"

#include <string.h>

#include "dnglook.h"
#include "dungeon.h"
#include "sjog.h"

// CHECKED (code structure)
void DNGLOOK_0000_LookCmdInDungeon(void)
{
    int local_e;
    int local_c;
    int local_a;
    int local_8;
    byte local_6;
    int local_4;

    local_e = ULTIMA_4988();
    if (local_e + 1 == 0) // inc ax, jne?
    {
        return;
    }

    if (D_58a7 == 0 && D_58a6 == 0)
    {
        ULTIMA_1850_PrintString(/*0x752e*/ "You see:\ndarkness.\n");
        return;
    }

    if (SJOG_006c(D_6603) == 0)
    {
        return;
    }

    local_8 = D_5876;
    local_a = D_5878;

    local_c = D_595a[D_5895_map_level * 0x40 + (local_a & 7) * 8 + (local_8 & 7)];

    ULTIMA_1850_PrintString(/*0x7542*/ "You see:\n");

    if (local_c == 0x61)
    {
        local_c = 0;
    }

    // a30b
    if ((local_c & 0xf0) == 0x80)
    {
        switch (local_c)
        {
        case 0x80:
            ULTIMA_1850_PrintString(/*0x754c*/ "A sleep field.\n");
            break;
        case 0x81:
            ULTIMA_1850_PrintString(/*0x755c*/ "A poison gas field.\n");
            break;
        case 0x82:
            ULTIMA_1850_PrintString(/*0x7572*/ "A wall of fire.\n");
            break;
        case 0x83:
            ULTIMA_1850_PrintString(/*0x7584*/ "An electric field.\n");
            break;
        default:
            ULTIMA_1850_PrintString(/*0x7598*/ "An energy field.\n");
            // nop
            break;
        }

        return;
    }

    if ((local_c & 0xf0) == 0xc0)
    {
        local_4 = D_6604 & 0xf;
        if (local_4 == 1)
        {
            ULTIMA_1850_PrintString(/*0x75aa*/ "a dripping stalactite.\n");
        }
        else if (local_4 == 2)
        {
            ULTIMA_1850_PrintString(/*0x75c2*/ "a caved in passage.\n");
        }
        else
        {
            // a376
            if (ULTIMA_2092_RandomRange(1, 0xff) == 0xff)
            {
                ULTIMA_1850_PrintString(/*0x75d8*/ "an unfortunate software pirate.\n");
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x75fa*/ "a less fortunate adventurer.\n");
            }
        }

        return;
    }

    // a392
    switch (local_c & 0xf0)
    {
    case 0x00: // a3b8
        ULTIMA_1850_PrintString(/*0x7618*/ "a passage.\n");
        break;
    case 0x10: // a3d6
        ULTIMA_1850_PrintString(/*0x7624*/ "an up ladder.\n");
        break;
    case 0x20: // a3dc
        ULTIMA_1850_PrintString(/*0x7634*/ "a down ladder.\n");
        break;
    case 0x30: // a3e2
        ULTIMA_1850_PrintString(/*0x7644*/ "a ladder.\n");
        break;
    case 0x40:
        ULTIMA_1850_PrintString(/*0x7650*/ "a wooden chest.\n");
        break;
    case 0x50:
        ULTIMA_1850_PrintString(/*0x7662*/ "a fountain.\n");
        break;
    case 0x60:
        ULTIMA_1850_PrintString(/*0x7670*/ "a pit.\n");
        break;
    case 0x70: // a3fa
        ULTIMA_1850_PrintString(/*0x7678*/ "an open chest.\n");
        break;
    case 0x80:
        ULTIMA_1850_PrintString(/*0x7688*/ "an energy field.\n");
        break;
    case 0x90:
        ULTIMA_1850_PrintString(/*0x769a*/ "nothing of note.\n");
        break;
    case 0xa0:
        ULTIMA_1850_PrintString(/*0x76ac*/ "a heavy door.\n");
        break;
    case 0xb0:
        ULTIMA_1850_PrintString(/*0x76bc*/ "a wall.\n");
        break;
    case 0xc0:
        ULTIMA_1850_PrintString(/*0x76c6*/ "SPEC WALL ERR.\n");
        break;
    case 0xd0:
        ULTIMA_1850_PrintString(/*0x76d6*/ "a wall.\n");
        break;
    case 0xe0:
        ULTIMA_1850_PrintString(/*0x76e0*/ "a heavy door.\n");
        break;
    case 0xf0: // a42a
        ULTIMA_1850_PrintString(/*0x76f0*/ "a heavy door.\n");
        break;
    }

    // a3bf
    if ((local_c & 0xf0) == 0x50)
    {
        // a3cb
        ULTIMA_1850_PrintString(/*0x7700*/ "Will you drink?\n");
        // -> a480

        do
        {
            // a480
            local_6 = (byte)ULTIMA_266c_GetChar();
            if (local_6 == 'Y')
                break;
            if (local_6 == 'N')
                break;
        } while (1);

        // a48a
        if (local_6 == 'N')
        {
            ULTIMA_1850_PrintString(/*0x7712*/ "No.\n");
        }
        else
        {
            // a496~ (OK)
            ULTIMA_1850_PrintString(/*0x7718*/ "Yes.  Gulp!\n");

            switch (local_c)
            {
            case 0x50:
                ULTIMA_1850_PrintString(/*0x7726*/ "Cured!\n");
                D_55a8_party[local_e]._b = 0x47;
                break;

            case 0x51:
                ULTIMA_1850_PrintString(/*0x772e*/ "Healed!\n");
                D_55a8_party[local_e]._10 = D_55a8_party[local_e]._12;
                break;

            case 0x52:
                ULTIMA_1850_PrintString(/*0x7738*/ "Poisoned!\n");
                D_55a8_party[local_e]._b = 0x50;
                break;

            default:
                ULTIMA_1850_PrintString(/*0x7744*/ "Bad taste.\n");
                ULTIMA_2a52(local_e, ULTIMA_2092_RandomRange(0, 7));
                break;
            }
        }
    }
    // a50e
}

// OK P1
static void DNGLOOK_0284(int param_1, int param_2)
{
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b6 + 8);
    ULTIMA_0b10_GRAP_Line(param_1 + 1, param_2, param_1 + 6, param_2);
    ULTIMA_0b10_GRAP_Line(param_1 + 1, param_2 + 1, param_1 + 6, param_2 + 1);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13ae + 8);
    ULTIMA_0b10_GRAP_Line(param_1 + 1, param_2 + 2, param_1 + 6, param_2 + 2);
    ULTIMA_0b10_GRAP_Line(param_1 + 1, param_2 + 3, param_1 + 6, param_2 + 3);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color + 8);
    ULTIMA_0b10_GRAP_Line(param_1 + 1, param_2 + 4, param_1 + 6, param_2 + 4);
    ULTIMA_0b10_GRAP_Line(param_1 + 1, param_2 + 5, param_1 + 6, param_2 + 5);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b4 + 8);
    ULTIMA_0b10_GRAP_Line(param_1 + 1, param_2 + 6, param_1 + 6, param_2 + 6);
    ULTIMA_0b10_GRAP_Line(param_1 + 1, param_2 + 7, param_1 + 6, param_2 + 7);
}

// OK P1
static int DNGLOOK_0340(int param_1, int param_2)
{
    byte local_a;
    int local_4;
    int local_6;
    int local_8;

    local_8 = 0;
    if (param_1 < 0 || param_1 > 0x15 || param_2 < 0 || param_2 > 0x15)
    {
        return 0;
    }

    if (D_ad14[param_2 * 0x20 + param_1] != 0)
    {
        local_8 = 1;
        D_ad14[param_2 * 0x20 + param_1] = 0;

        local_4 = (param_1 + D_5896_map_x - 0xb) & 7;
        local_6 = (param_2 + D_5897_map_y - 0xb) & 7;
        local_a = D_595a[D_5895_map_level * 0x40 + local_6 * 8 + local_4];
        local_a >>= 4;

        ULTIMA_1bf2_SetTextPosition(param_1 + 1, param_2 + 1);

        // a66a
        param_1 = param_1 * 8 + 8;
        param_2 = param_2 * 8 + 8;
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);

        switch (local_a)
        {
        case 0:
            if ((D_595a[D_5895_map_level * 0x40 + local_6 * 8 + local_4] & 8) != 0)
            {
                ULTIMA_1cca_SetTextForegroundColor(D_13ba);
                ULTIMA_16ba_PrintChar(0x18);
            }
            break;

        case 1:
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1cca_SetTextForegroundColor(D_13ba);
            ULTIMA_16ba_PrintChar(0x2e);
            break;

        case 2:
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1cca_SetTextForegroundColor(D_13ba);
            ULTIMA_16ba_PrintChar(0x2d);
            break;

        case 3:
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1cca_SetTextForegroundColor(D_13ba);
            ULTIMA_16ba_PrintChar(0x2f);
            break;

        case 4:
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1cca_SetTextForegroundColor(D_13b8);
            ULTIMA_16ba_PrintChar(0x70);
            break;

        case 5:
            ULTIMA_0b10_GRAP_Line(param_1 + 9 - 8, param_2 + 0xc - 8, param_1 + 0xe - 8, param_2 + 0xc - 8);
            ULTIMA_0b10_GRAP_Line(param_1 + 10 - 8, param_2 + 0xd - 8, param_1 + 0xd - 8, param_2 + 0xd - 8);
            ULTIMA_0b10_GRAP_Line(param_1 + 9 - 8, param_2 + 0xe - 8, param_1 + 10 - 8, param_2 + 0xe - 8);
            ULTIMA_0b10_GRAP_Line(param_1 + 0xd - 8, param_2 + 0xe - 8, param_1 + 0xe - 8, param_2 + 0xe - 8);
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color + 8);
            ULTIMA_0c64_GRAP_30_Pset(param_1 + 9 - 8, param_2 + 10 - 8);
            ULTIMA_0c64_GRAP_30_Pset(param_1 + 10 - 8, param_2 + 9 - 8);
            ULTIMA_0b10_GRAP_Line(param_1 + 0xb - 8, param_2 + 10 - 8, param_1 + 0xc - 8, param_2 + 10 - 8);
            ULTIMA_0b10_GRAP_Line(param_1 + 0xb - 8, param_2 + 0xb - 8, param_1 + 0xc - 8, param_2 + 0xb - 8);
            ULTIMA_0c64_GRAP_30_Pset(param_1 + 0xd - 8, param_2 + 9 - 8);
            ULTIMA_0c64_GRAP_30_Pset(param_1 + 0xe - 8, param_2 + 10 - 8);
            break;

        case 6:
            // a7e4
            ULTIMA_1cca_SetTextForegroundColor(D_13ba);
            
            switch (D_595a[(uint)D_5895_map_level * 0x40 + local_6 * 8 + local_4])
            {
            case 96:
                ULTIMA_16ba_PrintChar(0x19);
                break;
            case 97:
            case 105:
                ULTIMA_1c9e_SelectCharset(1);
                ULTIMA_16ba_PrintChar(0x71);
                break;
            case 104:
                ULTIMA_16ba_PrintChar(0x12);
                break;
            default:
                ULTIMA_1c9e_SelectCharset(1);
                ULTIMA_1cca_SetTextForegroundColor(D_13ae + 8);
                ULTIMA_16ba_PrintChar(0x72);
                break;
            }

            break;

        case 8:
            DNGLOOK_0284(param_1, param_2);
            break;

        case 10:
        case 0xf:
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1cca_SetTextForegroundColor(D_13b8);
            ULTIMA_16ba_PrintChar(0x73);
            break;

        case 0xb:
            if (D_595a[(uint)D_5895_map_level * 0x40 + local_6 * 8 + local_4] == 0xb0)
            {
                ULTIMA_16ba_PrintChar(0x7f);
            }
            else
            {
                ULTIMA_1c9e_SelectCharset(1);
                ULTIMA_16ba_PrintChar(0x74);
            }
            local_8 = 0;
            break;

        case 0xc:
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1f26_SetTextBackgroundColor(D_13b2_frame_color);
            ULTIMA_16ba_PrintChar(0x75);
            ULTIMA_1f26_SetTextBackgroundColor(0);
            local_8 = 0;
            break;

        case 0xd:
            ULTIMA_1c9e_SelectCharset(1);
            if (D_52c8 == 0)
            {
                ULTIMA_1f26_SetTextBackgroundColor(D_13b2_frame_color);
            }
            else if (D_52c8 == 1 || D_52c8 == 2)
            {
                ULTIMA_1f26_SetTextBackgroundColor(D_13ba);
            }

            ULTIMA_16ba_PrintChar(0x76);
            ULTIMA_1f26_SetTextBackgroundColor(0);
            local_8 = 0;
            break;

        case 0xe:
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1cca_SetTextForegroundColor(D_13b8);
            ULTIMA_16ba_PrintChar(0x77);
            break;
        }
    }

    ULTIMA_1cca_SetTextForegroundColor(D_13b0_white_color);
    ULTIMA_1c9e_SelectCharset(0);

    return local_8;
}

// OK P1
void DNGLOOK_06a8_ViewCmd(void)
{
    byte* local_10;
    byte* local_c;
    byte* local_6;
    byte* local_4;
    byte* local_8;
    int local_a;
    int local_e;
    int local_12;
    int local_14;
    int local_16;

    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);

    local_4 = local_c = D_a528;
    local_6 = local_10 = D_a628;
    local_8 = &D_a528[0xff];

    memset(D_ad14, 0xff, 0x2e0);

    *local_4 = 0xb;
    local_4++;
    *local_6 = 0xb;
    local_6++;
    local_12 = 0x60;
    local_14 = 0x60;
    D_ad14[0x16b] = 0;

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(0xc, 0xc);
    ULTIMA_1c9e_SelectCharset(1);
    ULTIMA_1cca_SetTextForegroundColor(D_13b4 + 8);
    if (D_52c8 == 3)
    {
        ULTIMA_1cca_SetTextForegroundColor(D_13b0_white_color);
    }

    // a9ce
    ULTIMA_16ba_PrintChar(0x60);
    ULTIMA_1cca_SetTextForegroundColor(D_13b0_white_color);
    ULTIMA_1c9e_SelectCharset(0);
    // -> aa66

    while (local_4 != local_c) // aa66
    {
        for (local_16 = 0; local_16 < 8; local_16++) // aa3f
        {
            local_a = local_12 = *local_c;
            local_e = local_14 = *local_10;

            // ok
            switch (local_16)
            {
            case 0:
                local_12--;
                local_14--;
                break;

            case 1:
                local_14--;
                break;

            case 2:
                local_12++;
                local_14--;
                break;

            case 3:
                local_12--;
                break;

            case 4:
                local_12++;
                break;

            case 5:
                local_12--;
                local_14++;
                break;

            case 6:
                local_14++;
                break;

            case 7:
                local_12++;
                local_14++;
                break;
            }

            // aa3f ok
            if (DNGLOOK_0340(local_12, local_14) != 0)
            {
                *local_4++ = local_12;
                *local_6++ = local_14;

                if (local_4 > local_8)
                {
                    local_4 = D_a528;
                    local_6 = D_a628;
                }
            }
        }

        local_c++;
        local_10++;
        if (local_c > local_8)
        {
            local_c = D_a528;
            local_10 = D_a628;
        }
    }

    // aaaa ok
    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_1dda_WaitForKeystroke(0);
    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);
    DUNGEON_1be0();
}

// CHECKED (nop)
void DNGLOOK_0844(int param_1)
{
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    for (local_6 = 0; local_6 < D_3840; local_6++)
    {
        if (D_383a[local_6] == (D_5893_map_id & 0xf) * 0x10 + param_1)
        {
            return; // nop NOT MATCHING
        }
    }

    local_4 = D_5893_map_id - 0x21;
    if (local_4 >= 1)
    {
        local_4--;
    }

    local_a = param_1 + local_4 * 0x10;
    local_8 = local_a / 8;
    D_58e0[local_8] |= 1 << ((byte)local_a & 7);
}

// OK P1
static int DNGLOOK_08d4(int param_1)
{
    int local_6;
    int local_c;
    int local_a;
    u8 local_8;
    u8 local_4;

    local_6 = (int)D_5893_map_id - 0x21;
    if (local_6 >= 1) {
        local_6--;
    }

    // 08ed
    local_c = local_6 * 0x10 + param_1;
    local_a = local_c / 8;
    local_4 = D_58e0[local_a];
    local_8 = 1 << (local_c & 7);

    if (local_8 & local_4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// OK P1
void DNGLOOK_093a(void)
{
    byte local_4;
    byte local_c;
    int local_8;
    int local_6;
    byte* local_a;

    local_a = D_595a;

    for (local_6 = 0; local_6 < 0x200; local_6++)
    {
        local_c = *local_a;
        local_4 = local_c & 0xf0;
        if (local_4 == 0xf0)
        {
            local_8 = local_c & 0xf;
            if (DNGLOOK_08d4(local_8) != 0)
            {
                *local_a &= 0xaf;
            }
        }
        local_a++;
    }
}

// OK P1
static void DNGLOOK_097e(byte param_1, int param_2)
{
    int local_6;
    int local_4;
    int local_8;
    int local_c;
    int local_a;

    local_a = 0;
    local_c = 0;
    local_4 = 0;
    local_6 = 0;

    switch (param_2)
    {
    case 0:
        local_a++;
        break;

    case 1:
        local_c = 1;
        local_4 = 10;
        break;

    case 2:
        local_a = 1;
        local_6 = 10;
        break;

    case 3:
        local_c = 1;
        break;
    }

    for (local_8 = 0; local_8 < 0xb; local_8++)
    {
        D_ad14[local_6 * 0x20 + local_4] = 0xff;
        local_4 += local_a;
        local_6 += local_c;
    }

    if (param_2 == 0 && param_1 == 0xe0)
    {
        D_ad14[0x45] = D_ad14[0x105] = D_bb14;
    }

    if (param_2 == 3 && param_1 == 0xe0)
    {
        D_ad14[0xa2] = D_ad14[0xa8] = D_bb14;
    }
}

// OK P1
static void DNGLOOK_0a48(int param_1)
{
    int local_8;
    int local_c;
    int local_a;
    int local_6;
    int local_4;

    local_a = 0;
    local_c = 0;
    local_4 = 3;
    local_6 = 3;

    switch (param_1)
    {
    case 0:
        local_a++;
        local_6 = 1;
        break;

    case 1:
        local_c++;
        local_4 = 9;
        break;

    case 2:
        local_a++;
        local_6 = 9;
        break;

    case 3:
        local_c++;
        local_4 = 1;
        break;
    }

    for (local_8 = 0; local_8 < 5; local_8++)
    {
        D_ad14[local_6 * 0x20 + local_4] = D_bb15;
        local_4 += local_a;
        local_6 += local_c;
    }
}

// OK P1
static void DNGLOOK_0aee(int param_1)
{
    int local_6;
    int local_4;
    int local_8;
    int local_c;
    int local_a;

    local_a = 0;
    local_c = 0;

    switch (param_1)
    {
    case 0:
        local_a++;
        local_4 = 2;
        local_6 = 1;
        break;

    case 1:
        local_c++;
        local_4 = 9;
        local_6 = 2;
        break;

    case 2:
        local_a++;
        local_4 = 2;
        local_6 = 9;
        break;

    case 3:
        local_c++;
        local_4 = 1;
        local_6 = 2;
        break;
    }

    for (local_8 = 0; local_8 < 7; local_8++)
    {
        D_ad14[local_6 * 0x20 + local_4] = D_bb15;
        local_4 += local_a;
        local_6 += local_c;
    }
}

// CHECKED (nop)
static void DNGLOOK_0b9e(int param_1)
{
    byte local_8;
    int local_6;
    int local_4;

    local_4 = D_5896_map_x;
    local_6 = D_5897_map_y;
    switch (param_1)
    {
    case 0:
        local_6--;
        break;

    case 1:
        local_4++;
        break;

    case 2:
        local_6++;
        break;

    case 3:
        local_4--;
        break;
    }

    local_8 = D_595a[D_5895_map_level * 0x40 + (local_6 & 7) * 8 + (local_4 & 7)];
    local_8 &= 0xf0;
    if (local_8 < 0xa0)
    {
        DNGLOOK_0aee(param_1);
    }

    if (local_8 == 0xb0 || local_8 == 0xc0 || local_8 == 0xd0)
    {
        DNGLOOK_097e(D_595a[D_5895_map_level * 0x40 + D_5897_map_y * 8 + D_5896_map_x] & 0xf0, param_1);
        // nop
    }
    else
    {
        DNGLOOK_0a48(param_1);
    }
}

// CHECKED (loop)
void DNGLOOK_0c6c(void)
{
    byte local_8;
    byte local_c;
    int local_6;

    byte* local_4;

    byte* t;

    local_4 = &D_ad14[0x20];
    memset(local_4, D_bb14, 0xb);

    local_4 = &D_ad14[0x120];
    memset(local_4, D_bb14, 0xb);

    // af2e; NOT MATCHING
    for (local_6 = 0; local_6 < 0xb; local_6++)
    {
        D_ad14[local_6 * 0x20 + 1] = D_ad14[local_6 * 0x20 + 9] = D_bb14;
    }

    D_ad14[0] = D_ad14[0xa] = D_ad14[0x140] = D_ad14[0x14a] = 0xff;

    local_8 = D_595a[D_5895_map_level * 0x40 + D_5897_map_y * 8 + D_5896_map_x];
    local_8 &= 0xf0;
    if (local_8 != 0 && local_8 < 0x80)
    {
        local_8 >>= 4;
        local_c = D_244a[local_8];
        if (local_c != 0)
        {
            D_ad14[0xa5] = local_c;
        }

        if (local_8 == 3)
        {
            D_bb16 = 1;
            ULTIMA_6fbc(0);
        }
        else
        {
            D_bb16 = 0;
        }
    }

    for (local_6 = 0; local_6 < 4; local_6++)
    {
        DNGLOOK_0b9e(local_6);
    }
}

// CHECKED (optimization)
void DNGLOOK_0d3e(void)
{
    int local_32;
    int local_30;
    int local_2e[16];
    byte* local_34;
    byte* local_e;
    byte* local_c;
    byte* local_a;
    byte* local_8;
    byte* local_6;
    int local_4;

    for (local_30 = 0; local_30 < 0xb; local_30++)
    {
        memset(&D_ad14[local_30 * 0x20], D_bb15, 0xb);
    }

    if ((D_58a1 & 4) != 0)
    {
        D_ad14[0xa5] = 0xb3;
    }

    // b006
    DNGLOOK_0c6c();

    for (local_30 = 0; local_30 < 8; local_30++)
    {
        D_ad14[local_30 + 0x10b] = D_ad14[local_30 + 0x113] = 0xff;
    }

    local_34 = D_ad14 + 0x6b;
    local_a = D_ad14 + 0x4b;
    local_6 = D_ad14 + 0x8b;
    local_e = D_ad14 + 0x2b;

    for (local_30 = 0; local_30 < 6; local_30++)
    {
        if ((D_58a1 & 4) != 0)
        {
            *local_34 = *local_a = *local_6 = *local_e = D_2452[local_30];
            // nop
        }
        else
        {
            *local_34 = D_2470[local_30];
            *local_a = D_246a[local_30];
            *local_6 = D_245e[local_30];
            *local_e = D_2464[local_30];
        }
        local_34++;
        local_a++;
        local_6++;
        local_e++;
    }

    // OK
    for (local_30 = 0; local_30 < 6; local_30++)
    {
        if ((D_58a1 & 4) != 0)
        {
            *local_34 = *local_a = *local_6 = *local_e = D_2458[local_30];
        }
        else
        {
            *local_34 = D_2464[local_30];
            *local_a = D_245e[local_30];
            *local_6 = D_246a[local_30];
            *local_e = D_2470[local_30];
        }
        local_34++;
        local_a++;
        local_6++;
        local_e++;
    }

    // b0e3
    local_8 = D_ad14 + 0xcb;
    local_c = D_ad14 + 0xeb;

    // OK
    for (local_30 = 0; local_30 < 0x10; local_30++)
    {
        // b0f8
        if ((D_58a1 & 4) != 0)
        {
            *local_c = D_24c6[local_30];
            *local_8 = D_24b6[local_30];
        }
        else
        {
            // b10e
            switch (D_6603)
            {
            case 0:
                *local_8 = D_2476[local_30];
                *local_c = D_2496[local_30];
                break;
            case 1:
                *local_8 = D_2486[local_30];
                *local_c = D_24a6[local_30];
                break;
            case 2:
                *local_8 = D_24a6[local_30];
                *local_c = D_2486[local_30];
                break;
            case 3:
                *local_8 = D_2496[local_30];
                *local_c = D_2476[local_30];
                break;
            }
        }

        local_8++;
        local_c++;
    }

    for (local_30 = 0; local_30 < 0x10; local_30++)
    {
        local_2e[local_30] = local_30;
    }

    // b18d NOT MATCHING
    for (local_30 = 0; local_30 < 0x10; local_30++)
    {
        local_32 = ULTIMA_2092_RandomRange(0, 0xf);

        local_4 = local_2e[local_30];
        local_2e[local_30] = local_2e[local_32];
        local_2e[local_32] = local_4;

        D_ad14[local_30 + 0xab] = 0;
    }

    // b1cf OK
    if ((D_58a1 & 4) != 0)
    {
        local_32 = D_173c[ULTIMA_2092_RandomRange(0, 7)];
    }
    else
    {
        local_32 = D_5c5a[1]._5;
    }

    local_4 = ULTIMA_2092_RandomRange(1, D_13bc[local_32]._6);
    if (D_13bc[local_32]._6 == 8 || D_13bc[local_32]._6 == 0x10)
    {
        local_4 = D_13bc[local_32]._6;
    }

    // b223 NOT MATCHING
    for (local_30 = 0; local_30 < local_4; local_30++)
    {
        D_ad14[local_2e[local_30] + 0xab] = local_32 * 4 + 64;
    }
}

// OK P1
void DNGLOOK_0fda(void)
{
    switch (D_58a0)
    {
    case 3:
        D_5897_map_y--;
        D_6602 = D_6603 = 0;
        if (7 < D_5897_map_y)
        {
            D_5897_map_y = 7;
        }
        break;

    case 2:
        D_5896_map_x++;
        D_6602 = D_6603 = 1;
        if (7 < D_5896_map_x)
        {
            D_5896_map_x = 0;
        }
        break;

    case 4:
        D_5897_map_y++;
        D_6602 = D_6603 = 2;
        if (7 < D_5897_map_y)
        {
            D_5897_map_y = 0;
        }
        break;

    case 1:
        D_5896_map_x--;
        D_6602 = D_6603 = 3;
        if (7 < D_5896_map_x)
        {
            D_5896_map_x = 7;
        }
        break;

    case 5:
        if (D_5895_map_level == 0)
        {
            DUNGEON_1d08_Exit();
            D_5893_map_id = 0;
        }
        else
        {
            D_5895_map_level--;
            D_6602 = 4;
        }
        break;

    case 6:
        if (D_5895_map_level == 7)
        {
            DUNGEON_1d08_Exit();
            D_5893_map_id = 0;
        }
        else
        {
            D_5895_map_level++;
            D_6602 = 5;
        }
        break;
    }
}

// OK P1
void DNGLOOK_109e(int param_1)
{
    if (D_5893_map_id != 0)
    {
        if ((D_bb17 & 2) != 0)
        {
            ULTIMA_102e_UnloadTileset();
        }

        if ((D_bb17 & 1) == 0)
        {
            do
            {
                D_a9c0 = ULTIMA_0bae_LoadImageFile(D_25ea[4 + D_6604]); // DNGn.16
            } while (D_a9c0 == 0);

            do
            {
                D_a9c4 = ULTIMA_0bae_LoadImageFile(D_25ea[4]); // ITEMS.16
            } while (D_a9c4 == 0);
        }

        D_bb17 = 1;
        if (param_1 != 0)
        {
            D_5c5a[1]._0_tile = D_5c5a[1]._1 = 0;
            D_5c5a[1]._5 = D_5c5a[1]._2_x = D_5c5a[1]._3_y = 0xff;
        }

        ULTIMA_0a70_GRAP_2d_SetPenColor(0);
        ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);
        ULTIMA_0c22_GRAP_0f_SelectPage(1);
        ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);
        ULTIMA_0c22_GRAP_0f_SelectPage(0);
    }
}

// OK P1
void DNGLOOK_1130(void)
{
    if ((D_bb17 & 1) != 0)
    {
        if (D_5c5a[1]._5 != 0xff)
        {
            ULTIMA_0be4_FreeImage(D_a9c6);
        }
        D_a9c6 = 0;
        ULTIMA_0be4_FreeImage(D_a9c4);
        ULTIMA_0be4_FreeImage(D_a9c0);
    }

    if ((D_bb17 & 2) == 0)
    {
        while (ULTIMA_0ff4_LoadTileset(*D_25f0) == 0) // TILES.16
            ;
    }

    if ((D_bb17 & 4) == 0)
    {
        ULTIMA_6f9e(0);
    }

    D_bb17 = 6;
}

// CHECKED (optimization)
// prepare combat (in dungeon)
void DNGLOOK_117e(int param_1, int param_2)
{
    byte local_a;
    int local_16;
    int local_12;
    int local_14;
    uint local_10;
    int local_e;
    int local_c;
    byte local_8[4];
    int local_4;

    local_c = 0xb;
    local_e = 0x11;
    local_4 = 4;
    if (param_1 != 1)
    {
        // b42e
        switch (D_6603)
        {
        case 0:
        case 5:
            // b44c
            local_4 = 3;
            break;
        case 1:
            // b4c2
            local_4 = 2;
            break;
        case 3:
            // b4ca
            local_4 = 1;
            break;
        }

        // b451
        ULTIMA_6936();

        // NOT MATCHING
        for (local_10 = 0; local_10 < D_585b; local_10++)
        {
            D_ba14[local_10]._6 = D_5c5a[local_10]._2_x = D_ad14[local_4 * 0x20 + local_10 + local_c];
            D_ba14[local_10]._7 = D_5c5a[local_10]._3_y = D_ad14[local_4 * 0x20 + local_10 + local_e];
        }
    }

    // b4d8
    if (param_2 > 0 && ((param_1 > 0xef && param_2 == 3) || param_2 < 3))
    {
        local_4 = local_e = local_c = 0xb;

        for (local_10 = 0; local_10 < 4; local_10++)
        {
            local_8[local_10] = D_385e[ULTIMA_2092_RandomRange(0, 7)];
        }

        // b521
        for (local_10 = 0; local_10 < 0x10; local_10++)
        {
            local_a = D_ad14[local_4 + 0xa0];
            if (local_a != 0)
            { 
                // b542 (NOT MATCHING: nop)
                if (local_a < 0x40 || (local_a & 0xfc) == 0xb4 || (local_a & 0xfc) == 0xe8)
                {
                    local_14 = 2;
                    local_16 = local_a;
                    // nop
                }
                else
                {
                    local_14 = 0;
                    local_16 = (local_a - 0x40) / 4;
                }

                // b575
                if ((local_a & 0xfc) == 0xec)
                {
                    local_16 = local_8[local_a & 3];
                }

                // b58e
                local_12 = ULTIMA_6506(local_16, local_14, D_ad14[local_c + 0xc0], D_ad14[local_e + 0xe0], D_5895_map_level);
                if (local_14 == 2)
                {
                    if (local_16 == 1)
                    {
                        D_5c5a[local_12]._5 = D_5895_map_level * 3 + 7;
                        // nop
                    }
                    else if (local_16 == 2)
                    {
                        D_5c5a[local_12]._5 = ULTIMA_2092_RandomRange(1, D_5895_map_level * 10 + 10);
                    }
                    else if (local_16 < 0x10)
                    {
                        ASSERT(local_16 != 0);
                        // TODO: offset
                        D_5c5a[local_12]._5 = D_3850[local_16 - 3] + ULTIMA_2092_RandomRange(0, D_3842[local_16 - 3] - 1);
                    }
                }
            }

            local_4++;
            local_c++;
            local_e++;
        }
    }
}
