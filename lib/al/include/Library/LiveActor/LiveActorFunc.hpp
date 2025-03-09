#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

namespace al {
class LiveActor;
class SubActorKeeper;
}  // namespace al

namespace alLiveActorFunction {
void calcAnimDirect(al::LiveActor*);
void forceUpdateTrans(al::LiveActor*, const sead::Vector3f&, bool);
void setAlphaCtrlOn(al::LiveActor*, bool);
}  // namespace alLiveActorFunction

namespace alSubActorFunction {
void trySyncAlive(al::SubActorKeeper*);
void trySyncDead(al::SubActorKeeper*);
void trySyncClippingStart(al::SubActorKeeper*);
void trySyncClippingEnd(al::SubActorKeeper*);
void trySyncShowModel(al::SubActorKeeper*);
void trySyncHideModel(al::SubActorKeeper*);
al::LiveActor* findSubActor(const al::SubActorKeeper*, const char*);
void setGlobalYOffset(al::SubActorKeeper*, f32*);
}  // namespace alSubActorFunction
