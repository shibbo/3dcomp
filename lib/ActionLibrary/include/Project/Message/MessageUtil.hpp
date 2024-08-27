#pragma once

#include <prim/seadSafeString.hpp>
#include <types.hpp>

namespace al {
    class IUseMessageSystem;
    class MessageTag;
    class MessageProjectEx;

    bool isMessageTagMark(char16_t);
    bool isMessageTagEndMark(char16_t);
    bool isMessageTagPageBreak(const IUseMessageSystem*, const char16_t*);
    bool isMessageTagPageBreak(const IUseMessageSystem*, const MessageTag&);
    bool isMessageTagPageBreak(const MessageProjectEx*, const MessageTag&);
    const char* getMessageTagGroupName(const MessageProjectEx*, s32);
    const char* getMessageTagName(const MessageProjectEx*, s32, s32);
    const char* getMessageTagName(const IUseMessageSystem*, s32, s32);
    bool isExistMessageTag(const char16_t*);

    bool isMessageTagPictFont(const IUseMessageSystem*, s32);
    bool isMessageTagDeviceFont(const IUseMessageSystem*, s32);
    bool isExistMessageTagPadSwitch(const IUseMessageSystem*, const char16_t*);
    bool isMessageTagPadStyle(const IUseMessageSystem*, s32, s32);
    bool isMessageTagPadPair(const IUseMessageSystem*, s32, s32);
    bool isMessageTagPadStyle2P(const IUseMessageSystem*, s32, s32);
    bool isMessageTagAlignLeft(const IUseMessageSystem*, s32, s32);
    bool isMessageTagAlignCenter(const IUseMessageSystem*, s32, s32);
    void replaceMessageTagString(sead::BufferedSafeStringBase<char16_t>*, const IUseMessageSystem*,
                                 const char16_t*, const char16_t*);
    // void replaceMessageTagTimeDirectRaceTime()

    const char* getSystemMessageString(const IUseMessageSystem*, const char*, const char*);

};  // namespace al