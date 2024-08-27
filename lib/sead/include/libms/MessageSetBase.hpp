#pragma once

#include "libms/libms.h"
#include "prim/seadSafeString.hpp"

namespace sead {
    class Heap;

    class MessageSetBase {
    public:
        virtual ~MessageSetBase();

        void initialize(void*, Heap*);
        void* allocForLibm_(u32);
        void freeForLibms_(void*);
        void finalize();
        const char* getInitializeData() const;
        u32 calcTextSizeByIndex(s32) const;
        bool searchTextLabelByIndex(BufferedSafeString*, s32) const;

        LMSMsgFile* mMsgFile = nullptr;  // 0x08
        s32 mTextNum = 0;                // 0x10

        static Heap* sHeap;
    };

    template <typename T>
    class MessageSet : public MessageSetBase {
    public:
        inline MessageSet() {}

        virtual ~MessageSet() {}
    };
};  // namespace sead