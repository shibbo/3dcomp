#pragma once

#include <types.hpp>

namespace al {
    class ClippingJudge;

    class ActorAlphaCtrl {
    public:
        f32 update(const ClippingJudge*);
    };
};  // namespace al