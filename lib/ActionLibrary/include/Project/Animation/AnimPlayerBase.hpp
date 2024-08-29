#pragma once

#include <types.hpp>

#include "Library/HostIO/IUseHioNode.hpp"

namespace al {
    class AnimInfoTable;

    class AnimPlayerBase : public HioNode {
    public:
        AnimPlayerBase();

        virtual void updateLast();
        virtual bool calcNeedUpdateAnimNext() = 0;

        AnimInfoTable* mInfoTable = nullptr;  // 0x08
        bool _10 = false;
        bool _11 = false;
    };
};  // namespace al