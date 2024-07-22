#pragma once

#include <types.hpp>

namespace al {
    class ByamlData;

    class ByamlArrayIter {
    public:
        ByamlArrayIter();
        ByamlArrayIter(const u8* );

        u32 getSize() const;
        const u8* getTypeTable() const;
        const u32* getDataTable() const;
        bool getDataByIndex(ByamlData *, s32) const;
        const u8* getOffsetData(u32) const;
        
        const u8* mData = nullptr;              // 0x00
    };
}