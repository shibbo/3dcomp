#pragma once

#include <stdint.h>

namespace nn {
    namespace gfx {
        namespace detail {
            template <typename TType, typename TValue = uint64_t>
            union Ptr {
                typedef TType Type;
                typedef TValue ValueType;
                typedef TType* PtrType;
                typedef Ptr<Type, ValueType> SelfType;

                PtrType ptr;
                ValueType value;

                operator PtrType() const { return ptr; }

                template <typename T>
                operator T() const {
                    return static_cast<T>(ptr);
                }

                SelfType& operator=(PtrType p) {
                    ptr = p;
                    return *this;
                }
            };
        };  // namespace detail
    };  // namespace gfx
};  // namespace nn