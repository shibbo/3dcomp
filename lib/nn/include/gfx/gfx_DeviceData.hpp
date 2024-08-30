#pragma once

#include "gfx/detail/gfx_Declare.hpp"
#include "gfx/detail/gfx_Misc.hpp"
#include "gfx/gfx_Variaton.hpp"
#include "nn_BitTypes.hpp"
#include "util/util_BitPack.hpp"

namespace nn {
    namespace gfx {
        template <>
        struct DeviceImplData<ApiVariationNvn8> {
            enum State { State_NotInitialized, State_Initialized };

            enum Flag { Flag_Shared };

            detail::Ptr<void> pNvnDevice;
            char nvnDevice[12288];
            Bit8 state;
            nn::util::BitPack8 flags;
            char res[2];
            nn::util::BitPack32 supportedFeatures;
            detail::Ptr<void> userPtr;
        };
    };  // namespace gfx
};  // namespace nn