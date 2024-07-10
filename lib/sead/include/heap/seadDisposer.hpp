#pragma once

namespace sead {
    class Heap;

    class IDisposer {
    public:
        enum HeapNullOption {

        };

        IDisposer();
        IDisposer(Heap *, HeapNullOption);

        virtual ~IDisposer();

        Heap* mContainerHeap;           // 0x8
    };
};