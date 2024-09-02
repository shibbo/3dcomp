#pragma once

#include "util/util_MathTypes.hpp"

namespace nn {
    namespace util {
        class MatrixRowMajor4x3f : public MatrixRowMajor4x3fType {
        public:
            MatrixRowMajor4x3f(float, float, float, float, float, float, float, float, float, float,
                               float, float);
        };
    };  // namespace util
};  // namespace nn