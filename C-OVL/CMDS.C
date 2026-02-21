#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>
#include <string.h>
#include <memory.h>

void F_NPC_0db4(int param_1);

void F_TOWN_0170(void);

void F_TOWN_1694(void);

// NOT MATCHING
void F_CMDS_0552_hole_up_cmd(void)
{
    byte local_4;
    byte local_c;
    byte local_6;
    int local_a;
    int local_8;

    FUN_1000_1850_print_string(/*0x4209*/ "For how many hours? ");

    do
    {
        local_6 = FUN_1000_266c_get_ch();
    } while (local_6 != 0x20 && (local_6 < 0x30 || 0x39 < local_6));

    if (local_6 != 0x20 && local_6 != 0x30)
    {
        FUN_1000_16ba_print_char(local_6);
        FUN_1000_16ba_print_char(10);

        local_8 = (int)D_587f + (int)local_6 - 0x30;
        if (local_8 > 0x17)
        {
            local_8 -= 0x17;
        }

        for (local_a = 0; local_a < 0x10; local_a++)
        {
            F_NPC_0db4(D_587f);
            FUN_1000_5910_update_map();
            if (D_65be == 'a')
            {
                return;
            }
        }

        local_4 = D_587b;

        for (local_a = 0; local_a < D_585b; local_a++)
        {
            if (D_55a8_party[local_a]._b == 'G')
            {
                D_55a8_party[local_a]._b = 'S';
            }
        }

        FUN_1000_2900_update_vitals();
        FUN_1000_1850_print_string(/*0x421e*/ "Zzzzzzz...\n");

        FUN_1000_0a70_set_pen_color(0);
        FUN_1000_0aa6_fill_rectangle(8, 8, 0xb7, 0xb7);

        local_c = D_587f;
        while (local_8 != D_587f)
        {
            FUN_1000_4f7c(10);
            if (local_c != D_587f && (D_587f == 0x14 || D_587f == 0x05))
            {
                F_TOWN_0170();
            }
            local_c = D_587f;
            FUN_1000_4a84();
            FUN_1000_2ae8();
            FUN_1000_2900_update_vitals();
            F_TOWN_1694();

            if (FUN_1000_368e(D_5896_map_x, D_5897_map_y, D_5895_map_level) != 0)
            {
                local_8 = -1;
                break;
            }
            FUN_1000_20fa_wait_ticks(1);
        }

        if (local_8 == -1)
        {
            FUN_1000_1850_print_string(/*0x422a*/ "Thrown out of bed!\n");
        }

        for (local_a = 0; local_a < D_585b; local_a++)
        {
            if (D_55a8_party[local_a]._b == 'S')
            {
                D_55a8_party[local_a]._b = 'G';
            }
        }

        D_587b = local_4;
        D_5896_map_x++;
        D_24e6 = 1;
        D_5c5a[0]._2_x++;

        FUN_1000_2900_update_vitals();
        FUN_1000_5910_update_map();
    }
}

int F_CMDS_07f6_board_cmd(void) { puts("F_CMDS_07f6_board_cmd"); }

void F_CMDS_0aea_fire_cmd(void) { puts("F_CMDS_0aea_fire_cmd"); }

void F_CMDS_0d98_ignite_torch_cmd(void) { puts("F_CMDS_0d98_ignite_torch_cmd"); }

void F_CMDS_0ddc_new_order_cmd(void) { puts("F_CMDS_0ddc_new_order_cmd"); }

void F_CMDS_0eb4_xit_cmd(void) { puts("F_CMDS_0eb4_xit_cmd"); }

int F_CMDS_1418_yell_cmd(void) { puts("F_CMDS_1418_yell_cmd"); }

void F_CMDS_161a_push_cmd(void) { puts("F_CMDS_161a_push_cmd"); }

int F_CMDS_17ec(void) { puts("F_CMDS_17ec"); }

void F_CMDS_1ad8_mix_cmd(void) { puts("F_CMDS_1ad8_mix_cmd"); }

void F_CMDS_1c20_klimb_cmd(void) { puts("F_CMDS_1c20_klimb_cmd"); }
