#include "gfx/detail/gfx_Device.hpp"
#include <nvn_FuncPtr.h>
#include <nvn_FuncPtrInline.h>
#include "gfx/gfx_NvnHelper.h"

namespace nn {
    namespace gfx {
        namespace detail {
            DeviceImpl<ApiVariationNvn8>::DeviceImpl() {
                this->state = State_NotInitialized;
            }

            DeviceImpl<ApiVariationNvn8>::~DeviceImpl() {}

            // Initialize

            void DeviceImpl<ApiVariationNvn8>::Finalize() {
                NN_GFX_CALL_NVN_FUNCTION(nvnDeviceFinalize(this->pNvnDevice));
                this->pNvnDevice = nullptr;
                this->state = State_NotInitialized;
            }
        };  // namespace detail
    };  // namespace gfx
};  // namespace nn