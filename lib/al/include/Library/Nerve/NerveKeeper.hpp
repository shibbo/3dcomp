#pragma once

#include <basis/seadTypes.h>

namespace al {
class Nerve;
class NerveActionCtrl;
class NerveStateCtrl;
class IUseNerve;

class NerveKeeper {
public:
    NerveKeeper(void*, const Nerve*, s32);

    void update();
    void tryChangeNerve();
    void setNerve(const Nerve*);
    const Nerve* getCurrentNerve() const;
    void initNerveAction(NerveActionCtrl*);

    template <class T>
    T* getParent() {
        return static_cast<T*>(mKeeperUser);
    }

    IUseNerve* mKeeperUser;
    const Nerve* mLastNerve;
    const Nerve* mNerve;
    u32 mNerveStep;
    u32 _1c;
    NerveStateCtrl* mStateCtrl;
    NerveActionCtrl* mActionCtrl;
};
}  // namespace al
