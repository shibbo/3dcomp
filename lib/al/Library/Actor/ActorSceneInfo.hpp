#pragma once

#include <seadTypes.h>

namespace al {
    class SceneStopCtrl;
    class ScreenCoverCtrl;
    class DemoDirector;
    class CameraDirector_RS;
    class PadRumbleDirector;
    class SceneObjHolder;
    class ClippingDirectorBase;
    class PlayerHolder;
    class SceneCameraInfo;
    class CollisionDirector;
    class ItemDirectorBase;
    class ShadowDirector;
    class AreaObjDirector;

    class ActorSceneInfo {
    public:
        ActorSceneInfo();

        SceneObjHolder* mSceneObjHolder;              // 0x0
        ClippingDirectorBase* mClippingDirectorBase;  // 0x8
        CollisionDirector* mCollisionDirector;        // 0x10
        PlayerHolder* mPlayerHolder;                  // 0x18
        SceneCameraInfo* mSceneCameraInfo;            // 0x20
        SceneStopCtrl* mSceneStopCtrl;                // 0x28
        ScreenCoverCtrl* mScreenCoverCtrl;            // 0x30
        ItemDirectorBase* mItemDirectorBase;          // 0x38
        DemoDirector* mDemoDirector;                  // 0x40
        AreaObjDirector* mAreaObjDirector;            // 0x48
        ShadowDirector* mShadowDirector;              // 0x50
        PadRumbleDirector* mPadRumbleDirector;        // 0x58
        CameraDirector_RS* mCameraDirector;           // 0x60
        bool mIsSingleMode;                           // 0x68
        void* _70;
        void* _78;
    };
};  // namespace al