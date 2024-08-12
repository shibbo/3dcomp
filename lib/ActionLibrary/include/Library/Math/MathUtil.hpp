#pragma once

#include <math/seadVector.h>
#include <types.hpp>

namespace al {
    bool isNearZero(f32, f32);

    void normalizeOrZero(sead::Vector3f*);
};  // namespace al