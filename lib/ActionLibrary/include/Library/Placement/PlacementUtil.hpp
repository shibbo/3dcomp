#pragma once

#include <math/seadVector.h>

namespace al {
    class PlacementInfo;
    class ActorInitInfo;
    class PlacementId;

    bool isValidInfo(const PlacementId&);
    bool isPlaced(const ActorInitInfo&);
    void getObjectName(const char**, const ActorInitInfo&);
    void getObjectName(const char**, const PlacementInfo&);
    bool tryGetObjectName(const char**, const PlacementInfo&);
    bool tryGetObjectName(const char**, const ActorInitInfo&);
    bool tryGetStringArg(const char**, const PlacementInfo&, const char*);
    bool isObjectName(const ActorInitInfo&, const char*);
    bool isObjectName(const PlacementInfo&, const char*);
    bool isObjectNameSubStr(const ActorInitInfo&, const char*);
    bool isObjectNameSubStr(const PlacementInfo&, const char*);

    bool isClassName(const PlacementInfo&, const char*);
};  // namespace al