#include "common.h"
#include "memory.h"

u32 MEM_ReadU32LE(byte* p)
{
    return (u32)p[0] | ((u32)p[1] << 8) | ((u32)p[2] << 16) | ((u32)p[3] << 24);
}

u16 MEM_ReadU16LE(byte* p)
{
    return (u16)p[0] | ((u16)p[1] << 8);
}

u8 MEM_ReadU8(byte* p)
{
    return p[0];
}
