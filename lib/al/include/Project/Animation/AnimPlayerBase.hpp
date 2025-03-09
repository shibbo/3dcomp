#pragma once

#include <basis/seadTypes.h>

#include "Library/HostIO/IUseHioNode.hpp"

namespace al {
class AnimInfoTable;

class AnimPlayerBase : public HioNode {
public:
    AnimPlayerBase();

    virtual void updateLast();
    virtual bool calcNeedUpdateAnimNext() = 0;

    AnimInfoTable* mInfoTable = nullptr;
    bool _10 = false;
    bool _11 = false;
};
}  // namespace al
