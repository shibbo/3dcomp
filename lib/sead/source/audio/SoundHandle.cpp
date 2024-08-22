#include "audio/SoundHandle.hpp"

namespace sead {
    void SoundHandle::stop(s32 frames) {
        if (isAttachedSound()) {
            mSound->Stop(frames);
        }
    }

    void SoundHandle::pause(s32 frame) {
        if (isAttachedSound()) {
            mSound->Pause(true, frame);
        }
    }

    void SoundHandle::unpause(s32 frame) {
        if (isAttachedSound()) {
            mSound->Pause(false, frame);
        }
    }

    void SoundHandle::setVolume(f32 volume, s32 frames) {
        if (isAttachedSound()) {
            mSound->SetVolume(volume, frames);
        }
    }

    void SoundHandle::setPitch(f32 pitch) {
        if (isAttachedSound()) {
            mSound->SetPitch(pitch);
        }
    }

    void SoundHandle::setPan(f32 pan) {
        if (isAttachedSound()) {
            mSound->SetPan(pan);
        }
    }

    bool SoundHandle::isAttachedSound() const {
        return mSound != nullptr;
    }

    u32 SoundHandle::getSoundId() const {
        if (isAttachedSound()) {
            return mSound->mId;
        }

        return 0xFFFFFFFF;
    }
};