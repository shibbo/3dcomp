#pragma once

#include "math/seadMathBase.h"

namespace sead {
    template <typename T>
    class Matrix34 : public BaseMtx34<T> {
    public:
        inline void getTrans(sead::BaseVec3<T>* pVec) const {
            pVec->x = this->m[0][3];
            pVec->y = this->m[1][3];
            pVec->z = this->m[2][3];
        }

        static Matrix34<T> ident;
    };

    typedef Matrix34<float> Matrix34f;
};  // namespace sead