#pragma once

#include "Library/Yaml/ByamlIter.hpp"

namespace al {
    class PlacementInfo {
    public:
        PlacementInfo();

        inline PlacementInfo(const PlacementInfo& rInfo)
            : mPlacementIter(rInfo.mPlacementIter), mZoneIter(rInfo.mZoneIter) {
            auto inf = rInfo._20;
            _28 = rInfo._28;
            _20 = inf;
        }

        void set(const ByamlIter&, const ByamlIter&, PlacementInfo*, s32);

        ByamlIter mPlacementIter;  // 0x00
        ByamlIter mZoneIter;       // 0x10
        PlacementInfo* _20 = nullptr;
        s32 _28 = -1;
    };
};  // namespace al