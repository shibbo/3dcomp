#pragma once

namespace al {
    class LiveActor;
    class HitSensor;
    class SensorMsg;

    bool isSensorSimple(const HitSensor*);
    void updateHitSensorsAll(LiveActor*);
    bool isMySensor(const HitSensor*, LiveActor*);

    HitSensor* getHitSensor(const LiveActor*, const char*);

    bool isMsgFloorTouch(const SensorMsg*);

};  // namespace al