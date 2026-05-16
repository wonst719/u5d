#include "common/common.h"
#include "funcs.h"
#include "vars.h"

#include "town.h"

void CAST2_0000(int);
int CAST2_009e(void);
int CAST2_00de(void);
int CAST2_0306(void);
int CAST2_03c2(int);
void CAST2_040a(int, int);
void CAST2_046c(void);
int CAST2_04c2(int);
int CAST2_05e0(int, int);
void CAST2_06ec(void);
int CAST2_0768(void);
int CAST2_07bc(int);
void CAST2_08ea(int);
void CAST2_08f8(int, int, int);

void LOOKOBJ_10fc_ViewCmd(int, int);
void DNGLOOK_06a8_ViewCmd(void);

int DUNGEON_1c6a(int, int);
void DUNGEON_1d08(void);

int COMBAT_0000(int, int, int);
int COMBAT_120e(void);
void COMBAT_18ba(int, int);

void MAINOUT_0000(void);

int COMBAT_13e2(int, int);
int COMBAT_1574(int param_1, int param_2);

int COMSUBS_0000(int, int, int);
void COMSUBS_0094(int a);
void COMSUBS_0312(int a, int b);
int COMSUBS_0504(int a, int b);
int COMSUBS_0748(int a, int b);
void COMSUBS_0c52(int param_1, int param_2);
void COMBAT_1236(int a);

void ZSTATS_045e(int param_1);
int ZSTATS_05a4(int param_1, int param_2, byte* param_3, int param_4);
void ZSTATS_099a(void);
int ZSTATS_0f2e(int param_3, undefined2 param_2, int param_1);

void CAST_04a4(void);

void LOOKOBJ_0366(void);

// OK P1
int CAST_0000(int param_1)
{
    int local_4 = D_ba14[param_1]._3;
    if (local_4 == 47 || local_4 == 0xe || local_4 == 0xf)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// OK P1
void CAST_0032(int param_1)
{
    D_589d = param_1;
    COMSUBS_0c52(D_589e, param_1);
}

// OK P1
int CAST_004c(int param_1)
{
    int local_a;
    int local_8;
    int local_4;
    int local_6;

    if (D_5893_map_id < 0x80)
    {
        CAST2_0000(param_1 == 3 ? 4 : 3);
        local_4 = (D_24d6[D_6603] + D_5896_map_x) & 7;
        local_6 = (D_24de[D_6603] + D_5897_map_y) & 7;

        local_a = D_595a[D_5895_map_level * 0x40 + local_6 * 8 + local_4];
        if ((local_a & 0xf7) != 0)
        {
            local_8 = 0;
        }
        else
        {
            D_595a[D_5895_map_level * 0x40 + local_6 * 8 + local_4] = (local_a & 8) | D_4596[param_1];
            local_8 = -1;
        }
    }
    else
    {
        D_589d = D_4592[param_1];
        COMSUBS_0c52(D_589e, D_589d);
        local_8 = -1;
    }

    return local_8;
}

// OK P1
int CAST_0114(void)
{
    int local_8;
    int local_6;
    int local_4;

    local_8 = CAST2_009e();
    if (local_8 < 0)
    {
        local_4 = -1;
    }
    else if (D_55a8_party[local_8]._b == 0x53)
    {
        D_55a8_party[local_8]._b = 0x47;
        if (D_5893_map_id > 0x7f)
        {
            for (local_6 = 0; local_6 < 0x20; local_6++)
            {
                if ((D_ba14[local_6]._2 & 0xe8) == 0x88 && D_ba14[local_6]._3 == local_8)
                {
                    ULTIMA_6800(local_6);
                    break;
                }
            }

            if (local_6 == 0x20)
            {
                local_4 = 0;
            }
        }

        CAST2_0000(1);
        local_4 = -1;
        D_a9fa = 1;
    }
    else
    {
        local_4 = 0;
    }

    return local_4;
}

// OK P1
int CAST_01ae(void)
{
    int local_6;
    int local_4;

    local_6 = CAST2_009e();
    if (local_6 < 0)
    {
        local_4 = -1;
    }
    else
    {
        if (D_55a8_party[local_6]._b == 'P')
        {
            D_55a8_party[local_6]._b = 'G';
            CAST2_0000(1);
            D_a9fa = 1;
            local_4 = 1;
        }
        else
        {
            local_4 = 0;
        }
    }

    return local_4;
}

// OK P1
int CAST_01fa(void)
{
    int local_6;
    int local_4;

    local_6 = CAST2_009e();
    if (local_6 < 0)
    {
        local_4 = -1;
    }
    else
    {
        local_4 = CAST2_03c2(local_6);
    }

    if (local_4 != 0)
    {
        CAST2_0000(1);
    }

    return local_4;
}

// OK P1
int CAST_0230(void)
{
    int local_6;
    byte* local_4;

    if (CAST2_0306() == 0)
    {
        return -1;
    }

    CAST2_0000(1);
    local_4 = ULTIMA_4402_GetTileAddr(D_5876, D_5878);
    switch (*local_4)
    {
    case 0x5b:
    case 0x90:
    case 0x91:
    case 0x92:
    case 0x93:
    case 0x9d:
    case 0xa5:
    case 0xa6:
    case 0xa8:
    case 0xa9:
    case 0xad:
    case 0xae:
    case 0xaf:
        *local_4 = 0x44;
        ULTIMA_1850_PrintString(/*0x459a*/ "POOF!\n");
        D_24e6 |= 2;
        ULTIMA_5910_UpdateFrame();
        ULTIMA_43ae_AudioSweepTone(0x4b0, 2000, 1, 0x28);
        local_6 = -1;
        break;

    default:
        local_6 = 0;
        break;
    }

    return local_6;
}

// NOT MATCHING
int CAST_02d2(void)
{
    int iVar1;
    byte* pcVar2;
    int local_a;
    int local_8;
    byte* local_4;

    if (D_5893_map_id < 0x21 || D_5893_map_id > 0x7f)
    {
        iVar1 = CAST2_0306();
        if (iVar1 == 0)
        {
            local_8 = -1;
        }
        else
        {
            local_8 = 0;
            pcVar2 = ULTIMA_4402_GetTileAddr(D_5876, D_5878);
            if (*pcVar2 == 0xb9 || *pcVar2 == 0xbb)
            {
                *pcVar2 = *pcVar2 - 1;
                D_24e6 |= 2;
                CAST2_0000(2);
                local_8 = 1;
            }
            else
            {
                for (local_a = 0; local_a < 0x20; local_a++)
                {
                    if (D_5c5a[local_a]._0_tile == 1 && D_5c5a[local_a]._2_x == D_5876 &&
                        D_5c5a[local_a]._3_y == D_5878 &&
                        (D_5893_map_id > 0x7f || D_5c5a[local_a]._4_z == D_5895_map_level))
                    {
                        D_5c5a[local_a]._5 &= 0x7f;
                        CAST2_0000(2);
                        return 1;
                    }
                }
            }
        }
    }
    else
    {
        CAST2_0000(2);

        local_4 = &D_595a[D_5895_map_level * 0x40 + D_5897_map_y * 8 + D_5896_map_x];
        if ((*local_4 & 0xf0) != 0x40)
        {
            local_4 = &D_595a[(D_24de[D_6603] + D_5897_map_y & 7) * 8 + (D_24d6[D_6603] + D_5896_map_x & 7) +
                              D_5895_map_level * 0x40];
        }

        if ((*local_4 & 0xf0) == 0x40)
        {
            if ((*local_4 & 1) != 0)
            {
                ULTIMA_1850_PrintString(/*0x45a1*/ "Disarmed!\n");
            }

            *local_4 = (*local_4 & 8) | 0x70;
            ULTIMA_1850_PrintString(/*0x45ac*/ "Chest opened!\n");

            local_8 = -1;
        }
        else
        {
            local_8 = 0;
        }
    }

    return local_8;
}

// OK P1
void CAST_043e(void)
{
    S_ba14* local_4;
    int local_6;

    CAST2_0000(2);

    for (local_6 = 0; local_6 < 0x20; local_6++)
    {
        local_4 = &D_ba14[local_6];
        if (CAST_0000(local_6) == 0 && (local_4->_2 & 0xc0) == 0x40 &&
            ((byte)D_153c[local_4->_3] & 0x20) != 0)
        {
            if (COMSUBS_0000(D_589e, local_6, 0) == 0)
            {
                local_4->_0 = 1;
                local_4->_2 |= 2;
            }
        }
    }
}

// OK P1
void CAST_04a4(void)
{
    CAST2_0000(2);
    CAST2_06ec();
}

// NOT MATCHING
int CAST_04b0(void)
{
    int local_10;
    int local_e;
    int local_c;
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    CAST2_0000(2);

    local_c = ULTIMA_2092_RandomRange(0, 0xf);
    if (local_c < 6)
    {
        local_4 = 0x14;
    }
    else if (local_c < 0xb)
    {
        local_4 = 0x16;
    }
    else if (local_c < 0xe)
    {
        local_4 = 0x15;
    }
    else
    {
        local_4 = 0x22;
    }

    // 04f9
    local_a = 0;
    local_c = 0;

    local_e = local_4 * 4 + 0x40;
    local_10 = local_4 * 4 + 0x140;

    // si = local_6

    // 0522
    while (COMBAT_120e() == 0 || COMBAT_0000(0x90, D_5876, D_5878) == 0)
    {
        if (++local_c >= 8)
        {
            // -> 0566
            // local_6 = si
            return local_a;
        }
    }

    // 0548
    local_8 = ULTIMA_6506(local_4, 0, D_5876, D_5878, D_5895_map_level);
    if (local_8 < 0)
    {
        // 0566
        // local_6 = si
        return local_a;
    }
    else
    {
        // 056c
        D_5c5a[D_ba14[local_8]._4]._1 = D_5c5a[D_ba14[local_8]._4]._0_tile = 0x16;

        // 0588
        ULTIMA_1068(local_10, D_5876, D_5878);
    
        D_5c5a[D_ba14[local_8]._4]._1 = D_5c5a[D_ba14[local_8]._4]._0_tile = local_e;
        D_ba14[local_8]._2 |= 1;

        local_a = 1;
    }

    // 05aa
    return local_a;
}

// OK P1
int CAST_05b4(void)
{
    CAST2_0000(2);
    ULTIMA_3f14(&D_57a8, ULTIMA_2092_RandomRange(1, 3), 9999);
    D_a9fa = 1;
    return 1;
}

// OK P1
int CAST_05dc(void)
{
    int local_14;
    int local_12;
    int local_10;
    int local_e;
    int local_c;
    int local_a;
    int local_8;
    int local_6;
    ActorFmt* local_4;

    local_c = 0;
    if (D_5893_map_id > 0x7f)
    {
        local_4 = &D_5c5a[D_ba14[D_589e]._4];
        if ((D_58a1 & 2) != 0)
        {
            local_c = 0;
        }
        else
        {
            CAST2_0000(3);
            for (local_6 = 0; local_6 < 7; local_6++)
            {
                if (COMBAT_120e() == 0)
                    continue;

                if (COMBAT_0000(local_4->_0_tile, D_5876, D_5878) == 0)
                    continue;

                local_4->_2_x = D_ba14[D_589e]._6 = D_5876;
                local_4->_3_y = D_ba14[D_589e]._7 = D_5878;

                local_c = 1;
                break;
            }
        }
    }
    else
    {
        // 0680
        if (CAST2_0306() == 0)
        {
            return -1;
        }
        else
        {
            // 068e
            CAST2_0000(3);

            local_12 = D_5876 - D_5896_map_x;
            local_14 = D_5878 - D_5897_map_y;

            local_e = D_589b + 0x20;
            if (local_e > 0x100)
            {
                local_e = 0x100;
            }

            local_10 = D_589c + 0x20;
            if (local_10 > 0x100)
            {
                local_10 = 0x100;
            }

            // 06d9
            local_c = 0;
            local_8 = (byte)D_5876;
            for (local_a = (byte)D_5878; D_589b <= local_8 && local_8 < local_e && D_589c <= local_a && local_a < local_10;
                 local_a += local_14)
            {
                if (*ULTIMA_4402_GetTileAddr(local_8, local_a) == 5)
                {
                    local_c = -1;
                    D_5896_map_x = local_8;
                    D_5897_map_y = local_a;
                    D_24e6 = 1;
                }
                local_8 += local_12;
            }

            if (local_c != 0)
            {
                MAINOUT_0000();
            }
        }
    }

    return local_c;
}

// OK P1
void CAST_074c(void)
{
    int local_6;
    ActorFmt* local_4;

    CAST2_0000(4);

    for (local_6 = 0; local_6 < 0x20; local_6++)
    {
        if (D_ba14[local_6]._2 != 0 && (D_ba14[local_6]._2 & 0x80) == 0 && (D_ba14[local_6]._2 & 0x10) != 0)
        {
            D_ba14[local_6]._2 &= 0xef;
            local_4 = &D_5c5a[D_ba14[local_6]._4];
            local_4->_1 = local_4->_0_tile;

            ULTIMA_5394();
            ULTIMA_56ac_DrawMap();
        }
    }
}

// OK P1
int CAST_07b4(void)
{
    int local_4;
    int local_8;
    int local_6;

    CAST2_0000(5);

    local_6 = 0;

    // 07c7
    for (local_8 = 0; local_8 < 8; local_8++)
    {
        if (COMBAT_120e() == 0 || COMBAT_0000(0xbc, D_5876, D_5878) == 0)
            continue;

        local_6 = 1;
        break;
    }

    if (local_6 != 0)
    {
        local_6 = 0;

        for (local_8 = 0; local_8 < 4; local_8++)
        {
            local_4 = ULTIMA_6506(0x1f, 0, D_5876, D_5878, D_5895_map_level);
            if (local_4 < 0)
            {
                break;
            }

            D_ba14[local_4]._2 |= 1;
            local_6 = 1;
        }
    }

    return local_6;
}

// OK P1
int CAST_0846(void)
{
    int local_6;
    byte* local_4;

    if (CAST2_0306() == 0)
    {
        return -1;
    }
    else
    {
        CAST2_0000(5);
        local_4 = ULTIMA_4402_GetTileAddr(D_5876, D_5878);
        local_6 = 0;
        switch (*local_4)
        {
        case 0xb8:
        case 0xb9:
            *local_4 = 0x97;
            local_6 = 1;
            D_24e6 |= 2;
            break;

        case 0xba:
        case 0xbb:
            *local_4 = 0x98;
            local_6 = 1;
            D_24e6 |= 2;
            break;
        }

        return local_6;
    }
}

// OK P1
int CAST_08ac(void)
{
    int local_6;
    int local_4;

    local_6 = CAST2_009e();
    if (local_6 < 0)
    {
        local_4 = -1;
    }
    else if (D_55a8_party[local_6]._b == 'D' || (D_5893_map_id > 0x7f && D_58a3 == 0))
    {
        local_4 = 0;
    }
    else if (D_5893_map_id > 0x7f && D_58a3 == 0) // sic
    {
        local_4 = 0;
    }
    else
    {
        D_55a8_party[local_6]._10 = D_55a8_party[local_6]._12;
        CAST2_0000(5);
        D_a9fa = 1;
        local_4 = 1;
    }

    return local_4;
}

// OK P1
void CAST_091e(int param_1)
{
    int local_4;

    CAST2_0000(6);
    ULTIMA_3072();
    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        if (D_ba14[local_4]._2 != 0)
        {
            if (ULTIMA_5646(local_4) != 0)
            {
                if (COMBAT_13e2(local_4, -2) <= ULTIMA_3abe())
                {
                    ULTIMA_3564(local_4);
                    ULTIMA_3f14(&D_55a8_party[param_1]._14, COMBAT_1574(local_4, ULTIMA_2092_RandomRange(1, 0x14)), 9999); // FMT: &local_8 ??
                    COMSUBS_0312(local_4, D_589e);
                }
            }
        }
    }
}

// OK P1
int CAST_09a0(void)
{
    int local_4;

    ULTIMA_1850_PrintString(/*0x45bb*/ "Creature: ");
    if (COMSUBS_0504(D_589e, 0xf) == 0)
    {
        return -1;
    }

    // 09c6
    CAST2_0000(6);
    if ((*ULTIMA_4402_GetTileAddr(D_5899, D_589a) & 0xfe) == 0x84)
    {
        return 0;
    }

    local_4 = COMSUBS_0748(D_5899, D_589a);
    if (local_4 >= 0)
    {
        if (CAST_0000(local_4) == 0 &&ULTIMA_5646(local_4) != 0 && COMSUBS_0000(D_589e, local_4, 0) == 0)
        {
            D_ba14[local_4]._2 ^= 1;
            if ((D_ba14[local_4]._2 & 0x80) != 0)
            {
                D_55a8_party[D_ba14[local_4]._3]._b = 0x47;
                ULTIMA_2900_UpdateVitalsDisplay();
            }

            COMSUBS_0094(local_4);
            ULTIMA_1850_PrintString(/*0x45c6*/ " charmed!\n");

            return -1;
        }
    }

    return 0;
}

// OK P1
int CAST_0a5c(void)
{
    int local_8;
    int local_6;
    int local_4;

    ULTIMA_1850_PrintString(/*0x45d1*/ "Creature: ");
    if (COMSUBS_0504(D_589e, 0xf) == 0)
    {
        return -1;
    }

    // 0a82
    CAST2_0000(6);
    local_4 = COMSUBS_0748(D_5899, D_589a);
    if (local_4 < 0)
    {
        return 0;
    }

    if (CAST_0000(local_4) == 0 && COMSUBS_0000(D_589e, local_4, 0) == 0)
    {
        local_6 = D_ba14[local_4]._6;
        local_8 = D_ba14[local_4]._7;
        COMBAT_1236(-local_4 - 1);
        ULTIMA_6506(0x14, 0, local_6, local_8, D_5895_map_level);
        return 1;
    }

    return 0;
}

// OK P1
int CAST_0afe(void)
{
    D_5c5a[D_ba14[D_589e]._4]._1 = 0x1d;
    D_ba14[D_589e]._2 |= 0x10;
    CAST2_0000(7);
    return 1;
}

// OK P1
int CAST_0b28(void)
{
    int local_c;
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    ULTIMA_1850_PrintString(/*0x45dc*/ "Creature: ");
    if (COMSUBS_0504(D_589e, 0xf) == 0)
    {
        return -1;
    }

    CAST2_0000(7);
    local_6 = COMSUBS_0748(D_5899, D_589a);
    if (local_6 < 0)
    {
        local_8 = 0;
    }
    else
    {
        // 0b72
        local_4 = local_c = 0xff;
        for (local_a = 0; local_a < 0x20; local_a++)
        {
            if (D_5c5a[local_a]._0_tile == 0)
            {
                local_c = local_a;
                break;
            }
        }

        if (local_c != 0xff)
        {
            for (local_a = 0; local_a < 0x20; local_a++)
            {
                if (D_ba14[local_a]._2 == 0)
                {
                    local_4 = local_a;
                    break;
                }
            }

            if (local_4 != 0xff)
            {
                // 0bbc
                D_ba14[local_4] = D_ba14[local_6];
                
                D_ba14[local_4]._4 = local_c;

                D_5c5a[local_c] = D_5c5a[D_ba14[local_6]._4];

                do
                {
                    if (COMBAT_120e() == 0 || COMBAT_0000(0x1c, D_5876, D_5878) == 0)
                    {
                        local_8 = 0;
                    }
                    else
                    {
                        D_5c5a[local_c]._2_x = D_ba14[local_4]._6 = D_5876;
                        D_5c5a[local_c]._3_y = D_ba14[local_4]._7 = D_5878;
                        local_8 = 1;
                    }
                } while (local_8 == 0);
            }
        }
    }

    return local_8;
}

// OK P1
void CAST_0c98(void)
{
    int local_6;
    S_ba14* local_4;

    CAST2_0000(7);

    for (local_6 = 0; local_6 < 0x20; local_6++)
    {
        local_4 = &D_ba14[local_6];
        if ((local_4->_2 & 0xc0) == 0x40)
        {
            if (CAST_0000(local_6) == 0)
            {
                if (COMSUBS_0000(D_589e, local_6, 0) == 0)
                {
                    local_4->_0 = 1;
                    local_4->_2 |= 2;
                }
            }
        }
    }
}

// OK P1
int CAST_0cf0(void)
{
    byte local_4;

    if ((D_587c & 0xf0) != 0x20)
    {
        ULTIMA_1850_PrintString(/*0x45e7*/ "To phase: ");
        local_4 = ULTIMA_266c_GetChar();
        if (local_4 >= 0x20)
        {
            ULTIMA_16ba_PrintChar(local_4);
        }

        ULTIMA_16ba_PrintChar(10);

        if (local_4 >= 0x31 && local_4 <= 0x38)
        {
            local_4 -= 0x31;
            CAST2_0000(8);
            if (ULTIMA_47f4(local_4) != 0)
            {
                return -1;
            }
        }
    }

    return 0;
}

// OK P1
int CAST_0d4c(void)
{
    int local_4;
    int local_6;

    CAST2_0000(8);
    local_6 = -1;

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        if (D_5c5a[local_4]._0_tile == 0xfc)
        {
            ULTIMA_1850_PrintString(/*0x45f2*/ "Magic absorbed!\n");
            ULTIMA_2192_AudioPulse(0x2648, 1, 28000, 1000, 2);
            local_6 = 0;
            break;
        }
    }

    if (local_6 != 0)
    {
        D_587a = 0x54;
        D_588e = 10;
        ULTIMA_2900_UpdateVitalsDisplay();
    }

    return local_6;
}

void CAST_1f60(int param_1, int param_2, int param_3);

// NOT MATCHING
int CAST_0dba_CastSpellCmd(void)
{
    int iVar1;
    int iVar2;
    uint uVar3;
    bool bVar4;
    int iVar7;
    undefined2 uVar10;

    uVar10 = 1;
    D_588f = 1;
    D_5890 = 1;
    iVar7 = 1;
    iVar1 = ULTIMA_4988();
    if (iVar1 < 0)
    {
        return iVar1;
    }

    ULTIMA_1850_PrintString(/*0x4603*/ "Spell name:\n:");
    iVar2 = CAST2_00de();
    if (iVar2 == -1)
    {
        ULTIMA_1850_PrintString(/*0x4611*/ "None!\n");
        return; // sic
    }

    if (iVar2 == -2)
    {
        ULTIMA_1850_PrintString(/*0x4618*/ "No effect!\n");
        return; // sic
    }

    uVar3 = iVar2 / 6 + 1;
    D_588f = (char)uVar3;
    if (D_5893_map_id == 0)
    {
        bVar4 = (*(iVar2 + D_1c90) & 8) == 0;
    }
    else if (D_5893_map_id < 0x80)
    {
        if (((D_5893_map_id == 0x12) && (D_57b4 == 0)) || (D_5893_map_id == 0x1d))
        {
            ULTIMA_1850_PrintString(/*0x4624*/ "Absorbed!\n");
            ULTIMA_2192_AudioPulse(0x2648, 1, 28000, 1000, 2);
            return; // sic
        }

        if (D_5893_map_id < 0x21)
        {
            bVar4 = (*(iVar2 + D_1c90) & 4) == 0;
        }
        else
        {
            bVar4 = (*(iVar2 + D_1c90) & 2) == 0;
        }
    }
    else
    {
        bVar4 = (*(iVar2 + D_1c90) & 1) == 0;
    }

    if (bVar4)
    {
        iVar7 = 0;
    }

    if (iVar7 == 0)
    {
        ULTIMA_1850_PrintString(/*0x462f*/ "Not here!\n");
        ULTIMA_43ae_AudioSweepTone(800, 2000, 1, 0x32);
        return; // sic
    }

    if (D_57f0[iVar2] == 0)
    {
        ULTIMA_1850_PrintString(/*0x463a*/ "None mixed!\n");
        return; // sic
    }

    D_57f0[iVar2]--;
    if (D_55a8_party[iVar1]._f < uVar3)
    {
        ULTIMA_1850_PrintString(/*0x4647*/ "M.P. too low!\n");
        iVar7 = 0;
        goto switchD_ce9a_default;
    }

    D_55a8_party[iVar1]._f -= uVar3;
    iVar7 = -1;
    if (D_55a8_party[iVar1]._16 < uVar3)
    {
        iVar7 = 0;
        goto switchD_ce9a_default;
    }

    switch (iVar2)
    {
    case 0:
        CAST2_08ea(100);
        CAST2_0000(1);
        break;
    case 1:
        CAST_0032(0x30);
        break;
    case 2:
        iVar7 = CAST_0114();
        break;
    case 3:
        iVar7 = CAST_01ae();
        break;
    case 4:
        iVar7 = CAST_01fa();
        break;
    case 5:
        iVar7 = CAST_0230();
        break;
    case 6:
        iVar7 = CAST_02d2();
        break;
    case 7:
        CAST_043e();
        break;
    case 8:
        CAST2_040a(CAST2_0306(), 0);
        break;
    case 9:
        CAST_04a4();
        break;
    case 10:
        iVar7 = CAST_04b0();
        break;
    case 0xb:
        iVar7 = CAST_05b4();
        break;
    case 0xc:
        CAST2_08ea(0xff);
        CAST2_0000(3);
        break;
    case 0xd:
        CAST_0032(0x31);
        break;
    case 0xe:
        iVar7 = CAST_004c(0);
        break;
    case 0xf:
        iVar7 = CAST_004c(1);
        break;
    case 0x10:
        iVar7 = CAST_004c(2);
        break;
    case 0x11:
        iVar7 = CAST_05dc();
        break;
    case 0x12:
        iVar7 = CAST2_07bc(1);
        break;
    case 0x13:
        CAST2_08f8(0x50, 0x14, 4);
        break;
    case 0x14:
        iVar7 = CAST_004c(3);
        break;
    case 0x15:
        if (D_5893_map_id == 40)
        {
            iVar7 = 0;
            break;
        }

        CAST2_0000(4);
        if (DUNGEON_1c6a(-1, 1) != 0)
        {
            DUNGEON_1d08();
        }
        break;
    case 0x16:
        if (D_5893_map_id == 40)
        {
            iVar7 = 0;
            break;
        }

        CAST2_0000(4);
        if (DUNGEON_1c6a(1, 1) != 0)
        {
            DUNGEON_1d08();
        }
        break;
    case 0x17:
        CAST_074c();
        break;
    case 0x18:
        iVar7 = CAST_07b4();
        break;
    case 0x19:
        iVar7 = CAST_0846();
        break;
    case 0x1a:
        iVar7 = CAST2_0768();
        if (iVar7 == -1)
            break;
        CAST2_0000(5);
        break;
    case 0x1b:
        iVar7 = CAST_08ac();
        break;
    case 0x1c:
        CAST_1f60(D_589e, 1, D_13b6);
        break;
    case 0x1d:
        CAST2_08f8(0x51, 0x1e, 5);
        break;
    case 0x1e:
        CAST_091e(iVar1);
        break;
    case 0x1f:
        CAST2_08f8(0x43, 0x14, 6);
        break;
    case 0x20:
        CAST2_08f8(0x4e, 10, 6);
        break;
    case 0x21:
        CAST2_0000(6);
        CAST2_046c();
        break;
    case 0x22:
        iVar7 = CAST_09a0();
        break;
    case 0x23:
        iVar7 = CAST_0a5c();
        break;
    case 0x24:
        iVar7 = CAST_0b28();
        break;
    case 0x25:
        CAST_0032(0x32);
        break;
    case 0x26:
        iVar7 = CAST_0b28();
        break;
    case 0x27: // view?
        CAST2_0000(7);
        if (D_5893_map_id < 0x21)
        {
            LOOKOBJ_10fc_ViewCmd(D_5896_map_x, D_5897_map_y);
        }
        else
        {
            DNGLOOK_06a8_ViewCmd();
        }
        break;
    case 0x28:
        CAST_1f60(D_589e, 2, D_13b4);
        break;
    case 0x29:
        CAST_0c98();
        break;
    case 0x2a:
        CAST2_05e0(CAST2_009e(), 0);
        ULTIMA_2900_UpdateVitalsDisplay();
        break;
    case 0x2b:
        iVar7 = CAST2_04c2(0);
        break;
    case 0x2c:
        CAST_1f60(D_589e, 4, D_13b2_frame_color);
        break;
    case 0x2d:
        CAST_1f60(D_589e, 3, D_13ae);
        break;
    case 0x2e:
        iVar7 = CAST_0cf0();
        if (iVar7 != 0)
        {
            uVar10 = 0;
        }
        break;
    case 0x2f:
        iVar7 = CAST_0d4c();
        break;
    }

switchD_ce9a_default:
    if (iVar7 == 1)
    {
        ULTIMA_1850_PrintString(/*0x4656*/ "Success!\n");
    }
    else if (iVar7 == 0)
    {
        ULTIMA_1850_PrintString(/*0x4660*/ "Failed!\n");
        ULTIMA_43ae_AudioSweepTone(800, 2000, 1, 0x32);
    }

    return uVar10;
}

// OK P1
int CAST_11de(int param_1)
{
    int local_6;
    int local_4 = 1;

    D_5820[param_1]--;
    ULTIMA_1850_PrintString(/*0x466a*/ "Scroll\n\n");
    switch (param_1)
    {
    case 0:
        CAST2_08ea(0xf0);
        ULTIMA_1850_PrintString(/*0x4673*/ "Light!\n");
        CAST2_0000(0);
        break;

    case 1:
        ULTIMA_1850_PrintString(/*0x467b*/ "Wind change!\n");
        local_6 = CAST2_0306();
        if (D_5893_map_id < 0x21)
        {
            CAST2_040a(local_6, 1);
            break;
        }
        local_4 = 0;
        break;

    case 2:
        ULTIMA_1850_PrintString(/*0x4689*/ "Protection!\n");
        CAST2_08f8(0x50, 100, 2);
        break;

    case 3:
        ULTIMA_1850_PrintString(/*0x4696*/ "Negate magic!\n");
        CAST2_08f8(0x4e, 0x14, 3);
        break;

    case 4:
        // 1278
        ULTIMA_1850_PrintString(/*0x46a5*/ "View!\n");
        if (D_5893_map_id > 0x7f)
        {
            ULTIMA_1850_PrintString(/*0x46ac*/ "Not here!\n");
            break;
        }
        else
        {
            // 1290
            CAST2_0000(4);
            if (D_5893_map_id < 0x21)
            {
                LOOKOBJ_10fc_ViewCmd(D_5896_map_x, D_5897_map_y);
                break;
            }
            DNGLOOK_06a8_ViewCmd();
            break;
        }

    case 5:
        // 12b4
        ULTIMA_1850_PrintString(/*0x46b7*/ "Summon Daemon!\n");
        if (D_5893_map_id > 0x7f)
        {
            local_4 = CAST2_04c2(1);
            break;
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x46c7*/ "Not here!\n");
            break;
        }

    case 6:
        // 12d2
        ULTIMA_1850_PrintString(/*0x46d2*/ "Resurrection!\n");
        if (D_5893_map_id < 0x80)
        {
            local_4 = CAST2_05e0(CAST2_009e(), 1);
            ULTIMA_2900_UpdateVitalsDisplay();
            break;
        }
        ULTIMA_1850_PrintString(/*0x46e1*/ "Not here!\n");
        break;

    case 7:
        if ((D_5893_map_id == 0x1d) || (D_5893_map_id == 0x28))
        {
            ULTIMA_1850_PrintString(/*0x46ec*/ "No effect!\n");
            ULTIMA_43ae_AudioSweepTone(800, 2000, 1, 0x32);
            break;
        }
        ULTIMA_1850_PrintString(/*0x46f8*/ "Negate time!\n");
        CAST2_08f8(0x54, 0x14, 7);
        break;
    }

    return local_4;
}

// NOT MATCHING
int CAST_135a(int param_1)
{
    byte bVar2;
    int iVar4;
    int uVar5;
    int local_a;
    int local_8;

    local_8 = 1;
    (D_5828)[param_1]--;
    ULTIMA_1850_PrintString(/*0x4706*/ "Potion\n");
    if (D_5893_map_id < 0x80)
    {
        local_a = CAST2_009e();
    }
    else
    {
        local_a = D_ba14[D_589e]._3;
    }

    if (local_a < 0)
    {
        return local_a;
    }

    CAST2_0000(param_1);
    iVar4 = ULTIMA_2092_RandomRange(0, 0xf);
    if (iVar4 == 0)
    {
        param_1 = 4;
    }
    else if (iVar4 == 1)
    {
        param_1 = ULTIMA_2092_RandomRange(0, 7);
    }

    switch (param_1)
    {
    case 0:
        if (D_55a8_party[local_a]._b != 'S')
        {
            return 0;
        }
        D_55a8_party[local_a]._b = 'G';

        if (D_5893_map_id < 0x80)
        {
            ULTIMA_2900_UpdateVitalsDisplay();
            return local_8;
        }

        uVar5 = (uint)D_589e;
        if (local_a != D_ba14[uVar5]._3)
        {
            return 0;
        }

        if ((D_ba14[uVar5]._2 & 0xe8) != 0x88)
        {
            return 0;
        }

        ULTIMA_6800(uVar5);
        return 1;

    case 1:
        iVar4 = CAST2_03c2(local_a);
        if (iVar4 == 0)
        {
            return 0;
        }

        ULTIMA_1850_PrintString(/*0x470e*/ "Healed!\n");
        ULTIMA_2900_UpdateVitalsDisplay();
        break;

    case 2:
        if (D_55a8_party[local_a]._b != 'P')
        {
            return 0;
        }
        D_55a8_party[local_a]._b = 'G';

        ULTIMA_1850_PrintString(/*0x4717*/ "Poison cured!\n");
        ULTIMA_2900_UpdateVitalsDisplay();
        break;

    case 3:
        if (D_55a8_party[local_a]._b != 'G')
        {
            return 0;
        }
        D_55a8_party[local_a]._b = 'P';

        ULTIMA_1850_PrintString(/*0x4726*/ "POISONED!\n");
        ULTIMA_2900_UpdateVitalsDisplay();
        break;

    case 4:
        if (D_55a8_party[local_a]._b != 'G')
        {
            return 0;
        }

        if (D_5893_map_id < 0x80)
        {
            D_55a8_party[local_a]._b = 'S';
        }
        else
        {
            ULTIMA_68ae(local_a);
        }

        ULTIMA_1850_PrintString(/*0x4731*/ "Slept!\n");
        ULTIMA_2900_UpdateVitalsDisplay();
        break;

    case 5:
        if (0x7f < D_5893_map_id)
        {
            ULTIMA_1850_PrintString(/*0x4739*/ "Poof!\n");
            bVar2 = D_ba14[(uint)D_589e]._4;
            D_5c5a[bVar2]._0_tile = D_5c5a[bVar2]._1 = 0x90;
            return 1;
        }

        ULTIMA_1850_PrintString(/*0x474c*/ "\nNo noticeable effect now!\n");
        break;

    case 6:
        if (0x7f < D_5893_map_id)
        {
            local_a = (uint)D_589e;
            D_ba14[local_a]._2 |= 0x10;
            bVar2 = D_ba14[local_a]._4;
            ULTIMA_1850_PrintString(/*0x4740*/ "Invisible!\n");
            D_5c5a[bVar2]._0_tile = D_5c5a[bVar2]._1 = 0x1d;
            return 1;
        }

        ULTIMA_1850_PrintString(/*0x474c*/ "\nNo noticeable effect now!\n");
        break;

    case 7:
        if (D_5893_map_id < 0x21)
        {
            CAST2_046c();
            return 1;
        }

        ULTIMA_1850_PrintString(/*0x474c*/ "\nNo noticeable effect now!\n");
        break;
    }

    return local_8;
}

// OK P1
void CAST_153c(int param_1)
{
    int local_4;

    local_4 = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
    ULTIMA_1850_PrintString(/*0x4768*/ "Moonstone ");
    if (D_5893_map_id < 0x21 && (local_4 == 0x2c || local_4 == 0x2d || (3 < local_4 && local_4 < 0xb)))
    {
        ULTIMA_1850_PrintString(/*0x4773*/ "buried!\n");
        D_5830[param_1] = D_5896_map_x;
        D_5838[param_1] = D_5897_map_y;
        D_5840[param_1] = D_5893_map_id;
        D_5848[param_1] = D_5895_map_level;
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x477c*/ "cannot be buried here!\n");
    }
}

// NOT MATCHING
void CAST_15b4(int param_1)
{
    int iVar1;

    ULTIMA_1850_PrintString(/*0x4794*/ "Gem Shard\n\nThou dost hold above thee the evil Shard of ");
    if (param_1 == 0)
    {
        ULTIMA_1850_PrintString(/*0x47cc*/ "Falsehood...");
    }
    else if (param_1 == 1)
    {
        ULTIMA_1850_PrintString(/*0x47d9*/ "Hatred...");
    }
    else if (param_1 == 2)
    {
        ULTIMA_1850_PrintString(/*0x47e3*/ "Cowardice...");
    }

    for (iVar1 = 2000; iVar1 < 25000; iVar1 += 0x32)
    {
        ULTIMA_2192_AudioPulse(0xa50, 1, 200, iVar1, 0);
    }

    for (iVar1 = 25000; iVar1 > 2000; iVar1 -= 0x32)
    {
        ULTIMA_2192_AudioPulse(0xa50, 1, 200, iVar1, 0);
    }

    if (D_4882[param_1] != D_5896_map_x || D_4886[param_1] != D_5897_map_y || D_488a[param_1] != D_5893_map_id ||
        D_488e[param_1] != D_5895_map_level)
    {
        ULTIMA_1850_PrintString(/*0x47f0*/ "\n\nNo effect!\n");
        ULTIMA_43ae_AudioSweepTone(800, 2000, 1, 0x32);
        return;
    }

    ULTIMA_3ae6(7);
    ULTIMA_1850_PrintString(/*0x47fe*/ "\n\n...and cast it into the Flame of ");
    if (param_1 == 0)
    {
        ULTIMA_1850_PrintString(/*0x4822*/ "Truth!\n");
    }
    else if (param_1 == 1)
    {
        ULTIMA_1850_PrintString(/*0x482a*/ "Love!\n");
    }
    else if (param_1 == 2)
    {
        ULTIMA_1850_PrintString(/*0x4831*/ "Courage!\n");
    }

    ULTIMA_3072();
    ULTIMA_3072();
    ULTIMA_3072();
    ULTIMA_3ae6(3);

    if (ULTIMA_368e_FindNpcTileAtPos(D_5896_map_x, D_5897_map_y - 1, D_5895_map_level) != 0xfc)
    {
        return;
    }

    if (param_1 != D_58cb)
    {
        return;
    }

    TOWN_00b0(TOWN_011e(D_5876));

    for (iVar1 = 0; iVar1 < 7; iVar1++)
    {
        ULTIMA_3522(D_5896_map_x, D_5897_map_y - 1);
    }

    D_58c8[param_1] = 0xff;
    D_57b6[param_1] = 0;

    D_5b5a[0x70] |= D_4892[param_1];

    ULTIMA_1850_PrintString(/*0x483b*/ "\nThe doom of the Shadowlord ");
    if (param_1 == 0)
    {
        ULTIMA_1850_PrintString(/*0x4858*/ "Faulinei");
    }
    else if (param_1 == 1)
    {
        ULTIMA_1850_PrintString(/*0x4861*/ "Astaroth");
    }
    else if (param_1 == 2)
    {
        ULTIMA_1850_PrintString(/*0x486a*/ "Nosfentor");
    }

    ULTIMA_1850_PrintString(/*0x4874*/ " is wrought!\n");
    ULTIMA_4368_AudioSomething();
}

// OK P1
bool CAST_1764(int param_1)
{
    if (param_1 == D_587a)
    {
        ULTIMA_1850_PrintString(/*0x4895*/ "Removed!\n");

        D_587a = D_588e = 0;
        D_a9fa = 1;

        return 0;
    }

    return 1;
}

// NOT MATCHING
void CAST_1792_UseCmd(void)
{
    int iVar1;
    byte* pbVar2;
    int iVar3;
    int local_18;
    int local_14;
    int local_8;

    local_14 = 1;
    ZSTATS_099a();

    iVar1 = ZSTATS_05a4(-1, 0x26, D_b9ee, 0xff);
    if (iVar1 == -1)
    {
        ULTIMA_1850_PrintString(/*0x489f*/ "No usable items!\n");
        return;
    }

    ULTIMA_1850_PrintString(/*0x48b1*/ "Item: ");
    ULTIMA_4efc();
    ULTIMA_1b94_SelectTextWindow(1);
    ULTIMA_4e50(/*0x48b8*/ "Items:");
    ZSTATS_045e(8);

    iVar1 = ZSTATS_0f2e(iVar1, 0xff, 0x55);
    ULTIMA_4daa();
    ULTIMA_4e20();
    ULTIMA_4f3c();
    ULTIMA_2900_UpdateVitalsDisplay();
    if (iVar1 < 0)
    {
        return;
    }

    if (iVar1 < 8)
    {
        local_14 = CAST_11de(iVar1);
    }
    else if (iVar1 < 0x10)
    {
        local_14 = CAST_135a(iVar1 - 8);
    }
    else if (iVar1 > 0x14 && iVar1 < 0x1d)
    {
        CAST_153c(iVar1 - 0x15);
    }
    else
    {
        switch (iVar1)
        {
        case 0x10:
            ULTIMA_1850_PrintString(/*0x48bf*/ "Carpet\n\n");
            if (D_5893_map_id < 0x21 &&
                *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y) != 0xc)
            {
                if (D_587c == 0x1c)
                {
                    ULTIMA_1850_PrintString(/*0x48c8*/ "Boarded!\n");
                    D_587c = ULTIMA_2092_RandomRange(0, 1) + 0x14;
                    D_57b0--;
                    break;
                }

                if ((D_587c & 0xf8) == 0x20)
                {
                    ULTIMA_1850_PrintString(/*0x48d2*/ "X-it ship first!\n");
                }
                else
                {
                    ULTIMA_1850_PrintString(/*0x48e4*/ "Only on foot!\n");
                }
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x48f3*/ "Not here!\n");
            }
            break;

        case 0x11:
            D_57b1--;
            ULTIMA_1850_PrintString(/*0x48fe*/ "Skull Key\n");
            if (D_5893_map_id < 0x21 || 0x7f < D_5893_map_id)
            {
                local_14 = CAST2_0768();
                if (local_14 != 0 && D_5893_map_id < 0x80)
                {
                    ULTIMA_3522(D_5876, D_5878);
                }
                break;
            }

            ULTIMA_1850_PrintString(/*0x4909*/ "Not here!\n");
            break;

        case 0x12:
            ULTIMA_1850_PrintString(/*0x4914*/ "Amulet\n\n");
            if (CAST_1764(0xe) == 0)
                break;

            ULTIMA_1850_PrintString(/*0x491d*/ "Wearing the Amulet");
            ULTIMA_1850_PrintString(/*0x4a84*/ " of Lord British...\n");
            CAST2_08f8(0xe, 0xff, 9);
            break;

        case 0x13:
            ULTIMA_1850_PrintString(/*0x4930*/ "Crown\n\n");
            if (CAST_1764(0x1c) == 0)
                break;

            ULTIMA_1850_PrintString(/*0x4938*/ "Thou dost don the Crown");
            ULTIMA_1850_PrintString(/*0x4a84*/ " of Lord British...\n");
            CAST2_08f8(0x1c, 0xff, 9);
            break;

        case 0x14:
            ULTIMA_1850_PrintString(/*0x4950*/ "Sceptre\n\n");
            ULTIMA_1850_PrintString(/*0x495a*/ "Wielding the Sceptre");
            ULTIMA_1850_PrintString(/*0x4a84*/ " of Lord British...\n");
            ULTIMA_2192_AudioPulse(0x1450, 1, 50000, 5000, 1);

            local_8 = 0;
            if (D_5893_map_id < 0x21 || D_5893_map_id > 0x28)
            {
                for (iVar1 = -1; iVar1 < 2; iVar1++)
                {
                    for (iVar3 = -1; iVar3 < 2; iVar3++)
                    {
                        pbVar2 = ULTIMA_4402_GetTileAddr(iVar1 + D_5896_map_x,
                                                                      iVar3 + D_5897_map_y);
                        if ((*pbVar2 & 0xf0) == 0x70)
                        {
                            *pbVar2 = 5;
                            ULTIMA_5910_UpdateFrame();
                            ULTIMA_223c_AudioWhiteNoise(10, 3000, 2000);
                            local_8++;
                        }
                    }
                }
            }

            if (local_8 != 0)
                break;

            iVar1 = CAST2_07bc(0);
            if (iVar1 == 1)
            {
                ULTIMA_1850_PrintString(/*0x496f*/ "Field dissolved!\n");
            }
            else if (iVar1 == 0)
            {
                ULTIMA_1850_PrintString(/*0x4981*/ "No effect!\n");
            }
            break;

        case 0x1d:
        case 0x1e:
        case 0x1f:
            CAST_15b4(iVar1 - 0x1d);
            break;

        case 0x20:
            ULTIMA_1850_PrintString(/*0x498d*/ "Spyglass\n\n");
            if (D_5893_map_id < 0x21 && D_5895_map_level < 0x80)
            {
                if (D_587f < 6 || 0x12 < D_587f)
                {
                    ULTIMA_1850_PrintString(/*0x4998*/ "Looking...\n");
                    LOOKOBJ_0366();
                    break;
                }

                ULTIMA_1850_PrintString(/*0x49a4*/ "No stars!\n");
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x49af*/ "Not here!\n");
            }
            break;

        case 0x21:
            ULTIMA_1850_PrintString(/*0x49ba*/ "Plans\n\n");
            if ((D_587c & 0xf8) == 0x20)
            {
                D_57bb |= 0x80;
                ULTIMA_1850_PrintString(/*0x49c2*/ "Ship rigged for double speed!\n");
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x49e1*/ "Only usable on shipboard!\n");
            }
            break;

        case 0x22:
            ULTIMA_1850_PrintString(/*0x49fc*/ "Sextant\n\n");
            if (D_5895_map_level < 0x80 && D_5893_map_id == 0)
            {
                if (D_587f < 6 || D_587f > 0x12)
                {
                    ULTIMA_1850_PrintString(/*0x4a26*/ "Position:");
                    CAST2_06ec();
                    break;
                }

                ULTIMA_1850_PrintString(/*0x4a16*/ "Only at night!\n");
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x4a06*/ "Only outdoors!\n");
            }
            break;

        case 0x23:
            ULTIMA_1850_PrintString(/*0x4a30*/ "Watch\n\nThe pocket watch reads ");
            local_18 = (uint)D_587f % 0xc;
            if (local_18 == 0)
            {
                local_18 = 0xc;
            }

            ULTIMA_1a3e_PrintNumber(local_18, 1, 0x20);
            ULTIMA_16ba_PrintChar(0x3a);
            ULTIMA_1a3e_PrintNumber(D_5881, 2, 0x30);
            if (D_587f < 0xc)
            {
                ULTIMA_1850_PrintString(/*0x4a55*/ " AM.\n");
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x4a4f*/ " PM.\n");
            }
            break;

        case 0x24:
            ULTIMA_1850_PrintString(/*0x4a5b*/ "Badge\n\n");
            if (CAST_1764(0x1d) != 0)
            {
                ULTIMA_1850_PrintString(/*0x4a63*/ "Badge worn!\n");
                D_587a = 0x1d;
                D_588e = 0xff;
                D_a9fa = 1;
            }
            break;

        case 0x25:
            ULTIMA_1850_PrintString(/*0x4a70*/ "Box\n\nHow?\n");
            break;
        }
    }

    if (local_14 == 0)
    {
        ULTIMA_1850_PrintString(/*0x4a7b*/ "Failed!\n");
        ULTIMA_43ae_AudioSweepTone(800, 2000, 1, 0x32);
    }
}

// OK P1
int CAST_1bb0(int param_1, int param_2, int param_3)
{
    if (param_1 < 8 || 0xb6 < param_1 || param_2 < 8 || 0xb6 < param_2)
    {
        D_5876 = D_5878 = -1;
        return 0;
    }
    else
    {
        ULTIMA_0a70_GRAP_2d_SetPenColor(param_3);
        ULTIMA_0c64_GRAP_30_Pset(param_1, param_2);
        ULTIMA_0c64_GRAP_30_Pset(param_1 + 1, param_2);
        ULTIMA_22e2_PcspkOn(ULTIMA_2092_RandomRange(100, 10000));

        if ((param_2 & 1) != 0)
        {
            ULTIMA_3fb4(param_1, param_2);
            if (D_5876 >= 0 && D_5878 >= 0)
            {
                return ULTIMA_3f6e(D_5876, D_5878);
            }

            return 0;
        }
        else
        {
            return 1;
        }
    }
}

// NOT MATCHING
int CAST_1c36(s16* param_1, s16* param_2, int param_3, int param_4, int param_5)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int local_114;
    int local_110;
    int aiStack_10c[21];
    int aiStack_b8[21];
    int aiStack_64[21];
    int local_10;
    int local_c;
    int local_8;

    iVar3 = D_ba14[param_4]._6 * 0x10;
    local_110 = iVar3 + 8;
    iVar1 = D_ba14[param_4]._7 * 0x10;
    local_114 = iVar1 + 8;

    switch (param_5)
    {
    case 2:
        local_110 = iVar3 + 0x18;
    case 1:
        local_114 = iVar1 + 0x10;
        break;
    case 3:
        local_110 = iVar3 + 0x10;
        break;
    case 4:
        local_110 = iVar3 + 0x10;
        local_114 = iVar1 + 0x18;
    }

    for (iVar1 = 0; iVar1 < 0x15; iVar1++)
    {
        aiStack_64[iVar1] = local_110;
        aiStack_b8[iVar1] = local_114;

        aiStack_10c[iVar1] = 0;
        D_a9d0[iVar1] = D_1cf0[iVar1];
    }

    local_8 = 0;
    iVar1 = 0;
    while (1)
    {
        if (0x14 < local_8)
        {
            ULTIMA_230e_PcspkOff();
            return iVar1;
        }

        local_8 = 0;
        for (iVar3 = 0; iVar3 < 0x15; iVar3++)
        {
            if (aiStack_10c[iVar3] == 0)
            {
                local_10 = ULTIMA_3aae(0xf);
                for (local_c = 0; local_c < local_10; local_c++)
                {
                    if (CAST_1bb0(aiStack_64[iVar3], aiStack_b8[iVar3], param_3 + 8) == 0)
                    {
                        aiStack_10c[iVar3] = 1;
                    }
                    else if (iVar1 < 0x3f && -1 < D_5876 && -1 < D_5878 && D_5876 < 0xb && D_5878 < 0xb &&
                             D_ab02[D_5878 * 0x20 + D_5876] == 0)
                    {
                        iVar1++;
                        param_1[iVar1] = D_5876;
                        param_2[iVar1] = D_5878;
                        D_ab02[D_5876 + D_5878 * 0x20] = 0xff;
                    }

                    if (aiStack_10c[iVar3] == 0)
                    {
                        D_a9d0[iVar3] -= 10;

                        switch (param_5)
                        {
                        case 1:
                            aiStack_64[iVar3]--;
                            break;
                        case 2:
                            aiStack_64[iVar3]++;
                            break;
                        case 3:
                            aiStack_b8[iVar3]--;
                            break;
                        case 4:
                            aiStack_b8[iVar3]++;
                        }

                        if (D_a9d0[iVar3] < 1)
                        {
                            if (iVar3 < 10)
                            {
                                iVar2 = -1;
                            }
                            else
                            {
                                iVar2 = 1;
                            }

                            switch (param_5)
                            {
                            case 1:
                                aiStack_b8[iVar3] -= iVar2;
                                break;
                            case 2:
                                aiStack_b8[iVar3] += iVar2;
                                break;
                            case 3:
                                aiStack_64[iVar3] += iVar2;
                                break;
                            case 4:
                                aiStack_64[iVar3] -= iVar2;
                            }

                            D_a9d0[iVar3] += D_1cf0[iVar3];
                        }
                    }

                    if (aiStack_10c[iVar3] != 0)
                        break;
                }
            }
            else
            {
                local_8++;
            }
        }
    }
}

// NOT MATCHING
void CAST_1f60(int param_1, int param_2, int param_3)
{
    byte bVar1;
    int uVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    s16 local_214;
    int local_210;
    int local_20c;
    s16 local_208[64];
    s16 local_108[64];
    int local_8;

    local_20c = 1;
    uVar2 = D_ba14[param_1]._3;
#if !defined(TARGET_DOS16)
    local_8 = CAST2_0306();
#else
    local_8 = CAST2_0306(param_1); // NOTE: original code error?
#endif
    if (local_8 != 0)
    {
        if (param_2 == 1)
        {
            local_210 = 16000;
        }
        else if (param_2 == 2)
        {
            local_210 = 0x4b00;
        }
        else
        {
            local_210 = 0x5140;
        }

        ULTIMA_223c_AudioWhiteNoise(800, local_210, 700);

        iVar3 = CAST_1c36(local_108, local_208, param_3, param_1, local_8);
        local_8 = iVar3 + 1;

        for (local_20c = 1; local_20c < local_8; local_20c++)
        {
            for (iVar3 = 0x1f; -1 < iVar3; iVar3 = iVar3 + -1)
            {
                iVar5 = iVar3 * 8;
                if (D_ba14[iVar5]._6 == local_108[local_20c] &&
                    D_ba14[iVar5]._7 == local_208[local_20c] &&
                    (D_ba14[iVar5]._5 & 0x80) == 0 && (bVar1 = D_ba14[iVar5]._2, (bVar1 & 0x20) == 0 && bVar1 != 0))
                {
                    D_ba14[iVar5]._5 |= 0x80;
                    switch (param_2)
                    {
                    case 1:
                        iVar5 = COMSUBS_0000(param_1, iVar3, 0);
                        if (iVar5 == 0 && (iVar5 = CAST_0000(iVar3), iVar5 == 0))
                        {
                            ULTIMA_3564(iVar3);
                            ULTIMA_68ae(iVar3);
                            COMSUBS_0312(iVar3, param_1);
                        }
                        break;

                    case 2:
                        iVar5 = ULTIMA_3abe();
                        iVar4 = COMBAT_13e2(iVar3, -2);
                        if (iVar4 <= iVar5)
                        {
                            ULTIMA_3564(iVar3);
                            COMBAT_18ba(iVar3, param_1);
                            COMSUBS_0312(iVar3, param_1);
                        }
                        break;

                    case 3:
                        ULTIMA_3564(iVar3);
                        local_214 = D_55a8_party[uVar2]._14;

                        iVar5 = COMBAT_1574(iVar3, ULTIMA_3aae(0x1e));
                        ULTIMA_3f14(&local_214, iVar5, 9999);
                        D_55a8_party[uVar2]._14 = local_214;
                        COMSUBS_0312(iVar3, param_1);
                        break;

                    case 4:
                        iVar5 = COMSUBS_0000(param_1, iVar3, 0);
                        if (iVar5 != 0 || (iVar5 = CAST_0000(iVar3), iVar5 != 0))
                            break;

                        ULTIMA_3564(iVar3);
                        local_214 = D_55a8_party[uVar2]._14;

                        iVar5 = COMBAT_1574(iVar3, 99);
                        ULTIMA_3f14(&local_214, iVar5, 9999);
                        D_55a8_party[uVar2]._14 = local_214;
                        COMSUBS_0312(iVar3, param_1);
                        break;
                    }
                }
            }
        }

        for (iVar3 = 0x1f; iVar3 >= 0; iVar3--)
        {
            D_ba14[iVar3]._5 &= 0x7f;
        }
    }
}
