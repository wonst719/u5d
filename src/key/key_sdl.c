#include "common/common.h"

#include "vars.h"

#include <SDL3/SDL.h>

#define KBD_HOME   0x47
#define KBD_UP     0x48
#define KBD_PGUP   0x49
#define KBD_LEFT   0x4B
#define KBD_RIGHT  0x4D
#define KBD_END    0x4f
#define KBD_DOWN   0x50
#define KBD_PGDN   0x51

void KEY_Initialize(void)
{}

void KEY_Cleanup(void)
{}

static u16 s_lastDownKeycode = 0;

static u16 KeyboardEventToUltimaKeycode(SDL_KeyboardEvent ev)
{
    if (ev.mod & SDL_KMOD_CTRL)
    {
        switch (ev.key)
        {
        case SDLK_B: return 2;
        case SDLK_E: return 5;
        case SDLK_K: return 0xb;
        case SDLK_M: return 0xd; // same as CR
        case SDLK_S: return 0x13;
        case SDLK_V: return 0x16;
        }

        if (!(ev.key & SDLK_SCANCODE_MASK))
            return 0x1a; // return not used keycode
    }

    if (!(ev.key & SDLK_SCANCODE_MASK))
    {
        // ascii/unicode keypoint

        bool shift = (ev.mod & SDL_KMOD_SHIFT) != 0;
        bool caps = (ev.mod & SDL_KMOD_CAPS) != 0;

        if (shift ^ caps)
        {
            // TODO: symbols
            return SDL_toupper(ev.key);
        }

        return ev.key;
    }

    u8 extendedKeycode;
    switch (ev.key)
    {
    case SDLK_HOME: extendedKeycode = KBD_HOME; break;
    case SDLK_UP: extendedKeycode = KBD_UP; break;
    case SDLK_PAGEUP: extendedKeycode = KBD_PGUP; break;
    case SDLK_LEFT: extendedKeycode = KBD_LEFT; break;
    case SDLK_RIGHT: extendedKeycode = KBD_RIGHT; break;
    case SDLK_END: extendedKeycode = KBD_END; break;
    case SDLK_DOWN: extendedKeycode = KBD_DOWN; break;
    case SDLK_PAGEDOWN: extendedKeycode = KBD_PGDN; break;
    default:
        return 0;
    }

    // based on ULTIMA_1d5e

    if (extendedKeycode <= 0x44)
    {
        // F1..F10 -> c9..d2
        return extendedKeycode + 0x8e;
    }

    // Arrow keys
    // l, r, d, u, home, end, pgup, pgdn -> 1, 2, 3, 4, d3, d4, d5, d6
    int i;
    for (i = 0; i < 8; i++)
    {
        if (extendedKeycode == D_540e[i])
            break;
    }

    if (i == 8)
    {
        return 0;
    }

    u16 key = D_5416[i];
    key |= 0x100; // special keystroke
    return key;
}

void KEY_SDL_ProcessKeyDown(SDL_KeyboardEvent ev)
{
    s_lastDownKeycode = KeyboardEventToUltimaKeycode(ev);
}

extern void EVT_Yield(void);

int KEY_PollKey(void)
{
	int ret;

	D_538a = 0;

	EVT_Yield();

    // special keystroke
    if (s_lastDownKeycode & 0x100)
    {
        s_lastDownKeycode &= 0xff;
        D_538a = 1;
    }

    ret = s_lastDownKeycode;
    s_lastDownKeycode = 0;

	return ret;
}
