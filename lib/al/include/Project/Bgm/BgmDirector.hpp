#pragma once

#include <Project/Bgm/BgmRhythmCtrl.hpp>
#include <basis/seadTypes.h>

namespace al {
    class BgmLineKeeper;
    class BgmRhythmCtrl;
    class SeadAudioPlayer;

    class BgmDirector : public IUseActiveBgmLine {
    public:
        u64* _0;
        u64* _8;
        SeadAudioPlayer* mAudioPlayer;  // 0x10
        BgmLineKeeper* mLineKeeper;     // 0x18
        BgmRhythmCtrl* mRhythmCtrl;     // 0x20
        f32 _28;
        u32 _2C;
        u32 _30;
        u32 _34;
        bool _38;
        u8 _39;
        bool _3A;
    };
};  // namespace al