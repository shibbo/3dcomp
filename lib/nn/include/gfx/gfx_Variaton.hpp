#pragma once

#include "gfx/gfx_VariationBase.hpp"

namespace nn {
    namespace gfx {
        enum { LowLevelApi_Nvn = 4 };

        typedef ApiType<LowLevelApi_Nvn> ApiTypeNvn;
        typedef ApiVariation<ApiTypeNvn, ApiVersion<8>> ApiVariationNvn8;

        template <>
        struct DefaultVersion<ApiTypeNvn> {
            typedef ApiVersion<8> Version;
        };

        template <>
        struct TargetVersion<ApiTypeNvn> {
            typedef ApiVersion<8> Version;
        };
    };  // namespace gfx
};  // namespace nn