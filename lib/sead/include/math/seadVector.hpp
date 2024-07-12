#pragma once

namespace sead {
    template <typename T>
    class Vector3 {
    public:
        T x, y, z;
    };

    typedef sead::Vector3<float> Vector3f;
};