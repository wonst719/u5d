#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

// draw_frame
// FMT: F_26840
void FUN_1000_637e_draw_frame(void)
{
    // black
    FUN_1000_0a70_set_pen_color(0);
    FUN_1000_0aa6_fill_rectangle(0, 0, 319, 199);

    FUN_1000_0a70_set_pen_color(D_13b2_frame_color);
    FUN_1000_0aa6_fill_rectangle(0, 0, 319, 6);
    FUN_1000_0aa6_fill_rectangle(0, 185, 191, 191);
    FUN_1000_0aa6_fill_rectangle(0, 0, 6, 191);
    FUN_1000_0aa6_fill_rectangle(185, 0, 191, 191);
    FUN_1000_0aa6_fill_rectangle(313, 0, 319, 87);
    FUN_1000_0aa6_fill_rectangle(192, 80, 312, 87);
    FUN_1000_0aa6_fill_rectangle(192, 0x39, 312, 63);

    FUN_1000_1cca_set_text_foreground_color(D_13b2_frame_color);
    FUN_1000_1bf2_set_text_cursor_position(0, 0);
    FUN_1000_16ba_print_char(0x7b);
    FUN_1000_1bf2_set_text_cursor_position(39, 0);
    FUN_1000_16ba_print_char(0x7c);
    FUN_1000_1bf2_set_text_cursor_position(0, 23);
    FUN_1000_16ba_print_char(0x7d);

    FUN_1000_0a70_set_pen_color(D_13b0_white_color);
    FUN_1000_0b10_line(7, 7, 7, 184);
    FUN_1000_0f90_pen(184, 184);
    FUN_1000_0f90_pen(184, 7);
    FUN_1000_0f90_pen(7, 7);
    FUN_1000_0b10_line(191, 191, 191, 87);
    FUN_1000_0f90_pen(319, 87);
    FUN_1000_0b10_line(191, 7, 312, 7);
    FUN_1000_0f90_pen(312, 56);
    FUN_1000_0f90_pen(191, 56);
    FUN_1000_0f90_pen(191, 7);
    FUN_1000_0b10_line(191, 63, 312, 63);
    FUN_1000_0f90_pen(312, 80);
    FUN_1000_0f90_pen(191, 80);
    FUN_1000_0f90_pen(191, 63);

    FUN_1000_1cca_set_text_foreground_color(D_13b0_white_color);
}

// NOT MATCHING (asm?)
byte FUN_1000_6ff0(register int param_1, register int param_2)
{
    if ((param_1 < 0xb) && (param_2 < 0xb))
    {
        if ((param_1 > 5) || (param_2 > 5))
        {
            if (param_1 > 5)
            {
                param_1 = 10 - param_1;
            }
            if (param_2 > 5)
            {
                param_2 = 10 - param_2;
            }
        }

        return D_6aa8[param_1 + param_2 * 6];
    }

    return 0;
}
