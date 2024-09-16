#pragma once

namespace nn {
    namespace font {

#define NN_FONT_RUNTIME_TYPEINFO_ROOT()                                                                                                              \
    static const nn::font::detail::RuntimeTypeInfo* GetRuntimeTypeInfoStatic() {                                                                     \
        static const nn::font::detail::RuntimeTypeInfo s_TypeInfo(NULL);                                                                             \
        return &s_TypeInfo;                                                                                                                          \
    }                                                                                                                                                \
    virtual const nn::font::detail::RuntimeTypeInfo* GetRuntimeTypeInfo() const {                                                                    \
        return GetRuntimeTypeInfoStatic();                                                                                                           \
    }

#define NN_FONT_RUNTIME_TYPEINFO(base)                                                                                                               \
    static const nn::font::detail::RuntimeTypeInfo* GetRuntimeTypeInfoStatic() {                                                                     \
        static const nn::font::detail::RuntimeTypeInfo s_TypeInfo(base::GetRuntimeTypeInfoStatic());                                                 \
        return &s_TypeInfo;                                                                                                                          \
    }                                                                                                                                                \
    virtual const nn::font::detail::RuntimeTypeInfo* GetRuntimeTypeInfo() const NN_OVERRIDE {                                                        \
        return GetRuntimeTypeInfoStatic();                                                                                                           \
    }

        namespace detail {
            class RuntimeTypeInfo {
            public:
                const RuntimeTypeInfo* mParent;

                explicit RuntimeTypeInfo(const RuntimeTypeInfo* pParent) : mParent(pParent) {}

                bool IsDerivedFrom(const RuntimeTypeInfo* s_TypeInfo) const {
                    const RuntimeTypeInfo* self = this;

                    while (self != nullptr) {
                        if (self == s_TypeInfo) {
                            return true;
                        }

                        self = self->mParent;
                    }

                    return false;
                }
            };
        };  // namespace detail
    };  // namespace font
};  // namespace nn