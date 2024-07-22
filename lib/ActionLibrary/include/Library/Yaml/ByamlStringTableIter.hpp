#pragma once

#include <types.hpp>

namespace al {
    class ByamlStringTableIter {
    public:
        ByamlStringTableIter();
        ByamlStringTableIter(const u8 *pData);

        s32 getSize() const;
        const u32* getAddressTable() const;
        u32 getStringAddress(s32) const;
        u32 getEndAddress() const;
        const char* getString(s32) const;
        s32 getStringSize(s32) const;
        s32 findStringIndex(const char *) const;

        const u8* mData = nullptr;
    };
};