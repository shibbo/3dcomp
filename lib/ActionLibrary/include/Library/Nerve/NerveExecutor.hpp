#pragma once

#include "Library/Nerve/IUseNerve.hpp"
#include "Library/HostIO/IUseHioNode.hpp"

namespace al {
    class Nerve;

    class NerveExecutor : public IUseNerve, public HioNode {
    public:
        NerveExecutor(const char *);

        virtual NerveKeeper* getNerveKeeper() const {
            return mNerveKeeper;
        }

        virtual ~NerveExecutor();

        void initNerve(const Nerve *, int);
        void updateNerve();

        NerveKeeper* mNerveKeeper = nullptr;      // 0x08
    };
};