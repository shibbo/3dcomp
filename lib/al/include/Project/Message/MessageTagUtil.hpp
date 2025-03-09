#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.hpp>

namespace al {
class IUseMessageSystem;
class MessageTag;
class MessageProjectEx;

bool isMessageTagMark(s16);
bool isMessageTagEndMark(s16);
bool isMessageTagPageBreak(const IUseMessageSystem*, const s16*);
bool isMessageTagPageBreak(const IUseMessageSystem*, const MessageTag&);
bool isMessageTagPageBreak(const MessageProjectEx*, const MessageTag&);
const char* getMessageTagGroupName(const MessageProjectEx*, s32);
const char* getMessageTagName(const MessageProjectEx*, s32, s32);
const char* getMessageTagName(const IUseMessageSystem*, s32, s32);
bool isExistMessageTag(const s16*);

bool isMessageTagPictFont(const IUseMessageSystem*, s32);
bool isMessageTagDeviceFont(const IUseMessageSystem*, s32);
bool isExistMessageTagPadSwitch(const IUseMessageSystem*, const s16*);
bool isMessageTagPadStyle(const IUseMessageSystem*, s32, s32);
bool isMessageTagPadPair(const IUseMessageSystem*, s32, s32);
bool isMessageTagPadStyle2P(const IUseMessageSystem*, s32, s32);
bool isMessageTagAlignLeft(const IUseMessageSystem*, s32, s32);
bool isMessageTagAlignCenter(const IUseMessageSystem*, s32, s32);
void replaceMessageTagString(sead::BufferedSafeStringBase<s16>*, const IUseMessageSystem*,
                             const s16*, const s16*);
// void replaceMessageTagTimeDirectRaceTime()

const char* getSystemMessageString(const IUseMessageSystem*, const char*, const char*);

}  // namespace al
