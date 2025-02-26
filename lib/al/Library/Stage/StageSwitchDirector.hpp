#pragma once

#include <seadTypes.h>
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

        StageSwitchInfo** mSwitchInfos;  // 0x8
        int _10;
        int _14;
        StageSwitchWatcherHolder* mWatcherHolder;    // 0x18
        StageSwitchListenerHolder* mListenerHolder;  // 0x20
        CameraDirector_RS* mCameraDirector;          // 0x28
    };
};  // namespace al