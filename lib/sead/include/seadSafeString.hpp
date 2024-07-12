#pragma once

#include <types.hpp>

namespace sead {
    template <typename T>
    class SafeStringBase {
    public:
        SafeStringBase() : mString(&cNullChar) {

        }

        SafeStringBase(const T* pStr) : mString(pStr) {

        }

        virtual ~SafeStringBase() = default;
        virtual void assureTerminationImpl_() const {

        }
        
        const T* mString;       // 0x0

        static const T cNullChar;
    };

    template <typename T>
    class BufferedSafeStringBase : public SafeStringBase<T> {
    public:
        BufferedSafeStringBase(T* pBuf, s32 size) {
            mBufferSize = size;

            if (size <= 0) {
                mString = nullptr;
                mBufferSize = 0;
            }
            else {
                this->assureTerminationImpl_();
            }
        }

        ~BufferedSafeStringBase() override = default;
        void assureTerminationImpl_() const override;

        s32 mBufferSize;            // 0x10
    };

    /* commonly used types for easy use */
    typedef SafeStringBase<char> SafeString;
    typedef BufferedSafeStringBase<char> BufferedSafeString;
}
