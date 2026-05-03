#ifndef _AUD_SFX_H
#define _AUD_SFX_H

// 2192
extern void AUDIO_DispatchPulse(int freq, int delay, int dur, int pulseWidth, int pulseInc);

// 223c
extern void AUDIO_DispatchWhiteNoise(uint rate, uint dur, uint limit);

// 22c0
extern void AUDIO_DispatchTone(uint freq, uint dur);

// 43ae
extern void AUDIO_DispatchSweepTone(int param_1, int param_2, int param_3, int param_4);

#endif
