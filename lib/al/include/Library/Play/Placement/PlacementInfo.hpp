#pragma once

#include "Library/Yaml/ByamlIter.hpp"

namespace al {
struct PlacementInfo {
    PlacementInfo();

    inline PlacementInfo(const PlacementInfo& rInfo)
        : placementIter(rInfo.placementIter), zoneIter(rInfo.zoneIter) {
        auto inf = rInfo._20;
        _28 = rInfo._28;
        _20 = inf;
    }

    void set(const ByamlIter&, const ByamlIter&, PlacementInfo*, s32);

    ByamlIter placementIter;
    ByamlIter zoneIter;
    PlacementInfo* _20 = nullptr;
    s32 _28 = -1;
};
}  // namespace al
