#pragma once

namespace al {
    class EffectKeeper;

    class IUseEffectKeeper {
    public:
        virtual EffectKeeper* getEffectKeeper() const = 0;
    };
};