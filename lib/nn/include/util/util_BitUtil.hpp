#pragma once

#include "util/detail/util_TypeTraits.hpp"

namespace nn {
    namespace util {
        template <typename T>
        inline T align_up(T x, size_t align) {
            typedef typename detail::MakeUnsigned<T>::Type UIntType;
            UIntType mask = static_cast<UIntType>(align - 1);
            return static_cast<T>((x + mask) & ~mask);
        }
    };  // namespace util
};  // namespace nn