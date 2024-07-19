#pragma once

#include <types.hpp>

namespace al {
    class LiveActor;
};

namespace alActorSystemFunction {
    void addToExecutorMovement(al::LiveActor *);
    void addToExecutorDraw(al::LiveActor *);
    void removeFromExecutorMovement(al::LiveActor *);
    void removeFromExecutorDraw(al::LiveActor *);

    void addToExecutorDrawImmediate(al::LiveActor *);    
};