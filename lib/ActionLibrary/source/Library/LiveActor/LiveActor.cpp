#include "Library/LiveActor/LiveActor.hpp"
#include "Library/LiveActor/LiveActorFlag.hpp"
#include "Library/Placement/PlacementHolder.hpp"
#include "Library/Model/ModelKeeper.hpp"

namespace al {
    LiveActor::LiveActor(const char *pName) : mActorName(pName) {
        mFarLodActor = nullptr;
        mActorFlags = new LiveActorFlag();
        mPlacementHolder = new PlacementHolder();
    }

    void LiveActor::initNerveKeeper(NerveKeeper* pKeeper) {
        mNerveKeeper = pKeeper;
    }

    NerveKeeper* LiveActor::getNerveKeeper() const {
        return mNerveKeeper;
    }

    void LiveActor::setGlobalYOffsetRef(f32 *pOffs) {
        LiveActor* curActor = this;

       do {
            curActor->mGlobalYOffset = pOffs;

            if (curActor->mModelKeeper != nullptr) {
                curActor->mModelKeeper->setGlobalYOffset(pOffs);
            }

            if (curActor->mSubActorKeeper != nullptr) {
                alSubActorFunction::setGlobalYOffset(curActor->mSubActorKeeper, pOffs);
            }

            curActor = curActor->mFarLodActor;
       } while(curActor != nullptr);
    }

    f32 LiveActor::getGlobalYOffset() const {
        const f32* ptr = (mGlobalYOffset != nullptr ? mGlobalYOffset : &_130);
        return *ptr;
    }

    void LiveActor::setFarLodActor(LiveActor *pFarLodActor) {
        mFarLodActor = pFarLodActor;
    }
}; 