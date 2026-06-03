#include "common/common.h"
#include "funcs.h"
#include "vars.h"
#include "macros.h"

#include "combat.h"
#include "comsubs.h"
#include "dungeon.h"
#include "endgame.h"
#include "sjog.h"
#include "town.h"

void ULTIMA_6794(int param_1);

// OK P1
static int SJOG_0000(void)
{
    int i = 0x20;

    while (--i >= 0)
    {
        if (D_5c5a[i]._0_tile == 0)
            return i;
    }

    return 0;
}

// OK P1
static void SJOG_002a(int param_1, int param_2, int param_3)
{
    D_5876 = param_2;
    D_5878 = param_3;

    switch (param_1)
    {
    case 0:
        D_5878--;
        break;
    case 1:
        D_5876++;
        break;
    case 2:
        D_5878++;
        break;
    case 3:
        D_5876--;
        break;
    }
}

// OK P1
int SJOG_006c(int param_1)
{
    int local_4;
    byte local_6;

    ULTIMA_1850_PrintString(/*0x84e6*/ "Dir-");

    while ((local_6 = ULTIMA_266c_GetChar()) != ' ' && local_6 != 3 && local_6 != 4 && local_6 != 2 && local_6 != 1)
    {
    }

    switch (local_6)
    {
    case ' ':
        ULTIMA_1850_PrintString(/*0x84ec*/ "Pass\n");
        return 0;

    case 3:
        ULTIMA_1850_PrintString(/*0x84f2*/ "Ahead\n");
        SJOG_002a(param_1, D_5896_map_x, D_5897_map_y);
        break;

    case 4:
        ULTIMA_1850_PrintString(/*0x84fa*/ "Here\n");
        D_5876 = (uint)D_5896_map_x;
        D_5878 = (uint)D_5897_map_y;
        break;

    case 2:
        ULTIMA_1850_PrintString(/*0x8500*/ "Right\n");
        local_4 = (param_1 + 1) % 4;

        SJOG_002a(local_4, D_5896_map_x, D_5897_map_y);
        break;

    case 1:
        ULTIMA_1850_PrintString(/*0x8508*/ "Left\n");
        local_4 = (param_1 + 3) % 4;

        SJOG_002a(local_4, D_5896_map_x, D_5897_map_y);
        break;
    }

    return 1;
}

// OK P1
static void SJOG_012a(int param_1)
{
    switch (param_1)
    {
    case 1:
        ULTIMA_1850_PrintString("a chest!\n");
        break;
    case 2:
        ULTIMA_1850_PrintString("a sack of gold!\n");
        break;
    case 3:
        ULTIMA_1850_PrintString("a potion!\n");
        break;
    case 4:
        ULTIMA_1850_PrintString("a scroll!\n");
        break;
    case 5:
        ULTIMA_1850_PrintString("a weapon!\n");
        break;
    case 6:
        ULTIMA_1850_PrintString("a shield!\n");
        break;
    case 7:
        ULTIMA_1850_PrintString("a ring of keys!\n");
        break;
    case 8:
        ULTIMA_1850_PrintString("a gem!\n");
        break;
    case 9:
        ULTIMA_1850_PrintString("a helm!\n");
        break;
    case 10:
        ULTIMA_1850_PrintString("a ring!\n");
        break;
    case 0xb:
        ULTIMA_1850_PrintString("some armour!\n");
        break;
    case 0xc:
        ULTIMA_1850_PrintString("an amulet!\n");
        break;
    case 0xd:
        ULTIMA_1850_PrintString("some torches!\n");
        break;
    case 0xf:
        ULTIMA_1850_PrintString("some food!\n");
        break;
    case 0x19:
        ULTIMA_1850_PrintString("a strange rock!\n");
        break;
    case 0x1e:
        ULTIMA_1850_PrintString("a rotting body!\n");
        break;
    case 0x1f:
        ULTIMA_1850_PrintString("a moldy corpse!\n");
        break;
    default:
        ULTIMA_1850_PrintString("Nothing of note.\n");
        break;
    }
}

// OK P1
static void SJOG_01f2(int param_1, int param_2)
{
    if (ULTIMA_2092_RandomRange(0, 7) != 0)
    {
        ULTIMA_3a74(0, 0, 0, 0, 0, 0, param_1);
        if (ULTIMA_2092_RandomRange(0, 0x1f) == 0x13)
        {
            ULTIMA_1850_PrintString(/*0x8606*/ "Plague!\n");
            ULTIMA_223c_AudioWhiteNoise(0x28, 3000, 500);
            D_55a8_party[param_2]._b = 0x50;
            D_a9fa = 1;
        }
        else
        {
            switch (ULTIMA_2092_RandomRange(0, ULTIMA_2092_RandomRange(0, 3)))
            {
            case 0:
                ULTIMA_1850_PrintString(/*0x8610*/ "nothing!\n");
                break;

            case 1:
                ULTIMA_1850_PrintString(/*0x861a*/ "worms!\n");
                break;

            case 2:
                ULTIMA_1850_PrintString(/*0x8622*/ "guts!\n");
                break;

            case 3:
                ULTIMA_1850_PrintString(/*0x862a*/ "a bloody pulp!\n");
                break;
            }
        }
    }
    else
    {
        if (ULTIMA_2092_RandomRange(0, 3) == 0)
        {
            ULTIMA_1850_PrintString(/*0x863a*/ "food!\n");
            D_5c5a[param_1]._0_tile = D_5c5a[param_1]._1 = 0xf;
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x8642*/ "gold!\n");
            D_5c5a[param_1]._0_tile = D_5c5a[param_1]._1 = 2;
        }
        
        D_5c5a[param_1]._5 = ULTIMA_2092_RandomRange(1, 3);
        D_24e6 |= 2;
        ULTIMA_5910_UpdateFrame();
    }
}

// OK P1
static void SJOG_02ea(int param_1, int param_2)
{
    int local_4;
    int local_6;
    int local_8;

    local_4 = D_5c5a[param_1]._5;
    if ((local_4 & 0x80) == 0)
    {
        local_8 = (-(D_55a8_party[param_2]._e - 0x1e)) >> 1;
    }
    else
    {
        local_8 = ((local_4 & 0x7f) - (uint)D_55a8_party[param_2]._e + 0x1e) >> 1;
    }

    if (local_8 <= ULTIMA_2092_RandomRange(1, 0x1e))
        local_6 = 1;
    else
        local_6 = 0;

    if ((local_6 && (local_4 & 0x80) == 0) || (!local_6 && (local_4 & 0x80) != 0))
    {
        ULTIMA_1850_PrintString(/*0x864a*/ "no trap!\n");
    }
    else
    {
        local_8 = local_4 & 0x7f;
        if (local_6 && local_8 < 10)
        {
            ULTIMA_1850_PrintString(/*0x8654*/ "a simple trap!\n");
        }
        else if (local_6 && 0x14 < local_8)
        {
            ULTIMA_1850_PrintString(/*0x8664*/ "a complex trap!\n");
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x8676*/ "a trap!\n");
        }
    }
}

// OK P1
static int SJOG_03a8(int param_1, int param_2, int param_3)
{
    int local_6;
    int local_8;
    int local_4;
    int local_a;

    local_6 = 8;

    // 03b5
    while (--local_6 >= 0)
    {
        // 03bd
        if (D_5830[local_6] == param_1 && D_5838[local_6] == param_2 &&
            D_5848[local_6] == param_3 && D_5840[local_6] == D_5893_map_id)
        {
            // 03e6
            local_4 = 0;
            local_8 = 0x20;
            while (--local_8 >= 0)
            {
                // 03ee
                if (ULTIMA_368e_FindNpcTileAtPos(param_1, param_2, param_3) == 0x19 && D_5c5a[D_5876]._5 == local_6)
                {
                    local_4 = 1;
                }
                // 0415
            }

            // 041e
            if (local_4 != 0)
            {
                continue;
            }

            // 0422
            local_a = ULTIMA_38e4();
            ULTIMA_3a74(0x19, 0x19, param_1, param_2, param_3, local_6, local_a);
            ULTIMA_1850_PrintString(/*0x8680*/ "a strange rock!\n");
            D_24e6 |= 2;
            return 1;
        }
    }

    // 0450
    return 0;
}

// OK P1
static int SJOG_045a(int param_1, int param_2)
{
    int local_6;
    int local_8;
    int local_4;
    char** local_a;

    local_8 = 0;
    local_a = D_3e72;
    do
    {
        if (D_3e66[local_8] == param_1 && D_3e6a[local_8] == param_2 && D_587f == 0 && D_5858[local_8] != D_587e)
        {
            D_5858[local_8] = D_587e;

            local_6 = D_3e6e[local_8];
            local_4 = ULTIMA_2092_RandomRange(2, 0xf);
            D_5850[local_6] += local_4;
            if (D_5850[local_6] > 99)
            {
                D_5850[local_6] = 99;
            }

            // 04ba
            if (local_4 < 10)
            {
                ULTIMA_1a3e_PrintNumber(local_4, 1, 0x20);
            }
            else
            {
                ULTIMA_1a3e_PrintNumber(local_4, 2, 0x20);
            }

            // 04d4
            ULTIMA_1850_PrintString(/*0x86be*/ " sprigs of\n");
            ULTIMA_1850_PrintString(*local_a);
            ULTIMA_1850_PrintString(/*0x86ca*/ "\n");

            // 050b
            return 1;
        }

        // 04f6
        local_a++;
        local_8++;
    } while (local_8 < 3);

    // 0503
    return 0;
}

// CHECKED
static void SJOG_0514(int param_1, int param_2)
{
    bool local_a;
    int local_6;
    int local_4;
    int local_8;

    local_a = 0;

    for (local_4 = 0; local_4 < 0x71; local_4++)
    {
        if (D_3f5c[local_4] == D_5893_map_id && D_3fce[local_4] == D_5895_map_level && D_4040[local_4] == param_1 && D_40b2[local_4] == param_2)
        {
            // 0558
            if ((local_4 == 0xd && D_57ac == 0 && ULTIMA_368e_FindNpcTileAtPos(param_1, param_2, D_5895_map_level) == 0) ||
                (local_4 == 0xe && D_587e != D_57b2) ||
                (local_4 == 0xf && D_57c0[0x27] == 0 && ULTIMA_368e_FindNpcTileAtPos(param_1, param_2, D_5895_map_level) == 0))
            {
                local_a = 1;
                break;
            }

            // 05f6 (OK)
            local_8 = 1 << (local_4 & 7);
            if ((D_585c[(local_4 >> 3)] & local_8) == 0 && (local_4 < 0xd || local_4 > 0xf))
            {
                // 061a
                D_585c[(local_4 >> 3)] |= local_8;

                // -> 05a1
                local_a = 1;
                break;
            }
        }
    }

    if (local_4 == 0xe)
    {
        D_57b2 = D_587e;
    }

    // 05b7
    if (local_a)
    {
        register int si; // NOT MATCHING
        local_6 = ULTIMA_38e4();
        si = D_3e78[local_4];
        ULTIMA_3a74(si, si, D_4040[local_4], D_40b2[local_4], D_3fce[local_4], D_3eea[local_4], local_6);
        D_24e6 |= 2;
        SJOG_012a(si);
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x86cc*/ "nothing of note.\n");
    }
}

// CHECKED
static void SJOG_0646(void)
{
    int local_c;
    int local_e;
    int local_10;
    int local_6;
    int local_a;
    int local_4;
    int local_8;

    local_10 = ULTIMA_4988();
    if (++local_10 == 0)
    {
        return;
    }

    if (D_58a7 == 0 && D_58a6 == 0)
    {
        // 066b
        ULTIMA_1850_PrintString(/*0x86de*/ "\nYou find:\ndarkness.\n");
        return;
    }

    if (SJOG_006c(D_6603) == 0)
    {
        return;
    }

    local_a = D_5876;
    local_c = D_5878;
    local_e = GetDungeonMap(local_a & 7, local_c & 7, (uint)D_5895_map_level);
    local_4 = D_55a8_party[local_10]._d;
    local_6 = (D_5895_map_level * 2 - local_4 + 0x1e) >> 1;
    ULTIMA_1850_PrintString(/*0x86f4*/ "You find:\n");

    switch (local_e & 0xf0)
    {
    case 0x0:
        // 0704
        ULTIMA_1850_PrintString(/*0x8700*/ "Nothing of note.\n");
        break;

    case 0x10:
    case 0x20:
    case 0x30:
        // 070a
        ULTIMA_1850_PrintString(/*0x8712*/ "Nothing hidden on the ladder.\n");
        break;

    case 0x40:
        // 0710
        if (ULTIMA_2092_RandomRange(1, 0x1e) > local_6)
        {
            if (local_e == 0x40)
            {
                ULTIMA_1850_PrintString(/*0x8732*/ "No trap\n");
                break;
            }

            local_8 = D_5895_map_level;
        }
        else
        {
            local_8 = ULTIMA_2092_RandomRange(1, 8);
        }

        if (local_8 < 4)
        {
            ULTIMA_1850_PrintString(/*0x873c*/ "A simple trap\n");
            break;
        }
        else if (local_8 >= 7)
        {
            ULTIMA_1850_PrintString(/*0x874c*/ "A complex trap\n");
            break;
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x875c*/ "A trap\n");
            break;
        }
        break;

    case 0x50:
        // 0760
        ULTIMA_1850_PrintString(/*0x8764*/ "Nothing hidden on the fountain.\n");
        break;

    case 0x60:
        // 0766
        switch (local_e)
        {
        case 0x60:
            // 077c
            ULTIMA_1850_PrintString(/*0x8786*/ "Nothing hidden\nin the pit.\n");
            break;

        case 0x61:
            // 0782
            ULTIMA_1850_PrintString(/*0x87a2*/ "A pit!\n");
            GetDungeonMap(local_a & 7, local_c & 7, D_5895_map_level) = (local_e & 0x8) + 0x60;
            if (D_5895_map_level < 7)
            {
                GetDungeonMap(local_a & 7, local_c & 7, D_5895_map_level + 1) |= 8;
            }

            DUNGEON_1a90(1);
            ULTIMA_0f46_GRAP_66_Reveal(8, 8, 0xb7, 0xb7);
            break;

        case 0x62:
            // 07c6
            if (local_6 < ULTIMA_2092_RandomRange(1, 0x1e))
            {
                ULTIMA_1850_PrintString(/*0x87aa*/ "A bomb trap!\n");
                GetDungeonMap(local_a & 7, local_c & 7, D_5895_map_level) &= 8;
            }
            else
            {
                // 0802
                ULTIMA_1850_PrintString(/*0x87b8*/ "Nothing of note.\n");
            }

            // nop?
            break;
        }

        break;

    case 0x70:
        // 0808
        ULTIMA_1850_PrintString(/*0x87ca*/ "Treasure!\n");
        break;

    case 0x80:
        // 080e
        switch (local_e)
        {
        case 0x80:
            ULTIMA_1850_PrintString(/*0x87d6*/ "A sleep field.\n");
            break;
        case 0x81:
            ULTIMA_1850_PrintString(/*0x87e6*/ "A poison gas field.\n");
            break;
        case 0x82:
            ULTIMA_1850_PrintString(/*0x87fc*/ "A wall of fire.\n");
            break;
        case 0x83:
            ULTIMA_1850_PrintString(/*0x880e*/ "An electric field.\n");
            break;
        default:
            ULTIMA_1850_PrintString(/*0x8822*/ "An energy field.\n");
            break;
        }
        break;

    case 0x90:
        // 0844
        ULTIMA_1850_PrintString(/*0x8834*/ "This tile is impossible.\n");
        break;

    case 0xa0:
        // 084a
        ULTIMA_1850_PrintString(/*0x884e*/ "Nothing hidden on the door.\n");
        break;

    case 0xb0:
        // 0850
        ULTIMA_1850_PrintString(/*0x886c*/ "Nothing hidden on the wall.\n");
        break;

    case 0xc0:
        // 0856
        switch (D_6604 & 0xf)
        {
        case 2:
            // 08b6
            ULTIMA_1850_PrintString(/*0x888a*/ "Nothing in the caved in passage.\n");
            break;

        case 1:
            // 08bc
            ULTIMA_1850_PrintString(/*0x88ac*/ "Nothing on the stalactite.\n");
            break;

        default:
            // 0868
            ULTIMA_1850_PrintString(/*0x88c8*/ "Nothing hidden on the skeleton.\n");
            ULTIMA_1850_PrintString(/*0x88ea*/ "It crumbles away.\n");

            GetDungeonMap(local_a & 7, local_c & 7, D_5895_map_level) = (local_e & 8) - 0x50;
            DUNGEON_1a90(1);
            ULTIMA_0f46_GRAP_66_Reveal(8, 8, 0xb7, 0xb7);
            break;
        }
        break;

    case 0xd0:
        // 08c2
        ULTIMA_1850_PrintString(/*0x88fe*/ "A hidden door!\n");

        GetDungeonMap(local_a & 7, local_c & 7, D_5895_map_level) = (local_e & 8) - 0x20;
        DUNGEON_1a90(1);
        ULTIMA_0f46_GRAP_66_Reveal(8, 8, 0xb7, 0xb7);
        break;

    case 0xe0:
    case 0xf0:
        // 08f0
        ULTIMA_1850_PrintString(/*0x890e*/ "Nothing hidden on the door.\n");
        break;
    }
}

// CHECKED
void SJOG_095c_SearchCmd(void)
{
    int local_10;
    int local_e;
    int local_a;
    int local_c;
    int local_6;
    int local_4;
    int local_8;

    local_4 = 0;

    if (D_5893_map_id > 0x20 && D_5893_map_id < 0x29)
    {
        SJOG_0646();
        return;
    }

    if (ULTIMA_35ec_SelectDirection() == 0)
    {
        return;
    }

    local_a = D_5896_map_x + D_5876;
    local_c = D_5897_map_y + D_5878;
    if ((local_e = ULTIMA_4988()) == -1)
    {
        return;
    }

    local_10 = *ULTIMA_4402_GetTileAddr(local_a, local_c);

    for (local_6 = 1; local_6 < 0x20; local_6++)
    {
        if (D_5c5a[local_6]._2_x == local_a &&
            D_5c5a[local_6]._3_y == local_c &&
            (D_5893_map_id > 0x7f || D_5c5a[local_6]._4_z == D_5895_map_level))
        {
            local_8 = D_5c5a[local_6]._0_tile;
            if (local_8 == 1)
            break;
        }
    }

    if (local_6 < 0x20)
    {
        ULTIMA_1850_PrintString(/*0x892c*/ "\nThou dost find\n");
        SJOG_02ea(local_6, local_e);
        return;
    }

    local_8 = ULTIMA_3702(local_a, local_c, D_5895_map_level);
    if (local_8 == 0x1f)
    {
        ULTIMA_1850_PrintString(/*0x893e*/ "\nThou dost find\n");
        SJOG_01f2(D_5876, local_e);
        return;
    }

    switch (local_10)
    {
    case 0x2b:
        ULTIMA_1850_PrintString(/*0x8950*/ "\nIn the stump\nt");
        break;

    case 0x5a:
        ULTIMA_1850_PrintString(/*0x8960*/ "\nOn the shelf\nt");
        break;

    case 0x5c:
    case 0x5d:
        ULTIMA_1850_PrintString(/*0x8970*/ "\nIn the bookshelf\nt");
        break;

    case 0xa1:
        ULTIMA_1850_PrintString(/*0x8984*/ "\nNear the well\nt");
        break;

    case 0xa5:
        ULTIMA_1850_PrintString(/*0x8996*/ "\nIn the desk\nt");
        break;

    case 0xa6:
        ULTIMA_1850_PrintString(/*0x89a6*/ "\nIn the barrel\nt");
        break;

    case 0xa8:
        ULTIMA_1850_PrintString(/*0x89b8*/ "\nIn the vanity\nt");
        break;

    case 0xab:
    case 0xac:
        ULTIMA_1850_PrintString(/*0x89ca*/ "\nUnder the bed\nt");
        break;

    case 0xad:
        ULTIMA_1850_PrintString(/*0x89dc*/ "\nIn the dresser\nt");
        break;

    case 0xaf:
        ULTIMA_1850_PrintString(/*0x89ee*/ "\nIn the trunk\nt");
        break;

    case 0xbc:
        ULTIMA_1850_PrintString(/*0x89fe*/ "\nIn the fireplace\nt");
        break;

    case 0xb2:
        ULTIMA_1850_PrintString(/*0x8a12*/ "\nIn the brazier\nt");
        break;

    case 0x4f:
        ULTIMA_1850_PrintString(/*0x8a24*/ "\nIn the wall\nt");
        break;

    default:
        ULTIMA_1850_PrintString(/*0x8a34*/ "\nT");
        break;
    }

    ULTIMA_1850_PrintString(/*0x8a38*/ "hou dost find\n");
    if (local_10 == 0x4e)
    {
        ULTIMA_1850_PrintString(/*0x8a48*/ "a hidden door!\n");
        if (D_5895_map_level < 0x80)
        {
            *ULTIMA_4402_GetTileAddr(local_a, local_c) = 0xb9;
        }
        else
        {
            *ULTIMA_4402_GetTileAddr(local_a, local_c) = 0xb8;
        }
        D_24e6 |= 2;
    }
    else if ((local_10 == 0xdc || (local_4 = SJOG_03a8(local_a, local_c, D_5895_map_level)) == 0) && (local_4 = SJOG_045a(local_a, local_c)) == 0)
    {
        SJOG_0514(local_a, local_c);
    }
}

// OK P1
static void SJOG_0baa(int a, int b, int c, int param_4)
{
    byte local_4;
    byte local_6;
    int local_8;

    if ((local_8 = ULTIMA_4988()) != -1)
    {
        local_4 = D_5c5a[param_4]._5;
        if (local_4 < 0x80)
        {
            ULTIMA_1850_PrintString(/*0x8a58*/ "Key broke!\n");
        }
        else
        {
            local_6 = (((local_4 & 0x7f) - D_55a8_party[local_8]._d + 0x1e) >> 1) & 0xff;
            if (local_6 < ULTIMA_2092_RandomRange(1, 0x1e))
            {
                ULTIMA_1850_PrintString(/*0x8a64*/ "Success!\n");
                D_5c5a[param_4]._5 &= 0x7f;
                return;
            }
            ULTIMA_1850_PrintString(/*0x8a6e*/ "Key broke!\n");
        }

        ULTIMA_43ae_AudioSweepTone(800, 2000, 1, 0x32);
        D_57ac--;
    }
}

// CHECKED
static void SJOG_0c3e(void)
{
    int local_8;
    int local_a;
    int local_e;
    int local_4;
    int local_c;
    int local_6;

    ULTIMA_1850_PrintString(/*0x8a7a*/ "\n");
    if ((local_c = ULTIMA_4988()) == -1)
    {
        return;
    }

    local_8 = D_5896_map_x;
    local_a = D_5897_map_y;
    local_e = GetDungeonMap(local_8 & 7, local_a & 7, (uint)D_5895_map_level);
    local_4 = D_55a8_party[local_c]._d;
    local_6 = (D_5895_map_level * 2 - local_4 + 0x1e) >> 1;

    if ((local_e & 0xf7) == 0x40)
    {
        if (D_57ac == 0)
        {
            ULTIMA_1850_PrintString(/*0x8a7c*/ "No keys!\n");
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x8a86*/ "Key broke!\n");
            D_57ac--;
        }
    }
    else if ((local_e & 0xf0) == 0x40)
    {
        if (D_57ac == 0)
        {
            ULTIMA_1850_PrintString(/*0x8a92*/ "No keys!\n");
        }
        else
        {
            if (local_6 < ULTIMA_2092_RandomRange(1, 0x1e))
            {
                ULTIMA_1850_PrintString(/*0x8a9c*/ "Chest unlocked\n");
                GetDungeonMap(local_8 & 7, local_a & 7, D_5895_map_level) = (local_e & 8) + 0x40;
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x8aac*/ "Key broke!\n");
                D_57ac--;
            }
        }
    }
    else if ((local_e & 0xf0) == 0x70)
    {
        ULTIMA_1850_PrintString(/*0x8ab8*/ "Already open!\n");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x8ac8*/ "What?\n");
    }
}

// CHECKED
void SJOG_0d4a_JimmyCmd(void)
{
    int local_6;
    int local_4;
    int local_c;
    int local_8;
    int local_a;

    if (D_5893_map_id > 0x20 && D_5893_map_id < 0x29)
    {
        SJOG_0c3e();
        return;
    }

    if (D_57ac == 0)
    {
        // cced, ccf0
        ULTIMA_1850_PrintString(/*0x8ad0*/ "No Keys!\n");
        return;
    }

    // ccf8
    if (ULTIMA_35ec_SelectDirection() == 0)
    {
        return;
    }

    // cd02
    local_8 = D_5896_map_x + D_5876;
    local_a = D_5897_map_y + D_5878;
    local_6 = *ULTIMA_4402_GetTileAddr(local_8, local_a);
    switch (local_6)
    {
    case 0xb9:
    case 0xbb:
        // cd48
        if ((local_c = ULTIMA_4988()) == -1)
        {
            break;
        }

        if (D_55a8_party[local_c]._d <= ULTIMA_2092_RandomRange(0, 0x1d))
        {
            ULTIMA_1850_PrintString(/*0x8ada*/ "Key broke!\n");
            D_57ac--;
            break;
        }

        *ULTIMA_4402_GetTileAddr(local_8, local_a) = local_6 - 1;
        D_24e6 |= 2;
        ULTIMA_1850_PrintString(/*0x8ae6*/ "Unlocked!\n");
        break;

    case 0x97:
    case 0x98:
        // cd9c -> cd72
        ULTIMA_1850_PrintString(/*0x8af2*/ "Key broke!\n");
        D_57ac--;
        break;

    case 0x84:
    case 0x85:
        // cda2
        if (D_5893_map_id < 0x80 && ULTIMA_368e_FindNpcTileAtPos(local_8, local_a, D_5895_map_level) == 0)
        {
            // -> ccf0
            ULTIMA_1850_PrintString(/*0x8afe*/ "No one is there!\n");
            break;
        }

        // cdc2
        local_4 = D_5876;
        if ((local_c = ULTIMA_4988()) == -1)
        {
            break;
        }

        if (D_55a8_party[local_c]._d <= ULTIMA_2092_RandomRange(0, 0x1d))
        {
            // cdef -> cd72
            ULTIMA_1850_PrintString(/*0x8b10*/ "Key broke!\n");
            D_57ac--;
            break;
        }

        // cdf6
        if (D_5893_map_id < 0x7f)
        {
            if ((local_4 = TOWN_011e(local_4)) == -1)
            {
                // -> ccf0
                ULTIMA_1850_PrintString(/*0x8b1c*/ "Couldn't find this npc\n\n");
                break;
            }

            if (D_5f5e[local_4]._a != 0)
            {
                D_5f5e[local_4]._a = 0;
            }

            // ce24
            if (TOWN_0000(local_4) == 0)
            {
                D_5d5e[local_4]._0[0] = 5;
                D_5d5e[local_4]._0[1] = 5;
                D_5d5e[local_4]._0[2] = 5;
                ULTIMA_1850_PrintString(/*0x8b36*/ "\n\"I thank thee!\"\n");
                ULTIMA_3ef0(&D_5888, 2, 99);
            }

            // ce5a
            TOWN_0052(local_4);
            break;
        }

        // ce64
        *ULTIMA_4402_GetTileAddr(local_8, local_a) = 0x44;
        D_24e6 |= 2;
        ULTIMA_1850_PrintString(/*0x8b48*/ "Unlocked\n");
        break;

    default:
        // ceac (NOT MATCHING)
        for (local_c = 1; local_c < 0x20; local_c++)
        {
            if (D_5c5a[local_c]._2_x == local_8 && D_5c5a[local_c]._3_y == local_a &&
                (D_5893_map_id > 0x7f || D_5c5a[local_c]._4_z == D_5895_map_level) && D_5c5a[local_c]._0_tile == 1)
            {
                // exit from the loop
                break;
            }
        }

        // cee9
        if (local_c < 0x20)
        {
            SJOG_0baa(local_8, local_a, D_5895_map_level, local_c);
            break;
        }

        ULTIMA_1850_PrintString(/*0x8b52*/ "No lock!\n");
        break;
    }
}

// OK P1
static void SJOG_0f88(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int* param_7)
{
    int iVar1;
    int local_4;

    if (param_1 == 3 || param_1 == 4)
    {
        param_2--;
    }

    if (param_1 == 1)
    {
        local_4 = ULTIMA_2092_RandomRange(1, param_6);
    }
    else if (param_1 == 2)
    {
        local_4 = ULTIMA_2092_RandomRange(1, param_6 * 3);
    }
    else
    {
        local_4 = param_2;
    }

    iVar1 = SJOG_0000();
    if (iVar1 != 0)
    {
        ULTIMA_3a74(param_1, param_1, param_3, param_4, param_5, local_4, iVar1);
        if (D_5893_map_id < 0x80)
        {
            D_5c5a[iVar1]._7 = 0;
            D_5c5a[iVar1]._4_z = (undefined1)param_5;
        }
        else
        {
            D_5c5a[iVar1]._7 = 0x20;
        }
        D_24e6 = D_24e6 | 2;
        ULTIMA_5910_UpdateFrame();
        if (*param_7 == 0)
        {
            ULTIMA_1850_PrintString("Found:\n");
            *param_7 = 1;
        }
        SJOG_012a(param_1);
    }
}

// OK P1
static void SJOG_1040(int param_1, int param_2, int param_3, int param_4, int* param_5)
{
    int local_6;
    int local_4;

    local_6 = 8;
    while (--local_6 >= 0)
    {
        if (D_412c[local_6] <= param_1)
        {
            if (D_412c[local_6] <= ULTIMA_2092_RandomRange(1, 0x1e))
            {
                if (D_4134[local_6] == 1)
                {
                    local_4 = 1;
                }
                else
                {
                    local_4 = ULTIMA_2092_RandomRange(1, D_4134[local_6]);
                }

                SJOG_0f88(D_4124[local_6], local_4, param_2, param_3, param_4, param_1, param_5);
            }
        }
    }
}

// OK P1
static void SJOG_10b8(int param_5, int param_4, int param_3, int param_2, int* param_1)
{
    int local_4;
    int local_6;

    local_4 = param_5 / 2;
    while (local_4-- >= 0)
    {
        local_6 = ULTIMA_2092_RandomRange(0, 0x2f);

        if (D_416c[local_6] <= param_5)
        {
            if (D_416c[local_6] <= ULTIMA_2092_RandomRange(1, 0x1e))
            {
                SJOG_0f88(D_413c[local_6], local_6, param_4, param_3, param_2, param_5, param_1);
            }
        }
    }
}

// CHECKED
// Open sub
static void SJOG_112c(int param_1, int param_2, int param_3)
{
    int local_c;
    int local_a;
    byte local_8;
    int local_6;
    CombatEntity* local_4;

    local_a = 0;
    for (local_6 = 1; local_6 < 0x20; local_6++)
    {
        if (D_5c5a[local_6]._2_x == param_1 && D_5c5a[local_6]._3_y == param_2 &&
            (D_5893_map_id > 0x7f || (D_5893_map_id < 0x80 && D_5c5a[local_6]._4_z == param_3)))
        {
            if (D_5c5a[local_6]._0_tile == 1)
                break;

            if (D_5c5a[local_6]._0_tile == 14)
            {
                ULTIMA_1850_PrintString(/*0x8b64*/ "Can't!\n");
                return;
            }
        }
    }

    if (local_6 == 0x20)
    {
        ULTIMA_1850_PrintString(/*0x8b6c*/ "Nothing to open!\n");
        return;
    }

    if ((local_c = ULTIMA_4988()) == -1)
    {
        return;
    }

    local_8 = D_5c5a[local_6]._5;
    ULTIMA_3a74(0, 0, 0, 0, 0, 0, local_6);
    D_24e6 = D_24e6 | 2;
    if (D_5893_map_id >= 1 && D_5893_map_id <= 0x20)
    {
        if (D_5888 > 2)
        {
            D_5888 -= 2;
        }
        else
        {
            D_5888 = 0;
        }
    }

    if (local_8 > 0x7f)
    {
        local_8 &= 0x7f;
        ULTIMA_1850_PrintString(/*0x8b7e*/ "Trapped!\n");
        ULTIMA_2fd0(local_c);
        if (D_5893_map_id > 0x7f && D_55a8_party[local_c]._b == 'D')
        {
            for (local_6 = 0; local_6 < 32; local_6++)
            {
                local_4 = &D_ba14[local_6];
                if ((local_4->_2 & 0x80) != 0 && local_4->_3 == local_c)
                {
                    local_4->_2 |= 0x20;

                    D_5c5a[local_4->_4]._0_tile = D_5c5a[local_4->_4]._1 = 0x1e;
                    break;
                }
            }

            if (local_c == D_587b)
            {
                D_587b = 0xff;
            }
            ULTIMA_5910_UpdateFrame();
        }
    }

    SJOG_1040(local_8, param_1, param_2, param_3, &local_a);
    SJOG_10b8(local_8, param_1, param_2, param_3, &local_a);
    if (local_a != 0)
    {
        return;
    }

    ULTIMA_1850_PrintString(/*0x8b88*/ "Chest empty!\n");
}

// OK P1
static void SJOG_12d4(void)
{
    int local_6;
    int local_4;

    local_6 = GetDungeonMap2(D_5896_map_x, D_5897_map_y, D_5895_map_level);
    if ((local_6 & 0xf0) == 0x40)
    {
        if ((local_4 = ULTIMA_4988()) == -1)
        {
            return;
        }

        if ((local_6 & 7) != 0)
        {
            ULTIMA_2fd0(local_4);
        }

        GetDungeonMap2(D_5896_map_x, D_5897_map_y, D_5895_map_level) = (local_6 & 8) + 0x70;
        ULTIMA_1850_PrintString("\nChest opened\n");
    }
    else if ((local_6 & 0xf0) == 0x70)
    {
        ULTIMA_1850_PrintString("Already Open!\n");
    }
    else
    {
        ULTIMA_1850_PrintString("What?\n");
    }
}

// OK P1
void SJOG_1374_OpenCmd(void)
{
    int local_4;
    int local_6;
    int local_8;

    if (D_5893_map_id > 0x20 && D_5893_map_id < 0x29)
    {
        SJOG_12d4();
        return;
    }

    ULTIMA_39cc_SetTile(D_594f, D_5950, D_5951);
    if (ULTIMA_35ec_SelectDirection() == 0)
    {
        return;
    }

    local_6 = D_5896_map_x + D_5876;
    local_8 = D_5897_map_y + D_5878;
    local_4 = *ULTIMA_4402_GetTileAddr(local_6, local_8);
    switch (local_4)
    {
    case 0xaf:
        // 13ea
        ULTIMA_1850_PrintString("It's open!\n");
        break;

    case 0x99:
        // 13f4
        ULTIMA_1850_PrintString("Too heavy!\n");
        break;

    case 0x97:
    case 0x98:
    case 0xb9:
    case 0xbb:
        // 13fa
        ULTIMA_1850_PrintString("Locked!\n");
        break;

    case 0xb8:
    case 0xba:
        // 1400
        D_594f = local_4;
        D_5952 = 4;
        D_5950 = (undefined1)local_6;
        D_5951 = (undefined1)local_8;
        *ULTIMA_4402_GetTileAddr(local_6, local_8) = 0x44;
        D_24e6 = 1;
        ULTIMA_1850_PrintString("Opened!\n");
        break;

    default:
        // 1444
        SJOG_112c(local_6, local_8, D_5895_map_level);
        break;
    }
}

// CHECKED (nop)
static void SJOG_1458(int param_1, int param_2, int param_3)
{
    switch (param_1)
    {
    case 1:
        ULTIMA_1850_PrintString(/*0x8c3e*/ "Open it first!\n");
        return;

    case 0x19:
        ULTIMA_1850_PrintString(/*0x8c4e*/ "A moonstone!\n");
        D_5840[param_2] = 0xff;
        break;

    case 0x1b:
        ULTIMA_1850_PrintString(/*0x8c5c*/ "A magic carpet!\n");
        D_57b0++;
        if (D_57b0 == 100)
        {
            D_57b0 = 99;
        }

        if (D_5893_map_id != 0x11)
            break;

        TOWN_00b0(0x16);
        break;

    case 0xf:
        ULTIMA_1a3e_PrintNumber(param_2, 1, 0x20);
        ULTIMA_1850_PrintString(/*0x8c6e*/ " food!\n");
        ULTIMA_3f14(&D_57a8, param_2, 9999);
        break;

    case 0xe:
        ULTIMA_1850_PrintString(/*0x8c76*/ "A sandalwood box!\n");
        D_57bf = 0xff;
        D_5b5a[0x43] |= 0x80;
        break;

    case 0xd:
        ULTIMA_1a3e_PrintNumber(param_2, 1, 0x20);
        ULTIMA_1850_PrintString(/*0x8c8a*/ " torch");
        if (param_2 == 1)
        {
            ULTIMA_1850_PrintString(/*0x8c92*/ "!\n");
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x8c96*/ "es!\n");
        }
        ULTIMA_3ef0(&D_57ae, param_2, 99);
        break;

    case 8:
        ULTIMA_1a3e_PrintNumber(param_2, 1, 0x20);
        ULTIMA_1850_PrintString(/*0x8c9c*/ " gem");
        if (param_2 == 1)
        {
            ULTIMA_1850_PrintString(/*0x8ca2*/ "!\n");
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x8ca6*/ "s!\n");
        }

        ULTIMA_3ef0(&D_57ad, param_2, 99);
        break;

    case 7:
        if (param_2 > 0x7f)
        {
            param_2 &= 0x7f;
            ULTIMA_1a3e_PrintNumber(param_2, 1, 0x20);
            ULTIMA_1850_PrintString(/*0x8caa*/ " odd key");
            ULTIMA_3ef0(&D_57b1, param_2, 99);
        }
        else
        {
            ULTIMA_1a3e_PrintNumber(param_2, 1, 0x20);
            ULTIMA_1850_PrintString(/*0x8cb4*/ " key");
            ULTIMA_3ef0(&D_57ac, param_2, 99);
        }

        if (param_2 == 1)
        {
            ULTIMA_1850_PrintString(/*0x8cba*/ "!\n");
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x8cbe*/ "s!\n");
        }
        break;

    case 4:
        if (param_2 == 0xff)
        {
            ULTIMA_1850_PrintString(/*0x8cc2*/ "The plans for the HMS Cape!\n");
            D_57bb = 0xff;
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x8ce0*/ "A scroll: ");
            ULTIMA_1c9e_SelectCharset(1);
            ULTIMA_1850_PrintString(D_41ac[param_2 & 7]);
            ULTIMA_1c9e_SelectCharset(0);
            ULTIMA_1850_PrintString(/*0x8cec*/ "!\n");
            D_5820[param_2]++;
            if (D_5820[param_2] == 100)
            {
                D_5820[param_2] = 99;
            }
        }
        break;

    case 2:
        ULTIMA_1a3e_PrintNumber(param_2, 1, 0x20);
        ULTIMA_1850_PrintString(/*0x8cf0*/ " gold!\n");
        ULTIMA_3f14(&D_57aa, param_2, 9999);
        break;

    case 3:
        ULTIMA_1850_PrintString(/*0x8cf8*/ "A ");
        ULTIMA_1850_PrintString(D_419c[param_2]);
        ULTIMA_1850_PrintString(/*0x8cfc*/ " potion!\n");
        D_5828[param_2]++;
        if (D_5828[param_2] == 100)
        {
            D_5828[param_2] = 99;
        }
        break;

    case 5:
    case 6:
    case 9:
    case 0xa:
    case 0xb:
    case 0xc:
        if (param_2 == 0x1b || param_2 == 0x1d)
        {
            ULTIMA_3ef0(&D_57c0[param_2], 5, 99);
        }
        else
        {
            D_57c0[param_2]++;
            if (D_57c0[param_2] == 100)
            {
                D_57c0[param_2] = 99;
            }
        }

        ULTIMA_1850_PrintString(D_17f6[param_2]);
        ULTIMA_1850_PrintString(/*0x8d06*/ "!\n");
        break;

    case 0xb4:
        D_57b6[param_2 & 3] = 0xff;
        ULTIMA_1850_PrintString(/*0x8d0a*/ "The Shard of\n");
        switch (param_2 & 3)
        {
        case 0:
            ULTIMA_1850_PrintString(/*0x8d18*/ "Falsehood!\n");
            break;
        case 1:
            ULTIMA_1850_PrintString(/*0x8d24*/ "Hatred!\n");
            break;
        default:
            ULTIMA_1850_PrintString(/*0x8d2e*/ "Cowardice!\n");
            break;
        }
        break;

    case 0xb5:
        D_57b4 = 0xff;
        ULTIMA_1850_PrintString(/*0x8d3a*/ "The Crown of Lord British!\n");
        TOWN_0052(TOWN_011e(param_3));
        TOWN_00b0(TOWN_011e(param_3));
        break;

    case 0xb6:
        D_57b5 = 0xff;
        ULTIMA_1850_PrintString(/*0x8d56*/ "The Sceptre of Lord British!\n");
        break;

    case 0xb7:
        D_57b3 = 0xff;
        ULTIMA_1850_PrintString(/*0x8d74*/ "The Amulet of Lord British!\n");
        break;

    default:
        ULTIMA_1850_PrintString(/*0x8d92*/ "Nothing to get!\n");
        return;
    }

    if (param_3 < 0x20)
    {
        ULTIMA_3a74(0, 0, 0, 0, 0, 0, param_3);
    }

    D_24e6 |= 2;
    D_a9fa = 1;
}

// CHECKED (nop)
static void SJOG_179e(void)
{
    int local_a;
    int local_8;
    int local_6;
    int local_4;

    ULTIMA_1850_PrintString(/*0x8da4*/ "Get\n");

    local_a = GetDungeonMap2(D_5896_map_x, D_5897_map_y, D_5895_map_level);
    if ((local_a & 0xf0) == 0x40)
    {
        ULTIMA_1850_PrintString(/*0x8daa*/ "Must open first!\n");
        return;
    }

    if ((local_a & 0xf0) == 0x70)
    {
        GetDungeonMap2(D_5896_map_x, D_5897_map_y, D_5895_map_level) &= 8;

        ULTIMA_1850_PrintString(/*0x8dbc*/ "contents\nof chest\nYou find:\n");

        for (local_8 = 0; local_8 < 7; local_8++)
        {
            if (D_41bc[local_8] <= ULTIMA_2092_RandomRange(1, D_5895_map_level * 4 + 4))
            {
                if (local_8 == 5)
                {
                    local_6 = ULTIMA_2092_RandomRange(0, 7);
                    SJOG_1458(3, local_6, 0x20);
                }
                else if (local_8 == 6)
                {
                    local_6 = ULTIMA_2092_RandomRange(0, 7);
                    SJOG_1458(4, local_6, 0x20);
                }
                else
                {
                    if (local_8 == 1)
                    {
                        local_4 = ULTIMA_2092_RandomRange(1, D_5895_map_level << 3);
                    }
                    else
                    {
                        local_4 = ULTIMA_2092_RandomRange(1, D_41c4[local_8]);
                    }

                    SJOG_1458(D_41cc[local_8], local_4, 0x20);
                }
            }
        }

        return;
    }

    ULTIMA_1850_PrintString(/*0x8dda*/ "Not here!\n");
}

// CHECKED (loop)
void SJOG_18ce_GetCmd(void)
{
    int local_10;
    int local_c;
    int local_a;
    int local_e;
    int local_8;
    int local_6;
    int local_4;

    if (D_5893_map_id > 0x20 && D_5893_map_id < 0x29)
    {
        SJOG_179e();
        return;
    }

    if (ULTIMA_35ec_SelectDirection() == 0)
    {
        return;
    }

    local_c = D_5876;
    local_10 = D_5878;
    local_a = local_c + D_5896_map_x;
    local_e = local_10 + D_5897_map_y;
    ULTIMA_1850_PrintString(/*0x8de6*/ "\n");

    // 1921 (NOT MATCHING: loop)
    for (local_6 = 1; local_6 < 0x20; local_6++)
    {
        if (D_5c5a[local_6]._2_x == local_a && D_5c5a[local_6]._3_y == local_e &&
            (D_5893_map_id > 0x7f || (D_5893_map_id < 0x80 && D_5c5a[local_6]._4_z == D_5895_map_level)))
        {
            local_8 = D_5c5a[local_6]._0_tile;
            if (local_8 < 0x10 || local_8 == 0x19 || local_8 == 0x1b || (local_8 & 0xfc) == 0xb4)
                break;
        }
    }

    // 197f (NOT MATCHING)
    if (local_6 < 0x20)
    {
        local_4 = D_5c5a[local_6]._5;
        SJOG_1458(local_8, local_4, local_6);
        return;
    }

    // 19c0
    local_8 = *ULTIMA_4402_GetTileAddr(local_a, local_e);
    switch (local_8)
    {
    case 0xb0:
    case 0xb1:
        // 19e8
        *ULTIMA_4402_GetTileAddr(local_a, local_e) = 0x44;
        D_24e6 = 1;
        if (D_5893_map_id < 0x80)
        {
            ULTIMA_5e4a();
        }
        D_58a7 = 100;
        ULTIMA_1850_PrintString(/*0x8de8*/ "Borrowed!\n");
        ULTIMA_43ae_AudioSweepTone(800, 2000, 1, 0x32);
        ULTIMA_5910_UpdateFrame();
        break;

    case 0x2d:
        // 1a2a
        *ULTIMA_4402_GetTileAddr(local_a, local_e) = 0x2c;
        D_24e6 |= 2;
        ULTIMA_1850_PrintString(/*0x8df4*/ "Crops picked!\n");

        ULTIMA_3f14(&D_57a8, 1, 9999);

        D_a9fa = 1;

        if (D_5888 != 0)
        {
            D_5888--;
        }
        break;

    case 0x9a:
        // 1a6a
        if (local_10 == 1)
        {
            *ULTIMA_4402_GetTileAddr(local_a, local_e) = 0x95;
            D_24e6 |= 2;
            ULTIMA_1850_PrintString(/*0x8e04*/ "Mmmmm...!\n");

            ULTIMA_3f14(&D_57a8, 1, 9999);

            D_a9fa = 1;

            if (D_5888 != 0)
            {
                D_5888--;
            }
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x8e10*/ "Can't reach plate!\n");
        }

        break;

    case 0x9b:
        // 1a92
        if (local_10 == -1)
        {
            *ULTIMA_4402_GetTileAddr(local_a, local_e) = 0x95;
            D_24e6 |= 2;
            ULTIMA_1850_PrintString(/*0x8e24*/ "Mmmmm...!\n");

            ULTIMA_3f14(&D_57a8, 1, 9999);
            if (D_5888 != 0)
            {
                D_5888--;
            }
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x8e30*/ "Can't reach plate!\n");
        }

        break;

    case 0x9c:
        // 1aca
        if (local_c == 1 || local_c == -1)
        {
            ULTIMA_1850_PrintString(/*0x8e44*/ "Can't reach plate!\n");
            break;
        }

        if (local_10 == 1)
        {
            *ULTIMA_4402_GetTileAddr(local_a, local_e) = 0x9b;
        }

        if (local_10 == -1)
        {
            *ULTIMA_4402_GetTileAddr(local_a, local_e) = 0x9a;
        }

        D_24e6 |= 2;
        ULTIMA_1850_PrintString(/*0x8e58*/ "Mmmmm...!\n");

        ULTIMA_3f14(&D_57a8, 1, 9999);
        if (D_5888 != 0)
        {
            D_5888--;
        }

        break;

    default:
        // 1b28
        ULTIMA_1850_PrintString(/*0x8e64*/ "Nothing to get!\n");
        break;
    }
}

// OK P1
int SJOG_1b34(int param_1)
{
    int local_4;
    int local_6;

    local_6 = 0;

    for (local_4 = 0; local_4 < D_585b; local_4++)
    {
        if (ULTIMA_6e60(local_4, param_1) != 0)
        {
            local_6++;
        }
    }

    return local_6;
}

// OK P1
void SJOG_1b6c(void)
{
    int local_4;
    int local_6;

    D_5876 = D_5878 = 0;

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        if (D_ba14[local_4]._2 != 0 && (D_ba14[local_4]._2 & 0x20) == 0)
        {
            local_6 = ULTIMA_5646(local_4);
            if (local_6 != 0)
            {
                D_5876++;
            }
            else
            {
                D_5878++;
            }
        }
    }
}

// OK P1
// combat exit
static int SJOG_1bb2_CombatExit(int param_1, int param_2)
{
    if ((D_587c & 0xf8) == 0x20)
    {
        ULTIMA_1850_PrintString("\nStay with ship!\n");
        return 0;
    }

    if ((D_ba14[param_1]._2 & 0x80) != 0)
    {
        if (D_58a0 == 0)
        {
            D_58a0 = param_2;
        }
        else if (param_2 != D_58a0 && (D_58a1 & 0x80) != 0)
        {
            ULTIMA_1850_PrintString("\nAll must use the same exit!\n");
            ULTIMA_22c0_AudioTone(0xa5, 200);
            return 0;
        }
    }

    D_589f = 1;
    SJOG_1b6c();
    if (D_5876 == 0)
    {
        ULTIMA_1850_PrintString("Leave!\n");
    }
    else
    {
        ULTIMA_1850_PrintString("Escape!\n");
    }

    ULTIMA_43ae_AudioSweepTone(0x4b0, 2000, 1, 0x28);
    D_587b = 0xff;
    COMBAT_1236(-param_1 - 1);
    ULTIMA_2900_UpdateVitalsDisplay();
    ULTIMA_5910_UpdateFrame();

    return 1;
}

// OK P1
// move player in combat
// param_1: combat entity idx, param_2: direction
int SJOG_1c56_CombatMovePlayer(int param_1, int param_2)
{
    int bVar1;
    int local_c;
    int local_a;
    int local_6;
    int local_4;

    local_a = local_c = 0;
    bVar1 = D_ba14[param_1]._4;

    switch (param_2)
    {
    case 3:
        local_c = -1;
        ULTIMA_1850_PrintString(/*0x8eb8*/ "North\n");
        break;
    case 4:
        local_c = 1;
        ULTIMA_1850_PrintString(/*0x8ec0*/ "South\n");
        break;
    case 2:
        local_a = 1;
        ULTIMA_1850_PrintString(/*0x8ec8*/ "East\n");
        break;
    case 1:
        local_a = -1;
        ULTIMA_1850_PrintString(/*0x8ece*/ "West\n");
        break;
    }

    local_4 = D_ba14[param_1]._6 + local_a;
    local_6 = D_ba14[param_1]._7 + local_c;
    if (local_4 > 0xa || local_6 > 0xa || local_4 < 0 || local_6 < 0)
    {
        return SJOG_1bb2_CombatExit(param_1, param_2);
    }

    if (COMBAT_0000(D_5c5a[bVar1]._0_tile, local_4, local_6) != 0)
    {
        D_5c5a[bVar1]._2_x = D_ba14[param_1]._6 = local_4;
        D_5c5a[bVar1]._3_y = D_ba14[param_1]._7 = local_6;

        ULTIMA_433e_AudioWalkStep();
        if ((D_58a1 & 0x82) != 0)
        {
            COMBAT_111a(local_a, local_c);
        }

        return 1;
    }
    else
    {
        ULTIMA_1850_PrintString("Blocked!\n");
        ULTIMA_22c0_AudioTone(0xa5, 200);
        ULTIMA_1b16_ClearKbdBuffer();
        return 0;
    }
}

// CHECKED
// klimb in combat
int SJOG_1d6a_CombatKlimb(void)
{
    int local_c;
    int local_a;
    int local_4;
    int local_8;
    ActorFmt* local_6;

    ULTIMA_1850_PrintString(/*0x8ede*/ "Klimb-");

    local_4 = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);

    if ((D_58a1 & 2) != 0 && local_4 == 0xc8 && D_bb16 != 0)
    {
        ULTIMA_1850_PrintString(/*0x8ee6*/ "U/D-");
        do
        {
            local_c = ULTIMA_266c_GetChar();
            switch (local_c)
            {
            case 4:
            case 0x44:
                // dd48
                local_4 = 0xc9;
                break;

            case 3:
            case 0x55:
                // -> dd4b
                break;

            default:
                // dd44
                local_c = 0;
                break;
            }
            // dd4b
        } while (local_c == 0);
    }

    if (local_4 == 0xc8)
    {
        ULTIMA_1850_PrintString(/*0x8eec*/ "Up!\n");

        return SJOG_1bb2_CombatExit(D_589e, 5);
    }

    if ((local_4 == 0x86 && (D_58a1 & 0x80) != 0) || local_4 == 0xc9)
    {
        ULTIMA_1850_PrintString(/*0x8ef2*/ "Down!\n");

        return SJOG_1bb2_CombatExit(D_589e, 6);
    }

    if (ULTIMA_35ec_SelectDirection() != 0)
    {
        local_8 = D_5896_map_x + D_5876;
        local_a = D_5897_map_y + D_5878;
        if (*ULTIMA_4402_GetTileAddr(local_8, local_a) == 0x4c && ULTIMA_3702(local_8, local_a, 0) == 0)
        {
            local_6 = &D_5c5a[D_ba14[D_589e]._4];
            local_6->_2_x = D_ba14[D_589e]._6 = local_8;
            local_6->_3_y = D_ba14[D_589e]._7 = local_a;

            COMBAT_111a(local_8, local_a);
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x8efa*/ "What?\n");
            return 0;
        }
    }

    return 1;
}

// OK P1
// endgame sub
void SJOG_1ea4(void)
{
    CombatEntity* local_4;

    local_4 = &D_ba14[D_589e];

    if (local_4->_2 != 0 && (local_4->_2 & 0x20) == 0 && local_4->_7 == 2 &&
        (D_ac64[local_4->_6 + 0x10] & 0xfc) == 0x3c)
    {
        D_58a0 = 0x4d;
        ULTIMA_16ba_PrintChar(10);
        COMSUBS_0094(D_589e);
        ULTIMA_1850_PrintString(" is absorbed!\n");
        ULTIMA_43ae_AudioSweepTone(0x4b0, 2000, 1, 0x28);
        D_587b = 0xff;
        ULTIMA_2900_UpdateVitalsDisplay();
        COMBAT_1236(-D_589e - 1);
        ULTIMA_5910_UpdateFrame();
    }
}

// OK P1
// combat_command_misc
int SJOG_1f26_CombatMiscCmd(char* param_1, int param_2)
{
    ULTIMA_1850_PrintString(param_1);

    switch (param_2)
    {
    case 1:
        ULTIMA_1850_PrintString(/*0x8f12*/ " what?");
        break;
    case 2:
        ULTIMA_1850_PrintString(/*0x8f1a*/ "-Not here");
        break;
    case 3:
        ULTIMA_1850_PrintString(/*0x8f24*/ "-Funny, no response!");
        break;
    }

    ULTIMA_16ba_PrintChar(10);
    ULTIMA_22c0_AudioTone(0xdc, 0x96);
    ULTIMA_22c0_AudioTone(0x96, 0x96);

    return 1;
}

// OK P1
int SJOG_1f7a_CombatSetActivePlayer(int param_1)
{
    int local_8;
    int local_6;
    int local_4;

    local_8 = 0;
    ULTIMA_1850_PrintString(/*0x8f3a*/ "Set active plr:\n");
    
    for (local_6 = 0; local_6 < 0x20; local_6++)
    {
        local_4 = D_ba14[local_6]._2;

        if ((local_4 & 0x80) != 0)
        {
            if (ULTIMA_5646(local_6) == 0 && D_ba14[local_6]._3 == param_1)
            {
                if ((local_4 & 0x2c) != 0)
                {
                    local_8 = 0;
                }
                else
                {
                    local_8 = 1;
                }

                break;
            }
        }
    }

    if (local_8 != 0)
    {
        D_587b = param_1;
        COMSUBS_0094(local_6);
        ULTIMA_16ba_PrintChar(10);
        ULTIMA_2900_UpdateVitalsDisplay();
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x8f4c*/ "Invalid!\n");
    }

    return local_8;
}

// OK P1
void SJOG_2012(void)
{
    ULTIMA_6794(D_589e);
    COMSUBS_0056();

    if (D_588e != 0 && D_588e != 0xff)
    {
        if (--D_588e == 0)
        {
            D_587a = 0;
            D_a9fa = 1;
        }
    }
}

// CHECKED
void SJOG_203e(int param_1)
{
    int local_6;

    ActorFmt* local_4;

    if (D_58a0 == 0x4d)
    {
        ENDGAME_0648_EndgameMain();
    }

    for (local_6 = 0; local_6 < 0x20; local_6++)
    {
        D_5c5a[local_6] = D_a9fc[local_6];
    }

    if ((D_58a1 & 0x82) == 0)
    {
        if (param_1 < 0x20)
        {
            local_4 = &D_5c5a[param_1];

            if (D_58a3 != 0 && (local_4->_0_tile & 0xfc) == 0x2c)
            {
                local_4->_0_tile -= 8;
                local_4->_1 -= 8;
                local_4->_5 = 99;
                local_4->_7 = 2;
            }
            else
            {
                local_4->_0_tile = local_4->_1 = local_4->_2_x = local_4->_3_y = local_4->_4_z = 0;
            }
        }

        ULTIMA_16ba_PrintChar(10);
        D_5893_map_id = D_5894;
    }
}

// OK P1
int SJOG_20d8(int param_1, int param_2, int param_3)
{
    int local_6;
    CombatEntity* local_4;

    local_6 = 1;
    local_4 = &D_ba14[param_3];

    if (param_1 > -1 && param_1 < 11 && param_2 > -1 && param_2 < 11)
    {
        local_6 = COMBAT_0000(D_5c5a[local_4->_4]._0_tile, param_1, param_2);
        local_6 = 1 - local_6;
    }
    else
    {
        if ((local_4->_2 & 2) != 0)
        {
            local_6 = 0;
        }
    }

    return local_6;
}

// CHECKED
int SJOG_2148(int param_1)
{
    int local_c;
    int local_a;
    int local_8;
    int local_6;
    CombatEntity* local_4;

    local_6 = 0;
    local_4 = &D_ba14[param_1];

    local_8 = local_4->_6;
    local_a = local_4->_7;

    for (local_c = 0; local_c < 4; local_c++)
    {
        switch (local_c)
        {
        case 0:
            local_a++;
            break;
        case 2:
            // bug?
            local_8--;
            local_8--;
            break;
        case 1:
        case 3:
            local_a--;
            local_8++;
            break;
        }

        if (SJOG_20d8(local_8, local_a, param_1) != 0)
        {
            local_6++;
        }
    }

    return local_6 == 4;
}

// CHECKED
int SJOG_21ce(void)
{
    int local_4;

    for (local_4 = 0; local_4 < 6; local_4++)
    {
        if ((D_ba14[local_4]._2 & 1) != 0 && (D_ba14[local_4]._2 & 0x80) != 0)
        {
            D_ba14[local_4]._2 &= 0xfe;

            ULTIMA_1850_PrintString(D_55a8_party[D_ba14[local_4]._3]._0);
            ULTIMA_1850_PrintString(" passes out!");
            ULTIMA_2192_AudioPulse(0xc1c, 1, 30000, 1000, 2);
            ULTIMA_6e60(D_ba14[local_4]._3, 0x23);
            ULTIMA_68ae(local_4);

            if (local_4 == 6)
                local_4 = -1;

            return local_4;
        }
    }

    if (local_4 == 6)
        local_4 = -1;

    return local_4;
}
