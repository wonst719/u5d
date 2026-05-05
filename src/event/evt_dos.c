#include "event.h"

void EVT_Initialize(void)
{
}

void EVT_Cleanup(void)
{
}

void EVT_PollMessages(void)
{
}

// TODO
void GRAP_FlushPrevPresentReq(void);
void KEY_PollMessages(void);

void EVT_Yield(void)
{
    GRAP_FlushPrevPresentReq();
}
