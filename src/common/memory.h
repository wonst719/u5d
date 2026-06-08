#ifndef _COMMON_MEMORY_H
#define _COMMON_MEMORY_H

u32 MEM_ReadU32LE(const byte* p);
u16 MEM_ReadU16LE(const byte* p);
u8 MEM_ReadU8(const byte* p);

void MEM_WriteU16LE(byte* p, u16 v);

u16 MEM_Ror16(u16 v, int count);

#define MEM_ReadU32LEOffset(p, off) MEM_ReadU32LE(&(p)[off])
#define MEM_ReadU16LEOffset(p, off) MEM_ReadU16LE(&(p)[off])
#define MEM_ReadU8Offset(p, off) MEM_ReadU8(&(p)[off])

#endif
