#pragma once

#include "gfx/gfx_MemoryPool.hpp"
#include "gfx/gfx_TargetConfig.hpp"
#include "gfx/gfx_VariationBase.hpp"

namespace nn {
    namespace gfx {
        typedef TMemoryPool<TargetConfig::Variation> MemoryPool;
    };
};  // namespace nn