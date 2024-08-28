#pragma once

#include "math/seadMathBase.h"

namespace sead {
    template <typename T>
    class Matrix34 : public BaseMtx34<T> {
    public:
        Matrix34() {}

        Matrix34(T a00, T a01, T a02, T a03, T a10, T a11, T a12, T a13, T a20, T a21, T a22,
                 T a23) {
            this->m[0][0] = a00;
            this->m[0][1] = a01;
            this->m[0][2] = a02;
            this->m[0][3] = a03;

            this->m[1][0] = a10;
            this->m[1][1] = a11;
            this->m[1][2] = a12;
            this->m[1][3] = a13;

            this->m[2][0] = a20;
            this->m[2][1] = a21;
            this->m[2][2] = a22;
            this->m[2][3] = a23;
        }

        Matrix34<T>& operator=(const Matrix34<T>&);

        inline void getTrans(sead::BaseVec3<T>* pVec) const {
            pVec->x = this->m[0][3];
            pVec->y = this->m[1][3];
            pVec->z = this->m[2][3];
        }

        static Matrix34<T> ident;
    };

    typedef Matrix34<float> Matrix34f;
};  // namespace sead