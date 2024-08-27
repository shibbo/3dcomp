#pragma once

namespace sead {
    template <typename K>
    class TreeMapNode;

    template <typename K>
    class TreeMapImpl {
    public:
        TreeMapNode<K>* mRoot = nullptr;
    };
};  // namespace sead