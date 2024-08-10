#pragma once

#include "os/detail/os_InternalCriticalSection-os.horizon.hpp"
#include "util/util_TypedStorage.hpp"

namespace nn {
    namespace os {
        namespace detail {
            class InternalCriticalSection {
            public:
                InternalCriticalSectionImpl m_Impl;
            };

            typedef nn::util::TypedStorage<InternalCriticalSection, 4, 4> InternalCriticalSectionStorage;
        };
    };
};