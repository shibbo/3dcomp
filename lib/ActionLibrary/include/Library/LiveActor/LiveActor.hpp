#pragma once

#include "Library/Area/IUseAreaObj.hpp"
#include "Library/Audio/IUseAudioKeeper.hpp"
#include "Library/Camera/IUseCameraDirector.hpp"
#include "Library/Collision/IUseCollision.hpp"
#include "Library/Effect/IUseEffectKeeper.hpp"
#include "Library/Nerve/IUseNerve.hpp"
#include "Library/Scene/IUseSceneObjHolder.hpp"
#include "Library/Stage/IUseStageSwitch.hpp"
#include "Library/HostIO/IUseHioNode.hpp"
#include <types.hpp>
#include <math/seadMatrix.hpp>
#include <math/seadVector.hpp>

namespace al {
    class AudioKeeper;
    class EffectKeeper;
    class StageSwitchKeeper;
    class NerveKeeper;
    class PlacementHolder;
    class LiveActorFlag;
    class ActorPrePassLightKeeper;
    class ShadowKeeper;
    class ModelKeeper;
    class SubActorKeeper;
    class ActorSceneInfo;
    class Collider;
    class HitSensorKeeper;
    class ScreenPointKeeper;
    class RailKeeper;
    class ActorItemKeeper;
    class ActorScoreKeeper;
    class ActorInitInfo;
    class HitSensor;
    class SensorMsg;
    class ScreenPointer;
    class ScreenPointTarget;

    class LiveActor :   public IUseNerve, // 0x0
                        public IUseEffectKeeper, // 0x8
                        public IUseAudioKeeper, // 0x10
                        public IUseStageSwitch, // 0x18
                        public IUseSceneObjHolder, // 0x20
                        public IUseAreaObj,        // 0x28
                        public IUseCamera,      // 0x30
                        public IUseCamera_RS,   // 0x38
                        public IUseCollision, // 0x40,
                        public IUseHioNode  // 0x48
    {
    public:

        LiveActor(const char *);

        virtual NerveKeeper* getNerveKeeper() const;
        virtual ~LiveActor();
        virtual void init(const ActorInitInfo &);
        virtual void initAfterPlacement();
        virtual void appear();
        virtual void reappear();
        virtual void respawn();
        virtual void makeActorAppeared();
        virtual void kill();
        virtual void killComplete(bool);
        virtual void makeActorDead();
        virtual void showActor();
        virtual void hideActor();
        virtual void startDemoActor(s32);
        virtual void endDemoActor(s32);
        virtual void changeScenarioID(s32, bool);
        virtual void updateLinkedTrans(const sead::Vector3f &);
        virtual void movement();
        virtual void movementPaused(bool);
        virtual void draw() const;
        virtual void pause();
        virtual void resume();
        virtual void startClipped();
        virtual void endClipped();
        virtual void startClippedByLod();
        virtual void endClippedByLod();
        virtual void startFarLod();
        virtual void endFarLod();
        virtual bool isFarLodSwitchOkay();
        virtual bool canLinkYOffset();
        virtual void attackSensor(HitSensor *, HitSensor *);
        virtual bool receiveMsg(const SensorMsg *, HitSensor *, HitSensor *);
        virtual bool receiveMsgScreenPoint(const SensorMsg *, ScreenPointer *, ScreenPointTarget *);
        virtual bool receiveMsgScreenPointSM(const SensorMsg *, ScreenPointer *, ScreenPointTarget *);
        const char* getName() const;
        sead::Matrix34f& getBaseMtx() const;
        EffectKeeper* getEffectKeeper() const;
        AudioKeeper* getAudioKeeper() const;
        StageSwitchKeeper* getStageSwitchKeeper() const;
        SceneObjHolder* getSceneObjHolder() const;
        CollisionDirector* getCollisionDirector() const;
        AreaObjDirector* getAreaObjDirector() const;
        SceneCameraInfo* getSceneCameraInfo() const;
        CameraDirector_RS* getCameraDirector_RS() const;
        bool isInRouteDokan() const;
        virtual void initStageSwitchKeeper();
        LiveActor* getLinkedActor();
        virtual void control();
        virtual void calcAndSetBaseMtx();
        virtual void updateCollider();

        void initNerveKeeper(NerveKeeper *);

        const char* mActorName;                 // 0x50
        u64 _58;
        u64 _60;
        u64 _68;
        ActorItemKeeper* mItemKeeper;           // 0x70
        ActorScoreKeeper* mScoreKeeper;         // 0x78
        Collider* mCollider;                    // 0x80
        u64 _88;
        ModelKeeper* mModelKeeper;              // 0x90
        NerveKeeper* mNerveKeeper;              // 0x98
        HitSensorKeeper* mHitSensorKeeper;      // 0xA0
        ScreenPointKeeper* mScreenPointKeeper;  // 0xA8
        EffectKeeper* mEffectKeeper;            // 0xB0
        AudioKeeper* mAudioKeeper;              // 0xB8
        u64 _C0;
        StageSwitchKeeper* mStageSwitchKeeper;  // 0xC8
        RailKeeper* mRailKeeper;                // 0xD0
        ShadowKeeper* mShadowKeeper;            // 0xD8
        ActorPrePassLightKeeper* mLightKeeper;  // 0xE0
        SubActorKeeper* mSubActorKeeper;        // 0xE8
        u64 _F0;
        ActorSceneInfo* mActorSceneInfo;        // 0xF8
        u64 _100;
        LiveActorFlag* mActorFlags;             // 0x108
        u64 _110;
        PlacementHolder* mPlacementHolder;      // 0x118
    };
}