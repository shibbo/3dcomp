#include "Library/Action/ActionSeCtrl.hpp"
#include "Library/Action/ActorActionKeeper.hpp"
#include "Library/Actor/ActorAlphaCtrl.hpp"
#include "Library/Actor/ActorPoseFunction.hpp"
#include "Library/Actor/ActorPrePassLightKeeper.hpp"
#include "Library/Audio/AudioKeeper.hpp"
#include "Library/Clipping/ClippingFunction.hpp"
#include "Library/Clipping/ClippingUtil.hpp"
#include "Library/Collision/Collider.hpp"
#include "Library/Collision/CollisionParts.hpp"
#include "Library/Collision/CollisionUtil.hpp"
#include "Library/Effect/EffectKeeper.hpp"
#include "Library/Execute/ActorExecuteInfo.hpp"
#include "Library/Execute/ActorSystemFunction.hpp"
#include "Library/HitSensor/HitSensorKeeper.hpp"
#include "Library/LiveActor/LiveActor.hpp"
#include "Library/LiveActor/ActorPoseUtil.hpp"
#include "Library/LiveActor/LiveActorFlag.hpp"
#include "Library/LiveActor/LiveActorUtil.hpp"
#include "Library/LiveActor/LiveActorFunction.hpp"
#include "Library/Model/ModelKeeper.hpp"
#include "Library/Model/ModelUtil.hpp"
#include "Library/Placement/PlacementHolder.hpp"
#include "Library/Screen/ScreenPointKeeper.hpp"
#include "Library/Shadow/ShadowKeeper.hpp"

namespace al {
    LiveActor::LiveActor(const char *pName) : mActorName(pName) {
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

        if (mLightKeeper != nullptr) {
            mLightKeeper->initAfterPlacement();
        }
    }

    void LiveActor::appear() {
        makeActorAppeared();

        if (mActionKeeper != nullptr) {
            if (mActionKeeper->mSeCtrl != nullptr) {
                mActionKeeper->mSeCtrl->resetAction();
            }
        }
    }

    void LiveActor::reappear() {

    }

    void LiveActor::makeActorAppeared() {
        if (mHitSensorKeeper != nullptr) {
            mHitSensorKeeper->validateBySystem();
        }

        if (mScreenPointKeeper != nullptr) {
            mScreenPointKeeper->validateBySystem();
        }

        mActorFlags->mIsDead = false;

        if (al::isClipped(this)) {
            endClipped();
        }

        if (!al::isHideModel(this)) {
            if (mModelKeeper != nullptr) {
                mModelKeeper->show();
            }
        }

        al::resetPosition(this, false);

        if (mCollisionParts != nullptr) {
            al::validateCollisionPartsBySystem(this);
        }

        if (mHitSensorKeeper != nullptr) {
            mHitSensorKeeper->update();
        }
 
        alClippingFunction::addToClippingTarget(this);

        if (mActorExecuteInfo != nullptr) {
            alActorSystemFunction::addToExecutorMovement(this);
            if (!al::isHideModel(this) && mActorExecuteInfo->mNumDrawerBases >= 1) {
                alActorSystemFunction::addToExecutorDraw(this);
            }
        }

        if (getAudioKeeper() != nullptr) {
            getAudioKeeper()->appear();
        }

        if (mLightKeeper != nullptr) {
            mLightKeeper->appear(al::isHideModel(this));
        }

        if (mShadowKeeper != nullptr && !al::isHideModel(this)) {
            mShadowKeeper->show();
        }

        if (mSubActorKeeper != nullptr) {
            alSubActorFunction::trySyncAlive(mSubActorKeeper);
        }
    }

    void LiveActor::kill() {
        makeActorDead();
    }
    
    void LiveActor::killComplete(bool) {
        kill();
    }

    void LiveActor::makeActorDead() {
        if (mFarLodActor != nullptr) {
            endFarLod();
        }

        if (mActorPoseKeeper != nullptr) {
            al::setVelocityZero(this);
        }

        mActorFlags->mIsDead = true;

        if (mHitSensorKeeper != nullptr) {
            mHitSensorKeeper->invalidateBySystem();
        }

        if (mScreenPointKeeper != nullptr) {
            mScreenPointKeeper->invalidateBySystem();
        }

        alClippingFunction::removeFromClippingTarget(this);

        if (mCollider != nullptr) {
            mCollider->onInvalidate();
        }

        if (mCollisionParts != nullptr) {
            al::invalidateCollisionPartsBySystem(this);
        }

        if (mModelKeeper != nullptr) {
            mModelKeeper->hide();
        }

        if (getEffectKeeper() != nullptr) {
            getEffectKeeper()->deleteAndClearEffectAll();
        }

        if (getAudioKeeper() != nullptr) {
            getAudioKeeper()->kill();
        }

        if (mLightKeeper != nullptr) {
            mLightKeeper->requestKill();
        }

        if (mShadowKeeper != nullptr) {
            mShadowKeeper->hide();
        }

        if (mActorExecuteInfo != nullptr) {
            alActorSystemFunction::removeFromExecutorMovement(this);

            if (mActorExecuteInfo->mNumDrawerBases >= 1) {
                alActorSystemFunction::removeFromExecutorDraw(this);
            }
        }

        if (mSubActorKeeper != nullptr) {
            alSubActorFunction::trySyncDead(mSubActorKeeper);
        }
    }

    bool LiveActor::showActor() {
        if (mActorFlags->_1C) {
            if (al::isDead(this)) {
                return true;
            }
        }
        else {
            al::validateClipping(this);
            if (al::isDead(this)) {
                return true;
            }
        }

        if (mActorFlags->_1C && al::isClipped(this)) {
            endClipped();
        }

        if (mCollisionParts != nullptr) {
            mCollisionParts->validateBySystem();
            return true;
        }

        return true;
    }

    bool LiveActor::hideActor() {
        if (!mActorFlags->_1C && !al::isDead(this)) {
            al::invalidateClipping(this);
        }

        if (!al::isDead(this)) {
            if (!al::isClipped(this)) {
                startClipped();
            }
            
            if (mCollisionParts != nullptr) {
                mCollisionParts->invalidateBySystem();
            }
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

    void LiveActor::updateLinkedTrans(const sead::Vector3f &rVector) {
        al::setTrans(this, rVector);
    }
    
    // al::LiveActor::movementPaused

    ActorSceneInfo* LiveActor::getSceneInfo() const {
        return mActorSceneInfo;
    }

    // al::LiveActor::movement

    void LiveActor::calcAnim() {
        if (!mActorFlags->mIsDead && (!mActorFlags->mIsClipped || mActorFlags->mIsDrawClipping) && !_140) {
            if (mActorPoseKeeper != nullptr) {
                alLiveActorFunction::calcAnimDirect(this);
            }

            if (mAudioKeeper != nullptr) {
                mAudioKeeper->update();
            }
        }
    }

    bool LiveActor::modelUpdate() {
        if (mActorFlags->mIsDead) {
            return false;
        }

        if (mActorFlags->mIsClipped && !mActorFlags->mIsDrawClipping) {
            return false;
        }

        if (mAlphaCtrl != nullptr) {
            f32 alph = mAlphaCtrl->update(al::getClippingJudge(this));
            if (!al::isInvalidCliping(this)) {
                alph *= mGlobalAlpha;
            }

            mGlobalAlpha = alph;
        }

        return true;
    }

    void LiveActor::pausedModelUpdate() {
        if (modelUpdate() != false) {
            mGlobalAlphaLastFrame = mGlobalAlpha;
        }
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

    // al::LiveActor::startClipped
    // al::LiveActor::endClipped
    //al::LiveActor::startClippedByLod
    // al::LiveActor::endClippedByLod 

    void LiveActor::setGlobalYOffsetRef(f32 *pOffs) {
        LiveActor* curActor = this;
 
       do {
            curActor->mGlobalYOffset = *pOffs;

            if (curActor->mModelKeeper != nullptr) {
                curActor->mModelKeeper->setGlobalYOffset(pOffs);
            }

            if (curActor->mSubActorKeeper != nullptr) {
                alSubActorFunction::setGlobalYOffset(curActor->mSubActorKeeper, pOffs);
            }

            curActor = curActor->mFarLodActor;
       } while(curActor != nullptr);
    }

    f32 LiveActor::getGlobalYOffset() const {
        const f32* ptr = (mGlobalYOffsetRef != nullptr ? mGlobalYOffsetRef : &mGlobalYOffset);
        return *ptr;
    }

    void LiveActor::setFarLodActor(LiveActor *pFarLodActor) {
        mFarLodActor = pFarLodActor;
    }

    // al::LiveActor::startFarLod
    // al::LiveActor::endFarLod
    // al::LiveActor::getBaseMtx

    void al::LiveActor::setIsFarLodModel(bool flag) {
        mIsFarLodModel = flag;
    }

    // al::LiveActor::getSceneObjHolder
}; 