#pragma once

#include <seadTypes.h>

namespace al {
    class BgmLine {
    public:
        BgmLine(f32);

        void pauseBgm(s32);
        void resumeBgm(s32);

        const char* getLineName() const;
        bool isPause() const;

        void stopAllBgmPlayer(s32);

        void changeSituation(const char*, bool);

        bool isRunning() const;
    };
};  // namespace al