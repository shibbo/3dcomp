#pragma once

#include <math/seadVector.hpp>

namespace al {
    class LiveActor;

    sead::Vector3f& getGravity(const LiveActor *);
    sead::Vector3f& getTrans(const LiveActor *);
    sead::Vector3f& getScale(const LiveActor *);
};