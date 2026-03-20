#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>
#include <string.h>

void F_TOWN_0052(int param_1);
void F_TOWN_00b0(int param_1);
F_TOWN_0958();
void F_TOWN_10da(int param_1);
int F_TOWN_011e(int param_1);

int F_NPC_12e0(int a, char b);

int F_TALK_0f32(byte param_1);
void F_TALK_127e(int a);

void F_SHOPPES_04a2(int param_1);
void F_SHOPPES_075e(int param_1);
void F_SHOPPES_07be(int param_1);
void F_SHOPPES_12b2(int param_1);
void F_SHOPPES_14f8(int param_1);
void F_SHOPPES2_066c(int param_1);
void F_SHOPPES2_0abc(int param_1);
void F_SHOPPES3_08b4(int param_1);

// NOT MATCHING: nop
int F_TALK_0000(char* param_1, char* param_2)
{
    while (1)
    {
        if (FUN_1000_2032_to_upper((*param_1++) & 0x7f) != FUN_1000_2032_to_upper((*param_2++) & 0x7f))
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
int F_TALK_0054(int param_1, int param_2)
{
    switch (*FUN_1000_4402_get_address_of_tile_id(param_1, param_2))
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
int F_TALK_00ac(void)
{
    char ch;

    FUN_1000_1850_print_string("\n\nDost thou pay?\n\n:");

    do
    {
        ch = FUN_1000_2032_to_upper(FUN_1000_266c_get_ch());
        if (ch == 'Y')
        {
            FUN_1000_1850_print_string("Yes\n");
            return 0;
        }
    } while (ch != 'N');

    FUN_1000_1850_print_string("No!\n");
    return 1;
}

// NOT MATCHING
void F_TALK_00e6(int param_1)
{
    int iVar1;
    int iVar2;

    if (((D_587c & 0xfe) == 0x12) && (param_1 != 0x83))
    {
        FUN_1000_1850_print_string(/*0x9072*/ "A merchant says:\n\"GET THAT HORSE OUT OF HERE!\"\n");
    }
    else
    {
        if (D_587b == 0xff)
        {
            FUN_1000_39fc_get_first_active_party_member();
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
            F_SHOPPES_12b2(iVar1);
            break;
        case 1:
            F_SHOPPES2_066c(iVar1);
            break;
        case 2:
            F_SHOPPES_07be(iVar1);
            break;
        case 3:
            F_SHOPPES2_0abc(iVar1);
            break;
        case 4:
            F_SHOPPES_075e(iVar1);
            break;
        case 5:
            F_SHOPPES_04a2(iVar1);
            break;
        case 6:
            F_SHOPPES_14f8(iVar1);
            break;
        case 7:
            F_SHOPPES3_08b4(iVar1);
        }
    }
}

// NOT MATCHING
int F_TALK_01e2(void)
{
    int iVar1;
    int local_16;
    char local_12[4];
    byte local_e; // unused

    if (D_5893_map_id != 0x12)
    {
        if (D_5893_map_id == 5)
        {
            FUN_1000_16ba_print_char(0x22);
            FUN_1000_1850_print_string(/*0x90a2*/ "Thou wilt give\nhalf thy gold to\ncharity!");
            FUN_1000_16ba_print_char(0x22);

            if (F_TALK_00ac() != 0)
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

            FUN_1000_1850_print_string(/*0x90cc*/ "A guard demands\na ");
            FUN_1000_1a3e_print_number(local_16, 2, 0x20);
            FUN_1000_1850_print_string(/*0x90e0*/ " gp tribute\nto Blackthorn!");

            if (F_TALK_00ac() != 0)
            {
                return 1;
            }

            if (D_57aa < local_16)
            {
                return 1;
            }

            D_57aa -= local_16;
        }

        FUN_1000_2900_update_vitals();
        return 0;
    }

    if (D_587a == 0x1d)
    {
        FUN_1000_16ba_print_char(0x22);
        FUN_1000_1850_print_string(/*0x90fc*/ "Give now the\npassword, bearer\nof the Badge!");
        FUN_1000_16ba_print_char(0x22);
        FUN_1000_1850_print_string(/*0x9128*/ "\n\nYour response?\n");
        FUN_1000_3b1c_get_string(local_12, 0xe);
        FUN_1000_16ba_print_char(10);
        local_e = 0;

        if (F_TALK_0000(/*0x4a9a*/ "IMPE", local_12) != 0) // TODO: D_4a9a = "IMPE"?
        {
            FUN_1000_16ba_print_char(10);
            FUN_1000_16ba_print_char(0x22);
            FUN_1000_1850_print_string(/*0x913a*/ "Pass, friend!");
            FUN_1000_16ba_print_char(0x22);
            FUN_1000_16ba_print_char(10);
            return 0;
        }
    }

    return 1;
}

// TODO: MATCH
int F_TALK_031e(int param_1)
{
    int iVar1;

    FUN_1000_16ba_print_char(10);
    D_bcdc = param_1;

    if (D_5d5e[param_1]._0[D_5f5e[param_1]._e] == 4)
    {
        D_5d5e[param_1]._0[D_5f5e[param_1]._e] = 1;
    }
    else if (D_5c5a[D_5f5e[param_1]._c]._0_tile == 'p' && ((D_5f5e[param_1]._e & 1) == 0 || (D_5f5e[param_1]._a) == 0))
    {
        FUN_1000_1850_print_string("The guard offers\nno response!\n");
        return 0;
    }

    iVar1 = D_5f5e[param_1]._a;
    if (iVar1 == 0)
    {
        FUN_1000_1850_print_string("No response!\n");
        return 0;
    }
    else
    {
        if (iVar1 < 0x80)
        {
            F_TALK_127e(iVar1);
            return 0;
        }
        if (iVar1 == 0xfd)
        {
            FUN_1000_16ba_print_char(0x22);
            FUN_1000_1850_print_string("Don't hurt me!\nPlease go away!");
            FUN_1000_16ba_print_char(0x22);
            FUN_1000_16ba_print_char(10);
            return 0;
        }
        if (iVar1 == 0xfe)
        {
#if !defined(TARGET_DOS16)
            F_TOWN_10da(0); // TODO: validate param (reference apple?)
#else
            F_TOWN_10da(); // bug?
#endif
            return 0;
        }
        if (iVar1 == 0xff)
        {
            return F_TALK_01e2();
        }

        if ((D_5f5e[param_1]._e & 1) == 0 || (F_NPC_12e0(D_bcdc, D_587f) & 1) == 0)
        {
            FUN_1000_1850_print_string("A merchant says:\n\"Come see me at\nmy shoppe, ");
            FUN_1000_1850_print_string("when\nit's open!\"\n");
            return 0;
        }
        else
        {
            F_TALK_00e6(iVar1);
            return 0;
        }
    }
}

// TODO: MATCH
int F_TALK_041c_talk_cmd(void)
{
    int iVar1;
    int iVar2;
    int iVar3;
    undefined2 uVar4;
    char* pcVar5;
    int iVar6;
    int iStack_6;

    if (FUN_1000_35ec_select_direction() != 0)
    {
        iVar3 = D_5876;
        iStack_6 = iVar3 + (uint)D_5896_map_x;
        iVar1 = D_5878 + (uint)D_5897_map_y;
        iVar6 = iStack_6;
        if (FUN_1000_368e(iStack_6, iVar1, D_5895_map_level) == 0 && F_TALK_0054(iStack_6, iVar1) != 0)
        {
            iStack_6 += iVar3;
            iVar1 += iVar6;
        }

        if (FUN_1000_368e(iStack_6, iVar1, D_5895_map_level) == 0)
        {
            FUN_1000_1850_print_string("\nNobody's here!\n");
        }
        else
        {
            uVar4 = F_TOWN_011e(D_5876);
            pcVar5 = FUN_1000_4402_get_address_of_tile_id(iStack_6, iVar1);
            if (*pcVar5 != 0x9d)
            {
                if (*pcVar5 != 0xab)
                {
                    return F_TALK_031e(uVar4);
                }

                FUN_1000_1850_print_string("\n\"Zzzzzz...\"\n");
            }
            else
            {
                FUN_1000_1850_print_string("\nNo response!\n");
            }
        }
    }

    return 0;
}

// OK P1
void F_TALK_04d2(void) { F_TALK_0f32(0x8d); }

// OK P1
void F_TALK_04da(void) { F_TALK_0f32(0xa2); }

// TODO: MATCH
void F_TALK_04e2(void)
{
    byte bVar1;
    undefined1 uVar2;
    uint uVar4;

    if (D_4af1 != 0)
    {
        uVar4 = 0;
        while (uVar4 < D_4af1)
        {
            FUN_1000_1c9e_set_charset((D_bce4[uVar4] & 0x80) == 0);
            bVar1 = D_bce4[uVar4] & 0x7f;
            uVar4 = uVar4 + 1;

            if (FUN_1000_1f12_get_current_text_column() != 0 || bVar1 != 0x20)
            {
                if ((D_4af3 < 0xf) || (bVar1 != 10))
                {
                    if (bVar1 != 10)
                    {
                        uVar2 = FUN_1000_1f12_get_current_text_column();
                        D_4af3 = uVar2;
                    }
                    FUN_1000_16ba_print_char(bVar1);
                }
                else
                {
                    D_4af3 = 0;
                }
            }
        }

        D_4af1 = 0;
        FUN_1000_1c9e_set_charset(0);
    }
}

// OK P1
void F_TALK_0574(byte param_1)
{
    if (D_4af1 != 0x10)
    {
        D_bce4[D_4af1++] = param_1;

        if (param_1 != 0x8a && param_1 != 0xa0)
        {
            return;
        }

        if (FUN_1000_1f12_get_current_text_column() + (uint)D_4af1 >= 0x12)
        {
            FUN_1000_16ba_print_char(10);
        }
    }

    F_TALK_04e2();
}

int F_TALK_0b04(void);

// NOT MATCHING
int F_TALK_05b6(void)
{
    int local_4;

    local_4 = (D_bce0[0] & 0x7f) * 100 + (D_bce0[1] & 0x7f) * 10 + (D_bce0[2] & 0x7f) - 0x14d0; // 0x14d0 == 5328
    if (D_57aa >= local_4)
    {
        D_57aa -= local_4;
        FUN_1000_2900_update_vitals();
        if ((D_5c5a[D_5f5e[D_bcdc]._c]._0_tile & 0xfc) == 0x6c && D_588b >= 100)
        {
            D_588b = 0;
            FUN_1000_3ef0(&D_5888, 1, 99);
            if (D_57aa == 0)
            {
                FUN_1000_3ef0(&D_5888, 2, 99);
            }
        }

        return 0;
    }
    else
    {
        D_4af1 = 0;
        FUN_1000_16ba_print_char(0x22);
        FUN_1000_1850_print_string(/*0x9328*/ "Thou hast not enough gold!");
        FUN_1000_16ba_print_char(0x22);
        FUN_1000_1850_print_string(/*0x9344*/ "\n\n");
        D_4aee = 0;
        D_4aef = 0;
        return F_TALK_0b04();
    }
}

// NOT MATCHING
void F_TALK_0682(byte param_1)
{
    if (param_1 < 0x40)
    {
        FUN_1000_3ef0(&D_57c0[param_1], 1, 99);
        return;
    }

    switch (param_1)
    {
    case 0x41:
        FUN_1000_3f14(&D_57a8, 1, 9999);
        FUN_1000_2900_update_vitals();
        break;
    case 0x42:
        FUN_1000_3f14(&D_57aa, 1, 9999);
        FUN_1000_2900_update_vitals();
        break;
    case 0x43:
        FUN_1000_3ef0(&D_57ac, 1, 99);
        break;
    case 0x44:
        FUN_1000_3ef0(&D_57ad, 1, 99);
        break;
    case 0x45:
        FUN_1000_3ef0(&D_57ae, 1, 99);
        break;
    case 0x46:
        FUN_1000_3ef0(&D_57af, 1, 99);
        break;
    case 0x47:
        FUN_1000_3ef0(&D_57b0, 1, 99);
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
        FUN_1000_3ef0(&D_57b1, 1, 99);
        break;
    }
}

// TODO: MATCH
int F_TALK_0728(byte param_1, byte param_2)
{
    byte local_4;

    do
    {
        local_4 = *D_bcde++;
        if (local_4 == param_1)
        {
            return 1;
        }
    } while (local_4 != param_2);

    return 0;
}

// TODO: MATCH
void F_TALK_075a(int param_1)
{
    D_bcde = D_b21e;

    if (param_1 != 0)
    {
        for (; param_1 != 0; param_1--)
        {
            F_TALK_0728(0, 0x90);
        }
    }
}

int F_TALK_0f32(byte param_1);

// TODO: MATCH
int F_TALK_0788(void)
{
    do
    {
        if (*D_bcde == 0)
        {
            return 0;
        }
    } while (F_TALK_0f32(*D_bcde++) == 0);

    return 1;
}

// OK P1
int F_TALK_07aa(int param_1)
{
    F_TALK_075a(param_1);
    return F_TALK_0788();
}

// OK P1
int F_TALK_07be()
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

    return F_TALK_0788();
}

// TODO: MATCH
// put avatar name
void F_TALK_07e4(void)
{
    byte* pbVar1;

    for (pbVar1 = D_55a8_party[0]._0; *pbVar1 != 0; pbVar1++)
    {
        F_TALK_0f32(*pbVar1 | 0x80);
    }
}

// NOT MATCHING
// join
int F_TALK_080a(void)
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
        FUN_1000_266c_get_ch();
        FUN_1000_1850_print_string(/*0x9348*/ "\"Thou hast no room for me in thy party! ");
        FUN_1000_1850_print_string(/*0x9372*/ "Seek me again if one of thy members doth leave\nthee.");

        return 0;
    }

    F_TALK_075a(0);

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

        if (F_TALK_0000(local_8, local_2c) != 0)
        {
            // local_30 = DI;
            D_55a8_party[local_4]._1f = 0;

            ASSERT(sizeof(S_55a8) == 0x20);
            memcpy(&local_28, &D_55a8_party[local_4], sizeof(S_55a8));
            memcpy(&D_55a8_party[local_4], &D_55a8_party[D_585b], sizeof(S_55a8));
            memcpy(&D_55a8_party[D_585b]._0, &local_28, sizeof(S_55a8));

            D_585b++;

            F_TOWN_0052(D_bcdc);
            F_TOWN_00b0(D_bcdc);

            FUN_1000_2900_update_vitals();
            F_TALK_04e2();

            D_bcde = local_2e;

            return 1;
        }
    } while (--local_4 != 0);

    F_TALK_0574(0x22);
    F_TALK_0574(10);
    FUN_1000_1850_print_string(/*0x93a8*/ "\nSystem Error -\nNo Match!");
    D_bcde = local_2e;
    // local_30 = DI;

    return 1;
}

// OK P1?
int F_TALK_093a(void)
{
    D_bcde = D_b21e;
    while (*D_bcde != D_bcf4)
    {
        F_TALK_0728(0x90, 0x9f);
    }
    D_bcde++;
    return F_TALK_0788();
}

// OK P1?
int F_TALK_0960(void)
{
    F_TALK_0728(0, 0x90);
    return F_TALK_0788();
}

// OK P1?
int F_TALK_096e(void)
{
    D_bcde = D_b21e;
    while (*D_bcde != D_bcf4)
    {
        F_TALK_0728(0x90, 0x9f);
    }
    F_TALK_0728(0, 0x9f);
    return F_TALK_0788();
}

// OK P1
int F_TALK_099a(int param_1)
{
    D_bcde = D_b21e;
    param_1 = param_1 * 2 + 5;

    while (param_1 != 0)
    {
        if (F_TALK_0728(0, 0x90) == 0)
            return 0;

        param_1--;
    }

    return 1;
}

// OK P1
int F_TALK_09d8(void)
{
    int local_4;

    D_bcf6 = 0;
    while (1)
    {
        if (F_TALK_099a(D_bcf6) == 0)
        {
            return 0;
        }

        local_4 = FUN_1000_6f1e(D_bcde, D_bcf8);
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
void F_TALK_0a2c(void)
{
    F_TALK_04e2();
    FUN_1000_3b1c_get_string(D_bcf8, 0xf);
}

// OK P1
int F_TALK_0a3c(void)
{
    F_TALK_04da();
    if (F_TALK_07aa(4) == 0)
    {
        F_TALK_04da();
        F_TALK_04d2();
    }
    return 1;
}

// TODO: MATCH
int F_TALK_0a54(int param_1)
{
    int uVar1;
    int iVar2;
    int iVar3;

    switch (param_1)
    {
    case 0:
        if (D_4af2 != 0)
        {
            return 2;
        }
        FUN_1000_1850_print_string("\"My name is ");
        iVar3 = F_TALK_07aa(0);
        break;
    case 1:
    case 2:
        if (D_4af2 != 0)
        {
            return 2;
        }
        F_TALK_04da();
        iVar3 = F_TALK_07aa(3);
        break;
    case 3:
    case 4:
        if (D_4af2 != 0)
        {
            return 2;
        }
        return F_TALK_0a3c();
    default:
        FUN_1000_1850_print_string("\"With language like that, how did you become an Avatar?");
        F_TALK_04da();
        F_TALK_04d2();
        F_TALK_04d2();

        for (iVar3 = 0; iVar3 < 0x1c; iVar3 = iVar3 + 1)
        {
            FUN_1000_5910_update_map();
            iVar2 = FUN_1000_1d5e_peek_keystroke();
            if (iVar2 != 0)
                break;
            FUN_1000_20fa_wait_ticks(1);
        }
        FUN_1000_1b16_clear_keyboard_buffer();
        return 0;
    }

    if (iVar3 == 0)
    {
        F_TALK_04da();
        F_TALK_04d2();
        F_TALK_04d2();
        return 0;
    }

    return 1;
}

// TODO: MATCH
int F_TALK_0b04(void)
{
    int iVar2;
    int iVar3;
    byte bStack_4;

    do
    {
        D_4af2 = 0;
        FUN_1000_1850_print_string("Your interest?\n:");
        F_TALK_0a2c();
        if (D_bcf8[0] == 0)
        {
            FUN_1000_1850_print_string("BYE\n\n");
            return F_TALK_0a3c();
        }
        F_TALK_04d2();
        F_TALK_04d2();
        iVar3 = -1;
        for (bStack_4 = 0; bStack_4 < 0x22; bStack_4++)
        {
            iVar2 = FUN_1000_6f1e((byte*)D_4aa8[bStack_4], D_bcf8);
            if (iVar2 != -1 && (iVar2 == 0 || D_bcf8[iVar2 - 1] == ' '))
            {
                iVar3 = F_TALK_0a54(bStack_4);
                if (iVar3 == 0)
                    break;
                if (iVar3 == 1)
                {
                    return 1;
                }
            }
        }

        if (iVar3 != 0)
        {
            if (F_TALK_09d8() == 0)
            {
                FUN_1000_1850_print_string("\"I cannot help thee with that.");
                F_TALK_04da();
                F_TALK_04d2();
                F_TALK_04d2();
            }
            else
            {
                F_TALK_04da();
                iVar3 = F_TALK_07aa(D_bcf6 * 2 + 6);
                if (iVar3 != 0)
                {
                    return 1;
                }
                F_TALK_04da();
                F_TALK_04d2();
                F_TALK_04d2();
            }
        }
    } while (1);
}

// NOT MATCHING
int F_TALK_0bd4(void)
{
    int iVar1;

    D_bcde = D_b21e;
    while (*D_bcde != D_bcf4)
    {
        F_TALK_0728(0x90, 0x9f);
    }

    F_TALK_0728(0, 0x9f);
    F_TALK_0728(0, 0x9f);

    do
    {
        iVar1 = FUN_1000_6f1e(D_bcde, D_bcf8);
        if (iVar1 != -1 && (iVar1 == 0 || D_bcf8[iVar1 - 1] == ' '))
        {
            return 1;
        }
        iVar1 = F_TALK_0728(0, 0x90);
    } while (iVar1 != 0 && F_TALK_0728(0, 0x90) != 0);

    return 0;
}

// NOT MATCHING
// process label?
int F_TALK_0c5c(void)
{
    int iVar1;
    undefined2 uVar2;
    int iVar3;
    char** local_a;
    byte local_4;

    do
    {
        F_TALK_04da();

        iVar1 = F_TALK_093a();
        if (iVar1 != 0)
        {
            uVar2 = 1;
            return uVar2;
        }

        F_TALK_04da();

        do
        {
            F_TALK_04d2();
            F_TALK_04d2();
            D_4af2 = 0xff;
            FUN_1000_1850_print_string(/*0x9440*/ "You respond-\n:");
            F_TALK_0a2c();
            if (D_bcf8[0] == 0)
            {
                FUN_1000_1850_print_string(/*0x9450*/ "\n\n\"What didst thou say?");
            }
        } while (D_bcf8[0] == 0);

        F_TALK_04d2();
        F_TALK_04d2();
        local_4 = 0;
        iVar1 = -1;
        local_a = D_4aa8;
        do
        {
            iVar3 = FUN_1000_6f1e((byte*)*local_a, D_bcf8);
            if (iVar3 != -1 && (iVar3 == 0 || *(iVar3 + D_bcf8 - 1) == ' '))
            {
                iVar1 = F_TALK_0a54(local_4);
                if (iVar1 == 0)
                    break;
                if (iVar1 == 1)
                {
                    return 1;
                }
            }
            local_a = local_a + 1;
            local_4 = local_4 + 1;
        } while (local_4 < 0x22);
    } while (iVar1 == 0);

    iVar1 = F_TALK_0bd4();
    if (iVar1 == 0)
    {
        F_TALK_04da();
        iVar1 = F_TALK_096e();
    }
    else
    {
        F_TALK_04da();
        iVar1 = F_TALK_0960();
    }
    if (iVar1 == 0)
    {
        F_TALK_04da();
        F_TALK_04d2();
        F_TALK_04d2();
        uVar2 = F_TALK_0b04();
    }
    else
    {
        uVar2 = 1;
    }

    return uVar2;
}

// NOT MATCHING (u32 operation)
// set npc killed flag
int F_TALK_0d42(int param_1) { *(u32*)&D_5b5a[(D_5893_map_id - 1) * 4] |= ((u32)1) << ((byte)param_1 & 0x1f); }

// NOT MATCHING (u32 operation)
// check npc killed flag
int F_TALK_0d7a(int param_1)
{
    return (*(u32*)&D_5b5a[(D_5893_map_id - 1) * 4] & (((u32)1) << ((byte)param_1 & 0x1f))) != 0;
}

// NOT MATCHING
int F_TALK_0dbe(byte param_1)
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
        if (F_TALK_05b6() != 0)
        {
            // -> 0e74
            return 1;
        }

        // 0dda
        D_4aef = D_4aee = 0;
        return 0;

    case 0x86:
        // 0e0e
        F_TALK_0682(param_1 & 0x7f);

        // 0dda
        D_4aef = D_4aee = 0;
        return 0;

    case 0x8c:
        // 0e1c
        D_4aef = D_4aee = 0;

        if (F_TALK_0d7a(D_bcdc) == 0)
        {
            // 0dfc
            return 0;
        }

        if (param_1 == 0xff)
        {
            return F_TALK_0b04();
        }

        // 0e3a
        D_bcf4 = param_1;

        // 0e3d
        return F_TALK_0c5c();

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
        return F_TALK_0c5c();
    }
}

// NOT MATCHING
void F_TALK_0e78(void)
{
    int local_e;
    int local_c;
    int local_a;
    char local_8[4];
    int local_4;

    local_a = 0;
    F_TALK_04da();
    F_TALK_04e2();
    FUN_1000_1850_print_string(/*0x9468*/ "What is thy name?\"\n");
    FUN_1000_1850_print_string(/*0x947c*/ "\nYou respond-\n:");
    F_TALK_0a2c();
    D_4aef = 0;
    D_4aee = 0;

    if (D_bcf8[0] == 0)
    {
        FUN_1000_1850_print_string(/*0x948c*/ "\n\n\"If you say so...");
    }
    else
    {
        if (D_585b != 0)
        {
            for (; local_a < D_585b; local_a++)
            {
                local_c = 0;
                memcpy(local_8, D_55a8_party[local_a]._0, 4);
                local_c = 4;
                local_4 = 0;

                local_e = FUN_1000_6f1e(local_8, D_bcf8);
                if (local_e != -1 && (local_e == 0 || (D_bcf8[local_e - 1] == ' ')))
                {
                    F_TALK_0d42(D_bcdc);
                    FUN_1000_1850_print_string(/*0x94a0*/ "\n\n\"A pleasure!");
                    return;
                }
            }
        }

        FUN_1000_1850_print_string(/*0x94b0*/ "\n\n\"If you say so...");
    }
}

// OK P1
int F_TALK_0f32(byte param_1)
{
    byte* local_4;
    int local_6;
    char* pbVar5;

    if (D_4aee != 0)
    {
        return F_TALK_0dbe(param_1);
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
        F_TALK_07e4();
        break;
    case 0x82: // end conversation
        // 0f8c
        return 1;
    case 0x83: // pause
        // 0f92
        for (local_6 = 0; local_6 < 0x1c; local_6++)
        {
            FUN_1000_5910_update_map();
            if (FUN_1000_1d5e_peek_keystroke() != 0)
                break;
            FUN_1000_20fa_wait_ticks(1);
        }
        FUN_1000_1b16_clear_keyboard_buffer();
        return 0; // -> 0f5e
    case 0x84:    // join
        // 0fb6
        return F_TALK_080a(); // -> 1114
    case 0x87:                // key_or
        // 0fbc
        local_4 = D_bcde;
        if (F_TALK_07be() != 0)
        {
            return 1;
        }
        D_bcde = local_4;
        return 0; // -> 0f5e
    case 0x88:    // ask name
        // 0fd2
        F_TALK_0e78();
        return 0; // -> 0f5e
    case 0x89:    // karma +1
        // 0fd8
        FUN_1000_3ef0(&D_5888, 1, 99);
        return 0; // -> 0f5e
    case 0x8a:    // karma -1
        // 0fea
        FUN_1000_3f36(&D_5888, 1);
        return 0; // -> 0f5e
    case 0x8b:    // call guards
        // 0ff8
        F_TOWN_0958();
        return 0; // -> 0f5e
    case 0x8e:    // rune
        // 0ffe
        D_4af0 ^= 0x80;
        return 0; // -> 0f5e
    case 0xff:    // no selection
        // 1006
        F_TALK_04e2();
        return F_TALK_0b04(); // -> 1114
    case 0x8f:                // wait
        // 1010
        FUN_1000_266c_get_ch();
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
        return F_TALK_0c5c(); // -> 1114
        // ----------
    default:
        // 10ce
        if (param_1 < 0x81)
        {
            F_TALK_0574(0xa0);

            pbVar5 = D_24ea[param_1 - 1];
            while (*pbVar5 != 0)
            {
                F_TALK_0574((byte)*pbVar5++ | 0x80);
            }

            if (*D_24ea[param_1 - 1] == 0)
            {
                F_TALK_0574(param_1);
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
                F_TALK_0574(0xa0);
            }

            F_TALK_0574(param_1);
            D_4af5 = 0;
        }
        break;
    }

    return 0;
}

// OK P1
int F_TALK_111c(void)
{
    FUN_1000_1850_print_string("You see ");

    if (F_TALK_07aa(1) != 0)
    {
        return 1;
    }
    else
    {
        F_TALK_04d2();
        F_TALK_04d2();
        if (F_TALK_0d7a(D_bcdc) == 0)
        {
            FUN_1000_207e_srand(FUN_1000_2056_get_time());
            if (FUN_1000_2092_random_range(0, 1) != 0)
            {
                FUN_1000_1850_print_string("\"I am called ");
                if (F_TALK_07aa(0) == 0)
                {
                    F_TALK_04da();
                    F_TALK_04d2();
                    F_TALK_04d2();
                }
                else
                {
                    return 1;
                }
            }
        }
        else
        {
            F_TALK_04da();
            if (F_TALK_07aa(2) == 0)
            {
                F_TALK_04da();
                F_TALK_04d2();
                F_TALK_04d2();
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
void F_TALK_1180(void)
{
    int local_4;

    if (D_5958 == 0)
    {
        FUN_1000_1850_print_string("\nSomething was stolen!\n");
        FUN_1000_43ae(800, 2000, 1, 0x32);
        FUN_1000_207e_srand(FUN_1000_2056_get_time());

        if ((D_57ac | D_57ad | D_57ae) != 0)
        {
            do
            {
                while (1)
                {
                    switch (FUN_1000_2092_random_range(0, 2))
                    {
                    case 0:
                        if (D_57ac != 0)
                        {
                            FUN_1000_3f36(&D_57ac, 1);
                            return;
                        }
                        break;

                    case 1:
                        if (D_57ad != 0)
                        {
                            FUN_1000_3f36(&D_57ad, 1);
                            return;
                        }
                        break;

                    case 2:
                        if (D_57ae != 0)
                        {
                            FUN_1000_3f36(&D_57ae, 1);
                            return;
                        }
                        break;
                    default:
                        return;
                    }
                }
            } while (D_57ad == 0);

            FUN_1000_3f36(&D_57ad, 1);
        }
        else
        {
            for (local_4 = 0x2f; local_4 >= 0; local_4--)
            {
                if (D_57c0[local_4] != 0)
                {
                    FUN_1000_3f36(&D_57c0[local_4], 1);
                    return;
                }
            }

            for (local_4 = 7; local_4 >= 0; local_4--)
            {
                if (D_5828[local_4] != 0)
                {
                    FUN_1000_3f36(&D_5828[local_4], 1);
                    return;
                }
            }

            for (local_4 = 7; local_4 >= 0; local_4--)
            {
                if (D_5820[local_4] != 0)
                {
                    FUN_1000_3f36(&D_5820[local_4], 1);
                    return;
                }
            }

            FUN_1000_3f54(&D_57aa, FUN_1000_2092_random_range(1, 0xf));
            FUN_1000_2900_update_vitals();
        }
    }
}

// OK P1
void F_TALK_127e(int param_1)
{
    uint local_4;
    s16* local_6;
    s16 local_8;
    s16 local_a;
    s16 local_c;

    local_4 = (D_5893_map_id - 1) >> 3;
    FUN_1000_256e_read_file_from_disk(D_4aa0[local_4], D_b21e, 0x200, 0);

    // 12a9
    local_6 = (s16*)D_b21e;
    local_c = *local_6++;

    // 12ad
    for (local_a = 1; *local_6++ != param_1 && local_a <= local_c; local_6++, local_a++)
    {
    }

    // 12d6
    local_8 = *local_6;
    FUN_1000_256e_read_file_from_disk(D_4aa0[local_4], D_b21e, 0x400, local_8);

    if (F_TALK_111c() == 0)
    {
        if (F_TALK_0b04() == 0)
        {
            F_TALK_0a3c();
        }
    }

    F_TALK_1180();
}
