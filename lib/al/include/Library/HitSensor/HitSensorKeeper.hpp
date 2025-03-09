#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include <nn/os.h>

namespace al {
class LiveActor;
class HitSensor;

class HitSensorKeeper {
public:
    HitSensorKeeper(s32);

    HitSensor* addSensor(LiveActor*, const char*, u32, f32, u16, const sead::Vector3f*,
                         const sead::Matrix34f*, const sead::Vector3f&);
    void update();
    void attackSensor();
    HitSensor* getSensor(s32) const;
    void clear();
    void validate();
    void invalidate();
    void validateBySystem();
    void invalidateBySystem();
    HitSensor* getSensor(const char*) const;

    s32 mMaxSensorCount;
    s32 mSensorCount;
    HitSensor** mSensors;
};
}  // namespace al
