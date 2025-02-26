#pragma once

#include <seadTypes.h>

namespace al {
    class StageSwitchWatcher;

    class StageSwitchWatcherHolder {
    public:
        StageSwitchWatcherHolder(s32);

        void add(StageSwitchWatcher*);
        void movement();

        StageSwitchWatcher** mWatchers;  // 0x00
        s32 mNumHolders;                 // 0x08
        s32 mMaxHolders;                 // 0x0C
    };
};  // namespace al