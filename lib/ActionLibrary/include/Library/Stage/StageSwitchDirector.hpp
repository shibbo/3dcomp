#pragma once

#include "Library/Execute/IUseExecutor.hpp"

namespace al {
    class StageSwitchListenerHolder;
    class StageSwitchWatcherHolder;
    class StageSwitchInfo;
    class CameraDirector_RS;

    class StageSwitchDirector : public IUseExecutor {
    public:
        virtual void execute();

        StageSwitchInfo** mSwitchInfos;  // 0x8
        int _10;
        int _14;
        StageSwitchWatcherHolder* mWatcherHolder;    // 0x18
        StageSwitchListenerHolder* mListenerHolder;  // 0x20
        CameraDirector_RS* mCameraDirector;          // 0x28
    };
};  // namespace al