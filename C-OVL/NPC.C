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
    byte bVar3;
    int iVar4;
    int iVar5;
    int iVar7;
    int iStack_14;
    int iStack_10;
    uint uStack_c;
    uint uStack_a;
    int iStack_6;
    int iStack_4;

    iStack_14 = 0;
    D_65be = 0;
    D_65bf = 0;

    for (iStack_4 = 1; iStack_4 <= 0x1f; iStack_4++)
    {
        if (D_659e[iStack_4] != 0)
        {
            iVar7 = F_NPC_12e0(iStack_4, param_1);

            if ((D_5f5e[iStack_4]._0 < 2) && F_NPC_0938(iStack_4, param_1) == 0)
            {
                if (D_5f5e[iStack_4]._6 == (uint)D_5895_map_level)
                {
                    F_NPC_0d00(iStack_4, iVar7);
                }
            }
            else
            {
                if (D_5f5e[iStack_4]._0 < 4)
                {
                    if (D_655e[iStack_4] < 0x8000 &&
                        D_615e[iStack_4].data[D_655e[iStack_4]] != '\0')
                    {
                        D_5876 = D_5f5e[iStack_4]._2;
                        D_5878 = D_5f5e[iStack_4]._4;
                        F_NPC_0632(D_615e[iStack_4].data[D_655e[iStack_4] + 1]);
                        uStack_a = D_5876;
                        uStack_c = D_5878;
                        iVar4 = F_NPC_0b9e(D_5876, uStack_c, iStack_4, iVar7);
                        if (iVar4 == 0)
                        {
                            D_65c2[iStack_4]++;
                            F_NPC_0c50(&D_5f5e[iStack_4]._0, 0, iVar7, iStack_4, D_5d5e[iStack_4]._0);
                            if (3 < D_65c2[iStack_4])
                            {
                                D_655e[iStack_4] = 0xffff;
                                D_65c2[iStack_4] = 0;
                            }
                        }
                        else
                        {
                            D_5c5a[D_5f5e[iStack_4]._c]._2_x = (u8)uStack_a;
                            D_5f5e[iStack_4]._2 = uStack_a & 0xff;
                            D_5c5a[D_5f5e[iStack_4]._c]._3_y = (u8)uStack_c;
                            D_5f5e[iStack_4]._4 = uStack_c & 0xff;
                            D_24e6 |= 2;

                            D_615e[iStack_4].data[D_655e[iStack_4]]--;
                            D_65c2[iStack_4] = 0;
                            if (D_615e[iStack_4].data[D_655e[iStack_4]] == '\0')
                            {
                                D_655e[iStack_4]++;
                                iVar5 = D_655e[iStack_4];
                                D_655e[iStack_4]++;
                                D_615e[iStack_4].data[iVar5] = 0;
                                if (0x1f < D_655e[iStack_4] || D_615e[iStack_4].data[D_655e[iStack_4]] == 0)
                                {
                                    D_655e[iStack_4] = 0xffff;
                                }
                                if (iVar4 == 2)
                                {
                                    D_5f5e[iStack_4]._e = iVar7;
                                    D_5f5e[iStack_4]._0 = 1;
                                    D_655e[iStack_4] = 0xffff;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (D_655e[iStack_4] == 0xffff && D_5f5e[iStack_4]._0 == 3)
                        {
                            iVar7 = F_NPC_12e0(iStack_4, param_1);
                            if (D_5895_map_level < D_5d5e[iStack_4]._9[iVar7])
                            {
                                D_5f5e[iStack_4]._0 = 6;
                                return;
                            }
                            D_5f5e[iStack_4]._0 = 7;
                            return;
                        }

                        if (iStack_14 < 1)
                        {
                            if (D_5f5e[iStack_4]._0 != 1)
                            {
                                int iVar10 = D_65c2[iStack_4];
                                if ((iVar10 < 200) && ((iVar10 == 0 || (iVar10 = FUN_1000_2092_random_range(0, 2), iVar10 == 1))))
                                {
                                    if (D_655e[iStack_4] == 0xffff)
                                    {
                                        iStack_14 = iStack_14 + 1;
                                        if (F_NPC_032c(
                                            D_5f5e[iStack_4]._2,
                                            D_5f5e[iStack_4]._4,
                                            D_5d5e[iStack_4]._3[iVar7],
                                            D_5d5e[iStack_4]._6[iVar7],
                                            0, iStack_4) != 0)
                                        {
                                            F_NPC_04ac(iStack_4, 0,
                                                D_5d5e[iStack_4]._3[iVar7],
                                                D_5d5e[iStack_4]._6[iVar7]);

                                            D_65c2[iStack_4] = 0;
                                            continue;
                                        }
                                        D_65c2[iStack_4] = 200;
                                    }
                                    F_NPC_0c50(&D_5f5e[iStack_4]._0, 0, iVar7, iStack_4, D_5d5e[iStack_4]._0);
                                }
                                else
                                {
                                    if (199 < D_65c2[iStack_4])
                                    {
                                        D_65c2[iStack_4]++;
                                    }
                                    if (0xcc < D_65c2[iStack_4])
                                    {
                                        D_65c2[iStack_4] = 0;
                                    }
                                }
                            }
                        }
                        else if (D_5f5e[iStack_4]._6 == (uint)D_5895_map_level)
                        {
                            iVar7 = D_5f5e[iStack_4]._e;
                            F_NPC_0d00(iStack_4, iVar7);
                            continue;
                        }
                    }
                }
                else if ((D_5f5e[iStack_4]._0 == 4) || (D_5f5e[iStack_4]._0 == 5))
                {
                    if (iStack_14 != 1)
                    {
                        iStack_14 = 1;
                        if (D_5f5e[iStack_4]._0 == 4)
                        {
                            iStack_6 = 3;
                        }
                        else
                        {
                            iStack_6 = 4;
                        }
                        iStack_10 = F_NPC_01a0(
                            D_5d5e[iStack_4]._3[iVar7],
                            D_5d5e[iStack_4]._6[iVar7],
                            iStack_6 == 3, iStack_4);
                        if (iStack_10 != 0)
                        {
                            uStack_a = D_5876;
                            uStack_c = D_5878;
                            iStack_10 = F_NPC_032c(uStack_a, uStack_c,
                                D_5d5e[iStack_4]._3[iVar7],
                                D_5d5e[iStack_4]._6[iVar7],
                                iStack_6, iStack_4);
                        }

                        if (iStack_10 != 0)
                        {
                            F_NPC_04ac(iStack_4, iStack_6,
                                D_5d5e[iStack_4]._3[iVar7],
                                D_5d5e[iStack_4]._6[iVar7]);

                            bVar3 = D_6608[uStack_a + uStack_c * 0x20];
                            if ((iStack_6 == 3 && bVar3 == 200) ||
                                (iStack_6 == 4 && bVar3 == 0xc9) ||
                                (bVar3 & 0xfc) == 0xc4)
                            {
                                FUN_THUNK_7b2a(iStack_4, uStack_a, uStack_c, D_5895_map_level);
                            }

                            D_5f5e[iStack_4]._0 = 2;
                        }
                    }
                }
                else if ((D_5f5e[iStack_4]._0 == 6 || D_5f5e[iStack_4]._0 == 7) && F_NPC_0a4a(iStack_4, iVar7) == 0)
                {
                    if (D_5f5e[iStack_4]._0 != 2 && iStack_14 != 1)
                    {
                        iStack_14 = 1;
                        if (D_5f5e[iStack_4]._0 == 6)
                        {
                            iStack_6 = 1;
                        }
                        else
                        {
                            iStack_6 = 2;
                        }
                        iStack_10 = F_NPC_01a0(
                            D_5f5e[iStack_4]._2,
                            D_5f5e[iStack_4]._4,
                            iStack_6 == 1, iStack_4);
                        if (iStack_10 != 0)
                        {
                            uStack_a = D_5876;
                            uStack_c = D_5878;
                            iStack_10 = F_NPC_032c(
                                D_5f5e[iStack_4]._2,
                                D_5f5e[iStack_4]._4,
                                uStack_a, uStack_c, iStack_6, iStack_4);
                        }
                        if (iStack_10 != 0)
                        {
                            F_NPC_04ac(uStack_c, uStack_a, iStack_6, iStack_4);
                            D_5f5e[iStack_4]._0 = 3;
                        }
                    }
                }
                else
                {
                    FUN_THUNK_7b2a(iStack_4,
                        D_5d5e[iStack_4]._3[iVar7],
                        D_5d5e[iStack_4]._6[iVar7],
                        D_5d5e[iStack_4]._9[iVar7]);

                    D_5f5e[iStack_4]._e = iVar7;
                    D_655e[iStack_4] = 0xffff;
                    D_5f5e[iStack_4]._0 = 1;
                }
            }
        }
    }
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
