#pragma once

namespace al {
    class ClippingJudge;
    class LiveActor;

    ClippingJudge* getClippingJudge(LiveActor *);

    bool isInvalidCliping(const LiveActor *);
};