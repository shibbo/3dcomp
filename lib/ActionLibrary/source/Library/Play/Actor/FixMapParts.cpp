#include "Library/Play/Actor/FixMapParts.hpp"
#include "Project/Collision/PartsConnector.hpp"
#include "Util.hpp"

namespace al {
    FixMapParts::FixMapParts(const char* pName) : LiveActor(pName) {}

    void FixMapParts::initWithSuffix(const ActorInitInfo& rInfo, const char* pName) {
        al::initMapPartsActor(this, rInfo, pName, 0);

        bool needSwitch = false;

        if (mActorPoseKeeper == nullptr) {
            al::initActorPoseTQSV(this);
            needSwitch = !al::trySyncStageSwitchAppear(this);
        } else {
            needSwitch = !al::trySyncStageSwitchAppear(this);
        }

        if (needSwitch) {
            al::trySyncStageSwitchKill(this);
        }

        bool arg = false;
        bool argGet = al::tryGetArg(&arg, rInfo, "IsConnectCollision");

        if (arg && argGet) {
            mConnector = al::createMtxConnector(this);
        }
    }

    void FixMapParts::init(const ActorInitInfo& rInfo) {
        initWithSuffix(rInfo, nullptr);
    }

    void FixMapParts::initAfterPlacement() {
        LiveActor::initAfterPlacement();

        if (mConnector != nullptr) {
            al::attachMtxConnectorToCollision(mConnector, this, false);
        }
    }

    void FixMapParts::appear() {
        LiveActor::appear();

        if (mModelKeeper != nullptr) {
            al::tryStartAction(this, "Appear");
        }
    }

    void FixMapParts::control() {
        if (mConnector != nullptr) {
            al::connectPoseTrans(this, mConnector, al::getConnectBaseTrans(mConnector));
        }
    }

    void FixMapParts::updateLinkedTrans(const sead::Vector3f& rTrans) {
        alLiveActorFunction::forceUpdateTrans(this, rTrans, true);
    }

    bool FixMapParts::receiveMsg(const SensorMsg* pMsg, HitSensor* pSrc, HitSensor* pTarget) {
        if (al::isMsgAskSafetyPoint(pMsg)) {
            return true;
        }

        if (al::isMsgShowModel(pMsg)) {
            al::showModelIfHide(this);
            return true;
        }

        if (!al::isMsgHideModel(pMsg)) {
            return al::isMsgSink(pMsg);
        }

        al::hideModelIfShow(this);
        return true;
    }
};  // namespace al