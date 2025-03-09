#pragma once

#include <basis/seadTypes.h>

#include "Project/Bgm/Common/IUseActiveBgmLine.hpp"

namespace al {
class BgmLineKeeper;
class BgmRhythmCtrl;
class SeadAudioPlayer;

class BgmDirector : public IUseActiveBgmLine {
public:
    u64* _0;
    u64* _8;
    SeadAudioPlayer* mAudioPlayer;
    BgmLineKeeper* mLineKeeper;
    BgmRhythmCtrl* mRhythmCtrl;
    f32 _28;
    u32 _2c;
    u32 _30;
    u32 _34;
    bool _38;
    u8 _39;
    bool _3a;
};
}  // namespace al
