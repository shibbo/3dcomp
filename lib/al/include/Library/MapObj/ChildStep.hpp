#pragma once

#include "Library/LiveActor/LiveActor.hpp"

namespace al {
class ChildStep : public LiveActor {
public:
    ChildStep(const char*, LiveActor*);

    virtual void init(const ActorInitInfo&);

    void exeWait();

    LiveActor* _148;
    sead::Vector3f _150 = sead::Vector3f::zero;
};

void createChildStep(const ActorInitInfo&, LiveActor*, bool);
}  // namespace al
