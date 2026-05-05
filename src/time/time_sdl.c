#include <SDL3/SDL_timer.h>

#include "common/common.h"

#include "event/event.h"

void TIME_Initialize(void)
{}

void TIME_Cleanup(void)
{}

void TIME_SleepMs(int ms)
{
	u32 ticks = SDL_GetTicks() + (u32)ms;

	while (ticks > SDL_GetTicks())
	{
		EVT_Yield();
		SDL_Delay(ms);
	}
}

u32 TIME_CurrentFrame(void)
{
	// 62.5 hz
	return SDL_GetTicks() / 16;
}
