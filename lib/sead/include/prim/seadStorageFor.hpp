#pragma once

#include <new>
#include <types.hpp>
#include <utility>

namespace sead {
    template <typename T, bool Destruct = false>
    class StorageFor {
    public:
        constexpr StorageFor() = default;

        T* constructDefault() { return new (storage()) T; }

        void destruct() { data()->~T(); }

        T* data() { return reinterpret_cast<T*>(mStorage); }

        const T* data() const { return reinterpret_cast<const T*>(mStorage); }

        void* storage() { return mStorage; }

        const void* storage() const { return mStorage; }

        alignas(T) u8 mStorage[sizeof(T)];
    };
};  // namespace sead