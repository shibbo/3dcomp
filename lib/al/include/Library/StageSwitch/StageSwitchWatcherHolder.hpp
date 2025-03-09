#pragma once

#include <basis/seadTypes.h>

namespace al {
class StageSwitchWatcher;

class StageSwitchWatcherHolder {
public:
    StageSwitchWatcherHolder(s32);

    void add(StageSwitchWatcher*);
    void movement();

    StageSwitchWatcher** mWatchers;
    s32 mNumHolders;
    s32 mMaxHolders;
};
}  // namespace al
