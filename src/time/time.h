#ifndef _TIME_TIME_H
#define _TIME_TIME_H

extern void TIME_Initialize(void);
extern void TIME_Cleanup(void);

extern u32 TIME_GetTicksMs(void);
extern void TIME_SleepMs(int ms);

#endif
