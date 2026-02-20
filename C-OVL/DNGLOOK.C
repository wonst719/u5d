#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>

void F_DNGLOOK_0000_look_cmd_in_dungeon(void) { puts("F_DNGLOOK_0000_look_cmd_in_dungeon"); }

void F_DNGLOOK_06a8_view_cmd(void) { puts("F_DNGLOOK_06a8_view_cmd"); }

// OK P1 (NOT MATCH: TEST)
uint F_DNGLOOK_08d4(int param_1)
{
    uint local_6;
    uint local_c;
    uint local_a;
    u8 local_8;
    u8 local_4;

    local_6 = (int)D_5893_map_id - 0x21;
    if (1 <= local_6) {
        local_6--;
    }

    // 08ed
    local_c = local_6 * 0x10 + param_1;
    local_a = param_1 / 8;
    local_4 = D_58e0[local_a];
    local_8 = 1 << (local_c & 7);

    return (local_8 & local_4) != 0;
}

void F_DNGLOOK_093a(void)
{
    byte* ptr = D_595a;
    int size = 0x200;

    do
    {
        if ((*ptr & 0xf0) == 0xf0)
        {
            int iVar1 = F_DNGLOOK_08d4(*ptr & 0xf);
            if (iVar1 != 0)
            {
                *ptr &= 0xaf;
            }
        }
        ptr++;
        size--;
    } while (size != 0);
    return;
}

void F_DNGLOOK_109e() { puts("F_DNGLOOK_109e"); }

void F_DNGLOOK_1130() { puts("F_DNGLOOK_1130"); }
