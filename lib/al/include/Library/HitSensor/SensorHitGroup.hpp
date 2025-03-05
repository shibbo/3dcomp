#pragma once

#include <basis/seadTypes.h>

namespace al {
    class HitSensor;

    class SensorHitGroup {
    public:
        SensorHitGroup(int, const char*);

        void add(HitSensor*);
        void remove(HitSensor*);
        HitSensor* getSensor(int) const;
        void clear() const;
        void executeHitCheckGroup(SensorHitGroup*);
        void executeHitCheck(HitSensor*, HitSensor*);
        void executeHitCheckInSameGroup();

        s32 mMaxSize;          // 0x00
        s32 mCurSize;          // 0x04
        HitSensor** mSensors;  // 0x08
    };
};  // namespace al