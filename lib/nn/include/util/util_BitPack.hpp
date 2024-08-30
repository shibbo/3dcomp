#pragma once

#include <cstdint>

namespace nn {
    namespace util {
        template <typename Storage, typename Tag = void>
        struct BitPack {
            Storage storage;
        };

        typedef BitPack<uint8_t> BitPack8;
        typedef BitPack<uint16_t> BitPack16;
        typedef BitPack<uint32_t> BitPack32;
    };  // namespace util
};  // namespace nn