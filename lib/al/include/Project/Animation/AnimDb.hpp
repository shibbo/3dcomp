#pragma once

#include <basis/seadTypes.h>

namespace al {
class AnimResInfo {
public:
    AnimResInfo();

    s32 getFrameMax() const;
    bool isLoop() const;

    const char* mName = nullptr;
    void* mRes = nullptr;
    f32 mFrameMax = 0;
    bool mIsLoop = false;
};

class AnimInfoTable {
public:
    AnimInfoTable(s32);

    u32 mInfoCount = 0;
    AnimResInfo* mResInfArr = nullptr;
    bool mIsSorted = false;
};
}  // namespace al
