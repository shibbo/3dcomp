#pragma once

#include "os/os_TickTypes.hpp"
#include "types.hpp"

namespace nn {
    namespace atk {
        class SoundHandle;
        class SoundActor;
        class SoundArchive;
        class SoundPlayer;

        namespace detail {
            class PlayerHeap;
            class ExternalSoundPlayer;

            class BasicSound {
            public:
                virtual ~BasicSound();
                virtual void Initialize();
                virtual void Finalize();
                virtual bool IsPrepared() const = 0;
                virtual bool IsAttachedTempSpecialHandle() = 0;
                virtual void DetachTempSpecialHandle() = 0;
                virtual void OnUpdatePlayerPriority();
                virtual void UpdateMoveValue();
                virtual void OnUpdateParam();

                void Stop(s32);
                void Pause(bool, s32);
                void SetVolume(f32, s32);
                void SetPitch(f32);
                void SetPan(f32);

                void StartPrepared();

                bool IsPause() const;
                bool IsMute() const;

                PlayerHeap* mPlayerHeap;               // 0x08
                SoundHandle* mGeneralHandle;           // 0x10
                SoundHandle* mTempGeneralHandle;       // 0x18
                SoundPlayer* mSoundPlayer;             // 0x20
                SoundActor* mSoundActor;               // 0x28
                ExternalSoundPlayer* mExtSoundPlayer;  // 0x30
                const SoundArchive* mSoundArchive;     // 0x38
                u8 _40[0x104 - 0x40];
                s32 mAutoStopCounter;     // 0x104
                u32 mUpdateCounter;       // 0x108
                u32 mPlayingCounter;      // 0x10C
                u32 mId;                  // 0x110
                u32 mInstanceId;          // 0x114
                nn::os::Tick mSetupTick;  // 0x118
                f32 mInitialVolume;       // 0x120
                f32 mPitch;               // 0x124
                f32 mLpfFreq;             // 0x128
                f32 mBiquadFilterValue;   // 0x12C
                u32 mOutputLine;          // 0x130
                u8 _134[0x200 - 0x134];
            };
        };  // namespace detail
    };  // namespace atk
};  // namespace nn