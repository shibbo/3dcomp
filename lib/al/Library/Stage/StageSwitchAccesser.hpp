#pragma once

#include <seadTypes.h>
#include "Library/Placement/PlacementId.hpp"
#include "Library/Placement/PlacementInfo.hpp"

namespace al {
    class StageSwitchDirector;
    class StageSwitchListener;

    class StageSwitchAccesser {
    public:
        StageSwitchAccesser();

        bool init(StageSwitchDirector*, const char*, const PlacementId&, bool);
        bool isValid() const;
        void onSwitch();
        void offSwitch();
        bool isOnSwitch() const;
        StageSwitchDirector* getStageSwitchDirector() const;
        bool isEnableRead() const;
        bool isEnableWrite() const;
        bool isEqualSwitch(const StageSwitchAccesser*) const;
        void doInstanceResponse();
        void addListener(StageSwitchListener*);

        inline void setThing(void* ptr) { _8 = ptr; }

        StageSwitchDirector* mStageSwitchDirector = nullptr;  // 0x00
        void* _8 = nullptr;
        const char* mName = "";               // 0x10
        PlacementId* mPlacementId = nullptr;  // 0x18
        s32 mSwitchNo = -1;                   // 0x20
        u32 _24 = 0;
        bool mIsDisasterMode;  // 0x28
    };

    class StageSwitchAccesserList {
    public:
        StageSwitchAccesserList();
        StageSwitchAccesserList(const StageSwitchAccesser*);

        const StageSwitchAccesser* mAccesser = nullptr;  // 0x00
        u64 _8 = 0;
    };
};  // namespace al