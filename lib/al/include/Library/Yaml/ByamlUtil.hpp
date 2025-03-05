#pragma once

#include <basis/seadTypes.h>

namespace al {
    class ByamlIter;

    bool tryGetByamlU8(u8 *, const ByamlIter &, const char *);

    bool tryGetByamlS32(s32 *, const ByamlIter &, const char *);

    bool tryGetByamlV3f(sead::Vector3f *, const ByamlIter &, const char *);
};