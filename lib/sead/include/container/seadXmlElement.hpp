#pragma once

#include "container/seadTreeNode.hpp"
#include "prim/seadSafeString.hpp"
#include <types.hpp>

namespace sead {
    class Heap;

    class XmlElement {
    public:
        XmlElement();

        virtual ~XmlElement();

        TreeNode _8;
        u8 _10[0x80 - 0x10];
        u8* mContent;           // 0x80
        u32 _88;
        bool _8C;
        u8 _90[0xC8 - 0x90];
        Heap* _C8;
    };
};