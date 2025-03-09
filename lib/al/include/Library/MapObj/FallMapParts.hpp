#pragma once

#include "Library/LiveActor/LiveActor.hpp"

namespace al {
class FallMapParts : public LiveActor {
public:
    FallMapParts(const char*);

    virtual ~FallMapParts();
    virtual void init(const ActorInitInfo&);
    virtual bool receiveMsg(const SensorMsg* msg, HitSensor* self, HitSensor* other);
    virtual void switchAppear();
    virtual void switchKill();

    void init(const ActorInitInfo&, const char*);
    void exeAppear();
    void exeWait();
    void exeFallSign();
    bool isEndFallSign() const;
    void exeFall();
    void exeEnd();

    sead::Vector3f _144 = sead::Vector3f::zero;
    s32 mFallTime = 75;
    u8 _154 = 0;
};
}  // namespace al
