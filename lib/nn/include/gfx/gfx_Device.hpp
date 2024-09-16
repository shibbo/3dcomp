#pragma once

#include "gfx/detail/gfx_Device.hpp"
#include "gfx/detail/gfx_RequiredMemory.hpp"
#include "gfx/gfx_DeviceData.hpp"
#include "gfx/gfx_VariationBase.hpp"

namespace nn {
    namespace gfx {
        template <typename TTarget>
        class TDevice : public detail::DeviceImpl<typename detail::TargetVariation<TTarget>::Type>,
                        private detail::RequiredMemory<detail::DeviceImpl<typename detail::TargetVariation<TTarget>::Type>> {};
    };  // namespace gfx
};  // namespace nn