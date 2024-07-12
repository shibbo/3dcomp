#pragma once

#include <types.hpp>

namespace sead {
    class Heap;

    class IDisposer {
    public:
        enum HeapNullOption {
            UseSpecHeap = 0,
            UseSpecOrCont = 1,
            NoDispAppend = 2,
            UseSpecOrCur = 3
        };

        IDisposer();
        IDisposer(Heap *, HeapNullOption);

        virtual ~IDisposer();

        Heap* mContainerHeap;           // 0x8
        u64 _10;
        u64 _18;
    };
};