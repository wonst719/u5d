#include "common/common.h"

#include "audio.h"

#include "aud_ops.h"

#if defined(TARGET_WINDOWS)
extern AudioMusicDriverOps* AUDIO_SDL_GetMusicOps(void);
extern AudioSfxDriverOps* AUDIO_SDL_GetSfxOps(void);
#endif

static AudioMusicDriverOps* s_musicOps;
static AudioSfxDriverOps* s_sfxOps;

void AUDIO_Init(void)
{
#if defined(TARGET_WINDOWS)
    s_musicOps = AUDIO_SDL_GetMusicOps();
    s_sfxOps = AUDIO_SDL_GetSfxOps();
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

void AUDIO_PlayBgm(int id)
{
    if (!s_musicOps)
        return;

    s_musicOps->PlayBgm(id);
}

void AUDIO_StopBgm(void)
{
    if (!s_musicOps)
        return;

    s_musicOps->StopBgm();
}
