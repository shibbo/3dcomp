#pragma once

#include "types.hpp"

namespace nn {
    namespace util {
        struct FloatColumnMajor4x3 {
            union {
                f32 m[3][4];

                struct {
                    f32 m00;
                    f32 m10;
                    f32 m20;
                    f32 m30;
                    f32 m01;
                    f32 m11;
                    f32 m21;
                    f32 m31;
                    f32 m02;
                    f32 m12;
                    f32 m22;
                    f32 m32;
                };
            };
        };
    };  // namespace util
};  // namespace nn