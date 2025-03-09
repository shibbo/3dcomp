#pragma once

#include "Library/Connector/MtxConnector.hpp"
#include "Library/Play/Placement/PlacementInfo.hpp"
#include "Project/AreaObj/AreaObj.hpp"

namespace al {
class AreaObjMtxConnecter {
public:
    AreaObjMtxConnecter(AreaObj*, const PlacementInfo&);

    bool trySetParentMtx(const sead::Matrix34f*, const PlacementInfo&);
    bool trySyncParentMtx(const sead::Matrix34f*, const PlacementInfo&);
    void update();

    AreaObj* mAreaObj;
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

    AreaObjMtxConnecter** mConnecters;
    s32 mNumConnecters;
    s32 mMaxNumConnecters;
};
}  // namespace al
