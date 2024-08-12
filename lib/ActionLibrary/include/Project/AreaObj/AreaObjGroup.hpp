#pragma once

#include <types.hpp>
#include "Library/Actor/ActorInitInfo.hpp"
#include "Project/AreaObj/AreaObj.hpp"

namespace al {
    class AreaObjGroup {
    public:
        AreaObjGroup(const char*);
        AreaObjGroup(const char*, const char*, const ActorInitInfo&);
        ~AreaObjGroup();

        void createBuffer(s32);
        void resisterAreaObj(AreaObj*);
        void incrementCount();
        void createBuffer();
        AreaObj* getAreaObj(s32) const;
        AreaObj* getInVolumeAreaObj(const sead::Vector3f&);
        s32 getInVolumeAreaObj(const sead::Vector3f&, AreaObj**);
        AreaObj* getInVolumeAreaObj(const sead::Vector3f&, const sead::Vector3f&, sead::Vector3f*,
                                    sead::Vector3f*);
        AreaObj* getInFirstAreaObj(const sead::Vector3f&);

        const char* mGroupName;  // 0x00
        AreaObj** mAreaObjs;     // 0x08
        s32 mNumAreas;           // 0x10
        s32 mMaxAreas;           // 0x14
    };
};  // namespace al