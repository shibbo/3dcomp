#include "Library/Play/Placement/PlacementUtil.hpp"

#include "Library/Actor/ActorInitInfo.hpp"
#include "Library/Play/Placement/PlacementInfo.hpp"
#include "Project/Base/StringOpUtil.hpp"
#include "Project/Base/StringUtil.hpp"

namespace al {
bool isValidInfo(const PlacementInfo& rInfo) {
    return rInfo.placementIter.isValid();
}

bool isPlaced(const ActorInitInfo& rInfo) {
    return isValidInfo(*rInfo.mPlacementInfo);
}

void getObjectName(const char** pName, const ActorInitInfo& rInfo) {
    getObjectName(pName, *rInfo.mPlacementInfo);
}

void getObjectName(const char** pName, const PlacementInfo& rInfo) {
    const char* name = "";
    if (rInfo.placementIter.tryGetStringByKey(&name, "UnitConfigName")) {
        if (!isEqualString("", name))
            *pName = name;
    }
}

bool tryGetObjectName(const char** pName, const PlacementInfo& rInfo) {
    const char* name = "";

    if (!rInfo.placementIter.tryGetStringByKey(&name, "UnitConfigName"))
        return false;

    if (isEqualString("", name))
        return false;

    *pName = name;
    return true;
}

bool tryGetObjectName(const char** pName, const ActorInitInfo& rInfo) {
    return tryGetObjectName(pName, *rInfo.mPlacementInfo);
}

/*bool isObjectName(const PlacementInfo& rInfo, const char* pName) {
    const char* name;
    tryGetObjectName(&name, rInfo);
    return isEqualString(name, pName);
}*/

bool isObjectNameSubStr(const ActorInitInfo& rInfo, const char* pName) {
    return isObjectNameSubStr(*rInfo.mPlacementInfo, pName);
}

bool isObjectNameSubStr(const PlacementInfo& rInfo, const char* pName) {
    const char* name;
    if (!tryGetObjectName(&name, rInfo))
        return false;

    return isEqualSubString(name, pName);
}
}  // namespace al
