#include "COMMON.H"
#include "FUNCS.H"
#include "VARS.H"

#include <stdio.h>

void F_TOWN_11f0_Entry(int param_1);
void F_MAINOUT_0000(void);
char* F_OUTSUBS_0368_GetWorldSavefile();

// NOT MATCHING
void FUN_1000_400c(void)
{
    int local_4;
    for (local_4 = 0; local_4 < D_585b; local_4++)
	{
		if (D_55a8_party[local_4]._b != 'D' && D_55a8_party[local_4]._1d == ',')
		{
			if (FUN_1000_2092_random_range(0, 7) == 7)
			{
				FUN_1000_3f14(&D_55a8_party[local_4]._10, 1, D_55a8_party[local_4]._12);
				D_a9fa = 1;
			}
		}
	}
}

FUN_1000_4080(int a) { printf("FUN_1000_4080(%d)\n", a); }

// TODO: MATCH
void FUN_1000_4102_play_ambient_sfx(void)
{
	byte bVar1;
	int iVar4;
    int local_14;
	int local_12;
	int local_e;
	int local_c;
	uint local_a;
	uint local_8;
	int local_6;
	int local_4;

	local_e = 0;
	local_4 = 0x33;

	if (D_5893_map_id < 0x80)
	{
		local_8 = (uint)D_5896_map_x;
		local_a = (uint)D_5897_map_y;
	}
	else
	{
		local_a = 5;
		local_8 = 5;
	}

	local_12 = 0;
    for (local_c = local_8 - 5; local_c < local_8 + 6; local_c++)
	{
        local_14 = 0;
        for (iVar4 = local_a - 5; iVar4 < local_a + 6; iVar4++)
		{
			local_6 = (iVar4 - local_a) * (iVar4 - local_a) + (local_c - local_8) * (local_c - local_8);
			if (local_6 < local_4)
			{
				bVar1 = *FUN_1000_4402_get_address_of_tile_id(local_c, iVar4);
				if ((bVar1 & 0xfe) == 0xfa)
				{
					local_e = 1;
				}
				else if ((bVar1 & 0xfc) == 0xd4)
				{
					local_e = 2;
				}
				else if ((bVar1 & 0xfc) == 0xd8)
				{
					local_e = 3;
				}
                else if (D_ab02[local_14 * 0x20 + local_12] == 0 && (D_ac64[local_14 * 0x10 + local_12] & 0xfc) == 0x5c)
				{
					local_e = 4;
				}
				else
				{
					local_6 = local_4;
				}

				local_4 = local_6;
			}

            local_14++;
		}

		local_12++;
	}

	switch (local_e)
	{
    case 1:
        if (D_5884 != 0 && (D_6a34 == 0 || D_6a34 == 4))
        {
            FUN_1000_2192_audio_some_noise(0xc2c, 1, 2000, 20000, -10);
        }
        else
        {
            if (D_6a34 == 0)
            {
                FUN_1000_22c0_pcspk_play_tone(3000, 3);
            }
            else if (D_6a34 == 4)
            {
                FUN_1000_22c0_pcspk_play_tone(2000, 3);
            }
        }
        break;

    case 2:
		// waterfall
        FUN_1000_223c_audio_white_noise(0x14, 0x3c, 10000);
        break;

    case 3:
		// fountain
        FUN_1000_223c_audio_white_noise(10, 0x1e, 25000);
        break;

    case 4:
        if (D_6a48[D_6a08] != 0)
        {
            FUN_1000_2192_audio_some_noise((uint)D_6a48[D_6a08] * 2 + D_6a34, 1, 2000, 20000, -10);
        }

        D_6a08++;
        if (D_6a08 > 0x34)
        {
            D_6a08 = 0;
        }
        break;
	}

    if (D_5884 != 0 && (D_6a34 == 0 || D_6a34 == 4))
	{
		D_5884--;
	}

	if (++D_6a34 > 7)
	{
		D_6a34 = 0;
	}
}

// OK P1
void FUN_1000_433e_audio_some_noise()
{
	FUN_1000_223c_audio_white_noise(1, 0x19, 1000);
	FUN_1000_20c8_some_delay(1, 0x14);
	FUN_1000_223c_audio_white_noise(1, 0x19, 1500);
}

// NOT MATCHING
void FUN_1000_4368(void)
{
    int iVar1;

    for (iVar1 = 0; iVar1 < 3; iVar1++)
    {
        FUN_1000_2192_audio_some_noise(0x11f8, 1, 0x2a30, 300, 6);
    }

    FUN_1000_2192_audio_some_noise(0x17d4, 1, 0x5460, 300, 3);
}

FUN_1000_43ae(int a, int b, int c, int d) { printf("FUN_1000_43ae(%d,%d,%d,%d)\n", a, b, c, d); }

// NOT MATCHING: optimization
byte* FUN_1000_4402_get_address_of_tile_id(int x, int y)
{
	byte* local_2;
	undefined2 local_4;

	if (D_5893_map_id > 0x7f) // combat?
	{
        ASSERT(x >= 0 && x < 32 && y >= 0 && y < 32);

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

// TODO: MATCH
void FUN_1000_44b8(void)
{
	int i;

	for (i = 0xd4; i < 0xd8; i++)
	{
		D_b11e[i]++;
		if (D_b11e[i] == 0xd8)
		{
			D_b11e[i] = 0xd4;
		}
	}

	for (i = 0xd8; i < 0xdc; i++)
	{
		D_b11e[i]++;
		if (D_b11e[i] == 0xdc)
		{
			D_b11e[i] = 0xd8;
		}
	}

	if ((D_6a7e & 1) != 0)
	{
        for (i = 0x80; i < 0x84; i++)
		{
			D_b11e[i] ^= 1;
		}

		for (i = 0xec; i < 0xf0; i++)
		{
			D_b11e[i]++;
			if (D_b11e[i] == 0xf0)
			{
				D_b11e[i] = 0xec;
			}
		}

		if ((D_6a7e & 2) != 0)
		{
            for (i = 0xfa; i < 0xfe; i++)
			{
				D_b11e[i] ^= 1;
			}
		}
	}

	D_6a7e++;
}

// TODO: MATCH
// animate_actors
void FUN_1000_4552_animate_actors(void)
{
	byte bVar1;
	char cVar2;
	bool bVar3;
	byte bVar4;
	uint uVar7;
	uint uStack_14;
	int iStack_10;
	char cStack_c;

	for (iStack_10 = 0; iStack_10 < 0x20; iStack_10++)
	{
        if (D_5c5a[iStack_10]._0_tile != 0)
        {
            bVar4 = D_5c5a[iStack_10]._6 & 0xf;
            uStack_14 = D_5c5a[iStack_10]._6 >> 4;
            uVar7 = D_5c5a[iStack_10]._0_tile & 0xfc;
            bVar1 = D_1b18[((uVar7 - 0x34) >> 2) + 0xb0];
            if (bVar4 != 0xf)
            {
                if ((D_5c5a[iStack_10]._6 & 0xf) == 0)
                {
                    if (D_5c5a[iStack_10]._1 != 0 &&
						D_5c5a[iStack_10]._1 != 0x1d &&
						D_5c5a[iStack_10]._1 != 0x1e &&
                        uVar7 > 0x33 && uVar7 != 0xe8 && uVar7 != 0xb4 &&
                        (uVar7 == 0x5c || uVar7 == 0xa8 || FUN_1000_2092_random_range(0, 0xff) >= 0x80))
                    {
                        bVar3 = 0;
                        do
                        {
                            cVar2 = D_1b18[uStack_14 + (uint)bVar1 * 0x10];
                            switch (cVar2)
                            {
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                                D_5c5a[iStack_10]._1 = (char)uVar7 + cVar2 - 1;
                                uStack_14++;
                                bVar3 = 1;
                                break;
                            case 5:
                                if (FUN_1000_2092_random_range(0, 0xff) > 0x3f)
                                {
                                    uStack_14++;
                                    break;
                                }
                                D_5c5a[iStack_10]._1 = D_5c5a[iStack_10]._0_tile;
                                if (uVar7 == 0x5c)
                                {
                                    uStack_14++;
                                    bVar3 = 1;
                                    break;
                                }
                                bVar4 = 6;
                                bVar3 = 1;
                                break;
                            case 6:
                                if (FUN_1000_2092_random_range(0, 0xff) > 0xbf)
                                {
                                    uStack_14++;
                                    break;
                                }
                            case 0:
                                uStack_14 = 0;
                                break;
                            case 7:
                                uStack_14 = 2;
                                break;
                            default:
                                bVar4 = cVar2 + 0x80;
                                uStack_14++;
                                bVar3 = 1;
                                break;
                            }

                            D_5c5a[iStack_10]._6 = (char)uStack_14 * 0x10 + bVar4;
                        } while (!bVar3);
                    }
                }
                else
                {
                    cStack_c = bVar4 - 1;
                    D_5c5a[iStack_10]._6 = (D_5c5a[iStack_10]._6 & 0xf0) + cStack_c;
                }
            }
        }
    }

	FUN_1000_44b8();
    FUN_1000_6fd6();
}

// TODO: MATCH
int FUN_1000_4702(int param_1)
{
	int uStack_4;

	uStack_4 = 0;

	if ((D_5840[param_1] == D_5893_map_id) &&
		(D_5848[param_1] == D_5895_map_level))
	{
		if (D_5893_map_id == 0)
		{
			if (0x1f < (byte)(D_5830[param_1] - D_589b))
			{
				return 0;
			}

			if (0x1f < (byte)(D_5838[param_1] - D_589c))
			{
				return 0;
			}
		}

		uStack_4 = 1;
	}

	return uStack_4;
}

// TODO: MATCH
void FUN_1000_475a(void)
{
	char cVar1;
	char cVar2;
	int iVar3;
	byte* pcVar4;
	int iVar5;

	cVar2 = 0xdc;
	if ((D_587f < 0x14) && (4 < D_587f))
	{
		FUN_1000_3f36(&D_5887, 1);
		if (D_5887 == 0)
		{
			cVar2 = 5;
		}
	}
	else
	{
		FUN_1000_3ef0(&D_5887, 1, 0x10);
	}

	iVar5 = 0;
	do {
		iVar3 = FUN_1000_4702(iVar5);
		if (iVar3 != 0)
		{
			pcVar4 = FUN_1000_4402_get_address_of_tile_id(D_5830[iVar5], D_5838[iVar5]);
			cVar1 = *pcVar4;
			*pcVar4 = cVar2;
			D_24e6 = D_24e6 | 2;
			if (cVar1 != cVar2)
			{
				FUN_1000_5e4a();
			}
		}
		iVar5++;
	} while (iVar5 < 8);
}

// TODO: MATCH
int FUN_1000_47f4(int param_1)
{
	byte bVar1;
	int uVar2;
	int iVar3;

	if (*(param_1 + D_5840) == 0xff)
	{
		uVar2 = 0;
	}
	else
	{
		if (D_5893_map_id == 0)
		{
			FUN_1000_251e_switch_disks(1);
			do {
				iVar3 = FUN_1000_1674_test_open_file("BRIT.DAT");
			} while (iVar3 == 0);
			FUN_1000_25d8_write_file_to_disk(F_OUTSUBS_0368_GetWorldSavefile(), &D_5c5a[0]._0_tile, 0x100);
		}
		bVar1 = D_5893_map_id;
		D_5893_map_id = *(undefined1*)(param_1 + D_5840);
		D_5896_map_x = *(undefined1*)(param_1 + D_5830);
		D_5897_map_y = *(undefined1*)(param_1 + D_5838);
		D_5895_map_level = *(undefined1*)(param_1 + D_5848);
		if ((((D_5893_map_id == 0) || (bVar1 == 0)) || (0x20 < D_5893_map_id)) || (0x20 < bVar1))
		{
			if ((D_5893_map_id == 0) && (bVar1 == 0))
			{
				FUN_1000_256e_read_file_from_disk(F_OUTSUBS_0368_GetWorldSavefile(), &D_5c5a[0]._0_tile, 0x100, 0);
				F_MAINOUT_0000(); // thunk
			}
		}
		else
		{
			F_TOWN_11f0_Entry(1);
		}
		uVar2 = 1;
	}
	return uVar2;
}

// TODO: MATCH
int FUN_1000_48a8(void)
{
	char* pcVar1;
	char cVar2;
	uint x;
	undefined2 uVar4;

	uVar4 = 0;
	if (*FUN_1000_4402_get_address_of_tile_id((uint)D_5896_map_x, (uint)D_5897_map_y) == 0xdc)
	{
		FUN_1000_3ae6(1);
		FUN_1000_2192_audio_some_noise(0x170c, 1, 30000, 2000, 2);
		x = (uint)D_587c;
		D_587c = 0x16;
		FUN_1000_1068(0xdc, 5, 5);
		D_587c = 0;
		FUN_1000_3ae6(1);
		D_5887 = 0xf;
		do {
			FUN_1000_1112_GRAP_60(D_5887, 5, 5);
			FUN_1000_20fa_wait_ticks(2);
			D_5887--;
		} while (D_5887 != 0);
		*FUN_1000_4402_get_address_of_tile_id((uint)D_5896_map_x, (uint)D_5897_map_y) = 5;
		D_24e6 |= 2;
		cVar2 = 5;
		uVar4 = 5;
		FUN_1000_10e0_GRAP_51_draw_tile(5, 5, 5);
		if ((D_587f == 0) && (D_5881 < 10))
		{
			uVar4 = 1;
		}
		else
		{
			if (D_587f < 0xc)
			{
				cVar2 = D_5885;
			}
			else
			{
				cVar2 = D_5886;
			}
			FUN_1000_47f4(cVar2 - 0x30);
		}
		D_587c = x;
	}
	return uVar4;
}

int FUN_1000_4988(void)
{
    bool bVar1;
    int iVar3;
    int uVar5;
    int uStack_a;
    int iStack_8;

    uStack_a = -1;
    if (D_5893_map_id < 0x81)
    {
        if (D_587b == 0xff)
        {
            iStack_8 = 0;
            for (uVar5 = 0; uVar5 < D_585b; uVar5++)
            {
                if ((D_55a8_party[uVar5]._b == 'G') || (D_55a8_party[uVar5]._b == 'P'))
                {
                    iStack_8++;
                    uStack_a = uVar5;
                }
            }

            if (iStack_8 > 1)
            {
                bVar1 = 0;
                while (!bVar1)
                {
                    FUN_1000_1850_print_string(/*0xa3c4*/ "Player: ");
                    uStack_a = FUN_1000_2e8e();
                    if (uStack_a < 0)
                    {
                        bVar1 = 1;
                    }
                    else
                    {
                        if ((D_55a8_party[uStack_a]._b == 'G') ||
                            (D_55a8_party[uStack_a]._b == 'P'))
                        {
                            FUN_1000_1850_print_string(D_55a8_party[uStack_a]._0);
                            iVar3 = FUN_1000_1f12_get_current_text_column();
                            if (iVar3 != 0)
                            {
                                FUN_1000_16ba_print_char(10);
                            }

                            bVar1 = 1;
                        }
                        else
                        {
                            FUN_1000_1850_print_string(/*0xa3ce*/ "Disabled!\n\n");
                        }
                    }
                }
            }
        }
        else
        {
            uStack_a = D_587b;
        }
    }
    else
    {
        uStack_a = D_ba14[D_589e]._3;
    }

    if (uStack_a == -1)
    {
        FUN_1000_1850_print_string(/*0xa3da*/ "None!\n");
    }
    else if (uStack_a == -2)
    {
        FUN_1000_16ba_print_char(10);
    }

    return uStack_a;
}

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
		FUN_1000_1c9e_set_charset(1);

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
			FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b2_frame_color);
			FUN_1000_0aa6_GRAP_3f_fill_rectangle(0x28, 0, 0x98, 6);
			FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
			FUN_1000_0b10_GRAP_line(0x28, 7, 0x98, 7);
		}

		// 4bd5
		FUN_1000_1b94_select_charset(local_16);
		FUN_1000_1c9e_set_charset(0);
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
	FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
	FUN_1000_0b10_GRAP_line(local_6, local_8, local_6 + 5, local_8 + 3);
	FUN_1000_0b10_GRAP_line(local_6 + 5, local_8 + 4, local_6, local_8 + 7);
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
	FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
	FUN_1000_0b10_GRAP_line(local_6 + 7, local_8, local_6 + 2, local_8 + 3);
	FUN_1000_0b10_GRAP_line(local_6 + 2, local_8 + 4, local_6 + 7, local_8 + 7);
	FUN_1000_1cca_set_text_foreground_color(local_4 + 0xf);
	FUN_1000_1f26_set_text_background_color(local_4 >> 4);
}

// strchr
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
	FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b2_frame_color);
	FUN_1000_0aa6_GRAP_3f_fill_rectangle(0xf0, 0x51, 0x107, 0x56);
	FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
	FUN_1000_0c9c_GRAP_39_horiz_line(0xf0, 0x50, 0x107);
	FUN_1000_0c9c_GRAP_39_horiz_line(0xf0, 0x57, 0x107);
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
	FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b2_frame_color);
	FUN_1000_0aa6_GRAP_3f_fill_rectangle(0xc0, 0, 0x137, 0x6);
	FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
	FUN_1000_0c9c_GRAP_39_horiz_line(0xc0, 0x7, 0x137);
}

// OK P1
void FUN_1000_4e50(char* param_1)
{
	int local_2;
	int local_4;
	int local_6;

	local_6 = -(FUN_1000_216c_strlen(param_1) / 2 - 30);
	local_2 = FUN_1000_216c_strlen(param_1) + local_6 + 2;
	FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b2_frame_color);
	FUN_1000_0aa6_GRAP_3f_fill_rectangle(192, 0, local_6 * 8, 6);
	FUN_1000_0aa6_GRAP_3f_fill_rectangle(local_2 * 8, 0, 311, 6);
	FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
	FUN_1000_0c9c_GRAP_39_horiz_line(192, 7, local_6 * 8);
	FUN_1000_0c9c_GRAP_39_horiz_line(local_2 * 8, 7, 311);
	local_4 = D_5386_currentCharset;
	FUN_1000_1b94_select_charset(0);
	FUN_1000_1bf2_set_text_cursor_position(local_6, 0);
	FUN_1000_4c2a();
	FUN_1000_1850_print_string(param_1);
	FUN_1000_4cce();
	FUN_1000_1b94_select_charset(local_4);
}

FUN_1000_4efc(void) { puts("FUN_1000_4efc"); }

// OK P1
void FUN_1000_4f3c(void)
{
	FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b2_frame_color);
	FUN_1000_0aa6_GRAP_3f_fill_rectangle(0xbf, 0x39, 0x138, 0x3e);
	FUN_1000_0a70_GRAP_2d_set_pen_color(D_13b0_white_color);
	FUN_1000_0c9c_GRAP_39_horiz_line(0xc0, 0x38, 0x137);
	FUN_1000_0c9c_GRAP_39_horiz_line(0xc0, 0x3f, 0x137);
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

						D_58c8[local_6] = (u8)local_4;
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
