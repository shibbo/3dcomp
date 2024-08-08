#pragma once

#include "Library/Area/IUseAreaObj.hpp"
#include <math/seadVector.hpp>

namespace al {
    class HitSensor;
    class LiveActor;
    class ActorInitInfo;

    class ItemDirectorBase {
    public:
        virtual void appearItem(const char *, const sead::Vector3f &, const HitSensor *, bool, bool) = 0;
        virtual void acquirerItem(const LiveActor *, const ActorInitInfo &) = 0;
        virtual void declareItem(const char *, const ActorInitInfo &) = 0;
        virtual void endInit() = 0;
    };
}; 