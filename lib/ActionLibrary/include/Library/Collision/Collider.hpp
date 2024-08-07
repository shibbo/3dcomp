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

        virtual CollisionDirector* getCollisionDirector() const;

        void onInvalidate();

        CollisionDirector* mCollisionDirector;          // 0x08
        TriangleFilterBase* mTriFilterBase;             // 0x10
        CollisionPartsFilterBase* mColFilterBase;       // 0x18
        void* _20;
        void* _28;
        void* _30;
        f32 mRadius;                                    // 0x38
        f32 mOffsetY;                                   // 0x3C
        void* _40;
        u32 _48;
        u32 mStoredPlaneNum;                            // 0x4C
        u8 _50[0x70 - 0x50];
        Triangle mFloor;                                // 0x70
        u32 _E0;
        sead::Vector3f mGroundPos;                      // 0xE4
        u8 _F0[0x110 - 0xF0];
        f32 _110;
        f32 _114;
        Triangle mWall;                                 // 0x118
        u32 _188;
        sead::Vector3f mWallPos;                        // 0x18C
        u8 _198[0x1B8 - 0x198];
        f32 _1B8;
        f32 _1BC;
        Triangle mCeiling;                              // 0x1C0
        u32 _230;
        sead::Vector3f mCeilingPos;                     // 0x234
        u8 _240[0x260 - 0x240];
        f32 _260;
        u32 _264;
        u32 _268;
        u32 _26C;
        u32 _270;
        bool _274;
        bool _275;
        bool _276;
        bool _277;
        sead::Vector3f _278;
        u32 _284;
    };
};