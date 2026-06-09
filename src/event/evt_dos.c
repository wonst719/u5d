#include "event.h"
#include "graphics/grap.h"

void EVT_Initialize(void)
{
}

void EVT_Cleanup(void)
{
}

void EVT_PollMessages(void)
{
}

void KEY_PollMessages(void);

void EVT_Yield(void)
{
    GRAP_FlushPendingPresent();
}
