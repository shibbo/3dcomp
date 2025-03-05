#include "Library/Stage/StageSwitchListener.hpp"

namespace al {
    StageSwitchFunctorListener::StageSwitchFunctorListener() {}

    void StageSwitchFunctorListener::setOnFunctor(const FunctorBase& rFunc) {
        mOnFunctor = rFunc.clone();
    }

    void StageSwitchFunctorListener::setOffFunctor(const FunctorBase& rFunc) {
        mOffFunctor = rFunc.clone();
    }

    void StageSwitchFunctorListener::listenOn() {
        if (mOnFunctor != nullptr) {
            (*mOnFunctor)();
        }
    }

    void StageSwitchFunctorListener::listenOff() {
        if (mOffFunctor != nullptr) {
            (*mOffFunctor)();
        }
    }
};  // namespace al