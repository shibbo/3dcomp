import os, struct, sys
import lz4.block

class SegmentHeader:
    fileOffset = 0
    memoryOffset = 0
    decompressedSize = 0

    def __init__(self, fileOffset, memoryOffset, decompressedSize):
        self.fileOffset = fileOffset
        self.memoryOffset = memoryOffset
        self.decompressedSize = decompressedSize

class SegmentHeaderRelative:
    offset = 0
    size = 0

    def __init__(self, offset, size):
        self.offset = offset
        self.size = size

class NSO:
    textSegmentHeader = None
    textData = []
    rawData = None

    def __init__(self, nsoBinary):
        self.rawData = nsoBinary

        nsoStr = struct.unpack_from("4s", self.rawData, 0)[0].decode('latin-1')

        if nsoStr != "NSO0":
            print("Invalid NSO.")
            sys.exit(1)

        # we only need two things out of the header
        # 1) the offset and size of the text data within the binary (and its compressed size)
        # 2) whether or not we need to decompress the data
        flags = struct.unpack_from("<I", self.rawData, 0xC)[0]
        textOffs, textMemOffs, textSize = struct.unpack_from("<3I", self.rawData, 0x10)
        self.textSegmentHeader = SegmentHeader(textOffs, textMemOffs, textSize)
        textSizeComp = struct.unpack_from("<I", self.rawData, 0x60)[0]
        self.textData = self.rawData[textOffs:textOffs + textSizeComp]

        # decompress data if needed
        if flags & 0x1:
            self.textData = lz4.block.decompress(self.textData, uncompressed_size=textSize)

    def getFunction(self, addr, size):
        funcData = self.textData[addr:addr + size]
        return funcData