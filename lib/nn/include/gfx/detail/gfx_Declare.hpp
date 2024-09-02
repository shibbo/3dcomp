#pragma once

namespace nn {
    namespace gfx {
        template <typename TTarget>
        struct MemoryPoolImplData;

        template <typename TTarget>
        struct DeviceImplData;

        template <typename TTarget>
        struct TextureInfoImplData;

        namespace detail {
            template <typename TTarget>
            class MemoryPoolImpl;

            template <typename TTarget>
            class DeviceImpl;

            template <typename TTarget>
            class TextureInfoImpl;
        };  // namespace detail

    };  // namespace gfx
};  // namespace nn