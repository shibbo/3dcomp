#pragma once

#include <arm_neon.h>
#include <cmath>
#include "types.hpp"
#include "util/detail/util_ArithmeticImpl.hpp"
#include "util/detail/util_ConstantImpl.hpp"
#include "util/util_MathTypes.hpp"

namespace nn {
    namespace util {

        const float32x4_t Vector4fValueOne = {1.f, 1.f, 1.f, 1.f};
        const float32x4_t Vector4fValueOneWZero = {1.f, 1.f, 1.f, 0.f};

        const float32x4_t Vector4fValueNegativeOne = {-1.f, -1.f, -1.f, -1.f};

        const float32x4_t Vector4fValueR8G8B8A8 = {255.f, 255.f, 255.f, 255.f};
        const float32x4_t Vector4fValue0Point5 = {0.5f, 0.5f, 0.5f, 0.5f};

        NN_FORCEINLINE float32x4_t Vector4fMultiplySubtract(float32x4_t vector1,
                                                            float32x4_t vector2,
                                                            float32x4_t vector3);
        NN_FORCEINLINE float32x4_t Vector4fMultiplySubtract(float32x4_t vector1,
                                                            float32x4_t vector2, float factor);

        NN_FORCEINLINE float32x4_t Vector4fLoad(const Uint8x4& source) {
            uint32x2_t vLow = vcreate_u32(static_cast<uint64_t>(source.v[0]) |
                                          static_cast<uint64_t>(source.v[1]) << 32);
            uint32x2_t vHigh = vcreate_u32(static_cast<uint64_t>(source.v[2]) |
                                           static_cast<uint64_t>(source.v[3]) << 32);

            return vcombine_f32(vcvt_f32_u32(vLow), vcvt_f32_u32(vHigh));
        }

        NN_FORCEINLINE float32x4_t Vector4fLoad(const Unorm8x4& source) {
            uint32x2_t vLow = vcreate_u32(static_cast<uint64_t>(source.v[0]) |
                                          static_cast<uint64_t>(source.v[1]) << 32);
            uint32x2_t vHigh = vcreate_u32(static_cast<uint64_t>(source.v[2]) |
                                           static_cast<uint64_t>(source.v[3]) << 32);

            float32x4_t v = vcombine_f32(vcvt_f32_u32(vLow), vcvt_f32_u32(vHigh));
            float32x4_t vInvMax = vdupq_n_f32(1.0f / 255.0f);

            return vmulq_f32(v, vInvMax);
        }

        NN_FORCEINLINE float32x4_t Vector4fSet(float32_t x, float32_t y, float32_t z, float32_t w) {
            float32x2_t vLow =
                vcreate_f32(static_cast<uint64_t>(*reinterpret_cast<uint32_t*>(&x)) |
                            static_cast<uint64_t>(*reinterpret_cast<uint32_t*>(&y)) << 32);
            float32x2_t vHigh =
                vcreate_f32(static_cast<uint64_t>(*reinterpret_cast<uint32_t*>(&z)) |
                            static_cast<uint64_t>(*reinterpret_cast<uint32_t*>(&w)) << 32);

            return vcombine_f32(vLow, vHigh);
        }

        NN_FORCEINLINE float32x4_t Vector4fSetElement(float32x4_t vector, int index,
                                                      float32_t value) {
            vector[index] = value;
            return vector;
        }

        NN_FORCEINLINE float32x4_t Vector4fSetX(float32x4_t vector, float32_t value) {
            return vsetq_lane_f32(value, vector, 0);
        }

        NN_FORCEINLINE float32x4_t Vector4fSetY(float32x4_t vector, float32_t value) {
            return vsetq_lane_f32(value, vector, 1);
        }

        NN_FORCEINLINE float32x4_t Vector4fSetZ(float32x4_t vector, float32_t value) {
            return vsetq_lane_f32(value, vector, 2);
        }

        NN_FORCEINLINE float32x4_t Vector4fSetW(float32x4_t vector, float32_t value) {
            return vsetq_lane_f32(value, vector, 3);
        }

        NN_FORCEINLINE float32_t Vector4fGetX(float32x4_t vector) {
            return vgetq_lane_f32(vector, 0);
        }

        NN_FORCEINLINE float32_t Vector4fGetY(float32x4_t vector) {
            return vgetq_lane_f32(vector, 1);
        }

        NN_FORCEINLINE float32_t Vector4fGetZ(float32x4_t vector) {
            return vgetq_lane_f32(vector, 2);
        }

        NN_FORCEINLINE float32_t Vector4fGetW(float32x4_t vector) {
            return vgetq_lane_f32(vector, 3);
        }

        NN_FORCEINLINE float32x4_t Vector4fZero() {
            return vdupq_n_f32(0);
        }

        NN_FORCEINLINE float32x4_t Vector4fMultiplyAdd(float32x4_t vector1, float32x4_t vector2,
                                                       float32x4_t vector3) {
            return vfmaq_f32(vector1, vector2, vector3);
        }

        NN_FORCEINLINE float32x4_t Vector4fMultiplyAdd(float32x4_t vector1, float32x4_t vector2,
                                                       float factor) {
            return vfmaq_n_f32(vector1, vector2, factor);
        }

        NN_FORCEINLINE float32x4_t Vector4fRound(float32x4_t vector) {
            uint32x4_t vGreaterEqualZero = vcgeq_f32(vector, Vector4fZero());
            float32x4_t vFactor =
                vbslq_f32(vGreaterEqualZero, vdupq_n_f32(0.5f), vdupq_n_f32(-0.5f));
            float32x4_t vTmp = vaddq_f32(vector, vFactor);
            int32x4_t vTmp2 = vcvtq_s32_f32(vTmp);

            return vcvtq_f32_s32(vTmp2);
        }

        NN_FORCEINLINE float32x4_t Vector4fModPi(float32x4_t vector) {
            float32x4_t vVectorDivided2Pi =
                vmulq_f32(vector, vdupq_n_f32(nn::util::detail::Float1Divided2Pi));
            float32x4_t vRoundedQuotient = Vector4fRound(vVectorDivided2Pi);
            float32x4_t vFloat2Pi = vdupq_n_f32(nn::util::detail::Float2Pi);

            return Vector4fMultiplySubtract(vector, vRoundedQuotient, vFloat2Pi);
        }

        NN_FORCEINLINE float32x4_t Vector4fSin(float32x4_t vector) {
            float32x4_t v = Vector4fModPi(vector);

            float32x4_t vPositiveFloatPiDivided2 = vdupq_n_f32(nn::util::detail::FloatPiDivided2);
            uint32x4_t vGreaterThanPositiveFloatPiDivided2 = vcgtq_f32(v, vPositiveFloatPiDivided2);
            float32x4_t vTmp1 = vsubq_f32(vdupq_n_f32(nn::util::detail::FloatPi), v);

            v = vbslq_f32(vGreaterThanPositiveFloatPiDivided2, vTmp1, v);

            float32x4_t vNegativeFloatPiDivided2 = vdupq_n_f32(-nn::util::detail::FloatPiDivided2);
            uint32x4_t vLessThanNegativeFloatPiDivided2 = vcltq_f32(v, vNegativeFloatPiDivided2);
            float32x4_t vTmp2 = vsubq_f32(vdupq_n_f32(-nn::util::detail::FloatPi), v);

            v = vbslq_f32(vLessThanNegativeFloatPiDivided2, vTmp2, v);

            float32x4_t vv = vmulq_f32(v, v);

            float32x4_t vResult = vdupq_n_f32(-nn::util::detail::SinCoefficients[0]);
            vResult =
                Vector4fMultiplyAdd(vdupq_n_f32(nn::util::detail::SinCoefficients[1]), vResult, vv);
            vResult = Vector4fMultiplyAdd(vdupq_n_f32(-nn::util::detail::SinCoefficients[2]),
                                          vResult, vv);
            vResult =
                Vector4fMultiplyAdd(vdupq_n_f32(nn::util::detail::SinCoefficients[3]), vResult, vv);
            vResult = Vector4fMultiplyAdd(vdupq_n_f32(-nn::util::detail::SinCoefficients[4]),
                                          vResult, vv);
            vResult = Vector4fMultiplyAdd(Vector4fValueOne, vResult, vv);
            vResult = vmulq_f32(vResult, v);

            return vResult;
        }

        NN_FORCEINLINE float32x4_t Vector4fMultiplySubtract(float32x4_t vector1,
                                                            float32x4_t vector2,
                                                            float32x4_t vector3) {
            return vfmsq_f32(vector1, vector2, vector3);
        }

        NN_FORCEINLINE float32x4_t Vector4fMultiplySubtract(float32x4_t vector1,
                                                            float32x4_t vector2, float factor) {
            return vfmsq_n_f32(vector1, vector2, factor);
        }

        NN_FORCEINLINE void Vector4fSinCos(float32x4_t* pOutSin, float32x4_t* pOutCos,
                                           float32x4_t vector) {
            float32x4_t v = Vector4fModPi(vector);
            float32x4_t vSign = Vector4fValueOne;
            float32x4_t vNegativeSign = Vector4fValueNegativeOne;

            float32x4_t vPositiveFloatPiDivided2 = vdupq_n_f32(nn::util::detail::FloatPiDivided2);
            uint32x4_t vGreaterThanPositiveFloatPiDivided2 = vcgtq_f32(v, vPositiveFloatPiDivided2);
            float32x4_t vTmp1 = vsubq_f32(vdupq_n_f32(nn::util::detail::FloatPi), v);

            v = vbslq_f32(vGreaterThanPositiveFloatPiDivided2, vTmp1, v);
            vSign = vbslq_f32(vGreaterThanPositiveFloatPiDivided2, vNegativeSign, vSign);

            float32x4_t vNegativeFloatPiDivided2 = vdupq_n_f32(-nn::util::detail::FloatPiDivided2);
            uint32x4_t vLessThanNegativeFloatPiDivided2 = vcltq_f32(v, vNegativeFloatPiDivided2);
            float32x4_t vTmp2 = vsubq_f32(vdupq_n_f32(-nn::util::detail::FloatPi), v);

            v = vbslq_f32(vLessThanNegativeFloatPiDivided2, vTmp2, v);
            vSign = vbslq_f32(vLessThanNegativeFloatPiDivided2, vNegativeSign, vSign);

            float32x4_t vv = vmulq_f32(v, v);

            float32x4_t vSin = vdupq_n_f32(-nn::util::detail::SinCoefficients[0]);
            vSin = Vector4fMultiplyAdd(vdupq_n_f32(nn::util::detail::SinCoefficients[1]), vSin, vv);
            vSin =
                Vector4fMultiplyAdd(vdupq_n_f32(-nn::util::detail::SinCoefficients[2]), vSin, vv);
            vSin = Vector4fMultiplyAdd(vdupq_n_f32(nn::util::detail::SinCoefficients[3]), vSin, vv);
            vSin =
                Vector4fMultiplyAdd(vdupq_n_f32(-nn::util::detail::SinCoefficients[4]), vSin, vv);
            vSin = Vector4fMultiplyAdd(Vector4fValueOne, vSin, vv);
            vSin = vmulq_f32(vSin, v);

            *pOutSin = vSin;

            float32x4_t vCos = vdupq_n_f32(-nn::util::detail::CosCoefficients[0]);
            vCos = Vector4fMultiplyAdd(vdupq_n_f32(nn::util::detail::CosCoefficients[1]), vCos, vv);
            vCos =
                Vector4fMultiplyAdd(vdupq_n_f32(-nn::util::detail::CosCoefficients[2]), vCos, vv);
            vCos = Vector4fMultiplyAdd(vdupq_n_f32(nn::util::detail::CosCoefficients[3]), vCos, vv);
            vCos =
                Vector4fMultiplyAdd(vdupq_n_f32(-nn::util::detail::CosCoefficients[4]), vCos, vv);
            vCos = Vector4fMultiplyAdd(Vector4fValueOne, vCos, vv);
            vCos = vmulq_f32(vSign, vCos);

            *pOutCos = vCos;
        }

        NN_FORCEINLINE void Vector4fStore(Uint8x4* pOutValue, float32x4_t source) {
            float32x4_t v = vminq_f32(source, Vector4fValueR8G8B8A8);
            v = vmaxq_f32(v, Vector4fZero());
            v = vaddq_f32(v, Vector4fValue0Point5);

            pOutValue->v[0] = static_cast<uint8_t>(::std::floor(vgetq_lane_f32(v, 0)));
            pOutValue->v[1] = static_cast<uint8_t>(::std::floor(vgetq_lane_f32(v, 1)));
            pOutValue->v[2] = static_cast<uint8_t>(::std::floor(vgetq_lane_f32(v, 2)));
            pOutValue->v[3] = static_cast<uint8_t>(::std::floor(vgetq_lane_f32(v, 3)));
        }

        NN_FORCEINLINE void Vector4fStore(Unorm8x4* pOutValue, float32x4_t source) {
            float32x4_t v = vminq_f32(source, Vector4fValueOne);
            v = vmaxq_f32(v, Vector4fZero());
            v = Vector4fMultiplyAdd(Vector4fValue0Point5, v, Vector4fValueR8G8B8A8);

            pOutValue->v[0] = static_cast<uint8_t>(::std::floor(vgetq_lane_f32(v, 0)));
            pOutValue->v[1] = static_cast<uint8_t>(::std::floor(vgetq_lane_f32(v, 1)));
            pOutValue->v[2] = static_cast<uint8_t>(::std::floor(vgetq_lane_f32(v, 2)));
            pOutValue->v[3] = static_cast<uint8_t>(::std::floor(vgetq_lane_f32(v, 3)));
        }

        NN_FORCEINLINE void Vector4fStore(float32_t* pOutValue, float32x4_t source) {
            vst1q_f32(pOutValue, source);
        }

        NN_FORCEINLINE void Vector4fStore(Float4* pOutValue, float32x4_t source) {
            Vector4fStore(pOutValue->v, source);
        }
    };  // namespace util
};  // namespace nn