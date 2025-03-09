#pragma once

#include <basis/seadTypes.h>

namespace al {
class ExecuteRequestKeeper;
class ExecutorActorExecuteBase;
class ModelDrawerBase;

class ActorExecuteInfo {
public:
    ActorExecuteInfo(ExecuteRequestKeeper*);

    ExecuteRequestKeeper* mReqKeeper;
    s32 mNumExecuteBases;
    u32 _c;
    ExecutorActorExecuteBase** mExecutors;
    void* _18;
    void* _20;
    void* _28;
    s32 mNumDrawerBases;
    u32 _34;
    ModelDrawerBase** mModelDrawers;
};
}  // namespace al
