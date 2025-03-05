#pragma once

#include <basis/seadTypes.h>

namespace al {
    class AnimResInfo {
    public:
        AnimResInfo();

        s32 getFrameMax() const;
        bool isLoop() const;

        const char* mName = nullptr;  // 0x00
        void* mRes = nullptr;         // 0x08
        f32 mFrameMax = 0;            // 0x10
        bool mIsLoop = false;         // 0x14
    };

    class AnimInfoTable {
    public:
        AnimInfoTable(s32);

        u32 mInfoCount = 0;                 // 0x00
        AnimResInfo* mResInfArr = nullptr;  // 0x08
        bool mIsSorted = false;             // 0x10
    };
};  // namespace al