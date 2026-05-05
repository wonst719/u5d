#include "common/common.h"
#include "pctimer.h"

#include "event/event.h"

void TIME_Initialize(void)
{
    pctimer_init(182); // 10 * 18.2 hz
}

void TIME_Cleanup(void)
{
    pctimer_exit();
}

void TIME_SleepMs(int ms)
{
    EVT_Yield();

    pctimer_sleep(ms);
}

u32 TIME_CurrentFrame(void)
{
    // 60.6666... hz
    return pctimer_get_ticks() / 3;
}
