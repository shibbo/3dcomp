#include "Project/Animation/AnimDb.hpp"

namespace al {
AnimResInfo::AnimResInfo() {}

s32 AnimResInfo::getFrameMax() const {
    return mFrameMax;
}

bool AnimResInfo::isLoop() const {
    return mIsLoop;
}

AnimInfoTable::AnimInfoTable(s32 maxInfos) {
    mResInfArr = new AnimResInfo[maxInfos];
}
}  // namespace al
