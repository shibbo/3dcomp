#pragma once

#include <basis/seadTypes.h>

namespace al {
class HitSensor;

class SensorHitGroup {
public:
    SensorHitGroup(s32, const char*);

    void add(HitSensor*);
    void remove(HitSensor*);
    HitSensor* getSensor(s32) const;
    void clear() const;
    void executeHitCheckGroup(SensorHitGroup*);
    void executeHitCheck(HitSensor*, HitSensor*);
    void executeHitCheckInSameGroup();

    s32 mMaxSize;
    s32 mCurSize;
    HitSensor** mSensors;
};
}  // namespace al
