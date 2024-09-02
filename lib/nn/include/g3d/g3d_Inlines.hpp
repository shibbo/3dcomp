#pragma once

#include <cstring>
#include <stddef.h>

namespace nn {
    namespace g3d {
        void* AddOffset(void* pPtr, ptrdiff_t offs) {
            return static_cast<char*>(pPtr) + offs;
        }

        const void* AddOffset(const void* pPtr, ptrdiff_t offs) {
            return static_cast<const char*>(pPtr) + offs;
        }

        template <bool>
        void Copy32(void* pDest, const void* pSrc, int cnt) {
            memcpy(pDest, pSrc, 4 * cnt);
        }
    };  // namespace g3d
};  // namespace nn