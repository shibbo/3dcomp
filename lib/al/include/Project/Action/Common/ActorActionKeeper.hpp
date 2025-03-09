#pragma once

namespace al {
class ActionAnimCtrl;
class ActionBgmCtrl;
class ActionEffectCtrl;
class ActionFlagCtrl;
class ActionOceanWaveCtrl;
class ActionPadAndCameraCtrl;
class ActionScreenEffectCtrl;
class ActionSeCtrl;
class LiveActor;
class NerveActionCtrl;

class ActorActionKeeper {
public:
    void updatePrev();
    void updatePost();

    LiveActor* mHostActor;
    const char* mActionName;
    void* _10;
    ActionAnimCtrl* mAnimCtrl;
    NerveActionCtrl* mNerveActionCtrl;
    ActionFlagCtrl* mFlagCtrl;
    ActionEffectCtrl* mEffectCtrl;
    ActionSeCtrl* mSeCtrl;
    ActionScreenEffectCtrl* mScreenEffect;
    ActionPadAndCameraCtrl* mPadCtrl;
    ActionOceanWaveCtrl* mOceanWaveCtrl;
    ActionBgmCtrl* mBgmCtrl;
};
}  // namespace al
