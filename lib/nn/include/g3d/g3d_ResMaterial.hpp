#pragma once

#include <cstdio>
#include "gfx/gfx_DescriptorSlot.hpp"
#include "nn_BitTypes.hpp"
#include "util/util_AccessorBase.hpp"
#include "util/util_BinTypes.hpp"
#include "util/util_MathTypes.hpp"
#include "util/util_ResDic.hpp"

namespace nn {
    namespace g3d {

        struct Srt3d {
            nn::util::Float3 scale;
            nn::util::Float3 rotate;
            nn::util::Float3 translate;
        };

        struct ResRenderInfoData {
            nn::util::BinPtrToString pName;

            union {
                nn::util::BinTPtr<int32_t> intValueArray;
                nn::util::BinTPtr<float> floatValueArray;
                nn::util::BinTPtr<nn::util::BinPtrToString> stringArray;
            };

            uint16_t arrayLength;
            uint8_t type;
            uint8_t res[5];
        };

        class ResRenderInfo : public nn::util::AccessorBase<ResRenderInfoData> {
        public:
            enum Type { Type_Int, Type_Float, Type_String };
        };

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
            void Convert(void*, const void*) const;

            static size_t GetSize(Type);
            static size_t GetSrcSize(Type);
            bool SetDependPointer(void*, const void*) const;
            bool GetDependPointer(void**, const void*) const;
            static size_t ConvertSrt2dCallback(void*, const void*, const ResShaderParam*,
                                               const void*);
            static size_t ConvertSrt3dCallback(void*, const void*, const ResShaderParam*,
                                               const void*);
            static size_t ConvertSrt2dExCallback(void*, const void*, const ResShaderParam*,
                                                 const void*);
        };

        struct ResShaderAssignData {
            nn::util::BinPtrToString pShaderArchiveName;
            nn::util::BinPtrToString pShadingModelName;
            nn::util::BinTPtr<nn::util::BinPtrToString> pAttrAssignArray;
            nn::util::BinTPtr<nn::util::ResDic> pAttrAssignDic;
            nn::util::BinTPtr<nn::util::BinPtrToString> pSamplerAssignArray;
            nn::util::BinTPtr<nn::util::ResDic> pSamplerAssignDic;
            nn::util::BinTPtr<nn::util::BinPtrToString> pShaderOptionArray;
            nn::util::BinTPtr<nn::util::ResDic> pShaderOptionDic;
            uint32_t revision;
            uint8_t attrAssignCount;
            uint8_t samplerAssignCount;
            uint16_t shaderOptionCount;
        };

        // static size_t ConvertTexSrtCallback(void*, const void*, const ResShaderParam*, const
        // void*); static size_t ConvertTexSrtExCallback(void*, const void*, const ResShaderParam*,
        //                                      const void*);

        struct ResShaderAssignData {
            nn::util::BinPtrToString pShaderArchiveName;
            nn::util::BinPtrToString pShadingModelName;
            nn::util::BinTPtr<nn::util::BinPtrToString> pAttrAssignArray;
            nn::util::BinTPtr<nn::util::ResDic> pAttrAssignDic;
            nn::util::BinTPtr<nn::util::BinPtrToString> pSamplerAssignArray;
            nn::util::BinTPtr<nn::util::ResDic> pSamplerAssignDic;
            nn::util::BinTPtr<nn::util::BinPtrToString> pShaderOptionArray;
            nn::util::BinTPtr<nn::util::ResDic> pShaderOptionDic;
            uint32_t revision;
            uint8_t attrAssignCount;
            uint8_t samplerAssignCount;
            uint16_t shaderOptionCount;
        };

        class ResShaderAssign : public nn::util::AccessorBase<ResShaderAssignData> {
        public:
        };

        struct ResMaterialData {
            nn::util::BinBlockSignature signature;
            Bit32 flag;
            nn::util::BinPtrToString pName;
            nn::util::BinTPtr<ResRenderInfo> pRenderInfoArray;
            nn::util::BinTPtr<nn::util::ResDic> pRenderInfoDic;
            nn::util::BinTPtr<ResShaderAssign> pShaderAssign;
        };
    };  // namespace g3d
};  // namespace nn