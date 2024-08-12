#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include <types.hpp>

namespace al {
    class ActorInitInfo;
    class PlacementInfo;

    bool tryGetZoneMatrixTR(sead::Matrix34f*, const ActorInitInfo&);
    bool tryGetZoneID(s32*, const PlacementInfo&);

    bool tryGetArg(s32*, const PlacementInfo&, const char*);

    bool tryGetArg(f32*, const PlacementInfo&, const char*);

    bool tryGetArg(bool*, const PlacementInfo&, const char*);

    bool tryGetScale(sead::Vector3f*, const PlacementInfo&);

    bool tryGetMatrixTR(sead::Matrix34f*, const PlacementInfo&);
};  // namespace al

namespace alPlacementFunction {
    bool tryGetModelName(const char**, const al::PlacementInfo&);
};