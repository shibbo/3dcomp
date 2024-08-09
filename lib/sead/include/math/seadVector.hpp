#pragma once

#include <math/seadMatrix.hpp>

namespace sead {
    template <typename T>
    class Vector3 {
    public:
        Vector3() { }

        Vector3(T _x, T _y, T _z) {
            set(_x, _y, _z);
        }

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
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }

        inline void set(T _x, T _y, T _z) {
            x = _x;
            y = _y;
            z = _z;
        }

        inline void scale(T scalar) {
            x *= scalar;
            y *= scalar;
            z *= scalar;
        }

        inline void set(const Vector3<T> &rOther) {
            x = rOther.x;
            y = rOther.y;
            z = rOther.z;
        }

        static inline void multScalar(Vector3<T> &rOut, const Vector3<T> &rLhs, T scalar) {
            rOut.x = rLhs.x * scalar;
            rOut.y = rLhs.y * scalar;
            rOut.z = rLhs.z * scalar;
        }

        static inline void add(Vector3<T> &rOut, const Vector3<T> &rLhs, const Vector3<T> &rRhs) {
            rOut.x = rLhs.x + rRhs.x;
            rOut.y = rLhs.y + rRhs.y;
            rOut.z = rLhs.z + rRhs.z;
        }

        static inline void mult(Vector3<T> &rOut, const Matrix34<T> &rMtx, const Vector3<T> &rOther) {
            const Vector3<T> baseVec = rOther;
            rOut.x = rMtx.mMtx[0][0] * baseVec.x + rMtx.mMtx[0][1] * baseVec.y + rMtx.mMtx[0][2] * baseVec.z + rMtx.mMtx[0][3];
            rOut.y = rMtx.mMtx[1][0] * baseVec.x + rMtx.mMtx[1][1] * baseVec.y + rMtx.mMtx[1][2] * baseVec.z + rMtx.mMtx[1][3];
            rOut.z = rMtx.mMtx[2][0] * baseVec.x + rMtx.mMtx[2][1] * baseVec.y + rMtx.mMtx[2][2] * baseVec.z + rMtx.mMtx[2][3];
        }

        T x, y, z;

        static Vector3<T> zero;
        static const Vector3<T> ez;
    };

    typedef sead::Vector3<float> Vector3f;
};