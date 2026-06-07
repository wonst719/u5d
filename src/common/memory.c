#include "common.h"
#include "memory.h"

u32 MEM_ReadU32LE(const byte* p)
{
    return (u32)p[0] | ((u32)p[1] << 8) | ((u32)p[2] << 16) | ((u32)p[3] << 24);
}

u16 MEM_ReadU16LE(const byte* p)
{
    return (u16)p[0] | ((u16)p[1] << 8);
}

u8 MEM_ReadU8(const byte* p)
{
    return p[0];
}

void MEM_WriteU16LE(byte* p, u16 v)
{
    p[0] = (u8)v;
    p[1] = (u8)(v >> 8);
}

u16 MEM_Ror16(u16 v, int count)
{
    count &= 15;
    if (count == 0)
        return v;

    return (u16)((v >> count) | (v << (16 - count)));
}
