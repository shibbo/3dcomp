#include "heap/seadDisposer.hpp"
#include "heap/seadHeap.hpp"
#include <types.hpp>

namespace {
    const u32 cDestructedFlag = 1;
};

namespace sead {
    IDisposer::~IDisposer() {
        if (reinterpret_cast<uintptr_t>(mContainerHeap) != cDestructedFlag) {
            if (mContainerHeap != nullptr) {
                mContainerHeap->removeDisposer_(this);
            }

            *reinterpret_cast<uintptr_t*>(&mContainerHeap) = cDestructedFlag;
        }
    }
}; 