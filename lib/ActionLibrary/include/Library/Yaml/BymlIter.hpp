#pragma once

#include <types.hpp>

namespace al {
    class ByamlData;

    class ByamlIter {
    public:
        bool getByamlDataByIndex(ByamlData *, s32);
    };
};