#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

F_DUNGEON_0000() {}
F_DUNGEON_0134(int param_1) {}
F_DUNGEON_01d2_print_walk_dir() {}
F_DUNGEON_0332() {}
F_DUNGEON_03d6() {}
F_DUNGEON_06c4_process_command() {}
F_DUNGEON_0c76(int a, int b) {}
F_DUNGEON_1be0() {}

void F_DNGLOOK_093a();
void F_DNGLOOK_1130();
void F_DNGLOOK_109e();

void F_BLCKTHRN_0910_death();

// OK P1 (NOT MATCHING: SI)
void F_DUNGEON_0e2e_MainLoop(int param_1)
{
    register int si, di;
    int local_e;
    int local_c; // -> si
    int local_a;
    int local_8;
    u8 local_6; // -> di
    int local_4;
    u8 local_2;

#ifdef _WIN32
    local_a = 0;
#endif

    local_c = 1;
    local_e = 0;
    local_4 = 0;
    D_bb17 = 2;
    F_DNGLOOK_093a();
    local_6 = D_595a[(D_5895_map_level & 0xff) * 0x40 + D_5897_map_y * 8 + D_5896_map_x];
    local_6 &= 0xf0;
    F_DUNGEON_0332();
    F_DUNGEON_01d2_print_walk_dir();
    local_8 = D_5893_map_id - 0x20;
    if (((local_8 == 1) || (local_8 == 4)) || (local_8 == 5))
    {
        // 0e95
        D_bb14 = 0x4f;
        D_bb15 = 0x45;
        D_6604 = 3;
    }
    else
    {
        // 0ea6
        D_bb14 = 0x4d;
        D_bb15 = 5;
        if ((local_8 == 6) || (local_8 == 7))
        {
            // 0ebc
            D_6604 = 2;
        }
        else
        {
            // 0ec4
            D_6604 = 1;
        }
    }

    // 0ec9
    if ((local_6 == 0xa0) || (local_6 == 0xf0))
    {
        // 0ed5
        F_DNGLOOK_1130();
        F_DUNGEON_0000(D_595a[(D_5895_map_level & 0xff) * 0x40 + D_5897_map_y * 8 + D_5896_map_x]);
    }

    if (0x20 < D_5893_map_id)
    {
        F_DNGLOOK_109e(param_1);
        F_DUNGEON_0134(param_1);
        F_DUNGEON_1be0();
    }

    // 0f15
    di = local_4;
    si = local_a;

    while (local_c == 0 && D_5893_map_id <= 0x20) // 0f93
    {
        local_c = 1;
        si = 1;
        local_e = FUN_1000_39fc_get_first_active_party_member();
        if (local_e == si)
        {
            FUN_1000_16ba_print_char(10);
            FUN_1000_4c2a();
            FUN_1000_1850_print_string("Zzzzzz...\n");
        }

        // 0fc3
        if (0 > local_e)
        {
            local_c = 0;
            si = 0;
        }

        // 0fd0
        if (local_e != 0)
            continue;

        if (D_587a != 'T' && D_587a != 'Q')
        {
            // 0fea -> 0f2e
            di = 1;
            FUN_1000_4f7c(1);
        }
        else
        {
            if (D_587a == 'Q')
            {
                di ^= 1;
                if (di != 0)
                {
                    FUN_1000_4f7c(1);
                }
            }
            else
            {
                di = 0;
            }
        }

        // 0f36
        local_8 = F_DUNGEON_03d6();
        if (-1 < local_8)
        {
            si = F_DUNGEON_06c4_process_command(local_8);
        }

        if (D_5893_map_id < 0x21)
        {
            si = 0;
            local_c = si;
        }

        // 0f53
        local_2 = D_595a[(D_5895_map_level & 0xff) * 0x40 + D_5897_map_y * 8 + D_5896_map_x];
        local_6 = local_2 & 0xf0;
        if (si != 0)
        {
            F_DUNGEON_0c76(local_2, di);
        }

        if (D_5893_map_id >= 0x21)
        {
            continue;
        }

        si = 0;
        local_c = si;
    }

    // 0ff2
    local_4 = di;
    local_a = si;
    if ((D_bb17 & 2) != 0)
    {
        D_bb17 &= 0xfb;
    }
    else
    {
        D_bb17 |= 4;
    }
    // 100b
    F_DNGLOOK_1130();
    if (local_e < 0)
    {
        F_BLCKTHRN_0910_death();
    }
}
