#pragma once

#include <seadTypes.h>

namespace al {
    class ByamlHeader {
    public:
        u16 getTag() const;
        bool isInvertOrder() const;
        u16 getVersion() const;
        u32 getHashKeyTableOffset() const;
        u32 getStringTableOffset() const;
        u32 getDataOffset() const;

        // 0x00
        union {
            u32 _0;
            u16 mTag, mVersion;
        };

        s32 mHashKeyOffset;      // 0x04
        s32 mStringTableOffset;  // 0x08
        s32 mDataOffset;         // 0x0C
    };
};  // namespace al