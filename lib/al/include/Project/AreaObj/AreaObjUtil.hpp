#pragma once

namespace al {
class ActorInitInfo;
class AreaObj;
class LiveActor;

bool tryGetAreaObjStringArg(const char**, const AreaObj*, const char*);

bool tryGetAreaObjArg(bool*, const AreaObj*, const char*);

void registerAreaHostMtx(const LiveActor*, const ActorInitInfo&);
}  // namespace al
