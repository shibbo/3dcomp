#pragma once

#include "Library/Collision/IUseCollision.hpp"
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
        u8 _50[0x274 - 0x50];
        bool _274;
        bool _275;
        bool _276;
        bool _277;
        sead::Vector3f _278;
        u32 _284;
    };
};