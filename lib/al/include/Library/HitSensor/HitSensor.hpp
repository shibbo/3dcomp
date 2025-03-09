#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include <nn/os.h>

namespace al {
class LiveActor;
class SensorHitGroup;
class HitSensor;

using SensorSortCmpFunc = bool (*)(HitSensor* a, HitSensor* b);

class HitSensor {
public:
    HitSensor(LiveActor*, const char*, u32, f32, u16, const sead::Vector3f*, const sead::Matrix34f*,
              const sead::Vector3f&);

    void update();
    void addHitSensor(HitSensor*);
    void setTime();
    void trySensorSort();
    void setFollowPosPtr(const sead::Vector3f*);
    void setFollowMtxPtr(const sead::Matrix34f*);
    void validate();
    void invalidate();
    void validateBySystem();
    void invalidateBySystem();

    const char* mName;
    sead::Vector3f _8;
    f32 _14;
    f32 mRadius;
    u16 mMaxNumSensors;
    u16 mNumSensors;
    HitSensor** mSensors;
    SensorSortCmpFunc* mCmpFunc;
    SensorHitGroup* mHitGroup;
    bool _38;
    bool _39;
    LiveActor* mHostActor;
    const sead::Vector3f* mFollowPosVec;
    const sead::Matrix34f* mFollowPosMtx;
    sead::Vector3f mFollowPosOffset;
    u32 _64;
    nn::os::Tick mTime;
};

}  // namespace al
