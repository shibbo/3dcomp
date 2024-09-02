#pragma once

#include <stdint.h>
#include "gfx/detail/gfx_DataContainer.hpp"

namespace nn {
    namespace gfx {
        struct DescriptorSlotData {
            uint64_t value;
        };

        class DescriptorSlot : public detail::DataContainer<DescriptorSlotData> {
        public:
            DescriptorSlot() { this->value = InvalidValue; }

        private:
            static const uint64_t InvalidValue = static_cast<uint64_t>(-1);
        };

    };  // namespace gfx
};  // namespace nn