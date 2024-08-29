#pragma once

#include <types.hpp>
#include "math/seadMathBase.hpp"

namespace sead {
    template <typename T>
    class Quat : public BaseQuat<T> {
    public:
        Quat& operator=(const Quat& rhs) {
            this->x = rhs.x;
            this->y = rhs.y;
            this->z = rhs.z;
            this->w = rhs.w;
            return *this;
        }

        static Quat<T> unit;
    };

    typedef Quat<f32> Quatf;
};  // namespace sead