#pragma once

#include <types.hpp>
#include "Library/Placement/PlacementId.hpp"
#include "Library/Placement/PlacementInfo.hpp"

namespace al {
    class StageSwitchDirector;

    class StageSwitchAccesser {
    public:
        StageSwitchAccesser();

        void init(StageSwitchDirector*, const char*, const PlacementId&, bool);

        bool isOnSwitch() const;

        inline void setThing(void* ptr) { _8 = ptr; }

        StageSwitchDirector* mStageSwitchDirector;  // 0x00
        void* _8;
        const char* mName;  // 0x10
        u64 _18;
        s32 _20;
        s32 _24;
        bool _28;
    };
};  // namespace al