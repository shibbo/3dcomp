#pragma once

#include "gfx/detail/gfx_DataContainer.hpp"
#include "gfx/detail/gfx_Declare.hpp"
#include "gfx/gfx_Texture.hpp"
#include "gfx/gfx_TextureInfoData.hpp"
#include "gfx/gfx_Variaton.hpp"

namespace nn {
    namespace gfx {
        class TextureInfo;

        namespace detail {
            template <>
            class TextureInfoImpl<ApiVariationNvn8>
                : public DataContainer<TextureInfoImplData<ApiVariationNvn8>> {
            public:
            };
        };  // namespace detail
    };  // namespace gfx
};  // namespace nn