#pragma once

#include "Library/Area/IUseAreaObj.hpp"
#include "Library/Audio/IUseAudioKeeper.hpp"
#include "Library/Camera/IUseCameraDirector.hpp"
#include "Library/Collision/IUseCollision.hpp"
#include "Library/Effect/IUseEffectKeeper.hpp"
#include "Library/HostIO/IUseHioNode.hpp"
#include "Library/Map/IUseOceanWave.hpp"
#include "Library/Nerve/IUseNerve.hpp"
#include "Library/Scene/IUseSceneObjHolder.hpp"
#include "Library/Stage/IUseStageSwitch.hpp"
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
    class ActorPoseKeeperBase;
    class ActorExecuteInfo;
    class ActorActionKeeper;
    class HitReactionKeeper;
    class CollisionParts;
    class ActorParamHolder;

    class LiveActor :   public IUseNerve,
                        public IUseEffectKeeper,
                        public IUseAudioKeeper,
                        public IUseOceanWave,
                        public IUseStageSwitch,
                        public IUseSceneObjHolder,
                        public IUseAreaObj,
                        public IUseCamera_RS,
                        public IUseCamera,
                        public IUseCollision,
                        public IUseHioNode
    {
    public:

        LiveActor(const char *);

        virtual NerveKeeper* getNerveKeeper() const {
            return mNerveKeeper;
        }

        virtual ~LiveActor();

        virtual void init(const ActorInitInfo &) {

        }

        virtual void initAfterPlacement();
        virtual void appear();
        virtual void reappear();

        virtual void respawn() {

        }

        virtual void makeActorAppeared();
        virtual void kill();
        virtual void killComplete(bool);
        virtual void makeActorDead();
        virtual void showActor();
        virtual bool hideActor();
        virtual void startDemoActor(s32);
        virtual void endDemoActor(s32);
        virtual void changeScenarioID(s32, bool);
        virtual void updateLinkedTrans(const sead::Vector3f &);
        virtual void movement();
        virtual void movementPaused(bool);
        virtual void calcAnim();
        virtual void modelUpdate();
        virtual void pausedModelUpdate();
        virtual void draw() const;
        virtual void pause();
        virtual void resume();
        virtual void startClipped();
        virtual void endClipped();
        virtual void startClippedByLod();
        virtual void endClippedByLod();
        virtual void startFarLod();
        virtual void endFarLod();

        virtual bool isFarLodSwitchOkay() {
            return true;
        }
    
        virtual bool canLinkYOffset() const {
            return true;
        }
    
        virtual void attackSensor(HitSensor *, HitSensor *) {

        }

        virtual bool receiveMsg(const SensorMsg *, HitSensor *, HitSensor *) {
            return false;
        }

        virtual bool receiveMsgScreenPoint(const SensorMsg *, ScreenPointer *, ScreenPointTarget *) {
            return false;
        }

        virtual bool receiveMsgScreenPointSM(const SensorMsg *, ScreenPointer *, ScreenPointTarget *) {
            return false;
        }

        virtual const char* getName() const {
            return mActorName;
        }

        virtual sead::Matrix34f& getBaseMtx() const;

        virtual EffectKeeper* getEffectKeeper() const {
            return mEffectKeeper;
        }

        virtual AudioKeeper* getAudioKeeper() const {
            return mAudioKeeper;
        }

        virtual StageSwitchKeeper* getStageSwitchKeeper() const {
            return mStageSwitchKeeper;
        }

        virtual SceneObjHolder* getSceneObjHolder() const;
        virtual CollisionDirector* getCollisionDirector() const;
        virtual AreaObjDirector* getAreaObjDirector() const;
        virtual SceneCameraInfo* getSceneCameraInfo() const;
        virtual CameraDirector_RS* getCameraDirector_RS() const;

        virtual bool isInRouteDokan() const {
            return false;
        }

        virtual void initStageSwitchKeeper();

        virtual LiveActor* getLinkedActor() {
            return nullptr;
        }

        virtual void control();

        virtual void calcAndSetBaseMtx() {

        }

        virtual void updateCollider();


        ActorSceneInfo* getSceneInfo() const;
        void initNerveKeeper(NerveKeeper *);

        void setGlobalYOffsetRef(f32 *);
        f32 getGlobalYOffset() const;
        void setFarLodActor(LiveActor *);

        const char* mActorName = nullptr;                           // 0x50
        ActorPoseKeeperBase* mActorPoseKeeper = nullptr;            // 0x58
        ActorExecuteInfo* mActorExecuteInfo = nullptr;              // 0x60
        ActorActionKeeper* mActionKeeper = nullptr;                 // 0x68
        ActorItemKeeper* mItemKeeper = nullptr;                     // 0x70
        ActorScoreKeeper* mScoreKeeper = nullptr;                   // 0x78
        Collider* mCollider = nullptr;                              // 0x80
        CollisionParts* mCollisionParts = nullptr;                  // 0x88
        ModelKeeper* mModelKeeper = nullptr;                        // 0x90
        NerveKeeper* mNerveKeeper = nullptr;                        // 0x98
        HitSensorKeeper* mHitSensorKeeper = nullptr;                // 0xA0
        ScreenPointKeeper* mScreenPointKeeper = nullptr;            // 0xA8
        EffectKeeper* mEffectKeeper = nullptr;                      // 0xB0
        AudioKeeper* mAudioKeeper = nullptr;                        // 0xB8
        HitReactionKeeper* mHitReactionKeeper = nullptr;            // 0xC0
        StageSwitchKeeper* mStageSwitchKeeper = nullptr;            // 0xC8
        RailKeeper* mRailKeeper = nullptr;                          // 0xD0
        ShadowKeeper* mShadowKeeper = nullptr;                      // 0xD8
        ActorPrePassLightKeeper* mLightKeeper = nullptr;            // 0xE0
        SubActorKeeper* mSubActorKeeper = nullptr;                  // 0xE8
        ActorParamHolder* mActorParamHolder = nullptr;              // 0xF0
        ActorSceneInfo* mActorSceneInfo = nullptr;                  // 0xF8
        u64* _100 = nullptr;
        LiveActorFlag* mActorFlags = nullptr;                       // 0x108
        u64* _110 = nullptr;
        PlacementHolder* mPlacementHolder = nullptr;                // 0x118
        f32* mGlobalAlpha = (f32*)0x3F8000003F800000;                // 0x120
        f32* mGlobalYOffset = nullptr;                              // 0x128
        f32 _130 = 0;
        f32 _134;
        LiveActor* mFarLodActor;                                    // 0x138
        u8 _140 = 0;
        u8 mIsFarLodModel = 0;                                      // 0x141
        u8 _142 = 0;
        u8 _143 = 0;
    };
}

namespace alSubActorFunction {
    void setGlobalYOffset(al::SubActorKeeper *, f32 *);
}