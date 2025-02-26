#pragma once

#include <seadTypes.h>

namespace al {
    class LiveActorFlag {
    public:
        LiveActorFlag();

        bool mIsDead;             // 0x00
        bool mIsClipped;          // 0x01
        bool mIsInvalidClipping;  // 0x02
        bool mIsDrawClipping;     // 0x03
        bool mIsClippedByLOD;     // 0x04
        bool mIsOffCalcAnim;      // 0x05
        bool mIsHideModel;        // 0x06
        bool mIsNoCollide;        // 0x07
        bool _8;
        bool mIsValidMatCode;               // 0x09
        bool mIsValidCeilWallFloorMatCode;  // 0x0A
        bool mIsAreaTarget;                 // 0x0B
        bool mIsUpdMovementEffectAudioCol;  // 0x0C
        bool _D;
        bool _E;
        bool _F;
        u32 _10;
        u32 _14;
        u32 _18;
        bool _1C;
        bool mIsDeadAlive;  // 0x1D
    };
};  // namespace al