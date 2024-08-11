#pragma once

#include <types.hpp>

namespace al {
    class ByamlData;

    class ByamlIter {
    public:
        ByamlIter();
        ByamlIter(const u8 *, const u8 *);

        bool isValid() const;
        bool isTypeHash() const;
        bool isTypeArray() const;
        bool isTypeContainer() const;
        bool isExistKey(const char *) const;
        s32 getKeyIndex(const char *) const;
        s32 getSize() const;
        ByamlIter getIterByIndex(s32) const;
        bool getByamlDataByIndex(ByamlData *, s32) const;
        ByamlIter getIterByKey(const char *) const;
        bool getByamlDataByKey(ByamlData *, const char *) const;
        bool getByamlDataByKeyIndex(ByamlData *, s32) const;
        bool getByamlDataAndKeyName(ByamlData *, const char **, s32) const;
        bool getKeyName(const char **, s32) const;
        bool tryGetIterByIndex(ByamlIter *, s32) const;
        bool tryGetIterAndKeyNameByIndex(ByamlIter *, const char **, s32) const;
        bool tryGetIterByKey(ByamlIter *, const char *) const;
        bool tryGetStringByKey(const char **, const char *) const;
        bool tryConvertString(const char **, const ByamlData *) const;
        bool tryGetBinaryByKey(const u8 **, s32 *, const char *) const;
        bool tryConvertBinary(const u8 **, s32 *, const ByamlData *) const;
        bool tryGetBoolByKey(bool *, const char *) const;
        bool tryConvertBool(bool *, const ByamlData *) const;
        bool tryGetIntByKey(s32 *, const char *) const;
        bool tryConvertInt(s32 *, const ByamlData *) const;
        bool tryGetUIntByKey(u32 *, const char *) const;
        bool tryConvertUInt(u32 *, const ByamlData *) const;
        bool tryGetFloatByKey(f32 *, const char *) const;
        bool tryConvertFloat(f32 *, const ByamlData *) const;
        bool tryGetInt64ByKey(s64 *, const char *) const;
        bool tryConvertInt64(s64 *, const ByamlData *) const;
        bool tryGetUInt64ByKey(u64 *, const char *) const;
        bool tryConvertUInt64(u64 *, const ByamlData *) const;
        bool tryGetDoubleByKey(f64 *, const char *) const;
        bool tryConvertDouble(f64 *, const ByamlData *) const;
        bool tryGetStringByIndex(const char **, s32) const;
        bool tryGetBinaryByIndex(const u8 **, s32 *, s32) const;
        bool tryGetBoolByIndex(bool *, s32) const;
        bool tryGetIntByIndex(s32 *, s32) const;
        bool tryGetUIntByIndex(u32 *, s32) const;
        bool tryGetFloatByIndex(f32 *, s32) const;
        bool tryGetInt64ByIndex(s64 *, s32) const;
        bool tryGetUInt64ByIndex(u64 *, s32) const;
        bool tryGetDoubleByIndex(f64 *, s32) const;
        bool tryConvertIter(ByamlIter *, const ByamlData *) const;
        bool isEqualData(const ByamlIter &) const;

        const u8* mData;            // 0x00
        const u8* mRoot;            // 0x08
    };

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
};