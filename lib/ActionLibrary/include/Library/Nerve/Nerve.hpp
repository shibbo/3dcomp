#pragma once

#include "Library/Nerve/NerveKeeper.hpp"

namespace al {
    class Nerve {
    public:
        virtual void execute(NerveKeeper*) const = 0;

        virtual void executeOnEnd(NerveKeeper*) const {}
    };
};  // namespace al

#define NERVE_DECL(Class, Action)                                                                  \
    class Class##Nrv##Action : public al::Nerve {                                                  \
    public:                                                                                        \
        void execute(al::NerveKeeper* pKeeper) const override {                                    \
            (pKeeper->getParent<Class>())->exe##Action();                                          \
        }                                                                                          \
    };

#define NERVE_IMPL(Class, Action) Class##Nrv##Action Action;