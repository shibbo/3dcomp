#pragma once

#include <types.hpp>

namespace al {
    class LiveActor;

    bool isExistSubActorKeeper(const LiveActor *);
    void setSubActorAlpha(LiveActor *);
    void setSubActorAlphaPtr(LiveActor *, f32 *);
    LiveActor* getSubActor(const LiveActor *, const char *);
    LiveActor* tryGetSubActor(const LiveActor *, const char *);
    LiveActor* getSubActor(const LiveActor *, s32);
    s32 getSubActorNum(const LiveActor *);
    void offSyncClippingSubActor(LiveActor *, const LiveActor *);
    void offSyncClippingSubActorAll(LiveActor *);
    void onSyncClippingSubActor(LiveActor *, const LiveActor *);
    void onSyncClippingSubActorAll(LiveActor *);
};