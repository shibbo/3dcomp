#pragma once

#include <math/seadVector.h>

#include "Library/HostIO/IUseHioNode.hpp"
#include "Library/Play/Placement/PlacementInfo.hpp"
#include "Library/StageSwitch/Core/IUseStageSwitch.hpp"
#include "Project/AreaObj/AreaShape.hpp"

namespace al {
class StageSwitchDirector;
class SceneObjHolder;

class AreaInitInfo {
public:
    AreaInitInfo();
    AreaInitInfo(const PlacementInfo&, StageSwitchDirector*);
    AreaInitInfo(const PlacementInfo&, const AreaInitInfo&);

    void set(const PlacementInfo&, StageSwitchDirector*);

    PlacementInfo mPlacementInfo;
    StageSwitchDirector* mSwitchDirector;
};

class AreaObj : public IUseStageSwitch, public HioNode {
public:
    AreaObj(const char*);

    virtual const char* getName() const { return mName; }

    virtual StageSwitchKeeper* getStageSwitchKeeper() const { return mSwitchKeeper; }

    virtual void initStageSwitchKeeper();
    virtual void init(const AreaInitInfo&);
    virtual void init(const AreaInitInfo&, SceneObjHolder*);
    virtual bool isInVolume(const sead::Vector3f&);
    virtual bool isInVolumeCheck(const sead::Vector3f&) const;

    void invalidate();
    void validate();
    void enable();
    void disable();
    bool isInVolume(const sead::Vector3f&, const sead::Vector3f&, sead::Vector3f*, sead::Vector3f*);
    void setStartPos(sead::Vector3f&);
    bool getStartPos(sead::Vector3f*);

    s32 mZoneID = -1;
    s32 mScenarioID = -1;
    const char* mName = nullptr;
    AreaShape* mShape = nullptr;
    StageSwitchKeeper* mSwitchKeeper = nullptr;
    sead::Matrix34f _28 = sead::Matrix34f::ident;
    PlacementInfo* mPlacementInfo = nullptr;
    s32 mPriority = -1;
    bool mIsValid = true;
    bool mIsDisabled = false;
    u8 _66 = 1;
    bool mIsNoSinkOcean = false;
    bool mIsSpawnEntranceCamera = false;
    u8 _69 = 0;
    bool mIsCodeLink = false;
    bool mIsDisasterCameraOn = false;
    bool mIsPlessieCameraOn = false;
    bool mIsDisablePushControl = false;
    bool mIsSnapToCamera = false;
    bool mIsUIMapTriggered = false;
    u8 _70 = 0;
    bool mIsOnGroundOnly = false;
    bool mIsOneWayGroundOnly = false;
    bool mIsPlessieTunnel = false;
    bool mIsPlessieChaseV2SpecialCamera = false;
    bool _75 = false;
    bool mIsPlessieRideOnly = false;
    u8 _77 = 0;
    sead::Vector3f mStartPos = sead::Vector3f::zero;
};
}  // namespace al
