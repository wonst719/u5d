#ifndef _AUDIO_AUDIO_H
#define _AUDIO_AUDIO_H

#define BGM_ID_1 1
#define BGM_ID_2 2
#define BGM_ID_3 3
#define BGM_ID_4 4
#define BGM_ID_5 5
#define BGM_ID_6 6
#define BGM_ID_7 7
#define BGM_ID_8 8
#define BGM_ID_9 9
#define BGM_ID_10 10
#define BGM_ID_11 11
#define BGM_ID_12 12
#define BGM_ID_13 13
#define BGM_ID_14 14
#define BGM_ID_15 15
#define BGM_ID_16 16
#define BGM_ID_17 17

#define SFX_TYPE_NONE 0
#define SFX_TYPE_PCM 1
#define SFX_TYPE_SYNTH 2

extern void AUDIO_Initialize(void);
extern void AUDIO_Cleanup(void);

extern void AUDIO_PlayBgm(int id);
extern void AUDIO_QueueBgm(int id);
extern void AUDIO_StopBgm(void);

extern void AUDIO_PlaySfx(int id);
extern void AUDIO_StopSfx(void);
extern int AUDIO_GetSfxType(void);
extern void AUDIO_PlaySynthPulse(int freq, int delay, int dur, int pulseWidth, int pulseInc);
extern void AUDIO_PlaySynthNoise(int rate, int dur, int limit);
extern void AUDIO_PlaySynthTone(int freq, int dur);
extern void AUDIO_PlaySynthSweepTone(int param_1, int param_2, int param_3, int param_4);

#endif
