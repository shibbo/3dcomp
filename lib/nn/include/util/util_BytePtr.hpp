#pragma once

#include <stddef.h>
#include "util/util_BitUtil.hpp"

namespace nn {
    namespace util {
        class BytePtr {
        public:
            BytePtr(void* pPtr) : mPtr(pPtr) {}

            void* Get() const { return mPtr; }

            template <typename T>
            T* Get() const {
                return static_cast<T*>(mPtr);
            }

            BytePtr& Advance(ptrdiff_t offs) {
                mPtr = Get<char>() + offs;
                return *this;
            }

            BytePtr& AlignUp(size_t align) {
                uintptr_t& ptr = reinterpret_cast<uintptr_t&>(mPtr);
                ptr = align_up(ptr, align);
                return *this;
            }

        private:
            void* mPtr;
        };
    };  // namespace util
};  // namespace nn