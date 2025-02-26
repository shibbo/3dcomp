#pragma once

#include <seadTypes.h>

namespace al {
    class NerveStateBase;
    class Nerve;

    class NerveStateCtrl {
    public:
        class State {
        public:
            NerveStateBase* mState;  // 0x00
            const Nerve* mNerve;     // 0x08
            const char* mName;       // 0x10
        };

        NerveStateCtrl(s32);

        void addState(NerveStateBase*, const Nerve*, const char*);
        bool updateCurrentState();
        void startState(const Nerve*);
        State* findStateInfo(const Nerve*);
        bool isCurrentStateEnd() const;
        void tryEndCurrentState();

        s32 mMaxStates = 0;              // 0x00
        s32 mNumStates = 0;              // 0x04
        State* mStates = nullptr;        // 0x08
        State* mCurrentState = nullptr;  // 0x10
    };
};  // namespace al