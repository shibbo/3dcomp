#pragma once

#include "Library/Nerve/NerveKeeper.hpp"

namespace al {
    class Nerve {
    public:
        virtual void execute(NerveKeeper*) const = 0;

        virtual void executeOnEnd(NerveKeeper*) const {}
    };
};  // namespace al