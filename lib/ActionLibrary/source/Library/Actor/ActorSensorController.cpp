#include "Library/Actor/ActorSensorController.hpp"
#include "Library/Actor/ActorSensorUtil.hpp"

namespace al {
    ActorSensorController::ActorSensorController(LiveActor *pHost, const char *pName) {
        HitSensor* sensor = al::getHitSensor(pHost, pName);
        mSensor = sensor;
        mSensorRadius = sensor->mRadius;
        _C.x = sensor->_58.x;
        _C.y = sensor->_58.y;
        _C.z = sensor->_58.z;
    }

    void ActorSensorController::setSensorScale(f32 scalar) {
        setSensorRadius(mSensorRadius * scalar);
        HitSensor* sensor = mSensor;
        f32 x = _C.x * scalar;
        f32 y = _C.y * scalar;
        f32 z = _C.z * scalar;
        sensor->_58.set(x, y, z);
    }

    void ActorSensorController::setSensorRadius(f32 radius) {
        mSensor->mRadius = radius;
    }

    void ActorSensorController::setSensorFollowPosOffset(const sead::Vector3f &rVector) {
        mSensor->_58 = rVector;
    }
    
    /* tiny regswap on the sensor load */
    void ActorSensorController::resetActorSensorController() {
        setSensorRadius(mSensorRadius);
        setSensorFollowPosOffset(_C);
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