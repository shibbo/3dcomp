#pragma once

#include <basis/seadTypes.h>
#include <container/seadPtrArray.h>

#include "Project/Audio/AudioInfoList.hpp"

namespace al {
class BgmLine;
class BgmLineInfo;
struct BgmPlayingRequest;

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

    sead::PtrArray<BgmLine>* mLines = nullptr;

    AudioInfoList<BgmLineInfo>* _10 = nullptr;
    u32 mCurrentLine = 0;

    u8 _1d = 0;
    u8 _1e = 0;
    u8 _1f = 0;
    u32 _20 = 0;
    u32 _24 = 0;
    u8 _28 = 0;
    u8 _29;
    u8 _2a;
    u8 _2b;
    s32 _2c;
    s32 _30;
    s32 _34;
    s32 _38;
    s32 _3c;
    s32 _40;
    s32 _44;
    s32 _48;
    s32 _4c;
    s32 _50;
    s32 _54;
    s32 _58;
    u32 _5c;
    const char* _60 = "Dummy";
    s32 _68;
    s32 _6c;
    s32 _70 = -1;
    u16 _74 = 0;
    u16 _76;
    s32 _78 = -1;
    s32 _7c = -1;
    u32 _80 = 0;
    u8 _84 = 0;
    u8 _85;
    u8 _86;
    u8 _87;
    s32 _88 = -1;
    f32 _8c;
    s32 _90 = -1;
    s32 _94 = -1;
    u8 _98 = 0;
    u8 _99 = 0;
};
}  // namespace al
