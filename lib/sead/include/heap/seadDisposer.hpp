#pragma once

#include <types.hpp>
#include "basis/seadNew.hpp"

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
        IDisposer(Heap*, HeapNullOption = UseSpecOrCur);

        virtual ~IDisposer();

        Heap* mContainerHeap;  // 0x8
        u64 _10;
        u64 _18;
    };
};  // namespace sead

#define SEAD_INSTANCE(CLASS) (CLASS::instance())

#define SEAD_SINGLETON_DISPOSER(CLASS)                                                             \
public:                                                                                            \
    class SingletonDisposer_ : public sead::IDisposer {                                            \
    public:                                                                                        \
        using sead::IDisposer::IDisposer;                                                          \
        virtual ~SingletonDisposer_();                                                             \
                                                                                                   \
        static SingletonDisposer_* sDisposer;                                                      \
    };                                                                                             \
                                                                                                   \
    static CLASS* instance() {                                                                     \
        return sInstance;                                                                          \
    }                                                                                              \
                                                                                                   \
    static CLASS* createInstance(sead::Heap*);                                                     \
    static void deleteInstance();                                                                  \
                                                                                                   \
    CLASS(const CLASS&&) = delete;                                                                 \
    CLASS& operator=(const CLASS&) = delete;                                                       \
    CLASS(CLASS&&) = delete;                                                                       \
    CLASS& operator=(CLASS&&) = delete;                                                            \
                                                                                                   \
    static CLASS* sInstance;                                                                       \
                                                                                                   \
    u32 mBuf[sizeof(SingletonDisposer_) / 4];

#define SEAD_CREATE_SINGLETON_INSTANCE(CLASS)                                                      \
    CLASS* CLASS::createInstance(sead::Heap* pHeap) {                                              \
        if (sInstance == nullptr) {                                                                \
            auto* buf = new (pHeap, alignof(CLASS)) u8[sizeof(CLASS)];                             \
            auto* dispBuf = buf + offsetof(CLASS, mBuf);                                           \
            SingletonDisposer_::sDisposer = new (dispBuf) SingletonDisposer_(pHeap);               \
            sInstance = new (buf) CLASS;                                                           \
        }                                                                                          \
        return CLASS::sInstance;                                                                   \
    }

#define SEAD_DELETE_SINGLETON_INSTANCE(CLASS)                                                      \
    void CLASS::deleteInstance() {                                                                 \
        SingletonDisposer_* disposer = SingletonDisposer_::sDisposer;                              \
        if (SingletonDisposer_::sDisposer != nullptr) {                                            \
            SingletonDisposer_::sDisposer = nullptr;                                               \
            disposer->~SingletonDisposer_();                                                       \
            delete sInstance;                                                                      \
            sInstance = nullptr;                                                                   \
        }                                                                                          \
    }

#define SEAD_SINGLETON_DISPOSER_IMPL(CLASS)                                                        \
    CLASS::SingletonDisposer_::~SingletonDisposer_() {                                             \
        if (this == sDisposer) {                                                                   \
            sDisposer = nullptr;                                                                   \
            CLASS::sInstance->~CLASS();                                                            \
            CLASS::sInstance = nullptr;                                                            \
        }                                                                                          \
    }                                                                                              \
    SEAD_CREATE_SINGLETON_INSTANCE(CLASS)                                                          \
    SEAD_DELETE_SINGLETON_INSTANCE(CLASS)                                                          \
    CLASS* CLASS::sInstance = nullptr;                                                             \
    CLASS::SingletonDisposer_* CLASS::SingletonDisposer_::sDisposer = nullptr;