#pragma once

#include <nvn.h>
#include "gfx/detail/gfx_Declare.hpp"
#include "gfx/gfx_Variaton.hpp"
#include "nn_BitTypes.hpp"

namespace nn {
    namespace gfx {
        template <>
        struct TextureInfoImplData<ApiVariationNvn8> {
            NVNtextureBuilder nvnTextureBuilder;
            Bit8 imageStorageDimension;
            char res;
            uint16_t multisampleCount;
            Bit16 tileMode;
            char res2[2];
            uint32_t arrayLength;
            Bit32 gpuAccessFlags;
            Bit32 imageFormat;
            uint32_t width;
            uint32_t height;
            uint32_t depth;
        };
    };  // namespace gfx
};  // namespace nn