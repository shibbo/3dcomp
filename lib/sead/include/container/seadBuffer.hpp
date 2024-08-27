#pragma once

#include <types.hpp>

namespace sead {
    class Heap;

    template <typename T>
    class Buffer {
    public:
        Buffer() : mSize(0), mBuffer(nullptr) {}

        Buffer(s32 size, T* pBuffer) : mSize(size), mBuffer(pBuffer) {}

        s32 mSize;   // 0x00
        T* mBuffer;  // 0x08
    };
};  // namespace sead