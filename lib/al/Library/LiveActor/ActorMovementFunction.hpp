#pragma once

#include <seadTypes.h>

namespace al {
    class LiveActor;

    void addVelocityToGravity(LiveActor*, f32);

    void scaleVelocity(LiveActor*, f32);
};  // namespace al