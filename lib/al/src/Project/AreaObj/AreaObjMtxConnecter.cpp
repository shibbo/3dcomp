#include "Project/AreaObj/AreaObjMtxConnecter.hpp"

#include <math/seadMatrix.hpp>
#include <math/seadMatrixCalcCommon.hpp>

#include "Library/Play/Placement/PlacementFunction.hpp"

namespace al {

AreaObjMtxConnecter::AreaObjMtxConnecter(AreaObj* pArea, const PlacementInfo& rInfo)
    : mAreaObj(pArea), _40(rInfo) {
    _8 = mAreaObj->_28;
}

bool AreaObjMtxConnecter::trySetParentMtx(const sead::Matrix34f* pMtx, const PlacementInfo& rInfo) {
    if (!isEqualPlacementID(_40, rInfo))
        return false;

    _38 = new MtxConnector();
    _38->init(pMtx);
    return true;
}

bool AreaObjMtxConnecter::trySyncParentMtx(const sead::Matrix34f* pMtx,
                                           const PlacementInfo& rInfo) {
    if (!isEqualPlacementID(_40, rInfo))
        return false;

    _8 = *pMtx;
    _38 = new MtxConnector();
    _38->init(pMtx);
    return true;
}

void AreaObjMtxConnecter::update() {
    if (_38 != nullptr)
        _38->multMtx(&mAreaObj->_28, _8);
}

AreaObjMtxConnecterHolder::AreaObjMtxConnecterHolder(s32 maxConnecters)
    : mNumConnecters(0), mMaxNumConnecters(maxConnecters) {
    mConnecters = new AreaObjMtxConnecter*[maxConnecters];

    for (s32 i = 0; i < mMaxNumConnecters; i++)
        mConnecters[i] = nullptr;
}

bool AreaObjMtxConnecterHolder::tryAddArea(AreaObj* pArea, const PlacementInfo& rInfo) {
    s32 linkNum = calcLinkChildNum(rInfo, "NoDelete_FollowMtxTarget");

    if (linkNum != 0) {
        PlacementInfo info;
        getLinksInfo(&info, rInfo, "NoDelete_FollowMtxTarget");
        mConnecters[mNumConnecters] = new AreaObjMtxConnecter(pArea, info);
        mNumConnecters++;
        return true;
    }

    return false;
}

void AreaObjMtxConnecterHolder::registerParentMtx(const sead::Matrix34f* pMtx,
                                                  const PlacementInfo& rInfo) {
    for (s32 i = 0; i < mNumConnecters; i++) {
        AreaObjMtxConnecter* connecter = mConnecters[i];

        if (isEqualPlacementID(connecter->_40, rInfo)) {
            MtxConnector* mtxCon = new MtxConnector();
            connecter->_38 = mtxCon;
            mtxCon->init(pMtx);
        }
    }
}

void AreaObjMtxConnecterHolder::registerSyncParentMtx(const sead::Matrix34f* pMtx,
                                                      const PlacementInfo& rInfo) {
    for (s32 i = 0; i < mNumConnecters; i++) {
        AreaObjMtxConnecter* connecter = mConnecters[i];

        if (isEqualPlacementID(connecter->_40, rInfo)) {
            connecter->_8 = *pMtx;
            MtxConnector* mtxCon = new MtxConnector();
            connecter->_38 = mtxCon;
            mtxCon->init(pMtx);
        }
    }
}

void AreaObjMtxConnecterHolder::update() {
    for (s32 i = 0; i < mNumConnecters; i++)
        mConnecters[i]->update();
}

}  // namespace al
