#include "Project/AreaObj/AreaObjGroup.hpp"
#include "Library/Placement/PlacementFunction.hpp"
#include "Project/Base/StringUtil.hpp"

namespace al {
    AreaObjGroup::AreaObjGroup(const char* pName) {
        mAreaObjs = nullptr;
        mNumAreas = 0;
        mMaxAreas = 0;
        mGroupName = pName;
    }

    /* https://decomp.me/scratch/dCuQs */
    AreaObjGroup::AreaObjGroup(const char* a1, const char* a2, const ActorInitInfo& rInfo)
        : mNumAreas(0), mMaxAreas(0) {
        mAreaObjs = nullptr;
        mGroupName = a1;
        AreaInitInfo initInfo;
        s32 linkNum = al::calcLinkChildNum(rInfo, a2);
        createBuffer(linkNum);

        for (s32 i = 0; i < linkNum; i++) {
            PlacementInfo info;
            al::getLinksInfoByIndex(&info, rInfo, a2, i);
            initInfo.set(info, rInfo.mStageSwitchDirector);
            auto areaObj = new AreaObj("name");
            areaObj->init(initInfo);
            resisterAreaObj(areaObj);
        }
    }

    void AreaObjGroup::createBuffer(s32 max) {
        mMaxAreas = max;
        createBuffer();
    }

    void AreaObjGroup::resisterAreaObj(AreaObj* pArea) {
        if (mNumAreas < mMaxAreas) {
            mAreaObjs[mNumAreas] = pArea;
            mNumAreas++;
        }
    }

    AreaObjGroup::~AreaObjGroup() {
        for (s32 i = 0; i < mNumAreas; i++) {
            delete[] mAreaObjs[i];
        }
        delete mAreaObjs;
    }

    void AreaObjGroup::incrementCount() {
        mMaxAreas++;
    }

    void AreaObjGroup::createBuffer() {
        if (mMaxAreas >= 1) {
            if (al::isEqualString(mGroupName, "CameraArea")) {
                mMaxAreas += 130;
            }

            mAreaObjs = new AreaObj*[mMaxAreas];
        }
    }

    AreaObj* AreaObjGroup::getAreaObj(s32 idx) const {
        return mAreaObjs[idx];
    }

    AreaObj* AreaObjGroup::getInVolumeAreaObj(const sead::Vector3f& rVec) {
        AreaObj* prioArea = nullptr;

        for (s32 i = 0; i < mMaxAreas; i++) {
            auto curArea = getAreaObj(i);

            if (prioArea == nullptr || prioArea->mPriority <= curArea->mPriority) {
                if (curArea->isInVolume(rVec)) {
                    prioArea = curArea;
                }
            }
        }

        return prioArea;
    }

    s32 AreaObjGroup::getInVolumeAreaObj(const sead::Vector3f& rVec, AreaObj** pArea) {
        s32 numObjs = 0;
        AreaObj* obj = nullptr;

        for (s32 i = 0; i < mNumAreas; i++) {
            AreaObj* curArea = getAreaObj(i);

            if ((obj == nullptr || obj->mPriority <= curArea->mPriority) && curArea->mIsValid &&
                !curArea->mIsDisabled) {
                if (curArea->_66) {
                    numObjs++;

                    if (curArea->isInVolume(rVec)) {
                        obj = curArea;
                    }
                }
            }
        }

        *pArea = obj;
        return numObjs;
    }

    AreaObj* AreaObjGroup::getInVolumeAreaObj(const sead::Vector3f& a1, const sead::Vector3f& a2,
                                              sead::Vector3f* a3, sead::Vector3f* a4) {
        AreaObj* highPrioArea = nullptr;

        for (s32 i = 0; i < mNumAreas; i++) {
            auto areaObj = getAreaObj(i);

            if (highPrioArea == nullptr || highPrioArea->mPriority <= areaObj->mPriority) {
                if (areaObj->isInVolume(a1, a2, a3, a4)) {
                    highPrioArea = areaObj;
                }
            }
        }

        return highPrioArea;
    }

    AreaObj* AreaObjGroup::getInFirstAreaObj(const sead::Vector3f& rVec) {
        s32 num = mNumAreas;
        for (s32 i = 0; i < num; i++) {
            auto areaObj = getAreaObj(i);

            if (areaObj != nullptr) {
                if (areaObj->isInVolume(rVec)) {
                    return areaObj;
                }
            }
        }

        return nullptr;
    }
};  // namespace al