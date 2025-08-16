#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

// NOT MATCHING: optimization
byte* FUN_1000_4402_get_address_of_tile_id(int x, int y)
{
	byte* local_2;
	undefined2 local_4;

	if (D_5893_map_id > 0x7f) // combat?
	{
		local_2 = &D_ad14[y * 32 + x];
	}
	else if (D_5893_map_id == 0) // 4420; overworld
	{
		x = (x - D_589b) & 0x1f;
		y = (y - D_589c) & 0x1f;
		local_4 = 0;
		if (y > 0xf)
		{
			local_4 = 2;
			y -= 16;
		}
		if (x > 0xf)
		{
			local_4 += 1;
			x -= 16;
		}
		// 4467
		local_2 = &D_6608[local_4 * 0x100 + y * 16 + x];
	}
	else if ((((x < 0) || (y < 0)) || (0x1f < x)) || (0x1f < y))
	{
		local_2 = D_6a07;
	}
	else
	{
		local_2 = &D_6608[y * 32 + x];
	}

	return local_2;
}

// OK P1
// print >
void FUN_1000_4c2a(void)
{
	TextWindow* win;
	int local_4;
	int local_6;
	int local_8;

	win = &D_535e_textWindows[D_5386_currentCharset];

	local_6 = ((uint)win->left + FUN_1000_1f12_get_current_text_column()) * 8;
	local_8 = ((uint)win->top + FUN_1000_1cee_get_current_text_row()) * 8;

	local_4 = (uint)win->text_colors;
	FUN_1000_1cca_set_text_foreground_color(D_13b2_frame_color);
	FUN_1000_1f26_set_text_background_color(0);
	FUN_1000_16ba_print_char(2);
	FUN_1000_0a70_set_pen_color(D_13b0_white_color);
	FUN_1000_0b10_line(local_6, local_8, local_6 + 5, local_8 + 3);
	FUN_1000_0b10_line(local_6 + 5, local_8 + 4, local_6, local_8 + 7);
	FUN_1000_1cca_set_text_foreground_color(local_4 + 0xf);
	FUN_1000_1f26_set_text_background_color(local_4 >> 4);
}

// OK P1
// print <
void FUN_1000_4cce(void)
{
	TextWindow* win;
	int local_4;
	int local_6;
	int local_8;

	win = &D_535e_textWindows[D_5386_currentCharset];

	local_6 = ((uint)win->left + FUN_1000_1f12_get_current_text_column()) * 8;
	local_8 = ((uint)win->top + FUN_1000_1cee_get_current_text_row()) * 8;

	local_4 = (uint)win->text_colors;
	FUN_1000_1cca_set_text_foreground_color(D_13b2_frame_color);
	FUN_1000_1f26_set_text_background_color(0);
	FUN_1000_16ba_print_char(1);
	FUN_1000_0a70_set_pen_color(D_13b0_white_color);
	FUN_1000_0b10_line(local_6 + 7, local_8, local_6 + 2, local_8 + 3);
	FUN_1000_0b10_line(local_6 + 2, local_8 + 4, local_6 + 7, local_8 + 7);
	FUN_1000_1cca_set_text_foreground_color(local_4 + 0xf);
	FUN_1000_1f26_set_text_background_color(local_4 >> 4);
}

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
	local_4 = D_5386_currentCharset;
	FUN_1000_1b94_select_charset(0);
	FUN_1000_1bf2_set_text_cursor_position(local_6, 0);
	FUN_1000_4c2a();
	FUN_1000_1850_print_string(param_1);
	FUN_1000_4cce();
	FUN_1000_1b94_select_charset(local_4);
}
