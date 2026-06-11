#include "common/common.h"

#include "vars.h"

#include "aud_mus.h"

#include "audio.h"

void AUDIO_PlayBgmPerMap(void)
{
    if (D_5893_map_id == 0)
    {
        // overworld / underworld
        // TODO: underworld
        AUDIO_PlayBgm(BGM_ID_2);
        return;
    }

    // frigate / skiff
    switch (D_587c_partyTile & 0xfc)
    {
    case 0x24:
    case 0x28:
    case 0x20:
        AUDIO_PlayBgm(BGM_ID_3);
        break;
    }

    if (D_5893_map_id > 0x20)
    {
        // bgm 10?
        AUDIO_StopBgm();
        return;
    }

    int bgmId = 0;

    switch (D_5893_map_id)
    {
    case 0x11:
        bgmId = 8;
        break;

    case 0xd:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
        bgmId = 6;
        break;

    case 0x1f:
        bgmId = 7;
        break;

    case 2:
    case 6:
        bgmId = 9;
        break;
    }

    if (bgmId > 0)
    {
        AUDIO_PlayBgm(bgmId);
    }
    else
    {
        // TODO?
        AUDIO_StopBgm();
    }
}

void AUDIO_PlayBgmForCombat(void)
{
    // FMT: play(3)
    AUDIO_PlayBgm(BGM_ID_4);
}

void AUDIO_PlayBgmForCombatVictory(void)
{
    AUDIO_PlayBgm(BGM_ID_1);
}

void AUDIO_PlayBgmForHoleUp(void)
{
    // FMT: play(4)
    AUDIO_PlayBgm(BGM_ID_5);
}
