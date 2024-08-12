#pragma once

#include <math/seadVector.h>
#include <types.hpp>
#include "Library/Nerve/NerveExecutor.hpp"
#include "Project/Collision/IUseCollision.hpp"

namespace al {
    class ActorInitInfo;
    class PrePassLightKeeper;
    class ShadowDirector;
    class MtxConnector;

    class PrePassLightBase : public NerveExecutor, public IUseCollision {
    public:
        virtual ~PrePassLightBase();
        virtual void init(const ActorInitInfo&);
        virtual void execute() = 0;
        virtual void declareLpp() = 0;
        virtual void calcClippingInfo(sead::Vector3f*, f32*) = 0;
        virtual void trySetupShadow(int, PrePassLightKeeper*, ShadowDirector*);
        virtual s32 getLightType() const = 0;
        virtual CollisionDirector* getCollisionDirector() const;

        void requestKillByUser();

        void* _18;
        void* _20;
        void* _28;
        void* _30;
        void* _38;
        CollisionDirector* mColDirector;  // 0x40
        const char* mName;                // 0x48
        MtxConnector* mMtxConnector;      // 0x50
        f32 mOffsetX;                     // 0x58
        f32 mOffsetY;                     // 0x5C
        f32 mOffsetZ;                     // 0x60
        u32 _64;
        void* _68;
        u32 _70;
        f32 mColorGreen;  // 0x74
        f32 mColorBlue;   // 0x78
        u32 _7C;
        f32 mSpecularColorRed;    // 0x80
        f32 mSpecularColorGreen;  // 0x84
        f32 mSpecularColorBlue;   // 0x88
        u32 _8C;
        u8 _90;
        bool mIsEnableSpecular;   // 0x91
        bool mIsEnableSpecColor;  // 0x92
        u8 _93;
        int mLightShaderFunc;  // 0x94
        void* _98;
        void* _A0;
        void* _A8;
        void* _B0;
        void* _B8;
        void* _C0;
        void* _C8;
        void* _D0;
        void* _D8;
        void* _E0;
        int mAppearFrame;  // 0xE8
        u32 _EC;
        int mKillFrame;                // 0xF0
        bool mIsIndirectIllumination;  // 0xF4
        u32 _F8;
        u32 _FC;
        f32 mRandomCeil;  // 0x100
    };
};  // namespace al