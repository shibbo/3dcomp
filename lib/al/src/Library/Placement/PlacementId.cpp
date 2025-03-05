#include "Library/Placement/PlacementId.hpp"
#include "Library/Placement/PlacementInfo.hpp"
#include "Project/Base/StringUtil.hpp"

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

        rInfo.mPlacementIter.tryGetStringByKey(&mCommonID, "CommonId");
        rInfo.mPlacementIter.tryGetStringByKey(&mLayerConfigName, "LayerConfigName");
        rInfo.mZoneIter.tryGetStringByKey(&mUnitConfigName, "UnitConfigName");
        rInfo.mZoneIter.tryGetStringByKey(&mZoneID, "Id");
        return rInfo.mPlacementIter.tryGetStringByKey(&mPlacementID, "Id");
    }

    // bool PlacementId::isEqual(const PlacementId& rOther)

    bool PlacementId::isEqual(const PlacementId& lhs, const PlacementId& rhs) {
        return lhs.isEqual(rhs);
    }

};  // namespace al