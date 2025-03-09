#pragma once

#include <basis/seadTypes.h>

namespace al {
class AreaObjDirector;
class CameraDirector;
class CameraDirector_RS;
class ClippingAreaDirector;
class CollisionDirector;
class EffectSystem;
class ExecuteDirector;
class GraphicsSystemInfo;
class HitSensorDirector;
class LiveActorGroup;
class MultiCoreQueueThread;
class PadRumbleDirector;
class PlayerHolder;
class ScreenPointDirector;
class StageSwitchDirector;
class SwitchAreaDirector;

class LiveActorKit {
public:
    LiveActorKit(s32, s32, bool, bool);

    s32 _0;
    s32 _4;
    AreaObjDirector* mAreaObjDirector;
    ExecuteDirector* mExecDirector;
    EffectSystem* mEffectSystem;
    GraphicsSystemInfo* mGraphicsSystemInfo;
    CameraDirector* mCameraDirector;
    CameraDirector_RS* mCameraDirectorRS;
    ClippingAreaDirector* mClippingAreaDirector;
    CollisionDirector* mCollisionDirector;
    u64 _48;
    PlayerHolder* mPlayerHolder;
    HitSensorDirector* mSensorDirector;
    ScreenPointDirector* mScreenPointDirector;
    u64 _68;
    StageSwitchDirector* mStageSwitchDirector;
    SwitchAreaDirector* mSwitchAreaDirector;
    LiveActorGroup* mActorGroup;
    u64 _88;
    PadRumbleDirector* mRumbleDirector;
    MultiCoreQueueThread* mQueueThread;

    bool _a0;
    bool _a1;
};
}  // namespace al
