#pragma once

#include "gfx/gfx_VariationBase.hpp"

namespace nn {
    namespace gfx {
        struct TargetConfig {
            typedef ApiType<4> Type;
            typedef ApiVersion<8> Version;
            typedef ApiVariation<Type, Version> Variation;
        };
    };  // namespace gfx
};  // namespace nn