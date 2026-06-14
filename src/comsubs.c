#include "common/common.h"
#include "funcs.h"
#include "vars.h"
#include "macros.h"
#include "tiles.h"

#include <string.h>

#include "combat.h"
#include "comsubs.h"
#include "sjog.h"

// OK P1
int COMSUBS_0000(int param_1, int param_2, int param_3)
{
    int local_6;
    int local_4;

    if (param_3 == 0x30 || param_3 == 0x31 || param_3 >= 0x33)
        return 0;

    local_6 = COMBAT_13e2(param_1, QUERY_STAT_INTEL);
    local_4 = COMBAT_13e2(param_2, QUERY_STAT_INTEL);
    if (ULTIMA_3abe() < (local_4 + 0x1e - local_6) / 2)
    {
        return 1;
    }

    return 0;
}

// OK P1
void COMSUBS_0056(void)
{
    int iVar2;

    for (iVar2 = 0; iVar2 < 0x20; iVar2++)
    {
        if ((D_5c5a[iVar2]._0_tile & 0xfc) == TILE_ACTOR_E8)
        {
            if (ULTIMA_2092_RandomRange(0, 0xff) < 0x10)
            {
                COMBAT_1236(iVar2 + 1);
            }
        }
    }
}

// OK P1
void COMSUBS_0094(int param_1)
{
    if ((D_ba14[param_1].flags & COMBAT_FLAGS_PLAYER) != 0)
    {
        ULTIMA_1850_PrintString(D_55a8_party[D_ba14[param_1].entityIdx].name);
    }
    else
    {
        ULTIMA_1850_PrintString(D_1856[D_ba14[param_1].entityIdx]);
    }
}

// OK P1
static void COMSUBS_00d2(int param_1)
{
    if (D_588f != 0)
    {
        ULTIMA_1850_PrintString(/*0x99a0*/ "Failed!\n");
    }
    else
    {
        COMSUBS_0094(param_1);
        ULTIMA_1850_PrintString(/*0x99aa*/ " missed!\n");
    }
}

// OK P1
int COMSUBS_00f4(int param_1)
{
    int local_c;
    int local_4;
    int local_e;
    int local_6;
    int local_8;
    ActorFmt* local_a;

    local_4 = D_ba14[param_1].entityIdx;
    local_c = D_ba14[param_1].actorIdx;
    if (D_587a == 0x1c || D_587a == 'N' || (D_ba14[param_1].flags & COMBAT_FLAGS_PLAYER) != 0)
    {
        return 0;
    }

    if (((byte)D_153c[local_4] & 0x40) != 0)
    {
        local_e = ULTIMA_2092_RandomRange(0, 0x1f);

        local_6 = D_ba14[local_e].flags;
        if ((local_6 & COMBAT_FLAGS_PLAYER) != 0 &&
            (local_6 & (COMBAT_FLAGS_DEAD | COMBAT_FLAGS_INVISIBLE | COMBAT_FLAGS_ASLEEP | COMBAT_FLAGS_4 | COMBAT_FLAGS_CHARMED)) == 0)
        {
            if (COMSUBS_0000(param_1, local_e, 0) == 0)
            {
                ULTIMA_16ba_PrintChar(10);

                D_ba14[local_e].flags |= COMBAT_FLAGS_CHARMED;
                if (D_ba14[local_e].entityIdx == D_587b)
                {
                    D_587b = 0xff;
                }

                ULTIMA_2900_UpdateVitalsDisplay();
                COMSUBS_0094(local_e);
                ULTIMA_1850_PrintString(/*0x99b4*/ " possessed!\n");
                ULTIMA_2192_AudioPulse(0xc1c, 1, 30000, 1000, 2);
                if (local_4 == 0x26)
                {
                    COMBAT_1236(-param_1 - 1);
                }
            }

            return 1;
        }
    }

    if ((D_153c[local_4] & 0x800) != 0 && ULTIMA_2092_RandomRange(0, 0xff) < 0x20)
    {
        ULTIMA_16ba_PrintChar(10);
        COMSUBS_0094(param_1);
        if (D_5c5a[local_c]._1_animTile == 0)
        {
            ULTIMA_1850_PrintString(/*0x99c2*/ " reappears!");
            D_ba14[param_1].flags &= ~COMBAT_FLAGS_INVISIBLE;
            D_5c5a[local_c]._1_animTile = D_5c5a[local_c]._0_tile;
        }
        else
        {
            ULTIMA_1850_PrintString(/*0x99ce*/ " disappears!");
            D_ba14[param_1].flags |= COMBAT_FLAGS_INVISIBLE;
            D_5c5a[local_c]._1_animTile = 0;
        }

        return 1;
    }

    if ((D_153c[local_4] & 0x400) != 0 && ULTIMA_2092_RandomRange(0, 0xff) < 0x20)
    {
        if (COMBAT_120e() != 0)
        {
            if (COMBAT_0000(TILE_ACTOR_D8, D_5876, D_5878) != 0)
            {
                local_8 = ULTIMA_6506(0x26, 0, D_5876, D_5878, D_5895_map_level);
                if (local_8 != -1)
                {
                    ULTIMA_16ba_PrintChar(10);
                    COMSUBS_0094(param_1);
                    ULTIMA_1850_PrintString(/*0x99dc*/ " gates in a daemon!\n");
                    ULTIMA_2192_AudioPulse(0xac8, 1, 5000, 1000, 0xf);

                    local_a = &D_5c5a[D_ba14[local_8].actorIdx];

                    local_a->_0_tile = local_a->_1_animTile = TILE_ACTOR_CIRCLE;

                    ULTIMA_1068(0x1d8, D_5876, D_5878);

                    local_a->_0_tile = local_a->_1_animTile = TILE_ACTOR_D8;

                    return 1;
                }
            }
        }
    }

    return 0;
}

// OK P1
void COMSUBS_0312(int param_1, int param_2)
{
    int local_4;
    int local_6;
    int local_8; // unused
    
    local_4 = D_ba14[param_1].flags;
    D_58a2 &= 0xfe;
    if ((D_58a2 & 0x20) != 0)
    {
        COMSUBS_0094(param_1);
        ULTIMA_1850_PrintString(/*0x99f2*/ " grazed!\n");
        ULTIMA_43ae_AudioSweepTone(0x4b0, 2000, 1, 0x28);
    }

    if ((D_58a2 & 0x22) == 0)
    {
        if (local_4 == 0 || (local_4 & COMBAT_FLAGS_DEAD) != 0)
        {
            COMSUBS_0094(param_1);
            ULTIMA_1850_PrintString(/*0x99fc*/ " killed!\n");
            D_58a2 |= 1;
        }
        else if ((D_58a2 & 4) != 0)
        {
            COMSUBS_0094(param_1);
            ULTIMA_1850_PrintString(/*0x9a06*/ " slept!\n");
        }
        else if ((D_58a2 & 8) == 0)
        {
            COMSUBS_0094(param_1);
            if ((local_4 & COMBAT_FLAGS_PLAYER) != 0)
            {
                if (param_2 != 0xff && D_ba14[param_2].entityIdx == 0x2d)
                {
                    ULTIMA_1850_PrintString(/*0x9a10*/ " dragged under!\n");
                    ULTIMA_43ae_AudioSweepTone(0x4b0, 2000, 1, 0x28);
                    D_ba14[param_1].flags |= COMBAT_FLAGS_4;
                    D_5c5a[D_ba14[param_1].actorIdx]._1_animTile = 0;
                    ULTIMA_3ae6(4);
                }
                else
                {
                    ULTIMA_1850_PrintString(/*0x9a22*/ " hit!\n");
                }
            }
            else
            {
                local_6 = COMBAT_1a5c(param_1);
                switch (local_6)
                {
                case 4:
                    ULTIMA_1850_PrintString(/*0x9a2a*/ " barely wounded!\n");
                    break;
                case 3:
                    ULTIMA_1850_PrintString(/*0x9a3c*/ " lightly wounded!\n");
                    break;
                case 2:
                    ULTIMA_1850_PrintString(/*0x9a50*/ " heavily wounded!\n");
                    break;
                case 1:
                    ULTIMA_1850_PrintString(/*0x9a64*/ " critical!\n");
                    break;
                }
            }
        }

        if ((local_4 & COMBAT_FLAGS_PLAYER) != 0)
        {
            ULTIMA_2900_UpdateVitalsDisplay();
            ULTIMA_5910_UpdateFrame();
        }

        D_58a2 &= 0xf3;
    }
    else
    {
        D_58a2 &= 0xdd;
    }
}

// OK P1
static int COMSUBS_0458(int param_1, int param_2, int param_3, int param_4)
{
    int local_8 = param_1 - param_3;
    int local_6 = param_2 - param_4;
    int local_4 = local_8 * local_8 + local_6 * local_6;
    return local_4;
}

// OK P1
int COMSUBS_048a(int param_1, int param_2, int param_3, int param_4)
{
    int local_8;
    int local_6;
    int local_4;

    local_8 = 0;
    local_4 = 1;

    local_6 = 0;

    local_8 = COMSUBS_0458(param_1, param_2, param_3, param_4);

    for (; local_8 >= local_4;)
    {
        local_8 -= local_4;
        local_4++;
        local_4++;
        local_6++;
    }

    return local_6;
}

// OK P1
int COMSUBS_04d4(int param_1, int param_2)
{
    return COMSUBS_048a(D_ba14[param_1].x, D_ba14[param_1].y, D_ba14[param_2].x, D_ba14[param_2].y);
}

// OK P1
int COMSUBS_0504(int param_1, int param_2)
{
    int local_a;
    int local_e;
    int local_10;
    int local_12;
    int local_14;
    int local_c;
    int local_6;
    int local_4;
    ActorFmt* local_8;

    D_5898 = 1;
    local_c = D_5c5a[D_ba14[param_1].actorIdx]._7;
    local_8 = &D_5c5a[D_ba14[local_c].actorIdx];

    if (local_c > 0x1f || (D_ba14[local_c].flags & (COMBAT_FLAGS_DEAD | COMBAT_FLAGS_INVISIBLE)) != 0 || D_ba14[local_c].flags == 0 ||
        local_8->_0_tile == 0 || COMSUBS_04d4(param_1, local_c) > param_2)
    {
        // e742
        local_c = param_1;
    }

    // e748
    D_5899 = D_ba14[local_c].x;
    D_589a = D_ba14[local_c].y;

    local_a = local_e = 0;

    while (!local_a && !local_e)
    {
        // e816
        local_10 = local_12 = 0;

        ULTIMA_5910_UpdateFrame();

        switch (ULTIMA_266c_GetChar())
        {
        case U5_KEY_HOME: // 05c2
            local_10 = -1;
            local_12 = -1;
            break;

        case U5_KEY_PGDN: // 066c
            local_10 = 1;
            local_12 = 1;
            break;

        case U5_KEY_PGUP: // 0676
            local_12 = -1;
            local_10 = 1;
            break;

        case U5_KEY_END: // 0680
            local_12 = 1;
            local_10 = -1;
            break;

        case U5_KEY_UP: // 05c5
            local_12 = -1;
            break;

        case U5_KEY_DOWN: // 066f
            local_12 = 1;
            break;

        case U5_KEY_RIGHT: // 0679
            local_10 = 1;
            break;

        case U5_KEY_LEFT: // 0683
            local_10 = -1;
            break;

        case U5_KEY_SPACE: // 068a
            if ((D_ba14[param_1].x == D_5899) && (D_ba14[param_1].y == D_589a))
            {
                local_e = 1;
            }
            // fallthrough

        case U5_KEY_ENTER:  // 06a3
        case 0x41: // 06a3
            if (D_ba14[param_1].x != D_5899 || D_ba14[param_1].y != D_589a)
            {
                ULTIMA_16ba_PrintChar(10);
                if (D_588f != 0)
                {
                    ULTIMA_223c_AudioWhiteNoise(800, (uint)D_588f * 0x640 + 8000, 700);
                }
                local_a = 1;
            }
            break;

        case U5_KEY_ESC: // 06ea
            local_e = 1;
            //local_10 = local_12;
            break;
        }

        // 05c8
        local_4 = local_10 + D_5899;
        local_6 = local_12 + D_589a;

        local_14 = COMSUBS_048a(local_4, local_6, D_ba14[param_1].x, D_ba14[param_1].y);
        if (local_14 <= param_2 &&
            local_4 >= 0 && local_4 < 0xb &&
            local_6 >= 0 && local_6 < 0xb)
        {
            D_5899 = local_4;
            D_589a = local_6;
        }
    }

    D_5898 = 0;
    if (local_e)
    {
        ULTIMA_16ba_PrintChar(10);
        return 0;
    }

    return local_14;
}

// OK P1
int COMSUBS_0748(int param_1, int param_2)
{
    int local_6;
    int local_4; // flags
    int local_8;

    local_8 = -1;

    for (local_6 = 0; local_6 < 0x20; local_6++)
    {
        if (D_ba14[local_6].x == param_1 && D_ba14[local_6].y == param_2)
        {
            local_4 = D_ba14[local_6].flags;

            if (D_5c5a[D_ba14[local_6].actorIdx]._1_animTile != TILE_ACTOR_F4)
            {
                if ((local_4 & (COMBAT_FLAGS_PLAYER | COMBAT_FLAGS_MONSTER)) != 0 && (local_4 & COMBAT_FLAGS_DEAD) == 0)
                {
                    if ((local_4 & COMBAT_FLAGS_4) != 0)
                    {
                        // noop
                    }
                    else
                    {
                        local_8 = local_6;
                        break;
                    }
                }
            }

            local_8 = -1;
        }
    }

    return local_8;
}

// OK P1
void COMSUBS_07d4(int param_1, int param_2)
{
    do
    {
        D_5876 = ULTIMA_2092_RandomRange(1, 3) + param_1 - 2;
        D_5878 = ULTIMA_2092_RandomRange(1, 3) + param_2 - 2;
    } while (D_5876 < 0 || D_5876 > 10 || D_5878 < 0 || D_5878 > 10);
}

// OK P1
int COMSUBS_0822(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    int local_a;
    int local_4;
    int local_e;
    int local_c;
    int local_6;
    int local_8;

    local_6 = param_2;
    local_c = param_3;
    local_4 = D_ba14[param_1].x;
    local_a = D_ba14[param_1].y;

    if (param_4 == 0)
    {
        do
        {
            COMSUBS_07d4(local_6, local_c);
            if (local_4 != D_5876)
                break;

        } while (local_a == D_5878);
        local_6 = D_5876;
        local_c = D_5878;
    }

    if (D_589d == 25 || D_589d == 34)
    {
        if (param_4 != 0)
        {
            local_6 = param_2;
            local_c = param_3;
            local_e = 1;
        }
    }
    else
    {
        local_e = COMSUBS_12de(local_4, local_a, local_6, local_c, param_5);
        if (local_e != 0)
        {
            COMBAT_111a(local_6, local_c);
        }
        else
        {
            local_6 = D_5876;
            local_c = D_5878;
        }
    }

    if (local_e != 0)
    {
        local_8 = COMSUBS_0748(local_6, local_c);

        switch (D_589d)
        {
        case 0x13:
        case 53:
            ULTIMA_6506(TILE_ACTOR_EA, 2, local_6, local_c, D_5895_map_level);
            break;
        case 51:
            ULTIMA_6506(TILE_ACTOR_E8, 2, local_6, local_c, D_5895_map_level);
            break;
        case 52:
            ULTIMA_6506(TILE_ACTOR_E9, 2, local_6, local_c, D_5895_map_level);
            break;
        case 54:
            ULTIMA_6506(TILE_ACTOR_EB, 2, local_6, local_c, D_5895_map_level);
            break;
        }

        if ((D_588f == 0 || param_4 != 0) && local_8 >= 0 && local_8 != D_589e)
        {
            D_5876 = local_6;
            D_5878 = local_c;
            return local_8;
        }
    }

    D_5876 = local_6;
    D_5878 = local_c;
    return -1;
}

// OK P1
static void COMSUBS_097c(int param_1, int param_2)
{
    if (D_588f != 0)
    {
        return;
    }

    switch (param_1)
    {
    case 0x1a:
    case 0x24:
        if (--D_57db == 0)
        {
            D_57c0[param_1] += SJOG_1b34(param_1);
        }
        break;

    case 0x1c:
        if (--D_57dd == 0)
        {
            D_57c0[param_1] += SJOG_1b34(param_1);
        }
        break;

    case 0x10:
    case 0x15:
    case 0x16:
        if (param_2 <= 1)
        {
            break;
        }

        if (D_57c0[param_1] != 0)
        {
            D_57c0[param_1]--;
            break;
        }

        ULTIMA_6e60(D_ba14[D_589e].entityIdx, param_1);
        break;
    }
}

// OK P1
int COMSUBS_09fc(int param_1)
{
    int uVar1;

    uVar1 = D_58a8[param_1];
    if (uVar1 != 0xff && D_ba14[uVar1].flags != 0 && ULTIMA_5646(uVar1) != 0 && (D_ba14[uVar1].flags & (COMBAT_FLAGS_ASLEEP | COMBAT_FLAGS_4)) == 0 &&
        D_587a != 'T' && COMSUBS_04d4(param_1, uVar1) == 1)
    {
        ULTIMA_16ba_PrintChar(10);
        COMSUBS_0094(uVar1);
        ULTIMA_1850_PrintString(/*0x9a70*/ " interferes!\n");
        return 1;
    }

    return 0;
}

// OK P1
static void COMSUBS_0a68(int param_1, int param_2, int param_3)
{
    int local_8;
    int local_10;
    int local_c;
    int local_4;
    int local_6;
    int local_e;
    ActorFmt* local_a;

    if (param_2 != 0x1a && param_2 != 0x1c && param_2 != 0x24 && param_2 != 0x13 && param_2 != 0x11 ||
        COMSUBS_09fc(param_1) == 0)
    {
        ULTIMA_1850_PrintString(/*0x9a7e*/ "Aim! ");

        local_10 = COMSUBS_0504(param_1, D_1664[param_2]);
        if (local_10 != 0)
        {
            ULTIMA_43ae_AudioSweepTone(0x514, 300, 5, 100);
            if (param_2 == 0x13)
            {
                if (D_57c0[param_2] != 0)
                {
                    D_57c0[param_2]--;
                }
                else
                {
                    ULTIMA_6e60(D_ba14[D_589e].entityIdx, param_2);
                }
            }

            local_a = &D_5c5a[D_ba14[param_1].actorIdx];
            local_a->_7 = 0xff;
            local_c = local_e = COMSUBS_0748(D_5899, D_589a);
            if (local_c > -1)
            {
                local_a->_7 = local_c;
                COMSUBS_097c(param_2, local_10);
                local_4 = COMBAT_14d6(local_c, param_1, -D_588f, param_2);
                local_c = COMSUBS_0822(param_1, D_5899, D_589a, local_4, param_3);
            }
            else
            {
                local_c = COMSUBS_0822(param_1, D_5899, D_589a, 1, param_3);
            }

            local_6 = D_5876;
            local_8 = D_5878;
            if (local_c > -1)
            {
                ULTIMA_3564(local_c);
                ULTIMA_16ba_PrintChar(10);
                COMBAT_194a(local_c, param_1);
                COMSUBS_0312(local_c, param_1);
            }
            else if (local_e > -1)
            {
                ULTIMA_16ba_PrintChar(10);
                COMSUBS_00d2(local_e);
            }

            if (param_2 == 0x26)
            {
                COMSUBS_12de(local_6, local_8, D_ba14[param_1].x, D_ba14[param_1].y, param_3);
            }
        }
    }
}

// OK P1
void COMSUBS_0bf8(int param_1, int param_2, int param_3)
{
    ULTIMA_43ae_AudioSweepTone(400, 0x2ee, 5, 0x96);
    ULTIMA_16ba_PrintChar(10);
    if (COMBAT_14d6(param_2, param_1, -D_588f, param_3) != 0)
    {
        ULTIMA_3564(param_2);
        COMBAT_194a(param_2, param_1);
        COMSUBS_0312(param_2, param_1);
    }
    else
    {
        COMSUBS_00d2(param_2);
    }
}

// OK P1
void COMSUBS_0c52(int param_1, int param_2)
{
    int local_a;
    int local_4;
    int local_6;
    int local_8;

    if (param_2 >= 0x23)
    {
        D_5890 = 1;
    }

    if ((D_ba14[param_1].flags & COMBAT_FLAGS_PLAYER) == 0)
    {
        local_a = D_159c[D_ba14[param_1].entityIdx];
        if (local_a == 1)
        {
            local_a = 0;
        }

        local_4 = D_15cc[D_ba14[param_1].entityIdx];
    }
    else
    {
        if (param_2 != 0xff)
        {
            local_a = D_1664[param_2];
        }
        else
        {
            local_a = 0;
        }

        local_4 = D_169c[param_2];
    }

    if (local_a == 0)
    {
        ULTIMA_1850_PrintString(/*0x9a84*/ "Aim! ");
        local_6 = COMSUBS_0504(param_1, 1);
        local_8 = COMSUBS_0748(D_5899, D_589a);
        if (local_6 == 0 || local_8 == -1)
        {
            ULTIMA_1850_PrintString(/*0x9a8a*/ "Nothing!\n");
        }
        else
        {
            D_5c5a[D_ba14[param_1].actorIdx]._7 = local_8;
            COMSUBS_0bf8(param_1, local_8, param_2);
        }
    }
    else
    {
        COMSUBS_0a68(param_1, param_2, local_4);
    }
}

// OK P1
static void COMSUBS_0d3c(int param_1, int param_2)
{
    if (param_1 != 0xff && D_15fc[param_1] != 0)
    {
        if (param_2 > 1)
        {
            D_5890 = D_588f = 0;
            ULTIMA_16ba_PrintChar(10);
            ULTIMA_1850_PrintString(D_17f6[param_1]);
            ULTIMA_1850_PrintString(/*0x9a94*/ ":\n");
        }

        D_589d = (undefined1)param_1;
        ULTIMA_1850_PrintString(/*0x9a98*/ "Attack-");
        COMSUBS_0c52(D_589e, param_1);
    }
}

// OK P1
// attack
void COMSUBS_0d96(int param_1, int param_2)
{
    int local_4;

    if ((D_ba14[param_1].flags & COMBAT_FLAGS_PLAYER) == 0 || param_2 == 0)
    {
        D_589d = 0xff;
        ULTIMA_1850_PrintString(/*0x9aa0*/ "Attack-");
        COMSUBS_0c52(param_1, 0xff);
    }
    else
    {
        local_4 = D_ba14[param_1].entityIdx;
        if (param_2 > 1)
        {
            ULTIMA_1bf2_SetTextPosition(0, ULTIMA_1cee_GetCurrentTextY());
            ULTIMA_16ba_PrintChar(0x20);
        }

        COMSUBS_0d3c(D_55a8_party[local_4].equips[0], param_2);
        COMSUBS_0d3c(D_55a8_party[local_4].equips[2], param_2);
        COMSUBS_0d3c(D_55a8_party[local_4].equips[3], param_2);
    }
}

// OK P1
static void COMSUBS_0e26(int param_1, int param_2, int param_3, int param_4, u8* param_5, u8* param_6)
{
    int local_e;
    int local_c;
    int local_8;
    int local_6;
    int local_4;
    int local_10;
    int local_a;

    local_6 = 1;
    local_8 = 1;
    local_c = 0x148;

    if (param_3 != param_1)
    {
        local_a = ((param_4 - param_2) * 100) / (param_3 - param_1);
    }
    else
    {
        local_a = 0x4b00;
    }

    if (local_a < 0)
    {
        local_a = -local_a;
    }

    if (param_3 < param_1)
    {
        local_6 = -1;
    }

    if (param_4 < param_2)
    {
        local_8 = -1;
    }

    local_10 = param_3 - param_1;
    if (local_10 < 0)
    {
        local_10 = -local_10;
    }

    local_4 = param_4 - param_2;
    if (local_4 < 0)
    {
        local_4 = -local_4;
    }

    // f08f
    local_e = local_a;

    *param_5 = param_1;
    param_5++;

    *param_6 = param_2;
    param_6++;

    while (local_10 > 0 || local_4 > 0)
    {
        while (local_e > 0 && local_4 > 0)
        {
            local_e -= 100;
            param_2 += local_8;

            *param_6 = param_2;
            param_6++;
            local_4--;

            *param_5 = param_1;
            param_5++;
            local_c--;

            if (local_c == 0)
                break;
        }

        if (local_c == 0)
            break;

        local_10--;
        local_e += local_a;

        param_1 += local_6;

        *param_6 = param_2;
        *param_5 = param_1;

        param_6++;
        param_5++;
        local_c--;
    }

    *param_5 = 0xff;
    *param_6 = 0xff;
}

// OK P1
static void COMSUBS_0f4a(byte param_1, byte param_2, int param_3, int param_4, u8* param_5, u8* param_6)
{
    int local_1e;
    int local_1c;
    int local_16;
    int local_4;
    int local_c;
    int local_14;
    int local_12;
    int local_1a;
    int local_6;
    int local_8;
    s8* local_e;
    s8* local_a;
    byte* local_10;
    byte* local_18;

    local_1c = 1;
    local_1e = 1;
    local_4 = -1;

#if !defined(MATCHING_BUILD)
    local_e = NULL;
    local_a = NULL;
#endif

    if (param_4 == 2)
    {
        local_a = local_e = D_2188;
    }

    if (param_4 > 2)
    {
        local_a = local_e = D_2188 + 0x10;
    }

    switch (param_3)
    {
    case 1: // f178
        local_e++;
        break;
    case 2: // f196
        local_a++;
        local_1c = -1;
        break;
    case 3: // f1a0
        local_e++;
        local_1c = local_1e = -1;
        break;
    case 4: // f1ae
        local_a++;
        local_1e = -1;
        break;
    }

    // f17b
    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    switch (param_4)
    {
    case 0: // f1b8
        local_10 = param_5 - 4;
        local_18 = param_6 - 4;
        for (local_16 = 0; local_16 < 9; local_16++)
        {
            if (*local_10 == 0xff)
                break;

            ULTIMA_0b10_GRAP_Line(*local_10, *local_18, *local_10 + 1, *local_18);
            local_10++;
            local_18++;
        }
        break;

    case 1: // f206
        ULTIMA_0b10_GRAP_Line(param_1 - 1, param_2 - 2, param_1 + 1, param_2 - 2);
        ULTIMA_0b10_GRAP_Line(param_1 - 2, param_2 - 1, param_1 + 2, param_2 - 1);
        ULTIMA_0b10_GRAP_Line(param_1 - 2, param_2, param_1 + 2, param_2);
        ULTIMA_0b10_GRAP_Line(param_1 - 2, param_2 + 1, param_1 + 2, param_2 + 1);
        ULTIMA_0b10_GRAP_Line(param_1 - 1, param_2 + 2, param_1 + 1, param_2 + 2);
        break;

    case 2: // f27e
        for (local_16 = 0; local_16 < 4; local_16++)
        {
            local_c = *local_a * local_1c + param_1;
            local_a += 2;
            local_14 = *local_e * local_1e + param_2;
            local_e += 2;
            local_12 = *local_a * local_1c + param_1;
            local_a += 2;
            local_1a = *local_e * local_1e + param_2;
            local_e += 2;
            ULTIMA_0b10_GRAP_Line(local_c, local_14, local_12, local_1a);
        }
        break;

    case 3: // f2f4
        local_4 = D_13ae + 8;
        break;

    case 4: // f300
        local_4 = D_13b2_frame_color + 8;
        break;

    case 5: // f306
        local_4 = D_13b4 + 8;
        break;

    case 6: // f30c
        local_4 = D_13b6 + 8;
        break;

    case 7: // f312
        for (local_16 = 0; local_16 < 7; local_16++)
        {
            local_c = *local_a * local_1c + param_1;
            local_a += 2;
            local_14 = *local_e * local_1e + param_2;
            local_e += 2;
            local_12 = *local_a * local_1c + param_1;
            local_a += 2;
            local_1a = *local_e * local_1e + param_2;
            local_e += 2;
            ULTIMA_0b10_GRAP_Line(local_c, local_14, local_12, local_1a);
        }

        // f384
        ULTIMA_0c64_GRAP_30_Pset(*local_a * local_1c + param_1, *local_e * local_1e + param_2);
        local_a += 2;
        local_e += 2;
        ULTIMA_0c64_GRAP_30_Pset(*local_a * local_1c + param_1, *local_e * local_1e + param_2);
        local_a += 2;
        local_e += 2;
        ULTIMA_0c64_GRAP_30_Pset(*local_a * local_1c + param_1, *local_e * local_1e + param_2);
        break;
    }

    if (local_4 > -1)
    {
        // f40d
        local_1c = -1;
        local_1e = 1;
        for (local_16 = 0; local_16 < 0x30; local_16++)
        {
            // f42b
            local_10 = local_18 = D_21ba;

            local_10 += ULTIMA_2092_RandomRange(0, 0xf);
            local_18 += ULTIMA_2092_RandomRange(0, 0xf);

            local_6 = ULTIMA_2092_RandomRange(0, 1);
            local_8 = ULTIMA_2092_RandomRange(0, 1);

            if (local_6 != 0)
            {
                local_1c = -local_1c;
            }

            if (local_8 != 0)
            {
                local_1e = -local_1e;
            }

            ULTIMA_0a70_GRAP_2d_SetPenColor(local_4);
            ULTIMA_0c64_GRAP_30_Pset(*local_10 * local_1c + param_1, *local_18 * local_1e + param_2);
        }
    }
}

// OK P1
int COMSUBS_12de(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    byte* local_12;
    byte* local_e;
    int local_c;
    int local_a;
    int local_10;
    int local_4;
    int local_6;
    int local_8;

    local_c = 0xd;
    local_a = 0;
    ULTIMA_0f6e_GRAP_1b_TransferFullscreen(0, 1);

    memset(D_a728, 0xff, 0x100);
    memset(D_a872, 0xff, 0x100);

    local_10 = param_1 * 0x10 + 0x10;
    local_6 = param_2 * 0x10 + 0x10;
    local_4 = param_3 * 0x10 + 0x10;
    local_8 = param_4 * 0x10 + 0x10;
    COMSUBS_0e26(local_10, local_6, local_4, local_8, D_a728, D_a872);

    local_e = D_a728;
    local_12 = D_a872;

    if (D_5893_map_id != 0 && D_5893_map_id < 0x21)
    {
        local_c = 6;
    }
    else
    {
        if (param_5 == 7)
        {
            local_c = 8;
        }
    }

    if (param_5 == 0)
    {
        local_e += 4;
        local_12 += 4;
    }

    while (*local_e != 0xff)
    {
        local_a = (local_a & 3) + 1;
        ULTIMA_3fb4(*local_e, *local_12);
        if (D_5876 == -1)
        {
            break;
        }

        COMSUBS_0f4a(*local_e, *local_12, local_a, param_5, local_e, local_12);
        ULTIMA_20c8_SomeDelay(1, 0x28);
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, (*local_e & 0xf8) - 8, *local_12 - 8, (*local_e & 0xf8) + 0xf, *local_12 + 0xf);

        local_e += local_c;
        local_12 += local_c;

#if defined(MATCHING_BUILD)
        if (D_a872 < local_e)
        {
            break;
        }
#else
        if (D_a728 + sizeof(D_a728) < local_e)
        {
            break;
        }
#endif

        if (*local_e == 0xff)
        {
            break;
        }

        if (ULTIMA_3f6e(D_5876, D_5878) == 0 && (param_1 != D_5876 || param_2 != D_5878))
        {
            return 0;
        }
    }

    return 1;
}
