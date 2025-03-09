#pragma once

#include <basis/seadTypes.h>

namespace al {
class LiveActor;

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

    const char* mGroupName;
    s32 mMaxActors;
    s32 mNumActors = 0;
    LiveActor** mActors;
};
}  // namespace al
