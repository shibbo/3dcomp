#pragma once

#include <math/seadVector.h>
#include <basis/seadTypes.h>

namespace al {
    class LiveActor;

    void resetPosition(LiveActor*, bool);

    void initActorPoseTQSV(LiveActor*);
};  // namespace al