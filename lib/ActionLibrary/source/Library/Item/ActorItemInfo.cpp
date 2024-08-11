#include "Library/Item/ActorItemInfo.hpp"
#include "Project/Base/StringUtil.hpp"

namespace al {
    ActorItemInfo::ActorItemInfo(const char *pItemKind, const char *pTiming, const char *pFactor) {
        mItemKind = pItemKind;
        mTiming = pTiming;
        mFactor = pFactor;
    }

    bool ActorItemInfo::isEqualTiming(const char *pType) const {
        bool res = (pType || mTiming) == 0;

        if (pType != nullptr && mTiming != nullptr) {
            return al::isEqualString(pType, mTiming);
        }

        return res;
    }

    bool ActorItemInfo::isEqualFactor(const char *pFactor) const {
        bool res = (pFactor || mFactor) == 0;

        if (pFactor != nullptr && mFactor != nullptr) {
            return al::isEqualString(pFactor, mFactor);
        }

        return res;
    }
};