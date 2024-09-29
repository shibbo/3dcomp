#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include <types.hpp>

namespace al {
    class ActorInitInfo;
    class PlacementInfo;
    class PlacementId;

    bool tryGetZoneMatrixTR(sead::Matrix34f*, const ActorInitInfo&);
    bool tryGetZoneID(s32*, const PlacementInfo&);

    bool tryGetArg(s32*, const ActorInitInfo&, const char*);
    bool tryGetArg(s32*, const PlacementInfo&, const char*);

    bool tryGetArg(f32*, const PlacementInfo&, const char*);

    bool tryGetArg(bool*, const PlacementInfo&, const char*);

    bool tryGetArg(bool*, const ActorInitInfo&, const char*);

    bool tryGetScale(sead::Vector3f*, const PlacementInfo&);

    bool tryGetMatrixTR(sead::Matrix34f*, const PlacementInfo&);

    s32 calcLinkChildNum(const ActorInitInfo&, const char*);

    s32 calcLinkChildNum(const PlacementInfo&, const char*);

    s32 calcLinkCountClassName(const PlacementInfo&, const char*);

    void getLinksInfo(PlacementInfo*, const PlacementInfo&, const char*);

    void getLinksInfoByIndex(PlacementInfo*, const ActorInitInfo&, const char*, s32);

    bool tryGetPlacementInfoByKey(PlacementInfo*, const PlacementInfo&, const char*);

    bool isEqualPlacementID(const PlacementInfo&, const PlacementInfo&);

    bool isSingleMode(const ActorInitInfo&);

    s32 getCountPlacementInfo(const PlacementInfo&);

    bool tryGetPlacementID(PlacementId*, const PlacementInfo&);

    bool tryGetPlacementInfoAndKeyNameByIndex(PlacementInfo*, const char**, const PlacementInfo&, s32);

    bool tryGetPlacementInfoByIndex(PlacementInfo*, const PlacementInfo&, s32);

    s32 calcLinkChildNum(const ActorInitInfo&, const char*);
};  // namespace al

namespace alPlacementFunction {
    bool tryGetModelName(const char**, const al::PlacementInfo&);
};