#pragma once

#include <basis/seadTypes.h>

namespace al {
class SceneStopCtrl;
class ScreenCoverCtrl;
class DemoDirector;
class CameraDirector_RS;
class PadRumbleDirector;
class SceneObjHolder;
class ClippingDirectorBase;
class PlayerHolder;
class SceneCameraInfo;
class CollisionDirector;
class ItemDirectorBase;
class ShadowDirector;
class AreaObjDirector;

struct ActorSceneInfo {
    SceneObjHolder* sceneObjHolder;
    ClippingDirectorBase* clippingDirectorBase;
    CollisionDirector* collisionDirector;
    PlayerHolder* playerHolder;
    SceneCameraInfo* sceneCameraInfo;
    SceneStopCtrl* sceneStopCtrl;
    ScreenCoverCtrl* screenCoverCtrl;
    ItemDirectorBase* itemDirectorBase;
    DemoDirector* demoDirector;
    AreaObjDirector* areaObjDirector;
    ShadowDirector* shadowDirector;
    PadRumbleDirector* padRumbleDirector;
    CameraDirector_RS* cameraDirector;
    bool isSingleMode;
    void* _70;
    void* _78;
};
}  // namespace al
