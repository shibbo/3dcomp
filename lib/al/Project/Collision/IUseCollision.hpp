#pragma once

namespace al {
    class CollisionDirector;

    class IUseCollision {
    public:
        virtual CollisionDirector* getCollisionDirector() const = 0;
    };
};