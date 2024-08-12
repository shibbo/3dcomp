#pragma once

#include <math/seadVector.h>
#include "Library/HostIO/IUseHioNode.hpp"
#include "Library/HostIO/IUseName.hpp"
#include "Library/Placement/PlacementInfo.hpp"
#include "Library/Stage/IUseStageSwitch.hpp"
#include "Library/Yaml/ByamlIter.hpp"
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

        PlacementInfo mPlacementInfo;          // 0x00
        StageSwitchDirector* mSwitchDirector;  // 0x30
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
        bool isInVolume(const sead::Vector3f&, const sead::Vector3f&, sead::Vector3f*,
                        sead::Vector3f*);
        void setStartPos(sead::Vector3f&);
        bool getStartPos(sead::Vector3f*);

        s32 mZoneID = -1;                            // 0x8
        s32 mScenarioID = -1;                        // 0xC
        const char* mName = nullptr;                 // 0x10
        AreaShape* mShape = nullptr;                 // 0x18
        StageSwitchKeeper* mSwitchKeeper = nullptr;  // 0x20
        sead::Matrix34f _28 = sead::Matrix34f::ident;
        PlacementInfo* mPlacementInfo = nullptr;  // 0x58
        s32 mPriority = -1;                       // 0x60
        bool mIsValid = true;                     // 0x64
        bool mIsDisabled = false;                 // 0x65
        u8 _66 = 1;
        bool mIsNoSinkOcean = false;          // 0x67
        bool mIsSpawnEntranceCamera = false;  // 0x68
        u8 _69 = 0;
        bool mIsCodeLink = false;            // 0x6A
        bool mIsDisasterCameraOn = false;    // 0x6B
        bool mIsPlessieCameraOn = false;     // 0x6C
        bool mIsDisablePushControl = false;  // 0x6D
        bool mIsSnapToCamera = false;        // 0x6E
        bool mIsUIMapTriggered = false;      // 0x6F
        u8 _70 = 0;
        bool mIsOnGroundOnly = false;                 // 0x71
        bool mIsOneWayGroundOnly = false;             // 0x72
        bool mIsPlessieTunnel = false;                // 0x73
        bool mIsPlessieChaseV2SpecialCamera = false;  // 0x74
        bool _75 = false;
        bool mIsPlessieRideOnly = false;  // 0x76
        u8 _77 = 0;
        sead::Vector3f mStartPos = sead::Vector3f::zero;  // 0x78
    };
};  // namespace al