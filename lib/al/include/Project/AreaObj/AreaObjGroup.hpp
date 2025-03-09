#pragma once

#include <basis/seadTypes.h>

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

    const char* mGroupName;
    AreaObj** mAreaObjs;
    s32 mNumAreas;
    s32 mMaxAreas;
};
}  // namespace al
