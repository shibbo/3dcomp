#pragma once

#include "Library/Nerve/IUseNerve.hpp"
#include "Library/HostIO/IUseHioNode.hpp"

namespace al {
    class Nerve;

    class NerveExecutor : public IUseNerve, public HioNode {
    public:
        virtual NerveKeeper* getNerveKeeper() const;
        virtual ~NerveExecutor();

        void initNerve(const Nerve *, int);
        void updateNerve();

        NerveKeeper* mNerveKeeper;      // 0x08
    };
};