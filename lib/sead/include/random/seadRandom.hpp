#pragma once

#include <types.hpp>

namespace sead {
    class Random {
    public:
        Random() { init(); }

        void init();
        void init(u32);
        void init(u32, u32, u32, u32);
        u32 getU32();
        u64 getU64();
        void getContext(u32*, u32*, u32*, u32*) const;

        u32 mX;
        u32 mY;
        u32 mZ;
        u32 mW;
    };
};  // namespace sead