#include "Library/Item/ActorItemFunction.hpp"
#include "Library/Item/ActorItemKeeper.hpp"
#include "Library/Actor/ActorPoseUtil.hpp"
#include "Library/Item/ItemDirectorBase.hpp"

namespace al {
    ActorItemInfo* addItem(LiveActor *pActor, const ActorInitInfo &rInfo, const char *a3, const char *a4, const char *a5, bool a6) {
        return pActor->mItemKeeper->addItem(rInfo, a3, a4, a5, a6);
    }

    ActorItemInfo* addItem(LiveActor *pActor, const ActorInitInfo &rInfo, const char *a3, bool a4) {
        return pActor->mItemKeeper->addItem(rInfo, a3, nullptr, nullptr, a4);
    }

    void setAppearItemFactor(const LiveActor *pActor, const char *pFactor, const HitSensor *pSensor) {
        pActor->mItemKeeper->setFactor(pFactor, pSensor);
    }

    void setAppearItemOffset(const LiveActor *pActor, const sead::Vector3f &rOffs) {
        pActor->mItemKeeper->mItemOffset = rOffs;
    }

    void setAppearItemAttackerSensor(const LiveActor *pActor, const HitSensor *pSensor) {
        pActor->mItemKeeper->mAttackerSensor = pSensor;
    }

    void appearItem(const LiveActor *pActor) {
        appearItem(pActor, al::getTrans(pActor), sead::Vector3<f32>::ez, pActor->mItemKeeper->mAttackerSensor);
    }

    void appearItem(const LiveActor *pActor, const sead::Vector3f &rPosition, const sead::Vector3f &a3, const HitSensor *pSensor) {
        auto appearItemInfo = pActor->mItemKeeper->getAppearItemInfo(nullptr);

        if (appearItemInfo != nullptr) {
            const char* itemKind = appearItemInfo->mItemKind;
            ActorSceneInfo* sceneInfo = pActor->getSceneInfo();
            ActorItemKeeper* itemKeeper = pActor->mItemKeeper;
            sceneInfo->mItemDirectorBase->appearItem(itemKind, rPosition + itemKeeper->mItemOffset, a3, pSensor, false, false);
            itemKeeper->mFactor = nullptr;
            itemKeeper->mItemOffset = sead::Vector3<f32>::zero;
        }
    }

    void appearItem(const LiveActor *pActor, const sead::Vector3f &rPos, const sead::Vector3f &a3) {
        appearItem(pActor, rPos, a3, pActor->mItemKeeper->mAttackerSensor);
    }

    void appearItemTiming(const LiveActor *pActor, const char *pName) {
        appearItemTiming(pActor, pName, al::getTrans(pActor), sead::Vector3<f32>::ez, pActor->mItemKeeper->mAttackerSensor, false);
    }

    void appearItemTiming(const LiveActor *pActor, const char *pTiming, const sead::Vector3f &rPosition, const sead::Vector3f &a4, const HitSensor *pSensor, bool a6) {
        auto appearItemInfo = pActor->mItemKeeper->getAppearItemInfo(pTiming);

        if (appearItemInfo != nullptr) {
            const char* itemKind = appearItemInfo->mItemKind;
            ActorSceneInfo* sceneInfo = pActor->getSceneInfo();
            ActorItemKeeper* itemKeeper = pActor->mItemKeeper;
            sceneInfo->mItemDirectorBase->appearItem(itemKind, rPosition + itemKeeper->mItemOffset, a4, pSensor, a6, false);
            itemKeeper->mFactor = nullptr;
            itemKeeper->mItemOffset = sead::Vector3<f32>::zero;
        }
    }

    void appearItemTiming(const LiveActor *pActor, const char *pTiming, const sead::Vector3f &rPosition, const sead::Vector3f &a4) {
        appearItemTiming(pActor, pTiming, rPosition, a4, pActor->mItemKeeper->mAttackerSensor, false);
    }

   void acquirerItem(const LiveActor *pActor, HitSensor *pSensor, const char *a3) {
        auto sceneInfo = pActor->getSceneInfo();
        sceneInfo->mItemDirectorBase->acquirerItem(pActor, pSensor, a3);
   }
};