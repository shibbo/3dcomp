#pragma once

#include <arm_neon.h>
#include "types.hpp"
#include "util/util_MathTypes.hpp"
#include "util/util_VectorApi.hpp"

namespace nn {
    namespace util {

        NN_FORCEINLINE float32x4x4_t MatrixRowMajor4x3fSetScaleRotateXyz(
            float32x4x4_t matrix, float32x4_t scale, float32x4_t rotationRadian);

        NN_FORCEINLINE float32x4x4_t MatrixRowMajor4x3fSetTranslate(float32x4x4_t matrix,
                                                                    float32x4_t translate);

        NN_FORCEINLINE void MatrixRowMajor4x3fStore(FloatColumnMajor4x3* pOutValue,
                                                    float32x4x4_t source);

        NN_FORCEINLINE void MatrixSetScaleRotateXyz(MatrixRowMajor4x3fType* pOutValue,
                                                    const Vector3fType& scale,
                                                    const Vector3fType& rotationRadian) {
            pOutValue->_m =
                MatrixRowMajor4x3fSetScaleRotateXyz(pOutValue->_m, scale._v, rotationRadian._v);
        }

        NN_FORCEINLINE void MatrixSetTranslate(MatrixRowMajor4x3fType* pOutValue,
                                               const Vector3fType& translate) {
            pOutValue->_m = MatrixRowMajor4x3fSetTranslate(pOutValue->_m, translate._v);
        }

        NN_FORCEINLINE void MatrixStore(FloatColumnMajor4x3* pOutValue,
                                        const MatrixRowMajor4x3fType& source) {
            MatrixRowMajor4x3fStore(pOutValue, source._m);
        }

        /* the sdk has a million wrappers due to the multiple variations of functions supported */
        /* we are not doing that. we are writing only the neon version */

        NN_FORCEINLINE float32x4x4_t MatrixRowMajor4x3fSetScaleRotateXyz(
            float32x4x4_t matrix, float32x4_t scale, float32x4_t rotationRadian) {
            float32x4_t vSinRadian, vCosRadian;
            Vector4fSinCos(&vSinRadian, &vCosRadian, rotationRadian);

            float sinX = Vector4fGetX(vSinRadian);
            float sinY = Vector4fGetY(vSinRadian);
            float sinZ = Vector4fGetZ(vSinRadian);
            float cosX = Vector4fGetX(vCosRadian);
            float cosY = Vector4fGetY(vCosRadian);
            float cosZ = Vector4fGetZ(vCosRadian);

            float32x4x4_t vResult;

            float32x4_t cosYcosYNegativeOne = Vector4fSet(cosY, cosY, -1.f, 0.f);
            float32x4_t cosZsinZsinY = Vector4fSet(cosZ, sinZ, sinY, 0.f);

            float32x4_t row0 = vmulq_f32(cosYcosYNegativeOne, cosZsinZsinY);
            vResult.val[0] = vmulq_n_f32(row0, Vector4fGetX(scale));

            float32x4_t sinYsinYOne = Vector4fSet(sinY, sinY, 1.f, 0.f);
            float32x4_t cosZsinZcosY = Vector4fSet(cosZ, sinZ, cosY, 0.f);
            float32x4_t sinYsinYOne_x_cosZsinZcosY = vmulq_f32(sinYsinYOne, cosZsinZcosY);

            float32x4_t sinZcosZ = Vector4fSet(sinZ, cosZ, 0.f, 0.f);
            float32x4_t NegativeOneOne = Vector4fSet(-1.f, 1.f, 0.f, 0.f);
            float32x4_t OneNegativeOne = Vector4fSet(1.f, -1.f, 0.f, 0.f);

            float32x4_t row1 = vaddq_f32(vmulq_n_f32(sinYsinYOne_x_cosZsinZcosY, sinX),
                                         vmulq_f32(NegativeOneOne, vmulq_n_f32(sinZcosZ, cosX)));
            vResult.val[1] = vmulq_n_f32(row1, Vector4fGetY(scale));

            float32x4_t row2 = vaddq_f32(vmulq_n_f32(sinYsinYOne_x_cosZsinZcosY, cosX),
                                         vmulq_f32(OneNegativeOne, vmulq_n_f32(sinZcosZ, sinX)));
            vResult.val[2] = vmulq_n_f32(row2, Vector4fGetZ(scale));

            vResult.val[3] = matrix.val[3];

            return vResult;
        }

        NN_FORCEINLINE float32x4x4_t MatrixRowMajor4x3fSetTranslate(float32x4x4_t matrix,
                                                                    float32x4_t translate) {
            float32x4x4_t vResult;
            vResult.val[0] = matrix.val[0];
            vResult.val[1] = matrix.val[1];
            vResult.val[2] = matrix.val[2];
            vResult.val[3] = translate;

            return vResult;
        }

        NN_FORCEINLINE float32x4x4_t Matrix4x4fTranspose(float32x4x4_t matrix) {
            float32x4x2_t vTmp0 = vzipq_f32(matrix.val[0], matrix.val[2]);
            float32x4x2_t vTmp1 = vzipq_f32(matrix.val[1], matrix.val[3]);
            float32x4x2_t vTranspose0 = vzipq_f32(vTmp0.val[0], vTmp1.val[0]);
            float32x4x2_t vTranspose1 = vzipq_f32(vTmp0.val[1], vTmp1.val[1]);

            float32x4x4_t vResult;
            vResult.val[0] = vTranspose0.val[0];
            vResult.val[1] = vTranspose0.val[1];
            vResult.val[2] = vTranspose1.val[0];
            vResult.val[3] = vTranspose1.val[1];

            return vResult;
        }

        NN_FORCEINLINE void MatrixRowMajor4x3fStore(FloatColumnMajor4x3* pOutValue,
                                                    float32x4x4_t source) {
            float32x4x4_t matrixT = Matrix4x4fTranspose(source);

            Vector4fStore(pOutValue->m[0], matrixT.val[0]);
            Vector4fStore(pOutValue->m[1], matrixT.val[1]);
            Vector4fStore(pOutValue->m[2], matrixT.val[2]);
        }

    };  // namespace util
};  // namespace nn