#include "Library/HitSensor/HitSensorKeeper.hpp"

#include "Library/HitSensor/HitSensor.hpp"
#include "Library/LiveActor/LiveActor.hpp"
#include "Library/LiveActor/LiveActorUtil.hpp"
#include "Project/Base/StringUtil.hpp"

namespace al {
HitSensorKeeper::HitSensorKeeper(s32 maxSensors) {
    mMaxSensorCount = maxSensors;
    mSensorCount = 0;
    mSensors = new HitSensor*[mMaxSensorCount];

    for (s32 i = 0; i < mMaxSensorCount; i++)
        mSensors[i] = nullptr;
}

HitSensor* HitSensorKeeper::addSensor(LiveActor* pActor, const char* pName, u32 unk, f32 range,
                                      u16 unk2, const sead::Vector3f* pFollowVec,
                                      const sead::Matrix34f* pFollowMtx,
                                      const sead::Vector3f& rOffs) {
    HitSensor* sensor =
        new HitSensor(pActor, pName, unk, range, unk2, pFollowVec, pFollowMtx, rOffs);
    mSensors[mSensorCount] = sensor;
    mSensorCount++;
    sensor->update();
    return sensor;
}

void HitSensorKeeper::update() {
    for (s32 i = 0; i < mSensorCount; i++)
        mSensors[i]->update();
}

void HitSensorKeeper::attackSensor() {
    for (s32 i = 0; i < mSensorCount; i++) {
        HitSensor* baseSensor = mSensors[i];
        baseSensor->trySensorSort();

        if (baseSensor->mNumSensors != 0) {
            for (s32 i = 0; i < baseSensor->mNumSensors; i++) {
                HitSensor* childSensor = baseSensor->mSensors[i];
                if (!isDead(childSensor->mHostActor))
                    baseSensor->mHostActor->attackSensor(baseSensor, childSensor);
            }
        }
    }
}

HitSensor* HitSensorKeeper::getSensor(s32 idx) const {
    return mSensors[idx];
}

void HitSensorKeeper::clear() {
    for (s32 i = 0; i < mSensorCount; i++)
        mSensors[i]->mNumSensors = 0;
}

void HitSensorKeeper::validate() {
    for (s32 i = 0; i < mSensorCount; i++)
        mSensors[i]->validate();
}

void HitSensorKeeper::invalidate() {
    for (s32 i = 0; i < mSensorCount; i++)
        mSensors[i]->invalidate();
}

void HitSensorKeeper::validateBySystem() {
    for (s32 i = 0; i < mSensorCount; i++)
        mSensors[i]->validateBySystem();
}

void HitSensorKeeper::invalidateBySystem() {
    for (s32 i = 0; i < mSensorCount; i++)
        mSensors[i]->invalidateBySystem();
}

HitSensor* HitSensorKeeper::getSensor(const char* pName) const {
    if (mSensorCount == 1)
        return *mSensors;

    for (s32 i = 0; i < mSensorCount; i++)
        if (isEqualString(mSensors[i]->mName, pName))
            return mSensors[i];

    return nullptr;
}
}  // namespace al
