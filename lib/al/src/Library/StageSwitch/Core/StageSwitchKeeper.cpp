#include "Library/StageSwitch/Core/StageSwitchKeeper.hpp"

#include "Library/Play/Placement/PlacementFunction.hpp"
#include "Library/Play/Placement/PlacementId.hpp"
#include "Library/Play/Placement/PlacementInfo.hpp"
#include "Library/Play/Placement/PlacementUtil.hpp"
#include "Library/StageSwitch/StageSwitchAccesser.hpp"
#include "Project/Base/StringUtil.hpp"

namespace al {
StageSwitchKeeper::StageSwitchKeeper() {}

void StageSwitchKeeper::init(StageSwitchDirector* pDirector, const PlacementInfo& rInfo) {
    s32 linkCount = calcLinkCountClassName(rInfo, "StageSwitch");
    mLinkCount = linkCount;
    mAccessors = new StageSwitchAccesser[linkCount];

    PlacementInfo linksInfo;
    tryGetPlacementInfoByKey(&linksInfo, rInfo, "Links");
    s32 placementNum = getCountPlacementInfo(linksInfo);
    s32 curIndex = 0;

    for (s32 i = 0; i < placementNum; i++) {
        PlacementInfo info;
        const char* keyName = nullptr;
        tryGetPlacementInfoAndKeyNameByIndex(&info, &keyName, linksInfo, i);

        PlacementInfo curPlacement;
        tryGetPlacementInfoByIndex(&curPlacement, info, 0);
        if (isClassName(curPlacement, "StageSwitch")) {
            PlacementId placement;
            tryGetPlacementID(&placement, curPlacement);
            bool isDisaster = false;
            tryGetArg(&isDisaster, curPlacement, "IsDisasterCameraOn");
            mAccessors[curIndex].setThing(_10);
            mAccessors[curIndex].init(pDirector, keyName, placement, isDisaster);
            curIndex++;
        }
    }
}

StageSwitchAccesser* StageSwitchKeeper::tryGetStageSwitchAccesser(const char* pName) const {
    for (s32 i = 0; i < mLinkCount; i++)
        if (isEqualString(pName, mAccessors[i].mName))
            return &mAccessors[i];

    return nullptr;
}

bool StageSwitchKeeper::isUsingSwitchNo(s32 switchNo) {
    for (s32 i = 0; i < mLinkCount; i++)
        if (mAccessors[i].mSwitchNo == switchNo)
            return true;

    return false;
}
}  // namespace al
