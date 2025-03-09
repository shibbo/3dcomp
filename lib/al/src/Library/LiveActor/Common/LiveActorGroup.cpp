#include "Library/LiveActor/Common/LiveActorGroup.hpp"

#include "Library/LiveActor/LiveActor.hpp"
#include "Library/LiveActor/LiveActorUtil.hpp"

namespace al {
LiveActorGroup::LiveActorGroup(const char* pGroupName, s32 maxActors)
    : mGroupName(pGroupName), mMaxActors(maxActors) {
    mActors = new LiveActor*[maxActors];
}

LiveActorGroup::~LiveActorGroup() {
    for (s32 i = 0; i < mNumActors; i++)
        delete getActor(i);

    delete[] mActors;
}

void LiveActorGroup::registerActor(LiveActor* pActor) {
    mActors[mNumActors] = pActor;
    mNumActors++;
}

s32 LiveActorGroup::calcAliveActorNum() const {
    s32 aliveNum = 0;

    for (s32 i = 0; i < mNumActors; i++)
        if (!isDead(getActor(i)))
            aliveNum++;

    return aliveNum;
}

LiveActor* LiveActorGroup::getDeadActor() const {
    return tryFindDeadActor();
}

LiveActor* LiveActorGroup::tryFindDeadActor() const {
    for (s32 i = 0; i < mNumActors; i++)
        if (isDead(getActor(i)))
            return getActor(i);

    return nullptr;
}

void LiveActorGroup::appearAll() {
    for (s32 i = 0; i < mNumActors; i++)
        if (isDead(getActor(i)))
            getActor(i)->appear();
}

void LiveActorGroup::killAll() {
    for (s32 i = 0; i < mNumActors; i++)
        if (isAlive(getActor(i)))
            getActor(i)->kill();
}

void LiveActorGroup::makeActorAppearedAll() {
    for (s32 i = 0; i < mNumActors; i++)
        mActors[i]->makeActorAppeared();
}

void LiveActorGroup::makeActorDeadAll() {
    for (s32 i = 0; i < mNumActors; i++)
        mActors[i]->makeActorDead();
}
}  // namespace al
