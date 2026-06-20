#include "common/common.h"
#include "audio.h"
#include "vars.h"
#include "time/time.h"

#include "sfx_map.h"

static int AUDIO_LookupSfx(int type, int a, int b, int c, int d, int e)
{
    for (int i = 0; i < SFX_RULE_COUNT; i++)
    {
        const SfxRule* r = &g_sfxRules[i];
        if (r->type == type
            && r->parameter[0] == a && r->parameter[1] == b && r->parameter[2] == c
            && r->parameter[3] == d && r->parameter[4] == e)
        {
            return r->sfxId;
        }
    }
    return -1;
}

// harpsichord audio freqs
extern u16 D_2746[0xa];

// apparition phrase freqs
extern u16 D_3a26[6];

// 2192
void AUDIO_DispatchPulse(int freq, int delay, int dur, int pulseWidth, int pulseInc)
{
    debug("AUDIO_DispatchPulse(%d,%d,%d,%d,%d)", freq, delay, dur, pulseWidth, pulseInc);

    int sfxType = AUDIO_GetSfxType();
    if (sfxType == SFX_TYPE_NONE)
    {
        return;
    }

    if (sfxType == SFX_TYPE_SYNTH)
    {
        AUDIO_PlaySynthPulse(freq, delay, dur, pulseWidth, pulseInc);
        return;
    }

    // gemshard - CAST_15b4_UseGemShard
    if (freq == 0xa50 && delay == 1 && dur == 200 && pulseWidth >= 2000 && pulseWidth <= 25000 && pulseInc == 0)
    {
        if (pulseWidth == 2000)
        {
            AUDIO_PlaySfx(SFX_ID_GEMSHARD);
        }
    }

    // CAST2_0966_ShrineOfVirtue (0db3)
    if (freq == 0xa8c && delay == 1 && dur == 200 && pulseWidth >= 2000 && pulseWidth <= 25000 && pulseInc == 0)
    {
        if (pulseWidth == 2000)
        {
            AUDIO_PlaySfx(SFX_ID_SHRINE1);
        }
    }

    // CAST2_0966_ShrineOfVirtue (0c47)
    if (freq == 0xc1c && delay == 1 && dur == 0x96 && pulseWidth >= 2000 && pulseWidth <= 25000 && pulseInc == 0)
    {
        if (pulseWidth == 2000)
        {
            AUDIO_PlaySfx(SFX_ID_SHRINE2);
        }
    }

    // cast2 phrase - CAST2_0966_ShrineOfVirtue (0ac6)
    for (int i = 0; i < 7; i++)
    {
        if (freq == D_4be6[i] && delay == 1 && dur == D_4bf4[i] && pulseWidth == D_4c02[i] && pulseInc == D_4c10[i])
        {
            AUDIO_PlaySfx(SFX_ID_CAST2_PHRASE_BASE + i);
            break;
        }
    }

    // harpsichord - TOWN_0e34
    for (int i = 0; i < 10; i++)
    {
        if (freq == D_2746[i] && delay == 1 && dur == 4000 && pulseWidth == 20000 && pulseInc == -4)
        {
            AUDIO_PlaySfx(SFX_ID_HARPSICHORD_BASE + i);
            break;
        }
    }

    // lute - ULTIMA_4102_AudioPlayAmbientSfx
    for (int i = 0; i < 9; i++)
    {
        if (freq == D_6a36[i] && delay == 1 && dur == 2000 && pulseWidth == 20000 && pulseInc == -10)
        {
            AUDIO_PlaySfx(SFX_ID_LUTE_BASE + i);
            break;
        }
    }

    // cast2 spell tones - CAST2_0000_CastEffect
    // NOTE: ignores D_4b1a
    for (int i = 1; i < 9; i++)
    {
        int castDur = i * 4000 + 10000;
        if (freq == D_4af6[i] && delay == 1 && dur == castDur && pulseWidth == D_4b08[i] && pulseInc == D_4b2c[i])
        {
            AUDIO_PlaySfx(SFX_ID_CAST2_BASE + (i - 1));
            break;
        }
    }

    // blackthorn phrase - BLCKTHRN_0910_Death
    for (int i = 0; i < 6; i++)
    {
        if (freq == D_3720[i] && delay == 1 && dur == D_372c[i] && pulseWidth == D_3738[i] && pulseInc == D_3744[i])
        {
            AUDIO_PlaySfx(SFX_ID_BLACKTHORN_PHRASE_BASE + i);
            break;
        }
    }

    // apparition phrase - OUTSUBS_0658
    for (int i = 0; i < 6; i++)
    {
        if (freq == D_3a26[i] && delay == 1 && dur == 5000 && pulseWidth == 200 && pulseInc == 0xd)
        {
            AUDIO_PlaySfx(SFX_ID_APPARITION_PHRASE_BASE + i);
            break;
        }
    }

    int id = AUDIO_LookupSfx(SFX_TYPE_PULSE, freq, delay, dur, pulseWidth, pulseInc);
    if (id >= 0)
    {
        AUDIO_PlaySfx(id);
    }

    // approximation
    if (dur > 100)
    {
        TIME_SleepMs(dur / 20);
    }
}

// 223c
// ref: FMT FUN_0002c598
void AUDIO_DispatchWhiteNoise(uint rate, uint dur, uint limit)
{
    debug("AUDIO_DispatchWhiteNoise(%d,%d,%d)", rate, dur, limit);

    int sfxType = AUDIO_GetSfxType();
    if (sfxType == SFX_TYPE_NONE)
    {
        return;
    }

    if (sfxType == SFX_TYPE_SYNTH)
    {
        AUDIO_PlaySynthNoise(rate, dur, limit);
        return;
    }

    int id = AUDIO_LookupSfx(SFX_TYPE_NOISE, rate, dur, limit, 0, 0);
    if (id >= 0)
    {
        AUDIO_PlaySfx(id);
    }

    // approximation
    if (dur > 100 && !(rate == 0x13 && dur == 16000 && limit == 0x96))
    {
        TIME_SleepMs(dur / 10);
    }
}

// 22c0
// ref: FMT FUN_0002c4f4
void AUDIO_DispatchTone(uint freq, uint dur)
{
    debug("AUDIO_DispatchTone(%d,%d)", freq, dur);

    int sfxType = AUDIO_GetSfxType();
    if (sfxType == SFX_TYPE_NONE)
    {
        return;
    }

    if (sfxType == SFX_TYPE_SYNTH)
    {
        AUDIO_PlaySynthTone(freq, dur);
        return;
    }

    int id = AUDIO_LookupSfx(SFX_TYPE_TONE, freq, dur, 0, 0, 0);
    if (id >= 0)
    {
        AUDIO_PlaySfx(id);
    }

    // approximation
    if (dur > 100)
    {
        TIME_SleepMs(dur * 8 / 10);
    }
}

// 43ae
void AUDIO_DispatchSweepTone(int startFreq, int endFreq, int tickStep, int dur)
{
    debug("AUDIO_DispatchSweepTone(%d,%d,%d,%d)", startFreq, endFreq, tickStep, dur);

    int sfxType = AUDIO_GetSfxType();
    if (sfxType == SFX_TYPE_NONE)
    {
        return;
    }

    if (sfxType == SFX_TYPE_SYNTH)
    {
        AUDIO_PlaySynthSweepTone(startFreq, endFreq, tickStep, dur);
        return;
    }

    int id = AUDIO_LookupSfx(SFX_TYPE_SWEEP, startFreq, endFreq, tickStep, dur, 0);
    if (id >= 0)
    {
        AUDIO_PlaySfx(id);
    }

    // approximation
    if (dur > 100)
    {
        TIME_SleepMs(dur * 3 / 2);
    }
}
