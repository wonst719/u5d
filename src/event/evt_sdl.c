#include <SDL3/SDL.h>

#include "event.h"

void EVT_Initialize(void)
{
}

void EVT_Cleanup(void)
{
}

// TODO
void KEY_SDL_ProcessKeyDownScancode(SDL_Scancode scancode);

void EVT_PollMessages(void)
{
	SDL_Event ev;
	while (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
		case SDL_EVENT_QUIT:
			exit(0);
			break;

		case SDL_EVENT_KEY_DOWN:
			KEY_SDL_ProcessKeyDownScancode(ev.key.scancode);
			break;
		}
	}
}

// TODO
void GRAP_FlushPrevPresentReq(void);

void EVT_Yield(void)
{
	GRAP_FlushPrevPresentReq();
	EVT_PollMessages();
}
