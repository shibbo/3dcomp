#pragma once

#include <math/seadQuat.h>
#include <math/seadVector.h>
#include <types.hpp>

namespace al {
    class ActorInitInfo;
    class KeyPoseKeeper;

    KeyPoseKeeper* createKeyPoseKeeper(const ActorInitInfo&);
    void resetKeyPose(KeyPoseKeeper*);
    sead::Vector3f& getCurrentKeyTrans(const KeyPoseKeeper*);
    sead::Vector3f& getNextKeyTrans(const KeyPoseKeeper*);

    void calcLerpKeyTrans(sead::Vector3f*, const KeyPoseKeeper*, f32);

    void calcSlerpKeyQuat(sead::Quatf*, const KeyPoseKeeper*, f32);

    f32 calcDistanceNextKeyTrans(const KeyPoseKeeper*);
};  // namespace al