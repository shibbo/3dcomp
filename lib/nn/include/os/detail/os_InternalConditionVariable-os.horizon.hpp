#pragma once

#include <cstdint>

namespace nn {
    namespace os {
        namespace detail {
            class TimeoutHelper;

            class InternalConditionVariableImplByHorizon {
            public:
                InternalConditionVariableImplByHorizon();

                uint32_t m_Value;
            };

            typedef InternalConditionVariableImplByHorizon InternalConditionVariableImpl;
        };
    };
};