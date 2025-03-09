#pragma once

#include <basis/seadTypes.h>

namespace al {
class ByamlIter;

class ActorScoreInfo {
public:
    ActorScoreInfo();

    void init(const ByamlIter&);

    const char* mFactorName = nullptr;
    const char* mCategoryName = nullptr;
};

class ActorScoreKeeper {
public:
    ActorScoreKeeper();

    void init(const ByamlIter&);
    const char* getCategoryName() const;
    const char* tryGetCategoryName(const char*) const;

    ActorScoreInfo* mScoreInfos = nullptr;
    s32 mScoreNum = 0;
};
}  // namespace al
