#pragma once

/*
// #include "Library/Resource/Resource.hpp"
// #include "libms/MessageSetBase.hpp" // dont you *dare* use leaked material

namespace sead {
    class FrameHeap;
}

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

        sead::MessageSet<s16>* mMsgBase;
    };

    class MessageSystem;
    class MessageProjectEx;

    class IUseMessageSystem {
    public:
        virtual MessageSystem* getMessageSystem() const = 0;
    };

    class MessageSystem {
    public:
        MessageProjectEx* getMessageProject() const;
        MessageHolder* getSystemMessageHolder(const char*, const char*) const;

        MessageProjectEx* mProject;
        u64 _8;
        u64 _10;
        sead::FrameHeap* mHeap;
    };
}  // namespace al
*/
