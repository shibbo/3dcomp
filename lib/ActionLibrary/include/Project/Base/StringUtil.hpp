#pragma once

#include <prim/seadSafeString.hpp>
#include <types.hpp>

namespace al {
    bool isInStack(const void*);
    bool isEqualString(const char*, const char*);
    bool isEqualString(const sead::SafeString&, const sead::SafeString&);
    bool isEqualStringCase(const char*, const char*);
    bool isEqualStringCase(const sead::SafeString&, const sead::SafeString&);
};  // namespace al