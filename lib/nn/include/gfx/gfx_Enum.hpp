#pragma once

namespace nn {
    namespace gfx {
        enum ChannelFormat {
            ChannelFormat_Undefined,
            ChannelFormat_R4_G4,
            ChannelFormat_R8,
            ChannelFormat_R4_G4_B4_A4,
            ChannelFormat_A4_B4_G4_R4,
            ChannelFormat_R5_G5_B5_A1,
            ChannelFormat_A1_B5_G5_R5,
            ChannelFormat_R5_G6_B5,
            ChannelFormat_B5_G6_R5,
            ChannelFormat_R8_G8,
            ChannelFormat_R16,
            ChannelFormat_R8_G8_B8_A8,
            ChannelFormat_B8_G8_R8_A8,
            ChannelFormat_R9_G9_B9_E5,
            ChannelFormat_R10_G10_B10_A2,
            ChannelFormat_R11_G11_B10,
            ChannelFormat_B10_G11_R11,
            ChannelFormat_R10_G11_B11,
            ChannelFormat_R16_G16,
            ChannelFormat_R24_G8,
            ChannelFormat_R32,
            ChannelFormat_R16_G16_B16_A16,
            ChannelFormat_R32_G8_X24,
            ChannelFormat_R32_G32,
            ChannelFormat_R32_G32_B32,
            ChannelFormat_R32_G32_B32_A32,
            ChannelFormat_Bc1,
            ChannelFormat_Bc2,
            ChannelFormat_Bc3,
            ChannelFormat_Bc4,
            ChannelFormat_Bc5,
            ChannelFormat_Bc6,
            ChannelFormat_Bc7,
            ChannelFormat_Eac_R11,
            ChannelFormat_Eac_R11_G11,
            ChannelFormat_Etc1,
            ChannelFormat_Etc2,
            ChannelFormat_Etc2_Mask,
            ChannelFormat_Etc2_Alpha,
            ChannelFormat_Pvrtc1_2Bpp,
            ChannelFormat_Pvrtc1_4Bpp,
            ChannelFormat_Pvrtc1_Alpha_2Bpp,
            ChannelFormat_Pvrtc1_Alpha_4Bpp,
            ChannelFormat_Pvrtc2_Alpha_2Bpp,
            ChannelFormat_Pvrtc2_Alpha_4Bpp,
            ChannelFormat_Astc_4x4,
            ChannelFormat_Astc_5x4,
            ChannelFormat_Astc_5x5,
            ChannelFormat_Astc_6x5,
            ChannelFormat_Astc_6x6,
            ChannelFormat_Astc_8x5,
            ChannelFormat_Astc_8x6,
            ChannelFormat_Astc_8x8,
            ChannelFormat_Astc_10x5,
            ChannelFormat_Astc_10x6,
            ChannelFormat_Astc_10x8,
            ChannelFormat_Astc_10x10,
            ChannelFormat_Astc_12x10,
            ChannelFormat_Astc_12x12,
            ChannelFormat_B5_G5_R5_A1,
            ChannelFormat_End
        };

        enum TypeFormat {
            TypeFormat_Undefined,
            TypeFormat_Unorm,
            TypeFormat_Snorm,
            TypeFormat_Uint,
            TypeFormat_Sint,
            TypeFormat_Float,
            TypeFormat_UnormSrgb,
            TypeFormat_DepthStencil,
            TypeFormat_UintToFloat,
            TypeFormat_SintToFloat,
            TypeFormat_Ufloat,
            TypeFormat_End,
            TypeFormat_Bits = 8
        };

        enum ImageStorageDimension {
            ImageStorageDimension_Undefined,
            ImageStorageDimension_1d,
            ImageStorageDimension_2d,
            ImageStorageDimension_3d
        };

        enum ImageDimension {
            ImageDimension_1d,
            ImageDimension_2d,
            ImageDimension_3d,
            ImageDimension_CubeMap,
            ImageDimension_1dArray,
            ImageDimension_2dArray,
            ImageDimension_2dMultisample,
            ImageDimension_2dMultisampleArray,
            ImageDimension_CubeMapArray,
            ImageDimension_End
        };

        enum ImageFormat {
            ImageFormat_Undefined = 0,
            ImageFormat_R8_Unorm = (ChannelFormat_R8 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_R8_Snorm = (ChannelFormat_R8 << TypeFormat_Bits) | TypeFormat_Snorm,
            ImageFormat_R8_Uint = (ChannelFormat_R8 << TypeFormat_Bits) | TypeFormat_Uint,
            ImageFormat_R8_Sint = (ChannelFormat_R8 << TypeFormat_Bits) | TypeFormat_Sint,
            ImageFormat_R4_G4_B4_A4_Unorm =
                (ChannelFormat_R4_G4_B4_A4 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_A4_B4_G4_R4_Unorm =
                (ChannelFormat_A4_B4_G4_R4 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_R5_G5_B5_A1_Unorm =
                (ChannelFormat_R5_G5_B5_A1 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_A1_B5_G5_R5_Unorm =
                (ChannelFormat_A1_B5_G5_R5 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_R5_G6_B5_Unorm =
                (ChannelFormat_R5_G6_B5 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_B5_G6_R5_Unorm =
                (ChannelFormat_B5_G6_R5 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_R8_G8_Unorm = (ChannelFormat_R8_G8 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_R8_G8_Snorm = (ChannelFormat_R8_G8 << TypeFormat_Bits) | TypeFormat_Snorm,
            ImageFormat_R8_G8_Uint = (ChannelFormat_R8_G8 << TypeFormat_Bits) | TypeFormat_Uint,
            ImageFormat_R8_G8_Sint = (ChannelFormat_R8_G8 << TypeFormat_Bits) | TypeFormat_Sint,
            ImageFormat_R16_Unorm = (ChannelFormat_R16 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_R16_Snorm = (ChannelFormat_R16 << TypeFormat_Bits) | TypeFormat_Snorm,
            ImageFormat_R16_Uint = (ChannelFormat_R16 << TypeFormat_Bits) | TypeFormat_Uint,
            ImageFormat_R16_Sint = (ChannelFormat_R16 << TypeFormat_Bits) | TypeFormat_Sint,
            ImageFormat_R16_Float = (ChannelFormat_R16 << TypeFormat_Bits) | TypeFormat_Float,
            ImageFormat_D16_Unorm =
                (ChannelFormat_R16 << TypeFormat_Bits) | TypeFormat_DepthStencil,
            ImageFormat_R8_G8_B8_A8_Unorm =
                (ChannelFormat_R8_G8_B8_A8 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_R8_G8_B8_A8_Snorm =
                (ChannelFormat_R8_G8_B8_A8 << TypeFormat_Bits) | TypeFormat_Snorm,
            ImageFormat_R8_G8_B8_A8_Uint =
                (ChannelFormat_R8_G8_B8_A8 << TypeFormat_Bits) | TypeFormat_Uint,
            ImageFormat_R8_G8_B8_A8_Sint =
                (ChannelFormat_R8_G8_B8_A8 << TypeFormat_Bits) | TypeFormat_Sint,
            ImageFormat_R8_G8_B8_A8_UnormSrgb =
                (ChannelFormat_R8_G8_B8_A8 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_B8_G8_R8_A8_Unorm =
                (ChannelFormat_B8_G8_R8_A8 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_B8_G8_R8_A8_Snorm =
                (ChannelFormat_B8_G8_R8_A8 << TypeFormat_Bits) | TypeFormat_Snorm,
            ImageFormat_B8_G8_R8_A8_Uint =
                (ChannelFormat_B8_G8_R8_A8 << TypeFormat_Bits) | TypeFormat_Uint,
            ImageFormat_B8_G8_R8_A8_Sint =
                (ChannelFormat_B8_G8_R8_A8 << TypeFormat_Bits) | TypeFormat_Sint,
            ImageFormat_B8_G8_R8_A8_UnormSrgb =
                (ChannelFormat_B8_G8_R8_A8 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_R9_G9_B9_E5_SharedExp =
                (ChannelFormat_R9_G9_B9_E5 << TypeFormat_Bits) | TypeFormat_Float,
            ImageFormat_R10_G10_B10_A2_Unorm =
                (ChannelFormat_R10_G10_B10_A2 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_R10_G10_B10_A2_Uint =
                (ChannelFormat_R10_G10_B10_A2 << TypeFormat_Bits) | TypeFormat_Uint,
            ImageFormat_R11_G11_B10_Float =
                (ChannelFormat_R11_G11_B10 << TypeFormat_Bits) | TypeFormat_Float,
            ImageFormat_B10_G11_R11_Float =
                (ChannelFormat_B10_G11_R11 << TypeFormat_Bits) | TypeFormat_Float,
            ImageFormat_R16_G16_Unorm =
                (ChannelFormat_R16_G16 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_R16_G16_Snorm =
                (ChannelFormat_R16_G16 << TypeFormat_Bits) | TypeFormat_Snorm,
            ImageFormat_R16_G16_Uint = (ChannelFormat_R16_G16 << TypeFormat_Bits) | TypeFormat_Uint,
            ImageFormat_R16_G16_Sint = (ChannelFormat_R16_G16 << TypeFormat_Bits) | TypeFormat_Sint,
            ImageFormat_R16_G16_Float =
                (ChannelFormat_R16_G16 << TypeFormat_Bits) | TypeFormat_Float,
            ImageFormat_D24_Unorm_S8_Uint =
                (ChannelFormat_R24_G8 << TypeFormat_Bits) | TypeFormat_DepthStencil,
            ImageFormat_R32_Uint = (ChannelFormat_R32 << TypeFormat_Bits) | TypeFormat_Uint,
            ImageFormat_R32_Sint = (ChannelFormat_R32 << TypeFormat_Bits) | TypeFormat_Sint,
            ImageFormat_R32_Float = (ChannelFormat_R32 << TypeFormat_Bits) | TypeFormat_Float,
            ImageFormat_D32_Float =
                (ChannelFormat_R32 << TypeFormat_Bits) | TypeFormat_DepthStencil,
            ImageFormat_R16_G16_B16_A16_Unorm =
                (ChannelFormat_R16_G16_B16_A16 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_R16_G16_B16_A16_Snorm =
                (ChannelFormat_R16_G16_B16_A16 << TypeFormat_Bits) | TypeFormat_Snorm,
            ImageFormat_R16_G16_B16_A16_Uint =
                (ChannelFormat_R16_G16_B16_A16 << TypeFormat_Bits) | TypeFormat_Uint,
            ImageFormat_R16_G16_B16_A16_Sint =
                (ChannelFormat_R16_G16_B16_A16 << TypeFormat_Bits) | TypeFormat_Sint,
            ImageFormat_R16_G16_B16_A16_Float =
                (ChannelFormat_R16_G16_B16_A16 << TypeFormat_Bits) | TypeFormat_Float,
            ImageFormat_D32_Float_S8_Uint_X24 =
                (ChannelFormat_R32_G8_X24 << TypeFormat_Bits) | TypeFormat_DepthStencil,
            ImageFormat_R32_G32_Uint = (ChannelFormat_R32_G32 << TypeFormat_Bits) | TypeFormat_Uint,
            ImageFormat_R32_G32_Sint = (ChannelFormat_R32_G32 << TypeFormat_Bits) | TypeFormat_Sint,
            ImageFormat_R32_G32_Float =
                (ChannelFormat_R32_G32 << TypeFormat_Bits) | TypeFormat_Float,
            ImageFormat_R32_G32_B32_Uint =
                (ChannelFormat_R32_G32_B32 << TypeFormat_Bits) | TypeFormat_Uint,
            ImageFormat_R32_G32_B32_Sint =
                (ChannelFormat_R32_G32_B32 << TypeFormat_Bits) | TypeFormat_Sint,
            ImageFormat_R32_G32_B32_Float =
                (ChannelFormat_R32_G32_B32 << TypeFormat_Bits) | TypeFormat_Float,
            ImageFormat_R32_G32_B32_A32_Uint =
                (ChannelFormat_R32_G32_B32_A32 << TypeFormat_Bits) | TypeFormat_Uint,
            ImageFormat_R32_G32_B32_A32_Sint =
                (ChannelFormat_R32_G32_B32_A32 << TypeFormat_Bits) | TypeFormat_Sint,
            ImageFormat_R32_G32_B32_A32_Float =
                (ChannelFormat_R32_G32_B32_A32 << TypeFormat_Bits) | TypeFormat_Float,
            ImageFormat_Bc1_Unorm = (ChannelFormat_Bc1 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Bc1_UnormSrgb =
                (ChannelFormat_Bc1 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Bc2_Unorm = (ChannelFormat_Bc2 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Bc2_UnormSrgb =
                (ChannelFormat_Bc2 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Bc3_Unorm = (ChannelFormat_Bc3 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Bc3_UnormSrgb =
                (ChannelFormat_Bc3 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Bc4_Unorm = (ChannelFormat_Bc4 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Bc4_Snorm = (ChannelFormat_Bc4 << TypeFormat_Bits) | TypeFormat_Snorm,
            ImageFormat_Bc5_Unorm = (ChannelFormat_Bc5 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Bc5_Snorm = (ChannelFormat_Bc5 << TypeFormat_Bits) | TypeFormat_Snorm,
            ImageFormat_Bc6_Float = (ChannelFormat_Bc6 << TypeFormat_Bits) | TypeFormat_Float,
            ImageFormat_Bc6_Ufloat = (ChannelFormat_Bc6 << TypeFormat_Bits) | TypeFormat_Ufloat,
            ImageFormat_Bc7_Unorm = (ChannelFormat_Bc7 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Bc7_UnormSrgb =
                (ChannelFormat_Bc7 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Eac_R11_Unorm =
                (ChannelFormat_Eac_R11 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Eac_R11_Snorm =
                (ChannelFormat_Eac_R11 << TypeFormat_Bits) | TypeFormat_Snorm,
            ImageFormat_Eac_R11_G11_Unorm =
                (ChannelFormat_Eac_R11_G11 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Eac_R11_G11_Snorm =
                (ChannelFormat_Eac_R11_G11 << TypeFormat_Bits) | TypeFormat_Snorm,
            ImageFormat_Etc1_Unorm = (ChannelFormat_Etc1 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Etc2_Unorm = (ChannelFormat_Etc2 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Etc2_UnormSrgb =
                (ChannelFormat_Etc2 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Etc2_Mask_Unorm =
                (ChannelFormat_Etc2_Mask << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Etc2_Mask_UnormSrgb =
                (ChannelFormat_Etc2_Mask << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Etc2_Alpha_Unorm =
                (ChannelFormat_Etc2_Alpha << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Etc2_Alpha_UnormSrgb =
                (ChannelFormat_Etc2_Alpha << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Pvrtc1_2Bpp_Unorm =
                (ChannelFormat_Pvrtc1_2Bpp << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Pvrtc1_2Bpp_UnormSrgb =
                (ChannelFormat_Pvrtc1_2Bpp << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Pvrtc1_4Bpp_Unorm =
                (ChannelFormat_Pvrtc1_4Bpp << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Pvrtc1_4Bpp_UnormSrgb =
                (ChannelFormat_Pvrtc1_4Bpp << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Pvrtc1_Alpha_2Bpp_Unorm =
                (ChannelFormat_Pvrtc1_Alpha_2Bpp << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Pvrtc1_Alpha_2Bpp_UnormSrgb =
                (ChannelFormat_Pvrtc1_Alpha_2Bpp << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Pvrtc1_Alpha_4Bpp_Unorm =
                (ChannelFormat_Pvrtc1_Alpha_4Bpp << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Pvrtc1_Alpha_4Bpp_UnormSrgb =
                (ChannelFormat_Pvrtc1_Alpha_4Bpp << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Pvrtc2_Alpha_2Bpp_Unorm =
                (ChannelFormat_Pvrtc2_Alpha_2Bpp << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Pvrtc2_Alpha_2Bpp_UnormSrgb =
                (ChannelFormat_Pvrtc2_Alpha_2Bpp << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Pvrtc2_Alpha_4Bpp_Unorm =
                (ChannelFormat_Pvrtc2_Alpha_4Bpp << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Pvrtc2_Alpha_4Bpp_UnormSrgb =
                (ChannelFormat_Pvrtc2_Alpha_4Bpp << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_4x4_Unorm =
                (ChannelFormat_Astc_4x4 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_4x4_UnormSrgb =
                (ChannelFormat_Astc_4x4 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_5x4_Unorm =
                (ChannelFormat_Astc_5x4 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_5x4_UnormSrgb =
                (ChannelFormat_Astc_5x4 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_5x5_Unorm =
                (ChannelFormat_Astc_5x5 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_5x5_UnormSrgb =
                (ChannelFormat_Astc_5x5 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_6x5_Unorm =
                (ChannelFormat_Astc_6x5 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_6x5_UnormSrgb =
                (ChannelFormat_Astc_6x5 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_6x6_Unorm =
                (ChannelFormat_Astc_6x6 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_6x6_UnormSrgb =
                (ChannelFormat_Astc_6x6 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_8x5_Unorm =
                (ChannelFormat_Astc_8x5 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_8x5_UnormSrgb =
                (ChannelFormat_Astc_8x5 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_8x6_Unorm =
                (ChannelFormat_Astc_8x6 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_8x6_UnormSrgb =
                (ChannelFormat_Astc_8x6 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_8x8_Unorm =
                (ChannelFormat_Astc_8x8 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_8x8_UnormSrgb =
                (ChannelFormat_Astc_8x8 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_10x5_Unorm =
                (ChannelFormat_Astc_10x5 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_10x5_UnormSrgb =
                (ChannelFormat_Astc_10x5 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_10x6_Unorm =
                (ChannelFormat_Astc_10x6 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_10x6_UnormSrgb =
                (ChannelFormat_Astc_10x6 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_10x8_Unorm =
                (ChannelFormat_Astc_10x8 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_10x8_UnormSrgb =
                (ChannelFormat_Astc_10x8 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_10x10_Unorm =
                (ChannelFormat_Astc_10x10 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_10x10_UnormSrgb =
                (ChannelFormat_Astc_10x10 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_12x10_Unorm =
                (ChannelFormat_Astc_12x10 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_12x10_UnormSrgb =
                (ChannelFormat_Astc_12x10 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_Astc_12x12_Unorm =
                (ChannelFormat_Astc_12x12 << TypeFormat_Bits) | TypeFormat_Unorm,
            ImageFormat_Astc_12x12_UnormSrgb =
                (ChannelFormat_Astc_12x12 << TypeFormat_Bits) | TypeFormat_UnormSrgb,
            ImageFormat_B5_G5_R5_A1_Unorm =
                (ChannelFormat_B5_G5_R5_A1 << TypeFormat_Bits) | TypeFormat_Unorm

        };
    };  // namespace gfx
};  // namespace nn