// simple PC speaker sound implementation. doesn't match the original.
#include <pc.h>

#include "common/common.h"

#include "audio.h"
#include "aud_ops.h"
#include "time/time.h"

void AUDIO_SPK_Noop(void)
{
    // no-op
}

void AUDIO_SPK_PlayTone(int freq, int dur)
{
    sound(freq);
    TIME_SleepMs(dur);
    nosound();
}

void AUDIO_SPK_PlaySfx(int id)
{
    switch (id)
    {
    case SFX_ID_FOOTSTEP:
        AUDIO_SPK_PlayTone(220, 10);
        TIME_SleepMs(30);
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

void AUDIO_SPK_StopSfx(void)
{
}

void AUDIO_SPK_PlayBgm(int id)
{
}

void AUDIO_SPK_StopBgm(void)
{
}

static AudioMusicDriverOps s_musicOps =
{
    .Initialize = AUDIO_SPK_Noop,
    .Cleanup = AUDIO_SPK_Noop,
    .PlayBgm = AUDIO_SPK_PlayBgm,
    .StopBgm = AUDIO_SPK_StopBgm
};

static AudioSfxDriverOps s_sfxOps =
{
    .Initialize = AUDIO_SPK_Noop,
    .Cleanup = AUDIO_SPK_Noop,
    .PlaySfx = AUDIO_SPK_PlaySfx,
    .StopSfx = AUDIO_SPK_StopSfx
};

AudioMusicDriverOps* AUDIO_SPK_GetMusicOps(void)
{
    return &s_musicOps;
}

AudioSfxDriverOps* AUDIO_SPK_GetSfxOps(void)
{
    return &s_sfxOps;
}
