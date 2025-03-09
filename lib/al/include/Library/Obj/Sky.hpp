#pragma once

#include "Library/LiveActor/LiveActor.hpp"

namespace al {
class Sky : public LiveActor {
public:
    Sky(const char*);

    virtual ~Sky();
    virtual void init(const ActorInitInfo&);
    virtual void control();
};
}  // namespace al
