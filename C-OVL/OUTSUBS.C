#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <string.h>

// OK P1 (complete)
int F_OUTSUBS_0000(uint param_1)
{
    int local2_4;
    int local1_6 = 1;

    param_1 = (byte)(param_1 >> 8);

    for (local2_4 = 0; local2_4 < 8; local2_4++)
    {
        if (D_3866[local2_4] == param_1)
        {
            local1_6 = D_58d0[local2_4] == 0;
            break;
        }
    }

    return local1_6;
}

// OK P1 (complete)
int F_OUTSUBS_004a(int param_1)
{
    int local2_4;
    int local1_6 = 0;

    param_1 >>= 8;

    for (local2_4 = 0; local2_4 < 8; local2_4++)
    {
        // 0063
        if (D_386e[local2_4] == param_1)
        {
            local1_6 = 0x7f < D_58d8[local2_4];
            break;
        }
    }

    return local1_6;
}

// OK P1
void F_OUTSUBS_0098(char* param_1/*file_name*/, int param_2/*layer?*/, uint param_3)
{
    int local_c;
    int local_a;
    uint local_8;
    uint local_6;
    uint local_4;

    if (*param_1 == 'B') // "BRIT.DAT"
    {
        local_4 = D_3876[(byte)(param_3 >> 8)];
        if (local_4 == 0xff)
        {
            memset(&D_6608[param_2 * 0x100], 1, 0x100);
            return; // -> 01ac
        }

        // 00d4
        local_4 <<= 8;
    }
    else
    {
        // 00dc
        local_4 = param_3;
    }

    // 00e2
    if (D_5895_map_level != 0)
    {
        FUN_1000_251e_switch_disks(5);
    }

    // 00f0
    FUN_1000_256e_read_file_from_disk(param_1, D_6608 + param_2 * 0x100, 0x100, local_4);
    local_6 = param_3 >> 4 & 0xf0;
    local_8 = param_3 >> 8 & 0xf0;

    for (local_c = 0; local_c < 0x10; local_c++)
    {
        // 0125
        for (local_a = 0; local_a < 0x10; local_a++)
        {
            switch (D_6608[local_a + param_2 * 0x100 + local_c * 0x10])
            {
            case 0x16:
            case 0x17:
            case 0x18:
                // 012c
                if (F_OUTSUBS_0000(param_3) != 0)
                {
                    *FUN_1000_4402_get_address_of_tile_id(local_a + local_6, local_c + local_8) = 0xdf;
                }
                break;
            case 0x19:
                // 017d
                if (F_OUTSUBS_004a(param_3) != 0)
                {
                    *FUN_1000_4402_get_address_of_tile_id(local_a + local_6, local_c + local_8) = 0x1a;
                }
                break;
            }
        }
    }
}

// OK P1
void F_OUTSUBS_01b4(int param_1, int param_2)
{
    uint local_c;
    int local_a;
    byte* local_8;
    int local_6;
    char* local_4;

    local_a = D_589b * 0x10 + D_589c * 0x100;

    if (D_589b == 0xf0)
    {
        local_6 = -0xf00; // 0xf100?
    }
    else
    {
        // 01dc
        local_6 = 0x100;
    }

    // 01e1
    if (D_5895_map_level > 0x7f)
    {
        local_4 = "UNDER.DAT"; // 3976
    }
    else
    {
        local_4 = "BRIT.DAT"; // 3980
    }

    // 01f5
    if (param_1 == -1 || param_2 == -1)
    {
        F_OUTSUBS_0098(local_4, 0, local_a);
    }
    // 020d
    if (param_1 == 1 || param_2 == -1)
    {
        F_OUTSUBS_0098(local_4, 1, local_a + local_6);
    }
    // 022a
    if (param_1 == -1 || param_2 == 1)
    {
        F_OUTSUBS_0098(local_4, 2, local_a + 0x1000);
    }
    // 0247
    if (param_1 == 1 || param_2 == 1)
    {
        F_OUTSUBS_0098(local_4, 3, (local_a + local_6) + 0x1000);
    }

    // 0267
    local_8 = FUN_1000_0402_memchr(D_6608, 0x1b, 0x400);
    if (local_8 == 0)
    {
        D_217e = D_2180 = 0xffff; // -1?
    }
    else
    {
        // 028c
        local_c = (int)(local_8 - D_6608);
        D_217e = local_c & 0xf;
        D_2180 = ((byte)local_c & 0xf0) >> 4;
        if ((local_c & 0x100) != 0)
        {
            D_217e += 0x10;
        }
        if ((local_c & 0x200) != 0)
        {
            D_2180 += 0x10;
        }
    }
}

// OK P1
char* F_OUTSUBS_0368_GetWorldSavefile()
{
	if (D_5895_map_level == 0)
		return "BRIT.OOL";
	else
		return "UNDER.OOL";
}

F_OUTSUBS_0458() {}
F_OUTSUBS_0566() { puts("F_OUTSUBS_0546"); }
F_OUTSUBS_05ee() {}
F_OUTSUBS_05fc() {}
