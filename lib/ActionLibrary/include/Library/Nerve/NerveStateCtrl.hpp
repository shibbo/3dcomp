#pragma once

#include <types.hpp>

namespace al {
    class NerveStateBase;
    class Nerve;

    class NerveStateCtrl {
    public:
        struct State {
            NerveStateBase* mState;         // 0x00
            const Nerve* mNerve;            // 0x08
            const char* mName;              // 0x10
        };

        NerveStateCtrl(s32);

        void addState(NerveStateBase *, const Nerve *, const char *);
        void updateCurrentState();
        void startState(const Nerve *);
        State* findStateInfo(const Nerve *);
        bool isCurrentStateEnd() const;
        void tryEndCurrentState();

        u32 mMaxStates;             // 0x00
        u32 mNumStates;             // 0x04
        State* mStates;             // 0x08
        State* mCurrentState;       // 0x10
    };
};