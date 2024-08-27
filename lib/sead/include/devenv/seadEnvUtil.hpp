#pragma once

#include "prim/seadEnum.hpp"
#include "prim/seadSafeString.hpp"

namespace sead {
    SEAD_ENUM(RegionLanguageID, JPja, USen, USes, USfr, USpt, EUen, EUes, EUfr, EUde, EUit, EUpt,
              EUnl, EUru, KRko, CNzh, TWzh)
    SEAD_ENUM(RegionID, JP, US, EU, KR, CN, TW)

    class EnvUtil {
    public:
        static void getRegionLangaugeFromString(RegionLanguageID*, const sead::SafeString&);
    };
};  // namespace sead