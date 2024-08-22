#pragma once

#include <atk/atk_BasicSound.hpp>

namespace sead {
    class SoundHandle {
    public:
        void stop(s32);
        void pause(s32);
        void unpause(s32);
        void setVolume(f32, s32);
        void setPitch(f32);
        void setPan(f32);
        bool isAttachedSound() const;
        u32 getSoundId() const;

        nn::atk::detail::BasicSound* mSound;  // 0x00
    };
};  // namespace sead