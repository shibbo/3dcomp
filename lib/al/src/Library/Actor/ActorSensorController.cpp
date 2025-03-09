#include "Library/Actor/ActorSensorController.hpp"

#include "Library/Actor/ActorSensorUtil.hpp"
#include "Library/HitSensor/HitSensor.hpp"

namespace al {
ActorSensorController::ActorSensorController(LiveActor* pHost, const char* pName) {
    mSensor = getHitSensor(pHost, pName);
    mSensorRadius = mSensor->mRadius;
    mFollowPosOffs = mSensor->mFollowPosOffset;
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

void ActorSensorController::setSensorFollowPosOffset(const sead::Vector3f& rVector) {
    mSensor->mFollowPosOffset.set(rVector);
}

/* tiny regswap on the sensor load */
void ActorSensorController::resetActorSensorController() {
    setSensorRadius(mSensorRadius);
    setSensorFollowPosOffset(mFollowPosOffs);
}

ActorSensorControllerList::ActorSensorControllerList(s32 maxNum) {
    mMaxControllers = maxNum;
    mSensorControllers = new ActorSensorController*[mMaxControllers];

    for (s32 i = 0; i < mMaxControllers; i++)
        mSensorControllers[i] = nullptr;
}

void ActorSensorControllerList::addSensor(LiveActor* pActor, const char* pName) {
    mSensorControllers[mNumControllers++] = new ActorSensorController(pActor, pName);
}

/* tiny regswap through the setSensorScale inline */
void ActorSensorControllerList::setAllSensorScale(f32 scalar) {
    for (s32 i = 0; i < mNumControllers; i++)
        mSensorControllers[i]->setSensorScale(scalar);
}

/* tiny regswap due to issues in the inline itself */
void ActorSensorControllerList::resetAllActorSensorController() {
    for (s32 i = 0; i < mNumControllers; i++)
        mSensorControllers[i]->resetActorSensorController();
}
}  // namespace al
