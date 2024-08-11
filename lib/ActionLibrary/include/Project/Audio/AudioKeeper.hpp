#pragma once

#include <types.hpp>

namespace al {
    class AudioDirector;
    class BgmKeeper;
    class SeKeeper;

    class AudioKeeper {
    public:

        void initBgmKeeper(const AudioDirector *, const char *);
        void initOtherAuido(const AudioDirector *);
        void update();
        void startClipped();
        void endClipped();
        void appear();
        void kill();

        void* _0;
        void* _8;
        void* _10;
        void* _18;
        SeKeeper* mSeKeeper;            // 0x20
        BgmKeeper* mBgmKeeper;          // 0x28
        void* _30;
        void* _38;
        void* _40;
        u8 _48;
    };
};