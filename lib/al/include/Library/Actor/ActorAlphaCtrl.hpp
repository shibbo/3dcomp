#pragma once

#include <basis/seadTypes.h>

namespace al {
    class ClippingJudge;

    class ActorAlphaCtrl {
    public:
        f32 update(const ClippingJudge*);
    };
};  // namespace al