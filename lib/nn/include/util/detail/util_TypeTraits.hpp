#pragma once

#include <cstdint>

namespace nn {
    namespace util {
        namespace detail {
            template <int N>
            struct SizedInt;

            template <>
            struct SizedInt<1> {
                typedef uint8_t Unsigned;
                typedef int8_t Signed;
            };

            template <>
            struct SizedInt<2> {
                typedef uint16_t Unsigned;
                typedef int16_t Signed;
            };

            template <>
            struct SizedInt<4> {
                typedef uint32_t Unsigned;
                typedef int32_t Signed;
            };

            template <>
            struct SizedInt<8> {
                typedef uint64_t Unsigned;
                typedef int64_t Signed;
            };

            template <typename T>
            struct ChangeSign {
                typedef typename SizedInt<sizeof(T)>::Signed Signed;
                typedef typename SizedInt<sizeof(T)>::Unsigned Unsigned;
            };

            template <typename T>
            struct ChangeSign<const T> {
                typedef const typename SizedInt<sizeof(T)>::Signed Signed;
                typedef const typename SizedInt<sizeof(T)>::Unsigned Unsigned;
            };

            template <typename T>
            struct ChangeSign<volatile T> {
                typedef volatile typename SizedInt<sizeof(T)>::Signed Signed;
                typedef volatile typename SizedInt<sizeof(T)>::Unsigned Unsigned;
            };

            template <typename T>
            struct ChangeSign<const volatile T> {
                typedef const volatile typename SizedInt<sizeof(T)>::Signed Signed;
                typedef const volatile typename SizedInt<sizeof(T)>::Unsigned Unsigned;
            };

            template <typename T>
            struct MakeSigned {
                typedef typename ChangeSign<T>::Signed Type;
            };

            template <typename T>
            struct MakeUnsigned {
                typedef typename ChangeSign<T>::Unsigned Type;
            };
        };  // namespace detail
    };  // namespace util
};  // namespace nn