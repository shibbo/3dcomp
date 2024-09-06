#pragma once

#include <math/seadVector.h>
#include <types.hpp>

namespace al {
    class LiveActor;

    void resetPosition(LiveActor*, bool);

    void initActorPoseTQSV(LiveActor*);
};  // namespace al