#pragma once

#include <cstddef>
#include <types.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void* (*LMSMallocPtr)(size_t);
typedef void (*LMSFreePtr)(void*);

typedef u8 libms_u8_t;
typedef u16 libms_u16_t;
typedef s32 libms_s32_t;
typedef u32 libms_u32_t;

typedef struct LMSColor {
    libms_u8_t r;
    libms_u8_t g;
    libms_u8_t b;
    libms_u8_t a;
} LMSColor;

enum LMS_Type : u8 {
    eLMS_Type_U8 = 0x0,
    eLMS_Type_U16 = 0x1,
    eLMS_Type_U32 = 0x2,
    eLMS_Type_S8 = 0x3,
    eLMS_Type_S16 = 0x4,
    eLMS_Type_S32 = 0x5,
    eLMS_Type_F32 = 0x6,
    eLMS_Type_F64 = 0x7,
    eLMS_Type_String = 0x8,
    eLMS_Type_List = 0x9,
    eLMS_Type_Unknown = 0xFF,
};

typedef struct LMSBlockInfo {
    const char* pDataStart;
    char mBlockName[4];
    libms_u32_t mDataSize;
    libms_u16_t mFlags;
    libms_u16_t pad;
} LMSBlockInfo;

typedef struct LMSCommonBinaryFormat {
    const char* pResource;
    size_t mResourceLength;
    libms_u8_t mEncoding;
    libms_u8_t pad;
    libms_u16_t mBlockNum;
    LMSBlockInfo* mBlockInfo;
} LMSCommonBinaryFormat;

typedef struct LMSMsgFile {
    LMSCommonBinaryFormat commonnInfo;
    libms_s32_t mLabelBlockIndex;
    libms_s32_t mTextBlockIndex;
    libms_s32_t mAttributeBlockIndex;
    libms_s32_t mATOBlockIndex;
    libms_s32_t mStyleBlockIndex;
} LMSMsgFile;

typedef struct LMSProjFile {
    LMSCommonBinaryFormat commonInfo;
    libms_s32_t mColorNameBlockIndex;
    libms_s32_t mColorInfoBlockIndex;
    libms_s32_t mAttrNameBlockIndex;
    libms_s32_t mAttrInfoBlockindex;
    libms_s32_t mListItemBlockIndex;
    libms_s32_t mTagGroupInfoBlockIndex;
    libms_s32_t mTagInfoBlockIndex;
    libms_s32_t mTagParamInfoBlockIndex;
    libms_s32_t mTagListItemInfoBlockIndex;
    libms_s32_t mStyleInfoBlockIndex;
    libms_s32_t mStyleNameBlockIndex;
    libms_s32_t mContentInfoBlockIndex;
} LMSProjFile;

void LMS_SetMemFuncs(LMSMallocPtr, LMSFreePtr);
void* LMSi_Malloc(size_t);
void LMSi_Free(void*);
int LMSi_MemCmp(const char*, const char*, int);
void LMSi_MemCopy(void*, const void*, int);
void LMSi_AnalyzeMessageBinary(LMSCommonBinaryFormat*, const char*, s32);

void LMS_CloseMesasge(LMSMsgFile*);

libms_s32_t LMSi_SearchBlockByName(LMSCommonBinaryFormat*, const char*);

const void* LMS_GetText(LMSMsgFile*, libms_s32_t);
const void* LMS_GetTextByLabel(LMSMsgFile*, const char*);

const char* LMS_GetTagGroupName(LMSProjFile*, libms_u16_t);
const char* LMS_GetTagName(LMSProjFile*, libms_u16_t, libms_u16_t);
const char* LMS_GetTagParamName(LMSProjFile*, libms_u16_t, libms_u16_t, libms_u16_t);
libms_s32_t LMS_GetTagGroupNum(LMSProjFile*);
libms_s32_t LMS_GetTagNum(LMSProjFile*, libms_u16_t);
libms_s32_t LMS_GetTagParamNum(LMSProjFile*, libms_u16_t, libms_u16_t);

#ifdef __cplusplus
}
#endif