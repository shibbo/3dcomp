#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.hpp>

namespace al {
class Resource {
public:
    void* getOtherFile(const sead::SafeString&, u32*) const;
};
}  // namespace al
