#include "g3d/g3d_ResFile.hpp"

namespace nn {
    namespace g3d {
        const int64_t ResFile::Signature =
            NN_UTIL_CREATE_SIGNATURE_8('F', 'R', 'E', 'S', ' ', ' ', ' ', ' ');

        bool ResFile::IsValid(const void* pPtr) {
            const nn::util::BinaryFileHeader* header =
                static_cast<const nn::util::BinaryFileHeader*>(pPtr);

            return header->IsValid(Signature, 9, 0, 0);
        }

        void ResFile::Relocate() {
            if (!fileHeader.IsRelocated()) {
                fileHeader.GetRelocationTable()->Relocate();
            }
        }

        void ResFile::Unrelocate() {
            if (fileHeader.IsRelocated()) {
                fileHeader.GetRelocationTable()->Unrelocate();
            }
        }

        ResFile* ResFile::ResCast(void* pPtr) {
            ResFileData* fileData = static_cast<ResFileData*>(pPtr);
            ResFile* file = static_cast<ResFile*>(fileData);

            file->Relocate();
            if (fileData->fileHeader.IsEndianReverse()) {
                // probably something stripped from this block
            }

            return file;
        }
    };  // namespace g3d
};  // namespace nn