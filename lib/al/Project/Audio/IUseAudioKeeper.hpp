#pragma once

#include <seadTypes.h>

namespace al {
    class AudioKeeper;

    class IUseAudioKeeper {
    public:
        virtual AudioKeeper* getAudioKeeper() const = 0;
    };
};