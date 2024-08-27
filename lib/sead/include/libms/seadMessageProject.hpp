#pragma once

#include <types.hpp>
#include "container/seadBuffer.hpp"
#include "gfx/seadColor.hpp"
#include "libms/libms.h"

namespace sead {
    class Heap;

    class MessageProject {
    public:
        virtual ~MessageProject();

        struct Style {
            s32 mRegionWidth;
            s32 mLineNum;
            s32 mFontIndex;
            s32 mColorIndex;
        };

        enum DataType : u8 {
            cDataType_U8 = 0x0,
            cDataType_U16 = 0x1,
            cDataType_U32 = 0x2,
            cDataType_S8 = 0x3,
            cDataType_S16 = 0x4,
            cDataType_S32 = 0x5,
            cDataType_F32 = 0x6,
            cDataType_F64 = 0x7,
            cDataType_String = 0x8,
            cDataType_List = 0x9,
            cDataType_Unknown = 0xFF,
        };

        struct AttributeInfo {
            DataType mDataType;
            s32 mOffset;
        };

        void initialize(void*, Heap*);
        void finalize();

        LMSProjFile* mProjectFile = nullptr;  // 0x08
        sead::Buffer<Color4u8> mColors;
        sead::Buffer<Style> mStyles;
        sead::Buffer<AttributeInfo> mAttributeInfos;
        s32 mContentsNum = 0;
    };
};  // namespace sead