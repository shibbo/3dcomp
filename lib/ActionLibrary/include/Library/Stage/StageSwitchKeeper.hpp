#pragma once

#include <types.hpp>
#include "Library/Placement/PlacementInfo.hpp"

namespace al {
    class StageSwitchAccesser;
    class StageSwitchDirector;

    class StageSwitchKeeper {
    public:
        StageSwitchKeeper();

        void init(StageSwitchDirector*, const PlacementInfo&);
        StageSwitchAccesser* tryGetStageSwitchAccesser(const char*) const;
        bool isUsingSwitchNo(s32);

        StageSwitchAccesser* mAccessors = nullptr;  // 0x00
        s32 mLinkCount = 0;                         // 0x8
        u32 _C;
        void* _10 = nullptr;
    };
};  // namespace al