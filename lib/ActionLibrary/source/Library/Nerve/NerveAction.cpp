#include "Library/Nerve/NerveAction.hpp"

namespace alNerveFunction {
    void NerveActionCollector::addNerve(al::NerveAction* pAction) {
        if (mStartAction == nullptr) {
            mStartAction = pAction;

        } else {
            mEndAction->mNextNode = pAction;
        }

        mEndAction = pAction;
        mNumActions++;
    }

    NerveActionCollector::NerveActionCollector() {
        sCurrentCollector = this;
    }

};  // namespace alNerveFunction