#pragma once

namespace al {
    class LiveActor;

    bool isDead(const LiveActor*);

    bool isClipped(const LiveActor*);

    bool isHideModel(const LiveActor*);

    void setVelocityZero(LiveActor*);

    void invalidateClipping(LiveActor*);
    void validateClipping(LiveActor*);
};  // namespace al