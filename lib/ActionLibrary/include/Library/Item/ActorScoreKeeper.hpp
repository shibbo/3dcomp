#pragma once

#include "Library/Yaml/BymlIter.hpp"

namespace al {
    class ActorScoreInfo {
        public:
            ActorScoreInfo();

            void init(const ByamlIter &);

            const char* mFactorName = nullptr;          // 0x00
            const char* mCategoryName = nullptr;        // 0x08
    };

    class ActorScoreKeeper {
    public:
        ActorScoreKeeper();

        void init(const ByamlIter &);
        const char* getCategoryName() const;
        const char* tryGetCategoryName(const char *) const;

        ActorScoreInfo* mScoreInfos = nullptr;     // 0x00
        s32 mScoreNum = 0;                         // 0x08
    };
};