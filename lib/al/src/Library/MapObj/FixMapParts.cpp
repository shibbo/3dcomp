#include "Library/MapObj/FixMapParts.hpp"

#include "Library/Actor/ActorInitUtil.hpp"
#include "Library/Actor/ActorMapUtil.hpp"
#include "Library/Actor/ActorModelUtil.hpp"
#include "Library/Actor/ActorPoseUtil.hpp"
#include "Library/Actor/ActorSensorUtil.hpp"
#include "Library/Connector/MtxConnector.hpp"
#include "Library/LiveActor/ActorActionFunc.hpp"
#include "Library/LiveActor/LiveActorFunc.hpp"
#include "Library/LiveActor/LiveActorUtil.hpp"
#include "Library/Play/Placement/PlacementFunction.hpp"

namespace al {
FixMapParts::FixMapParts(const char* pName) : LiveActor(pName) {}

void FixMapParts::initWithSuffix(const ActorInitInfo& rInfo, const char* pName) {
    initMapPartsActor(this, rInfo, pName, 0);

    bool needSwitch = false;

    if (mActorPoseKeeper == nullptr) {
        initActorPoseTQSV(this);
        needSwitch = !trySyncStageSwitchAppear(this);
    } else {
        needSwitch = !trySyncStageSwitchAppear(this);
    }

    if (needSwitch)
        trySyncStageSwitchKill(this);

    bool arg = false;
    bool argGet = tryGetArg(&arg, rInfo, "IsConnectCollision");

    if (arg && argGet)
        mConnector = createMtxConnector(this);
}

void FixMapParts::init(const ActorInitInfo& rInfo) {
    initWithSuffix(rInfo, nullptr);
}

void FixMapParts::initAfterPlacement() {
    LiveActor::initAfterPlacement();

    if (mConnector != nullptr)
        attachMtxConnectorToCollision(mConnector, this, false);
}

void FixMapParts::appear() {
    LiveActor::appear();

    if (mModelKeeper != nullptr)
        tryStartAction(this, "Appear");
}

void FixMapParts::control() {
    if (mConnector != nullptr)
        connectPoseTrans(this, mConnector, getConnectBaseTrans(mConnector));
}

void FixMapParts::updateLinkedTrans(const sead::Vector3f& rTrans) {
    alLiveActorFunction::forceUpdateTrans(this, rTrans, true);
}

bool FixMapParts::receiveMsg(const SensorMsg* msg, HitSensor* self, HitSensor* other) {
    if (isMsgAskSafetyPoint(msg))
        return true;

    if (isMsgShowModel(msg)) {
        showModelIfHide(this);
        return true;
    }

    if (!isMsgHideModel(msg))
        return isMsgSink(msg);

    hideModelIfShow(this);
    return true;
}
}  // namespace al
