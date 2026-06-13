#include "common/common.h"
#include "pctimer.h"

#include "event/event.h"

#include <errno.h>
#include <dpmi.h>

// 10 * 18.2 hz
#define PIT_FREQ 182

static bool s_hasDpmiYield;

void TIME_Initialize(void)
{
    pctimer_init(PIT_FREQ);

    errno = 0;
    __dpmi_yield();
    s_hasDpmiYield = errno != ENOSYS;
    errno = 0;
}

void TIME_Cleanup(void)
{
    pctimer_exit();
}

void TIME_DpmiYield(void)
{
    if (s_hasDpmiYield)
    {
        __dpmi_yield();
    }
}

u32 TIME_GetTicksMs(void)
{
    return pctimer_time(0, pctimer_get_ticks());
}

void TIME_SleepMs(int ms)
{
    u32 sleepTicks = ms * PIT_FREQ / 1000;
    u32 expireTicks = pctimer_get_ticks() + sleepTicks;

    EVT_Yield();
    while (expireTicks > pctimer_get_ticks())
    {
        EVT_Yield();
        TIME_DpmiYield();
    }
}

u32 TIME_CurrentFrame(void)
{
    // 60.6666... hz
    return pctimer_get_ticks() / 3;
}
