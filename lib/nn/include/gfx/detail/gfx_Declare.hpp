#pragma once

namespace nn {
    namespace gfx {
        template <typename TTarget>
        struct MemoryPoolImplData;

        template <typename TTarget>
        struct DeviceImplData;

        namespace detail {
            template <typename TTarget>
            class MemoryPoolImpl;

            template <typename TTarget>
            class DeviceImpl;
        };  // namespace detail

    };  // namespace gfx
};  // namespace nn