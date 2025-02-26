#pragma once

namespace al {
    class SceneObjHolder;

    class IUseSceneObjHolder {
    public:
        virtual SceneObjHolder* getSceneObjHolder() const = 0;
    };
};