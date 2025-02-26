#pragma once

#include <seadTypes.h>

namespace al {
    class LiveActor;

    void startAction(LiveActor*, const char*);
    void startActionAtRandomFrame(LiveActor*, const char*);
    bool tryStartAction(LiveActor*, const char*);
    bool tryStartActionIfNotPlaying(LiveActor*, const char*);
    bool isActionPlaying(const LiveActor*, const char*);

    bool isActionEnd(const LiveActor*);
    bool isExistAction(const LiveActor*);
    bool isExistAction(const LiveActor*, const char*);

    f32 getActionFrame(const LiveActor*);
    f32 getActionFrameMax(const LiveActor*, const char*);

    void setActionFrame(LiveActor*, f32);

    void startNerveAction(LiveActor*, const char*);
};  // namespace al