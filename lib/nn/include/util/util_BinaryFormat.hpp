#pragma once

#include "types.hpp"
#include "util/util_BinTypes.hpp"

namespace nn {
    namespace util {
        enum ByteOrderMark { ByteOrderMark_Normal = 0xFEFF, ByteOrderMark_Reverse = 0xFFFE };

        struct BinaryBlockHeader;
        struct RelocationTable;

        struct BinaryFileHeader {
        public:
            bool IsEndianReverse();
            bool IsValid(int64_t packedSig, int major, int minor, int micro) const;
            bool IsRelocated() const;
            RelocationTable* GetRelocationTable();

            BinFileSignature signature;
            BinVersion version;
            uint16_t byteOrderMark;
            uint8_t alignmentShift;
            uint8_t targetAddressSize;
            uint32_t offsetToFileName;
            uint16_t flag;
            uint16_t offsetToFirstBlock;
            uint32_t offsetToRelTable;
            uint32_t fileSize;
        };

        struct BinaryBlockHeader {
        public:
            BinBlockSignature signature;
            uint32_t offsetToNextBlock;
            uint32_t blockSize;
            uint32_t res;
        };

        struct RelocationTable {
        public:
            struct Section {
            public:
                union {
                    uint64_t pad;
                    void* ptr;
                };

                uint32_t position;
                uint32_t size;
                int32_t entryIndex;
                int32_t entryCount;
            };

            struct Entry {
                uint32_t position;
                uint16_t structCount;
                uint8_t offsetCount;
                uint8_t padCount;
            };

            void Relocate();
            void Unrelocate();

            BinBlockSignature signature;
            uint32_t position;
            int32_t sectionCount;
            int pad;
            Section sections[1];
        };

        struct StringPool {
        public:
            BinaryBlockHeader header;
            int32_t stringCount;
            BinString strings;
        };
    };  // namespace util
};  // namespace nn