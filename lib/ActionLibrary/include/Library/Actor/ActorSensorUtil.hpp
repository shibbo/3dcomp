#pragma once

namespace al {
    class LiveActor;
    class HitSensor;

    bool isSensorSimple(const HitSensor*);
    void updateHitSensorsAll(LiveActor*);
    bool isMySensor(const HitSensor*, LiveActor*);

    HitSensor* getHitSensor(const LiveActor*, const char*);
};  // namespace al