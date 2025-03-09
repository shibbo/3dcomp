#include "Library/StageSwitch/StageSwitchWatcher.hpp"

#include "Library/StageSwitch/Core/StageSwitchDirector.hpp"
#include "Library/StageSwitch/StageSwitchAccesser.hpp"
#include "Library/StageSwitch/StageSwitchFunctorListener.hpp"
#include "Project/Camera/Main/CameraDirector_RS.hpp"

namespace al {
StageSwitchWatcher::StageSwitchWatcher(StageSwitchListener* pListener,
                                       StageSwitchAccesser* pAccessor) {
    mListener = pListener;
    mAccesser = pAccessor;
    _18 = false;
    mCameraDirector = pAccessor->mStageSwitchDirector->mCameraDirector;
}

void StageSwitchWatcher::update() {
    if (!mAccesser->mIsDisasterMode || mCameraDirector->_102) {
        bool isOn = mAccesser->isOnSwitch();

        if (isOn != _18) {
            if (isOn)
                mListener->listenOn();
            else
                mListener->listenOff();
        }

        _18 = isOn;
    }
}
}  // namespace al
