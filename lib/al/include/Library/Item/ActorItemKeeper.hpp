#pragma once

#include <math/seadVector.h>
#include <basis/seadTypes.h>
#include "Library/Actor/ActorInitInfo.hpp"
#include "Library/Item/ActorItemInfo.hpp"

namespace al {
    class LiveActor;
    class HitSensor;

    class ActorItemKeeper {
    public:
        ActorItemKeeper(const LiveActor*, int);

        ActorItemInfo* addItem(const ActorInitInfo&, const char*, const char*, const char*, bool);
        void setFactor(const char*, const HitSensor*);
        ActorItemInfo* getAppearItemInfo(const char*) const;

        const LiveActor* mHostActor;                 // 0x00
        ActorItemInfo** mItemInfos;                  // 0x08
        int mMaxItemInfos;                           // 0x10
        int mCurNumItemInfos = 0;                    // 0x14
        const char* mFactor = nullptr;               // 0x18
        const HitSensor* mAttackerSensor = nullptr;  // 0x20
        sead::Vector3f mItemOffset;                  // 0x28
        u32 _34;
    };
};  // namespace al