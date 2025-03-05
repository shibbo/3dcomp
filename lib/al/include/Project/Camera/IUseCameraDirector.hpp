#pragma once

namespace al {
    class SceneCameraInfo;
    class CameraDirector_RS;

    class IUseCamera {
    public:
        virtual SceneCameraInfo* getSceneCameraInfo() const = 0;
    };

    class IUseCamera_RS {
    public:
        virtual CameraDirector_RS* getCameraDirector_RS() const = 0;
    };
};