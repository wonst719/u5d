#include "common/common.h"
#include "audio/aud_mus.h"
#include "audio/aud_sfx.h"
#include "funcs.h"
#include "macros.h"
#include "vars.h"
#include "tiles.h"

#include "outsubs.h"
#include "town.h"

void MAINOUT_0000(void);

// OK P1
void ULTIMA_400c(void)
{
    int local_4;
    for (local_4 = 0; local_4 < D_585b; local_4++)
	{
		if (D_55a8_party[local_4].status != STATUS_DEAD && D_55a8_party[local_4].equips[4] == 0x2c)
		{
			if (ULTIMA_2092_RandomRange(0, 7) == 7)
			{
				ULTIMA_3f14_IncreaseInt(&D_55a8_party[local_4].hp, 1, D_55a8_party[local_4].maxHp);
				D_a9fa = 1;
			}
		}
	}
}

// OK P1
// select active player
int ULTIMA_4080(int param_1)
{
    int local_6;
	int local_4;
    
    local_4 = 1;
    local_6 = param_1 - 0x31;

    ULTIMA_1850_PrintString(_TEXT(0xa396, "Set Active Plr:\n"));
    if (param_1 == 0x30)
    {
        ULTIMA_1850_PrintString(_TEXT(0xa3a8, "None!\n"));
        D_587b = 0xff;

		ULTIMA_2900_UpdateVitalsDisplay();
		local_4 = 0;
    }
    else
    {
        if (D_585b > local_6 && D_55a8_party[local_6].status != STATUS_DEAD && D_55a8_party[local_6].status != STATUS_SLEEP)
        {
            D_587b = local_6;

            ULTIMA_1850_PrintString(D_55a8_party[local_6].name);
            ULTIMA_16ba_PrintChar(10);

            ULTIMA_2900_UpdateVitalsDisplay();
            local_4 = 0;
        }
		else
		{
            ULTIMA_1850_PrintString(_TEXT(0xa3b0, "Invalid!\n"));
        }
    }

    return local_4;
}

// CHECKED
void ULTIMA_4102_AudioPlayAmbientSfx(void)
{
	int local_14;
	int local_10;
    int local_16;
	int local_12;
	int local_e;
	int local_c;
	int local_a;
	int local_8;
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
		local_8 = local_a = 5;
	}

    for (local_c = local_8 - 5, local_12 = 0; local_c < local_8 + 6; local_c++, local_12++)
	{
        for (local_10 = local_a - 5, local_16 = 0; local_10 < local_a + 6; local_10++, local_16++)
		{
			local_6 = (local_10 - local_a) * (local_10 - local_a) + (local_c - local_8) * (local_c - local_8);
			if (local_6 < local_4)
			{
				local_14 = *ULTIMA_4402_GetTileAddr(local_c, local_10);
				if ((local_14 & 0xfe) == TILE_MAP_CLOCK)
				{
					local_e = 1;
				}
				else if ((local_14 & 0xfc) == TILE_MAP_WATERFALL)
				{
					local_e = 2;
				}
				else if ((local_14 & 0xfc) == TILE_MAP_FOUNTAIN)
				{
					local_e = 3;
				}
                else if (GetMapViewport(local_12, local_16) == 0 && (GetActorMap(local_12, local_16) & 0xfc) == TILE_ACTOR_BARD)
				{
					// BGM/NOTE: no jingle when bgm is activated
					local_e = 4;
				}
				else
				{
					local_6 = local_4;
				}

				local_4 = local_6;
			}
		}
	}

	switch (local_e)
	{
    case 1:
		// clock
        if (D_5884 != 0 && (D_6a34_u8 == 0 || D_6a34_u8 == 4))
        {
            ULTIMA_2192_AudioPulse(0xc2c, 1, 2000, 20000, -10);
        }
        else
        {
            if (D_6a34_u8 == 0)
            {
                ULTIMA_22c0_AudioTone(3000, 3);
            }
            else if (D_6a34_u8 == 4)
            {
                ULTIMA_22c0_AudioTone(2000, 3);
            }
        }
        break;

    case 2:
		// waterfall
        ULTIMA_223c_AudioWhiteNoise(0x14, 0x3c, 10000);
        break;

    case 3:
		// fountain
        ULTIMA_223c_AudioWhiteNoise(10, 0x1e, 25000);
        break;

    case 4:
        if (D_6a48[D_6a08] != 0)
        {
            ULTIMA_2192_AudioPulse(D_6a36[D_6a48[D_6a08] - 1], 1, 2000, 20000, -10);
        }

        D_6a08++;
        if (D_6a08 > 0x34)
        {
            D_6a08 = 0;
        }
        break;
	}

    if (D_5884 != 0 && (D_6a34_u8 == 0 || D_6a34_u8 == 4))
	{
		D_5884--;
	}

	if (++D_6a34_u8 > 7)
	{
		D_6a34_u8 = 0;
	}
}

// OK P1
void ULTIMA_433e_AudioFootstep(void)
{
	ULTIMA_223c_AudioWhiteNoise(1, 0x19, 1000);
	ULTIMA_20c8_SomeDelay(1, 0x14);
	ULTIMA_223c_AudioWhiteNoise(1, 0x19, 1500);
}

// OK P1
void ULTIMA_4368_AudioVictoryTune(void)
{
    int local_4;

    for (local_4 = 0; local_4 < 3; local_4++)
    {
        ULTIMA_2192_AudioPulse(0x11f8, 1, 0x2a30, 300, 6);
    }

    ULTIMA_2192_AudioPulse(0x17d4, 1, 0x5460, 300, 3);
}

// OK P1
void ULTIMA_43ae_AudioSweepTone(int param_1, int param_2, int param_3, int param_4)
{
#if !defined(TARGET_DOS16)
	AUDIO_DispatchSweepTone(param_1, param_2, param_3, param_4);
	return;
#endif

	int local_6;
	int local_4;
	int local_a;
	int local_8;

	local_a = param_3;
	local_4 = (param_2 - param_1) * local_a;
    local_4 /= param_4;
	local_8 = param_1;

	for (local_6 = 0; local_6 < param_4; local_6 += param_3)
	{
		ULTIMA_22e2_PcspkOn(local_8);
		ULTIMA_20c8_SomeDelay(1, param_3);
		local_8 += local_4;
	}

	ULTIMA_230e_PcspkOff();
}

// CHECKED (NOT MATCHING: optimization)
byte* ULTIMA_4402_GetTileAddr(int x, int y)
{
	byte* local_4;
	int local_6;

	if (D_5893_map_id > 0x7f) // combat?
	{
		// 440f
        // There are cases where y < 0. original bug
#if !defined(MATCHING_BUILD)
		ASSERT(x >= 0 && x < 0xb && y < 0xb);
		if (y < 0)
			return &D_6a07; // return unused byte
#endif

		local_4 = &GetCombatMap(x, y);
	}
	else if (D_5893_map_id == 0) // 4420; overworld
	{
		x = (x - D_589b) & 0x1f;
		y = (y - D_589c) & 0x1f;
		local_6 = 0;
		if (y > 0xf)
		{
			local_6 = 2;
			y -= 16;
		}

		if (x > 0xf)
		{
			local_6++;
			x -= 16;
		}

		// 4467 (NOT MATCHING: optimization)
		local_4 = &GetMapOverworld(x, y, local_6);
	}
	else if (x < 0 || y < 0 || x > 0x1f || y > 0x1f) // 447e
	{
		// 4496
		local_4 = &D_6a07;
	}
	else
	{
		// 449e
		local_4 = &GetMap(x, y);
	}

	return local_4;
}

// OK P1
static void ULTIMA_44b8_AnimateTiles(void)
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

// CHECKED
// animate_actors
void ULTIMA_4552_AnimateActors(void)
{
	int local_e;
	int local_6;
	bool local_a;
	int local_c;
	int local_4;
	int local_14;
	int local_10;
	ActorFmt* local_8;
	byte* local_12;

	for (local_10 = 0; local_10 < 0x20; local_10++)
	{
		local_8 = &D_5c5a[local_10];
		if (local_8->_0_tile == 0)
		{
			continue;
		}

        local_c = local_8->_6 & 0xf;
        local_14 = local_8->_6 >> 4;
        local_4 = local_8->_0_tile & 0xfc;
        local_e = D_1b18[((local_4 - 0x34) >> 2) + 0xb0];
		local_12 = &D_1b18[local_e * 0x10];

		if (local_c == 0xf)
		{
			continue;
		}

        if (local_c != 0)
        {
            local_c--;
            local_8->_6 = (local_8->_6 & 0xf0) + local_c;
			continue;
        }

		if (local_8->_1_animTile == 0 || local_8->_1_animTile == TILE_ACTOR_1D || local_8->_1_animTile == TILE_ACTOR_SLEEP)
		{
			continue;
		}

		if (local_4 <= 0x33 || local_4 == 0xe8 || local_4 == 0xb4)
		{
			continue;
		}

		if (local_4 != 0x5c && local_4 != 0xa8)
		{
			if (ULTIMA_2092_RandomRange(0, 0xff) < 0x80)
			{
				continue;
			}
		}

        local_a = 0;
        do
        {
            local_6 = local_12[local_14];
            switch (local_6)
            {
            case 1:
            case 2:
            case 3:
            case 4:
                local_8->_1_animTile = local_4 + local_6 - 1;
                local_14++;
                local_a = 1;
                break;

            case 5:
                if (ULTIMA_2092_RandomRange(0, 0xff) < 0x40)
                {
                    local_8->_1_animTile = local_8->_0_tile;
                    if (local_4 == 0x5c)
                    {
                        local_14++;
                        local_a = 1;
                        break;
                    }

                    local_c = 6;
                    local_a = 1;
                    break;
                }

                local_14++;
                break;

            case 6:
                if (ULTIMA_2092_RandomRange(0, 0xff) >= 0xc0)
                {
                    local_14++;
                    break;
                }
                local_14 = 0;
                break;

            case 0:
                local_14 = 0;
                break;

            case 7:
                local_14 = 2;
                break;

            default:
                local_c = local_6 + 0x80;
                local_14++;
                local_a = 1;
                break;
            }

            local_8->_6 = local_14 * 0x10 + local_c;
        } while (!local_a);
    }

	ULTIMA_44b8_AnimateTiles();
    ULTIMA_6fd6_GRAP_AnimateTiles();
}

// OK P1
static int ULTIMA_4702(int param_1)
{
	int local_4;
	int local_6;
	int local_8;

	local_4 = 0;

	if (D_5840[param_1] == D_5893_map_id && D_5848[param_1] == D_5895_map_level)
	{
		if (D_5893_map_id != 0)
		{
			local_4 = 1;
		}
		else
		{
			local_6 = (byte)(D_5830[param_1] - D_589b);
			local_8 = (byte)(D_5838[param_1] - D_589c);

			if (local_6 < 0x20 && local_8 < 0x20)
			{
				local_4 = 1;
			}
		}
	}

	return local_4;
}

// OK P1
void ULTIMA_475a(void)
{
	int local_a;
	byte* local_4;
	int local_6;
	int local_8;

	local_a = 0xdc;
	if (D_587f >= 0x14 || D_587f < 5)
	{
        ULTIMA_3ef0_IncreaseByte(&D_5887, 1, 0x10);
    }
	else
	{
        ULTIMA_3f36_DecreaseByte(&D_5887, 1);
        if (D_5887 == 0)
        {
            local_a = 5;
        }
    }

	for (local_6 = 0; local_6 < 8; local_6++)
	{
		if (ULTIMA_4702(local_6) != 0)
		{
			local_4 = ULTIMA_4402_GetTileAddr(D_5830[local_6], D_5838[local_6]);
			local_8 = *local_4 != local_a;
			*local_4 = local_a;
			D_24e6 |= 2;
			if (local_8 != 0)
			{
				ULTIMA_5e4a();
			}
		}
	}
}

// OK P1
int ULTIMA_47f4(int param_1)
{
	int local_4;

	if (D_5840[param_1] == 0xff)
	{
		return 0;
	}

    if (D_5893_map_id == 0)
    {
        ULTIMA_251e_SwitchDisks(1);

        while (ULTIMA_1674_TestOpenFile(/*0xa3ba*/ "BRIT.DAT") == 0) {}

        ULTIMA_25d8_WriteFileToDisk(OUTSUBS_0368_GetWorldSavefile(), &D_5c5a[0]._0_tile, 0x100);
    }

    local_4 = D_5893_map_id;
    D_5893_map_id = D_5840[param_1];
    D_5896_map_x = D_5830[param_1];
    D_5897_map_y = D_5838[param_1];
    D_5895_map_level = D_5848[param_1];

    if (D_5893_map_id != 0 && local_4 != 0 && D_5893_map_id < 0x21 && local_4 < 0x21)
    {
        TOWN_11f0_Entry(1);
    }
    else
    {
        if (D_5893_map_id == 0 && local_4 == 0)
        {
#if defined(ENABLE_BGM)
			AUDIO_StopBgm();
#endif

            ULTIMA_256e_ReadFileFromDisk(OUTSUBS_0368_GetWorldSavefile(), &D_5c5a[0]._0_tile, 0x100, 0);
            MAINOUT_0000();

#if defined(ENABLE_BGM)
			AUDIO_PlayBgmPerMap();
#endif
        }
    }

    return 1;
}

// OK P1
int ULTIMA_48a8(void)
{
	int local_4;
	int local_6; // unused
	int local_8;

	local_8 = 0;
	if (*ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y) == TILE_MAP_MOONGATE)
	{
		ULTIMA_3ae6(1);
		ULTIMA_2192_AudioPulse(0x170c, 1, 30000, 2000, 2);
		local_4 = D_587c_partyTile;
		D_587c_partyTile = TILE_ACTOR_CIRCLE;
		ULTIMA_1068(0xdc, 5, 5);
		D_587c_partyTile = 0;
		ULTIMA_3ae6(1);

		for (D_5887 = 0xf; D_5887 != 0; D_5887--)
		{
			ULTIMA_1112_GRAP_60(D_5887, 5, 5);
			ULTIMA_20fa_WaitTicks(2);
		}

		*ULTIMA_4402_GetTileAddr(D_5896_map_x, D_5897_map_y) = TILE_MAP_GRASS;

		D_24e6 |= 2;

		ULTIMA_10e0_GRAP_51_PutTile(5, 5, 5);
		if (D_587f == 0 && D_5881 < 10)
		{
			local_8 = 1;
		}
		else
		{
			ULTIMA_47f4((D_587f < 0xc ? D_5885 : D_5886) - 0x30);
		}

		D_587c_partyTile = local_4;
	}

	return local_8;
}

// OK P1
int ULTIMA_4988(void)
{
    bool local_4;
    int local_6;
    int local_a;
    int local_8;

    local_a = -1;
    if (D_5893_map_id > 0x80)
    {
        local_a = D_ba14[D_589e].entityIdx;
    }
    else if (D_587b != 0xff)
    {
        local_a = D_587b;
    }
    else
    {
        local_8 = 0;
        for (local_6 = 0; local_6 != D_585b; local_6++)
        {
            if (D_55a8_party[local_6].status == STATUS_GOOD || D_55a8_party[local_6].status == STATUS_POISONED)
            {
				local_a = local_6;
                local_8++;
            }
        }

        if (local_8 > 1)
        {
            local_4 = 0;
            while (!local_4)
            {
                ULTIMA_1850_PrintString(_TEXT(0xa3c4, "Player: "));
                local_a = ULTIMA_2e8e();
                if (local_a < 0)
                {
                    local_4 = 1;
                }
                else
                {
                    if (D_55a8_party[local_a].status == STATUS_GOOD || D_55a8_party[local_a].status == STATUS_POISONED)
                    {
                        ULTIMA_1850_PrintString(D_55a8_party[local_a].name);
                        if (ULTIMA_1f12_GetCurrentTextX() != 0)
                        {
                            ULTIMA_16ba_PrintChar(10);
                        }

                        local_4 = 1;
                    }
                    else
                    {
                        ULTIMA_1850_PrintString(_TEXT(0xa3ce, "Disabled!\n\n"));
                    }
                }
            }
        }
    }

    if (local_a == -1)
    {
        ULTIMA_1850_PrintString(_TEXT(0xa3da, "None!\n"));
    }
    else if (local_a == -2)
    {
        ULTIMA_16ba_PrintChar(10);
    }

    return local_a;
}

// OK P1
// draw moon phase
void ULTIMA_4a84(void)
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
		local_16 = D_5386_current_text_window_idx;
		ULTIMA_1b94_SelectTextWindow(0);
		ULTIMA_1c9e_SelectCharset(1);

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
		ULTIMA_1bf2_SetTextPosition(6, 0);
		if (D_5893_map_id != 0x19 && D_5895_map_level < 0x80)
		{
			for (local_14 = 0; local_12[local_14] != 0;)
			{
				if (local_12[local_14] == 0x2a)
				{
					// -> 4b74
					ULTIMA_1cca_SetTextForegroundColor(D_13b8);
				}
				else
				{
					// 4b70
					ULTIMA_1cca_SetTextForegroundColor(D_13ba);
				}

				ULTIMA_16ba_PrintChar(local_12[local_14++]);
			}

			ULTIMA_1cca_SetTextForegroundColor(D_13b0_white_color);
		}
		else
		{
			// 4ba2
			ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
			ULTIMA_0aa6_GRAP_3f_FillRect(0x28, 0, 0x98, 6);
			ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
			ULTIMA_0b10_GRAP_Line(0x28, 7, 0x98, 7);
		}

		// 4bd5
		ULTIMA_1b94_SelectTextWindow(local_16);
		ULTIMA_1c9e_SelectCharset(0);
	}
}

// OK P1 (complete)
// print map name?
void ULTIMA_4be8(void)
{
	undefined2 local_4;

	local_4 = D_5386_current_text_window_idx;
	ULTIMA_1b94_SelectTextWindow(0);

	if (D_5893_map_id != 0x19 && D_5895_map_level < 0x80)
	{
		ULTIMA_1bf2_SetTextPosition(5, 0);
		ULTIMA_4c2a();
		ULTIMA_1850_PrintString(D_a3e2);
		ULTIMA_4cce();
	}

	ULTIMA_1b94_SelectTextWindow(local_4);
}

// OK P1
// print >
void ULTIMA_4c2a(void)
{
	TextWindow* win;
	int local_4;
	int local_6;
	int local_8;

	win = &D_535e_textWindows[D_5386_current_text_window_idx];

	local_6 = ((uint)win->left + ULTIMA_1f12_GetCurrentTextX()) * 8;
	local_8 = ((uint)win->top + ULTIMA_1cee_GetCurrentTextY()) * 8;

	local_4 = (uint)win->colors;
	ULTIMA_1cca_SetTextForegroundColor(D_13b2_frame_color);
	ULTIMA_1f26_SetTextBackgroundColor(0);
	ULTIMA_16ba_PrintChar(2);
	ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
	ULTIMA_0b10_GRAP_Line(local_6, local_8, local_6 + 5, local_8 + 3);
	ULTIMA_0b10_GRAP_Line(local_6 + 5, local_8 + 4, local_6, local_8 + 7);
	ULTIMA_1cca_SetTextForegroundColor(local_4 & 0xf);
	ULTIMA_1f26_SetTextBackgroundColor(local_4 >> 4);
}

// OK P1
// print <
void ULTIMA_4cce(void)
{
	TextWindow* win;
	int local_4;
	int local_6;
	int local_8;

	win = &D_535e_textWindows[D_5386_current_text_window_idx];

	local_6 = ((uint)win->left + ULTIMA_1f12_GetCurrentTextX()) * 8;
	local_8 = ((uint)win->top + ULTIMA_1cee_GetCurrentTextY()) * 8;

	local_4 = (uint)win->colors;
	ULTIMA_1cca_SetTextForegroundColor(D_13b2_frame_color);
	ULTIMA_1f26_SetTextBackgroundColor(0);
	ULTIMA_16ba_PrintChar(1);
	ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
	ULTIMA_0b10_GRAP_Line(local_6 + 7, local_8, local_6 + 2, local_8 + 3);
	ULTIMA_0b10_GRAP_Line(local_6 + 2, local_8 + 4, local_6 + 7, local_8 + 7);
	ULTIMA_1cca_SetTextForegroundColor(local_4 & 0xf);
	ULTIMA_1f26_SetTextBackgroundColor(local_4 >> 4);
}

// CHECKED
// find index
int ULTIMA_4d76_FindIndex(char* param_2, int param_1)
{
	int local_4;

	for (local_4 = 0; ; local_4++)
	{
		if (param_2[local_4] == 0 || param_2[local_4] == param_1)
			break;
	}

	return local_4;
}

// OK P1
void ULTIMA_4daa(void)
{
	ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
	ULTIMA_0aa6_GRAP_3f_FillRect(0xf0, 0x51, 0x107, 0x56);
	ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
	ULTIMA_0c9c_GRAP_39_HorizLine(0xf0, 0x50, 0x107);
	ULTIMA_0c9c_GRAP_39_HorizLine(0xf0, 0x57, 0x107);
}

// OK P1
void ULTIMA_4dea(int param_1)
{
	int local_4;

	local_4 = D_5386_current_text_window_idx;
	ULTIMA_1b94_SelectTextWindow(0);
	ULTIMA_1bf2_SetTextPosition(0x1e, 10);
	ULTIMA_4c2a();
	ULTIMA_16ba_PrintChar(param_1);
	ULTIMA_4cce();
	ULTIMA_1b94_SelectTextWindow(local_4);
}

// OK P1
void ULTIMA_4e20(void)
{
	ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
	ULTIMA_0aa6_GRAP_3f_FillRect(0xc0, 0, 0x137, 0x6);
	ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
	ULTIMA_0c9c_GRAP_39_HorizLine(0xc0, 0x7, 0x137);
}

// OK P1
void ULTIMA_4e50(char* param_1)
{
	int local_2;
	int local_4;
	int local_6;

	local_6 = -(ULTIMA_216c_strlen(param_1) / 2 - 30);
	local_2 = ULTIMA_216c_strlen(param_1) + local_6 + 2;
	ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
	ULTIMA_0aa6_GRAP_3f_FillRect(192, 0, local_6 * 8, 6);
	ULTIMA_0aa6_GRAP_3f_FillRect(local_2 * 8, 0, 311, 6);
	ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
	ULTIMA_0c9c_GRAP_39_HorizLine(192, 7, local_6 * 8);
	ULTIMA_0c9c_GRAP_39_HorizLine(local_2 * 8, 7, 311);
	local_4 = D_5386_current_text_window_idx;
	ULTIMA_1b94_SelectTextWindow(0);
	ULTIMA_1bf2_SetTextPosition(local_6, 0);
	ULTIMA_4c2a();
	ULTIMA_1850_PrintString(param_1);
	ULTIMA_4cce();
	ULTIMA_1b94_SelectTextWindow(local_4);
}

// OK P1
void ULTIMA_4efc(void)
{
	ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
	ULTIMA_0cf2_GRAP_3c_VertLine(0xbf, 0x38, 0x3f);
	ULTIMA_0cf2_GRAP_3c_VertLine(0x138, 0x38, 0x3f);
	ULTIMA_0a70_GRAP_2d_SetPenColor(0);
	ULTIMA_0aa6_GRAP_3f_FillRect(0xc0, 0x38, 0x137, 0x3f);
}

// OK P1
void ULTIMA_4f3c(void)
{
	ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b2_frame_color);
	ULTIMA_0aa6_GRAP_3f_FillRect(0xbf, 0x39, 0x138, 0x3e);
	ULTIMA_0a70_GRAP_2d_SetPenColor(D_13b0_white_color);
	ULTIMA_0c9c_GRAP_39_HorizLine(0xc0, 0x38, 0x137);
	ULTIMA_0c9c_GRAP_39_HorizLine(0xc0, 0x3f, 0x137);
}

// OK P1 (stack, loop)
// time related
void ULTIMA_4f7c(int param_1)
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
			ULTIMA_3f36_DecreaseByte(&D_58a7, param_1);
			ULTIMA_3f36_DecreaseByte(&D_58a6, param_1);
		}
		// 4fc8
		if (D_5881 > 59)
		{
			// 4fd2
			D_5881 -= 60;
			ULTIMA_3f36_DecreaseByte(&D_588c, 1);
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
							local_4 = ULTIMA_2092_RandomRange(1, 8);
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
				ULTIMA_2900_UpdateVitalsDisplay();
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
			ULTIMA_4a84();
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
		ULTIMA_71aa();
	}
}
