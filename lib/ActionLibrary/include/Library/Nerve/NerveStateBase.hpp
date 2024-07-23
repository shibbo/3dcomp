#pragma once

#include "Library/Nerve/NerveExecutor.hpp"

namespace al {
    class LiveActor;

    class NerveStateBase : public NerveExecutor {
    public:
        NerveStateBase(const char *);

        virtual ~NerveStateBase();

        virtual void init() {

        }

        virtual void appear() {
            mIsDead = false;
        }

        virtual void kill() {
            mIsDead = true;
        }

        virtual bool update();

        virtual void control() {

        }

        bool mIsDead = true;           // 0x10
    };

    class ActorStateBase : public NerveStateBase {
    public:
        ActorStateBase(const char *, LiveActor *);

        virtual ~ActorStateBase();

        LiveActor* mHostActor;          // 0x18
    };
};