#include "Library/Yaml/ByamlStringTableIter.hpp"
#include <string.h>

namespace al {
    ByamlStringTableIter::ByamlStringTableIter() = default;

    ByamlStringTableIter::ByamlStringTableIter(const u8* pData) : mData(pData) { 
        
    }

    s32 ByamlStringTableIter::getSize() const {
        return *reinterpret_cast<const u32*>(mData + 4) >> 8;
    }

    const u32* ByamlStringTableIter::getAddressTable() const {
        return reinterpret_cast<const u32*>(mData + 4);
    }

    u32 ByamlStringTableIter::getStringAddress(s32 strIdx) const {
        return getAddressTable()[strIdx];
    }

    u32 ByamlStringTableIter::getEndAddress() const {
        return getAddressTable()[getSize()];
    }

    const char* ByamlStringTableIter::getString(s32 strIdx) const {
        return reinterpret_cast<const char *>(&mData[getStringAddress(strIdx)]);
    }

    s32 ByamlStringTableIter::getStringSize(s32 idx) const {
        return getStringAddress(idx + 1) + ~getStringAddress(idx);
    }

    s32 ByamlStringTableIter::findStringIndex(const char* str) const {
        s32 lower = 0;
        s32 upper = getSize();
        while (lower < upper) {
            s32 avg = (lower + upper) / 2;
            s32 result = strcmp(str, getString(avg));

            if (result == 0) {
                return avg; 
            }

            if (result > 0) {
                lower = avg + 1;
            }
            else {
                upper = avg;
            }
        }
        return -1;
    }
};