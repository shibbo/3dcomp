#pragma once

#include <stdint.h>

namespace nn {
    namespace os {
        class Tick {
        public:
            int64_t GetInt64Value() const { return mTick; }

            int64_t mTick;  // 0x00
        };
    };  // namespace os
};  // namespace nn