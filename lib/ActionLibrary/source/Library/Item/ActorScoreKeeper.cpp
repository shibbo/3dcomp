#include "Library/Item/ActorScoreKeeper.hpp"
#include "Library/Base/StringUtil.hpp"
#include <cstring>

namespace al {
    ActorScoreInfo::ActorScoreInfo() = default;

    void ActorScoreInfo::init(const ByamlIter &rIter) {
        rIter.tryGetStringByKey(&mFactorName, "FactorName");
        rIter.tryGetStringByKey(&mCategoryName, "CategoryName");
    }

    ActorScoreKeeper::ActorScoreKeeper() = default;

    void ActorScoreKeeper::init(const ByamlIter &rIter) {
        if (!rIter.isTypeArray()) { 
            mScoreNum = 1;
            mScoreInfos = new ActorScoreInfo();
            mScoreInfos->init(rIter);
        }
        else {
            mScoreNum = rIter.getSize();
            auto infos = new ActorScoreInfo[mScoreNum];

            if (mScoreNum != 0) {
                mScoreInfos = infos;

                for (int i = 0; i < mScoreNum; i++) { 
                    ByamlIter iter;
                    rIter.tryGetIterByIndex(&iter, i);
                    mScoreInfos[i].init(iter);
                }
            }
            else {
                mScoreInfos = infos;
            }
        }
    }

    const char* ActorScoreKeeper::getCategoryName() const {
        return mScoreInfos->mCategoryName;
    }

    const char* ActorScoreKeeper::tryGetCategoryName(const char *pFactor) const {
        if (mScoreNum < 0) {
            return nullptr;
        }

        for (int i = 0; i < mScoreNum; i++) {
            if (mScoreInfos->mFactorName != nullptr) {
                if (al::isEqualString(mScoreInfos[i].mFactorName, pFactor)) {
                    return mScoreInfos[i].mCategoryName;
                }
            }
        }

        return nullptr;
    }
};