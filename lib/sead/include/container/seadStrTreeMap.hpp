#pragma once

#include "container/seadFreeList.hpp"
#include "container/seadTreeMap.hpp"
#include "prim/seadSafeString.hpp"

namespace sead {
    template <size_t KeyLength, typename V>
    class StrTreeMap : public TreeMapImpl<SafeString> {
    public:
        FreeList mFreeList;
        s32 mSize = 0;
        s32 mMaxSize = 0;
    };
};  // namespace sead