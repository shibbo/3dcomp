#pragma once

#include <basis/seadTypes.h>

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

    void update();

    s32 mMaxNumTargets;
    s32 mCurNumTargets;
    ScreenPointTarget** mTargets;
};
}  // namespace al
