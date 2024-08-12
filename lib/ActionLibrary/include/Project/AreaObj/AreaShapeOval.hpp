#pragma once

#include "Project/AreaObj/AreaShape.hpp"

namespace al {
    class AreaShapeOval : public AreaShape {
    public:
        AreaShapeOval();

        virtual bool isInVolume(const sead::Vector3f&) const;
        virtual void calcNearPoint(sead::Vector3f*, const sead::Vector3f&) const;
        virtual bool calcNearestEdgePoint(sead::Vector3f*, const sead::Vector3f&) const;
        virtual bool checkArrowCollision(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&,
                                         const sead::Vector3f&) const;
        virtual bool calcLocalBoundingBox(sead::BoundBox3f*) const;
        virtual bool calcWorldBoundingBox(sead::BoundBox3f*) const;
    };
};