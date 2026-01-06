#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>

void F_TOWN_10da();
int F_NPC_12e0(int a, char b);

int F_TALK_0f32(byte param_1);
void F_TALK_127e(int a);

int F_TALK_0054(int a, int b)
{
    printf("F_TALK_0054(%d,%d)\n", a, b);
}

void F_TALK_00e6(int a)
{
    printf("F_TALK_00e6(%d)\n", a);
}

int F_TALK_01e2()
{
    puts("F_TALK_01e2");
}

// TODO: MATCH
int F_TALK_031e(int param_1)
{
    int iVar1;

    FUN_1000_16ba_print_char(10);
    D_bcdc = param_1;

    if (D_5d5e[param_1]._0[D_5f5e[param_1]._e] == 4)
    {
        D_5d5e[param_1]._0[D_5f5e[param_1]._e] = 1;
    }
    else if (D_5c5a[D_5f5e[param_1]._c]._0_tile == 'p' && ((D_5f5e[param_1]._e & 1) == 0 || (D_5f5e[param_1]._a) == 0))
    {
        FUN_1000_1850_print_string("The guard offers\nno response!\n");
        return 0;
    }

    iVar1 = D_5f5e[param_1]._a;
    if (iVar1 == 0)
    {
        FUN_1000_1850_print_string("No response!\n");
        return 0;
    }
    else
    {
        if (iVar1 < 0x80)
        {
            F_TALK_127e(iVar1);
            return 0;
        }
        if (iVar1 == 0xfd)
        {
            FUN_1000_16ba_print_char(0x22);
            FUN_1000_1850_print_string("Don't hurt me!\nPlease go away!");
            FUN_1000_16ba_print_char(0x22);
            FUN_1000_16ba_print_char(10);
            return 0;
        }
        if (iVar1 == 0xfe)
        {
            F_TOWN_10da();
            return 0;
        }
        if (iVar1 == 0xff)
        {
            return F_TALK_01e2();
        }

        if ((D_5f5e[param_1]._e & 1) == 0 || (F_NPC_12e0(D_bcdc, D_587f) & 1) == 0)
        {
            FUN_1000_1850_print_string("A merchant says:\n\"Come see me at\nmy shoppe, ");
            FUN_1000_1850_print_string("when\nit's open!\"\n");
            return 0;
        }
        else
        {
            F_TALK_00e6(iVar1);
            return 0;
        }
    }
}

// TODO: MATCH
int F_TALK_041c_talk_cmd(void)
{
    int iVar1;
    int iVar2;
    int iVar3;
    undefined2 uVar4;
    char* pcVar5;
    int iVar6;
    int iStack_6;

    if (FUN_1000_35ec_select_direction() != 0)
    {
        iVar3 = D_5876;
        iStack_6 = iVar3 + (uint)D_5896_map_x;
        iVar1 = D_5878 + (uint)D_5897_map_y;
        iVar6 = iStack_6;
        if (FUN_1000_368e(iStack_6, iVar1, D_5895_map_level) == 0 && F_TALK_0054(iStack_6, iVar1) != 0)
        {
            iStack_6 += iVar3;
            iVar1 += iVar6;
        }

        if (FUN_1000_368e(iStack_6, iVar1, D_5895_map_level) == 0)
        {
            FUN_1000_1850_print_string("\nNobody's here!\n");
        }
        else
        {
            uVar4 = F_TOWN_011e(D_5876);
            pcVar5 = FUN_1000_4402_get_address_of_tile_id(iStack_6, iVar1);
            if (*pcVar5 != 0x9d)
            {
                if (*pcVar5 != 0xab)
                {
                    return F_TALK_031e(uVar4);
                }

                FUN_1000_1850_print_string("\n\"Zzzzzz...\"\n");
            }
            else
            {
                FUN_1000_1850_print_string("\nNo response!\n");
            }
        }
    }

    return 0;
}

// OK P1
void F_TALK_04d2(void)
{
    F_TALK_0f32(0x8d);
}

// OK P1
void F_TALK_04da(void)
{
    F_TALK_0f32(0xa2);
}

// TODO: MATCH
void F_TALK_04e2(void)
{
    byte bVar1;
    undefined1 uVar2;
    uint uVar4;

    if (D_4af1 != 0)
    {
        uVar4 = 0;
        while (uVar4 < D_4af1)
        {
            FUN_1000_1c9e_get_char_segment((D_bce4[uVar4] & 0x80) == 0);
            bVar1 = D_bce4[uVar4] & 0x7f;
            uVar4 = uVar4 + 1;

            if (FUN_1000_1f12_get_current_text_column() != 0 || bVar1 != 0x20)
            {
                if ((D_4af3 < 0xf) || (bVar1 != 10))
                {
                    if (bVar1 != 10)
                    {
                        uVar2 = FUN_1000_1f12_get_current_text_column();
                        D_4af3 = uVar2;
                    }
                    FUN_1000_16ba_print_char(bVar1);
                }
                else
                {
                    D_4af3 = 0;
                }
            }
        }

        D_4af1 = 0;
        FUN_1000_1c9e_get_char_segment(0);
    }
}

// OK P1
void F_TALK_0574(byte param_1)
{
    if (D_4af1 != 0x10)
    {
        D_bce4[D_4af1++] = param_1;

        if (param_1 != 0x8a && param_1 != 0xa0)
        {
            return;
        }

        if (FUN_1000_1f12_get_current_text_column() + (uint)D_4af1 >= 0x12)
        {
            FUN_1000_16ba_print_char(10);
        }
    }

    F_TALK_04e2();
}


// TODO: MATCH
int F_TALK_0728(char param_1, char param_2)
{
    char* pcVar1;
    undefined2 uVar2;
    char* pcVar3;

    pcVar3 = D_bcde;
    do
    {
        pcVar1 = pcVar3;
        pcVar3++;
        if (*pcVar1 == param_1)
        {
            uVar2 = 1;
            goto LAB_0000_0741;
        }
    } while (*pcVar1 != param_2);
    uVar2 = 0;

LAB_0000_0741:
    D_bcde = pcVar3;
    return uVar2;
}

// TODO: MATCH
void F_TALK_075a(int param_1)
{
    D_bcde = D_b21e;

    if (param_1 != 0)
    {
        for (; param_1 != 0; param_1--)
        {
            F_TALK_0728(0, 0x90);
        }
    }
}

int F_TALK_0f32(byte param_1);

// TODO: MATCH
int F_TALK_0788(void)
{
    do
    {
        if (*D_bcde == '\0')
        {
            return 0;
        }
    } while (F_TALK_0f32(*D_bcde++) == 0);

    return 1;
}

// OK P1
int F_TALK_07aa(int param_1)
{
    F_TALK_075a(param_1);
    return F_TALK_0788();
}

// TODO: asm? optimization?
int F_TALK_07be() { puts("F_TALK_07be"); }

void F_TALK_07e4() { puts("F_TALK_07e4"); }

int F_TALK_080a() { puts("F_TALK_080a"); }

int F_TALK_09d8() { puts("F_TALK_09d8"); }

void F_TALK_0a2c() { puts("F_TALK_0a2c"); }

int F_TALK_0a3c() { puts("F_TALK_0a3c"); }

int F_TALK_0a54(int a) { printf("F_TALK_0a54(%d)\n", a); }

int FUN_1000_6f1e(char* a, char* b);

// TODO: MATCH
int F_TALK_0b04(void)
{
    int iVar2;
    int iVar3;
    byte bStack_4;

    do
    {
        D_4af2 = 0;
        FUN_1000_1850_print_string("Your interest?\n:");
        F_TALK_0a2c();
        if (D_bcf8[0] == '\0')
        {
            FUN_1000_1850_print_string("BYE\n\n");
            return F_TALK_0a3c();
        }
        F_TALK_04d2();
        F_TALK_04d2();
        iVar3 = -1;
        for (bStack_4 = 0; bStack_4 < 0x22; bStack_4++)
        {
            iVar2 = FUN_1000_6f1e(D_4aa8[bStack_4], D_bcf8);
            if (iVar2 != -1 && (iVar2 == 0 || D_bcf8[iVar2 - 1] == ' '))
            {
                iVar3 = F_TALK_0a54(bStack_4);
                if (iVar3 == 0)
                    break;
                if (iVar3 == 1)
                {
                    return 1;
                }
            }
        }

        if (iVar3 != 0)
        {
            if (F_TALK_09d8() == 0)
            {
                FUN_1000_1850_print_string("\"I cannot help thee with that.");
                F_TALK_04da();
                F_TALK_04d2();
                F_TALK_04d2();
            }
            else
            {
                F_TALK_04da();
                iVar3 = F_TALK_07aa(D_bcf6 * 2 + 6);
                if (iVar3 != 0)
                {
                    return 1;
                }
                F_TALK_04da();
                F_TALK_04d2();
                F_TALK_04d2();
            }
        }
    } while (1);
}

int F_TALK_0c5c() { puts("F_TALK_0c5c"); }

// NOT MATCHING (u32 operation)
// check npc killed flag
int F_TALK_0d7a(int param_1)
{
    return (*(u32*)&D_5b5a[(D_5893_map_id - 1) * 4] & (((u32)1) << ((byte)param_1 & 0x1f))) != 0;
}

int F_TALK_0dbe(int param_1) { printf("F_TALK_0dbe(%d)\n", param_1); }

void F_TALK_0e78() { puts("F_TALK_0e78"); }

F_TOWN_0958();

// OK P1
int F_TALK_0f32(byte param_1)
{
    char* local_4;
    int local_6;
    byte* pbVar5;

    if (D_4aee != 0)
    {
        return F_TALK_0dbe(param_1);
    }

    // 0f4c
    D_4aef = 0;
    if ((param_1 == 0xa2) && (D_4af4 == 0xa2))
    {
        // 0f5e
        return 0;
    }

    // 0f64
    switch (param_1)
    {
    case 0x81:
        // 0f86
        F_TALK_07e4();
        break;
    case 0x82:
        // 0f8c
        return 1;
    case 0x83:
        // 0f92
        for (local_6 = 0; local_6 < 0x1c; local_6++)
        {
            FUN_1000_5910_update_map();
            if (FUN_1000_1d5e_peek_keystroke() != 0)
                break;
            FUN_1000_20fa_wait_ticks(1);
        }
        FUN_1000_1b16_clear_keyboard_buffer();
        return 0; // -> 0f5e
    case 0x84:
        // 0fb6
        return F_TALK_080a(); // -> 1114
    case 0x87:
        // 0fbc
        local_4 = D_bcde;
        if (F_TALK_07be() != 0)
        {
            return 1;
        }
        D_bcde = local_4;
        return 0; // -> 0f5e
    case 0x88:
        // 0fd2
        F_TALK_0e78();
        return 0; // -> 0f5e
    case 0x89:
        // 0fd8
        FUN_1000_3ef0(&D_5888, 1, 99);
        return 0; // -> 0f5e
    case 0x8a:
        // 0fea
        FUN_1000_3f36(&D_5888, 1);
        return 0; // -> 0f5e
    case 0x8b:
        // 0ff8
        F_TOWN_0958();
        return 0; // -> 0f5e
    case 0x8e:
        // 0ffe
        D_4af0 ^= 0x80;
        return 0; // -> 0f5e
    case 0xff:
        // 1006
        F_TALK_04e2();
        return F_TALK_0b04(); // -> 1114
    case 0x8f:
        // 1010
        FUN_1000_266c_get_ch();
        return 0; // -> 0f5e
    case 0xfe:
    case 0x85:
    case 0x86:
    case 0x8c:
        // 1016
        D_4aee = param_1;
        return 0;
    case 0x91:
    case 0x92:
    case 0x93:
    case 0x94:
    case 0x95:
    case 0x96:
    case 0x97:
    case 0x98:
    case 0x99:
    case 0x9a:
    case 0x9b:
    case 0x9c:
    case 0x9d:
    case 0x9e:
    case 0x9f:
        // 1020
        D_bcf4 = param_1;
        return F_TALK_0c5c(); // -> 1114
        // ----------
    default:
        // 10ce
        if (param_1 < 0x81)
        {
            F_TALK_0574(0xa0);

            pbVar5 = D_24ea[param_1 - 1];
            while (*pbVar5 != 0)
            {
                F_TALK_0574(*pbVar5++ | 0x80);
            }

            if (*D_24ea[param_1 - 1] == 0)
            {
                F_TALK_0574(param_1);
                return 0; // -> 0f5e
            }

            D_4af5 = 1;
        }
        else
        {
            // 1062
            param_1 |= 0x80;
            if (param_1 == 0x8d)
            {
                param_1 = 0x8a;
            }

            D_4af4 = param_1 &= D_4af0;

            if (D_4af5 != 0)
            {
                F_TALK_0574(0xa0);
            }

            F_TALK_0574(param_1);
            D_4af5 = 0;
        }
        break;
    }

    return 0;
}

// TODO: MATCH
int F_TALK_111c(void)
{
    FUN_1000_1850_print_string("You see ");

    if (F_TALK_07aa(1) == 0)
    {
        F_TALK_04d2();
        F_TALK_04d2();
        if (F_TALK_0d7a(D_bcdc) == 0)
        {
            FUN_1000_207e_srand(FUN_1000_2056_get_time());
            if (FUN_1000_2092_random_range(0, 1) != 0)
            {
                FUN_1000_1850_print_string("\"I am called ");
                if (F_TALK_07aa(0) != 0)
                    return 1;

                F_TALK_04da();
                F_TALK_04d2();
                F_TALK_04d2();

                return 0;
            }
        }
        else
        {
            F_TALK_04da();
            if (F_TALK_07aa(2) != 0)
                return 1;

        LAB_0000_116c:
            F_TALK_04da();
            F_TALK_04d2();
            F_TALK_04d2();
        }

        return 0;
    }
    else
    {
        return 1;
    }
}

void F_TALK_1180() { puts("F_TALK_1180"); }

// TODO: MATCH
void F_TALK_127e(int param_1)
{
    uint uVar1;
    int iVar2;
    u16* piVar3;

    uVar1 = (D_5893_map_id - 1) >> 3;
    FUN_1000_256e_read_file_from_disk(D_4aa0[uVar1], D_b21e, 0x200, 0);

    piVar3 = (u16*)(D_b21e + 2);
    for (iVar2 = 1; (*piVar3 != param_1 && (iVar2 <= *(u16*)D_b21e)); iVar2++) // ?
    {
        piVar3++;
    }

    FUN_1000_256e_read_file_from_disk(D_4aa0[uVar1], D_b21e, 0x400, piVar3[1]);

    if (F_TALK_111c() == 0)
    {
        if (F_TALK_0b04() == 0)
        {
            F_TALK_0a3c();
        }
    }

    F_TALK_1180();
}

