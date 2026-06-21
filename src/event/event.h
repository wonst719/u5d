#ifndef _EVENT_EVENT_H
#define _EVENT_EVENT_H

typedef void EVT_Callback(void);

extern void EVT_Initialize(void);
extern void EVT_Cleanup(void);
extern void EVT_Yield(void);
extern void EVT_RegisterCallback(EVT_Callback* callback);

#endif
