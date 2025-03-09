#pragma once

#include <container/seadPtrArray.h>
#include <gfx/seadColor.h>

namespace al {
class PrePassLightBase;
class ByamlIter;
class LiveActor;

class ActorPrePassLightKeeper {
public:
    class UserColor {
    public:
        void setPtr();
        void readIter(const ByamlIter&);

        const char* mName;
        sead::Color4f* mColor;
    };

    ActorPrePassLightKeeper();
    ~ActorPrePassLightKeeper();

    void initAfterPlacement();
    void appear(bool);
    void requestKill();
    void hideModel();
    void updateHideModel(bool);

    sead::PtrArray<PrePassLightBase*> mLightBaseArray;
    sead::PtrArray<UserColor*> mColorArray;
    LiveActor* mParentActor;
    bool mIsIgnorePrePassYaml;
    bool mIsIgnoreHideModel;
};
}  // namespace al
