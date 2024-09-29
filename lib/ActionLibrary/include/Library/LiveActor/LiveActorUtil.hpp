#pragma once

namespace al {
    class ActorInitInfo;
    class LiveActor;

    bool isAlive(const LiveActor*);
    bool isDead(const LiveActor*);
    bool isDeadAlive(const LiveActor*);
    bool isCountAsAlive(LiveActor*);
    bool isNoCollide(const LiveActor*);

    bool isClipped(const LiveActor*);

    bool isHideModel(const LiveActor*);

    void setVelocityZero(LiveActor*);

    void invalidateClipping(LiveActor*);
    void validateClipping(LiveActor*);

    void initMapPartsActor(LiveActor*, const ActorInitInfo&, const char*, s32);
};  // namespace al