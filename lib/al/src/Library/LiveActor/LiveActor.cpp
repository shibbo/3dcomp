#include "Library/LiveActor/LiveActor.hpp"

#include "Library/Actor/ActorClippingUtil.hpp"
#include "Library/Actor/ActorInitInfo.hpp"
#include "Library/Actor/ActorMapUtil.hpp"
#include "Library/Actor/ActorModelUtil.hpp"
#include "Library/Actor/ActorMovementUtil.hpp"
#include "Library/Actor/ActorPoseKeeper.hpp"
#include "Library/Actor/ActorPoseUtil.hpp"
#include "Library/Actor/ActorSceneInfo.hpp"
#include "Library/Actor/ActorSceneUtil.hpp"
#include "Library/Execute/ActorExecuteDb.hpp"
#include "Library/Execute/ActorSystemFunction.hpp"
#include "Library/HitSensor/HitSensor.hpp"
#include "Library/HitSensor/HitSensorKeeper.hpp"
#include "Library/Item/ActorScoreKeeper.hpp"
#include "Library/Light/LppActor.hpp"
#include "Library/LiveActor/LiveActorFlag.hpp"
#include "Library/LiveActor/LiveActorFunc.hpp"
#include "Library/LiveActor/LiveActorUtil.hpp"
#include "Library/LiveActor/SubActorUtil.hpp"
#include "Library/Model/Core/ModelKeeper.hpp"
#include "Library/Screen/ScreenPointKeeper.hpp"
#include "Library/Sequence/DemoDirector.hpp"
#include "Library/Shadow/Common/ShadowUtil.hpp"
#include "Library/Shadow/ShadowKeeper.hpp"
#include "Project/Action/Common/ActionSeCtrl.hpp"
#include "Project/Action/Common/ActorActionKeeper.hpp"
#include "Project/Audio/AudioKeeper.hpp"
#include "Project/Clipping/ClippingFunction.hpp"
#include "Project/Collision/Collider.hpp"
#include "Project/Collision/CollisionParts.hpp"
#include "Project/Collision/CollisionPartsKeeperUtil.hpp"
#include "Project/Effect/Core/EffectKeeper.hpp"
#include "Project/Matrix/MatrixUtil.hpp"
#include "Project/Play/Actor/ActorAlphaCtrl.hpp"
#include "Project/Play/Placement/PlacementHolder.hpp"

namespace al {
LiveActor::LiveActor(const char* pName) : mActorName(pName) {
    mFarLodActor = nullptr;
    mActorFlags = new LiveActorFlag();
    mPlacementHolder = new PlacementHolder();
}

LiveActor::~LiveActor() {
    if (mShadowKeeper != nullptr) {
        delete mShadowKeeper;
        mShadowKeeper = nullptr;
    }

    if (mLightKeeper != nullptr) {
        delete mLightKeeper;
        mLightKeeper = nullptr;
    }
}

void LiveActor::initAfterPlacement() {
    tryInitFixedModelGpuBuffer(this);

    if (mLightKeeper != nullptr)
        mLightKeeper->initAfterPlacement();
}

void LiveActor::appear() {
    makeActorAppeared();

    if (mActionKeeper != nullptr) {
        if (mActionKeeper->mSeCtrl != nullptr)
            mActionKeeper->mSeCtrl->resetAction();
    }
}

void LiveActor::reappear() {}

void LiveActor::makeActorAppeared() {
    if (mHitSensorKeeper != nullptr)
        mHitSensorKeeper->validateBySystem();

    if (mScreenPointKeeper != nullptr)
        mScreenPointKeeper->validateBySystem();

    mActorFlags->isDead = false;

    if (isClipped(this))
        endClipped();

    if (!isHideModel(this)) {
        if (mModelKeeper != nullptr)
            mModelKeeper->show();
    }

    resetPosition(this, false);

    if (mCollisionParts != nullptr)
        validateCollisionPartsBySystem(this);

    if (mHitSensorKeeper != nullptr)
        mHitSensorKeeper->update();

    alClippingFunction::addToClippingTarget(this);

    if (mActorExecuteInfo != nullptr) {
        alActorSystemFunction::addToExecutorMovement(this);
        if (!isHideModel(this) && mActorExecuteInfo->mNumDrawerBases >= 1)
            alActorSystemFunction::addToExecutorDraw(this);
    }

    if (getAudioKeeper() != nullptr)
        getAudioKeeper()->appear();

    if (mLightKeeper != nullptr)
        mLightKeeper->appear(isHideModel(this));

    if (mShadowKeeper != nullptr && !isHideModel(this))
        mShadowKeeper->show();

    if (mSubActorKeeper != nullptr)
        alSubActorFunction::trySyncAlive(mSubActorKeeper);
}

void LiveActor::kill() {
    makeActorDead();
}

void LiveActor::killComplete(bool) {
    kill();
}

void LiveActor::makeActorDead() {
    if (mFarLodActor != nullptr)
        endFarLod();

    if (mActorPoseKeeper != nullptr)
        setVelocityZero(this);

    mActorFlags->isDead = true;

    if (mHitSensorKeeper != nullptr)
        mHitSensorKeeper->invalidateBySystem();

    if (mScreenPointKeeper != nullptr)
        mScreenPointKeeper->invalidateBySystem();

    alClippingFunction::removeFromClippingTarget(this);

    if (mCollider != nullptr)
        mCollider->onInvalidate();

    if (mCollisionParts != nullptr)
        invalidateCollisionPartsBySystem(this);

    if (mModelKeeper != nullptr)
        mModelKeeper->hide();

    if (getEffectKeeper() != nullptr)
        getEffectKeeper()->deleteAndClearEffectAll();

    if (getAudioKeeper() != nullptr)
        getAudioKeeper()->kill();

    if (mLightKeeper != nullptr)
        mLightKeeper->requestKill();

    if (mShadowKeeper != nullptr)
        mShadowKeeper->hide();

    if (mActorExecuteInfo != nullptr) {
        alActorSystemFunction::removeFromExecutorMovement(this);

        if (mActorExecuteInfo->mNumDrawerBases >= 1)
            alActorSystemFunction::removeFromExecutorDraw(this);
    }

    if (mSubActorKeeper != nullptr)
        alSubActorFunction::trySyncDead(mSubActorKeeper);
}

bool LiveActor::showActor() {
    if (mActorFlags->_1c) {
        if (isDead(this))
            return true;
    } else {
        validateClipping(this);
        if (isDead(this))
            return true;
    }

    if (mActorFlags->_1c && isClipped(this))
        endClipped();

    if (mCollisionParts != nullptr) {
        mCollisionParts->validateBySystem();
        return true;
    }

    return true;
}

bool LiveActor::hideActor() {
    if (!mActorFlags->_1c && !isDead(this))
        invalidateClipping(this);

    if (!isDead(this)) {
        if (!isClipped(this))
            startClipped();

        if (mCollisionParts != nullptr)
            mCollisionParts->invalidateBySystem();
    }

    return true;
}

void LiveActor::startDemoActor(s32) {
    return;
}

void LiveActor::endDemoActor(s32) {
    return;
}

void LiveActor::changeScenarioID(s32, bool) {
    return;
}

void LiveActor::updateLinkedTrans(const sead::Vector3f& rVector) {
    setTrans(this, rVector);
}

// LiveActor::movementPaused

inline void LiveActor::updateLOD() {
    bool isActiveDemo;

    if (mActorSceneInfo->demoDirector != nullptr) {
        isActiveDemo = mActorSceneInfo->demoDirector->isActiveDemo();
        if (isSingleMode(this))
            return;
    } else {
        isActiveDemo = false;
        if (isSingleMode(this))
            return;
    }

    mModelKeeper->updateLod(mActorPoseKeeper->mTranslation, isActiveDemo);
}

inline void LiveActor::setMaterial() {
    const char* name;

    if (isCollidedGround(this))
        name = getCollidedFloorMaterialCodeName(this);
    else if (isCollidedWall(this))
        name = getCollidedWallMaterialCodeName(this);
    else if (isCollidedCeiling(this))
        name = getCollidedCeilingMaterialCodeName(this);
    else
        return;

    setMaterialCode(this, name);
}

ActorSceneInfo* LiveActor::getSceneInfo() const {
    return mActorSceneInfo;
}

/*
void LiveActor::movement() {
    if (mActorFlags->isDead || (mActorFlags->isClipped && !mActorFlags->isDrawClipping)) {
        return;
    }

    mGlobalAlphaLastFrame = mGlobalAlpha;

    if (!_140) {
        if (mActionKeeper != nullptr) {
            mActionKeeper->updatePrev();
        }

        if (mModelKeeper != nullptr) {
            updateLOD();
            mModelKeeper->update();
        }

        if (mActorFlags->isValidCeilWallFloorMatCode) {
            setMaterial();
        }

        if (mActorFlags->isValidMatCode) {
            if (isCollidedGround(this)) {
                setMaterialCode(this, getCollidedFloorMaterialCodeName(this));
            }
        }

        HitSensorKeeper* keeper = mHitSensorKeeper;

        if (keeper != nullptr) {
            keeper->attackSensor();
        }

        if (!mActorFlags->isDead) {
            NerveKeeper* nerveKeeper = mNerveKeeper;
            if (nerveKeeper != nullptr, nerveKeeper->update(), !mActorFlags->isDead) {
                control();

                if (!mActorFlags->isDead) {
                    updateCollider();

                    if (isUpdateMovementEffectAudioCollision(this)) {
                        if (mEffectKeeper != nullptr) {
                            mEffectKeeper->update();
                        }

                        if (mAudioKeeper != nullptr) {
                            mAudioKeeper->update();
                        }

                        if (mCollisionParts != nullptr) {
                            if (mModelKeeper == nullptr || !mModelKeeper->_18) {
                                sead::Matrix34f poseMtx;
                                mActorPoseKeeper->updatePoseMtx(&poseMtx);
                                preScaleMtx(&poseMtx, mActorPoseKeeper->getScale());
                                syncCollisionMtx(this, &poseMtx);
                            }
                        }
                    }

                    if (mActionKeeper != nullptr) {
                        mActionKeeper->updatePost();
                    }

                    if (mHitSensorKeeper != nullptr) {
                        mHitSensorKeeper->update();
                    }

                    if (mScreenPointKeeper != nullptr) {
                        mScreenPointKeeper->update();
                    }

                    if (mModelKeeper != nullptr) {
                        mModelKeeper->mModelCafe->updateLast();
                        return;
                    }

                    return;
                }
            }
        }
    }
}
*/

void LiveActor::calcAnim() {
    if (!mActorFlags->isDead && (!mActorFlags->isClipped || mActorFlags->isDrawClipping) && !_140) {
        if (mActorPoseKeeper != nullptr)
            alLiveActorFunction::calcAnimDirect(this);

        if (mAudioKeeper != nullptr)
            mAudioKeeper->update();
    }
}

bool LiveActor::modelUpdate() {
    if (mActorFlags->isDead)
        return false;

    if (mActorFlags->isClipped && !mActorFlags->isDrawClipping)
        return false;

    if (mAlphaCtrl != nullptr) {
        f32 alph = mAlphaCtrl->update(getClippingJudge(this));
        if (!isInvalidCliping(this))
            alph *= mGlobalAlpha;

        mGlobalAlpha = alph;
    }

    return true;
}

void LiveActor::pausedModelUpdate() {
    if (modelUpdate() != false)
        mGlobalAlphaLastFrame = mGlobalAlpha;
}

void LiveActor::draw() const {
    return;
}

void LiveActor::pause() {
    return;
}

void LiveActor::resume() {
    return;
}

void LiveActor::startClipped() {
    mActorFlags->isClipped = true;

    if (!mActorFlags->isClippedByLOD) {
        if (mModelKeeper != nullptr)
            mModelKeeper->hide();

        if (!mActorFlags->isDrawClipping) {
            if (mHitSensorKeeper != nullptr)
                mHitSensorKeeper->invalidateBySystem();

            if (getEffectKeeper() != nullptr)
                getEffectKeeper()->offCalcAndDraw();

            if (getAudioKeeper())
                getAudioKeeper()->startClipped();
        }

        if (mShadowKeeper != nullptr)
            hideShadow(this);

        if (mScreenPointKeeper != nullptr)
            mScreenPointKeeper->invalidateBySystem();

        if (mLightKeeper != nullptr)
            mLightKeeper->hideModel();

        if (mActorExecuteInfo != nullptr) {
            if (!mActorFlags->isDrawClipping)
                alActorSystemFunction::removeFromExecutorMovement(this);

            if (mActorExecuteInfo->mNumDrawerBases >= 1)
                alActorSystemFunction::removeFromExecutorDraw(this);

            if (mActorFlags->isDrawClipping) {
                if (mModelKeeper != nullptr) {
                    if (mModelKeeper->_19)
                        setNeedSetBaseMtxAndCalcAnimFlag(this, false);
                }
            }
        }

        if (mSubActorKeeper != nullptr)
            alSubActorFunction::trySyncClippingStart(mSubActorKeeper);
    }

    if (mFarLodActor != nullptr) {
        if (!isClipped(mFarLodActor))
            mFarLodActor->startClipped();
    }
}

// LiveActor::endClipped
// LiveActor::startClippedByLod
// LiveActor::endClippedByLod

void LiveActor::setGlobalYOffsetRef(f32* pOffs) {
    LiveActor* curActor = this;

    do {
        curActor->mGlobalYOffsetRef = pOffs;

        if (curActor->mModelKeeper != nullptr)
            curActor->mModelKeeper->setGlobalYOffset(pOffs);

        if (curActor->mSubActorKeeper != nullptr)
            alSubActorFunction::setGlobalYOffset(curActor->mSubActorKeeper, pOffs);

        curActor = curActor->mFarLodActor;
    } while (curActor != nullptr);
}

f32 LiveActor::getGlobalYOffset() const {
    const f32* ptr = (mGlobalYOffsetRef != nullptr ? mGlobalYOffsetRef : &mGlobalYOffset);
    return *ptr;
}

void LiveActor::setFarLodActor(LiveActor* pFarLodActor) {
    mFarLodActor = pFarLodActor;
}

void LiveActor::startFarLod() {
    if (!_140) {
        _140 = true;

        if (mFarLodActor != nullptr && isClipped(mFarLodActor) && !isClipped(this)) {
            mFarLodActor->endClipped();
            alActorSystemFunction::addToExecutorDrawImmediate(mFarLodActor);
        }

        if (_142) {
            if (mFarLodActor != nullptr && mActorPoseKeeper != nullptr)
                alLiveActorFunction::calcAnimDirect(mFarLodActor);

            if (mActorExecuteInfo != nullptr) {
                if (mActorExecuteInfo->mNumDrawerBases >= 1)
                    hideModelIfShow(this);
            }
        } else {
            startClippedByLod();
        }
    }
}

void LiveActor::endFarLod() {
    if (_140) {
        _140 = false;

        if (mFarLodActor != nullptr && !isClipped(mFarLodActor))
            mFarLodActor->startClipped();

        if (_142) {
            if (mActorPoseKeeper != nullptr)
                alLiveActorFunction::calcAnimDirect(this);

            if (mActorExecuteInfo != nullptr) {
                if (mActorExecuteInfo->mNumDrawerBases >= 1) {
                    showModelIfHide(this);

                    if (!isDead(this) && !isClipped(this))
                        alActorSystemFunction::addToExecutorDrawImmediate(this);
                }
            }
        } else {
            endClippedByLod();
        }
    }
}

// LiveActor::getBaseMtx

void LiveActor::setIsFarLodModel(bool flag) {
    mIsFarLodModel = flag;
}

SceneObjHolder* LiveActor::getSceneObjHolder() const {
    return mActorSceneInfo->sceneObjHolder;
}

CollisionDirector* LiveActor::getCollisionDirector() const {
    return mActorSceneInfo->collisionDirector;
}

AreaObjDirector* LiveActor::getAreaObjDirector() const {
    return mActorSceneInfo->areaObjDirector;
}

SceneCameraInfo* LiveActor::getSceneCameraInfo() const {
    return mActorSceneInfo->sceneCameraInfo;
}

CameraDirector_RS* LiveActor::getCameraDirector_RS() const {
    return mActorSceneInfo->cameraDirector;
}

void LiveActor::initPoseKeeper(ActorPoseKeeperBase* pPoseKeeper) {
    mActorPoseKeeper = pPoseKeeper;
}

// LiveActor::initRailKeeper

void LiveActor::initCollider(f32 radius, f32 offsetY, u32 numHitInfos) {
    mCollider = new Collider(getCollisionDirector(), getBaseMtx(), &getTrans(this),
                             &getGravity(this), radius, offsetY, numHitInfos);
    mActorFlags->isNoCollide = false;
}

void LiveActor::initShadowKeeper(ShadowKeeper* pShadowKeeper) {
    mShadowKeeper = pShadowKeeper;
}

// LiveActor::initItemKeeper

void LiveActor::initScoreKeeper() {
    mScoreKeeper = new ActorScoreKeeper();
}

void LiveActor::initActorPrePassLightKeeper(ActorPrePassLightKeeper* pLightKeeper) {
    mLightKeeper = pLightKeeper;
}

void LiveActor::initSubActorKeeper(SubActorKeeper* pSubActorKeeper) {
    mSubActorKeeper = pSubActorKeeper;
    setSubActorAlphaPtr(this, &mGlobalAlphaLastFrame);
}

void LiveActor::initSceneInfo(ActorSceneInfo* pSceneInfo) {
    mActorSceneInfo = pSceneInfo;
}

// LiveActor::initActorAlphaCtrl

void LiveActor::setCollision(bool isValidate) {
    if (isValidate) {
        if (mCollisionParts != nullptr)
            validateCollisionPartsBySystem(this);
    } else {
        if (mCollider != nullptr)
            mCollider->onInvalidate();

        if (mCollisionParts != nullptr)
            invalidateCollisionPartsBySystem(this);
    }
}

void LiveActor::control() {
    return;
}

// LiveActor::updateCollider

void LiveActor::setPlacementHolder(const ActorInitInfo& rInfo) {
    mPlacementHolder->init(*rInfo.mPlacementInfo);
}

void LiveActor::setGlobalAlphaPtr(f32* pAlphaPtr) {
    if (mModelKeeper != nullptr)
        mModelKeeper->setGlobalAlpha(pAlphaPtr);

    if (mSubActorKeeper != nullptr)
        setSubActorAlphaPtr(this, pAlphaPtr);
}
}  // namespace al
