#pragma once

#include <basis/seadTypes.h>

namespace al {
class NerveStateBase;
class Nerve;

class NerveStateCtrl {
public:
    class State {
    public:
        NerveStateBase* mState;
        const Nerve* mNerve;
        const char* mName;
    };

    NerveStateCtrl(s32);

    void addState(NerveStateBase*, const Nerve*, const char*);
    bool updateCurrentState();
    void startState(const Nerve*);
    State* findStateInfo(const Nerve*);
    bool isCurrentStateEnd() const;
    void tryEndCurrentState();

    s32 mMaxStates = 0;
    s32 mNumStates = 0;
    State* mStates = nullptr;
    State* mCurrentState = nullptr;
};
}  // namespace al
