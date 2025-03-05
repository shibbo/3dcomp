#pragma once

#include <prim/seadSafeString.hpp>
#include <basis/seadTypes.h>

namespace al {
    class Resource {
    public:
        void* getOtherFile(const sead::SafeString&, u32*) const;
    };
};  // namespace al