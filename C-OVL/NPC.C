#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>

// OK P1
void F_NPC_0000(void)
{
    int local_4;
    char* local_6;
    byte local_26[32];
    int local_28;

#ifdef _WIN32
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

    FUN_1000_256e_read_file_from_disk(local_6, D_5d5e, 0x200, local_28 * 0x240);
    FUN_1000_256e_read_file_from_disk(local_6, D_659e, 0x20, local_28 * 0x240 + 0x200);
    FUN_1000_256e_read_file_from_disk(local_6, local_26, 0x20, local_28 * 0x240 + 0x220);

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        D_5f5e[local_4]._a = (u16)local_26[local_4];
    }

    D_5893_map_id++;
}

int F_NPC_12e0(int a, char b);

// OK P1
void F_NPC_00d6(int param_1)
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
            local_6 = F_NPC_12e0(local_4, param_1);
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

int F_NPC_01a0(int a, int b, int c, int d)
{
    printf("F_NPC_01a0(a=%d, b=%d, c=%d, d=%d)\n", a, b, c, d);
    return 0;
}

int F_NPC_032c(int a, int b, int c, int d, int e, int f)
{
    printf("F_NPC_032c(a=%d, b=%d, c=%d, d=%d, e=%d, f=%d)\n",
        a, b, c, d, e, f);
    return 0;
}

void F_NPC_04ac(int a, int b, int c, int d)
{
    printf("F_NPC_04ac(a=%d, b=%d, c=%d, d=%d)\n", a, b, c, d);
}

void F_NPC_0632(int a)
{
    printf("F_NPC_0632(a=%d)\n", a);
}

int F_NPC_0938(int a, int b)
{
    printf("F_NPC_0938(a=%d, b=%d)\n", a, b);
    return 0;
}

int F_NPC_0a4a(int a, int b)
{
    printf("F_NPC_0a4a(a=%d, b=%d)\n", a, b);
    return 0;
}

int F_NPC_0b9e(int a, int b, int c, int d)
{
    printf("F_NPC_0b9e(a=%d, b=%d, c=%d, d=%d)\n", a, b, c, d);
    return 0;
}

void F_NPC_0c50(u16* a, int b, int c, int d, u8* e)
{
    printf("F_NPC_0c50(a=, b=%d, c=%d, d=%d, e=)\n",
        b, c, d);
}

void F_NPC_0d00(int a, int b)
{
    printf("F_NPC_0d00(a=%d, b=%d)\n", a, b);
}

void FUN_THUNK_7b2a(int a, int b, int c, int d)
{
    printf("FUN_THUNK_7b2a(a=%d, b=%d, c=%d, d=%d)\n", a, b, c, d);
}

// TODO: MATCH
void F_NPC_0db4(int param_1)
{
    byte local_12;
    int iVar4;
    int local_e;
    int local_14;
    int local_10;
    uint local_c;
    uint local_a;
    int local_6;
    int local_4;
    NpcFmt* local_8;

    local_14 = 0;
    D_65be = 0;
    D_65bf = 0;

    // 0dd9
    for (local_4 = 1; /*1267*/local_4 < 0x20; /*1264*/local_4++)
    {
        // 126d
        if (D_659e[local_4] != 0)
        {
            // 1277
            local_e = F_NPC_12e0(local_4, param_1);
            // 1281
            local_8 = &D_5f5e[local_4];

            if (local_8->_0 <= 1 && F_NPC_0938(local_4, param_1) == 0)
            {
                // 124e
                if (local_8->_6 == (uint)D_5895_map_level)
                {
                    // 1261
                    F_NPC_0d00(local_4, local_e);
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
                        local_10 = F_NPC_01a0(
                            D_5d5e[local_4]._3[local_e],
                            D_5d5e[local_4]._6[local_e],
                            local_6 == 3, local_4);
                        if (local_10 != 0)
                        {
                            local_a = D_5876;
                            local_c = D_5878;
                            local_10 = F_NPC_032c(local_a, local_c,
                                D_5d5e[local_4]._3[local_e],
                                D_5d5e[local_4]._6[local_e],
                                local_6, local_4);
                        }

                        // 0e32 (ok)
                        if (local_10 != 0)
                        {
                            // 0e3b (ok)
                            F_NPC_04ac(local_4, local_6,
                                D_5d5e[local_4]._3[local_e],
                                D_5d5e[local_4]._6[local_e]);

                            // 0e5a (ok)
                            local_12 = D_6608[local_a + local_c * 0x20];
                            if (/*0e6b*/(local_6 == 3 && local_12 == 200) ||
                                /*0e75*/(local_6 == 4 && local_12 == 0xc9) ||
                                /*0e81*/(local_12 & 0xfc) == 0xc4)
                            {
                                // 0e8a (ok)
                                FUN_THUNK_7b2a(local_4, local_a, local_c, D_5895_map_level);
                            }

                            // 0e9c (ok)
                            local_8->_0 = 2;
                        }
                    }
                }
                else if (local_8->_0 == 6 || local_8->_0 == 7)
                {
                    // 0eb2
                    if (F_NPC_0a4a(local_4, local_e) != 0)
                    {
                        // 0ebf
                        FUN_THUNK_7b2a(local_4,
                            D_5d5e[local_4]._3[local_e],
                            D_5d5e[local_4]._6[local_e],
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
                            local_10 = F_NPC_01a0(local_8->_2, local_8->_4, local_6 == 1, local_4);
                            if (local_10 != 0)
                            {
                                local_a = D_5876;
                                local_c = D_5878;
                                local_10 = F_NPC_032c(local_8->_2, local_8->_4, local_a, local_c, local_6, local_4);
                            }
                            // 0f71
                            if (local_10 != 0)
                            {
                                // 0f7a
                                F_NPC_04ac(local_c, local_a, local_6, local_4);
                                local_8->_0 = 3;
                            }
                        }
                    }
                }
            }
            else// if (local_8->_0 == 2 || local_8->_0 == 3)
            {
                // 0f94
                if (D_655e[local_4] < 0x8000 &&
                    D_615e[local_4].data[D_655e[local_4]] != '\0')
                {
                    // 0fb8
                    D_5876 = local_8->_2;
                    D_5878 = local_8->_4;
                    F_NPC_0632(D_615e[local_4].data[D_655e[local_4] + 1]);
                    local_a = D_5876;
                    local_c = D_5878;
                    iVar4 = F_NPC_0b9e(D_5876, local_c, local_4, local_e);
                    if (iVar4 == 0)
                    {
                        D_65c2[local_4]++;
                        F_NPC_0c50(&local_8->_0, 0, local_e, local_4, D_5d5e[local_4]._0);
                        if (3 < D_65c2[local_4])
                        {
                            // 10d0
                            D_655e[local_4] = 0xffff;
                            // 10d6
                            D_65c2[local_4] = 0;
                        }
                    }
                    else
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
                }
                else
                {
                    // 10e0
                    if (D_655e[local_4] == 0xffff && local_8->_0 == 3)
                    {
                        local_e = F_NPC_12e0(local_4, param_1);
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
                            if ((iVar10 < 200) && ((iVar10 == 0 || (iVar10 = FUN_1000_2092_random_range(0, 2), iVar10 == 1))))
                            {
                                // 1160
                                if (D_655e[local_4] == 0xffff)
                                {
                                    local_14 = local_14 + 1;
                                    if (F_NPC_032c(
                                        local_8->_2,
                                        local_8->_4,
                                        D_5d5e[local_4]._3[local_e],
                                        D_5d5e[local_4]._6[local_e],
                                        0, local_4) != 0)
                                    {
                                        F_NPC_04ac(local_4, 0,
                                            D_5d5e[local_4]._3[local_e],
                                            D_5d5e[local_4]._6[local_e]);

                                        D_65c2[local_4] = 0;
                                        continue;
                                    }
                                    // 11ba
                                    D_65c2[local_4] = 200;
                                }

                                // 11c5
                                F_NPC_0c50(&local_8->_0, 0, local_e, local_4, D_5d5e[local_4]._0);
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
                        F_NPC_0d00(local_4, local_8->_e);
                    }
                }
            }
        }
    }

    // 12d8
}

// F_NPC_12e0: optimized using assembly?
// use literal conversion from FMT
int F_NPC_12e0(int param_1, char param_2)
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
