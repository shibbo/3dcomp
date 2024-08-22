#include "Project/Bgm/Bgm.hpp"

namespace al {
    void Bgm::startPreparedBgmExistingRequest() {
        _38 = 0;

        if (_3C == 0 && mSoundHandle->mSound != nullptr) {
            mSoundHandle->mSound->StartPrepared();
        }
    }

    void Bgm::pauseBgm(s32 frame) {
        if (_38 == 0) {
            auto basicSound = mSoundHandle->mSound;

            if ((basicSound == nullptr || !basicSound->IsPause()) && !_40) {
                s32 f = (frame == -1) ? 0 : frame;

                if (_3C >= 1) {
                    _40 = 1;

                } else {
                    if (mSoundHandle->mSound != nullptr) {
                        mSoundHandle->mSound->Pause(true, f);
                    }
                }
            }
        }
    }

    /*
    void Bgm::resumeBgm(s32 frame) {
        auto basicSound = mSoundHandle->mSound;
        if ((!_38 && (basicSound != nullptr && basicSound->IsPause())) || _40) {
            if (_3C < 1) {
                _40 = 0;

            } else {
                if (mSoundHandle->mSound != nullptr) {
                    s32 f = (frame >= 1) ? frame : 20;
                    mSoundHandle->mSound->Pause(false, f);
                }
            }
        }
    }
    */

};  // namespace al