#pragma once

#include <types.hpp>

namespace sead {
    class Heap;
    class Random;

    class PtrArrayImpl {
    public:
        PtrArrayImpl() = default;

        PtrArrayImpl(s32 maxNumPtrs, void *pBuffer) {
            setBuffer(maxNumPtrs, pBuffer);
        }

        void setBuffer(s32, void *);
        void allocBuffer(s32, Heap *, s32);
        bool tryAllocBuffer(s32, Heap *, s32);
        void freeBuffer();
        void erase(s32, s32);
        void reverse();
        void shuffle(Random *);
        void insert(s32, void *);
        bool checkInsert(s32, s32);
        void insertArray(s32, void *, s32, s32);

        inline s32 getNum() const {
            return mNumPtrs;
        }

        inline void* getAt(s32 idx) const {
            return mPtrArray[idx];
        }

        s32 mNumPtrs = 0;                   // 0x00
        s32 mMaxNumPtrs = 0;                // 0x04
        void** mPtrArray = nullptr;         // 0x08  
    };

    template<typename T>
    class PtrArray : public PtrArrayImpl {
    public:
        PtrArray() = default;
        
        PtrArray(s32 maxNumptrs, T** pBuffer) : PtrArrayImpl(maxNumptrs, pBuffer) { 

        }

        T* operator[](s32 idx) const {
            return getAt(idx);
        }
    };
};