#pragma once

#include <basis/seadTypes.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {
class ActorInitInfo;
class KeyPoseKeeper;

KeyPoseKeeper* createKeyPoseKeeper(const ActorInitInfo&);
void resetKeyPose(KeyPoseKeeper*);
const sead::Vector3f& getCurrentKeyTrans(const KeyPoseKeeper*);
const sead::Vector3f& getNextKeyTrans(const KeyPoseKeeper*);

void calcLerpKeyTrans(sead::Vector3f*, const KeyPoseKeeper*, f32);

void calcSlerpKeyQuat(sead::Quatf*, const KeyPoseKeeper*, f32);

f32 calcDistanceNextKeyTrans(const KeyPoseKeeper*);
}  // namespace al
