#include "hash/seadHash.hpp"

namespace sead {
    void HashCRC16::initialize() {
        for (u32 i = 0; i < 256; i++) {
            u32 val = i;

            for (u32 j = 0; j < 8; j++) {
                val = ((val & 1) == 0) ? (val >> 1) : ((val >> 1) ^ 0xA001);
            }

            sTable[i] = val;
        }

        sInitialized = true;
    }

    u32 HashCRC16::calcHash(const void *pData, u32 dataSize) {
        Context context;
        return calcHashWithContext(&context, pData, dataSize);
    }

    u32 HashCRC16::calcHashWithContext(Context *pContext, const void *pData, u32 dataSize) {
        if (!sInitialized) {
            initialize();
        }

        u32 hash = pContext->mHash;
        const u8* data = static_cast<const u8*>(pData);
        
        while (dataSize-- != 0) {
            hash = sTable[*data++ ^ (hash & 0xFF)] ^ (hash >> 8);
        }

        pContext->mHash = hash;
        return hash;
    }

    u32 HashCRC16::calcStringHash(const char *pStr) {
        Context context;
        return calcStringHashWithContext(&context, pStr);
    }

    u32 HashCRC16::calcStringHashWithContext(Context *pContext, const char *pStr) {
        if (!sInitialized) {
            initialize();
        }

        u32 hash = pContext->mHash;

        while (*pStr != 0) {
            hash = sTable[*pStr++ ^ (hash & 0xFF)] ^ (hash >> 8);
        }

        pContext->mHash = hash;
        return hash;
    }

    void HashCRC32::initialize() {
        for (u32 i = 0; i < 256; i++) {
            u32 val = i;

            for (u32 j = 0; j < 8; j++) {
                val = ((val & 0x1) == 0) ? (val >> 1) : ((val >> 1) ^ 0xEDB88320);
            }

            sTable[i] = val;
        }

        sInitialized = true;
    }

    u32 HashCRC32::calcHash(const void *pData, u32 dataSize) {
        Context context;
        return calcHashWithContext(&context, pData, dataSize);
    }

    u32 HashCRC32::calcHashWithContext(Context *pContext, const void *pData, u32 dataSize) {
        if (!sInitialized) {
            initialize();
        }

        u32 hash = pContext->mHash;
        const u8* data = static_cast<const u8*>(pData);

        while (dataSize-- != 0) {
            hash = sTable[*data++ ^ (hash & 0xFF)] ^ (hash >> 8);
        }

        pContext->mHash = hash;
        return ~hash;
    }

    u32 HashCRC32::calcStringHash(const char *pStr) {
        Context context;
        return calcStringHashWithContext(&context, pStr);
    }

    u32 HashCRC32::calcStringHashWithContext(Context *pContext, const char *pStr) {
        if (!sInitialized) {
            initialize();
        }

        u32 hash = pContext->mHash;
        while (*pStr != 0) {
            hash = sTable[*pStr++ ^ (hash & 0xFF)] ^ (hash >> 8);
        }

        pContext->mHash = hash;
        return ~hash;
    }
};