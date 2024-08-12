#pragma once

#include "math/seadMathBase.h"

namespace sead {
    template <typename T>
    class Vector2 : public BaseVec2<T> {
    public:
        Vector2();
    };

    template <typename T>
    class Vector3 : public BaseVec3<T> {
    public:
        Vector3() {}

        Vector3(T _x, T _y, T _z) { set(_x, _y, _z); }

        friend Vector3 operator*(const Vector3& rBase, T scalar) {
            Vector3 out;
            multScalar(out, rBase, scalar);
            return out;
        }

        friend Vector3 operator+(const Vector3& a, const Vector3& b) {
            Vector3 o;
            add(o, a, b);
            return o;
        }

        Vector3<T>& operator+=(const Vector3& other) {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;
            return *this;
        }

        Vector3<T>& operator/=(const Vector3& other) {
            this->x /= other.x;
            this->y /= other.y;
            this->z /= other.z;
            return *this;
        }

        inline void set(T _x, T _y, T _z) {
            this->x = _x;
            this->y = _y;
            this->z = _z;
        }

        inline void mult(const BaseMtx34<T>& rMtx) { sead::Vector3<T>::mult(*this, rMtx, *this); }

        inline void rotate(const BaseMtx34<T>& rMtx) {
            sead::Vector3<T>::rotate(*this, rMtx, *this);
        }

        inline void scale(T scalar) {
            this->x *= scalar;
            this->y *= scalar;
            this->z *= scalar;
        }

        inline void set(const Vector3<T>& rOther) {
            this->x = rOther.x;
            this->y = rOther.y;
            this->z = rOther.z;
        }

        inline void div(const Vector3<T>& rOther) {
            this->x /= rOther.x;
            this->y /= rOther.y;
            this->z /= rOther.z;
        }

        static inline void multScalar(Vector3<T>& rOut, const Vector3<T>& rLhs, T scalar) {
            rOut.x = rLhs.x * scalar;
            rOut.y = rLhs.y * scalar;
            rOut.z = rLhs.z * scalar;
        }

        static inline void add(Vector3<T>& rOut, const Vector3<T>& rLhs, const Vector3<T>& rRhs) {
            rOut.x = rLhs.x + rRhs.x;
            rOut.y = rLhs.y + rRhs.y;
            rOut.z = rLhs.z + rRhs.z;
        }

        static inline void mult(Vector3<T>& rOut, const BaseMtx34<T>& rMtx,
                                const Vector3<T>& rVec) {
            const Vector3<T> temp = rVec;
            rOut.x = rMtx.m[0][0] * temp.x + rMtx.m[0][1] * temp.y + rMtx.m[0][2] * temp.z +
                     rMtx.m[0][3];
            rOut.y = rMtx.m[1][0] * temp.x + rMtx.m[1][1] * temp.y + rMtx.m[1][2] * temp.z +
                     rMtx.m[1][3];
            rOut.z = rMtx.m[2][0] * temp.x + rMtx.m[2][1] * temp.y + rMtx.m[2][2] * temp.z +
                     rMtx.m[2][3];
        }

        static inline void rotate(Vector3<T>& rOut, const BaseMtx34<T>& rMtx,
                                  const Vector3<T>& rVec) {
            const Vector3<T> temp = rVec;
            rOut.x = rMtx.m[0][0] * temp.x + rMtx.m[0][1] * temp.y + rMtx.m[0][2] * temp.z;
            rOut.y = rMtx.m[1][0] * temp.x + rMtx.m[1][1] * temp.y + rMtx.m[1][2] * temp.z;
            rOut.z = rMtx.m[2][0] * temp.x + rMtx.m[2][1] * temp.y + rMtx.m[2][2] * temp.z;
        }

        static Vector3<T> zero;
        static const Vector3<T> ez;
    };

    typedef sead::Vector3<float> Vector3f;
};  // namespace sead