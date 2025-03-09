#pragma once

#include <basis/seadTypes.h>

namespace al {
struct PlacementInfo;

class PlacementId {
public:
    PlacementId();
    PlacementId(const char*, const char*, const char*, const char*);

    bool init(const PlacementInfo&);
    bool isEqual(const PlacementId&) const;
    static bool isEqual(const PlacementId&, const PlacementId&);

    const char* mPlacementID = nullptr;
    const char* mLayerConfigName = nullptr;
    const char* mUnitConfigName = nullptr;
    const char* mZoneID = nullptr;
    const char* mCommonID = nullptr;
};
}  // namespace al
