#pragma once

#include "Library/LiveActor/LiveActor.hpp"

namespace al {
    class LiveActorGroup {
    public:
        LiveActorGroup(const char*, s32);
        ~LiveActorGroup();

        virtual void registerActor(LiveActor*);

        s32 calcAliveActorNum() const;
        LiveActor* getDeadActor() const;
        LiveActor* tryFindDeadActor() const;
        void appearAll();
        void killAll();
        void makeActorAppearedAll();
        void makeActorDeadAll();

        inline LiveActor* getActor(s32 idx) const { return mActors[idx]; }

        const char* mGroupName;  // 0x08
        s32 mMaxActors;          // 0x10
        s32 mNumActors;          // 0x14
        LiveActor** mActors;     // 0x18
    };
};  // namespace al