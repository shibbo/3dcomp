#include "g3d/g3d_ResMaterial.hpp"
#include "g3d/g3d_Inlines.hpp"
#include "util/util_BytePtr.hpp"
#include "util/util_MathTypes.hpp"
#include "util/util_MatrixApi.hpp"

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

        bool ResShaderParam::SetDependPointer(void* pSrc, const void* pDest) const {
            if (srcSize > GetSrcSize((Type)type)) {
                if (dependedIndex == dependIndex) {
                    nn::util::BytePtr bytePtr(pSrc);
                    bytePtr.Advance(GetSrcSize((Type)type));
                    // ptrs are aligned by 8
                    bytePtr.AlignUp(8);
                    void** ptr = bytePtr.Get<void*>();
                    *ptr = const_cast<void*>(pDest);
                    return true;
                }
            }

            return false;
        }

        bool ResShaderParam::GetDependPointer(void** pOut, const void* pSrc) const {
            if (srcSize > GetSrcSize((Type)type)) {
                nn::util::BytePtr bytePtr(const_cast<void*>(pSrc));
                bytePtr.Advance(GetSrcSize((Type)type));
                bytePtr.AlignUp(8);
                void** ptr = bytePtr.Get<void*>();
                *pOut = *ptr;
                return true;
            }

            *pOut = nullptr;
            return false;
        }

        template <bool Swap>
        void ResShaderParam::Convert(void* pDest, const void* pSrc) const {
            ResShaderParam::Type t = (Type)type;

            if (t <= Type_Float4) {
                s32 cmpCnt = (t & 0x3) + 1;
                Copy32<Swap>(pDest, pSrc, cmpCnt);
            } else if (t <= Type_Float4x4) {
                const int colCnt = (t & 0x3) + 1;
                const int rowCnt = ((t - Type_Reserved2) >> 2) + 2;
                const int cmpCnt = static_cast<int>(colCnt);
                const size_t size = sizeof(f32) * colCnt;
                const size_t stride = sizeof(f32) * 4;

                for (int idx = 0; idx < rowCnt; idx++) {
                    Copy32<Swap>(pDest, pSrc, cmpCnt);
                    pDest = AddOffset(pDest, stride);
                    pSrc = AddOffset(pSrc, size);
                }
            }
        }

        size_t ResShaderParam::ConvertSrt3dCallback(void* pDest, const void* pSrc,
                                                    const ResShaderParam*, const void*) {
            const Srt3d& srt = *static_cast<const Srt3d*>(pSrc);

            nn::util::FloatColumnMajor4x3& mtx =
                *static_cast<nn::util::FloatColumnMajor4x3*>(pDest);
            nn::util::Vector3fType scale = {{srt.scale.v[0], srt.scale.v[1], srt.scale.v[2]}};

            nn::util::Vector3fType rotate = {{srt.rotate.v[0], srt.rotate.v[1], srt.rotate.v[2]}};
            nn::util::Vector3fType translate = {
                {srt.translate.v[0], srt.translate.v[1], srt.translate.v[2]}};

            nn::util::Matrix4x3fType calcMtx;
            nn::util::MatrixSetScaleRotateXyz(&calcMtx, scale, rotate);
            nn::util::MatrixSetTranslate(&calcMtx, translate);
            nn::util::MatrixStore(&mtx, calcMtx);

            return sizeof(nn::util::FloatColumnMajor4x3);
        }

        template void ResShaderParam::Convert<true>(void*, const void*) const;
        template void ResShaderParam::Convert<false>(void*, const void*) const;
    };  // namespace g3d
};  // namespace nn