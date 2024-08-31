#pragma once

#include <stddef.h>
#include <stdint.h>
#include "gfx/gfx_Enum.hpp"

namespace nn {
    namespace gfx {
        namespace detail {
            void UseMiddleWare();
            int GetBlockWidth(ChannelFormat);
            int GetBlockHeight(ChannelFormat);
            bool IsCompressedFormat(ChannelFormat);
            bool IsSrgbFormat(TypeFormat);
            int GetBytePerPixel(ChannelFormat);
            size_t CalculateImageSize(ChannelFormat, uint32_t, uint32_t, uint32_t);
            int GetChannelCount(ChannelFormat);

            ImageDimension GetImageDimension(ImageStorageDimension, bool, bool);
        };  // namespace detail
    };  // namespace gfx
};  // namespace nn