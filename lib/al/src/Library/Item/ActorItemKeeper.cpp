#include "Library/Item/ActorItemKeeper.hpp"

#include "Library/Actor/ActorSceneInfo.hpp"
#include "Library/Item/ItemDirectorBase.hpp"
#include "Library/LiveActor/LiveActor.hpp"

namespace al {
ActorItemKeeper::ActorItemKeeper(const LiveActor* pActor, s32 maxItems)
    : mHostActor(pActor), mMaxItemInfos(maxItems) {
    mItemOffset.x = 0;
    mItemOffset.y = 0;
    mItemOffset.z = 0;
    mItemInfos = new ActorItemInfo*[mMaxItemInfos];
}

ActorItemInfo* ActorItemKeeper::addItem(const ActorInitInfo& rInfo, const char* a2, const char* a3,
                                        const char* a4, bool a5) {
    if (mHostActor->getSceneInfo()->itemDirectorBase != nullptr) {
        ActorSceneInfo* sceneInfo = mHostActor->getSceneInfo();
        sceneInfo->itemDirectorBase->declareItem(a2, rInfo);
    }

    ActorItemInfo* info = new ActorItemInfo(a2, a3, a4);
    mItemInfos[mCurNumItemInfos] = info;
    mCurNumItemInfos++;
    return info;
}

void ActorItemKeeper::setFactor(const char* a1, const HitSensor* a2) {
    mFactor = a1;
    mAttackerSensor = a2;
}

ActorItemInfo* ActorItemKeeper::getAppearItemInfo(const char* pName) const {
    for (s32 i = 0; i < mCurNumItemInfos; i++)
        if (mItemInfos[i]->isEqualTiming(pName) && mItemInfos[i]->isEqualFactor(mFactor))
            return mItemInfos[i];

    return nullptr;
}
}  // namespace al
