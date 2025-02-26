#pragma once

#include <seadTypes.h>
#include "Library/Nerve/Nerve.hpp"

namespace al {
    class NerveAction : public Nerve {
    public:
        NerveAction();

        virtual const char* getActionName() const = 0;

        NerveAction* mNextNode;
    };
};  // namespace al

namespace alNerveFunction {
    class NerveActionCollector {
    public:
        NerveActionCollector();

        void addNerve(al::NerveAction*);

        static NerveActionCollector* sCurrentCollector;

        s32 mNumActions = 0;  // 0x00
        u32 _4;
        al::NerveAction* mStartAction = nullptr;  // 0x08
        al::NerveAction* mEndAction = nullptr;    // 0x10
    };
};  // namespace alNerveFunction