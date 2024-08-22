#pragma once

#include <audio/SoundHandle.hpp>
#include <container/seadPtrArray.hpp>
#include <types.hpp>

namespace al {
    class BgmResourceInfo;
    class SeadAudioPlayer;

    class Bgm {
    public:
        void startPreparedBgmExistingRequest();
        void pauseBgm(s32);
        void resumeBgm(s32);
        void stopBgm(s32);
        bool isFadeOutNow() const;
        bool isFadeInNow() const;
        f32 getCurBpm() const;

        u64 _0;
        SeadAudioPlayer* mAudioPlayer;    // 0x8
        sead::SoundHandle* mSoundHandle;  // 0x10
        BgmResourceInfo* mBgmResInfo;     // 0x18
        u8 _20;
        u8 _21;
        u8 _22;
        u8 _23;
        u32 _24;
        u32 _28;
        u32 _2C;
        u64 _30;
        u8 _38;
        s32 _3C;
        u8 _40;
        u8 _41;
        u8 _42;
        u8 _43;
        u32 _44;
        u64 _48;
        u64 _50;
        u64 _58;
        u64 _60;
        u64 _68;
    };
};  // namespace al