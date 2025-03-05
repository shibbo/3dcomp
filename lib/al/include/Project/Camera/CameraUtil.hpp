#pragma once

#include <math/seadVector.h>

namespace al {
    class IUseCamera;

    sead::Vector3f& getCameraPos(const IUseCamera*);

};  // namespace al