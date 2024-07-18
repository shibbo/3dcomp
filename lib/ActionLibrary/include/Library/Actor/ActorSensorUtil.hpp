#pragma once

namespace al {
    class LiveActor;
    class HitSensor;

    bool isSensorSimple(const HitSensor *);
    void updateHitSensorsAll(LiveActor *);
    bool isMySensor(const HitSensor *, LiveActor *);
};