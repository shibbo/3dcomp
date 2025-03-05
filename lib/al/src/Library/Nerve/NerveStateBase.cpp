#include "Library/Nerve/NerveStateBase.hpp"

namespace al {
    NerveStateBase::NerveStateBase(const char *pName) : NerveExecutor(pName) { }

    bool NerveStateBase::update() {
        NerveExecutor::updateNerve();

        if (mIsDead) {
            return true;
        }

        control();
        return mIsDead;
    }

    ActorStateBase::ActorStateBase(const char *pName, LiveActor *pActor) : NerveStateBase(pName) {
        mHostActor = pActor;
    }

    NerveStateBase::~NerveStateBase() {

    }

    ActorStateBase::~ActorStateBase() {
        
    }
}