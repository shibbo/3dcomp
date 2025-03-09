#pragma once

#include <basis/seadTypes.h>

namespace al {
class GpuMemAllocator;
class SimpleModelG3D;
class AnimPlayerSkl;
class AnimPlayerMat;
class AnimPlayerVis;
}  // namespace al

class alModelCafe {
public:
    ~alModelCafe();

    void show();
    bool isHidden() const;
    void hide();
    void update();

    void updateLast();

    void* _0;
    void* _10;
    al::SimpleModelG3D* mModelG3D;
    void* _20;
    void* _28;
    void* _30;
    void* _38;
    al::AnimPlayerSkl* _40;
    al::AnimPlayerMat* _48;
    al::AnimPlayerMat* _50;
    al::AnimPlayerMat* _58;
    al::AnimPlayerVis* _60;
    void* _68;
    void* _70;
    void* _78;
    void* _80;
    void* _88;
    void* _90;
    void* _98;
};
