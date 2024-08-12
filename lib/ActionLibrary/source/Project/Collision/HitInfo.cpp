#include "Project/Collision/HitInfo.hpp"
#include <types.hpp>
#include "Project/Collision/CollisionParts.hpp"

namespace al {
    bool Triangle::isValid() const {
        return mPrismData != nullptr;
    }

    const sead::Vector3f* Triangle::getNormal(int norm) const {
        return &mNormals[norm];
    }

    const sead::Vector3f* Triangle::getFaceNormal() const {
        return mNormals;
    }

    const sead::Vector3f* Triangle::getEdgeNormal(int edge) const {
        return &mNormals[edge + 1];
    }

    const sead::Vector3f* Triangle::getPos(int pos) const {
        return &mPos[pos];
    }

    void Triangle::calcCenterPos(sead::Vector3f* pOut) const {
        f32 x = ((mPos[0].x + mPos[1].x) + mPos[2].x);
        f32 y = ((mPos[0].y + mPos[1].y) + mPos[2].y);
        f32 z = ((mPos[0].z + mPos[1].z) + mPos[2].z);
        pOut->set(x, y, z);
        pOut->scale(0.33333f);
    }

    // ....

    HitSensor* Triangle::getSensor() const {
        return mCollisionParts->mSensor;
    }

    sead::Matrix34f* Triangle::getBaseMtx() const {
        return &mCollisionParts->mBaseMtx;
    }

    sead::Matrix34f* Triangle::getBaseInvMtx() const {
        return &mCollisionParts->mBaseInvMtx;
    }

    sead::Matrix34f* Triangle::getPrevBaseMtx() const {
        return &mCollisionParts->mPrevBaseMtx;
    }
};  // namespace al

bool operator==(const al::Triangle& lhs, const al::Triangle& rhs) {
    return lhs.mCollisionParts == rhs.mCollisionParts && lhs.mPrismData == rhs.mPrismData;
}

bool operator!=(const al::Triangle& lhs, const al::Triangle& rhs) {
    return lhs.mCollisionParts != rhs.mCollisionParts || lhs.mPrismData != rhs.mPrismData;
}