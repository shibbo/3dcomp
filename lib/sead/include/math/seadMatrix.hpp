#pragma once

#include "math/seadMatrixCalcCommon.h"

namespace sead {
    template <typename T>
    inline Matrix34<T>& Matrix34<T>::operator=(const Matrix34<T>& rOther) {
        Matrix34CalcCommon<T>::copy(*this, rOther);
        return *this;
    }
};  // namespace sead