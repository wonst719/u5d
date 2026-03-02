#include "COMMON.H"
#include "FILE.H"
#include "FUNCS.H"
#include "VARS.H"

#include <memory.h>
#include <stdio.h>
#include <string.h>

int F_COMBAT_0000(int param_1, int param_2, int param_3);

int F_COMBAT_120e(void);

int F_COMBAT_13e2(int param_1, int param_2);

// NOT MATCHING
void F_CAST2_0000(int param_1)
{
    int iVar2;

    if (param_1 < 9)
    {
        FUN_1000_223c_audio_white_noise(800, param_1 * 0x640 + 8000, 700);
        FUN_1000_0a70_set_pen_color(D_13b0_white_color);
        FUN_1000_0b86(8, 8, 0xb7, 0xb7);
        iVar2 = param_1 * 4000 + 10000;
        FUN_1000_2192_audio_some_noise(D_4af6[param_1], 1, iVar2, D_4b08[param_1], D_4b2c[param_1]);
        FUN_1000_2192_audio_some_noise(D_4af6[param_1], 1, iVar2, D_4b1a[param_1], -D_4b2c[param_1]);
        FUN_1000_0b86(8, 8, 0xb7, 0xb7);
    }
    else
    {
        FUN_1000_2192_audio_some_noise(0x1180, 1, 65000, 300, 1);
    }
}

// NOT MATCHING
int F_CAST2_009e(void)
{
    int iVar1;

    FUN_1000_1850_print_string(/*0x94f4*/ "On who: ");

    iVar1 = FUN_1000_2e8e();
    if (iVar1 < 0)
    {
        FUN_1000_1850_print_string(/*0x94fe*/ "None!");
    }
    else
    {
        FUN_1000_1850_print_string(D_55a8_party[iVar1]._0);
    }

    if (FUN_1000_1f12_get_current_text_column() != 0)
    {
        FUN_1000_16ba_print_char(10);
    }

    return iVar1;
}

// NOT MATCHING
int F_CAST2_00de(void)
{
    byte bVar1;
    int iVar2;
    int uVar3;
    int iVar4;
    int iVar5;
    int local_28;
    byte abStack_24[11];
    byte local_19;
    int local_18;
    int local_14;
    int local_10;
    int local_c;
    int local_8;

    local_14 = -1;
    local_c = 0;
    iVar4 = 0;

    while (local_c == 0)
    {
        iVar2 = FUN_1000_266c_get_ch();
        uVar3 = FUN_1000_2032_to_upper(iVar2);
        // switch
        local_19 = (byte)uVar3;
        if (local_19 != 0x4a && local_19 != 0x4f)
        {
            if (local_19 > 0x40 && local_19 < 0x5b && iVar4 < 4)
            {
                abStack_24[iVar4 + 4] = local_19;
                local_28 = FUN_1000_1f12_get_current_text_column();
                iVar2 = FUN_1000_216c_strlen(D_1bfc[local_19 - 'A']);
                if (iVar2 + local_28 > 0xd)
                {
                    FUN_1000_16ba_print_char(10);
                }

                bVar1 = FUN_1000_1f12_get_current_text_column();
                abStack_24[iVar4] = bVar1;
                FUN_1000_1850_print_string(D_1bfc[local_19 - 'A']);
                FUN_1000_16ba_print_char(0x20);
                iVar4++;
                continue;
            }

            uVar3 = uVar3 & 0xff;
            if (uVar3 == 8)
            {
                if (iVar4 != 0)
                {
                    if (FUN_1000_1f12_get_current_text_column() == 0)
                    {
                        FUN_1000_16ba_print_char(0x20);
                        iVar2 = FUN_1000_1cee_get_current_text_row();
                        FUN_1000_1bf2_set_text_cursor_position(abStack_24[iVar4 - 1], iVar2 - 1);
                    }
                    else
                    {
                        iVar2 = FUN_1000_1cee_get_current_text_row();
                        FUN_1000_1bf2_set_text_cursor_position(abStack_24[iVar4 - 1], iVar2);
                    }

                    local_18 = FUN_1000_216c_strlen(D_1bfc[abStack_24[iVar4 + 3] - 'A']);

                    for (iVar2 = 0; iVar2 <= local_18 + 1; iVar2++)
                    {
                        FUN_1000_16ba_print_char(0x20);
                    }
                    iVar2 = FUN_1000_1cee_get_current_text_row();
                    FUN_1000_1bf2_set_text_cursor_position(abStack_24[iVar4 - 1], iVar2);
                    iVar4--;
                }
                continue;
            }

            if (uVar3 != 0xd)
            {
                if (uVar3 == 0x1b)
                {
                    iVar4 = 0;
                }
                else if (uVar3 != 0x20)
                    continue;
            }

            local_c = 1;
        }
    }

    do
    {
        local_c = 1;
        for (iVar2 = 0; iVar2 < iVar4 - 1; iVar2 = iVar2 + 1)
        {
            if (abStack_24[iVar2 + 5] < abStack_24[iVar2 + 4])
            {
                bVar1 = abStack_24[iVar2 + 4];
                abStack_24[iVar2 + 4] = abStack_24[iVar2 + 5];
                abStack_24[iVar2 + 5] = bVar1;
                local_c = 0;
            }
        }
    } while (local_c == 0);

    for (iVar2 = 0; iVar5 = local_14, iVar2 < 0x30; iVar2++)
    {
        local_10 = 1;
        local_8 = 0;

        for (iVar5 = 0; iVar5 < iVar4; iVar5++)
        {
            if (D_1c30[iVar2][local_8] != abStack_24[iVar5 + 4])
            {
                local_10 = 0;
                break;
            }

            for (; iVar5 < iVar4 - 1 && abStack_24[iVar5 + 4] == abStack_24[iVar5 + 5]; iVar5++)
            {
            }

            local_8++;
        }

        if (local_10 != 0 && D_1c30[iVar2][local_8] != '\0')
        {
            local_10 = 0;
        }

        iVar5 = iVar2;
        if (local_10 != 0)
            break;
    }

    local_14 = iVar5;
    if (iVar4 == 0)
    {
        local_14 = -1;
    }
    else
    {
        FUN_1000_16ba_print_char(10);
        if (local_14 < 0)
        {
            local_14 = -2;
        }
    }

    return local_14;
}

// NOT MATCHING
int F_CAST2_0306(void)
{
    bool bVar1;
    int iVar3;

    if (D_5893_map_id < 0x80)
    {
        D_5876 = D_5896_map_x;
        D_5878 = D_5897_map_y;
    }
    else
    {
        D_5876 = D_ba14[D_589e]._6;
        D_5878 = D_ba14[D_589e]._7;
    }

    FUN_1000_1850_print_string(/*0x9504*/ "Direction-");

    do
    {
        iVar3 = FUN_1000_266c_get_ch();
        bVar1 = 1;
        if (iVar3 == 1)
        {
            FUN_1000_1850_print_string(/*0x9526*/ "West\n");
            D_5876--;
        }
        else if (iVar3 == 2)
        {
            FUN_1000_1850_print_string(/*0x9518*/ "East\n");
            D_5876++;
        }
        else if (iVar3 == 3)
        {
            FUN_1000_1850_print_string(/*0x9510*/ "North\n");
            D_5878--;
        }
        else if (iVar3 == 4)
        {
            FUN_1000_1850_print_string(/*0x951e*/ "South\n");
            D_5878++;
        }
        else if (iVar3 == 0x20)
        {
            FUN_1000_1850_print_string(/*0x952c*/ "Pass\n");
            iVar3 = 0;
        }
        else
        {
            bVar1 = 0;
        }
    } while (!bVar1);

    return iVar3;
}

// NOT MATCHING
int F_CAST2_03c2(int param_1)
{
    char cVar1;
    int uVar2;
    int iVar3;
    s16 local_8;

    cVar1 = D_55a8_party[param_1]._b;
    if (cVar1 != 'D')
    {
        local_8 = D_55a8_party[param_1]._10;
        iVar3 = D_55a8_party[param_1]._12;
        uVar2 = FUN_1000_3abe();
        FUN_1000_3f14(&local_8, uVar2, iVar3);
        D_55a8_party[param_1]._10 = local_8;
        D_a9fa = 1;
    }

    return cVar1 != 'D';
}

// NOT MATCHING
void F_CAST2_040a(int param_1, int param_2)
{
    if (param_1 != 0 || param_2 != 0)
    {
        if (param_2 == 0)
        {
            F_CAST2_0000(2);
        }
        else
        {
            F_CAST2_0000(1);
        }

        switch (param_1)
        {
        case 0:
            FUN_1000_2e96_print_direction(0);
            break;

        case 1:
            FUN_1000_2e96_print_direction(4);
            break;

        case 2:
            FUN_1000_2e96_print_direction(3);
            break;

        case 3:
            FUN_1000_2e96_print_direction(1);
            break;

        case 4:
            FUN_1000_2e96_print_direction(2);
            break;
        }
    }
}

// NOT MATCHING
void F_CAST2_046c(void)
{
    int iVar1;

    FUN_1000_5d0a(-1, D_5896_map_x - D_589b, D_5897_map_y - D_589c, 0x20);

    for (iVar1 = 0; iVar1 < 0x14; iVar1++)
    {
        if (D_587a != 'T')
        {
            FUN_1000_4552();
        }

        FUN_1000_5394();
        FUN_1000_56ac_draw_map();
        FUN_1000_20fa_wait_ticks(1);
    }

    FUN_1000_5910_update_map();
}

// NOT MATCHING
int F_CAST2_04c2(int param_1)
{
    byte bVar1;
    int iVar2;
    int iVar4;
    int iVar5;
    int uVar6;
    int local_8;

    if (param_1 == 0)
    {
        uVar6 = 8;
    }
    else
    {
        uVar6 = 5;
    }

    F_CAST2_0000(uVar6);

    for (local_8 = 0;; local_8++)
    {
        if (local_8 > 7)
        {
            return 0;
        }

        if (F_COMBAT_120e() != 0)
        {
            if (F_COMBAT_0000(0xd8, D_5876, D_5878) != 0)
            {
                if (*FUN_1000_4402_get_address_of_tile_id(D_5876, D_5878) != 0xff)
                {
                    break;
                }
            }
        }
    }

    iVar2 = FUN_1000_6506(0x26, 0, D_5876, D_5878, D_5895_map_level);
    if (iVar2 > -1)
    {
        FUN_1000_2192_audio_some_noise(0xac8, 1, 12000, 500, 5);
        bVar1 = D_ba14[iVar2]._4;
        D_5c5a[bVar1]._1 = 0x16;
        D_5c5a[bVar1]._2_x = 0x16;
        FUN_1000_1068(0x1d8, D_5876, D_5878);
        D_5c5a[bVar1]._1 = 0xd8;
        D_5c5a[bVar1]._2_x = 0xd8;

        if (param_1 == 0)
        {
            iVar4 = FUN_1000_3abe();
            iVar5 = F_COMBAT_13e2(D_589e, -1);
            if (iVar5 <= iVar4)
            {
                FUN_1000_1850_print_string(/*0x9532*/ "Oops...\n");
                return -1;
            }
        }

        D_ba14[iVar2]._2 |= 1;
        return 1;
    }

    return 0;
}

// NOT MATCHING
// resurrect
int F_CAST2_05e0(int param_1, int param_2)
{
    int iVar4;
    short sVar5;
    int uVar6;

    if (param_1 < 0)
    {
        return -1;
    }

    if (D_55a8_party[param_1]._b != 'D')
    {
        if (param_2 != 0)
        {
            FUN_1000_1850_print_string(/*0x953c*/ "Not dead!\n");
        }
        return 0;
    }

    D_55a8_party[param_1]._b = 'G';
    D_55a8_party[param_1]._10 = 1;

    switch (D_55a8_party[param_1]._a)
    {
    case 'A':
        D_55a8_party[param_1]._f = D_55a8_party[param_1]._e;
        break;

    case 'B':
        D_55a8_party[param_1]._f = D_55a8_party[param_1]._e >> 1;
        break;

    case 'M':
        D_55a8_party[param_1]._f = D_55a8_party[param_1]._e;
        break;
    }

    if (D_5888 < 0x62)
    {
        D_55a8_party[param_1]._14 = D_5888 * D_55a8_party[param_1]._14 / 100;
    }

    sVar5 = 1;
    for (iVar4 = D_55a8_party[param_1]._14 / 100; 0 < iVar4; iVar4 = iVar4 >> 1)
    {
        sVar5++;
    }

    D_55a8_party[param_1]._16 = sVar5;
    D_55a8_party[param_1]._12 = sVar5 * 0x1e;

    if (param_2 == 1)
    {
        uVar6 = 6;
    }
    else
    {
        if (param_2 != 0)
        {
            D_a9fa = 1;
            return 1;
        }

        uVar6 = 8;
    }

    F_CAST2_0000(uVar6);
    D_a9fa = 1;
    return 1;
}

// NOT MATCHING
void F_CAST2_06ec(void)
{
    FUN_1000_1c9e_set_charset(1);
    FUN_1000_16ba_print_char(10);
    FUN_1000_16ba_print_char(((D_5897_map_y & 0xf0) >> 4) + 0x41);
    FUN_1000_16ba_print_char(0x27);
    FUN_1000_16ba_print_char((D_5897_map_y & 0xf) + 0x41);
    FUN_1000_1850_print_string(/*0x9548*/ "\", ");
    FUN_1000_16ba_print_char(((D_5896_map_x & 0xf0) >> 4) + 0x41);
    FUN_1000_16ba_print_char(0x27);
    FUN_1000_16ba_print_char((D_5896_map_x & 0xf) + 0x41);
    FUN_1000_16ba_print_char(0x22);
    FUN_1000_1c9e_set_charset(0);
    FUN_1000_16ba_print_char(10);
}

// NOT MATCHING
int F_CAST2_0768(void)
{
    int uVar2;
    byte* pbVar3;

    if (F_CAST2_0306() == 0)
    {
        uVar2 = -1;
    }
    else
    {
        pbVar3 = FUN_1000_4402_get_address_of_tile_id(D_5876, D_5878);
        if (*pbVar3 == 0x97)
        {
            *pbVar3 = 0xb8;
        }
        else if (*pbVar3 != 0x98)
        {
            return 0;
        }
        else
        {
            *pbVar3 = 0xba;
        }

        D_24e6 |= 2;
        uVar2 = 1;
    }

    return uVar2;
}

// NOT MATCHING
int F_CAST2_07bc(int param_1)
{
    int iVar1;
    byte* pbVar2;
    int uVar3;

    if (D_5893_map_id < 0x80)
    {
        if (param_1 != 0)
        {
            F_CAST2_0000(4);
        }

        pbVar2 = &D_595a[D_5896_map_x + D_5897_map_y * 8 + D_5895_map_level * 0x40];
        if ((*pbVar2 & 0xf0) != 0x80)
        {
            pbVar2 = &D_595a[((D_5896_map_x + D_24d6[D_6603]) & 7) + ((D_5897_map_y + D_24de[D_6603]) & 7) * 8 +
                             D_5895_map_level * 0x40];
        }

        if ((*pbVar2 & 0xf0) == 0x80)
        {
            *pbVar2 &= 8;
            FUN_1000_1850_print_string(/*0x954c*/ "Field destroyed!\n");
            uVar3 = -1;
        }
        else
        {
            uVar3 = 0;
        }
    }
    else
    {
        iVar1 = F_CAST2_0306();
        if (iVar1 == 0)
        {
            uVar3 = -1;
        }
        else
        {
            if (param_1 != 0)
            {
                F_CAST2_0000(4);
            }

            uVar3 = 0;
            for (iVar1 = 0; iVar1 < 0x20; iVar1++)
            {
                if ((D_5c5a[iVar1]._0_tile & 0xfc) == 0xe8 && D_5876 == D_5c5a[iVar1]._2_x &&
                    D_5878 == D_5c5a[iVar1]._3_y)
                {
                    FUN_1000_3a74(0, 0, 0, 0, 0, 0, iVar1);
                    return 1;
                }
            }
        }
    }

    return uVar3;
}

// NOT MATCHING
void F_CAST2_08ea(int param_1) { D_58a6 = param_1; }

// NOT MATCHING
void F_CAST2_08f8(int param_1, int param_2, int param_3)
{
    D_587a = param_1;
    D_588e = param_2;

    F_CAST2_0000(param_3);

    FUN_1000_2900_update_vitals();
}

// NOT MATCHING
void F_CAST2_0914(int param_1)
{
    int iVar1;
    uint uVar2;

    uVar2 = D_4b95[param_1];
    if (param_1 > 0)
    {
        for (iVar1 = 0; iVar1 != param_1; iVar1++)
        {
            FUN_1000_3a74(3, 3, D_4b9e[uVar2], D_4bc2[uVar2], D_5895_map_level, 0, iVar1 + 1);
            uVar2++;
        }
    }
}

// NOT MATCHING
void F_CAST2_0966(void)
{
    bool bVar1;
    int iVar2;
    int iVar3;
    byte bVar4;
    int local_4;
    int iVar5;
    bool bVar6;

    bVar1 = 0;
    for (iVar5 = 0; iVar5 < 8; iVar5 = iVar5 + 1)
    {
        if (D_5896_map_x == D_1f6e[iVar5] && D_5897_map_y == D_1f76[iVar5])
            break;
    }

    if (iVar5 == 8)
    {
        iVar5 = 6;
    }

    D_5c5a[0]._1 = 0x6c;
    D_5c5a[0]._0_tile = 0x6c;
    FUN_1000_5910_update_map();
    FUN_1000_1850_print_string((char*)&D_b21e[0x36d]);
    FUN_1000_3ae6(10);
    FUN_1000_1850_print_string((char*)&D_b21e[0x398]);

    FUN_1000_3b1c_get_string(D_bd08, 0xc);

    if (D_bd08[0] == '\0')
    {
        return;
    }

    iVar2 = FUN_1000_6f1e(D_4b3e[iVar5], D_bd08);
    bVar6 = iVar2 != -1;
    FUN_1000_3ae6(6);
    FUN_1000_16ba_print_char(10);
    for (iVar2 = 0; iVar2 < 3; iVar2++)
    {
        FUN_1000_1850_print_string(/*0x958e*/ "\nMantra:");
        FUN_1000_3b1c_get_string(D_bd08, 0xc);
        if (D_bd08[0] == '\0')
        {
            return;
        }

        iVar3 = FUN_1000_6f1e(D_1f5e[iVar5], D_bd08);
        if (iVar3 == -1)
        {
            bVar6 = 0;
        }

        FUN_1000_3ae6(0xc);
    }

    FUN_1000_16ba_print_char(10);
    if (bVar6)
    {
        bVar4 = (byte)iVar5;
        if ((D_58ce & 1 << (bVar4 & 0x1f)) == 0)
        {
            D_58cc |= 1 << (bVar4 & 0x1f);
            FUN_1000_1850_print_string((char*)&D_b21e[0x3e1]);

            D_5c5a[0]._0_tile = D_5c5a[0]._1 = 0x1c;

            FUN_1000_266c_get_ch();
            FUN_1000_1850_print_string((char*)&D_b21e[0x40e]);
            FUN_1000_1850_print_string((char*)&D_b21e[D_4b5e[iVar5]]);
            FUN_1000_1850_print_string(/*0x9598*/ "\"\n");
            FUN_1000_266c_get_ch();
            FUN_1000_1850_print_string((char*)&D_b21e[0x44b]);

            for (iVar5 = 0; iVar5 < 7; iVar5 = iVar5 + 1)
            {
                FUN_1000_2192_audio_some_noise(D_4be6[iVar5], 1, D_4bf4[iVar5], D_4c02[iVar5], D_4c10[iVar5]);
            }
        }
        else if ((D_58cc & (1 << (bVar4 & 0x1f))) == 0)
        {
            while (!bVar1)
            {
                FUN_1000_1850_print_string((char*)&D_b21e[0x474]);
                do
                {
                    do
                    {
                        iVar5 = FUN_1000_266c_get_ch();
                    } while (iVar5 < 0x30);
                } while (0x39 < iVar5);

                FUN_1000_16ba_print_char(iVar5);
                local_4 = iVar5 - 0x30;
                if (local_4 == 0)
                {
                    FUN_1000_1850_print_string(/*0x959c*/ " gp\n");
                    return;
                }

                FUN_1000_1850_print_string(/*0x95a2*/ "00 gp\n\n");
                if ((int)D_57aa < local_4 * 100)
                {
                    FUN_1000_1850_print_string((char*)&D_b21e[0x49b]);
                }
                else
                {
                    bVar1 = 1;
                }
            }

            D_57aa += (short)local_4 * -100;
            FUN_1000_2900_update_vitals();
            D_5888 += (char)local_4;
            if (D_5888 > 99)
            {
                D_5888 = 99;
            }

            FUN_1000_1c9e_set_charset(1);
            FUN_1000_1850_print_string(/*0x95aa*/ "ALAKAZAM");
            FUN_1000_1c9e_set_charset(0);
            FUN_1000_1850_print_string(/*0x95b4*/ "!\n");
            FUN_1000_0a70_set_pen_color(D_13b0_white_color);
            FUN_1000_0b86(8, 8, 0xb7, 0xb7);

            for (iVar5 = 2000; iVar5 < 25000; iVar5 = iVar5 + 0x32)
            {
                FUN_1000_2192_audio_some_noise(0xa8c, 1, 200, iVar5, 0);
            }

            for (iVar5 = 25000; 2000 < iVar5; iVar5 = iVar5 + -0x32)
            {
                FUN_1000_2192_audio_some_noise(0xa8c, 1, 200, iVar5, 0);
            }
        }
        else
        {
            D_58cc &= ~(1 << (bVar4 & 0x1f) & D_58cc);
            FUN_1000_1850_print_string((char*)&D_b21e[0x4b9]);
            FUN_1000_0a70_set_pen_color(D_13b0_white_color);
            FUN_1000_0b86(8, 8, 0xb7, 0xb7);

            for (iVar2 = 2000; iVar2 < 25000; iVar2 = iVar2 + 0x32)
            {
                FUN_1000_2192_audio_some_noise(0xc1c, 1, 0x96, iVar2, 0);
            }

            for (iVar2 = 25000; 2000 < iVar2; iVar2 = iVar2 + -0x32)
            {
                FUN_1000_2192_audio_some_noise(0xc1c, 1, 0x96, iVar2, 0);
            }

            FUN_1000_3072();
            D_5888 += 3;
            if (D_5888 > 99)
            {
                D_5888 = 99;
            }

            if (D_4b7e[iVar5] != 0)
            {
                D_55a8_party[0]._c++;
                if (D_55a8_party[0]._c > 0x1e)
                {
                    D_55a8_party[0]._c = 0x1e;
                }

                FUN_1000_1850_print_string(/*0x95b8*/ "Strength +1\n");
            }

            if (D_4b86[iVar5] != 0)
            {
                D_55a8_party[0]._d++;
                if (D_55a8_party[0]._d > 0x1e)
                {
                    D_55a8_party[0]._d = 0x1e;
                }

                FUN_1000_1850_print_string(/*0x95c6*/ "Dexterity +1\n");
            }

            if (D_4b8e[iVar5] != 0)
            {
                D_55a8_party[0]._e++;
                if (D_55a8_party[0]._e > 0x1e)
                {
                    D_55a8_party[0]._e = 0x1e;
                }

                FUN_1000_1850_print_string(/*0x95d4*/ "Intelligence +1\n");
            }

            if (iVar5 == 7)
            {
                D_5888 += 3;
                if (D_5888 > 99)
                {
                    D_5888 = 99;
                }
            }
        }

        FUN_1000_3ae6(10);
    }
    else
    {
        FUN_1000_1850_print_string((char*)&D_b21e[0x3c0]);
    }
}

// NOT MATCHING
void F_CAST2_0d24(void)
{
    int iVar1;

    FUN_1000_266c_get_ch();
    FUN_1000_1850_print_string((char*)&D_b21e[0x4e5]);
    FUN_1000_266c_get_ch();
    FUN_1000_1850_print_string((char*)&D_b21e[0x515]);
    FUN_1000_266c_get_ch();

    for (iVar1 = 0; iVar1 < 8; iVar1++)
    {
        if ((D_58cc & (1 << ((byte)iVar1 & 0x1f))) != 0)
            break;
    }

    if (iVar1 == 8)
    {
        FUN_1000_1850_print_string((char*)&D_b21e[0x53e]);
    }
    else
    {
        D_58ce |= 1 << ((byte)iVar1 & 0x1f);

        FUN_1000_16ba_print_char(0x22);
        FUN_1000_1850_print_string((char*)&D_b21e[D_4b6e[iVar1]]);
        FUN_1000_1850_print_string(/*0x95e6*/ "\"\n\n");
        FUN_1000_266c_get_ch();

        if ((byte)D_58ce == 0xff)
        {
            FUN_1000_0a70_set_pen_color(D_13ae);
            FUN_1000_0b86(8, 8, 0xb7, 0xb7);
            FUN_1000_3072();
            FUN_1000_0a70_set_pen_color(D_13b0_white_color);
            FUN_1000_0b86(8, 8, 0xb7, 0xb7);
            FUN_1000_3072();
            FUN_1000_0a70_set_pen_color(D_13ae);
            FUN_1000_0b86(8, 8, 0xb7, 0xb7);
            FUN_1000_3072();
            FUN_1000_1850_print_string((char*)&D_b21e[0x555]);
            FUN_1000_266c_get_ch();
            FUN_1000_1850_print_string(/*0x95ea*/ "Thou dost read:\n\n");
            FUN_1000_1c9e_set_charset(1);
            FUN_1000_1850_print_string((char*)&D_b21e[0x57f]);
            FUN_1000_1c9e_set_charset(0);
            FUN_1000_266c_get_ch();
            FUN_1000_1c9e_set_charset(1);
            FUN_1000_1850_print_string((char*)&D_b21e[0x5d1]);
            FUN_1000_1c9e_set_charset(0);
            FUN_1000_266c_get_ch();
            FUN_1000_1c9e_set_charset(1);
            FUN_1000_1850_print_string((char*)&D_b21e[0x60c]);
            FUN_1000_1c9e_set_charset(0);
            FUN_1000_266c_get_ch();
            FUN_1000_1c9e_set_charset(1);
            FUN_1000_1850_print_string((char*)&D_b21e[0x680]);
            FUN_1000_1c9e_set_charset(0);
            FUN_1000_266c_get_ch();
        }
    }
    return;
}

// OK P1
void F_CAST2_0e64(void)
{
    FUN_1000_3ae6(1);
    FUN_1000_433e_audio_some_noise();
    FUN_1000_3ae6(4);
}

// NOT MATCHING
void F_CAST2_0e76(void)
{
    byte cVar3;
    int uVar6;
    int iVar9;
    int iVar11;
    int local_16;
    int i;

    cVar3 = *FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y);
    D_24e6 = 1;
    D_bd15 = D_5893_map_id;
    D_5893_map_id = 0xff;
    D_589e = 0xff;

    for (i = 0; i < 0x20; i++)
    {
        memcpy(&D_a9fc[i], &D_5c5a[i], sizeof(ActorFmt));
        D_5c5a[i]._0_tile = 0;
    }

    if (cVar3 != 0x11)
    {
        FUN_1000_256e_read_file_from_disk(/*0x95fc*/ "MISCMAPS.DAT", D_ac64, 0xb0, 0xb0);
    }
    else
    {
        FUN_1000_256e_read_file_from_disk(/*0x960a*/ "MISCMAPS.DAT", D_ac64, 0xb0, 0x160);
    }

    FUN_1000_256e_read_file_from_disk(/*0x9618*/ "MISCMSG.DAT", D_b21e, 2000, 0x3ab);

    for (iVar11 = 0; iVar11 < 0xb; iVar11++)
    {
        for (iVar9 = 0; iVar9 < 0xb; iVar9++)
        {
            D_ad14[iVar11 * 0x20 + iVar9] = D_ac64[iVar11 * 0x10 + iVar9];
        }
    }

    FUN_1000_5910_update_map();

    iVar9 = 0;
    for (i = 1; i < 0x10; i++)
    {
        if (D_55a8_party[i]._1f == 0x7f)
        {
            iVar9++;
        }
    }

    if (iVar9 > 0)
    {
        F_CAST2_0914(iVar9);
    }

    if (cVar3 != 0x11)
    {
        FUN_1000_1850_print_string((char*)&D_b21e[0x6ae]);
    }
    else
    {
        FUN_1000_1850_print_string((char*)&D_b21e[0x6db]);
    }

    for (iVar11 = 0; iVar11 < 4; iVar11++)
    {
        F_CAST2_0e64();
    }

    D_5c5a[0]._0_tile = D_5c5a[0]._1 = 0x1c;
    D_5c5a[0]._2_x = 5;
    D_5c5a[0]._3_y = 10;
    D_5c5a[0]._4_z = D_5895_map_level;

    F_CAST2_0e64();
    if (cVar3 == 0x11 && iVar9 > 0)
    {
        FUN_1000_1850_print_string(/*0x9624*/ "\n\nThou dost see\n");
        if (iVar9 == 1)
        {
            FUN_1000_1850_print_string(/*0x9636*/ "an urn marked:\n\n");
        }
        else
        {
            FUN_1000_1850_print_string(/*0x9648*/ "urns marked:\n\n");
        }

        for (local_16 = 1; local_16 < 0x10; local_16++)
        {
            if (D_55a8_party[local_16]._1f == 0x7f)
            {
                iVar9 = 0;
                while (D_55a8_party[local_16]._0[iVar9] != '\0')
                {
                    uVar6 = FUN_1000_2032_to_upper(D_55a8_party[local_16]._0[iVar9++]);
                    FUN_1000_16ba_print_char(uVar6);
                }

                FUN_1000_16ba_print_char(10);
            }
        }
    }

    if (cVar3 == 0x11)
    {
        iVar9 = 7;
    }
    else
    {
        iVar9 = 4;
    }

    for (; iVar9 != 0; iVar9--)
    {
        D_5c5a[0]._3_y--;
        F_CAST2_0e64();
    }

    if (cVar3 == 0x11)
    {
        F_CAST2_0d24();
    }
    else
    {
        F_CAST2_0966();
    }

    D_5c5a[0]._0_tile = D_5c5a[0]._1 = 0x1c;
    FUN_1000_3ae6(1);
    for (iVar9 = D_5c5a[0]._3_y; iVar9 < 10; iVar9++)
    {
        D_5c5a[0]._3_y++;
        F_CAST2_0e64();
    }

    D_5c5a[0]._0_tile = D_5c5a[0]._2_x = D_5c5a[0]._3_y = 0;

    for (iVar9 = 0; iVar9 < 4; iVar9++)
    {
        F_CAST2_0e64();
    }

    FUN_1000_3ae6(10);

    for (i = 0; i < 0x20; i++)
    {
        memcpy(&D_5c5a[i], &D_a9fc[i], sizeof(ActorFmt));
    }

    D_5893_map_id = D_bd15;
    FUN_1000_4f7c(0x10);
    FUN_1000_5e4a();
}

// NOT MATCHING
// NOTE: IBM version; not compatible with modern platforms
void F_CAST2_10fe_save_game_IBMPC(void)
{
    byte bVar1;
    char cVar2;

    FUN_1000_1850_print_string(/*0x9658*/ "\nSave game? ");
    do
    {
        cVar2 = FUN_1000_266c_get_ch();
        if (cVar2 == 'Y')
            break;
    } while (cVar2 != 'N');

    if (cVar2 == 'N')
    {
        FUN_1000_1850_print_string(/*0x9666*/ "No\n");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x966a*/ "Yes\nSaving...\n");
        bVar1 = D_a9bd;
        if (D_a9bd != 5)
        {
            FUN_1000_251e_switch_disks(1);
        }

        FUN_1000_256e_read_file_from_disk(/*0x967a*/ "UNDER.OOL", D_b21e + 0x100, 0x100, 0);
        FUN_1000_251e_switch_disks(1);
        FUN_1000_256e_read_file_from_disk(/*0x9684*/ "BRIT.OOL", D_b21e, 0x100, 0);
        if (bVar1 != 1)
        {
            FUN_1000_25d8_write_file_to_disk(/*0x968e*/ "UNDER.OOL", D_b21e + 0x100, 0x100);
        }

        FUN_1000_251e_switch_disks(3);
        FUN_1000_25d8_write_file_to_disk(/*0x9698*/ "SAVED.GAM", &D_55a6, 0x1060);
        FUN_1000_25d8_write_file_to_disk(/*0x96a2*/ "SAVED.OOL", D_b21e, 0x200);
        FUN_1000_251e_switch_disks(bVar1);
        FUN_1000_1850_print_string(/*0x96ac*/ "Done.\n");
    }
}

// NOT MATCHING
// based on FMT
void F_CAST2_10fe_save_game_FMT(void)
{
    byte bVar1;
    char cVar2;
    void* local_c;

    FUN_1000_1850_print_string(/*0x4c114*/ "\nSave game? ");
    do
    {
        cVar2 = FUN_1000_266c_get_ch();
        if (cVar2 == 'Y')
            break;
    } while (cVar2 != 'N');

    if (cVar2 == 'N')
    {
        FUN_1000_1850_print_string(/*0x4c124*/ "No\n");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x4c128*/ "Yes\nSaving...\n");
        bVar1 = D_a9bd;
        if (D_a9bd != 5)
        {
            FUN_1000_251e_switch_disks(1);
        }

        FUN_1000_256e_read_file_from_disk(/*0x4c138*/ "UNDER.OOL", D_b21e + 0x100, 0x100, 0);
        FUN_1000_251e_switch_disks(1);
        FUN_1000_256e_read_file_from_disk(/*0x4c144*/ "BRIT.OOL", D_b21e, 0x100, 0);
        if (bVar1 != 1)
        {
            FUN_1000_251e_switch_disks(3);
            FUN_1000_25d8_write_file_to_disk(/*0x4c150*/ "UNDER.OOL", D_b21e + 0x100, 0x100);
        }

        // DAT_0003ddb0_55a6 = (byte)DAT_00065334; // ?
        // DAT_0003ee18_6606 = (byte)DAT_00065338; // ?

        FUN_1000_251e_switch_disks(3);
        FILE_WriteSavegameFile(/*0x4c15c*/ "SAVED.GAM" /*, local_c*/);
        FUN_1000_25d8_write_file_to_disk(/*0x4c168*/ "SAVED.OOL", D_b21e, 0x200);
        FUN_1000_251e_switch_disks(bVar1);
        FUN_1000_1850_print_string(/*0x4c174*/ "Done.\n");
    }
}

void F_CAST2_10fe_save_game(void)
{
    F_CAST2_10fe_save_game_FMT();
}
