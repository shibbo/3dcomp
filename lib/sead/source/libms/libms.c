#include "libms/libms.h"

#ifdef __cplusplus
extern "C" {
#endif

LMSMsgFile* LMS_InitMessage(const char* pData) {
    LMSMsgFile* file = (LMSMsgFile*)LMSi_Malloc(sizeof(LMSMsgFile));
    file->commonnInfo.pResource = pData;
    LMSi_AnalyzeMessageBinary(&file->commonnInfo, "MsgStdBn", 3);
    file->mLabelBlockIndex = LMSi_SearchBlockByName(&file->commonnInfo, "LBL1");
    file->mTextBlockIndex = LMSi_SearchBlockByName(&file->commonnInfo, "TXT2");
    file->mAttributeBlockIndex = LMSi_SearchBlockByName(&file->commonnInfo, "ATR1");
    file->mATOBlockIndex = LMSi_SearchBlockByName(&file->commonnInfo, "ATO1");
    file->mStyleBlockIndex = LMSi_SearchBlockByName(&file->commonnInfo, "TSY1");
    return file;
}

void LMS_CloseMessage(LMSMsgFile* pFile) {
    LMSBlockInfo* info = pFile->commonnInfo.mBlockInfo;

    if (info != 0) {
        LMSi_Free(info);
    }

    LMSi_Free(pFile);
}

#ifdef __cplusplus
}
#endif