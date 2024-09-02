#pragma once

#include <cstdio>
#include "util/util_AccessorBase.hpp"
#include "util/util_BinTypes.hpp"

namespace nn {
    namespace g3d {
        struct ResShaderParamData {
            nn::util::BinPtr pCallback;
            nn::util::BinPtrToString pId;
            uint8_t type;
            uint8_t srcSize;
            uint16_t srcOffset;
            int32_t offset;
            uint16_t dependedIndex;
            uint16_t dependIndex;
            uint8_t res[4];
        };

        class ResShaderParam : public nn::util::AccessorBase<ResShaderParamData> {
        public:
            enum Type {
                Type_Bool,
                Type_Bool2,
                Type_Bool3,
                Type_Bool4,
                Type_Int,
                Type_Int2,
                Type_Int3,
                Type_Int4,
                Type_Uint,
                Type_Uint2,
                Type_Uint3,
                Type_Uint4,
                Type_Float,
                Type_Float2,
                Type_Float3,
                Type_Float4,
                Type_Reserved2,
                Type_Float2x2,
                Type_Float2x3,
                Type_Float2x4,
                Type_Reserved3,
                Type_Float3x2,
                Type_Float3x3,
                Type_Float3x4,
                Type_Reserved4,
                Type_Float4x2,
                Type_Float4x3,
                Type_Float4x4,
                Type_Srt2d,
                Type_Srt3d,
                Type_Texsrt,
                Type_Num
            };

            template <bool>
            void Convert(void*, const void*);

            static size_t GetSize(Type);
            static size_t GetSrcSize(Type);
            bool SetDependPointer(void*, const void*) const;
            bool GetDependPointer(void**, const void*);
            static size_t ConvertSrt2dCallback(void*, const void*, const ResShaderParam*,
                                               const void*);
            static size_t ConvertSrt3dCallback(void*, const void*, const ResShaderParam*,
                                               const void*);
            static size_t ConvertSrt2dExCallback(void*, const void*, const ResShaderParam*,
                                                 const void*);
        };

        static size_t ConvertTexSrtCallback(void*, const void*, const ResShaderParam*, const void*);
        static size_t ConvertTexSrtExCallback(void*, const void*, const ResShaderParam*,
                                              const void*);
    };  // namespace g3d
};  // namespace nn