#include "common/common.h"

#include "vars.h"

#include "aud_mus.h"

#include "audio.h"

void AUDIO_PlayBgmPerMap(void)
{
    if (D_5893_map_id > 0x20)
    {
        //AUDIO_PlayBgm(BGM_ID_9);
        AUDIO_StopBgm();
    }
    else
    {
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
}

void AUDIO_PlayBgmForOverworld(void)
{
    AUDIO_PlayBgm(BGM_ID_2);
}

void AUDIO_PlayBgmForCombat(void)
{
    // FMT: play(3)
    AUDIO_PlayBgm(BGM_ID_4);
}

void AUDIO_PlayBgmForHoleUp(void)
{
    // FMT: play(4)
    AUDIO_PlayBgm(BGM_ID_5);
}
