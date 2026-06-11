#include "common/common.h"

#include "audio.h"
#include "aud_ops.h"

#include <stdio.h>

// TODO: clean up

#include <SDL3_mixer/SDL_mixer.h>

static MIX_Mixer* s_mixer;

static MIX_Track* s_bgmTrack;
static MIX_Track* s_sfxTrack;

static SDL_PropertiesID s_bgmTrackProp;

static SDL_AudioSpec s_mixerSpec;

static MIX_Audio* s_bgm[20];
static MIX_Audio* s_sfx[256];

static int s_currentBgmId;

void AUDIO_SDL_LoadBgmTable(void);
void AUDIO_SDL_LoadSfxTable(void);

void AUDIO_SDL_Init(void)
{
    MIX_Init();
    s_mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
    MIX_GetMixerFormat(s_mixer, &s_mixerSpec);

    s_bgmTrack = MIX_CreateTrack(s_mixer);
    s_sfxTrack = MIX_CreateTrack(s_mixer);

    MIX_SetTrackGain(s_bgmTrack, 0.3f);
    MIX_SetTrackGain(s_sfxTrack, 0.2f);

    s_bgmTrackProp = SDL_CreateProperties();
    SDL_SetNumberProperty(s_bgmTrackProp, MIX_PROP_PLAY_LOOPS_NUMBER, -1);

    AUDIO_SDL_LoadBgmTable();
    AUDIO_SDL_LoadSfxTable();
}

void AUDIO_SDL_Cleanup(void)
{
    // TODO: release audios

    MIX_DestroyTrack(s_bgmTrack);
    MIX_DestroyTrack(s_sfxTrack);
    MIX_DestroyMixer(s_mixer);
    s_mixer = NULL;
    MIX_Quit();
}

void AUDIO_SDL_LoadBgmTable(void)
{
    for (int i = 1; i <= 15; i++)
    {
        char fileName[256] = {0,};
        sprintf(fileName, "BGM/%02d.ogg", i);
        s_bgm[i] = MIX_LoadAudio(s_mixer, fileName, false);

        const char* err = SDL_GetError();
        if (err)
        {
            puts(err);
        }
    }
}

void AUDIO_SDL_LoadSfxTable(void)
{
    s_sfx[SFX_ID_FOOTSTEP] = MIX_LoadAudio(s_mixer, "SFX/walk.wav", true);
    s_sfx[SFX_ID_BLOCKED] = MIX_LoadAudio(s_mixer, "SFX/blocked.wav", true);
    s_sfx[SFX_ID_POISON] = MIX_LoadAudio(s_mixer, "SFX/poison.wav", true);
    //s_sfx[SFX_ID_FOUNTAIN] = MIX_LoadAudio(s_mixer, "SFX/fountain.wav", true);

    s_sfx[SFX_ID_HARPSI1] = MIX_LoadAudio(s_mixer, "SFX/harpsi1.wav", true);
    s_sfx[SFX_ID_HARPSI2] = MIX_LoadAudio(s_mixer, "SFX/harpsi2.wav", true);
    s_sfx[SFX_ID_HARPSI3] = MIX_LoadAudio(s_mixer, "SFX/harpsi3.wav", true);
    s_sfx[SFX_ID_HARPSI4] = MIX_LoadAudio(s_mixer, "SFX/harpsi4.wav", true);
    s_sfx[SFX_ID_HARPSI5] = MIX_LoadAudio(s_mixer, "SFX/harpsi5.wav", true);
    s_sfx[SFX_ID_HARPSI6] = MIX_LoadAudio(s_mixer, "SFX/harpsi6.wav", true);
    s_sfx[SFX_ID_HARPSI7] = MIX_LoadAudio(s_mixer, "SFX/harpsi7.wav", true);
    s_sfx[SFX_ID_HARPSI8] = MIX_LoadAudio(s_mixer, "SFX/harpsi8.wav", true);
    s_sfx[SFX_ID_HARPSI9] = MIX_LoadAudio(s_mixer, "SFX/harpsi9.wav", true);
    s_sfx[SFX_ID_HARPSI0] = MIX_LoadAudio(s_mixer, "SFX/harpsi10.wav", true);

    s_sfx[SFX_ID_GT1] = MIX_LoadAudio(s_mixer, "SFX/gt1.wav", true);
    s_sfx[SFX_ID_GT2] = MIX_LoadAudio(s_mixer, "SFX/gt2.wav", true);
    s_sfx[SFX_ID_GT3] = MIX_LoadAudio(s_mixer, "SFX/gt3.wav", true);
    s_sfx[SFX_ID_GT4] = MIX_LoadAudio(s_mixer, "SFX/gt4.wav", true);
    s_sfx[SFX_ID_GT5] = MIX_LoadAudio(s_mixer, "SFX/gt5.wav", true);
    s_sfx[SFX_ID_GT6] = MIX_LoadAudio(s_mixer, "SFX/gt6.wav", true);
    s_sfx[SFX_ID_GT7] = MIX_LoadAudio(s_mixer, "SFX/gt7.wav", true);
    s_sfx[SFX_ID_GT8] = MIX_LoadAudio(s_mixer, "SFX/gt8.wav", true);
    s_sfx[SFX_ID_GT9] = MIX_LoadAudio(s_mixer, "SFX/gt9.wav", true);
}

void AUDIO_SDL_PlaySfx(int id)
{
    if (s_sfx[id] == NULL)
        return;

    MIX_SetTrackAudio(s_sfxTrack, s_sfx[id]);
    MIX_PlayTrack(s_sfxTrack, 0);
    const char* err = SDL_GetError();
    if (err) { puts(err); }
}

void AUDIO_SDL_StopSfx(void)
{
    Sint64 frames = MIX_MSToFrames(s_mixerSpec.freq, 10);
    MIX_StopTrack(s_sfxTrack, frames);
    const char* err = SDL_GetError();
    if (err) { puts(err); }
}

void AUDIO_SDL_PlayBgm(int id)
{
    debug("AUDIO_SDL_PlayBgm(%d)", id);

    if (s_currentBgmId == id)
        return;

    s_currentBgmId = id;

    if (s_bgm[id] == NULL)
        return;

    MIX_SetTrackAudio(s_bgmTrack, s_bgm[id]);
    MIX_PlayTrack(s_bgmTrack, s_bgmTrackProp);
    const char* err = SDL_GetError();
    if (err) { puts(err); }
}

void AUDIO_SDL_StopBgm(void)
{
    debug("AUDIO_SDL_StopBgm()");

    s_currentBgmId = 0;

    Sint64 frames = MIX_MSToFrames(s_mixerSpec.freq, 500);
    MIX_StopTrack(s_bgmTrack, frames);
    const char* err = SDL_GetError();
    if (err) { puts(err); }
}

void AUDIO_SDL_Noop(void)
{
    // no-op
}

static AudioMusicDriverOps s_musicOps =
{
    .Initialize = AUDIO_SDL_Init,
    .Cleanup = AUDIO_SDL_Cleanup,
    .PlayBgm = AUDIO_SDL_PlayBgm,
    .StopBgm = AUDIO_SDL_StopBgm
};

static AudioSfxDriverOps s_sfxOps =
{
    .Initialize = AUDIO_SDL_Noop,
    .Cleanup = AUDIO_SDL_Noop,
    .PlaySfx = AUDIO_SDL_PlaySfx,
    .StopSfx = AUDIO_SDL_StopSfx
};

AudioMusicDriverOps* AUDIO_SDL_GetMusicOps(void)
{
    return &s_musicOps;
}

AudioSfxDriverOps* AUDIO_SDL_GetSfxOps(void)
{
    return &s_sfxOps;
}
