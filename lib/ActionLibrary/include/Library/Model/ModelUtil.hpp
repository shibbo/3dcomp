#pragma once

#include <math/seadMatrix.hpp>

namespace al {
    class LiveActor;

    void setMaterialCode(LiveActor *, const char *);

    void tryInitFixedModelGpuBuffer(LiveActor *);

    bool isHideModel(const LiveActor *);

    void showModelIfHide(LiveActor *);
    void hideModelIfShow(LiveActor *);

    void setNeedSetBaseMtxAndCalcAnimFlag(LiveActor *, bool);

    sead::Matrix34f* getJointMtxPtr(const LiveActor *, const char *);
};