#pragma once

#include "os/detail/os_InternalConditionVariable.hpp"
#include "os/detail/os_InternalCriticalSection.hpp"
#include "util/util_TypedStorage.hpp"
#include <cstdint>

namespace nn {
    namespace os {
        namespace detail {
            class MultiWaitObjectList;
        };

        struct MessageQueueType {
            enum State {
                NotInitialized  = 0,
                Initialized     = 1
            };

            util::TypedStorage<detail::MultiWaitObjectList, 16, 8> _multiWaitObjectListNotFull;
            util::TypedStorage<detail::MultiWaitObjectList, 16, 8> _multiWaitObjectListNotEmpty;
            uintptr_t* _buffer;
            int _maxCount;
            int _count;
            int _offset;
            int _state;
            detail::InternalCriticalSectionStorage _csQueue;
            detail::InternalConditionVariableStorage _cvNotFull;
            detail::InternalConditionVariableStorage _cvNotEmpty;
        };
    };
};