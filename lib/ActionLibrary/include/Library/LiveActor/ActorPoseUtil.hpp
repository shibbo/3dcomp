#pragma once

#include <math/seadVector.hpp>

namespace al {
    class LiveActor;

    sead::Vector3f& getScale(const LiveActor *);

    void setTrans(LiveActor *, const sead::Vector3f &);

    bool isSingleMode(const LiveActor *);
};