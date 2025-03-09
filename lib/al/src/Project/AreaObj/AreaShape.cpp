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

bool AreaShape::calcLocalPos(sead::Vector3f* localPos, const sead::Vector3f& trans) const {
    if (isNearZeroOrLess(mScale.x, 0.001))
        return false;
    if (isNearZeroOrLess(mScale.y, 0.001))
        return false;
    if (isNearZeroOrLess(mScale.z, 0.001))
        return false;

    if (mBaseMtx)
        calcMtxLocalTrans(localPos, *mBaseMtx, trans);
    else
        localPos->e = trans.e;

    f32 localX = localPos->x;
    localPos->x = localX / mScale.x;
    f32 localY = localPos->y;
    localPos->y = localY / mScale.y;
    f32 localZ = localPos->z;
    localPos->z = localZ / mScale.z;

    return true;
}

bool AreaShape::calcWorldPos(sead::Vector3f* pWorldPos, const sead::Vector3f& rPos) const {
    if (isNearZero(mScale.x, 0.001f) || isNearZero(mScale.y, 0.001f) ||
        isNearZero(mScale.z, 0.001f)) {
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
    if (isNearZero(mScale.x, 0.001f) || isNearZero(mScale.y, 0.001f) ||
        isNearZero(mScale.z, 0.001f)) {
        return false;
    } else {
        pWorldDir->x = rPos.x * mScale.x;
        pWorldDir->y = rPos.y * mScale.y;
        pWorldDir->z = rPos.z * mScale.z;

        if (mBaseMtx != nullptr)
            pWorldDir->rotate(*mBaseMtx);

        normalizeOrZero(pWorldDir);
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
}  // namespace al
