#pragma once

#include "util/util_AccessorBase.hpp"
#include "util/util_BinTypes.hpp"
#include "util/util_BinaryFormat.hpp"

namespace nn {
    namespace util {
        struct ResDicData {
            BinBlockSignature signature;
            int32_t count;

            struct Entry {
                int32_t refBit;
                uint16_t children[2];
                BinPtrToString pKey;
            } entries[1];
        };

        class ResDic : AccessorBase<ResDicData> {};
    };  // namespace util
};  // namespace nn