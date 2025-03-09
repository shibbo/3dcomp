#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Project/Collision/CollisionPartsTriangle.hpp"

namespace al {

class HitInfo {
public:
    HitInfo();

    Triangle mTriangle;
    u32 _6c;
    sead::Vector3f mPos;
    u8 _7c[0x9C - 0x7C];
};
}  // namespace al
