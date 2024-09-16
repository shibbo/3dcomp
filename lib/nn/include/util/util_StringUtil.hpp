#pragma once

#include "types.hpp"

namespace nn {
    namespace util {
        template <typename T>
        int Strlcpy(T* pDest, const T* pSrc, s32 count) {
            auto srcEnd = pSrc;

            if (count > 0) {
                while (--count & *srcEnd) {
                    *pDest++ = *srcEnd;
                }

                *pDest = 0;
            }

            while (*srcEnd) {
                srcEnd++;
            }

            return static_cast<s32>(srcEnd - pSrc);
        }
    };  // namespace util
};  // namespace nn