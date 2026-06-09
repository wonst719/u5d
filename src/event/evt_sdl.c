#include "common/common.h"
#include "graphics/grap.h"

#include "event.h"

#include <SDL3/SDL.h>

void EVT_Initialize(void)
{
}

void EVT_Cleanup(void)
{
}

// TODO
void KEY_SDL_ProcessKeyDown(SDL_KeyboardEvent ev);

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
			KEY_SDL_ProcessKeyDown(ev.key);
			break;
		}
	}
}

void EVT_Yield(void)
{
	GRAP_FlushPendingPresent();
	EVT_PollMessages();
}
