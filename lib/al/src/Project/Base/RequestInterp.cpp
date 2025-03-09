#include "Project/Base/RequestInterp.hpp"

s32 RequestInterpMathImpl::max(s32 a1, s32 a2) {
    if (a1 <= a2)
        return a2;

    return a1;
}
