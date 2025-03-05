#pragma once

#include <basis/seadTypes.h>

namespace al {
    class LiveActor;

    void addVelocityToGravity(LiveActor*, f32);

    void scaleVelocity(LiveActor*, f32);
};  // namespace al