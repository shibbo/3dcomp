#include "Library/Actor/ActorPoseKeeper.hpp"
#include <math/seadMatrix.hpp>

namespace al {
    ActorPoseKeeperBase::ActorPoseKeeperBase() {}

    /*
    void ActorPoseKeeperBase::copyPose(const ActorPoseKeeperBase* pPose) {
        sead::Matrix34f mtx;
        mtx = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};
        pPose->calcBaseMtx(&mtx);
        updatePoseMtx(&mtx);
    }
    */

    const sead::Vector3f& ActorPoseKeeperTRSV::getRotate() const {
        return mRotate;
    }

    const sead::Vector3f& ActorPoseKeeperTRSV::getScale() const {
        return mScale;
    }

    const sead::Vector3f& ActorPoseKeeperTRSV::getVelocity() const {
        return mVelocity;
    }

};  // namespace al