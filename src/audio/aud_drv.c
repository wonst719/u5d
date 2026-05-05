#include "aud_drv.h"
#include "common/common.h"

#include <stdio.h>

// TODO: clean up

#include <SDL3_mixer/SDL_mixer.h>

static MIX_Mixer* s_mixer;

static MIX_Track* s_bgmTrack;
static MIX_Track* s_sfxTrack;

static SDL_PropertiesID s_bgmTrackProp;

static SDL_AudioSpec s_mixerSpec;

static MIX_Audio* s_bgm[20];
static MIX_Audio* s_sfx[20];

static int s_currentBgmId;

void AUDIO_LoadBgmTable(void);
void AUDIO_LoadSfxTable(void);

void AUDIO_Init(void)
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

    AUDIO_LoadBgmTable();
    AUDIO_LoadSfxTable();
}

void AUDIO_Cleanup(void)
{
    // TODO: release audios

    MIX_DestroyTrack(s_bgmTrack);
    MIX_DestroyTrack(s_sfxTrack);
    MIX_DestroyMixer(s_mixer);
    s_mixer = NULL;
    MIX_Quit();
}

void AUDIO_LoadBgmTable(void)
{
    s_bgm[1] = MIX_LoadAudio(s_mixer, "BGM/01.ogg", false);
    s_bgm[9] = MIX_LoadAudio(s_mixer, "BGM/09.ogg", false);
    const char* err = SDL_GetError();
    if (err) { puts(err); }
}

void AUDIO_LoadSfxTable(void)
{
    s_sfx[SFX_ID_FOOTSTEP] = MIX_LoadAudio(s_mixer, "SFX/walk.wav", true);
    s_sfx[SFX_ID_BLOCKED] = MIX_LoadAudio(s_mixer, "SFX/blocked.wav", true);
    s_sfx[SFX_ID_POISON] = MIX_LoadAudio(s_mixer, "SFX/poison.wav", true);
    //s_sfx[SFX_ID_FOUNTAIN] = MIX_LoadAudio(s_mixer, "SFX/fountain.wav", TRUE);
}

void AUDIO_PlaySfx(int id)
{
    MIX_SetTrackAudio(s_sfxTrack, s_sfx[id]);
    MIX_PlayTrack(s_sfxTrack, 0);
    const char* err = SDL_GetError();
    if (err) { puts(err); }
}

void AUDIO_StopSfx(void)
{
    Sint64 frames = MIX_MSToFrames(s_mixerSpec.freq, 10);
    MIX_StopTrack(s_sfxTrack, frames);
    const char* err = SDL_GetError();
    if (err) { puts(err); }
}

void AUDIO_PlayBgm(int id)
{
    if (s_currentBgmId == id)
        return;

    s_currentBgmId = id;

    MIX_SetTrackAudio(s_bgmTrack, s_bgm[id]);
    MIX_PlayTrack(s_bgmTrack, s_bgmTrackProp);
    const char* err = SDL_GetError();
    if (err) { puts(err); }
}

void AUDIO_StopBgm(void)
{
    s_currentBgmId = 0;

    Sint64 frames = MIX_MSToFrames(s_mixerSpec.freq, 500);
    MIX_StopTrack(s_bgmTrack, frames);
    const char* err = SDL_GetError();
    if (err) { puts(err); }
}
