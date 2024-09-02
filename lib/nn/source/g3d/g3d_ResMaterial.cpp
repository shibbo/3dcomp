#include "g3d/g3d_ResMaterial.hpp"
#include "util/util_MathTypes.hpp"

namespace nn {
    namespace g3d {
        namespace {
            struct TexMtx {
                f32 m[3][2];
            };
        };  // namespace

        size_t ResShaderParam::GetSize(Type type) {
            if (type <= Type_Float4) {
                return 4 * ((type & 0x3) + 1);
            } else if (type <= Type_Float4x4) {
                return sizeof(f32) * 4 * (((type - Type_Reserved2) >> 2) + 2);
            }

            static const size_t s_tblSize[] = {0x18, 0x30, 0x18};

            return s_tblSize[type - Type_Srt2d];
        }

        size_t ResShaderParam::GetSrcSize(Type type) {
            if (type <= Type_Float4) {
                s32 cmpCnt = (type & 0x3) + 1;
                return sizeof(f32) * cmpCnt;
            } else if (type <= Type_Float4x4) {
                const s32 colCnt = (type & 0x3) + 1;
                const s32 rowCnt = ((type - Type_Reserved2) >> 2) + 1;
                return sizeof(f32) * colCnt * rowCnt;
            }

            static const size_t s_tblSrcSize[] = {0x14, 0x24, 0x18, 0x20};
            return s_tblSrcSize[type - Type_Srt2d];
        }
    };  // namespace g3d
};  // namespace nn