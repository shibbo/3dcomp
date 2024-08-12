#pragma once

#include <types.hpp>

namespace al {
    class EffectKeeper {
    public:
        void update();
        void deleteAndClearEffectAll();

        void offCalcAndDraw();
    };
};  // namespace al