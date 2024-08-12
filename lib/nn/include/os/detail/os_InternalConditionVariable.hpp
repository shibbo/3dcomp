#pragma once

#include "os/detail/os_InternalConditionVariable-os.horizon.hpp"
#include "util/util_TypedStorage.hpp"

namespace nn {
    namespace os {
        namespace detail {
            class InternalConditionVariable {
            public:
                InternalConditionVariableImpl m_Impl;
            };

            typedef util::TypedStorage<InternalConditionVariable, 4, 4>
                InternalConditionVariableStorage;
        };  // namespace detail
    };  // namespace os
};  // namespace nn