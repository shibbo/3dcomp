#include "Library/Item/ActorItemKeeper.hpp"
#include "Library/Item/ItemDirectorBase.hpp"
#include "Library/Actor/ActorSceneInfo.hpp"
#include "Library/LiveActor/LiveActor.hpp"

namespace al {
    ActorItemKeeper::ActorItemKeeper(const LiveActor *pActor, int maxItems) : mHostActor(pActor), mMaxItemInfos(maxItems) {
        mItemOffset.x = 0;
        mItemOffset.y = 0;
        mItemOffset.z = 0;
        mItemInfos = new ActorItemInfo*[mMaxItemInfos];
    }

    ActorItemInfo* ActorItemKeeper::addItem(const ActorInitInfo &rInfo, const char *a2, const char *a3, const char *a4, bool a5) {
        if (mHostActor->getSceneInfo()->mItemDirectorBase != nullptr) {
            auto sceneInfo = mHostActor->getSceneInfo();
            sceneInfo->mItemDirectorBase->declareItem(a2, rInfo);
        }

        auto info = new ActorItemInfo(a2, a3, a4);
        mItemInfos[mCurNumItemInfos] = info;
        mCurNumItemInfos++;
        return info;
    }

    void ActorItemKeeper::setFactor(const char *a1, const HitSensor *a2) {
        mFactor = a1;
        mAttackerSensor = a2;
    }
 
    ActorItemInfo* ActorItemKeeper::getAppearItemInfo(const char *pName) const {
        for (int i = 0; i < mCurNumItemInfos; i++) {
            if (mItemInfos[i]->isEqualTiming(pName) && mItemInfos[i]->isEqualFactor(mFactor)) {
                return mItemInfos[i];
            }
        }

        return nullptr;
    }
};