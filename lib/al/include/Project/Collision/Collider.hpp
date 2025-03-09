#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

#include "Project/Collision/HitDb.hpp"
#include "Project/Collision/IUseCollision.hpp"

namespace al {
class TriangleFilterBase;
class CollisionPartsFilterBase;
class CollisionDirector;

class Collider : public IUseCollision {
public:
    Collider(CollisionDirector*, const sead::Matrix34f*, const sead::Vector3f*,
             const sead::Vector3f*, f32, f32, u32);

    virtual CollisionDirector* getCollisionDirector() const;

    void onInvalidate();

    CollisionDirector* mCollisionDirector = nullptr;
    TriangleFilterBase* mTriFilterBase = nullptr;
    CollisionPartsFilterBase* mColFilterBase = nullptr;
    const sead::Matrix34f* mBaseMtx = nullptr;
    const sead::Vector3f* mTrans = nullptr;
    const sead::Vector3f* mGravity = nullptr;
    f32 mRadius = 0.0f;
    f32 mOffsetY = 0.0f;
    void* _40 = nullptr;
    u32 _48 = 0;
    u32 mStoredPlaneNum = 0;
    HitInfo* _50 = nullptr;
    sead::Vector3f _58;
    sead::Vector3f _64;
    HitInfo mFloor;
    f32 _110 = 0.0f;
    HitInfo mWall;
    f32 _1b8 = 0.0f;
    HitInfo mCeiling;
    f32 _260 = 0.0f;
    u32 _264 = 0;
    sead::Vector3f _268;
    u8 _274;
    bool _275;
    bool _276;
    bool _277;
    sead::Vector3f _278;
    f32 _284;
};
}  // namespace al
