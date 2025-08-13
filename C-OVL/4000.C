#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

// OK P1
void FUN_1000_4e50(char* param_1)
{
    int local_2;
    int local_4;
    int local_6;

    local_6 = -(FUN_1000_216c_strlen(param_1) / 2 - 30);
    local_2 = FUN_1000_216c_strlen(param_1) + local_6 + 2;
    FUN_1000_0a70_set_pen_color(D_13b2_frame_color);
    FUN_1000_0aa6_fill_rectangle(192, 0, local_6 * 8, 6);
    FUN_1000_0aa6_fill_rectangle(local_2 * 8, 0, 311, 6);
    FUN_1000_0a70_set_pen_color(D_13b0_white_color);
    FUN_1000_0c9c_grap_horiz_line(192, 7, local_6 * 8);
    FUN_1000_0c9c_grap_horiz_line(local_2 * 8, 7, 311);
    local_4 = D_5386_currentTextWindow;
    FUN_1000_1b94_select_charset(0);
    FUN_1000_1bf2_set_text_cursor_position(local_6, 0);
    FUN_1000_4c2a();
    FUN_1000_1850_print_string(param_1);
    FUN_1000_4cce();
    FUN_1000_1b94_select_charset(local_4);
}
