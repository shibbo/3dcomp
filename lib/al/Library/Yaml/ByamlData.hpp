#pragma once

#include <seadTypes.h>

namespace al {
    class ByamlData {
    public:
        ByamlData() = default;

        u32 mValue = 0;  // 0x00
        u8 mType = 0;    // 0x04
    };
};  // namespace al