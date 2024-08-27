#include "Project/Message/MessageHolder.hpp"
#include "Library/Resource/ResourceUtil.hpp"
#include "Project/Base/StringUtil.hpp"

namespace al {
    MessageHolder::MessageHolder() {
        mMsgBase = new sead::MessageSet<char16_t>();
    }

    MessageHolder::~MessageHolder() {
        if (mMsgBase != nullptr) {
            delete mMsgBase;
        }
    }

    void MessageHolder::init(const char* a1, const char* a2) {
        Resource* res = al::findOrCreateResource(sead::SafeString(a1), nullptr);
        void* file = res->getOtherFile(al::StringTmp<128>("%s.msbt", a2), nullptr);
        mMsgBase->initialize(file, nullptr);
    }

    void MessageHolder::init(Resource* pResource, const char* p2) {
        void* file = pResource->getOtherFile(sead::SafeString(p2), nullptr);
        mMsgBase->initialize(file, nullptr);
    }

    const char* MessageHolder::getText(s32 textIdx) const {
        const char* txt;

        if (mMsgBase->mTextNum <= textIdx) {
            txt = nullptr;
        } else {
            txt = reinterpret_cast<const char*>(LMS_GetText(mMsgBase->mMsgFile, textIdx));
        }

        return (txt != nullptr) ? txt : "NULL";
    }

    const char* MessageHolder::getText(const char* pLabel) const {
        const char* txt =
            reinterpret_cast<const char*>(LMS_GetTextByLabel(mMsgBase->mMsgFile, pLabel));
        return (txt != nullptr) ? txt : "NULL";
    }

    const char* MessageHolder::tryGetText(const char* pLabel) const {
        return reinterpret_cast<const char*>(LMS_GetTextByLabel(mMsgBase->mMsgFile, pLabel));
    }

    bool MessageHolder::isExistText(const char* pLabel) const {
        return tryGetText(pLabel) != nullptr;
    }

};  // namespace al