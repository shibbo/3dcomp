#pragma once

#include "Project/AreaObj/AreaShape.hpp"

namespace al {
    class AreaShapeCube : public AreaShape {
    public:
        enum OriginType { Center = 0, Base = 1 };

        AreaShapeCube(OriginType);

        virtual bool isInVolume(const sead::Vector3f&) const;
        virtual void calcNearPoint(sead::Vector3f*, const sead::Vector3f&) const;
        virtual bool calcNearestEdgePoint(sead::Vector3f*, const sead::Vector3f&) const;
        virtual bool checkArrowCollision(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&,
                                         const sead::Vector3f&) const;
        virtual bool calcLocalBoundingBox(sead::BoundBox3f*) const;
        virtual bool calcWorldBoundingBox(sead::BoundBox3f*) const;

        OriginType mOriginType;  // 0x1C
    };
};