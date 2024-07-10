#pragma once

namespace sead {
    class Heap;

    class HeapMgr {
    public:
        Heap* findContainHeap(const void *);

        static HeapMgr* sInstancePtr;
    };
};