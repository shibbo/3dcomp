#pragma once

#include <types.hpp>

namespace al {
    class ByamlData;

    class ByamlIter {
    public:
        ByamlIter();

        bool isTypeArray() const;
        
        s32 getSize() const;

        bool tryGetIterByIndex(ByamlIter *, s32) const;

        bool tryGetStringByKey(const char **, const char *) const;

        bool getByamlDataByIndex(ByamlData *, s32);

        const u8* mData;            // 0x00
        const u8* mRoot;            // 0x08
    };
};