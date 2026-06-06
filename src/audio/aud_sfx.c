#include "common/common.h"
#include "audio.h"
#include "vars.h"
#include "time/time.h"

// TODO: add pc speaker emulation?

// 2192
void AUDIO_DispatchPulse(int freq, int delay, int dur, int pulseWidth, int pulseInc)
{
    debug("AUDIO_DispatchPulse(%d,%d,%d,%d,%d)", freq, delay, dur, pulseWidth, pulseInc);

    // TOWN_11b8 An air of *** doth surround thee...
    if (freq == 6600 && delay == 1 && dur == 60000 && pulseWidth == 2000 && pulseInc == 1)
    {
    }

    for (int i = 0; i < 10; i++)
    {
        if (freq == D_2746[i] && delay == 1 && dur == 4000 && pulseWidth == 20000 && pulseInc == -4)
        {
            AUDIO_PlaySfx(SFX_ID_HARPSI0 + i);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (freq == D_6a36[i] && delay == 1 && dur == 2000 && pulseWidth == 20000 && pulseInc == -10)
        {
            AUDIO_PlaySfx(SFX_ID_GT1 + i);
        }
    }

    // approximation
    if (dur > 100)
    {
        TIME_SleepMs(dur / 20);
    }
}

static int s_footstepFlag = 0;

// 223c
// ref: FMT FUN_0002c598
void AUDIO_DispatchWhiteNoise(uint rate, uint dur, uint limit)
{
    debug("AUDIO_DispatchWhiteNoise(%d,%d,%d)", rate, dur, limit);

    if (rate == 1 && dur == 0x19 && limit == 1000)
    {
        s_footstepFlag = 1;
    }

    if (rate == 1 && dur == 0x19 && limit == 0x5dc && s_footstepFlag == 1)
    {
        s_footstepFlag = 0;
        AUDIO_PlaySfx(SFX_ID_FOOTSTEP);
    }

    if (rate == 10 && dur == 0x640 && limit == 2000)
    {
        AUDIO_PlaySfx(SFX_ID_POISON); // note: 60 (C4)
    }
    else if (rate == 0x14 && dur == 0x3c && limit == 10000)
    {
        AUDIO_PlaySfx(0x13); // note: 60 (C4)
    }
    else if (rate == 0x28 && dur == 3000 && limit == 500)
    {
        AUDIO_PlaySfx(7); // note: 60 (C4)
    }
    else if (rate == 10 && dur == 3000 && limit == 2000)
    {
        AUDIO_PlaySfx(8); // note: 60 (C4)
    }
    else if (rate == 800 && dur >= 8000 && dur <= 20800 && limit == 700)
    {
        AUDIO_PlaySfx(9); // note: 60 - (dur - 8000) / 1600
    }
    else if (rate == 10 && dur == 30 && limit == 25000)
    {
        AUDIO_PlaySfx(SFX_ID_FOUNTAIN);
    }

    // approximation
    if (dur > 100)
    {
        TIME_SleepMs(dur / 10);
    }
}

// 22c0
// ref: FMT FUN_0002c4f4
void AUDIO_DispatchTone(uint freq, uint dur)
{
    debug("AUDIO_DispatchTone(%d,%d)", freq, dur);

    if (freq == 165 && dur == 200)
    {
        AUDIO_PlaySfx(SFX_ID_BLOCKED);
    }

    // approximation
    if (dur > 100)
    {
        TIME_SleepMs(dur * 8 / 10);
    }
}

// 43ae
void AUDIO_DispatchSweepTone(int param_1, int param_2, int param_3, int param_4)
{
    debug("AUDIO_DispatchSweepTone(%d,%d,%d,%d)", param_1, param_2, param_3, param_4);
}
