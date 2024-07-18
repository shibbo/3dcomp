#pragma once

#include <container/seadPtrArray.hpp>
#include <gfx/seadColor.hpp>

namespace al {
    class PrePassLightBase;
    class ByamlIter;
    class LiveActor;

    class ActorPrePassLightKeeper {
    public:
        class UserColor {
        public:
            void setPtr();
            void readIter(const ByamlIter &);

            const char* mName;          // 0x00
            sead::Color4f* mColor;      // 0x04
        };

        ActorPrePassLightKeeper();
        ~ActorPrePassLightKeeper();

        void initAfterPlacement();
        void appear(bool);
        void requestKill();
        void hideModel();
        void updateHideModel(bool);

        sead::PtrArray<PrePassLightBase*> mLightBaseArray;      // 0x00
        sead::PtrArray<UserColor*> mColorArray;                 // 0x10
        LiveActor* mParentActor;                                // 0x20
        bool mIsIgnorePrePassYaml;                              // 0x28
        bool mIsIgnoreHideModel;                                // 0x29
    };
};