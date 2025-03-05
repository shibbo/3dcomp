#pragma once

#include <basis/seadTypes.h>

namespace al {
    class AudioKeeper;

    class IUseAudioKeeper {
    public:
        virtual AudioKeeper* getAudioKeeper() const = 0;
    };
};