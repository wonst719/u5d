#include "common/common.h"
#include "common/debug.h"

#include "event/event.h"

#include <errno.h>
#include <dpmi.h>

#include <time.h>

static bool s_hasDpmiYield;

static uclock_t s_beginTicks;

void TIME_Initialize(void)
{
    errno = 0;
    __dpmi_yield();
    s_hasDpmiYield = errno != ENOSYS;
    errno = 0;

    s_beginTicks = uclock();
}

void TIME_Cleanup(void)
{
    uclock_t elapsedTicks = uclock() - s_beginTicks;

    debug("%lld tick have elapsed", (long long)elapsedTicks);
    debug("%f second have elapsed", (double)elapsedTicks / UCLOCKS_PER_SEC);
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
    return (u32)(uclock() * 1000 / UCLOCKS_PER_SEC);
}

void TIME_SleepMs(int ms)
{
    uclock_t sleepTicks = (uclock_t)ms * UCLOCKS_PER_SEC / 1000;
    uclock_t expireTicks = uclock() + sleepTicks;

    EVT_Yield();
    while (expireTicks > uclock())
    {
        EVT_Yield();
        TIME_DpmiYield();
    }
}

u32 TIME_CurrentFrame(void)
{
    // 62.5 hz
    return TIME_GetTicksMs() / 16;
}
