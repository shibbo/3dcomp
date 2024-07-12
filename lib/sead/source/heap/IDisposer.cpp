#include "heap/seadDisposer.hpp"
#include "heap/seadHeap.hpp"
#include "heap/seadHeapMgr.hpp"
#include <types.hpp>

namespace sead {
    IDisposer::IDisposer() {
        _10 = 0;
        _18 = 0;
        mContainerHeap = nullptr;

        if (HeapMgr::sInstancePtr != nullptr) {
            Heap* container = HeapMgr::sInstancePtr->findContainHeap(this);
            mContainerHeap = container;

            if (container != nullptr) {
                container->appendDisposer_(this);
            }
        }
    }

    IDisposer::IDisposer(Heap *pHeap, HeapNullOption nullOpt) {
        _10 = 0;
        _18 = 0;
        mContainerHeap = pHeap;

        if (mContainerHeap != nullptr) {
            mContainerHeap->appendDisposer_(this);
            return;
        }

        switch (nullOpt) {
            case UseSpecHeap:
            case UseSpecOrCont:
                if (HeapMgr::sInstancePtr == nullptr) {
                    return;
                }

                mContainerHeap = HeapMgr::sInstancePtr->findContainHeap(this);

                if (mContainerHeap != nullptr) {
                    mContainerHeap->appendDisposer_(this);
                }
                return;
            case NoDispAppend:
                return;
            case UseSpecOrCur:
                if (HeapMgr::sInstancePtr == nullptr) {
                    return;
                }

                mContainerHeap = HeapMgr::sInstancePtr->getCurrentHeap();

                if (mContainerHeap != nullptr) {
                    mContainerHeap->appendDisposer_(this);
                }
                return;
            default:
                return;
        }
    }

    IDisposer::~IDisposer() {
        if (reinterpret_cast<uintptr_t>(mContainerHeap) != 1) {
            if (mContainerHeap != nullptr) {
                mContainerHeap->removeDisposer_(this);
            }

            *reinterpret_cast<uintptr_t*>(&mContainerHeap) = 1;
        }
    }
}; 