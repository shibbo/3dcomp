#pragma once

namespace al {
class FunctorBase;
class IUseStageSwitch;
class StageSwitchDirector;
struct PlacementInfo;

void initStageSwitch(IUseStageSwitch*, StageSwitchDirector*, const PlacementInfo&);

bool listenStageSwitchOnOffAppear(IUseStageSwitch*, const FunctorBase&, const FunctorBase&);
bool listenStageSwitchOnKill(IUseStageSwitch*, const FunctorBase&);
bool listenStageSwitchOnOff(IUseStageSwitch*, const char*, const FunctorBase&, const FunctorBase&);
}  // namespace al
