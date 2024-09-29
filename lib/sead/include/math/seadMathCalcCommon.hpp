#pragma once

#include <cmath>
#include "math/seadMathCalcCommon.h"

namespace sead {

    template <typename T>
    inline T MathCalcCommon<T>::sin(T val) {
        return std::sin(val);
    }
};  // namespace sead