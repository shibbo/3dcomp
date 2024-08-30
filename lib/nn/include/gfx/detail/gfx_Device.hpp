#pragma once

#include "gfx/detail/gfx_DataContainer.hpp"
#include "gfx/detail/gfx_Declare.hpp"
#include "gfx/detail/gfx_Misc.hpp"
#include "gfx/gfx_DeviceData.hpp"
#include "gfx/gfx_Variaton.hpp"
#include "nn_BitTypes.hpp"
#include "util/util_BitPack.hpp"

namespace nn {
    namespace gfx {

        class DeviceInfo;
        class DisplayHandle;

        namespace detail {
            template <>
            class DeviceImpl<ApiVariationNvn8>
                : public DataContainer<DeviceImplData<ApiVariationNvn8>> {
            public:
                DeviceImpl();
                ~DeviceImpl();

                void Initialize(const DeviceInfo&);
                void Finalize();
            };
        };  // namespace detail
    };  // namespace gfx
};  // namespace nn