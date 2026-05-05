#include "common/common.h"
#include "pctimer.h"

#include <stdlib.h>

// TODO
void GRAP_FlushPrevPresentReq(void);
void KEY_PollMessages(void);

void EVT_Yield(void)
{
    GRAP_FlushPrevPresentReq();
    KEY_PollMessages();
}

void TIME_Initialize(void)
{
    pctimer_init(182); // 10 * 18.2 hz
    atexit(pctimer_exit);
}

void TIME_Cleanup(void)
{}

void TIME_Sleep(int ms)
{
    EVT_Yield();

    pctimer_sleep(ms);
}

u32 TIME_CurrentFrame(void)
{
    // 60.6666... hz
    return pctimer_get_ticks() / 3;
}
