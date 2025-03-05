#pragma once

#include <basis/seadTypes.h>
#include "Library/Execute/IUseExecutor.hpp"
#include "Project/Camera/IUseCameraDirector.hpp"

namespace al {
    class SceneCameraCtrl;
    class CameraPoserSceneInfo_RS;
    class CameraPoserFactory_RS;
    class CameraInSwitchOnAreaDirector;
    class CameraAngleVerticalRequester;
    class CameraTargetCollideInfoHolder;
    class CameraTargetHolder;
    class CameraInputHolder;
    class CameraFlagCtrl;
    class CameraParamTransfer;
    class CameraTicketHolder;
    class CameraStartParamCtrl;
    class CameraStopJudge;
    class SpecialCameraHolder;
    class CameraPoseUpdater;
    class CameraResourceHolder;
    class ClippingDirectorBase;

    class CameraDirector_RS : public IUseExecutor, public IUseCamera {
    public:
        virtual void execute();
        virtual void draw() const;
        virtual ~CameraDirector_RS();
        virtual SceneCameraInfo* getSceneCameraInfo() const;

        int _10;
        int _14;
        SceneCameraInfo* mSceneCameraInf;                       // 0x18
        SceneCameraCtrl* mSceneCameraCtrl;                      // 0x20
        CameraPoseUpdater** mPoseUpdaters;                      // 0x28
        CameraPoserFactory_RS* mFactory;                        // 0x30
        CameraPoserSceneInfo_RS* mSceneInfo;                    // 0x38
        CameraTicketHolder* mTicketHolder;                      // 0x40
        SpecialCameraHolder* mSpecialCameraHolder;              // 0x48
        CameraTargetCollideInfoHolder* mCollideInfoHolder;      // 0x50
        CameraTargetHolder* mTargetHolder;                      // 0x58
        CameraInputHolder* mInputHolder;                        // 0x60
        CameraAngleVerticalRequester* mCameraAngleVerticalReq;  // 0x68
        CameraStartParamCtrl* mStartParamCtrl;                  // 0x70
        CameraStopJudge* mStopJudge;                            // 0x78
        CameraParamTransfer* mParamTransfer;                    // 0x80
        CameraResourceHolder* mResourceHolder;                  // 0x88
        CameraFlagCtrl* mCameraFlagCtrl;                        // 0x90
        u64 _98;
        CameraInSwitchOnAreaDirector* mCameraSwitchOnArea;  // 0xA0
        u64 _A8;
        ClippingDirectorBase* mCLippingDirectorBase;  // 0xB0
        u64 _B8;
        u64 _C0;
        u64 _C8;
        u64 _D0;
        u64 _D8;
        u64 _E0;
        u64 _E8;
        u64 _F0;
        u64 _F8;
        u8 _100;
        u8 _101;
        u8 _102;
        u8 _103;
        u8 _104;
    };
};  // namespace al