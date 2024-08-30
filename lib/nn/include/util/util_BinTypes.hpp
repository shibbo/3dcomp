#pragma once

#include "types.hpp"

namespace nn {
    namespace util {
#define NN_UTIL_CREATE_SIGNATURE_4(s0, s1, s2, s3)                                                 \
    (static_cast<int32_t>((s0 & 0xFF) | ((s1 & 0xFF) << 8) | ((s2 & 0xFF) << 16) |                 \
                          ((s3 & 0xFF) << 24)))

#define NN_UTIL_CREATE_SIGNATURE_8(s0, s1, s2, s3, s4, s5, s6, s7)                                 \
    (static_cast<int64_t>(NN_UTIL_CREATE_SIGNATURE_4(s0, s1, s2, s3)) |                            \
     (static_cast<int64_t>(NN_UTIL_CREATE_SIGNATURE_4(s4, s5, s6, s7)) << 32))

        struct BinFileSignature {
        public:
            union {
                char str[8];
                int64_t packed;
            };
        };

        struct BinBlockSignature {
        public:
            union {
                char str[4];
                int32_t packed;
            };
        };

        struct BinVersion {
        public:
            uint8_t micro;
            uint8_t minor;
            uint8_t major;
        };

        template <typename T>
        struct BinTPtr {
        public:
            union {
                int64_t offset;
                T* ptr;
            };
        };

        typedef BinTPtr<void> BinPtr;

        template <typename Char>
        struct BinTString {
            uint16_t length;
            Char data[2 / sizeof(Char)];
        };

        typedef BinTString<char> BinString;
        typedef BinTPtr<BinString> BinPtrToString;
    };  // namespace util
};  // namespace nn