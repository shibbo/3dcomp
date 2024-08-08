#include "Library/Action/ActionSeCtrl.hpp"
#include "Library/Action/ActorActionKeeper.hpp"
#include "Library/Actor/ActorAlphaCtrl.hpp"
#include "Library/Actor/ActorInitInfo.hpp"
#include "Library/Actor/ActorPoseFunction.hpp"
#include "Library/Actor/ActorPoseKeeperBase.hpp"
#include "Library/Actor/ActorPoseUtil.hpp"
#include "Library/Actor/ActorPrePassLightKeeper.hpp"
#include "Library/Actor/ActorSceneInfo.hpp"
#include "Library/Audio/AudioKeeper.hpp"
#include "Library/Clipping/ClippingFunction.hpp"
#include "Library/Clipping/ClippingUtil.hpp"
#include "Library/Collision/Collider.hpp"
#include "Library/Collision/CollisionParts.hpp"
#include "Library/Collision/CollisionUtil.hpp"
#include "Library/Demo/DemoDirector.hpp"
#include "Library/Effect/EffectKeeper.hpp"
#include "Library/Execute/ActorExecuteInfo.hpp"
#include "Library/Execute/ActorSystemFunction.hpp"
#include "Library/HitSensor/HitSensorKeeper.hpp"
#include "Library/LiveActor/LiveActor.hpp"
#include "Library/Item/ActorScoreKeeper.hpp"
#include "Library/LiveActor/ActorPoseUtil.hpp"
#include "Library/LiveActor/LiveActorFlag.hpp"
#include "Library/LiveActor/LiveActorUtil.hpp"
#include "Library/LiveActor/LiveActorFunction.hpp"
#include "Library/LiveActor/SubActorUtil.hpp"
#include "Library/Math/MtxUtil.hpp"
#include "Library/Model/alModelCafe.hpp"
#include "Library/Model/ModelKeeper.hpp"
#include "Library/Model/ModelUtil.hpp"
#include "Library/Nerve/NerveKeeper.hpp"
#include "Library/Placement/PlacementHolder.hpp"
#include "Library/Screen/ScreenPointKeeper.hpp"
#include "Library/Shadow/ShadowKeeper.hpp" 
#include "Library/Shadow/ShadowUtil.hpp"

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

    inline void LiveActor::updateLOD() {
        bool isActiveDemo;

        if (mActorSceneInfo->mDemoDirector != nullptr) {
            isActiveDemo = mActorSceneInfo->mDemoDirector->isActiveDemo();
            if (al::isSingleMode(this)) {
                return;
            }
        }
        else {
            isActiveDemo = false;
            if (al::isSingleMode(this)) {
                return;
            }
        }

        mModelKeeper->updateLod(mActorPoseKeeper->mTranslation, isActiveDemo);
    }

    inline void LiveActor::setMaterial() {
        const char* name;

        if (al::isCollidedGround(this)) {
            name = al::getCollidedFloorMaterialCodeName(this);
        }
        else if (al::isCollidedWall(this)) {
            name = al::getCollidedWallMaterialCodeName(this);
        }
        else if (al::isCollidedCeiling(this)) {
            name = al::getCollidedCeilingMaterialCodeName(this);
        }
        else {
            return;
        }

        al::setMaterialCode(this, name);
    }

    ActorSceneInfo* LiveActor::getSceneInfo() const {
        return mActorSceneInfo;
    }

    /*
    void LiveActor::movement() {
        if (mActorFlags->mIsDead || (mActorFlags->mIsClipped && !mActorFlags->mIsDrawClipping)) {
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

            if (mActorFlags->mIsValidCeilWallFloorMatCode) {
                setMaterial();
            }

            if (mActorFlags->mIsValidMatCode) {
                if (al::isCollidedGround(this)) {
                    al::setMaterialCode(this, al::getCollidedFloorMaterialCodeName(this));
                }
            }

            HitSensorKeeper* keeper = mHitSensorKeeper;

            if (keeper != nullptr) {
                keeper->attackSensor();
            }

            if (!mActorFlags->mIsDead) {
                NerveKeeper* nerveKeeper = mNerveKeeper;
                if (nerveKeeper != nullptr, nerveKeeper->update(), !mActorFlags->mIsDead) {
                    control();

                    if (!mActorFlags->mIsDead) {
                        updateCollider();

                        if (al::isUpdateMovementEffectAudioCollision(this)) {
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
                                    al::preScaleMtx(&poseMtx, mActorPoseKeeper->getScale());
                                    al::syncCollisionMtx(this, &poseMtx);
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

    void LiveActor::startClipped() {
        mActorFlags->mIsClipped = true;

        if (!mActorFlags->mIsClippedByLOD) {
            if (mModelKeeper != nullptr) {
                mModelKeeper->hide();
            }

            if (!mActorFlags->mIsDrawClipping) {
                if (mHitSensorKeeper != nullptr) {
                    mHitSensorKeeper->invalidateBySystem();
                }

                if (getEffectKeeper() != nullptr) {
                    getEffectKeeper()->offCalcAndDraw();
                }

                if (getAudioKeeper()) {
                    getAudioKeeper()->startClipped();
                }
            }

            if (mShadowKeeper != nullptr) {
                al::hideShadow(this);
            }

            if (mScreenPointKeeper != nullptr) {
                mScreenPointKeeper->invalidateBySystem();
            }

            if (mLightKeeper != nullptr) {
                mLightKeeper->hideModel();
            }

            if (mActorExecuteInfo != nullptr) {
                if (!mActorFlags->mIsDrawClipping) {
                    alActorSystemFunction::removeFromExecutorMovement(this);
                }

                if (mActorExecuteInfo->mNumDrawerBases >= 1) {
                    alActorSystemFunction::removeFromExecutorDraw(this);
                }

                if (mActorFlags->mIsDrawClipping) {
                    if (mModelKeeper != nullptr) {
                        if (mModelKeeper->_19) {
                            al::setNeedSetBaseMtxAndCalcAnimFlag(this, false);
                        }
                    }
                }
            }

            if (mSubActorKeeper != nullptr) {
                alSubActorFunction::trySyncClippingStart(mSubActorKeeper);
            }
        }

        if (mFarLodActor != nullptr) {
            if (!al::isClipped(mFarLodActor)) {
                mFarLodActor->startClipped();
            }
        }
    }

    // al::LiveActor::endClipped
    // al::LiveActor::startClippedByLod
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

    void LiveActor::startFarLod() {
        if (!_140) {
            _140 = true;
            
            if (mFarLodActor != nullptr && al::isClipped(mFarLodActor) && !al::isClipped(this)) {
                mFarLodActor->endClipped();
                alActorSystemFunction::addToExecutorDrawImmediate(mFarLodActor);
            }

            if (_142) {
                if (mFarLodActor != nullptr && mActorPoseKeeper != nullptr) {
                    alLiveActorFunction::calcAnimDirect(mFarLodActor);
                }

                if (mActorExecuteInfo != nullptr) {
                    if (mActorExecuteInfo->mNumDrawerBases >= 1) {
                        al::hideModelIfShow(this);
                    }
                }
            }
            else {
                startClippedByLod();
            }
        }
    }

    void LiveActor::endFarLod() {
        if (_140) {
            _140 = false;

            if (mFarLodActor != nullptr && !al::isClipped(mFarLodActor)) {
                mFarLodActor->startClipped();
            }

            if (_142) {
                if (mActorPoseKeeper != nullptr) {
                    alLiveActorFunction::calcAnimDirect(this);
                }

                if (mActorExecuteInfo != nullptr) {
                    if (mActorExecuteInfo->mNumDrawerBases >= 1) {
                        al::showModelIfHide(this);

                        if (!al::isDead(this) && !al::isClipped(this)) {
                            alActorSystemFunction::addToExecutorDrawImmediate(this);
                        }
                    }
                }
            }
            else {
                endClippedByLod();
            }
        }
    }

    // al::LiveActor::getBaseMtx

    void al::LiveActor::setIsFarLodModel(bool flag) {
        mIsFarLodModel = flag;
    }

    SceneObjHolder* LiveActor::getSceneObjHolder() const {
        return mActorSceneInfo->mSceneObjHolder;
    }

    CollisionDirector* LiveActor::getCollisionDirector() const {
        return mActorSceneInfo->mCollisionDirector;
    }

    AreaObjDirector* LiveActor::getAreaObjDirector() const {
        return mActorSceneInfo->mAreaObjDirector;
    }

    SceneCameraInfo* LiveActor::getSceneCameraInfo() const {
        return mActorSceneInfo->mSceneCameraInfo;
    }

    CameraDirector_RS* LiveActor::getCameraDirector_RS() const {
        return mActorSceneInfo->mCameraDirector;
    }

    void LiveActor::initPoseKeeper(ActorPoseKeeperBase *pPoseKeeper) {
        mActorPoseKeeper = pPoseKeeper;
    }

    // al::LiveActor::initRailKeeper

    void LiveActor::initCollider(f32 radius, f32 offsetY, u32 numHitInfos) {
        mCollider = new Collider(getCollisionDirector(), getBaseMtx(), &al::getTrans(this), &al::getGravity(this), radius, offsetY, numHitInfos);
        mActorFlags->mIsNoCollide = false;
    }

    void LiveActor::initShadowKeeper(ShadowKeeper* pShadowKeeper) {
        mShadowKeeper = pShadowKeeper;
    }

    // al::LiveActor::initItemKeeper

    void LiveActor::initScoreKeeper() {
        mScoreKeeper = new ActorScoreKeeper();
    }

    void LiveActor::initActorPrePassLightKeeper(ActorPrePassLightKeeper *pLightKeeper) {
        mLightKeeper = pLightKeeper;
    }

    void LiveActor::initSubActorKeeper(SubActorKeeper *pSubActorKeeper) {
        mSubActorKeeper = pSubActorKeeper;
        al::setSubActorAlphaPtr(this, &mGlobalAlphaLastFrame);
    }

    void LiveActor::initSceneInfo(ActorSceneInfo *pSceneInfo) {
        mActorSceneInfo = pSceneInfo;
    }

    // al::LiveActor::initActorAlphaCtrl

    void LiveActor::setCollision(bool isValidate) {
        if (isValidate) {
            if (mCollisionParts != nullptr) {
                al::validateCollisionPartsBySystem(this);
            }
        }
        else {
            if (mCollider != nullptr) {
                mCollider->onInvalidate();
            }

            if (mCollisionParts != nullptr) {
                al::invalidateCollisionPartsBySystem(this);
            }
        }
    }

    void LiveActor::control() {
        return;
    }

    // al::LiveActor::updateCollider

    void LiveActor::setPlacementHolder(const ActorInitInfo &rInfo) {
        mPlacementHolder->init(*rInfo.mPlacementInfo);
    }

    void LiveActor::setGlobalAlphaPtr(f32 *pAlphaPtr) {
        if (mModelKeeper != nullptr) {
            mModelKeeper->setGlobalAlpha(pAlphaPtr);
        }

        if (mSubActorKeeper != nullptr) {
            al::setSubActorAlphaPtr(this, pAlphaPtr);
        }
    }
}; 