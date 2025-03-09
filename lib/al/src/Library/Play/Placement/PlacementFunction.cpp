#include "Library/Play/Placement/PlacementFunction.hpp"

#include "Library/Actor/ActorInitInfo.hpp"
#include "Library/Play/Placement/PlacementId.hpp"
#include "Library/Play/Placement/PlacementInfo.hpp"
#include "Library/Yaml/ByamlIter.hpp"
#include "Library/Yaml/ByamlUtil.hpp"

namespace al {
bool tryGetZoneID(s32* pId, const PlacementInfo& rInfo) {
    ByamlIter iter(rInfo.zoneIter);
    bool ret;
    if (iter.isValid())
        ret = tryGetByamlS32(pId, rInfo.zoneIter, "ZoneID");
    else
        ret = false;

    return ret;
}

// tryGetDisplayOffset

// minor stack issue
bool tryGetDisplayScale(sead::Vector3f* pVector, const ActorInitInfo& rInfo) {
    PlacementInfo info;
    PlacementInfo* actorInfo = rInfo.mPlacementInfo;
    ByamlIter iter;

    if (actorInfo->placementIter.tryGetIterByKey(&iter, "UnitConfig"))
        info.set(iter, actorInfo->zoneIter, actorInfo->_20, actorInfo->_28);

    return tryGetByamlV3f(pVector, info.placementIter, "DisplayScale");
}

bool isSingleMode(const ActorInitInfo& rInfo) {
    return rInfo._78;
}

bool isExistLinkChild(const PlacementInfo& rInfo, const char* pLinkName, s32 idx) {
    return calcLinkChildNum(rInfo, pLinkName) > idx;
}
}  // namespace al

namespace alPlacementFunction {
bool getClippingViewId(al::PlacementId* pId, const al::PlacementInfo& rInfo) {
    al::PlacementInfo info;
    if (tryGetLinksInfo(&info, rInfo, "ViewGroup")) {
        if (pId->init(info))
            return true;
    }

    return false;
}

bool getClippingViewId(al::PlacementId* pId, const al::ActorInitInfo& rInfo) {
    al::PlacementInfo* linksInfo = rInfo.mPlacementInfo;
    al::PlacementInfo info;
    if (tryGetLinksInfo(&info, *linksInfo, "ViewGroup")) {
        if (pId->init(info))
            return true;
    }

    return false;
}
}  // namespace alPlacementFunction
