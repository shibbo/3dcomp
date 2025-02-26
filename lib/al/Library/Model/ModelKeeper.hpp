#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>
#include <seadTypes.h>

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
        void initModel(int, GpuMemAllocator*);
        void show();
        void hide();
        void update();
        void updatePaused();
        void calc(const sead::Matrix34f&, const sead::Vector3f&);
        void setLodParams(const f32*, int, const sead::Vector3f*, bool);
        void updateLod(const sead::Vector3f&, bool);
        s32 getLodNum() const;
        void setDisableDraw(bool);
        void setDisableDepthShadow(bool);
        sead::Matrix34f& getWorldMtxPtrByIndex(int) const;
        void initLightCtrl(int);

        alModelCafe* mModelCafe = nullptr;  // 0x00
        const char* mModelName = nullptr;   // 0x08
        void* _10 = nullptr;
        bool _18 = false;
        bool _19 = false;
        bool _1A = false;
        bool _1B = false;
        bool _1C = false;
    };
};  // namespace al