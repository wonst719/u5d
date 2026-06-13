// simple PC speaker sound implementation. doesn't match the original.
#include <pc.h>

#include "common/common.h"

#include "audio.h"
#include "aud_ops.h"
#include "vars.h"
#include "time/time.h"

static void AUDIO_SPK_Noop(void)
{
    // no-op
}

static void AUDIO_SPK_PlayTone(int freq, int dur)
{
    sound(freq);
    TIME_SleepMs(dur);
    nosound();
}

static void AUDIO_SPK_PlaySfx(int id)
{
    if (id >= SFX_ID_HARPSI0 && id <= SFX_ID_HARPSI9)
    {
        AUDIO_SPK_PlayTone(D_2746[id - SFX_ID_HARPSI0] / 6, 300);
        return;
    }

    switch (id)
    {
    case SFX_ID_FOOTSTEP:
        AUDIO_SPK_PlayTone(220, 10);
        TIME_SleepMs(15);
        AUDIO_SPK_PlayTone(230, 10);
        break;
    case SFX_ID_BLOCKED:
        AUDIO_SPK_PlayTone(165, 200);
        break;
    case SFX_ID_FOUNTAIN:
        AUDIO_SPK_PlayTone(rand() % 2000 + 3000, 8);
        break;
    }
}

static void AUDIO_SPK_StopSfx(void)
{
}

static int AUDIO_SPK_GetSfxType(void)
{
    return SFX_TYPE_SYNTH;
}

static void AUDIO_SPK_PlaySynthPulse(int param_1, int param_2, int param_3, int param_4, int param_5)
{
}

static void AUDIO_SPK_PlaySynthNoise(int param_1, int param_2, int param_3)
{
}

static void AUDIO_SPK_PlaySynthTone(int param_1, int param_2)
{
}

static void AUDIO_SPK_PlaySynthSweepTone(int param_1, int param_2, int param_3, int param_4)
{
}

static AudioSfxDriverOps s_sfxOps =
{
    .Initialize = AUDIO_SPK_Noop,
    .Cleanup = AUDIO_SPK_Noop,
    .PlaySfx = AUDIO_SPK_PlaySfx,
    .StopSfx = AUDIO_SPK_StopSfx,
    .GetSfxType = AUDIO_SPK_GetSfxType,
    .PlaySynthPulse = AUDIO_SPK_PlaySynthPulse,
    .PlaySynthNoise = AUDIO_SPK_PlaySynthNoise,
    .PlaySynthTone = AUDIO_SPK_PlaySynthTone,
    .PlaySynthSweepTone = AUDIO_SPK_PlaySynthSweepTone
};

AudioSfxDriverOps* AUDIO_SPK_GetSfxOps(void)
{
    return &s_sfxOps;
}
