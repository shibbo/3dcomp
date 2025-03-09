#pragma once

#include <basis/seadTypes.h>

namespace al {
class ByamlHeader {
public:
    u16 getTag() const;
    bool isInvertOrder() const;
    u16 getVersion() const;
    u32 getHashKeyTableOffset() const;
    u32 getStringTableOffset() const;
    u32 getDataOffset() const;

    union {
        u32 _0;
        u16 mTag, mVersion;
    };

    s32 mHashKeyOffset;
    s32 mStringTableOffset;
    s32 mDataOffset;
};
}  // namespace al
