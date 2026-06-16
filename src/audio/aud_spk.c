#include "audio.h"
#include "aud_ops.h"

static void AUDIO_SPK_Noop(void)
{
    // no-op
}

static void AUDIO_SPK_PlaySfx(int id)
{
}

static void AUDIO_SPK_StopSfx(void)
{
}

static int AUDIO_SPK_GetSfxType(void)
{
    return SFX_TYPE_SYNTH;
}

static void AUDIO_SPK_PlaySynthPulse(int freq, int delay, int dur, int pulseWidth, int pulseInc)
{
}

static void AUDIO_SPK_PlaySynthNoise(int rate, int dur, int limit)
{
}

static void AUDIO_SPK_PlaySynthTone(int freq, int dur)
{
}

static void AUDIO_SPK_PlaySynthSweepTone(int startFreq, int endFreq, int tickStep, int dur)
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
