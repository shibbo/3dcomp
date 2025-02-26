#pragma once

#include "Library/Placement/PlacementInfo.hpp"
#include "Project/AreaObj/AreaObj.hpp"
#include "Project/Collision/PartsConnector.hpp"

namespace al {
    class AreaObjMtxConnecter {
    public:
        AreaObjMtxConnecter(AreaObj*, const PlacementInfo&);

        bool trySetParentMtx(const sead::Matrix34f*, const PlacementInfo&);
        bool trySyncParentMtx(const sead::Matrix34f*, const PlacementInfo&);
        void update();

        AreaObj* mAreaObj;  // 0x00
        sead::Matrix34f _8;
        MtxConnector* _38 = nullptr;
        PlacementInfo _40;
    };

    class AreaObjMtxConnecterHolder {
    public:
        AreaObjMtxConnecterHolder(s32);

        bool tryAddArea(AreaObj*, const PlacementInfo&);
        void registerParentMtx(const sead::Matrix34f*, const PlacementInfo&);
        void registerSyncParentMtx(const sead::Matrix34f*, const PlacementInfo&);
        void update();

        AreaObjMtxConnecter** mConnecters;  // 0x00
        s32 mNumConnecters;                 // 0x08
        s32 mMaxNumConnecters;              // 0x0C
    };
};  // namespace al