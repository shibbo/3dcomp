#pragma once

#include <arm_neon.h>
#include "math/seadMatrixCalcCommon.h"

namespace sead {
    template <typename T>
    void Matrix34CalcCommon<T>::copy(sead::Matrix34<T>& out, const sead::Matrix34<T>& other) {
        for (int i = 0; i < 3; i++) {
            vst1q_f32(out.m[i], vld1q_f32(other.m[i]));
        }
    }
};  // namespace sead