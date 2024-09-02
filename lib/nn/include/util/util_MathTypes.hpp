#pragma once

#include "types.hpp"

namespace nn {
    namespace util {

        struct Uint8x4 {
            uint8_t v[4];
        };

        struct Unorm8x4 {
            uint8_t v[4];
        };

        struct Float3 {
            union {
                float v[3];

                struct {
                    float x;
                    float y;
                    float z;
                };
            };
        };

        struct Float4 {
            union {
                float v[4];

                struct {
                    float x;
                    float y;
                    float z;
                    float w;
                };
            };
        };

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

#include <arm_neon.h>

        /* game uses the neon target so let's use the neon structs */
        /* the normal sdk does a lot of layering bullshit we will not do */
        struct Vector2fType {
            float32x2_t _v;
        };

        struct Vector3fType {
            float32x4_t _v;
        };

        struct Vector4fType {
            float32x4_t _v;
        };

        struct MatrixRowMajor3x2fType {
            float32x2x3_t _m;
        };

        struct MatrixRowMajor4x3fType {
            float32x4x4_t _m;
        };

        struct MatrixRowMajor4x4fType {
            float32x4x4_t _m;
        };

        struct MatrixColumnMajor3x2fType {
            float32x4x2_t _m;
        };

        struct MatrixColumnMajor4x3fType {
            float32x4x3_t _m;
        };

        struct MatrixColumnMajor4x4fType {
            float32x4x4_t _m;
        };

        typedef MatrixRowMajor3x2fType Matrix3x2fType;
        typedef MatrixRowMajor4x3fType Matrix4x3fType;
        typedef MatrixRowMajor4x4fType Matrix4x4fType;

        typedef MatrixColumnMajor3x2fType MatrixT3x2fType;
        typedef MatrixColumnMajor4x3fType MatrixT4x3fType;
        typedef MatrixColumnMajor4x4fType MatrixT4x4fType;
    };  // namespace util
};  // namespace nn