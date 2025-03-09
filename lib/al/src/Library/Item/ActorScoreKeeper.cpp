#include "Library/Item/ActorScoreKeeper.hpp"

#include "Library/Yaml/ByamlIter.hpp"
#include "Project/Base/StringUtil.hpp"

namespace al {
ActorScoreInfo::ActorScoreInfo() = default;

void ActorScoreInfo::init(const ByamlIter& rIter) {
    rIter.tryGetStringByKey(&mFactorName, "FactorName");
    rIter.tryGetStringByKey(&mCategoryName, "CategoryName");
}

ActorScoreKeeper::ActorScoreKeeper() = default;

void ActorScoreKeeper::init(const ByamlIter& rIter) {
    if (!rIter.isTypeArray()) {
        mScoreNum = 1;
        mScoreInfos = new ActorScoreInfo[1];
        mScoreInfos->init(rIter);
        return;
    }
    mScoreNum = rIter.getSize();
    mScoreInfos = new ActorScoreInfo[mScoreNum];

    for (s32 i = 0; i < mScoreNum; i++) {
        ByamlIter iter;
        rIter.tryGetIterByIndex(&iter, i);
        mScoreInfos[i].init(iter);
    }
}

const char* ActorScoreKeeper::getCategoryName() const {
    return mScoreInfos->mCategoryName;
}

const char* ActorScoreKeeper::tryGetCategoryName(const char* pFactor) const {
    if (mScoreNum < 0)
        return nullptr;

    for (s32 i = 0; i < mScoreNum; i++) {
        if (mScoreInfos->mFactorName != nullptr) {
            if (isEqualString(mScoreInfos[i].mFactorName, pFactor))
                return mScoreInfos[i].mCategoryName;
        }
    }

    return nullptr;
}
}  // namespace al
