#pragma once

#include <math/seadMatrix.h>

namespace al {
    class LiveActor;

    bool isCollidedGround(const LiveActor*);
    bool isCollidedWall(const LiveActor*);
    bool isCollidedCeiling(const LiveActor*);

    void validateCollisionParts(LiveActor*);
    void invalidateCollisionParts(LiveActor*);

    void validateCollisionPartsBySystem(LiveActor*);
    void invalidateCollisionPartsBySystem(LiveActor*);

    void validateAllCollisionParts(LiveActor*);
    void invalidateAllCollisionParts(LiveActor*);
    void disableAllCollisionParts(LiveActor*);
    void enableAllCollisionParts(LiveActor*);
    bool isValidCollisionParts(const LiveActor*);

    void syncCollisionMtx(LiveActor*, const sead::Matrix34f&);

    const char* getCollidedFloorMaterialCodeName(const LiveActor*);
    const char* getCollidedWallMaterialCodeName(const LiveActor*);
    const char* getCollidedCeilingMaterialCodeName(const LiveActor*);

    bool isUpdateMovementEffectAudioCollision(const LiveActor*);
};  // namespace al