#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>
#include <string.h>

int COMBAT_0000(int param_1, int param_2, int param_3);
int COMBAT_111a(int param_1, int param_2);
int COMBAT_120e(void);
void COMBAT_1236(int param_1);
uint COMBAT_13e2(int param_1, int param_2);
int COMBAT_14d6(int param_1, int param_2, int param_3, int param_4);
void COMBAT_194a(int param_1, int param_2);
int COMBAT_1a5c(int param_1);

int SJOG_1b34(int param_1);

// NOT MATCHING
int COMSUBS_0000(int param_1, int param_2, int param_3)
{
    int iVar1;
    int iVar2;
    int iVar3;

    if (param_3 != 0x30 && param_3 != 0x31 && param_3 < 0x33)
    {
        iVar1 = COMBAT_13e2(param_1, -1);
        iVar2 = COMBAT_13e2(param_2, -1);
        iVar3 = ULTIMA_3abe();
        if (iVar3 < ((iVar2 + 0x1e) - iVar1) / 2)
        {
            return 1;
        }
    }

    return 0;
}

// NOT MATCHING
void COMSUBS_0056(void)
{
    int iVar2;

    for (iVar2 = 0; iVar2 < 0x20; iVar2++)
    {
        if ((D_5c5a[iVar2]._0_tile & 0xfc) == 0xe8)
        {
            if (ULTIMA_2092_RandomRange(0, 0xff) < 0x10)
            {
                COMBAT_1236(iVar2 + 1);
            }
        }
    }
}

// NOT MATCHING
void COMSUBS_0094(int param_1)
{
    if ((D_ba14[param_1]._2 & 0x80) == 0)
    {
        ULTIMA_1850_PrintString(D_1856[D_ba14[param_1]._3]);
    }
    else
    {
        ULTIMA_1850_PrintString(D_55a8_party[D_ba14[param_1]._3]._0);
    }
}

// NOT MATCHING
void COMSUBS_00d2(int param_1)
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

// NOT MATCHING
int COMSUBS_00f4(int param_1)
{
    byte bVar2;
    uint uVar3;
    int iVar6;

    uVar3 = D_ba14[param_1]._3;
    bVar2 = D_ba14[param_1]._4;
    if (D_587a == 0x1c || D_587a == 'N' || (D_ba14[param_1]._2 & 0x80) != 0)
    {
        return 0;
    }
    else
    {
        if (((byte)D_153c[uVar3] & 0x40) != 0)
        {
            iVar6 = ULTIMA_2092_RandomRange(0, 0x1f);

            if ((D_ba14[iVar6]._2 & 0x80) != 0 && (D_ba14[iVar6]._2 & 0x3d) == 0)
            {
                if (COMSUBS_0000(param_1, iVar6, 0) == 0)
                {
                    ULTIMA_16ba_PrintChar(10);

                    D_ba14[iVar6]._2 |= 1;
                    if (D_ba14[iVar6]._3 == D_587b)
                    {
                        D_587b = 0xff;
                    }

                    ULTIMA_2900_UpdateVitalsDisplay();
                    COMSUBS_0094(iVar6);
                    ULTIMA_1850_PrintString(" possessed!\n");
                    ULTIMA_2192_AudioPulse(0xc1c, 1, 30000, 1000, 2);
                    if (uVar3 == 0x26)
                    {
                        COMBAT_1236(-param_1 - 1);
                    }
                }

                return 1;
            }
        }

        if ((D_153c[uVar3] & 0x800) == 0 || (iVar6 = ULTIMA_2092_RandomRange(0, 0xff), 0x1f < iVar6))
        {
            if (((D_153c[uVar3] & 0x400) == 0 || (iVar6 = ULTIMA_2092_RandomRange(0, 0xff), 0x1f < iVar6)) ||
                (iVar6 = COMBAT_120e(), iVar6 == 0) || (iVar6 = COMBAT_0000(0xd8, D_5876, D_5878), iVar6 == 0) ||
                (iVar6 = ULTIMA_6506(0x26, 0, D_5876, D_5878, D_5895_map_level), iVar6 == -1))
            {
                return 0;
            }

            ULTIMA_16ba_PrintChar(10);
            COMSUBS_0094(param_1);
            ULTIMA_1850_PrintString(" gates in a daemon!\n");
            ULTIMA_2192_AudioPulse(0xac8, 1, 5000, 1000, 0xf);
            D_5c5a[D_ba14[iVar6]._4]._1 = 0x16;
            D_5c5a[D_ba14[iVar6]._4]._0_tile = 0x16;
            ULTIMA_1068(D_5878, D_5876, 0x1d8);
            D_5c5a[D_ba14[iVar6]._4]._1 = 0xd8;
            D_5c5a[D_ba14[iVar6]._4]._0_tile = 0xd8;
        }
        else
        {
            ULTIMA_16ba_PrintChar(10);
            COMSUBS_0094(param_1);
            if (D_5c5a[bVar2]._1 == 0)
            {
                ULTIMA_1850_PrintString(" reappears!");
                D_ba14[param_1]._2 &= 0xef;
                D_5c5a[bVar2]._1 = D_5c5a[bVar2]._0_tile;
            }
            else
            {
                ULTIMA_1850_PrintString(" disappears!");
                D_ba14[param_1]._2 |= 0x10;
                D_5c5a[bVar2]._1 = 0;
            }
        }
        return 1;
    }
}

// NOT MATCHING
void COMSUBS_0312(int param_1, int param_2)
{
    byte bVar2 = D_ba14[param_1]._2;
    D_58a2 &= 0xfe;
    if ((D_58a2 & 0x20) != 0)
    {
        COMSUBS_0094(param_1);
        ULTIMA_1850_PrintString(/*0x99f2*/ " grazed!\n");
        ULTIMA_43ae_AudioSweepTone(0x4b0, 2000, 1, 0x28);
    }

    if ((D_58a2 & 0x22) != 0)
    {
        D_58a2 = D_58a2 & 0xdd;
        return;
    }

    if (bVar2 == 0 || (bVar2 & 0x20) != 0)
    {
        COMSUBS_0094(param_1);
        ULTIMA_1850_PrintString(/*0x99fc*/ " killed!\n");
        D_58a2 = D_58a2 | 1;
    }
    else
    {
        if ((D_58a2 & 4) != 0)
        {
            COMSUBS_0094(param_1);
            ULTIMA_1850_PrintString(/*0x9a06*/ " slept!\n");
        }
        else
        {
            if ((D_58a2 & 8) == 0)
            {
                COMSUBS_0094(param_1);
                if ((bVar2 & 0x80) != 0)
                {
                    if (param_2 != 0xff && D_ba14[param_2]._3 == '-')
                    {
                        ULTIMA_1850_PrintString(/*0x9a10*/ " dragged under!\n");
                        ULTIMA_43ae_AudioSweepTone(0x4b0, 2000, 1, 0x28);
                        D_ba14[param_1]._2 |= 4;
                        D_5c5a[D_ba14[param_1]._4]._1 = 0;
                        ULTIMA_3ae6(4);
                    }
                    else
                    {
                        ULTIMA_1850_PrintString(/*0x9a22*/ " hit!\n");
                    }
                }
                else
                {
                    switch (COMBAT_1a5c(param_1))
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
        }
    }

    if ((bVar2 & 0x80) != 0)
    {
        ULTIMA_2900_UpdateVitalsDisplay();
        ULTIMA_5910_UpdateFrame();
    }
    D_58a2 &= 0xf3;
}

// NOT MATCHING
// TODO: verify math
int COMSUBS_0458(int param_1, int param_2, int param_3, int param_4)
{
    return (param_2 - param_4) * (param_2 - param_4) + (param_1 - param_3) * (param_1 - param_3);
}

// NOT MATCHING
int COMSUBS_048a(int param_1, int param_2, int param_3, int param_4)
{
    int iVar1;
    int iVar2;
    int iVar3;

    iVar2 = 0;
    iVar1 = COMSUBS_0458(param_1, param_2, param_3, param_4);
    for (iVar3 = 1; iVar3 <= iVar1; iVar3 += 2)
    {
        iVar1 -= iVar3;
        iVar2++;
    }

    return iVar2;
}

// NOT MATCHING
int COMSUBS_04d4(int param_1, int param_2)
{
    return COMSUBS_048a(D_ba14[param_1]._6, D_ba14[param_1]._7, D_ba14[param_2]._6, D_ba14[param_2]._7);
}

// NOT MATCHING
int COMSUBS_0504(int param_1, int param_2)
{
    bool bVar1;
    bool bVar2;
    u8 cVar3;
    u8 cVar4;
    int iVar5;
    int iVar6;
    int iVar7;
    undefined2 uVar8;
    int iStack_14;
    uint uStack_c;
    undefined1 uStack_6;
    undefined1 uStack_4;

    D_5898 = 1;
    uStack_c = D_5c5a[D_ba14[param_1]._4]._7;
    if (uStack_c > 0x1f || (D_ba14[uStack_c]._2 & 0x30) != 0 || D_ba14[uStack_c]._2 == 0 ||
        D_5c5a[D_ba14[uStack_c]._4]._0_tile == 0 || param_2 < COMSUBS_04d4(param_1, uStack_c))
    {
        uStack_c = param_1;
    }

    D_5899 = D_ba14[uStack_c]._6;
    D_589a = D_ba14[uStack_c]._7;

    bVar2 = 0;
    bVar1 = 0;
    cVar3 = D_ba14[param_1]._7;
    cVar4 = D_ba14[param_1]._6;

    do
    {
        if (bVar1 || bVar2)
        {
            D_5898 = 0;
            if (bVar2)
            {
                ULTIMA_16ba_PrintChar(10);
                iStack_14 = 0;
            }
            return iStack_14;
        }
        iVar7 = 0;
        iVar6 = 0;
        ULTIMA_5910_UpdateFrame();
        iVar5 = ULTIMA_266c_GetChar();

        switch (iVar5)
        {
        case 1: // 0683
            iVar6 = -1;
            break;
        case 2: // 0679
            iVar6 = 1;
            break;
        case 3: // 05c5
            iVar7 = -1;
            break;
        case 4: // 066f
            iVar7 = 1;
            break;
        case 0x20: // 068a
            if ((cVar4 == D_5899) && (cVar3 == D_589a))
            {
                bVar2 = 1;
            }
            // fallthrough
        case 0xd:  // 06a3
        case 0x41: // 06a3
            if (cVar4 != D_5899 || cVar3 != D_589a)
            {
                ULTIMA_16ba_PrintChar(10);
                if (D_588f != 0)
                {
                    ULTIMA_223c_AudioWhiteNoise(800, (uint)D_588f * 0x640 + 8000, 700);
                }
                bVar1 = 1;
            }
            break;
        case 0x1b: // 06ea
            bVar2 = 1;
            iVar6 = iVar7;
            break;
        case 0xd3: // 05c2
            iVar6 = -1;
            iVar7 = -1;
            break;
        case 0xd4: // 0680
            iVar7 = 1;
            iVar6 = -1;
            break;
        case 0xd5: // 0676
            iVar7 = -1;
            iVar6 = 1;
            break;
        case 0xd6: // 066c
            iVar6 = 1;
            iVar7 = 1;
            break;
        }

        // 05c8
        iVar6 = iVar6 + (uint)D_5899;
        iVar7 = iVar7 + (uint)D_589a;
        iStack_14 = COMSUBS_048a(iVar6, iVar7, cVar4, cVar3);
        if (iStack_14 <= param_2 && -1 < iVar6 && iVar6 < 0xb && -1 < iVar7 && iVar7 < 0xb)
        {
            uStack_4 = (undefined1)iVar6;
            D_5899 = uStack_4;
            uStack_6 = (undefined1)iVar7;
            D_589a = uStack_6;
        }
    } while (1);
}

// NOT MATCHING
int COMSUBS_0748(int param_1, int param_2)
{
    byte bVar1;
    int iVar2;

    iVar2 = 0;
    while (D_ba14[iVar2]._6 != param_1 || D_ba14[iVar2]._7 != param_2 ||
           (bVar1 = D_ba14[iVar2]._2, D_5c5a[D_ba14[iVar2]._4]._1 == 0xf4) || (bVar1 & 0xc0) == 0 ||
           (bVar1 & 0x20) != 0 || (bVar1 & 4) != 0)
    {
        iVar2++;
        if (iVar2 >= 0x20)
        {
            return -1;
        }
    }

    return iVar2;
}

// NOT MATCHING
void COMSUBS_07d4(int param_1, int param_2)
{
    do
    {
        do
        {
            D_5876 = ULTIMA_2092_RandomRange(1, 3) + param_1 - 2;
            D_5878 = ULTIMA_2092_RandomRange(1, 3) + param_2 - 2;
        } while (D_5876 < 0);
    } while (10 < D_5876 || D_5878 < 0 || 10 < D_5878);
}

int COMSUBS_12de(int param_1, int param_2, int param_3, int param_4, int param_5);

// NOT MATCHING
int COMSUBS_0822(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    int uVar2;
    int iVar3;
    int local_e;
    int local_c;
    int local_6;

    local_6 = param_2;
    local_c = param_3;
    iVar3 = D_ba14[param_1]._6;
    uVar2 = D_ba14[param_1]._7;

    if (param_4 == 0)
    {
        do
        {
            COMSUBS_07d4(param_2, param_3);
            if (iVar3 != D_5876)
                break;

        } while (uVar2 == D_5878);
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
        local_e = COMSUBS_12de(param_5, local_c, local_6, uVar2, iVar3);
        if (local_e == 0)
        {
            local_6 = D_5876;
            local_c = D_5878;
        }
        else
        {
            COMBAT_111a(local_6, local_c);
        }
    }

    if (local_e == 0)
    {
        D_5876 = local_6;
        D_5878 = local_c;
        return -1;
    }

    iVar3 = COMSUBS_0748(local_6, local_c);

    switch (D_589d)
    {
    case 0x13:
        ULTIMA_6506(0xea, 2, local_6, local_c, D_5895_map_level);
        break;
    case '3':
        ULTIMA_6506(0xe8, 2, local_6, local_c, D_5895_map_level);
        break;
    case '4':
        ULTIMA_6506(0xe9, 2, local_6, local_c, D_5895_map_level);
        break;
    case '5':
        ULTIMA_6506(0xea, 2, local_6, local_c, D_5895_map_level);
        break;
    case '6':
        ULTIMA_6506(0xeb, 2, local_6, local_c, D_5895_map_level);
        break;
    }

    if ((D_588f == 0 || param_4 != 0) && 0 <= iVar3 && iVar3 != D_589e)
    {
        D_5876 = local_6;
        D_5878 = local_c;
        return iVar3;
    }

    D_5876 = local_6;
    D_5878 = local_c;
    return -1;
}

// NOT MATCHING
void COMSUBS_097c(int param_1, int param_2)
{
    char cVar2;

    if (D_588f != 0)
    {
        return;
    }

    switch (param_1)
    {
    case 0x10:
    case 0x15:
    case 0x16:
        if (param_2 < 2)
        {
            return;
        }

        if (D_57c0[param_1] != 0)
        {
            D_57c0[param_1]--;
            return;
        }

        ULTIMA_6e60(D_ba14[D_589e]._3, param_1);
        return;

    default:
        return;

    case 0x1a:
    case 0x24:
        cVar2 = --D_57db;
        break;
    case 0x1c:
        cVar2 = --D_57dd;
        break;
    }

    if (cVar2 == 0)
    {
        cVar2 = SJOG_1b34(param_1);
        D_57c0[param_1] += cVar2;
    }
}

// NOT MATCHING
int COMSUBS_09fc(int param_1)
{
    int uVar1;

    uVar1 = D_58a8[param_1];
    if (uVar1 != 0xff && D_ba14[uVar1]._2 != 0 && ULTIMA_5646(uVar1) != 0 && (D_ba14[uVar1]._2 & 0xc) == 0 &&
        D_587a != 'T' && COMSUBS_04d4(param_1, uVar1) == 1)
    {
        ULTIMA_16ba_PrintChar(10);
        COMSUBS_0094(uVar1);
        ULTIMA_1850_PrintString(/*0x9a70*/ " interferes!\n");
        return 1;
    }

    return 0;
}

// NOT MATCHING
void COMSUBS_0a68(int param_1, int param_2, int param_3)
{
    undefined2 uVar3;
    int iVar4;
    int iVar6;
    undefined2 uVar7;

    if (param_2 != 0x1a && param_2 != 0x1c && param_2 != 0x24 && param_2 != 0x13 && param_2 != 0x11 ||
        COMSUBS_09fc(param_1) == 0)
    {
        ULTIMA_1850_PrintString(/*0x9a7e*/ "Aim! ");

        iVar4 = COMSUBS_0504(param_1, D_1664[param_2]);
        if (iVar4 != 0)
        {
            ULTIMA_43ae_AudioSweepTone(0x514, 300, 5, 100);
            if (param_2 == 0x13)
            {
                if (D_57c0[0x13] == '\0')
                {
                    ULTIMA_6e60(D_ba14[D_589e]._3, 0x13);
                }
                else
                {
                    D_57c0[0x13]--;
                }
            }

            D_5c5a[D_ba14[param_1]._4]._7 = 0xff;
            iVar6 = COMSUBS_0748(D_5899, D_589a);
            if (iVar6 < 0)
            {
                uVar7 = 1;
            }
            else
            {
                D_5c5a[D_ba14[param_1]._4]._7 = iVar6;
                COMSUBS_097c(param_2, iVar4);
                uVar7 = COMBAT_14d6(iVar6, param_1, -D_588f, param_2);
            }

            iVar4 = COMSUBS_0822(param_1, D_5899, D_589a, uVar7, param_3);
            uVar7 = D_5876;
            uVar3 = D_5878;
            if (iVar4 < 0)
            {
                if (iVar6 > -1)
                {
                    ULTIMA_16ba_PrintChar(10);
                    COMSUBS_00d2(iVar6);
                }
            }
            else
            {
                ULTIMA_3564(iVar4);
                ULTIMA_16ba_PrintChar(10);
                COMBAT_194a(iVar4, param_1);
                COMSUBS_0312(iVar4, param_1);
            }

            if (param_2 == 0x26)
            {
                COMSUBS_12de(uVar7, uVar3, D_ba14[param_1]._6, D_ba14[param_1]._7, param_3);
            }
        }
    }
}

// NOT MATCHING
void COMSUBS_0bf8(int param_1, int param_2, int param_3)
{
    int iVar1;

    ULTIMA_43ae_AudioSweepTone(400, 0x2ee, 5, 0x96);
    ULTIMA_16ba_PrintChar(10);
    iVar1 = COMBAT_14d6(param_2, param_1, -D_588f, param_3);
    if (iVar1 == 0)
    {
        COMSUBS_00d2(param_2);
    }
    else
    {
        ULTIMA_3564(param_2);
        COMBAT_194a(param_2, param_1);
        COMSUBS_0312(param_2, param_1);
    }
}

// NOT MATCHING
void COMSUBS_0c52(int param_1, int param_2)
{
    char cVar1;
    undefined1 uVar2;
    int iVar3;
    int iVar4;
    undefined1 uStack_8;

    if (param_2 > 0x22)
    {
        D_5890 = 1;
    }

    if ((D_ba14[param_1]._2 & 0x80) == 0)
    {
        cVar1 = D_159c[D_ba14[param_1]._3];
        if (cVar1 == 1)
        {
            cVar1 = 0;
        }
        uVar2 = D_15cc[D_ba14[param_1]._3];
    }
    else
    {
        if (param_2 == 0xff)
        {
            cVar1 = 0;
        }
        else
        {
            cVar1 = D_1664[param_2];
        }
        uVar2 = D_169c[param_2];
    }

    if (cVar1 == 0)
    {
        ULTIMA_1850_PrintString(/*0x9a84*/ "Aim! ");
        iVar3 = COMSUBS_0504(param_1, 1);
        iVar4 = COMSUBS_0748(D_5899, D_589a);
        if ((iVar3 == 0) || (iVar4 == -1))
        {
            ULTIMA_1850_PrintString(/*0x9a8a*/ "Nothing!\n");
        }
        else
        {
            uStack_8 = (undefined1)iVar4;
            D_5c5a[D_ba14[param_1]._4]._7 = uStack_8;
            COMSUBS_0bf8(param_1, iVar4, param_2);
        }
    }
    else
    {
        COMSUBS_0a68(param_1, param_2, uVar2);
    }
}

// NOT MATCHING
void COMSUBS_0d3c(int param_1, int param_2)
{
    if (param_1 != 0xff && D_15fc[param_1] != 0)
    {
        if (param_2 > 1)
        {
            D_588f = 0;
            D_5890 = 0;
            ULTIMA_16ba_PrintChar(10);
            ULTIMA_1850_PrintString(D_17f6[param_1]);
            ULTIMA_1850_PrintString(/*0x9a94*/ ":\n");
        }

        D_589d = (undefined1)param_1;
        ULTIMA_1850_PrintString(/*0x9a98*/ "Attack-");
        COMSUBS_0c52(D_589e, param_1);
    }
}

// NOT MATCHING
// attack
void COMSUBS_0d96(int param_1, int param_2)
{
    int local_4;

    if ((D_ba14[param_1]._2 & 0x80) == 0 || param_2 == 0)
    {
        D_589d = 0xff;
        ULTIMA_1850_PrintString(/*0x9aa0*/ "Attack-");
        COMSUBS_0c52(param_1, 0xff);
    }
    else
    {
        local_4 = D_ba14[param_1]._3;
        if (1 < param_2)
        {
            ULTIMA_1bf2_SetTextPosition(0, ULTIMA_1cee_GetCurrentTextY());
            ULTIMA_16ba_PrintChar(0x20);
        }
        COMSUBS_0d3c(D_55a8_party[local_4]._19, param_2);
        COMSUBS_0d3c(D_55a8_party[local_4]._1b, param_2);
        COMSUBS_0d3c(D_55a8_party[local_4]._1c, param_2);
    }
}

// NOT MATCHING
void COMSUBS_0e26(int param_1, int param_2, int param_3, int param_4, u8* param_5, u8* param_6)
{
    int iVar1;
    int local_1c;
    int local_18;
    int local_14;
    int local_10;
    int local_c;
    int local_8;

    local_14 = 1;
    local_18 = 1;
    local_1c = 0x148;

    if (param_3 == param_1)
    {
        local_8 = 0x4b00;
    }
    else
    {
        local_8 = ((param_4 - param_2) * 100) / (param_3 - param_1);
    }

    if (local_8 < 0)
    {
        local_8 = -local_8;
    }

    if (param_3 < param_1)
    {
        local_14 = -1;
    }

    if (param_4 < param_2)
    {
        local_18 = -1;
    }

    local_c = param_3 - param_1;
    if (local_c < 0)
    {
        local_c = -local_c;
    }

    local_10 = param_4 - param_2;
    if (local_10 < 0)
    {
        local_10 = -local_10;
    }

    *param_5 = (undefined1)param_1;
    *param_6 = (char)param_2;
    iVar1 = local_8;
    while (param_6++, param_5++, local_c > 0 || local_10 > 0)
    {
        do
        {
            if (iVar1 <= 0 || local_10 <= 0)
                break;

            iVar1 -= 100;
            param_2 += local_18;
            *param_6 = param_2;
            param_6++;
            local_10--;
            *param_5 = param_1;
            param_5++;
            local_1c--;
        } while (local_1c != 0);

        if (local_1c == 0)
            break;

        local_c--;
        iVar1 += local_8;

        param_1 += local_14;

        *param_6 = param_2;
        *param_5 = param_1;
        local_1c--;
    }

    *param_5 = 0xff;
    *param_6 = 0xff;
}

// NOT MATCHING
void COMSUBS_0f4a(byte param_1, byte param_2, int param_3, int param_4, u8* param_5, u8* param_6)
{
    char* pcVar1;
    char* pcVar2;
    uint uVar3;
    uint uVar4;
    int iVar5;
    int iVar6;
    int iVar7;
    int iVar8;
    byte* pbVar9;
    char* pcVar10;
    int iVar11;
    char* pcVar12;
    int iVar13;
    int local_34;
    int local_30;
    int local_1e;
    int local_1c;
    undefined1* local_18;
    int local_16;
    s8* local_e;
    s8* local_a;
    int local_4;

    local_1c = 1;
    local_1e = 1;
    local_4 = -1;

#if !defined(TARGET_DOS16)
    local_e = NULL;
    local_a = NULL;
#endif

    if (param_4 == 2)
    {
        local_e = D_2188;
        local_a = D_2188;
    }

    if (param_4 > 2)
    {
        local_e = D_2188 + 0x10;
        local_a = D_2188 + 0x10;
    }

    switch (param_3)
    {
    case 1:
        local_e++;
        break;
    case 2:
        local_a++;
        local_1c = -1;
        break;
    case 3:
        local_e++;
        local_1e = -1;
        local_1c = -1;
        break;
    case 4:
        local_a++;
        local_1e = -1;
        break;
    }

    ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
    switch (param_4)
    {
    case 0:
        pbVar9 = param_5 - 4;
        local_18 = param_6 - 4;
        local_16 = 0;
        do
        {
            if (*pbVar9 == 0xff)
                break;

            ULTIMA_0b10_GRAP_Line(*pbVar9, *local_18, *pbVar9 + 1, *local_18);
            pbVar9 = pbVar9 + 1;
            local_18 = local_18 + 1;
            local_16 = local_16 + 1;
        } while (local_16 < 9);
        break;

    case 1:
        uVar3 = (uint)param_2;
        uVar4 = (uint)param_1;
        ULTIMA_0b10_GRAP_Line(uVar4 - 1, uVar3 - 2, uVar4 + 1, uVar3 - 2);
        iVar13 = uVar4 + 2;
        iVar11 = uVar4 - 2;
        ULTIMA_0b10_GRAP_Line(iVar11, uVar3 - 1, iVar13, uVar3 - 1);
        ULTIMA_0b10_GRAP_Line(iVar11, uVar3, iVar13, uVar3);
        ULTIMA_0b10_GRAP_Line(iVar11, uVar3 + 1, iVar13, uVar3 + 1);
        ULTIMA_0b10_GRAP_Line(uVar4 - 1, uVar3 + 2, uVar4 + 1, uVar3 + 2);
        break;

    case 2:
        local_34 = 4;
        do
        {
            pcVar1 = local_a;
            pcVar12 = local_a + 2;

            pcVar2 = local_e;
            pcVar10 = local_e + 2;

            local_a = local_a + 4;
            local_e = local_e + 4;

            ULTIMA_0b10_GRAP_Line(*pcVar1 * local_1c + (uint)param_1, *pcVar2 * local_1e + (uint)param_2,
                               *pcVar12 * local_1c + (uint)param_1, *pcVar10 * local_1e + (uint)param_2);
            local_34 = local_34 + -1;
        } while (local_34 != 0);
        break;
    case 3:
        iVar13 = D_13ae;
        goto LAB_0000_f2f7;
    case 4:
        iVar13 = D_13b2_frame_color;
        goto LAB_0000_f2f7;
    case 5:
        iVar13 = D_13b4;
        goto LAB_0000_f2f7;
    case 6:
        iVar13 = D_13b6;
    LAB_0000_f2f7:
        local_4 = iVar13 + 8;
        break;
    case 7:
        for (local_30 = 0; local_30 < 7; local_30++)
        {
            pcVar12 = local_a;
            pcVar10 = local_e;
            ULTIMA_0b10_GRAP_Line(*pcVar12 * local_1c + (uint)param_1, *pcVar10 * local_1e + (uint)param_2,
                               pcVar12[2] * local_1c + (uint)param_1, pcVar10[2] * local_1e + (uint)param_2);
            local_e = pcVar10 + 4;
            local_a = pcVar12 + 4;
        }

        uVar3 = (uint)param_2;
        uVar4 = (uint)param_1;
        ULTIMA_0c64_GRAP_30_Pset(pcVar12[4] * local_1c + uVar4, pcVar10[4] * local_1e + uVar3);
        ULTIMA_0c64_GRAP_30_Pset(pcVar12[6] * local_1c + uVar4, pcVar10[6] * local_1e + uVar3);
        ULTIMA_0c64_GRAP_30_Pset(pcVar12[8] * local_1c + uVar4, pcVar10[8] * local_1e + uVar3);
        break;
    }

    if (local_4 >= 0)
    {
        iVar13 = -1;
        iVar11 = 1;
        for (local_30 = 0; local_30 < 0x30; local_30++)
        {
            iVar5 = ULTIMA_2092_RandomRange(0, 0xf);
            iVar6 = ULTIMA_2092_RandomRange(0, 0xf);
            iVar7 = ULTIMA_2092_RandomRange(0, 1);
            iVar8 = ULTIMA_2092_RandomRange(0, 1);
            if (iVar7 != 0)
            {
                iVar13 = -iVar13;
            }
            if (iVar8 != 0)
            {
                iVar11 = -iVar11;
            }
            ULTIMA_0a70_GRAP_2d_SetPenColor(local_4);
            ULTIMA_0c64_GRAP_30_Pset((uint)D_21ba[iVar5] * iVar13 + (uint)param_1,
                               (uint)D_21ba[iVar6] * iVar11 + (uint)param_2);
        }
    }
}

// NOT MATCHING
int COMSUBS_12de(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    byte* pbStack_12;
    byte* pbStack_e;
    int local_c;
    uint uStack_a;

    local_c = 0xd;
    uStack_a = 0;
    ULTIMA_0f6e_GRAP_1b_TransferFullscreen(0, 1);

    memset(D_a728, 0xff, 0x100);
    memset(D_a872, 0xff, 0x100);

    COMSUBS_0e26(param_1 * 0x10 + 0x10, param_2 * 0x10 + 0x10, param_3 * 0x10 + 0x10, param_4 * 0x10 + 0x10, D_a728,
                   D_a872);

    pbStack_e = (byte*)D_a728;
    pbStack_12 = (byte*)D_a872;

    if (D_5893_map_id == 0 || 0x20 < D_5893_map_id)
    {
        if (param_5 == 7)
        {
            local_c = 8;
        }
    }
    else
    {
        local_c = 6;
    }

    if (param_5 == 0)
    {
        pbStack_e = (byte*)D_a728 + 4;
        pbStack_12 = (byte*)D_a872 + 4;
    }

    while (*pbStack_e != 0xff)
    {
        uStack_a = (uStack_a & 3) + 1;
        ULTIMA_3fb4(*pbStack_e, *pbStack_12);
        if (D_5876 == -1)
        {
            return 1;
        }

        COMSUBS_0f4a(*pbStack_e, *pbStack_12, uStack_a, param_5, pbStack_e, pbStack_12);
        ULTIMA_20c8_SomeDelay(1, 0x28);
        ULTIMA_0ace_GRAP_18_TransferArea(1, 0, (*pbStack_e & 0xf8) - 8, *pbStack_12 - 8, (*pbStack_e & 0xf8) + 0xf, *pbStack_12 + 0xf);

        pbStack_e += local_c;
        pbStack_12 += local_c;

        if (D_a872 < pbStack_e)
        {
            return 1;
        }

        if (*pbStack_e == 0xff)
            break;

        if (ULTIMA_3f6e(D_5876, D_5878) == 0 && (param_1 != D_5876 || param_2 != D_5878))
        {
            return 0;
        }
    }

    return 1;
}
