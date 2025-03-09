#pragma once

#include <basis/seadTypes.h>

#include "Library/Execute/IUseExecutor.hpp"
#include "Project/Camera/Core/IUseCameraDirector.hpp"

namespace al {
class CameraAngleVerticalRequester;
class CameraFlagCtrl;
class CameraInputHolder;
class CameraInSwitchOnAreaDirector;
class CameraParamTransfer;
class CameraPoserFactory_RS;
class CameraPoserSceneInfo_RS;
class CameraPoseUpdater;
class CameraResourceHolder;
class CameraStartParamCtrl;
class CameraStopJudge;
class CameraTargetCollideInfoHolder;
class CameraTargetHolder;
class CameraTicketHolder;
class ClippingDirectorBase;
class SceneCameraCtrl;
class SpecialCameraHolder;

class CameraDirector_RS : public IUseExecutor, public IUseCamera {
public:
    virtual void execute();
    virtual void draw() const;
    virtual ~CameraDirector_RS();
    virtual SceneCameraInfo* getSceneCameraInfo() const;

    s32 _10;
    s32 _14;
    SceneCameraInfo* mSceneCameraInfo;
    SceneCameraCtrl* mSceneCameraCtrl;
    CameraPoseUpdater** mPoseUpdaters;
    CameraPoserFactory_RS* mFactory;
    CameraPoserSceneInfo_RS* mSceneInfo;
    CameraTicketHolder* mTicketHolder;
    SpecialCameraHolder* mSpecialCameraHolder;
    CameraTargetCollideInfoHolder* mCollideInfoHolder;
    CameraTargetHolder* mTargetHolder;
    CameraInputHolder* mInputHolder;
    CameraAngleVerticalRequester* mCameraAngleVerticalReq;
    CameraStartParamCtrl* mStartParamCtrl;
    CameraStopJudge* mStopJudge;
    CameraParamTransfer* mParamTransfer;
    CameraResourceHolder* mResourceHolder;
    CameraFlagCtrl* mCameraFlagCtrl;
    u64 _98;
    CameraInSwitchOnAreaDirector* mCameraSwitchOnArea;
    u64 _a8;
    ClippingDirectorBase* mClippingDirectorBase;
    u64 _b8;
    u64 _c0;
    u64 _c8;
    u64 _d0;
    u64 _d8;
    u64 _e0;
    u64 _e8;
    u64 _f0;
    u64 _f8;
    u8 _100;
    u8 _101;
    u8 _102;
    u8 _103;
    u8 _104;
};
}  // namespace al
