#pragma once

#include "gfx/detail/gfx_DataContainer.hpp"
#include "gfx/detail/gfx_Declare.hpp"
#include "gfx/gfx_MemoryPoolData.hpp"
#include "gfx/gfx_Variaton.hpp"

namespace nn {
    namespace gfx {
        class MemoryPoolInfo;

        namespace detail {
            template <>
            class MemoryPoolImpl<ApiVariationNvn8>
                : public DataContainer<MemoryPoolImplData<ApiVariationNvn8>> {
                MemoryPoolImpl();
                ~MemoryPoolImpl();
            };
        };  // namespace detail
    };  // namespace gfx
};  // namespace nn