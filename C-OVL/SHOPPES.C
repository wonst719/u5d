#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// OK P1
char* F_SHOPPES_0000(char* param_1, char* param_2)
{
    while (*param_1 = *param_2++)
    {
        param_1++;
    }

    return param_1;
}

// OK P1
void F_SHOPPES_0026(char* param_1)
{
    byte local_e;
    char local_c[6];
    char* local_6;
    char* local_4;

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
            local_4 = F_SHOPPES_0000(local_4, param_1);
            *local_6 = local_e;
            param_1 = local_6 + 1;
        }

        // 00a4
        local_6++;

        if (local_e >= 0x80)
        {
            // 00ab
            *local_4++ = 0x20;
            local_4 = F_SHOPPES_0000(local_4, D_24ea[local_e - 0x80]);
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
            case 0x23:
                // 0056
                local_4 = F_SHOPPES_0000(local_4, D_aafc); // 3ef24
                break;

            case 0x24:
                // 00d0
                local_4 = F_SHOPPES_0000(local_4, D_aafe); // 3ef28
                continue;

            case 0x40:
                // 00d8
                if (D_587f < 0xc)
                {
                    local_4 = F_SHOPPES_0000(local_4, /*0x7826*/ "morning");
                }
                else if (D_587f < 0x12)
                {
                    local_4 = F_SHOPPES_0000(local_4, /*0x782e*/ "afternoon");
                }
                else
                {
                    local_4 = F_SHOPPES_0000(local_4, /*0x7838*/ "evening");
                }
                break;

            case 0x25:
                // 00fc
                FUN_1000_0426_itoa(D_b118, local_c, 10);
                local_4 = F_SHOPPES_0000(local_4, local_c);
                break;

            case 0x5e:
                // 0114
                FUN_1000_0426_itoa(D_b11a, local_c, 10);
                local_4 = F_SHOPPES_0000(local_4, local_c);
                break;

            case 0x26:
                // 0122
                local_4 = F_SHOPPES_0000(local_4, D_ab00);
                break;

            case 0x2a:
                // 012a
                local_4 = F_SHOPPES_0000(local_4, D_ac62);
                break;
            }
        }
    }

    // 014a
    strcpy(local_4, param_1);

    FUN_1000_1850_print_string(D_b7fa);
}

// OK P1
void F_SHOPPES_017a(int param_1)
{
    FUN_1000_256e_read_file_from_disk(/*0x7840*/ "SHOPPE.DAT", D_b21e, 1500, param_1);
    F_SHOPPES_0026(D_b21e);
}

// OK P1
void F_SHOPPES_019a(void)
{
    if (D_5958 == 0)
    {
        // FMT: int local_8 = D_57aa;
        // 3f54(&local_8)
        // D_57aa = local_8
        FUN_1000_3f54(&D_57aa, FUN_1000_2092_random_range(1, 0x40));
    }
}

// NOT MATCHING (address calculation)
void F_SHOPPES_01b6(void)
{
    FUN_1000_16ba_print_char(0x22);
    F_SHOPPES_017a(D_3b2a[D_b116 * 4 + FUN_1000_2092_random_range(0, 3)]);
    //F_SHOPPES_017a(*(u16*)((byte*)D_3b2a + (D_b116 * 8 + FUN_1000_2092_random_range(0, 3) * 2)));

    if (FUN_1000_1f12_get_current_text_column() > 0xb)
    {
        FUN_1000_1850_print_string(/*0x784c*/ "\n\n:");
    }
    else if (FUN_1000_1f12_get_current_text_column() == 0)
    {
        FUN_1000_1850_print_string(/*0x7850*/ "\n:");
    }
    else
    {
        FUN_1000_16ba_print_char(0x20);
    }
}

// NOT MATCHING (address calculation)
void F_SHOPPES_0202(int param_1)
{
    if (param_1 == 0)
    {
        FUN_1000_1850_print_string(/*0x7854*/ "\n\n\"");
        F_SHOPPES_017a(D_3b6a[D_b116 * 4 + FUN_1000_2092_random_range(0, 3)]);
    }
    else if (param_1 == 1)
    {
        FUN_1000_1850_print_string(/*0x7858*/ "\n\n\"");
        F_SHOPPES_017a(D_3baa[D_b116 * 4 + FUN_1000_2092_random_range(0, 3)]);
    }

    if (param_1 == 0 || param_1 == 1)
    {
        if (FUN_1000_1f12_get_current_text_column() != 0)
        {
            FUN_1000_16ba_print_char(10);
        }

        F_SHOPPES_0026(/*0x785c*/ "says $.\n");
    }
}

// NOT MATCHING
int F_SHOPPES_0280(void)
{
    int local_4;

    do
    {
        local_4 = FUN_1000_266c_get_ch();
        if (local_4 == 0x4e)
        {
            FUN_1000_1850_print_string(/*0x7866*/ "No");
        }
        else if (local_4 == 0x59)
        {
            FUN_1000_1850_print_string(/*0x786a*/ "Yes");
        }
    } while (local_4 != 0x4e && local_4 != 0x59);

    return local_4;
}

void F_SHOPPES_04a2(int param_1) { printf("F_SHOPPES_04a2(%d)\n", param_1); }

void F_SHOPPES_075e(int param_1) { printf("F_SHOPPES_075e(%d)\n", param_1); }

void F_SHOPPES_07be(int param_1) { printf("F_SHOPPES_07be(%d)\n", param_1); }

void F_SHOPPES_12b2(int param_1) { printf("F_SHOPPES_12b2(%d)\n", param_1); }

void F_SHOPPES_14f8(int param_1) { printf("F_SHOPPES_14f8(%d)\n", param_1); }
