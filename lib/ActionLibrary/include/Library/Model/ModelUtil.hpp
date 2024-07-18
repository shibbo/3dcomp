#pragma once

namespace al {
    class LiveActor;

    void tryInitFixedModelGpuBuffer(LiveActor *);

    bool isHideModel(const LiveActor *);

    void setNeedSetBaseMtxAndCalcAnimFlag(LiveActor *, bool);
};