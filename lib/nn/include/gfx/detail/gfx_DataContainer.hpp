#pragma once

namespace nn {
    namespace gfx {
        namespace detail {
            template <typename T>
            class DataContainer : protected T {
            public:
                DataContainer() : T() {}
            };
        };  // namespace detail
    };  // namespace gfx
};  // namespace nn