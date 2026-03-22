#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>
#include <string.h>

void TOWN_0170(void);
void TOWN_0958(void);
void TOWN_1694(void);

void SHOPPES_0026(char* param_1);
void SHOPPES_017a(int param_1);
void SHOPPES_019a(void);
void SHOPPES_01b6(void);
void SHOPPES_0202(int param_1);
int SHOPPES_0280(void);

// NOT MATCHING
int SHOPPES3_0000(void)
{
    int iVar1;
    int iVar2;

    iVar2 = 0;
    for (iVar1 = 0x10; iVar1 >= 0; iVar1--)
    {
        if (D_55a8_party[iVar1]._1f == D_5893_map_id)
        {
            iVar2++;
        }
    }

    return iVar2;
}

// NOT MATCHING
int SHOPPES3_002c(int param_1)
{
    int uVar2;

    ULTIMA_1850_PrintString(/*0x4d84*/ "\n\n");

    if (SHOPPES3_0000() < D_4dc4[D_b114])
    {
        uVar2 = 1;
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x4d87*/ "\"I am sorry,\n");
        if (param_1 == 0xc)
        {
            ULTIMA_1850_PrintString(/*0x4d95*/ "milady");
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x4d9c*/ "sir");
        }

        ULTIMA_1850_PrintString(/*0x4da0*/ ", but we\nhave no room\navailable.\"\n\n");
        uVar2 = 0;
    }

    return uVar2;
}

// NOT MATCHING
int SHOPPES3_0072(int param_1, int param_2, int param_3)
{
    undefined1 uVar1;
    byte bVar2;
    char cVar3;
    int iVar4;
    uint uVar6;
    uint local_a;

    ULTIMA_16ba_PrintChar(0x52);
    iVar4 = SHOPPES3_002c(param_2);
    if (iVar4 == 0)
    {
        param_3 = -2;
    }
    else
    {
        ULTIMA_16ba_PrintChar(0x22);

        D_b118 = (uint)D_4d7e[D_b114] * (uint)D_585b;
        D_b118 += (s32)D_b118 * -(param_1 * 3 - 100) / 100;

        SHOPPES_017a(D_4e6e[D_b114]);
        ULTIMA_1850_PrintString(/*0x4dca*/ "\nWilt thou take\nit?\" ");
        cVar3 = SHOPPES_0280();
        ULTIMA_1850_PrintString(/*0x4de0*/ "\n\n");
        if (cVar3 == 'Y')
        {
            if (D_57aa < D_b118)
            {
                ULTIMA_1850_PrintString(/*0x4de3*/ "\"Highwaymen!\nCheap, at that!\nOUT!\" ");
                SHOPPES_0026(/*0x4e07*/ "screams\n$.\n");
            }
            else
            {
                D_57aa -= D_b118;
                SHOPPES_019a();
                ULTIMA_2900_UpdateVitalsDisplay();

                ULTIMA_1850_PrintString(/*0x4e13*/ "\"Have a pleasant\nnight, ");
                if (param_2 == 0xc)
                {
                    ULTIMA_1850_PrintString(/*0x4e2c*/ "milady");
                }
                else
                {
                    ULTIMA_1850_PrintString(/*0x4e33*/ "sir");
                }
                SHOPPES_0026(/*0x4e37*/ "!\"\nsays $.\n\n");

                ULTIMA_3ae6(10);
                ULTIMA_39cc_set_new_tile_id(D_594f, D_5950, D_5951);

                D_5896_map_x = D_4e7a[D_b114];
                D_5897_map_y = D_4e80[D_b114];
                D_24e6 = 1;

                uVar1 = D_587b;
                bVar2 = D_585b;

                for (uVar6 = 0; uVar6 < bVar2; uVar6++)
                {
                    if (D_55a8_party[uVar1]._b == 'G')
                    {
                        D_55a8_party[uVar1]._b = 'S';
                    }
                }

                ULTIMA_2900_UpdateVitalsDisplay();
                ULTIMA_5910_UpdateFrame();
                ULTIMA_1850_PrintString(/*0x4e44*/ "Zzzzzz....\n\n");

                for (iVar4 = 0; iVar4 < 0xc; iVar4++)
                {
                    ULTIMA_4f7c(5);
                }

                while (D_587f != 6)
                {
                    ULTIMA_3ae6(1);
                    ULTIMA_400c();
                    ULTIMA_2900_UpdateVitalsDisplay();
                    ULTIMA_4f7c(9);
                    if (D_587f == 0x14 || D_587f == 0x05)
                    {
                        TOWN_0170();
                    }
                }

                ULTIMA_1850_PrintString(/*0x4e51*/ "Morning!\n");
                TOWN_1694();

                for (local_a = 0; local_a < D_585b; local_a++)
                {
                    if (D_55a8_party[local_a]._b != 'D')
                    {
                        D_55a8_party[local_a]._10 = D_55a8_party[local_a]._12;

                        switch (D_55a8_party[local_a]._10)
                        {
                        case 'A':
                        case 'M':
                            D_55a8_party[local_a]._f = D_55a8_party[local_a]._e;
                            break;

                        case 'B':
                            D_55a8_party[local_a]._f = D_55a8_party[local_a]._e >> 1;
                            break;
                        }

                        if (D_55a8_party[local_a]._b == 'P')
                        {
                            D_55a8_party[local_a]._b = 0x44;
                            D_55a8_party[local_a]._10 = 0;

                            ULTIMA_16ba_PrintChar(10);
                            ULTIMA_1850_PrintString(D_55a8_party[local_a]._0);
                            ULTIMA_1850_PrintString(/*0x4e5b*/ " has\npassed away.\n");
                        }
                        else if (D_55a8_party[local_a]._b == 'S')
                        {
                            D_55a8_party[local_a]._b = 0x47;
                        }
                    }
                }

                D_587b = uVar1;
                D_5896_map_x++;
                D_24e6 = 1;
                ULTIMA_2900_UpdateVitalsDisplay();

                param_3 = -1;
            }
        }
    }
    return param_3;
}

// NOT MATCHING
int SHOPPES3_02ae(int param_1, int param_2, int param_3)
{
    bool bVar4;
    char cVar5;
    int iVar6;
    int uVar7;
    S_55a8 local_22;

    ULTIMA_16ba_PrintChar(0x4c);
    iVar6 = SHOPPES3_002c(param_2);
    if (iVar6 != 0)
    {
        if (D_585b == 1)
        {
            SHOPPES_017a(0x26e8);
            param_3 = -1;
        }
        else
        {
            do
            {
                bVar4 = 1;
                SHOPPES_0026(/*0x4e86*/ "$ asks,\n\"Who will\nstay?\" ");
                uVar7 = ULTIMA_2e8e();
                if (uVar7 == -1)
                {
                    ULTIMA_1850_PrintString(/*0x4ea0*/ "Nobody\n\n");
                    param_3 = -2;
                }
                else
                {
                    ULTIMA_1850_PrintString(/*0x4ea9*/ "\n\n");
                    if (uVar7 == 0)
                    {
                        ULTIMA_1850_PrintString(/*0x4eac*/ "Thy friend");
                        if (2 < D_585b)
                        {
                            ULTIMA_16ba_PrintChar(0x73);
                        }
                        ULTIMA_1850_PrintString(/*0x4eb7*/ " will not leave thee!\n\n");
                        bVar4 = 0;
                    }
                    else if (D_55a8_party[uVar7]._b == 'D')
                    {
                        SHOPPES_017a(0x2723);
                        param_3 = -1;
                    }
                    else
                    {
                        D_b118 = (uint)D_4d7e[D_b114] * 10;
                        D_b118 += (s32)D_b118 * (-(param_1 * 3) - 100) / 100;

                        ULTIMA_1850_PrintString(/*0x4ecf*/ "\"The rate for\nour most comfortable room will be ");
                        SHOPPES_0026(/*0x4f00*/ "% gold per month, due at check-out.");
                        ULTIMA_1850_PrintString(/*0x4f24*/ "\nWilt thou take\nit?\" ");
                        cVar5 = SHOPPES_0280();
                        ULTIMA_1850_PrintString(/*0x4f3a*/ "\n\n");
                        if (cVar5 == 'Y')
                        {
                            param_3 = 1;
                            if (D_587b == uVar7)
                            {
                                D_587b = 0xff;
                            }
                            else if (uVar7 < D_587b && D_587b != 0xff)
                            {
                                D_587b--;
                            }

                            D_55a8_party[uVar7]._1f = D_5893_map_id;
                            D_55a8_party[uVar7]._17 = 0;

                            memcpy(&local_22, D_55a8_party[uVar7]._0, sizeof(S_55a8));

                            for (iVar6 = uVar7; iVar6 < 0xf; iVar6++)
                            {
                                memcpy(&D_55a8_party[iVar6], &D_55a8_party[iVar6 + 1], sizeof(S_55a8));
                            }

                            memcpy(&D_55a8_party[0x10 - 1], &local_22, sizeof(S_55a8));

                            D_585b--;
                            ULTIMA_2900_UpdateVitalsDisplay();
                            SHOPPES_0026(/*0x4f3d*/ "\"I thank thee.\"\nsays $.\n\n");
                        }
                    }
                }
            } while (!bVar4);
        }
    }

    return param_3;
}

// NOT MATCHING
int SHOPPES3_0494(int param_1)
{
    do
    {
        if (--param_1 == 0)
        {
            return 0;
        }
    } while (D_55a8_party[param_1]._1f != D_5893_map_id);

    return param_1;
}

// NOT MATCHING
int SHOPPES3_04b6(int param_1)
{
    do
    {
        if (++param_1 > 0xf)
        {
            break;
        }
    } while (D_55a8_party[param_1]._1f != D_5893_map_id);

    if (param_1 == 0x10)
    {
        param_1 = 0;
    }

    return param_1;
}

// NOT MATCHING
int SHOPPES3_04e6(int param_1, int param_2)
{
    bool bVar5;
    byte bVar6;
    int iVar8;
    int iVar11;
    int local_3a;
    int local_34;
    uint local_2c;
    S_55a8 local_24;
    int local_4;
    int i;

    local_4 = SHOPPES3_0000();

    if (D_585b == 6)
    {
        ULTIMA_1850_PrintString(/*0x4f57*/ "\n\nOne must first be left behind!\n\n");
        return param_2;
    }

    if (local_4 == 0)
    {
        SHOPPES_0026(/*0x4f7a*/ "\n\n\"No one here is from thy party!\"\nsays $.\n\n");
        return param_2;
    }

    if (local_4 < 2)
    {
        local_34 = SHOPPES3_04b6(0);
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x4fa7*/ "\n\n\"Who will\ncheck out?\" ");
        ULTIMA_1b94_SelectTextWindow(1);
        ULTIMA_4efc();
        ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x26, 9);
        ULTIMA_16ba_PrintChar(0xff);
        ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x27, 9);
        ULTIMA_16ba_PrintChar(0x10);

        for (iVar8 = 0; iVar8 < 0xd; iVar8++)
        {
            ULTIMA_16ba_PrintChar(0x11);
        }

        ULTIMA_16ba_PrintChar(0x13);

        for (iVar8 = 1; iVar8 < 8; iVar8++)
        {
            ULTIMA_1bf2_SetTextPosition(0, iVar8);
            ULTIMA_16ba_PrintChar(0x17);
            ULTIMA_1bf2_SetTextPosition(0xe, iVar8);
            ULTIMA_16ba_PrintChar(0x17);
        }

        ULTIMA_16ba_PrintChar(10);
        ULTIMA_16ba_PrintChar(0x14);

        for (iVar8 = 0; iVar8 < 0xd; iVar8++)
        {
            ULTIMA_16ba_PrintChar(0x15);
        }

        ULTIMA_16ba_PrintChar(0x16);
        ULTIMA_1bf2_SetTextPosition(1, 1);
        ULTIMA_1850_PrintString(/*0x4fc0*/ "    GUEST");
        ULTIMA_1bf2_SetTextPosition(1, 2);
        ULTIMA_1850_PrintString(/*0x4fca*/ "  REGISTER:\n\n");

        for (local_3a = 0; local_3a < 0xf; local_3a++)
        {
            if (D_55a8_party[local_3a]._1f == D_5893_map_id)
            {
                ULTIMA_1bf2_SetTextPosition(4, ULTIMA_1cee_GetCurrentTextY());

                ULTIMA_1850_PrintString(D_55a8_party[local_3a]._0);
                ULTIMA_16ba_PrintChar(10);
            }
        }

        ULTIMA_1b94_SelectTextWindow(2);
        bVar5 = 0;
        local_34 = SHOPPES3_04b6(0);
        iVar8 = 0x28;
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);

        while (!bVar5)
        {
            ULTIMA_0b86(0xc6, iVar8, 0x131, iVar8 + 7);

            do
            {
                bVar6 = ULTIMA_266c_GetChar();
                switch (bVar6)
                {
                case 1:
                case 3:
                    iVar11 = SHOPPES3_0494(local_34);
                    if (iVar11 != 0)
                    {
                        ULTIMA_0b86(0xc6, iVar8, 0x131, iVar8 + 7);
                        iVar8 -= 8;
                        local_34 = iVar11;
                    }
                    break;

                case 2:
                case 4:
                    iVar11 = SHOPPES3_04b6(local_34);
                    if (iVar11 != 0)
                    {
                        ULTIMA_0b86(0xc6, iVar8, 0x131, iVar8 + 7);
                        iVar8 += 8;
                        local_34 = iVar11;
                    }
                    break;

                case 0x20:
                case 0xd:
                    iVar11 = 1;
                    bVar5 = 1;
                    break;

                case 0x1b:
                    ULTIMA_1850_PrintString(/*0x4fd8*/ "No one\n\n");
                    local_34 = 0;

                    iVar11 = 1;
                    bVar5 = 1;
                    break;

                default:
                    iVar11 = 0;
                    break;
                }
            } while (iVar11 == 0);
        }

        ULTIMA_4f3c();
        ULTIMA_2900_UpdateVitalsDisplay();
    }

    if (local_34 == 0)
    {
        return param_2;
    }

    local_2c = (uint)D_55a8_party[local_34]._17;
    if (local_2c == 0)
    {
        local_2c = 1;
    }

    D_b118 = (uint)D_4d7e[D_b114] * 10;
    D_b118 += ((s32)D_b118 * -(param_1 * 3 - 100)) / 100;

    D_b118 = local_2c * D_b118;

    SHOPPES_0026(/*0x4fe1*/ "\n\n\"That will be % gold, please.\"\n\n\"");
    if (D_57aa < D_b118)
    {
        SHOPPES_017a(0x275a);
        TOWN_0958();
        return -1;
    }

    D_57aa -= D_b118;

    SHOPPES_019a();
    ULTIMA_2900_UpdateVitalsDisplay();

    memcpy(&local_24, &D_55a8_party[local_34], sizeof(S_55a8));

    for (i = local_34; i > D_585b; i--)
    {
        memcpy(&D_55a8_party[i], &D_55a8_party[i - 1], sizeof(S_55a8));
    }

    memcpy(&D_55a8_party[D_585b], &local_24, sizeof(S_55a8));

    bVar6 = D_585b++;

    D_55a8_party[bVar6]._1f = 0;
    if (D_55a8_party[bVar6]._b == 'P')
    {
        D_55a8_party[bVar6]._b = 0x44;
        D_55a8_party[bVar6]._10 = 0;

        ULTIMA_1850_PrintString(/*0x5005*/ "Thy friend has died, by the way.\"\n");
    }
    else
    {
        D_55a8_party[bVar6]._10 = D_55a8_party[bVar6]._12;

        switch (D_55a8_party[bVar6]._a)
        {
        case 'A':
        case 'M':
            D_55a8_party[bVar6]._f = D_55a8_party[bVar6]._e;
            break;
        case 'B':
            D_55a8_party[bVar6]._f = D_55a8_party[bVar6]._e >> 1;
            break;
        }

        ULTIMA_1850_PrintString(/*0x5028*/ "I hope thou hast found thy stay enjoyable,\"\n");
    }

    SHOPPES_0026(/*0x5055*/ "says $.\n\n");
    ULTIMA_2900_UpdateVitalsDisplay();
    return 1;
}

// NOT MATCHING
void SHOPPES3_08b4(int param_1)
{
    undefined1 uVar1;
    undefined1 uVar2;
    bool bVar3;
    int iVar5;
    int iVar6;
    char local_e;
    int local_a;

    local_a = 0;
    bVar3 = 0;

    uVar1 = D_55a8_party[param_1]._e;
    uVar2 = D_55a8_party[param_1]._9;

    D_588e = 0;
    D_587a = 0;
    ULTIMA_2900_UpdateVitalsDisplay();

    SHOPPES_01b6();

    while (!bVar3)
    {
        do
        {
            local_e = ULTIMA_266c_GetChar();
            if (local_e == ' ')
            {
                local_e = 'N';
            }
            if (local_e == 'N')
            {
                ULTIMA_1850_PrintString(/*0x505f*/ "No");
            }
            else if (local_e == 'Y')
            {
                ULTIMA_1850_PrintString(/*0x5062*/ "Yes");
            }
        } while (local_e != 'N' && local_e != 'Y');

        if (local_e == 'N')
            break;

        SHOPPES_0026(/*0x5066*/ "\n\n$ asks,\n\"Art thou here\nto Pick up or\n");
        ULTIMA_1850_PrintString(/*0x508e*/ "Leave a\ncompanion, or\nto Rest for the\nnight?\" ");

        do
        {
            local_e = ULTIMA_266c_GetChar();
            iVar5 = local_a;

            if (local_e == ' ')
            {
                bVar3 = 1;
                local_a = iVar5;
            }
            else if (local_e == 'L')
            {
                iVar6 = SHOPPES3_02ae(uVar1, uVar2, local_a);
                if (iVar6 > -2)
                {
                    iVar5 = iVar6;
                }

                local_a = iVar5;
                if (iVar5 == -1)
                {
                    bVar3 = 1;
                    local_a = iVar5;
                }
            }
            else if (local_e == 'P')
            {
                iVar5 = SHOPPES3_04e6(uVar1, local_a);
                local_a = iVar5;
                if (iVar5 == -1)
                {
                    bVar3 = 1;
                    local_a = iVar5;
                }
            }
            else if (local_e == 'R')
            {
                iVar5 = SHOPPES3_0072(uVar1, uVar2, local_a);
                if (iVar5 > -2)
                {
                    bVar3 = 1;
                    local_a = iVar5;
                }
            }
            else
            {
                local_e = '\0';
            }
        } while (local_e == '\0');

        if (!bVar3)
        {
            ULTIMA_1850_PrintString(/*0x50bd*/ "\"Is there\nanything more\nI can do for\nthee?\" ");
        }
    }

    SHOPPES_0202(local_a);
}
