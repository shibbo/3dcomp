#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

class alModelCafe;

namespace al {
class GpuMemAllocator;

class ModelKeeper {
public:
    ModelKeeper() = default;
    ~ModelKeeper();

    void setGlobalAlpha(f32*);
    void setGlobalYOffset(f32*);
    void initResource(const char*, const char*, const char*);
    void setModel(const char*, alModelCafe*);
    void initModel(s32, GpuMemAllocator*);
    void show();
    void hide();
    void update();
    void updatePaused();
    void calc(const sead::Matrix34f&, const sead::Vector3f&);
    void setLodParams(const f32*, s32, const sead::Vector3f*, bool);
    void updateLod(const sead::Vector3f&, bool);
    s32 getLodNum() const;
    void setDisableDraw(bool);
    void setDisableDepthShadow(bool);
    sead::Matrix34f& getWorldMtxPtrByIndex(s32) const;
    void initLightCtrl(s32);

    alModelCafe* mModelCafe = nullptr;
    const char* mModelName = nullptr;
    void* _10 = nullptr;
    bool _18 = false;
    bool _19 = false;
    bool _1a = false;
    bool _1b = false;
    bool _1c = false;
};
}  // namespace al
