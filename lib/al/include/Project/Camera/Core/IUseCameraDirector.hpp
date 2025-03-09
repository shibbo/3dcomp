#pragma once

namespace al {
class SceneCameraInfo;

class IUseCamera {
public:
    virtual SceneCameraInfo* getSceneCameraInfo() const = 0;
};
}  // namespace al
