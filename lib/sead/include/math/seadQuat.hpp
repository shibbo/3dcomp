#pragma once

#include <types.hpp>

namespace sead {
    template<typename T>
    class Quat {
    public:
        T x;
        T y;
        T z;
        T w;
    };

    typedef Quat<f32> Quatf;
};