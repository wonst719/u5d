#include "common/common.h"
#include "funcs.h"
#include "vars.h"

#include <stdlib.h>

void CAST2_0e76(void);

void BLCKTHRN_0910_Death();

char* OUTSUBS_0368_GetWorldSavefile(void);
void OUTSUBS_01b4(int param_1, int param_2);
void OUTSUBS_02c8(int a, int b);
int OUTSUBS_0388(char* param_1);
void OUTSUBS_0458(void);
void OUTSUBS_0566(void);
void OUTSUBS_05ee(void);
void OUTSUBS_05fc(void);
int COMSUBS_12de(int param_1, int param_2, int param_3, int param_4, int param_5);

void MAINOUT_109e(void);
int MAINOUT_1a60(void);
void MAINOUT_1be8(void);

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

// TODO: MATCH
void MAINOUT_007a(void)
{
    uint uVar1;
    uint uVar2;

    uVar1 = (int)((uint)D_5896_map_x - (uint)D_5c5a[1]._2_x) >> 0xf;
    uVar2 = (int)((uint)D_5897_map_y - (uint)D_5c5a[1]._3_y) >> 0xf;
    if ((((D_5c5a[1]._0_tile != '\0') && (D_5c5a[1]._4_z == D_5895_map_level)) &&
         ((int)(((uint)D_5896_map_x - (uint)D_5c5a[1]._2_x ^ uVar1) - uVar1) < 6)) &&
        ((int)(((uint)D_5897_map_y - (uint)D_5c5a[1]._3_y ^ uVar2) - uVar2) < 6))
    {
        ULTIMA_3ae6(1);
    }
}

// OK P1
int MAINOUT_00da(int param_1)
{
    int local1_6;
    int local2_4 = 0;

    switch (D_587c & 0xfc)
    {
    case 0x10:
        // 010a
        ULTIMA_1850_PrintString("Ride "); // 2946
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
        ULTIMA_1850_PrintString("Fly ");
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
        ULTIMA_1850_PrintString("Row ");
        D_587c = (char)param_1 + (D_587c & 0xfc);
        break;

    case 0x20:
    case 0x24:
        // 016a
        local1_6 = D_587c;
        D_587c = (char)param_1 + (D_587c & 0xfc);
        if (local1_6 != D_587c)
        {
            ULTIMA_1850_PrintString("Head ");

            switch (param_1)
            {
            case 0:
                ULTIMA_1850_PrintString("North\n");
                break;
            case 2:
                ULTIMA_1850_PrintString("South\n");
                break;
            case 1:
                ULTIMA_1850_PrintString("East\n");
                break;
            case 3:
                ULTIMA_1850_PrintString("West\n");
                break;
            }

            // 01ad
            D_5956 = local2_4 = 1;
            if (D_5c5a[0]._5 < 0x32)
            {
                ULTIMA_1850_PrintString("Hull weak!\n");
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

// TODO: MATCH
// Check before Walk/Move
int MAINOUT_01fe(int param_2, int param_1)
{
    byte bVar1;
    bool bVar2;
    int iVar3;
    byte bStack_6;

    if ((D_587c & 0xfc) == 0x24)
    {
        ULTIMA_1850_PrintString("Rowing!\n");
    }

    bVar2 = 1;
    iVar3 = ULTIMA_368e_FindNpcTileAtPos(param_2 + (uint)D_5896_map_x, param_1 + (uint)D_5897_map_y, D_5895_map_level);
    bStack_6 = (byte)iVar3;
    if (iVar3 != 0)
    {
        bVar2 = 0;
        if (D_587c < 0x30 && D_587c > 0x1f)
        {
            if (D_587c > 0x27 && iVar3 > 0x23 && iVar3 < 0x28)
            {
                bVar2 = 1;
            }
        }
        else if ((0x23 < iVar3 && iVar3 < 0x2c) || iVar3 == 0x1b || (bStack_6 & 0xfe) == 0x10)
        {
            bVar2 = 1;
        }
    }

    bVar1 = D_ab02[param_2 + param_1 * 0x20 + 0xa5];
    if (bVar2 && (iVar3 = ULTIMA_2c4c(D_587c, bVar1), iVar3 != 0))
    {
        iVar3 = 1;
    }
    else
    {
        iVar3 = 0;
    }

    if (iVar3 != 0)
    {
        return iVar3;
    }

    if (D_5955 == 0)
    {
        if (D_587c > 0x1f && (bStack_6 & 0xfc) == 0xec)
        {
            return 0;
        }
        ULTIMA_1850_PrintString("Blocked!\n");
        if (bVar1 == 0x2f)
        {
            ULTIMA_1850_PrintString("OUCH!\n");
            ULTIMA_2aa8();
        }
        else
        {
            ULTIMA_22c0_AudioTone(0xa5, 200);
        }
        ULTIMA_1b16_ClearKbdBuffer();
        return 0;
    }

    if (bVar1 == 3)
    {
        ULTIMA_1850_PrintString("BREAKING UP!\n");
    }
    else if (bVar1 != 0x47)
    {
        ULTIMA_1850_PrintString("COLLISION!\n");
    }

    if (bVar1 == 0x47)
    {
        ULTIMA_1850_PrintString("Docked!\n");
        D_587c += 4;
    }
    else
    {
        ULTIMA_223c_AudioWhiteNoise(100, 2000, 300);
        MAINOUT_109e();
    }

    D_5955 = 0;
    D_5956 = 1;
    return 0;
}

// TODO: MATCH
// Move
void MAINOUT_0354(int param_1, int param_2)
{
    byte bVar1;
    byte bVar2;

    D_5896_map_x = D_5896_map_x + (char)param_1;
    D_5897_map_y = D_5897_map_y + (char)param_2;
    D_24e6 = 1;
    bVar1 = D_5896_map_x - D_589b & 0x1f;
    bVar2 = D_5897_map_y - D_589c & 0x1f;
    if ((((bVar1 < 5) || (0x1a < bVar1)) || (bVar2 < 5)) || (0x1a < bVar2))
    {
        OUTSUBS_02c8(param_1, param_2); // 7bd2
        D_589b = (char)param_1 * 16 + D_589b & 0xf0; // wrap x?
        D_589c = (char)param_2 * 16 + D_589c & 0xf0; // wrap y?
        OUTSUBS_01b4(param_1, param_2); // 7b8a
        ULTIMA_5e4a();
    }
    return;
}

// TODO: MATCH
void MAINOUT_03e0(void)
{
    byte bVar1;
    byte* pbVar2;
    int iVar3;
    int iVar4;
    undefined2 uVar5;
    int iStack_6;

    pbVar2 = (byte*)ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
    bVar1 = *pbVar2;
    if (bVar1 == 5)
    {
    LAB_0000_0406:
        iStack_6 = 0;
    }
    else
    {
        if ((bVar1 != 0x1e) && (bVar1 != 0x1f))
        {
            if ((bVar1 < 4) || (0xf < bVar1))
                goto LAB_0000_0406;
            if (8 < bVar1)
            {
                iStack_6 = 2;
                goto LAB_0000_041f;
            }
        }
        iStack_6 = 1;
    }
LAB_0000_041f:
    if (iStack_6 == 1)
    {
        iVar3 = MAINOUT_1a60();
        MAINOUT_007a();
        if (iVar3 == 0)
        {
            ULTIMA_1850_PrintString("Slow progress!\n");
        }
        uVar5 = 2;
    }
    else
    {
        if (iStack_6 != 2)
        {
            return;
        }
        iVar3 = MAINOUT_1a60();
        MAINOUT_007a();
        iVar4 = MAINOUT_1a60();
        MAINOUT_007a();
        if (iVar3 + iVar4 == 0)
        {
            ULTIMA_1850_PrintString("Very slow!\n");
        }
        uVar5 = 4;
    }
    ULTIMA_4f7c(uVar5);
    return;
}

// OK P1
int MAINOUT_0490(int param_1, int param_2)
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
            ULTIMA_1850_PrintString("North\n"); // 29db
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
            ULTIMA_1850_PrintString("South\n");
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
            ULTIMA_1850_PrintString("East\n");
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
            ULTIMA_1850_PrintString("West\n");
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

// OK P1
int MAINOUT_0598(void)
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
            local3_6 = ULTIMA_2032_ToUpper(ULTIMA_1b38_KeystrokeCursor());
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
                    local1_a = -1;
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
                    local2_8 = -1;
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

    ULTIMA_1850_PrintString("Attack-");
    if ((*ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y) < 4) &&
        ((D_587c & 0xfc) == 0x28 || (D_587c & 0xfe) == 0x14))
    {
        ULTIMA_1850_PrintString("On foot!\n");
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
                ULTIMA_1850_PrintString("Nothing to attack!\n");
            }
        }
    }
    return local_4;
}

// Load map
// TODO: MATCH
int MAINOUT_0790(char* param_1)
{
    undefined2 uVar1;
    int iVar2;
    int iVar3;
    char cStack_4;

    ULTIMA_1850_PrintString(param_1);
    for (iVar3 = 0x20; iVar3 < 0x28; iVar3++)
    {
        if ((*(char*)(iVar3 + D_1e8a) == D_5896_map_x) && (*(char*)(iVar3 + D_1eb2) == D_5897_map_y))
            break;
    }
    if (iVar3 < 0x28)
    {
        if (D_587c != '\x1c')
        {
            ULTIMA_1850_PrintString("\nOn foot!\n");
            return; // sic?
        }
        if (iVar3 == 0x27)
        {
            if ((D_58c8[0] & D_58c8[1] & D_58c8[2]) < 0x80)
            {
                ULTIMA_1850_PrintString("\nAttacked at entrance!\n");
                iVar3 = ULTIMA_38e4();
                D_5c5a[iVar3]._0_tile = 0xfc;
                ULTIMA_6150_Attack(iVar3);
                return; // sic?
            }
        }
        else
        {
            ULTIMA_1850_PrintString("\n\n");
            ULTIMA_16ba_PrintChar(0xfc);
            ULTIMA_1850_PrintString(D_1e3a[iVar3]);
            ULTIMA_16ba_PrintChar(0xfb);
        }
        ULTIMA_16ba_PrintChar(10);
        if (D_a9bd[0] != 1)
        {
            ULTIMA_251e_SwitchDisks(1);
            do
            {
                iVar2 = ULTIMA_1674_TestOpenFile("BRIT.DAT");
            } while (iVar2 == 0);
        }

        ULTIMA_25d8_WriteFile(OUTSUBS_0368_GetWorldSavefile(), D_5c5a, 0x100);
        ULTIMA_251e_SwitchDisks(2);
        ULTIMA_256e_ReadFile("DUNGEON.DAT", D_595a, 0x200, iVar3 * 0x200 + -0x4000);
        cStack_4 = (char)iVar3;
        D_5893_map_id = cStack_4 + '\x01';
        if ((D_5895_map_level == '\0') || ((char)(cStack_4 + '\x01') == '('))
        {
            D_5895_map_level = 0;
            D_5897_map_y = 1;
            D_5896_map_x = 1;
            D_6603 = 1;
            D_6602 = 5;
        }
        else
        {
            D_5895_map_level = 7;
            D_6603 = 3;
            D_6602 = 4;
            D_5897_map_y = 7;
            D_5896_map_x = 7;
        }
    }
    else
    {
        ULTIMA_1850_PrintString("\nWhat dungeon?\n");
    }
    return 1;
}

// TODO: MATCH
int MAINOUT_08de_EnterCmd(void)
{
    byte bVar1;
    byte* pbVar2;
    char* uVar3;
    int iVar4;
    undefined2 uStack_4;

    ULTIMA_1850_PrintString("Enter ");
    pbVar2 = (byte*)ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
    bVar1 = *pbVar2;
    if (bVar1 == 0x16)
    {
        uVar3 = "cave";
    LAB_0000_09ab:
        uStack_4 = MAINOUT_0790(uVar3);
    }
    else
    {
        if (bVar1 < 0x17)
        {
            if (bVar1 == 0x10)
            {
                uVar3 = "hut";
            }
            else
            {
                if (bVar1 == 0x11)
                {
                    ULTIMA_1850_PrintString("the Shrine of the Codex!\n");
                    goto LAB_0000_0968;
                }
                if (bVar1 == 0x12)
                {
                    uVar3 = "keep";
                }
                else if (bVar1 == 0x13)
                {
                    uVar3 = "village";
                }
                else if (bVar1 == 0x14)
                {
                    uVar3 = "towne";
                }
                else
                {
                    if (bVar1 != 0x15)
                        goto LAB_0000_09ee;
                    uVar3 = "castle";
                }
            }
        }
        else
        {
            if (bVar1 == 0x19)
            {
                ULTIMA_1850_PrintString("the shrine of\n");
                iVar4 = 0;
                do
                {
                    if ((*(char*)(iVar4 + D_1f6e) == D_5896_map_x) && (*(char*)(iVar4 + D_1f76) == D_5897_map_y))
                        break;
                    iVar4 = iVar4 + 1;
                } while (iVar4 < 8);
                ULTIMA_1850_PrintString(D_1f4e[iVar4]);
                ULTIMA_16ba_PrintChar(10);
            LAB_0000_0968:
                CAST2_0e76(); // THUNK 7a6a
                return 1;
            }
            if (bVar1 < 0x19)
            {
                if (bVar1 == 0x17)
                {
                    uVar3 = "mine";
                }
                else
                {
                    if (bVar1 != 0x18)
                    {
                    LAB_0000_09ee:
                        ULTIMA_1850_PrintString("What?\n");
                        return 0;
                    }
                    uVar3 = "dungeon";
                }
                goto LAB_0000_09ab;
            }
            if (bVar1 == 0x1a)
            {
                ULTIMA_1850_PrintString("ruins");
                return 1;
            }
            if (bVar1 == 0x1b)
            {
                uVar3 = "lighthouse";
            }
            else if (bVar1 == 0x39)
            {
                uVar3 = "the palace of Blackthorn!";
            }
            else
            {
                if (bVar1 != 0x3e)
                    goto LAB_0000_09ee;
                uVar3 = "the Castle of Lord British!";
            }
        }
        uStack_4 = OUTSUBS_0388(uVar3); // THUNK 7bba
    }
    return uStack_4;
}

// OK P1
int MAINOUT_0a1a(int param_1)
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
void MAINOUT_0a60(void)
{
    if (D_5895_map_level != 0)
    {
        if (ULTIMA_2092_RandomRange(0, 0xff) == 0x69)
        {
            ULTIMA_1850_PrintString("EARTHQUAKE!\n");
            ULTIMA_3072();
            ULTIMA_2aa8();
        }
    }
}

// OK P1 (stack)
void MAINOUT_0a84_MainLoop()
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
            ULTIMA_1850_PrintString("Zzzzzz...\n");
        }
        else if (local_8 == -1) // 0ac2
        {
            if (D_a9bd[0] != 1)
            {
                ULTIMA_251e_SwitchDisks(1);
                // 0ad6
                while (ULTIMA_1674_TestOpenFile("BRIT.DAT") == 0) {}
            }
            // 0ae1
            ULTIMA_25d8_WriteFile(OUTSUBS_0368_GetWorldSavefile(), D_5c5a, 0x100);
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
                    ULTIMA_1850_PrintString("Exit to DOS? ");
                    local_6 = ULTIMA_266c_GetChar();
                    if (local_6 == 'Y')
                    {
                        ULTIMA_0878_RestoreVideoMode();
                        exit(0);
                    }
                    else
                    {
                        ULTIMA_1850_PrintString("N\n");
                    }
                    break;

                case 0x16: // 0b6e
                    ULTIMA_1850_PrintString("1.16");
                    // 0b75
                    ULTIMA_16ba_PrintChar(10);
                    local_a = 0;
                    break;

                case 0x13: // 0b80
                    ULTIMA_1850_PrintString("Sound ");
                    if (D_a9ce != 0)
                    {
                        ULTIMA_1850_PrintString("Off\n");
                    }
                    else
                    {
                        ULTIMA_1850_PrintString("On\n");
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
                    ULTIMA_1850_PrintString("What?\n");
                    break;
                }
            }
            else
            {
                // 0bee
                if ((local_6 < 0x30) || (0x39 < local_6))
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
                    ULTIMA_1850_PrintString("\n\"");
                    if (D_58cc != 0)
                    {
                        ULTIMA_1850_PrintString("Pass, Seeker!\"\n");
                    }
                    else
                    {
                        ULTIMA_1850_PrintString("Thou art not upon a Sacred Quest!\n");
                        ULTIMA_1850_PrintString("Passage denied!\"\n");
                        D_5897_map_y++;
                    }
                }

                // 0cd0
                MAINOUT_0a60();
                ULTIMA_2ae8();
                if (local_12 == 1 && ((D_587c & 0xfc) == 0x28 || (D_587c & 0xfe) == 0x14))
                {
                    ULTIMA_1850_PrintString("Rough seas!\n");
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

// TODO: Match
int MAINOUT_0d8c(void)
{
    byte bVar1;
    int iStack_4;

    if (D_5895_map_level < 0x80)
    {
        bVar1 = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
        if ((bVar1 < 0x20) || (0x26 < bVar1))
        {
            if ((bVar1 == 4) || ((8 < bVar1 && (bVar1 < 0x10))))
            {
                iStack_4 = 2;
            }
            else
            {
                iStack_4 = 1;
            }
        }
        else
        {
            iStack_4 = 0;
        }
        if ((0x1f < D_587f) || (D_587f < 5))
        {
            iStack_4 = iStack_4 + 3;
        }
    }
    else
    {
        iStack_4 = 3;
    }

    return iStack_4;
}

// TODO: MATCH ([bx][si])
int MAINOUT_0e04(byte* param_1)
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

// TODO: MATCH
byte MAINOUT_0e4e(int param_1)
{
    int iVar1;

    if (param_1 < 4 || (0x5f < param_1 && param_1 < 0x70) || (0xd3 < param_1 && param_1 < 0xd8) ||
        (0xe3 < param_1 && param_1 < 0xe8))
    {
        iVar1 = ULTIMA_2092_RandomRange(0, 0x40);
        if (iVar1 < 0x10)
        {
            if (0x7f < D_5895_map_level)
            {
                iVar1 = MAINOUT_0e04(D_2bf6);
                return D_2bda[iVar1];
            }
            if ((param_1 == 1) && (iVar1 = ULTIMA_2092_RandomRange(0, 7), iVar1 == 7))
            {
                return 0xec;
            }
            iVar1 = MAINOUT_0e04(D_2bf0);
            return D_2bd4[iVar1];
        }
    }
    else if (param_1 == 7)
    {
        iVar1 = ULTIMA_2092_RandomRange(0, 3);
        if (iVar1 == 0)
        {
            return 0xe0;
        }
    }
    else
    {
        if ((param_1 == 4) && (D_5895_map_level == 0xff))
        {
            return 0xf8;
        }
        if (((param_1 != 0xc) && (param_1 != 0xd)) && ((param_1 < 0x10 || (((byte)param_1 & 0xfc) == 0x30))))
        {
            if (D_5895_map_level < 0x80)
            {
                iVar1 = MAINOUT_0e04(D_2bdc);
                return D_2bc0[iVar1];
            }
            iVar1 = MAINOUT_0e04(D_2be8);
            return D_2bcc[iVar1];
        }
    }
    return 0;
}

// TODO: MATCH
void MAINOUT_0f4e(void)
{
    int uVar2;

    do
    {
        do
        {
            D_5876 = (uint)(byte)(ULTIMA_2092_RandomRange(0, 0x1f) + D_589b);
            D_5878 = (uint)(byte)(ULTIMA_2092_RandomRange(0, 0x1f) + D_589c);
            uVar2 = (int)(D_5876 - (uint)D_5896_map_x) >> 0xf;
        } while ((int)((D_5876 - (uint)D_5896_map_x ^ uVar2) - uVar2) < 7);

        uVar2 = (int)(D_5878 - (uint)D_5897_map_y) >> 0xf;
    } while ((((int)((D_5878 - (uint)D_5897_map_y ^ uVar2) - uVar2) < 7) ||
              (uVar2 = (int)(D_5876 - (uint)D_5896_map_x) >> 0xf,
               0xf9 < (int)((D_5876 - (uint)D_5896_map_x ^ uVar2) - uVar2))) ||
             (uVar2 = (int)(D_5878 - (uint)D_5897_map_y) >> 0xf,
              0xf9 < (int)((D_5878 - (uint)D_5897_map_y ^ uVar2) - uVar2)));
}

// TODO: MATCH
void MAINOUT_0fc4(void)
{
    undefined2 uVar1;
    undefined2 uVar2;
    byte cVar3;
    int iVar6;
    int iStack_6;

    iStack_6 = 0;
    do
    {
        MAINOUT_0f4e();
        uVar1 = D_5876;
        uVar2 = D_5878;
        cVar3 = MAINOUT_0e4e(*ULTIMA_4402_GetTileAddr(uVar1, uVar2));
        if (cVar3 != 0 && (cVar3 != 0x2c || (*ULTIMA_4402_GetTileAddr(uVar1, uVar2) & 0xf0) != 0x60))
            break;
        iStack_6 = iStack_6 + 1;
    } while (iStack_6 < 0x80);

    if (iStack_6 != 0x80)
    {
        iVar6 = ULTIMA_38e4();
        ULTIMA_3a74(cVar3, cVar3, uVar1, uVar2, D_5895_map_level, 0, iVar6);
        if (cVar3 == 0x2c)
        {
            D_5c5a[iVar6]._5 = 100;
        }
    }
}

// TODO: Match
int MAINOUT_105c(int param_1)
{
    int uVar1;

    if (((param_1 < 0x2c) || (0x2f < param_1)) &&
        (((param_1 < 0x80 || ((0xb3 < param_1 && (param_1 < 0xb8)))) || ((0xe7 < param_1 && (param_1 < 0xec))))))
    {
        uVar1 = 0;
    }
    else
    {
        uVar1 = 1;
    }
    return uVar1;
}

// NOT MATCHING
void MAINOUT_109e(void)
{
    uint uVar2;
    undefined1 local_4;

    if ((D_587c & 0xf8) == 0x20)
    {
        uVar2 = ULTIMA_2092_RandomRange(1, 0x1e);
        if (uVar2 < D_5c5a[0]._5)
        {
            local_4 = (char)uVar2;
            D_5c5a[0]._5 -= local_4;
            ULTIMA_2900_UpdateVitalsDisplay();
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x6ada*/ "Ship sunk!\n");
            uVar2 = (uint)D_5c5a[0]._7;
            if (uVar2 == 0 && D_57b0 == 0)
            {
                D_587c = 0;
                ULTIMA_2900_UpdateVitalsDisplay();
                ULTIMA_5910_UpdateFrame();
                ULTIMA_43ae_AudioSweepTone(0x294, 0x96, 0x28, 0x1e78);
                ULTIMA_1850_PrintString(/*0x6af6*/ "DROWNING!!!\n");

                while (ULTIMA_39fc_GetFirstActivePartyMember() != -1)
                {
                    ULTIMA_3522(D_5897_map_y, D_5896_map_x);
                    ULTIMA_2aa8();
                }
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x6ae6*/ "Abandon ship!\n");
                if ((int)uVar2 < 1)
                {
                    D_57b0 -= 1;
                    D_587c = ULTIMA_2092_RandomRange(0, 1) + 0x14;
                }
                else
                {
                    D_587c = (D_587c & 3) + 0x28;
                }
                D_a9fa = 1;
            }
        }
    }
    else
    {
        ULTIMA_2aa8();
    }
}

// NOT MATCHING
void MAINOUT_1168(int param_1, int param_2, int param_3)
{
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

    if (COMSUBS_12de(D_5c5a[param_1]._2_x - D_5896_map_x + 5, D_5c5a[param_1]._3_y - D_5897_map_y + 5, 5, 5, 1) != 0)
    {
        ULTIMA_5910_UpdateFrame();
        ULTIMA_3522(D_5896_map_x, D_5897_map_y);
        MAINOUT_109e();
    }
}

// NOT MATCHING
void MAINOUT_1248(int param_1)
{
    int local_4;

    if ((D_5c5a[param_1]._0_tile & 0xfc) == 0xec)
    {
        if (D_587c != 0x1c)
        {
            D_5c5a[param_1]._1 = 0;
            D_5c5a[param_1]._0_tile = 0;
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
        if (*ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y) > 3 ||
            ((D_587c & 0xfe) != 0x14 && (D_587c & 0xfc) != 0x28))
        {
            ULTIMA_6150_Attack(param_1);
            return;
        }
    }

    MAINOUT_109e();
}

int COMSUBS_12de(int param_1, int param_2, int param_3, int param_4, int param_5);

// TODO: Match
int MAINOUT_131a(int param_1)
{
    byte bVar1;
    uint uVar2;
    undefined2 uVar3;
    int iVar4;
    uint uVar5;
    int iStack_8;
    int iStack_6;

    bVar1 = D_5c5a[param_1]._0_tile;
    uVar2 = (uint)D_5c5a[param_1]._2_x - (uint)D_5896_map_x;
    uVar5 = (s16)uVar2 >> 0xf; // iStack_6 =
    iStack_6 = (uVar2 ^ uVar5) - uVar5; //     abs(uVar2)
    if (0x7f < iStack_6)
    {
        iStack_6 = 0x100 - iStack_6;
    }

    uVar2 = (u16)D_5c5a[param_1]._3_y - (uint)D_5897_map_y;
    uVar5 = (s16)uVar2 >> 0xf; // iStack_8 =
    iStack_8 = (uVar2 ^ uVar5) - uVar5; //     abs(uVar2)
    if (0x7f < iStack_8)
    {
        iStack_8 = 0x100 - iStack_8;
    }

    if ((iStack_6 == 1 && iStack_8 == 0) || (iStack_6 == 0 && iStack_8 == 1))
    {
        MAINOUT_1248(param_1);
    LAB_0000_139c:
        uVar3 = 1;
    }
    else
    {
        if (bVar1 == 0x88 || bVar1 == 0xdc)
        {
            if (iStack_6 < 4 && iStack_8 < 4 && ULTIMA_2092_RandomRange(0, 7) == 0)
            {
                ULTIMA_5910_UpdateFrame();
                ULTIMA_43ae_AudioSweepTone(0x514, 300, 5, 100);
                iVar4 = COMSUBS_12de((D_5c5a[param_1]._2_x - D_5896_map_x) + 5,
                                       (D_5c5a[param_1]._3_y - D_5897_map_y) + 5, 5, 5, 3);
                if (iVar4 != 0)
                {
                    ULTIMA_3522(D_5896_map_x, D_5897_map_y);
                    MAINOUT_109e();
                }
                goto LAB_0000_139c;
            }
        }
        else if ((bVar1 & 0xfc) == 0x2c && ((iStack_6 == 0 && iStack_8 < 4) || (iStack_8 == 0 && iStack_6 < 4)))
        {
            ULTIMA_1850_PrintString("* BOOOM! *\n\n");
            MAINOUT_1168(param_1, iStack_6, iStack_8);
            goto LAB_0000_139c;
        }
        uVar3 = 0;
    }
    return uVar3;
}

// NOT MATCHING
int MAINOUT_1482(int param_1, int param_2, int param_3)
{
    if (ULTIMA_2c4c(D_5c5a[param_1]._0_tile, *ULTIMA_4402_GetTileAddr(param_2, param_3)) != 0 &&
        ULTIMA_3702(param_2, param_3, D_5895_map_level) == 0)
    {
        return 1;
    }

    return 0;
}

// NOT MATCHING
int MAINOUT_14c8(int param_1, int param_2)
{
    if (param_1 == D_a526 && param_2 == D_a527)
    {
        return 0;
    }

    return 1;
}

// NOT MATCHING
int MAINOUT_14ea(int param_1)
{
    int local_6;
    int local_4;

    local_4 = abs(D_5c5a[param_1]._2_x - D_5896_map_x);
    if (0x7f < local_4)
    {
        local_4 = 0x100 - local_4;
    }

    local_6 = abs(D_5c5a[param_1]._3_y - D_5897_map_y);
    if (0x7f < local_6)
    {
        local_6 = 0x100 - local_6;
    }

    if (local_4 < 6 && local_6 < 6)
    {
        return D_2c18[local_4 + local_6 * 0xb];
    }

    return 0;
}

// NOT MATCHING
void MAINOUT_1578(int param_1, int param_2, int param_3)
{
    byte bVar1;
    int iVar2;
    undefined1* puVar3;
    int iVar6;
    undefined1 local_a;
    undefined1 local_8;
    char local_4;

    bVar1 = D_5c5a[param_1]._0_tile;
    iVar2 = D_5c5a[param_1]._2_x + param_2;
    iVar6 = D_5c5a[param_1]._3_y + param_3;
    puVar3 = ULTIMA_4402_GetTileAddr(iVar2, iVar6);
    if ((bVar1 & 0xfc) == 0x2c)
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
        D_5c5a[param_1]._1 = local_4 + ',';
        D_5c5a[param_1]._0_tile = local_4 + ',';
    }
    else if (bVar1 != 0xdc && bVar1 != 0x94 && bVar1 != 0xd8 && bVar1 != 0xf0)
    {
        switch (*puVar3)
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

    local_8 = (undefined1)iVar2;
    D_5c5a[param_1]._2_x = local_8;

    local_a = (undefined1)iVar6;
    D_5c5a[param_1]._3_y = local_a;
    D_24e6 |= 2;

    if (*ULTIMA_4402_GetTileAddr(iVar2, iVar6) == 0xdc)
    {
        D_5c5a[param_1]._1 = 0;
        D_5c5a[param_1]._0_tile = 0;
    }
}

// NOT MATCHING
void MAINOUT_16fc(int param_1)
{
    int uVar1;
    uint uVar3;
    uint uVar4;
    int uVar5;
    int local_8;

    uVar4 = D_5c5a[param_1]._2_x;
    uVar3 = D_5c5a[param_1]._3_y;
    local_8 = 0;

    while (1)
    {
        if (local_8 < 3)
        {
            switch (ULTIMA_2092_RandomRange(0, 3))
            {
            case 0:
                if (MAINOUT_1482(param_1, uVar4, uVar3 - 1) == 0)
                {
                    return;
                }
                uVar5 = -1;
                uVar1 = 0;
                MAINOUT_1578(param_1, uVar1, uVar5);
                break;

            case 1:
                if (MAINOUT_1482(param_1, uVar4 + 1, uVar3) == 0)
                {
                    return;
                }
                uVar5 = 0;
                uVar1 = 1;
                MAINOUT_1578(param_1, uVar1, uVar5);
                break;

            case 2:
                if (MAINOUT_1482(param_1, uVar4, uVar3 + 1) == 0)
                {
                    return;
                }
                uVar5 = 1;
                uVar1 = 0;
                MAINOUT_1578(param_1, uVar1, uVar5);
                break;

            case 3:
                if (MAINOUT_1482(param_1, uVar4 - 1, uVar3) == 0)
                {
                    return;
                }
                uVar5 = 0;
                uVar1 = -1;
                MAINOUT_1578(param_1, uVar1, uVar5);
                break;

            default:
                local_8++;
                continue;
            }
        }

        return;
    }
}

// NOT MATCHING
void MAINOUT_17d4(int param_1, int param_2)
{
    uint uVar2;
    uint uVar3;
    int iVar4;
    int local_e;
    int local_a;
    int local_6;
    int local_4;

    uVar2 = D_5c5a[param_1]._2_x;
    uVar3 = D_5c5a[param_1]._3_y;
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

    if (local_a == 0)
    {
        local_4 = 0;
    }
    else if (local_a < 1)
    {
        if (local_a < 0)
        {
            local_4 = 1;
        }
    }
    else
    {
        local_4 = -1;
    }

    if (local_e == 0)
    {
        local_6 = 0;
    }
    else if (local_e < 1)
    {
        if (local_e < 0)
        {
            local_6 = 1;
        }
    }
    else
    {
        local_6 = -1;
    }

    if (ULTIMA_2092_RandomRange(0, 1) == 1)
    {
        if (local_4 != 0)
        {
            // 18c3
            iVar4 = MAINOUT_1482(param_1, uVar2 + local_4, uVar3);
            if (iVar4 != 0 && MAINOUT_14c8(uVar2 + local_4, uVar3) != 0)
            {
                // 18e2
                local_6 = 0;
                MAINOUT_1578(param_1, local_4, local_6);
                return;
            }
        }

        // 18fc
        if (local_6 == 0)
        {
            // -> 197d
            MAINOUT_16fc(param_1);
            return;
        }

        // 1902
        iVar4 = MAINOUT_1482(param_1, uVar2, uVar3 + local_6);
        if (iVar4 == 0 || MAINOUT_14c8(uVar2, uVar3 + local_6) == 0)
        {
            MAINOUT_16fc(param_1);
            return;
        }

        // 192a
        local_4 = 0;
        MAINOUT_1578(param_1, local_4, local_6);
    }
    else
    {
        // 1930
        if (local_6 != 0)
        {
            // 1936
            iVar4 = MAINOUT_1482(param_1, uVar2, uVar3 + local_6);
            if (iVar4 != 0 && MAINOUT_14c8(uVar2, uVar3 + local_6) != 0)
            {
                // ->192a
                local_4 = 0;
                MAINOUT_1578(param_1, local_4, local_6);
                return;
            }
        }

        if (local_4 == 0)
        {
            // -> 197d
            MAINOUT_16fc(param_1);
            return;
        }

        // 195b
        iVar4 = MAINOUT_1482(param_1, uVar2 + local_4, uVar3);
        if (iVar4 == 0 || MAINOUT_14c8(uVar2 + local_4, uVar3) == 0)
        {
            // 197d
            MAINOUT_16fc(param_1);
            return;
        }

        // -> 18e2
        local_6 = 0;
        MAINOUT_1578(param_1, local_4, local_6);
    }
}

// NOT MATCHING
void MAINOUT_198c(int param_1)
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
            // nop
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
        local_6 = ((uint)D_5c5a[param_1]._0_tile - 0x2c);
        // 1a21..1a31; NOT MATCHING
        local_4 = D_2bf8[local_6 * 4 + D_5892_wind_dir - 1];
        if (local_4 != 4 && local_4 < ++D_5c5a[param_1]._7)
        {
            D_5c5a[param_1]._7 = 0;
            return;
        }
    }
    MAINOUT_17d4(param_1, 1);
}

// TODO: Match
int MAINOUT_1a60(void)
{
    int iVar2;
    int iVar3;
    int iStack_4;

    iStack_4 = 0;
    if (D_587a == 'T')
    {
        iStack_4 = 0;
        return iStack_4;
    }
    else
    {
        if (D_587a == 'Q')
        {
            D_2c55 = D_2c55 ^ 1;
            if (D_2c55 != 0)
            {
                iStack_4 = 0;
                return iStack_4;
            }
        }
        if (((D_587c & 0xfe) == 0x12) || ((D_587c & 0xfe) == 0x14))
        {
            D_2c57 = D_2c57 ^ 1;
            if (D_2c57 != 0)
            {
                iStack_4 = 0;
                return iStack_4;
            }
        }
        if (ULTIMA_2092_RandomRange(1, 0x1e) < MAINOUT_0d8c())
        {
            MAINOUT_0fc4();
        }
        for (iVar2 = 0x1f; 0 < iVar2; iVar2--)
        {
            iVar3 = MAINOUT_105c(D_5c5a[iVar2]._0_tile);
            if (iVar3 != 0)
            {
                iVar3 = MAINOUT_131a(iVar2);
                iStack_4 = iStack_4 + iVar3;
                if (iStack_4 == 0)
                {
                    MAINOUT_198c(iVar2);
                }
            }
        }

        for (iVar2 = 0x1f; 0 < iVar2; iVar2--)
        {
            iVar3 = MAINOUT_105c(D_5c5a[iVar2]._0_tile);
            if (iVar3 != 0 && ((0x1f < (D_5c5a[iVar2]._2_x - D_589b) || (0x1f < (D_5c5a[iVar2]._3_y - D_589c)))))
            {
                ULTIMA_3a74(0, 0, 0, 0, 0, 0, iVar2);
            }
        }
    }
    return iStack_4;
}

// NOT MATCHING
void MAINOUT_1b3e(void)
{
    int local_8;
    int local_6;
    int local_4;

    ULTIMA_1850_PrintString(/*0x6b2c*/ "Caught!\n\nThe trolls demand a ");
    ULTIMA_39fc_GetFirstActivePartyMember();
    local_8 = -(D_55a8_party[D_5876]._c * 3 - 99);
    ULTIMA_1a3e_PrintNumber(local_8, 2, 0x20);
    ULTIMA_1850_PrintString(/*0x6b4a*/ " gp toll!\n\nDost thou pay?");

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
        if (0 <= (int)D_57aa)
        {
            return;
        }
        D_57aa += local_8;
    }

    local_6 = ULTIMA_38e4();
    ULTIMA_3a74(0xe4, 0, D_5896_map_x, D_5897_map_y, 0, 0, local_6);
    ULTIMA_6150_Attack(local_6);
}

// NOT MATCHING
void MAINOUT_1be8(void)
{
    int local_6;
    int local_4;

    local_6 = ULTIMA_2092_RandomRange(0, 7);
    if (local_6 == 0 && D_587c == 0x1c)
    {
        ULTIMA_5910_UpdateFrame();
        ULTIMA_1850_PrintString(/*0x6b64*/ "\nThou spieth trolls under the bridge!\n\n");
        ULTIMA_3ae6(10);
        if (D_585b != 0)
        {
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
        }

        ULTIMA_1850_PrintString(/*0x6ba0*/ "Trolls evaded!\n");
    }
}
