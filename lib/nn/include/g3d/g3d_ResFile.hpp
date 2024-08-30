#pragma once

#include "gfx/gfx_Types.hpp"
#include "util/util_BinTypes.hpp"
#include "util/util_BinaryFormat.hpp"
#include "util/util_ResDic.hpp"

namespace nn {
    namespace g3d {
        class ResModel;
        class ResSkeletalAnim;
        class ResMaterialAnim;
        class ResBoneVisibilityAnim;
        class ResShapeAnim;
        class ResSceneAnim;
        class ResExternalFile;

        struct ResFileData {
            nn::util::BinaryFileHeader fileHeader;
            nn::util::BinPtrToString pName;
            nn::util::BinTPtr<ResModel> pModelArray;
            nn::util::BinTPtr<nn::util::ResDic> pModelDic;
            uint8_t res0[32];
            nn::util::BinTPtr<ResSkeletalAnim> pSkeletalAnimArray;
            nn::util::BinTPtr<nn::util::ResDic> pSkeletalAnimDic;
            nn::util::BinTPtr<ResMaterialAnim> pMaterialAnimArray;
            nn::util::BinTPtr<nn::util::ResDic> pMaterialAnimDic;
            nn::util::BinTPtr<ResBoneVisibilityAnim> pBoneVisAnimArray;
            nn::util::BinTPtr<nn::util::ResDic> pBoneVisAnimDic;
            nn::util::BinTPtr<ResShapeAnim> pShapeAnimArray;
            nn::util::BinTPtr<nn::util::ResDic> pShapeAnimDic;
            nn::util::BinTPtr<ResSceneAnim> pSceneAnimArray;
            nn::util::BinTPtr<nn::util::ResDic> pSceneAnimDic;
            nn::util::BinTPtr<nn::gfx::MemoryPool> pBufferMemoryPool;
            nn::util::BinTPtr<nn::gfx::MemoryPool::InfoType> pBufferMemoryPoolInfo;
            nn::util::BinTPtr<ResExternalFile> pExternalFileArray;
            nn::util::BinTPtr<nn::util::ResDic> pExternalFileDic;
            nn::util::BinPtr pUserPtr;
            nn::util::BinTPtr<nn::util::BinString> pStringPool;
            uint32_t stringPoolSize;
            uint16_t modelCount;
            uint8_t res1[4];
            uint16_t skeletalAnimCount;
            uint16_t materialAnimCount;
            uint16_t boneVisAnimCount;
            uint16_t shapeAnimCount;
            uint16_t sceneAnimCount;
            uint16_t externalFileCount;
            uint8_t res2[2];
        };

        class ResFile : public nn::util::AccessorBase<ResFileData> {
        public:
            static const int64_t Signature;

            static bool IsValid(const void*);
            void Relocate();
            void Unrelocate();

            static ResFile* ResCast(void*);
        };
    };  // namespace g3d
};  // namespace nn