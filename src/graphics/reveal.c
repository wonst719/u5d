#include "common/common.h"
#include "reveal.h"

// T1K.DRV 19e1
static u16 s_lfsrMasks[] =
{
    3,     6,     0xc,   0x14,   0x30,   0x60,   0xb8,  0x110,
    0x240, 0x500, 0xca0, 0x1b00, 0x3500, 0x6000, 0xb400
};

static u16 GetRevealLfsrMask(int bits)
{
    ASSERT(bits >= 2 && bits <= 16);

    return s_lfsrMasks[bits - 2];
}

void RevealInit(RevealState* state, int width, int height, u16 seed)
{
    ASSERT(state);
    ASSERT(width > 0 && height > 0);
    ASSERT(seed);

    u16 total;

    u8 bits = 2;
    u16 maxState = 3;

    total = width * height;

    while (maxState < total)
    {
        bits++;
        maxState = (1 << bits) - 1;
    }

    state->maxState = maxState;
    state->mask = GetRevealLfsrMask(bits);
    ASSERT(state->mask);

    seed %= maxState;
    ASSERT(seed);

    state->state = seed;

    state->total = total;
    state->produced = 0;
}

static u16 RevealStep(u16 state, u16 mask)
{
    int lsb = state & 1;
    state >>= 1;
    if (lsb)
        state ^= mask;
    return state;
}

bool RevealNextIndex(RevealState* state, int* outIndex)
{
    int guard;
    int idx;

    ASSERT(state);
    ASSERT(outIndex);

    if (state->produced >= state->total)
        return 0;

    guard = 0;

    for (;;)
    {
        idx = state->state - 1;
        state->state = RevealStep(state->state, state->mask);

        if (idx < state->total)
        {
            *outIndex = idx;
            state->produced++;
            return 1;
        }

        if (++guard > state->maxState)
            return 0;
    }
}
