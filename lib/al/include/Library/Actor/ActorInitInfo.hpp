#pragma once

#include <basis/seadTypes.h>

namespace al {
class AreaObjDirector;
class AudioDirector;
class CameraDirector_RS;
class ClippingDirectorBase;
class CollisionDirector;
class DemoDirector;
class EffectSystemInfo;
class ExecuteDirector;
class GraphicsSystemInfo;
class HitSensorDirector;
class ItemDirectorBase;
class LayoutInitInfo;
class LiveActor;
class LiveActorGroup;
class Nerve;
class OceanWaveDirector;
class PadRumbleDirector;
class PlacementId;
struct PlacementInfo;
class PlayerHolder;
class SceneCameraInfo;
class SceneObjHolder;
class SceneStopCtrl;
class ScreenCoverCtrl;
class ScreenPointDirector;
class ShadowDirector;
class StageSwitchDirector;

class ActorInitInfo {
public:
    PlacementInfo* mPlacementInfo;
    LayoutInitInfo* mLayoutInitInfo;
    SceneObjHolder* mSceneObjHolder;
    ClippingDirectorBase* mClippingDirectorBase;
    CollisionDirector* mCollisionDirector;
    PlayerHolder* mPlayerHolder;
    SceneCameraInfo* mSceneCameraInfo;
    SceneStopCtrl* mSceneStopCtrl;
    ScreenCoverCtrl* mScreenCoverCtrl;
    ItemDirectorBase* mItemDirectorBase;
    DemoDirector* mDemoDirector;
    AreaObjDirector* mAreaObjDirector;
    ShadowDirector* mShadowDirector;
    PadRumbleDirector* mPadRumbleDirector;
    CameraDirector_RS* mCameraDirector;
    bool _78;
    void* _80;
    GraphicsSystemInfo* mGraphicsSystemInfo;
    ExecuteDirector* mExecuteDirector;
    AudioDirector* mAudioDirector;
    EffectSystemInfo* mEffectSystemInfo;
    OceanWaveDirector* mOceanWaveDirector;
    HitSensorDirector* mHitSensorDirector;
    StageSwitchDirector* mStageSwitchDirector;
    ScreenPointDirector* mScreenPointerDirector;
    PlacementId* mPlacementId;
    LiveActorGroup* mLiveActorGroup;
};
}  // namespace al
