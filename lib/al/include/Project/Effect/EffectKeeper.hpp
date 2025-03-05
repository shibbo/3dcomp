#pragma once

#include <basis/seadTypes.h>

namespace al {
    class EffectKeeper {
    public:
        void update();
        void deleteAndClearEffectAll();

        void offCalcAndDraw();
    };
};  // namespace al