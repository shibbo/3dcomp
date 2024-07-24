#include "Library/Nerve/NerveStateCtrl.hpp"
#include "Library/Nerve/NerveStateBase.hpp"

namespace al {
    NerveStateCtrl::NerveStateCtrl(s32 maxStates) {
        mMaxStates = maxStates;
        mNumStates = 0;
        mStates = nullptr;
        mCurrentState = nullptr;

        mStates = new State[mMaxStates];
        for (int i = 0; i < mMaxStates; i++) {
            State* state = &mStates[i];
            state->mState = nullptr;
            state->mNerve = nullptr;
            state->mName = nullptr;
        }
    }

    void NerveStateCtrl::addState(NerveStateBase *pState, const Nerve *pNerve, const char *pName) {
        State* state = &mStates[mNumStates];
        state->mState = pState;
        state->mNerve = pNerve;
        state->mName = pName;
        mNumStates++;
    }

    bool NerveStateCtrl::updateCurrentState() {
        if (mCurrentState != nullptr) {
            return mCurrentState->mState->update();
        }

        return false;
    }

    void NerveStateCtrl::startState(const Nerve *pNerve) {
        mCurrentState = findStateInfo(pNerve);

        if (mCurrentState != nullptr) {
            mCurrentState->mState->appear();
        }
    }

    NerveStateCtrl::State* NerveStateCtrl::findStateInfo(const Nerve *pNerve) {
        for (int i = 0; i < mNumStates; i++) {
            State* state = &mStates[i];

            if (state->mNerve == pNerve) {
                return state;
            }
        }

        return nullptr;
    }

    bool NerveStateCtrl::isCurrentStateEnd() const {
        return !mCurrentState || mCurrentState->mState->mIsDead;
    }

    void NerveStateCtrl::tryEndCurrentState() {
        if (mCurrentState != nullptr) {
            if (!mCurrentState->mState->mIsDead) {
                mCurrentState->mState->kill();
                mCurrentState = nullptr;
            }
        }
    }
}; 