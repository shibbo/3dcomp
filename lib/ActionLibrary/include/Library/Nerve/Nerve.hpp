#pragma once

namespace al {
    class NerveKeeper;

    class Nerve {
    public:
        virtual void execute(NerveKeeper*) const = 0;

        virtual void executeOnEnd(NerveKeeper*) const {}
    };
};  // namespace al