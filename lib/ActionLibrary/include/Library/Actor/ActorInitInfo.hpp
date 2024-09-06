#pragma once

#include <prim/seadSafeString.hpp>
#include <types.hpp>
#include "Library/Nerve/NerveAction.hpp"

namespace al {
    class PlacementInfo;
    class LayoutInitInfo;
    class SceneObjHolder;
    class ClippingDirectorBase;
    class CollisionDirector;
    class PlayerHolder;
    class SceneCameraInfo;
    class SceneStopCtrl;
    class ScreenCoverCtrl;
    class ItemDirectorBase;
    class DemoDirector;
    class AreaObjDirector;
    class ShadowDirector;
    class PadRumbleDirector;
    class CameraDirector_RS;
    class GraphicsSystemInfo;
    class ExecuteDirector;
    class AudioDirector;
    class EffectSystemInfo;
    class OceanWaveDirector;
    class HitSensorDirector;
    class StageSwitchDirector;
    class ScreenPointDirector;
    class PlacementId;
    class LiveActorGroup;
    class Nerve;

    class ActorInitInfo {
    public:
        PlacementInfo* mPlacementInfo;                // 0x0
        LayoutInitInfo* mLayoutInitInfo;              // 0x08
        SceneObjHolder* mSceneObjHolder;              // 0x10
        ClippingDirectorBase* mClippingDirectorBase;  // 0x18
        CollisionDirector* mCollisionDirector;        // 0x20
        PlayerHolder* mPlayerHolder;                  // 0x28
        SceneCameraInfo* mSceneCameraInfo;            // 0x30
        SceneStopCtrl* mSceneStopCtrl;                // 0x38
        ScreenCoverCtrl* mScreenCoverCtrl;            // 0x40
        ItemDirectorBase* mItemDirectorBase;          // 0x48
        DemoDirector* mDemoDirector;                  // 0x50
        AreaObjDirector* mAreaObjDirector;            // 0x58
        ShadowDirector* mShadowDirector;              // 0x60
        PadRumbleDirector* mPadRumbleDirector;        // 0x68
        CameraDirector_RS* mCameraDirector;           // 0x70
        bool _78;
        void* _80;
        GraphicsSystemInfo* mGraphicsSystemInfo;      // 0x88
        ExecuteDirector* mExecuteDirector;            // 0x90
        AudioDirector* mAudioDirector;                // 0x98
        EffectSystemInfo* mEffectSystemInfo;          // 0xA0
        OceanWaveDirector* mOceanWaveDirector;        // 0xA8
        HitSensorDirector* mHitSensorDirector;        // 0xB0
        StageSwitchDirector* mStageSwitchDirector;    // 0xB8
        ScreenPointDirector* mScreenPointerDirector;  // 0xC0
        PlacementId* mPlacementId;                    // 0xC8
        LiveActorGroup* mLiveActorGroup;              // 0xD0
    };

    void initActorChangeModelSuffix(LiveActor*, const ActorInitInfo&, const char*);
    void initActorWithArchiveName(LiveActor*, const ActorInitInfo&, const sead::SafeString&,
                                  const char*);
    void initActorWithArchiveCategoryName(LiveActor*, const ActorInitInfo&, const sead::SafeString&,
                                          const sead::SafeString&, const char*);
    void initActorWithArchiveNameWithPlacementInfo(LiveActor*, const ActorInitInfo&,
                                                   const sead::SafeString&, const char*);
    void initActorWithArchiveNameNoPlacementInfo(LiveActor*, const ActorInitInfo&,
                                                 const sead::SafeString&, const char*);

    void initNerve(LiveActor*, const Nerve*, s32);
    void initNerveAction(LiveActor*, const char*, alNerveFunction::NerveActionCollector*, s32);

    bool trySyncStageSwitchAppear(LiveActor*);
    bool trySyncStageSwitchKill(LiveActor*);
    bool trySyncStageSwitchAppearAndKill(LiveActor*);
    bool tryListenStageSwitchAppear(LiveActor*);
    bool tryListenStageSwitchKill(LiveActor*);
    void syncSensorScaleY(LiveActor*);
};  // namespace al