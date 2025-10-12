#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>

FUN_1000_4102(void) { puts("FUN_1000_4102"); }

// OK P1
void FUN_1000_433e_audio_some_noise()
{
	FUN_1000_223c_audio_white_noise(1, 0x19, 1000);
	FUN_1000_20c8_some_delay(1, 0x14);
	FUN_1000_223c_audio_white_noise(1, 0x19, 1500);
}

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

FUN_1000_4552(void) { puts("FUN_1000_4552"); }

FUN_1000_475a(void) { puts("FUN_1000_475a"); }

// OK P1
// draw moon phase
void FUN_1000_4a84(void)
{
	u16 local_16;
	int local_14;
	byte local_12[12 + 1];
	int local_4;

	if (D_5893_map_id < 0x21)
	{
		// 4a96
		for (local_14 = 0; local_14 < 12; local_14++)
		{
			local_12[local_14] = 0x20;
		}

		local_12[12] = 0;
		local_16 = D_5386_currentCharset;
		FUN_1000_1b94_select_charset(0);
		FUN_1000_1c9e_get_char_segment(1);

		// 4ac3
		local_4 = -((int)D_587f - 17);
		if (local_4 < 12 && local_4 >= 0)
		{
			local_12[local_4] = 0x2a;
		}

		// 4adf
		D_5885 = D_1eda[(D_587e - 1) * 2];
		local_4 = -(D_587f - 8);
		if (local_4 < -12)
		{
			local_4 += 24;
		}

		// 4b04
		if (local_4 < 12 && local_4 >= 0)
		{
			local_12[local_4] = D_5885;
		}

		// 4b19
		D_5886 = D_1eda[(D_587e - 1) * 2 + 1];
		local_4 = -(D_587f - 2);
		if (local_4 < -12)
		{
			local_4 += 24;
		}

		// 4b3e
		if (local_4 < 12 && local_4 >= 0)
		{
			local_12[local_4] = D_5886;
		}

		// 4b53
		FUN_1000_1bf2_set_text_cursor_position(6, 0);
		if (D_5893_map_id != 0x19 && D_5895_map_level < 0x80)
		{
			for (local_14 = 0; local_12[local_14] != 0;)
			{
				if (local_12[local_14] == 0x2a)
				{
					// -> 4b74
					FUN_1000_1cca_set_text_foreground_color(D_13b8);
				}
				else
				{
					// 4b70
					FUN_1000_1cca_set_text_foreground_color(D_13ba);
				}

				FUN_1000_16ba_print_char(local_12[local_14++]);
			}

			FUN_1000_1cca_set_text_foreground_color(D_13b0_white_color);
		}
		else
		{
			// 4ba2
			FUN_1000_0a70_set_pen_color(D_13b2_frame_color);
			FUN_1000_0aa6_fill_rectangle(0x28, 0, 0x98, 6);
			FUN_1000_0a70_set_pen_color(D_13b0_white_color);
			FUN_1000_0b10_line(0x28, 7, 0x98, 7);
		}

		// 4bd5
		FUN_1000_1b94_select_charset(local_16);
		FUN_1000_1c9e_get_char_segment(0);
	}
}

// OK P1 (complete)
// print map name?
void FUN_1000_4be8()
{
	undefined2 local_4;

	local_4 = D_5386_currentCharset;
	FUN_1000_1b94_select_charset(0);

	if (D_5893_map_id != 0x19 && D_5895_map_level < 0x80)
	{
		FUN_1000_1bf2_set_text_cursor_position(5, 0);
		FUN_1000_4c2a();
		FUN_1000_1850_print_string(D_a3e2);
		FUN_1000_4cce();
	}

	FUN_1000_1b94_select_charset(local_4);
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

int FUN_1000_4d76(char* param_2, int param_1)
{
	int iVar1;

	for (iVar1 = 0; ; iVar1++)
	{
		if (param_2[iVar1] == 0 || param_2[iVar1] == param_1)
			break;
	}
	return iVar1;
}

// OK P1
void FUN_1000_4daa(void)
{
	FUN_1000_0a70_set_pen_color(D_13b2_frame_color);
	FUN_1000_0aa6_fill_rectangle(0xf0, 0x51, 0x107, 0x56);
	FUN_1000_0a70_set_pen_color(D_13b0_white_color);
	FUN_1000_0c9c_grap_horiz_line(0xf0, 0x50, 0x107);
	FUN_1000_0c9c_grap_horiz_line(0xf0, 0x57, 0x107);
}

// OK P1
void FUN_1000_4dea(int param_1)
{
	int local_4;

	local_4 = D_5386_currentCharset;
	FUN_1000_1b94_select_charset(0);
	FUN_1000_1bf2_set_text_cursor_position(0x1e, 10);
	FUN_1000_4c2a();
	FUN_1000_16ba_print_char(param_1);
	FUN_1000_4cce();
	FUN_1000_1b94_select_charset(local_4);
}

// OK P1
void FUN_1000_4e20(void)
{
	FUN_1000_0a70_set_pen_color(D_13b2_frame_color);
	FUN_1000_0aa6_fill_rectangle(0xc0, 0, 0x137, 0x6);
	FUN_1000_0a70_set_pen_color(D_13b0_white_color);
	FUN_1000_0c9c_grap_horiz_line(0xc0, 0x7, 0x137);
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

// OK P1 (stack, loop)
// time related
void FUN_1000_4f7c(int param_1)
{
	int local_a;
	int local_8;
	int local_6;
	uint local_4;

	if (param_1 != 0)
	{
		// 4f8d
		if ((D_587a == 'Q') && (param_1 = param_1 >> 1, param_1 == 0))
		{
			param_1++;
		}

		// 4fa0
		D_5880 = D_587f;
		if (D_587a != 'T')
		{
			D_5881 += param_1;
			FUN_1000_3f36(&D_58a7, param_1);
			FUN_1000_3f36(&D_58a6, param_1);
		}
		// 4fc8
		if (D_5881 > 59)
		{
			// 4fd2
			D_5881 -= 60;
			FUN_1000_3f36(&D_588c, 1);
			D_587f++;
			if (D_587f > 23)
			{
				// 4ff0
				D_587f = 0;
				for (local_6 = 0; local_6 < 3; local_6++)
				{
					// 4ffa
					if (D_58c8[local_6] < 0x80)
					{
						do
						{
							// 5004
							local_4 = FUN_1000_2092_random_range(1, 8);
							if (D_5893_map_id == local_4)
							{
								local_4 = 0;
							}
							// 501c
							for (local_8 = 0; local_8 < 3; local_8++)
							{
								// 5020
								if (D_58c8[local_8] == local_4)
								{
									local_4 = 0;
								}
							}
						} while (local_4 == 0);

						D_58c8[local_6] = local_4;
					}
				}

				// 5048
				D_587e++;

				if (D_587e > 28)
				{
					D_5858[0] = D_5858[1] = D_5858[2] = 0;
					D_57b2 = 0;
					D_587e = 1;
					D_5959 = 0;

					// 5077
					// TODO: loop counter
					for (local_6 = 0; local_6 < 0x10; local_6++)
					{
						// 507a
						if (D_55a8_party[local_6]._17 < 0x19)
						{
							D_55a8_party[local_6]._17++;
						}
					}

					D_587d++;
					if (0xd < D_587d)
					{
						D_587d = 1;
						D_5874++;
					}
				}

				// 509e
				FUN_1000_2900_update_vitals();
			}
		}
	}

	// 50a1
	// setup light intensity
	if (D_58a5 < 0x33)
	{
		// 50ab
		local_a = D_58a5;
		if (D_5893_map_id == 0x19 || D_5895_map_level > 0x7f || D_587f < 5 || D_587f > 0x13)
		{
			// 50cf
			D_58a5 = 2;
		}
		else
		{
			// 50d6
			if (D_587f == 5)
			{
				D_58a5 = D_6a80[D_5881 / 10];
			}
			// 50f4
			else if (D_587f == 19)
			{
				D_58a5 = D_6a80[(-(D_5881 - 59)) / 10];
			}
			else
			{
				D_58a5 = 0x32;
			}
		}

		// 5115
		if (D_58a6 != 0 && D_58a5 < 0x12)
		{
			D_58a5 = 0x12;
		}
		// 5128
		if (D_58a7 != 0 && D_58a5 < 10)
		{
			D_58a5 = 10;
		}
		// 513b
		if (local_a != D_58a5)
		{
			D_24e6 = 1;
		}
	}

	// 514a
	if (D_587f != D_5880)
	{
		if (D_5893_map_id < 0x21 && D_5895_map_level < 0x80)
		{
			FUN_1000_4a84();
		}

		// 5164
		if (D_587f == 0)
		{
			D_5884 = 0xc;
		}
		else
		{
			// 5172
			if (D_587f > 0xc)
			{
				D_5884 = D_587f - 0xc;
			}
			else
			{
				D_5884 = D_587f;
			}
		}
	}

	if (D_5893_map_id != 0 && D_5893_map_id < 0x21)
	{
		FUN_1000_71aa();
	}
}
