#pragma once

#include "gfx/detail/gfx_MemoryPool.hpp"
#include "gfx/gfx_VariationBase.hpp"

namespace nn {
    namespace gfx {
        template <typename TTarget>
        class TMemoryPool
            : public detail::MemoryPoolImpl<typename detail::TargetVariation<TTarget>::Type> {
        public:
            typedef MemoryPoolInfo InfoType;
        };
    };  // namespace gfx
};  // namespace nn