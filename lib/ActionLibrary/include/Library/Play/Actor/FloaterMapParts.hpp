#pragma once

#include "Library/LiveActor/LiveActor.hpp"

namespace al {
    class KeyPoseKeeper;

    class FloaterMapParts : public LiveActor {
    public:
        FloaterMapParts(const char*);

        virtual ~FloaterMapParts();
        virtual void init(const ActorInitInfo&);
        virtual bool receiveMsg(const SensorMsg*, HitSensor*, HitSensor*);
        virtual void control();

        void exeWait();
        void exeSink();
        void exeBack();

        KeyPoseKeeper* mKeyPoseKeeper = nullptr;  // 0x148
        f32 _150 = 0;
        f32 mNextKeyDist = 0;   // 0x154
        f32 mSinkSpeed = 5.0f;  // 0x158
        f32 mBackSpeed = 5.0f;  // 0x15C
        s32 _160 = 0;
        s32 _164 = 0;
        s32 mSinkKeepTime = 10;   // 0x168
        s32 mMaxAccelCount = 10;  // 0x16C
        s32 _170 = 0;
    };
};  // namespace al