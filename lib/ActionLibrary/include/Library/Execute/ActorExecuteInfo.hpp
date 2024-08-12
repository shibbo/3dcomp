#pragma once

#include <types.hpp>

namespace al {
    class ExecuteRequestKeeper;
    class ExecutorActorExecuteBase;
    class ModelDrawerBase;

    class ActorExecuteInfo {
    public:
        ActorExecuteInfo(ExecuteRequestKeeper*);

        ExecuteRequestKeeper* mReqKeeper;  // 0x00
        s32 mNumExecuteBases;              // 0x08
        u32 _C;
        ExecutorActorExecuteBase** mExecutors;  // 0x10
        void* _18;
        void* _20;
        void* _28;
        s32 mNumDrawerBases;  // 0x30
        u32 _34;
        ModelDrawerBase** mModelDrawers;  // 0x38
    };
};  // namespace al