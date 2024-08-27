#pragma once

#include <prim/seadSafeString.hpp>
#include <types.hpp>

namespace al {
    class Resource {
    public:
        void* getOtherFile(const sead::SafeString&, u32*) const;
    };
};  // namespace al