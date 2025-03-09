#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

namespace al {
class LiveActor;
class HitSensor;

class ActorSensorController {
public:
    ActorSensorController(LiveActor*, const char*);

    void setSensorScale(f32);
    void setSensorRadius(f32);
    void setSensorFollowPosOffset(const sead::Vector3f&);
    void resetActorSensorController();

    HitSensor* mSensor = nullptr;
    f32 mSensorRadius = 0.0f;
    sead::Vector3f mFollowPosOffs = {0.0f, 0.0f, 0.0f};
};

class ActorSensorControllerList {
public:
    ActorSensorControllerList(s32);

    void addSensor(LiveActor*, const char*);
    void setAllSensorScale(f32);
    void resetAllActorSensorController();

    ActorSensorController** mSensorControllers;
    s32 mMaxControllers;
    s32 mNumControllers = 0;
};
}  // namespace al
