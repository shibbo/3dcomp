#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {
class CollisionParts;
class HitSensor;
class KCPrismData;
class KCPrismHeader;

class Triangle {
public:
    Triangle();
    Triangle(const CollisionParts&, KCPrismData*, KCPrismHeader*);

    void fillData(const CollisionParts&, KCPrismData*, KCPrismHeader*);
    void fill(const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);
    bool isHostMoved() const;
    bool isValid() const;
    const sead::Vector3f* getNormal(s32) const;
    const sead::Vector3f* getFaceNormal() const;
    const sead::Vector3f* getEdgeNormal(s32) const;
    const sead::Vector3f* getPos(s32) const;
    sead::Vector3f* calcAndGetNormal(s32);
    sead::Vector3f* calcAndGetFaceNormal();
    sead::Vector3f* calcAndGetEdgeNormal(s32);
    sead::Vector3f* calcAndGetPos(s32);
    void calcCenterPos(sead::Vector3f*) const;
    void getLocalPos(sead::Vector3f*, s32) const;
    void calcForceMovePower(sead::Vector3f*, const sead::Vector3f&) const;

    HitSensor* getSensor() const;
    sead::Matrix34f* getBaseMtx() const;
    sead::Matrix34f* getBaseInvMtx() const;
    sead::Matrix34f* getPrevBaseMtx() const;

    CollisionParts* mCollisionParts;
    KCPrismData* mPrismData;
    KCPrismHeader* mPrismHeader;
    sead::Vector3f mNormals[4];
    sead::Vector3f mPos[3];
};
}  // namespace al

bool operator==(const al::Triangle&, const al::Triangle&);
bool operator!=(const al::Triangle&, const al::Triangle&);
