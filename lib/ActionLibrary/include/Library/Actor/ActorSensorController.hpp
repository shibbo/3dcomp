#pragma once

#include "Library/HitSensor/HitSensor.hpp"
#include <types.hpp>
#include <math/seadVector.hpp>

namespace al {
    class LiveActor;

    class ActorSensorController {
    public:
        ActorSensorController(LiveActor *, const char *);
        
        void setSensorScale(f32);
        void setSensorRadius(f32);
        void setSensorFollowPosOffset(const sead::Vector3f &);
        void resetActorSensorController();

        HitSensor* mSensor;             // 0x00
        f32 _8;
        f32 _C;
        f32 _10;
        f32 _14;
    };

    class ActorSensorControllerList {
    public:
        ActorSensorControllerList(int);

        ActorSensorController** mControllers;       // 0x00
        s32 mMaxControllers;                        // 0x08
        s32 mNumControllers;                        // 0x0C
    };
}; 