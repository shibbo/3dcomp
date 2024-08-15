#pragma once

#include "math/seadMatrix.h"

namespace sead {
    template <typename T>
    class Matrix34CalcCommon {
    public:
        static void copy(Matrix34<T>&, const Matrix34<T>&);
    };
}  // namespace sead