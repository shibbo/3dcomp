#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
    class LiveActor;

    void syncCollisionMtx(LiveActor*, const sead::Matrix34f*);

    void preScaleMtx(sead::Matrix34f*, const sead::Vector3f&);

    void calcMtxLocalTrans(sead::Vector3f*, const sead::Matrix34f&, const sead::Vector3f&);
};  // namespace al