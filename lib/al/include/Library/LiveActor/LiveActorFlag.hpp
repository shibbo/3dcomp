#pragma once

#include <basis/seadTypes.h>

namespace al {
struct LiveActorFlag {
    LiveActorFlag();

    bool isDead;
    bool isClipped;
    bool isInvalidClipping;
    bool isDrawClipping;
    bool isClippedByLOD;
    bool isOffCalcAnim;
    bool isHideModel;
    bool isNoCollide;
    bool _8;
    bool isValidMatCode;
    bool isValidCeilWallFloorMatCode;
    bool isAreaTarget;
    bool isUpdMovementEffectAudioCol;
    bool _d;
    bool _e;
    bool _f;
    u32 _10;
    u32 _14;
    u32 _18;
    bool _1c;
    bool isDeadAlive;
};
}  // namespace al
