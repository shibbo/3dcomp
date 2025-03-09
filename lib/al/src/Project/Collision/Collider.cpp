#include "Project/Collision/Collider.hpp"

#include "Project/Collision/HitDb.hpp"

namespace al {
Collider::Collider(CollisionDirector* pCollisionDirector, const sead::Matrix34f* pBaseMtx,
                   const sead::Vector3f* pTrans, const sead::Vector3f* pGravity, f32 radius,
                   f32 offsetY, u32 numHitInfos)
    : mCollisionDirector(pCollisionDirector), mBaseMtx(pBaseMtx), mTrans(pTrans),
      mGravity(pGravity), mRadius(radius), mOffsetY(offsetY), _48(numHitInfos),
      _58(sead::Vector3f(0.0f, 0.0f, 0.0f)), _64(sead::Vector3f(0.0f, 0.0f, 0.0f)),
      _268(sead::Vector3f(0.0f, 1.0f, 0.0f)), _278(*pTrans), _284(radius) {
    if (_48 == 0)
        _50 = nullptr;
    else
        _50 = new HitInfo[_48]();

    mStoredPlaneNum = 0;

    _110 = -99999.0f;
    _1b8 = -99999.0f;
    _260 = -99999.0f;

    _58 = sead::Vector3f(0.0f, 0.0f, 0.0f);
    _64 = sead::Vector3f(0.0f, 0.0f, 0.0f);

    _274 &= 0xc0;
    _274 |= 0x03;
}
}  // namespace al
