#include "common/common.h"
#include "funcs.h"
#include "vars.h"

#include <stdio.h>

int NPC_032c(int a, int b, int c, int d, int e, int f);
int NPC_06a0(int param_1, int param_2, int param_3, int param_4);
int NPC_0adc(int param_1, int param_2, int param_3, int param_4, int param_5);
int NPC_0b9e(int param_1, int param_2, int param_3, int param_4);
int NPC_12e0(int a, char b);

// OK P1
void NPC_0000_LoadNpcFile(void)
{
    int local_4;
    char* local_6;
    byte local_26[32];
    int local_28;

#if !defined(TARGET_DOS16)
    local_6 = NULL;
#endif

    D_5893_map_id--;

    local_4 = (uint)D_5893_map_id >> 3;
    switch (local_4)
    {
    case 0:
        local_6 = "towne.npc";
        break;
    case 1:
        local_6 = "dwelling.npc";
        break;
    case 2:
        local_6 = "castle.npc";
        break;
    case 3:
        local_6 = "keep.npc";
        break;
    }

    local_28 = (uint)D_5893_map_id - (local_4 << 3);

    ULTIMA_256e_ReadFile(local_6, D_5d5e, 0x200, local_28 * 0x240);
    ULTIMA_256e_ReadFile(local_6, D_659e, 0x20, local_28 * 0x240 + 0x200);
    ULTIMA_256e_ReadFile(local_6, local_26, 0x20, local_28 * 0x240 + 0x220);

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        D_5f5e[local_4]._a = (u16)local_26[local_4];
    }

    D_5893_map_id++;
}

// OK P1
void NPC_00d6(int param_1)
{
    int local_4;
    int local_6;

    for (local_4 = 1; local_4 < 0x20; local_4++)
    {
        if (D_659e[local_4] == 0)
        {
            D_5f5e[local_4]._0 = 0;
        }
        else
        {
            local_6 = NPC_12e0(local_4, param_1);
            D_5f5e[local_4]._0 = 1;

            D_5f5e[local_4]._2 = D_5d5e[local_4]._3[local_6];
            D_5f5e[local_4]._4 = D_5d5e[local_4]._6[local_6];
            D_5f5e[local_4]._6 = D_5d5e[local_4]._9[local_6];

            D_5f5e[local_4]._8 = D_659e[local_4];
            D_5f5e[local_4]._e = local_6;
            D_5f5e[local_4]._c = 0;

            D_655e[local_4] = 0xffff;
            D_615e[local_4].data[0] = 0;
            D_65c2[local_4] = 0;
        }
    }
}

// OK P1
int NPC_01a0(int param_1, int param_2, int param_3, int param_4)
{
    int local_4;

    if (param_3 != 0)
    {
        local_4 = -1;
    }
    else
    {
        local_4 = -2;
    }

    return NPC_032c(param_1, param_2, 0, 0, local_4, param_4);
}

// CHECKED (loop)
void NPC_01d2(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
{
    int local_a;
    int local_8;
    int local_6;
    byte local_e;
    NpcFmt* local_4;
    ActorFmt* local_c;

    if (param_5 == -1)
    {
        local_e = 0xc8;
    }

    if (param_5 == -2)
    {
        local_e = 0xc9;
    }

    local_a = NPC_12e0(param_6, D_587f);
    for (local_6 = 0; local_6 < 0x20; local_6 = local_6 + 1)
    {
        for (local_8 = 0; local_8 < 0x20; local_8 = local_8 + 1)
        {
            if (NPC_0adc(local_8, local_6, D_5895_map_level, param_6, local_a) != 0)
            {
                D_b11c[local_8 + local_6 * 0x20] = 0;
            }
            else
            {
                D_b11c[local_8 + local_6 * 0x20] = 0x90;
            }

            if (param_5 < 0 && D_6608[local_8 + local_6 * 0x20] == local_e)
            {
                D_b11c[local_8 + local_6 * 0x20] = 5;
            }
        }
    }

    // 0272
    local_4 = &D_5f5e[param_6];

    for (local_6 = 0x1f; local_6 > 0; local_6--) // NOT MATCHING
    {
        local_c = &D_5c5a[local_6];
        if (local_c->_0_tile > 0x3f)
        {
            if (NPC_06a0(local_c->_2_x, local_c->_3_y, local_4->_2, local_4->_4) < 4)
            {
                D_b11c[local_c->_3_y * 0x20 + local_c->_2_x] = 0x90;
            }
        }
    }

    local_c = &D_5c5a[0];
    if (NPC_06a0(local_c->_2_x, local_c->_3_y, local_4->_2, local_4->_4) < 4)
    {
        D_b11c[local_c->_3_y * 0x20 + local_c->_2_x] = 0x90;
    }

    if (param_5 > -1)
    {
        D_b11c[param_4 * 0x20 + param_3] = 5;
    }

    D_b11c[param_2 * 0x20 + param_1] = 0x46;
}

// NOT MATCHING
// based on FMT
int NPC_032c(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
{
    byte bVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int local_54;
    int local_50;
    int local_4c;
    int local_48;
    byte local_44[32];
    byte local_24[32];

    iVar5 = 0;
    local_48 = 0;
    local_4c = 1;

    NPC_01d2(param_1, param_2, param_3, param_4, param_5, param_6);

    local_24[0] = param_1;
    local_44[0] = param_2;

    while (local_48 != local_4c && iVar5 == 0)
    {
        iVar3 = local_24[local_48];
        iVar4 = local_44[local_48];
        local_50 = D_b11c[iVar3 + iVar4 * 0x20] >> 4;

        for (local_54 = 0; local_54 < 4; local_54++)
        {
            switch (local_50)
            {
            case 1:
                iVar3--;
                iVar2 = iVar3;
                if (iVar2 < 0)
                {
                    iVar5 = 2;
                }
                break;

            case 2:
                iVar4++;
                iVar2 = iVar4;
                if (iVar2 > 0x20)
                {
                    iVar5 = 2;
                }
                break;

            case 3:
                iVar3++;
                iVar2 = iVar3;
                if (iVar2 > 0x20)
                {
                    iVar5 = 2;
                }
                break;

            case 4:
                iVar4--;
                iVar2 = iVar4;
                if (iVar2 < 0)
                {
                    iVar5 = 2;
                }
                break;

            default:
                break;
            }

            if (iVar5 != 2)
            {
                iVar5 = iVar4 * 0x20 + iVar3;
                bVar1 = D_b11c[iVar5];
                if (bVar1 < 0x10)
                {
                    D_b11c[iVar5] = (char)local_50 << 4;
                    if ((bVar1 & 0xf) == 5)
                    {
                        iVar5 = 1;
                        D_5876 = iVar3;
                        D_5878 = iVar4;
                        break;
                    }
                    if (local_4c != local_48)
                    {
                        local_24[local_4c] = iVar3;
                        local_44[local_4c] = iVar4;
                        local_4c++;
                    }
                    if (0x1f < local_4c)
                    {
                        local_4c = 0;
                    }
                }
            }
            iVar5 = 0;
            local_50 = (local_50 & 3) + 1;
            iVar3 = local_24[local_48];
            iVar4 = local_44[local_48];
        }

        if (iVar5 == 1)
            break;

        local_48++;
        if (local_48 == 0x20)
        {
            local_48 = 0;
        }
    }

    return iVar5 != 0;
}

// NOT MATCHING
int NPC_04ac(int param_1, int param_2, int param_3, int param_4)
{
    undefined1 uVar1;
    char cVar2;
    byte bVar3;
    int iVar4;
    int iVar9;
    int iVar10;
    byte bVar11;
    byte bVar12;

    cVar2 = 0;
    iVar9 = 0;
    D_655e[param_1] = 0;

    bVar12 = D_b11c[param_4 * 0x20 + param_3];
    bVar11 = bVar12 >> 4;
    bVar3 = bVar11;

    do
    {
        bVar12 &= 0xf;

        switch (bVar11)
        {
        case 1:
            param_3++;
            break;
        case 2:
            param_4--;
            break;
        case 3:
            param_3--;
            break;
        case 4:
            param_4++;
            break;
        }

        if (bVar3 == bVar11 && bVar12 != 6)
        {
            cVar2++;
        }

        if (bVar3 != bVar11 || bVar12 == 6)
        {
            D_615e[param_1].data[iVar9] = cVar2;
            D_615e[param_1].data[iVar9 + 1] = bVar3;
            iVar9 += 2;

            if (bVar12 == 6)
                break;

            cVar2 = 1;
            bVar3 = bVar11;
        }

        bVar12 = D_b11c[param_4 * 0x20 + param_3];
        bVar11 = bVar12 >> 4;
    } while (iVar9 < 0x20);

    iVar4 = iVar9 - 2;
    iVar10 = 0;
    do
    {
        // swap
        uVar1 = D_615e[param_1].data[iVar10];
        D_615e[param_1].data[iVar10] = D_615e[param_1].data[iVar4];
        D_615e[param_1].data[iVar4] = uVar1;

        // swap*
        cVar2 = D_615e[param_1].data[iVar10 + 1];
        D_615e[param_1].data[iVar10 + 1] = (D_615e[param_1].data[iVar4 + 1] + 1U & 3) + 1;
        D_615e[param_1].data[iVar4 + 1] = (cVar2 + 1U & 3) + 1;

        iVar10 += 2;
        iVar4 -= 2;
    } while (iVar10 <= iVar4);

    return iVar9;
}

// OK P1
// set walk direction
void NPC_0632(int param_1)
{
    switch (param_1)
    {
    case 1:
        D_5876++;
        if (D_5878 > 0x20)
        {
            D_5876 = 0x20;
        }
        break;

    case 2:
        D_5878--;
        if (D_5876 < 0)
        {
            D_5878 = 0;
        }
        break;

    case 3:
        D_5876--;
        if (D_5878 < 0)
        {
            D_5876 = 0;
        }
        break;

    case 4:
        D_5878++;
        if (D_5876 > 0x20)
        {
            D_5878 = 0x20;
        }
        break;
    }
}

// OK P1
// Calculate manhattan distance
int NPC_06a0(int param_1, int param_2, int param_3, int param_4)
{
    int local_6;
    int local_4;

    local_4 = param_1 - param_3;
    local_6 = param_2 - param_4;

    if (local_4 < 0)
    {
        local_4 = -local_4;
    }

    if (local_6 < 0)
    {
        local_6 = -local_6;
    }

    local_4 += local_6;
    return local_4;
}

// CHECKED
void NPC_06e4(int param_1, int param_2)
{
    int local_4;
    int local_6;
    NpcFmt* local_8;
    int local_10[4];
    int local_12;
    int local_14;
    int local_16;
    ActorFmt* local_18;
    int local_1a;
    int local_1c;

    CHECK_PARAM_RANGE(param_1, 0, 32);
    CHECK_PARAM_RANGE(param_2, 0, 3);

    local_18 = &D_5c5a[0];
    local_8 = &D_5f5e[param_1];
    local_4 = D_5d5e[param_1]._0[param_2];
    local_6 = NPC_06a0(D_5c5a[0]._2_x, D_5c5a[0]._3_y, local_8->_2, local_8->_4);
    if (local_6 == 1 && local_4 > 3)
    {
        if (local_4 == 4 || local_4 == 5)
        {
            // a9cd
            if (local_8->_a != 0)
            {
                // a9d6
                D_65be = 0x74;
                // a9db
                D_65bf = param_1;
                local_4 = 1;
            }
        }
        else
        {
            // aa4e: ??
            D_65be = 0x61;
            // -> a9db
            D_65bf = param_1;
            local_4 = 1;
        }
    }
    else
    {
        // a9ea
        for (local_16 = 1; local_16 < 5; local_16++)
        {
            // aa09
            D_5876 = local_8->_2;
            D_5878 = local_8->_4;
            NPC_0632(local_16);
            local_12 = D_5876;
            local_14 = D_5878;
            if (NPC_0b9e(D_5876, D_5878, param_1, -1) != 0)
            {
                local_10[local_16 - 1] = NPC_06a0(local_18->_2_x, local_18->_3_y, local_12, local_14);
            }
            else
            {
                // aa56 (OK)
                local_10[local_16 - 1] = 99;
            }
        }

        // aa6a (OK)
        local_1a = -1; // di
        local_6 = NPC_06a0(local_18->_2_x, local_18->_3_y, local_8->_2, local_8->_4);
        // aa8c
        for (local_16 = 1; local_16 < 8; local_16++)
        {
            // aaa7
            if (local_16 < 5 && local_10[local_16 - 1] != 99)
            {
                if (local_4 == 3)
                {
                    if (local_6 < local_10[local_16 - 1])
                    {
                        if (local_1a == -1 || ULTIMA_2092_RandomRange(0, 1) != 0)
                        {
                            local_1a = local_16;
                        }

                        if (local_16 == 4)
                            break;
                    }
                }
                else
                {
                    // ab14
                    if (local_10[local_16 - 1] < local_6)
                    {
                        local_1a = local_16;
                        break;
                    }
                }
            }

#if defined(TARGET_DOS16)
            // aae4 (OK)
            if (local_16 > 4 && local_10[local_16 - 1] != 99) // BUG? (OOB, invalid index)
#else
            if (local_16 > 4 && local_10[local_16 - 5] != 99) // BUGFIX?
#endif
            {
                if (local_10[local_16 - 5] == local_6)
                {
                    local_1a = local_16;
                    break;
                }
            }
        }

        // ab22 (OK below)
        if ((local_4 == 5 || local_4 == 7) && ULTIMA_2092_RandomRange(0, 0x3f) < 0x10)
        {
            // ab3d
            local_1c = local_1a;
            for (local_16 = 1; local_16 < 5; local_16++)
            {
                // ab4b
                if (local_1a != local_16 && local_10[local_16 - 1] != 99 &&
                    (local_1c == local_1a || ULTIMA_2092_RandomRange(0, 0x3f) < 0x10))
                {
                    local_1c = local_16;
                }
            }
            local_1a = local_1c;
        }

        if (local_1a > -1)
        {
            D_5876 = local_8->_2;
            D_5878 = local_8->_4;
            NPC_0632(local_1a);

            D_5c5a[local_8->_c]._2_x = local_8->_2 = D_5876;
            D_5c5a[local_8->_c]._3_y = local_8->_4 = D_5878;
            D_24e6 |= 2;
        }
    }
}

// CHECKED
int NPC_0938(int param_1, int param_2)
{
    NpcFmt* local_8;
    int local_a;
    int local_6;
    NpcScheduleFmt* local_4;

    local_a = -1;
    local_8 = &D_5f5e[param_1];
    local_4 = &D_5d5e[param_1];

    for (local_6 = 0; local_6 < 4; local_6++)
    {
        if (local_4->_c[local_6] == param_2)
        {
            local_a = NPC_12e0(param_1, param_2);
            if (local_a == local_8->_e) // NOT MATCHING: di vs ax
            {
                local_8->_0 = 1;
                break;
            }

            if (local_8->_6 != D_5895_map_level && local_4->_9[local_a] != D_5895_map_level)
            {
                local_8->_0 = 8;
            }
            else
            {
                if (local_8->_6 == D_5895_map_level)
                {
                    if (local_4->_9[0] == D_5895_map_level)
                    {
                        local_8->_0 = 2;
                    }
                    else if ((char)D_5895_map_level < (char)local_4->_9[local_a])
                    {
                        local_8->_0 = 6;
                    }
                    else
                    {
                        local_8->_0 = 7;
                    }
                }
                else if ((char)D_5895_map_level < (char)local_8->_6)
                {
                    local_8->_0 = 4;
                }
                else
                {
                    local_8->_0 = 5;
                }
            }
            break;
        }
    }

    // ac1b
    if (-1 < local_a && local_8->_2 == (uint)local_4->_3[local_a] &&
        local_8->_4 == (uint)local_4->_6[local_a] &&
        local_8->_6 == (uint)local_4->_9[local_a])
    {
        local_a = 0;
        local_8->_0 = 1;
    }

    if (local_a == -1)
    {
        local_a = 0;
    }
    else
    {
        local_a++;
    }

    return local_a;
}

// OK P1
int NPC_0a4a(int param_1, int param_2)
{
    byte local_8;
    int local_6;
    NpcFmt* local_4;

    local_4 = &D_5f5e[param_1];

    // 0a4a
    local_8 = *ULTIMA_4402_GetTileAddr(D_5c5a[local_4->_c]._2_x, D_5c5a[local_4->_c]._3_y);
    if ((char)D_5d5e[param_1]._9[param_2] < (char)D_5895_map_level)
    {
        if (local_8 != 0xc9)
        {
            // 0a92
            if ((local_8 & 0xf4) == 0xc4)
            {
                local_6 = 1;
            }
            else
            {
                local_6 = 0;
            }
        }
        else
        {
            // 0a9b
            local_6 = 1;
        }
    }
    else
    {
        // 0aa2
        local_8 = *ULTIMA_4402_GetTileAddr(D_5c5a[local_4->_c]._2_x, D_5c5a[local_4->_c]._3_y);
        if (local_8 == 0xc8)
        {
            // -> 0a9b
            local_6 = 1;
        }
        else
        {
            if ((local_8 & 0xf4) == 0xc4)
            {
                local_6 = 1;
            }
            else
            {
                local_6 = 0;
            }
        }
    }

    return local_6;
}

// OK P1
int NPC_0adc(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    byte local_8;
    int local_6;
    NpcScheduleFmt* local_4;

    local_6 = 0;
    local_4 = &D_5d5e[param_4];

    if (param_5 > -1 && local_4->_3[param_5] == param_1 && local_4->_6[param_5] == param_2 && local_4->_9[param_5] == param_3)
    {
        local_6 = 2;
    }
    else
    {
        if (param_1 < 0 || param_2 < 0 || 0x1f < param_1 || 0x1f < param_2)
        {
            local_8 = D_6608[1023]; // D_6a07;
        }
        else
        {
            local_8 = D_6608[param_1 + param_2 * 0x20];
        }

        if (D_5f5e[param_4]._0 == 3 && (local_8 == 200 || local_8 == 0xc9))
        {
            local_6 = 1;
        }
        else
        {
            local_6 = ((uint)D_367e[local_8 >> 3] & 0x80 >> (local_8 & 7)) == 0;
        }
    }

    return local_6;
}

// OK P1
int NPC_0b9e(int param_1, int param_2, int param_3, int param_4)
{
    int local_8;
    int local_6;
    int local_4;

    local_6 = 0;
    if (param_1 < 0 || param_1 > 0x1f || param_2 < 0 || param_2 > 0x1f)
    {
        return 0;
    }

    local_8 = *ULTIMA_4402_GetTileAddr(param_1, param_2) & 0xfc;
    if (D_659e[param_3] == 0xfc)
    {
        local_4 = 1;
    }
    else if (local_8 == 0x30)
    {
        local_4 = 1;
    }
    else if (local_8 == 0x90 && D_5f5e[param_3]._0 != 2)
    {
        local_4 = 0;
    }
    else
    {
        local_4 = NPC_0adc(param_1, param_2, D_5895_map_level, param_3, param_4);
    }

    local_6 = ULTIMA_3702(param_1, param_2, D_5895_map_level);
    if (local_4 == 0 || local_6 != 0)
    {
        local_4 = 0;
    }

    return local_4;
}

// OK P1
// move npc randomly
void NPC_0c50(NpcFmt* param_1, int param_2, int param_3, int param_4, NpcScheduleFmt* param_5)
{
    int local_8;
    int local_6;
    int local_4;

    if ((ULTIMA_2092_RandomRange(0, 0xff) & 8) != 0)
    {
        local_4 = ULTIMA_3aae(0x40);
        local_4 = (local_4 & 3) + 1;
        D_5876 = param_1->_2;
        D_5878 = param_1->_4;
        NPC_0632(local_4);
        local_6 = D_5876;
        local_8 = D_5878;

        if ((param_2 == 0 || NPC_06a0(param_5->_3[param_3], param_5->_6[param_3], D_5876, D_5878) <= param_2) &&
            NPC_0b9e(D_5876, D_5878, param_4, param_3) != 0)
        {
            D_5c5a[param_1->_c]._2_x = param_1->_2 = local_6;
            D_5c5a[param_1->_c]._3_y = param_1->_4 = local_8;

            D_24e6 |= 2;
        }
    }
}

// CHECKED (switch order)
void NPC_0d00(int param_1, int param_2)
{
    NpcFmt* local_4;
    NpcScheduleFmt* local_6;

    local_4 = &D_5f5e[param_1];
    local_6 = &D_5d5e[param_1];

    switch (local_6->_0[param_2])
    {
    case 0:
        break;

    case 2:
        NPC_0c50(local_4, 0, param_2, param_1, local_6);
        break;

    case 4:
        if (NPC_06a0(D_5896_map_x, D_5897_map_y, local_6->_3[param_2], local_6->_6[param_2]) < 4)
        {
            NPC_06e4(param_1, param_2);
        }

        break;

    case 1:
        NPC_0c50(local_4, 3, param_2, param_1, local_6);
        break;

    case 3:
    case 6:
        if (NPC_06a0(D_5896_map_x, D_5897_map_y, local_4->_2, local_4->_4) >= 4)
        {
            return;
        }

        NPC_06e4(param_1, param_2);
        break;

    case 5:
    case 7:
        NPC_06e4(param_1, param_2);
        break;

    }
}

void TOWN_1726(int param_1, int param_2, int param_3, int param_4);

// NOT MATCHING
// move npc
void NPC_0db4(int param_1)
{
    byte local_12;
    int iVar4;
    int local_e;
    int local_14;
    int local_10;
    int local_c;
    int local_a;
    int local_6;
    int local_4;
    NpcFmt* local_8;

    local_14 = 0;
    D_65be = 0;
    D_65bf = 0;

    // 0dd9
    for (local_4 = 1; /*1267*/ local_4 < 0x20; /*1264*/ local_4++)
    {
        // 126d
        if (D_659e[local_4] != 0)
        {
            // 1277
            local_e = NPC_12e0(local_4, param_1);
            // 1281
            local_8 = &D_5f5e[local_4];

            // 128e
            if (local_8->_0 <= 1 && NPC_0938(local_4, param_1) == 0)
            {
                // 124e
                if (local_8->_6 == D_5895_map_level)
                {
                    // 1261
                    NPC_0d00(local_4, local_e);
                }
            }
            // 12a2
            else if (local_8->_0 > 3)
            {
                if (local_8->_0 == 4 || local_8->_0 == 5)
                {
                    // 12bc
                    if (local_14 != 1)
                    {
                        local_14 = 1;
                        if (local_8->_0 == 4)
                        {
                            // 12cf
                            local_6 = 3;
                            // -> 0dd9
                        }
                        else
                        {
                            // 0dd4
                            local_6 = 4;
                        }

                        // 0dd9 (ok)
                        local_10 =
                            NPC_01a0(D_5d5e[local_4]._3[local_e], D_5d5e[local_4]._6[local_e], local_6 == 3, local_4);
                        if (local_10 != 0)
                        {
                            local_a = D_5876;
                            local_c = D_5878;
                            local_10 = NPC_032c(local_a, local_c, D_5d5e[local_4]._3[local_e],
                                                  D_5d5e[local_4]._6[local_e], local_6, local_4);
                        }

                        // 0e32 (ok)
                        if (local_10 != 0)
                        {
                            // 0e3b (ok)
                            NPC_04ac(local_4, local_6, D_5d5e[local_4]._3[local_e], D_5d5e[local_4]._6[local_e]);

                            // 0e5a (ok)
                            local_12 = D_6608[local_a + local_c * 0x20];
                            if (/*0e6b*/ (local_6 == 3 && local_12 == 200) ||
                                         /*0e75*/ (local_6 == 4 && local_12 == 0xc9) ||
                                         /*0e81*/ (local_12 & 0xfc) == 0xc4)
                            {
                                // 0e8a (ok)
                                TOWN_1726(local_4, local_a, local_c, D_5895_map_level);
                            }

                            // 0e9c (ok)
                            local_8->_0 = 2;
                        }
                    }
                }
                else if (local_8->_0 == 6 || local_8->_0 == 7)
                {
                    // 0eb2
                    if (NPC_0a4a(local_4, local_e) != 0)
                    {
                        // 0ebf
                        TOWN_1726(local_4, D_5d5e[local_4]._3[local_e], D_5d5e[local_4]._6[local_e],
                                       D_5d5e[local_4]._9[local_e]);

                        local_8->_e = local_e;
                        D_655e[local_4] = 0xffff;
                        local_8->_0 = 1;
                    }
                    else
                    {
                        // 0efe
                        if (local_8->_0 != 2 && local_14 != 1)
                        {
                            local_14 = 1;
                            if (local_8->_0 == 6)
                            {
                                local_6 = 1;
                            }
                            else
                            {
                                local_6 = 2;
                            }
                            // 0f2b
                            local_10 = NPC_01a0(local_8->_2, local_8->_4, local_6 == 1, local_4);
                            if (local_10 != 0)
                            {
                                local_a = D_5876;
                                local_c = D_5878;
                                local_10 = NPC_032c(local_8->_2, local_8->_4, local_a, local_c, local_6, local_4);
                            }
                            // 0f71
                            if (local_10 != 0)
                            {
                                // 0f7a
                                NPC_04ac(local_4, local_6, local_a, local_c);
                                local_8->_0 = 3;
                            }
                        }
                    }
                }
            }
            else
            {
                // 0f94
                if ((s16)D_655e[local_4] > -1 && D_615e[local_4].data[D_655e[local_4]] != 0)
                {
                    // 0fb8
                    D_5876 = local_8->_2;
                    D_5878 = local_8->_4;
                    NPC_0632(D_615e[local_4].data[D_655e[local_4] + 1]);
                    local_a = D_5876;
                    local_c = D_5878;
                    iVar4 = NPC_0b9e(D_5876, local_c, local_4, local_e);
                    if (iVar4 != 0)
                    {
                        // 0ff9
                        D_5c5a[local_8->_c]._2_x = (u8)local_a;
                        local_8->_2 = local_a & 0xff;
                        D_5c5a[local_8->_c]._3_y = (u8)local_c;
                        local_8->_4 = local_c & 0xff;
                        D_24e6 |= 2;

                        D_615e[local_4].data[D_655e[local_4]]--;
                        D_65c2[local_4] = 0;
                        if (D_615e[local_4].data[D_655e[local_4]] == '\0')
                        {
                            // 104a
                            D_655e[local_4]++;
                            D_615e[local_4].data[D_655e[local_4]++] = 0;
                            if (0x1f < D_655e[local_4] || D_615e[local_4].data[D_655e[local_4]] == 0)
                            {
                                D_655e[local_4] = 0xffff;
                            }
                            if (iVar4 == 2)
                            {
                                local_8->_e = local_e;
                                local_8->_0 = 1;
                                D_655e[local_4] = 0xffff;
                            }
                        }
                    }
                    else
                    {
                        D_65c2[local_4]++;
                        NPC_0c50(&D_5f5e[local_4], 0, local_e, local_4, &D_5d5e[local_4]);
                        if (3 < D_65c2[local_4])
                        {
                            // 10d0
                            D_655e[local_4] = 0xffff;
                            // 10d6
                            D_65c2[local_4] = 0;
                        }
                    }
                }
                else
                {
                    // 10e0
                    if (D_655e[local_4] == 0xffff && local_8->_0 == 3)
                    {
                        local_e = NPC_12e0(local_4, param_1);
                        if (D_5895_map_level < D_5d5e[local_4]._9[local_e])
                        {
                            local_8->_0 = 6;
                            return; // 12d8
                        }
                        local_8->_0 = 7;
                        return; // 12d8
                    }

                    // 1124
                    if (local_14 < 1)
                    {
                        // 112d
                        if (local_8->_0 != 1)
                        {
                            // 1138
                            int iVar10 = D_65c2[local_4];
                            if ((iVar10 < 200) &&
                                ((iVar10 == 0 || (iVar10 = ULTIMA_2092_RandomRange(0, 2), iVar10 == 1))))
                            {
                                // 1160
                                if (D_655e[local_4] == 0xffff)
                                {
                                    local_14 = local_14 + 1;
                                    if (NPC_032c(local_8->_2, local_8->_4, D_5d5e[local_4]._3[local_e],
                                                   D_5d5e[local_4]._6[local_e], 0, local_4) != 0)
                                    {
                                        NPC_04ac(local_4, 0, D_5d5e[local_4]._3[local_e],
                                                   D_5d5e[local_4]._6[local_e]);

                                        D_65c2[local_4] = 0;
                                        continue;
                                    }
                                    // 11ba
                                    D_65c2[local_4] = 200;
                                }

                                // 11c5
                                NPC_0c50(local_8, 0, local_e, local_4, &D_5d5e[local_4]);
                            }
                            else
                            {
                                // 11e8
                                if (200 <= D_65c2[local_4])
                                {
                                    D_65c2[local_4]++;
                                }
                                // 11f9
                                if (0xcc < D_65c2[local_4])
                                {
                                    D_65c2[local_4] = 0;
                                }
                            }
                        }
                    }
                    // 120e
                    else if (local_8->_6 == (uint)D_5895_map_level)
                    {
                        // 1243 -> 1261
                        NPC_0d00(local_4, local_8->_e);
                    }
                }
            }
        }
    }

    // 12d8
}

// NPC_12e0: optimized using assembly?
// use literal conversion from FMT
int NPC_12e0(int param_1, char param_2)
{
    int i;
    int ret;
    byte local_8[4];

    for (i = 0; i < 4; i++)
    {
        local_8[i] = param_2 - D_5d5e[param_1]._c[i];
    }

    ret = 0;
    if (local_8[1] < local_8[0])
    {
        local_8[0] = local_8[1];
        ret = 1;
    }

    if (local_8[2] < local_8[0])
    {
        local_8[0] = local_8[2];
        ret = 2;
    }

    if (local_8[3] < local_8[0])
    {
        ret = 1;
    }

    return ret;
}
