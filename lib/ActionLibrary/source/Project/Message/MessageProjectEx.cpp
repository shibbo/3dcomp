#include "Project/Message/MessageProjectEx.hpp"
#include <prim/seadSafeString.hpp>
#include "Library/Resource/Resource.hpp"
#include "Library/Resource/ResourceUtil.hpp"

const char* sProjectDataPath = "LocalizedData/Common/ProjectData";

namespace al {
    MessageProjectEx::MessageProjectEx() {}

    void MessageProjectEx::init() {
        auto resource = al::findOrCreateResource(sead::SafeString(sProjectDataPath), nullptr);
        void* file = resource->getOtherFile(sead::SafeString("ProjectData.msbp"), nullptr);
        initialize(file, nullptr);
    }

    void MessageProjectEx::finalize() {
        sead::MessageProject::finalize();
    }

    const char* MessageProjectEx::getTagGroupNameByIndex(s32 idx) const {
        return LMS_GetTagGroupName(mProjectFile, idx);
    }

    const char* MessageProjectEx::getTagNameByIndex(s32 groupID, s32 tagID) const {
        return LMS_GetTagName(mProjectFile, groupID, tagID);
    }

    const char* MessageProjectEx::getTagParamNameByIndex(s32 groupID, s32 tagID,
                                                         s32 paramIndex) const {
        return LMS_GetTagParamName(mProjectFile, groupID, tagID, paramIndex);
    }

    s32 MessageProjectEx::getTagGroupNum() const {
        return LMS_GetTagGroupNum(mProjectFile);
    }

    s32 MessageProjectEx::getTagNum(s32 groupId) const {
        return LMS_GetTagNum(mProjectFile, groupId);
    }

    s32 MessageProjectEx::getTagParamNum(s32 groupId, s32 tagId) const {
        return LMS_GetTagParamNum(mProjectFile, groupId, tagId);
    }

    MessageProjectEx::~MessageProjectEx() {}

};  // namespace al