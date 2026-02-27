#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void F_CAST2_05e0(int a, int b);

int F_ZSTATS_056c(int param_3, int notused, byte* param_2, int param_1);

int F_ZSTATS_05a4(int param_4, int param_3, byte* param_2, int param_1);

void F_ZSTATS_05e2(int param_4, byte* param_3, char** param_2, uint param_1);

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
            case 0x23: // '#'
                // 0056
                local_4 = F_SHOPPES_0000(local_4, D_aafc); // 3ef24
                break;

            case 0x24: // '$'
                // 00d0
                local_4 = F_SHOPPES_0000(local_4, D_aafe); // 3ef28
                continue;

            case 0x40: // '('
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

            case 0x25: // '%'
                // 00fc
                FUN_1000_0426_itoa(D_b118, local_c, 10);
                local_4 = F_SHOPPES_0000(local_4, local_c);
                break;

            case 0x5e: // '^'
                // 0114
                FUN_1000_0426_itoa(D_b11a, local_c, 10);
                local_4 = F_SHOPPES_0000(local_4, local_c);
                break;

            case 0x26: // '&'
                // 0122
                local_4 = F_SHOPPES_0000(local_4, D_ab00);
                break;

            case 0x2a: // '*'
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
    // F_SHOPPES_017a(*(u16*)((byte*)D_3b2a + (D_b116 * 8 + FUN_1000_2092_random_range(0, 3) * 2)));

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

// NOT MATCHING
int F_SHOPPES_02ba(int param_1, int param_2, int param_3)
{
    char cVar2;

    ASSERT(param_2 < 3); // ?
    ASSERT(D_b114 < 4); // ?

    D_b118 = D_3bea[D_b114 * 4 + param_2];
    D_b118 += (s16)((s32)D_b118 * -(D_55a8_party[param_1]._e * 3 - 100) / 100);

    FUN_1000_1850_print_string(/*0x786e*/ "\n\n\"");
    F_SHOPPES_017a(D_3c0a[param_2]);
    FUN_1000_1850_print_string(/*0x7872*/ "\n\nInterested?\" ");

    do
    {
        cVar2 = FUN_1000_266c_get_ch();
        if (cVar2 == 'N')
        {
            FUN_1000_1850_print_string(/*0x7882*/ "No\n\n\"What else, then?\n\n");
        }
        else if (cVar2 == 'Y')
        {
            FUN_1000_1850_print_string(/*0x789a*/ "Yes\n");
            if (D_b118 > D_57aa)
            {
                F_SHOPPES_017a(D_21e6); // TODO: ???
                param_3 = -1;
            }
            else
            {
                D_57aa -= D_b118;
                F_SHOPPES_019a();
                FUN_1000_2900_update_vitals();
                if (param_2 == 0)
                {
                    FUN_1000_3ef0(&D_57ac, 3, 99);
                }
                else
                {
                    if (param_2 == 1)
                    {
                        FUN_1000_3ef0(&D_57ad, 4, 99);
                    }

                    if (param_2 == 2)
                    {
                        FUN_1000_3ef0(&D_57ae, 5, 99);
                    }
                }

                param_3 = 1;
                F_SHOPPES_0026(/*0x78a0*/ "\n\"Sold!\"\nsays $.\n\n\"What else, \n");
                if (D_55a8_party[param_1]._9 == 12)
                {
                    FUN_1000_1850_print_string(/*0x78c0*/ "m'lady");
                }
                else
                {
                    FUN_1000_1850_print_string(/*0x78c8*/ "m'lord");
                }

                FUN_1000_1850_print_string(/*0x78d0*/ "?\n\n");
            }
        }

        if (cVar2 == 'N' || cVar2 == 'Y')
        {
            return param_3;
        }
    } while (1);
}

// NOT MATCHING
int F_SHOPPES_03f6(int param_1)
{
    bool bVar1;
    int local_8;
    byte local_4;

    bVar1 = 0;
    local_8 = 0;
    do
    {
        if (bVar1)
        {
            return local_8;
        }

        FUN_1000_1850_print_string(/*0x78d4*/ "a.........Keys\n");
        FUN_1000_1850_print_string(/*0x78e4*/ "b.........Gems\n");
        FUN_1000_1850_print_string(/*0x78f4*/ "c......Torches\n\n");
        FUN_1000_1850_print_string(/*0x7906*/ "Thy concern?\" ");

        do
        {
            local_4 = FUN_1000_266c_get_ch();
            switch (local_4)
            {
            case 0x1b:
            case 0x20:
                bVar1 = 1;
                break;

            case 0x41:
            case 0x42:
            case 0x43:
                FUN_1000_16ba_print_char(local_4 | 0x20);
                local_8 = F_SHOPPES_02ba(param_1, local_4 - 0x41, local_8);
                if (local_8 == -1)
                    bVar1 = 1;
                break;

            case 0x44:
                F_SHOPPES_017a(8725); // offset: 0x2215
                break;

            default:
                local_4 = 0;
                break;
            }
        } while (local_4 == 0 && !bVar1);
    } while (1);
}

// NOT MATCHING
void F_SHOPPES_04a2(int param_1)
{
    bool bVar1;
    char cVar2;
    int uVar3;

    uVar3 = 0;
    F_SHOPPES_01b6();
    bVar1 = 0;
    do
    {
        cVar2 = FUN_1000_266c_get_ch();
        if (cVar2 != ' ' && cVar2 != 'N')
        {
            if (cVar2 == 'Y')
            {
                FUN_1000_1850_print_string(/*0x7916*/ "Yes\n\n\"We sell:\n\n");
                uVar3 = F_SHOPPES_03f6(param_1);
                bVar1 = 1;
            }
        }
        else
        {
            FUN_1000_1850_print_string(/*0x7928*/ "No");
            bVar1 = 1;
        }

        if (bVar1)
        {
            F_SHOPPES_0202(uVar3);
            return;
        }
    } while (1);
}

// NOT MATCHING
int F_SHOPPES_0502(int param_1, int param_2, int param_3)
{
    char cVar2;
    int iVar4;
    int iVar5;

    iVar5 = 0;
    for (iVar4 = 0; iVar4 < 8; iVar4++)
    {
        if (D_3a32[D_b114 * 8 + iVar4] != 0)
        {
            if (iVar5 == param_2)
                break;

            iVar5++;
        }
    }

    if (iVar4 == 8)
    {
        param_3 = -2;
    }
    else if (D_5850[iVar4] == 99)
    {
        FUN_1000_1850_print_string(/*0x792c*/ "\n\n\"Thou canst not carry any more!\"\n\n");
        FUN_1000_266c_get_ch();
    }
    else
    {
        //iVar6 = D_b114 * 8 + iVar4;
        //D_b118 = (uint)D_3a32[iVar6];
        //uVar8 = 0;
        //uVar1 = (uint)D_55a8_party[param_1]._e * 3;
        //iVar5 = uVar1 - 100;
        //uVar7 = FUN_1000_0442(D_b118 >> 0xf, D_b118, -((uint)(iVar5 != 0) - (uint)(uVar1 < 100)), -iVar5);
        //iVar5 = FUN_1000_03a0(0, 100, 0, (int)((ulong)uVar7 >> 0x10));
        //    iVar5 = uVar7 / 100;
        //D_b118 = D_b118 + iVar5;
        //D_b11a = (uint) * (iVar6 + D_3a5a);

        D_b118 = D_3a32[D_b114 * 8 + iVar4];
        D_b118 += ((s32)D_b118 * -(D_55a8_party[param_1]._e * 3 - 100)) / 100;
        D_b11a = D_3a5a[D_b114 * 8 + iVar4];

        FUN_1000_1850_print_string(/*0x7952*/ "\n\n\"");
        //F_SHOPPES_0026(D_3c10[iVar4] + 0x97b7);
        F_SHOPPES_0026((char*)&D_b21e[((D_3c10[iVar4] + 0x97b7) - 0xb21e)]); // 0x97b7 + 0x1c1c - b21e = 0x1b5
        FUN_1000_1850_print_string(/*0x7956*/ " Is this thy need?\" ");
        if (FUN_1000_1f12_get_current_text_column() > 0xc)
        {
            FUN_1000_1850_print_string(/*0x796c*/ "\n:");
        }
        do
        {
            cVar2 = FUN_1000_266c_get_ch();
            if (cVar2 == 'N')
            {
                FUN_1000_1850_print_string(/*0x7970*/ "No\n\n\"What else?\n\n");
            }
            else if (cVar2 == 'Y')
            {
                FUN_1000_1850_print_string(/*0x7982*/ "Yes\n");
                if (D_b118 <= D_57aa)
                {
                    D_57aa -= D_b118;
                    F_SHOPPES_019a();
                    FUN_1000_2900_update_vitals();
                    FUN_1000_3ef0(&D_5850[iVar4], D_b11a, 99);
                    param_3 = 1;
                    F_SHOPPES_0026(/*0x7988*/ "\n\"I thank thee!\"\nsays $.\n");
                    FUN_1000_1850_print_string(/*0x79a2*/ "\"Anything else?\n\n");
                }
                else
                {
                    F_SHOPPES_0026(/*0xb6e2*/ "");
                    param_3 = -1;
                }
            }
        } while (cVar2 != 'N' && cVar2 != 'Y');
    }
    return param_3;
}

// NOT MATCHING
int F_SHOPPES_0666(int param_1)
{
    bool bVar1;
    int iVar2;
    int local_e;
    char local_c;
    int local_8;
    byte local_4;

    bVar1 = 0;
    local_e = 0;

    FUN_1000_256e_read_file_from_disk(/*0x7a0a*/ "SHOPPE.DAT", D_b21e, 1500, 6759); //offset: 0x1a67

    do
    {
        if (bVar1)
        {
            return local_e;
        }
        local_c = 'A';
        local_8 = 0;
        do
        {
            if (D_3a32[D_b114 * 8 + local_8] != 0) // size = max_b114 * 8 + 8
            {
                FUN_1000_16ba_print_char(local_c);
                FUN_1000_1850_print_string(/*0x7a16*/ "...");
                FUN_1000_1850_print_string(D_3c20[local_8]);
                FUN_1000_16ba_print_char(10);
                local_c++;
            }
            local_8++;
        } while (local_8 < 8);

        FUN_1000_1850_print_string(/*0x7a1a*/ "\nThy interest?\" ");

        do
        {
            local_4 = FUN_1000_266c_get_ch();

            switch (local_4)
            {
            case 0xd:
            case 0x1b:
            case 0x20:
                bVar1 = 1;
                iVar2 = local_e;
                break;

            case 0x41:
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
                iVar2 = F_SHOPPES_0502(param_1, local_4 - 0x41, local_e);
                if (iVar2 == -1)
                {
                    local_e = -1;
                    bVar1 = 1;
                    iVar2 = local_e;
                    break;
                }

                if (iVar2 == -2)
                {
                    local_4 = 0;
                    iVar2 = local_e;
                    break;
                }
                break;

            default:
                local_4 = 0;
                iVar2 = local_e;
                break;
            }

            local_e = iVar2;
        } while (local_4 == 0 && !bVar1);
    } while (1);
}

// NOT MATCHING
void F_SHOPPES_075e(int param_1)
{
    bool bVar1;
    char cVar2;
    int uVar3;

    uVar3 = 0;
    F_SHOPPES_01b6();
    bVar1 = 0;
    do
    {
        cVar2 = FUN_1000_266c_get_ch();
        if (cVar2 != ' ' && cVar2 != 'N')
        {
            if (cVar2 == 'Y')
            {
                FUN_1000_1850_print_string(/*0x7a2c*/ "Yes\n\n\"Fine! We sell:\n\n");
                uVar3 = F_SHOPPES_0666(param_1);
                bVar1 = 1;
            }
        }
        else
        {
            FUN_1000_1850_print_string(/*0x7a44*/ "No");
            bVar1 = 1;
        }

        if (bVar1)
        {
            F_SHOPPES_0202(uVar3);
            return;
        }
    } while (1);
}

// NOT MATCHING
void F_SHOPPES_07be(int param_1)
{
    bool bVar2;
    byte bVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int iVar8;
    int local_12;
    int local_c;

    for (iVar8 = 0; iVar8 < 32; iVar8++)
    {
        if (D_5c5a[0]._0_tile == 0)
            break;
    }

    for (local_c = 0; local_c < 4; local_c++)
    {
        iVar4 = D_3c38[local_c] + (uint)D_5896_map_x;
        iVar5 = D_3c40[local_c] + (uint)D_5897_map_y;
        bVar3 = *FUN_1000_4402_get_address_of_tile_id(iVar4, iVar5);
        iVar6 = FUN_1000_368e(iVar4, iVar5, D_5895_map_level);

        if (iVar6 == 0 && (bVar3 == 0x44 || bVar3 == 0x45 || bVar3 == 5))
            break;
    }

    if (local_c == 4 || iVar8 == 0x20)
    {
        FUN_1000_1850_print_string(/*0x7a48*/ "The stables are closed.\n");
    }
    else
    {
        bVar2 = 0;
        local_12 = 0;

        D_b118 = D_3c30[D_b114];
        D_b118 += (s32)D_b118 * -(D_55a8_party[param_1]._e * 3 - 100) / 100;

        F_SHOPPES_01b6();
        do
        {
            bVar3 = FUN_1000_266c_get_ch();
            if (bVar3 != ' ' && bVar3 != 'N')
            {
                if (bVar3 == 'Y')
                {
                    FUN_1000_1850_print_string(/*0x7a62*/ "Yes\n\n\"");
                    F_SHOPPES_017a(5699); // 0x1643
                    FUN_1000_1850_print_string(/*0x7a6a*/ "\n\nDeal?\" ");

                    do
                    {
                        bVar3 = FUN_1000_266c_get_ch();
                        if (bVar3 == 'Y')
                            break;
                    } while (bVar3 != 'N');

                    if (bVar3 == 'N')
                    {
                        FUN_1000_1850_print_string(/*0x7a74*/ "No");
                        bVar2 = 1;
                    }

                    FUN_1000_1850_print_string(/*0x7a78*/ "Yes!");
                    if (D_57aa < D_b118)
                    {
                        FUN_1000_1850_print_string(/*0x7a7e*/ "\n\n\"Thou couldst not afford to ");
                        F_SHOPPES_0026(/*0x7a9e*/ "feed it!\"\nyells $.\n");
                        local_12 = -1;
                    }
                    else
                    {
                        D_57aa -= D_b118;
                        F_SHOPPES_019a();

                        D_5c5a[iVar8]._5 = 0;
                        D_5c5a[iVar8]._7 = 0;
                        D_5c5a[iVar8]._6 = 0;
                        D_5c5a[iVar8]._1 = 0x10;
                        D_5c5a[iVar8]._0_tile = 0x10;
                        D_5c5a[iVar8]._2_x = iVar4;
                        D_5c5a[iVar8]._3_y = iVar5;
                        D_5c5a[iVar8]._4_z = D_5895_map_level;
                        FUN_1000_5910_update_map();
                        FUN_1000_2900_update_vitals();
                        local_12 = 1;
                    }
                    bVar2 = 1;
                }
            }
            else
            {
                FUN_1000_1850_print_string(/*0x7ab2*/ "No");
                bVar2 = 1;
            }
        } while (!bVar2);

        F_SHOPPES_0202(local_12);
    }
}

// NOT MATCHING
int F_SHOPPES_09ac(int param_1, int param_2, int param_3)
{
    char cVar2;

    D_b118 = D_3a82[param_2];
    D_b118 += (s32)D_b118 * -(D_55a8_party[param_1]._e * 3 - 100) / 100;

    FUN_1000_1850_print_string(/*0x7b5e*/ "\n\n\"");
    F_SHOPPES_017a(D_3c48[param_2]);
    FUN_1000_1850_print_string(/*0x7b62*/ "\n\n");
    FUN_1000_1850_print_string(D_3ca6[FUN_1000_2092_random_range(0, 3)]);
    FUN_1000_1850_print_string(/*0x7b66*/ "\" ");

    do
    {
        cVar2 = FUN_1000_266c_get_ch();
        if (cVar2 == 'N')
        {
            FUN_1000_1850_print_string(/*0x7b6a*/ "No\n\n");
        }
        else if (cVar2 == 'Y')
        {
            FUN_1000_1850_print_string(/*0x7b70*/ "Yes\n");
            if (D_57c0[param_2] == 99)
            {
                FUN_1000_1850_print_string(/*0x7b76*/ "\n\"Thou canst not carry any more!\"\n");
                F_SHOPPES_0026(/*0x7b9a*/ "says $.\n\n");
                FUN_1000_266c_get_ch();
            }
            else if (D_57aa < D_b118)
            {
                FUN_1000_1850_print_string(/*0x7ba4*/ "\n\"");
                FUN_1000_1850_print_string(D_3cae[FUN_1000_2092_random_range(0, 3)]);
                F_SHOPPES_0026(/*0x7ba8*/ "\"\nyells $.\n");
                param_3 = -1;
            }
            else
            {
                D_57aa -= D_b118;
                F_SHOPPES_019a();
                FUN_1000_2900_update_vitals();
                if (param_2 == 0x1b || param_2 == 0x1d)
                {
                    D_57c0[param_2] = 99;
                }
                else
                {
                    FUN_1000_3ef0(param_2 + D_57c0, 1, 99);
                }

                F_SHOPPES_0026(/*0x7bb4*/ "\nSold!\n");
                param_3 = 1;
            }
        }
    } while (cVar2 != 'N' && cVar2 != 'Y');

    if (param_3 != -1)
    {
        FUN_1000_1850_print_string(/*0x7bbc*/ "\"Anything else,\n");
        if (param_3 == 0)
        {
            FUN_1000_1850_print_string(/*0x7bdc*/ "then?");
        }
        else if (D_55a8_party[param_1]._9 == 12)
        {
            FUN_1000_1850_print_string(/*0x7bce*/ "milady?");
        }
        else
        {
            FUN_1000_1850_print_string(/*0x7bd6*/ "sir?");
        }
    }

    return param_3;
}

// NOT MATCHING
int F_SHOPPES_0b30(int param_1)
{
    bool bVar1;
    uint uVar2;
    int iVar3;
    int iVar4;
    int local_a;
    byte local_4;

    bVar1 = 0;
    local_a = 0;
    do
    {
        FUN_1000_1850_print_string(/*0x7c44*/ "\n\n");

        for (iVar4 = 0; iVar4 < 8; iVar4++)
        {
            uVar2 = D_3ae2[D_b114 * 8 + iVar4];
            if (uVar2 == 0xff)
                break;

            FUN_1000_16ba_print_char(iVar4 + 0x61);
            FUN_1000_1850_print_string(/*0x7c48*/ "...");

            if (FUN_1000_216c_strlen(D_17f6[uVar2]) < 0xd)
            {
                FUN_1000_1850_print_string(D_17f6[uVar2]);
            }
            else
            {
                FUN_1000_1850_print_string(D_1962[uVar2]);
            }

            if (FUN_1000_1f12_get_current_text_column() != 0)
            {
                FUN_1000_16ba_print_char(10);
            }
        }

        FUN_1000_16ba_print_char(10);
        FUN_1000_1850_print_string(D_3cb6[FUN_1000_2092_random_range(0, 3)]);
        FUN_1000_1850_print_string(/*0x7c4c*/ "\" ");

        do
        {
            local_4 = FUN_1000_266c_get_ch();
            iVar3 = local_4 - 0x41;
            if (iVar3 < iVar4 && -1 < iVar3)
            {
                FUN_1000_16ba_print_char(local_4 + 0x20);
                local_a = F_SHOPPES_09ac(param_1, D_3ae2[D_b114 * 8 + iVar3], local_a);
                if (local_a == -1)
                {
                    bVar1 = 1;
                }
            }
            else if (local_4 == 0x1b || local_4 == 0x20)
            {
                bVar1 = 1;
            }
            else
            {
                local_4 = 0;
            }
        } while (local_4 == 0 && !bVar1);

        if (bVar1)
        {
            return local_a;
        }
    } while (1);
}

// NOT MATCHING
int F_SHOPPES_0c58(void)
{
    int iVar1;

    for (iVar1 = 0; iVar1 < 0x30; iVar1++)
    {
        if (D_57c0[iVar1] != 0)
        {
            return 1;
        }
    }

    return 0;
}

// NOT MATCHING
int F_SHOPPES_0c80(int* param_1, int* param_2)
{
    int iVar2;
    int iVar3;
    int local_a;
    int local_8;
    int local_4;

    iVar3 = *param_2;
    if (D_57c0[iVar3] == 0)
    {
        if (*param_1 == iVar3)
        {
            iVar3 = F_ZSTATS_056c(iVar3, 0x30, D_57c0, 0xff);
            *param_2 = iVar3;
            if (iVar3 == -1)
            {
                iVar3 = F_ZSTATS_05a4(-1, 0x30, D_57c0, 0xff);
                *param_2 = iVar3;
            }
            iVar3 = *param_2;
        LAB_0000_0d3a:
            *param_1 = iVar3;
        }
        else
        {
            iVar3 = F_ZSTATS_05a4(*param_2, 0x30, D_57c0, 0xff);
            *param_2 = iVar3;
            if (iVar3 == -1)
            {
                iVar3 = F_ZSTATS_056c(0x30, 0x30, D_57c0, 0xff);
                *param_2 = iVar3;
                iVar3 = *param_1;
                iVar2 = F_ZSTATS_056c(iVar3, 0x30, D_57c0, 0xff);
                if (-1 < iVar2)
                {
                    iVar3 = F_ZSTATS_056c(iVar3, 0x30, D_57c0, 0xff);
                    goto LAB_0000_0d3a;
                }
            }
        }
    }

    FUN_1000_1b94_select_charset(1);
    FUN_1000_1bf2_set_text_cursor_position(1, 1);

    local_8 = *param_1;
    if (local_8 != -1)
    {
        iVar3 = *param_2;
        do
        {
            if (iVar3 == local_8)
            {
                FUN_1000_16ba_print_char(0xfd);
                local_4 = FUN_1000_1cee_get_current_text_row();
            }

            F_ZSTATS_05e2(local_8, D_57c0, D_1962, 0x2d);

            if (iVar3 == local_8)
            {
                FUN_1000_16ba_print_char(0xfd);
            }

            FUN_1000_1bf2_set_text_cursor_position(1, FUN_1000_1cee_get_current_text_row());
            if (FUN_1000_1cee_get_current_text_row() == 5)
                break;
            
            local_8 = F_ZSTATS_05a4(local_8, 0x30, D_57c0, 0xff);
        } while (local_8 != -1);
    }

    for (iVar3 = FUN_1000_1cee_get_current_text_row(); iVar3 != 5; iVar3 = iVar3 + 1)
    {
        FUN_1000_1bf2_set_text_cursor_position(1, iVar3);
        FUN_1000_1850_print_string(/*0x7c50*/ "             ");
    }

    local_a = 0;
    iVar3 = F_ZSTATS_056c(*param_1, 0x30, D_57c0, 0xff);
    if (iVar3 != -1)
    {
        local_a = 2;
    }

    if (local_8 != -1 && F_ZSTATS_05a4(local_8, 0x30, D_57c0, 0xff) != -1)
    {
        local_a++;
    }

    if (local_a == 0)
    {
        FUN_1000_4f3c();
    }
    else
    {
        FUN_1000_1bf2_set_text_cursor_position(6, 6);
        FUN_1000_4c2a();

        if (local_a == 1)
        {
            FUN_1000_16ba_print_char(0x19);
            FUN_1000_4cce();
        }
        else if (local_a == 2)
        {
            FUN_1000_16ba_print_char(0x18);
            FUN_1000_4cce();
        }
        else if (local_a == 3)
        {
            FUN_1000_16ba_print_char(0x12);
            FUN_1000_4cce();
        }
    }

    FUN_1000_1b94_select_charset(2);

    return local_4;
}

// NOT MATCHING
int F_SHOPPES_0e76(int param_1, int param_2)
{
    char cVar2;
    int uVar3;
    int iVar5;

    if (param_2 == 0x1b || param_2 == 0x1d)
    {
        F_SHOPPES_0026(/*0x7d32*/ "\n\n\"We don't deal in used ammunition!\"\ngrowls $.\n");
        uVar3 = 1;
    }
    else
    {
        FUN_1000_1850_print_string(/*0x7d64*/ "\n\n\"");
        if (D_3a82[param_2] != 0)
        {
            D_b118 = ((uint)D_55a8_party[param_1]._e * D_3a82[param_2] * 3) / 100 + 1;

            D_ab00 = D_3cce[param_2];
            if (D_3cce[param_2] == 0)
            {
                D_ab00 = D_17f6[param_2];
            }

            iVar5 = FUN_1000_2092_random_range(0, 7);
            //F_SHOPPES_0026(D_3cbe[iVar5] + 0xa65e);
            F_SHOPPES_0026((char*)&D_b21e[D_3cbe[iVar5] + 0xa65e - 0xb21e]);
            FUN_1000_1850_print_string(/*0x7d68*/ "\n\nDeal?\" ");
            do
            {
                cVar2 = FUN_1000_266c_get_ch();
                if (cVar2 == 'N')
                    break;
            } while (cVar2 != 'Y');

            if (cVar2 == 'N')
            {
                FUN_1000_1850_print_string(/*0x7d72*/ "No");
            }
            else
            {
                F_SHOPPES_0026(/*0x7d76*/ "Yes\n\n\"Done!\"\nsays $.");
                FUN_1000_3f14(&D_57aa, D_b118, 9999);
                FUN_1000_3f36(&D_57c0[param_2], 1);
            }
            FUN_1000_2884_update_gold();
        }
        else
        {
            F_SHOPPES_0026(/*0x7d8c*/ "That, I cannot buy from thee.\"\nsays $.");
        }

        uVar3 = 0;
    }

    return uVar3;
}

// NOT MATCHING
void F_SHOPPES_0f64(int param_1)
{
    int iVar1;
    int iVar2;
    int iVar4;
    int local_16;
    int local_12;
    int local_10;
    int local_e;
    int local_c;
    int local_a;
    byte local_8;
    int local_6;
    int local_4;

    if (F_SHOPPES_0c58() != 0)
    {
        FUN_1000_1850_print_string(D_3d2e[FUN_1000_2092_random_range(0, 3)]);
        FUN_1000_1850_print_string(/*0x7ef0*/ "\" ");
        FUN_1000_4e50(/*0x7ef4*/ "Arms");
        FUN_1000_1b94_select_charset(1);
        FUN_1000_1c22_set_text_window_size(1, 0x18, 1, 0x26, 6);
        FUN_1000_16ba_print_char(0xff);
        FUN_1000_1c22_set_text_window_size(1, 0x18, 1, 0x27, 9);
        FUN_1000_16ba_print_char(0x10);

        for (local_e = 0; local_e < 0xd; local_e++)
        {
            FUN_1000_16ba_print_char(0x11);
        }

        FUN_1000_16ba_print_char(0x13);

        for (local_e = 1; local_e < 5; local_e++)
        {
            FUN_1000_1bf2_set_text_cursor_position(0, local_e);
            FUN_1000_16ba_print_char(0x17);
            FUN_1000_1bf2_set_text_cursor_position(0xe, local_e);
            FUN_1000_16ba_print_char(0x17);
        }

        FUN_1000_16ba_print_char(10);
        FUN_1000_16ba_print_char(0x14);

        for (local_e = 0; local_e < 0xd; local_e++)
        {
            FUN_1000_16ba_print_char(0x15);
        }

        FUN_1000_16ba_print_char(0x16);

        local_10 = F_ZSTATS_05a4(-1, 0x30, D_57c0, 0xff);
        local_6 = local_10;
        local_c = F_SHOPPES_0c80(&local_6, &local_10);
        local_12 = 0;
        local_a = 0;

        FUN_1000_256e_read_file_from_disk(/*0x7efa*/ "SHOPPE.DAT", D_b21e, 1500, 3008); // offset: 0xbc0

        while (local_a == 0)
        {
            local_8 = FUN_1000_266c_get_ch();

            switch (local_8)
            {
            case 0x1b:
                local_a = 1;
                break;

            case 0xd:
            case 0x20:
                local_12 = F_SHOPPES_0e76(param_1, local_10);
                if (local_12 == 0 && F_SHOPPES_0c58() != 0)
                {
                    local_c = F_SHOPPES_0c80(&local_6, &local_10);
                    FUN_1000_1850_print_string(/*0x7f06*/ "\n\n\"");
                    FUN_1000_1850_print_string(D_3d3e[FUN_1000_2092_random_range(0, 3)]);
                    FUN_1000_1850_print_string(/*0x7f0a*/ "\" ");
                }
                else
                {
                    local_a = 1;
                }
                break;

            case 0xd3:
                local_6 = F_ZSTATS_05a4(-1, 0x30, D_57c0, 0xff);
                local_10 = local_6;
                local_c = F_SHOPPES_0c80(&local_6, &local_10);
                break;

            case 0xd4:
                local_10 = F_ZSTATS_056c(0x30, 0x30, D_57c0, 0xff);

                local_6 = local_10;
                for (iVar4 = 1; iVar4 < 4; iVar4++)
                {
                    iVar2 = F_ZSTATS_056c(local_6, 0x30, D_57c0, 0xff);
                    if (iVar2 == -1)
                        break;

                    local_6 = iVar2;
                }

                local_c = F_SHOPPES_0c80(&local_6, &local_10);
                break;

            case 0xd5:
            case 1:
            case 3:
                iVar1 = local_10;

                if (local_8 == 0xd5)
                {
                    local_4 = 4;
                }
                else
                {
                    local_4 = 1;
                }

                local_e = 0;
                iVar4 = local_e;
                if (local_4 != 0)
                {
                    local_16 = local_4;
                    local_e = local_4;
                    do
                    {
                        iVar2 = F_ZSTATS_056c(iVar1, 0x30, D_57c0, 0xff);
                        iVar4 = local_6;
                        if (iVar1 != local_6 || (iVar4 = iVar2, -1 < iVar2))
                        {
                            local_6 = iVar4;
                            iVar1 = iVar2;
                        }
                        local_16--;
                        iVar4 = local_e;
                    } while (local_16 != 0);
                }

                local_e = iVar4;
                local_10 = iVar1;
                local_c = F_SHOPPES_0c80(&local_6, &local_10);
                break;

            case 0xd6:
            case 2:
            case 4:
                iVar1 = local_10;

                if (local_8 == 0xd6)
                {
                    local_4 = 4;
                }
                else
                {
                    local_4 = 1;
                }

                local_e = 0;
                iVar4 = local_e;
                if (local_4 != 0)
                {
                    local_e = local_4;
                    iVar2 = local_4;
                    do
                    {
                        iVar1 = F_ZSTATS_05a4(local_10, 0x30, D_57c0, 0xff);
                        if (iVar1 > -1)
                        {
                            local_c++;
                            local_10 = iVar1;

                            if (local_c > 4)
                            {
                                local_6 = F_ZSTATS_05a4(local_6, 0x30, D_57c0, 0xff);
                            }
                        }
                        iVar2--;
                        iVar1 = local_10;
                        iVar4 = local_e;
                    } while (iVar2 != 0);
                }

                local_e = iVar4;
                local_10 = iVar1;
                local_c = F_SHOPPES_0c80(&local_6, &local_10);
                break;

            default:
                break;
            }
        }

        FUN_1000_2900_update_vitals();
        FUN_1000_4e20();

        if (local_12 != 0)
        {
            return;
        }

        FUN_1000_1850_print_string(/*0x7f0e*/ "\n\n\"");
        FUN_1000_1850_print_string(D_3d36[FUN_1000_2092_random_range(0, 3)]);
        FUN_1000_1850_print_string(/*0x7f12*/ "\"\n");

        if (F_SHOPPES_0c58() == 0)
        {
            return;
        }

        F_SHOPPES_0026(/*0x7f16*/ "says $.\n");
    }
    else
    {
        F_SHOPPES_0026(/*0x7f20*/ "Thou hast nothing to sell!\"\ngrowls $.\n");
    }
}

// NOT MATCHING
void F_SHOPPES_12b2(int param_1)
{
    char cVar1;
    int uVar3;

    uVar3 = 0;

    F_SHOPPES_0026(/*0x8018*/ "\"Good @, and welcome to #!\"\n");
    FUN_1000_266c_get_ch();
    F_SHOPPES_0026(/*0x8036*/ "\n$ says,\n\"");

    FUN_1000_1850_print_string(D_3d46[FUN_1000_2092_random_range(0, 1)]);
    FUN_1000_1850_print_string(/*0x8042*/ "\" ");

    do
    {
        cVar1 = FUN_1000_266c_get_ch();
        if (cVar1 != ' ') // switch?
        {
            if (cVar1 == 'B')
            {
                FUN_1000_1850_print_string(/*0x8046*/ "Buy\n\n\"");
                FUN_1000_1850_print_string(D_3d4a[FUN_1000_2092_random_range(0, 3)]);
                FUN_1000_1850_print_string(D_3d52[FUN_1000_2092_random_range(0, 3)]);
                uVar3 = F_SHOPPES_0b30(param_1);
            }
            else if (cVar1 == 'S')
            {
                FUN_1000_1850_print_string(/*0x804e*/ "Sell\n\n\"");
                F_SHOPPES_0f64(param_1);
                uVar3 = -1;
            }
        }
        else
        {
            FUN_1000_1850_print_string(/*0x8056*/ "No");
        }
    } while (cVar1 != 'B' && cVar1 != 'S' && cVar1 != ' ');

    F_SHOPPES_0202(uVar3);
}

// NOT MATCHING
int F_SHOPPES_137c(void)
{
    int local_4;

    if (D_585b == 1)
    {
        local_4 = 0;
    }
    else
    {
        FUN_1000_1850_print_string(/*0x805a*/ "\n\n\"Who needs my aid?\" ");
        local_4 = FUN_1000_2e8e();
        if (local_4 == -1)
        {
            FUN_1000_1850_print_string(/*0x8072*/ "No one");
        }
    }

    return local_4;
}

// NOT MATCHING
void F_SHOPPES_13b0(void)
{
    FUN_1000_0a70_set_pen_color(D_13ae);
    FUN_1000_0b86(8, 8, 0xb7, 0xb7);
    FUN_1000_2192_audio_some_noise(0x100e, 1, 0x57e4, 5000, 1);
    FUN_1000_2192_audio_some_noise(0x100e, 1, 0x57e4, 0x6b6c, -1);
    FUN_1000_0a70_set_pen_color(D_13b0_white_color);
    FUN_1000_0b86(8, 8, 0xb7, 0xb7);
    FUN_1000_2192_audio_some_noise(0x11b2, 1, 40000, 1, 1);
    FUN_1000_2192_audio_some_noise(0x11b2, 1, 40000, 40000, -1);
    FUN_1000_0b86(8, 8, 0xb7, 0xb7);
    FUN_1000_2192_audio_some_noise(0x8fc, 1, 18000, 1, 2);
    FUN_1000_2192_audio_some_noise(0x8fc, 1, 18000, 36000, -2);
}

// NOT MATCHING
int F_SHOPPES_146a(void)
{
    int iVar1;
    bool bVar3;

    F_SHOPPES_0026(/*0x807a*/ "for % gold.\n\nWilt thou\npay?\" ");
    do
    {
        iVar1 = FUN_1000_266c_get_ch();
        if (iVar1 == 'Y')
        {
            FUN_1000_1850_print_string(/*0x8098*/ "Yes");
        }
        else if (iVar1 == 'N')
        {
            FUN_1000_1850_print_string(/*0x809c*/ "No");
        }

        if (iVar1 == 'Y' || iVar1 == 'N')
        {
            bVar3 = iVar1 == 'N';
            if (!bVar3 && D_57aa < D_b118 && (D_b118 > 100 || D_5893_map_id != 7))
            {
                F_SHOPPES_017a(9131); // 0x23ab
                bVar3 = 1;
            }

            if (bVar3 == 0 && D_b118 <= D_57aa)
            {
                D_57aa = D_57aa - D_b118;
                F_SHOPPES_019a();
            }

            return bVar3;
        }
    } while (1);
}

// NOT MATCHING
void F_SHOPPES_14f8(void)
{
    bool bVar1;
    char cVar2;
    int iVar4;

    F_SHOPPES_01b6();

    bVar1 = 0;
    while (!bVar1)
    {
        do
        {
            cVar2 = FUN_1000_266c_get_ch();
            if (cVar2 == 'N')
            {
                FUN_1000_1850_print_string(/*0x80a0*/ "No");
            }
            else if (cVar2 == 'Y')
            {
                FUN_1000_1850_print_string(/*0x80a4*/ "Yes\n\n");
            }
        } while (cVar2 != 'N' && cVar2 != 'Y');

        if (cVar2 == 'N')
            break;

        FUN_1000_1850_print_string(/*0x80aa*/ "\"We have powers to Cure, Heal, or Resurrect.\"\n");
        F_SHOPPES_0026(/*0x80da*/ "says $.\n\n\"What is the nature of thy need?\" ");

        do
        {
            cVar2 = FUN_1000_266c_get_ch();
        } while (cVar2 != 'C' && cVar2 != 'H' && cVar2 != 'R' && cVar2 != ' ' && cVar2 != '\r');

        if (cVar2 != '\r' && cVar2 != ' ')
        {
            if (cVar2 == 'C')
            {
                FUN_1000_1850_print_string(/*0x8106*/ "Curing");
                iVar4 = F_SHOPPES_137c();
                if (iVar4 != -1)
                {
                    if (D_55a8_party[iVar4]._b == 'P')
                    {
                        FUN_1000_1850_print_string(/*0x810e*/ "\n\n\"");
                        if (D_5893_map_id == 5)
                        {
                            FUN_1000_1850_print_string(/*0x8112*/ "Receive now the Light!\"");
                            F_SHOPPES_13b0();
                            D_55a8_party[iVar4]._b = 0x47;
                        }
                        else
                        {
                            FUN_1000_1850_print_string(/*0x812a*/ "I can cure thy poisoned body ");
                            D_b118 = D_3d8e[D_b114];
                            if (F_SHOPPES_146a() == 0)
                            {
                                F_SHOPPES_13b0();
                                D_55a8_party[iVar4]._b = 0x47;
                            }
                        }
                    }
                    else
                    {
                        F_SHOPPES_0026(D_3d5a);
                    }
                }
            }
            else if (cVar2 == 'H')
            {
                FUN_1000_1850_print_string(/*0x8148*/ "Healing");
                iVar4 = F_SHOPPES_137c();
                if (iVar4 != -1)
                {
                    if (D_55a8_party[iVar4]._b != 'D' && D_55a8_party[iVar4]._10 != D_55a8_party[iVar4]._12)
                    {
                        FUN_1000_1850_print_string(/*0x8150*/ "\n\n\"");
                        if (D_5893_map_id == 5)
                        {
                            FUN_1000_1850_print_string(/*0x8154*/ "Receive now the Light!\"");
                            F_SHOPPES_13b0();
                            D_55a8_party[iVar4]._10 = D_55a8_party[iVar4]._12;
                        }
                        else
                        {
                            FUN_1000_1850_print_string(/*0x816c*/ "I can heal thee ");
                            D_b118 = D_3d86[D_b114];
                            if (F_SHOPPES_146a() == 0)
                            {
                                F_SHOPPES_13b0();
                                D_55a8_party[iVar4]._10 = D_55a8_party[iVar4]._12;
                            }
                        }
                    }
                    else
                    {
                        F_SHOPPES_0026(D_3d5a);
                    }
                }
            }
            else if (cVar2 == 'R')
            {
                FUN_1000_1850_print_string(/*0x817e*/ "Resurrect");
                iVar4 = F_SHOPPES_137c();
                if (iVar4 != -1)
                {
                    if (D_55a8_party[iVar4]._b == 'D')
                    {
                        FUN_1000_1850_print_string(/*0x8188*/ "\n\n\"");
                        FUN_1000_1850_print_string(/*0x818c*/ "I can raise this unfortunate person from ");
                        FUN_1000_1850_print_string(/*0x81b6*/ "the dead ");

                        D_b118 = D_3d96[D_b114];

                        if (F_SHOPPES_146a() == 0)
                        {
                            F_SHOPPES_13b0();
                            F_CAST2_05e0(iVar4, 0xff);
                            D_55a8_party[iVar4]._10 = D_55a8_party[iVar4]._12;
                            FUN_1000_2900_update_vitals();
                        }
                    }
                    else
                    {
                        F_SHOPPES_0026(D_3d5a);
                    }
                }
            }
        }
        else
        {
            FUN_1000_1850_print_string(/*0x81c0*/ "Nothing");
            bVar1 = 1;
        }

        if (!bVar1)
        {
            FUN_1000_2900_update_vitals();
            FUN_1000_1850_print_string(/*0x81c8*/ "\n\n\"Is there any other way in which I may\n");
            FUN_1000_1850_print_string(/*0x81f2*/ "aid thee?\" ");
        }
    }

    F_SHOPPES_0202(1);
}
