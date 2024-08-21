#pragma once

#include <container/seadPtrArray.hpp>
#include <types.hpp>
#include "Project/Audio/AudioInfoList.hpp"
#include "Project/Bgm/BgmLine.hpp"

namespace al {
    struct BgmPlayingRequest {
        const char* mName;  // 0x00
    };

    class BgmLineInfo;

    class BgmLineKeeper {
    public:
        BgmLineKeeper(f32);

        s32 checkIfIsIslandBgm(const BgmPlayingRequest&);
        s32 checkPhaseBgm(const BgmPlayingRequest&);

        void pauseActiveBgmLine(s32);
        void resumeActiveBgmLine(s32);

        BgmLine* getBgmLineByLineName(const char*) const;
        void resumeIslandBgm(s32);
        void pauseOceanBgm(s32);
        void resumeOceanBgm(s32);
        bool isPauseActiveBgmLine();
        void stopAllBgmLine(s32);
        bool tryStopAllBgmLine(f32);

        void changeSituation(const char*);
        BgmLine* getActiveBgmLine() const;

        sead::PtrArray<BgmLine>* mLines = nullptr;  // 0x00
        u64* _8 = nullptr;
        AudioInfoList<BgmLineInfo>* _10 = nullptr;
        u32 mCurrentLine = 0;  // 0x18
        u8 _1C = 0;
        u8 _1D = 0;
        u8 _1E = 0;
        u8 _1F = 0;
        u32 _20 = 0;
        u32 _24 = 0;
        u8 _28 = 0;
        u8 _29;
        u8 _2A;
        u8 _2B;
        s32 _2C;
        s32 _30;
        s32 _34;
        s32 _38;
        s32 _3C;
        s32 _40;
        s32 _44;
        s32 _48;
        s32 _4C;
        s32 _50;
        s32 _54;
        s32 _58;
        u32 _5C;
        const char* _60 = "Dummy";
        s32 _68;
        s32 _6C;
        s32 _70 = -1;
        u16 _74 = 0;
        u16 _76;
        s32 _78 = -1;
        s32 _7C = -1;
        u32 _80 = 0;
        u8 _84 = 0;
        u8 _85;
        u8 _86;
        u8 _87;
        s32 _88 = -1;
        f32 _8C;
        s32 _90 = -1;
        s32 _94 = -1;
        u8 _98 = 0;
        u8 _99 = 0;
    };
};  // namespace al