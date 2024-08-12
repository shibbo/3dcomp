#pragma once

#include <types.hpp>
#include "math/seadVector.h"

namespace sead {
    template <typename T>
    class BoundBox2 {
    public:
        Vector2<T> mMin;
        Vector2<T> mMax;
    };

    template <typename T>
    class BoundBox3 {
    public:
        inline void setMin(T val) { mMin.set(val, val, val); }

        inline void setMin(T x, T y, T z) { mMin.set(x, y, z); }

        inline void setMax(T val) { mMax.set(val, val, val); }

        inline void setMax(T x, T y, T z) { mMax.set(x, y, z); }

        Vector3<T> mMin;
        Vector3<T> mMax;
    };

    typedef BoundBox2<f32> BoundBox2f;
    typedef BoundBox3<f32> BoundBox3f;
};  // namespace sead