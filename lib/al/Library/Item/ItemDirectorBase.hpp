#pragma once

#include <math/seadVector.h>
#include "Project/AreaObj/IUseAreaObj.hpp"

namespace al {
    class HitSensor;
    class LiveActor;
    class ActorInitInfo;

    class ItemDirectorBase {
    public:
        virtual void appearItem(const char*, const sead::Vector3f&, const sead::Vector3f&,
                                const HitSensor*, bool, bool) = 0;
        virtual void acquirerItem(const LiveActor*, HitSensor*, const char*) = 0;
        virtual void declareItem(const char*, const ActorInitInfo&) = 0;
        virtual void endInit() = 0;
    };
};  // namespace al