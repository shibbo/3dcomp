#pragma once

namespace sead {
    class FreeList {
    public:
        struct Node {
            Node* mNextFree;
        };

        Node* mFree = nullptr;
        void* mWork = nullptr;
    };
};  // namespace sead