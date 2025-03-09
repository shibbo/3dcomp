#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/Actor/ActorInitInfo.hpp"
#include "Library/Item/ActorItemInfo.hpp"

namespace al {
class LiveActor;
class HitSensor;

class ActorItemKeeper {
public:
    ActorItemKeeper(const LiveActor*, s32);

    ActorItemInfo* addItem(const ActorInitInfo&, const char*, const char*, const char*, bool);
    void setFactor(const char*, const HitSensor*);
    ActorItemInfo* getAppearItemInfo(const char*) const;

    const LiveActor* mHostActor;
    ActorItemInfo** mItemInfos;
    s32 mMaxItemInfos;
    s32 mCurNumItemInfos = 0;
    const char* mFactor = nullptr;
    const HitSensor* mAttackerSensor = nullptr;
    sead::Vector3f mItemOffset;
    u32 _34;
};
}  // namespace al
