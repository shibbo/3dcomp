#pragma once

#include <basis/seadTypes.h>

#include "Library/Execute/IUseExecutor.hpp"

namespace al {
class StageSwitchListener;
class StageSwitchListenerHolder;
class StageSwitchWatcherHolder;
class StageSwitchInfo;
class CameraDirector_RS;
class StageSwitchAccesser;

class StageSwitchDirector : public IUseExecutor {
public:
    virtual void execute();

    s32 useSwitch(const StageSwitchAccesser*);

    void onSwitch(const StageSwitchAccesser*);
    void offSwitch(const StageSwitchAccesser*);
    bool isOnSwitch(const StageSwitchAccesser*) const;
    void instantUpdate(StageSwitchAccesser*);
    void addListener(StageSwitchListener*, StageSwitchAccesser*);

    StageSwitchInfo** mSwitchInfos;
    s32 _10;
    s32 _14;
    StageSwitchWatcherHolder* mWatcherHolder;
    StageSwitchListenerHolder* mListenerHolder;
    CameraDirector_RS* mCameraDirector;
};
}  // namespace al
