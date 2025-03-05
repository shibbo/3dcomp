#include "Project/AreaObj/AreaShape.hpp"
#include "Library/Math/MathUtil.hpp"
#include "Project/Matrix/MatrixUtil.hpp"

namespace al {
    AreaShape::AreaShape() : mScale(1.0f, 1.0f, 1.0f) {}

    void AreaShape::setBaseMtxPtr(const sead::Matrix34f* pMtx) {
        mBaseMtx = pMtx;
    }

    void AreaShape::setScale(const sead::Vector3f& rScale) {
        mScale.set(rScale);
    }

    bool AreaShape::calcLocalPos(sead::Vector3f* pLocalPos, const sead::Vector3f& a2) const {
        if (al::isNearZero(mScale.x, 0.001f) || al::isNearZero(mScale.y, 0.001f) ||
            al::isNearZero(mScale.z, 0.001f)) {
            return false;
        } else {
            if (mBaseMtx != nullptr)
                al::calcMtxLocalTrans(pLocalPos, *mBaseMtx, a2);
            else
                *pLocalPos = a2;

            f32 x = pLocalPos->x;
            pLocalPos->x = x / mScale.x;
            f32 y = pLocalPos->y;
            pLocalPos->y = y / mScale.y;
            f32 z = pLocalPos->z;
            pLocalPos->z = z / mScale.z;
        }

        return true;
    }

    bool AreaShape::calcWorldPos(sead::Vector3f* pWorldPos, const sead::Vector3f& rPos) const {
        if (al::isNearZero(mScale.x, 0.001f) || al::isNearZero(mScale.y, 0.001f) ||
            al::isNearZero(mScale.z, 0.001f)) {
            return false;
        } else {
            pWorldPos->x = rPos.x * mScale.x;
            pWorldPos->y = rPos.y * mScale.y;
            pWorldPos->z = rPos.z * mScale.z;

            if (mBaseMtx != nullptr)
                pWorldPos->mul(*mBaseMtx);
        }

        return true;
    }

    bool AreaShape::calcWorldDir(sead::Vector3f* pWorldDir, const sead::Vector3f& rPos) const {
        if (al::isNearZero(mScale.x, 0.001f) || al::isNearZero(mScale.y, 0.001f) ||
            al::isNearZero(mScale.z, 0.001f)) {
            return false;
        } else {
            pWorldDir->x = rPos.x * mScale.x;
            pWorldDir->y = rPos.y * mScale.y;
            pWorldDir->z = rPos.z * mScale.z;

            if (mBaseMtx != nullptr)
                pWorldDir->rotate(*mBaseMtx);

            al::normalizeOrZero(pWorldDir);
        }

        return true;
    }

    /*void AreaShape::calcTrans(sead::Vector3f* pTrans) const {
        if (mBaseMtx != nullptr)
            mBaseMtx->getBase(pTrans);
        else
            *pTrans = sead::Vector3f::zero;
    }
    */
};  // namespace al