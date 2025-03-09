#pragma once

#include <math/seadMatrix.h>

namespace al {
class LiveActor;

void tryInitFixedModelGpuBuffer(LiveActor*);

bool isHideModel(const LiveActor*);

void hideModel(LiveActor*);
void showModel(LiveActor*);

void showModelIfHide(LiveActor*);
void hideModelIfShow(LiveActor*);

void setNeedSetBaseMtxAndCalcAnimFlag(LiveActor*, bool);

sead::Matrix34f* getJointMtxPtr(const LiveActor*, const char*);
}  // namespace al
