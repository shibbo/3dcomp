#include "Library/HitSensor/HitSensor.hpp"
#include "Library/HitSensor/SensorHitGroup.hpp"
#include "Library/LiveActor/LiveActor.hpp"
#include <algorithm>
#include <os/os_TickApi.hpp>

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

    #ifdef NON_MATCHING
    void HitSensor::update() {
        f32 v10, v8, v15;

        if (mFollowPosVec != nullptr) {
            const sead::Matrix34f* baseMtx = mHostActor->getBaseMtx();

            if (baseMtx != nullptr) {
                sead::Vector3f::mult(_58, *baseMtx, *mFollowPosVec);
                _8.set(*mFollowPosVec);
                v8 = ((_58.x * baseMtx->mMtx[2][0]) + (_58.y * baseMtx->mMtx[2][1])) + (_58.z * baseMtx->mMtx[2][2]);
                v10 = mFollowPosVec->z;
            }
            else {
                sead::Vector3f::add(_8, *mFollowPosVec, _58);
                v8 = mFollowPosVec->x;
                v10 = _58.z;
            }

            v15 = v8 + v10;
        }
        else {
            if (mFollowPosMtx != nullptr) {
                sead::Vector3f::mult(_8, *mFollowPosMtx, _58);
                v15 = mFollowPosMtx->mMtx[2][3] + (((_58.x * mFollowPosMtx->mMtx[2][0]) + (_58.y * mFollowPosMtx->mMtx[2][1])) + (_58.z * mFollowPosMtx->mMtx[2][2]));
            }
            else {
                return;
            }
        }

        _14 = v15;
    }
    #endif

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