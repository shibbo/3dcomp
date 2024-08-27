#pragma once

#include <types.hpp>

namespace nn {
    namespace font {
        template <typename CharType>
        class TextWriterBase;

        template <typename CharType>
        class PrintContext {
        public:
            TextWriterBase<CharType>* writer;  // 0x00
            const CharType* str;               // 0x08
            const CharType* strEnd;            // 0x10
            const f32 xOrigin;                 // 0x18
            const f32 yOrigin;                 // 0x1C
            const f32 hScale;                  // 0x20
            const f32 vScale;                  // 0x24
            uint32_t flags;                    // 0x28
            uint32_t prevCode;                 // 0x2C
        };
    };  // namespace font
};  // namespace nn