#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/Nerve/NerveExecutor.hpp"
#include "Project/Collision/IUseCollision.hpp"

namespace al {
class ActorInitInfo;
class MtxConnector;
class PrePassLightKeeper;
class ShadowDirector;

class PrePassLightBase : public NerveExecutor, public IUseCollision {
public:
    virtual ~PrePassLightBase();
    virtual void init(const ActorInitInfo&);
    virtual void execute() = 0;
    virtual void declareLpp() = 0;
    virtual void calcClippingInfo(sead::Vector3f*, f32*) = 0;
    virtual void trySetupShadow(s32, PrePassLightKeeper*, ShadowDirector*);
    virtual s32 getLightType() const = 0;
    virtual CollisionDirector* getCollisionDirector() const;

    void requestKillByUser();

    void* _18;
    void* _20;
    void* _28;
    void* _30;
    void* _38;
    CollisionDirector* mColDirector;
    const char* mName;
    MtxConnector* mMtxConnector;
    f32 mOffsetX;
    f32 mOffsetY;
    f32 mOffsetZ;
    u32 _64;
    void* _68;
    u32 _70;
    f32 mColorGreen;
    f32 mColorBlue;
    u32 _7c;
    f32 mSpecularColorRed;
    f32 mSpecularColorGreen;
    f32 mSpecularColorBlue;
    u32 _8c;
    u8 _90;
    bool mIsEnableSpecular;
    bool mIsEnableSpecColor;
    u8 _93;
    s32 mLightShaderFunc;
    void* _98;
    void* _a0;
    void* _a8;
    void* _b0;
    void* _b8;
    void* _c0;
    void* _c8;
    void* _d0;
    void* _d8;
    void* _e0;
    s32 mAppearFrame;
    u32 _ec;
    s32 mKillFrame;
    bool mIsIndirectIllumination;
    u32 _f8;
    u32 _f;
    f32 mRandomCeil;
};
}  // namespace al
