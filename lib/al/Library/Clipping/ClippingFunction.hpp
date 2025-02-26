#pragma once

namespace al {
    class LiveActor;
};

namespace alClippingFunction {
    void addToClippingTarget(al::LiveActor*);
    void removeFromClippingTarget(al::LiveActor*);
};  // namespace alClippingFunction