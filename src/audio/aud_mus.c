#include "common/common.h"

#include "vars.h"

#include "aud_mus.h"

#include "audio.h"

void AUDIO_PlayBgmPerMap(void)
{
    // frigate / skiff
    switch (D_587c_partyTile & 0xfc)
    {
    case 0x24:
    case 0x28:
    case 0x20:
        AUDIO_PlayBgm(BGM_ID_3);
        return;
    }

    if (D_5893_map_id == 0)
    {
        // overworld / underworld
        if (D_5895_map_level == 255)
        {
            AUDIO_PlayBgm(BGM_ID_11);
        }
        else
        {
            AUDIO_PlayBgm(BGM_ID_2);
        }
        return;
    }

    if (D_5893_map_id > 0x20)
    {
        AUDIO_PlayBgm(BGM_ID_10);
        return;
    }

    int bgmId = 0;

    switch (D_5893_map_id)
    {
        // town
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        bgmId = 9;
        break;

        // lighthouse
    case 9:
    case 0xa:
    case 0xb:
    case 0xc:
        bgmId = 13;
        break;

        // castle lb
    case 0x11:
        bgmId = 8;
        break;

        // blackthorn
    case 0x12:
        bgmId = 12;
        break;

        // hut
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
        // village
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
        bgmId = 6;
        break;

        // keep
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d: // ok
        bgmId = 13;
        break;

        // keep
    case 0x1e:
    case 0x1f:
    case 0x20:
        bgmId = 7;
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

void AUDIO_PlayBgmForShrine(void)
{
    AUDIO_PlayBgm(BGM_ID_5);
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

void AUDIO_PlayBgmForEnding(void)
{
    // TODO: chain 14 -> 15
    AUDIO_PlayBgm(BGM_ID_15);
}
