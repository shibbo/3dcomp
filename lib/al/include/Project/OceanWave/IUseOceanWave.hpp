#pragma once

namespace al {
class OceanWaveKeeper;

class IUseOceanWave {
public:
    OceanWaveKeeper* mOceanWaveKeeper = nullptr;
};
}  // namespace al
