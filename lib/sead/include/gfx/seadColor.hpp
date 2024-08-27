#pragma once

#include <types.hpp>

namespace sead {
    class Color4u8 {
    public:
        u8 a;
        u8 b;
        u8 g;
        u8 r;
    };

    class Color4f {
    public:
        f32 r;
        f32 g;
        f32 b;
        f32 a;
    };
};