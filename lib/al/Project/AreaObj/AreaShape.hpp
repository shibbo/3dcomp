#pragma once

#include <math/seadBoundBox.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
    class AreaShape {
    public:
        AreaShape();

        virtual bool isInVolume(const sead::Vector3f&) const = 0;
        virtual void calcNearPoint(sead::Vector3f*, const sead::Vector3f&) const = 0;
        virtual bool calcNearestEdgePoint(sead::Vector3f*, const sead::Vector3f&) const = 0;
        virtual bool checkArrowCollision(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&,
                                         const sead::Vector3f&) const = 0;
        virtual bool calcLocalBoundingBox(sead::BoundBox3f*) const = 0;
        virtual bool calcWorldBoundingBox(sead::BoundBox3f*) const = 0;

        void setBaseMtxPtr(const sead::Matrix34f*);
        void setScale(const sead::Vector3f&);
        bool calcLocalPos(sead::Vector3f*, const sead::Vector3f&) const;
        bool calcWorldPos(sead::Vector3f*, const sead::Vector3f&) const;
        bool calcWorldDir(sead::Vector3f*, const sead::Vector3f&) const;
        void calcTrans(sead::Vector3f*) const;

        const sead::Matrix34f* mBaseMtx = nullptr;  // 0x08
        sead::Vector3f mScale;                      // 0x10
    };
};  // namespace al