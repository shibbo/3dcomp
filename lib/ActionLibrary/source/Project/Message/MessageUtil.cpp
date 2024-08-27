#include "Project/Message/MessageUtil.hpp"
#include "Project/Base/StringUtil.hpp"
#include "Project/Message/MessageHolder.hpp"
#include "Project/Message/MessageProjectEx.hpp"
#include "Project/Message/MessageTag.hpp"

namespace al {
    bool isMessageTagMark(char16_t tag) {
        return (tag | 1) == 0xF;
    }

    bool isMessageTagEndMark(char16_t tag) {
        return tag == 0xE;
    }

    bool isMessageTagPageBreak(const IUseMessageSystem* pMsgSys, const char16_t* pTag) {
        if (pTag == nullptr || (*pTag | 1) != 0xF) {
            return false;
        }

        return isMessageTagPageBreak(pMsgSys, MessageTag(pTag));
    }

    bool isMessageTagPageBreak(const IUseMessageSystem* pMsgSys, const MessageTag& rTag) {
        return isMessageTagPageBreak(pMsgSys->getMessageSystem()->getMessageProject(), rTag);
    }

    bool isMessageTagPageBreak(const MessageProjectEx* pProj, const MessageTag& rTag) {
        auto groupName = pProj->getTagGroupNameByIndex(rTag.mTag[1]);

        if (groupName != nullptr) {
            if (al::isEqualString("System", groupName)) {
                auto tagName = pProj->getTagNameByIndex(rTag.mTag[1], rTag.mTag[2]);

                if (tagName != nullptr) {
                    return al::isEqualString("PageBreak", tagName);
                }
            }
        }

        return false;
    }

    const char* getMessageTagGroupName(const MessageProjectEx* pProject, s32 groupId) {
        return pProject->getTagGroupNameByIndex(groupId);
    }

    const char* getMessageTagGroupName(const IUseMessageSystem* pMsg, s32 groupId) {
        return pMsg->getMessageSystem()->getMessageProject()->getTagGroupNameByIndex(groupId);
    }

    const char* getMessageTagName(const MessageProjectEx* pProject, s32 groupId, s32 tagId) {
        return pProject->getTagNameByIndex(groupId, tagId);
    }

    const char* getMessageTagName(const IUseMessageSystem* pMsg, s32 groupId, s32 tagId) {
        auto msgSystem = pMsg->getMessageSystem();
        auto msgProj = msgSystem->getMessageProject();
        return msgProj->getTagNameByIndex(groupId, tagId);
    }

    // ....

    bool isMessageTagPictFont(const IUseMessageSystem* pMsg, s32 groupId) {
        auto msgProj = pMsg->getMessageSystem()->getMessageProject();
        auto tagGroupName = msgProj->getTagGroupNameByIndex(groupId);

        if (tagGroupName != nullptr) {
            return al::isEqualString(tagGroupName, "PictFont");
        }

        return false;
    }

    bool isMessageTagDeviceFont(const IUseMessageSystem* pMsg, s32 groupId) {
        auto msgProj = pMsg->getMessageSystem()->getMessageProject();
        auto tagGroupName = msgProj->getTagGroupNameByIndex(groupId);

        if (tagGroupName != nullptr) {
            return al::isEqualString(tagGroupName, "DeviceFont");
        }

        return false;
    }

    // ...

    bool isMessageTagPadStyle(const IUseMessageSystem* pMsg, s32 groupId, s32 tagId) {
        auto tagName =
            pMsg->getMessageSystem()->getMessageProject()->getTagNameByIndex(groupId, tagId);
        auto tagGroupName =
            pMsg->getMessageSystem()->getMessageProject()->getTagGroupNameByIndex(groupId);

        bool isEitherInvalid;

        if (tagName != nullptr) {
            isEitherInvalid = tagGroupName == nullptr;
        } else {
            isEitherInvalid = true;
        }

        return !isEitherInvalid && al::isEqualString(tagGroupName, "ProjectTag") &&
               al::isEqualString(tagName, "PadStyle");
    }

    bool isMessageTagPadPair(const IUseMessageSystem* pMsg, s32 groupId, s32 tagId) {
        auto tagName =
            pMsg->getMessageSystem()->getMessageProject()->getTagNameByIndex(groupId, tagId);
        auto tagGroupName =
            pMsg->getMessageSystem()->getMessageProject()->getTagGroupNameByIndex(groupId);

        bool isEitherInvalid;

        if (tagName != nullptr) {
            isEitherInvalid = tagGroupName == nullptr;
        } else {
            isEitherInvalid = true;
        }

        return !isEitherInvalid && al::isEqualString(tagGroupName, "ProjectTag") &&
               al::isEqualString(tagName, "PadPair");
    }

    bool isMessageTagPadStyle2P(const IUseMessageSystem* pMsg, s32 groupId, s32 tagId) {
        auto tagName =
            pMsg->getMessageSystem()->getMessageProject()->getTagNameByIndex(groupId, tagId);
        auto tagGroupName =
            pMsg->getMessageSystem()->getMessageProject()->getTagGroupNameByIndex(groupId);

        bool isEitherInvalid;

        if (tagName != nullptr) {
            isEitherInvalid = tagGroupName == nullptr;
        } else {
            isEitherInvalid = true;
        }

        return !isEitherInvalid && al::isEqualString(tagGroupName, "ProjectTag") &&
               al::isEqualString(tagName, "PadStyle2P");
    }

    bool isMessageTagAlignLeft(const IUseMessageSystem* pMsg, s32 groupId, s32 tagId) {
        auto tagName =
            pMsg->getMessageSystem()->getMessageProject()->getTagNameByIndex(groupId, tagId);
        auto tagGroupName =
            pMsg->getMessageSystem()->getMessageProject()->getTagGroupNameByIndex(groupId);

        bool isEitherInvalid;

        if (tagName != nullptr) {
            isEitherInvalid = tagGroupName == nullptr;
        } else {
            isEitherInvalid = true;
        }

        return !isEitherInvalid && al::isEqualString(tagGroupName, "TextAlign") &&
               al::isEqualString(tagName, "AlignLeft");
    }

    bool isMessageTagAlignCenter(const IUseMessageSystem* pMsg, s32 groupId, s32 tagId) {
        auto tagName =
            pMsg->getMessageSystem()->getMessageProject()->getTagNameByIndex(groupId, tagId);
        auto tagGroupName =
            pMsg->getMessageSystem()->getMessageProject()->getTagGroupNameByIndex(groupId);

        bool isEitherInvalid;

        if (tagName != nullptr) {
            isEitherInvalid = tagGroupName == nullptr;
        } else {
            isEitherInvalid = true;
        }

        return !isEitherInvalid && al::isEqualString(tagGroupName, "TextAlign") &&
               al::isEqualString(tagName, "AlignCenter");
    }
};  // namespace al