#include "Project/AreaObj/AreaObj.hpp"

#include "Library/Play/Placement/PlacementFunction.hpp"
#include "Library/StageSwitch/Core/StageSwitchKeeper.hpp"
#include "Library/StageSwitch/StageSwitchFunc.hpp"
#include "Library/Thread/Functor.hpp"
#include "Project/AreaObj/AreaShapeCube.hpp"
#include "Project/AreaObj/AreaShapeRound.hpp"
#include "Project/Base/StringUtil.hpp"

namespace al {
AreaInitInfo::AreaInitInfo() {
    mSwitchDirector = nullptr;
}

AreaInitInfo::AreaInitInfo(const PlacementInfo& rInfo, StageSwitchDirector* pDir)
    : mPlacementInfo(rInfo) {
    mSwitchDirector = pDir;
}

AreaInitInfo::AreaInitInfo(const PlacementInfo& rInfo, const AreaInitInfo& rAreaInfo)
    : mPlacementInfo(rInfo), mSwitchDirector(rAreaInfo.mSwitchDirector) {}

// AreaInitInfo::set

AreaObj::AreaObj(const char* pName) : mName(pName) {}

void AreaObj::init(const AreaInitInfo& rInfo) {
    mPlacementInfo = new PlacementInfo(rInfo.mPlacementInfo);
    tryGetZoneID(&mZoneID, rInfo.mPlacementInfo);
    tryGetArg(&mScenarioID, rInfo.mPlacementInfo, "ScenarioID");
    tryGetMatrixTR(&_28, *mPlacementInfo);

    const char* modelName = nullptr;
    alPlacementFunction::tryGetModelName(&modelName, *mPlacementInfo);

    if (isEqualString(modelName, "AreaCubeBase"))
        mShape = new AreaShapeCube(AreaShapeCube::OriginType::Base);
    else if (isEqualString(modelName, "AreaCubeCenter"))
        mShape = new AreaShapeCube(AreaShapeCube::OriginType::Center);
    else if (isEqualString(modelName, "AreaSphere"))
        mShape = new AreaShapeOval();
    else if (isEqualString(modelName, "AreaCylinder"))
        mShape = new AreaShapeCylinder();

    mShape->setBaseMtxPtr(&_28);
    tryGetArg(&mPriority, *mPlacementInfo, "Priority");
    tryGetArg(&mIsSpawnEntranceCamera, *mPlacementInfo, "IsSpawnEntranceCamera");
    tryGetArg(&mIsNoSinkOcean, *mPlacementInfo, "IsNoSinkOcean");
    tryGetArg(&mIsCodeLink, *mPlacementInfo, "IsCodeLink");
    tryGetArg(&mIsDisasterCameraOn, *mPlacementInfo, "IsDisasterCameraOn");
    tryGetArg(&mIsPlessieCameraOn, *mPlacementInfo, "IsPlessieCameraOn");
    tryGetArg(&mIsDisablePushControl, *mPlacementInfo, "IsDisablePushControl");
    tryGetArg(&mIsSnapToCamera, *mPlacementInfo, "IsSnapToCamera");
    tryGetArg(&mIsUIMapTriggered, *mPlacementInfo, "IsUIMapTriggered");
    tryGetArg(&mIsOnGroundOnly, *mPlacementInfo, "IsOnGroundOnly");
    tryGetArg(&mIsOneWayGroundOnly, *mPlacementInfo, "IsOneWayGroundOnly");
    tryGetArg(&mIsPlessieTunnel, *mPlacementInfo, "IsPlessieTunnel");
    tryGetArg(&mIsPlessieChaseV2SpecialCamera, *mPlacementInfo, "IsPlessieChaseV2SpecialCamera");
    tryGetArg(&mIsPlessieRideOnly, *mPlacementInfo, "IsPlessieRideOnly");

    if (mIsPlessieCameraOn || mIsUIMapTriggered)
        mIsValid = false;

    sead::Vector3f scale(1.0f, 1.0f, 1.0f);
    tryGetScale(&scale, *mPlacementInfo);
    mShape->setScale(scale);
    initStageSwitch(this, rInfo.mSwitchDirector, rInfo.mPlacementInfo);

    bool listenStageSwitch = listenStageSwitchOnOffAppear(this, Functor(this, &AreaObj::validate),
                                                          Functor(this, &AreaObj::invalidate));

    if (listenStageSwitch)
        invalidate();

    if ((~listenStageSwitch & listenStageSwitchOnKill(this, Functor(this, &AreaObj::invalidate))))
        validate();

    FunctorV0M<AreaObj*, void (AreaObj::*)()> enable(this, &AreaObj::enable);
    FunctorV0M<AreaObj*, void (AreaObj::*)()> disable(this, &AreaObj::disable);

    if (listenStageSwitchOnOff(this, "SwitchEnableOn", enable, disable))
        mIsDisabled = true;
}

void AreaObj::invalidate() {
    mIsValid = false;
}

void AreaObj::validate() {
    mIsValid = true;
}

void AreaObj::enable() {
    mIsDisabled = false;
}

void AreaObj::disable() {
    mIsDisabled = true;
}

void AreaObj::initStageSwitchKeeper() {
    mSwitchKeeper = new StageSwitchKeeper();
}

bool AreaObj::isInVolume(const sead::Vector3f& rVec) {
    if (mIsValid && !mIsDisabled && _66)
        return mShape->isInVolume(rVec);

    return false;
}

bool AreaObj::isInVolumeCheck(const sead::Vector3f& rVec) const {
    return mShape->isInVolume(rVec);
}

bool AreaObj::isInVolume(const sead::Vector3f& a1, const sead::Vector3f& a2, sead::Vector3f* a3,
                         sead::Vector3f* a4) {
    if (mIsValid && !mIsDisabled && _66)
        return mShape->checkArrowCollision(a3, a4, a1, a2);

    return false;
}

void AreaObj::setStartPos(sead::Vector3f& rPos) {
    _75 = true;
    mStartPos.set(rPos);
}

bool AreaObj::getStartPos(sead::Vector3f* pPos) {
    pPos->set(mStartPos);
    return _75;
}

}  // namespace al
