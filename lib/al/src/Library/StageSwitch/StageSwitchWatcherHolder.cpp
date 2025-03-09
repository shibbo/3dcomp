#include "Library/StageSwitch/StageSwitchWatcherHolder.hpp"

#include "Library/StageSwitch/StageSwitchWatcher.hpp"

namespace al {
StageSwitchWatcherHolder::StageSwitchWatcherHolder(s32 maxHolders) {
    mNumHolders = 0;
    mMaxHolders = maxHolders;
    mWatchers = new StageSwitchWatcher*[maxHolders];
}

void StageSwitchWatcherHolder::add(StageSwitchWatcher* pWatcher) {
    mWatchers[mNumHolders] = pWatcher;
    mNumHolders++;
}

void StageSwitchWatcherHolder::movement() {
    for (s32 i = 0; i < mNumHolders; i++)
        mWatchers[i]->update();
}
}  // namespace al
