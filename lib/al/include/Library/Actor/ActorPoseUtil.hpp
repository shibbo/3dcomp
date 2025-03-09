#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {
class LiveActor;
void initActorPoseT(LiveActor*, const sead::Vector3f&);
void initActorPoseTR(LiveActor*, const sead::Vector3f&, const sead::Vector3f&);
void makeMtxSRT(sead::Matrix34f*, const LiveActor*);
void makeMtxRT(sead::Matrix34f*, const LiveActor*);

void multVecPose(sead::Vector3f*, const LiveActor*, const sead::Vector3f&);

void copyPose(LiveActor*, const LiveActor*);
void updatePoseRotate(LiveActor*, const sead::Vector3f&);

void setTrans(LiveActor*, const sead::Vector3f&);
void setTrans(LiveActor*, f32, f32, f32);
void setTransX(LiveActor*, f32);
void setTransY(LiveActor*, f32);
void setTransZ(LiveActor*, f32);

void setRotate(LiveActor*, const sead::Vector3f&);
void setRotate(LiveActor*, f32, f32, f32);
void setRotateX(LiveActor*, f32);
void setRotateY(LiveActor*, f32);
void setRotateZ(LiveActor*, f32);

void setScale(LiveActor*, const sead::Vector3f&);
void setScale(LiveActor*, f32, f32, f32);
void setScaleAll(LiveActor*, f32);
void setScaleX(LiveActor*, f32);
void setScaleY(LiveActor*, f32);
void setScaleZ(LiveActor*, f32);

f32 getScaleX(const LiveActor*);
f32 getScaleY(const LiveActor*);
f32 getScaleZ(const LiveActor*);

sead::Vector3f* tryGetScalePtr(LiveActor*);

const sead::Vector3f& getGravity(const LiveActor*);
const sead::Vector3f& getTrans(const LiveActor*);
const sead::Vector3f& getScale(const LiveActor*);
const sead::Vector3f& getRotate(const LiveActor*);

sead::Vector3f* getTransPtr(LiveActor*);
sead::Vector3f* getRotatePtr(LiveActor*);

sead::Quatf* getQuatPtr(LiveActor*);

}  // namespace al
