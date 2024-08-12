#pragma once

namespace sead {
    class TreeNode {
    public:
        TreeNode();

        void clearLinks();
        void pushBackChild(TreeNode*);
        void detatchSubTree();
        void pushBackSibling(TreeNode*);

        TreeNode* mParent;
        TreeNode* mChild;
        TreeNode* mNext;
        TreeNode* mPrev;
    };
};  // namespace sead
