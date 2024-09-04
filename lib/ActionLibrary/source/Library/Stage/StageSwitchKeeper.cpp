#include "Library/Stage/StageSwitchKeeper.hpp"
#include "Library/Placement/PlacementFunction.hpp"
#include "Library/Placement/PlacementId.hpp"
#include "Library/Stage/StageSwitchAccesser.hpp"
#include "Project/Base/StringUtil.hpp"

namespace al {
    StageSwitchKeeper::StageSwitchKeeper() {}

    void StageSwitchKeeper::init(StageSwitchDirector* pDirector, const PlacementInfo& rInfo) {
        s32 linkCount = al::calcLinkCountClassName(rInfo, "StageSwitch");
        mLinkCount = linkCount;
        mAccessors = new StageSwitchAccesser[linkCount];

        PlacementInfo linksInfo;
        al::tryGetPlacementInfoByKey(&linksInfo, rInfo, "Links");
        s32 placementNum = al::getCountPlacementInfo(linksInfo);
        s32 curIndex = 0;

        for (s32 i = 0; i < placementNum; i++) {
            PlacementInfo info;
            const char* keyName = nullptr;
            al::tryGetPlacementInfoAndKeyNameByIndex(&info, &keyName, linksInfo, i);

            PlacementInfo curPlacement;
            al::tryGetPlacementInfoByIndex(&curPlacement, info, 0);
            if (al::isClassName(curPlacement, "StageSwitch")) {
                PlacementId placement;
                al::tryGetPlacementID(&placement, curPlacement);
                bool isDisaster = false;
                al::tryGetArg(&isDisaster, curPlacement, "IsDisasterMode");
                mAccessors[curIndex].setThing(_10);
                mAccessors[curIndex].init(pDirector, keyName, placement, isDisaster);
                curIndex++;
            }
        }
    }

    StageSwitchAccesser* StageSwitchKeeper::tryGetStageSwitchAccesser(const char* pName) const {
        for (s32 i = 0; i < mLinkCount; i++) {
            if (al::isEqualString(pName, mAccessors[i].mName)) {
                return &mAccessors[i];
            }
        }

        return nullptr;
    }

    bool StageSwitchKeeper::isUsingSwitchNo(s32 switchNo) {
        for (s32 i = 0; i < mLinkCount; i++) {
            if (mAccessors[i].mSwitchNo == switchNo) {
                return true;
            }
        }

        return false;
    }
};  // namespace al