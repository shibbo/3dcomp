#pragma once

#include <seadTypes.h>

namespace al {
    class PlacementInfo;

    class PlacementHolder {
    public:
        PlacementHolder();

        void init(const PlacementInfo&);

        const char* _0;
        const char* _8;
        const char* _10;
        const char* _18;
        s32 _20;
        s32 _24;
    };
};  // namespace al