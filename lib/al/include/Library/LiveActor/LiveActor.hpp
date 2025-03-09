#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

#include "Library/HostIO/IUseHioNode.hpp"
#include "Library/Nerve/IUseNerve.hpp"
#include "Library/Scene/IUseSceneObjHolder.hpp"
#include "Library/StageSwitch/Core/IUseStageSwitch.hpp"
#include "Project/AreaObj/IUseAreaObj.hpp"
#include "Project/Audio/IUseAudioKeeper.hpp"
#include "Project/Camera/Core/IUseCameraDirector.hpp"
#include "Project/Camera/Main/IUseCameraDirector_RS.hpp"
#include "Project/Collision/IUseCollision.hpp"
#include "Project/Effect/Core/IUseEffectKeeper.hpp"
#include "Project/OceanWave/IUseOceanWave.hpp"

namespace al {
class ActorActionKeeper;
class ActorAlphaCtrl;
class ActorExecuteInfo;
class ActorInitInfo;
class ActorItemKeeper;
class ActorParamHolder;
class ActorPoseKeeperBase;
class ActorPrePassLightKeeper;
class ActorScoreKeeper;
class AudioKeeper;
class Collider;
class CollisionParts;
class EffectKeeper;
class HitReactionKeeper;
class HitSensor;
class HitSensorKeeper;
class ModelKeeper;
class NerveKeeper;
class PlacementHolder;
class RailKeeper;
class ScreenPointer;
class ScreenPointKeeper;
class ScreenPointTarget;
class SensorMsg;
class ShadowKeeper;
class StageSwitchKeeper;
class SubActorKeeper;
struct ActorSceneInfo;
struct LiveActorFlag;

class LiveActor : public IUseNerve,
                  public IUseEffectKeeper,
                  public IUseAudioKeeper,
                  public IUseOceanWave,
                  public IUseStageSwitch,
                  public IUseSceneObjHolder,
                  public IUseAreaObj,
                  public IUseCamera,
                  public IUseCamera_RS,
                  public IUseCollision,
                  public IUseHioNode {
public:
    LiveActor(const char*);

    virtual NerveKeeper* getNerveKeeper() const { return mNerveKeeper; }

    virtual ~LiveActor();

    virtual void init(const ActorInitInfo&) {}

    virtual void initAfterPlacement();
    virtual void appear();
    virtual void reappear();

    virtual void respawn() {}

    virtual void makeActorAppeared();
    virtual void kill();
    virtual void killComplete(bool);
    virtual void makeActorDead();
    virtual bool showActor();
    virtual bool hideActor();
    virtual void startDemoActor(s32);
    virtual void endDemoActor(s32);
    virtual void changeScenarioID(s32, bool);
    virtual void updateLinkedTrans(const sead::Vector3f&);
    virtual void movement();
    virtual void movementPaused(bool);
    virtual void calcAnim();
    virtual bool modelUpdate();
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

    virtual bool isFarLodSwitchOkay() { return true; }

    virtual bool canLinkYOffset() const { return true; }

    virtual void attackSensor(HitSensor* self, HitSensor* other) {}

    virtual bool receiveMsg(const SensorMsg* msg, HitSensor* self, HitSensor* other) {
        return false;
    }

    virtual bool receiveMsgScreenPoint(const SensorMsg*, ScreenPointer*, ScreenPointTarget*) {
        return false;
    }

    virtual bool receiveMsgScreenPointSM(const SensorMsg*, ScreenPointer*, ScreenPointTarget*) {
        return false;
    }

    virtual const char* getName() const { return mActorName; }

    virtual const sead::Matrix34f* getBaseMtx() const;

    virtual EffectKeeper* getEffectKeeper() const { return mEffectKeeper; }

    virtual AudioKeeper* getAudioKeeper() const { return mAudioKeeper; }

    virtual StageSwitchKeeper* getStageSwitchKeeper() const { return mStageSwitchKeeper; }

    virtual SceneObjHolder* getSceneObjHolder() const;
    virtual CollisionDirector* getCollisionDirector() const;
    virtual AreaObjDirector* getAreaObjDirector() const;
    virtual SceneCameraInfo* getSceneCameraInfo() const;
    virtual CameraDirector_RS* getCameraDirector_RS() const;

    virtual bool isInRouteDokan() const { return false; }

    virtual void initStageSwitchKeeper();

    virtual LiveActor* getLinkedActor() { return nullptr; }

    virtual void control();

    virtual void calcAndSetBaseMtx() {}

    virtual void updateCollider();

    ActorSceneInfo* getSceneInfo() const;

    void initPoseKeeper(ActorPoseKeeperBase*);
    void initExecuteInfo(ActorExecuteInfo*);
    void initModelKeeper(ModelKeeper*);
    void initActionKeeper(const char*, const char*);
    void initNerveKeeper(NerveKeeper*);
    void initHitSensor(s32);
    void initScreenPointKeeper(s32);
    void initEffectKeeper(EffectKeeper*);
    void initAudioKeeper(AudioKeeper*);
    void initOceanWaveKeeper(OceanWaveKeeper*);
    void initRailKeeper(const ActorInitInfo&);
    void initCollider(f32, f32, u32);
    void initShadowKeeper(ShadowKeeper*);
    void initItemKeeper(s32);
    void initScoreKeeper();
    void initActorPrePassLightKeeper(ActorPrePassLightKeeper*);
    void initSubActorKeeper(SubActorKeeper*);
    void initSceneInfo(ActorSceneInfo*);
    void initActorAlphaCtrl(ActorAlphaCtrl*, const ActorInitInfo&);
    void setCollision(bool);
    void setPlacementHolder(const ActorInitInfo&);
    void setGlobalAlphaPtr(f32*);

    void setGlobalYOffsetRef(f32*);
    f32 getGlobalYOffset() const;
    void setFarLodActor(LiveActor*);
    void setIsFarLodModel(bool);

    inline void updateLOD();
    inline void setMaterial();

    const char* mActorName = nullptr;
    ActorPoseKeeperBase* mActorPoseKeeper = nullptr;
    ActorExecuteInfo* mActorExecuteInfo = nullptr;
    ActorActionKeeper* mActionKeeper = nullptr;
    ActorItemKeeper* mItemKeeper = nullptr;
    ActorScoreKeeper* mScoreKeeper = nullptr;
    Collider* mCollider = nullptr;
    CollisionParts* mCollisionParts = nullptr;
    ModelKeeper* mModelKeeper = nullptr;
    NerveKeeper* mNerveKeeper = nullptr;
    HitSensorKeeper* mHitSensorKeeper = nullptr;
    ScreenPointKeeper* mScreenPointKeeper = nullptr;
    EffectKeeper* mEffectKeeper = nullptr;
    AudioKeeper* mAudioKeeper = nullptr;
    HitReactionKeeper* mHitReactionKeeper = nullptr;
    StageSwitchKeeper* mStageSwitchKeeper = nullptr;
    RailKeeper* mRailKeeper = nullptr;
    ShadowKeeper* mShadowKeeper = nullptr;
    ActorPrePassLightKeeper* mLightKeeper = nullptr;
    SubActorKeeper* mSubActorKeeper = nullptr;
    ActorParamHolder* mActorParamHolder = nullptr;
    ActorSceneInfo* mActorSceneInfo = nullptr;
    u64* _100 = nullptr;
    LiveActorFlag* mActorFlags = nullptr;
    ActorAlphaCtrl* mAlphaCtrl = nullptr;
    PlacementHolder* mPlacementHolder = nullptr;
    f32 mGlobalAlphaLastFrame = 1.0f;
    f32 mGlobalAlpha = 1.0f;
    f32* mGlobalYOffsetRef = nullptr;
    f32 mGlobalYOffset = 0;
    f32 _134;
    LiveActor* mFarLodActor;
    u8 _140 = 0;
    u8 mIsFarLodModel = 0;
    u8 _142 = 0;
    u8 _143 = 0;
};
}  // namespace al
