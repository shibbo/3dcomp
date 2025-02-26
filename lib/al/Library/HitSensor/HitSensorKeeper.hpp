#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include <seadTypes.h>

namespace al {
    class LiveActor;
    class HitSensor;

    class HitSensorKeeper {
    public:
        HitSensorKeeper(int);

        HitSensor* addSensor(LiveActor*, const char*, u32, f32, u16, const sead::Vector3f*,
                             const sead::Matrix34f*, const sead::Vector3f&);
        void update();
        void attackSensor();
        HitSensor* getSensor(int) const;
        void clear();
        void validate();
        void invalidate();
        void validateBySystem();
        void invalidateBySystem();
        HitSensor* getSensor(const char*) const;

        s32 mMaxSensorCount;   // 0x00
        s32 mSensorCount;      // 0x04
        HitSensor** mSensors;  // 0x08
    };
};  // namespace al