#pragma once

#include "Library/LiveActor/LiveActor.hpp"

namespace al {
    class ChildStep : public LiveActor {
    public:
        ChildStep(const char*, LiveActor*);

        void exeWait();
    };
};  // namespace al