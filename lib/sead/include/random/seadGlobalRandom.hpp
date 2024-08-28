#pragma once

#include "heap/seadDisposer.hpp"
#include "random/seadRandom.hpp"

namespace sead {
    class GlobalRandom : public Random {
    public:
        SEAD_SINGLETON_DISPOSER(GlobalRandom)

        GlobalRandom() = default;
    };

    class GlobalRandomNonSync : public Random {
    public:
        SEAD_SINGLETON_DISPOSER(GlobalRandomNonSync)

        GlobalRandomNonSync() = default;
    };
};  // namespace sead