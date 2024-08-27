#pragma once

#include <prim/seadSafeString.hpp>

namespace al {
    class Resource;

    Resource* findOrCreateResource(const sead::SafeString&, const char*);
};  // namespace al