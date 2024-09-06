#include "Project/Play/Actor/Sky.hpp"
#include "Library/Actor/ActorInitInfo.hpp"
#include "Library/Actor/ActorPoseUtil.hpp"
#include "Library/Clipping/ClippingUtil.hpp"
#include "Library/Placement/PlacementFunction.hpp"
#include "Project/Camera/CameraUtil.hpp"

namespace al {
    Sky::Sky(const char* pName) : LiveActor(pName) {}

    void Sky::init(const ActorInitInfo& rInfo) {
        bool isUseDemo = false;
        al::tryGetArg(&isUseDemo, rInfo, "IsUseDemo");

        al::initActorChangeModelSuffix(this, rInfo, isUseDemo ? "Demo" : nullptr);
        al::invalidateClipping(this);
        bool isOnlyCubeMap = false;
        al::tryGetArg(&isOnlyCubeMap, rInfo, "IsOnlyCubeMap");

        if (isOnlyCubeMap) {
            makeActorDead();
        } else {
            al::trySyncStageSwitchAppear(this);
        }
    }

    void Sky::control() {
        al::setTrans(this, al::getCameraPos(this));
    }
};  // namespace al