#pragma once

namespace sead {
    class Heap;

    class HeapMgr {
    public:
        Heap* findContainHeap(const void *);
        Heap* getCurrentHeap() const;

        static HeapMgr* sInstancePtr;
    };
};