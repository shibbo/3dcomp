#pragma once

namespace al {
struct ActorInitInfo;

class ISceneObj {
public:
    virtual const char* getSceneObjName() const { return ""; }

    virtual void initAfterPlacementSceneObj(const ActorInitInfo& rInfo) { return; }

    virtual void initSceneObj() { return; }
};
}  // namespace al
