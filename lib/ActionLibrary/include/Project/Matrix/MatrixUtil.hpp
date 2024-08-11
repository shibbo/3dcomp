#pragma once

#include <math/seadMatrix.hpp>
#include <math/seadVector.hpp>

namespace al {
    class LiveActor;

    void syncCollisionMtx(LiveActor *, const sead::Matrix34f *);

    void preScaleMtx(sead::Matrix34f *, const sead::Vector3f &);
};