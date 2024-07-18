#pragma once

#include <types.hpp>

namespace al {
    class LiveActor;
    class ScreenPointTarget;

    class ScreenPointKeeper {
    public:
        ScreenPointKeeper(s32);

        void validate();
        void invalidate();
        void validateBySystem();
        void invalidateBySystem();

        s32 mMaxNumTargets;                 // 0x00
        s32 mCurNumTargets;                 // 0x04
        ScreenPointTarget** mTargets;       // 0x08
    };
};