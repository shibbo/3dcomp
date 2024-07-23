#pragma once

#include <types.hpp>

namespace al {
    class Nerve;
    class NerveActionCtrl;
    class NerveStateCtrl;
    class IUseNerve;

    class NerveKeeper {
    public:
        NerveKeeper(void *, const Nerve *, s32);

        void update();
        void tryChangeNerve();
        void setNerve(const Nerve *);
        const Nerve* getCurrentNerve() const;
        void initNerveAction(NerveActionCtrl *);

        IUseNerve* mKeeperUser;             // 0x00
        const Nerve* mLastNerve;            // 0x08
        const Nerve* mNerve;                // 0x10
        u32 mNerveStep;                     // 0x18
        u32 _1C;
        NerveStateCtrl* mStateCtrl;         // 0x20
        NerveActionCtrl* mActionCtrl;       // 0x28
    };
};