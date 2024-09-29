#include "Library/Play/Actor/FloaterMapParts.hpp"
#include "Library/Nerve/NerveAction.hpp"
#include "Library/Nerve/NerveSetup.hpp"
#include "Util.hpp"

namespace {
    using namespace al;

    NERVE_ACTION_IMPL(FloaterMapParts, Wait)
    NERVE_ACTION_IMPL(FloaterMapParts, Sink)
    NERVE_ACTION_IMPL(FloaterMapParts, Back)

    NERVE_ACTIONS_MAKE_STRUCT(FloaterMapParts, Wait, Sink, Back)
};  // namespace

namespace al {
    FloaterMapParts::FloaterMapParts(const char* pName) : LiveActor(pName) {}

    void FloaterMapParts::init(const ActorInitInfo& rInfo) {
        al::initNerveAction(this, "Wait", &NrvFloaterMapParts.mCollector, 0);
        al::initActorPoseTQSV(this);
        al::initMapPartsActor(this, rInfo, nullptr, 0);
        al::registerAreaHostMtx(this, rInfo);
        mKeyPoseKeeper = al::createKeyPoseKeeper(rInfo);
        mNextKeyDist = al::calcDistanceNextKeyTrans(mKeyPoseKeeper);
        al::tryGetArg(&mSinkSpeed, rInfo, "SinkSpeed");
        al::tryGetArg(&mBackSpeed, rInfo, "BackSpeed");
        al::tryGetArg(&mMaxAccelCount, rInfo, "MaxAccelCount");
        al::tryGetArg(&mSinkKeepTime, rInfo, "SinkKeepTime");
        al::trySyncStageSwitchAppear(this);
    }

    bool FloaterMapParts::receiveMsg(const SensorMsg* pMsg, HitSensor* pSrc, HitSensor* pTarget) {
        if (al::isMsgFloorTouch(pMsg)) {
            _160 = 2;
            return true;
        } else if (al::isMsgShowModel(pMsg)) {
            al::showModelIfHide(this);
            return true;
        } else if (al::isMsgHideModel(pMsg)) {
            al::hideModelIfShow(this);
            return true;
        }

        return false;
    }

    void FloaterMapParts::control() {
        f32 v2;

        if (al::isNearZero(mNextKeyDist, 0.001f)) {
            v2 = 0.0f;
        } else {
            v2 = _150 / mNextKeyDist;
        }

        al::calcLerpKeyTrans(al::getTransPtr(this), mKeyPoseKeeper, v2);
        al::calcSlerpKeyQuat(al::getQuatPtr(this), mKeyPoseKeeper, v2);

        if (_160 > 0) {
            _160 = _160 - 1;
        }
    }

    void FloaterMapParts::exeWait() {
        if (al::isFirstStep(this)) {
            al::validateClipping(this);
        }

        if (_160 >= 1) {
            al::invalidateClipping(this);
            al::startNerveAction(this, "Sink");
        }
    }

    /*
    void FloaterMapParts::exeSink() {
        if (al::isFirstStep(this)) {
            _170 = 0;
        }

        if (_160 != 0) {
            _150 += ((mSinkSpeed * _170) / mMaxAccelCount);

            if (_170 < mMaxAccelCount) {
                _170++;
            }

            if (_150 > mNextKeyDist) {
                _150 = mNextKeyDist;
            }

            _164 = 0;

            if (mSinkKeepTime <= 0) {
                al::startNerveAction(this, "Back");
            }
        } else {

        }
    }
    */

    // FloaterMapParts::exeBack

    FloaterMapParts::~FloaterMapParts() {}

};  // namespace al