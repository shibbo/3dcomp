#pragma once

#include <basis/seadTypes.h>

#include "Library/Nerve/Nerve.hpp"

namespace al {
class NerveAction : public Nerve {
public:
    NerveAction();

    virtual const char* getActionName() const = 0;

    NerveAction* mNextNode;
};
}  // namespace al

namespace alNerveFunction {
class NerveActionCollector {
public:
    NerveActionCollector();

    void addNerve(al::NerveAction*);

    void alt(al::NerveAction* pAction) {
        if (mStartAction != nullptr)
            mEndAction->mNextNode = pAction;
        else
            mStartAction = pAction;
    }

    static NerveActionCollector* sCurrentCollector;

    s32 mNumActions = 0;
    u32 _4;
    al::NerveAction* mStartAction = nullptr;
    al::NerveAction* mEndAction = nullptr;
};
}  // namespace alNerveFunction
