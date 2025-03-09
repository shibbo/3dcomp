#include "Library/Play/Placement/PlacementInfo.hpp"

namespace al {
PlacementInfo::PlacementInfo() {}

void PlacementInfo::set(const ByamlIter& rPlacementIter, const ByamlIter& rZoneIter,
                        PlacementInfo* pInfo, s32 a4) {
    placementIter = rPlacementIter;
    zoneIter = rZoneIter;
    _20 = pInfo;
    _28 = a4;
}
}  // namespace al
