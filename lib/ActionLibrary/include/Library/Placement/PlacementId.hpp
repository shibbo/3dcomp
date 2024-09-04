#pragma once

#include <types.hpp>

namespace al {
    class PlacementId {
    public:
        PlacementId();

        const char* mID;              // 0x00
        const char* mUnitConfigName;  // 0x08
        const char* mZoneID;          // 0x10
        const char* mCommonID;        // 0x18
        const char* _20;
    };
};  // namespace al