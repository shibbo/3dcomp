#pragma once

#include <types.hpp>

namespace al {
    class NerveAction {
    public:

    };
};

namespace alNerveFunction {
    class NerveActionCollector {
    public:
        NerveActionCollector();

        void addNerve(al::NerveAction *);

        static NerveActionCollector sCurrentCollector;

        s32 mNumActions;                // 0x00
        u32 _4;
        al::NerveAction** mActions;     // 0x08
        void* _10;
    };
};