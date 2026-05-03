#include <stdio.h>

#include "AUD_DRV.H"
#include "COMMON.H"

// TODO: clean up

#if defined(TARGET_WINDOWS)
#include <SDL3_mixer/SDL_mixer.h>
#endif

static MIX_Mixer* s_mixer;

static MIX_Track* s_bgmTrack;
static MIX_Track* s_sfxTrack;

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
    MIX_SetTrackGain(s_sfxTrack, 0.3f);

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
    s_bgm[1] = MIX_LoadAudio(s_mixer, "BGM/01.ogg", FALSE);
    s_bgm[9] = MIX_LoadAudio(s_mixer, "BGM/09.ogg", FALSE);
    const char* err = SDL_GetError();
    if (err) { puts(err); }
}

void AUDIO_LoadSfxTable(void)
{
    s_sfx[0] = MIX_LoadAudio(s_mixer, "SFX/walk.wav", TRUE);
    s_sfx[1] = MIX_LoadAudio(s_mixer, "SFX/blocked.wav", TRUE);
}

void AUDIO_PlaySfx(int id)
{
    MIX_SetTrackAudio(s_sfxTrack, s_sfx[id]);
    MIX_PlayTrack(s_sfxTrack, 0);
    const char* err = SDL_GetError();
    if (err) { puts(err); }
}

void AUDIO_PlayBgm(int id)
{
    if (s_currentBgmId == id)
        return;

    s_currentBgmId = id;

    MIX_SetTrackAudio(s_bgmTrack, s_bgm[id]);
    MIX_PlayTrack(s_bgmTrack, 0);
    const char* err = SDL_GetError();
    if (err) { puts(err); }
}

void AUDIO_StopBgm(void)
{
    s_currentBgmId = 0;

    Sint64 frames = MIX_MSToFrames(s_mixerSpec.freq, 1000);
    MIX_StopTrack(s_bgmTrack, frames);
    const char* err = SDL_GetError();
    if (err) { puts(err); }
}

// 2192
void AUDIO_DispatchPulse(int freq, int delay, int dur, int pulseWidth, int pulseInc)
{
    debug("AUDIO_DispatchPulse(%d,%d,%d,%d,%d)", freq, delay, dur, pulseWidth, pulseInc);

    // TOWN_11b8 An air of *** doth surround thee...
    // ULTIMA_2192_AudioPulse(0x19c8, 1, 60000, 2000, 1);
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
}

// 43ae
void AUDIO_DispatchSweepTone(int param_1, int param_2, int param_3, int param_4)
{
    debug("AUDIO_DispatchSweepTone(%d,%d,%d,%d)", param_1, param_2, param_3, param_4);
}
