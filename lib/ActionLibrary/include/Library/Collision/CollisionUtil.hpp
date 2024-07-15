#pragma once

#include <math/seadMatrix.hpp>

namespace al {
    class LiveActor;

    bool isCollidedGround(const LiveActor *);

    void validateCollisionPartsBySystem(LiveActor *);
    void invalidateCollisionPartsBySystem(LiveActor *);

    void syncCollisionMtx(LiveActor *, const sead::Matrix34f &);

    const char* getCollidedFloorMaterialCodeName(const LiveActor *);
    const char* getCollidedWallMaterialCodeName(const LiveActor *);
    const char* getCollidedCeilingMaterialCodeName(const LiveActor *);

    bool isUpdateMovementEffectAudioCollision(const LiveActor *);
};