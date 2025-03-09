#pragma once

#include <math/seadVector.h>

namespace al {
class IUseCamera;

const sead::Vector3f& getCameraPos(const IUseCamera*);

}  // namespace al
