#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
class HitSensor;
class KCollisionServer;

class CollisionParts {
public:
    void invalidateBySystem();

    void validateBySystem();

    u8 _0[0x58];
    sead::Matrix34f mBaseMtx;
    sead::Matrix34f mBaseInvMtx;
    sead::Matrix34f mPrevBaseMtx;
    sead::Matrix34f _e8;
    sead::Vector3f _118;
    f32 _124;
    f32 _128;
    f32 _12c;
    KCollisionServer* mKColServer;
    HitSensor* mSensor;
    u32 _140;
    u32 _144;
    u32 _148;
    u32 _14c;
    u32 _150;
    u32 _154;
    f32 _158;
    f32 _15c;
    u8 _160;
    u8 _161;
    u8 _162;
    u8 _163;
    u8 _164;
    u8 _165;
};
}  // namespace al
