#pragma once

#include "gfx/gfx_Device.hpp"
#include "gfx/gfx_MemoryPool.hpp"
#include "gfx/gfx_TargetConfig.hpp"
#include "gfx/gfx_VariationBase.hpp"

namespace nn {
    namespace gfx {
        typedef TMemoryPool<TargetConfig::Variation> MemoryPool;
        typedef TDevice<TargetConfig::Variation> Device;
    };  // namespace gfx
};  // namespace nn