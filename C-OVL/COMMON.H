#ifndef _COMMON_H
#define _COMMON_H

typedef unsigned char u8;
typedef unsigned int u16;
typedef signed char s8;
typedef signed int s16;

typedef char i8;
typedef int i16;

typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned int uint;
typedef int bool;

typedef byte undefined;
typedef byte undefined1;
typedef int undefined2;

#if _WIN32
#define far
#endif

#endif
