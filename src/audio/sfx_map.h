/* AUTO-GENERATED - do not edit by hand. */
#ifndef _AUDIO_SFX_MAP_H
#define _AUDIO_SFX_MAP_H

#include "common/common.h"
#include "audio.h"

#define SFX_TYPE_PULSE 0
#define SFX_TYPE_NOISE 1
#define SFX_TYPE_TONE  2
#define SFX_TYPE_SWEEP 3
#define SFX_TYPE_UNMAPPED 255

#define SFX_ID_MIN                     1
#define SFX_ID_MAX                   113
#define SFX_ID_HARPSICHORD_BASE       20
#define SFX_ID_LUTE_BASE              30
#define SFX_ID_CAST2_BASE             39
#define SFX_ID_BLACKTHORN_PHRASE_BASE  49
#define SFX_ID_CAST2_PHRASE_BASE      55
#define SFX_ID_APPARITION_PHRASE_BASE  62
#define SFX_ID_GEMSHARD              109
#define SFX_ID_SHRINE1               110
#define SFX_ID_SHRINE2               111

typedef struct SfxRule
{
    s32 parameter[5];
    const char* fileName;
    u16 sfxId;
    u8  type;
} SfxRule;

static const SfxRule g_sfxRules[] = {
    { {   3116,      1,   2000,  20000,  -10 }, "chime.wav",   1, SFX_TYPE_PULSE },
    { {   5900,      1,  30000,   2000,    2 }, "moongate.wav",   2, SFX_TYPE_PULSE },
    { {   4050,      1,  65000,      1,    1 }, "sceptre.wav",   3, SFX_TYPE_PULSE },
    { {   2800,      1,  13000,    100,    5 }, "blackapp.wav",   4, SFX_TYPE_PULSE },
    { {   9800,      1,  28000,   1000,    2 }, "absorb.wav",   5, SFX_TYPE_PULSE },
    { {   5200,      1,  50000,   5000,    1 }, "sceptuse.wav",   6, SFX_TYPE_PULSE },
    { {   4480,      1,  65000,    300,    1 }, "artifact.wav",   7, SFX_TYPE_PULSE },
    { {   2760,      1,  12000,    500,    5 }, "summon.wav",   8, SFX_TYPE_PULSE },
    { {  10400,      1,  30000,   2000,    2 }, "shadowin.wav",   9, SFX_TYPE_PULSE },
    { {   3100,      1,  30000,   1000,    2 }, "possess.wav",  10, SFX_TYPE_PULSE },
    { {   2760,      1,   5000,   1000,   15 }, "gatein.wav",  11, SFX_TYPE_PULSE },
    { {   8800,      1,  40000,   5000,    1 }, "revive.wav",  12, SFX_TYPE_PULSE },
    { {   5200,      1,  50000,  10000,    1 }, "endmoon.wav",  13, SFX_TYPE_PULSE },
    { {   2620,      1,  10000,   2500,    6 }, "spiritin.wav",  14, SFX_TYPE_PULSE },
    { {   5500,      1,   5000,    200,   13 }, "raise.wav",  15, SFX_TYPE_PULSE },
    { {   4110,      1,  22500,   5000,    1 }, "shop0.wav",  16, SFX_TYPE_PULSE },
    { {   4530,      1,  40000,      1,    1 }, "shop1.wav",  17, SFX_TYPE_PULSE },
    { {   2300,      1,  18000,      1,    2 }, "shop2.wav",  18, SFX_TYPE_PULSE },
    { {   6600,      1,  60000,   2000,    1 }, "air.wav",  19, SFX_TYPE_PULSE },
    { {      0,      0,      0,      0,    0 }, "harpsi0.wav",  20, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "harpsi1.wav",  21, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "harpsi2.wav",  22, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "harpsi3.wav",  23, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "harpsi4.wav",  24, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "harpsi5.wav",  25, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "harpsi6.wav",  26, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "harpsi7.wav",  27, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "harpsi8.wav",  28, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "harpsi9.wav",  29, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "lute0.wav",  30, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "lute1.wav",  31, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "lute2.wav",  32, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "lute3.wav",  33, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "lute4.wav",  34, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "lute5.wav",  35, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "lute6.wav",  36, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "lute7.wav",  37, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "lute8.wav",  38, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "cast1.wav",  39, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "cast2.wav",  40, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "cast3.wav",  41, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "cast4.wav",  42, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "cast5.wav",  43, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "cast6.wav",  44, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "cast7.wav",  45, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "cast8.wav",  46, SFX_TYPE_UNMAPPED },
    { {   4600,      1,  10800,    300,    6 }, "victory1.wav",  47, SFX_TYPE_PULSE },
    { {   6100,      1,  21600,    300,    3 }, "victory2.wav",  48, SFX_TYPE_PULSE },
    { {      0,      0,      0,      0,    0 }, "thorn0.wav",  49, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "thorn1.wav",  50, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "thorn2.wav",  51, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "thorn3.wav",  52, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "thorn4.wav",  53, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "thorn5.wav",  54, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "chant0.wav",  55, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "chant1.wav",  56, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "chant2.wav",  57, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "chant3.wav",  58, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "chant4.wav",  59, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "chant5.wav",  60, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "chant6.wav",  61, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "spirit0.wav",  62, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "spirit1.wav",  63, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "spirit2.wav",  64, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "spirit3.wav",  65, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "spirit4.wav",  66, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "spirit5.wav",  67, SFX_TYPE_UNMAPPED },
    { {     10,   1600,   2000,      0,    0 }, "damage.wav",  68, SFX_TYPE_NOISE },
    { {     40,   3000,    500,      0,    0 }, "burst1.wav",  69, SFX_TYPE_NOISE },
    { {     10,   3000,   2000,      0,    0 }, "burst2.wav",  70, SFX_TYPE_NOISE },
    { {     20,     60,  10000,      0,    0 }, "watrfall.wav",  71, SFX_TYPE_NOISE },
    { {     10,     30,  25000,      0,    0 }, "fountain.wav",  72, SFX_TYPE_NOISE },
    { {      1,     25,   1000,      0,    0 }, "step0.wav",  73, SFX_TYPE_NOISE },
    { {      1,     25,   1500,      0,    0 }, "step1.wav",  74, SFX_TYPE_NOISE },
    { {      1,   7000,    600,      0,    0 }, "regurgit.wav",  75, SFX_TYPE_NOISE },
    { {      1,    500,  20000,      0,    0 }, "shock.wav",  76, SFX_TYPE_NOISE },
    { {      1,     50,   3500,      0,    0 }, "status.wav",  77, SFX_TYPE_NOISE },
    { {      1,   1200,   4000,      0,    0 }, "introhit.wav",  78, SFX_TYPE_NOISE },
    { {    100,   2000,    300,      0,    0 }, "shiphit.wav",  79, SFX_TYPE_NOISE },
    { {      1,     15,  20000,      0,    0 }, "dunstep0.wav",  80, SFX_TYPE_NOISE },
    { {      1,     11,  20000,      0,    0 }, "dunstep1.wav",  81, SFX_TYPE_NOISE },
    { {      1,      7,  20000,      0,    0 }, "dunstep2.wav",  82, SFX_TYPE_NOISE },
    { {      1,      3,  20000,      0,    0 }, "dunstep3.wav",  83, SFX_TYPE_NOISE },
    { {    800,   9600,    700,      0,    0 }, "spell1.wav",  84, SFX_TYPE_NOISE },
    { {    800,  11200,    700,      0,    0 }, "spell2.wav",  85, SFX_TYPE_NOISE },
    { {    800,  12800,    700,      0,    0 }, "spell3.wav",  86, SFX_TYPE_NOISE },
    { {    800,  14400,    700,      0,    0 }, "spell4.wav",  87, SFX_TYPE_NOISE },
    { {    800,  16000,    700,      0,    0 }, "spell5.wav",  88, SFX_TYPE_NOISE },
    { {    800,  17600,    700,      0,    0 }, "spell6.wav",  89, SFX_TYPE_NOISE },
    { {    800,  19200,    700,      0,    0 }, "spell7.wav",  90, SFX_TYPE_NOISE },
    { {    800,  20800,    700,      0,    0 }, "spell8.wav",  91, SFX_TYPE_NOISE },
    { {   3000,      3,      0,      0,    0 }, "tickhigh.wav",  92, SFX_TYPE_TONE },
    { {   2000,      3,      0,      0,    0 }, "ticklow.wav",  93, SFX_TYPE_TONE },
    { {    165,    200,      0,      0,    0 }, "blocked.wav",  94, SFX_TYPE_TONE },
    { {    220,    150,      0,      0,    0 }, "denyhi.wav",  95, SFX_TYPE_TONE },
    { {    150,    150,      0,      0,    0 }, "denylo.wav",  96, SFX_TYPE_TONE },
    { {   1200,   2000,      1,     40,    0 }, "vanish.wav",  97, SFX_TYPE_SWEEP },
    { {    800,   2000,      1,     50,    0 }, "failure.wav",  98, SFX_TYPE_SWEEP },
    { {   1000,    200,      5,    300,    0 }, "cannon.wav",  99, SFX_TYPE_SWEEP },
    { {    750,    400,      5,    150,    0 }, "foefire.wav", 100, SFX_TYPE_SWEEP },
    { {   1300,    300,      5,    100,    0 }, "launch.wav", 101, SFX_TYPE_SWEEP },
    { {    400,    750,      5,    150,    0 }, "attack.wav", 102, SFX_TYPE_SWEEP },
    { {    660,    150,     40,   7800,    0 }, "whirl.wav", 103, SFX_TYPE_SWEEP },
    { {   2500,    800,      1,    300,    0 }, "fall.wav", 104, SFX_TYPE_SWEEP },
    { {   3200,   3500,      1,     20,    0 }, "drip0.wav", 105, SFX_TYPE_SWEEP },
    { {      0,      0,      0,      0,    0 }, "drip1.wav", 106, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "drip2.wav", 107, SFX_TYPE_UNMAPPED },
    { {   1000,    250,     40,  30000,    0 }, "trapfall.wav", 108, SFX_TYPE_SWEEP },
    { {      0,      0,      0,      0,    0 }, "gemshard.wav", 109, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "shrine1.wav", 110, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "shrine2.wav", 111, SFX_TYPE_UNMAPPED },
    { {      0,      0,      0,      0,    0 }, "mirror.wav", 112, SFX_TYPE_UNMAPPED },
    { {     19,  16000,    150,      0,    0 }, "shake.wav", 113, SFX_TYPE_NOISE },
    { {   3200,   3500,      1,     12,    0 }, "drip0.wav", 105, SFX_TYPE_SWEEP },
    { {   3200,   3500,      1,      4,    0 }, "drip0.wav", 105, SFX_TYPE_SWEEP },
};

#define SFX_RULE_COUNT ((int)(sizeof(g_sfxRules) / sizeof(g_sfxRules[0])))

#endif
