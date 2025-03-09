#include "Library/Nerve/NerveKeeper.hpp"

#include "Library/Nerve/Nerve.hpp"
#include "Library/Nerve/NerveStateCtrl.hpp"

namespace al {
NerveKeeper::NerveKeeper(void* pUser, const Nerve* pNerve, s32 numStates) {
    mKeeperUser = reinterpret_cast<IUseNerve*>(pUser);
    mLastNerve = nullptr;
    mNerve = pNerve;
    mNerveStep = 0;
    mStateCtrl = nullptr;
    mActionCtrl = nullptr;

    if (numStates >= 1)
        mStateCtrl = new NerveStateCtrl(numStates);
}

void NerveKeeper::update() {
    const Nerve* nrv = mNerve;
    if (nrv != nullptr) {
        if (mStateCtrl != nullptr) {
            mStateCtrl->tryEndCurrentState();
            mStateCtrl->startState(mNerve);
            nrv = mNerve;
        }

        mLastNerve = nrv;
        mNerve = nullptr;
        mNerveStep = 0;
    } else {
        nrv = mLastNerve;
    }

    nrv->execute(this);
    mNerveStep++;

    if (mNerve != nullptr) {
        if (mStateCtrl != nullptr) {
            mStateCtrl->tryEndCurrentState();
            mStateCtrl->startState(mNerve);
            nrv = mNerve;
        }

        mLastNerve = mNerve;
        mNerve = nullptr;
        mNerveStep = 0;
    }
}

void NerveKeeper::tryChangeNerve() {
    if (mNerve != nullptr) {
        if (mStateCtrl != nullptr) {
            mStateCtrl->tryEndCurrentState();
            mStateCtrl->startState(mNerve);
        }

        mLastNerve = mNerve;
        mNerve = nullptr;
        mNerveStep = 0;
    }
}

void NerveKeeper::setNerve(const Nerve* pNerve) {
    if ((mNerveStep & 0x80000000) == 0) {
        if (mLastNerve != nullptr)
            mLastNerve->executeOnEnd(this);
    }

    mNerve = pNerve;
    mNerveStep = -1;
}

const Nerve* NerveKeeper::getCurrentNerve() const {
    if (mNerve == nullptr)
        return mLastNerve;

    return mNerve;
}

void NerveKeeper::initNerveAction(NerveActionCtrl* pCtrl) {
    mActionCtrl = pCtrl;
}
}  // namespace al
