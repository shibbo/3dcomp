#pragma once

#include <basis/seadTypes.h>

namespace al {
class StageSwitchAccesser;
class StageSwitchDirector;
struct PlacementInfo;

class StageSwitchKeeper {
public:
    StageSwitchKeeper();

    void init(StageSwitchDirector*, const PlacementInfo&);
    StageSwitchAccesser* tryGetStageSwitchAccesser(const char*) const;
    bool isUsingSwitchNo(s32);

    StageSwitchAccesser* mAccessors = nullptr;
    s32 mLinkCount = 0;
    u32 _c;
    void* _10 = nullptr;
};
}  // namespace al
