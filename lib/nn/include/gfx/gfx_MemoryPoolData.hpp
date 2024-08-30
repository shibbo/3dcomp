#pragma once

#include "gfx/detail/gfx_Declare.hpp"
#include "gfx/detail/gfx_Misc.hpp"
#include "gfx/gfx_Variaton.hpp"
#include "nn_BitTypes.hpp"
#include "types.hpp"
#include "util/util_BitPack.hpp"

namespace nn {
    namespace gfx {
        template <>
        struct MemoryPoolImplData<ApiVariationNvn8> {
            detail::Ptr<void> pNvnMemoryPool;
            detail::Ptr<void> pMemory;

            NN_ALIGNAS(8) char nvnMemoryPool[256];

            enum State { State_NotInitialized, State_Initalized };

            enum Flag { Flag_Shared };

            Bit8 state;
            nn::util::BitPack8 flags;
            char res[6];
            detail::Ptr<void> userPtr;
        };
    };  // namespace gfx
};  // namespace nn