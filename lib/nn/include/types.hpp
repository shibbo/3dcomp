#pragma once

#include <cstdint>

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long u64;
typedef signed long s64;
typedef float f32;
typedef double f64;

// this is to get vscode to shut up about certain definitions
#ifdef __INTELLISENSE__
#define NN_ALIGNAS(alignment)
#else
#define NN_ALIGNAS(alignment) __attribute__((aligned(alignment)))
#endif

#ifdef __INTELLISENSE__
#define NN_FORCEINLINE
#else
#define NN_FORCEINLINE __attribute__((always_inline)) inline
#endif