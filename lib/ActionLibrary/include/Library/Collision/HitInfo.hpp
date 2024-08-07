#pragma once

#include <math/seadVector.hpp>

namespace al {
    class CollisionParts;
    class KCPrismData;
    class KCPrismHeader;
    class HitSensor;

    class Triangle {
    public:
        Triangle();
        Triangle(const CollisionParts &, KCPrismData *, KCPrismHeader *);

        void fillData(const CollisionParts &, KCPrismData *, KCPrismHeader *);
        void fill(const sead::Vector3f &, const sead::Vector3f &, const sead::Vector3f &);
        bool isHostMoved() const;
        bool isValid() const;
        const sead::Vector3f* getNormal(int) const;
        const sead::Vector3f* getFaceNormal() const;
        const sead::Vector3f* getEdgeNormal(int) const;
        const sead::Vector3f* getPos(int) const;
        sead::Vector3f* calcAndGetNormal(int);
        sead::Vector3f* calcAndGetFaceNormal();
        sead::Vector3f* calcAndGetEdgeNormal(int);
        sead::Vector3f* calcAndGetPos(int);
        void calcCenterPos(sead::Vector3f *) const;
        void getLocalPos(sead::Vector3f *, int) const;
        void calcForceMovePower(sead::Vector3f *, const sead::Vector3f &) const;

        HitSensor* getSensor() const;
        sead::Matrix34f* getBaseMtx() const;
        sead::Matrix34f* getBaseInvMtx() const;
        sead::Matrix34f* getPrevBaseMtx() const;

        CollisionParts* mCollisionParts;        // 0x00
        KCPrismData* mPrismData;                // 0x08
        KCPrismHeader* mPrismHeader;            // 0x10
        sead::Vector3f mNormals[4];             // 0x18
        sead::Vector3f mPos[3];                 // 0x48
    };
};

bool operator==(const al::Triangle &, const al::Triangle &);
bool operator!=(const al::Triangle &, const al::Triangle &);
