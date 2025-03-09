#include "Library/StageSwitch/StageSwitchAccesser.hpp"

#include "Library/Play/Placement/PlacementId.hpp"
#include "Library/StageSwitch/Core/StageSwitchDirector.hpp"
#include "Project/Base/StringUtil.hpp"

namespace al {
StageSwitchAccesserList::StageSwitchAccesserList() {}

StageSwitchAccesserList::StageSwitchAccesserList(const StageSwitchAccesser* pAccesser) {
    mAccesser = pAccesser;
    _8 = 0;
}

StageSwitchAccesser::StageSwitchAccesser() {}

bool StageSwitchAccesser::init(StageSwitchDirector* pDirector, const char* pName,
                               const PlacementId& rId, bool isDisasterMode) {
    mStageSwitchDirector = pDirector;
    mName = pName;
    mPlacementId = new PlacementId(rId);
    mIsDisasterMode = isDisasterMode;

    s32 state;

    if (!isMatchString(pName, MatchStr("On")) && !isMatchString(pName, MatchStr("Off")))
        state = 1;
    else
        state = 2;

    _24 = state;
    mSwitchNo = mStageSwitchDirector->useSwitch(this);
    return isValid();
}

bool StageSwitchAccesser::isValid() const {
    return mSwitchNo >= 0;
}

void StageSwitchAccesser::onSwitch() {
    if (isValid())
        getStageSwitchDirector()->onSwitch(this);
}

void StageSwitchAccesser::offSwitch() {
    if (isValid())
        getStageSwitchDirector()->offSwitch(this);
}

bool StageSwitchAccesser::isOnSwitch() const {
    return getStageSwitchDirector()->isOnSwitch(this);
}

StageSwitchDirector* StageSwitchAccesser::getStageSwitchDirector() const {
    return mStageSwitchDirector;
}

bool StageSwitchAccesser::isEnableRead() const {
    return (_24 - 1) < 2;
}

bool StageSwitchAccesser::isEnableWrite() const {
    return _24 == 2;
}

bool StageSwitchAccesser::isEqualSwitch(const StageSwitchAccesser* pOther) const {
    if (pOther != nullptr)
        return mSwitchNo == pOther->mSwitchNo;

    return false;
}

void StageSwitchAccesser::doInstanceResponse() {
    getStageSwitchDirector()->instantUpdate(this);
}

void StageSwitchAccesser::addListener(StageSwitchListener* pListener) {
    getStageSwitchDirector()->addListener(pListener, this);
}
}  // namespace al
