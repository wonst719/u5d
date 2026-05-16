#include "common/common.h"
#include "funcs.h"
#include "vars.h"

#include "combat.h"
#include "comsubs.h"
#include "dungeon.h"
#include "town.h"

void ULTIMA_6794(int param_1);

void ENDGAME_0648_EndgameMain(void);

// OK P1
int SJOG_0000(void)
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
void SJOG_002a(int param_1, int param_2, int param_3)
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

// CHECKED
int SJOG_006c(int param_1)
{
    int local_4;
    byte local_6;

    ULTIMA_1850_PrintString(/*0x84e6*/ "Dir-");

    // NOT MATCHING
    while (1)
    {
        local_6 = ULTIMA_266c_GetChar();
        if (local_6 == ' ')
            break;
        if (local_6 == 3 || local_6 == 4 || local_6 == 2 || local_6 == 1)
            break;
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
void SJOG_012a(int param_1)
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
void SJOG_01f2(int param_1, int param_2)
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
void SJOG_02ea(int param_1, int param_2)
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
int SJOG_03a8(int param_1, int param_2, int param_3)
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
int SJOG_045a(int param_1, int param_2)
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
void SJOG_0514(int param_1, int param_2)
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
void SJOG_0646(void)
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
    local_e = D_595a[(uint)D_5895_map_level * 0x40 + (local_c & 7) * 8 + (local_a & 7)];
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
            D_595a[D_5895_map_level * 0x40 + (local_c & 7) * 8 + (local_a & 7)] = (local_e & 0x8) + 0x60;
            if (D_5895_map_level < 7)
            {
                D_595a[D_5895_map_level * 0x40 + (local_c & 7) * 8 + (local_a & 7) + 0x40] |= 8;
            }

            DUNGEON_1a90(1);
            ULTIMA_0f46_GRAP_66_Reveal(8, 8, 0xb7, 0xb7);
            break;

        case 0x62:
            // 07c6
            if (local_6 < ULTIMA_2092_RandomRange(1, 0x1e))
            {
                ULTIMA_1850_PrintString(/*0x87aa*/ "A bomb trap!\n");
                D_595a[D_5895_map_level * 0x40 + (local_c & 7) * 8 + (local_a & 7)] &= 8;
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

            D_595a[D_5895_map_level * 0x40 + (local_c & 7) * 8 + (local_a & 7)] = (local_e & 8) - 0x50;
            DUNGEON_1a90(1);
            ULTIMA_0f46_GRAP_66_Reveal(8, 8, 0xb7, 0xb7);
            break;
        }
        break;

    case 0xd0:
        // 08c2
        ULTIMA_1850_PrintString(/*0x88fe*/ "A hidden door!\n");

        D_595a[D_5895_map_level * 0x40 + (local_c & 7) * 8 + (local_a & 7)] = (local_e & 8) - 0x20;
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
    local_e = ULTIMA_4988();
    if (local_e == -1)
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

// CHECKED
void SJOG_0baa(int a, int b, int c, int param_4)
{
    byte local_4;
    byte local_6;
    int local_8;

    local_8 = ULTIMA_4988();
    if (local_8 != -1) // NOT MATCHING: INC AX vs CMP AX, -1
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

// NOT MATCHING
void SJOG_0c3e(void)
{
    byte bVar1;
    byte bVar2;
    byte bVar3;
    byte bVar4;
    byte bVar5;
    int iVar6;

    ULTIMA_1850_PrintString(/*0x8a7a*/ "\n");
    iVar6 = ULTIMA_4988();
    if (iVar6 == -1)
    {
        return;
    }

    bVar1 = D_5896_map_x;
    bVar2 = D_5897_map_y;
    bVar3 = D_5895_map_level;
    bVar4 = D_595a[(uint)bVar3 * 0x40 + (bVar2 & 7) * 8 + (bVar1 & 7)];
    bVar5 = D_55a8_party[iVar6]._d;

    if ((bVar4 & 0xf7) == 0x40)
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
    else if ((bVar4 & 0xf0) == 0x40)
    {
        if (D_57ac == 0)
        {
            ULTIMA_1850_PrintString(/*0x8a92*/ "No keys!\n");
        }
        else
        {
            if (((bVar3 * 2 - bVar5 + 0x1e) >> 1) < ULTIMA_2092_RandomRange(1, 0x1e))
            {
                ULTIMA_1850_PrintString(/*0x8a9c*/ "Chest unlocked\n");
                D_595a[D_5895_map_level * 0x40 + (bVar2 & 7) * 8 + (bVar1 & 7)] = (bVar4 & 8) + 0x40;
            }
            else
            {
                ULTIMA_1850_PrintString(/*0x8aac*/ "Key broke!\n");
                D_57ac--;
            }
        }
    }
    else if ((bVar4 & 0xf0) == 0x70)
    {
        ULTIMA_1850_PrintString(/*0x8ab8*/ "Already open!\n");
    }
    else
    {
        ULTIMA_1850_PrintString(/*0x8ac8*/ "What?\n");
    }
}

// NOT MATCHING
void SJOG_0d4a_JimmyCmd(void)
{
    byte bVar1;
    int uVar2;
    int iVar3;
    uint uVar4;
    uint uVar5;

    if (D_5893_map_id > 0x20 && D_5893_map_id < 0x29)
    {
        SJOG_0c3e();
        return;
    }

    if (D_57ac == 0)
    {
        ULTIMA_1850_PrintString(/*0x8ad0*/ "No Keys!\n");
        return;
    }
    else
    {
        iVar3 = ULTIMA_35ec_SelectDirection();
        if (iVar3 == 0)
        {
            return;
        }
        uVar4 = (uint)D_5896_map_x + D_5876;
        uVar5 = (uint)D_5897_map_y + D_5878;
        bVar1 = *ULTIMA_4402_GetTileAddr(uVar4, uVar5);
        if (bVar1 >= 0x99)
        {
            if (bVar1 == 0xb9 || bVar1 == 0xbb)
            {
                iVar3 = ULTIMA_4988();
                if (iVar3 == -1)
                {
                    return;
                }

                if (D_55a8_party[iVar3]._d <= ULTIMA_2092_RandomRange(0, 0x1d))
                {
                    ULTIMA_1850_PrintString(/*0x8ada*/ "Key broke!\n");
                    D_57ac--;
                    return;
                }

                *ULTIMA_4402_GetTileAddr(uVar4, uVar5) = bVar1 - 1;
                D_24e6 |= 2;
                ULTIMA_1850_PrintString(/*0x8ae6*/ "Unlocked!\n");
                return;
            }
        }
        else
        {
            if (bVar1 > 0x96)
            {
                ULTIMA_1850_PrintString(/*0x8af2*/ "Key broke!\n");
                D_57ac = D_57ac + -1;
                return;
            }

            if (bVar1 > 0x83 && bVar1 < 0x86)
            {
                if (D_5893_map_id < 0x80 && ULTIMA_368e_FindNpcTileAtPos(uVar4, uVar5, D_5895_map_level) == 0)
                {
                    ULTIMA_1850_PrintString(/*0x8afe*/ "No one is there!\n");
                    return;
                }
                else
                {
                    uVar2 = D_5876;
                    iVar3 = ULTIMA_4988();
                    if (iVar3 == -1)
                    {
                        return;
                    }

                    if (D_55a8_party[iVar3]._d <= ULTIMA_2092_RandomRange(0, 0x1d))
                    {
                        ULTIMA_1850_PrintString(/*0x8b10*/ "Key broke!\n");
                        return;
                    }

                    if (D_5893_map_id < 0x7f)
                    {
                        iVar3 = TOWN_011e(uVar2);
                        if (iVar3 == -1)
                        {
                            ULTIMA_1850_PrintString(/*0x8b1c*/ "Couldn't find this npc\n\n");
                            return;
                        }
                        else
                        {
                            if (D_5f5e[iVar3]._a != 0)
                            {
                                D_5f5e[iVar3]._a = 0;
                            }

                            if (TOWN_0000(iVar3) == 0)
                            {
                                D_5d5e[iVar3]._0[0] = 5;
                                D_5d5e[iVar3]._0[1] = 5;
                                D_5d5e[iVar3]._0[2] = 5;
                                ULTIMA_1850_PrintString(/*0x8b36*/ "\n\"I thank thee!\"\n");
                                ULTIMA_3ef0(&D_5888, 2, 99);
                            }

                            TOWN_0052(iVar3);
                            return;
                        }
                    }
                    else
                    {
                        *ULTIMA_4402_GetTileAddr(uVar4, uVar5) = 0x44;
                        D_24e6 |= 2;
                        ULTIMA_1850_PrintString(/*0x8b48*/ "Unlocked\n");
                        return;
                    }
                }
            }
        }

        for (iVar3 = 1; iVar3 < 0x20; iVar3++)
        {
            if (D_5c5a[iVar3]._2_x == uVar4 && D_5c5a[iVar3]._3_y == uVar5 &&
                (D_5893_map_id > 0x7f || D_5c5a[iVar3]._4_z == D_5895_map_level) && D_5c5a[iVar3]._0_tile == 1)
                break;
        }

        if (iVar3 < 0x20)
        {
            SJOG_0baa(uVar4, uVar5, D_5895_map_level, iVar3);
            return;
        }

        ULTIMA_1850_PrintString(/*0x8b52*/ "No lock!\n");
    }
}

// NOT MATCHING
void SJOG_0f88(int param_7, int param_6, int param_5, int param_4, int param_3, int param_2, int* param_1)
{
    int iVar1;

    if (param_7 == 3 || param_7 == 4)
    {
        param_6--;
    }

    if (param_7 != 1)
    {
        if (param_7 != 2)
            goto LAB_0000_0fc9;
        param_2 = param_2 * 3;
    }

    param_6 = ULTIMA_2092_RandomRange(1, param_2);
LAB_0000_0fc9:
    iVar1 = SJOG_0000();
    if (iVar1 != 0)
    {
        ULTIMA_3a74(param_7, param_7, param_5, param_4, param_3, param_6, iVar1);
        if (D_5893_map_id < 0x80)
        {
            D_5c5a[iVar1]._7 = 0;
            D_5c5a[iVar1]._4_z = (undefined1)param_3;
        }
        else
        {
            D_5c5a[iVar1]._7 = 0x20;
        }
        D_24e6 = D_24e6 | 2;
        ULTIMA_5910_UpdateFrame();
        if (*param_1 == 0)
        {
            ULTIMA_1850_PrintString("Found:\n");
            *param_1 = 1;
        }
        SJOG_012a(param_7);
    }
}

// NOT MATCHING
void SJOG_1040(uint param_5, int param_4, int param_3, int param_2, int* param_1)
{
    uint uVar1;
    int iVar2;
    int uVar4;
    int iVar3;

    iVar2 = 8;
    while (iVar3 = iVar2, iVar2 = iVar3 - 1, 0 <= iVar2)
    {
        if (*(iVar3 - 1 + D_412c) <= param_5)
        {
            uVar1 = ULTIMA_2092_RandomRange(1, 0x1e);
            if (*(iVar3 - 1 + D_412c) <= uVar1)
            {
                if (*(iVar3 - 1 + D_4134) == 1)
                {
                    uVar4 = 1;
                }
                else
                {
                    uVar4 = ULTIMA_2092_RandomRange(1, *(iVar3 - 1 + D_4134));
                }
                SJOG_0f88(*(iVar3 - 1 + D_4124), uVar4, param_4, param_3, param_2, param_5, param_1);
            }
        }
    }
}

// NOT MATCHING
void SJOG_10b8(uint param_5, int param_4, int param_3, int param_2, int* param_1)
{
    int iVar1;
    int iVar2;
    uint uVar3;
    int uStack_4;

    uStack_4 = (int)param_5 / 2;
    while (iVar1 = uStack_4 - 1, 0 <= uStack_4)
    {
        iVar2 = ULTIMA_2092_RandomRange(0, 0x2f);
        uStack_4 = iVar1;
        if (D_416c[iVar2] <= param_5)
        {
            uVar3 = ULTIMA_2092_RandomRange(1, 0x1e);
            if (D_416c[iVar2] <= uVar3)
            {
                SJOG_0f88(D_413c[iVar2], iVar2, param_4, param_3, param_2, param_5, param_1);
            }
        }
    }
}

// NOT MATCHING
// Open sub
void SJOG_112c(uint param_3, uint param_2, uint param_1)
{
    uint uVar4;
    int local_a;
    byte bStack_8;
    int iStack_6;

    local_a = 0;
    iStack_6 = 1;
    do
    {
        if (D_5c5a[iStack_6]._2_x == param_3 && D_5c5a[iStack_6]._3_y == param_2 &&
            (0x7f < D_5893_map_id || (D_5893_map_id < 0x80 && D_5c5a[iStack_6]._4_z == param_1)))
        {
            if (D_5c5a[iStack_6]._0_tile == 1)
                break;
            if (D_5c5a[iStack_6]._0_tile == '\x0e')
            {
                ULTIMA_1850_PrintString("Can't!\n");
                return;
            }
        }
    } while (++iStack_6 < 0x20);

    if (iStack_6 == 0x20)
    {
        ULTIMA_1850_PrintString("Nothing to open!\n");
    }
    else
    {
        uVar4 = ULTIMA_4988();
        if (uVar4 == -1)
        {
            return;
        }
        bStack_8 = D_5c5a[iStack_6]._5;
        ULTIMA_3a74(0, 0, 0, 0, 0, 0, iStack_6);
        D_24e6 = D_24e6 | 2;
        if (D_5893_map_id != 0 && D_5893_map_id < 0x21)
        {
            if (D_5888 < 3)
            {
                D_5888 = 0;
            }
            else
            {
                D_5888 -= 2;
            }
        }

        if (0x7f < bStack_8)
        {
            bStack_8 = bStack_8 & 0x7f;
            ULTIMA_1850_PrintString("Trapped!\n");
            ULTIMA_2fd0(uVar4);
            if (0x7f < D_5893_map_id && D_55a8_party[uVar4]._b == 'D')
            {
                iStack_6 = 0;
                do
                {
                    if ((D_ba14[iStack_6]._2 & 0x80) != 0 && D_ba14[iStack_6]._3 == uVar4)
                    {
                        D_ba14[iStack_6]._2 |= 0x20;

                        D_5c5a[D_ba14[iStack_6]._4]._1 = 0x1e;
                        D_5c5a[D_ba14[iStack_6]._4]._0_tile = 0x1e;
                        break;
                    }
                } while (++iStack_6 < 32);

                if (uVar4 == D_587b)
                {
                    D_587b = 0xff;
                }
                ULTIMA_5910_UpdateFrame();
            }
        }
        SJOG_1040(bStack_8, param_3, param_2, param_1, &local_a);
        SJOG_10b8(bStack_8, param_3, param_2, param_1, &local_a);
        if (local_a != 0)
        {
            return;
        }
        ULTIMA_1850_PrintString("Chest empty!\n");
    }
}

// NOT MATCHING
void SJOG_12d4(void)
{
    byte bVar1;
    int iVar2;

    bVar1 = D_595a[(uint)D_5895_map_level * 0x40 + (D_5897_map_y & 7) * 8 + (D_5896_map_x & 7)];
    if ((bVar1 & 0xf0) == 0x40)
    {
        iVar2 = ULTIMA_4988();
        if (iVar2 == -1)
        {
            return;
        }
        if ((bVar1 & 7) != 0)
        {
            ULTIMA_2fd0(iVar2);
        }
        D_595a[(uint)D_5895_map_level * 0x40 + (D_5897_map_y & 7) * 8 + (D_5896_map_x & 7)] = (bVar1 & 8) + 0x70;
        ULTIMA_1850_PrintString("\nChest opened\n");
    }
    else if ((bVar1 & 0xf0) == 0x70)
    {
        ULTIMA_1850_PrintString("Already Open!\n");
    }
    else
    {
        ULTIMA_1850_PrintString("What?\n");
    }
}

// NOT MATCHING
void SJOG_1374_OpenCmd(void)
{
    byte bVar1;
    int iVar2;
    int iVar3;

    if (0x20 < D_5893_map_id && D_5893_map_id < 0x29)
    {
        SJOG_12d4();
        return;
    }
    ULTIMA_39cc_SetTile(D_594f, D_5950, D_5951);
    iVar2 = ULTIMA_35ec_SelectDirection();
    if (iVar2 == 0)
    {
        return;
    }
    iVar2 = D_5896_map_x + D_5876;
    iVar3 = D_5897_map_y + D_5878;
    bVar1 = *ULTIMA_4402_GetTileAddr(iVar2, iVar3);

    // TODO: switch?
    if (bVar1 == 0xaf)
    {
        ULTIMA_1850_PrintString("It's open!\n");
        return;
    }
    if (bVar1 < 0xb0)
    {
        if (bVar1 < 0x97)
        {
        LAB_0000_1444:
            SJOG_112c(iVar2, iVar3, D_5895_map_level);
            return;
        }
        if (0x98 < bVar1)
        {
            if (bVar1 == 0x99)
            {
                ULTIMA_1850_PrintString("Too heavy!\n");
                return;
            }
            goto LAB_0000_1444;
        }
    }
    else
    {
        if (bVar1 == 0xb8)
        {
        LAB_0000_1400:
            D_594f = bVar1;
            D_5952 = 4;
            D_5950 = (undefined1)iVar2;
            D_5951 = (undefined1)iVar3;
            *ULTIMA_4402_GetTileAddr(iVar2, iVar3) = 0x44;
            D_24e6 = 1;
            ULTIMA_1850_PrintString("Opened!\n");
            return;
        }
        if (bVar1 != 0xb9)
        {
            if (bVar1 == 0xba)
                goto LAB_0000_1400;
            if (bVar1 != 0xbb)
                goto LAB_0000_1444;
        }
    }
    ULTIMA_1850_PrintString("Locked!\n");
}

// NOT MATCHING
void SJOG_1458(int param_1, int param_2, int param_3)
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
        if (param_2 >= 0x80)
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
        param_2 = param_2 & 3;
        ((undefined*)&D_57b6)[param_2] = 0xff;
        ULTIMA_1850_PrintString(/*0x8d0a*/ "The Shard of\n");
        if (param_2 == 0)
        {
            ULTIMA_1850_PrintString(/*0x8d18*/ "Falsehood!\n");
        }
        else if (param_2 == 1)
        {
            ULTIMA_1850_PrintString(/*0x8d24*/ "Hatred!\n");
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x8d2e*/ "Cowardice!\n");
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

// NOT MATCHING
void SJOG_179e(void)
{
    byte bVar2;
    uint uVar4;
    int iVar5;

    ULTIMA_1850_PrintString(/*0x8da4*/ "Get\n");

    bVar2 = D_595a[(uint)D_5895_map_level * 0x40 + (D_5897_map_y & 7) * 8 + (D_5896_map_x & 7)];
    if ((bVar2 & 0xf0) == 0x40)
    {
        ULTIMA_1850_PrintString(/*0x8daa*/ "Must open first!\n");
        return;
    }
    else
    {
        if ((bVar2 & 0xf0) == 0x70)
        {
            D_595a[(uint)D_5895_map_level * 0x40 + (D_5897_map_y & 7) * 8 + (D_5896_map_x & 7)] &= 8;

            ULTIMA_1850_PrintString(/*0x8dbc*/ "contents\nof chest\nYou find:\n");

            for (iVar5 = 0; iVar5 < 7; iVar5++)
            {
                if (D_41bc[iVar5] <= ULTIMA_2092_RandomRange(1, (uint)D_5895_map_level * 4 + 4))
                {
                    if (iVar5 == 5)
                    {
                        SJOG_1458(3, ULTIMA_2092_RandomRange(0, 7), 0x20);
                    }
                    else if (iVar5 == 6)
                    {
                        SJOG_1458(4, ULTIMA_2092_RandomRange(0, 7), 0x20);
                    }
                    else
                    {
                        if (iVar5 == 1)
                        {
                            uVar4 = (uint)D_5895_map_level << 3;
                        }
                        else
                        {
                            uVar4 = (uint)D_41c4[iVar5];
                        }

                        SJOG_1458(D_41cc[iVar5], ULTIMA_2092_RandomRange(1, uVar4), 0x20);
                    }
                }
            }

            return;
        }

        ULTIMA_1850_PrintString(/*0x8dda*/ "Not here!\n");
    }
}

// NOT MATCHING
void SJOG_18ce_GetCmd(void)
{
    int iVar1;
    byte bVar2;
    int iVar3;
    uint uVar4;
    uint uVar5;
    uint uStack_8;
    int iStack_6;

    if (D_5893_map_id > 0x20 && D_5893_map_id < 0x29)
    {
        SJOG_179e();
        return;
    }

    if (ULTIMA_35ec_SelectDirection() == 0)
    {
        return;
    }

    iVar3 = D_5876;
    iVar1 = D_5878;
    uVar4 = iVar3 + (uint)D_5896_map_x;
    uVar5 = iVar1 + (uint)D_5897_map_y;
    ULTIMA_1850_PrintString(/*0x8de6*/ "\n");

    for (iStack_6 = 1; iStack_6 < 0x20; iStack_6++)
    {
        if (D_5c5a[iStack_6]._2_x == uVar4 && D_5c5a[iStack_6]._3_y == uVar5 &&
            (0x7f < D_5893_map_id || (D_5893_map_id < 0x80 && D_5c5a[iStack_6]._4_z == D_5895_map_level)))
        {
            bVar2 = D_5c5a[iStack_6]._0_tile;
            uStack_8 = (uint)bVar2;
            if (bVar2 < 0x10 || uStack_8 == 0x19 || uStack_8 == 0x1b || (bVar2 & 0xfc) == 0xb4)
                break;
        }
    }

    if (iStack_6 < 0x20)
    {
        SJOG_1458(uStack_8, D_5c5a[iStack_6]._5, iStack_6);
        return;
    }

    bVar2 = *ULTIMA_4402_GetTileAddr(uVar4, uVar5);

    if (bVar2 == 0x9a)
    {
        if (iVar1 != 1)
        {
            ULTIMA_1850_PrintString(/*0x8e10*/ "Can't reach plate!\n");
            return;
        }

        *ULTIMA_4402_GetTileAddr(uVar4, uVar5) = 0x95;
        D_24e6 |= 2;
        ULTIMA_1850_PrintString(/*0x8e04*/ "Mmmmm...!\n");
    }
    else
    {
        if (bVar2 > 0x9a)
        {
            if (bVar2 == 0x9b)
            {
                if (iVar1 != -1)
                {
                    ULTIMA_1850_PrintString(/*0x8e30*/ "Can't reach plate!\n");
                    return;
                }

                *ULTIMA_4402_GetTileAddr(uVar4, uVar5) = 0x95;
                D_24e6 |= 2;
                ULTIMA_1850_PrintString(/*0x8e24*/ "Mmmmm...!\n");
                ULTIMA_3f14(&D_57a8, 1, 9999);

                if (D_5888 != 0)
                {
                    D_5888--;
                }

                return;
            }
            else
            {
                if (bVar2 != 0x9c)
                {
                    if (0xaf < bVar2 && bVar2 < 0xb2)
                    {
                        *ULTIMA_4402_GetTileAddr(uVar4, uVar5) = 0x44;
                        D_24e6 = 1;
                        if (D_5893_map_id < 0x80)
                        {
                            ULTIMA_5e4a();
                        }
                        D_58a7 = 100;
                        ULTIMA_1850_PrintString(/*0x8de8*/ "Borrowed!\n");
                        ULTIMA_43ae_AudioSweepTone(0x32, 1, 2000, 800);
                        ULTIMA_5910_UpdateFrame();
                        return;
                    }

                    ULTIMA_1850_PrintString(/*0x8e64*/ "Nothing to get!\n");
                    return;
                }

                if (iVar3 == 1 || iVar3 == -1)
                {
                    ULTIMA_1850_PrintString(/*0x8e44*/ "Can't reach plate!\n");
                    return;
                }

                if (iVar1 == 1)
                {
                    *ULTIMA_4402_GetTileAddr(uVar4, uVar5) = 0x9b;
                }

                if (iVar1 == -1)
                {
                    *ULTIMA_4402_GetTileAddr(uVar4, uVar5) = 0x9a;
                }

                D_24e6 |= 2;
                ULTIMA_1850_PrintString(/*0x8e58*/ "Mmmmm...!\n");
                ULTIMA_3f14(&D_57a8, 1, 9999);
                if (D_5888 != 0)
                {
                    D_5888--;
                }

                return;
            }
        }

        if (bVar2 != 0x2d)
        {
            ULTIMA_1850_PrintString(/*0x8e64*/ "Nothing to get!\n");
            return;
        }

        *ULTIMA_4402_GetTileAddr(uVar4, uVar5) = 0x2c;
        D_24e6 |= 2;
        ULTIMA_1850_PrintString(/*0x8df4*/ "Crops picked!\n");
    }

    ULTIMA_3f14(&D_57a8, 1, 9999);

    D_a9fa = 1;

    if (D_5888 != 0)
    {
        D_5888--;
    }
}

// NOT MATCHING
int SJOG_1b34(int param_1)
{
    int iVar1;
    uint uVar2;
    int iVar3;

    iVar3 = 0;

    for (uVar2 = 0; uVar2 < D_585b; uVar2++)
    {
        iVar1 = ULTIMA_6e60(uVar2, param_1);
        if (iVar1 != 0)
        {
            iVar3++;
        }
    }

    return iVar3;
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

// NOT MATCHING
int SJOG_1bb2(int param_2, int param_1)
{
    if ((D_587c & 0xf8) == 0x20)
    {
        ULTIMA_1850_PrintString("\nStay with ship!\n");
        return 0;
    }
    else
    {
        if ((D_ba14[param_2]._2 & 0x80) != 0)
        {
            if (D_58a0 == 0)
            {
                D_58a0 = param_1;
            }
            else if (param_1 != D_58a0 && (D_58a1 & 0x80) != 0)
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
        COMBAT_1236(-param_2 - 1);
        ULTIMA_2900_UpdateVitalsDisplay();
        ULTIMA_5910_UpdateFrame();
        return 1;
    }
}

// NOT MATCHING
int SJOG_1c56(int param_1, int param_2)
{
    byte bVar1;
    int uVar2;
    int iVar3;
    int uStack_c;
    int uStack_a;
    undefined1 uStack_6;
    undefined1 uStack_4;

    uStack_c = 0;
    uStack_a = 0;
    bVar1 = D_ba14[param_1]._4;

    switch (param_2)
    {
    case 1:
        uStack_a = -1;
        ULTIMA_1850_PrintString("West\n");
        break;
    case 2:
        uStack_a = 1;
        ULTIMA_1850_PrintString("East\n");
        break;
    case 3:
        uStack_c = -1;
        ULTIMA_1850_PrintString("North\n");
        break;
    case 4:
        uStack_c = 1;
        ULTIMA_1850_PrintString("South\n");
        break;
    }

    uStack_a = D_ba14[param_1]._6 + uStack_a;
    uStack_c = D_ba14[param_1]._7 + uStack_c;
    if (uStack_a < 0xb && uStack_c < 0xb && 0 <= uStack_a && 0 <= uStack_c)
    {
        iVar3 = COMBAT_0000(D_5c5a[bVar1]._0_tile, uStack_a, uStack_c);
        if (iVar3 == 0)
        {
            ULTIMA_1850_PrintString("Blocked!\n");
            ULTIMA_22c0_AudioTone(0xa5, 200);
            ULTIMA_1b16_ClearKbdBuffer();
            uVar2 = 0;
        }
        else
        {
            uStack_4 = (undefined1)uStack_a;
            D_ba14[param_1]._6 = uStack_4;
            D_5c5a[bVar1]._2_x = uStack_4;
            uStack_6 = (undefined1)uStack_c;
            D_ba14[param_1]._7 = uStack_6;
            D_5c5a[bVar1]._3_y = uStack_6;
            ULTIMA_433e_AudioWalkStep();
            if ((D_58a1 & 0x82) != 0)
            {
                COMBAT_111a(uStack_a, uStack_c);
            }
            uVar2 = 1;
        }
    }
    else
    {
        uVar2 = SJOG_1bb2(param_1, param_2);
    }

    return uVar2;
}

// NOT MATCHING
int SJOG_1d6a_Klimb(void)
{
    int iVar3;
    int uVar4;
    int iVar5;
    byte cVar8;

    ULTIMA_1850_PrintString(/*0x8ede*/ "Klimb-");

    cVar8 = *ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y);

    if ((D_58a1 & 2) != 0 && cVar8 == 0xc8 && D_bb16 != 0)
    {
        ULTIMA_1850_PrintString(/*0x8ee6*/ "U/D-");
        do
        {
            iVar3 = ULTIMA_266c_GetChar();
            if (iVar3 != 3)
            {
                if (iVar3 == 4 || iVar3 == 0x44)
                {
                    cVar8 = 0xc9;
                }
                else if (iVar3 != 0x55)
                {
                    iVar3 = 0;
                }
            }
        } while (iVar3 == 0);
    }

    if (cVar8 == 0xc8)
    {
        ULTIMA_1850_PrintString(/*0x8eec*/ "Up!\n");
        uVar4 = SJOG_1bb2(D_589e, 5);

        return uVar4;
    }
    else if ((cVar8 == 0x86 && (D_58a1 & 0x80) != 0) || cVar8 == 0xc9)
    {
        ULTIMA_1850_PrintString(/*0x8ef2*/ "Down!\n");
        uVar4 = SJOG_1bb2(D_589e, 6);

        return uVar4;
    }
    else
    {
        if (ULTIMA_35ec_SelectDirection() != 0)
        {
            iVar3 = (uint)D_5896_map_x + D_5876;
            iVar5 = (uint)D_5897_map_y + D_5878;
            if (*ULTIMA_4402_GetTileAddr(iVar3, iVar5) != 'L' || ULTIMA_3702(iVar3, iVar5, 0) != 0)
            {
                ULTIMA_1850_PrintString(/*0x8efa*/ "What?\n");
                return 0;
            }
            else
            {
                D_ba14[D_589e]._6 = iVar3;
                D_5c5a[D_ba14[D_589e]._4]._2_x = iVar3;
                D_ba14[D_589e]._7 = iVar5;
                D_5c5a[D_ba14[D_589e]._4]._3_y = iVar5;
                COMBAT_111a(iVar3, iVar5);
            }
        }

        return 1;
    }
}

// NOT MATCHING
void SJOG_1ea4(void)
{
    if (D_ba14[D_589e]._2 != 0 && (D_ba14[D_589e]._2 & 0x20) == 0 && D_ba14[D_589e]._7 == 2 &&
        (D_ac64[D_ba14[D_589e]._6 + 0x10] & 0xfc) == 0x3c)
    {
        D_58a0 = 0x4d;
        ULTIMA_16ba_PrintChar(10);
        COMSUBS_0094(D_589e);
        ULTIMA_1850_PrintString(" is absorbed!\n");
        ULTIMA_43ae_AudioSweepTone(0x4b0, 2000, 1, 0x28);
        D_587b = 0xff;
        ULTIMA_2900_UpdateVitalsDisplay();
        COMBAT_1236(-(uint)D_589e - 1);
        ULTIMA_5910_UpdateFrame();
    }
}

// NOT MATCHING
// combat_command_misc
int SJOG_1f26(char* param_1, int param_2)
{
    ULTIMA_1850_PrintString(param_1);

    if (param_2 == 1)
    {
        ULTIMA_1850_PrintString(" what?");
    }
    else if (param_2 == 2)
    {
        ULTIMA_1850_PrintString("-Not here");
    }
    else if (param_2 == 3)
    {
        ULTIMA_1850_PrintString("-Funny, no response!");
    }

    ULTIMA_16ba_PrintChar(10);
    ULTIMA_22c0_AudioTone(0xdc, 0x96);
    ULTIMA_22c0_AudioTone(0x96, 0x96);

    return 1;
}

// NOT MATCHING
int SJOG_1f7a(int param_1)
{
    byte bVar1;
    int iVar2;
    int iVar3;
    int iVar4;

    iVar3 = 0;
    ULTIMA_1850_PrintString(/*0x8f3a*/ "Set active plr:\n");
    
    for (iVar4 = 0; iVar4 < 0x20; iVar4++)
    {
        bVar1 = D_ba14[iVar4]._2;
        if ((bVar1 & 0x80) != 0)
        {
            iVar2 = ULTIMA_5646(iVar4);
            if (iVar2 == 0 && D_ba14[iVar4]._3 == param_1)
            {
                if ((bVar1 & 0x2c) == 0)
                {
                    iVar3 = 1;
                }
                else
                {
                    iVar3 = 0;
                }

                break;
            }
        }
    }

    if (iVar3 == 0)
    {
        ULTIMA_1850_PrintString(/*0x8f4c*/ "Invalid!\n");
    }
    else
    {
        D_587b = param_1;
        COMSUBS_0094(iVar4);
        ULTIMA_16ba_PrintChar(10);
        ULTIMA_2900_UpdateVitalsDisplay();
    }

    return iVar3;
}

// NOT MATCHING
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

// NOT MATCHING
void SJOG_203e(int param_1)
{
    int i;

    if (D_58a0 == 'M')
    {
        ENDGAME_0648_EndgameMain();
    }

    for (i = 0; i < 0x20; i++)
    {
        D_5c5a[i]._0_tile = D_a9fc[i]._0_tile;
        D_5c5a[i]._1 = D_a9fc[i]._1;
        D_5c5a[i]._2_x = D_a9fc[i]._2_x;
        D_5c5a[i]._3_y = D_a9fc[i]._3_y;
    }

    if ((D_58a1 & 0x82) == 0)
    {
        if (param_1 < 0x20)
        {
            if (D_58a3 == 0 || (D_5c5a[param_1]._0_tile & 0xfc) != 0x2c)
            {
                D_5c5a[param_1]._4_z = 0;
                D_5c5a[param_1]._3_y = 0;
                D_5c5a[param_1]._2_x = 0;
                D_5c5a[param_1]._1 = 0;
                D_5c5a[param_1]._0_tile = 0;
            }
            else
            {
                D_5c5a[param_1]._0_tile -= 8;
                D_5c5a[param_1]._1 -= 8;
                D_5c5a[param_1]._5 = 99;
                D_5c5a[param_1]._7 = 2;
            }
        }

        ULTIMA_16ba_PrintChar(10);
        D_5893_map_id = D_5894;
    }
}

// NOT MATCHING
int SJOG_20d8(int param_1, int param_2, int param_3)
{
    int local_4;

    local_4 = 1;
    if (param_1 <= -1 || param_1 >= 11 || param_2 <= -1 || param_2 >= 11)
    {
        if ((D_ba14[param_3]._2 & 2) != 0)
        {
            local_4 = 0;
        }
    }
    else
    {
        local_4 = COMBAT_0000(D_5c5a[D_ba14[param_3]._4]._0_tile, param_1, param_2);
        local_4 = 1 - local_4;
    }

    return local_4;
}

// NOT MATCHING
bool SJOG_2148(int param_1)
{
    uint uVar2;
    uint uVar3;
    int iVar4;
    int local_c;

    local_c = 0;
    uVar3 = D_ba14[param_1]._6;
    uVar2 = D_ba14[param_1]._7;

    for (iVar4 = 0; iVar4 < 4; iVar4++)
    {
        switch (iVar4)
        {
        case 0:
            uVar2++;
            break;
        case 1:
        case 3:
            uVar2--;
            uVar3++;
            break;
        case 2:
            uVar3 -= 2;
        }

        if (SJOG_20d8(uVar3, uVar2, param_1) != 0)
        {
            local_c++;
        }
    }

    return local_c == 4;
}

// NOT MATCHING
int SJOG_21ce(void)
{
    int local_4;

    for (local_4 = 0; local_4 < 6; local_4++)
    {
        if ((D_ba14[local_4]._2 & 1) == 0 || (D_ba14[local_4]._2 & 0x80) == 0)
        {
            continue;
        }
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

    if (local_4 == 6)
        local_4 = -1;

    return local_4;
}
