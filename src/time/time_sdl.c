#include <SDL3/SDL_timer.h>

#include "common/common.h"

#include "event/event.h"

void TIME_Initialize(void)
{}

void TIME_Cleanup(void)
{}

extern u32 TIME_GetTickFrequency(void)
{
	return 1000;
}

extern u32 TIME_GetTickCounter(void)
{
	return (u32)SDL_GetTicks();
}

u32 TIME_GetTicksMs(void)
{
	return (u32)SDL_GetTicks();
}

void TIME_SleepMs(int ms)
{
	u32 ticks = (u32)SDL_GetTicks() + (u32)ms;

	EVT_Yield();
	while (ticks > SDL_GetTicks())
	{
		EVT_Yield();
		SDL_Delay(1);
	}
}

u32 TIME_CurrentFrame(void)
{
	// 62.5 hz
	return SDL_GetTicks() / 16;
}
