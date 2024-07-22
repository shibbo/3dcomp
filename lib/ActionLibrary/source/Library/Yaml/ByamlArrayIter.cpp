#include "Library/Yaml/ByamlArrayIter.hpp"

namespace al {
    ByamlArrayIter::ByamlArrayIter() = default;

    ByamlArrayIter::ByamlArrayIter(const u8* pData) : mData(pData) { }

    u32 ByamlArrayIter::getSize() const {
        return *reinterpret_cast<const u32*>(mData) >> 8;
    }

    const u8* ByamlArrayIter::getTypeTable() const {
        return mData + 4;
    }

    const u32* ByamlArrayIter::getDataTable() const {
        return reinterpret_cast<const u32*>(getOffsetData((getSize() + 3) & 0x1FFFFFC)) + 4;
    }

    // al::ByamlArrayIter::getDataByIndex

    const u8* ByamlArrayIter::getOffsetData(u32 offs) const {
        return &mData[offs];
    }
};