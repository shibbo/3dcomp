#include "Library/Placement/PlacementFunction.hpp"
#include "Library/Placement/PlacementInfo.hpp"
#include "Library/Placement/PlacementId.hpp"
#include "Library/Yaml/ByamlIter.hpp"
#include "Library/Yaml/ByamlUtil.hpp"
#include "Library/Actor/ActorInitInfo.hpp"

namespace al {
    bool tryGetZoneID(s32 *pId, const PlacementInfo &rInfo) {
        ByamlIter iter(rInfo.mZoneIter);
        bool ret;
        if (iter.isValid()) {
            ret = al::tryGetByamlS32(pId, rInfo.mZoneIter, "ZoneID");
        }
        else {
            ret = false;
        }

        return ret;
    }

    // al::tryGetDisplayOffset

    // minor stack issue
    bool tryGetDisplayScale(sead::Vector3f *pVector, const ActorInitInfo &rInfo) {
        PlacementInfo info;
        PlacementInfo* actorInfo = rInfo.mPlacementInfo;
        ByamlIter iter;
        
        if (actorInfo->mPlacementIter.tryGetIterByKey(&iter, "UnitConfig")) {
            info.set(iter, actorInfo->mZoneIter, actorInfo->_20, actorInfo->_28);
        }

        return al::tryGetByamlV3f(pVector, info.mPlacementIter, "DisplayScale");
    }

    bool isSingleMode(const ActorInitInfo &rInfo) {
        return rInfo._78;
    }

    bool isExistLinkChild(const PlacementInfo &rInfo, const char *pLinkName, s32 idx) {
        return calcLinkChildNum(rInfo, pLinkName) > idx;
    }
};

namespace alPlacementFunction {
    bool getClippingViewId(al::PlacementId *pId, const al::PlacementInfo &rInfo) {
        al::PlacementInfo info;
        if (al::tryGetLinksInfo(&info, rInfo, "ViewGroup")) {
            if (pId->init(info)) {
                return true;
            }
        }

        return false;
    }

    bool getClippingViewId(al::PlacementId *pId, const al::ActorInitInfo &rInfo) {
        al::PlacementInfo* linksInfo = rInfo.mPlacementInfo;
        al::PlacementInfo info;
        if (al::tryGetLinksInfo(&info, *linksInfo, "ViewGroup")) {
            if (pId->init(info)) {
                return true;
            }
        }

        return false;
    }
};