#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>

int F_TALK_0054(int a, int b)
{
    printf("F_TALK_0054(%d,%d)", a, b);
}

int F_TALK_031e(int a)
{
    printf("F_TALK_031e(%d)", a);
}

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

