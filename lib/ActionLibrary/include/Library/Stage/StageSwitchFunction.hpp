#pragma once

#include "Library/Placement/PlacementInfo.hpp"
#include "Library/Thread/Functor.hpp"

namespace al {
    class IUseStageSwitch;
    class StageSwitchDirector;

    void initStageSwitch(IUseStageSwitch*, StageSwitchDirector*, const PlacementInfo&);

    bool listenStageSwitchOnOffAppear(IUseStageSwitch*, const FunctorBase&, const FunctorBase&);
    bool listenStageSwitchOnKill(IUseStageSwitch*, const FunctorBase&);
    bool listenStageSwitchOnOff(IUseStageSwitch*, const char*, const FunctorBase&,
                                const FunctorBase&);
};  // namespace al