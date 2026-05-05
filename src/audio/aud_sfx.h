#ifndef _AUDIO_AUD_SFX_H
#define _AUDIO_AUD_SFX_H

#if defined(TARGET_DOS16) || defined(TARGET_DOS32)

#define AUDIO_DispatchPulse(freq, delay, dur, pulseWidth, pulseInc)
#define AUDIO_DispatchWhiteNoise(rate, dur, limit)
#define AUDIO_DispatchTone(freq, dur)
#define AUDIO_DispatchSweepTone(param_1, param_2, param_3, param_4)

#else

// 2192
extern void AUDIO_DispatchPulse(int freq, int delay, int dur, int pulseWidth, int pulseInc);

// 223c
extern void AUDIO_DispatchWhiteNoise(uint rate, uint dur, uint limit);

// 22c0
extern void AUDIO_DispatchTone(uint freq, uint dur);

// 43ae
extern void AUDIO_DispatchSweepTone(int param_1, int param_2, int param_3, int param_4);

#endif

#endif
