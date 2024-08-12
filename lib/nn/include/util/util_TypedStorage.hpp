#pragma once

#include <type_traits>

namespace nn {
    namespace util {
        template <typename T, size_t Size, size_t Alignment>
        struct TypedStorage {
            typename std::aligned_storage<Size, Alignment>::type storage;
        };
    };  // namespace util
};  // namespace nn