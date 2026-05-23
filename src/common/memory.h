#ifndef _MEMORY_H
#define _MEMORY_H

u32 MEM_ReadU32LE(byte* p);
u16 MEM_ReadU16LE(byte* p);
u8 MEM_ReadU8(byte* p);

#define MEM_ReadU32LEOffset(p, off) MEM_ReadU32LE(&(p)[off])
#define MEM_ReadU16LEOffset(p, off) MEM_ReadU16LE(&(p)[off])
#define MEM_ReadU8Offset(p, off) MEM_ReadU8(&(p)[off])

#endif
