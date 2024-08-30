#pragma once

namespace nn {
    namespace util {
        template <typename T>
        class AccessorBase : protected T {
        protected:
            AccessorBase();

        public:
            T& ToData() { return *this; }

            const T& ToData() const { return *this; }
        };
    };  // namespace util
};  // namespace nn