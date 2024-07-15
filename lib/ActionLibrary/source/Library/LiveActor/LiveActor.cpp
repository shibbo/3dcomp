#include "Library/LiveActor/LiveActor.hpp"
#include "Library/LiveActor/LiveActorFlag.hpp"
#include "Library/LiveActor/PlacementHolder.hpp"

namespace al {
    LiveActor::LiveActor(const char *pName) : mActorName(pName) {
        _58 = 0;
        _60 = 0;
        _68 = 0;
        mItemKeeper = 0;
        mScreenPointKeeper = 0;
        mCollider = 0; 
        _88 = 0; 
        mModelKeeper = 0; 
        mNerveKeeper = 0;
        mHitSensorKeeper = 0; 
        mScreenPointKeeper = 0;
        mEffectKeeper = 0;
        mAudioKeeper = 0;
        _C0 = 0;
        mStageSwitchKeeper = 0;
        mRailKeeper = 0;
        mShadowKeeper = 0; 
        mLightKeeper = 0;
        mSubActorKeeper = 0;
        _F0 = 0;
        mActorSceneInfo = 0;
        _100 = 0;
        mActorFlags = 0;
        _110 = 0;
        mPlacementHolder = 0;
        mActorFlags = new LiveActorFlag();
        mPlacementHolder = new PlacementHolder();
    }

    void LiveActor::initNerveKeeper(NerveKeeper* pKeeper) {
        mNerveKeeper = pKeeper;
    }

    NerveKeeper* LiveActor::getNerveKeeper() const {
        return mNerveKeeper;
    }
};