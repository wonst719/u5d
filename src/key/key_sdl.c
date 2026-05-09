#include "common/common.h"

#include "vars.h"

#include <SDL3/SDL.h>

// from u4
#define KBD_ESC    0x011b
#define KBD_BS     0x0e08
#define KBD_0e7f   0x0e7f
#define KBD_SPACE  0x3920
#define KBD_ENTER  0x1c0d

#define KBD_HOME   0x4700
#define KBD_UP     0x4800
#define KBD_UP_    0x487e
#define KBD_PGUP   0x4900
#define KBD_LEFT   0x4B00
#define KBD_LEFT_  0x4b7c
#define KBD_RIGHT  0x4D00
#define KBD_RIGHT_ 0xf400
#define KBD_END    0x4f00
#define KBD_DOWN   0x5000
#define KBD_DOWN_  0x5060
#define KBD_PGDN   0x5100

#define KBD_1 0x0231
#define KBD_2 0x0332
#define KBD_3 0x0433
#define KBD_4 0x0534
#define KBD_5 0x0635
#define KBD_6 0x0736
#define KBD_7 0x0837
#define KBD_8 0x0938
#define KBD_9 0x0a39
#define KBD_0 0x0b30

#define KBD_A 0x1E61
#define KBD_B 0x3062
#define KBD_C 0x2E63
#define KBD_D 0x2064
#define KBD_E 0x1265
#define KBD_F 0x2166
#define KBD_G 0x2267
#define KBD_H 0x2368
#define KBD_I 0x1769
#define KBD_J 0x246A
#define KBD_K 0x256B
#define KBD_L 0x266C
#define KBD_M 0x326D
#define KBD_N 0x316E
#define KBD_O 0x186F
#define KBD_P 0x1970
#define KBD_Q 0x1071
#define KBD_R 0x1372
#define KBD_S 0x1F73
#define KBD_T 0x1474
#define KBD_U 0x1675
#define KBD_V 0x2F76
#define KBD_W 0x1177
#define KBD_X 0x2D78
#define KBD_Y 0x1579
#define KBD_Z 0x2c7a

#define KBD_CTRL_S 0x1f13
#define KBD_ALT_Z  0x2c00
#define KBD_ALT_X  0x2d00

void KEY_Initialize(void)
{}

void KEY_Cleanup(void)
{}

static int s_lastDownKeyScancode = 0;

void KEY_SDL_ProcessKeyDownScancode(SDL_Scancode scancode)
{
	switch (scancode)
	{
	case SDL_SCANCODE_LEFT: s_lastDownKeyScancode = KBD_LEFT; break;
	case SDL_SCANCODE_RIGHT: s_lastDownKeyScancode = KBD_RIGHT; break;
	case SDL_SCANCODE_UP: s_lastDownKeyScancode = KBD_UP; break;
	case SDL_SCANCODE_DOWN: s_lastDownKeyScancode = KBD_DOWN; break;

	case SDL_SCANCODE_RETURN: s_lastDownKeyScancode = KBD_ENTER; break;
	case SDL_SCANCODE_ESCAPE: s_lastDownKeyScancode = KBD_ESC; break;
	case SDL_SCANCODE_SPACE: s_lastDownKeyScancode = KBD_SPACE; break;
	case SDL_SCANCODE_BACKSPACE: s_lastDownKeyScancode = KBD_BS; break;

	case SDL_SCANCODE_A: s_lastDownKeyScancode = KBD_A; break;
	case SDL_SCANCODE_B: s_lastDownKeyScancode = KBD_B; break;
	case SDL_SCANCODE_C: s_lastDownKeyScancode = KBD_C; break;
	case SDL_SCANCODE_D: s_lastDownKeyScancode = KBD_D; break;
	case SDL_SCANCODE_E: s_lastDownKeyScancode = KBD_E; break;
	case SDL_SCANCODE_F: s_lastDownKeyScancode = KBD_F; break;
	case SDL_SCANCODE_G: s_lastDownKeyScancode = KBD_G; break;
	case SDL_SCANCODE_H: s_lastDownKeyScancode = KBD_H; break;
	case SDL_SCANCODE_I: s_lastDownKeyScancode = KBD_I; break;
	case SDL_SCANCODE_J: s_lastDownKeyScancode = KBD_J; break;
	case SDL_SCANCODE_K: s_lastDownKeyScancode = KBD_K; break;
	case SDL_SCANCODE_L: s_lastDownKeyScancode = KBD_L; break;
	case SDL_SCANCODE_M: s_lastDownKeyScancode = KBD_M; break;
	case SDL_SCANCODE_N: s_lastDownKeyScancode = KBD_N; break;
	case SDL_SCANCODE_O: s_lastDownKeyScancode = KBD_O; break;
	case SDL_SCANCODE_P: s_lastDownKeyScancode = KBD_P; break;
	case SDL_SCANCODE_Q: s_lastDownKeyScancode = KBD_Q; break;
	case SDL_SCANCODE_R: s_lastDownKeyScancode = KBD_R; break;
	case SDL_SCANCODE_S: s_lastDownKeyScancode = KBD_S; break;
	case SDL_SCANCODE_T: s_lastDownKeyScancode = KBD_T; break;
	case SDL_SCANCODE_U: s_lastDownKeyScancode = KBD_U; break;
	case SDL_SCANCODE_V: s_lastDownKeyScancode = KBD_V; break;
	case SDL_SCANCODE_W: s_lastDownKeyScancode = KBD_W; break;
	case SDL_SCANCODE_X: s_lastDownKeyScancode = KBD_X; break;
	case SDL_SCANCODE_Y: s_lastDownKeyScancode = KBD_Y; break;
	case SDL_SCANCODE_Z: s_lastDownKeyScancode = KBD_Z; break;

	case SDL_SCANCODE_0: s_lastDownKeyScancode = KBD_0; break;
	case SDL_SCANCODE_1: s_lastDownKeyScancode = KBD_1; break;
	case SDL_SCANCODE_2: s_lastDownKeyScancode = KBD_2; break;
	case SDL_SCANCODE_3: s_lastDownKeyScancode = KBD_3; break;
	case SDL_SCANCODE_4: s_lastDownKeyScancode = KBD_4; break;
	case SDL_SCANCODE_5: s_lastDownKeyScancode = KBD_5; break;
	case SDL_SCANCODE_6: s_lastDownKeyScancode = KBD_6; break;
	case SDL_SCANCODE_7: s_lastDownKeyScancode = KBD_7; break;
	case SDL_SCANCODE_8: s_lastDownKeyScancode = KBD_8; break;
	case SDL_SCANCODE_9: s_lastDownKeyScancode = KBD_9; break;
	}
}

extern void EVT_Yield(void);

int KEY_PollKey(void)
{
	int ret;

	D_538a = 0;

	EVT_Yield();

	ret = s_lastDownKeyScancode;
	s_lastDownKeyScancode = 0;

	if (ret == KBD_LEFT)
	{
		D_538a = 1;
		ret = 1;
	}

	if (ret == KBD_UP)
	{
		D_538a = 1;
		ret = 3;
	}

	if (ret == KBD_RIGHT)
	{
		D_538a = 1;
		ret = 2;
	}

	if (ret == KBD_DOWN)
	{
		D_538a = 1;
		ret = 4;
	}

	// Ctrl+E: 0x5?
	// Ctrl+S: 0x13?
	// Ctrl+V: 0x16?
	// ?: 0xb?

	return ret;
}
