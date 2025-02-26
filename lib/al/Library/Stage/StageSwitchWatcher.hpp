#pragma once

#include <seadTypes.h>

namespace al {
    class StageSwitchListener;
    class StageSwitchAccesser;
    class CameraDirector_RS;

    class StageSwitchWatcher {
    public:
        StageSwitchWatcher(StageSwitchListener*, StageSwitchAccesser*);

        void update();

        StageSwitchListener* mListener;      // 0x00
        StageSwitchAccesser* mAccesser;      // 0x08
        CameraDirector_RS* mCameraDirector;  // 0x10
        bool _18 = false;
    };

};  // namespace al