#pragma once

#include <basis/seadTypes.h>

#include "Library/HostIO/IUseHioNode.hpp"
#include "Library/Nerve/IUseNerve.hpp"

namespace al {
class Nerve;

class NerveExecutor : public IUseNerve, public HioNode {
public:
    NerveExecutor(const char*);

    virtual NerveKeeper* getNerveKeeper() const { return mNerveKeeper; }

    virtual ~NerveExecutor();

    void initNerve(const Nerve*, s32);
    void updateNerve();

    NerveKeeper* mNerveKeeper = nullptr;
};
}  // namespace al
