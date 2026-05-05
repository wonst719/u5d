#ifndef _GRAPHICS_REVEAL_H
#define _GRAPHICS_REVEAL_H

typedef struct RevealState
{
    u16 state;
    u16 maxState;
    u16 mask;

    int total;
    int produced;
} RevealState;

extern void RevealInit(RevealState* state, int width, int height, u16 seed);
extern bool RevealNextIndex(RevealState* state, int* outIndex);

#endif
