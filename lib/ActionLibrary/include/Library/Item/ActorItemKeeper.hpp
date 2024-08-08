#pragma once

#include <types.hpp>
#include "Library/Actor/ActorInitInfo.hpp"
#include "Library/Item/ActorItemInfo.hpp"

namespace al {
    class LiveActor;
    class HitSensor;

    class ActorItemKeeper {
    public:
        ActorItemKeeper(const LiveActor *, int);

        ActorItemInfo* addItem(const ActorInitInfo &, const char *, const char *, const char *, bool);
        void setFactor(const char *, const HitSensor *);
        ActorItemInfo* getAppearItemInfo(const char *) const;

        const LiveActor* mHostActor;        // 0x00
        ActorItemInfo** mItemInfos;         // 0x08
        int mMaxItemInfos;                  // 0x10
        int mCurNumItemInfos = 0;               // 0x14
        const char* _18 = nullptr;
        const HitSensor* _20 = nullptr;
        u32 _28 = 0;
        u32 _2C = 0;
        u32 _30 = 0;
        u32 _34;
    };
};