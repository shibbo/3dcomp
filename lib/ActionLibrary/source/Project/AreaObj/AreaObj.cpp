#include "Project/AreaObj/AreaObj.hpp"
#include "Library/Placement/PlacementFunction.hpp"
#include "Library/Stage/StageSwitchKeeper.hpp"
#include "Library/Stage/SwitchUtil.hpp"
#include "Library/Thread/Functor.hpp"
#include "Project/AreaObj/AreaShapeCube.hpp"
#include "Project/AreaObj/AreaShapeCylinder.hpp"
#include "Project/AreaObj/AreaShapeOval.hpp"
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

    // al::AreaInitInfo::set

    AreaObj::AreaObj(const char* pName) : mName(pName) {}

    void AreaObj::init(const AreaInitInfo& rInfo) {
        mPlacementInfo = new PlacementInfo(rInfo.mPlacementInfo);
        al::tryGetZoneID(&mZoneID, rInfo.mPlacementInfo);
        al::tryGetArg(&mScenarioID, rInfo.mPlacementInfo, "ScenarioID");
        al::tryGetMatrixTR(&_28, *mPlacementInfo);

        const char* modelName = nullptr;
        alPlacementFunction::tryGetModelName(&modelName, *mPlacementInfo);

        if (al::isEqualString(modelName, "AreaCubeBase")) {
            mShape = new AreaShapeCube(AreaShapeCube::OriginType::Base);
        } else if (al::isEqualString(modelName, "AreaCubeCenter")) {
            mShape = new AreaShapeCube(AreaShapeCube::OriginType::Center);
        } else if (al::isEqualString(modelName, "AreaSphere")) {
            mShape = new AreaShapeOval();
        } else if (al::isEqualString(modelName, "AreaCylinder")) {
            mShape = new AreaShapeCylinder();
        }

        mShape->setBaseMtxPtr(&_28);
        al::tryGetArg(&mPriority, *mPlacementInfo, "Priority");
        al::tryGetArg(&mIsSpawnEntranceCamera, *mPlacementInfo, "IsSpawnEntranceCamera");
        al::tryGetArg(&mIsNoSinkOcean, *mPlacementInfo, "IsNoSinkOcean");
        al::tryGetArg(&mIsCodeLink, *mPlacementInfo, "IsCodeLink");
        al::tryGetArg(&mIsDisasterCameraOn, *mPlacementInfo, "IsDisasterCameraOn");
        al::tryGetArg(&mIsPlessieCameraOn, *mPlacementInfo, "IsPlessieCameraOn");
        al::tryGetArg(&mIsDisablePushControl, *mPlacementInfo, "IsDisablePushControl");
        al::tryGetArg(&mIsSnapToCamera, *mPlacementInfo, "IsSnapToCamera");
        al::tryGetArg(&mIsUIMapTriggered, *mPlacementInfo, "IsUIMapTriggered");
        al::tryGetArg(&mIsOnGroundOnly, *mPlacementInfo, "IsOnGroundOnly");
        al::tryGetArg(&mIsOneWayGroundOnly, *mPlacementInfo, "IsOneWayGroundOnly");
        al::tryGetArg(&mIsPlessieTunnel, *mPlacementInfo, "IsPlessieTunnel");
        al::tryGetArg(&mIsPlessieChaseV2SpecialCamera, *mPlacementInfo,
                      "IsPlessieChaseV2SpecialCamera");
        al::tryGetArg(&mIsPlessieRideOnly, *mPlacementInfo, "IsPlessieRideOnly");

        if (mIsPlessieCameraOn || mIsUIMapTriggered) {
            mIsValid = false;
        }

        sead::Vector3f scale(1.0f, 1.0f, 1.0f);
        al::tryGetScale(&scale, *mPlacementInfo);
        mShape->setScale(scale);
        al::initStageSwitch(this, rInfo.mSwitchDirector, rInfo.mPlacementInfo);

        bool listenStageSwitch = al::listenStageSwitchOnOffAppear(
            this, al::Functor(this, &AreaObj::validate), al::Functor(this, &AreaObj::invalidate));

        if (listenStageSwitch) {
            invalidate();
        }

        if ((~listenStageSwitch &
             al::listenStageSwitchOnKill(this, al::Functor(this, &AreaObj::invalidate)))) {
            validate();
        }

        al::FunctorV0M<al::AreaObj*, void (AreaObj::*)(void)> enable(this, &AreaObj::enable);
        al::FunctorV0M<al::AreaObj*, void (AreaObj::*)(void)> disable(this, &AreaObj::disable);

        if (al::listenStageSwitchOnOff(this, "SwitchEnableOn", enable, disable)) {
            mIsDisabled = true;
        }
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
        if (mIsValid && !mIsDisabled && _66) {
            return mShape->checkArrowCollision(a3, a4, a1, a2);
        }

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

};  // namespace al