#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>

void F_SHOPPES_0026(char* param_1);

void F_SHOPPES_017a(int param_1);

void F_SHOPPES_019a(void);

void F_SHOPPES_01b6(void);

void F_SHOPPES_0202(int param_1);

// NOT MATCHING
void F_SHOPPES2_0000(short param_1)
{
    int iVar1;

    D_bd1a = D_bd1c = D_b118 = 0;

    for (iVar1 = 0; iVar1 < D_585b; iVar1++)
    {
        if (D_55a8_party[iVar1]._b != 'D')
        {
            D_bd1a++;
            D_bd1c++;
            D_b118 += param_1;
        }
    }

    FUN_1000_16ba_print_char(10);
    FUN_1000_16ba_print_char(10);
}

// OK P1?
void F_SHOPPES2_006a(void)
{
    switch (D_bd1c)
    {
    case 2:
        FUN_1000_1850_print_string(/*0x9aa8*/ "two");
        break;

    case 3:
        FUN_1000_1850_print_string(/*0x9aac*/ "three");
        break;

    case 4:
        FUN_1000_1850_print_string(/*0x9ab2*/ "four");
        break;

    case 5:
        FUN_1000_1850_print_string(/*0x9ab8*/ "five");
        break;

    case 6:
        FUN_1000_1850_print_string(/*0x9abe*/ "six");
        break;
    }
}

// NOT MATCHING
void F_SHOPPES2_00ac(void)
{
    D_587b = 0xff;
    if (D_55a8_party[0]._9 == 0xb)
    {
        FUN_1000_1850_print_string(/*0x9ac2*/ "sir");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x9ac6*/ "milady");
    }
}

// NOT MATCHING
int F_SHOPPES2_00dc(void)
{
    FUN_1000_16ba_print_char(0x22);
    FUN_1000_1850_print_string(/*0x9ace*/ "That will be ");
    FUN_1000_1a3e_print_number(D_b118, 1, 0x20);
    FUN_1000_1850_print_string(/*0x9adc*/ " gold for the ");
    F_SHOPPES2_006a();
    FUN_1000_1850_print_string(/*0x9aec*/ " of ye,\n");
    F_SHOPPES2_00ac();
    FUN_1000_16ba_print_char(0x2e);

    if (D_57aa < D_b118)
    {
        FUN_1000_1850_print_string(/*0x9af6*/ "\"\n\n\"CAN'T PAY?\nBeat it!\"\nyells ");
        FUN_1000_1850_print_string(D_aafe);
        FUN_1000_16ba_print_char(0x2e);
        FUN_1000_16ba_print_char(10);
        return 1;
    }

    D_57aa -= D_b118;
    F_SHOPPES_019a();

    if (D_bd1a == 0)
    {
        D_bd20++;
    }
    else
    {
        FUN_1000_3f14(&D_57a8, D_bd1a, 9999);

        if (*FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y - 1) == 0x95)
        {
            *FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y - 1) = 0x9b;
            D_bd1e = 0x9b;

            FUN_1000_5910_update_map();
        }
        else if (*FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y + 1) == 0x95)
        {
            *FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y + 1) = 0x9a;
            D_bd1e = 0x9a;

            FUN_1000_5910_update_map();
        }
    }

    FUN_1000_1850_print_string(/*0x9b16*/ "\nEnjoy!\"\n\n");
    return 0;
}

// NOT MATCHING
int F_SHOPPES2_01d2(void)
{
    FUN_1000_16ba_print_char(D_4c1e[D_bd16]);
    F_SHOPPES2_0000(D_4c36[D_b114]);
    return F_SHOPPES2_00dc();
}

// NOT MATCHING
int F_SHOPPES2_01f4(void)
{
    char cVar1;
    byte bVar2;
    int uVar3;

    FUN_1000_16ba_print_char(D_4c24[D_bd16]);
    if (D_bd20 == 3)
    {
        FUN_1000_1850_print_string(/*0x9b22*/ "\n\n\"I beg thy\npardon, ");
        F_SHOPPES2_00ac();
        FUN_1000_1850_print_string(/*0x9b38*/ ",\"\nsays ");
        FUN_1000_1850_print_string(D_aafe);
        FUN_1000_1850_print_string(/*0x9b42*/ ".\n\"But haven't\nye had enough\nto drink?\" ");
        do
        {
            cVar1 = FUN_1000_266c_get_ch();
            if (cVar1 == 'Y')
            {
                FUN_1000_1850_print_string(/*0x9b6c*/ "Yes\n\n");
                goto LAB_0000_0241;
            }
            if (cVar1 == 'N')
            {
                FUN_1000_1850_print_string(/*0x9b72*/ "No!");
                D_5957 = 0x19;
                FUN_1000_3f36(&D_5888, 1);
            }
        } while (cVar1 != 'Y' && cVar1 != 'N');
    }

    F_SHOPPES2_0000(1);
    if (D_4c24[D_bd16] == 'W')
    {
        FUN_1000_1850_print_string(/*0x9b76*/ "\"Our wine list,\n");
        F_SHOPPES2_00ac();
        FUN_1000_1850_print_string(/*0x9b88*/ ".\n\n");
        FUN_1000_1850_print_string(/*0x9b8c*/ "a) Rose.......18\n");
        FUN_1000_1850_print_string(/*0x9b9e*/ "b) Claret....192\n");
        FUN_1000_1850_print_string(/*0x9bb0*/ "c) Sauterne...79\n");
        FUN_1000_1850_print_string(/*0x9bc2*/ "d) Muscatel...30\n");
        FUN_1000_1850_print_string(/*0x9bd4*/ "e) Moselle...275\n");
        FUN_1000_1850_print_string(/*0x9be6*/ "f) Chablis....98\n\n");
        FUN_1000_1850_print_string(/*0x9bfa*/ "Thy choice?\" ");

        do
        {
            bVar2 = FUN_1000_266c_get_ch();
            if (bVar2 == 0x20)
                goto LAB_0000_02d2;
        } while (bVar2 < 0x41 || 0x46 < bVar2);

        FUN_1000_16ba_print_char(bVar2);
        FUN_1000_1850_print_string(/*0x9c08*/ "\n\n\"Ah, a fine\nchoice, ");
        F_SHOPPES2_00ac();
        FUN_1000_16ba_print_char(0x2e);

        if (D_57aa < D_4c48[bVar2 + 0xbf])
        {
            FUN_1000_1850_print_string(/*0x9c20*/ "\"\n\n\"CAN'T PAY?\nBeat it!\"\nyells ");
            FUN_1000_1850_print_string(D_aafe);
            FUN_1000_16ba_print_char(0x2e);
            FUN_1000_16ba_print_char(10);
            uVar3 = 1;
        }
        else
        {
            D_57aa -= D_4c48[bVar2 + 0xbf];
            F_SHOPPES_019a();
            D_bd20++;
            bVar2 = 0x40;
            FUN_1000_1850_print_string(/*0x9c40*/ "\nEnjoy!\"");
        LAB_0000_02d2:
            FUN_1000_16ba_print_char(10);
            FUN_1000_16ba_print_char(10);
            if (bVar2 == 0x20)
            {
                F_SHOPPES_017a(0x1413);
                uVar3 = 2;
            }
            else
            {
            LAB_0000_0241:
                uVar3 = 0;
            }
        }
    }
    else
    {
        D_bd1a = 0;
        uVar3 = F_SHOPPES2_00dc();
    }

    return uVar3;
}

// NOT MATCHING
int F_SHOPPES2_0380(int param_1)
{
    int iVar2;
    int iVar3;
    int uVar4;

    FUN_1000_16ba_print_char(*(D_bd16 + D_4c2a));
    FUN_1000_16ba_print_char(10);
    FUN_1000_16ba_print_char(10);

    D_b118 = D_4c54[D_b114];
    D_b118 += (s32)D_b118 * -(D_55a8_party[param_1]._e * 3 - 100) / 100;

    FUN_1000_16ba_print_char(0x22);
    iVar2 = FUN_1000_2092_random_range(0, 6);
    F_SHOPPES_017a(D_4c66[iVar2]);
    FUN_1000_1850_print_string(/*0x9c4a*/ "\n\nHow many wouldst\nthou like?\" ");
    iVar3 = FUN_1000_3b9e(2);
    iVar2 = iVar3;
    if (iVar3 == 0)
    {
        FUN_1000_1850_print_string(/*0x9c6a*/ "\n\n\"Hrumph.\"");
        uVar4 = 2;
    }
    else
    {
        for (; iVar2 != 0; iVar2--)
        {
            if (D_57aa < D_b118)
            {
                FUN_1000_1850_print_string(/*0x9c76*/ "\n\n");
                if (iVar3 - iVar2 == 0)
                {
                    if (D_57a8 < 3)
                    {
                        iVar2 = FUN_1000_2092_random_range(0, 1);
                        FUN_1000_3f14(&D_57a8, iVar2 + 1, 9999);
                        F_SHOPPES_017a(0x143f);
                    }
                    else
                    {
                        FUN_1000_1850_print_string(/*0x9c7a*/ "\"Thou hast\nneither gold nor\nneed! Out!\"\n");
                        FUN_1000_1850_print_string(/*0x9ca4*/ "yells ");
                        FUN_1000_1850_print_string(D_aafe);
                        FUN_1000_1850_print_string(/*0x9cac*/ ".\n");
                    }
                    return 1;
                }

                FUN_1000_1850_print_string(/*0x9cb0*/ "\"Thou canst\nafford only ");
                FUN_1000_1a3e_print_number(iVar3 - iVar2, 1, 0x20);
                FUN_1000_1850_print_string(/*0x9cca*/ "!\"\n\n");
                return 0;
            }

            FUN_1000_3f54(&D_57aa, D_b118);
            FUN_1000_3f14(&D_57a8, 0x19, 9999);

            if (D_57a8 == 9999)
                break;
        }

        FUN_1000_1850_print_string(/*0x9cd0*/ "\n\n");
        F_SHOPPES_019a();
        uVar4 = 0;
    }

    return uVar4;
}

// NOT MATCHING
int F_SHOPPES2_0508(void)
{
    int iVar2;
    int iVar4;
    int local_8;

    FUN_1000_16ba_print_char(D_4c30[D_bd16]);
    FUN_1000_1850_print_string(/*0x9efc*/ "\n\n\"");

    while (1)
    {
        FUN_1000_1850_print_string(/*0x9f00*/ "Of what wouldst\nthou hear my\nlore, ");
        F_SHOPPES2_00ac();
        FUN_1000_1850_print_string(/*0x9f24*/ "?\"\n\nYou respond:\n");
        FUN_1000_3b1c_get_string(D_bcf8, 0xf);
        FUN_1000_1850_print_string(/*0x9f36*/ "\n\n");
        if (D_bcf8[0] == '\0')
        {
            return 0;
        }

        local_8 = -1;
        for (iVar4 = 0; iVar4 < 0x1a; iVar4++)
        {
            iVar2 = FUN_1000_6f1e(D_4c74[iVar4], D_bcf8);
            if (iVar2 == 0 || (0 < iVar2 && D_bcf8[iVar2 - 1] == ' '))
            {
                local_8 = iVar4;
                break;
            }
        }

        if (local_8 != -1)
        {
            D_b118 = D_4d10[local_8];
            F_SHOPPES_017a(0x134e);
            FUN_1000_1850_print_string(/*0x9f5c*/ "\n\nFair 'nuff?\" ");
            iVar4 = 0;
            break;
        }

        FUN_1000_1850_print_string(/*0x9f3a*/ "\"That, I cannot help thee with.\n\n");
    }

    while (iVar4 = FUN_1000_266c_get_ch(), iVar4 != 0x59)
    {
        if (iVar4 == 0x4e)
            break;
    }

    if (iVar4 == 0x4e)
    {
        FUN_1000_1850_print_string(/*0x9f6c*/ "No\n\n");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x9f72*/ "Yes\n\n");

        if (D_57aa < D_b118)
        {
            FUN_1000_1850_print_string(/*0x9f78*/ "\"Sorry, ");
            F_SHOPPES2_00ac();
            F_SHOPPES_017a(0x146a);
            return 1;
        }

        D_57aa -= D_b118;
        FUN_1000_2900_update_vitals();

        D_ab00 = D_4ca8[local_8];
        D_ac62 = D_4cf6[D_4cdc[local_8]];

        iVar4 = FUN_1000_2092_random_range(0, 3);
        F_SHOPPES_017a(D_4d44[iVar4]);

        FUN_1000_1850_print_string(/*0x9f82*/ "\nsays ");
        FUN_1000_1850_print_string(D_aafe);
        FUN_1000_1850_print_string(/*0x9f8a*/ ".\n\n");
    }

    return 0;
}

// NOT MATCHING
void F_SHOPPES2_0664(void) { F_SHOPPES_0202(D_bd18); }

// NOT MATCHING
void F_SHOPPES2_066c(int param_1)
{
    char cVar1;
    int iVar3;
    int iVar4;
    uint uVar5;

    D_bd16 = D_4d4c[D_b114];
    D_bd18 = 0;
    D_bd1e = 0;
    F_SHOPPES_01b6();

    do
    {
        cVar1 = FUN_1000_266c_get_ch();
        if (cVar1 == 'N' || cVar1 == ' ')
        {
            FUN_1000_1850_print_string(/*0x9f8e*/ "No");
            F_SHOPPES2_0664();
            return;
        }
    } while (cVar1 != 'Y');

    FUN_1000_1850_print_string(/*0x9f92*/ "Yes\n\n\"");
    F_SHOPPES_017a(D_4d56[D_bd16]);
    FUN_1000_16ba_print_char(0x22);
    FUN_1000_16ba_print_char(0x20);

    if (FUN_1000_1f12_get_current_text_column() >= 0xf)
    {
        FUN_1000_16ba_print_char(10);
    }

    while (1)
    {
        while (1)
        {
            cVar1 = FUN_1000_266c_get_ch();
            iVar3 = 0;

            if (cVar1 == 0x20 || cVar1 == 0x1b || cVar1 == 0xd)
            {
                F_SHOPPES2_0664();
                return;
            }

            if (D_4c1e[D_bd16] == cVar1)
            {
                if (F_SHOPPES2_01d2() != 0)
                {
                    return;
                }
            }

            if (D_4c24[D_bd16] == cVar1)
            {
                if (F_SHOPPES2_01f4() == 1)
                {
                    return;
                }
            }

            if (D_4c2a[D_bd16] == cVar1)
            {
                if (F_SHOPPES2_0380(param_1) == 1)
                {
                    return;
                }
            }

            if (D_4c30[D_bd16] == cVar1)
            {
                if (D_bd18 == 0)
                    continue;

                if (F_SHOPPES2_0508() != 0)
                {
                    return;
                }
            }

            if (D_4c1e[D_bd16] == cVar1 || D_4c24[D_bd16] == cVar1 || D_4c2a[D_bd16] == cVar1 ||
                D_4c30[D_bd16] == cVar1)
                break;
        }

        if (iVar3 != 2)
        {
            D_bd18 = 1;
        }

        FUN_1000_2900_update_vitals();
        FUN_1000_1850_print_string(/*0x9f9a*/ "\"Anything else\nfor thee?\" ");

        do
        {
            cVar1 = FUN_1000_266c_get_ch();
            if (cVar1 == 'N')
            {
                FUN_1000_1850_print_string(/*0x9fb6*/ "No");
                F_SHOPPES2_0664();
                return;
            }
        } while (cVar1 != 'Y');

        FUN_1000_1850_print_string(/*0x9fba*/ "Yes\n\n\"");
        F_SHOPPES_017a(D_4d5e[D_bd16]);
        FUN_1000_16ba_print_char(0x22);
        FUN_1000_16ba_print_char(0x20);
    }
}

// NOT MATCHING
bool F_SHOPPES2_07e2(int param_1)
{
    if (param_1 > D_57aa)
    {
        F_SHOPPES_017a(0x198e);
        F_SHOPPES_0026(/*0x9fc2*/ "yells $.\n");
        D_bd22 = 1;
    }

    return param_1 <= D_57aa;
}

// NOT MATCHING
bool F_SHOPPES2_080e(int param_1, int param_2, int param_3)
{
    char cVar2;

    if (param_1 != 0)
    {
        F_SHOPPES_017a(0x19ab);
        D_5953 = D_4d76[D_b114];
        D_5954 = D_4d7a[D_b114];
    }

    if (param_2 != 0)
    {
        D_57aa -= D_b118;
        D_bd24 = 1;
        F_SHOPPES_019a();
    }

    FUN_1000_2900_update_vitals();
    F_SHOPPES_017a(0x19da);

    if (D_55a8_party[param_3]._9 == 'F')
    {
        FUN_1000_1850_print_string(/*0x9fcc*/ "milady");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x9fd4*/ "sir");
    }

    FUN_1000_1850_print_string(/*0x9fd8*/ "?\" ");

    do
    {
        cVar2 = FUN_1000_266c_get_ch();
        if (cVar2 == 'Y')
            break;
    } while (cVar2 != 'N');

    if (cVar2 == 'Y')
    {
        FUN_1000_1850_print_string(/*0x9fdc*/ "Yes");
    }
    else
    {
        FUN_1000_1850_print_string(/*0x9fe0*/ "No");
    }

    return cVar2 != 'Y';
}

// NOT MATCHING
void F_SHOPPES2_08a8(int param_1)
{
    char cVar2;
    int iVar4;
    int uVar5;
    int iVar6;

    iVar6 = 0;
    while (1)
    {
        F_SHOPPES_017a(0x18eb);
        iVar4 = FUN_1000_266c_get_ch();
        if (iVar4 == 0x1b || iVar4 == 0x20)
        {
            iVar6 = 1;
        }
        else if (iVar4 == 0x46)
        {
            FUN_1000_1850_print_string(/*0x9fe4*/ "F\n\n");
            iVar6 = 1;
            if ((D_6605 & 0xc0) != 0)
            {
                F_SHOPPES_017a(0x19f2);

                do
                {
                    cVar2 = FUN_1000_266c_get_ch();
                    if (cVar2 == 'Y')
                        break;
                } while (cVar2 != 'N');

                if (cVar2 == 'Y')
                {
                    FUN_1000_1850_print_string(/*0x9fe8*/ "Yes");
                    F_SHOPPES2_07e2(10000);
                }
                else
                {
                    FUN_1000_1850_print_string(/*0x9fec*/ "No");
                    F_SHOPPES2_08a8(param_1);
                }
            }
            else
            {
                D_b118 = D_4d66[D_b114];
                D_b118 += ((s32)D_b118 * -(D_55a8_party[param_1]._e * 3 - 100)) / 100;

                F_SHOPPES_017a(0x183e);
                F_SHOPPES_017a(0x1a50);

                do
                {
                    cVar2 = FUN_1000_266c_get_ch();
                    if (cVar2 == 'Y')
                        break;
                } while (cVar2 != 'N');

                if (cVar2 == 'Y')
                {
                    FUN_1000_1850_print_string(/*0x9ff0*/ "Yes\n\n");
                    iVar6 = F_SHOPPES2_07e2(D_b118);
                    if (iVar6 == 0)
                    {
                        return;
                    }
                    D_6605 = 0x82;
                    iVar6 = 1;
                    iVar4 = iVar6;
                    iVar6 = F_SHOPPES2_080e(iVar4, iVar6, param_1);
                    if (iVar6 != 0)
                    {
                        return;
                    }
                }
                else
                {
                    FUN_1000_1850_print_string(/*0x9ff6*/ "No");
                    return;
                }

                continue;
            }
        }
        else if (iVar4 == 0x53)
        {
            FUN_1000_1850_print_string(/*0x9ffa*/ "S\n\n");

            D_b118 = D_4d6e[D_b114];
            D_b118 += ((s32)D_b118 * -(D_55a8_party[param_1]._e * 3 - 100)) / 100;

            F_SHOPPES_017a(0x188c);
            F_SHOPPES_017a(0x1a50);

            do
            {
                cVar2 = FUN_1000_266c_get_ch();
                if (cVar2 == 'Y')
                    break;
            } while (cVar2 != 'N');

            iVar6 = 1;

            if (cVar2 == 'Y')
            {
                FUN_1000_1850_print_string(/*0x9ffe*/ "Yes\n\n");
                iVar4 = F_SHOPPES2_07e2(D_b118);
                if (iVar4 == 0)
                {
                    return;
                }
                if ((D_6605 & 0xc0) == 0)
                {
                    D_6605 = 0x40;
                    iVar4 = iVar6;
                }
                else if ((D_6605 & 0x80) == 0)
                {
                    if ((D_6605 & 0x40) == 0)
                    {
                        if (iVar6 != 0)
                        {
                            return;
                        }

                        continue;
                    }

                    F_SHOPPES_017a(0x195f);
                    iVar6 = 0;
                    iVar4 = iVar6;
                }
                else
                {
                    F_SHOPPES_017a(0x193b);
                    D_6605++;
                    iVar6 = 1;
                    iVar4 = 0;
                }

                iVar6 = F_SHOPPES2_080e(iVar4, iVar6, param_1);
            }
            else
            {
                FUN_1000_1850_print_string(/*0xa004*/ "No");
                return;
            }
        }

        if (iVar6 != 0)
        {
            return;
        }
    }
}

// NOT MATCHING
void F_SHOPPES2_0abc(int param_1)
{
    bool bVar1;
    int iVar2;

    bVar1 = 0;
    D_bd22 = 0;
    D_bd24 = 0;

    F_SHOPPES_01b6();

    do
    {
        iVar2 = FUN_1000_266c_get_ch();
        if (iVar2 != 0x20 && iVar2 != 0x4e)
        {
            if (iVar2 == 0x59)
            {
                FUN_1000_1850_print_string(/*0xa008*/ "Yes");
                F_SHOPPES2_08a8(param_1);
                bVar1 = 1;
            }
        }
        else
        {
            FUN_1000_1850_print_string(/*0xa00c*/ "No");
            bVar1 = 1;
        }

        if (bVar1)
        {
            if (D_bd22 == 0)
            {
                F_SHOPPES_0202(D_bd24);
            }

            return;
        }

    } while (1);
}
