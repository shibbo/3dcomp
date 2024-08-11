#pragma once

#include <math/seadMatrix.hpp>
#include <math/seadVector.hpp>
#include <types.hpp>

namespace al {
    class HitSensor;
    class KCollisionServer;

    class CollisionParts {
    public:
        void invalidateBySystem();

        void validateBySystem();

        u8 _0[0x58];
        sead::Matrix34f mBaseMtx;               // 0x58
        sead::Matrix34f mBaseInvMtx;            // 0x88
        sead::Matrix34f mPrevBaseMtx;           // 0xB8
        sead::Matrix34f _E8;
        sead::Vector3f _118;
        f32 _124;
        f32 _128;
        f32 _12C;
        KCollisionServer* mKColServer;          // 0x130
        HitSensor* mSensor;                     // 0x138
        u32 _140;
        u32 _144;
        u32 _148;
        u32 _14C;
        u32 _150;
        u32 _154;
        f32 _158;
        f32 _15C;
        u8 _160;
        u8 _161;
        u8 _162;
        u8 _163;
        u8 _164;
        u8 _165;
    };
};