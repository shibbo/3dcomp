#pragma once

#include <math/seadMatrix.hpp>

namespace sead {
    template <typename T>
    class Vector3 {
    public:

        inline void set(const Vector3<T> &rOther) {
            x = rOther.x;
            y = rOther.y;
            z = rOther.z;
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
    };

    typedef sead::Vector3<float> Vector3f;
};