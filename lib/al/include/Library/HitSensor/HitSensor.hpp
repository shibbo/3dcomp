#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include <nn/os.h>
#include <basis/seadTypes.h>

namespace al {
    class LiveActor;
    class SensorHitGroup;
    class HitSensor;

    using SensorSortCmpFunc = bool (*)(al::HitSensor* a, al::HitSensor* b);

    class HitSensor {
    public:
        HitSensor(LiveActor*, const char*, u32, f32, u16, const sead::Vector3f*,
                  const sead::Matrix34f*, const sead::Vector3f&);

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

        const char* mName;  // 0x00
        sead::Vector3f _8;
        f32 _14;
        f32 mRadius;                  // 0x18
        u16 mMaxNumSensors;           // 0x1C
        u16 mNumSensors;              // 0x1E
        HitSensor** mSensors;         // 0x20
        SensorSortCmpFunc* mCmpFunc;  // 0x28
        SensorHitGroup* mHitGroup;    // 0x30
        bool _38;
        bool _39;
        LiveActor* mHostActor;                 // 0x40
        const sead::Vector3f* mFollowPosVec;   // 0x48
        const sead::Matrix34f* mFollowPosMtx;  // 0x50
        sead::Vector3f mFollowPosOffset;       // 0x58
        u32 _64;
        nn::os::Tick mTime;  // 0x68
    };
};  // namespace al