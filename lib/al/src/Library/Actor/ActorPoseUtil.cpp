#include "Library/Actor/ActorPoseUtil.hpp"
#include "Library/Actor/ActorPoseKeeper.hpp"
#include "Library/LiveActor/LiveActor.hpp"

namespace al {
    const sead::Vector3f& getGravity(const LiveActor* pActor) {
        return pActor->mActorPoseKeeper->getGravity();
    }

    sead::Vector3f& getTrans(const LiveActor* pActor) {
        return pActor->mActorPoseKeeper->mTranslation;
    }

    const sead::Vector3f& getScale(const LiveActor* pActor) {
        return pActor->mActorPoseKeeper->getScale();
    }

    void copyPose(LiveActor* pSource, const LiveActor* pDest) {
        pSource->mActorPoseKeeper->copyPose(pDest->mActorPoseKeeper);
    }

    void updatePoseRotate(LiveActor* pActor, const sead::Vector3f& rRotate) {
        pActor->mActorPoseKeeper->updatePoseRotate(rRotate);
    }

    void updatePoseQuat(LiveActor* pActor, const sead::Quatf& rQuat) {
        pActor->mActorPoseKeeper->updatePoseQuat(rQuat);
    }

    void updatePoseMtx(LiveActor* pActor, const sead::Matrix34f& rMtx) {
        pActor->mActorPoseKeeper->updatePoseMtx(&rMtx);
    }

    sead::Vector3f* getTransPtr(LiveActor* pActor) {
        return &pActor->mActorPoseKeeper->mTranslation;
    }

    void setTrans(LiveActor* pActor, f32 x, f32 y, f32 z) {
        auto trans = getTransPtr(pActor);
        trans->set(x, y, z);
    }

    void setTransX(LiveActor* pActor, f32 x) {
        getTransPtr(pActor)->x = x;
    }

    void setTransY(LiveActor* pActor, f32 y) {
        getTransPtr(pActor)->y = y;
    }

    void setTransZ(LiveActor* pActor, f32 z) {
        getTransPtr(pActor)->z = z;
    }

    const sead::Vector3f& getRotate(const LiveActor* pActor) {
        return pActor->mActorPoseKeeper->getRotate();
    }

    sead::Vector3f* getRotatePtr(LiveActor* pActor) {
        return pActor->mActorPoseKeeper->getRotatePtr();
    }

    void setRotate(LiveActor* pActor, f32 x, f32 y, f32 z) {
        pActor->mActorPoseKeeper->getRotatePtr()->set(x, y, z);
    }

    void setRotateX(LiveActor* pActor, f32 x) {
        getRotatePtr(pActor)->x = x;
    }

    void setRotateY(LiveActor* pActor, f32 y) {
        getRotatePtr(pActor)->y = y;
    }

    void setRotateZ(LiveActor* pActor, f32 z) {
        getRotatePtr(pActor)->z = z;
    }

    // ...

    sead::Vector3f* tryGetScalePtr(LiveActor* pActor) {
        return pActor->mActorPoseKeeper->getScalePtr();
    }

    f32 getScaleX(const LiveActor* pActor) {
        return pActor->mActorPoseKeeper->getScalePtr()->x;
    }

    f32 getScaleY(const LiveActor* pActor) {
        return pActor->mActorPoseKeeper->getScalePtr()->y;
    }

    f32 getScaleZ(const LiveActor* pActor) {
        return pActor->mActorPoseKeeper->getScalePtr()->z;
    }

    void setScale(LiveActor* pActor, const sead::Vector3f& rScale) {
        tryGetScalePtr(pActor)->set(rScale);
    }

    void setScale(LiveActor* pActor, f32 x, f32 y, f32 z) {
        auto scale = pActor->mActorPoseKeeper->getScalePtr();
        scale->set(x, y, z);
    }

    void setScaleAll(LiveActor* pActor, f32 scalar) {
        setScale(pActor, scalar, scalar, scalar);
    }

    void setScaleX(LiveActor* pActor, f32 x) {
        tryGetScalePtr(pActor)->x = x;
    }

    void setScaleY(LiveActor* pActor, f32 y) {
        tryGetScalePtr(pActor)->y = y;
    }

    void setScaleZ(LiveActor* pActor, f32 z) {
        tryGetScalePtr(pActor)->z = z;
    }
};  // namespace al