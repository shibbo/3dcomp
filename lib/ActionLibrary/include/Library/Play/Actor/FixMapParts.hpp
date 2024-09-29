#pragma once

#include "Library/LiveActor/LiveActor.hpp"

namespace al {
    class MtxConnector;

    class FixMapParts : public LiveActor {
    public:
        FixMapParts(const char*);

        virtual ~FixMapParts();
        virtual void init(const ActorInitInfo&);
        virtual void initAfterPlacement();
        virtual void appear();
        virtual void updateLinkedTrans(const sead::Vector3f&);
        virtual bool receiveMsg(const SensorMsg*, HitSensor*, HitSensor*);
        virtual void control();

        void initWithSuffix(const ActorInitInfo&, const char*);

        MtxConnector* mConnector = nullptr;  // 0x148
    };
};  // namespace al