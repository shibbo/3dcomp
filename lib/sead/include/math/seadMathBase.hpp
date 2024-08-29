#pragma once

namespace sead {
    /* these structs seem to be for certain common math calcluation functions, since the vector /
     * matrix types inherit from these */
    template <typename T>
    struct BaseVec2 {
        T x;
        T y;
    };

    template <typename T>
    struct BaseVec3 {
        T x;
        T y;
        T z;
    };

    template <typename T>
    struct BaseMtx33 {
        T m[3][3];
    };

    template <typename T>
    struct BaseMtx34 {
        T m[3][4];
    };

    template <typename T>
    struct BaseQuat {
        T x;
        T y;
        T z;
        T w;
    };
};  // namespace sead