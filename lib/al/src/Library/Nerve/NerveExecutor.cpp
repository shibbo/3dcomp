#include "Library/Nerve/NerveExecutor.hpp"
#include "Library/Nerve/NerveKeeper.hpp"

namespace al {
    NerveExecutor::NerveExecutor(const char *) {
        mNerveKeeper = nullptr;
    }

    NerveExecutor::~NerveExecutor() {
        delete mNerveKeeper;
    }

    void NerveExecutor::initNerve(const Nerve *pNerve, s32 numNerves) {
        mNerveKeeper = new NerveKeeper(this, pNerve, numNerves);
    }

    void NerveExecutor::updateNerve() {
        if (mNerveKeeper != nullptr) {
            mNerveKeeper->update();
        }
    }
};