#pragma once

#include <basis/seadTypes.h>

namespace al {
class PlacementId;
class StageSwitchDirector;
class StageSwitchListener;

class StageSwitchAccesser {
public:
    StageSwitchAccesser();

    bool init(StageSwitchDirector*, const char*, const PlacementId&, bool);
    bool isValid() const;
    void onSwitch();
    void offSwitch();
    bool isOnSwitch() const;
    StageSwitchDirector* getStageSwitchDirector() const;
    bool isEnableRead() const;
    bool isEnableWrite() const;
    bool isEqualSwitch(const StageSwitchAccesser*) const;
    void doInstanceResponse();
    void addListener(StageSwitchListener*);

    inline void setThing(void* ptr) { _8 = ptr; }

    StageSwitchDirector* mStageSwitchDirector = nullptr;
    void* _8 = nullptr;
    const char* mName = "";
    PlacementId* mPlacementId = nullptr;
    s32 mSwitchNo = -1;
    u32 _24 = 0;
    bool mIsDisasterMode;
};

class StageSwitchAccesserList {
public:
    StageSwitchAccesserList();
    StageSwitchAccesserList(const StageSwitchAccesser*);

    const StageSwitchAccesser* mAccesser = nullptr;
    u64 _8 = 0;
};
}  // namespace al
