#include "common/common.h"
#include "savegame.h"
#include "funcs.h"
#include "vars.h"
#include "macros.h"
#include "tiles.h"

#include "cast2.h"
#include "combat.h"

// OK P1
void CAST2_0000(int param_1)
{
    if (param_1 < 9)
    {
        ULTIMA_223c_AudioWhiteNoise(800, param_1 * 0x640 + 8000, 700);
        ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
        ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);
        ULTIMA_2192_AudioPulse(D_4af6[param_1], 1, param_1 * 4000 + 10000, D_4b08[param_1], D_4b2c[param_1]);
        ULTIMA_2192_AudioPulse(D_4af6[param_1], 1, param_1 * 4000 + 10000, D_4b1a[param_1], -D_4b2c[param_1]);
        ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);
    }
    else
    {
        ULTIMA_2192_AudioPulse(0x1180, 1, 65000, 300, 1);
    }
}

// OK P1
int CAST2_009e(void)
{
    int local_4;

    ULTIMA_1850_PrintString(/*0x94f4*/ "On who: ");

    local_4 = ULTIMA_2e8e();
    if (local_4 < 0)
    {
        ULTIMA_1850_PrintString(/*0x94fe*/ "None!");
    }
    else
    {
        ULTIMA_1850_PrintString(D_55a8_party[local_4].name);
    }

    if (ULTIMA_1f12_GetCurrentTextX() != 0)
    {
        ULTIMA_16ba_PrintChar(10);
    }

    return local_4;
}

// CHECKED
// select spell
int CAST2_00de(void)
{
    int local_a;
    byte local_10[4];
    byte local_8[4];
    byte local_16;
    int local_18;
    int local_14;
    int local_12;
    int local_1a;
    int local_c;
    int local_4;
    int local_1c;

    local_a = 0; // di
    local_4 = -1;
    local_c = 0;

    while (local_c == 0)
    {
        local_16 = ULTIMA_2032_ToUpper(ULTIMA_266c_GetChar());
        if (local_16 == 0x4a || local_16 == 0x4f)
        {}
        else if (local_16 >= 0x41 && local_16 <= 0x5a)
        {
            if (local_a < 4)
            {
                local_10[local_a] = local_16;

                if (ULTIMA_1f12_GetCurrentTextX() + ULTIMA_216c_strlen(D_1bfc[local_16 - 'A']) > 0xd)
                {
                    ULTIMA_16ba_PrintChar(10);
                }

                local_8[local_a] = ULTIMA_1f12_GetCurrentTextX();
                ULTIMA_1850_PrintString(D_1bfc[local_16 - 'A']);
                ULTIMA_16ba_PrintChar(0x20);
                local_a++;
            }
        }
        else
        {
            switch (local_16)
            {
            case U5_KEY_BACKSPACE:
                // 0174
                if (local_a != 0) // di
                {
                    local_a--;
                    if (ULTIMA_1f12_GetCurrentTextX() == 0)
                    {
                        // NOTE: FMT
                        //ULTIMA_16ba_PrintChar(0x20);
                        ULTIMA_1bf2_SetTextPosition(local_8[local_a], ULTIMA_1cee_GetCurrentTextY() - 1);
                    }
                    else
                    {
                        ULTIMA_1bf2_SetTextPosition(local_8[local_a], ULTIMA_1cee_GetCurrentTextY());
                    }

                    local_1c = ULTIMA_216c_strlen(D_1bfc[local_10[local_a] - 'A']);

                    for (local_12 = 0; local_12 < local_1c; local_12++)
                    {
                        ULTIMA_16ba_PrintChar(0x20);
                    }

                    ULTIMA_1bf2_SetTextPosition(local_8[local_a], ULTIMA_1cee_GetCurrentTextY());
                }
                break;

            case U5_KEY_ESC:
                // 01d8/e3b8
                local_a = 0;
                local_c = 1;
                break;

            case U5_KEY_ENTER:
            case U5_KEY_SPACE:
                // 01da/e3ba
                local_c = 1;
                break;
            }
        }
    }

    // e3c2
    // di--;

    // e3c6
    // bubble sort
    do
    {
        local_c = 1;
        for (local_12 = 0; local_12 < local_a - 1; local_12++)
        {
            if (local_10[local_12 + 1] < local_10[local_12])
            {
                local_16 = local_10[local_12];
                local_10[local_12] = local_10[local_12 + 1];
                local_10[local_12 + 1] = local_16;
                local_c = 0;
            }
        }
    } while (local_c == 0);

    // e412
    for (local_12 = 0; local_12 < 0x30; local_12++)
    {
        // e42e
        local_1a = 1;
        local_18 = 0;

        for (local_14 = 0; local_14 < local_a; local_14++)
        {
            if (D_1c30[local_12][local_18] != local_10[local_14])
            {
                local_1a = 0;
                break;
            }

            while (local_14 < local_a - 1 && local_10[local_14] == local_10[local_14 + 1])
            {
                local_14++;
            }

            local_18++;
        }

        // e460
        if (local_1a != 0 && D_1c30[local_12][local_18] != '\0')
        {
            local_1a = 0;
        }

        if (local_1a != 0)
        {
            local_4 = local_12;
            break;
        }
    }

    // e484
    if (local_a == 0)
    {
        local_4 = -1;
        // -> e4dc
    }
    else
    {
        ULTIMA_16ba_PrintChar(10);
        if (local_4 < 0)
        {
            local_4 = -2;
        }
    }

    // e4dc
    return local_4;
}

// OK P1
int CAST2_0306(void)
{
    bool local_4;
    int local_6;

    if (D_5893_map_id > 0x7f)
    {
        D_5876 = D_ba14[D_589e].x;
        D_5878 = D_ba14[D_589e].y;
    }
    else
    {
        D_5876 = D_5896_map_x;
        D_5878 = D_5897_map_y;
    }

    // 033e
    ULTIMA_1850_PrintString(/*0x9504*/ "Direction-");
    local_4 = 0;

    do
    {
        local_6 = ULTIMA_266c_GetChar();
        local_4 = 1;
        switch (local_6)
        {
        case U5_KEY_UP:
            ULTIMA_1850_PrintString(/*0x9510*/ "North\n");
            D_5878--;
            break;
        case U5_KEY_RIGHT:
            ULTIMA_1850_PrintString(/*0x9518*/ "East\n");
            D_5876++;
            break;
        case U5_KEY_DOWN:
            ULTIMA_1850_PrintString(/*0x951e*/ "South\n");
            D_5878++;
            break;
        case U5_KEY_LEFT:
            ULTIMA_1850_PrintString(/*0x9526*/ "West\n");
            D_5876--;
            break;
        case U5_KEY_SPACE:
            ULTIMA_1850_PrintString(/*0x952c*/ "Pass\n");
            local_6 = 0;
            break;
        default:
            local_4 = 0;
            break;
        }
    } while (!local_4);

    return local_6;
}

// OK P1
int CAST2_03c2(int param_1)
{
    int local_4;

    if (D_55a8_party[param_1].status == STATUS_DEAD)
    {
        local_4 = 0;
    }
    else
    {
        ULTIMA_3f14(&D_55a8_party[param_1].hp, ULTIMA_3abe(), D_55a8_party[param_1].maxHp);

        local_4 = 1;
        D_a9fa = 1;
    }

    return local_4;
}

// OK P1
void CAST2_040a(int param_1, int param_2)
{
    if (param_1 != 0 || param_2 != 0)
    {
        if (param_2 != 0)
        {
            CAST2_0000(1);
        }
        else
        {
            CAST2_0000(2);
        }

        switch (param_1)
        {
        case DIR_UP:
            // 0448
            ULTIMA_2e96_SetWindDirection(1);
            break;

        case DIR_DOWN:
            // 0452
            ULTIMA_2e96_SetWindDirection(2);
            break;

        case DIR_RIGHT:
            // 0458
            ULTIMA_2e96_SetWindDirection(3);
            break;

        case DIR_LEFT:
            // 045e
            ULTIMA_2e96_SetWindDirection(4);
            break;

        case 0:
            // 0464
            ULTIMA_2e96_SetWindDirection(0);
            break;
        }
    }
}

// OK P1
void CAST2_046c(void)
{
    int local_4;

    ULTIMA_5d0a(-1, D_5896_map_x - D_589b, D_5897_map_y - D_589c, 0x20);

    for (local_4 = 0; local_4 < 0x14; local_4++)
    {
        if (D_587a != 'T')
        {
            ULTIMA_4552_AnimateActors();
        }

        ULTIMA_5394();
        ULTIMA_56ac_DrawMap();
        ULTIMA_20fa_WaitTicks(1);
    }

    ULTIMA_5910_UpdateFrame();
}

// CHECKED (code structure)
int CAST2_04c2(int param_1)
{
    int local_a;
    int local_8;
    ActorFmt* local_6;
    int local_4;

    local_a = 0;

    if (param_1 != 0)
    {
        CAST2_0000(5);
    }
    else
    {
        CAST2_0000(8);
    }

    // 04e1
    for (local_8 = 0; local_8 < 8; local_8++)
    {
        if (COMBAT_120e() == 0 || COMBAT_0000(TILE_ACTOR_D8, D_5876, D_5878) == 0 || *ULTIMA_4402_GetTileAddr(D_5876, D_5878) == 0xff)
        {
            continue;
        }

        // 0524
        local_4 = ULTIMA_6506(0x26, 0, D_5876, D_5878, D_5895_map_level);
        if (local_4 >= 0)
        {
            // 054c
            ULTIMA_2192_AudioPulse(0xac8, 1, 12000, 500, 5);
            local_6 = &D_5c5a[D_ba14[local_4].actorIdx];
            local_6->_0_tile = local_6->_1_animTile = TILE_ACTOR_CIRCLE;
            ULTIMA_1068(0x1d8, D_5876, D_5878);
            local_6->_0_tile = local_6->_1_animTile = TILE_ACTOR_D8;

            if (param_1 == 0 && ULTIMA_3abe() >= COMBAT_13e2(D_589e, -1))
            {
                // 05b2
                ULTIMA_1850_PrintString(/*0x9532*/ "Oops...\n");
                local_a = -1;
            }
            else
            {
                // 05c0
                D_ba14[local_4].flags |= 1;
                local_a = 1;
            }
        }

        // 0518
        break;
    }

    return local_a;
}

// CHECKED
// resurrect
int CAST2_05e0(int param_1, int param_2)
{
    int local_6;
    short local_a;

    int local_8;
    S_55a8* local_4;

    if (param_1 < 0)
    {
        local_8 = -1;
    }
    else if (D_55a8_party[param_1].status != STATUS_DEAD)
    {
        if (param_2 != 0)
        {
            ULTIMA_1850_PrintString(/*0x953c*/ "Not dead!\n");
        }

        local_8 = 0;
    }
    else
    {
        // 061a
        local_4 = &D_55a8_party[param_1];

        local_4->status = STATUS_GOOD;
        local_4->hp = 1;

        switch (local_4->cls)
        {
        case CLASS_AVATAR:
        case CLASS_MAGE:
            local_4->mag = local_4->intel;
            break;

        case CLASS_BARD:
            local_4->mag = local_4->intel >> 1;
            break;
        }

        if (D_5888 < 0x62)
        {
            // NOT MATCHING (pointer)
            local_4->exp = local_4->exp * (s32)D_5888 / 100;
        }

        local_a = 1;
        for (local_6 = local_4->exp / 100; 0 < local_6; local_6 >>= 1)
        {
            local_a++;
        }

        local_4->level = local_a;
        local_4->maxHp = local_a * 0x1e;

        if (param_2 == 1)
        {
            CAST2_0000(6);
        }
        else if (param_2 == 0)
        {
            CAST2_0000(8);
        }

        local_8 = 1;
        D_a9fa = 1;
    }

    return local_8;
}

// OK P1
void CAST2_06ec(void)
{
    ULTIMA_1c9e_SelectCharset(1);
    ULTIMA_16ba_PrintChar(10);
    ULTIMA_16ba_PrintChar(((D_5897_map_y & 0xf0) >> 4) + 0x41);
    ULTIMA_16ba_PrintChar(0x27);
    ULTIMA_16ba_PrintChar((D_5897_map_y & 0xf) + 0x41);
    ULTIMA_1850_PrintString(/*0x9548*/ "\", ");
    ULTIMA_16ba_PrintChar(((D_5896_map_x & 0xf0) >> 4) + 0x41);
    ULTIMA_16ba_PrintChar(0x27);
    ULTIMA_16ba_PrintChar((D_5896_map_x & 0xf) + 0x41);
    ULTIMA_16ba_PrintChar(0x22);
    ULTIMA_1c9e_SelectCharset(0);
    ULTIMA_16ba_PrintChar(10);
}

// CHECKED (07b2 block)
int CAST2_0768(void)
{
    int local_6;
    byte* local_4;

    if (CAST2_0306() == 0)
    {
        return -1;
    }

    local_4 = ULTIMA_4402_GetTileAddr(D_5876, D_5878);
    local_6 = 0;

    switch (*local_4)
    {
    case TILE_MAP_97:
        // 07a0
        *local_4 = TILE_MAP_DOOR_B8;
        D_24e6 |= 2;
        local_6 = 1;
        break;

    case TILE_MAP_98:
        // 07b2: not matching
        *local_4 = TILE_MAP_DOOR_BA;
        D_24e6 |= 2;
        local_6 = 1;
        break;
    }

    return local_6;
}

// CHECKED (085d nop)
int CAST2_07bc(int param_1)
{
    int local_6;
    byte* local_4;
    int local_8;
    int local_a;
    int local_c;

    if (D_5893_map_id < 0x80)
    {
        if (param_1 != 0)
        {
            CAST2_0000(4);
        }

        local_a = D_24d6[D_6603];
        local_c = D_24de[D_6603];

        local_4 = &GetDungeonMap(D_5896_map_x, D_5897_map_y, D_5895_map_level);
        if ((*local_4 & 0xf0) != 0x80)
        {
            local_4 = &GetDungeonMap((D_5896_map_x + local_a) & 7, (D_5897_map_y + local_c) & 7, D_5895_map_level);
        }

        if ((*local_4 & 0xf0) == 0x80)
        {
            *local_4 &= 8;
            ULTIMA_1850_PrintString(/*0x954c*/ "Field destroyed!\n");
            local_8 = -1;
            // NOT MATCHING: 085d: nop (not aligned?)
        }
        else
        {
            local_8 = 0;
        }
    }
    else
    {
        // 0866
        if (CAST2_0306() == 0)
        {
            return -1;
        }
        
        if (param_1 != 0)
        {
            CAST2_0000(4);
        }

        local_8 = 0;
        for (local_6 = 0; local_6 < 0x20; local_6++)
        {
            if ((D_5c5a[local_6]._0_tile & 0xfc) == TILE_ACTOR_E8 && D_5876 == D_5c5a[local_6]._2_x &&
                D_5878 == D_5c5a[local_6]._3_y)
            {
                local_8 = 1;
                ULTIMA_3a74(0, 0, 0, 0, 0, 0, local_6);
                break;
            }
        }
    }
    
    return local_8;
}

// OK P1
void CAST2_08ea(int param_1) { D_58a6 = param_1; }

// OK P1
void CAST2_08f8(int param_1, int param_2, int param_3)
{
    D_587a = param_1;
    D_588e = param_2;

    CAST2_0000(param_3);

    ULTIMA_2900_UpdateVitalsDisplay();
}

// OK P1
static void CAST2_0914(int param_1)
{
    int local_6;
    int local_4;

    local_4 = D_4b96[param_1 - 1];
    if (param_1 > 0)
    {
        for (local_6 = 0; local_6 != param_1; local_6++)
        {
            ULTIMA_3a74(TILE_ACTOR_3, TILE_ACTOR_3, D_4b9e[local_4], D_4bc2[local_4], D_5895_map_level, 0, local_6 + 1);
            local_4++;
        }
    }
}

// CHECKED (code structure)
static void CAST2_0966(void)
{
    bool local_6;
    int local_8;
    int local_4;
    int local_a;
    bool local_c;

    local_c = 1;
    local_6 = 0;
    for (local_a = 0; local_a < 8; local_a++) // 0a2e -> 0a37 -> 0982, 0994
    {
        // 0982
        if (D_5896_map_x == D_1f6e[local_a] && D_5897_map_y == D_1f76[local_a])
            break; // -> 0a2e ??
    }

    // 0994
    if (local_a == 8)
    {
        local_a = 6;
    }

    // 09a1
    D_5c5a[0]._0_tile = D_5c5a[0]._1_animTile = TILE_ACTOR_BEGGAR;
    ULTIMA_5910_UpdateFrame();
    ULTIMA_1850_PrintString((char*)&D_b21e[0x36d]);
    ULTIMA_3ae6(10);
    ULTIMA_1850_PrintString((char*)&D_b21e[0x398]);

    ULTIMA_3b1c_GetString(D_bd08, 0xc);

    if (D_bd08[0] == '\0')
    {
        // -> 0d1d
        return;
    }

    // 09d6
    if (ULTIMA_6f1e(D_4b3e[local_a], D_bd08) == -1)
    {
        local_c = 0;
    }

    // 09ee
    ULTIMA_3ae6(6);
    ULTIMA_16ba_PrintChar(10);

    for (local_8 = 0; local_8 < 3; local_8++)
    {
        // 0a0c
        ULTIMA_1850_PrintString(/*0x958e*/ "\nMantra:");
        ULTIMA_3b1c_GetString(D_bd08, 0xc);
        if (D_bd08[0] == '\0')
        {
            return;
        }

        // 0a3a
        if (ULTIMA_6f1e(D_1f5e[local_a], D_bd08) == -1)
        {
            local_c = 0;
        }

        // 0a4b
        ULTIMA_3ae6(0xc);
    }

    // NOTE: FMT addition
    //ULTIMA_16ba_PrintChar(10);

    // 0a5e
    if (!local_c)
    {
        ULTIMA_1850_PrintString((char*)&D_b21e[0x3c0]);
    }
    else
    {
        // 0a6c
        if (((byte)D_58ce & (1 << local_a)) == 0)
        {
            // TODO: 58cc, 58ce: u8?
            *((byte*)&D_58cc) |= (1 << local_a);
            ULTIMA_1850_PrintString((char*)&D_b21e[0x3e1]);

            D_5c5a[0]._0_tile = D_5c5a[0]._1_animTile = TILE_ACTOR_AVATAR;

            ULTIMA_266c_GetChar();
            ULTIMA_1850_PrintString((char*)&D_b21e[0x40e]);
            ULTIMA_1850_PrintString((char*)&D_b21e[D_4b5e[local_a]]);
            ULTIMA_1850_PrintString(/*0x9598*/ "\"\n");
            ULTIMA_266c_GetChar();
            ULTIMA_1850_PrintString((char*)&D_b21e[0x44b]);

            // 0ac6 (NOT MATCHING)
            for (local_8 = 0; local_8 < 7; local_8++)
            {
                ULTIMA_2192_AudioPulse(D_4be6[local_8], 1, D_4bf4[local_8], D_4c02[local_8], D_4c10[local_8]);
            }
        }
        // 0b08
        else if (((byte)D_58cc & (1 << local_a)) == 0)
        {
            // 0b1d -> 0b5f

            // NOT MATCHING: code structure
            while (!local_6) // 0b5f
            {
                // 0b63
                ULTIMA_1850_PrintString((char*)&D_b21e[0x474]);

                // 0b6a
                do
                {
                    local_4 = ULTIMA_266c_GetChar();
                } while ((unsigned)local_4 < 0x30 || (unsigned)local_4 > 0x39);

                // 0b26 (OK)
                ULTIMA_16ba_PrintChar(local_4);
                local_4 -= 0x30;
                if (local_4 == 0)
                {
                    // 0b2f
                    ULTIMA_1850_PrintString(/*0x959c*/ " gp\n");
                    return; // -> 0d1d
                }

                // 0b40 (OK)
                ULTIMA_1850_PrintString(/*0x95a2*/ "00 gp\n\n");
                if ((int)D_57aa < local_4 * 100)
                {
                    ULTIMA_1850_PrintString((char*)&D_b21e[0x49b]);
                }
                else
                {
                    // 0b5c (OK)
                    local_6 = 1;
                }

                // 0b5f
            }

            // 0b82 (OK)
            D_57aa -= local_4 * 100;
            ULTIMA_2900_UpdateVitalsDisplay();
            D_5888 += local_4;
            if (D_5888 > 99)
            {
                D_5888 = 99;
            }

            // 0ba1 (OK)
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1850_PrintString(/*0x95aa*/ "ALAKAZAM");
            ULTIMA_1c9e_SelectCharset(0);
            ULTIMA_1850_PrintString(/*0x95b4*/ "!\n");
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
            ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);

            // 0bd3 (OK)
            for (local_8 = 2000; local_8 < 25000; local_8 += 0x32)
            {
                ULTIMA_2192_AudioPulse(0xa8c, 1, 200, local_8, 0);
            }

            // 0bf5 (OK)
            for (local_8 = 25000; local_8 > 2000; local_8 -= 0x32)
            {
                ULTIMA_2192_AudioPulse(0xa8c, 1, 200, local_8, 0);
            }
        }
        else
        {
            // 0c18 (OK)
            *((byte*)&D_58cc) &= (1 << local_a & (byte)D_58cc) ^ 0xff;
            ULTIMA_1850_PrintString((char*)&D_b21e[0x4b9]);
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
            ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);

            // 0c47 (OK)
            for (local_8 = 2000; local_8 < 25000; local_8 += 0x32)
            {
                ULTIMA_2192_AudioPulse(0xc1c, 1, 0x96, local_8, 0);
            }

            // 0c69 (OK)
            for (local_8 = 25000; local_8 > 2000; local_8 -= 0x32)
            {
                ULTIMA_2192_AudioPulse(0xc1c, 1, 0x96, local_8, 0);
            }

            ULTIMA_3072();
            D_5888 += 3;
            if (D_5888 > 99)
            {
                D_5888 = 99;
            }

            // 0c9c (OK)
            if (D_4b7e[local_a] != 0)
            {
                D_55a8_party[0].str++;
                if (D_55a8_party[0].str > 0x1e)
                {
                    D_55a8_party[0].str = 0x1e;
                }

                ULTIMA_1850_PrintString(/*0x95b8*/ "Strength +1\n");
            }

            if (D_4b86[local_a] != 0)
            {
                D_55a8_party[0].dex++;
                if (D_55a8_party[0].dex > 0x1e)
                {
                    D_55a8_party[0].dex = 0x1e;
                }

                ULTIMA_1850_PrintString(/*0x95c6*/ "Dexterity +1\n");
            }

            if (D_4b8e[local_a] != 0)
            {
                D_55a8_party[0].intel++;
                if (D_55a8_party[0].intel > 0x1e)
                {
                    D_55a8_party[0].intel = 0x1e;
                }

                ULTIMA_1850_PrintString(/*0x95d4*/ "Intelligence +1\n");
            }

            if (local_a == 7)
            {
                D_5888 += 3;
                if (D_5888 > 99)
                {
                    D_5888 = 99;
                }
            }
        }

        // 0d16
        ULTIMA_3ae6(10);
    }
}

// OK P1
static void CAST2_0d24(void)
{
    int local_4;

    ULTIMA_266c_GetChar();
    ULTIMA_1850_PrintString((char*)&D_b21e[0x4e5]);
    ULTIMA_266c_GetChar();
    ULTIMA_1850_PrintString((char*)&D_b21e[0x515]);
    ULTIMA_266c_GetChar();

    for (local_4 = 0; local_4 < 8; local_4++)
    {
        if (((byte)D_58cc & (1 << local_4)) != 0)
            break;
    }

    if (local_4 == 8)
    {
        ULTIMA_1850_PrintString((char*)&D_b21e[0x53e]);
    }
    else
    {
        *((byte*)&D_58ce) |= 1 << local_4;

        ULTIMA_16ba_PrintChar(0x22);
        ULTIMA_1850_PrintString((char*)&D_b21e[D_4b6e[local_4]]);
        ULTIMA_1850_PrintString(/*0x95e6*/ "\"\n\n");
        ULTIMA_266c_GetChar();

        if ((byte)D_58ce == 0xff)
        {
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13ae);
            ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);
            ULTIMA_3072();
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
            ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);
            ULTIMA_3072();
            ULTIMA_0a70_GRAP_2d_SetPenColor(D_13ae);
            ULTIMA_0b86_GRAP_XorFillRect(8, 8, 0xb7, 0xb7);
            ULTIMA_3072();
            ULTIMA_1850_PrintString((char*)&D_b21e[0x555]);
            ULTIMA_266c_GetChar();
            ULTIMA_1850_PrintString(/*0x95ea*/ "Thou dost read:\n\n");
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1850_PrintString((char*)&D_b21e[0x57f]);
            ULTIMA_1c9e_SelectCharset(0);
            ULTIMA_266c_GetChar();
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1850_PrintString((char*)&D_b21e[0x5d1]);
            ULTIMA_1c9e_SelectCharset(0);
            ULTIMA_266c_GetChar();
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1850_PrintString((char*)&D_b21e[0x60c]);
            ULTIMA_1c9e_SelectCharset(0);
            ULTIMA_266c_GetChar();
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1850_PrintString((char*)&D_b21e[0x680]);
            ULTIMA_1c9e_SelectCharset(0);
            ULTIMA_266c_GetChar();
        }
    }
}

// OK P1
static void CAST2_0e64(void)
{
    ULTIMA_3ae6(1);
    ULTIMA_433e_AudioWalkStep();
    ULTIMA_3ae6(4);
}

// CHECKED (loop)
void CAST2_0e76(void)
{
    int local_c;
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    local_8 = 0;

    local_6 = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);
    D_24e6 = 1;
    D_bd15 = D_5893_map_id;
    D_5893_map_id = 0xff;
    D_589e = 0xff;

    // 0eb3: NOT MATCHING
    for (local_a = 0; local_a < 0x20; local_a++)
    {
        D_a9fc[local_a] = D_5c5a[local_a];
        D_5c5a[local_a]._0_tile = 0;
    }

    if (local_6 != TILE_MAP_CODEX)
    {
        ULTIMA_256e_ReadFileFromDisk(/*0x95fc*/ "MISCMAPS.DAT", D_ac64, 0xb0, 0xb0);
    }
    else
    {
        ULTIMA_256e_ReadFileFromDisk(/*0x960a*/ "MISCMAPS.DAT", D_ac64, 0xb0, 0x160);
    }

    ULTIMA_256e_ReadFileFromDisk(/*0x9618*/ "MISCMSG.DAT", D_b21e, 2000, 0x3ab);

    // 0f0c
    for (local_a = 0; local_a < 0xb; local_a++)
    {
        for (local_c = 0; local_c < 0xb; local_c++)
        {
            GetCombatMap(local_c, local_a) = D_ac64[local_a * 0x10 + local_c];
        }
    }

    ULTIMA_5910_UpdateFrame();

    // 0f44 (NOT MATCHING)
    for (local_a = 1; local_a < 0x10; local_a++)
    {
        if (D_55a8_party[local_a].mapId == 0x7f)
        {
            local_8++;
        }
    }

    if (local_8 > 0)
    {
        CAST2_0914(local_8);
    }

    // 0f69
    if (local_6 != TILE_MAP_CODEX)
    {
        ULTIMA_1850_PrintString((char*)&D_b21e[0x6ae]);
    }
    else
    {
        ULTIMA_1850_PrintString((char*)&D_b21e[0x6db]);
    }

    // 0f7b (OK)
    for (local_a = 0; local_a < 4; local_a++)
    {
        CAST2_0e64();
    }

    D_5c5a[0]._0_tile = D_5c5a[0]._1_animTile = TILE_ACTOR_AVATAR;
    D_5c5a[0]._2_x = 5;
    D_5c5a[0]._3_y = 10;
    D_5c5a[0]._4_z = D_5895_map_level;

    CAST2_0e64();
    if (local_6 == TILE_MAP_CODEX && local_8 > 0)
    {
        ULTIMA_1850_PrintString(/*0x9624*/ "\n\nThou dost see\n");
        if (local_8 == 1)
        {
            ULTIMA_1850_PrintString(/*0x9636*/ "an urn marked:\n\n");
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x9648*/ "urns marked:\n\n");
        }

        // 0fcf (OK)
        for (local_a = 1; local_a < 0x10; local_a++)
        {
            if (D_55a8_party[local_a].mapId == 0x7f)
            {
                local_c = 0;
                while (D_55a8_party[local_a].name[local_c] != '\0')
                {
                    ULTIMA_16ba_PrintChar(ULTIMA_2032_ToUpper((byte)D_55a8_party[local_a].name[local_c++]));
                }

                // 101f
                ULTIMA_16ba_PrintChar(10);
            }
        }
    }

    // 103c
    local_4 = local_6 != TILE_MAP_CODEX ? 4 : 7;

    for (local_a = 0; local_a < local_4; local_a++)
    {
        // 105c
        D_5c5a[0]._3_y--;
        CAST2_0e64();
    }

    // 1066
    if (local_6 != TILE_MAP_CODEX)
    {
        CAST2_0966();
    }
    else
    {
        CAST2_0d24();
    }

    // 1075
    D_5c5a[0]._0_tile = D_5c5a[0]._1_animTile = TILE_ACTOR_AVATAR;
    ULTIMA_3ae6(1);
    for (local_a = D_5c5a[0]._3_y; local_a < 10; local_a++)
    {
        D_5c5a[0]._3_y++;
        CAST2_0e64();
    }

    D_5c5a[0]._0_tile = D_5c5a[0]._2_x = D_5c5a[0]._3_y = 0;

    for (local_a = 0; local_a < 4; local_a++)
    {
        CAST2_0e64();
    }

    ULTIMA_3ae6(10);

    // 10c6 (NOT MATCHING)
    for (local_a = 0; local_a < 0x20; local_a++)
    {
        D_5c5a[local_a] = D_a9fc[local_a];
    }

    // 10e7
    D_5893_map_id = D_bd15;
    ULTIMA_4f7c(0x10);
    ULTIMA_5e4a();
}

// OK P1
// NOTE: IBM version; not compatible with modern platforms
static void CAST2_10fe_SaveGameIBM(void)
{
    byte local_4;
    byte local_6;

    ULTIMA_1850_PrintString(/*0x9658*/ "\nSave game? ");

    while ((local_6 = ULTIMA_266c_GetChar()) != 'Y')
    {
        if (local_6 == 'N')
            break;
    }

    if (local_6 == 'N')
    {
        ULTIMA_1850_PrintString(/*0x9666*/ "No\n");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x966a*/ "Yes\nSaving...\n");
        local_4 = D_a9bd[0];
        if (D_a9bd[0] != 5)
        {
            ULTIMA_251e_SwitchDisks(1);
        }

        ULTIMA_256e_ReadFileFromDisk(/*0x967a*/ "UNDER.OOL", D_b21e + 0x100, 0x100, 0);
        ULTIMA_251e_SwitchDisks(1);
        ULTIMA_256e_ReadFileFromDisk(/*0x9684*/ "BRIT.OOL", D_b21e, 0x100, 0);
        if (local_4 != 1)
        {
            ULTIMA_25d8_WriteFileToDisk(/*0x968e*/ "UNDER.OOL", D_b21e + 0x100, 0x100);
        }

        ULTIMA_251e_SwitchDisks(3);
        ULTIMA_25d8_WriteFileToDisk(/*0x9698*/ "SAVED.GAM", &D_55a6, ((int)&D_6606 - (int)&D_55a6) /*0x1060*/);
        ULTIMA_25d8_WriteFileToDisk(/*0x96a2*/ "SAVED.OOL", D_b21e, 0x200);
        ULTIMA_251e_SwitchDisks(local_4);
        ULTIMA_1850_PrintString(/*0x96ac*/ "Done.\n");
    }
}

// NOT MATCHING
// based on FMT
static void CAST2_10fe_SaveGameFMT(void)
{
    byte local_4;
    byte local_6;
    void* local_c;

    ULTIMA_1850_PrintString(/*0x4c114*/ "\nSave game? ");

    while ((local_6 = ULTIMA_266c_GetChar()) != 'Y')
    {
        if (local_6 == 'N')
            break;
    }

    if (local_6 == 'N')
    {
        ULTIMA_1850_PrintString(/*0x4c124*/ "No\n");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x4c128*/ "Yes\nSaving...\n");
        local_4 = D_a9bd[0];
        if (D_a9bd[0] != 5)
        {
            ULTIMA_251e_SwitchDisks(1);
        }

        ULTIMA_256e_ReadFileFromDisk(/*0x4c138*/ "UNDER.OOL", D_b21e + 0x100, 0x100, 0);
        ULTIMA_251e_SwitchDisks(1);
        ULTIMA_256e_ReadFileFromDisk(/*0x4c144*/ "BRIT.OOL", D_b21e, 0x100, 0);
        if (local_4 != 1)
        {
            ULTIMA_251e_SwitchDisks(3);
            ULTIMA_25d8_WriteFileToDisk(/*0x4c150*/ "UNDER.OOL", D_b21e + 0x100, 0x100);
        }

        // DAT_0003ddb0_55a6 = (byte)DAT_00065334_CurrentBgm;
        // DAT_0003ee18_6606 = (byte)DAT_00065338; // ?

        ULTIMA_251e_SwitchDisks(3);
        FILE_WriteSavegameFile(/*0x4c15c*/ "SAVED.GAM" /*, local_c*/);
        ULTIMA_25d8_WriteFileToDisk(/*0x4c168*/ "SAVED.OOL", D_b21e, 0x200);
        ULTIMA_251e_SwitchDisks(local_4);
        ULTIMA_1850_PrintString(/*0x4c174*/ "Done.\n");
    }
}

void CAST2_10fe_SaveGame(void)
{
    CAST2_10fe_SaveGameFMT();
}
