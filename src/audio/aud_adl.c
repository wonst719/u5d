#include "common/common.h"

#include "audio.h"
#include "aud_ops.h"
#include "vars.h"
#include "time/time.h"

#include <dos.h>

#include "event/event.h"

// assist ide
#if !defined(TARGET_DOS32)
#define inportb(port) (0)
#define inportw(port) (0)
#define outportb(port, val)
#define outportw(port, val)
#endif

static bool s_adlibAvailable = false;
static int s_oplPort = -1;

static int s_indexWriteDelay = 6;
static int s_dataWriteDelay = 35;

static int s_adlibPorts[3] =
{
    0x388, 0x220, 0x240
};

static void OplWrite(u8 reg, u8 data)
{
	int i;

	//debug("OPL OplWrite: reg %02xh, data %02xh", reg, data);

	outportb(s_oplPort, reg);

	for (i = 0; i < s_indexWriteDelay; i++)
	{
		inportb(s_oplPort);
	}

	outportb(s_oplPort + 1, data);

	for (i = 0; i < s_dataWriteDelay; i++)
	{
		inportb(s_oplPort);
	}
}

static void OplReset()
{
	for (int i = 0xf5; i > 0; i--)
	{
		OplWrite(i, 0);
	}

	for (int i = 0x40; i <= 0x55; i++)
	{
		OplWrite(i, 0x3f);
	}

	for (int i = 0x80; i <= 0x95; i++)
	{
		OplWrite(i, 0xff);
	}

	OplWrite(0x01, 0x20);
}

static bool OplDetect()
{
	u8 status;

    // 0. Init test register
	OplWrite(1, 0);

    // 1. Reset Timer 1, 2
	OplWrite(4, 0x60);

    // 2. Reset the IRQ
    OplWrite(4, 0x80);

	// 3. Read status register
	status = inportb(s_oplPort) & 0xe0;
	if (status != 0)
	{
		debug("OPL detect fail: status1 %d", status);
		return false;
	}

	// 4. Set Timer 1 to FFh
	OplWrite(2, 0xff);

	// 5. Start Timer 1
	OplWrite(4, 0x21);

	// 6. Wait
	TIME_SleepMs(100);

	// 7. Read status register
	status = inportb(s_oplPort) & 0xe0;
	if (status != 0xc0)
	{
		debug("OPL detect fail: status2 %d", status);
		return false;
	}

	// 8. Reset Timer 1, 2 and IRQ
	OplWrite(4, 0x60);
	OplWrite(4, 0x80);

	debug("OPL detect success");
	return true;
}

static bool DetectAdlib()
{
	bool detected = false;

	if (s_oplPort >= 0)
	{
        if (!OplDetect())
        {
			detected = true;
        }
    }
	else
	{
        for (int i = 0; i < ARRAYSIZE(s_adlibPorts); i++)
        {
            s_oplPort = s_adlibPorts[i];

            if (OplDetect())
            {
				detected = true;
				break;
            }
        }
    }

	return detected;
}

// Adlib sfx driver
// TODO: cleanup

// per operator
typedef struct OperatorSetting
{
	// 20
	union
	{
		u8 byte;
		struct
		{
			u8 mul : 4;
			u8 ksr : 1;
			u8 sustain : 1;
			u8 vibrato : 1;
			u8 tremolo : 1;
		};
	} _20;

	// 40
	union
	{
		u8 byte;
		struct
		{
			u8 ol : 6;
			u8 ksl : 2;
		};
	} _40;

	// 60
	union
	{
		u8 byte;
		struct
		{
			u8 dr : 4;
			u8 ar : 4;
		};
	} _60;

	// 80
	union
	{
		u8 byte;
		struct
		{
			u8 rr : 4;
			u8 sl : 4;
		};
	} _80;

	// e0
	union
	{
		u8 byte;
		struct
		{
			u8 ws : 2;
		};
	} _e0;
} OperatorSetting;

typedef struct InstrumentSetting
{
	OperatorSetting op1;
	OperatorSetting op2;

	// c0
	union
	{
		u8 byte;
		struct
		{
			u8 fm : 1;
			u8 fb : 3;
		};
	} _c0;

} InstrumentSetting;

InstrumentSetting instruments[] =
{
	// noise
    {
        .op1 = {
			._20 = {
				.mul = 0,
				.ksr = 0,
				.sustain = 1
			},
			._40 = {
				.ol = 4
			},
			._60 = {
				.ar = 15,
				.dr = 0
			},
			._80 = {
				.sl = 0,
				.rr = 15
			},
			._e0 = {
				.ws = 0
			}
        },
		.op2 = {
			._20 = {
				.mul = 8,
				.ksr = 0,
				.sustain = 1
			},
			._40 = {
				.ol = 0
			},
			._60 = {
				.ar = 15,
				.dr = 0
			},
			._80 = {
				.sl = 0,
				.rr = 15
			},
			._e0 = {
				.ws = 3
			}
		},
		._c0 = {
			.fb = 5,
			.fm = 0
		}
    },
	// sqr
	{
		.op1 = {
			._20 = {
				.mul = 2,
				.ksr = 0,
				.sustain = 1
			},
			._40 = {
				.ol = 0x1a,
				.ksl = 2
			},
			._60 = {
				.ar = 15,
				.dr = 0
			},
			._80 = {
				.sl = 0,
				.rr = 15
			},
			._e0 = {
				.ws = 0
			}
		},
		.op2 = {
			._20 = {
				.mul = 1,
				.ksr = 0,
				.sustain = 1
			},
			._40 = {
				.ol = 0
			},
			._60 = {
				.ar = 15,
				.dr = 0
			},
			._80 = {
				.sl = 0,
				.rr = 15
			},
			._e0 = {
				.ws = 0
			}
		},
		._c0 = {
			.fb = 7,
			.fm = 0
		}
	},
	// sqr2h
	{
		.op1 = {
			._20 = {
				.mul = 2,
				.ksr = 0,
				.sustain = 1
			},
			._40 = {
				.ol = 0x16,
				.ksl = 2
			},
			._60 = {
				.ar = 15,
				.dr = 0
			},
			._80 = {
				.sl = 0,
				.rr = 15
			},
			._e0 = {
				.ws = 0
			}
		},
		.op2 = {
			._20 = {
				.mul = 1,
				.ksr = 0,
				.sustain = 1
			},
			._40 = {
				.ol = 0
			},
			._60 = {
				.ar = 15,
				.dr = 0
			},
			._80 = {
				.sl = 0,
				.rr = 15
			},
			._e0 = {
				.ws = 0
			}
		},
		._c0 = {
			.fb = 7,
			.fm = 0
		}
	},
	// pulse
	{
		.op1 = {
			._20 = {
				.mul = 0,
				.ksr = 0,
				.sustain = 1
			},
			._40 = {
				.ol = 0x1a,
				.ksl = 0
			},
			._60 = {
				.ar = 15,
				.dr = 2
			},
			._80 = {
				.sl = 15,
				.rr = 0
			},
			._e0 = {
				.ws = 3
			}
		},
		.op2 = {
			._20 = {
				.mul = 1,
				.ksr = 0,
				.sustain = 1
			},
			._40 = {
				.ol = 0
			},
			._60 = {
				.ar = 11,
				.dr = 4
			},
			._80 = {
				.sl = 1,
				.rr = 8
			},
			._e0 = {
				.ws = 0
			}
		},
		._c0 = {
			.fb = 5,
			.fm = 0
		}
	},
	// water
	{
		.op1 = {
			._20 = {
				.mul = 0,
				.ksr = 1,
				.sustain = 0
			},
			._40 = {
				.ol = 0xc,
				.ksl = 0
			},
			._60 = {
				.ar = 15,
				.dr = 0
			},
			._80 = {
				.sl = 0,
				.rr = 8
			},
			._e0 = {
				.ws = 0
			}
		},
		.op2 = {
			._20 = {
				.mul = 15,
				.ksr = 1,
				.sustain = 0
			},
			._40 = {
				.ol = 0
			},
			._60 = {
				.ar = 13,
				.dr = 8
			},
			._80 = {
				.sl = 15,
				.rr = 8
			},
			._e0 = {
				.ws = 0
			}
		},
		._c0 = {
			.fb = 2,
			.fm = 0
		}
	}
};

typedef union KslOl
{
	u8 byte;
	struct
	{
		u8 ol : 6;
		u8 ksl : 2;
	};
} KslOl;

static byte s_chanToOpMap[] =
{
    0, 1, 2, 3, 4, 5,
    8, 9, 10, 11, 12, 13,
    16, 17, 18, 19, 20, 21
};

static void SetInstrumentSetting(int ch, InstrumentSetting* instrument)
{
	//debug("OPL SetInstrumentSetting: ch %d", ch);

	// melodic mode only
	int op1 = (ch / 3) * 6 + (ch % 3);
    int op2 = op1 + 3;

	OplWrite(0x20 + s_chanToOpMap[op1], instrument->op1._20.byte);
	OplWrite(0x40 + s_chanToOpMap[op1], instrument->op1._40.byte);
	OplWrite(0x60 + s_chanToOpMap[op1], instrument->op1._60.byte);
	OplWrite(0x80 + s_chanToOpMap[op1], instrument->op1._80.byte);
	OplWrite(0xe0 + s_chanToOpMap[op1], instrument->op1._e0.byte);

	OplWrite(0x20 + s_chanToOpMap[op2], instrument->op2._20.byte);
	OplWrite(0x40 + s_chanToOpMap[op2], instrument->op2._40.byte);
	OplWrite(0x60 + s_chanToOpMap[op2], instrument->op2._60.byte);
	OplWrite(0x80 + s_chanToOpMap[op2], instrument->op2._80.byte);
	OplWrite(0xe0 + s_chanToOpMap[op2], instrument->op2._e0.byte);

	OplWrite(0xc0 + ch, instrument->_c0.byte);
}

static void SetVolumeSetting(int ch, InstrumentSetting* instrument, int relativeLevel)
{
	//debug("OPL SetInstrumentSetting: ch %d", ch);

	// melodic mode only
	int op1 = (ch / 3) * 6 + (ch % 3);
	int op2 = op1 + 3;

	u8 newOl = (instrument->op2._40.ol + relativeLevel) & 0x3f;
	KslOl kslOl;
	kslOl.ol = newOl;
	kslOl.ksl = instrument->op2._40.ksl;

	OplWrite(0x40 + s_chanToOpMap[op2], kslOl.byte);
}

static int s_blockFreqTable[8] = { 48, 97, 194, 388, 776, 1552, 3104, 6208 };

static u16 CalcBlock(int freq)
{
	for (int i = 0; i < ARRAYSIZE(s_blockFreqTable); i++)
	{
		if (freq < s_blockFreqTable[i])
			return i;
	}

	return 7;
}

static u16 CalcFnum(int freq, int block)
{
	u32 x = 1u << (u32)(20 - block);
	return (freq * x / 49716) & 1023;
}

static int s_chanFreqMap[9] = { 0, };
int s_nextChannel = 0;

static void KeyOn(int ch, int freq)
{
	u16 block = CalcBlock(freq);
	u16 fnum = CalcFnum(freq, block);

	//debug("OPL KeyOn: ch %d, freq %d - block %d, fnum %d", ch, freq, (int)block, (int)fnum);

	s_chanFreqMap[ch] = freq;
	OplWrite(0xa0 + ch, fnum & 0xff); // fnum
	OplWrite(0xb0 + ch, (1 << 5) | (block << 2) | (fnum >> 8)); // kon | bnum | fnum_hi
}

static void KeyOff(int ch)
{
	//debug("OPL KeyOff: ch %d", ch);

	int freq = s_chanFreqMap[ch];
	u16 block = CalcBlock(freq);
	u16 fnum = CalcFnum(freq, block);

	OplWrite(0xa0 + ch, fnum & 0xff); // fnum
	OplWrite(0xb0 + ch, 0 | (block << 2) | (fnum >> 8)); // kon | bnum | fnum_hi
}

static void SetInstrument(int ch, int instr)
{
	SetInstrumentSetting(ch, &instruments[instr]);
}

static void SetVolume(int ch, int instr, int relativeLevel)
{
	SetVolumeSetting(ch, &instruments[instr], relativeLevel);
}

static void AUDIO_ADLIB_Initialize(void)
{
	s_adlibAvailable = DetectAdlib();
	OplReset();
}

static void AUDIO_ADLIB_Cleanup(void)
{
	if (!s_adlibAvailable)
		return;

	OplReset();
}

static void AUDIO_ADLIB_PlaySfx(int id)
{
	// no-op
}

static void AUDIO_ADLIB_StopSfx(void)
{
	// no-op
}

static int AUDIO_ADLIB_GetSfxType(void)
{
	return SFX_TYPE_SYNTH;
}

//
#define SFX_CH_1 6
#define SFX_CH_2 7
#define SFX_CH_3 8

static u32 SyncToNextTick()
{
	EVT_Yield();
	u32 tick = TIME_GetTickCounter();
	while (tick == TIME_GetTickCounter()) {}
	tick = TIME_GetTickCounter();
	return tick;
}

static void BusyWaitTicks(u32 startTick, u32 count)
{
	while (TIME_GetTickCounter() < startTick + count)
	{}
}

static void PlayTone(int ch, int instr, int freq, int durMs)
{
	SetInstrument(ch, instr);
	KeyOn(ch, freq);
	TIME_SleepMs(durMs);
	KeyOff(ch);
}

static void AUDIO_ADLIB_PlaySynthPulse(int freq, int delay, int dur, int pulseWidth, int pulseInc)
{
	if (!s_adlibAvailable)
		return;

	// cast 1
	for (int i = 0; i < 9; i++)
	{
		if (dur == i * 4000 + 10000 && pulseWidth == D_4b08[i] && pulseInc == D_4b2c[i])
		{
			dur *= 2;
			break;
		}
	}

	// cast 2
	for (int i = 0; i < 9; i++)
	{
		if (dur == i * 4000 + 10000 && pulseWidth == D_4b1a[i] && pulseInc == -D_4b2c[i])
		{
			// ignore
			return;
		}
	}

	int ch1 = s_nextChannel;
	s_nextChannel = (s_nextChannel + 1) % 3;
	int ch2 = s_nextChannel;
	s_nextChannel = (s_nextChannel + 1) % 3;

	SetInstrument(SFX_CH_1 + ch1, 3);
	SetInstrument(SFX_CH_1 + ch2, 3);
	SetVolume(SFX_CH_1 + ch2, 3, 8);
	KeyOn(SFX_CH_1 + ch1, freq / 4);
	KeyOn(SFX_CH_1 + ch2, freq / 4 - 7);
	TIME_SleepMs(dur / 20);
	KeyOff(SFX_CH_1 + ch1);
	KeyOff(SFX_CH_1 + ch2);
}

static void AUDIO_ADLIB_PlaySynthNoise(int rate, int dur, int limit)
{
	if (!s_adlibAvailable)
		return;

	if (rate == 1)
	{
		int center = limit / 2;
		int distribution = limit;

		SetInstrument(SFX_CH_1, 2);

		u32 tick = SyncToNextTick();

		while (tick + dur / 5 > TIME_GetTickCounter())
		{
			int randFreq = (rand() % distribution) - (distribution / 2) + center;
			KeyOn(SFX_CH_1, randFreq / 2);
		}

		KeyOff(SFX_CH_1);
	}
	else if (rate < 100)
	{
		// waterfall
		if (rate == 0x14 && dur == 0x3c && limit == 10000)
		{
			int center = limit / 32;
			int distribution = limit / 64;

			int randFreq = (rand() % distribution) - (distribution / 2) + center;
			PlayTone(SFX_CH_1, 4, randFreq, dur / 10);

			return;
		}

		// fountain
		if (rate == 10 && dur == 0x1e && limit == 25000)
		{
			int center = limit / 64;
			int distribution = limit / 128;

			int randFreq = (rand() % distribution) - (distribution / 2) + center;
			PlayTone(SFX_CH_1, 4, randFreq, dur / 10);

			return;
		}

		int freq = limit / 50 + 20;

		SetInstrument(SFX_CH_1, 0);
		SetInstrument(SFX_CH_2, 0);
		SetInstrument(SFX_CH_3, 0);
		KeyOn(SFX_CH_1, freq * 2 / 3);
		KeyOn(SFX_CH_2, freq);
		KeyOn(SFX_CH_3, freq + 7);

		// approx
		TIME_SleepMs(dur / 10);

		KeyOff(SFX_CH_1);
		KeyOff(SFX_CH_2);
		KeyOff(SFX_CH_3);
	}
	else
	{
		SetInstrument(SFX_CH_1, 1);

		int tickStep = dur / rate * 3;
		for (int i = 0; i < dur; i += rate)
		{
			int randFreq = (rand() % (limit - 5)) + 5;
			KeyOn(SFX_CH_1, randFreq);

			TIME_SleepMs(tickStep);
		}

		KeyOff(SFX_CH_1);
	}
}

static void AUDIO_ADLIB_PlaySynthTone(int freq, int dur)
{
	if (!s_adlibAvailable)
		return;

	PlayTone(SFX_CH_1, 1, freq, dur * 8 / 10);
}

static void AUDIO_ADLIB_PlaySynthSweepTone(int startFreq, int endFreq, int tickStep, int dur)
{
	int i;
	int freqStep;
	int freq;

	freqStep = (endFreq - startFreq) * tickStep / dur;
	freq = startFreq;

	SetInstrument(SFX_CH_1, 1);

	u32 tick = SyncToNextTick();

	for (i = 0; i < dur; i += tickStep)
	{
		KeyOn(SFX_CH_1, freq);

		TIME_SleepMs(tickStep * 3 / 2);
		freq += freqStep;
	}

	KeyOff(SFX_CH_1);
}

static AudioSfxDriverOps s_sfxOps =
{
    .Initialize = AUDIO_ADLIB_Initialize,
    .Cleanup = AUDIO_ADLIB_Cleanup,
    .PlaySfx = AUDIO_ADLIB_PlaySfx,
    .StopSfx = AUDIO_ADLIB_StopSfx,
    .GetSfxType = AUDIO_ADLIB_GetSfxType,
    .PlaySynthPulse = AUDIO_ADLIB_PlaySynthPulse,
    .PlaySynthNoise = AUDIO_ADLIB_PlaySynthNoise,
    .PlaySynthTone = AUDIO_ADLIB_PlaySynthTone,
    .PlaySynthSweepTone = AUDIO_ADLIB_PlaySynthSweepTone
};

AudioSfxDriverOps* AUDIO_ADLIB_GetSfxOps(void)
{
    return &s_sfxOps;
}
