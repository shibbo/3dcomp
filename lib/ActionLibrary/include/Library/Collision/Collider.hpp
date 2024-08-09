#pragma once

#include "Library/Collision/IUseCollision.hpp"
#include "Library/Collision/HitInfo.hpp"
#include <math/seadVector.hpp>
#include <types.hpp>

namespace al {
    class TriangleFilterBase;
    class CollisionPartsFilterBase;
    class CollisionDirector;

    class Collider : public IUseCollision {
    public:
        Collider(CollisionDirector*, const sead::Matrix34f*, const sead::Vector3f*, const sead::Vector3f*, f32, f32, u32);

        virtual CollisionDirector* getCollisionDirector() const;

        void onInvalidate();

        CollisionDirector* mCollisionDirector = nullptr;        // 0x08
        TriangleFilterBase* mTriFilterBase = nullptr;           // 0x10
        CollisionPartsFilterBase* mColFilterBase = nullptr;     // 0x18
        const sead::Matrix34f* mBaseMtx = nullptr;              // 0x20
        const sead::Vector3f* mTrans = nullptr;                 // 0x28
        const sead::Vector3f* mGravity = nullptr;               // 0x30
        f32 mRadius = 0.0f;                                     // 0x38
        f32 mOffsetY = 0.0f;                                    // 0x3C
        void* _40 = nullptr;
        u32 _48 = 0;
        u32 mStoredPlaneNum = 0;                                // 0x4C
        HitInfo *_50 = nullptr;
        sead::Vector3f _58;
        sead::Vector3f _64;
        HitInfo mFloor;                                         // 0x70
        f32 _110 = 0.0f;
        HitInfo mWall;                                          // 0x118
        f32 _1B8 = 0.0f;
        HitInfo mCeiling;                                       // 0x1c0
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
};