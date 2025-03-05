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

    bool isMsgAskSafetyPoint(const SensorMsg*);

    bool isMsgHideModel(const SensorMsg*);

    bool isMsgSink(const SensorMsg*);

    bool isMsgShowModel(const SensorMsg*);

};  // namespace al