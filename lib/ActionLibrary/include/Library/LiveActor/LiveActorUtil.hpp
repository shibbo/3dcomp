#pragma once

namespace al {
    class LiveActor;

    bool isDead(const LiveActor *);

    bool isClipped(const LiveActor *);

    bool isHideModel(const LiveActor *);

    void setVelocityZero(LiveActor *);

    void validateClipping(LiveActor *);
};