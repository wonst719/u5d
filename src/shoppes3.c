#include "common.h"
#include "funcs.h"
#include "vars.h"

void TOWN_0170(void);
void TOWN_0958(void);
void TOWN_1694(void);

void SHOPPES_0026(char* param_1);
void SHOPPES_017a(int param_1);
void SHOPPES_019a(void);
void SHOPPES_01b6(void);
void SHOPPES_0202(int param_1);
int SHOPPES_0280(void);

// OK P1
int SHOPPES3_0000(void)
{
    int local_6;
    int local_4;

    local_4 = 0;

    for (local_6 = 0; local_6 < 0x10; local_6++)
    {
        if (D_55a8_party[local_6]._1f == D_5893_map_id)
        {
            local_4++;
        }
    }

    return local_4;
}

// OK P1
int SHOPPES3_002c(int param_1)
{
    ULTIMA_1850_PrintString(/*0x4d84*/ "\n\n");

    if (SHOPPES3_0000() < D_4dc4[D_b114])
    {
        return 1;
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
        return 0;
    }
}

// OK P1
int SHOPPES3_0072(int param_1, int param_2, int param_3)
{
    byte local_4;
    byte local_8;
    int local_a;
    S_55a8* local_6;

    ULTIMA_16ba_PrintChar(0x52);
    if (SHOPPES3_002c(param_2) != 0)
    {
        ULTIMA_16ba_PrintChar(0x22);

        D_b118 = D_4d7e[D_b114] * D_585b;
        D_b118 += D_b118 * -((s32)(param_1 * 3) - 100) / (u32)100;

        SHOPPES_017a(D_4e6e[D_b114]);
        ULTIMA_1850_PrintString(/*0x4dca*/ "\nWilt thou take\nit?\" ");
        local_8 = SHOPPES_0280();
        ULTIMA_1850_PrintString(/*0x4de0*/ "\n\n");
        if (local_8 == 'Y')
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
                ULTIMA_39cc_SetTile(D_594f, D_5950, D_5951);

                D_5896_map_x = D_4e7a[D_b114];
                D_5897_map_y = D_4e80[D_b114];
                D_24e6 = 1;

                local_4 = D_587b;

                for (local_a = 0; local_a < D_585b; local_a++)
                {
                    if (D_55a8_party[local_a]._b == 'G')
                    {
                        D_55a8_party[local_a]._b = 'S';
                    }
                }

                ULTIMA_2900_UpdateVitalsDisplay();
                ULTIMA_5910_UpdateFrame();
                ULTIMA_1850_PrintString(/*0x4e44*/ "Zzzzzz....\n\n");

                for (local_a = 0; local_a < 0xc; local_a++)
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

                // e3e0
                for (local_a = 0; local_a < D_585b; local_a++)
                {
                    local_6 = &D_55a8_party[local_a];

                    if (local_6->_b != 'D')
                    {
                        local_6->_10 = local_6->_12;

                        switch (local_6->_a)
                        {
                        case 'A':
                        case 'M':
                            local_6->_f = local_6->_e;
                            break;

                        case 'B':
                            local_6->_f = local_6->_e >> 1;
                            break;
                        }

                        if (local_6->_b == 'P')
                        {
                            local_6->_b = 0x44;
                            local_6->_10 = 0;

                            ULTIMA_16ba_PrintChar(10);
                            ULTIMA_1850_PrintString(local_6->_0);
                            ULTIMA_1850_PrintString(/*0x4e5b*/ " has\npassed away.\n");
                        }
                        else if (local_6->_b == 'S')
                        {
                            local_6->_b = 0x47;
                        }
                    }
                }

                D_587b = local_4;
                D_5896_map_x++;
                D_24e6 = 1;
                ULTIMA_2900_UpdateVitalsDisplay();

                param_3 = -1;
            }
        }
    }
    else
    {
        param_3 = -2;
    }

    return param_3;
}

// OK P1
int SHOPPES3_02ae(int param_1, int param_2, int param_3)
{
    bool local_24;
    byte local_26;
    int local_28;
    int local_2a;
    S_55a8 local_22;

    ULTIMA_16ba_PrintChar(0x4c);

    if (SHOPPES3_002c(param_2) == 0)
    {
        return param_3;
    }

    if (D_585b == 1)
    {
        SHOPPES_017a(0x26e8);
        param_3 = -1;
    }
    else
    {
        do
        {
            local_24 = 1;
            SHOPPES_0026(/*0x4e86*/ "$ asks,\n\"Who will\nstay?\" ");
            local_2a = ULTIMA_2e8e();
            if (local_2a == -1)
            {
                ULTIMA_1850_PrintString(/*0x4ea0*/ "Nobody\n\n");
                param_3 = -2;
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x4ea9*/ "\n\n");
                if (local_2a == 0)
                {
                    ULTIMA_1850_PrintString(/*0x4eac*/ "Thy friend");
                    if (D_585b > 2)
                    {
                        ULTIMA_16ba_PrintChar(0x73);
                    }
                    ULTIMA_1850_PrintString(/*0x4eb7*/ " will not leave thee!\n\n");
                    local_24 = 0;
                }
                else if (D_55a8_party[local_2a]._b == 'D')
                {
                    SHOPPES_017a(0x2723);
                    param_3 = -1;
                }
                else
                {
                    D_b118 = (uint)D_4d7e[D_b114] * 10;
                    D_b118 += D_b118 * -((s32)(param_1 * 3) + 100) / (u32)100;

                    ULTIMA_1850_PrintString(/*0x4ecf*/ "\"The rate for\nour most comfortable room will be ");
                    SHOPPES_0026(/*0x4f00*/ "% gold per month, due at check-out.");
                    ULTIMA_1850_PrintString(/*0x4f24*/ "\nWilt thou take\nit?\" ");
                    local_26 = SHOPPES_0280();
                    ULTIMA_1850_PrintString(/*0x4f3a*/ "\n\n");
                    if (local_26 == 'Y')
                    {
                        param_3 = 1;
                        if (D_587b == local_2a)
                        {
                            D_587b = 0xff;
                        }
                        else if (local_2a < D_587b && D_587b != 0xff)
                        {
                            D_587b--;
                        }

                        D_55a8_party[local_2a]._1f = D_5893_map_id;
                        D_55a8_party[local_2a]._17 = 0;

                        local_22 = D_55a8_party[local_2a];

                        for (local_28 = local_2a; local_28 < 0xf; local_28++)
                        {
                            D_55a8_party[local_28] = D_55a8_party[local_28 + 1];
                        }

                        D_55a8_party[0x10 - 1] = local_22;

                        D_585b--;
                        ULTIMA_2900_UpdateVitalsDisplay();
                        SHOPPES_0026(/*0x4f3d*/ "\"I thank thee.\"\nsays $.\n\n");
                    }
                }
            }
        } while (!local_24);
    }

    return param_3;
}

// OK P1
int SHOPPES3_0494(int param_1)
{
    while (--param_1)
    {
        if (D_55a8_party[param_1]._1f == D_5893_map_id)
        {
            break;
        }
    }

    return param_1;
}

// OK P1
int SHOPPES3_04b6(int param_1)
{
    while (++param_1 < 0x10)
    {
        if (D_55a8_party[param_1]._1f == D_5893_map_id)
        {
            break;
        }
    }

    if (param_1 == 0x10)
    {
        return 0;
    }

    return param_1;
}

// OK P1
int SHOPPES3_04e6(int param_1, int param_2)
{
    bool local_2a;
    byte local_32;
    int local_2e;
    int local_28;
    int local_34;
    uint local_2c;
    S_55a8 local_24;
    int local_4;
    int local_30;
    S_55a8* local_26;

    local_4 = SHOPPES3_0000();

    if (D_585b == 6)
    {
        ULTIMA_1850_PrintString(/*0x4f57*/ "\n\nOne must first be left behind!\n\n");
    }
    else if (local_4 == 0)
    {
        SHOPPES_0026(/*0x4f7a*/ "\n\n\"No one here is from thy party!\"\nsays $.\n\n");
    }
    else
    {
        if (local_4 > 1)
        {
            // e6ff
            ULTIMA_1850_PrintString(/*0x4fa7*/ "\n\n\"Who will\ncheck out?\" ");
            ULTIMA_1b94_SelectTextWindow(1);
            ULTIMA_4efc();
            ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x26, 9);
            ULTIMA_16ba_PrintChar(0xff);
            ULTIMA_1c22_SetTextWindowSize(1, 0x18, 1, 0x27, 9);
            ULTIMA_16ba_PrintChar(0x10);

            for (local_2e = 0; local_2e < 0xd; local_2e++)
            {
                ULTIMA_16ba_PrintChar(0x11);
            }

            ULTIMA_16ba_PrintChar(0x13);

            for (local_2e = 1; local_2e < 8; local_2e++)
            {
                ULTIMA_1bf2_SetTextPosition(0, local_2e);
                ULTIMA_16ba_PrintChar(0x17);
                ULTIMA_1bf2_SetTextPosition(0xe, local_2e);
                ULTIMA_16ba_PrintChar(0x17);
            }

            ULTIMA_16ba_PrintChar(10);
            ULTIMA_16ba_PrintChar(0x14);

            for (local_2e = 0; local_2e < 0xd; local_2e++)
            {
                ULTIMA_16ba_PrintChar(0x15);
            }

            ULTIMA_16ba_PrintChar(0x16);
            ULTIMA_1bf2_SetTextPosition(1, 1);
            ULTIMA_1850_PrintString(/*0x4fc0*/ "    GUEST");
            ULTIMA_1bf2_SetTextPosition(1, 2);
            ULTIMA_1850_PrintString(/*0x4fca*/ "  REGISTER:\n\n");

            // e7d6
            for (local_34 = 1; local_34 < 0x10; local_34++)
            {
                if (D_55a8_party[local_34]._1f == D_5893_map_id)
                {
                    ULTIMA_1bf2_SetTextPosition(4, ULTIMA_1cee_GetCurrentTextY());

                    ULTIMA_1850_PrintString(D_55a8_party[local_34]._0);
                    ULTIMA_16ba_PrintChar(10);
                }
            }

            ULTIMA_1b94_SelectTextWindow(2);
            local_2a = 0;
            local_34 = SHOPPES3_04b6(0);
            local_30 = 0x28;
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);

            while (!local_2a)
            {
                ULTIMA_0b86_GRAP_XorFillRect(0xc6, local_30, 0x131, local_30 + 7);

                // si = local_28

                do
                {
                    local_32 = ULTIMA_266c_GetChar();
                    switch (local_32)
                    {
                    case 1:
                    case 3:
                        // e85c
                        local_28 = SHOPPES3_0494(local_34);
                        if (local_28 != 0)
                        {
                            ULTIMA_0b86_GRAP_XorFillRect(0xc6, local_30, 0x131, local_30 + 7);
                            local_34 = local_28;
                            local_30 -= 8;
                        }
                        // -> e87e
                        break;

                    case 2:
                    case 4:
                        // e884
                        local_28 = SHOPPES3_04b6(local_34);
                        if (local_28 != 0)
                        {
                            ULTIMA_0b86_GRAP_XorFillRect(0xc6, local_30, 0x131, local_30 + 7);
                            local_34 = local_28;
                            local_30 += 8;
                        }
                        break;

                    case 0x1b:
                        // e8a8
                        ULTIMA_1850_PrintString(/*0x4fd8*/ "No one\n\n");
                        local_34 = 0;

                        local_28 = 1;
                        local_2a = 1;
                        break;

                    case 0x20:
                    case 0xd:
                        // e8b4
                        local_28 = 1;
                        local_2a = 1;
                        break;

                    default:
                        // e8d0
                        local_28 = 0;
                        break;
                    }

                    // e87e
                } while (local_28 == 0);
            }

            // e8e0
            ULTIMA_4f3c();
            ULTIMA_2900_UpdateVitalsDisplay();
        }
        else
        {
            local_34 = SHOPPES3_04b6(0);
        }

        if (local_34 != 0)
        {
            local_2c = (uint)D_55a8_party[local_34]._17;
            if (local_2c == 0)
            {
                local_2c = 1;
            }

            D_b118 = (uint)D_4d7e[D_b114] * 10;
            D_b118 += D_b118 * -((s32)(param_1 * 3) - 100) / (u32)100;

            D_b118 = local_2c * D_b118;

            SHOPPES_0026(/*0x4fe1*/ "\n\n\"That will be % gold, please.\"\n\n\"");
            if (D_57aa < D_b118)
            {
                SHOPPES_017a(0x275a);
                TOWN_0958();
                param_2 = -1;
            }
            else
            {
                D_57aa -= D_b118;

                SHOPPES_019a();
                ULTIMA_2900_UpdateVitalsDisplay();
                param_2 = 1;

                local_24 = D_55a8_party[local_34];

                for (local_2e = local_34; local_2e > (int)D_585b; local_2e--)
                {
                    D_55a8_party[local_2e] = D_55a8_party[local_2e - 1];
                }

                // e9ff
                D_55a8_party[D_585b] = local_24;

                local_26 = &D_55a8_party[D_585b++];

                local_26->_1f = 0;
                if (local_26->_b == 'P')
                {
                    local_26->_b = 0x44;
                    local_26->_10 = 0;

                    ULTIMA_1850_PrintString(/*0x5005*/ "Thy friend has died, by the way.\"\n");
                }
                else
                {
                    local_26->_10 = local_26->_12;

                    switch (local_26->_a)
                    {
                    case 'A':
                    case 'M':
                        local_26->_f = local_26->_e;
                        break;
                    case 'B':
                        local_26->_f = local_26->_e >> 1;
                        break;
                    }

                    ULTIMA_1850_PrintString(/*0x5028*/ "I hope thou hast found thy stay enjoyable,\"\n");
                }

                SHOPPES_0026(/*0x5055*/ "says $.\n\n");
                ULTIMA_2900_UpdateVitalsDisplay();
            }
        }
    }

    return param_2;
}

// OK P1
void SHOPPES3_08b4(int param_1)
{
    int local_6;
    int local_c;
    bool local_4;
    int local_8;
    byte local_e;
    int local_a;

    local_4 = local_a = 0;

    local_6 = D_55a8_party[param_1]._e;
    local_c = D_55a8_party[param_1]._9;

    D_587a = D_588e = 0;

    ULTIMA_2900_UpdateVitalsDisplay();

    SHOPPES_01b6();

    while (!local_4)
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

            switch (local_e)
            {
            case 0x52:
                // eb2c
                local_8 = SHOPPES3_0072(local_6, local_c, local_a);
                if (local_8 > -2)
                {
                    local_a = local_8;
                    // eb3f
                    local_4 = 1;
                }
                // -> eb44
                break;

            case 0x20:
                // eb3f
                local_4 = 1;
                // -> eb44
                break;

            case 0x4c:
                // eb4c
                local_8 = SHOPPES3_02ae(local_6, local_c, local_a);
                if (local_8 > -2)
                {
                    local_a = local_8;
                }

                // eb5f
                if (local_a == -1)
                {
                    // -> eb3f
                    local_4 = 1;
                }
                break;

            case 0x50:
                // eb66
                local_a = SHOPPES3_04e6(local_6, local_a);
                // -> eb5f
                if (local_a == -1)
                {
                    // -> eb3f
                    local_4 = 1;
                }
                break;

            default:
                local_e = 0;
            }

            // eb44
        } while (local_e == 0);

        if (!local_4)
        {
            ULTIMA_1850_PrintString(/*0x50bd*/ "\"Is there\nanything more\nI can do for\nthee?\" ");
        }
    }

    SHOPPES_0202(local_a);
}
