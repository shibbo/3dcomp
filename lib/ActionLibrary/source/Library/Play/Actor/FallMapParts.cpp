#include "Library/Play/Actor/FallMapParts.hpp"
#include "Library/Nerve/NerveAction.hpp"
#include "Util.hpp"
#include <math/seadMathCalcCommon.h>

namespace {
    using namespace al;

    NERVE_ACTION_IMPL(FallMapParts, Appear)
    NERVE_ACTION_IMPL(FallMapParts, Wait)
    NERVE_ACTION_IMPL(FallMapParts, FallSign)
    NERVE_ACTION_IMPL(FallMapParts, Fall)
    NERVE_ACTION_IMPL(FallMapParts, End)

    NERVE_ACTIONS_MAKE_STRUCT(FallMapParts, Appear, Wait, FallSign, Fall, End)
};  // namespace

namespace al {

    FallMapParts::FallMapParts(const char* pName) : LiveActor(pName) {}

    void FallMapParts::init(const ActorInitInfo& rInfo) {
        init(rInfo, nullptr);
    }

    void FallMapParts::init(const ActorInitInfo& rInfo, const char* pName) {
        al::initNerveAction(this, "Wait", &NrvFallMapParts.mCollector, 0);
        al::initActorPoseTQSV(this);
        al::initMapPartsActor(this, rInfo, pName, 0);
        al::registerAreaHostMtx(this, rInfo);
        _144 = al::getTrans(this);
        al::tryGetArg(&mFallTime, rInfo, "FallTime");

        bool hasSwitch = al::listenStageSwitchOnOffAppear(this, al::Functor(this, &al::FallMapParts::switchAppear),
                                                          al::Functor(this, &al::FallMapParts::switchKill));

        if (hasSwitch) {
            makeActorDead();
        } else {
            makeActorAppeared();
        }
    }

    void FallMapParts::switchAppear() {
        LiveActor::appear();
        al::showModelIfHide(this);
        al::setTrans(this, _144);
        al::resetPosition(this, false);
        al::startAction(this, "Wait");
        al::startNerveAction(this, "Wait");
        al::validateCollisionParts(this);
    }

    void FallMapParts::switchKill() {
        LiveActor::kill();
    }

    bool FallMapParts::receiveMsg(const SensorMsg* pMsg, HitSensor* pSrc, HitSensor* pTarget) {
        if (!al::isMsgFloorTouch(pMsg)) {
            return false;
        }

        if (!al::isNerve(this, NrvFallMapParts.Wait.data())) {
            return false;
        }

        al::startNerveAction(this, "FallSign");
        al::invalidateClipping(this);
        return true;
    }

    void FallMapParts::exeAppear() {
        if (al::isFirstStep(this) &&
            ((al::validateCollisionParts(this), al::tryStartMclAnimIfExist(this, "Wait"), !al::tryStartAction(this, "Appear")) ||
             !al::isExistAction(this) || al::isActionEnd(this))) {
            al::startNerveAction(this, "Wait");
        }
    }

    void FallMapParts::exeWait() {
        if (al::isFirstStep(this)) {
            al::tryStartAction(this, "Wait");
            al::showModelIfHide(this);
            al::validateClipping(this);
        }
    }

    /*
    void FallMapParts::exeFallSign() {
        if (al::isFirstStep(this)) {
            _154 = al::tryStartAction(this, "FallSign");

            if (!_154) {
                f32 offs = sead::MathCalcCommon<f32>::sin(al::calcNerveValue(this, 20, 0.0f, 9.4248f)) * 3;
                al::setTrans(this, offs * sead::Vector3f::ey + _144);
            }

            if (_154) {
                if (!al::isActionEnd(this)) {
                    return;
                }
            }

            if (!al::isGreaterEqualStep(this, 20)) {
                return;
            }

            al::startNerveAction(this, "Fall");
        }
    }
    */

    bool FallMapParts::isEndFallSign() const {
        if (_154) {
            return al::isActionEnd(this);
        } else {
            return al::isGreaterEqualStep(this, 20);
        }
    }

    void FallMapParts::exeFall() {
        if (al::isFirstStep(this)) {
            al::tryStartAction(this, "Fall");
            al::setTrans(this, _144);
        }

        al::addVelocityToGravity(this, 0.3f);
        al::scaleVelocity(this, 0.9f);

        if (al::isGreaterStep(this, mFallTime)) {
            al::startNerveAction(this, "End");
        }
    }

    void FallMapParts::exeEnd() {
        if (al::isFirstStep(this)) {
            al::tryStartAction(this, "End");
            al::hideModel(this);
            al::invalidateCollisionParts(this);
            al::setVelocityZero(this);
        }

        if (al::isGreaterStep(this, 120)) {
            al::setTrans(this, _144);
            al::resetPosition(this, false);
            al::showModel(this);
            al::startNerveAction(this, "Appear");
        }
    }
};  // namespace al