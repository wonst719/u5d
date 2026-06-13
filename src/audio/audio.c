#include "common/common.h"

#include "audio.h"

#include "aud_ops.h"

#if defined(TARGET_WINDOWS)
extern AudioMusicDriverOps* AUDIO_SDL_GetMusicOps(void);
extern AudioSfxDriverOps* AUDIO_SDL_GetSfxOps(void);
#elif defined(TARGET_DOS32)
extern AudioMusicDriverOps* AUDIO_CDDA_GetMusicOps(void);
extern AudioSfxDriverOps* AUDIO_SPK_GetSfxOps(void);
extern AudioSfxDriverOps* AUDIO_ADLIB_GetSfxOps(void);
#endif

static AudioMusicDriverOps* s_musicOps;
static AudioSfxDriverOps* s_sfxOps;

void AUDIO_Initialize(void)
{
#if defined(TARGET_WINDOWS)
    s_musicOps = AUDIO_SDL_GetMusicOps();
    s_sfxOps = AUDIO_SDL_GetSfxOps();
#elif defined(TARGET_DOS32)
    s_musicOps = AUDIO_CDDA_GetMusicOps();
    //s_sfxOps = AUDIO_SPK_GetSfxOps();
    s_sfxOps = AUDIO_ADLIB_GetSfxOps();
#endif

    if (s_musicOps)
        s_musicOps->Initialize();

    if (s_sfxOps)
        s_sfxOps->Initialize();
}

void AUDIO_Cleanup(void)
{
    if (s_musicOps)
        s_musicOps->Cleanup();

    if (s_sfxOps)
        s_sfxOps->Cleanup();
}

void AUDIO_PlaySfx(int id)
{
    if (!s_sfxOps)
        return;

    s_sfxOps->PlaySfx(id);
}

void AUDIO_StopSfx(void)
{
    if (!s_sfxOps)
        return;

    s_sfxOps->StopSfx();
}

int AUDIO_GetSfxType(void)
{
    if (!s_sfxOps)
        return SFX_TYPE_NONE;

    return s_sfxOps->GetSfxType();
}

void AUDIO_PlaySynthPulse(int freq, int delay, int dur, int pulseWidth, int pulseInc)
{
    if (!s_sfxOps)
        return;

    s_sfxOps->PlaySynthPulse(freq, delay, dur, pulseWidth, pulseInc);
}

void AUDIO_PlaySynthNoise(int rate, int dur, int limit)
{
    if (!s_sfxOps)
        return;

    s_sfxOps->PlaySynthNoise(rate, dur, limit);
}

void AUDIO_PlaySynthTone(int freq, int dur)
{
    if (!s_sfxOps)
        return;

    s_sfxOps->PlaySynthTone(freq, dur);
}

void AUDIO_PlaySynthSweepTone(int param_1, int param_2, int param_3, int param_4)
{
    if (!s_sfxOps)
        return;

    s_sfxOps->PlaySynthSweepTone(param_1, param_2, param_3, param_4);
}

void AUDIO_PlayBgm(int id)
{
    if (!s_musicOps)
        return;

    s_musicOps->PlayBgm(id);
}

void AUDIO_QueueBgm(int id)
{
    if (!s_musicOps)
        return;

    s_musicOps->QueueBgm(id);
}

void AUDIO_StopBgm(void)
{
    if (!s_musicOps)
        return;

    s_musicOps->StopBgm();
}
