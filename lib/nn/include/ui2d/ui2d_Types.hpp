#pragma once

#include "font/font_Util.hpp"
#include "types.hpp"

namespace nn {
    namespace ui2d {
        /* these are already defined in nn::font */
#define NN_UI2D_RUNTIME_TYPEINFO_ROOT NN_FONT_RUNTIME_TYPEINFO_ROOT
#define NN_UI2D_RUNTIME_TYPEINFO NN_FONT_RUNTIME_TYPEINFO

        struct Size {
            f32 mWidth;
            f32 mHeight;
        };
    };  // namespace ui2d
};  // namespace nn