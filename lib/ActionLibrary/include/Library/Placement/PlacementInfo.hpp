#pragma once

#include "Library/Yaml/ByamlIter.hpp"

namespace al {
    class PlacementInfo {
    public:
        PlacementInfo();

        inline PlacementInfo(const PlacementInfo& rInfo) : _0(rInfo._0), _10(rInfo._10) {
            auto inf = rInfo._20;
            _28 = rInfo._28;
            _20 = inf;
        }

        void set(const ByamlIter&, const ByamlIter&, PlacementInfo*, s32);

        ByamlIter _0;
        ByamlIter _10;
        PlacementInfo* _20;
        s32 _28;
    };
};  // namespace al