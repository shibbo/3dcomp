#include "Library/Stage/StageSwitchWatcher.hpp"
#include "Library/Stage/StageSwitchAccesser.hpp"
#include "Library/Stage/StageSwitchDirector.hpp"
#include "Library/Stage/StageSwitchListener.hpp"
#include "Project/Camera/CameraDirector_RS.hpp"

namespace al {
    StageSwitchWatcher::StageSwitchWatcher(StageSwitchListener* pListener,
                                           StageSwitchAccesser* pAccessor) {
        mListener = pListener;
        mAccesser = pAccessor;
        _18 = false;
        mCameraDirector = pAccessor->mStageSwitchDirector->mCameraDirector;
    }

    void StageSwitchWatcher::update() {
        if (!mAccesser->_28 || mCameraDirector->_102) {
            bool isOn = mAccesser->isOnSwitch();

            if (isOn != _18) {
                if (isOn) {
                    mListener->listenOn();
                } else {
                    mListener->listenOff();
                }
            }

            _18 = isOn;
        }
    }
};  // namespace al