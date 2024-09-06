#pragma once

#include <types.hpp>

namespace al {
    class PlacementInfo;

    class PlacementId {
    public:
        PlacementId();
        PlacementId(const char*, const char*, const char*, const char*);

        void init(const PlacementInfo&);
        bool isEqual(const PlacementId&) const;
        static bool isEqual(const PlacementId&, const PlacementId&);

        const char* mPlacementID = nullptr;      // 0x00
        const char* mLayerConfigName = nullptr;  // 0x08
        const char* mUnitConfigName = nullptr;   // 0x10
        const char* mZoneID = nullptr;           // 0x18
        const char* mCommonID = nullptr;         // 0x20
    };
};  // namespace al