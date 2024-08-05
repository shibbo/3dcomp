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

        HitSensor* mSensor = nullptr;             // 0x00
        f32 mSensorRadius = 0;                    // 0x08
        sead::Vector3f mFollowPosOffs;            // 0x0C
    };

    class ActorSensorControllerList {
    public:
        ActorSensorControllerList(int);

        void addSensor(LiveActor *, const char *);
        void setAllSensorScale(f32);
        void resetAllActorSensorController();

        ActorSensorController** mControllers;       // 0x00
        s32 mMaxControllers;                        // 0x08
        s32 mNumControllers;                        // 0x0C
    };
};