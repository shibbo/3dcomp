#include "Library/Play/AreaObj/SePlayArea.hpp"

#include "Project/AreaObj/AreaObjUtil.hpp"

namespace al {
SePlayArea::SePlayArea(const char* pName) : AreaObj(pName) {}

void SePlayArea::init(const AreaInitInfo& rInfo) {
    AreaObj::init(rInfo);
    tryGetAreaObjStringArg(&mPlayName, this, "SePlayName");
    bool isStartEnabled = false;
    bool gotArg = tryGetAreaObjArg(&isStartEnabled, this, "IsStartEnabled");

    if (isStartEnabled && gotArg)
        mIsValid = true;
}
}  // namespace al
