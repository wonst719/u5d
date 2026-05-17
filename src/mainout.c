#include "common/common.h"
#include "funcs.h"
#include "vars.h"

#include <stdlib.h>

#include "blckthrn.h"
#include "cast2.h"
#include "comsubs.h"
#include "mainout.h"
#include "outsubs.h"

static void MAINOUT_109e(void);
static void MAINOUT_1be8(void);

// OK P1
void MAINOUT_0000(void)
{
    ULTIMA_4be8();
    ULTIMA_4f7c(0);

    D_58a4 = D_5956 = D_24e6 = 1;
    D_5955 = 0;
    D_589b = D_5896_map_x & 0xf0;
    if ((D_5896_map_x & 0xf) < 8)
    {
        D_589b = (D_589b - 0x10) & 0xf0;
    }

    // 0034
    D_589c = D_5897_map_y & 0xf0;
    if ((D_5897_map_y & 0xf) < 8)
    {
        D_589c = (D_589c - 0x10) & 0xf0;
    }

    // 004f
    OUTSUBS_01b4(0, 1);
    OUTSUBS_01b4(0, -1);
    ULTIMA_4f7c(0);
    ULTIMA_5e4a();
    ULTIMA_2e96_SetWindDirection(-1);
    ULTIMA_4a84();
    OUTSUBS_0566();
}

// OK P1
void MAINOUT_007a(void)
{
    int local_8;
    int local_a;

    int local_6;
    ActorFmt* local_4;

    for (local_6 = 1; local_6 < 32; local_6++)
    {
        local_4 = &D_5c5a[local_6];

        local_8 = abs(D_5896_map_x - local_4->_2_x);
        local_a = abs(D_5897_map_y - local_4->_3_y);

        if (local_4->_0_tile != 0 && local_4->_4_z == D_5895_map_level && local_8 < 6 && local_a < 6)
        {
            ULTIMA_3ae6(1);
        }

        break;
    }
}

// OK P1
static int MAINOUT_00da(int param_1)
{
    int local1_6;
    int local2_4 = 0;

    switch (D_587c & 0xfc)
    {
    case 0x10:
        // 010a
        ULTIMA_1850_PrintString(/*0x2946*/ "Ride ");
        if (param_1 == 1)
        {
            D_587c = 0x12;
        }
        else if (param_1 == 3)
        {
            D_587c = 0x13;
        }
        break;

    case 0x14:
        // 0130
        ULTIMA_1850_PrintString(/*0x294c*/ "Fly ");
        if (param_1 == 1)
        {
            D_587c = 0x14;
        }
        else if (param_1 == 3)
        {
            D_587c = 0x15;
        }
        break;

    case 0x28:
        // 0152
        ULTIMA_1850_PrintString(/*0x2951*/ "Row ");
        D_587c = (char)param_1 + (D_587c & 0xfc);
        break;

    case 0x20:
    case 0x24:
        // 016a
        local1_6 = D_587c;
        D_587c = (char)param_1 + (D_587c & 0xfc);
        if (local1_6 != D_587c)
        {
            ULTIMA_1850_PrintString(/*0x2956*/ "Head ");

            switch (param_1)
            {
            case 0:
                ULTIMA_1850_PrintString(/*0x295c*/ "North\n");
                break;
            case 2:
                ULTIMA_1850_PrintString(/*0x2963*/ "South\n");
                break;
            case 1:
                ULTIMA_1850_PrintString(/*0x296a*/ "East\n");
                break;
            case 3:
                ULTIMA_1850_PrintString(/*0x2970*/ "West\n");
                break;
            }

            // 01ad
            D_5956 = local2_4 = 1;
            if (D_5c5a[0]._5 < 0x32)
            {
                ULTIMA_1850_PrintString(/*0x2976*/ "Hull weak!\n");
            }
        }
        // 01dc
        else if (D_587c < 0x24 && D_5892_wind_dir == 0)
        {
            local2_4 = 1;
        }

        break;
    }

    // 0129
    return local2_4;
}

// OK P1
// Check before Walk/Move
static int MAINOUT_01fe(int param_2, int param_1)
{
    int local_8;
    bool local_4;
    int local_6;

    if ((D_587c & 0xfc) == 0x24)
    {
        ULTIMA_1850_PrintString(/*0x2982*/ "Rowing!\n");
    }

    local_4 = 1;
    local_6 = ULTIMA_368e_FindNpcTileAtPos(param_2 + (uint)D_5896_map_x, param_1 + (uint)D_5897_map_y, D_5895_map_level);
    if (local_6 != 0)
    {
        local_4 = 0;
        if (D_587c >= 0x30 || D_587c < 0x20)
        {
            if ((local_6 >= 0x24 && local_6 < 0x2c) || local_6 == 0x1b || (local_6 & 0xfe) == 0x10)
            {
                local_4 = 1;
            }
        }
        else
        {
            if (D_587c >= 0x28 && local_6 >= 0x24 && local_6 < 0x28)
            {
                local_4 = 1;
            }
        }
    }

    local_8 = D_ab02[param_2 + param_1 * 0x20 + 0xa5];

    local_4 = local_4 && ULTIMA_2c4c(D_587c, local_8) != 0 ? 1 : 0;
    if (local_4 == 0)
    {
        if (D_5955 != 0)
        {
            if (local_8 == 3)
            {
                ULTIMA_1850_PrintString(/*0x298b*/ "BREAKING UP!\n");
            }
            else if (local_8 != 0x47)
            {
                ULTIMA_1850_PrintString(/*0x2999*/ "COLLISION!\n");
            }

            if (local_8 == 0x47)
            {
                ULTIMA_1850_PrintString(/*0x29a5*/ "Docked!\n");
                D_587c += 4;
            }
            else
            {
                ULTIMA_223c_AudioWhiteNoise(100, 2000, 300);
                MAINOUT_109e();
            }

            D_5955 = 0;
            D_5956 = 1;
        }
        else if (D_587c < 0x20 || (local_6 & 0xfc) != 0xec)
        {
            ULTIMA_1850_PrintString(/*0x29ae*/ "Blocked!\n");
            if (local_8 == 0x2f)
            {
                ULTIMA_1850_PrintString(/*0x29b8*/ "OUCH!\n");
                ULTIMA_2aa8();
            }
            else
            {
                ULTIMA_22c0_AudioTone(0xa5, 200);
            }
            ULTIMA_1b16_ClearKbdBuffer();
        }
    }

    return local_4;
}

// OK P1
// Move
void MAINOUT_0354(int param_1, int param_2)
{
    int local_4;
    int local_6;

    D_5896_map_x += param_1;
    D_5897_map_y += param_2;
    D_24e6 = 1;
    local_4 = D_5896_map_x - D_589b & 0x1f;
    local_6 = D_5897_map_y - D_589c & 0x1f;

    if (local_4 < 5 || local_4 > 0x1a || local_6 < 5 || local_6 > 0x1a)
    {
        OUTSUBS_02c8(param_1, param_2); // 7bd2
        D_589b = (char)param_1 * 16 + D_589b & 0xf0; // wrap x?
        D_589c = (char)param_2 * 16 + D_589c & 0xf0; // wrap y?
        OUTSUBS_01b4(param_1, param_2); // 7b8a
        ULTIMA_5e4a();
    }
}

// OK P1
static void MAINOUT_03e0(void)
{
    int local_8;
    int local_4;
    int local_6;

    local_4 = 0;

    local_8 = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
    if (local_8 == 5)
    {
        // 0406
        local_6 = 0;
    }
    else if (local_8 == 0x1e || local_8 == 0x1f)
    {
        // 041a
        local_6 = 1;
    }
    else if (local_8 < 4 || local_8 >= 0x10) // 042e
    {
        // -> 0406
        local_6 = 0;
    }
    else if (local_8 >= 9)
    {
        local_6 = 2;
    }
    else
    {
        local_6 = 1;
    }

    // 041f
    switch (local_6)
    {
    case 1:
        // 0448
        local_4 += MAINOUT_1a60();
        MAINOUT_007a();

        if (local_4 == 0)
        {
            ULTIMA_1850_PrintString(/*0x29bf*/ "Slow progress!\n");
        }

        ULTIMA_4f7c(2);
        break;

    case 2:
        // 0468
        local_4 += MAINOUT_1a60();
        MAINOUT_007a();

        local_4 += MAINOUT_1a60();
        MAINOUT_007a();

        if (local_4 == 0)
        {
            ULTIMA_1850_PrintString(/*0x29cf*/ "Very slow!\n");
        }

        ULTIMA_4f7c(4);
        break;
    }
}

// OK P1
static int MAINOUT_0490(int param_1, int param_2)
{
    int local_8;
    int local_6;
    int local_4;

    if ((D_587c & 0xfc) == 0x20)
    {
        if (param_1 != D_5955)
        {
            D_5955 = param_1;
            D_5883 = 0;
        }
        D_5956 = 0;
    }

    // 04b8
    if ((D_587c == 0x1c) || ((D_587c & 0xfe) == 0x12))
    {
        ULTIMA_433e_AudioWalkStep();
    }

    // 04cb
    local_6 = local_8 = 0;

    switch (param_1)
    {
    case 3:
        // 04f0
        local_8--;
#if !defined(TARGET_DOS16)
        local_4 = MAINOUT_00da(0);
        if (local_4 != 0)
        {
            return local_4;
        }
#else
        if (MAINOUT_00da(0))
        {
            return;
        }
#endif

        // 0500
        if (D_5955 == 0)
        {
            ULTIMA_1850_PrintString(/*0x29db*/ "North\n");
        }
        break;

    case 4:
        // 054e
        local_8++;
#if !defined(TARGET_DOS16)
        local_4 = MAINOUT_00da(2);
        if (local_4 != 0)
        {
            return local_4;
        }
#else
        if (MAINOUT_00da(2))
        {
            return;
        }
#endif
        if (D_5955 == 0)
        {
            ULTIMA_1850_PrintString(/*0x29e2*/ "South\n");
        }
        break;

    case 2:
        // 055c
        local_6++;
#if !defined(TARGET_DOS16)
        local_4 = MAINOUT_00da(1);
        if (local_4 != 0)
        {
            return local_4;
        }
#else
        if (MAINOUT_00da(1))
        {
            return;
        }
#endif
        if (D_5955 == 0)
        {
            ULTIMA_1850_PrintString(/*0x29e9*/ "East\n");
        }
        break;

    case 1:
        // 0576
        local_6--;
#if !defined(TARGET_DOS16)
        local_4 = MAINOUT_00da(3);
        if (local_4 != 0)
        {
            return local_4;
        }
#else
        if (MAINOUT_00da(3))
        {
            return;
        }
#endif
        if (D_5955 == 0)
        {
            ULTIMA_1850_PrintString(/*0x29ef*/ "West\n");
        }
        break;
    }

    // 050e
    local_4 = MAINOUT_01fe(local_6, local_8);
    if (param_2 == 0 && local_4 != 0)
    {
        if ((D_587c & 0xfe) == 0x12)
        {
            ULTIMA_433e_AudioWalkStep();
        }
        // 0530
        MAINOUT_0354(local_6, local_8);
        MAINOUT_03e0();
    }
    return local_4;
}

u8 D_29f5L[4]; // wind-releated
u8 D_29f9L[4]; // wind-releated

// OK P1
static int MAINOUT_0598(void)
{
    int local1_a;
    int local2_8;
    int local3_6;
    int local4_4;

    ULTIMA_5910_UpdateFrame();
    if (D_a9fa != 0)
    {
        ULTIMA_2900_UpdateVitalsDisplay();
        D_a9fa = 0;
    }

    // 05b2
    if ((D_ab02[0xc5] & 0xfc) == 0xd4)
    {
        OUTSUBS_0458();
        local3_6 = 0;
    }
    else
    {
        // 05c6
        if (D_5956 != 0)
        {
            ULTIMA_16ba_PrintChar(10);
            ULTIMA_4c2a();
        }

        // 05d7
        D_5956 = 1;
        while (D_5955 != 0)
        {
            local3_6 = ULTIMA_2032_ToUpper(ULTIMA_1b38_PollKeyWithCursor());
            if (local3_6 != 0 && local3_6 != D_5955)
                break;

            // 05e6
            local3_6 = (uint)D_5955;
            if (D_5892_wind_dir != 0)
            {
                local2_8 = local1_a = 0;

                switch (local3_6)
                {
                case 3:
                    // 0614
                    local1_a = (byte)-1;
                    break;
                case 4:
                    // 0658
                    local1_a = 1;
                    break;
                case 2:
                    // 0660
                    local2_8 = 1;
                    break;
                case 1:
                    // 0668
                    local2_8 = (byte)-1;
                    break;
                }

                // 0619
                local4_4 = 1;
                if (D_29f5[D_5892_wind_dir] != local2_8)
                {
                    local4_4++;
                }
                // 062e
                if (D_29f9[D_5892_wind_dir] != local1_a)
                {
                    local4_4++;
                }
                // 0640
                if (local4_4 % 3 <= (uint)D_5883)
                {
                    D_5883 = 0;
                    break;
                }
            }

            // 0670
            if (D_57bb > 0x7f)
            {
                D_a524 = (uint)(D_a524 == 0);
                ULTIMA_4f7c(1);
            }
            else
            {
                ULTIMA_4f7c(2);
            }

            if (D_a524 == 0 || D_57bb < 0x80)
            {
                MAINOUT_1a60();
            }

            ULTIMA_3ae6(1);
            D_5883 = D_5883 + 1;
        }

        if (D_5955 == 0)
        {
            local3_6 = ULTIMA_266c_GetChar();
        }
    }

    return local3_6;
}

// OK P1
int MAINOUT_06ec_AttackCmd(void)
{
    int local_6;
    int local_8;
    int local_4 = 0;
    int local_a;

    ULTIMA_1850_PrintString(/*0x29fe*/ "Attack-");
    if ((*ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y) < 4) &&
        ((D_587c & 0xfc) == 0x28 || (D_587c & 0xfe) == 0x14))
    {
        ULTIMA_1850_PrintString(/*0x2a06*/ "On foot!\n");
        local_4 = 0;
    }
    else
    {
        if (ULTIMA_35ec_SelectDirection() != 0)
        {
            local_6 = (uint)D_5896_map_x + D_5876;
            local_8 = (uint)D_5897_map_y + D_5878;
            local_a = ULTIMA_368e_FindNpcTileAtPos(local_6, local_8, D_5895_map_level) & 0xfc;
            if (local_a == 0x2c || (local_a != 0xb4 && local_a != 0xe8 && local_a >= 0x40))
            {
                ULTIMA_6150_Attack(D_5876);
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x2a10*/ "Nothing to attack!\n");
            }
        }
    }
    return local_4;
}

// OK P1
// Load dungeon
static int MAINOUT_0790_LoadDungeon(char* param_1)
{
    int local_4;
    int local_6; // unused

    ULTIMA_1850_PrintString(param_1);
    for (local_4 = 0x20; local_4 < 0x28; local_4++)
    {
        if (D_1e8a[local_4] == D_5896_map_x && D_1eb2[local_4] == D_5897_map_y)
            break;
    }

    if (local_4 < 0x28)
    {
        if (D_587c != 0x1c)
        {
            ULTIMA_1850_PrintString(/*0x2a24*/ "\nOn foot!\n");
            return; // sic
        }

        if (local_4 == 0x27)
        {
            if ((D_58c8[0] & D_58c8[1] & D_58c8[2]) < 0x80)
            {
                ULTIMA_1850_PrintString(/*0x2a2f*/ "\nAttacked at entrance!\n");
                local_4 = ULTIMA_38e4();
                D_5c5a[local_4]._0_tile = 0xfc;
                ULTIMA_6150_Attack(local_4);
                return; // sic
            }
        }
        else
        {
            ULTIMA_1850_PrintString("\n\n");
            ULTIMA_16ba_PrintChar(0xfc);
            ULTIMA_1850_PrintString(D_1e3a[local_4]);
            ULTIMA_16ba_PrintChar(0xfb);
        }

        ULTIMA_16ba_PrintChar(10);
        if (D_a9bd[0] != 1)
        {
            ULTIMA_251e_SwitchDisks(1);
            while (ULTIMA_1674_TestOpenFile(/*0x2a4a*/ "BRIT.DAT") == 0) {}
        }

        ULTIMA_25d8_WriteFileToDisk(OUTSUBS_0368_GetWorldSavefile(), D_5c5a, 0x100);
        ULTIMA_251e_SwitchDisks(2);
        ULTIMA_256e_ReadFileFromDisk(/*0x2a53*/ "DUNGEON.DAT", D_595a, 0x200, local_4 * 0x200 + -0x4000);
        D_5893_map_id = local_4 + 1;
        if (D_5895_map_level != 0 && (byte)(local_4 + 1) != 0x28)
        {
            D_5895_map_level = 7;
            D_6603 = 3;
            D_6602 = 4;
            D_5896_map_x = D_5897_map_y = 7;
        }
        else
        {
            D_5895_map_level = 0;
            D_5896_map_x = D_5897_map_y = 1;
            D_6603 = 1;
            D_6602 = 5;
        }
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x2a5f*/ "\nWhat dungeon?\n");
    }

    return 1;
}

// OK P1
int MAINOUT_08de_EnterCmd(void)
{
    int local_6;
    int local_4;
    int local_8;

    local_4 = 1;

    ULTIMA_1850_PrintString(/*0x2a6f*/ "Enter ");

    local_8 = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
    switch (local_8)
    {
    case 0x19:
        ULTIMA_1850_PrintString(/*0x2a76*/ "the shrine of\n");
        for (local_6 = 0; local_6 < 8; local_6++)
        {
            if (D_1f6e[local_6] == D_5896_map_x && D_1f76[local_6] == D_5897_map_y)
                break;
        }

        ULTIMA_1850_PrintString(D_1f4e[local_6]);
        ULTIMA_16ba_PrintChar(10);
        CAST2_0e76();
        break;

    case 0x10:
        local_4 = OUTSUBS_0388_EnterTown(/*0x2a85*/ "hut");
        break;

    case 0x11:
        ULTIMA_1850_PrintString(/*0x2a89*/ "the Shrine of the Codex!\n");
        CAST2_0e76();
        break;

    case 0x12:
        local_4 = OUTSUBS_0388_EnterTown(/*0x2aa3*/ "keep");
        break;

    case 0x13:
        local_4 = OUTSUBS_0388_EnterTown(/*0x2aa8*/ "village");
        break;

    case 0x14:
        local_4 = OUTSUBS_0388_EnterTown(/*0x2ab0*/ "towne");
        break;

    case 0x15:
        local_4 = OUTSUBS_0388_EnterTown(/*0x2ab6*/ "castle");
        break;

    case 0x16:
        local_4 = MAINOUT_0790_LoadDungeon(/*0x2abd*/ "cave");
        break;

    case 0x17:
        local_4 = MAINOUT_0790_LoadDungeon(/*0x2ac2*/ "mine");
        break;

    case 0x18:
        local_4 = MAINOUT_0790_LoadDungeon(/*0x2ac7*/ "dungeon");
        break;

    case 0x1a:
        ULTIMA_1850_PrintString(/*0x2acf*/ "ruins");
        break;

    case 0x1b:
        local_4 = OUTSUBS_0388_EnterTown(/*0x2ad5*/ "lighthouse");
        break;

    case 0x39:
        local_4 = OUTSUBS_0388_EnterTown(/*0x2ae0*/ "the palace of Blackthorn!");
        break;

    case 0x3e:
        local_4 = OUTSUBS_0388_EnterTown(/*0x2afa*/ "the Castle of Lord British!");
        break;

    default:
        ULTIMA_1850_PrintString(/*0x2b16*/ "What?\n");
        local_4 = 0;
        break;
    }

    return local_4;
}

// OK P1
static int MAINOUT_0a1a(int param_1)
{
    if (*ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y) == 0xff && D_587a != 0xe)
    {
        D_58a5 = 0;
        if (param_1 == 0)
        {
            ULTIMA_5910_UpdateFrame();
            param_1 = 1;
        }
    }
    else
    {
        param_1 = 0;
        ULTIMA_4f7c(0);
    }

    return param_1;
}

// OK P1
// check earthquake
static void MAINOUT_0a60(void)
{
    if (D_5895_map_level != 0)
    {
        if (ULTIMA_2092_RandomRange(0, 0xff) == 0x69)
        {
            ULTIMA_1850_PrintString(/*0x2b1d*/ "EARTHQUAKE!\n");
            ULTIMA_3072();
            ULTIMA_2aa8();
        }
    }
}

// OK P1 (stack)
static void MAINOUT_0a84_MainLoop(void)
{
    int local_4 = 0;
    byte local_6;
    int local_8;
    int local_a;
    bool local_c;
    int local_e; // not used
    int local_10; // not used
    int local_12;
    do
    {
        // 0a8f
        local_c = 0;
        local_a = 1;
        local_4 = MAINOUT_0a1a(local_4);
        local_8 = ULTIMA_39fc_GetFirstActivePartyMember();
        if (local_8 == 1)
        {
            ULTIMA_16ba_PrintChar(10);
            ULTIMA_4c2a();
            // 0aba
            ULTIMA_1850_PrintString(/*0x2b2a*/ "Zzzzzz...\n");
        }
        else if (local_8 == -1) // 0ac2
        {
            if (D_a9bd[0] != 1)
            {
                ULTIMA_251e_SwitchDisks(1);
                // 0ad6
                while (ULTIMA_1674_TestOpenFile(/*0x2b35*/ "BRIT.DAT") == 0) {}
            }
            // 0ae1
            ULTIMA_25d8_WriteFileToDisk(OUTSUBS_0368_GetWorldSavefile(), D_5c5a, 0x100);
            BLCKTHRN_0910_Death();
            local_c = 1;
            local_a = 0;
        }
        else
        {
            // 0b00
            if (ULTIMA_48a8() != 0)
            {
                CAST2_0e76();
            }
            // 0b0a
            if (D_5893_map_id != 0)
            {
                return;
            }
            // 0b14
            local_6 = MAINOUT_0598();
            if (local_6 < 0x20)
            {
                switch (local_6 & 0xff)
                {
                case 0xb: // 0b34
                    ULTIMA_1a3e_PrintNumber(D_5888, 1, 0x20);
                    // -> 0b75
                    ULTIMA_16ba_PrintChar(10);
                    // -> 0af8
                    local_a = 0;
                    break; // -> 0c12

                case 5: // 0b48
                    ULTIMA_1850_PrintString(/*0x2b3e*/ "Exit to DOS? ");
                    local_6 = ULTIMA_266c_GetChar();
                    if (local_6 == 'Y')
                    {
                        ULTIMA_0878_RestoreVideoMode();
                        exit(0);
                    }
                    else
                    {
                        ULTIMA_1850_PrintString(/*0x2b4c*/ "N\n");
                    }
                    break;

                case 0x16: // 0b6e
                    ULTIMA_1850_PrintString(/*0x2b4f*/ "1.16");
                    // 0b75
                    ULTIMA_16ba_PrintChar(10);
                    local_a = 0;
                    break;

                case 0x13: // 0b80
                    ULTIMA_1850_PrintString(/*0x2b54*/ "Sound ");
                    if (D_a9ce != 0)
                    {
                        ULTIMA_1850_PrintString(/*0x2b5b*/ "Off\n");
                    }
                    else
                    {
                        ULTIMA_1850_PrintString(/*0x2b60*/ "On\n");
                    }
                    // ?
                    D_a9ce = !D_a9ce;
                    break;

                case 1: // 0baa
                case 2:
                case 3:
                case 4:
                    local_a = MAINOUT_0490(local_6, local_4);
                    break;

                case 0: // 0af8
                    local_a = 0;
                    break;

                default: // 0bb8
                    ULTIMA_1850_PrintString(/*0x2b64*/ "What?\n");
                    break;
                }
            }
            else
            {
                // 0bee
                if (local_6 < 0x30 || local_6 > 0x39)
                {
                    // 0bfa
                    local_a = ULTIMA_3178_ProcessCommand(local_6 & 0xff);
                }
                else
                {
                    // 0c06
                    local_a = ULTIMA_4080(local_6);
                }
            }
        }
        // 0c12
        if ((D_587c & 0xfc) != 0x20)
        {
            D_5955 = 0;
        }
        // 0c20
        if (D_5893_map_id != 0)
        {
            local_c = 1;
        }
        else
        {
            if (local_a != 0)
            {
                // 0c39
                ULTIMA_4f7c(2);
                local_12 = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
                if ((local_12 & 0xfe) == 0x6a)
                {
                    MAINOUT_1be8();
                }
                // 0c64
                else if ((local_12 == 4) && (D_587c == 0x1c))
                {
                    OUTSUBS_05fc();
                    ULTIMA_3ae6(1);
                }
                else if (local_12 == 0x8f)
                {
                    OUTSUBS_05ee();
                }
                else if (D_5896_map_x == 0xe9 && D_5897_map_y == 0xeb && D_5895_map_level == 0 && D_5893_map_id == 0)
                {
                    ULTIMA_1850_PrintString(/*0x2b6b*/ "\n\"");
                    if (D_58cc != 0)
                    {
                        ULTIMA_1850_PrintString(/*0x2b6e*/ "Pass, Seeker!\"\n");
                    }
                    else
                    {
                        ULTIMA_1850_PrintString(/*0x2b7e*/ "Thou art not upon a Sacred Quest!\n");
                        ULTIMA_1850_PrintString(/*0x2ba1*/ "Passage denied!\"\n");
                        D_5897_map_y++;
                    }
                }

                // 0cd0
                MAINOUT_0a60();
                ULTIMA_2ae8();
                if (local_12 == 1 && ((D_587c & 0xfc) == 0x28 || (D_587c & 0xfe) == 0x14))
                {
                    ULTIMA_1850_PrintString(/*0x2bb3*/ "Rough seas!\n");
                    ULTIMA_3522(D_5896_map_x, D_5897_map_y);
                    MAINOUT_109e();
                }
                if ((local_12 & 0xfc) == 0xd4)
                {
                    OUTSUBS_0458();
                }
                MAINOUT_1a60();
            }
        }
    } while (!local_c);
}

// on_load_mainout_ovl
// OK P1 (reg)
void MAINOUT_0d22(void)
{
    undefined1 local_8;
    int local_6;
    ActorFmt* local_4;

    MAINOUT_0000();

    if (D_6605 >= 0x40)
    {
        local_6 = ULTIMA_38e4();
        local_4 = &D_5c5a[local_6]; // get some actor
        local_4->_7 = D_6605 & 0x3f;
        local_4->_2_x = D_5953; // ship_x
        local_4->_3_y = D_5954; // ship_y
        local_4->_4_z = 0;

        if (D_6605 > 0x7f)
        {
            local_8 = 0x25;
        }
        else
        {
            local_8 = 0x29;
        }

        local_4->_0_tile = local_4->_1 = local_8;
        local_4->_5 = 99;
        D_6605 = 0;
    }

    MAINOUT_0a84_MainLoop();
}

// OK P1
static int MAINOUT_0d8c(void)
{
    int local_6;
    int local_4;

    if (D_5895_map_level > 0x7f)
    {
        return 3;
    }

    local_6 = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
    if (local_6 >= 0x20 && local_6 <= 0x26)
    {
        local_4 = 0;
    }
    else
    {
        if (local_6 == 4 || (local_6 >= 9 && local_6 <= 0xf))
        {
            local_4 = 2;
        }
        else
        {
            local_4 = 1;
        }
    }

    if (D_587f >= 0x20 || D_587f < 5)
    {
        return local_4 + 3;
    }

    return local_4;
}

// CHECKED ([bx][si])
static int MAINOUT_0e04(byte* param_1)
{
    int local_4;
    int local_6;

    local_4 = ULTIMA_2092_RandomRange(0, 0xff);

    for (local_6 = 0; param_1[local_6] <= local_4; local_6++)
    {
        local_4 -= param_1[local_6];
    }
    return local_6;
}

// OK P1
static byte MAINOUT_0e4e(int param_1)
{
    int unused;

    if (param_1 < 4 || (param_1 >= 0x60 && param_1 <= 0x6f) || (param_1 >= 0xd4 && param_1 <= 0xd7) ||
        (param_1 >= 0xe4 && param_1 <= 0xe7))
    {
        if (ULTIMA_2092_RandomRange(0, 0x40) < 0x10)
        {
            if (D_5895_map_level < 0x80)
            {
                if (param_1 == 1 && ULTIMA_2092_RandomRange(0, 7) == 7)
                {
                    return 0xec;
                }
                else
                {
                    return D_2bd4[MAINOUT_0e04(D_2bf0)];
                }
            }
            else
            {
                return D_2bda[MAINOUT_0e04(D_2bf6)];
            }
        }
    }
    else if (param_1 == 7)
    {
        if (ULTIMA_2092_RandomRange(0, 3) == 0)
        {
            return 0xe0;
        }
    }
    else
    {
        if (param_1 == 4 && D_5895_map_level == 0xff)
        {
            return 0xf8;
        }

        if (param_1 == 0xc || param_1 == 0xd)
        {
            return 0;
        }

        if (param_1 < 0x10 || ((byte)param_1 & 0xfc) == 0x30)
        {
            if (D_5895_map_level < 0x80)
            {
                return D_2bc0[MAINOUT_0e04(D_2bdc)];
            }

            return D_2bcc[MAINOUT_0e04(D_2be8)];
        }
    }

    return 0;
}

// OK P1
static void MAINOUT_0f4e(void)
{
    do
    {
        D_5876 = (byte)(ULTIMA_2092_RandomRange(0, 0x1f) + D_589b);
        D_5878 = (byte)(ULTIMA_2092_RandomRange(0, 0x1f) + D_589c);
    } while (abs(D_5876 - D_5896_map_x) <= 6 || abs(D_5878 - D_5897_map_y) <= 6 ||
        abs(D_5876 - D_5896_map_x) >= 0xfa || abs(D_5878 - D_5897_map_y) >= 0xfa);
}

// OK P1
static void MAINOUT_0fc4(void)
{
    byte local_4;
    int local_6;
    int local_8;
    int local_a;

    for (local_6 = 0; local_6 < 0x80; local_6++)
    {
        MAINOUT_0f4e();

        local_8 = D_5876;
        local_a = D_5878;

        local_4 = MAINOUT_0e4e(*ULTIMA_4402_GetTileAddr(local_8, local_a));
        if (local_4 != 0)
        {
            if (local_4 != 0x2c || (*ULTIMA_4402_GetTileAddr(local_8, local_a) & 0xf0) != 0x60)
            {
                break;
            }
        }
    }

    if (local_6 != 0x80)
    {
        local_6 = ULTIMA_38e4();
        ULTIMA_3a74(local_4, local_4, local_8, local_a, D_5895_map_level, 0, local_6);
        if (local_4 == 0x2c)
        {
            D_5c5a[local_6]._5 = 100;
        }
    }
}

// OK P1
int MAINOUT_105c(int param_1)
{
    if (param_1 >= 0x2c && param_1 <= 0x2f)
    {
        return 1;
    }
    
    if (param_1 < 0x80)
    {
        return 0;
    }

    if (param_1 >= 0xb4 && param_1 <= 0xb7 || param_1 >= 0xe8 && param_1 <= 0xeb)
    {
        return 0;
    }

    return 1;
}

// CHECKED
static void MAINOUT_109e(void)
{
    int local_6;
    int local_4;

    if ((D_587c & 0xf8) == 0x20)
    {
        local_4 = ULTIMA_2092_RandomRange(1, 0x1e);
        if (local_4 < D_5c5a[0]._5)
        {
            D_5c5a[0]._5 -= local_4;
            ULTIMA_2900_UpdateVitalsDisplay();
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x6ada*/ "Ship sunk!\n");
            local_6 = D_5c5a[0]._7;
            if (local_6 > 0 || D_57b0 != 0)
            {
                ULTIMA_1850_PrintString(/*0x6ae6*/ "Abandon ship!\n");
                if (local_6 > 0)
                {
                    D_587c = (D_587c & 3) + 0x28;
                }
                else
                {
                    D_57b0--;
                    D_587c = ULTIMA_2092_RandomRange(0, 1) + 0x14;
                }

                D_a9fa = 1;
            }
            else
            {
                D_587c = 0;
                ULTIMA_2900_UpdateVitalsDisplay();
                ULTIMA_5910_UpdateFrame();
                ULTIMA_43ae_AudioSweepTone(0x294, 0x96, 0x28, 0x1e78);
                ULTIMA_1850_PrintString(/*0x6af6*/ "DROWNING!!!\n");

                while (ULTIMA_39fc_GetFirstActivePartyMember() != -1) // NOT MATCHING
                {
                    ULTIMA_3522(D_5896_map_x, D_5897_map_y);
                    ULTIMA_2aa8();
                }
            }
        }
    }
    else
    {
        ULTIMA_2aa8();
    }
}

// OK P1
static void MAINOUT_1168(int param_1, int param_2, int param_3)
{
    int local_4;
    byte local_6;
    byte local_8;

    if (param_2 == 0)
    {
        if (D_5c5a[param_1]._1 == 0x2c || D_5c5a[param_1]._1 == 0x2e)
        {
            D_5c5a[param_1]._1 = (ULTIMA_2092_RandomRange(0, 3) & 2) + 0x2d;
        }
    }

    if (param_3 == 0)
    {
        if (D_5c5a[param_1]._1 == 0x2d || D_5c5a[param_1]._1 == 0x2f)
        {
            D_5c5a[param_1]._1 = (ULTIMA_2092_RandomRange(0, 3) & 2) + 0x2c;
        }
    }

    ULTIMA_5910_UpdateFrame();
    ULTIMA_43ae_AudioSweepTone(0x514, 300, 5, 100);

    local_6 = D_5c5a[param_1]._2_x - D_5896_map_x + 5;
    local_8 = D_5c5a[param_1]._3_y - D_5897_map_y + 5;
    local_4 = COMSUBS_12de(local_6, local_8, 5, 5, 1);
    if (local_4 != 0)
    {
        ULTIMA_5910_UpdateFrame();
        ULTIMA_3522(D_5896_map_x, D_5897_map_y);
        MAINOUT_109e();
    }
}

// OK P1
static void MAINOUT_1248(int param_1)
{
    int local_4;

    if ((D_5c5a[param_1]._0_tile & 0xfc) == 0xec)
    {
        if (D_587c == 0x1c)
        {
            MAINOUT_109e();
            return;
        }
        else
        {
            D_5c5a[param_1]._0_tile = D_5c5a[param_1]._1 = 0;
            ULTIMA_1850_PrintString(/*0x6b04*/ "\nWHIRLPOOL!\n");

            local_4 = D_587c;
            D_587c = 0xec;
            ULTIMA_5910_UpdateFrame();
            ULTIMA_43ae_AudioSweepTone(0x294, 0x96, 0x28, 0x1e78);

            D_587c = local_4;
            MAINOUT_109e();

            D_5895_map_level = 0xff;
            D_5896_map_x = 0x22;
            D_5897_map_y = 0x12;
            MAINOUT_0000();
        }
    }
    else if ((D_5c5a[param_1]._0_tile & 0xfc) != 0xe0)
    {
        ULTIMA_5910_UpdateFrame();
        ULTIMA_1850_PrintString(/*0x6b12*/ "\nAttacked!\n");

        if (*ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y) < 4 &&
            ((D_587c & 0xfe) == 0x14 || (D_587c & 0xfc) == 0x28))
        {
            MAINOUT_109e();
            return;
        }
        else
        {
            ULTIMA_6150_Attack(param_1);
        }
    }
    else
    {
        MAINOUT_109e();
        return;
    }
}

// OK P1
static int MAINOUT_131a(int param_1)
{
    int local_c;
    int local_4;
    int local_8;
    int local_6;
    byte local_a;
    byte local_e;

    local_c = D_5c5a[param_1]._0_tile;
    local_6 = abs(D_5c5a[param_1]._2_x - D_5896_map_x);
    if (local_6 > 0x7f)
    {
        local_6 = 0x100 - local_6;
    }

    local_8 = abs(D_5c5a[param_1]._3_y - D_5897_map_y);
    if (local_8 > 0x7f)
    {
        local_8 = 0x100 - local_8;
    }

    if ((local_6 == 1 && local_8 == 0) || (local_6 == 0 && local_8 == 1))
    {
        MAINOUT_1248(param_1);
        return 1;
    }

    if (local_c == 0x88 || local_c == 0xdc)
    {
        if (local_6 <= 3 && local_8 <= 3 && ULTIMA_2092_RandomRange(0, 7) == 0)
        {
            ULTIMA_5910_UpdateFrame();
            ULTIMA_43ae_AudioSweepTone(0x514, 300, 5, 100);

            local_a = D_5c5a[param_1]._2_x - D_5896_map_x + 5;
            local_e = D_5c5a[param_1]._3_y - D_5897_map_y + 5;

            local_4 = COMSUBS_12de(local_a, local_e, 5, 5, 3);
            if (local_4 != 0)
            {
                ULTIMA_3522(D_5896_map_x, D_5897_map_y);
                MAINOUT_109e();
            }

            return 1;
        }
    }
    else if ((local_c & 0xfc) == 0x2c && ((local_6 == 0 && local_8 < 4) || (local_8 == 0 && local_6 < 4)))
    {
        ULTIMA_1850_PrintString(/*0x6b1e*/ "* BOOOM! *\n\n");
        MAINOUT_1168(param_1, local_6, local_8);
        return 1;
    }

    return 0;
}

// OK P1
static int MAINOUT_1482(int param_1, int param_2, int param_3)
{
    if (ULTIMA_2c4c(D_5c5a[param_1]._0_tile, *ULTIMA_4402_GetTileAddr(param_2, param_3)) == 0)
        return 0;

    if (ULTIMA_3702(param_2, param_3, D_5895_map_level) != 0)
        return 0;

    return 1;
}

// OK P1
static int MAINOUT_14c8(int param_1, int param_2)
{
    if (param_1 == D_a526 && param_2 == D_a527)
    {
        return 0;
    }

    return 1;
}

// OK P1
static int MAINOUT_14ea(int param_1)
{
    int local_6;
    int local_4;

    local_4 = abs(D_5c5a[param_1]._2_x - D_5896_map_x);
    if (local_4 > 0x7f)
    {
        local_4 = 0x100 - local_4;
    }

    local_6 = abs(D_5c5a[param_1]._3_y - D_5897_map_y);
    if (local_6 > 0x7f)
    {
        local_6 = 0x100 - local_6;
    }

    if (local_4 < 6 && local_6 < 6)
    {
        return D_2c18[local_4 + local_6 * 0xb];
    }

    return 0;
}

// OK P1
static void MAINOUT_1578(int param_1, int param_2, int param_3)
{
    int local_6;
    int local_c;
    int local_a;
    int local_8;
    int local_4;

    local_6 = D_5c5a[param_1]._0_tile;
    local_8 = D_5c5a[param_1]._2_x + param_2;
    local_a = D_5c5a[param_1]._3_y + param_3;
    local_c = *ULTIMA_4402_GetTileAddr(local_8, local_a);
    if ((local_6 & 0xfc) == 0x2c)
    {
        if (param_2 == 0 && param_3 == -1)
        {
            local_4 = 0;
        }
        else if (param_2 == 1 && param_3 == 0)
        {
            local_4 = 1;
        }
        else if (param_2 == 0 && param_3 == 1)
        {
            local_4 = 2;
        }
        else if (param_2 == -1 && param_3 == 0)
        {
            local_4 = 3;
        }

        D_5c5a[param_1]._0_tile = D_5c5a[param_1]._1 = local_4 + 0x2c;
    }
    else if (local_6 != 0xdc && local_6 != 0x94 && local_6 != 0xd8 && local_6 != 0xf0)
    {
        switch (local_c)
        {
        case 4:
        case 6:
        case 7:
        case 8:
        case 0x1e:
        case 0x1f:
            if (ULTIMA_2092_RandomRange(0, 1) == 0)
            {
                return;
            }
            break;
        case 9:
        case 10:
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xe:
        case 0xf:
            if (ULTIMA_2092_RandomRange(0, 2) != 2)
            {
                return;
            }
        }
    }

    D_a526 = D_5c5a[param_1]._2_x;
    D_a527 = D_5c5a[param_1]._3_y;

    D_5c5a[param_1]._2_x = local_8;
    D_5c5a[param_1]._3_y = local_a;
    D_24e6 |= 2;

    if (*ULTIMA_4402_GetTileAddr(local_8, local_a) == 0xdc)
    {
        D_5c5a[param_1]._0_tile = D_5c5a[param_1]._1 = 0;
    }
}

// OK P1
static void MAINOUT_16fc(int param_1)
{
    int local_10;
    int local_c;
    int local_e;
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    local_6 = D_5c5a[param_1]._2_x;
    local_8 = D_5c5a[param_1]._3_y;

    local_4 = 0;
    local_a = local_6 - 1;
    local_c = local_8 + 1;
    local_e = local_6 + 1;
    local_10 = local_8 - 1;

    // bug?
    for (; local_4 < 3; local_4++)
    {
        switch (ULTIMA_2092_RandomRange(0, 3))
        {
        case 0:
            // 1760
            if (MAINOUT_1482(param_1, local_6, local_10) != 0)
            {
                MAINOUT_1578(param_1, 0, -1);
            }
            return;

        case 1:
            // 177c
            if (MAINOUT_1482(param_1, local_e, local_8) != 0)
            {
                MAINOUT_1578(param_1, 1, 0);
            }
            return;

        case 2:
            // 1790
            if (MAINOUT_1482(param_1, local_6, local_c) != 0)
            {
                MAINOUT_1578(param_1, 0, 1);
            }
            return;

        case 3:
            // 17a8
            if (MAINOUT_1482(param_1, local_a, local_8) != 0)
            {
                MAINOUT_1578(param_1, -1, 0);
            }
            return;
        }
    }
}

// CHECKED
static void MAINOUT_17d4(int param_1, int param_2)
{
    int local_8;
    int local_c;
    int local_e;
    int local_a;
    int local_6;
    int local_4;

    local_8 = D_5c5a[param_1]._2_x;
    local_c = D_5c5a[param_1]._3_y;
    local_a = (D_5c5a[param_1]._2_x - D_5896_map_x) & 0xff;
    if (local_a > 0x7f)
    {
        local_a -= 0x100;
    }

    local_e = (D_5c5a[param_1]._3_y - D_5897_map_y) & 0xff;
    if (local_e > 0x7f)
    {
        local_e -= 0x100;
    }

    // 1828
    if (local_a == 0)
    {
        local_4 = 0;
    }
    else if (local_a > 0) // 1836
    {
        param_2 = 1; 
        local_4 = -1;
        // -> 1864
    }
    else
    {
        // ????
        if (local_a < 0) // 184a
        {
            param_2 = 0;
        }

        if (local_a < 0) // 1855
        {
            local_4 = param_2 = 1;
        }
        else if (local_a > 0) // 1872
        {
            param_2 = 0;
        }
    }

    if (local_e == 0) // 1864
    {
        local_6 = 0;
    }
    else if (local_e > 0) // 1880
    {
        param_2 = 1;
        local_6 = -1;
    }
    else
    {
        // ????
        if (local_e < 0) // 1894
        {
            param_2 = 0;
        }

        if (local_e < 0) // 189f
        {
            local_6 = param_2 = 1;
        }
        else if (local_e > 0) // 18ee
        {
            param_2 = 0;
        }
    }

    // 18ae
    if (ULTIMA_2092_RandomRange(0, 1) == 1)
    {
        if (local_4 != 0)
        {
            // 18c3
            if (MAINOUT_1482(param_1, local_8 + local_4, local_c) != 0 && MAINOUT_14c8(local_8 + local_4, local_c) != 0)
            {
                // 18e2
                MAINOUT_1578(param_1, local_4, 0);
                return;
            }
        }

        // 18fc
        if (local_6 != 0)
        {
            // 1902
            if (MAINOUT_1482(param_1, local_8, local_c + local_6) != 0 && MAINOUT_14c8(local_8, local_c + local_6) != 0)
            {
                // 192a
                MAINOUT_1578(param_1, 0, local_6);
                return;
            }
        }
    }
    else
    {
        // 1930
        if (local_6 != 0)
        {
            // 1936
            if (MAINOUT_1482(param_1, local_8, local_c + local_6) != 0 && MAINOUT_14c8(local_8, local_c + local_6) != 0)
            {
                // ->192a
                MAINOUT_1578(param_1, 0, local_6);
                return;
            }
        }

        if (local_4 != 0)
        {
            // 195b
            if (MAINOUT_1482(param_1, local_8 + local_4, local_c) != 0 && MAINOUT_14c8(local_8 + local_4, local_c) != 0)
            {
                // -> 18e2
                MAINOUT_1578(param_1, local_4, 0);
                return;
            }
        }
    }

    // 197d
    MAINOUT_16fc(param_1);
}

// OK P1
static void MAINOUT_198c(int param_1)
{
    int local_8;
    int local_6;
    uint local_4;

    local_8 = D_5c5a[param_1]._0_tile;
    if ((local_8 & 0xfc) == 0xec)
    {
        D_5c5a[param_1]._5 ^= 1;
        if (D_5c5a[param_1]._5 == 0)
        {
            return;
        }

        if (ULTIMA_2092_RandomRange(0, 1) == 0)
        {
            MAINOUT_16fc(param_1);
            return;
        }
    }
    else if (local_8 == 0xfc)
    {
        if (MAINOUT_14ea(param_1) != 0 && D_5c5a[param_1]._5++ < 0x14)
        {
            MAINOUT_17d4(param_1, 0);
            return;
        }
    }
    else if ((local_8 & 0xfc) == 0x2c)
    {
        if (D_5892_wind_dir == 0)
        {
            return;
        }

        local_6 = D_5c5a[param_1]._0_tile - 0x2c;

        local_4 = D_2bf8[local_6][D_5892_wind_dir - 1];
        if (local_4 != 4 && local_4 < ++D_5c5a[param_1]._7)
        {
            D_5c5a[param_1]._7 = 0;
            return;
        }
    }

    MAINOUT_17d4(param_1, 1);
}

// OK P1
int MAINOUT_1a60(void)
{
    int local_6;
    int local_4;

    local_4 = 0;
    if (D_587a == 'T')
    {
        return 0;
    }

    if (D_587a == 'Q')
    {
        D_2c55 = D_2c55 ^ 1;
        if (D_2c55 != 0)
        {
            return 0;
        }
    }

    if ((D_587c & 0xfe) == 0x12 || (D_587c & 0xfe) == 0x14)
    {
        D_2c57 = D_2c57 ^ 1;
        if (D_2c57 != 0)
        {
            return 0;
        }
    }

    if (MAINOUT_0d8c() > ULTIMA_2092_RandomRange(1, 0x1e))
    {
        MAINOUT_0fc4();
    }

    for (local_6 = 0x1f; 0 < local_6; local_6--)
    {
        if (MAINOUT_105c(D_5c5a[local_6]._0_tile) != 0)
        {
            local_4 += MAINOUT_131a(local_6);
            if (local_4 == 0)
            {
                MAINOUT_198c(local_6);
            }
        }
    }

    for (local_6 = 0x1f; 0 < local_6; local_6--)
    {
        if (MAINOUT_105c(D_5c5a[local_6]._0_tile) != 0 &&
            ((byte)(D_5c5a[local_6]._2_x - D_589b) > 0x1f || (byte)(D_5c5a[local_6]._3_y - D_589c) > 0x1f))
        {
            ULTIMA_3a74(0, 0, 0, 0, 0, 0, local_6);
        }
    }

    return local_4;
}

// CHECKED
static void MAINOUT_1b3e(void)
{
    int local_8;
    int local_6;
    byte local_4;

    ULTIMA_1850_PrintString(/*0x6b2c*/ "Caught!\n\nThe trolls demand a ");
    ULTIMA_39fc_GetFirstActivePartyMember();
    local_8 = -(D_55a8_party[D_5876]._c * 3 - 99);
    ULTIMA_1a3e_PrintNumber(local_8, 2, 0x20);
    ULTIMA_1850_PrintString(/*0x6b4a*/ " gp toll!\n\nDost thou pay?");

    // NOT MATCHING
    do
    {
        local_4 = ULTIMA_266c_GetChar();
        if (local_4 == 'Y')
            break;
    } while (local_4 != 'N');

    ULTIMA_16ba_PrintChar(local_4);
    ULTIMA_16ba_PrintChar(10);
    if (local_4 == 'Y')
    {
        D_57aa -= local_8;
        D_a9fa = 1;
        if (D_57aa >= 0)
        {
            return;
        }

        D_57aa += local_8;
    }

    local_6 = ULTIMA_38e4();
    ULTIMA_3a74(0xe4, 0, D_5896_map_x, D_5897_map_y, 0, 0, local_6);
    ULTIMA_6150_Attack(local_6);
}

// OK P1
static void MAINOUT_1be8(void)
{
    int local_6;
    int local_4;

    if (ULTIMA_2092_RandomRange(0, 7) == 0 && D_587c == 0x1c)
    {
        ULTIMA_5910_UpdateFrame();
        ULTIMA_1850_PrintString(/*0x6b64*/ "\nThou spieth trolls under the bridge!\n\n");
        ULTIMA_3ae6(10);

        for (local_4 = 0; local_4 < D_585b; local_4++)
        {
            if (D_55a8_party[local_4]._b != 'D' && D_55a8_party[local_4]._b != 'S')
            {
                ULTIMA_1850_PrintString(D_55a8_party[local_4]._0);
                ULTIMA_1850_PrintString(/*0x6b8c*/ " sneaks across");

                for (local_6 = 0; local_6 < 3; local_6++)
                {
                    ULTIMA_3ae6(5);
                    ULTIMA_16ba_PrintChar(0x2e);
                }

                ULTIMA_1850_PrintString(/*0x6b9c*/ "\n\n");

                if (D_55a8_party[local_4]._d < ULTIMA_2092_RandomRange(1, 0x1e))
                {
                    MAINOUT_1b3e();
                    return;
                }
            }
        }

        ULTIMA_1850_PrintString(/*0x6ba0*/ "Trolls evaded!\n");
    }
}
