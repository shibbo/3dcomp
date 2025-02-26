#pragma once

#include <prim/seadSafeString.hpp>
#include <seadTypes.h>

namespace al {
    class Resource {
    public:
        void* getOtherFile(const sead::SafeString&, u32*) const;
    };
};  // namespace al