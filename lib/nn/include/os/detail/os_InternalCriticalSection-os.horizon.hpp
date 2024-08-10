#pragma once

#include "nn_BitTypes.hpp"

namespace nn {
    namespace os {
        namespace detail {
            class InternalCriticalSectionImplByHorizon {
            public:
                InternalCriticalSectionImplByHorizon();

                Bit32 m_ThreadHandle;
            };

            typedef InternalCriticalSectionImplByHorizon InternalCriticalSectionImpl;
        };
    };
};