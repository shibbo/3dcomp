#include "Library/HitSensor/SensorHitGroup.hpp"
#include "Library/HitSensor/HitSensor.hpp"

namespace al {
    SensorHitGroup::SensorHitGroup(int maxSensors, const char *pName) {
        mMaxSize = maxSensors;
        mCurSize = 0;
        mSensors = new HitSensor*[maxSensors];

        for (int i = 0; i < mMaxSize; i++) {
            mSensors[i] = nullptr;
        }
    }

    void SensorHitGroup::add(HitSensor *pSensor) {
        mSensors[mCurSize] = pSensor;
        mCurSize++;
    }

    /*
    void SensorHitGroup::remove(HitSensor *pSensor) {
        if (mCurSize < 1) {
            return;
        }

        HitSensor** sensors = mSensors;
        int idx = 0;

        while (*(sensors++) != pSensor) {
            if (idx++ >= mCurSize) {
                return;
            }
         }

        *sensors = mSensors[idx];
        mCurSize--;
    }*/
   
    HitSensor* SensorHitGroup::getSensor(int idx) const {
        return mSensors[idx];
    }

    void SensorHitGroup::clear() const {
        for (int i = 0; i < mCurSize; i++) {
            mSensors[i]->mNumSensors = 0;
        }
    }

    // al::SensorHitGroup::executeHitCheckGroup
    // al::SensorHitGroup::executeHitCheck
    // al::SensorHitGroup::executeHitCheckInSameGroup
};