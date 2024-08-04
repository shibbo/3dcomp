#pragma once

#include "Library/Collision/IUseCollision.hpp"
#include <math/seadVector.hpp>

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
        u8 _50[0x278 - 0x50];
        sead::Vector3f _278;
        u32 _284;
    };
};