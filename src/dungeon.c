#include "common/common.h"
#include "funcs.h"
#include "vars.h"
#include "macros.h"

#include <string.h>

#include "blckthrn.h"
#include "combat.h"
#include "dnglook.h"
#include "dungeon.h"
#include "endgame.h"

void DNGLOOK_109e(int param_1);

// OK P1
static void DUNGEON_0000(byte param_1)
{
    int local_4;
    int local_6;
    int local_8;

    ActorFmt local_12;
    ActorFmt local_1a;

    int local_1e;
    int local_1c;
    int local_a;

    ULTIMA_1850_PrintString(/*0x2c58*/ "Entering room...\n");

    D_6603 = D_2c76[D_6602];

    ULTIMA_1b16_ClearKbdBuffer();

    local_1c = param_1 & 0xf;
    local_4 = D_587b;
    D_589e = D_587b = 0xff;

    local_1e = D_5893_map_id - 0x21;
    if (local_1e >= 1)
    {
        local_1e--;
    }

    local_a = 0x1600 * local_1e + local_1c * 0x160;

    memset(D_ad14, 0, 0x160);

    ULTIMA_256e_ReadFileFromDisk(/*0x2c6a*/ "dungeon.cbt", D_ad14, 0x160, local_a);

    D_5894 = D_5893_map_id;
    local_6 = D_5896_map_x;
    local_8 = D_5897_map_y;

    local_12 = D_5c5a[1];
    local_1a = D_5c5a[2];

    D_5893_map_id = 0xff;
    D_58a0 = 0;

    DNGLOOK_117e(param_1, 3);
    ULTIMA_5910_UpdateFrame();

    D_58a1 = 0x82;

    if (COMBAT_0b94_MainLoop() == 0)
    {
        if (D_58a0 == 0x4d)
        {
            ENDGAME_0648_EndgameMain();
        }

        D_5893_map_id = D_5894;
        DNGLOOK_0844(local_1c);
        GetDungeonMap((uint)local_6, (uint)local_8, (uint)D_5895_map_level) &= 0xaf;
    }

    D_5897_map_y = local_8;
    D_5896_map_x = local_6;
    D_5893_map_id = D_5894;

    DNGLOOK_0fda();

    D_5c5a[1] = local_12;
    D_5c5a[2] = local_1a;
    D_587b = local_4;
}

static int DUNGEON_0252(void);

// OK P1
void DUNGEON_0134(int param_1)
{
    ActorFmt* local_4;
    int local_6;
    int local_8;

    local_4 = &D_5c5a[1];
    local_6 = D_5c5a[1]._5;
    if (param_1 != 0)
    {
        local_8 = ULTIMA_2092_RandomRange(0, 7);
        D_5c5a[1]._0_tile = D_5c5a[1]._1_animTile = local_8;
        D_5c5a[1]._7 = 0;
        D_5c5a[1]._6 = D_1744[local_8];
        D_5c5a[1]._5 = D_173c[local_8];
        D_5c5a[1]._4_z = D_5895_map_level;
        if (local_6 != 0xff)
        {
            ULTIMA_0be4_FreeImage(D_a9c6);
        }
        D_a9c6 = 0;
        if (DUNGEON_0252() == 0)
        {
            local_4->_0_tile = local_4->_1_animTile = 0;
            local_4->_5 = 0xff;
        }
    }

    if (local_4->_5 != 0xff)
    {
        do
        {
            D_a9c6 = ULTIMA_0bae_LoadImageFile(D_25ea[local_4->_0_tile + 8]);
        } while (D_a9c6 == 0);
    }
}

// OK P1
static void DUNGEON_01d2_PrintWalkDir(void)
{
    int local_4;
    int local_6;

    local_4 = D_5386_current_text_window_idx;
    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(0xc, 0);
    local_6 = D_5895_map_level + 1;
    ULTIMA_1a3e_PrintNumber(local_6, 1, 0x20);
    ULTIMA_1bf2_SetTextPosition(0xc, 0x17);

    switch (D_6603)
    {
    case 0:
        ULTIMA_1850_PrintString(/*0x2c7c*/ "North");
        break;
    case 1:
        ULTIMA_1850_PrintString(/*0x2c82*/ " East");
        break;
    case 2:
        ULTIMA_1850_PrintString(/*0x2c88*/ "South");
        break;
    case 3:
        ULTIMA_1850_PrintString(/*0x2c8e*/ " West");
        break;
    default:
        ULTIMA_1850_PrintString(/*0x2c94*/ " ????");
        break;
    }

    ULTIMA_1b94_SelectTextWindow(local_4);
}

// OK P1
static int DUNGEON_0252(void)
{
    byte local_c;
    int local_a;
    int local_8;
    byte* local_e;
    int local_6;
    int local_4;

    for (local_8 = 0; local_8 < 8; local_8++)
    {
        // 0262
        local_e = &GetDungeonMap(0, 0, D_5895_map_level);
        local_a = ULTIMA_2092_RandomRange(0, 0x3f);
        local_e += local_a;
        local_c = *local_e & 0xf0;
        if (local_c < 0x60 || local_c == 0x70)
        {
            // 0292
            local_6 = local_a / 8;
            local_4 = local_a % 8;
            if (local_4 != D_5896_map_x && local_6 != D_5897_map_y)
            {
                D_5c5a[1]._2_x = D_5c5a[2]._2_x = local_4;
                D_5c5a[1]._3_y = D_5c5a[2]._3_y = local_6;

                if ((D_5c5a[1]._5 == 0x16 || D_5c5a[1]._5 == 0x18) && (int)ULTIMA_2092_RandomRange(0, 99) > 0x30)
                {
                    D_5c5a[1]._7 = 0xff;
                }

                local_a = 1;
                break;
            }
        }
    }

    if (local_8 == 8)
    {
        D_5c5a[1]._2_x = D_5c5a[2]._2_x = D_5c5a[1]._3_y = D_5c5a[2]._3_y = 0xff;
        local_a = 0;
    }

    return local_a;
}

// OK P1
static void DUNGEON_0332(void)
{
    int local_4;

    local_4 = D_5386_current_text_window_idx;
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
    ULTIMA_0aa6_GRAP_3f_FillRect(0x28, 0, 0x98, 7);
    ULTIMA_0aa6_GRAP_3f_FillRect(0x30, 0xb9, 0x98, 0xbf);
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b10_GRAP_Line(0x28, 7, 0x98, 7);
    ULTIMA_0b10_GRAP_Line(0x30, 0xb8, 0x98, 0xb8);
    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1bf2_SetTextPosition(10, 0);
    ULTIMA_4c2a();
    ULTIMA_1850_PrintString(/*0x2c9a*/ "L ");
    ULTIMA_4cce();
    ULTIMA_1bf2_SetTextPosition(6, 0x17);
    ULTIMA_4c2a();
    ULTIMA_1850_PrintString(/*0x2c9d*/ "Dir:      ");
    ULTIMA_4cce();
    ULTIMA_1b94_SelectTextWindow(local_4);
}

static void DUNGEON_1020(void);

// OK P1
static int DUNGEON_03d6(void)
{
    int local_6;
    int local_4;

    if (D_a9fa != 0)
    {
        ULTIMA_2900_UpdateVitalsDisplay();
        D_a9fa = 0;
    }

    ULTIMA_16ba_PrintChar(10);
    ULTIMA_4c2a();

    local_4 = 1;
    do
    {
        local_6 = ULTIMA_2032_ToUpper(ULTIMA_1b38_PollKeyWithCursor());
        if (local_6 != 0 && local_6 < 5 && D_538a == 0)
        {
            local_6 += 0xfa;
        }

        if (local_6 == 0)
        {
            DUNGEON_1a90(local_4);
            if (local_4 != 0)
            {
                ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0x10, 0xe, 0xaf, 0xb2);
            }
            else
            {
                ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0x28, 0xe, 0x96, 0xb2);
            }

            if (D_6604 != 1)
            {
                local_4 = 0;
            }

            DUNGEON_1020();
        }
    } while (local_6 == 0);

    return local_6;
}

// OK P1
static void DUNGEON_0470_ElectricField(int param_1)
{
    DUNGEON_1be0();
    ULTIMA_1850_PrintString(/*0x2ca8*/ "Ouch!\n");
    ULTIMA_1850_PrintString(/*0x2caf*/ "Electric field!\n");
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);
    ULTIMA_20fa_WaitTicks(1);
    ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);
    ULTIMA_223c_AudioWhiteNoise(1, 500, 20000);
    if (param_1 > 0)
    {
        D_5896_map_x -= D_24d6[D_6603];
        D_5897_map_y -= D_24de[D_6603];
    }
    else
    {
        D_5896_map_x += D_24d6[D_6603];
        D_5897_map_y += D_24de[D_6603];
    }
    ULTIMA_2aa8();
    DUNGEON_1be0();
}

// OK P1
static int DUNGEON_0502(int param_1, byte param_2)
{
    byte local_c;
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    local_6 = 0;
    local_4 = 0;

    switch (param_1)
    {
    case 3:
        // 0542
        ULTIMA_1850_PrintString(/*0x2cc0*/ "Advance\n");
        local_6 = 1;
        break;

    case 2:
        // 0628
        if ((param_2 & 0xf0) == 0xe0)
        {
            ULTIMA_1850_PrintString(/*0x2cc9*/ "Not in doorway!\n"); // -> 0666
        }
        else
        {
            // 0636
            ULTIMA_1850_PrintString(/*0x2cda*/ "Turn right\n");
            D_6603 = (D_6603 + 1) & 3;
        }
        break;

    case 4:
        // 064a
        ULTIMA_1850_PrintString(/*0x2ce6*/ "Back up\n");
        local_6 = -1;
        break;

    case 1:
        // 065a
        if ((param_2 & 0xf0) == 0xe0)
        {
            // 0666
            ULTIMA_1850_PrintString(/*0x2cef*/ "Not in doorway!\n");
        }
        else
        {
            // 066e
            ULTIMA_1850_PrintString(/*0x2d00*/ "Turn left\n");
            D_6603 = (D_6603 + 3) & 3;
        }
        break;

    default:
        // 0533
        ULTIMA_1850_PrintString(/*0x2d0b*/ "Turn around.\n");
        D_6603 = (D_6603 + 2) & 3; // -> 0642 -> 054e
        break;
    }

    D_6602 = D_6603;

    if (local_6 != 0)
    {
        local_4 = 1;
        local_8 = D_24d6[D_6603] * local_6 + D_5896_map_x;
        if (local_8 < 0)
        {
            local_8 = 7;
        }

        if (local_8 > 7)
        {
            local_8 = 0;
        }

        local_a = D_24de[D_6603] * local_6 + D_5897_map_y;
        if (local_a < 0)
        {
            local_a = 7;
        }

        if (local_a > 7)
        {
            local_a = 0;
        }

        // 05bc
        local_c = GetDungeonMap(local_8, local_a, D_5895_map_level);
        if (local_c == 0x83)
        {
            D_5896_map_x = local_8;
            D_5897_map_y = local_a;
            DUNGEON_0470_ElectricField(local_6);
            local_8 = D_5896_map_x;
            local_a = D_5897_map_y;
        }

        // 05fb
        local_c &= 0xf0;
        if (local_c > 0xa0 && local_c < 0xe0 || local_6 == -1 && (local_c == 0xa0 || local_c == 0xf0))
        {
            // 061d
            ULTIMA_1850_PrintString(/*0x2d19*/ "Blocked!\n");
        }
        else
        {
            // 067c~: OK
            if (local_8 == D_5c5a[1]._2_x && local_a == D_5c5a[1]._3_y)
            {
                ULTIMA_1850_PrintString(/*0x2d23*/ "Blocked!\n");
            }
            else
            {
                // 0694
                D_a9fb = 0xf;
                D_24e7 = 0;
                DUNGEON_1020();
                D_24e7 = 0;
                D_5896_map_x = (byte)local_8 & 7;
                D_5897_map_y = (byte)local_a & 7;
            }
        }
    }

    // 06b6
    DUNGEON_1be0();
    return local_4;
}

// OK P1
static int DUNGEON_06c4_ProcessCommand(int param_1)
{
    byte local_6;
    int local_4;

    local_4 = 1;
    switch (param_1)
    {
    case 0xb:
        // 06f2
        ULTIMA_1a3e_PrintNumber(D_5888, 1, 0x20);
        ULTIMA_16ba_PrintChar(10);
        break;

    case 5:
        // 0710
        ULTIMA_1850_PrintString(/*0x2d2d*/ "Exit to DOS? ");
        param_1 = ULTIMA_266c_GetChar();
        if (param_1 == 0x59)
        {
            ULTIMA_0878_RestoreVideoMode();
            exit(0);
            // nop?
            break;
        }
        ULTIMA_1850_PrintString(/*0x2d3b*/ "N\n");
        break;

    case 0x16:
        // 073a
        ULTIMA_1850_PrintString(/*0x2d3e*/ "1.16");
        ULTIMA_16ba_PrintChar(10);
        break;

    case 1:
    case 2:
    case 3:
    case 4:
    case 0xd:
    case 0x2e:
        // 0744
        local_6 = GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level);
        local_4 = DUNGEON_0502(param_1, local_6);
        // ?
        break;

    case 0x13:
        // 0776
        ULTIMA_1850_PrintString(/*0x2d43*/ "Sound ");
        if (D_a9ce != 0)
        {
            ULTIMA_1850_PrintString(/*0x2d4a*/ "Off\n");
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x2d4f*/ "On\n");
        }
        D_a9ce = !D_a9ce;
        break;

    default:
        if ((uint)param_1 >= 0x30 && (uint)param_1 <= 0x39)
        {
            local_4 = ULTIMA_4080(param_1);
            local_4 = 0;
        }
        else
        {
            local_4 = ULTIMA_3178_ProcessCommand(param_1);
        }
        break;
    }

    return local_4;
}

// OK P1
static int DUNGEON_07e2(void)
{
    ActorFmt* local_4;
    int local_6;
    int local_8;
    int local_a;
    int local_c;
    int local_e;
    int local_10;
    int local_12;
    int local_14;
    byte local_16;
    ActorFmt* local_18;

    local_c = 0;
    local_10 = 0;
    local_e = 999;
    local_4 = &D_5c5a[1];
    local_18 = &D_5c5a[2];

    if (D_5c5a[1]._5 != 0xff)
    {
        if (local_4->_5 != 0x1b)
        {
            // 0819
            for (local_c = 0; local_c < 8; local_c++)
            {
                // 083e
                local_a = ULTIMA_2092_RandomRange(0, 3);
                local_12 = D_24d6[local_a] + local_4->_2_x;
                if (local_12 > 7)
                {
                    local_12 = 0;
                }
                if (local_12 < 0)
                {
                    local_12 = 7;
                }

                // 0866
                local_14 = D_24de[local_a] + local_4->_3_y;
                if (local_14 > 7)
                {
                    local_14 = 0;
                }
                if (local_14 < 0)
                {
                    local_14 = 7;
                }

                // 0882
                local_16 = GetDungeonMap(local_12, local_14, D_5895_map_level);
                local_16 &= 0xf0;

                if (local_16 != 0x60 && local_16 != 0x80 && local_16 < 0xa0)
                {
                    local_6 = local_18->_2_x;
                    local_8 = local_18->_3_y;
                    if (local_12 != local_6 || local_14 != local_8 || ULTIMA_2092_RandomRange(0, 7) == 1)
                    {
                        local_e = 900;
                        break;
                    }
                }
            }

            // 08d6
            if (local_e == 900)
            {
                local_18->_2_x = local_4->_2_x;
                local_18->_3_y = local_4->_3_y;
                local_4->_2_x = (byte)local_12;
                local_4->_3_y = (byte)local_14;
            }
        }

        // 0917
        if (local_4->_2_x == D_5896_map_x && local_4->_3_y == D_5897_map_y)
        {
            local_10 = 1;
            local_4->_2_x = local_18->_2_x;
            local_4->_3_y = local_18->_3_y;
        }
    }
    return local_10;
}

// OK P1
// sleep spell
static void DUNGEON_0948_SleepSpell(void)
{
    int local_4;

    ULTIMA_1850_PrintString(/*0x2d53*/ "Sleep spell!\n");

    for (local_4 = 0; local_4 < D_585b; local_4++)
    {
        if (D_55a8_party[local_4].dex <= ULTIMA_2092_RandomRange(1, 0x1e) && D_55a8_party[local_4].status != 'D')
        {
            D_55a8_party[local_4].status = 'S';
            ULTIMA_2a28(local_4);
            ULTIMA_223c_AudioWhiteNoise(1, 0x32, 0xdac);
            D_a9fa = 1;
        }
    }

    GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level) &= 8;
}

// OK P1
// poison
static void DUNGEON_09e6_Poison(void)
{
    int local_4;

    ULTIMA_1850_PrintString(/*0x2d61*/ "Poison!\n");

    for (local_4 = 0; local_4 < D_585b; local_4++)
    {
        if (D_55a8_party[local_4].dex <= ULTIMA_2092_RandomRange(1, 0x1e) && D_55a8_party[local_4].status != 'D')
        {
            D_55a8_party[local_4].status = 'P';
            ULTIMA_223c_AudioWhiteNoise(1, 0x32, 0xdac);
        }
    }
}

// OK P1
static void DUNGEON_0a4c(byte param_1)
{
    D_6602 = 5;

    while ((param_1 == 0x61 || param_1 == 0x69) && D_5895_map_level < 8)
    {
        ULTIMA_1850_PrintString(/*0x2d6a*/ "Pit Trap!\n");
        ULTIMA_1850_PrintString(/*0x2d75*/ "Falling...\n");

        GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level) &= 0xf8;

        D_5895_map_level++;

        param_1 = GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level);
        if (param_1 < 0x90)
        {
            param_1 = param_1 | 8;
            GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level) = param_1;
        }

        DUNGEON_1be0();
        ULTIMA_1850_PrintString(/*0x2d81*/ "      ...splat!\n");
        ULTIMA_2aa8();
    }

    if (D_5895_map_level == 8)
    {
        D_5893_map_id = 0;
    }

    if (D_5893_map_id != 0)
    {
        param_1 = GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level);
        param_1 &= 0xf0;
        if (param_1 == 0xa0 || param_1 == 0xf0)
        {
            DNGLOOK_1130();
            DUNGEON_0000(GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level));
            if (D_5893_map_id == 0)
            {
                return;
            }

            DNGLOOK_109e(1);
        }

        DUNGEON_0134(1);
    }
}

// OK P1
// attacked
static void DUNGEON_0b7e(void)
{
    ActorFmt* local_4;

    ULTIMA_1850_PrintString(/*0x2d92*/ "Attacked");

    local_4 = &D_5c5a[2];

    if (((local_4->_2_x - 1) & 7) == D_5896_map_x)
    {
        D_6602 = 1;
    }
    else if (((local_4->_2_x + 1) & 7) == D_5896_map_x)
    {
        D_6602 = 3;
    }
    else if (((local_4->_3_y - 1) & 7) == D_5897_map_y)
    {
        D_6602 = 2;
    }
    else
    {
        D_6602 = 0;
    }

    if (D_6602 != D_6603)
    {
        ULTIMA_1850_PrintString(/*0x2d9b*/ " from the ");

        switch (D_6602)
        {
        case 0:
            ULTIMA_1850_PrintString(/*0x2da6*/ "north");
            break;
        case 1:
            ULTIMA_1850_PrintString(/*0x2dac*/ "east");
            break;
        case 2:
            ULTIMA_1850_PrintString(/*0x2db1*/ "south");
            break;
        case 3:
            ULTIMA_1850_PrintString(/*0x2db7*/ "west");
            break;
        }

        D_6603 = D_6602;
    }

    ULTIMA_1850_PrintString(/*0x2dbc*/ "!\n");
    DUNGEON_1be0();
    ULTIMA_1b16_ClearKbdBuffer();
    ULTIMA_20fa_WaitTicks(2);
    DNGLOOK_1130();
    D_58a0 = 0;
    D_58a1 = 2;
    DNGLOOK_0d3e();
    ULTIMA_5f86_SpecialMapHandler(2, D_5c5a[1]._5, 0);
    DNGLOOK_0fda();
    DNGLOOK_109e(1);
    DUNGEON_0134(1);
    if (D_5893_map_id != 0)
    {
        DUNGEON_1be0();
    }
}

// OK P1
void DUNGEON_0c76(byte param_1, int param_2)
{
    int local_a;
    byte local_8;
    byte local_4;
    int local_6;

    local_a = 0;
    local_4 = param_1 & 0xf0;
    local_8 = 0;

    for (local_6 = 0; local_6 < D_585b; local_6++)
    {
        if (D_55a8_party[local_6].status == 'S' && ULTIMA_2092_RandomRange(0, 0x3f) < 4)
        {
            D_55a8_party[local_6].status = 'G';
            local_8++;
        }
    }

    if (local_8 != 0)
    {
        ULTIMA_2900_UpdateVitalsDisplay();
    }

    if (param_2 != 0)
    {
        local_a = DUNGEON_07e2();
    }

    if (local_a != 0)
    {
        DUNGEON_0b7e();
        param_1 = GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level);
        local_4 = param_1 & 0xf0;
    }

    // 0d17
    if (local_4 == 0xf0 || local_4 == 0xa0)
    {
        // 0d23
        DNGLOOK_1130();

        // 0d26
        while ((local_4 == 0xf0 || local_4 == 0xa0))
        {
            // 0d32
            if (ULTIMA_39fc_GetFirstActivePartyMember() > -1)
            {
                DUNGEON_0000(param_1);
                if (D_5893_map_id == 0)
                {
                    break;
                }

                // 0d62
                param_1 = GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level);
                local_4 = param_1 & 0xf0;
            }
            else
            {
                break;
            }
        }

        // 0d4a
        DNGLOOK_109e(1);

        if (D_5893_map_id > 0x20)
        {
            // 0d5b
            DUNGEON_1be0();
        }
        // -> 0e22
    }
    else
    {
        switch (param_1)
        {
        case 0x80:
        case 0x88:
            DUNGEON_0948_SleepSpell();
            break;

        case 0x81:
        case 0x89:
            DUNGEON_09e6_Poison();
            break;

        case 0x82:
        case 0x8a:
            ULTIMA_1850_PrintString(/*0x2dbf*/ "Fire!!\n");
            ULTIMA_2aa8();
            break;

        case 0x62:
        case 0x6a:
            ULTIMA_1850_PrintString(/*0x2dc7*/ "Bomb Trap!\n");
            ULTIMA_1850_PrintString(/*0x2dd3*/ "KABOOM!!\n");
            GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level) &= 8;
            ULTIMA_2aa8();
            break;

        case 0x61:
        case 0x69:
            DUNGEON_0a4c(param_1);
            break;
        }

        ULTIMA_2900_UpdateVitalsDisplay();
    }

    ULTIMA_2ae8();
}

// OK P1
void DUNGEON_0e2e_MainLoop(int param_1)
{
    int local_10;
    int local_e;
    int local_c;
    int local_a;
    u8 local_8;
    int local_6;
    u8 local_4;

#if !defined(TARGET_DOS16)
    local_c = 0;
#endif

    local_e = 1;
    local_10 = 0;
    local_6 = 0;
    D_bb17 = 2;
    DNGLOOK_093a();
    local_8 = GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level);
    local_8 &= 0xf0;
    DUNGEON_0332();
    DUNGEON_01d2_PrintWalkDir();
    local_a = D_5893_map_id - 0x20;
    if (local_a == 1 || local_a == 4 || local_a == 5)
    {
        // 0e95
        D_bb14 = 0x4f;
        D_bb15 = 0x45;
        D_6604 = 3;
    }
    else
    {
        // 0ea6
        D_bb14 = 0x4d;
        D_bb15 = 5;
        if (local_a == 6 || local_a == 7)
        {
            // 0ebc
            D_6604 = 2;
        }
        else
        {
            // 0ec4
            D_6604 = 1;
        }
    }

    // 0ec9
    if (local_8 == 0xa0 || local_8 == 0xf0)
    {
        // 0ed5
        DNGLOOK_1130();
        DUNGEON_0000(GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level));
    }

    if (D_5893_map_id > 0x20)
    {
        DNGLOOK_109e(param_1);
        DUNGEON_0134(param_1);
        DUNGEON_1be0();
    }

    // 0f15
    while (local_e != 0 && D_5893_map_id > 0x20) // 0f93
    {
        local_e = 1;
        local_c = 1;
        local_10 = ULTIMA_39fc_GetFirstActivePartyMember();
        if (local_10 == local_c)
        {
            ULTIMA_16ba_PrintChar(10);
            ULTIMA_4c2a();
            ULTIMA_1850_PrintString("Zzzzzz...\n");
        }

        // 0fc3
        if (local_10 < 0)
        {
            local_e = 0;
            local_c = 0;
        }

        // 0fd0
        if (local_10 != 0)
            continue;

        if (D_587a != 'T' && D_587a != 'Q')
        {
            // 0fea -> 0f2e
            local_6 = 1;
            ULTIMA_4f7c(1);
        }
        else
        {
            if (D_587a == 'Q')
            {
                local_6 ^= 1;
                if (local_6 != 0)
                {
                    ULTIMA_4f7c(1);
                }
            }
            else
            {
                local_6 = 0;
            }
        }

        // 0f36
        local_a = DUNGEON_03d6();
        if (local_a > -1)
        {
            local_c = DUNGEON_06c4_ProcessCommand(local_a);
        }

        if (D_5893_map_id < 0x21)
        {
            local_c = 0;
            local_e = local_c;
        }

        // 0f53
        local_4 = GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level & 0xff);
        local_8 = local_4 & 0xf0;
        if (local_c != 0)
        {
            DUNGEON_0c76(local_4, local_6);
        }

        if (D_5893_map_id >= 0x21)
        {
            continue;
        }

        local_c = 0;
        local_e = local_c;
    }

    // 0ff2
    if ((D_bb17 & 2) != 0)
    {
        D_bb17 &= 0xfb;
    }
    else
    {
        D_bb17 |= 4;
    }
    // 100b
    DNGLOOK_1130();
    if (local_10 < 0)
    {
        BLCKTHRN_0910_Death();
    }
}

// OK P1
static void DUNGEON_1020(void)
{
    D_24e7 ^= 1;
    if (D_24e7 != 0 && D_a9fb != 0)
    {
        ULTIMA_223c_AudioWhiteNoise(1, D_a9fb, 20000);
        ULTIMA_3f36(&D_a9fb, 4);
    }
}

// CHECKED (register)
static void DUNGEON_104c(int param_1)
{
    int local_4;

    if (param_1 <= D_2df0[D_5893_map_id - 0x21])
    {
        // 1063 (ok)
        local_4 = D_2de8[D_5893_map_id - 0x21] + param_1 - 1;
        ULTIMA_1c22_SetTextWindowSize(0, D_2df8[local_4], D_2e04[local_4], 0x27, 0x18);
        ULTIMA_1b94_SelectTextWindow(0);
        ULTIMA_1c9e_SelectCharset(1);
        ULTIMA_1bf2_SetTextPosition(0, 0);
        ULTIMA_16ba_PrintChar(0xfd);
        ULTIMA_1850_PrintString(D_2e10[local_4]);
        ULTIMA_16ba_PrintChar(0xfd);
        ULTIMA_1c9e_SelectCharset(0);
        ULTIMA_1b94_SelectTextWindow(2);
        ULTIMA_1c22_SetTextWindowSize(0, 0, 0, 0x27, 0x18);
    }
}

// OK P1
static int DUNGEON_10dc(int param_1, int param_2)
{
    int local_4;

    local_4 = GetDungeonMap(param_1 & 7, param_2 & 7, D_5895_map_level);
    if (local_4 < 0x90)
    {
        local_4 &= 0xf7;
    }

    return local_4;
}

// CHECKED (register)
static void DUNGEON_111e(int param_1)
{
    int uVar2;
    int local_c;
    int local_4;
    int local_e;
    int local_8;
    int local_6;
    int local_a;

    if (D_587a == 'T')
    {
        D_5c5a[1]._6 = D_1744[D_5c5a[1]._0_tile];
    }

    // 113a
    local_c = D_5c5a[1]._7 == 0xff;
    // 1148
    local_a = (D_5c5a[1]._6 & 0x90);
    local_4 = (D_5c5a[1]._6 & 0x60);
    local_8 = D_5c5a[1]._6 & 0xf;

    if (D_587a == 'T')
    {
        
        local_6 = local_e = 1;
    }
    else
    {
        local_6 = ULTIMA_2092_RandomRange(0, 100) < 0x32;
        local_e = ULTIMA_2092_RandomRange(0, 100) < 0x32;
        switch (local_4)
        {
        case 0x20:
            // 11c2
            local_e = local_6 = local_8 = local_8 == 0;
            break;
        case 0x40:
            break;
        case 0x60:
            // 11e6
            local_8--;
            if (local_8 < 0)
            {
                local_8 = 3;
            }
            local_6 = D_2e26[local_8] >> 1;
            local_e = D_2e26[local_8] & 1;
            break;
        }
    }

    // 11d3
    if (local_a != 0)
    {
        local_e = (local_a == 0x90) ^ local_6;
    }

    if (D_a9c6 == 0)
    {
        // debug message
        ULTIMA_1850_PrintString(/*0x6c4e*/ "Hey!! What's going on here???");
    }
    else
    {
        // 1220
        // NOT MATCHING: register
        ULTIMA_0d4c_GRAP_4b_PutImage(D_a9c6, local_6 * 3 + param_1 - 1, D_2e2a[param_1], D_2e32[local_c][param_1], local_c);

        // OK
        ULTIMA_0bfc_GRAP_63(D_a9c6, local_e * 3 + param_1 - 1, 0x60, D_2e32[local_c][param_1], local_c);
        D_5c5a[1]._6 = local_4 + local_a + local_8;
    }
}

// CHECKED (optimization)
static void DUNGEON_127e(int param_1, int param_2)
{
    int local_4;
    int local_6;
    int local_8;

    local_4 = D_52ba_vdp._52c4;
    D_52ba_vdp._52c4 = 0;

    switch (param_2)
    {
    case 0:
        // 12b4
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b6 + 8);
        break;
    case 1:
        // 1326
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b4 + 8);
        break;
    case 2:
        // 132c
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13ae + 8);
        break;
    case 3:
        // 1332
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color + 8);
        break;
    }

    // 12be NOT MATCHING
    for (local_8 = 0; local_8 < D_2e52[param_1]; local_8++)
    {
        local_6 = ULTIMA_2092_RandomRange(D_2e42[param_1], D_2e4a[param_1] - D_2e5a[param_1]);
        ULTIMA_0c9c_GRAP_39_HorizLine(local_6, ULTIMA_2092_RandomRange(D_2e42[param_1], D_2e4a[param_1]), D_2e5a[param_1] + local_6);
    }

    D_52ba_vdp._52c4 = local_4;
}

// OK P1
static void DUNGEON_134a(int param_1, int param_2, int param_3)
{
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    if (param_1 < 0x1f)
    {
        local_6 = (param_1 & 3);
        local_8 = D_2e62[param_3][local_6];
        if (param_3 != 0 && (((byte)param_1 & 0xf8) == 8 || ((byte)param_1 & 0xfc) == 0x18))
        {
            local_8 = 0x60;
        }

        local_a = 0xe;
        if (param_3 != 0)
        {
            ULTIMA_0bfc_GRAP_63(D_a9c0, param_1, local_8, local_a, 0);
        }
        else
        {
            ULTIMA_0d4c_GRAP_4b_PutImage(D_a9c0, param_1, local_8, local_a, 0);
        }
    }
    else
    {
        local_4 = ((param_1 + 1) >> 1) - 0x10;
        local_6 = ((param_1 + 1) & 6) >> 1;
        if (param_3 != 0)
        {
            local_8 = 0x60;
        }
        else
        {
            local_8 = D_2e72[local_6];
        }

        local_a = (local_4 < 8) ? (param_2 ? D_2e7a[1][local_6] : 0x60) : D_2e7a[param_2][local_6];

        if (param_3 != 0)
        {
            ULTIMA_0bfc_GRAP_63(D_a9c4, local_4, local_8, local_a, param_2);
        }
        else
        {
            ULTIMA_0d4c_GRAP_4b_PutImage(D_a9c4, local_4, local_8, local_a, param_2);
        }
    }
}

// OK P1
static int DUNGEON_145c(int param_1, int param_2, int param_3, int param_4)
{
    if (param_3 == 5)
    {
        param_3 = 0;
        ULTIMA_43ae_AudioSweepTone(0xc80, 0xdac, 1, -(param_4 * 8 + 0xec));
    }
    else
    {
        if (param_3 == 4)
        {
            if (D_52c8 == 0 || D_52c8 == 3)
            {
                ULTIMA_0a70_GRAP_2d_SetPenColor(3);
            }
            else
            {
                ULTIMA_0a70_GRAP_2d_SetPenColor(0xb);
            }
        }
        else
        {
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
        }

        ULTIMA_0c9c_GRAP_39_HorizLine(param_1 - 1, param_2, param_1 + 1);
        ULTIMA_0cf2_GRAP_3c_VertLine(param_1, param_2 - 1, param_2 + 1);

        if (param_3 < 4)
        {
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color + 8);
            ULTIMA_0c64_GRAP_30_Pset(param_1, param_2);
        }

        if (param_3 != 0 || (int)ULTIMA_2092_RandomRange(0, 0x40) < 4)
        {
            param_3++;
        }
    }

    return param_3;
}

// CHECKED (nop)
static int DUNGEON_150a(int param_1, int param_2, int param_3)
{
    int local_8;
    int local_6;
    int local_4;

    local_6 = DUNGEON_10dc(param_1, param_2);
    if (local_6 < 0xa0)
    {
        return 1;
    }

    local_4 = D_2e8a[(local_6 >> 4) - 0xa] + param_3;
    if (param_3 == 0)
    {
        local_4 = 0xc;
    }

    DUNGEON_134a(local_4, 0, 0);
    DUNGEON_134a(local_4, 0, 1);

    if ((param_3 == 1 || param_3 == 2) && D_6604 == 1 && (local_6 & 0xf0) == 0xc0)
    {
        local_8 = local_6 & 7;

#if !defined(TARGET_DOS16)
        if (local_8 >= 5)
        {
            debug("WARNING: local_8 >= 5");
        }
#endif

        local_8 = DUNGEON_145c(0x5f, D_2e90[local_8 + (param_3 - 1) * 5] + 0xe, local_8, param_3);

        GetDungeonMap(param_1 & 7, param_2 & 7, D_5895_map_level) &= 0xf8;
        GetDungeonMap(param_1 & 7, param_2 & 7, D_5895_map_level) += local_8;
    }

    if (param_3 == 1)
    {
        if ((local_6 & 0xf0) == 0xb0 && (local_6 & 0xf) != 0)
        {
            DUNGEON_104c(local_6 & 0xf);
            // NOT MATCHING: nop
        }
        else if (D_6604 == 3 && (local_6 & 0xf0) == 0xc0 && (int)ULTIMA_2092_RandomRange(0, 0x40) < 4)
        {
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13ae + 8);
            ULTIMA_0c9c_GRAP_39_HorizLine(0x5c, 0x57, 0x5d);
            ULTIMA_0c9c_GRAP_39_HorizLine(0x5b, 0x58, 0x5d);
            ULTIMA_0c9c_GRAP_39_HorizLine(0x61, 0x57, 0x62);
            ULTIMA_0c9c_GRAP_39_HorizLine(0x61, 0x58, 99);
        }
    }

    if ((local_6 & 0xf0) == 0xe0 && param_3 == 0)
    {
        D_52ba_vdp._52c4 = 1;

        return 1;
    }

    return 0;
}

// CHECKED (nop)
static void DUNGEON_1682(int param_1, int param_2, int param_3, int param_4)
{
    int local_4;
    int local_8;
    int local_6;
    int local_a;

    local_8 = DUNGEON_10dc(param_1, param_2);
    if (local_8 >= 0xa0)
    {
        switch (local_8 & 0xf0)
        {
        case 0xc0:
            // 16c4
            local_4 = param_4 + 0x14;
            DUNGEON_134a(local_4, 0, param_3);
            if (param_4 >= 2)
            {
                break;
            }

            if (D_6604 != 1)
            {
                break;
            }

            // 16ea
            local_a = local_8 & 7;
            local_6 = (param_4 != 0) ? 0x43 : 0x21;

            if (param_3 != 0)
            {
                local_6 = 0xbe - local_6;
            }

#if !defined(TARGET_DOS16)
            if (local_a >= 5)
            {
                debug("WARNING: local_a >= 5");
            }
#endif

            local_a = DUNGEON_145c(local_6, D_2e9a[local_a + param_4 * 5] + 0xe, local_a, param_4);

            GetDungeonMap(param_1 & 7, param_2 & 7, D_5895_map_level) &= 0xf8;
            GetDungeonMap(param_1 & 7, param_2 & 7, D_5895_map_level) += local_a;
            // NOT MATCHING (nop)
            break;

        case 0xa0:
        case 0xe0:
        case 0xf0:
            // 1766
            DUNGEON_134a(param_4 + 4, 0, param_3);
            break;

        default:
            DUNGEON_134a(param_4, 0, param_3);
            break;
        }
    }
    else
    {
        DUNGEON_134a(param_4 + 0x10, 0, param_3);
    }
}

// CHECKED
static void DUNGEON_1786(int param_1, int param_2)
{
    int local_4;

    if (D_52c8 == 0 || D_52c8 == 3)
    {
        ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    }
    else
    {
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
    }

    // 17a9
    switch (param_1)
    {
    case 0:
        // 17cc
        if (D_52c8 != 0 && D_52c8 != 3)
        {
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color + 8);
        }

        // 17e4
        for (local_4 = 0; local_4 < 8; local_4++)
        {
            ULTIMA_0c64_GRAP_30_Pset(D_2ea4[param_2][local_4].x, D_2ea4[param_2][local_4].y);
            ULTIMA_0c64_GRAP_30_Pset(0xbe - D_2ea4[param_2][local_4].x, D_2ea4[param_2][local_4].y);
        }

        ULTIMA_0c64_GRAP_30_Pset(D_2f10[param_2].x, D_2f10[param_2].y);
        ULTIMA_0c64_GRAP_30_Pset(0xbe - D_2f10[param_2].x, D_2f10[param_2].y);
        break;

    case 1:
        // 185e
        for (local_4 = 0; local_4 < 5; local_4++)
        {
            ULTIMA_0c64_GRAP_30_Pset(D_2ed4[param_2][local_4].x + 0x48, D_2ed4[param_2][local_4].y + 0x60);
            ULTIMA_0c64_GRAP_30_Pset(0x76 - D_2ed4[param_2][local_4].x, D_2ed4[param_2][local_4].y + 0x60);
        }
        break;

    case 2:
        // 18c4
        for (local_4 = 0; local_4 < 4; local_4++)
        {
            ULTIMA_0c64_GRAP_30_Pset(D_2ef2[param_2][local_4].x + 0x50, D_2ef2[param_2][local_4].y + 0x60);
            ULTIMA_0c64_GRAP_30_Pset(0x6e - D_2ef2[param_2][local_4].x, D_2ef2[param_2][local_4].y + 0x60);
        }
        break;

    case 3:
        // 1920
        ULTIMA_0c64_GRAP_30_Pset(D_2f0a[param_2].x + 0x58, D_2f0a[param_2].y + 0x60);
        ULTIMA_0c64_GRAP_30_Pset(0x66 - D_2f0a[param_2].x, D_2f0a[param_2].y + 0x60);
        break;
    }
}

// CHECKED
static void DUNGEON_1952(int param_1, int param_2, int param_3)
{
    int local_6;
    int local_4;

    local_6 = DUNGEON_10dc(param_1, param_2);
    local_4 = local_6 >> 4;
    if (local_4 > 0 && local_4 < 8 && (local_4 != 6 || (local_6 & 7) == 0))
    {
        if (D_2f16[local_4] != 0)
        {
            DUNGEON_134a(D_2f16[local_4] + param_3 * 2, 1, 0);
            DUNGEON_134a(D_2f16[local_4] + param_3 * 2, 1, 1);
        }

        if (D_2f1e[local_4] != 0)
        {
            DUNGEON_134a(D_2f1e[local_4] + param_3 * 2, 0, 0);
            DUNGEON_134a(D_2f1e[local_4] + param_3 * 2, 0, 1);
        }

        if (local_4 == 5)
        {
            DUNGEON_1786(param_3, D_2f26);
        }
    }
    else if (local_4 == 8)
    {
        DUNGEON_127e(param_3, local_6 & 7);
    }

    // 1a03
    if (local_4 < 9 && (GetDungeonMap(param_1 & 7, param_2 & 7, D_5895_map_level) & 8) != 0)
    {
        // 1a2d
        DUNGEON_134a(D_2f24 + param_3 * 2, 1, 0);
        DUNGEON_134a(D_2f24 + param_3 * 2, 1, 1);
    }

    // 1a4f (OK)
    if (param_3 != 0 && (param_1 & 7) == D_5c5a[1]._2_x && (param_2 & 7) == D_5c5a[1]._3_y)
    {
        DUNGEON_111e(param_3);
    }

    if (param_3 == 0 && ++D_2f26 > 2)
    {
        D_2f26 = 0;
    }
}

// OK P1
void DUNGEON_1a90(int param_1)
{
    int local_a;
    int local_c;
    int local_4;
    int local_6_x;
    int local_8_y;

    D_545e = 0xff;
    ULTIMA_0c22_GRAP_0f_SelectPage(1);
    ULTIMA_0a70_GRAP_2d_SetPenColor(0);
    ULTIMA_0aa6_GRAP_3f_FillRect(0x60, 0xe, 0xaf, 0xb2);
    ULTIMA_0c3c(0x28, 0x2a, 0x98, 0xb7);
    D_52ba_vdp._52c4 = 0;

    if (D_58a6 != 0 || D_58a7 != 0)
    {
        local_6_x = D_5896_map_x;
        local_8_y = D_5897_map_y;
        local_a = D_24d6[D_6603];
        local_c = D_24de[D_6603];

        for (local_4 = 0; local_4 < 4; local_4++)
        {
            // 1b0e
            if (DUNGEON_150a(local_6_x, local_8_y, local_4) != 0)
            {
                if (local_4 != 0 || (DUNGEON_10dc(D_5896_map_x, D_5897_map_y) != 0xe0 && param_1 != 0))
                {
                    // 1b36
                    DUNGEON_1682((u8)D_2f28[D_6603] + local_6_x, (u8)D_2f2c[D_6603] + local_8_y, 0, local_4);
                    DUNGEON_1682(local_6_x - (u8)D_2f28[D_6603], local_8_y - (u8)D_2f2c[D_6603], 1, local_4);
                }

                local_6_x += local_a;
                local_8_y += local_c;
            }
            else
            {
                break;
            }
        }

        // 1b92
        for (--local_4; local_4 >= 0; local_4--)
        {
            local_6_x -= local_a;
            local_8_y -= local_c;
            DUNGEON_1952(local_6_x, local_8_y, local_4);
        }
    }
    else
    {
        ULTIMA_0aa6_GRAP_3f_FillRect(8, 8, 0xb7, 0xb7);
    }

    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    D_52ba_vdp._52c4 = 0;
}

// OK P1
void DUNGEON_1be0(void)
{
    ULTIMA_2900_UpdateVitalsDisplay();
    DUNGEON_1a90(1);
    ULTIMA_0ace_GRAP_18_TransferArea(1, 0, 0x10, 0xe, 0xaf, 0xb2);
    DUNGEON_1020();
    DUNGEON_01d2_PrintWalkDir();
}

// OK P1
static int DUNGEON_1c0c(int param_1, int param_2)
{
    int local_6;
    int local_4;

    local_4 = 1;
    local_6 = GetDungeonMap(D_5896_map_x, D_5897_map_y, param_1) & 0xf0;
    if (param_2 != 0 &&
        (local_6 != 0 || local_6 == 0xe0 || local_6 == 0xd0 || local_6 == 0xc0 || local_6 == 0xb0)) // NOTE: logic bug?
    {
        local_4 = 0;
    }

    return local_4;
}

// OK P1
int DUNGEON_1c6a_Klimb(int param_1, int param_2)
{
    int local_4;

    local_4 = 0;

    if (param_1 > 0)
    {
        ULTIMA_1850_PrintString(/*0x6c6c*/ "Down!\n");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x6c74*/ "Up!\n");
    }

    if (param_1 > 0 && D_5895_map_level == 7 || param_1 < 0 && D_5895_map_level == 0)
    {
        local_4 = 1;
    }
    else
    {
        if (DUNGEON_1c0c(param_1 + (uint)D_5895_map_level, param_2) != 0)
        {
            D_5895_map_level += param_1;
            if (param_1 > 0)
            {
                D_6602 = 5;
            }
            else
            {
                D_6602 = 4;
            }

            DUNGEON_0134(1);
            DUNGEON_1be0();
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x6c7a*/ "Failed!\n");
            ULTIMA_43ae_AudioSweepTone(800, 2000, 1, 0x32);
        }
    }

    return local_4;
}

// OK P1
void DUNGEON_1d08_Exit(void)
{
    D_5896_map_x = D_1e8a[D_5893_map_id - 1];
    D_5897_map_y = D_1eb2[D_5893_map_id - 1];

    ULTIMA_1850_PrintString(/*0x6c84*/ "\nExit to ");
    if (D_5895_map_level != 0)
    {
        D_5895_map_level = 0xff;
        ULTIMA_1850_PrintString(/*0x6c8e*/ "Underworld!\n\n");
    }
    else
    {
        D_5895_map_level = 0;
        ULTIMA_1850_PrintString(/*0x6c9c*/ "Britannia!\n\n");
    }

    D_5893_map_id = 0;
}

// OK P1
int DUNGEON_1d4a_AttackCmd(void)
{
    int local_4;
    int local_6;
    int local_8;

    local_4 = 0;

    ULTIMA_1850_PrintString(/*0x6caa*/ "Attack\n");

    local_6 = (D_24d6[D_6603] + D_5896_map_x) & 7;
    local_8 = (D_24de[D_6603] + D_5897_map_y) & 7;
    if (local_6 == D_5c5a[1]._2_x && local_8 == D_5c5a[1]._3_y)
    {
        D_58a1 = 2;
        DNGLOOK_1130();
        DNGLOOK_0c6c();
        DNGLOOK_0d3e();
        ULTIMA_5f86_SpecialMapHandler(2, D_5c5a[1]._5, 0);

        if (D_58a0 == 5)
        {
            if (D_5895_map_level != 0)
            {
                D_5895_map_level--;
            }
            else
            {
                DUNGEON_1d08_Exit();
            }
        }
        else if (D_58a0 == 6)
        {
            if (D_5895_map_level < 7)
            {
                D_5895_map_level++;
            }
            else
            {
                DUNGEON_1d08_Exit();
            }
        }

        DNGLOOK_109e(1);

        if (D_5893_map_id != 0)
        {
            DUNGEON_0134(1);
            DUNGEON_1be0();
        }
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x6cb2*/ "What?\n");
    }

    return local_4;
}

// OK P1
int DUNGEON_1e10_KlimbCmd(void)
{
    int local_4;
    int local_6;
    int local_8;
    int local_a;

    local_4 = 0;
    local_6 = 0;
    local_a = DUNGEON_10dc(D_5896_map_x, D_5897_map_y) & 0xf0;
    local_8 = GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level) & 8;
    if (local_a == 0x10 || local_a == 0x30 || (local_8 != 0 && D_57af != 0))
    {
        local_4 = 1;
    }

    if (local_a == 0x20 || local_a == 0x30 || local_a == 0x60)
    {
        local_6 = 1;
    }

    if (local_4 && local_6)
    {
        ULTIMA_1850_PrintString(/*0x6cba*/ "Klimb-U/D-");
        while (local_4 && local_6)
        {
            switch (ULTIMA_266c_GetChar())
            {
            case 3:
            case 0x55:
                local_6 = 0;
                break;

            case 4:
            case 0x44:
                local_4 = 0;
                break;

            case 0x20:
                ULTIMA_1850_PrintString(/*0x6cc6*/ "Pass\n\n");
                local_4 = local_6 = 0;
                break;
            }
        }
    }
    else if (local_4 || local_6) // 1eee
    {
        // 1efa
        ULTIMA_1850_PrintString(/*0x6cce*/ "Klimb-");
    }
    else if (local_8 != 0)
    {
        // 1f08
        ULTIMA_1850_PrintString(/*0x6cd6*/ "Klimb-\nWith What?\n");

        return 0;
    }
    else
    {
        // 1f16
        ULTIMA_1850_PrintString(/*0x6cea*/ "Klimb-what?\n");

        return 0;
    }

    // 1f1c
    if ((local_4 && DUNGEON_1c6a_Klimb(-1, 0) != 0) || (local_6 && DUNGEON_1c6a_Klimb(1, 0) != 0))
    {
        DUNGEON_1d08_Exit();
    }

    return 1;
}
