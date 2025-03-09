#pragma once

#include "Library/LiveActor/LiveActor.hpp"

namespace al {
class KeyPoseKeeper;

class FloaterMapParts : public LiveActor {
public:
    FloaterMapParts(const char*);

    virtual ~FloaterMapParts();
    virtual void init(const ActorInitInfo&);
    virtual bool receiveMsg(const SensorMsg* msg, HitSensor* self, HitSensor* other);
    virtual void control();

    void exeWait();
    void exeSink();
    void exeBack();

    KeyPoseKeeper* mKeyPoseKeeper = nullptr;
    f32 _150 = 0;
    f32 mNextKeyDist = 0;
    f32 mSinkSpeed = 5.0f;
    f32 mBackSpeed = 5.0f;
    s32 _160 = 0;
    s32 _164 = 0;
    s32 mSinkKeepTime = 10;
    s32 mMaxAccelCount = 10;
    s32 _170 = 0;
};
}  // namespace al
