#pragma once

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

};  // namespace al