#pragma once

#include <libms/MessageSetBase.hpp>
#include "Library/Resource/Resource.hpp"

namespace al {
    class MessageHolder {
    public:
        MessageHolder();

        virtual ~MessageHolder();

        void init(const char*, const char*);
        void init(Resource*, const char*);
        const char* getText(s32) const;
        const char* getText(const char*) const;
        const char* tryGetText(const char*) const;
        bool isExistText(const char*) const;
        u32 calcCharacterNum(s32) const;
        u32 calcCharacterNum(const char*) const;
        u32 calcCharacterByteSize(const char*) const;
        u32 getTextNum() const;
        s32 searchTextLabelByIndex(sead::BufferedSafeString*, s32) const;
        u32 getStyleByIndex(s32) const;
        u32 trySearchStyleIndexByLabel(const char*) const;

        sead::MessageSet<char16_t>* mMsgBase;  // 0x8
    };
};  // namespace al