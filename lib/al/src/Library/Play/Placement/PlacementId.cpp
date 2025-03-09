#include "Library/Play/Placement/PlacementId.hpp"

#include "Library/Play/Placement/PlacementInfo.hpp"

namespace al {
PlacementId::PlacementId() {}

PlacementId::PlacementId(const char* pID, const char* pConfig, const char* pZone,
                         const char* pCommon) {
    mPlacementID = pID;
    mLayerConfigName = pConfig;
    mUnitConfigName = pZone;
    mZoneID = pCommon;
    mCommonID = nullptr;
}

bool PlacementId::init(const PlacementInfo& rInfo) {
    mPlacementID = nullptr;
    mCommonID = nullptr;
    mZoneID = nullptr;
    mUnitConfigName = nullptr;
    mLayerConfigName = nullptr;

    rInfo.placementIter.tryGetStringByKey(&mCommonID, "CommonId");
    rInfo.placementIter.tryGetStringByKey(&mLayerConfigName, "LayerConfigName");
    rInfo.zoneIter.tryGetStringByKey(&mUnitConfigName, "UnitConfigName");
    rInfo.zoneIter.tryGetStringByKey(&mZoneID, "Id");
    return rInfo.placementIter.tryGetStringByKey(&mPlacementID, "Id");
}

// bool PlacementId::isEqual(const PlacementId& rOther)

bool PlacementId::isEqual(const PlacementId& lhs, const PlacementId& rhs) {
    return lhs.isEqual(rhs);
}

}  // namespace al
