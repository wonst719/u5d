#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <string.h>

void DUNGEON_1d08(void);
void DUNGEON_1be0(void);
int SJOG_006c(int param_1);

// NOT MATCHING
void DNGLOOK_0000_LookCmdInDungeon(void)
{
    byte bVar1;
    char cVar3;
    int iVar4;

    iVar4 = ULTIMA_4988();
    if (iVar4 == -1)
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

    bVar1 = D_595a[D_5895_map_level * 0x40 + (D_5878 & 7) * 8 + (D_5876 & 7)];

    ULTIMA_1850_PrintString(/*0x7542*/ "You see:\n");

    if (bVar1 == 0x61)
    {
        bVar1 = 0;
    }

    if ((bVar1 & 0xf0) == 0x80)
    {
        switch (bVar1)
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
            break;
        }

        return;
    }

    if ((bVar1 & 0xf0) == 0xc0)
    {
        if ((D_6604 & 0xf) == 1)
        {
            ULTIMA_1850_PrintString(/*0x75aa*/ "a dripping stalactite.\n");
        }
        else if ((D_6604 & 0xf) == 2)
        {
            ULTIMA_1850_PrintString(/*0x75c2*/ "a caved in passage.\n");
        }
        else
        {
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

    switch (bVar1 & 0xf0)
    {
    case 0x00:
        ULTIMA_1850_PrintString(/*0x7618*/ "a passage.\n");
        break;
    case 0x10:
        ULTIMA_1850_PrintString(/*0x7624*/ "an up ladder.\n");
        break;
    case 0x20:
        ULTIMA_1850_PrintString(/*0x7634*/ "a down ladder.\n");
        break;
    case 0x30:
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
    case 0x70:
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
    case 0xf0:
        ULTIMA_1850_PrintString(/*0x76f0*/ "a heavy door.\n");
        break;
    }

    if ((bVar1 & 0xf0) == 0x50)
    {
        ULTIMA_1850_PrintString(/*0x7700*/ "Will you drink?\n");

        do
        {
            cVar3 = (char)ULTIMA_266c_GetChar();
            if (cVar3 == 'Y')
                break;
        } while (cVar3 != 'N');

        if (cVar3 == 'N')
        {
            ULTIMA_1850_PrintString(/*0x7712*/ "No.\n");
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x7718*/ "Yes.  Gulp!\n");

            switch (bVar1)
            {
            case 0x50:
                ULTIMA_1850_PrintString(/*0x7726*/ "Cured!\n");
                D_55a8_party[iVar4]._b = 0x47;
                break;

            case 0x51:
                ULTIMA_1850_PrintString(/*0x772e*/ "Healed!\n");
                D_55a8_party[iVar4]._10 = D_55a8_party[iVar4]._12;
                break;

            case 0x52:
                ULTIMA_1850_PrintString(/*0x7738*/ "Poisoned!\n");
                D_55a8_party[iVar4]._b = 0x50;
                break;

            default:
                ULTIMA_1850_PrintString(/*0x7744*/ "Bad taste.\n");
                ULTIMA_2a52(iVar4, ULTIMA_2092_RandomRange(0, 7));
                break;
            }
        }
    }
}

// NOT MATCHING
void DNGLOOK_0284(int param_1, int param_2)
{
    int iVar1;

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b6 + 8);
    iVar1 = param_1 + 6;
    param_1 = param_1 + 1;
    ULTIMA_0b10_GRAP_Line(param_1, param_2, iVar1, param_2);
    ULTIMA_0b10_GRAP_Line(param_1, param_2 + 1, iVar1, param_2 + 1);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13ae + 8);
    ULTIMA_0b10_GRAP_Line(param_1, param_2 + 2, iVar1, param_2 + 2);
    ULTIMA_0b10_GRAP_Line(param_1, param_2 + 3, iVar1, param_2 + 3);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color + 8);
    ULTIMA_0b10_GRAP_Line(param_1, param_2 + 4, iVar1, param_2 + 4);
    ULTIMA_0b10_GRAP_Line(param_1, param_2 + 5, iVar1, param_2 + 5);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b4 + 8);
    ULTIMA_0b10_GRAP_Line(param_1, param_2 + 6, iVar1, param_2 + 6);
    ULTIMA_0b10_GRAP_Line(param_1, param_2 + 7, iVar1, param_2 + 7);
}

// NOT MATCHING
int DNGLOOK_0340(int param_1, int param_2)
{
    byte bVar1;
    uint uVar3;
    uint uVar4;
    int iVar5;
    int iVar6;
    int iVar7;
    undefined2 uVar8;
    int iVar10;
    int iVar11;
    undefined2 local_8;

    local_8 = 0;
    if (param_1 < 0 || 0x15 < param_1 || param_2 < 0 || 0x15 < param_2)
    {
        return 0;
    }

    if (D_ad14[param_2 * 0x20 + param_1] != 0)
    {
        local_8 = 1;
        D_ad14[param_2 * 0x20 + param_1] = 0;

        uVar3 = (param_1 + (uint)D_5896_map_x - 0xb) & 7;
        uVar4 = (param_2 + (uint)D_5897_map_y - 0xb) & 7;
        bVar1 = D_595a[(uint)D_5895_map_level * 0x40 + uVar4 * 8 + uVar3];

        ULTIMA_1bf2_SetTextPosition(param_1 + 1, param_2 + 1);

        param_1 *= 8;
        param_2 *= 8;
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);

        switch (bVar1 >> 4)
        {
        case 0:
            if ((D_595a[(uint)D_5895_map_level * 0x40 + uVar4 * 8 + uVar3] & 8) == 0)
                break;

            ULTIMA_1cca_SetTextForegroundColor(D_13ba);
            ULTIMA_16ba_PrintChar(0x18);
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
            iVar10 = param_1 + 0xe;
            iVar11 = param_1 + 9;
            ULTIMA_0b10_GRAP_Line(iVar11, param_2 + 0xc, iVar10, param_2 + 0xc);
            iVar5 = param_1 + 0xd;
            iVar6 = param_1 + 10;
            ULTIMA_0b10_GRAP_Line(iVar6, param_2 + 0xd, iVar5, param_2 + 0xd);
            iVar7 = param_2 + 0xe;
            ULTIMA_0b10_GRAP_Line(iVar11, iVar7, iVar6, iVar7);
            ULTIMA_0b10_GRAP_Line(iVar5, iVar7, iVar10, iVar7);
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color + 8);
            iVar7 = param_2 + 10;
            ULTIMA_0c64_GRAP_30_Pset(iVar11, iVar7);
            ULTIMA_0c64_GRAP_30_Pset(iVar6, param_2 + 9);
            ULTIMA_0b10_GRAP_Line(param_1 + 0xb, iVar7, param_1 + 0xc, iVar7);
            ULTIMA_0b10_GRAP_Line(param_1 + 0xb, param_2 + 0xb, param_1 + 0xc, param_2 + 0xb);
            ULTIMA_0c64_GRAP_30_Pset(iVar5, param_2 + 9);
            ULTIMA_0c64_GRAP_30_Pset(iVar10, iVar7);
            break;

        case 6:
            ULTIMA_1cca_SetTextForegroundColor(D_13ba);
            
            switch (D_595a[(uint)D_5895_map_level * 0x40 + uVar4 * 8 + uVar3])
            {
            case 96:
                ULTIMA_16ba_PrintChar(0x19);
                break;
            case 97:
                ULTIMA_1c9e_SelectCharset(1);
                ULTIMA_16ba_PrintChar(0x71);
                break;
            case 104:
                ULTIMA_16ba_PrintChar(0x12);
                break;
            case 105:
                ULTIMA_1c9e_SelectCharset(1);
                ULTIMA_16ba_PrintChar(0x71);
                break;
            default:
                ULTIMA_1c9e_SelectCharset(1);
                ULTIMA_1cca_SetTextForegroundColor(D_13ae + 8);
                ULTIMA_16ba_PrintChar(0x72);
                break;
            }

            break;

        case 8:
            DNGLOOK_0284(param_1 + 8, param_2 + 8);
            break;

        case 10:
        case 0xf:
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1cca_SetTextForegroundColor(D_13b8);
            ULTIMA_16ba_PrintChar(0x73);
            break;

        case 0xb:
            if (D_595a[(uint)D_5895_map_level * 0x40 + uVar4 * 8 + uVar3] == 0xb0)
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
                uVar8 = D_13b2_frame_color;
                ULTIMA_1f26_SetTextBackgroundColor(uVar8);
            }
            else if (D_52c8 == 1 || D_52c8 == 2)
            {
                uVar8 = D_13ba;
                ULTIMA_1f26_SetTextBackgroundColor(uVar8);
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

// NOT MATCHING
void DNGLOOK_06a8_ViewCmd(void)
{
    uint uVar2;
    uint uVar3;
    int iVar4;
    uint uVar5;
    uint uVar7;
    int local_16;
    byte* local_10;
    byte* local_c;
    byte* local_6;
    byte* local_4;

    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);

    local_c = D_a528;
    local_10 = D_a628;

    for (iVar4 = 0; iVar4 < 0x2e0; iVar4++)
    {
        D_ad14[iVar4] = 0xff;
    }

    D_a528[0] = 0xb;
    local_4 = D_a528 + 1;
    D_a628[0] = 0xb;
    local_6 = D_a628 + 1;
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
    ULTIMA_16ba_PrintChar(0x60);
    ULTIMA_1cca_SetTextForegroundColor(D_13b0_white_color);
    ULTIMA_1c9e_SelectCharset(0);

    do
    {
        if (local_4 == local_c)
        {
            break;
        }

        uVar2 = (uint)*local_10;
        uVar3 = (uint)*local_c;

        for (local_16 = 0; local_16 < 8; local_16++)
        {
            uVar5 = uVar2;
            uVar7 = uVar3;
            switch (local_16)
            {
            case 0:
                uVar7 = uVar3 - 1;
                uVar5 = uVar2 - 1;
                break;

            case 1:
                uVar5 = uVar2 - 1;
                break;

            case 2:
                uVar7 = uVar3 + 1;
                uVar5 = uVar2 - 1;
                break;

            case 3:
                uVar7 = uVar3 - 1;
                break;

            case 4:
                uVar7 = uVar3 + 1;
                break;

            case 5:
                uVar7 = uVar3 - 1;
                uVar5 = uVar2 + 1;
                break;

            case 6:
                uVar5 = uVar2 + 1;
                break;

            case 7:
                uVar7 = uVar3 + 1;
                uVar5 = uVar2 + 1;
                break;
            }

            if (DNGLOOK_0340(uVar7, uVar5) != 0)
            {
                *local_4++ = (byte)uVar7;
                *local_6++ = (byte)uVar5;

                if (local_4 > (D_a528 + 0xff))
                {
                    local_4 = D_a528;
                    local_6 = D_a628;
                }
            }
        }

        local_c++;
        local_10++;
        if (local_c > (D_a528 + 0xff))
        {
            local_c = D_a528;
            local_10 = D_a628;
        }
    } while (1);

    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_1dda_WaitForKeystroke(0);
    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);
    DUNGEON_1be0();
}

// NOT MATCHING
void DNGLOOK_0844(int param_1)
{
    int iVar3;
    int local_4;

    for (iVar3 = 0; iVar3 < D_3840; iVar3++)
    {
        if (D_383a[iVar3] == (D_5893_map_id & 0xf) * 0x10 + param_1)
        {
            return;
        }
    }

    local_4 = D_5893_map_id - 0x21;
    if (0 < local_4)
    {
        local_4 = D_5893_map_id - 0x22;
    }

    param_1 += local_4 * 0x10;
    D_58e0[param_1 / 8] |= 1 << ((byte)param_1 & 7);
}

// NOT MATCHING: TEST
uint DNGLOOK_08d4(int param_1)
{
    uint local_6;
    uint local_c;
    uint local_a;
    u8 local_8;
    u8 local_4;

    local_6 = (int)D_5893_map_id - 0x21;
    if (1 <= local_6) {
        local_6--;
    }

    // 08ed
    local_c = local_6 * 0x10 + param_1;
    local_a = param_1 / 8;
    local_4 = D_58e0[local_a];
    local_8 = 1 << (local_c & 7);

    return (local_8 & local_4) != 0;
}

// NOT MATCHING
void DNGLOOK_093a(void)
{
    byte* ptr = D_595a;
    int size = 0x200;

    do
    {
        if ((*ptr & 0xf0) == 0xf0)
        {
            int iVar1 = DNGLOOK_08d4(*ptr & 0xf);
            if (iVar1 != 0)
            {
                *ptr &= 0xaf;
            }
        }
        ptr++;
        size--;
    } while (size != 0);
    return;
}

// NOT MATCHING
void DNGLOOK_097e(byte param_1, int param_2)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int local_c;
    int local_8;

    local_8 = 0;
    local_c = 0;
    iVar2 = 0;
    iVar1 = 0;
    switch (param_2)
    {
    case 0:
        local_8 = 1;
        break;

    case 1:
        local_c = 1;
        iVar2 = 10;
        break;

    case 2:
        local_8 = 1;
        iVar1 = 10;
        break;

    case 3:
        local_c = 1;
        break;
    }

    for (iVar3 = 0; iVar3 < 0xb; iVar3++)
    {
        D_ad14[iVar1 * 0x20 + iVar2] = 0xff;
        iVar2 += local_8;
        iVar1 += local_c;
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

// NOT MATCHING
void DNGLOOK_0a48(int param_1)
{
    int iVar1;
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
        local_a = 1;
        local_6 = 1;
        break;

    case 1:
        local_c = 1;
        local_4 = 9;
        break;

    case 2:
        local_a = 1;
        local_6 = 9;
        break;

    case 3:
        local_c = 1;
        local_4 = 1;
        break;
    }

    for (iVar1 = 0; iVar1 < 5; iVar1++)
    {
        D_ad14[local_6 * 0x20 + local_4] = D_bb15;
        local_4 += local_a;
        local_6 += local_c;
    }
}

// NOT MATCHING
void DNGLOOK_0aee(int param_1)
{
    int local_6;
    int local_4;
    int iVar1;
    int local_c;
    int local_a;

    local_a = 0;
    local_c = 0;

    switch (param_1)
    {
    case 0:
        local_a = 1;
        local_4 = 2;
        local_6 = 1;
        break;

    case 1:
        local_4 = 9;
        local_c = 1;
        local_6 = 2;
        break;

    case 2:
        local_a = 1;
        local_4 = 2;
        local_6 = 9;
        break;

    case 3:
        local_4 = 1;
        local_c = 1;
        local_6 = 2;
        break;
    }

    for (iVar1 = 0; iVar1 < 7; iVar1++)
    {
        D_ad14[local_6 * 0x20 + local_4] = D_bb15;
        local_4 += local_a;
        local_6 += local_c;
    }
}

// NOT MATCHING
void DNGLOOK_0b9e(int param_1)
{
    byte bVar1;
    int local_6;
    int local_4;

    local_4 = D_5896_map_x;
    local_6 = D_5897_map_y;
    if (param_1 == 0)
    {
        local_6--;
    }
    else if (param_1 == 1)
    {
        local_4++;
    }
    else if (param_1 == 2)
    {
        local_6++;
    }
    else if (param_1 == 3)
    {
        local_4--;
    }

    bVar1 = D_595a[D_5895_map_level * 0x40 + (local_6 & 7) * 8 + (local_4 & 7)] & 0xf0;
    if (bVar1 < 0xa0)
    {
        DNGLOOK_0aee(param_1);
    }
    if (bVar1 == 0xb0 || bVar1 == 0xc0 || bVar1 == 0xd0)
    {
        DNGLOOK_097e(D_595a[D_5896_map_x + D_5895_map_level * 0x40 + D_5897_map_y * 8] & 0xf0, param_1);
    }
    else
    {
        DNGLOOK_0a48(param_1);
    }
}

// NOT MATCHING
void DNGLOOK_0c6c(void)
{
    byte bVar1;
    byte bVar4;
    byte bVar5;
    int iVar6;

    for (iVar6 = 0; iVar6 < 0xb; iVar6++)
    {
        D_ad14[0x20 + iVar6] = D_bb14;
    }

    for (iVar6 = 0; iVar6 < 0xb; iVar6++)
    {
        D_ad14[0x120 + iVar6] = D_bb14;
    }

    for (iVar6 = 0; iVar6 < 0xb; iVar6++)
    {
        D_ad14[iVar6 * 0x20 + 1] = D_bb14;
        D_ad14[iVar6 * 0x20 + 9] = D_bb14;
    }

    D_ad14[0x14a] = 0xff;
    D_ad14[0x140] = 0xff;
    D_ad14[0xa] = 0xff;
    D_ad14[0] = 0xff;

    bVar4 = D_595a[D_5896_map_x + D_5897_map_y * 8 + (D_5895_map_level & 0xff) * 0x40];

    bVar1 = bVar4 & 0xf0;
    if (bVar1 != 0 && bVar1 < 0x80)
    {
        bVar4 >>= 4;
        bVar5 = D_244a[bVar4];
        if (bVar5 != 0)
        {
            D_ad14[0xa5] = bVar5;
        }

        if (bVar4 == 3)
        {
            D_bb16 = 1;
            ULTIMA_6fbc(0);
        }
        else
        {
            D_bb16 = 0;
        }
    }

    for (iVar6 = 0; iVar6 < 4; iVar6++)
    {
        DNGLOOK_0b9e(iVar6);
    }
}

// NOT MATCHING
void DNGLOOK_0d3e(void)
{
    byte cVar3;
    byte bVar5;
    int iVar6;
    int iVar7;
    int local_2e[16];
    byte* pcVar12;
    byte* local_e;
    byte* local_c;
    byte* local_a;
    byte* local_8;
    byte* local_6;
    int local_4;

    for (iVar7 = 0; iVar7 < 0xb; iVar7++)
    {
        memset(&D_ad14[iVar7 * 0x20], D_bb15, 0xb);
    }

    if ((D_58a1 & 4) != 0)
    {
        D_ad14[0xa5] = 0xb3;
    }

    DNGLOOK_0c6c();

    for (iVar7 = 0; iVar7 < 8; iVar7++)
    {
        D_ad14[iVar7 + 0x113] = 0xff;
        D_ad14[iVar7 + 0x10b] = 0xff;
    }

    pcVar12 = D_ad14 + 0x6b;
    local_a = D_ad14 + 0x4b;
    local_6 = D_ad14 + 0x8b;
    local_e = D_ad14 + 0x2b;

    for (iVar7 = 0; iVar7 < 6; iVar7++)
    {
        if ((D_58a1 & 4) == 0)
        {
            *pcVar12 = D_2470[iVar7];
            *local_a = D_246a[iVar7];
            *local_6 = D_245e[iVar7];
            *local_e = D_2464[iVar7];
        }
        else
        {
            cVar3 = D_2452[iVar7];
            *local_e = cVar3;
            *local_6 = cVar3;
            *local_a = cVar3;
            *pcVar12 = cVar3;
        }
        pcVar12++;
        local_a++;
        local_6++;
        local_e++;
    }

    for (iVar7 = 0; iVar7 < 6; iVar7++)
    {
        if ((D_58a1 & 4) == 0)
        {
            *pcVar12 = D_2464[iVar7];
            *local_a = D_245e[iVar7];
            *local_6 = D_246a[iVar7];
            *local_e = D_2470[iVar7];
        }
        else
        {
            cVar3 = D_2458[iVar7];
            *local_e = cVar3;
            *local_6 = cVar3;
            *local_a = cVar3;
            *pcVar12 = cVar3;
        }
        pcVar12++;
        local_a++;
        local_6++;
        local_e++;
    }

    local_8 = D_ad14 + 0xcb;
    local_c = D_ad14 + 0xeb;

    for (iVar7 = 0; iVar7 < 0x10; iVar7++)
    {
        if ((D_58a1 & 4) == 0)
        {
            if (D_6603 == 0)
            {
                *local_8 = D_2476[iVar7];
                *local_c = D_2496[iVar7];
            }
            else if (D_6603 == 1)
            {
                *local_8 = D_2486[iVar7];
                *local_c = D_24a6[iVar7];
            }
            else if (D_6603 == 2)
            {
                *local_8 = D_24a6[iVar7];
                *local_c = D_2486[iVar7];
            }
            else if (D_6603 == 3)
            {
                *local_8 = D_2496[iVar7];
                *local_c = D_2476[iVar7];
            }
        }
        else
        {
            *local_c = D_24c6[iVar7];
            *local_8 = D_24b6[iVar7];
        }

        local_8++;
        local_c++;
    }

    for (iVar7 = 0; iVar7 < 0x10; iVar7++)
    {
        local_2e[iVar7] = iVar7;
    }

    for (iVar7 = 0; iVar7 < 0x10; iVar7++)
    {
        iVar6 = ULTIMA_2092_RandomRange(0, 0xf);

        local_4 = local_2e[iVar7];
        local_2e[iVar7] = local_2e[iVar6];
        local_2e[iVar6] = local_4;

        D_ad14[iVar7 + 0xab] = 0;
    }

    if ((D_58a1 & 4) == 0)
    {
        bVar5 = D_5c5a[1]._5;
    }
    else
    {
        bVar5 = D_173c[ULTIMA_2092_RandomRange(0, 7)];
    }

    local_4 = ULTIMA_2092_RandomRange(1, D_13bc[bVar5]._6);
    if (D_13bc[bVar5]._6 == 8 || D_13bc[bVar5]._6 == 0x10)
    {
        local_4 = D_13bc[bVar5]._6;
    }

    for (iVar7 = 0; iVar7 < local_4; iVar7++)
    {
        D_ad14[local_2e[iVar7] + 0xab] = bVar5 * 4 + 64;
    }
}

// NOT MATCHING
void DNGLOOK_0fda(void)
{
    switch (D_58a0)
    {
    case 1:
        D_5896_map_x--;
        D_6603 = 3;
        D_6602 = 3;
        if (7 < D_5896_map_x)
        {
            D_5896_map_x = 7;
        }
        break;

    case 2:
        D_5896_map_x++;
        D_6603 = 1;
        D_6602 = 1;
        if (7 < D_5896_map_x)
        {
            D_5896_map_x = 0;
        }
        break;

    case 3:
        D_5897_map_y--;
        D_6603 = 0;
        D_6602 = 0;
        if (7 < D_5897_map_y)
        {
            D_5897_map_y = 7;
        }
        break;

    case 4:
        D_5897_map_y++;
        D_6603 = 2;
        D_6602 = 2;
        if (7 < D_5897_map_y)
        {
            D_5897_map_y = 0;
        }
        break;

    case 5:
        if (D_5895_map_level != 0)
        {
            D_5895_map_level = D_5895_map_level + -1;
            D_6602 = 4;
            return;
        }

        DUNGEON_1d08();
        D_5893_map_id = 0;
        break;

    case 6:
        if (D_5895_map_level != 7)
        {
            D_5895_map_level++;
            D_6602 = 5;
            return;
        }

        DUNGEON_1d08();
        D_5893_map_id = 0;
        break;
    }
}

// NOT MATCHING
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
            D_5c5a[1]._1 = 0;
            D_5c5a[1]._0_tile = 0;
            D_5c5a[1]._3_y = 0xff;
            D_5c5a[1]._2_x = 0xff;
            D_5c5a[1]._5 = 0xff;
        }

        ULTIMA_0a70_GRAP_2d_SetPenColor(0);
        ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);
        ULTIMA_0c22_GRAP_0f_SelectPage(1);
        ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);
        ULTIMA_0c22_GRAP_0f_SelectPage(0);
    }
}

// NOT MATCHING
void DNGLOOK_1130(void)
{
    int iVar1;

    if ((D_bb17 & 1) != 0)
    {
        if (D_5c5a[1]._5 != 0xff)
        {
            ULTIMA_0be4_FreeMemory(D_a9c6);
        }
        D_a9c6 = 0;
        ULTIMA_0be4_FreeMemory(D_a9c4);
        ULTIMA_0be4_FreeMemory(D_a9c0);
    }

    if ((D_bb17 & 2) == 0)
    {
        do
        {
            iVar1 = ULTIMA_0ff4_LoadTileset(*D_25f0); // TILES.16
        } while (iVar1 == 0);
    }

    if ((D_bb17 & 4) == 0)
    {
        ULTIMA_6f9e(0);
    }

    D_bb17 = 6;
}

// NOT MATCHING
void DNGLOOK_117e(int param_1, int param_2)
{
    byte bVar2;
    byte bVar3;
    uint uVar5;
    int iVar8;
    int local_22;
    int local_14;
    uint local_10;
    int local_e;
    int local_c;
    byte local_8[4];
    int local_4;

    local_4 = 4;
    if (param_1 != 1)
    {
        bVar3 = D_6603;
        if (bVar3 == 0)
        {
            local_4 = 3;
        }
        else if (bVar3 == 1)
        {
            local_4 = 2;
        }
        else if (bVar3 == 3)
        {
            local_4 = 1;
        }
        else if (bVar3 == 5)
        {
            local_4 = 3;
        }

        ULTIMA_6936();

        for (local_10 = 0; local_10 < D_585b; local_10++)
        {
            D_ba14[local_10]._6 = D_5c5a[local_10]._2_x = D_ad14[local_4 * 0x20 + local_10 + 0xb];
            D_ba14[local_10]._7 = D_5c5a[local_10]._3_y = D_ad14[local_4 * 0x20 + local_10 + 0x11];
        }
    }

    if (param_1 > 0 && ((param_2 > 0xef && param_1 == 3) || param_1 < 3))
    {
        local_c = 0xb;
        local_e = 0xb;
        local_4 = 0xb;

        for (iVar8 = 0; iVar8 < 4; iVar8++)
        {
            local_8[iVar8] = D_385e[ULTIMA_2092_RandomRange(0, 7)];
        }

        for (local_22 = 0; local_22 < 0x10; local_22++)
        {
            bVar2 = D_ad14[local_4 + 0xa0];
            if (bVar2 != 0)
            {
                if (bVar2 < 0x40 || (bVar2 & 0xfc) == 0xb4 || (bVar2 & 0xfc) == 0xe8)
                {
                    local_14 = 2;
                    uVar5 = bVar2;
                }
                else
                {
                    local_14 = 0;
                    uVar5 = (bVar2 - 0x40) >> 2;
                }

                if ((bVar2 & 0xfc) == 0xec)
                {
                    uVar5 = local_8[bVar2 & 3];
                }

                iVar8 = ULTIMA_6506(uVar5, local_14, D_ad14[local_c + 0xc0], D_ad14[local_e + 0xe0], D_5895_map_level);
                if (local_14 == 2)
                {
                    if (uVar5 == 1)
                    {
                        D_5c5a[iVar8]._5 = D_5895_map_level * 3 + 7;
                    }
                    else if (uVar5 == 2)
                    {
                        D_5c5a[iVar8]._5 = ULTIMA_2092_RandomRange(1, D_5895_map_level * 10 + 10);
                    }
                    else if (uVar5 <= 0xf)
                    {
                        ASSERT(uVar5 != 0);
                        // TODO: offset
                        D_5c5a[iVar8]._5 = D_3850[uVar5 - 3] + ULTIMA_2092_RandomRange(0, D_3842[uVar5 - 3] - 1);
                    }
                }
            }

            local_4++;
            local_c++;
            local_e++;
        }
    }
}
