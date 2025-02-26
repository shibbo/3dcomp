#pragma once

#include <seadTypes.h>

namespace al {
    class LiveActorGroup;
    class PlayerHolder;
    class ExecuteDirector;
    class SwitchAreaDirector;
    class MultiCoreQueueThread;
    class EffectSystem;
    class AreaObjDirector;
    class CollisionDirector;
    class CameraDirector_RS;
    class CameraDirector;
    class PadRumbleDirector;
    class ClippingAreaDirector;
    class StageSwitchDirector;
    class ScreenPointDirector;
    class GraphicsSystemInfo;
    class HitSensorDirector;

    class LiveActorKit {
    public:
        LiveActorKit(s32, s32, bool, bool);

        s32 _0;
        s32 _4;
        AreaObjDirector* mAreaObjDirector;            // 0x08
        ExecuteDirector* mExecDirector;               // 0x10
        EffectSystem* mEffectSystem;                  // 0x18
        GraphicsSystemInfo* mGraphicsSystemInfo;      // 0x20
        CameraDirector* mCameraDirector;              // 0x28
        CameraDirector_RS* mCameraDirectorRS;         // 0x30
        ClippingAreaDirector* mClippingAreaDirector;  // 0x38
        CollisionDirector* mCollisionDirector;        // 0x40
        u64 _48;
        PlayerHolder* mPlayerHolder;                // 0x50
        HitSensorDirector* mSensorDirector;         // 0x58
        ScreenPointDirector* mScreenPointDirector;  // 0x60
        u64 _68;
        StageSwitchDirector* mStageSwitchDirector;  // 0x70
        SwitchAreaDirector* mSwitchAreaDirector;    // 0x78
        LiveActorGroup* mActorGroup;                // 0x80
        u64 _88;
        PadRumbleDirector* mRumbleDirector;  // 0x90
        MultiCoreQueueThread* mQueueThread;  // 0x98

        bool _A0;
        bool _A1;
    };
};  // namespace al