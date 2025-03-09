#include "Library/Nerve/NerveUtil.hpp"

#include "Library/Nerve/IUseNerve.hpp"
#include "Library/Nerve/Nerve.hpp"
#include "Library/Nerve/NerveKeeper.hpp"

namespace al {
void setNerve(IUseNerve* pUser, const Nerve* pNerve) {
    pUser->getNerveKeeper()->setNerve(pNerve);
}

void setNerveAtStep(IUseNerve* pUser, const Nerve* pNerve, s32 step) {
    if (getNerveStep(pUser) == step)
        pUser->getNerveKeeper()->setNerve(pNerve);
}

bool isStep(const IUseNerve* pUser, s32 step) {
    return getNerveStep(pUser) == step;
}

bool isNerve(const IUseNerve* pUser, const Nerve* pNerve) {
    return getNerve(pUser) == pNerve;
}

s32 getNerveStep(const IUseNerve* pUser) {
    return pUser->getNerveKeeper()->mNerveStep;
}

const Nerve* getNerve(const IUseNerve* pUser) {
    return pUser->getNerveKeeper()->getCurrentNerve();
}

bool isFirstStep(const IUseNerve* pUser) {
    return getNerveStep(pUser) == 0;
}

bool isLessStep(const IUseNerve* pUser, s32 step) {
    return getNerveStep(pUser) < step;
}

bool isLessEqualStep(const IUseNerve* pUser, s32 step) {
    return getNerveStep(pUser) <= step;
}

bool isGreaterStep(const IUseNerve* pUser, s32 step) {
    return getNerveStep(pUser) > step;
}

bool isGreaterEqualStep(const IUseNerve* pUser, s32 step) {
    return getNerveStep(pUser) >= step;
}

bool isIntervalStep(const IUseNerve* pUser, s32 min, s32 max) {
    return (getNerveStep(pUser) - max) % min == 0;
}

bool isIntervalOnOffStep(const IUseNerve* pUser, s32 min, s32 max) {
    return (((getNerveStep(pUser) - max) / min) & 0x1) == 0;
}

bool isNewNerve(const IUseNerve* pUser) {
    return getNerveStep(pUser) >> 31;
}

}  // namespace al
