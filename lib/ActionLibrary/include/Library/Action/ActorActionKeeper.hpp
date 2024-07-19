#pragma once

namespace al {
    class LiveActor;
    class ActionAnimCtrl;
    class NerveActionCtrl;
    class ActionFlagCtrl;
    class ActionEffectCtrl;
    class ActionSeCtrl;
    class ActionBgmCtrl;
    class ActionOceanWaveCtrl;
    class ActionPadAndCameraCtrl;
    class ActionScreenEffectCtrl;

    class ActorActionKeeper {
    public:

        void updatePrev();
        void updatePost();

        LiveActor* mHostActor;                  // 0x00
        const char* mActionName;                // 0x08
        void* _10;
        ActionAnimCtrl* mAnimCtrl;              // 0x18
        NerveActionCtrl* mNerveActionCtrl;      // 0x20
        ActionFlagCtrl* mFlagCtrl;              // 0x28
        ActionEffectCtrl* mEffectCtrl;          // 0x30
        ActionSeCtrl* mSeCtrl;                  // 0x38
        ActionScreenEffectCtrl* mScreenEffect;  // 0x40
        ActionPadAndCameraCtrl* mPadCtrl;       // 0x48
        ActionOceanWaveCtrl* mOceanWaveCtrl;    // 0x50
        ActionBgmCtrl* mBgmCtrl;                // 0x58
    };
};