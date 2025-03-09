#pragma once

namespace al {
class CameraDirector_RS;

class IUseCamera_RS {
public:
    virtual CameraDirector_RS* getCameraDirector_RS() const = 0;
};
}  // namespace al
