#include "Library/HitSensor/HitSensor.hpp"
#include "Library/HitSensor/SensorHitGroup.hpp"
#include <algorithm>
#include <os/os_TickApi.h>

namespace al {
    void HitSensor::trySensorSort() {
        if (mCmpFunc && mNumSensors > 1) {
            std::sort(mSensors, &mSensors[mNumSensors], *mCmpFunc);
        }
    }

    void HitSensor::setFollowPosPtr(const sead::Vector3f *pFollowPos) {
        mFollowPosVec = pFollowPos;
        mFollowPosMtx = nullptr;
    }

    void HitSensor::setFollowMtxPtr(const sead::Matrix34f *pFollowMtx) {
        mFollowPosVec = nullptr;
        mFollowPosMtx = pFollowMtx;
    }

    void HitSensor::validate() {
        if (_39 == false) {
            _39 = true;

            if (mMaxNumSensors != 0) {
                if (_38) {
                    mHitGroup->add(this);
                }
            }
        }

        mNumSensors = 0;
    }

    void HitSensor::invalidate() {
        if (_39) {
            _39 = false;

            if (mMaxNumSensors != 0) {
                if (_38) {
                    mHitGroup->remove(this);
                }
            }
        }

        mNumSensors = 0;
    }

    void HitSensor::validateBySystem() {
        if (_38 == false) {
            if (mMaxNumSensors != 0) {
                if (_39) {
                    mHitGroup->add(this);
                }
            }

            _38 = true;
            mNumSensors = 0;
        }
    }

    void HitSensor::invalidateBySystem() {
        if (_38) {
            if (mMaxNumSensors != 0) {
                if (_39) {
                    mHitGroup->remove(this);
                }
            }

            _38 = false;
            mNumSensors = 0;
        }
    }
    
    // HitSensor::HitSensor

    void HitSensor::addHitSensor(HitSensor *pSensor) {
        if (mNumSensors < mMaxNumSensors) {
            mSensors[mNumSensors] = pSensor;
            mNumSensors++;
        }
    }

    void HitSensor::setTime() {
        mTime = nn::os::GetSystemTick();
    }
};