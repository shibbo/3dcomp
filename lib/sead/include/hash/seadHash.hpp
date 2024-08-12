#pragma once

#include <types.hpp>

namespace sead {
    class HashCRC16 {
    public:
        struct Context {
            u32 mHash = 0;
        };

        static void initialize();
        static u32 calcHash(const void*, u32);
        static u32 calcHashWithContext(Context*, const void*, u32);
        static u32 calcStringHash(const char*);
        static u32 calcStringHashWithContext(Context*, const char*);

        static u16 sTable[256];
        static bool sInitialized;
    };

    class HashCRC32 {
    public:
        struct Context {
            u32 mHash = -1;
        };

        static void initialize();
        static u32 calcHash(const void*, u32);
        static u32 calcHashWithContext(Context*, const void*, u32);
        static u32 calcStringHash(const char*);
        static u32 calcStringHashWithContext(Context*, const char*);

        static u32 sTable[256];
        static bool sInitialized;
    };
};  // namespace sead