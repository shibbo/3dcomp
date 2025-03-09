#pragma once

#include <container/seadPtrArray.h>

namespace al {
class LiveActor;
class ShadowMaskBase;

class ShadowKeeper {
public:
    class ShadowMaskBaseInfo {
    public:
    };

    ShadowKeeper(bool);
    ~ShadowKeeper();

    void initShadowMaskNum(s32 maskNum);
    void show();
    void initAfterPlacement();
    void hide();

    sead::PtrArray<ShadowMaskBase*> mMaskArray;
    void* _10;
    void* _18;
    void* _20;
    void* _28;
    void* _30;
    void* _38;
    LiveActor* mHostActor;
    bool mIsIgnoreShadowMaskYaml;
};
}  // namespace al
