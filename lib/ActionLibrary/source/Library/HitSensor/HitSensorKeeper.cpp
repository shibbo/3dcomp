#include "Library/HitSensor/HitSensorKeeper.hpp"
#include "Library/HitSensor/HitSensor.hpp"
#include "Library/LiveActor/LiveActor.hpp"
#include "Library/LiveActor/LiveActorUtil.hpp"
#include "Library/Base/StringUtil.hpp"

namespace al {
    HitSensorKeeper::HitSensorKeeper(int maxSensors) {
        mMaxSensorCount = maxSensors;
        mSensorCount = 0;
        mSensors = new HitSensor*[mMaxSensorCount];

        for (int i = 0; i < mMaxSensorCount; i++) {
            mSensors[i] = nullptr;
        }
    }

    HitSensor* HitSensorKeeper::addSensor(LiveActor *pActor, const char *pName, u32 unk, f32 range, u16 unk2, const sead::Vector3f *pFollowVec, const sead::Matrix34f *pFollowMtx, const sead::Vector3f &rOffs) {
        HitSensor* sensor = new HitSensor(pActor, pName, unk, range, unk2, pFollowVec, pFollowMtx, rOffs);
        mSensors[mSensorCount] = sensor;
        mSensorCount++;
        sensor->update();
        return sensor;
    }

    void HitSensorKeeper::update() {
        for (int i = 0; i < mSensorCount; i++) {
            mSensors[i]->update();
        }
    }

    void HitSensorKeeper::attackSensor() {
        for (int i = 0; i < mSensorCount; i++) {
            HitSensor* sensor = mSensors[i];
            sensor->trySensorSort();

            if (sensor->mNumSensors != 0) {
                for (int i = 0; i < sensor->mNumSensors; i++) {
                    HitSensor* childSensor = sensor->mSensors[i];
                    if (!al::isDead(childSensor->mHostActor)) {
                        childSensor->mHostActor->attackSensor(sensor, childSensor);
                    }
                }
            }
        }
    }

    HitSensor* HitSensorKeeper::getSensor(int idx) const {
        return mSensors[idx];
    }

    void HitSensorKeeper::clear() {
        for (int i = 0; i < mSensorCount; i++) {
            mSensors[i]->mNumSensors = 0;
        }
    }

    void HitSensorKeeper::validate() {
        for (int i = 0; i < mSensorCount; i++) {
            mSensors[i]->validate();
        }
    }

    void HitSensorKeeper::invalidate() {
        for (int i = 0; i < mSensorCount; i++) {
            mSensors[i]->invalidate();
        }
    }

    void HitSensorKeeper::validateBySystem() {
        for (int i = 0; i < mSensorCount; i++) {
            mSensors[i]->validateBySystem();
        }
    }

    void HitSensorKeeper::invalidateBySystem() {
        for (int i = 0; i < mSensorCount; i++) {
            mSensors[i]->invalidateBySystem();
        }
    }

    HitSensor* HitSensorKeeper::getSensor(const char *pName) const {
        if (mSensorCount == 1) {
            return *mSensors;
        }

        for (int i = 0; i < mSensorCount; i++) {
            if (al::isEqualString(mSensors[i]->mName, pName)) {
                return mSensors[i];
            }
        }

        return nullptr;
    }
};