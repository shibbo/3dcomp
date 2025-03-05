#pragma once

namespace al {
    class AreaObj;
    class LiveActor;
    class ActorInitInfo;

    bool tryGetAreaObjStringArg(const char**, const AreaObj*, const char*);

    bool tryGetAreaObjArg(bool*, const AreaObj*, const char*);

    void registerAreaHostMtx(const LiveActor*, const ActorInitInfo&);
};  // namespace al