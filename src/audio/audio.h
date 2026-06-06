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

#define SFX_ID_FOOTSTEP 0
#define SFX_ID_BLOCKED 3
#define SFX_ID_POISON 0xd
#define SFX_ID_FOUNTAIN 0x11

#define SFX_ID_HARPSI0 0x80
#define SFX_ID_HARPSI1 0x81
#define SFX_ID_HARPSI2 0x82
#define SFX_ID_HARPSI3 0x83
#define SFX_ID_HARPSI4 0x84
#define SFX_ID_HARPSI5 0x85
#define SFX_ID_HARPSI6 0x86
#define SFX_ID_HARPSI7 0x87
#define SFX_ID_HARPSI8 0x88
#define SFX_ID_HARPSI9 0x89

#define SFX_ID_GT1 0x91
#define SFX_ID_GT2 0x92
#define SFX_ID_GT3 0x93
#define SFX_ID_GT4 0x94
#define SFX_ID_GT5 0x95
#define SFX_ID_GT6 0x96
#define SFX_ID_GT7 0x97
#define SFX_ID_GT8 0x98
#define SFX_ID_GT9 0x99

extern void AUDIO_Initialize(void);
extern void AUDIO_Cleanup(void);

extern void AUDIO_PlayBgm(int id);
extern void AUDIO_StopBgm(void);

extern void AUDIO_PlaySfx(int id);
extern void AUDIO_StopSfx(void);

#endif
