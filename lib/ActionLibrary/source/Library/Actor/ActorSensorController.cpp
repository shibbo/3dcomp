#include "Library/Actor/ActorSensorController.hpp"
#include "Library/Actor/ActorSensorUtil.hpp"

namespace al {
    ActorSensorController::ActorSensorController(LiveActor *pHost, const char *pName) {
        HitSensor* sensor = al::getHitSensor(pHost, pName);
        mSensor = sensor;
        mSensorRadius = sensor->mRadius;
        mFollowPosOffs.x = sensor->mFollowPosOffset.x;
        mFollowPosOffs.y = sensor->mFollowPosOffset.y;
        mFollowPosOffs.z = sensor->mFollowPosOffset.z;
    }

    void ActorSensorController::setSensorScale(f32 scalar) {
        setSensorRadius(mSensorRadius * scalar);
        HitSensor* sensor = mSensor;
        f32 x = mFollowPosOffs.x * scalar;
        f32 y = mFollowPosOffs.y * scalar;
        f32 z = mFollowPosOffs.z * scalar;
        sensor->mFollowPosOffset.set(x, y, z);
    }

    void ActorSensorController::setSensorRadius(f32 radius) {
        mSensor->mRadius = radius;
    }

    void ActorSensorController::setSensorFollowPosOffset(const sead::Vector3f &rVector) {
        mSensor->mFollowPosOffset = rVector;
    }
    
    /* tiny regswap on the sensor load */
    void ActorSensorController::resetActorSensorController() {
        setSensorRadius(mSensorRadius);
        setSensorFollowPosOffset(mFollowPosOffs);
    }

    ActorSensorControllerList::ActorSensorControllerList(int maxNum) {
        mMaxControllers = maxNum;
        mNumControllers = 0;
        mControllers = new ActorSensorController*[mMaxControllers];

        for (s32 i = 0; i < mMaxControllers; i++ ) {
            mControllers[i] = nullptr;
        }
    }

    void ActorSensorControllerList::addSensor(LiveActor *pActor, const char *pName) {
        mControllers[mNumControllers++] = new ActorSensorController(pActor, pName);
    }

    /* tiny regswap through the setSensorScale inline */
    void ActorSensorControllerList::setAllSensorScale(f32 scalar) {
        for (s32 i = 0; i < mNumControllers; i++) {
            ActorSensorController* cnt = mControllers[i];
            cnt->setSensorScale(scalar);
        }
    }

    /* tiny regswap due to issues in the inline itself */
    void ActorSensorControllerList::resetAllActorSensorController() {
        for (s32 i = 0; i < mNumControllers; i++) {
            mControllers[i]->resetActorSensorController();
        }
    }
};