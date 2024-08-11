#pragma once

#include <types.hpp>

namespace al {
    class AudioKeeper;

    class IUseAudioKeeper {
    public:
        virtual AudioKeeper* getAudioKeeper() const = 0;
    };
};