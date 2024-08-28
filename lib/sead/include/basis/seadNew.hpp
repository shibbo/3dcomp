#pragma once

#include <cstddef>
#include <new>
#include <types.hpp>

namespace sead {
    class Heap;
};

void* operator new(size_t size);
void* operator new[](size_t size);
void* operator new(size_t size, const std::nothrow_t&) noexcept;
void* operator new[](size_t size, const std::nothrow_t&) noexcept;

void* operator new(size_t size, s32 alignment);
void* operator new[](size_t size, s32 alignment);
void* operator new(size_t size, s32 alignment, const std::nothrow_t&) noexcept;
void* operator new[](size_t size, s32 alignment, const std::nothrow_t&) noexcept;

void* operator new(size_t size, sead::Heap* heap, const std::nothrow_t&) noexcept;
void* operator new[](size_t size, sead::Heap* heap, const std::nothrow_t&) noexcept;

void* operator new(size_t size, sead::Heap* heap, s32 alignment = sizeof(void*));
void* operator new[](size_t size, sead::Heap* heap, s32 alignment = sizeof(void*));
void* operator new(size_t size, sead::Heap* heap, s32 alignment, const std::nothrow_t&) noexcept;
void* operator new[](size_t size, sead::Heap* heap, s32 alignment, const std::nothrow_t&) noexcept;