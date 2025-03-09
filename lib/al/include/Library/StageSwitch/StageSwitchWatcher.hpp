#pragma once

#include <basis/seadTypes.h>

namespace al {
class StageSwitchListener;
class StageSwitchAccesser;
class CameraDirector_RS;

class StageSwitchWatcher {
public:
    StageSwitchWatcher(StageSwitchListener*, StageSwitchAccesser*);

    void update();

    StageSwitchListener* mListener;
    StageSwitchAccesser* mAccesser;
    CameraDirector_RS* mCameraDirector;
    bool _18 = false;
};
}  // namespace al
