#include "Library/LiveActor/LiveActor.hpp"
#include "Library/LiveActor/ActorPoseUtil.hpp"
#include "Library/LiveActor/LiveActorFlag.hpp"
#include "Library/LiveActor/LiveActorUtil.hpp"
#include "Library/Placement/PlacementHolder.hpp"
#include "Library/Model/ModelKeeper.hpp"
#include "Library/Model/ModelUtil.hpp"
#include "Library/Actor/ActorPrePassLightKeeper.hpp"
#include "Library/Collision/CollisionParts.hpp"
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

    // al::LiveActor::appear

    void LiveActor::reappear() {

    }

    // al::LiveActor::makeActorAppeared

    void LiveActor::kill() {
        makeActorDead();
    }
    
    void LiveActor::killComplete(bool) {
        kill();
    }

    // al::LiveActor::makeActorDead
    // al::LiveActor::showActor

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
    // al::LiveActor::calcAnim
    // al::LiveActor::modelUpdate
    // al::LiveActor::pausedModelUpdate

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
            curActor->mGlobalYOffset = pOffs;

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
        const f32* ptr = (mGlobalYOffset != nullptr ? mGlobalYOffset : &_130);
        return *ptr;
    }

    void LiveActor::setFarLodActor(LiveActor *pFarLodActor) {
        mFarLodActor = pFarLodActor;
    }

    // al::LiveActor::startFarLod
    // al::LiveActor::endFarLod
    // al::LiveActor::getBaseMtx
    // al::LiveActor::setIsFarLodModel
    // al::LiveActor::getSceneObjHolder
}; 